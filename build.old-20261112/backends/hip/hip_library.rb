require 'ffi'
module FFI

  class HIPStruct < Struct
    def self.enclosing_module
      HIP
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
  class HIPEnum < Enum
  end
  class HIPUnion < Union
    def self.enclosing_module
      HIP
    end
  end
  class HIPBitmask < Bitmask
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
    def hipbitmask(*args)
      generic_enum(FFI::HIPBitmask, *args)
    end
    def hipenum(*args)
      generic_enum(FFI::HIPEnum, *args)
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
module HIP
  HIP_IPC_HANDLE_SIZE = 64
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

  hipDeviceAttributeCudaCompatibleBegin = 0
  hipDeviceAttributeAmdSpecificBegin = 10000
  HIPRTC_JIT_NUM_LEGACY_INPUT_TYPES = 6
  ACTIVITY_DOMAIN_HIP_OPS = 2
  HipComputeMode = hipenum :hipComputeMode,
    [ :hipComputeModeDefault, 0,
      :hipComputeModeExclusive, 1,
      :hipComputeModeProhibited, 2,
      :hipComputeModeExclusiveProcess, 3 ]

  HipTextureAddressMode = hipenum :hipTextureAddressMode,
    [ :hipAddressModeWrap, 0,
      :hipAddressModeClamp, 1,
      :hipAddressModeMirror, 2,
      :hipAddressModeBorder, 3 ]

  HipTextureFilterMode = hipenum :hipTextureFilterMode,
    [ :hipFilterModePoint, 0,
      :hipFilterModeLinear, 1 ]

  HipTextureReadMode = hipenum :hipTextureReadMode,
    [ :hipReadModeElementType, 0,
      :hipReadModeNormalizedFloat, 1 ]

  HipSurfaceBoundaryMode = hipenum :hipSurfaceBoundaryMode,
    [ :hipBoundaryModeZero, 0,
      :hipBoundaryModeTrap, 1,
      :hipBoundaryModeClamp, 2 ]

  HipLimit_t = hipenum :hipLimit_t,
    [ :hipLimitStackSize, 0x0,
      :hipLimitPrintfFifoSize, 0x1,
      :hipLimitMallocHeapSize, 0x2,
      :hipLimitRange ]

  class HipDeviceArch_t < FFI::HIPStruct
    layout :_aggregated_bitfields_1, :uint
  end
  typedef HipDeviceArch_t.by_value, :hipDeviceArch_t

  class HipUUID < FFI::HIPStruct
    prepend UUID
    layout :bytes, [ :char, 16 ]
  end
  typedef HipUUID.by_value, :hipUUID

  class HipDeviceProp_t < FFI::HIPStruct
    layout :name, [ :char, 256 ],
           :totalGlobalMem, :size_t,
           :sharedMemPerBlock, :size_t,
           :regsPerBlock, :int,
           :warpSize, :int,
           :maxThreadsPerBlock, :int,
           :maxThreadsDim, [ :int, 3 ],
           :maxGridSize, [ :int, 3 ],
           :clockRate, :int,
           :memoryClockRate, :int,
           :memoryBusWidth, :int,
           :totalConstMem, :size_t,
           :major, :int,
           :minor, :int,
           :multiProcessorCount, :int,
           :l2CacheSize, :int,
           :maxThreadsPerMultiProcessor, :int,
           :computeMode, :int,
           :clockInstructionRate, :int,
           :arch, :hipDeviceArch_t,
           :concurrentKernels, :int,
           :pciDomainID, :int,
           :pciBusID, :int,
           :pciDeviceID, :int,
           :maxSharedMemoryPerMultiProcessor, :size_t,
           :isMultiGpuBoard, :int,
           :canMapHostMemory, :int,
           :gcnArch, :int,
           :gcnArchName, [ :char, 256 ],
           :integrated, :int,
           :cooperativeLaunch, :int,
           :cooperativeMultiDeviceLaunch, :int,
           :maxTexture1DLinear, :int,
           :maxTexture1D, :int,
           :maxTexture2D, [ :int, 2 ],
           :maxTexture3D, [ :int, 3 ],
           :hdpMemFlushCntl, :pointer,
           :hdpRegFlushCntl, :pointer,
           :memPitch, :size_t,
           :textureAlignment, :size_t,
           :texturePitchAlignment, :size_t,
           :kernelExecTimeoutEnabled, :int,
           :ECCEnabled, :int,
           :tccDriver, :int,
           :cooperativeMultiDeviceUnmatchedFunc, :int,
           :cooperativeMultiDeviceUnmatchedGridDim, :int,
           :cooperativeMultiDeviceUnmatchedBlockDim, :int,
           :cooperativeMultiDeviceUnmatchedSharedMem, :int,
           :isLargeBar, :int,
           :asicRevision, :int,
           :managedMemory, :int,
           :directManagedMemAccessFromHost, :int,
           :concurrentManagedAccess, :int,
           :pageableMemoryAccess, :int,
           :pageableMemoryAccessUsesHostPageTables, :int
  end
  typedef HipDeviceProp_t.by_value, :hipDeviceProp_t

  HipMemoryType = hipenum :hipMemoryType,
    [ :hipMemoryTypeHost,
      :hipMemoryTypeDevice,
      :hipMemoryTypeArray,
      :hipMemoryTypeUnified,
      :hipMemoryTypeManaged ]

  class HipPointerAttribute_t < FFI::HIPStruct
    layout :memoryType, :hipMemoryType,
           :device, :int,
           :devicePointer, :pointer,
           :hostPointer, :pointer,
           :isManaged, :int,
           :allocationFlags, :uint
  end
  typedef HipPointerAttribute_t.by_value, :hipPointerAttribute_t

  HipError_t = hipenum :hipError_t,
    [ :hipSuccess, 0,
      :hipErrorInvalidValue, 1,
      :hipErrorOutOfMemory, 2,
      :hipErrorMemoryAllocation, 2,
      :hipErrorNotInitialized, 3,
      :hipErrorInitializationError, 3,
      :hipErrorDeinitialized, 4,
      :hipErrorProfilerDisabled, 5,
      :hipErrorProfilerNotInitialized, 6,
      :hipErrorProfilerAlreadyStarted, 7,
      :hipErrorProfilerAlreadyStopped, 8,
      :hipErrorInvalidConfiguration, 9,
      :hipErrorInvalidPitchValue, 12,
      :hipErrorInvalidSymbol, 13,
      :hipErrorInvalidDevicePointer, 17,
      :hipErrorInvalidMemcpyDirection, 21,
      :hipErrorInsufficientDriver, 35,
      :hipErrorMissingConfiguration, 52,
      :hipErrorPriorLaunchFailure, 53,
      :hipErrorInvalidDeviceFunction, 98,
      :hipErrorNoDevice, 100,
      :hipErrorInvalidDevice, 101,
      :hipErrorInvalidImage, 200,
      :hipErrorInvalidContext, 201,
      :hipErrorContextAlreadyCurrent, 202,
      :hipErrorMapFailed, 205,
      :hipErrorMapBufferObjectFailed, 205,
      :hipErrorUnmapFailed, 206,
      :hipErrorArrayIsMapped, 207,
      :hipErrorAlreadyMapped, 208,
      :hipErrorNoBinaryForGpu, 209,
      :hipErrorAlreadyAcquired, 210,
      :hipErrorNotMapped, 211,
      :hipErrorNotMappedAsArray, 212,
      :hipErrorNotMappedAsPointer, 213,
      :hipErrorECCNotCorrectable, 214,
      :hipErrorUnsupportedLimit, 215,
      :hipErrorContextAlreadyInUse, 216,
      :hipErrorPeerAccessUnsupported, 217,
      :hipErrorInvalidKernelFile, 218,
      :hipErrorInvalidGraphicsContext, 219,
      :hipErrorInvalidSource, 300,
      :hipErrorFileNotFound, 301,
      :hipErrorSharedObjectSymbolNotFound, 302,
      :hipErrorSharedObjectInitFailed, 303,
      :hipErrorOperatingSystem, 304,
      :hipErrorInvalidHandle, 400,
      :hipErrorInvalidResourceHandle, 400,
      :hipErrorIllegalState, 401,
      :hipErrorNotFound, 500,
      :hipErrorNotReady, 600,
      :hipErrorIllegalAddress, 700,
      :hipErrorLaunchOutOfResources, 701,
      :hipErrorLaunchTimeOut, 702,
      :hipErrorPeerAccessAlreadyEnabled, 704,
      :hipErrorPeerAccessNotEnabled, 705,
      :hipErrorSetOnActiveProcess, 708,
      :hipErrorContextIsDestroyed, 709,
      :hipErrorAssert, 710,
      :hipErrorHostMemoryAlreadyRegistered, 712,
      :hipErrorHostMemoryNotRegistered, 713,
      :hipErrorLaunchFailure, 719,
      :hipErrorCooperativeLaunchTooLarge, 720,
      :hipErrorNotSupported, 801,
      :hipErrorStreamCaptureUnsupported, 900,
      :hipErrorStreamCaptureInvalidated, 901,
      :hipErrorStreamCaptureMerge, 902,
      :hipErrorStreamCaptureUnmatched, 903,
      :hipErrorStreamCaptureUnjoined, 904,
      :hipErrorStreamCaptureIsolation, 905,
      :hipErrorStreamCaptureImplicit, 906,
      :hipErrorCapturedEvent, 907,
      :hipErrorStreamCaptureWrongThread, 908,
      :hipErrorGraphExecUpdateFailure, 910,
      :hipErrorUnknown, 999,
      :hipErrorRuntimeMemory, 1052,
      :hipErrorRuntimeOther, 1053,
      :hipErrorTbd ]

  HipDeviceAttribute_t = hipenum :hipDeviceAttribute_t,
    [ :hipDeviceAttributeCudaCompatibleBegin, 0,
      :hipDeviceAttributeEccEnabled, hipDeviceAttributeCudaCompatibleBegin,
      :hipDeviceAttributeAccessPolicyMaxWindowSize,
      :hipDeviceAttributeAsyncEngineCount,
      :hipDeviceAttributeCanMapHostMemory,
      :hipDeviceAttributeCanUseHostPointerForRegisteredMem,
      :hipDeviceAttributeClockRate,
      :hipDeviceAttributeComputeMode,
      :hipDeviceAttributeComputePreemptionSupported,
      :hipDeviceAttributeConcurrentKernels,
      :hipDeviceAttributeConcurrentManagedAccess,
      :hipDeviceAttributeCooperativeLaunch,
      :hipDeviceAttributeCooperativeMultiDeviceLaunch,
      :hipDeviceAttributeDeviceOverlap,
      :hipDeviceAttributeDirectManagedMemAccessFromHost,
      :hipDeviceAttributeGlobalL1CacheSupported,
      :hipDeviceAttributeHostNativeAtomicSupported,
      :hipDeviceAttributeIntegrated,
      :hipDeviceAttributeIsMultiGpuBoard,
      :hipDeviceAttributeKernelExecTimeout,
      :hipDeviceAttributeL2CacheSize,
      :hipDeviceAttributeLocalL1CacheSupported,
      :hipDeviceAttributeLuid,
      :hipDeviceAttributeLuidDeviceNodeMask,
      :hipDeviceAttributeComputeCapabilityMajor,
      :hipDeviceAttributeManagedMemory,
      :hipDeviceAttributeMaxBlocksPerMultiProcessor,
      :hipDeviceAttributeMaxBlockDimX,
      :hipDeviceAttributeMaxBlockDimY,
      :hipDeviceAttributeMaxBlockDimZ,
      :hipDeviceAttributeMaxGridDimX,
      :hipDeviceAttributeMaxGridDimY,
      :hipDeviceAttributeMaxGridDimZ,
      :hipDeviceAttributeMaxSurface1D,
      :hipDeviceAttributeMaxSurface1DLayered,
      :hipDeviceAttributeMaxSurface2D,
      :hipDeviceAttributeMaxSurface2DLayered,
      :hipDeviceAttributeMaxSurface3D,
      :hipDeviceAttributeMaxSurfaceCubemap,
      :hipDeviceAttributeMaxSurfaceCubemapLayered,
      :hipDeviceAttributeMaxTexture1DWidth,
      :hipDeviceAttributeMaxTexture1DLayered,
      :hipDeviceAttributeMaxTexture1DLinear,
      :hipDeviceAttributeMaxTexture1DMipmap,
      :hipDeviceAttributeMaxTexture2DWidth,
      :hipDeviceAttributeMaxTexture2DHeight,
      :hipDeviceAttributeMaxTexture2DGather,
      :hipDeviceAttributeMaxTexture2DLayered,
      :hipDeviceAttributeMaxTexture2DLinear,
      :hipDeviceAttributeMaxTexture2DMipmap,
      :hipDeviceAttributeMaxTexture3DWidth,
      :hipDeviceAttributeMaxTexture3DHeight,
      :hipDeviceAttributeMaxTexture3DDepth,
      :hipDeviceAttributeMaxTexture3DAlt,
      :hipDeviceAttributeMaxTextureCubemap,
      :hipDeviceAttributeMaxTextureCubemapLayered,
      :hipDeviceAttributeMaxThreadsDim,
      :hipDeviceAttributeMaxThreadsPerBlock,
      :hipDeviceAttributeMaxThreadsPerMultiProcessor,
      :hipDeviceAttributeMaxPitch,
      :hipDeviceAttributeMemoryBusWidth,
      :hipDeviceAttributeMemoryClockRate,
      :hipDeviceAttributeComputeCapabilityMinor,
      :hipDeviceAttributeMultiGpuBoardGroupID,
      :hipDeviceAttributeMultiprocessorCount,
      :hipDeviceAttributeName,
      :hipDeviceAttributePageableMemoryAccess,
      :hipDeviceAttributePageableMemoryAccessUsesHostPageTables,
      :hipDeviceAttributePciBusId,
      :hipDeviceAttributePciDeviceId,
      :hipDeviceAttributePciDomainID,
      :hipDeviceAttributePersistingL2CacheMaxSize,
      :hipDeviceAttributeMaxRegistersPerBlock,
      :hipDeviceAttributeMaxRegistersPerMultiprocessor,
      :hipDeviceAttributeReservedSharedMemPerBlock,
      :hipDeviceAttributeMaxSharedMemoryPerBlock,
      :hipDeviceAttributeSharedMemPerBlockOptin,
      :hipDeviceAttributeSharedMemPerMultiprocessor,
      :hipDeviceAttributeSingleToDoublePrecisionPerfRatio,
      :hipDeviceAttributeStreamPrioritiesSupported,
      :hipDeviceAttributeSurfaceAlignment,
      :hipDeviceAttributeTccDriver,
      :hipDeviceAttributeTextureAlignment,
      :hipDeviceAttributeTexturePitchAlignment,
      :hipDeviceAttributeTotalConstantMemory,
      :hipDeviceAttributeTotalGlobalMem,
      :hipDeviceAttributeUnifiedAddressing,
      :hipDeviceAttributeUuid,
      :hipDeviceAttributeWarpSize,
      :hipDeviceAttributeMemoryPoolsSupported,
      :hipDeviceAttributeVirtualMemoryManagementSupported,
      :hipDeviceAttributeCudaCompatibleEnd, 9999,
      :hipDeviceAttributeAmdSpecificBegin, 10000,
      :hipDeviceAttributeClockInstructionRate, hipDeviceAttributeAmdSpecificBegin,
      :hipDeviceAttributeArch,
      :hipDeviceAttributeMaxSharedMemoryPerMultiprocessor,
      :hipDeviceAttributeGcnArch,
      :hipDeviceAttributeGcnArchName,
      :hipDeviceAttributeHdpMemFlushCntl,
      :hipDeviceAttributeHdpRegFlushCntl,
      :hipDeviceAttributeCooperativeMultiDeviceUnmatchedFunc,
      :hipDeviceAttributeCooperativeMultiDeviceUnmatchedGridDim,
      :hipDeviceAttributeCooperativeMultiDeviceUnmatchedBlockDim,
      :hipDeviceAttributeCooperativeMultiDeviceUnmatchedSharedMem,
      :hipDeviceAttributeIsLargeBar,
      :hipDeviceAttributeAsicRevision,
      :hipDeviceAttributeCanUseStreamWaitValue,
      :hipDeviceAttributeImageSupport,
      :hipDeviceAttributePhysicalMultiProcessorCount,
      :hipDeviceAttributeFineGrainSupport,
      :hipDeviceAttributeWallClockRate,
      :hipDeviceAttributeAmdSpecificEnd, 19999,
      :hipDeviceAttributeVendorSpecificBegin, 20000 ]

  typedef :pointer, :hipDeviceptr_t

  HipChannelFormatKind = hipenum :hipChannelFormatKind,
    [ :hipChannelFormatKindSigned, 0,
      :hipChannelFormatKindUnsigned, 1,
      :hipChannelFormatKindFloat, 2,
      :hipChannelFormatKindNone, 3 ]

  class HipChannelFormatDesc < FFI::HIPStruct
    layout :x, :int,
           :y, :int,
           :z, :int,
           :w, :int,
           :f, :hipChannelFormatKind
  end
  typedef HipChannelFormatDesc.by_value, :hipChannelFormatDesc

  HipArray_Format = hipenum :hipArray_Format,
    [ :HIP_AD_FORMAT_UNSIGNED_INT8, 0x1,
      :HIP_AD_FORMAT_UNSIGNED_INT16, 0x2,
      :HIP_AD_FORMAT_UNSIGNED_INT32, 0x3,
      :HIP_AD_FORMAT_SIGNED_INT8, 0x8,
      :HIP_AD_FORMAT_SIGNED_INT16, 0x9,
      :HIP_AD_FORMAT_SIGNED_INT32, 0xa,
      :HIP_AD_FORMAT_HALF, 0x10,
      :HIP_AD_FORMAT_FLOAT, 0x20 ]

  class HIP_ARRAY_DESCRIPTOR < FFI::HIPStruct
    layout :Width, :size_t,
           :Height, :size_t,
           :Format, :hipArray_Format,
           :NumChannels, :uint
  end
  typedef HIP_ARRAY_DESCRIPTOR.by_value, :HIP_ARRAY_DESCRIPTOR

  class HIP_ARRAY3D_DESCRIPTOR < FFI::HIPStruct
    layout :Width, :size_t,
           :Height, :size_t,
           :Depth, :size_t,
           :Format, :hipArray_Format,
           :NumChannels, :uint,
           :Flags, :uint
  end
  typedef HIP_ARRAY3D_DESCRIPTOR.by_value, :HIP_ARRAY3D_DESCRIPTOR

  class HipArray < FFI::HIPStruct
    layout :data, :pointer,
           :desc, :hipChannelFormatDesc,
           :type, :uint,
           :width, :uint,
           :height, :uint,
           :depth, :uint,
           :Format, :hipArray_Format,
           :NumChannels, :uint,
           :isDrv, :bool,
           :textureType, :uint
  end
  typedef HipArray.by_value, :hipArray

  class Hip_Memcpy2D < FFI::HIPStruct
    layout :srcXInBytes, :size_t,
           :srcY, :size_t,
           :srcMemoryType, :hipMemoryType,
           :srcHost, :pointer,
           :srcDevice, :hipDeviceptr_t,
           :srcArray, :pointer,
           :srcPitch, :size_t,
           :dstXInBytes, :size_t,
           :dstY, :size_t,
           :dstMemoryType, :hipMemoryType,
           :dstHost, :pointer,
           :dstDevice, :hipDeviceptr_t,
           :dstArray, :pointer,
           :dstPitch, :size_t,
           :WidthInBytes, :size_t,
           :Height, :size_t
  end
  typedef Hip_Memcpy2D.by_value, :hip_Memcpy2D

  typedef :pointer, :hipArray_t

  typedef :pointer, :hiparray

  typedef :pointer, :hipArray_const_t

  class HipMipmappedArray < FFI::HIPStruct
    layout :data, :pointer,
           :desc, :hipChannelFormatDesc,
           :type, :uint,
           :width, :uint,
           :height, :uint,
           :depth, :uint,
           :min_mipmap_level, :uint,
           :max_mipmap_level, :uint,
           :flags, :uint,
           :format, :hipArray_Format
  end
  typedef HipMipmappedArray.by_value, :hipMipmappedArray

  typedef :pointer, :hipMipmappedArray_t

  typedef :pointer, :hipMipmappedArray_const_t

  HipResourceType = hipenum :hipResourceType,
    [ :hipResourceTypeArray, 0x0,
      :hipResourceTypeMipmappedArray, 0x1,
      :hipResourceTypeLinear, 0x2,
      :hipResourceTypePitch2D, 0x3 ]

  HIPresourcetype = hipenum :HIPresourcetype,
    [ :HIP_RESOURCE_TYPE_ARRAY, 0x0,
      :HIP_RESOURCE_TYPE_MIPMAPPED_ARRAY, 0x1,
      :HIP_RESOURCE_TYPE_LINEAR, 0x2,
      :HIP_RESOURCE_TYPE_PITCH2D, 0x3 ]

  HipResourcetype = hipenum :hipResourcetype,
    [ :HIP_RESOURCE_TYPE_ARRAY, 0x0,
      :HIP_RESOURCE_TYPE_MIPMAPPED_ARRAY, 0x1,
      :HIP_RESOURCE_TYPE_LINEAR, 0x2,
      :HIP_RESOURCE_TYPE_PITCH2D, 0x3 ]

  HIPaddress_mode = hipenum :HIPaddress_mode,
    [ :HIP_TR_ADDRESS_MODE_WRAP, 0,
      :HIP_TR_ADDRESS_MODE_CLAMP, 1,
      :HIP_TR_ADDRESS_MODE_MIRROR, 2,
      :HIP_TR_ADDRESS_MODE_BORDER, 3 ]

  HIPfilter_mode = hipenum :HIPfilter_mode,
    [ :HIP_TR_FILTER_MODE_POINT, 0,
      :HIP_TR_FILTER_MODE_LINEAR, 1 ]

  class HIP_TEXTURE_DESC < FFI::HIPStruct
    layout :addressMode, [ :HIPaddress_mode, 3 ],
           :filterMode, :HIPfilter_mode,
           :flags, :uint,
           :maxAnisotropy, :uint,
           :mipmapFilterMode, :HIPfilter_mode,
           :mipmapLevelBias, :float,
           :minMipmapLevelClamp, :float,
           :maxMipmapLevelClamp, :float,
           :borderColor, [ :float, 4 ],
           :reserved, [ :int, 12 ]
  end
  typedef HIP_TEXTURE_DESC.by_value, :HIP_TEXTURE_DESC

  HipResourceViewFormat = hipenum :hipResourceViewFormat,
    [ :hipResViewFormatNone, 0x0,
      :hipResViewFormatUnsignedChar1, 0x1,
      :hipResViewFormatUnsignedChar2, 0x2,
      :hipResViewFormatUnsignedChar4, 0x3,
      :hipResViewFormatSignedChar1, 0x4,
      :hipResViewFormatSignedChar2, 0x5,
      :hipResViewFormatSignedChar4, 0x6,
      :hipResViewFormatUnsignedShort1, 0x7,
      :hipResViewFormatUnsignedShort2, 0x8,
      :hipResViewFormatUnsignedShort4, 0x9,
      :hipResViewFormatSignedShort1, 0xa,
      :hipResViewFormatSignedShort2, 0xb,
      :hipResViewFormatSignedShort4, 0xc,
      :hipResViewFormatUnsignedInt1, 0xd,
      :hipResViewFormatUnsignedInt2, 0xe,
      :hipResViewFormatUnsignedInt4, 0xf,
      :hipResViewFormatSignedInt1, 0x10,
      :hipResViewFormatSignedInt2, 0x11,
      :hipResViewFormatSignedInt4, 0x12,
      :hipResViewFormatHalf1, 0x13,
      :hipResViewFormatHalf2, 0x14,
      :hipResViewFormatHalf4, 0x15,
      :hipResViewFormatFloat1, 0x16,
      :hipResViewFormatFloat2, 0x17,
      :hipResViewFormatFloat4, 0x18,
      :hipResViewFormatUnsignedBlockCompressed1, 0x19,
      :hipResViewFormatUnsignedBlockCompressed2, 0x1a,
      :hipResViewFormatUnsignedBlockCompressed3, 0x1b,
      :hipResViewFormatUnsignedBlockCompressed4, 0x1c,
      :hipResViewFormatSignedBlockCompressed4, 0x1d,
      :hipResViewFormatUnsignedBlockCompressed5, 0x1e,
      :hipResViewFormatSignedBlockCompressed5, 0x1f,
      :hipResViewFormatUnsignedBlockCompressed6H, 0x20,
      :hipResViewFormatSignedBlockCompressed6H, 0x21,
      :hipResViewFormatUnsignedBlockCompressed7, 0x22 ]

  HIPresourceViewFormat = hipenum :HIPresourceViewFormat,
    [ :HIP_RES_VIEW_FORMAT_NONE, 0x0,
      :HIP_RES_VIEW_FORMAT_UINT_1X8, 0x1,
      :HIP_RES_VIEW_FORMAT_UINT_2X8, 0x2,
      :HIP_RES_VIEW_FORMAT_UINT_4X8, 0x3,
      :HIP_RES_VIEW_FORMAT_SINT_1X8, 0x4,
      :HIP_RES_VIEW_FORMAT_SINT_2X8, 0x5,
      :HIP_RES_VIEW_FORMAT_SINT_4X8, 0x6,
      :HIP_RES_VIEW_FORMAT_UINT_1X16, 0x7,
      :HIP_RES_VIEW_FORMAT_UINT_2X16, 0x8,
      :HIP_RES_VIEW_FORMAT_UINT_4X16, 0x9,
      :HIP_RES_VIEW_FORMAT_SINT_1X16, 0xa,
      :HIP_RES_VIEW_FORMAT_SINT_2X16, 0xb,
      :HIP_RES_VIEW_FORMAT_SINT_4X16, 0xc,
      :HIP_RES_VIEW_FORMAT_UINT_1X32, 0xd,
      :HIP_RES_VIEW_FORMAT_UINT_2X32, 0xe,
      :HIP_RES_VIEW_FORMAT_UINT_4X32, 0xf,
      :HIP_RES_VIEW_FORMAT_SINT_1X32, 0x10,
      :HIP_RES_VIEW_FORMAT_SINT_2X32, 0x11,
      :HIP_RES_VIEW_FORMAT_SINT_4X32, 0x12,
      :HIP_RES_VIEW_FORMAT_FLOAT_1X16, 0x13,
      :HIP_RES_VIEW_FORMAT_FLOAT_2X16, 0x14,
      :HIP_RES_VIEW_FORMAT_FLOAT_4X16, 0x15,
      :HIP_RES_VIEW_FORMAT_FLOAT_1X32, 0x16,
      :HIP_RES_VIEW_FORMAT_FLOAT_2X32, 0x17,
      :HIP_RES_VIEW_FORMAT_FLOAT_4X32, 0x18,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC1, 0x19,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC2, 0x1a,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC3, 0x1b,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC4, 0x1c,
      :HIP_RES_VIEW_FORMAT_SIGNED_BC4, 0x1d,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC5, 0x1e,
      :HIP_RES_VIEW_FORMAT_SIGNED_BC5, 0x1f,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC6H, 0x20,
      :HIP_RES_VIEW_FORMAT_SIGNED_BC6H, 0x21,
      :HIP_RES_VIEW_FORMAT_UNSIGNED_BC7, 0x22 ]

  class HipResourceDesc < FFI::HIPStruct
    layout :resType, :hipResourceType,
           :res, (Class::new(FFI::HIPUnion) { layout :array, (Class::new(FFI::HIPStruct) { layout :array, :hipArray_t }.by_value), :mipmap, (Class::new(FFI::HIPStruct) { layout :mipmap, :hipMipmappedArray_t }.by_value), :linear, (Class::new(FFI::HIPStruct) { layout :devPtr, :pointer, :desc, :hipChannelFormatDesc, :sizeInBytes, :size_t }.by_value), :pitch2D, (Class::new(FFI::HIPStruct) { layout :devPtr, :pointer, :desc, :hipChannelFormatDesc, :width, :size_t, :height, :size_t, :pitchInBytes, :size_t }.by_value) }.by_value)
  end
  typedef HipResourceDesc.by_value, :hipResourceDesc

  class HIP_RESOURCE_DESC < FFI::HIPStruct
    layout :resType, :HIPresourcetype,
           :res, (Class::new(FFI::HIPUnion) { layout :array, (Class::new(FFI::HIPStruct) { layout :hArray, :hipArray_t }.by_value), :mipmap, (Class::new(FFI::HIPStruct) { layout :hMipmappedArray, :hipMipmappedArray_t }.by_value), :linear, (Class::new(FFI::HIPStruct) { layout :devPtr, :hipDeviceptr_t, :format, :hipArray_Format, :numChannels, :uint, :sizeInBytes, :size_t }.by_value), :pitch2D, (Class::new(FFI::HIPStruct) { layout :devPtr, :hipDeviceptr_t, :format, :hipArray_Format, :numChannels, :uint, :width, :size_t, :height, :size_t, :pitchInBytes, :size_t }.by_value), :reserved, (Class::new(FFI::HIPStruct) { layout :reserved, [ :int, 32 ] }.by_value) }.by_value),
           :flags, :uint
  end
  typedef HIP_RESOURCE_DESC.by_value, :HIP_RESOURCE_DESC

  class HIP_RESOURCE_VIEW_DESC < FFI::HIPStruct
    layout :format, :HIPresourceViewFormat,
           :width, :size_t,
           :height, :size_t,
           :depth, :size_t,
           :firstMipmapLevel, :uint,
           :lastMipmapLevel, :uint,
           :firstLayer, :uint,
           :lastLayer, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef HIP_RESOURCE_VIEW_DESC.by_value, :HIP_RESOURCE_VIEW_DESC

  HipMemcpyKind = hipenum :hipMemcpyKind,
    [ :hipMemcpyHostToHost, 0,
      :hipMemcpyHostToDevice, 1,
      :hipMemcpyDeviceToHost, 2,
      :hipMemcpyDeviceToDevice, 3,
      :hipMemcpyDefault, 4 ]

  class HipPitchedPtr < FFI::HIPStruct
    layout :ptr, :pointer,
           :pitch, :size_t,
           :xsize, :size_t,
           :ysize, :size_t
  end
  typedef HipPitchedPtr.by_value, :hipPitchedPtr

  class HipExtent < FFI::HIPStruct
    layout :width, :size_t,
           :height, :size_t,
           :depth, :size_t
  end
  typedef HipExtent.by_value, :hipExtent

  class HipPos < FFI::HIPStruct
    layout :x, :size_t,
           :y, :size_t,
           :z, :size_t
  end
  typedef HipPos.by_value, :hipPos

  class HipMemcpy3DParms < FFI::HIPStruct
    layout :srcArray, :hipArray_t,
           :srcPos, :hipPos,
           :srcPtr, :hipPitchedPtr,
           :dstArray, :hipArray_t,
           :dstPos, :hipPos,
           :dstPtr, :hipPitchedPtr,
           :extent, :hipExtent,
           :kind, :hipMemcpyKind
  end
  typedef HipMemcpy3DParms.by_value, :hipMemcpy3DParms

  class HIP_MEMCPY3D < FFI::HIPStruct
    layout :srcXInBytes, :uint,
           :srcY, :uint,
           :srcZ, :uint,
           :srcLOD, :uint,
           :srcMemoryType, :hipMemoryType,
           :srcHost, :pointer,
           :srcDevice, :hipDeviceptr_t,
           :srcArray, :hipArray_t,
           :srcPitch, :uint,
           :srcHeight, :uint,
           :dstXInBytes, :uint,
           :dstY, :uint,
           :dstZ, :uint,
           :dstLOD, :uint,
           :dstMemoryType, :hipMemoryType,
           :dstHost, :pointer,
           :dstDevice, :hipDeviceptr_t,
           :dstArray, :hipArray_t,
           :dstPitch, :uint,
           :dstHeight, :uint,
           :WidthInBytes, :uint,
           :Height, :uint,
           :Depth, :uint
  end
  typedef HIP_MEMCPY3D.by_value, :HIP_MEMCPY3D

  HipFunction_attribute = hipenum :hipFunction_attribute,
    [ :HIP_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
      :HIP_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
      :HIP_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
      :HIP_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
      :HIP_FUNC_ATTRIBUTE_NUM_REGS,
      :HIP_FUNC_ATTRIBUTE_PTX_VERSION,
      :HIP_FUNC_ATTRIBUTE_BINARY_VERSION,
      :HIP_FUNC_ATTRIBUTE_CACHE_MODE_CA,
      :HIP_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES,
      :HIP_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT,
      :HIP_FUNC_ATTRIBUTE_MAX ]

  HipPointer_attribute = hipenum :hipPointer_attribute,
    [ :HIP_POINTER_ATTRIBUTE_CONTEXT, 1,
      :HIP_POINTER_ATTRIBUTE_MEMORY_TYPE,
      :HIP_POINTER_ATTRIBUTE_DEVICE_POINTER,
      :HIP_POINTER_ATTRIBUTE_HOST_POINTER,
      :HIP_POINTER_ATTRIBUTE_P2P_TOKENS,
      :HIP_POINTER_ATTRIBUTE_SYNC_MEMOPS,
      :HIP_POINTER_ATTRIBUTE_BUFFER_ID,
      :HIP_POINTER_ATTRIBUTE_IS_MANAGED,
      :HIP_POINTER_ATTRIBUTE_DEVICE_ORDINAL,
      :HIP_POINTER_ATTRIBUTE_IS_LEGACY_HIP_IPC_CAPABLE,
      :HIP_POINTER_ATTRIBUTE_RANGE_START_ADDR,
      :HIP_POINTER_ATTRIBUTE_RANGE_SIZE,
      :HIP_POINTER_ATTRIBUTE_MAPPED,
      :HIP_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES,
      :HIP_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE,
      :HIP_POINTER_ATTRIBUTE_ACCESS_FLAGS,
      :HIP_POINTER_ATTRIBUTE_MEMPOOL_HANDLE ]

  class Uchar1 < FFI::HIPStruct
    layout :x, :uchar
  end
  typedef Uchar1.by_value, :uchar1

  class Uchar2 < FFI::HIPStruct
    layout :x, :uchar,
           :y, :uchar
  end
  typedef Uchar2.by_value, :uchar2

  class Uchar3 < FFI::HIPStruct
    layout :x, :uchar,
           :y, :uchar,
           :z, :uchar
  end
  typedef Uchar3.by_value, :uchar3

  class Uchar4 < FFI::HIPStruct
    layout :x, :uchar,
           :y, :uchar,
           :z, :uchar,
           :w, :uchar
  end
  typedef Uchar4.by_value, :uchar4

  class Char1 < FFI::HIPStruct
    layout :x, :char
  end
  typedef Char1.by_value, :char1

  class Char2 < FFI::HIPStruct
    layout :x, :char,
           :y, :char
  end
  typedef Char2.by_value, :char2

  class Char3 < FFI::HIPStruct
    layout :x, :char,
           :y, :char,
           :z, :char
  end
  typedef Char3.by_value, :char3

  class Char4 < FFI::HIPStruct
    layout :x, :char,
           :y, :char,
           :z, :char,
           :w, :char
  end
  typedef Char4.by_value, :char4

  class Ushort1 < FFI::HIPStruct
    layout :x, :ushort
  end
  typedef Ushort1.by_value, :ushort1

  class Ushort2 < FFI::HIPStruct
    layout :x, :ushort,
           :y, :ushort
  end
  typedef Ushort2.by_value, :ushort2

  class Ushort3 < FFI::HIPStruct
    layout :x, :ushort,
           :y, :ushort,
           :z, :ushort
  end
  typedef Ushort3.by_value, :ushort3

  class Ushort4 < FFI::HIPStruct
    layout :x, :ushort,
           :y, :ushort,
           :z, :ushort,
           :w, :ushort
  end
  typedef Ushort4.by_value, :ushort4

  class Short1 < FFI::HIPStruct
    layout :x, :short
  end
  typedef Short1.by_value, :short1

  class Short2 < FFI::HIPStruct
    layout :x, :short,
           :y, :short
  end
  typedef Short2.by_value, :short2

  class Short3 < FFI::HIPStruct
    layout :x, :short,
           :y, :short,
           :z, :short
  end
  typedef Short3.by_value, :short3

  class Short4 < FFI::HIPStruct
    layout :x, :short,
           :y, :short,
           :z, :short,
           :w, :short
  end
  typedef Short4.by_value, :short4

  class Uint1 < FFI::HIPStruct
    layout :x, :uint
  end
  typedef Uint1.by_value, :uint1

  class Uint2 < FFI::HIPStruct
    layout :x, :uint,
           :y, :uint
  end
  typedef Uint2.by_value, :uint2

  class Uint3 < FFI::HIPStruct
    layout :x, :uint,
           :y, :uint,
           :z, :uint
  end
  typedef Uint3.by_value, :uint3

  class Uint4 < FFI::HIPStruct
    layout :x, :uint,
           :y, :uint,
           :z, :uint,
           :w, :uint
  end
  typedef Uint4.by_value, :uint4

  class Int1 < FFI::HIPStruct
    layout :x, :int
  end
  typedef Int1.by_value, :int1

  class Int2 < FFI::HIPStruct
    layout :x, :int,
           :y, :int
  end
  typedef Int2.by_value, :int2

  class Int3 < FFI::HIPStruct
    layout :x, :int,
           :y, :int,
           :z, :int
  end
  typedef Int3.by_value, :int3

  class Int4 < FFI::HIPStruct
    layout :x, :int,
           :y, :int,
           :z, :int,
           :w, :int
  end
  typedef Int4.by_value, :int4

  class Ulong1 < FFI::HIPStruct
    layout :x, :ulong
  end
  typedef Ulong1.by_value, :ulong1

  class Ulong2 < FFI::HIPStruct
    layout :x, :ulong,
           :y, :ulong
  end
  typedef Ulong2.by_value, :ulong2

  class Ulong3 < FFI::HIPStruct
    layout :x, :ulong,
           :y, :ulong,
           :z, :ulong
  end
  typedef Ulong3.by_value, :ulong3

  class Ulong4 < FFI::HIPStruct
    layout :x, :ulong,
           :y, :ulong,
           :z, :ulong,
           :w, :ulong
  end
  typedef Ulong4.by_value, :ulong4

  class Long1 < FFI::HIPStruct
    layout :x, :long
  end
  typedef Long1.by_value, :long1

  class Long2 < FFI::HIPStruct
    layout :x, :long,
           :y, :long
  end
  typedef Long2.by_value, :long2

  class Long3 < FFI::HIPStruct
    layout :x, :long,
           :y, :long,
           :z, :long
  end
  typedef Long3.by_value, :long3

  class Long4 < FFI::HIPStruct
    layout :x, :long,
           :y, :long,
           :z, :long,
           :w, :long
  end
  typedef Long4.by_value, :long4

  class Ulonglong1 < FFI::HIPStruct
    layout :x, :uint64
  end
  typedef Ulonglong1.by_value, :ulonglong1

  class Ulonglong2 < FFI::HIPStruct
    layout :x, :uint64,
           :y, :uint64
  end
  typedef Ulonglong2.by_value, :ulonglong2

  class Ulonglong3 < FFI::HIPStruct
    layout :x, :uint64,
           :y, :uint64,
           :z, :uint64
  end
  typedef Ulonglong3.by_value, :ulonglong3

  class Ulonglong4 < FFI::HIPStruct
    layout :x, :uint64,
           :y, :uint64,
           :z, :uint64,
           :w, :uint64
  end
  typedef Ulonglong4.by_value, :ulonglong4

  class Longlong1 < FFI::HIPStruct
    layout :x, :int64
  end
  typedef Longlong1.by_value, :longlong1

  class Longlong2 < FFI::HIPStruct
    layout :x, :int64,
           :y, :int64
  end
  typedef Longlong2.by_value, :longlong2

  class Longlong3 < FFI::HIPStruct
    layout :x, :int64,
           :y, :int64,
           :z, :int64
  end
  typedef Longlong3.by_value, :longlong3

  class Longlong4 < FFI::HIPStruct
    layout :x, :int64,
           :y, :int64,
           :z, :int64,
           :w, :int64
  end
  typedef Longlong4.by_value, :longlong4

  class Float1 < FFI::HIPStruct
    layout :x, :float
  end
  typedef Float1.by_value, :float1

  class Float2 < FFI::HIPStruct
    layout :x, :float,
           :y, :float
  end
  typedef Float2.by_value, :float2

  class Float3 < FFI::HIPStruct
    layout :x, :float,
           :y, :float,
           :z, :float
  end
  typedef Float3.by_value, :float3

  class Float4 < FFI::HIPStruct
    layout :x, :float,
           :y, :float,
           :z, :float,
           :w, :float
  end
  typedef Float4.by_value, :float4

  class Double1 < FFI::HIPStruct
    layout :x, :double
  end
  typedef Double1.by_value, :double1

  class Double2 < FFI::HIPStruct
    layout :x, :double,
           :y, :double
  end
  typedef Double2.by_value, :double2

  class Double3 < FFI::HIPStruct
    layout :x, :double,
           :y, :double,
           :z, :double
  end
  typedef Double3.by_value, :double3

  class Double4 < FFI::HIPStruct
    layout :x, :double,
           :y, :double,
           :z, :double,
           :w, :double
  end
  typedef Double4.by_value, :double4

  typedef :pointer, :hipTextureObject_t

  class TextureReference < FFI::HIPStruct
    layout :normalized, :int,
           :readMode, :hipTextureReadMode,
           :filterMode, :hipTextureFilterMode,
           :addressMode, [ :hipTextureAddressMode, 3 ],
           :channelDesc, :hipChannelFormatDesc,
           :sRGB, :int,
           :maxAnisotropy, :uint,
           :mipmapFilterMode, :hipTextureFilterMode,
           :mipmapLevelBias, :float,
           :minMipmapLevelClamp, :float,
           :maxMipmapLevelClamp, :float,
           :textureObject, :hipTextureObject_t,
           :numChannels, :int,
           :format, :hipArray_Format
  end
  typedef TextureReference.by_value, :textureReference

  class HipTextureDesc < FFI::HIPStruct
    layout :addressMode, [ :hipTextureAddressMode, 3 ],
           :filterMode, :hipTextureFilterMode,
           :readMode, :hipTextureReadMode,
           :sRGB, :int,
           :borderColor, [ :float, 4 ],
           :normalizedCoords, :int,
           :maxAnisotropy, :uint,
           :mipmapFilterMode, :hipTextureFilterMode,
           :mipmapLevelBias, :float,
           :minMipmapLevelClamp, :float,
           :maxMipmapLevelClamp, :float
  end
  typedef HipTextureDesc.by_value, :hipTextureDesc

  typedef :pointer, :hipSurfaceObject_t

  typedef :pointer, :hipCtx_t

  typedef :int, :hipDevice_t
  HipDeviceP2PAttr = hipenum :hipDeviceP2PAttr,
    [ :hipDevP2PAttrPerformanceRank, 0,
      :hipDevP2PAttrAccessSupported,
      :hipDevP2PAttrNativeAtomicSupported,
      :hipDevP2PAttrHipArrayAccessSupported ]

  typedef :pointer, :hipStream_t

  class HipIpcMemHandle_t < FFI::HIPStruct
    layout :reserved, [ :char, HIP_IPC_HANDLE_SIZE ]
  end
  typedef HipIpcMemHandle_t.by_value, :hipIpcMemHandle_t

  class HipIpcEventHandle_t < FFI::HIPStruct
    layout :reserved, [ :char, HIP_IPC_HANDLE_SIZE ]
  end
  typedef HipIpcEventHandle_t.by_value, :hipIpcEventHandle_t

  typedef :pointer, :hipModule_t

  typedef :pointer, :hipFunction_t

  typedef :pointer, :hipMemPool_t

  class HipFuncAttributes < FFI::HIPStruct
    layout :binaryVersion, :int,
           :cacheModeCA, :int,
           :constSizeBytes, :size_t,
           :localSizeBytes, :size_t,
           :maxDynamicSharedSizeBytes, :int,
           :maxThreadsPerBlock, :int,
           :numRegs, :int,
           :preferredShmemCarveout, :int,
           :ptxVersion, :int,
           :sharedSizeBytes, :size_t
  end
  typedef HipFuncAttributes.by_value, :hipFuncAttributes

  typedef :pointer, :hipEvent_t

  HipMemoryAdvise = hipenum :hipMemoryAdvise,
    [ :hipMemAdviseSetReadMostly, 1,
      :hipMemAdviseUnsetReadMostly, 2,
      :hipMemAdviseSetPreferredLocation, 3,
      :hipMemAdviseUnsetPreferredLocation, 4,
      :hipMemAdviseSetAccessedBy, 5,
      :hipMemAdviseUnsetAccessedBy, 6,
      :hipMemAdviseSetCoarseGrain, 100,
      :hipMemAdviseUnsetCoarseGrain, 101 ]

  HipMemRangeCoherencyMode = hipenum :hipMemRangeCoherencyMode,
    [ :hipMemRangeCoherencyModeFineGrain, 0,
      :hipMemRangeCoherencyModeCoarseGrain, 1,
      :hipMemRangeCoherencyModeIndeterminate, 2 ]

  HipMemRangeAttribute = hipenum :hipMemRangeAttribute,
    [ :hipMemRangeAttributeReadMostly, 1,
      :hipMemRangeAttributePreferredLocation, 2,
      :hipMemRangeAttributeAccessedBy, 3,
      :hipMemRangeAttributeLastPrefetchLocation, 4,
      :hipMemRangeAttributeCoherencyMode, 100 ]

  HipMemPoolAttr = hipenum :hipMemPoolAttr,
    [ :hipMemPoolReuseFollowEventDependencies, 0x1,
      :hipMemPoolReuseAllowOpportunistic, 0x2,
      :hipMemPoolReuseAllowInternalDependencies, 0x3,
      :hipMemPoolAttrReleaseThreshold, 0x4,
      :hipMemPoolAttrReservedMemCurrent, 0x5,
      :hipMemPoolAttrReservedMemHigh, 0x6,
      :hipMemPoolAttrUsedMemCurrent, 0x7,
      :hipMemPoolAttrUsedMemHigh, 0x8 ]

  HipMemLocationType = hipenum :hipMemLocationType,
    [ :hipMemLocationTypeInvalid, 0,
      :hipMemLocationTypeDevice, 1 ]

  class HipMemLocation < FFI::HIPStruct
    layout :type, :hipMemLocationType,
           :id, :int
  end
  typedef HipMemLocation.by_value, :hipMemLocation

  HipMemAccessFlags = hipenum :hipMemAccessFlags,
    [ :hipMemAccessFlagsProtNone, 0,
      :hipMemAccessFlagsProtRead, 1,
      :hipMemAccessFlagsProtReadWrite, 3 ]

  class HipMemAccessDesc < FFI::HIPStruct
    layout :location, :hipMemLocation,
           :flags, :hipMemAccessFlags
  end
  typedef HipMemAccessDesc.by_value, :hipMemAccessDesc

  HipMemAllocationType = hipenum :hipMemAllocationType,
    [ :hipMemAllocationTypeInvalid, 0x0,
      :hipMemAllocationTypePinned, 0x1,
      :hipMemAllocationTypeMax, 0x7fffffff ]

  HipMemAllocationHandleType = hipenum :hipMemAllocationHandleType,
    [ :hipMemHandleTypeNone, 0x0,
      :hipMemHandleTypePosixFileDescriptor, 0x1,
      :hipMemHandleTypeWin32, 0x2,
      :hipMemHandleTypeWin32Kmt, 0x4 ]

  class HipMemPoolProps < FFI::HIPStruct
    layout :allocType, :hipMemAllocationType,
           :handleTypes, :hipMemAllocationHandleType,
           :location, :hipMemLocation,
           :win32SecurityAttributes, :pointer,
           :reserved, [ :uchar, 64 ]
  end
  typedef HipMemPoolProps.by_value, :hipMemPoolProps

  class HipMemPoolPtrExportData < FFI::HIPStruct
    layout :reserved, [ :uchar, 64 ]
  end
  typedef HipMemPoolPtrExportData.by_value, :hipMemPoolPtrExportData

  HipJitOption = hipenum :hipJitOption,
    [ :hipJitOptionMaxRegisters, 0,
      :hipJitOptionThreadsPerBlock,
      :hipJitOptionWallTime,
      :hipJitOptionInfoLogBuffer,
      :hipJitOptionInfoLogBufferSizeBytes,
      :hipJitOptionErrorLogBuffer,
      :hipJitOptionErrorLogBufferSizeBytes,
      :hipJitOptionOptimizationLevel,
      :hipJitOptionTargetFromContext,
      :hipJitOptionTarget,
      :hipJitOptionFallbackStrategy,
      :hipJitOptionGenerateDebugInfo,
      :hipJitOptionLogVerbose,
      :hipJitOptionGenerateLineInfo,
      :hipJitOptionCacheMode,
      :hipJitOptionSm3xOpt,
      :hipJitOptionFastCompile,
      :hipJitOptionNumOptions ]

  HipFuncAttribute = hipenum :hipFuncAttribute,
    [ :hipFuncAttributeMaxDynamicSharedMemorySize, 8,
      :hipFuncAttributePreferredSharedMemoryCarveout, 9,
      :hipFuncAttributeMax ]

  HipFuncCache_t = hipenum :hipFuncCache_t,
    [ :hipFuncCachePreferNone,
      :hipFuncCachePreferShared,
      :hipFuncCachePreferL1,
      :hipFuncCachePreferEqual ]

  HipSharedMemConfig = hipenum :hipSharedMemConfig,
    [ :hipSharedMemBankSizeDefault,
      :hipSharedMemBankSizeFourByte,
      :hipSharedMemBankSizeEightByte ]

  class Dim3 < FFI::HIPStruct
    layout :x, :uint32,
           :y, :uint32,
           :z, :uint32
  end
  typedef Dim3.by_value, :dim3

  class HipLaunchParams < FFI::HIPStruct
    layout :func, :pointer,
           :gridDim, :dim3,
           :blockDim, :dim3,
           :args, :pointer,
           :sharedMem, :size_t,
           :stream, :hipStream_t
  end
  typedef HipLaunchParams.by_value, :hipLaunchParams

  HipExternalMemoryHandleType = hipenum :hipExternalMemoryHandleType,
    [ :hipExternalMemoryHandleTypeOpaqueFd, 1,
      :hipExternalMemoryHandleTypeOpaqueWin32, 2,
      :hipExternalMemoryHandleTypeOpaqueWin32Kmt, 3,
      :hipExternalMemoryHandleTypeD3D12Heap, 4,
      :hipExternalMemoryHandleTypeD3D12Resource, 5,
      :hipExternalMemoryHandleTypeD3D11Resource, 6,
      :hipExternalMemoryHandleTypeD3D11ResourceKmt, 7 ]

  class HipExternalMemoryHandleDesc < FFI::HIPStruct
    layout :type, :hipExternalMemoryHandleType,
           :handle, (Class::new(FFI::HIPUnion) { layout :fd, :int, :win32, (Class::new(FFI::HIPStruct) { layout :handle, :pointer, :name, :pointer }.by_value) }.by_value),
           :size, :uint64,
           :flags, :uint
  end
  typedef HipExternalMemoryHandleDesc.by_value, :hipExternalMemoryHandleDesc

  class HipExternalMemoryBufferDesc < FFI::HIPStruct
    layout :offset, :uint64,
           :size, :uint64,
           :flags, :uint
  end
  typedef HipExternalMemoryBufferDesc.by_value, :hipExternalMemoryBufferDesc

  typedef :pointer, :hipExternalMemory_t

  HipExternalSemaphoreHandleType = hipenum :hipExternalSemaphoreHandleType,
    [ :hipExternalSemaphoreHandleTypeOpaqueFd, 1,
      :hipExternalSemaphoreHandleTypeOpaqueWin32, 2,
      :hipExternalSemaphoreHandleTypeOpaqueWin32Kmt, 3,
      :hipExternalSemaphoreHandleTypeD3D12Fence, 4 ]

  class HipExternalSemaphoreHandleDesc < FFI::HIPStruct
    layout :type, :hipExternalSemaphoreHandleType,
           :handle, (Class::new(FFI::HIPUnion) { layout :fd, :int, :win32, (Class::new(FFI::HIPStruct) { layout :handle, :pointer, :name, :pointer }.by_value) }.by_value),
           :flags, :uint
  end
  typedef HipExternalSemaphoreHandleDesc.by_value, :hipExternalSemaphoreHandleDesc

  typedef :pointer, :hipExternalSemaphore_t

  class HipExternalSemaphoreSignalParams < FFI::HIPStruct
    layout :params, (Class::new(FFI::HIPStruct) { layout :fence, (Class::new(FFI::HIPStruct) { layout :value, :uint64 }.by_value), :keyedMutex, (Class::new(FFI::HIPStruct) { layout :key, :uint64 }.by_value), :reserved, [ :uint, 12 ] }.by_value),
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef HipExternalSemaphoreSignalParams.by_value, :hipExternalSemaphoreSignalParams

  class HipExternalSemaphoreWaitParams < FFI::HIPStruct
    layout :params, (Class::new(FFI::HIPStruct) { layout :fence, (Class::new(FFI::HIPStruct) { layout :value, :uint64 }.by_value), :keyedMutex, (Class::new(FFI::HIPStruct) { layout :key, :uint64, :timeoutMs, :uint }.by_value), :reserved, [ :uint, 10 ] }.by_value),
           :flags, :uint,
           :reserved, [ :uint, 16 ]
  end
  typedef HipExternalSemaphoreWaitParams.by_value, :hipExternalSemaphoreWaitParams

  HipGLDeviceList = hipenum :hipGLDeviceList,
    [ :hipGLDeviceListAll, 1,
      :hipGLDeviceListCurrentFrame, 2,
      :hipGLDeviceListNextFrame, 3 ]

  HipGraphicsRegisterFlags = hipenum :hipGraphicsRegisterFlags,
    [ :hipGraphicsRegisterFlagsNone, 0,
      :hipGraphicsRegisterFlagsReadOnly, 1,
      :hipGraphicsRegisterFlagsWriteDiscard, 2,
      :hipGraphicsRegisterFlagsSurfaceLoadStore, 4,
      :hipGraphicsRegisterFlagsTextureGather, 8 ]

  typedef :pointer, :hipGraphicsResource_t

  typedef :pointer, :hipGraph_t

  typedef :pointer, :hipGraphNode_t

  typedef :pointer, :hipGraphExec_t

  typedef :pointer, :hipUserObject_t

  HipGraphNodeType = hipenum :hipGraphNodeType,
    [ :hipGraphNodeTypeKernel, 0,
      :hipGraphNodeTypeMemcpy, 1,
      :hipGraphNodeTypeMemset, 2,
      :hipGraphNodeTypeHost, 3,
      :hipGraphNodeTypeGraph, 4,
      :hipGraphNodeTypeEmpty, 5,
      :hipGraphNodeTypeWaitEvent, 6,
      :hipGraphNodeTypeEventRecord, 7,
      :hipGraphNodeTypeExtSemaphoreSignal, 8,
      :hipGraphNodeTypeExtSemaphoreWait, 9,
      :hipGraphNodeTypeMemcpyFromSymbol, 10,
      :hipGraphNodeTypeMemcpyToSymbol, 11,
      :hipGraphNodeTypeCount ]

  callback :hipHostFn_t,
           [ :pointer ],
           :void

  class HipHostNodeParams < FFI::HIPStruct
    layout :fn, :hipHostFn_t,
           :userData, :pointer
  end
  typedef HipHostNodeParams.by_value, :hipHostNodeParams

  class HipKernelNodeParams < FFI::HIPStruct
    layout :blockDim, :dim3,
           :extra, :pointer,
           :func, :pointer,
           :gridDim, :dim3,
           :kernelParams, :pointer,
           :sharedMemBytes, :uint
  end
  typedef HipKernelNodeParams.by_value, :hipKernelNodeParams

  class HipMemsetParams < FFI::HIPStruct
    layout :dst, :pointer,
           :elementSize, :uint,
           :height, :size_t,
           :pitch, :size_t,
           :value, :uint,
           :width, :size_t
  end
  typedef HipMemsetParams.by_value, :hipMemsetParams

  HipKernelNodeAttrID = hipenum :hipKernelNodeAttrID,
    [ :hipKernelNodeAttributeAccessPolicyWindow, 1,
      :hipKernelNodeAttributeCooperative, 2 ]

  HipAccessProperty = hipenum :hipAccessProperty,
    [ :hipAccessPropertyNormal, 0,
      :hipAccessPropertyStreaming, 1,
      :hipAccessPropertyPersisting, 2 ]

  class HipAccessPolicyWindow < FFI::HIPStruct
    layout :base_ptr, :pointer,
           :hitProp, :hipAccessProperty,
           :hitRatio, :float,
           :missProp, :hipAccessProperty,
           :num_bytes, :size_t
  end
  typedef HipAccessPolicyWindow.by_value, :hipAccessPolicyWindow

  class HipKernelNodeAttrValue < FFI::HIPUnion
    layout :accessPolicyWindow, :hipAccessPolicyWindow,
           :cooperative, :int
  end
  typedef HipKernelNodeAttrValue.by_value, :hipKernelNodeAttrValue

  HipGraphExecUpdateResult = hipenum :hipGraphExecUpdateResult,
    [ :hipGraphExecUpdateSuccess, 0x0,
      :hipGraphExecUpdateError, 0x1,
      :hipGraphExecUpdateErrorTopologyChanged, 0x2,
      :hipGraphExecUpdateErrorNodeTypeChanged, 0x3,
      :hipGraphExecUpdateErrorFunctionChanged, 0x4,
      :hipGraphExecUpdateErrorParametersChanged, 0x5,
      :hipGraphExecUpdateErrorNotSupported, 0x6,
      :hipGraphExecUpdateErrorUnsupportedFunctionChange, 0x7 ]

  HipStreamCaptureMode = hipenum :hipStreamCaptureMode,
    [ :hipStreamCaptureModeGlobal, 0,
      :hipStreamCaptureModeThreadLocal,
      :hipStreamCaptureModeRelaxed ]

  HipStreamCaptureStatus = hipenum :hipStreamCaptureStatus,
    [ :hipStreamCaptureStatusNone, 0,
      :hipStreamCaptureStatusActive,
      :hipStreamCaptureStatusInvalidated ]

  HipStreamUpdateCaptureDependenciesFlags = hipenum :hipStreamUpdateCaptureDependenciesFlags,
    [ :hipStreamAddCaptureDependencies, 0,
      :hipStreamSetCaptureDependencies ]

  HipGraphMemAttributeType = hipenum :hipGraphMemAttributeType,
    [ :hipGraphMemAttrUsedMemCurrent, 0,
      :hipGraphMemAttrUsedMemHigh,
      :hipGraphMemAttrReservedMemCurrent,
      :hipGraphMemAttrReservedMemHigh ]

  HipUserObjectFlags = hipenum :hipUserObjectFlags,
    [ :hipUserObjectNoDestructorSync, 0x1 ]

  HipUserObjectRetainFlags = hipenum :hipUserObjectRetainFlags,
    [ :hipGraphUserObjectMove, 0x1 ]

  HipGraphInstantiateFlags = hipenum :hipGraphInstantiateFlags,
    [ :hipGraphInstantiateFlagAutoFreeOnLaunch, 1 ]

  class HipMemAllocationProp < FFI::HIPStruct
    layout :type, :hipMemAllocationType,
           :requestedHandleType, :hipMemAllocationHandleType,
           :location, :hipMemLocation,
           :win32HandleMetaData, :pointer,
           :allocFlags, (Class::new(FFI::HIPStruct) { layout :compressionType, :uchar, :gpuDirectRDMACapable, :uchar, :usage, :ushort }.by_value)
  end
  typedef HipMemAllocationProp.by_value, :hipMemAllocationProp

  typedef :pointer, :hipMemGenericAllocationHandle_t

  HipMemAllocationGranularity_flags = hipenum :hipMemAllocationGranularity_flags,
    [ :hipMemAllocationGranularityMinimum, 0x0,
      :hipMemAllocationGranularityRecommended, 0x1 ]

  HipMemHandleType = hipenum :hipMemHandleType,
    [ :hipMemHandleTypeGeneric, 0x0 ]

  HipMemOperationType = hipenum :hipMemOperationType,
    [ :hipMemOperationTypeMap, 0x1,
      :hipMemOperationTypeUnmap, 0x2 ]

  HipArraySparseSubresourceType = hipenum :hipArraySparseSubresourceType,
    [ :hipArraySparseSubresourceTypeSparseLevel, 0x0,
      :hipArraySparseSubresourceTypeMiptail, 0x1 ]

  class HipArrayMapInfo < FFI::HIPStruct
    layout :resourceType, :hipResourceType,
           :resource, (Class::new(FFI::HIPUnion) { layout :mipmap, :hipMipmappedArray, :array, :hipArray_t }.by_value),
           :subresourceType, :hipArraySparseSubresourceType,
           :subresource, (Class::new(FFI::HIPUnion) { layout :sparseLevel, (Class::new(FFI::HIPStruct) { layout :level, :uint, :layer, :uint, :offsetX, :uint, :offsetY, :uint, :offsetZ, :uint, :extentWidth, :uint, :extentHeight, :uint, :extentDepth, :uint }.by_value), :miptail, (Class::new(FFI::HIPStruct) { layout :layer, :uint, :offset, :uint64, :size, :uint64 }.by_value) }.by_value),
           :memOperationType, :hipMemOperationType,
           :memHandleType, :hipMemHandleType,
           :memHandle, (Class::new(FFI::HIPUnion) { layout :memHandle, :hipMemGenericAllocationHandle_t }.by_value),
           :offset, :uint64,
           :deviceBitMask, :uint,
           :flags, :uint,
           :reserved, [ :uint, 2 ]
  end
  typedef HipArrayMapInfo.by_value, :hipArrayMapInfo

  callback :hipStreamCallback_t,
           [ :hipStream_t,
             :hipError_t,
             :pointer ],
           :void

  typedef :uint, :GLuint
  typedef :uint, :GLenum
  HiprtcResult = hipenum :hiprtcResult,
    [ :HIPRTC_SUCCESS, 0,
      :HIPRTC_ERROR_OUT_OF_MEMORY, 1,
      :HIPRTC_ERROR_PROGRAM_CREATION_FAILURE, 2,
      :HIPRTC_ERROR_INVALID_INPUT, 3,
      :HIPRTC_ERROR_INVALID_PROGRAM, 4,
      :HIPRTC_ERROR_INVALID_OPTION, 5,
      :HIPRTC_ERROR_COMPILATION, 6,
      :HIPRTC_ERROR_BUILTIN_OPERATION_FAILURE, 7,
      :HIPRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION, 8,
      :HIPRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION, 9,
      :HIPRTC_ERROR_NAME_EXPRESSION_NOT_VALID, 10,
      :HIPRTC_ERROR_INTERNAL_ERROR, 11,
      :HIPRTC_ERROR_LINKING, 100 ]

  HiprtcJIT_option = hipenum :hiprtcJIT_option,
    [ :HIPRTC_JIT_MAX_REGISTERS, 0,
      :HIPRTC_JIT_THREADS_PER_BLOCK,
      :HIPRTC_JIT_WALL_TIME,
      :HIPRTC_JIT_INFO_LOG_BUFFER,
      :HIPRTC_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
      :HIPRTC_JIT_ERROR_LOG_BUFFER,
      :HIPRTC_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
      :HIPRTC_JIT_OPTIMIZATION_LEVEL,
      :HIPRTC_JIT_TARGET_FROM_HIPCONTEXT,
      :HIPRTC_JIT_TARGET,
      :HIPRTC_JIT_FALLBACK_STRATEGY,
      :HIPRTC_JIT_GENERATE_DEBUG_INFO,
      :HIPRTC_JIT_LOG_VERBOSE,
      :HIPRTC_JIT_GENERATE_LINE_INFO,
      :HIPRTC_JIT_CACHE_MODE,
      :HIPRTC_JIT_NEW_SM3X_OPT,
      :HIPRTC_JIT_FAST_COMPILE,
      :HIPRTC_JIT_GLOBAL_SYMBOL_NAMES,
      :HIPRTC_JIT_GLOBAL_SYMBOL_ADDRESS,
      :HIPRTC_JIT_GLOBAL_SYMBOL_COUNT,
      :HIPRTC_JIT_LTO,
      :HIPRTC_JIT_FTZ,
      :HIPRTC_JIT_PREC_DIV,
      :HIPRTC_JIT_PREC_SQRT,
      :HIPRTC_JIT_FMA,
      :HIPRTC_JIT_NUM_OPTIONS ]

  HiprtcJITInputType = hipenum :hiprtcJITInputType,
    [ :HIPRTC_JIT_INPUT_CUBIN, 0,
      :HIPRTC_JIT_INPUT_PTX,
      :HIPRTC_JIT_INPUT_FATBINARY,
      :HIPRTC_JIT_INPUT_OBJECT,
      :HIPRTC_JIT_INPUT_LIBRARY,
      :HIPRTC_JIT_INPUT_NVVM,
      :HIPRTC_JIT_NUM_LEGACY_INPUT_TYPES,
      :HIPRTC_JIT_INPUT_LLVM_BITCODE, 100,
      :HIPRTC_JIT_INPUT_LLVM_BUNDLED_BITCODE, 101,
      :HIPRTC_JIT_INPUT_LLVM_ARCHIVES_OF_BUNDLED_BITCODE, 102,
      :HIPRTC_JIT_NUM_INPUT_TYPES, HIPRTC_JIT_NUM_LEGACY_INPUT_TYPES + 3 ]

  typedef :pointer, :hiprtcLinkState

  typedef :pointer, :hiprtcProgram

  HipDataType = hipenum :hipDataType,
    [ :HIP_R_16F, 2,
      :HIP_R_32F, 0,
      :HIP_R_64F, 1,
      :HIP_C_16F, 6,
      :HIP_C_32F, 4,
      :HIP_C_64F, 5 ]

  HipLibraryPropertyType = hipenum :hipLibraryPropertyType,
    [ :HIP_LIBRARY_MAJOR_VERSION,
      :HIP_LIBRARY_MINOR_VERSION,
      :HIP_LIBRARY_PATCH_LEVEL ]

  Activity_domain_t = hipenum :activity_domain_t,
    [ :ACTIVITY_DOMAIN_HSA_API, 0,
      :ACTIVITY_DOMAIN_HSA_OPS, 1,
      :ACTIVITY_DOMAIN_HIP_OPS, 2,
      :ACTIVITY_DOMAIN_HCC_OPS, ACTIVITY_DOMAIN_HIP_OPS,
      :ACTIVITY_DOMAIN_HIP_VDI, ACTIVITY_DOMAIN_HIP_OPS,
      :ACTIVITY_DOMAIN_HIP_API, 3,
      :ACTIVITY_DOMAIN_KFD_API, 4,
      :ACTIVITY_DOMAIN_EXT_API, 5,
      :ACTIVITY_DOMAIN_ROCTX, 6,
      :ACTIVITY_DOMAIN_HSA_EVT, 7,
      :ACTIVITY_DOMAIN_NUMBER ]

end
