#define CL_TARGET_OPENCL_VERSION 300
#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#define CL_USE_DEPRECATED_OPENCL_2_1_APIS
#define CL_USE_DEPRECATED_OPENCL_2_2_APIS
#include <CL/opencl.h>
#include <CL/cl_gl_ext.h>
#include <CL/cl_egl.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <ffi.h>
#include "uthash.h"
#include "utlist.h"

#include "opencl_tracepoints.h"
#include "opencl_profiling.h"
#include "opencl_source.h"
#include "opencl_dump.h"
#include "opencl_arguments.h"
#include "opencl_build.h"
#include "opencl_devices.h"

#define CONCAT(c,suf) c ## _ ## suf
#define STARTEV(command) CONCAT(command, entry)
#define STOPEV(command) CONCAT(command, exit)
#define do_tracepoint_safe(provider, name, ...)         do_tracepoint(provider, name, __VA_ARGS__)
#define tracepoint_enabled_safe(provider, name)         tracepoint_enabled(provider, name)
#define tracepoint_safe(provider, name, ...)         tracepoint(provider, name, __VA_ARGS__)
#define CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR clCreateEventFromEGLSyncKHR_ptr
#define CL_CREATE_FROM_EGLIMAGE_KHR_PTR clCreateFromEGLImageKHR_ptr
#define CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR clEnqueueAcquireEGLObjectsKHR_ptr
#define CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR clEnqueueReleaseEGLObjectsKHR_ptr
#define CL_RELEASE_DEVICE_EXT_PTR clReleaseDeviceEXT_ptr
#define CL_RETAIN_DEVICE_EXT_PTR clRetainDeviceEXT_ptr
#define CL_CREATE_SUB_DEVICES_EXT_PTR clCreateSubDevicesEXT_ptr
#define CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR clGetKernelSubGroupInfoKHR_ptr
#define CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR clCreateEventFromGLsyncKHR_ptr
#define CL_GET_GLCONTEXT_INFO_KHR_PTR clGetGLContextInfoKHR_ptr
#define CL_CREATE_FROM_GLBUFFER_PTR clCreateFromGLBuffer_ptr
#define CL_CREATE_FROM_GLTEXTURE_PTR clCreateFromGLTexture_ptr
#define CL_CREATE_FROM_GLRENDERBUFFER_PTR clCreateFromGLRenderbuffer_ptr
#define CL_GET_GLOBJECT_INFO_PTR clGetGLObjectInfo_ptr
#define CL_GET_GLTEXTURE_INFO_PTR clGetGLTextureInfo_ptr
#define CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR clEnqueueAcquireGLObjects_ptr
#define CL_ENQUEUE_RELEASE_GLOBJECTS_PTR clEnqueueReleaseGLObjects_ptr
#define CL_CREATE_FROM_GLTEXTURE2_D_PTR clCreateFromGLTexture2D_ptr
#define CL_CREATE_FROM_GLTEXTURE3_D_PTR clCreateFromGLTexture3D_ptr
#define CL_GET_PLATFORM_IDS_PTR clGetPlatformIDs_ptr
#define CL_GET_PLATFORM_INFO_PTR clGetPlatformInfo_ptr
#define CL_GET_DEVICE_IDS_PTR clGetDeviceIDs_ptr
#define CL_GET_DEVICE_INFO_PTR clGetDeviceInfo_ptr
#define CL_CREATE_SUB_DEVICES_PTR clCreateSubDevices_ptr
#define CL_RETAIN_DEVICE_PTR clRetainDevice_ptr
#define CL_RELEASE_DEVICE_PTR clReleaseDevice_ptr
#define CL_SET_DEFAULT_DEVICE_COMMAND_QUEUE_PTR clSetDefaultDeviceCommandQueue_ptr
#define CL_GET_DEVICE_AND_HOST_TIMER_PTR clGetDeviceAndHostTimer_ptr
#define CL_GET_HOST_TIMER_PTR clGetHostTimer_ptr
#define CL_CREATE_CONTEXT_PTR clCreateContext_ptr
#define CL_CREATE_CONTEXT_FROM_TYPE_PTR clCreateContextFromType_ptr
#define CL_RETAIN_CONTEXT_PTR clRetainContext_ptr
#define CL_RELEASE_CONTEXT_PTR clReleaseContext_ptr
#define CL_GET_CONTEXT_INFO_PTR clGetContextInfo_ptr
#define CL_SET_CONTEXT_DESTRUCTOR_CALLBACK_PTR clSetContextDestructorCallback_ptr
#define CL_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_PTR clCreateCommandQueueWithProperties_ptr
#define CL_RETAIN_COMMAND_QUEUE_PTR clRetainCommandQueue_ptr
#define CL_RELEASE_COMMAND_QUEUE_PTR clReleaseCommandQueue_ptr
#define CL_GET_COMMAND_QUEUE_INFO_PTR clGetCommandQueueInfo_ptr
#define CL_CREATE_BUFFER_PTR clCreateBuffer_ptr
#define CL_CREATE_BUFFER_WITH_PROPERTIES_PTR clCreateBufferWithProperties_ptr
#define CL_CREATE_SUB_BUFFER_PTR clCreateSubBuffer_ptr
#define CL_CREATE_IMAGE_PTR clCreateImage_ptr
#define CL_CREATE_IMAGE_WITH_PROPERTIES_PTR clCreateImageWithProperties_ptr
#define CL_CREATE_PIPE_PTR clCreatePipe_ptr
#define CL_RETAIN_MEM_OBJECT_PTR clRetainMemObject_ptr
#define CL_RELEASE_MEM_OBJECT_PTR clReleaseMemObject_ptr
#define CL_GET_SUPPORTED_IMAGE_FORMATS_PTR clGetSupportedImageFormats_ptr
#define CL_GET_MEM_OBJECT_INFO_PTR clGetMemObjectInfo_ptr
#define CL_GET_IMAGE_INFO_PTR clGetImageInfo_ptr
#define CL_GET_PIPE_INFO_PTR clGetPipeInfo_ptr
#define CL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_PTR clSetMemObjectDestructorCallback_ptr
#define CL_SVMALLOC_PTR clSVMAlloc_ptr
#define CL_SVMFREE_PTR clSVMFree_ptr
#define CL_CREATE_SAMPLER_WITH_PROPERTIES_PTR clCreateSamplerWithProperties_ptr
#define CL_RETAIN_SAMPLER_PTR clRetainSampler_ptr
#define CL_RELEASE_SAMPLER_PTR clReleaseSampler_ptr
#define CL_GET_SAMPLER_INFO_PTR clGetSamplerInfo_ptr
#define CL_CREATE_PROGRAM_WITH_SOURCE_PTR clCreateProgramWithSource_ptr
#define CL_CREATE_PROGRAM_WITH_BINARY_PTR clCreateProgramWithBinary_ptr
#define CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_PTR clCreateProgramWithBuiltInKernels_ptr
#define CL_CREATE_PROGRAM_WITH_IL_PTR clCreateProgramWithIL_ptr
#define CL_RETAIN_PROGRAM_PTR clRetainProgram_ptr
#define CL_RELEASE_PROGRAM_PTR clReleaseProgram_ptr
#define CL_BUILD_PROGRAM_PTR clBuildProgram_ptr
#define CL_COMPILE_PROGRAM_PTR clCompileProgram_ptr
#define CL_LINK_PROGRAM_PTR clLinkProgram_ptr
#define CL_SET_PROGRAM_RELEASE_CALLBACK_PTR clSetProgramReleaseCallback_ptr
#define CL_SET_PROGRAM_SPECIALIZATION_CONSTANT_PTR clSetProgramSpecializationConstant_ptr
#define CL_UNLOAD_PLATFORM_COMPILER_PTR clUnloadPlatformCompiler_ptr
#define CL_GET_PROGRAM_INFO_PTR clGetProgramInfo_ptr
#define CL_GET_PROGRAM_BUILD_INFO_PTR clGetProgramBuildInfo_ptr
#define CL_CREATE_KERNEL_PTR clCreateKernel_ptr
#define CL_CREATE_KERNELS_IN_PROGRAM_PTR clCreateKernelsInProgram_ptr
#define CL_CLONE_KERNEL_PTR clCloneKernel_ptr
#define CL_RETAIN_KERNEL_PTR clRetainKernel_ptr
#define CL_RELEASE_KERNEL_PTR clReleaseKernel_ptr
#define CL_SET_KERNEL_ARG_PTR clSetKernelArg_ptr
#define CL_SET_KERNEL_ARG_SVMPOINTER_PTR clSetKernelArgSVMPointer_ptr
#define CL_SET_KERNEL_EXEC_INFO_PTR clSetKernelExecInfo_ptr
#define CL_GET_KERNEL_INFO_PTR clGetKernelInfo_ptr
#define CL_GET_KERNEL_ARG_INFO_PTR clGetKernelArgInfo_ptr
#define CL_GET_KERNEL_WORK_GROUP_INFO_PTR clGetKernelWorkGroupInfo_ptr
#define CL_GET_KERNEL_SUB_GROUP_INFO_PTR clGetKernelSubGroupInfo_ptr
#define CL_WAIT_FOR_EVENTS_PTR clWaitForEvents_ptr
#define CL_GET_EVENT_INFO_PTR clGetEventInfo_ptr
#define CL_CREATE_USER_EVENT_PTR clCreateUserEvent_ptr
#define CL_RETAIN_EVENT_PTR clRetainEvent_ptr
#define CL_RELEASE_EVENT_PTR clReleaseEvent_ptr
#define CL_SET_USER_EVENT_STATUS_PTR clSetUserEventStatus_ptr
#define CL_SET_EVENT_CALLBACK_PTR clSetEventCallback_ptr
#define CL_GET_EVENT_PROFILING_INFO_PTR clGetEventProfilingInfo_ptr
#define CL_FLUSH_PTR clFlush_ptr
#define CL_FINISH_PTR clFinish_ptr
#define CL_ENQUEUE_READ_BUFFER_PTR clEnqueueReadBuffer_ptr
#define CL_ENQUEUE_READ_BUFFER_RECT_PTR clEnqueueReadBufferRect_ptr
#define CL_ENQUEUE_WRITE_BUFFER_PTR clEnqueueWriteBuffer_ptr
#define CL_ENQUEUE_WRITE_BUFFER_RECT_PTR clEnqueueWriteBufferRect_ptr
#define CL_ENQUEUE_FILL_BUFFER_PTR clEnqueueFillBuffer_ptr
#define CL_ENQUEUE_COPY_BUFFER_PTR clEnqueueCopyBuffer_ptr
#define CL_ENQUEUE_COPY_BUFFER_RECT_PTR clEnqueueCopyBufferRect_ptr
#define CL_ENQUEUE_READ_IMAGE_PTR clEnqueueReadImage_ptr
#define CL_ENQUEUE_WRITE_IMAGE_PTR clEnqueueWriteImage_ptr
#define CL_ENQUEUE_FILL_IMAGE_PTR clEnqueueFillImage_ptr
#define CL_ENQUEUE_COPY_IMAGE_PTR clEnqueueCopyImage_ptr
#define CL_ENQUEUE_COPY_IMAGE_TO_BUFFER_PTR clEnqueueCopyImageToBuffer_ptr
#define CL_ENQUEUE_COPY_BUFFER_TO_IMAGE_PTR clEnqueueCopyBufferToImage_ptr
#define CL_ENQUEUE_MAP_BUFFER_PTR clEnqueueMapBuffer_ptr
#define CL_ENQUEUE_MAP_IMAGE_PTR clEnqueueMapImage_ptr
#define CL_ENQUEUE_UNMAP_MEM_OBJECT_PTR clEnqueueUnmapMemObject_ptr
#define CL_ENQUEUE_MIGRATE_MEM_OBJECTS_PTR clEnqueueMigrateMemObjects_ptr
#define CL_ENQUEUE_NDRANGE_KERNEL_PTR clEnqueueNDRangeKernel_ptr
#define CL_ENQUEUE_NATIVE_KERNEL_PTR clEnqueueNativeKernel_ptr
#define CL_ENQUEUE_MARKER_WITH_WAIT_LIST_PTR clEnqueueMarkerWithWaitList_ptr
#define CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR clEnqueueBarrierWithWaitList_ptr
#define CL_ENQUEUE_SVMFREE_PTR clEnqueueSVMFree_ptr
#define CL_ENQUEUE_SVMMEMCPY_PTR clEnqueueSVMMemcpy_ptr
#define CL_ENQUEUE_SVMMEM_FILL_PTR clEnqueueSVMMemFill_ptr
#define CL_ENQUEUE_SVMMAP_PTR clEnqueueSVMMap_ptr
#define CL_ENQUEUE_SVMUNMAP_PTR clEnqueueSVMUnmap_ptr
#define CL_ENQUEUE_SVMMIGRATE_MEM_PTR clEnqueueSVMMigrateMem_ptr
#define CL_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_PTR clGetExtensionFunctionAddressForPlatform_ptr
#define CL_SET_COMMAND_QUEUE_PROPERTY_PTR clSetCommandQueueProperty_ptr
#define CL_CREATE_IMAGE2_D_PTR clCreateImage2D_ptr
#define CL_CREATE_IMAGE3_D_PTR clCreateImage3D_ptr
#define CL_ENQUEUE_MARKER_PTR clEnqueueMarker_ptr
#define CL_ENQUEUE_WAIT_FOR_EVENTS_PTR clEnqueueWaitForEvents_ptr
#define CL_ENQUEUE_BARRIER_PTR clEnqueueBarrier_ptr
#define CL_UNLOAD_COMPILER_PTR clUnloadCompiler_ptr
#define CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR clGetExtensionFunctionAddress_ptr
#define CL_CREATE_COMMAND_QUEUE_PTR clCreateCommandQueue_ptr
#define CL_CREATE_SAMPLER_PTR clCreateSampler_ptr
#define CL_ENQUEUE_TASK_PTR clEnqueueTask_ptr

typedef CL_API_ENTRY cl_event (CL_API_CALL *clCreateEventFromEGLSyncKHR_t)(cl_context, CLeglSyncKHR, CLeglDisplayKHR, cl_int *);
static clCreateEventFromEGLSyncKHR_t  CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromEGLImageKHR_t)(cl_context, CLeglDisplayKHR, CLeglImageKHR, cl_mem_flags, const cl_egl_image_properties_khr *, cl_int *);
static clCreateFromEGLImageKHR_t  CL_CREATE_FROM_EGLIMAGE_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireEGLObjectsKHR_t)(cl_command_queue, cl_uint, const cl_mem *, cl_uint, const cl_event *, cl_event *);
static clEnqueueAcquireEGLObjectsKHR_t  CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseEGLObjectsKHR_t)(cl_command_queue, cl_uint, const cl_mem *, cl_uint, const cl_event *, cl_event *);
static clEnqueueReleaseEGLObjectsKHR_t  CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseDeviceEXT_t)(cl_device_id);
static clReleaseDeviceEXT_t  CL_RELEASE_DEVICE_EXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainDeviceEXT_t)(cl_device_id);
static clRetainDeviceEXT_t  CL_RETAIN_DEVICE_EXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clCreateSubDevicesEXT_t)(cl_device_id, const cl_device_partition_property_ext *, cl_uint, cl_device_id *, cl_uint *);
static clCreateSubDevicesEXT_t  CL_CREATE_SUB_DEVICES_EXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelSubGroupInfoKHR_t)(cl_kernel, cl_device_id, cl_kernel_sub_group_info, size_t, const void *, size_t, void *, size_t *);
static clGetKernelSubGroupInfoKHR_t  CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_event (CL_API_CALL *clCreateEventFromGLsyncKHR_t)(cl_context, cl_GLsync, cl_int *);
static clCreateEventFromGLsyncKHR_t  CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetGLContextInfoKHR_t)(const cl_context_properties *, cl_gl_context_info, size_t, void *, size_t *);
static clGetGLContextInfoKHR_t  CL_GET_GLCONTEXT_INFO_KHR_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromGLBuffer_t)(cl_context, cl_mem_flags, cl_GLuint, int *);
static clCreateFromGLBuffer_t  CL_CREATE_FROM_GLBUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromGLTexture_t)(cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);
static clCreateFromGLTexture_t  CL_CREATE_FROM_GLTEXTURE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromGLRenderbuffer_t)(cl_context, cl_mem_flags, cl_GLuint, cl_int *);
static clCreateFromGLRenderbuffer_t  CL_CREATE_FROM_GLRENDERBUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetGLObjectInfo_t)(cl_mem, cl_gl_object_type *, cl_GLuint *);
static clGetGLObjectInfo_t  CL_GET_GLOBJECT_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetGLTextureInfo_t)(cl_mem, cl_gl_texture_info, size_t, void *, size_t *);
static clGetGLTextureInfo_t  CL_GET_GLTEXTURE_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueAcquireGLObjects_t)(cl_command_queue, cl_uint, const cl_mem *, cl_uint, const cl_event *, cl_event *);
static clEnqueueAcquireGLObjects_t  CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReleaseGLObjects_t)(cl_command_queue, cl_uint, const cl_mem *, cl_uint, const cl_event *, cl_event *);
static clEnqueueReleaseGLObjects_t  CL_ENQUEUE_RELEASE_GLOBJECTS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromGLTexture2D_t)(cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);
static clCreateFromGLTexture2D_t  CL_CREATE_FROM_GLTEXTURE2_D_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateFromGLTexture3D_t)(cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);
static clCreateFromGLTexture3D_t  CL_CREATE_FROM_GLTEXTURE3_D_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetPlatformIDs_t)(cl_uint, cl_platform_id *, cl_uint *);
static clGetPlatformIDs_t  CL_GET_PLATFORM_IDS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetPlatformInfo_t)(cl_platform_id, cl_platform_info, size_t, void *, size_t *);
static clGetPlatformInfo_t  CL_GET_PLATFORM_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceIDs_t)(cl_platform_id, cl_device_type, cl_uint, cl_device_id *, cl_uint *);
static clGetDeviceIDs_t  CL_GET_DEVICE_IDS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceInfo_t)(cl_device_id, cl_device_info, size_t, void *, size_t *);
static clGetDeviceInfo_t  CL_GET_DEVICE_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clCreateSubDevices_t)(cl_device_id, const cl_device_partition_property *, cl_uint, cl_device_id *, cl_uint *);
static clCreateSubDevices_t  CL_CREATE_SUB_DEVICES_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainDevice_t)(cl_device_id);
static clRetainDevice_t  CL_RETAIN_DEVICE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseDevice_t)(cl_device_id);
static clReleaseDevice_t  CL_RELEASE_DEVICE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetDefaultDeviceCommandQueue_t)(cl_context, cl_device_id, cl_command_queue);
static clSetDefaultDeviceCommandQueue_t  CL_SET_DEFAULT_DEVICE_COMMAND_QUEUE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceAndHostTimer_t)(cl_device_id, cl_ulong *, cl_ulong *);
static clGetDeviceAndHostTimer_t  CL_GET_DEVICE_AND_HOST_TIMER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetHostTimer_t)(cl_device_id, cl_ulong *);
static clGetHostTimer_t  CL_GET_HOST_TIMER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_context (CL_API_CALL *clCreateContext_t)(const cl_context_properties *, cl_uint, const cl_device_id *, void (CL_CALLBACK* )(const char* errinfo, const void* private_info, size_t cb, void* user_data), void *, cl_int *);
static clCreateContext_t  CL_CREATE_CONTEXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_context (CL_API_CALL *clCreateContextFromType_t)(const cl_context_properties *, cl_device_type, void (CL_CALLBACK* )(const char* errinfo, const void* private_info, size_t cb, void* user_data), void *, cl_int *);
static clCreateContextFromType_t  CL_CREATE_CONTEXT_FROM_TYPE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainContext_t)(cl_context);
static clRetainContext_t  CL_RETAIN_CONTEXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseContext_t)(cl_context);
static clReleaseContext_t  CL_RELEASE_CONTEXT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetContextInfo_t)(cl_context, cl_context_info, size_t, void *, size_t *);
static clGetContextInfo_t  CL_GET_CONTEXT_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetContextDestructorCallback_t)(cl_context, void (CL_CALLBACK* )(cl_context context, void* user_data), void *);
static clSetContextDestructorCallback_t  CL_SET_CONTEXT_DESTRUCTOR_CALLBACK_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_command_queue (CL_API_CALL *clCreateCommandQueueWithProperties_t)(cl_context, cl_device_id, const cl_queue_properties *, cl_int *);
static clCreateCommandQueueWithProperties_t  CL_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainCommandQueue_t)(cl_command_queue);
static clRetainCommandQueue_t  CL_RETAIN_COMMAND_QUEUE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseCommandQueue_t)(cl_command_queue);
static clReleaseCommandQueue_t  CL_RELEASE_COMMAND_QUEUE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetCommandQueueInfo_t)(cl_command_queue, cl_command_queue_info, size_t, void *, size_t *);
static clGetCommandQueueInfo_t  CL_GET_COMMAND_QUEUE_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateBuffer_t)(cl_context, cl_mem_flags, size_t, void *, cl_int *);
static clCreateBuffer_t  CL_CREATE_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateBufferWithProperties_t)(cl_context, const cl_mem_properties *, cl_mem_flags, size_t, void *, cl_int *);
static clCreateBufferWithProperties_t  CL_CREATE_BUFFER_WITH_PROPERTIES_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateSubBuffer_t)(cl_mem, cl_mem_flags, cl_buffer_create_type, const void *, cl_int *);
static clCreateSubBuffer_t  CL_CREATE_SUB_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateImage_t)(cl_context, cl_mem_flags, const cl_image_format *, const cl_image_desc *, void *, cl_int *);
static clCreateImage_t  CL_CREATE_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateImageWithProperties_t)(cl_context, const cl_mem_properties *, cl_mem_flags, const cl_image_format *, const cl_image_desc *, void *, cl_int *);
static clCreateImageWithProperties_t  CL_CREATE_IMAGE_WITH_PROPERTIES_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreatePipe_t)(cl_context, cl_mem_flags, cl_uint, cl_uint, const cl_pipe_properties *, cl_int *);
static clCreatePipe_t  CL_CREATE_PIPE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainMemObject_t)(cl_mem);
static clRetainMemObject_t  CL_RETAIN_MEM_OBJECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseMemObject_t)(cl_mem);
static clReleaseMemObject_t  CL_RELEASE_MEM_OBJECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetSupportedImageFormats_t)(cl_context, cl_mem_flags, cl_mem_object_type, cl_uint, cl_image_format *, cl_uint *);
static clGetSupportedImageFormats_t  CL_GET_SUPPORTED_IMAGE_FORMATS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetMemObjectInfo_t)(cl_mem, cl_mem_info, size_t, void *, size_t *);
static clGetMemObjectInfo_t  CL_GET_MEM_OBJECT_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetImageInfo_t)(cl_mem, cl_image_info, size_t, void *, size_t *);
static clGetImageInfo_t  CL_GET_IMAGE_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetPipeInfo_t)(cl_mem, cl_pipe_info, size_t, void *, size_t *);
static clGetPipeInfo_t  CL_GET_PIPE_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetMemObjectDestructorCallback_t)(cl_mem, void (CL_CALLBACK* )(cl_mem memobj, void* user_data), void *);
static clSetMemObjectDestructorCallback_t  CL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_PTR = (void *) 0x0;

typedef CL_API_ENTRY void * (CL_API_CALL *clSVMAlloc_t)(cl_context, cl_svm_mem_flags, size_t, cl_uint);
static clSVMAlloc_t  CL_SVMALLOC_PTR = (void *) 0x0;

typedef CL_API_ENTRY void (CL_API_CALL *clSVMFree_t)(cl_context, void *);
static clSVMFree_t  CL_SVMFREE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_sampler (CL_API_CALL *clCreateSamplerWithProperties_t)(cl_context, const cl_sampler_properties *, cl_int *);
static clCreateSamplerWithProperties_t  CL_CREATE_SAMPLER_WITH_PROPERTIES_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainSampler_t)(cl_sampler);
static clRetainSampler_t  CL_RETAIN_SAMPLER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseSampler_t)(cl_sampler);
static clReleaseSampler_t  CL_RELEASE_SAMPLER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetSamplerInfo_t)(cl_sampler, cl_sampler_info, size_t, void *, size_t *);
static clGetSamplerInfo_t  CL_GET_SAMPLER_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithSource_t)(cl_context, cl_uint, const char **, const size_t *, cl_int *);
static clCreateProgramWithSource_t  CL_CREATE_PROGRAM_WITH_SOURCE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithBinary_t)(cl_context, cl_uint, const cl_device_id *, const size_t *, const unsigned char **, cl_int *, cl_int *);
static clCreateProgramWithBinary_t  CL_CREATE_PROGRAM_WITH_BINARY_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithBuiltInKernels_t)(cl_context, cl_uint, const cl_device_id *, const char *, cl_int *);
static clCreateProgramWithBuiltInKernels_t  CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithIL_t)(cl_context, const void *, size_t, cl_int *);
static clCreateProgramWithIL_t  CL_CREATE_PROGRAM_WITH_IL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainProgram_t)(cl_program);
static clRetainProgram_t  CL_RETAIN_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseProgram_t)(cl_program);
static clReleaseProgram_t  CL_RELEASE_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clBuildProgram_t)(cl_program, cl_uint, const cl_device_id *, const char *, void (CL_CALLBACK* )(cl_program program, void* user_data), void *);
static clBuildProgram_t  CL_BUILD_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clCompileProgram_t)(cl_program, cl_uint, const cl_device_id *, const char *, cl_uint, const cl_program *, const char **, void (CL_CALLBACK* )(cl_program program, void* user_data), void *);
static clCompileProgram_t  CL_COMPILE_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clLinkProgram_t)(cl_context, cl_uint, const cl_device_id *, const char *, cl_uint, const cl_program *, void (CL_CALLBACK* )(cl_program program, void* user_data), void *, cl_int *);
static clLinkProgram_t  CL_LINK_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetProgramReleaseCallback_t)(cl_program, void (CL_CALLBACK* )(cl_program program, void* user_data), void *);
static clSetProgramReleaseCallback_t  CL_SET_PROGRAM_RELEASE_CALLBACK_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetProgramSpecializationConstant_t)(cl_program, cl_uint, size_t, const void *);
static clSetProgramSpecializationConstant_t  CL_SET_PROGRAM_SPECIALIZATION_CONSTANT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clUnloadPlatformCompiler_t)(cl_platform_id);
static clUnloadPlatformCompiler_t  CL_UNLOAD_PLATFORM_COMPILER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetProgramInfo_t)(cl_program, cl_program_info, size_t, void *, size_t *);
static clGetProgramInfo_t  CL_GET_PROGRAM_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetProgramBuildInfo_t)(cl_program, cl_device_id, cl_program_build_info, size_t, void *, size_t *);
static clGetProgramBuildInfo_t  CL_GET_PROGRAM_BUILD_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_kernel (CL_API_CALL *clCreateKernel_t)(cl_program, const char *, cl_int *);
static clCreateKernel_t  CL_CREATE_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clCreateKernelsInProgram_t)(cl_program, cl_uint, cl_kernel *, cl_uint *);
static clCreateKernelsInProgram_t  CL_CREATE_KERNELS_IN_PROGRAM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_kernel (CL_API_CALL *clCloneKernel_t)(cl_kernel, cl_int *);
static clCloneKernel_t  CL_CLONE_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainKernel_t)(cl_kernel);
static clRetainKernel_t  CL_RETAIN_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseKernel_t)(cl_kernel);
static clReleaseKernel_t  CL_RELEASE_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetKernelArg_t)(cl_kernel, cl_uint, size_t, const void *);
static clSetKernelArg_t  CL_SET_KERNEL_ARG_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetKernelArgSVMPointer_t)(cl_kernel, cl_uint, const void *);
static clSetKernelArgSVMPointer_t  CL_SET_KERNEL_ARG_SVMPOINTER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetKernelExecInfo_t)(cl_kernel, cl_kernel_exec_info, size_t, const void *);
static clSetKernelExecInfo_t  CL_SET_KERNEL_EXEC_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelInfo_t)(cl_kernel, cl_kernel_info, size_t, void *, size_t *);
static clGetKernelInfo_t  CL_GET_KERNEL_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelArgInfo_t)(cl_kernel, cl_uint, cl_kernel_arg_info, size_t, void *, size_t *);
static clGetKernelArgInfo_t  CL_GET_KERNEL_ARG_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelWorkGroupInfo_t)(cl_kernel, cl_device_id, cl_kernel_work_group_info, size_t, void *, size_t *);
static clGetKernelWorkGroupInfo_t  CL_GET_KERNEL_WORK_GROUP_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelSubGroupInfo_t)(cl_kernel, cl_device_id, cl_kernel_sub_group_info, size_t, const void *, size_t, void *, size_t *);
static clGetKernelSubGroupInfo_t  CL_GET_KERNEL_SUB_GROUP_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clWaitForEvents_t)(cl_uint, const cl_event *);
static clWaitForEvents_t  CL_WAIT_FOR_EVENTS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetEventInfo_t)(cl_event, cl_event_info, size_t, void *, size_t *);
static clGetEventInfo_t  CL_GET_EVENT_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_event (CL_API_CALL *clCreateUserEvent_t)(cl_context, cl_int *);
static clCreateUserEvent_t  CL_CREATE_USER_EVENT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainEvent_t)(cl_event);
static clRetainEvent_t  CL_RETAIN_EVENT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseEvent_t)(cl_event);
static clReleaseEvent_t  CL_RELEASE_EVENT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetUserEventStatus_t)(cl_event, cl_int);
static clSetUserEventStatus_t  CL_SET_USER_EVENT_STATUS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetEventCallback_t)(cl_event, cl_int, void (CL_CALLBACK* )(cl_event event, cl_int event_command_status, void *user_data), void *);
static clSetEventCallback_t  CL_SET_EVENT_CALLBACK_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetEventProfilingInfo_t)(cl_event, cl_profiling_info, size_t, void *, size_t *);
static clGetEventProfilingInfo_t  CL_GET_EVENT_PROFILING_INFO_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clFlush_t)(cl_command_queue);
static clFlush_t  CL_FLUSH_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clFinish_t)(cl_command_queue);
static clFinish_t  CL_FINISH_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReadBuffer_t)(cl_command_queue, cl_mem, cl_bool, size_t, size_t, void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueReadBuffer_t  CL_ENQUEUE_READ_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReadBufferRect_t)(cl_command_queue, cl_mem, cl_bool, const size_t *, const size_t *, const size_t *, size_t, size_t, size_t, size_t, void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueReadBufferRect_t  CL_ENQUEUE_READ_BUFFER_RECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueWriteBuffer_t)(cl_command_queue, cl_mem, cl_bool, size_t, size_t, const void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueWriteBuffer_t  CL_ENQUEUE_WRITE_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueWriteBufferRect_t)(cl_command_queue, cl_mem, cl_bool, const size_t *, const size_t *, const size_t *, size_t, size_t, size_t, size_t, const void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueWriteBufferRect_t  CL_ENQUEUE_WRITE_BUFFER_RECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueFillBuffer_t)(cl_command_queue, cl_mem, const void *, size_t, size_t, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueFillBuffer_t  CL_ENQUEUE_FILL_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueCopyBuffer_t)(cl_command_queue, cl_mem, cl_mem, size_t, size_t, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueCopyBuffer_t  CL_ENQUEUE_COPY_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueCopyBufferRect_t)(cl_command_queue, cl_mem, cl_mem, const size_t *, const size_t *, const size_t *, size_t, size_t, size_t, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueCopyBufferRect_t  CL_ENQUEUE_COPY_BUFFER_RECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueReadImage_t)(cl_command_queue, cl_mem, cl_bool, const size_t *, const size_t *, size_t, size_t, void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueReadImage_t  CL_ENQUEUE_READ_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueWriteImage_t)(cl_command_queue, cl_mem, cl_bool, const size_t *, const size_t *, size_t, size_t, const void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueWriteImage_t  CL_ENQUEUE_WRITE_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueFillImage_t)(cl_command_queue, cl_mem, const void *, const size_t *, const size_t *, cl_uint, const cl_event *, cl_event *);
static clEnqueueFillImage_t  CL_ENQUEUE_FILL_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueCopyImage_t)(cl_command_queue, cl_mem, cl_mem, const size_t *, const size_t *, const size_t *, cl_uint, const cl_event *, cl_event *);
static clEnqueueCopyImage_t  CL_ENQUEUE_COPY_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueCopyImageToBuffer_t)(cl_command_queue, cl_mem, cl_mem, const size_t *, const size_t *, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueCopyImageToBuffer_t  CL_ENQUEUE_COPY_IMAGE_TO_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueCopyBufferToImage_t)(cl_command_queue, cl_mem, cl_mem, size_t, const size_t *, const size_t *, cl_uint, const cl_event *, cl_event *);
static clEnqueueCopyBufferToImage_t  CL_ENQUEUE_COPY_BUFFER_TO_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY void * (CL_API_CALL *clEnqueueMapBuffer_t)(cl_command_queue, cl_mem, cl_bool, cl_map_flags, size_t, size_t, cl_uint, const cl_event *, cl_event *, cl_int *);
static clEnqueueMapBuffer_t  CL_ENQUEUE_MAP_BUFFER_PTR = (void *) 0x0;

typedef CL_API_ENTRY void * (CL_API_CALL *clEnqueueMapImage_t)(cl_command_queue, cl_mem, cl_bool, cl_map_flags, const size_t *, const size_t *, size_t *, size_t *, cl_uint, const cl_event *, cl_event *, cl_int *);
static clEnqueueMapImage_t  CL_ENQUEUE_MAP_IMAGE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueUnmapMemObject_t)(cl_command_queue, cl_mem, void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueUnmapMemObject_t  CL_ENQUEUE_UNMAP_MEM_OBJECT_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMigrateMemObjects_t)(cl_command_queue, cl_uint, const cl_mem *, cl_mem_migration_flags, cl_uint, const cl_event *, cl_event *);
static clEnqueueMigrateMemObjects_t  CL_ENQUEUE_MIGRATE_MEM_OBJECTS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueNDRangeKernel_t)(cl_command_queue, cl_kernel, cl_uint, const size_t *, const size_t *, const size_t *, cl_uint, const cl_event *, cl_event *);
static clEnqueueNDRangeKernel_t  CL_ENQUEUE_NDRANGE_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueNativeKernel_t)(cl_command_queue, void (CL_CALLBACK* )(void*), void *, size_t, cl_uint, const cl_mem *, const void **, cl_uint, const cl_event *, cl_event *);
static clEnqueueNativeKernel_t  CL_ENQUEUE_NATIVE_KERNEL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMarkerWithWaitList_t)(cl_command_queue, cl_uint, const cl_event *, cl_event *);
static clEnqueueMarkerWithWaitList_t  CL_ENQUEUE_MARKER_WITH_WAIT_LIST_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueBarrierWithWaitList_t)(cl_command_queue, cl_uint, const cl_event *, cl_event *);
static clEnqueueBarrierWithWaitList_t  CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMFree_t)(cl_command_queue, cl_uint, void * [], void (CL_CALLBACK* )(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data), void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMFree_t  CL_ENQUEUE_SVMFREE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMMemcpy_t)(cl_command_queue, cl_bool, void *, const void *, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMMemcpy_t  CL_ENQUEUE_SVMMEMCPY_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMMemFill_t)(cl_command_queue, void *, const void *, size_t, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMMemFill_t  CL_ENQUEUE_SVMMEM_FILL_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMMap_t)(cl_command_queue, cl_bool, cl_map_flags, void *, size_t, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMMap_t  CL_ENQUEUE_SVMMAP_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMUnmap_t)(cl_command_queue, void *, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMUnmap_t  CL_ENQUEUE_SVMUNMAP_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueSVMMigrateMem_t)(cl_command_queue, cl_uint, const void **, const size_t *, cl_mem_migration_flags, cl_uint, const cl_event *, cl_event *);
static clEnqueueSVMMigrateMem_t  CL_ENQUEUE_SVMMIGRATE_MEM_PTR = (void *) 0x0;

typedef CL_API_ENTRY void * (CL_API_CALL *clGetExtensionFunctionAddressForPlatform_t)(cl_platform_id, const char *);
static clGetExtensionFunctionAddressForPlatform_t  CL_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetCommandQueueProperty_t)(cl_command_queue, cl_command_queue_properties, cl_bool, cl_command_queue_properties *);
static clSetCommandQueueProperty_t  CL_SET_COMMAND_QUEUE_PROPERTY_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateImage2D_t)(cl_context, cl_mem_flags, const cl_image_format *, size_t, size_t, size_t, void *, cl_int *);
static clCreateImage2D_t  CL_CREATE_IMAGE2_D_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateImage3D_t)(cl_context, cl_mem_flags, const cl_image_format *, size_t, size_t, size_t, size_t, size_t, void *, cl_int *);
static clCreateImage3D_t  CL_CREATE_IMAGE3_D_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMarker_t)(cl_command_queue, cl_event *);
static clEnqueueMarker_t  CL_ENQUEUE_MARKER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueWaitForEvents_t)(cl_command_queue, cl_uint, const cl_event *);
static clEnqueueWaitForEvents_t  CL_ENQUEUE_WAIT_FOR_EVENTS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueBarrier_t)(cl_command_queue);
static clEnqueueBarrier_t  CL_ENQUEUE_BARRIER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clUnloadCompiler_t)(void);
static clUnloadCompiler_t  CL_UNLOAD_COMPILER_PTR = (void *) 0x0;

typedef CL_API_ENTRY void * (CL_API_CALL *clGetExtensionFunctionAddress_t)(const char *);
static clGetExtensionFunctionAddress_t  CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_command_queue (CL_API_CALL *clCreateCommandQueue_t)(cl_context, cl_device_id, cl_command_queue_properties, cl_int *);
static clCreateCommandQueue_t  CL_CREATE_COMMAND_QUEUE_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_sampler (CL_API_CALL *clCreateSampler_t)(cl_context, cl_bool, cl_addressing_mode, cl_filter_mode, cl_int *);
static clCreateSampler_t  CL_CREATE_SAMPLER_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueTask_t)(cl_command_queue, cl_kernel, cl_uint, const cl_event *, cl_event *);
static clEnqueueTask_t  CL_ENQUEUE_TASK_PTR = (void *) 0x0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithILKHR_t)(cl_context, const void *, size_t, cl_int *);
static void clCreateProgramWithILKHR_ffi(ffi_cif *cif, cl_program *ffi_ret, void** args, clCreateProgramWithILKHR_t clCreateProgramWithILKHR_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clTerminateContextKHR_t)(cl_context);
static void clTerminateContextKHR_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clTerminateContextKHR_t clTerminateContextKHR_ptr);

typedef CL_API_ENTRY cl_command_queue (CL_API_CALL *clCreateCommandQueueWithPropertiesKHR_t)(cl_context, cl_device_id, const cl_queue_properties_khr *, cl_int *);
static void clCreateCommandQueueWithPropertiesKHR_ffi(ffi_cif *cif, cl_command_queue *ffi_ret, void** args, clCreateCommandQueueWithPropertiesKHR_t clCreateCommandQueueWithPropertiesKHR_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMigrateMemObjectEXT_t)(cl_command_queue, cl_uint, const cl_mem *, cl_mem_migration_flags_ext, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMigrateMemObjectEXT_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMigrateMemObjectEXT_t clEnqueueMigrateMemObjectEXT_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetKernelSuggestedLocalWorkSizeKHR_t)(cl_command_queue, cl_kernel, cl_uint, const size_t *, const size_t *, size_t *);
static void clGetKernelSuggestedLocalWorkSizeKHR_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetKernelSuggestedLocalWorkSizeKHR_t clGetKernelSuggestedLocalWorkSizeKHR_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetICDLoaderInfoOCLICD_t)(cl_icdl_info, size_t, void *, size_t *);
static void clGetICDLoaderInfoOCLICD_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetICDLoaderInfoOCLICD_t clGetICDLoaderInfoOCLICD_ptr);

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateImageWithPropertiesINTEL_t)(cl_context, const cl_mem_properties_intel *, const cl_image_format *, const cl_image_desc *, void *, cl_int *);
static void clCreateImageWithPropertiesINTEL_ffi(ffi_cif *cif, cl_mem *ffi_ret, void** args, clCreateImageWithPropertiesINTEL_t clCreateImageWithPropertiesINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetImageParamsINTEL_t)(cl_context, const cl_image_format *, const cl_image_desc *, size_t *, size_t *);
static void clGetImageParamsINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetImageParamsINTEL_t clGetImageParamsINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueVerifyMemoryINTEL_t)(cl_command_queue, const void *, const void *, size_t, cl_uint);
static void clEnqueueVerifyMemoryINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueVerifyMemoryINTEL_t clEnqueueVerifyMemoryINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clAddCommentINTEL_t)(cl_device_id, const char *);
static void clAddCommentINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clAddCommentINTEL_t clAddCommentINTEL_ptr);

typedef CL_API_ENTRY cl_command_queue (CL_API_CALL *clCreatePerfCountersCommandQueueINTEL_t)(cl_context, cl_device_id, cl_command_queue_properties, cl_uint, cl_int *);
static void clCreatePerfCountersCommandQueueINTEL_ffi(ffi_cif *cif, cl_command_queue *ffi_ret, void** args, clCreatePerfCountersCommandQueueINTEL_t clCreatePerfCountersCommandQueueINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetPerformanceConfigurationINTEL_t)(cl_device_id, cl_uint, cl_uint *, cl_uint *);
static void clSetPerformanceConfigurationINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clSetPerformanceConfigurationINTEL_t clSetPerformanceConfigurationINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceFunctionPointerINTEL_t)(cl_device_id, cl_program, const char *, cl_ulong *);
static void clGetDeviceFunctionPointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetDeviceFunctionPointerINTEL_t clGetDeviceFunctionPointerINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetDeviceGlobalVariablePointerINTEL_t)(cl_device_id, cl_program, const char *, size_t *, void **);
static void clGetDeviceGlobalVariablePointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetDeviceGlobalVariablePointerINTEL_t clGetDeviceGlobalVariablePointerINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetExecutionInfoINTEL_t)(cl_command_queue, cl_kernel, cl_uint, const size_t *, const size_t *, cl_execution_info_intel, size_t, void *, size_t *);
static void clGetExecutionInfoINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetExecutionInfoINTEL_t clGetExecutionInfoINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueNDRangeKernelINTEL_t)(cl_command_queue, cl_kernel, cl_uint, const size_t *, const size_t *, const size_t *, cl_uint, const cl_event *, cl_event *);
static void clEnqueueNDRangeKernelINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueNDRangeKernelINTEL_t clEnqueueNDRangeKernelINTEL_ptr);

typedef CL_API_ENTRY void * (CL_API_CALL *clHostMemAllocINTEL_t)(cl_context, const cl_mem_properties_intel *, size_t, cl_uint, cl_int *);
static void clHostMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clHostMemAllocINTEL_t clHostMemAllocINTEL_ptr);

typedef CL_API_ENTRY void * (CL_API_CALL *clDeviceMemAllocINTEL_t)(cl_context, cl_device_id, const cl_mem_properties_intel *, size_t, cl_uint, cl_int *);
static void clDeviceMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clDeviceMemAllocINTEL_t clDeviceMemAllocINTEL_ptr);

typedef CL_API_ENTRY void * (CL_API_CALL *clSharedMemAllocINTEL_t)(cl_context, cl_device_id, const cl_mem_properties_intel *, size_t, cl_uint, cl_int *);
static void clSharedMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clSharedMemAllocINTEL_t clSharedMemAllocINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clMemFreeINTEL_t)(cl_context, void *);
static void clMemFreeINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clMemFreeINTEL_t clMemFreeINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetMemAllocInfoINTEL_t)(cl_context, const void *, cl_mem_info_intel, size_t, void *, size_t *);
static void clGetMemAllocInfoINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetMemAllocInfoINTEL_t clGetMemAllocInfoINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clSetKernelArgMemPointerINTEL_t)(cl_kernel, cl_uint, const void *);
static void clSetKernelArgMemPointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clSetKernelArgMemPointerINTEL_t clSetKernelArgMemPointerINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMemsetINTEL_t)(cl_command_queue, void *, cl_int, size_t, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMemsetINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemsetINTEL_t clEnqueueMemsetINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMemFillINTEL_t)(cl_command_queue, void *, const void *, size_t, size_t, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMemFillINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemFillINTEL_t clEnqueueMemFillINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMemcpyINTEL_t)(cl_command_queue, cl_bool, void *, const void *, size_t, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMemcpyINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemcpyINTEL_t clEnqueueMemcpyINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMigrateMemINTEL_t)(cl_command_queue, const void *, size_t, cl_mem_migration_flags, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMigrateMemINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMigrateMemINTEL_t clEnqueueMigrateMemINTEL_ptr);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMemAdviseINTEL_t)(cl_command_queue, const void *, size_t, cl_mem_advice_intel, cl_uint, const cl_event *, cl_event *);
static void clEnqueueMemAdviseINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemAdviseINTEL_t clEnqueueMemAdviseINTEL_ptr);

typedef CL_API_ENTRY cl_mem (CL_API_CALL *clCreateBufferWithPropertiesINTEL_t)(cl_context, const cl_mem_properties_intel *, cl_mem_flags, size_t, void *, cl_int *);
static void clCreateBufferWithPropertiesINTEL_ffi(ffi_cif *cif, cl_mem *ffi_ret, void** args, clCreateBufferWithPropertiesINTEL_t clCreateBufferWithPropertiesINTEL_ptr);

static void find_opencl_symbols(void * handle, int verbose) {

  CL_CREATE_FROM_GLBUFFER_PTR = (clCreateFromGLBuffer_t)(intptr_t)dlsym(handle, "clCreateFromGLBuffer") ;
  if (!CL_CREATE_FROM_GLBUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateFromGLBuffer!\n");

  CL_CREATE_FROM_GLTEXTURE_PTR = (clCreateFromGLTexture_t)(intptr_t)dlsym(handle, "clCreateFromGLTexture") ;
  if (!CL_CREATE_FROM_GLTEXTURE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateFromGLTexture!\n");

  CL_CREATE_FROM_GLRENDERBUFFER_PTR = (clCreateFromGLRenderbuffer_t)(intptr_t)dlsym(handle, "clCreateFromGLRenderbuffer") ;
  if (!CL_CREATE_FROM_GLRENDERBUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateFromGLRenderbuffer!\n");

  CL_GET_GLOBJECT_INFO_PTR = (clGetGLObjectInfo_t)(intptr_t)dlsym(handle, "clGetGLObjectInfo") ;
  if (!CL_GET_GLOBJECT_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetGLObjectInfo!\n");

  CL_GET_GLTEXTURE_INFO_PTR = (clGetGLTextureInfo_t)(intptr_t)dlsym(handle, "clGetGLTextureInfo") ;
  if (!CL_GET_GLTEXTURE_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetGLTextureInfo!\n");

  CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR = (clEnqueueAcquireGLObjects_t)(intptr_t)dlsym(handle, "clEnqueueAcquireGLObjects") ;
  if (!CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueAcquireGLObjects!\n");

  CL_ENQUEUE_RELEASE_GLOBJECTS_PTR = (clEnqueueReleaseGLObjects_t)(intptr_t)dlsym(handle, "clEnqueueReleaseGLObjects") ;
  if (!CL_ENQUEUE_RELEASE_GLOBJECTS_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueReleaseGLObjects!\n");

  CL_CREATE_FROM_GLTEXTURE2_D_PTR = (clCreateFromGLTexture2D_t)(intptr_t)dlsym(handle, "clCreateFromGLTexture2D") ;
  if (!CL_CREATE_FROM_GLTEXTURE2_D_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateFromGLTexture2D!\n");

  CL_CREATE_FROM_GLTEXTURE3_D_PTR = (clCreateFromGLTexture3D_t)(intptr_t)dlsym(handle, "clCreateFromGLTexture3D") ;
  if (!CL_CREATE_FROM_GLTEXTURE3_D_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateFromGLTexture3D!\n");

  CL_GET_PLATFORM_IDS_PTR = (clGetPlatformIDs_t)(intptr_t)dlsym(handle, "clGetPlatformIDs") ;
  if (!CL_GET_PLATFORM_IDS_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetPlatformIDs!\n");

  CL_GET_PLATFORM_INFO_PTR = (clGetPlatformInfo_t)(intptr_t)dlsym(handle, "clGetPlatformInfo") ;
  if (!CL_GET_PLATFORM_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetPlatformInfo!\n");

  CL_GET_DEVICE_IDS_PTR = (clGetDeviceIDs_t)(intptr_t)dlsym(handle, "clGetDeviceIDs") ;
  if (!CL_GET_DEVICE_IDS_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetDeviceIDs!\n");

  CL_GET_DEVICE_INFO_PTR = (clGetDeviceInfo_t)(intptr_t)dlsym(handle, "clGetDeviceInfo") ;
  if (!CL_GET_DEVICE_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetDeviceInfo!\n");

  CL_CREATE_SUB_DEVICES_PTR = (clCreateSubDevices_t)(intptr_t)dlsym(handle, "clCreateSubDevices") ;
  if (!CL_CREATE_SUB_DEVICES_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateSubDevices!\n");

  CL_RETAIN_DEVICE_PTR = (clRetainDevice_t)(intptr_t)dlsym(handle, "clRetainDevice") ;
  if (!CL_RETAIN_DEVICE_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainDevice!\n");

  CL_RELEASE_DEVICE_PTR = (clReleaseDevice_t)(intptr_t)dlsym(handle, "clReleaseDevice") ;
  if (!CL_RELEASE_DEVICE_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseDevice!\n");

  CL_SET_DEFAULT_DEVICE_COMMAND_QUEUE_PTR = (clSetDefaultDeviceCommandQueue_t)(intptr_t)dlsym(handle, "clSetDefaultDeviceCommandQueue") ;
  if (!CL_SET_DEFAULT_DEVICE_COMMAND_QUEUE_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetDefaultDeviceCommandQueue!\n");

  CL_GET_DEVICE_AND_HOST_TIMER_PTR = (clGetDeviceAndHostTimer_t)(intptr_t)dlsym(handle, "clGetDeviceAndHostTimer") ;
  if (!CL_GET_DEVICE_AND_HOST_TIMER_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetDeviceAndHostTimer!\n");

  CL_GET_HOST_TIMER_PTR = (clGetHostTimer_t)(intptr_t)dlsym(handle, "clGetHostTimer") ;
  if (!CL_GET_HOST_TIMER_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetHostTimer!\n");

  CL_CREATE_CONTEXT_PTR = (clCreateContext_t)(intptr_t)dlsym(handle, "clCreateContext") ;
  if (!CL_CREATE_CONTEXT_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateContext!\n");

  CL_CREATE_CONTEXT_FROM_TYPE_PTR = (clCreateContextFromType_t)(intptr_t)dlsym(handle, "clCreateContextFromType") ;
  if (!CL_CREATE_CONTEXT_FROM_TYPE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateContextFromType!\n");

  CL_RETAIN_CONTEXT_PTR = (clRetainContext_t)(intptr_t)dlsym(handle, "clRetainContext") ;
  if (!CL_RETAIN_CONTEXT_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainContext!\n");

  CL_RELEASE_CONTEXT_PTR = (clReleaseContext_t)(intptr_t)dlsym(handle, "clReleaseContext") ;
  if (!CL_RELEASE_CONTEXT_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseContext!\n");

  CL_GET_CONTEXT_INFO_PTR = (clGetContextInfo_t)(intptr_t)dlsym(handle, "clGetContextInfo") ;
  if (!CL_GET_CONTEXT_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetContextInfo!\n");

  CL_SET_CONTEXT_DESTRUCTOR_CALLBACK_PTR = (clSetContextDestructorCallback_t)(intptr_t)dlsym(handle, "clSetContextDestructorCallback") ;
  if (!CL_SET_CONTEXT_DESTRUCTOR_CALLBACK_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetContextDestructorCallback!\n");

  CL_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_PTR = (clCreateCommandQueueWithProperties_t)(intptr_t)dlsym(handle, "clCreateCommandQueueWithProperties") ;
  if (!CL_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateCommandQueueWithProperties!\n");

  CL_RETAIN_COMMAND_QUEUE_PTR = (clRetainCommandQueue_t)(intptr_t)dlsym(handle, "clRetainCommandQueue") ;
  if (!CL_RETAIN_COMMAND_QUEUE_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainCommandQueue!\n");

  CL_RELEASE_COMMAND_QUEUE_PTR = (clReleaseCommandQueue_t)(intptr_t)dlsym(handle, "clReleaseCommandQueue") ;
  if (!CL_RELEASE_COMMAND_QUEUE_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseCommandQueue!\n");

  CL_GET_COMMAND_QUEUE_INFO_PTR = (clGetCommandQueueInfo_t)(intptr_t)dlsym(handle, "clGetCommandQueueInfo") ;
  if (!CL_GET_COMMAND_QUEUE_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetCommandQueueInfo!\n");

  CL_CREATE_BUFFER_PTR = (clCreateBuffer_t)(intptr_t)dlsym(handle, "clCreateBuffer") ;
  if (!CL_CREATE_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateBuffer!\n");

  CL_CREATE_BUFFER_WITH_PROPERTIES_PTR = (clCreateBufferWithProperties_t)(intptr_t)dlsym(handle, "clCreateBufferWithProperties") ;
  if (!CL_CREATE_BUFFER_WITH_PROPERTIES_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateBufferWithProperties!\n");

  CL_CREATE_SUB_BUFFER_PTR = (clCreateSubBuffer_t)(intptr_t)dlsym(handle, "clCreateSubBuffer") ;
  if (!CL_CREATE_SUB_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateSubBuffer!\n");

  CL_CREATE_IMAGE_PTR = (clCreateImage_t)(intptr_t)dlsym(handle, "clCreateImage") ;
  if (!CL_CREATE_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateImage!\n");

  CL_CREATE_IMAGE_WITH_PROPERTIES_PTR = (clCreateImageWithProperties_t)(intptr_t)dlsym(handle, "clCreateImageWithProperties") ;
  if (!CL_CREATE_IMAGE_WITH_PROPERTIES_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateImageWithProperties!\n");

  CL_CREATE_PIPE_PTR = (clCreatePipe_t)(intptr_t)dlsym(handle, "clCreatePipe") ;
  if (!CL_CREATE_PIPE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreatePipe!\n");

  CL_RETAIN_MEM_OBJECT_PTR = (clRetainMemObject_t)(intptr_t)dlsym(handle, "clRetainMemObject") ;
  if (!CL_RETAIN_MEM_OBJECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainMemObject!\n");

  CL_RELEASE_MEM_OBJECT_PTR = (clReleaseMemObject_t)(intptr_t)dlsym(handle, "clReleaseMemObject") ;
  if (!CL_RELEASE_MEM_OBJECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseMemObject!\n");

  CL_GET_SUPPORTED_IMAGE_FORMATS_PTR = (clGetSupportedImageFormats_t)(intptr_t)dlsym(handle, "clGetSupportedImageFormats") ;
  if (!CL_GET_SUPPORTED_IMAGE_FORMATS_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetSupportedImageFormats!\n");

  CL_GET_MEM_OBJECT_INFO_PTR = (clGetMemObjectInfo_t)(intptr_t)dlsym(handle, "clGetMemObjectInfo") ;
  if (!CL_GET_MEM_OBJECT_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetMemObjectInfo!\n");

  CL_GET_IMAGE_INFO_PTR = (clGetImageInfo_t)(intptr_t)dlsym(handle, "clGetImageInfo") ;
  if (!CL_GET_IMAGE_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetImageInfo!\n");

  CL_GET_PIPE_INFO_PTR = (clGetPipeInfo_t)(intptr_t)dlsym(handle, "clGetPipeInfo") ;
  if (!CL_GET_PIPE_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetPipeInfo!\n");

  CL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_PTR = (clSetMemObjectDestructorCallback_t)(intptr_t)dlsym(handle, "clSetMemObjectDestructorCallback") ;
  if (!CL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetMemObjectDestructorCallback!\n");

  CL_SVMALLOC_PTR = (clSVMAlloc_t)(intptr_t)dlsym(handle, "clSVMAlloc") ;
  if (!CL_SVMALLOC_PTR && verbose)
    fprintf(stderr, "Missing symbol clSVMAlloc!\n");

  CL_SVMFREE_PTR = (clSVMFree_t)(intptr_t)dlsym(handle, "clSVMFree") ;
  if (!CL_SVMFREE_PTR && verbose)
    fprintf(stderr, "Missing symbol clSVMFree!\n");

  CL_CREATE_SAMPLER_WITH_PROPERTIES_PTR = (clCreateSamplerWithProperties_t)(intptr_t)dlsym(handle, "clCreateSamplerWithProperties") ;
  if (!CL_CREATE_SAMPLER_WITH_PROPERTIES_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateSamplerWithProperties!\n");

  CL_RETAIN_SAMPLER_PTR = (clRetainSampler_t)(intptr_t)dlsym(handle, "clRetainSampler") ;
  if (!CL_RETAIN_SAMPLER_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainSampler!\n");

  CL_RELEASE_SAMPLER_PTR = (clReleaseSampler_t)(intptr_t)dlsym(handle, "clReleaseSampler") ;
  if (!CL_RELEASE_SAMPLER_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseSampler!\n");

  CL_GET_SAMPLER_INFO_PTR = (clGetSamplerInfo_t)(intptr_t)dlsym(handle, "clGetSamplerInfo") ;
  if (!CL_GET_SAMPLER_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetSamplerInfo!\n");

  CL_CREATE_PROGRAM_WITH_SOURCE_PTR = (clCreateProgramWithSource_t)(intptr_t)dlsym(handle, "clCreateProgramWithSource") ;
  if (!CL_CREATE_PROGRAM_WITH_SOURCE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateProgramWithSource!\n");

  CL_CREATE_PROGRAM_WITH_BINARY_PTR = (clCreateProgramWithBinary_t)(intptr_t)dlsym(handle, "clCreateProgramWithBinary") ;
  if (!CL_CREATE_PROGRAM_WITH_BINARY_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateProgramWithBinary!\n");

  CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_PTR = (clCreateProgramWithBuiltInKernels_t)(intptr_t)dlsym(handle, "clCreateProgramWithBuiltInKernels") ;
  if (!CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateProgramWithBuiltInKernels!\n");

  CL_CREATE_PROGRAM_WITH_IL_PTR = (clCreateProgramWithIL_t)(intptr_t)dlsym(handle, "clCreateProgramWithIL") ;
  if (!CL_CREATE_PROGRAM_WITH_IL_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateProgramWithIL!\n");

  CL_RETAIN_PROGRAM_PTR = (clRetainProgram_t)(intptr_t)dlsym(handle, "clRetainProgram") ;
  if (!CL_RETAIN_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainProgram!\n");

  CL_RELEASE_PROGRAM_PTR = (clReleaseProgram_t)(intptr_t)dlsym(handle, "clReleaseProgram") ;
  if (!CL_RELEASE_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseProgram!\n");

  CL_BUILD_PROGRAM_PTR = (clBuildProgram_t)(intptr_t)dlsym(handle, "clBuildProgram") ;
  if (!CL_BUILD_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clBuildProgram!\n");

  CL_COMPILE_PROGRAM_PTR = (clCompileProgram_t)(intptr_t)dlsym(handle, "clCompileProgram") ;
  if (!CL_COMPILE_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clCompileProgram!\n");

  CL_LINK_PROGRAM_PTR = (clLinkProgram_t)(intptr_t)dlsym(handle, "clLinkProgram") ;
  if (!CL_LINK_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clLinkProgram!\n");

  CL_SET_PROGRAM_RELEASE_CALLBACK_PTR = (clSetProgramReleaseCallback_t)(intptr_t)dlsym(handle, "clSetProgramReleaseCallback") ;
  if (!CL_SET_PROGRAM_RELEASE_CALLBACK_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetProgramReleaseCallback!\n");

  CL_SET_PROGRAM_SPECIALIZATION_CONSTANT_PTR = (clSetProgramSpecializationConstant_t)(intptr_t)dlsym(handle, "clSetProgramSpecializationConstant") ;
  if (!CL_SET_PROGRAM_SPECIALIZATION_CONSTANT_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetProgramSpecializationConstant!\n");

  CL_UNLOAD_PLATFORM_COMPILER_PTR = (clUnloadPlatformCompiler_t)(intptr_t)dlsym(handle, "clUnloadPlatformCompiler") ;
  if (!CL_UNLOAD_PLATFORM_COMPILER_PTR && verbose)
    fprintf(stderr, "Missing symbol clUnloadPlatformCompiler!\n");

  CL_GET_PROGRAM_INFO_PTR = (clGetProgramInfo_t)(intptr_t)dlsym(handle, "clGetProgramInfo") ;
  if (!CL_GET_PROGRAM_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetProgramInfo!\n");

  CL_GET_PROGRAM_BUILD_INFO_PTR = (clGetProgramBuildInfo_t)(intptr_t)dlsym(handle, "clGetProgramBuildInfo") ;
  if (!CL_GET_PROGRAM_BUILD_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetProgramBuildInfo!\n");

  CL_CREATE_KERNEL_PTR = (clCreateKernel_t)(intptr_t)dlsym(handle, "clCreateKernel") ;
  if (!CL_CREATE_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateKernel!\n");

  CL_CREATE_KERNELS_IN_PROGRAM_PTR = (clCreateKernelsInProgram_t)(intptr_t)dlsym(handle, "clCreateKernelsInProgram") ;
  if (!CL_CREATE_KERNELS_IN_PROGRAM_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateKernelsInProgram!\n");

  CL_CLONE_KERNEL_PTR = (clCloneKernel_t)(intptr_t)dlsym(handle, "clCloneKernel") ;
  if (!CL_CLONE_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clCloneKernel!\n");

  CL_RETAIN_KERNEL_PTR = (clRetainKernel_t)(intptr_t)dlsym(handle, "clRetainKernel") ;
  if (!CL_RETAIN_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainKernel!\n");

  CL_RELEASE_KERNEL_PTR = (clReleaseKernel_t)(intptr_t)dlsym(handle, "clReleaseKernel") ;
  if (!CL_RELEASE_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseKernel!\n");

  CL_SET_KERNEL_ARG_PTR = (clSetKernelArg_t)(intptr_t)dlsym(handle, "clSetKernelArg") ;
  if (!CL_SET_KERNEL_ARG_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetKernelArg!\n");

  CL_SET_KERNEL_ARG_SVMPOINTER_PTR = (clSetKernelArgSVMPointer_t)(intptr_t)dlsym(handle, "clSetKernelArgSVMPointer") ;
  if (!CL_SET_KERNEL_ARG_SVMPOINTER_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetKernelArgSVMPointer!\n");

  CL_SET_KERNEL_EXEC_INFO_PTR = (clSetKernelExecInfo_t)(intptr_t)dlsym(handle, "clSetKernelExecInfo") ;
  if (!CL_SET_KERNEL_EXEC_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetKernelExecInfo!\n");

  CL_GET_KERNEL_INFO_PTR = (clGetKernelInfo_t)(intptr_t)dlsym(handle, "clGetKernelInfo") ;
  if (!CL_GET_KERNEL_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetKernelInfo!\n");

  CL_GET_KERNEL_ARG_INFO_PTR = (clGetKernelArgInfo_t)(intptr_t)dlsym(handle, "clGetKernelArgInfo") ;
  if (!CL_GET_KERNEL_ARG_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetKernelArgInfo!\n");

  CL_GET_KERNEL_WORK_GROUP_INFO_PTR = (clGetKernelWorkGroupInfo_t)(intptr_t)dlsym(handle, "clGetKernelWorkGroupInfo") ;
  if (!CL_GET_KERNEL_WORK_GROUP_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetKernelWorkGroupInfo!\n");

  CL_GET_KERNEL_SUB_GROUP_INFO_PTR = (clGetKernelSubGroupInfo_t)(intptr_t)dlsym(handle, "clGetKernelSubGroupInfo") ;
  if (!CL_GET_KERNEL_SUB_GROUP_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetKernelSubGroupInfo!\n");

  CL_WAIT_FOR_EVENTS_PTR = (clWaitForEvents_t)(intptr_t)dlsym(handle, "clWaitForEvents") ;
  if (!CL_WAIT_FOR_EVENTS_PTR && verbose)
    fprintf(stderr, "Missing symbol clWaitForEvents!\n");

  CL_GET_EVENT_INFO_PTR = (clGetEventInfo_t)(intptr_t)dlsym(handle, "clGetEventInfo") ;
  if (!CL_GET_EVENT_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetEventInfo!\n");

  CL_CREATE_USER_EVENT_PTR = (clCreateUserEvent_t)(intptr_t)dlsym(handle, "clCreateUserEvent") ;
  if (!CL_CREATE_USER_EVENT_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateUserEvent!\n");

  CL_RETAIN_EVENT_PTR = (clRetainEvent_t)(intptr_t)dlsym(handle, "clRetainEvent") ;
  if (!CL_RETAIN_EVENT_PTR && verbose)
    fprintf(stderr, "Missing symbol clRetainEvent!\n");

  CL_RELEASE_EVENT_PTR = (clReleaseEvent_t)(intptr_t)dlsym(handle, "clReleaseEvent") ;
  if (!CL_RELEASE_EVENT_PTR && verbose)
    fprintf(stderr, "Missing symbol clReleaseEvent!\n");

  CL_SET_USER_EVENT_STATUS_PTR = (clSetUserEventStatus_t)(intptr_t)dlsym(handle, "clSetUserEventStatus") ;
  if (!CL_SET_USER_EVENT_STATUS_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetUserEventStatus!\n");

  CL_SET_EVENT_CALLBACK_PTR = (clSetEventCallback_t)(intptr_t)dlsym(handle, "clSetEventCallback") ;
  if (!CL_SET_EVENT_CALLBACK_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetEventCallback!\n");

  CL_GET_EVENT_PROFILING_INFO_PTR = (clGetEventProfilingInfo_t)(intptr_t)dlsym(handle, "clGetEventProfilingInfo") ;
  if (!CL_GET_EVENT_PROFILING_INFO_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetEventProfilingInfo!\n");

  CL_FLUSH_PTR = (clFlush_t)(intptr_t)dlsym(handle, "clFlush") ;
  if (!CL_FLUSH_PTR && verbose)
    fprintf(stderr, "Missing symbol clFlush!\n");

  CL_FINISH_PTR = (clFinish_t)(intptr_t)dlsym(handle, "clFinish") ;
  if (!CL_FINISH_PTR && verbose)
    fprintf(stderr, "Missing symbol clFinish!\n");

  CL_ENQUEUE_READ_BUFFER_PTR = (clEnqueueReadBuffer_t)(intptr_t)dlsym(handle, "clEnqueueReadBuffer") ;
  if (!CL_ENQUEUE_READ_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueReadBuffer!\n");

  CL_ENQUEUE_READ_BUFFER_RECT_PTR = (clEnqueueReadBufferRect_t)(intptr_t)dlsym(handle, "clEnqueueReadBufferRect") ;
  if (!CL_ENQUEUE_READ_BUFFER_RECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueReadBufferRect!\n");

  CL_ENQUEUE_WRITE_BUFFER_PTR = (clEnqueueWriteBuffer_t)(intptr_t)dlsym(handle, "clEnqueueWriteBuffer") ;
  if (!CL_ENQUEUE_WRITE_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueWriteBuffer!\n");

  CL_ENQUEUE_WRITE_BUFFER_RECT_PTR = (clEnqueueWriteBufferRect_t)(intptr_t)dlsym(handle, "clEnqueueWriteBufferRect") ;
  if (!CL_ENQUEUE_WRITE_BUFFER_RECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueWriteBufferRect!\n");

  CL_ENQUEUE_FILL_BUFFER_PTR = (clEnqueueFillBuffer_t)(intptr_t)dlsym(handle, "clEnqueueFillBuffer") ;
  if (!CL_ENQUEUE_FILL_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueFillBuffer!\n");

  CL_ENQUEUE_COPY_BUFFER_PTR = (clEnqueueCopyBuffer_t)(intptr_t)dlsym(handle, "clEnqueueCopyBuffer") ;
  if (!CL_ENQUEUE_COPY_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueCopyBuffer!\n");

  CL_ENQUEUE_COPY_BUFFER_RECT_PTR = (clEnqueueCopyBufferRect_t)(intptr_t)dlsym(handle, "clEnqueueCopyBufferRect") ;
  if (!CL_ENQUEUE_COPY_BUFFER_RECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueCopyBufferRect!\n");

  CL_ENQUEUE_READ_IMAGE_PTR = (clEnqueueReadImage_t)(intptr_t)dlsym(handle, "clEnqueueReadImage") ;
  if (!CL_ENQUEUE_READ_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueReadImage!\n");

  CL_ENQUEUE_WRITE_IMAGE_PTR = (clEnqueueWriteImage_t)(intptr_t)dlsym(handle, "clEnqueueWriteImage") ;
  if (!CL_ENQUEUE_WRITE_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueWriteImage!\n");

  CL_ENQUEUE_FILL_IMAGE_PTR = (clEnqueueFillImage_t)(intptr_t)dlsym(handle, "clEnqueueFillImage") ;
  if (!CL_ENQUEUE_FILL_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueFillImage!\n");

  CL_ENQUEUE_COPY_IMAGE_PTR = (clEnqueueCopyImage_t)(intptr_t)dlsym(handle, "clEnqueueCopyImage") ;
  if (!CL_ENQUEUE_COPY_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueCopyImage!\n");

  CL_ENQUEUE_COPY_IMAGE_TO_BUFFER_PTR = (clEnqueueCopyImageToBuffer_t)(intptr_t)dlsym(handle, "clEnqueueCopyImageToBuffer") ;
  if (!CL_ENQUEUE_COPY_IMAGE_TO_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueCopyImageToBuffer!\n");

  CL_ENQUEUE_COPY_BUFFER_TO_IMAGE_PTR = (clEnqueueCopyBufferToImage_t)(intptr_t)dlsym(handle, "clEnqueueCopyBufferToImage") ;
  if (!CL_ENQUEUE_COPY_BUFFER_TO_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueCopyBufferToImage!\n");

  CL_ENQUEUE_MAP_BUFFER_PTR = (clEnqueueMapBuffer_t)(intptr_t)dlsym(handle, "clEnqueueMapBuffer") ;
  if (!CL_ENQUEUE_MAP_BUFFER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueMapBuffer!\n");

  CL_ENQUEUE_MAP_IMAGE_PTR = (clEnqueueMapImage_t)(intptr_t)dlsym(handle, "clEnqueueMapImage") ;
  if (!CL_ENQUEUE_MAP_IMAGE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueMapImage!\n");

  CL_ENQUEUE_UNMAP_MEM_OBJECT_PTR = (clEnqueueUnmapMemObject_t)(intptr_t)dlsym(handle, "clEnqueueUnmapMemObject") ;
  if (!CL_ENQUEUE_UNMAP_MEM_OBJECT_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueUnmapMemObject!\n");

  CL_ENQUEUE_MIGRATE_MEM_OBJECTS_PTR = (clEnqueueMigrateMemObjects_t)(intptr_t)dlsym(handle, "clEnqueueMigrateMemObjects") ;
  if (!CL_ENQUEUE_MIGRATE_MEM_OBJECTS_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueMigrateMemObjects!\n");

  CL_ENQUEUE_NDRANGE_KERNEL_PTR = (clEnqueueNDRangeKernel_t)(intptr_t)dlsym(handle, "clEnqueueNDRangeKernel") ;
  if (!CL_ENQUEUE_NDRANGE_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueNDRangeKernel!\n");

  CL_ENQUEUE_NATIVE_KERNEL_PTR = (clEnqueueNativeKernel_t)(intptr_t)dlsym(handle, "clEnqueueNativeKernel") ;
  if (!CL_ENQUEUE_NATIVE_KERNEL_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueNativeKernel!\n");

  CL_ENQUEUE_MARKER_WITH_WAIT_LIST_PTR = (clEnqueueMarkerWithWaitList_t)(intptr_t)dlsym(handle, "clEnqueueMarkerWithWaitList") ;
  if (!CL_ENQUEUE_MARKER_WITH_WAIT_LIST_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueMarkerWithWaitList!\n");

  CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR = (clEnqueueBarrierWithWaitList_t)(intptr_t)dlsym(handle, "clEnqueueBarrierWithWaitList") ;
  if (!CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueBarrierWithWaitList!\n");

  CL_ENQUEUE_SVMFREE_PTR = (clEnqueueSVMFree_t)(intptr_t)dlsym(handle, "clEnqueueSVMFree") ;
  if (!CL_ENQUEUE_SVMFREE_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMFree!\n");

  CL_ENQUEUE_SVMMEMCPY_PTR = (clEnqueueSVMMemcpy_t)(intptr_t)dlsym(handle, "clEnqueueSVMMemcpy") ;
  if (!CL_ENQUEUE_SVMMEMCPY_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMMemcpy!\n");

  CL_ENQUEUE_SVMMEM_FILL_PTR = (clEnqueueSVMMemFill_t)(intptr_t)dlsym(handle, "clEnqueueSVMMemFill") ;
  if (!CL_ENQUEUE_SVMMEM_FILL_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMMemFill!\n");

  CL_ENQUEUE_SVMMAP_PTR = (clEnqueueSVMMap_t)(intptr_t)dlsym(handle, "clEnqueueSVMMap") ;
  if (!CL_ENQUEUE_SVMMAP_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMMap!\n");

  CL_ENQUEUE_SVMUNMAP_PTR = (clEnqueueSVMUnmap_t)(intptr_t)dlsym(handle, "clEnqueueSVMUnmap") ;
  if (!CL_ENQUEUE_SVMUNMAP_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMUnmap!\n");

  CL_ENQUEUE_SVMMIGRATE_MEM_PTR = (clEnqueueSVMMigrateMem_t)(intptr_t)dlsym(handle, "clEnqueueSVMMigrateMem") ;
  if (!CL_ENQUEUE_SVMMIGRATE_MEM_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueSVMMigrateMem!\n");

  CL_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_PTR = (clGetExtensionFunctionAddressForPlatform_t)(intptr_t)dlsym(handle, "clGetExtensionFunctionAddressForPlatform") ;
  if (!CL_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetExtensionFunctionAddressForPlatform!\n");

  CL_SET_COMMAND_QUEUE_PROPERTY_PTR = (clSetCommandQueueProperty_t)(intptr_t)dlsym(handle, "clSetCommandQueueProperty") ;
  if (!CL_SET_COMMAND_QUEUE_PROPERTY_PTR && verbose)
    fprintf(stderr, "Missing symbol clSetCommandQueueProperty!\n");

  CL_CREATE_IMAGE2_D_PTR = (clCreateImage2D_t)(intptr_t)dlsym(handle, "clCreateImage2D") ;
  if (!CL_CREATE_IMAGE2_D_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateImage2D!\n");

  CL_CREATE_IMAGE3_D_PTR = (clCreateImage3D_t)(intptr_t)dlsym(handle, "clCreateImage3D") ;
  if (!CL_CREATE_IMAGE3_D_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateImage3D!\n");

  CL_ENQUEUE_MARKER_PTR = (clEnqueueMarker_t)(intptr_t)dlsym(handle, "clEnqueueMarker") ;
  if (!CL_ENQUEUE_MARKER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueMarker!\n");

  CL_ENQUEUE_WAIT_FOR_EVENTS_PTR = (clEnqueueWaitForEvents_t)(intptr_t)dlsym(handle, "clEnqueueWaitForEvents") ;
  if (!CL_ENQUEUE_WAIT_FOR_EVENTS_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueWaitForEvents!\n");

  CL_ENQUEUE_BARRIER_PTR = (clEnqueueBarrier_t)(intptr_t)dlsym(handle, "clEnqueueBarrier") ;
  if (!CL_ENQUEUE_BARRIER_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueBarrier!\n");

  CL_UNLOAD_COMPILER_PTR = (clUnloadCompiler_t)(intptr_t)dlsym(handle, "clUnloadCompiler") ;
  if (!CL_UNLOAD_COMPILER_PTR && verbose)
    fprintf(stderr, "Missing symbol clUnloadCompiler!\n");

  CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR = (clGetExtensionFunctionAddress_t)(intptr_t)dlsym(handle, "clGetExtensionFunctionAddress") ;
  if (!CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR && verbose)
    fprintf(stderr, "Missing symbol clGetExtensionFunctionAddress!\n");

  CL_CREATE_COMMAND_QUEUE_PTR = (clCreateCommandQueue_t)(intptr_t)dlsym(handle, "clCreateCommandQueue") ;
  if (!CL_CREATE_COMMAND_QUEUE_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateCommandQueue!\n");

  CL_CREATE_SAMPLER_PTR = (clCreateSampler_t)(intptr_t)dlsym(handle, "clCreateSampler") ;
  if (!CL_CREATE_SAMPLER_PTR && verbose)
    fprintf(stderr, "Missing symbol clCreateSampler!\n");

  CL_ENQUEUE_TASK_PTR = (clEnqueueTask_t)(intptr_t)dlsym(handle, "clEnqueueTask") ;
  if (!CL_ENQUEUE_TASK_PTR && verbose)
    fprintf(stderr, "Missing symbol clEnqueueTask!\n");

  CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR = (clCreateEventFromEGLSyncKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clCreateEventFromEGLSyncKHR");
  if (!CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR)
    fprintf(stderr, "Missing symbol clCreateEventFromEGLSyncKHR!\n");

  CL_CREATE_FROM_EGLIMAGE_KHR_PTR = (clCreateFromEGLImageKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clCreateFromEGLImageKHR");
  if (!CL_CREATE_FROM_EGLIMAGE_KHR_PTR)
    fprintf(stderr, "Missing symbol clCreateFromEGLImageKHR!\n");

  CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR = (clEnqueueAcquireEGLObjectsKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clEnqueueAcquireEGLObjectsKHR");
  if (!CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR)
    fprintf(stderr, "Missing symbol clEnqueueAcquireEGLObjectsKHR!\n");

  CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR = (clEnqueueReleaseEGLObjectsKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clEnqueueReleaseEGLObjectsKHR");
  if (!CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR)
    fprintf(stderr, "Missing symbol clEnqueueReleaseEGLObjectsKHR!\n");

  CL_RELEASE_DEVICE_EXT_PTR = (clReleaseDeviceEXT_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clReleaseDeviceEXT");
  if (!CL_RELEASE_DEVICE_EXT_PTR)
    fprintf(stderr, "Missing symbol clReleaseDeviceEXT!\n");

  CL_RETAIN_DEVICE_EXT_PTR = (clRetainDeviceEXT_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clRetainDeviceEXT");
  if (!CL_RETAIN_DEVICE_EXT_PTR)
    fprintf(stderr, "Missing symbol clRetainDeviceEXT!\n");

  CL_CREATE_SUB_DEVICES_EXT_PTR = (clCreateSubDevicesEXT_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clCreateSubDevicesEXT");
  if (!CL_CREATE_SUB_DEVICES_EXT_PTR)
    fprintf(stderr, "Missing symbol clCreateSubDevicesEXT!\n");

  CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR = (clGetKernelSubGroupInfoKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clGetKernelSubGroupInfoKHR");
  if (!CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR)
    fprintf(stderr, "Missing symbol clGetKernelSubGroupInfoKHR!\n");

  CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR = (clCreateEventFromGLsyncKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clCreateEventFromGLsyncKHR");
  if (!CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR)
    fprintf(stderr, "Missing symbol clCreateEventFromGLsyncKHR!\n");

  CL_GET_GLCONTEXT_INFO_KHR_PTR = (clGetGLContextInfoKHR_t)(intptr_t)CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR("clGetGLContextInfoKHR");
  if (!CL_GET_GLCONTEXT_INFO_KHR_PTR)
    fprintf(stderr, "Missing symbol clGetGLContextInfoKHR!\n");
}

void CL_CALLBACK event_notify(cl_event event, cl_int event_command_exec_status, void *user_data) {
  (void)user_data;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling_results)) {
    cl_ulong queued;
    cl_ulong submit;
    cl_ulong start;
    cl_ulong end;
    cl_int queued_status = CL_GET_EVENT_PROFILING_INFO_PTR(event, CL_PROFILING_COMMAND_QUEUED,
                                                           sizeof(cl_ulong), &queued, NULL);
    cl_int submit_status = CL_GET_EVENT_PROFILING_INFO_PTR(event, CL_PROFILING_COMMAND_SUBMIT,
                                                           sizeof(cl_ulong), &submit, NULL);
    cl_int start_status = CL_GET_EVENT_PROFILING_INFO_PTR(event, CL_PROFILING_COMMAND_START,
                                                          sizeof(cl_ulong), &start, NULL);
    cl_int end_status = CL_GET_EVENT_PROFILING_INFO_PTR(event, CL_PROFILING_COMMAND_END,
                                                        sizeof(cl_ulong), &end, NULL);
    do_tracepoint(lttng_ust_opencl_profiling, event_profiling_results, event,
                  event_command_exec_status, queued_status, queued, submit_status, submit,
                  start_status, start, end_status, end);
  }
}

struct opencl_version {
  cl_uint major;
  cl_uint minor;
};

// static const struct opencl_version opencl_version_1_0 = {1, 0};
// static const struct opencl_version opencl_version_1_1 = {1, 1};
static const struct opencl_version opencl_version_1_2 = {1, 2};
// static const struct opencl_version opencl_version_2_0 = {2, 0};
static const struct opencl_version opencl_version_2_1 = {2, 1};
// static const struct opencl_version opencl_version_2_2 = {2, 2};

static inline int compare_opencl_version(const struct opencl_version *v1,
                                         const struct opencl_version *v2) {
  if (v1->major > v2->major)
    return 1;
  if (v1->major < v2->major)
    return -1;
  if (v1->minor > v2->minor)
    return 1;
  if (v1->minor < v2->minor)
    return -1;
  return 0;
}

static void get_platform_version(cl_platform_id platform, struct opencl_version *v) {
  if (!v)
    return;
  cl_int err;
  char version[128];
  char major[2], minor[2];
  size_t version_sz;

  v->major = 1;
  v->minor = 0;
  err = CL_GET_PLATFORM_INFO_PTR(platform, CL_PLATFORM_VERSION, 128, version, &version_sz);
  if (err != CL_SUCCESS || version_sz < 10)
    return;
  major[0] = version[7];
  major[1] = 0;
  minor[0] = version[9];
  minor[1] = 0;
  v->major = atoi(major);
  v->minor = atoi(minor);
}

static void get_device_platform_version(cl_device_id device, struct opencl_version *v) {
  if (!v)
    return;
  cl_platform_id platform;

  if (CL_GET_DEVICE_INFO_PTR(device, CL_DEVICE_PLATFORM, sizeof(platform), &platform, NULL) ==
      CL_SUCCESS)
    get_platform_version(platform, v);
  else {
    v->major = 1;
    v->minor = 0;
  }
}

static inline cl_device_id *get_program_devices(cl_program program, cl_uint *num_devices_ret) {
  cl_device_id *devices = NULL;
  cl_uint num_devices = 0;

  if (CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_NUM_DEVICES, sizeof(num_devices), &num_devices,
                              NULL) != CL_SUCCESS)
    num_devices = 0;
  else if (num_devices != 0) {
    devices = (cl_device_id *)malloc(num_devices * sizeof(cl_device_id));
    if (!devices)
      num_devices = 0;
    else if (CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_DEVICES,
                                     num_devices * sizeof(cl_device_id), devices,
                                     NULL) != CL_SUCCESS) {
      free(devices);
      devices = NULL;
      num_devices = 0;
    }
  }
  if (num_devices_ret)
    *num_devices_ret = num_devices;
  return devices;
}

static void get_program_platform_version(cl_program program, struct opencl_version *v) {
  if (!v)
    return;
  cl_device_id *devices;

  v->major = 1;
  v->minor = 0;
  devices = get_program_devices(program, NULL);
  if (devices) {
    get_device_platform_version(*devices, v);
    free(devices);
  }
}

static int do_host_profile = 0;
static int do_dump = 0;
pthread_mutex_t enqueue_counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t opencl_obj_mutex = PTHREAD_MUTEX_INITIALIZER;
static int64_t enqueue_counter = 0;
static int64_t dump_start = 0;
static int64_t dump_end = INT64_MAX;

#define BIN_TEMPLATE "/tmp/binXXXXXX"
#define SOURCE_TEMPLATE "/tmp/sourceXXXXXX"
#define BIN_SOURCE_TEMPLATE "/tmp/binsourceXXXXXX"
#define BIN_BUILD_TEMPLATE "/tmp/binbuildXXXXXX"
#define OBJ_BUILD_TEMPLATE "/tmp/objbuildXXXXXX"
#define IL_SOURCE_TEMPLATE "/tmp/ilsourceXXXXXX"

pthread_mutex_t opencl_closures_mutex = PTHREAD_MUTEX_INITIALIZER;

struct opencl_closure {
  void *ptr;
  void *c_ptr;
  UT_hash_handle hh;
  ffi_cif cif;
  ffi_closure *closure;
  ffi_type **types;
};

struct opencl_closure *opencl_closures = NULL;

struct buffer_obj_data {
  size_t size;
};

struct svmptr_obj_data;

struct svmptr_obj_data {
  struct svmptr_obj_data *prev;
  struct svmptr_obj_data *next;
  void *ptr;
  size_t size;
};

struct svmptr_obj_data *svmptr_objs = NULL;

struct kernel_arg {
  // 0 regular, 1 SVM
  int type;
  size_t arg_size;
  void *arg_value;
};

struct kernel_obj_data {
  cl_uint num_args;
  struct kernel_arg *args;
};

void kernel_obj_data_free(void *obj_data) {
  struct kernel_obj_data *data = (struct kernel_obj_data *)obj_data;
  for (cl_uint i = 0; i < data->num_args; i++) {
    if (data->args[i].arg_value) {
      free(data->args[i].arg_value);
    }
  }
  free(obj_data);
}

enum cl_obj_type {
  UNKNOWN = 0,
  PLATFORM,
  DEVICE,
  CONTEXT,
  COMMAND_QUEUE,
  BUFFER,
  PIPE,
  IMAGE,
  KERNEL,
  EVENT,
  SAMPLER,
  SVMMEM
};

struct opencl_obj_h {
  void *ptr;
  UT_hash_handle hh;
  enum cl_obj_type type;
  void *obj_data;
  void (*obj_data_free)(void *obj_data);
};

struct opencl_obj_h *opencl_objs = NULL;

static inline void delete_opencl_obj(struct opencl_obj_h *o_h) {
  HASH_DEL(opencl_objs, o_h);
  if (o_h->obj_data != NULL) {
    if (o_h->obj_data_free != NULL)
      o_h->obj_data_free(o_h->obj_data);
    else
      free(o_h->obj_data);
  }
  free(o_h);
}

int cmp_svm_ptr(struct svmptr_obj_data *svm_a, struct svmptr_obj_data *svm_b) {
  intptr_t a = (intptr_t)(svm_a->ptr);
  intptr_t b = (intptr_t)(svm_b->ptr);
  return (a < b ? -1 : (a == b ? 0 : 1));
}

static inline void add_svmptr(void *ptr, size_t size) {
  struct opencl_obj_h *o_h = NULL;
  struct svmptr_obj_data *svm_data = NULL;

  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &ptr, o_h);
  if (o_h != NULL) {
    delete_opencl_obj(o_h);
  }
  pthread_mutex_unlock(&opencl_obj_mutex);

  o_h = (struct opencl_obj_h *)calloc(1, sizeof(struct opencl_obj_h));
  if (o_h == NULL)
    return;
  svm_data = (struct svmptr_obj_data *)calloc(1, sizeof(struct svmptr_obj_data));
  if (svm_data == NULL) {
    free(o_h);
    return;
  }
  o_h->ptr = ptr;
  o_h->type = SVMMEM;
  svm_data->ptr = ptr;
  svm_data->size = size;
  o_h->obj_data = (void *)svm_data;

  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_ADD_PTR(opencl_objs, ptr, o_h);
  DL_INSERT_INORDER(svmptr_objs, svm_data, cmp_svm_ptr);
  pthread_mutex_unlock(&opencl_obj_mutex);
}

static inline void remove_svmptr(void *ptr) {
  struct opencl_obj_h *o_h = NULL;
  struct svmptr_obj_data *svm_data = NULL;

  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &ptr, o_h);
  if (o_h != NULL) {
    svm_data = (struct svmptr_obj_data *)o_h->obj_data;
    DL_DELETE(svmptr_objs, svm_data);
    delete_opencl_obj(o_h);
  }
  pthread_mutex_unlock(&opencl_obj_mutex);
}

static inline void add_buffer(cl_mem b, size_t size) {
  struct opencl_obj_h *o_h = NULL;
  struct buffer_obj_data *b_data = NULL;

  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &b, o_h);
  if (o_h != NULL) {
    delete_opencl_obj(o_h);
  }
  pthread_mutex_unlock(&opencl_obj_mutex);

  o_h = (struct opencl_obj_h *)calloc(1, sizeof(struct opencl_obj_h));
  if (o_h == NULL)
    return;
  b_data = (struct buffer_obj_data *)calloc(1, sizeof(struct buffer_obj_data));
  if (b_data == NULL) {
    free(o_h);
    return;
  }
  o_h->ptr = (void *)b;
  o_h->type = BUFFER;
  b_data->size = size;
  o_h->obj_data = (void *)b_data;

  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_ADD_PTR(opencl_objs, ptr, o_h);
  pthread_mutex_unlock(&opencl_obj_mutex);
}

static inline void add_kernel(cl_kernel k) {
  cl_uint num_args = 0;
  cl_int err = CL_GET_KERNEL_INFO_PTR(k, CL_KERNEL_NUM_ARGS, sizeof(cl_uint), &num_args, NULL);
  if (err == CL_SUCCESS) {
    struct opencl_obj_h *o_h = NULL;
    struct kernel_obj_data *k_data = NULL;

    pthread_mutex_lock(&opencl_obj_mutex);
    HASH_FIND_PTR(opencl_objs, &k, o_h);
    if (o_h != NULL) {
      delete_opencl_obj(o_h);
    }
    pthread_mutex_unlock(&opencl_obj_mutex);

    o_h = (struct opencl_obj_h *)calloc(1, sizeof(struct opencl_obj_h));
    if (o_h == NULL)
      return;
    k_data = (struct kernel_obj_data *)calloc(1, sizeof(struct kernel_obj_data) +
                                                     num_args * sizeof(struct kernel_arg));
    if (k_data == NULL) {
      free(o_h);
      return;
    }
    o_h->ptr = (void *)k;
    o_h->type = KERNEL;
    k_data->num_args = num_args;
    k_data->args = (struct kernel_arg *)((intptr_t)k_data + sizeof(struct kernel_obj_data));
    o_h->obj_data = (void *)k_data;
    o_h->obj_data_free = kernel_obj_data_free;

    pthread_mutex_lock(&opencl_obj_mutex);
    HASH_ADD_PTR(opencl_objs, ptr, o_h);
    pthread_mutex_unlock(&opencl_obj_mutex);
  }
}

static inline void add_kernel_arg(
    cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void *arg_value, int type) {
  struct opencl_obj_h *o_h = NULL;
  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &kernel, o_h);
  if (o_h != NULL && o_h->type == KERNEL) {
    struct kernel_obj_data *k_data = (struct kernel_obj_data *)o_h->obj_data;
    if (k_data != NULL && arg_index < k_data->num_args) {
      struct kernel_arg *arg = k_data->args + arg_index;
      if (arg_value != NULL) {
        if (arg->arg_value == NULL) {
          arg->arg_value = malloc(arg_size);
        } else if (arg->arg_size < arg_size) {
          arg->arg_value = realloc(arg->arg_value, arg_size);
        }
        memcpy(arg->arg_value, arg_value, arg_size);
      }
      arg->arg_size = arg_size;
      arg->type = type;
    }
  }
  pthread_mutex_unlock(&opencl_obj_mutex);
}

struct buffer_dump_notify_data {
  uint64_t enqueue_counter;
  cl_uint arg_index;
  int direction;
  size_t size;
  int fd;
  char path[sizeof(BIN_TEMPLATE)];
};

void CL_CALLBACK buffer_dump_notify(cl_event event,
                                    cl_int event_command_exec_status,
                                    void *user_data) {
  struct buffer_dump_notify_data *data = (struct buffer_dump_notify_data *)user_data;
  tracepoint(lttng_ust_opencl_dump, buffer_dump_result, data->enqueue_counter, data->arg_index,
             data->direction, event, event_command_exec_status, data->size, data->path);
  if (event_command_exec_status == CL_COMPLETE) {
    int err = ftruncate(data->fd, data->size);
    if (err)
      unlink(data->path);
  } else {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    ftruncate(data->fd, 0);
#pragma GCC diagnostic pop
    unlink(data->path);
  }
  close(data->fd);
  free(user_data);
}

struct svmptr_dump_notify_data {
  uint64_t enqueue_counter;
  cl_uint arg_index;
  int direction;
  size_t size;
  int fd;
  char path[sizeof(BIN_TEMPLATE)];
};

void CL_CALLBACK svmptr_dump_notify(cl_event event,
                                    cl_int event_command_exec_status,
                                    void *user_data) {
  struct svmptr_dump_notify_data *data = (struct svmptr_dump_notify_data *)user_data;
  tracepoint(lttng_ust_opencl_dump, buffer_dump_result, data->enqueue_counter, data->arg_index,
             data->direction, event, event_command_exec_status, data->size, data->path);
  if (event_command_exec_status == CL_COMPLETE) {
    int err = ftruncate(data->fd, data->size);
    if (err)
      unlink(data->path);
  } else {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    ftruncate(data->fd, 0);
#pragma GCC diagnostic pop
    unlink(data->path);
  }
  close(data->fd);
  free(user_data);
}

static inline size_t align(size_t size, unsigned int bit) {
  size_t alignment_mask = (1 << bit) - 1;
  return (size + alignment_mask) & ~(alignment_mask);
}

static inline int create_file_and_map(char template[], size_t size, void **ptr) {
  int fd = mkstemp(template);
  size_t map_size = align(size, 12);
  int err = ftruncate(fd, map_size); // page size
  if (err == 0) {
    *ptr = mmap(NULL, map_size, PROT_WRITE, MAP_SHARED, fd, 0);
    if (*ptr == MAP_FAILED) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
      ftruncate(fd, 0);
#pragma GCC diagnostic pop
      close(fd);
      unlink(template);
      return -1;
    }
    return fd;
  } else {
    return -1;
  }
}

static inline void create_file_and_write(char template[], size_t size, const void *ptr) {
  int fd = mkstemp(template);
  if (fd != -1) {
    if (ptr != NULL) {
      ssize_t ret;
      size_t written = 0;
      while (written < size) {
        ret = write(fd, ptr, size);
        if (ret > 0) {
          written += ret;
        } else // if (errno != EINTR) avoid errno...
          break;
      }
    }
    close(fd);
  }
}

static void dump_buffer(cl_command_queue command_queue,
                        struct opencl_obj_h *o_h,
                        uint64_t enqueue_counter,
                        cl_uint arg_index,
                        int direction,
                        cl_uint num_events_in_wait_list,
                        cl_event *event_wait_list,
                        cl_uint *new_num_events_in_wait_list,
                        cl_event **new_event_wait_list) {
  cl_event event;
  void *ptr = NULL;
  struct buffer_dump_notify_data *data = NULL;
  struct buffer_obj_data *obj_data = (struct buffer_obj_data *)(o_h->obj_data);

  data = (struct buffer_dump_notify_data *)malloc(sizeof(struct buffer_dump_notify_data));
  if (data == NULL)
    return;
  data->enqueue_counter = enqueue_counter;
  data->arg_index = arg_index;
  data->direction = direction;
  data->size = obj_data->size;
  strncpy(data->path, BIN_TEMPLATE, sizeof(data->path));
  data->fd = create_file_and_map(data->path, data->size, &ptr);
  if (data->fd == -1) {
    free(data);
    return;
  }

  cl_int err =
      CL_ENQUEUE_READ_BUFFER_PTR(command_queue, (cl_mem)(o_h->ptr), CL_FALSE, 0, obj_data->size,
                                 ptr, num_events_in_wait_list, event_wait_list, &event);
  if (err == CL_SUCCESS) {
    int _set_retval = CL_SET_EVENT_CALLBACK_PTR(event, CL_COMPLETE, buffer_dump_notify, data);
    tracepoint(lttng_ust_opencl_dump, buffer_dump_event, enqueue_counter, arg_index, direction,
               (cl_mem)(o_h->ptr), _set_retval, event);
    if (new_event_wait_list != NULL) {
      *new_num_events_in_wait_list += 1;
      *new_event_wait_list = (cl_event *)realloc(*new_event_wait_list,
                                                 *new_num_events_in_wait_list * sizeof(cl_event));
      if (*new_event_wait_list != NULL) {
        (*new_event_wait_list)[*new_num_events_in_wait_list - 1] = event;
      } else {
        CL_RELEASE_EVENT_PTR(event);
      }
    } else {
      CL_RELEASE_EVENT_PTR(event);
    }
    if (_set_retval != CL_SUCCESS) {
      free(data);
    }
  } else {
    free(data);
  }
}

static void dump_svmptr(cl_command_queue command_queue,
                        struct opencl_obj_h *o_h,
                        uint64_t enqueue_counter,
                        cl_uint arg_index,
                        int direction,
                        cl_uint num_events_in_wait_list,
                        cl_event *event_wait_list,
                        cl_uint *new_num_events_in_wait_list,
                        cl_event **new_event_wait_list) {
  cl_event event;
  void *ptr = NULL;
  struct svmptr_dump_notify_data *data = NULL;
  struct svmptr_obj_data *obj_data = (struct svmptr_obj_data *)(o_h->obj_data);

  data = (struct svmptr_dump_notify_data *)malloc(sizeof(struct svmptr_dump_notify_data));
  if (data == NULL)
    return;
  data->enqueue_counter = enqueue_counter;
  data->arg_index = arg_index;
  data->direction = direction;
  data->size = obj_data->size;
  strncpy(data->path, BIN_TEMPLATE, sizeof(data->path));
  data->fd = create_file_and_map(data->path, data->size, &ptr);
  if (data->fd == -1) {
    free(data);
    return;
  }

  cl_int err = CL_ENQUEUE_SVMMEMCPY_PTR(command_queue, CL_FALSE, ptr, obj_data->ptr, obj_data->size,
                                        num_events_in_wait_list, event_wait_list, &event);
  if (err == CL_SUCCESS) {
    int _set_retval = CL_SET_EVENT_CALLBACK_PTR(event, CL_COMPLETE, svmptr_dump_notify, data);
    tracepoint(lttng_ust_opencl_dump, svmptr_dump_event, enqueue_counter, arg_index, direction,
               obj_data->ptr, _set_retval, event);
    if (new_event_wait_list != NULL) {
      *new_num_events_in_wait_list += 1;
      *new_event_wait_list = (cl_event *)realloc(*new_event_wait_list,
                                                 *new_num_events_in_wait_list * sizeof(cl_event));
      if (*new_event_wait_list != NULL) {
        (*new_event_wait_list)[*new_num_events_in_wait_list - 1] = event;
      } else {
        CL_RELEASE_EVENT_PTR(event);
      }
    } else {
      CL_RELEASE_EVENT_PTR(event);
    }
    if (_set_retval != CL_SUCCESS) {
      free(data);
    }
  } else {
    free(data);
  }
}

static void dump_opencl_object(cl_command_queue command_queue,
                               uint64_t enqueue_counter,
                               struct kernel_arg *arg,
                               int do_event,
                               cl_uint arg_index,
                               int direction,
                               cl_uint num_events_in_wait_list,
                               cl_event *event_wait_list,
                               cl_uint *new_num_events_in_wait_list,
                               cl_event **new_event_wait_list) {
  struct opencl_obj_h *oo_h = NULL;
  struct svmptr_obj_data *svm_data = NULL;
  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, (void **)(arg->arg_value), oo_h);
  pthread_mutex_unlock(&opencl_obj_mutex);
  if (oo_h != NULL) {
    switch (oo_h->type) {
    case BUFFER:
      if (do_event)
        dump_buffer(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, new_num_events_in_wait_list,
                    new_event_wait_list);
      else
        dump_buffer(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, NULL, NULL);
      break;
    case SVMMEM:
      if (do_event)
        dump_svmptr(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, new_num_events_in_wait_list,
                    new_event_wait_list);
      else
        dump_svmptr(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, NULL, NULL);
      break;
    default:
      break;
    }
  } else {
    // check if it is a pointer into an SVM region
    pthread_mutex_lock(&opencl_obj_mutex);
    DL_FOREACH(svmptr_objs, svm_data) {
      if (*(uintptr_t *)(arg->arg_value) > (uintptr_t)(svm_data->ptr) &&
          *(uintptr_t *)(arg->arg_value) < (uintptr_t)(svm_data->ptr) + svm_data->size) {
        HASH_FIND_PTR(opencl_objs, (void **)(arg->arg_value), oo_h);
        break;
      }
    }
    pthread_mutex_unlock(&opencl_obj_mutex);
    if (oo_h != NULL && oo_h->type == SVMMEM) {
      if (do_event)
        dump_svmptr(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, new_num_events_in_wait_list,
                    new_event_wait_list);
      else
        dump_svmptr(command_queue, oo_h, enqueue_counter, arg_index, direction,
                    num_events_in_wait_list, event_wait_list, NULL, NULL);
    }
  }
}

static int dump_kernel_args(cl_command_queue command_queue,
                            cl_kernel kernel,
                            uint64_t enqueue_counter,
                            cl_command_queue_properties properties,
                            cl_uint *num_events_in_wait_list,
                            cl_event **event_wait_list) {
  cl_event *new_event_wait_list = NULL;
  cl_uint new_num_events_in_wait_list = 0;
  struct opencl_obj_h *o_h = NULL;
  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &kernel, o_h);
  pthread_mutex_unlock(&opencl_obj_mutex);
  if (o_h != NULL && o_h->type == KERNEL) {
    struct kernel_obj_data *k_data = (struct kernel_obj_data *)o_h->obj_data;
    if (k_data != NULL) {
      for (cl_uint arg_index = 0; arg_index < k_data->num_args; arg_index++) {
        struct kernel_arg *arg = k_data->args + arg_index;
        tracepoint(lttng_ust_opencl_dump, kernel_arg_value, enqueue_counter, arg_index,
                   arg->arg_size, arg->arg_value);
        if (arg->arg_value != NULL && arg->arg_size == 8) {
          dump_opencl_object(command_queue, enqueue_counter, arg,
                             properties | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, arg_index, 0,
                             *num_events_in_wait_list, *event_wait_list,
                             &new_num_events_in_wait_list, &new_event_wait_list);
        }
      }
    }
  }
  if (new_event_wait_list != NULL && new_num_events_in_wait_list > 0) {
    *event_wait_list = new_event_wait_list;
    *num_events_in_wait_list = new_num_events_in_wait_list;
    return 1;
  }
  if (new_event_wait_list != NULL)
    free(new_event_wait_list);
  return 0;
}

static cl_event dump_kernel_buffers(cl_command_queue command_queue,
                                    cl_kernel kernel,
                                    uint64_t enqueue_counter,
                                    cl_event *event) {
  cl_event *new_event_wait_list = NULL;
  cl_uint new_num_events_in_wait_list = 0;
  cl_uint num_event = (event == NULL ? 0 : 1);
  struct opencl_obj_h *o_h = NULL;
  pthread_mutex_lock(&opencl_obj_mutex);
  HASH_FIND_PTR(opencl_objs, &kernel, o_h);
  pthread_mutex_unlock(&opencl_obj_mutex);
  if (o_h != NULL && o_h->type == KERNEL) {
    struct kernel_obj_data *k_data = (struct kernel_obj_data *)o_h->obj_data;
    if (k_data != NULL) {
      for (cl_uint arg_index = 0; arg_index < k_data->num_args; arg_index++) {
        struct kernel_arg *arg = k_data->args + arg_index;
        if (arg->arg_value != NULL && arg->arg_size == 8) {
          dump_opencl_object(command_queue, enqueue_counter, arg, event != NULL, arg_index, 1,
                             num_event, event, &new_num_events_in_wait_list, &new_event_wait_list);
        }
      }
    }
  }
  if (new_event_wait_list != NULL && new_num_events_in_wait_list > 0) {
    cl_event ev;
    CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR(command_queue, new_num_events_in_wait_list,
                                          new_event_wait_list, &ev);
    for (cl_uint i = 0; i < new_num_events_in_wait_list; i++) {
      CL_RELEASE_EVENT_PTR(new_event_wait_list[i]);
    }
    free(new_event_wait_list);
    return ev;
  }
  if (new_event_wait_list != NULL)
    free(new_event_wait_list);
  return NULL;
}

static void dump_kernel_info(cl_kernel kernel) {
  cl_int error = CL_SUCCESS;
  char *function_name = "";
  size_t function_name_sz = 0;
  int free_function_name = 0;
  cl_uint num_args;
  cl_context context = NULL;
  cl_program program = NULL;
  char *attributes = "";
  size_t attributes_sz = 0;
  int free_attributes = 0;

  error = CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_NUM_ARGS, sizeof(num_args), &num_args, NULL);
  if (error != CL_SUCCESS)
    return;
  error = CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_FUNCTION_NAME, 0, NULL, &function_name_sz);
  if (error == CL_SUCCESS && function_name_sz > 0) {
    char *new_function_name = (char *)calloc(function_name_sz + 1, 1);
    if (new_function_name) {
      error = CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_FUNCTION_NAME, function_name_sz,
                                     new_function_name, NULL);
      if (error == CL_SUCCESS) {
        function_name = new_function_name;
        free_function_name = 1;
      }
    }
  }
  CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_CONTEXT, sizeof(context), &context, NULL);
  CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_PROGRAM, sizeof(program), &program, NULL);
  error = CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_ATTRIBUTES, 0, NULL, &attributes_sz);
  if (error == CL_SUCCESS && attributes_sz > 0) {
    char *new_attributes = (char *)calloc(attributes_sz + 1, 1);
    if (new_attributes) {
      error =
          CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_ATTRIBUTES, attributes_sz, new_attributes, NULL);
      if (error == CL_SUCCESS) {
        attributes = new_attributes;
        free_attributes = 1;
      }
    }
  }
  do_tracepoint(lttng_ust_opencl_arguments, kernel_info, kernel, function_name, num_args, context,
                program, attributes);
  if (free_function_name)
    free(function_name);
  if (free_attributes)
    free(attributes);
}

static void dump_argument_info(cl_kernel kernel, cl_uint arg_index) {

  cl_int error = CL_SUCCESS;
  cl_kernel_arg_address_qualifier address_qualifier;
  cl_kernel_arg_access_qualifier access_qualifier;
  char *type_name;
  size_t type_name_sz;
  cl_kernel_arg_type_qualifier type_qualifier;
  char *name;
  size_t name_sz;

  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_ADDRESS_QUALIFIER,
                                     sizeof(address_qualifier), &address_qualifier, NULL);
  if (error != CL_SUCCESS)
    return;
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_ACCESS_QUALIFIER,
                                     sizeof(access_qualifier), &access_qualifier, NULL);
  if (error != CL_SUCCESS)
    return;
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_TYPE_QUALIFIER,
                                     sizeof(type_qualifier), &type_qualifier, NULL);
  if (error != CL_SUCCESS)
    return;
  // Strings are forced to be zero terminated
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_TYPE_NAME, 0, NULL,
                                     &type_name_sz);
  if (error != CL_SUCCESS)
    return;
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_NAME, 0, NULL, &name_sz);
  if (error != CL_SUCCESS)
    return;
  type_name = (char *)calloc(type_name_sz + 1, 1);
  if (type_name == NULL)
    return;
  name = (char *)calloc(name_sz + 1, 1);
  if (name == NULL)
    goto type_name_lb;
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_TYPE_NAME, type_name_sz,
                                     type_name, NULL);
  if (error != CL_SUCCESS)
    goto name_lb;
  error = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, CL_KERNEL_ARG_NAME, name_sz, name, NULL);
  if (error != CL_SUCCESS)
    goto name_lb;
  // Menbers are initialized, call tracepoint
  do_tracepoint(lttng_ust_opencl_arguments, argument_info, kernel, arg_index, address_qualifier,
                access_qualifier, type_name, type_qualifier, name);

name_lb:
  free(name);
type_name_lb:
  free(type_name);
}

static void dump_kernel_arguments(cl_program program, cl_kernel kernel) {
  struct opencl_version version = {1, 0};
  get_program_platform_version(program, &version);
  if (compare_opencl_version(&version, &opencl_version_1_2) >= 0) {
    cl_uint num_args;
    if (CL_GET_KERNEL_INFO_PTR(kernel, CL_KERNEL_NUM_ARGS, sizeof(num_args), &num_args, NULL) ==
        CL_SUCCESS) {
      for (cl_uint i = 0; i < num_args; i++)
        dump_argument_info(kernel, i);
    }
  }
}

static inline void dump_device_name(cl_device_id device) {
  size_t name_sz = 0;
  char *name = NULL;
  if (CL_GET_DEVICE_INFO_PTR(device, CL_DEVICE_NAME, 0, NULL, &name_sz) != CL_SUCCESS)
    return;
  if (name_sz > 0) {
    name = (char *)calloc(name_sz + 1, 1);
    if (!name)
      return;
    if (CL_GET_DEVICE_INFO_PTR(device, CL_DEVICE_NAME, name_sz, name, NULL) != CL_SUCCESS)
      goto cleanup;
  }
  do_tracepoint(lttng_ust_opencl_devices, device_name, device, name);
cleanup:
  free(name);
}

static inline void dump_device_timer(cl_device_id device) {
  struct opencl_version version = {1, 0};
  if (CL_GET_DEVICE_AND_HOST_TIMER_PTR != NULL)
    return;
  get_device_platform_version(device, &version);
  if (compare_opencl_version(&version, &opencl_version_2_1) >= 0) {
    cl_ulong device_timestamp;
    cl_ulong host_timestamp;
    if (CL_GET_DEVICE_AND_HOST_TIMER_PTR(device, &device_timestamp, &host_timestamp) != CL_SUCCESS)
      return;
    do_tracepoint(lttng_ust_opencl_devices, device_timer, device, device_timestamp, host_timestamp);
  }
}

static inline void dump_program_device_build_infos(cl_program program, cl_device_id device) {
  cl_build_status build_status;
  char *build_options = "";
  size_t build_options_sz = 0;
  int free_build_options = 0;
  char *build_log = "";
  size_t build_log_sz = 0;
  int free_build_log = 0;

  if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_STATUS, sizeof(build_status),
                                    &build_status, NULL) != CL_SUCCESS)
    return;
  if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_OPTIONS, 0, NULL,
                                    &build_options_sz) != CL_SUCCESS)
    return;
  if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL,
                                    &build_log_sz) != CL_SUCCESS)
    return;

  if (build_options_sz > 0) {
    build_options = (char *)calloc(build_options_sz + 1, 1);
    if (!build_options)
      return;
    free_build_options = 1;
    if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_OPTIONS, build_options_sz,
                                      build_options, NULL) != CL_SUCCESS)
      goto cleanup;
  }

  if (build_log_sz > 0) {
    build_log = (char *)calloc(build_log_sz + 1, 1);
    if (!build_log)
      goto cleanup;
    free_build_log = 1;
    if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_LOG, build_log_sz,
                                      build_log, NULL) != CL_SUCCESS)
      goto cleanup;
  }

  do_tracepoint(lttng_ust_opencl_build, infos, program, device, build_status, build_options,
                build_log);
cleanup:
  if (free_build_options)
    free(build_options);
  if (free_build_log)
    free(build_log);
}

static inline void dump_program_device_build_infos_1_2(cl_program program, cl_device_id device) {
  cl_program_binary_type binary_type;

  if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BINARY_TYPE, sizeof(binary_type),
                                    &binary_type, NULL) != CL_SUCCESS)
    return;

  do_tracepoint(lttng_ust_opencl_build, infos_1_2, program, device, binary_type);
}

static inline void dump_program_device_build_infos_2_0(cl_program program, cl_device_id device) {
  size_t build_global_variable_total_size;

  if (CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, CL_PROGRAM_BUILD_GLOBAL_VARIABLE_TOTAL_SIZE,
                                    sizeof(size_t), &build_global_variable_total_size,
                                    NULL) != CL_SUCCESS)
    return;

  do_tracepoint(lttng_ust_opencl_build, infos_2_0, program, device,
                build_global_variable_total_size);
}

static void dump_program_build_infos(cl_program program) {
  cl_device_id *devices;
  cl_uint num_devices;
  cl_uint i;

  devices = get_program_devices(program, &num_devices);
  if (!devices)
    return;

  for (i = 0; i < num_devices; i++) {
    dump_program_device_build_infos(program, devices[i]);
    dump_program_device_build_infos_1_2(program, devices[i]);
    dump_program_device_build_infos_2_0(program, devices[i]);
  }
}

static void dump_program_objects(cl_program program) {
  cl_int err = CL_SUCCESS;
  cl_device_id *devices;
  cl_uint num_devices;
  size_t *binary_sizes;
  size_t total_size = 0;
  void **binaries;
  char (*paths)[sizeof(OBJ_BUILD_TEMPLATE)];
  int *fds;
  cl_uint i;

  devices = get_program_devices(program, &num_devices);
  if (!devices)
    goto with_noting;
  binary_sizes = (size_t *)malloc(num_devices * sizeof(size_t));
  if (!binary_sizes)
    goto with_devices;

  err = CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_BINARY_SIZES, num_devices * sizeof(size_t),
                                binary_sizes, NULL);
  if (err != CL_SUCCESS)
    goto with_binary_sizes;

  binaries = (void **)calloc(num_devices * sizeof(void *), 1);
  if (!binaries)
    goto with_binary_sizes;
  paths = (char (*)[sizeof(OBJ_BUILD_TEMPLATE)])calloc(num_devices * sizeof(OBJ_BUILD_TEMPLATE), 1);
  if (!paths)
    goto with_binaries;
  fds = (int *)calloc(num_devices * sizeof(int), 1);
  if (!fds)
    goto with_paths;

  for (i = 0; i < num_devices; i++) {
    if (binary_sizes[i] > 0) {
      strncpy(paths[i], OBJ_BUILD_TEMPLATE, sizeof(paths[i]));
      fds[i] = create_file_and_map(paths[i], binary_sizes[i], binaries + i);
      if (fds[i] == -1) {
        for (cl_uint j = i; j > 0; j--) {
          if (binary_sizes[j - 1] > 0) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
            ftruncate(fds[j - 1], 0);
#pragma GCC diagnostic pop
            close(fds[j - 1]);
            unlink(paths[j - 1]);
          }
        }
        goto with_fds;
      }
      total_size += binary_sizes[i];
    }
  }

  err = CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_BINARIES, total_size, binaries, NULL);
  if (err != CL_SUCCESS) {
    for (i = 0; i < num_devices; i++) {
      if (binary_sizes[i] > 0) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
        ftruncate(fds[i], 0);
#pragma GCC diagnostic pop
        close(fds[i]);
        unlink(paths[i]);
      }
    }
  }
  for (i = 0; i < num_devices; i++) {
    int e = ftruncate(fds[i], binary_sizes[i]);
    if (e) {
      unlink(paths[i]);
      close(fds[i]);
    } else {
      close(fds[i]);
      do_tracepoint(lttng_ust_opencl_build, objects, program, devices[i], binary_sizes[i],
                    paths[i]);
    }
  }
with_fds:
  free(fds);
with_paths:
  free(paths);
with_binaries:
  free(binaries);
with_binary_sizes:
  free(binary_sizes);
with_devices:
  free(devices);
with_noting:
  return;
}

static void dump_program_binaries(cl_program program) {
  cl_int err = CL_SUCCESS;
  cl_device_id *devices;
  cl_uint num_devices;
  size_t *binary_sizes;
  size_t total_size = 0;
  void **binaries;
  char (*paths)[sizeof(BIN_BUILD_TEMPLATE)];
  int *fds;
  cl_uint i;

  devices = get_program_devices(program, &num_devices);
  if (!devices)
    goto with_noting;
  binary_sizes = (size_t *)malloc(num_devices * sizeof(size_t));
  if (!binary_sizes)
    goto with_devices;

  err = CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_BINARY_SIZES, num_devices * sizeof(size_t),
                                binary_sizes, NULL);
  if (err != CL_SUCCESS)
    goto with_binary_sizes;

  binaries = (void **)calloc(num_devices * sizeof(void *), 1);
  if (!binaries)
    goto with_binary_sizes;
  paths = (char (*)[sizeof(BIN_BUILD_TEMPLATE)])calloc(num_devices * sizeof(BIN_BUILD_TEMPLATE), 1);
  if (!paths)
    goto with_binaries;
  fds = (int *)calloc(num_devices * sizeof(int), 1);
  if (!fds)
    goto with_paths;

  for (i = 0; i < num_devices; i++) {
    if (binary_sizes[i] > 0) {
      strncpy(paths[i], BIN_BUILD_TEMPLATE, sizeof(paths[i]));
      fds[i] = create_file_and_map(paths[i], binary_sizes[i], binaries + i);
      if (fds[i] == -1) {
        for (cl_uint j = i; j > 0; j--) {
          if (binary_sizes[j - 1] > 0) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
            ftruncate(fds[j - 1], 0);
#pragma GCC diagnostic pop
            close(fds[j - 1]);
            unlink(paths[j - 1]);
          }
        }
        goto with_fds;
      }
      total_size += binary_sizes[i];
    }
  }

  err = CL_GET_PROGRAM_INFO_PTR(program, CL_PROGRAM_BINARIES, total_size, binaries, NULL);
  if (err != CL_SUCCESS) {
    for (i = 0; i < num_devices; i++) {
      if (binary_sizes[i] > 0) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
        ftruncate(fds[i], 0);
#pragma GCC diagnostic pop
        close(fds[i]);
        unlink(paths[i]);
      }
    }
  }
  for (i = 0; i < num_devices; i++) {
    int e = ftruncate(fds[i], binary_sizes[i]);
    if (e) {
      unlink(paths[i]);
      close(fds[i]);
    } else {
      close(fds[i]);
      do_tracepoint(lttng_ust_opencl_build, binaries, program, devices[i], binary_sizes[i],
                    paths[i]);
    }
  }
with_fds:
  free(fds);
with_paths:
  free(paths);
with_binaries:
  free(binaries);
with_binary_sizes:
  free(binary_sizes);
with_devices:
  free(devices);
with_noting:
  return;
}

struct clLinkProgram_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data);
  void *user_data;
};

void CL_CALLBACK clLinkProgram_callback(cl_program program, void *user_data) {
  struct clLinkProgram_callback_payload *payload =
      (struct clLinkProgram_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clLinkProgram_callback), program,
                     payload->user_data);
  payload->pfn_notify(program, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clLinkProgram_callback), program, payload->user_data);
  if (tracepoint_enabled(lttng_ust_opencl_build, binaries))
    dump_program_binaries(program);
  if (tracepoint_enabled(lttng_ust_opencl_build, infos))
    dump_program_build_infos(program);
  free(user_data);
}

struct clCompileProgram_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data);
  void *user_data;
};

void CL_CALLBACK clCompileProgram_callback(cl_program program, void *user_data) {
  struct clCompileProgram_callback_payload *payload =
      (struct clCompileProgram_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clCompileProgram_callback), program,
                     payload->user_data);
  payload->pfn_notify(program, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clCompileProgram_callback), program,
                     payload->user_data);
  if (tracepoint_enabled(lttng_ust_opencl_build, objects))
    dump_program_objects(program);
  if (tracepoint_enabled(lttng_ust_opencl_build, infos))
    dump_program_build_infos(program);
  free(user_data);
}

struct clBuildProgram_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data);
  void *user_data;
};

void CL_CALLBACK clBuildProgram_callback(cl_program program, void *user_data) {
  struct clBuildProgram_callback_payload *payload =
      (struct clBuildProgram_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clBuildProgram_callback), program,
                     payload->user_data);
  payload->pfn_notify(program, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clBuildProgram_callback), program,
                     payload->user_data);
  if (tracepoint_enabled(lttng_ust_opencl_build, binaries))
    dump_program_binaries(program);
  if (tracepoint_enabled(lttng_ust_opencl_build, infos))
    dump_program_build_infos(program);
  free(user_data);
}

struct clCreateContext_callback_payload {
  void(CL_CALLBACK *pfn_notify)(const char *errinfo,
                                const void *private_info,
                                size_t cb,
                                void *user_data);
  void *user_data;
};

void CL_CALLBACK clCreateContext_callback(const char *errinfo,
                                          const void *private_info,
                                          size_t cb,
                                          void *user_data) {
  struct clCreateContext_callback_payload *payload =
      (struct clCreateContext_callback_payload *)user_data;

  tracepoint_safe(lttng_ust_opencl, STARTEV(clCreateContext_callback), errinfo, private_info, cb,
                  payload->user_data);
  payload->pfn_notify(errinfo, private_info, cb, payload->user_data);
  tracepoint_safe(lttng_ust_opencl, STOPEV(clCreateContext_callback), errinfo, private_info, cb,
                  payload->user_data);
}

struct clCreateContextFromType_callback_payload {
  void(CL_CALLBACK *pfn_notify)(const char *errinfo,
                                const void *private_info,
                                size_t cb,
                                void *user_data);
  void *user_data;
};

void CL_CALLBACK clCreateContextFromType_callback(const char *errinfo,
                                                  const void *private_info,
                                                  size_t cb,
                                                  void *user_data) {
  struct clCreateContextFromType_callback_payload *payload =
      (struct clCreateContextFromType_callback_payload *)user_data;

  tracepoint_safe(lttng_ust_opencl, STARTEV(clCreateContextFromType_callback), errinfo,
                  private_info, cb, payload->user_data);
  payload->pfn_notify(errinfo, private_info, cb, payload->user_data);
  tracepoint_safe(lttng_ust_opencl, STOPEV(clCreateContextFromType_callback), errinfo, private_info,
                  cb, payload->user_data);
}

struct clSetMemObjectDestructorCallback_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_mem memobj, void *user_data);
  void *user_data;
};

void CL_CALLBACK clSetMemObjectDestructorCallback_callback(cl_mem memobj, void *user_data) {
  struct clSetMemObjectDestructorCallback_callback_payload *payload =
      (struct clSetMemObjectDestructorCallback_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clSetMemObjectDestructorCallback_callback), memobj,
                     payload->user_data);
  payload->pfn_notify(memobj, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clSetMemObjectDestructorCallback_callback), memobj,
                     payload->user_data);
  free(user_data);
}

struct clSetProgramReleaseCallback_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data);
  void *user_data;
};

void CL_CALLBACK clSetProgramReleaseCallback_callback(cl_program program, void *user_data) {
  struct clSetProgramReleaseCallback_callback_payload *payload =
      (struct clSetProgramReleaseCallback_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clSetProgramReleaseCallback_callback), program,
                     payload->user_data);
  payload->pfn_notify(program, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clSetProgramReleaseCallback_callback), program,
                     payload->user_data);
  free(user_data);
}

struct clSetEventCallback_callback_payload {
  void(CL_CALLBACK *pfn_notify)(cl_event event, cl_int type, void *user_data);
  void *user_data;
};

void CL_CALLBACK clSetEventCallback_callback(cl_event event, cl_int type, void *user_data) {
  struct clSetEventCallback_callback_payload *payload =
      (struct clSetEventCallback_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clSetEventCallback_callback), event, type,
                     payload->user_data);
  payload->pfn_notify(event, type, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clSetEventCallback_callback), event, type,
                     payload->user_data);
  free(user_data);
}

struct clEnqueueSVMFree_callback_payload {
  void(CL_CALLBACK *pfn_free_func)(cl_command_queue command_queue,
                                   cl_uint num_svm_pointers,
                                   void *svm_pointers[],
                                   void *user_data);
  void *user_data;
};

void CL_CALLBACK clEnqueueSVMFree_callback(cl_command_queue command_queue,
                                           cl_uint num_svm_pointers,
                                           void *svm_pointers[],
                                           void *user_data) {
  struct clEnqueueSVMFree_callback_payload *payload =
      (struct clEnqueueSVMFree_callback_payload *)user_data;

  do_tracepoint_safe(lttng_ust_opencl, STARTEV(clEnqueueSVMFree_callback), command_queue,
                     num_svm_pointers, svm_pointers, payload->user_data);
  payload->pfn_free_func(command_queue, num_svm_pointers, svm_pointers, payload->user_data);
  do_tracepoint_safe(lttng_ust_opencl, STOPEV(clEnqueueSVMFree_callback), command_queue,
                     num_svm_pointers, svm_pointers, payload->user_data);
  free(user_data);
}

static inline uint64_t get_timestamp_ns() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ((uint64_t)ts.tv_sec) * 1000000000 + ((uint64_t)ts.tv_nsec);
}

static pthread_once_t _init = PTHREAD_ONCE_INIT;
static __thread volatile int in_init = 0;
static volatile cl_uint _initialized = 0;

static void _load_tracer(void) {
  char *s = NULL;
  void *handle = NULL;
  int verbose = 0;

  s = getenv("LTTNG_UST_OPENCL_LIBOPENCL");
  if (s)
    handle = dlopen(s, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
  else
    handle = dlopen("libOpenCL.so", RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
  if (handle) {
    void *ptr = dlsym(handle, "clGetPlatformIDs");
    if (ptr == (void *)&clGetPlatformIDs) { // opening oneself
      dlclose(handle);
      handle = NULL;
    }
  }

  if (!handle) {
    printf("Failure: could not load OpenCL library!\n");
    exit(1);
  }

  s = getenv("LTTNG_UST_OPENCL_HOST_PROFILE");
  if (s)
    do_host_profile = 1;
  s = getenv("LTTNG_UST_OPENCL_DUMP");
  if (s)
    do_dump = 1;
  s = getenv("LTTNG_UST_OPENCL_DUMP_START");
  if (s)
    dump_start = atoll(s);
  s = getenv("LTTNG_UST_OPENCL_DUMP_END");
  if (s)
    dump_end = atoll(s);

  s = getenv("LTTNG_UST_OPENCL_VERBOSE");
  if (s)
    verbose = 1;

  find_opencl_symbols(handle, verbose);
}

static inline void _init_tracer(void) {
  if (__builtin_expect(_initialized, 1))
    return;
  /* Avoid reentrancy */
  if (!in_init) {
    in_init = 1;
    __sync_synchronize();
    pthread_once(&_init, _load_tracer);
    __sync_synchronize();
    in_init = 0;
  }
  _initialized = 1;
}
CL_API_ENTRY cl_event CL_API_CALL clCreateEventFromEGLSyncKHR(cl_context context, CLeglSyncKHR sync, CLeglDisplayKHR display, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateEventFromEGLSyncKHR_entry, context, sync, display, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_event _retval;
  _retval = CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR(context, sync, display, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling) ) {
    int _set_retval = CL_SET_EVENT_CALLBACK_PTR(_retval, CL_COMPLETE, event_notify, NULL);
    do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, _retval);
  }
  tracepoint(lttng_ust_opencl, clCreateEventFromEGLSyncKHR_exit, context, sync, display, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromEGLImageKHR(cl_context context, CLeglDisplayKHR egldisplay, CLeglImageKHR eglimage, cl_mem_flags flags, const cl_egl_image_properties_khr * properties, cl_int * errcode_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateFromEGLImageKHR_entry, context, egldisplay, eglimage, flags, properties, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_EGLIMAGE_KHR_PTR(context, egldisplay, eglimage, flags, properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromEGLImageKHR_exit, context, egldisplay, eglimage, flags, properties, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueAcquireEGLObjectsKHR(cl_command_queue command_queue, cl_uint num_objects, const cl_mem * mem_objects, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueAcquireEGLObjectsKHR_entry, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR(command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueAcquireEGLObjectsKHR_exit, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueReleaseEGLObjectsKHR(cl_command_queue command_queue, cl_uint num_objects, const cl_mem * mem_objects, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueReleaseEGLObjectsKHR_entry, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR(command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueReleaseEGLObjectsKHR_exit, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseDeviceEXT(cl_device_id device) {
  tracepoint(lttng_ust_opencl, clReleaseDeviceEXT_entry, device);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_DEVICE_EXT_PTR(device);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseDeviceEXT_exit, device, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainDeviceEXT(cl_device_id device) {
  tracepoint(lttng_ust_opencl, clRetainDeviceEXT_entry, device);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_DEVICE_EXT_PTR(device);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainDeviceEXT_exit, device, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clCreateSubDevicesEXT(cl_device_id in_device, const cl_device_partition_property_ext * properties, cl_uint num_entries, cl_device_id * out_devices, cl_uint * num_devices) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size++] != CL_PROPERTIES_LIST_END_EXT) {
      switch(properties[_properties_size]) {
      case CL_DEVICE_PARTITION_EQUALLY_EXT:
      case CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN_EXT:
        _properties_size++; //value
        break;
      case CL_DEVICE_PARTITION_BY_COUNTS_EXT:
        while(properties[_properties_size++] != CL_PARTITION_BY_COUNTS_LIST_END_EXT);
        break;
      case CL_DEVICE_PARTITION_BY_NAMES_EXT:
        while(properties[_properties_size] != (cl_device_partition_property_ext)CL_PARTITION_BY_NAMES_LIST_END_EXT);
        break;
      }
    }
  }
  tracepoint(lttng_ust_opencl, clCreateSubDevicesEXT_entry, in_device, properties, num_entries, out_devices, num_devices, _properties_size);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_CREATE_SUB_DEVICES_EXT_PTR(in_device, properties, num_entries, out_devices, num_devices);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateSubDevicesEXT_exit, in_device, properties, num_entries, out_devices, num_devices, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetKernelSubGroupInfoKHR(cl_kernel in_kernel, cl_device_id in_device, cl_kernel_sub_group_info param_name, size_t input_value_size, const void * input_value, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetKernelSubGroupInfoKHR_entry, in_kernel, in_device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR(in_kernel, in_device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetKernelSubGroupInfoKHR_exit, in_kernel, in_device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_event CL_API_CALL clCreateEventFromGLsyncKHR(cl_context context, cl_GLsync sync, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateEventFromGLsyncKHR_entry, context, sync, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_event _retval;
  _retval = CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR(context, sync, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling) ) {
    int _set_retval = CL_SET_EVENT_CALLBACK_PTR(_retval, CL_COMPLETE, event_notify, NULL);
    do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, _retval);
  }
  tracepoint(lttng_ust_opencl, clCreateEventFromGLsyncKHR_exit, context, sync, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetGLContextInfoKHR(const cl_context_properties * properties, cl_gl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetGLContextInfoKHR_entry, properties, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_GLCONTEXT_INFO_KHR_PTR(properties, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetGLContextInfoKHR_exit, properties, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromGLBuffer(cl_context context, cl_mem_flags flags, cl_GLuint bufobj, int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateFromGLBuffer_entry, context, flags, bufobj, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_GLBUFFER_PTR(context, flags, bufobj, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromGLBuffer_exit, context, flags, bufobj, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromGLTexture(cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture_entry, context, flags, target, miplevel, texture, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_GLTEXTURE_PTR(context, flags, target, miplevel, texture, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture_exit, context, flags, target, miplevel, texture, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromGLRenderbuffer(cl_context context, cl_mem_flags flags, cl_GLuint renderbuffer, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateFromGLRenderbuffer_entry, context, flags, renderbuffer, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_GLRENDERBUFFER_PTR(context, flags, renderbuffer, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromGLRenderbuffer_exit, context, flags, renderbuffer, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetGLObjectInfo(cl_mem memobj, cl_gl_object_type * gl_object_type, cl_GLuint * gl_object_name) {
  tracepoint(lttng_ust_opencl, clGetGLObjectInfo_entry, memobj, gl_object_type, gl_object_name);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_GLOBJECT_INFO_PTR(memobj, gl_object_type, gl_object_name);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetGLObjectInfo_exit, memobj, gl_object_type, gl_object_name, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetGLTextureInfo(cl_mem memobj, cl_gl_texture_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetGLTextureInfo_entry, memobj, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_GLTEXTURE_INFO_PTR(memobj, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetGLTextureInfo_exit, memobj, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueAcquireGLObjects(cl_command_queue command_queue, cl_uint num_objects, const cl_mem * mem_objects, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueAcquireGLObjects_entry, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR(command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueAcquireGLObjects_exit, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueReleaseGLObjects(cl_command_queue command_queue, cl_uint num_objects, const cl_mem * mem_objects, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueReleaseGLObjects_entry, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_RELEASE_GLOBJECTS_PTR(command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueReleaseGLObjects_exit, command_queue, num_objects, mem_objects, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromGLTexture2D(cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture2D_entry, context, flags, target, miplevel, texture, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_GLTEXTURE2_D_PTR(context, flags, target, miplevel, texture, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture2D_exit, context, flags, target, miplevel, texture, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateFromGLTexture3D(cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture3D_entry, context, flags, target, miplevel, texture, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_FROM_GLTEXTURE3_D_PTR(context, flags, target, miplevel, texture, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateFromGLTexture3D_exit, context, flags, target, miplevel, texture, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetPlatformIDs_entry, num_entries, platforms, num_platforms);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_PLATFORM_IDS_PTR(num_entries, platforms, num_platforms);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetPlatformIDs_exit, num_entries, platforms, num_platforms, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetPlatformInfo_entry, platform, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_PLATFORM_INFO_PTR(platform, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetPlatformInfo_exit, platform, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetDeviceIDs_entry, platform, device_type, num_entries, devices, num_devices);
  cl_uint n_e;
  if (tracepoint_enabled(lttng_ust_opencl_devices, device_name) && !num_devices && devices) {
    num_devices = &n_e;
  }
  if (tracepoint_enabled(lttng_ust_opencl_devices, device_timer) && !num_devices && devices) {
    num_devices = &n_e;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_DEVICE_IDS_PTR(platform, device_type, num_entries, devices, num_devices);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (tracepoint_enabled(lttng_ust_opencl_devices, device_name) && _retval == CL_SUCCESS && devices) {
    for (cl_uint i = 0; i < *num_devices; i++) {
      dump_device_name(devices[i]);
    }
  }
  if (tracepoint_enabled(lttng_ust_opencl_devices, device_timer) && _retval == CL_SUCCESS && devices) {
    for (cl_uint i = 0; i < *num_devices; i++) {
      dump_device_timer(devices[i]);
    }
  }
  tracepoint(lttng_ust_opencl, clGetDeviceIDs_exit, platform, device_type, num_entries, devices, num_devices, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetDeviceInfo_entry, device, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_DEVICE_INFO_PTR(device, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetDeviceInfo_exit, device, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clCreateSubDevices(cl_device_id in_device, const cl_device_partition_property * properties, cl_uint num_devices, cl_device_id * out_devices, cl_uint * num_devices_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size++] != CL_PROPERTIES_LIST_END_EXT) {
      switch(properties[_properties_size]) {
      case CL_DEVICE_PARTITION_EQUALLY_EXT:
      case CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN_EXT:
        _properties_size++; //value
        break;
      case CL_DEVICE_PARTITION_BY_COUNTS_EXT:
        while(properties[_properties_size++] != CL_PARTITION_BY_COUNTS_LIST_END_EXT);
        break;
      case CL_DEVICE_PARTITION_BY_NAMES_EXT:
        while(properties[_properties_size] != (cl_device_partition_property)CL_PARTITION_BY_NAMES_LIST_END_EXT);
        break;
      }
    }
  }
  tracepoint(lttng_ust_opencl, clCreateSubDevices_entry, in_device, properties, num_devices, out_devices, num_devices_ret, _properties_size);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_CREATE_SUB_DEVICES_PTR(in_device, properties, num_devices, out_devices, num_devices_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateSubDevices_exit, in_device, properties, num_devices, out_devices, num_devices_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainDevice(cl_device_id device) {
  tracepoint(lttng_ust_opencl, clRetainDevice_entry, device);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_DEVICE_PTR(device);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainDevice_exit, device, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseDevice(cl_device_id device) {
  tracepoint(lttng_ust_opencl, clReleaseDevice_entry, device);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_DEVICE_PTR(device);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseDevice_exit, device, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetDefaultDeviceCommandQueue(cl_context context, cl_device_id device, cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clSetDefaultDeviceCommandQueue_entry, context, device, command_queue);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_DEFAULT_DEVICE_COMMAND_QUEUE_PTR(context, device, command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetDefaultDeviceCommandQueue_exit, context, device, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetDeviceAndHostTimer(cl_device_id device, cl_ulong * device_timestamp, cl_ulong * host_timestamp) {
  tracepoint(lttng_ust_opencl, clGetDeviceAndHostTimer_entry, device, device_timestamp, host_timestamp);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_DEVICE_AND_HOST_TIMER_PTR(device, device_timestamp, host_timestamp);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetDeviceAndHostTimer_exit, device, device_timestamp, host_timestamp, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetHostTimer(cl_device_id device, cl_ulong * host_timestamp) {
  tracepoint(lttng_ust_opencl, clGetHostTimer_entry, device, host_timestamp);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_HOST_TIMER_PTR(device, host_timestamp);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetHostTimer_exit, device, host_timestamp, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_context CL_API_CALL clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK* pfn_notify )(const char* errinfo, const void* private_info, size_t cb, void* user_data), void * user_data, cl_int * errcode_ret) {
  _init_tracer();
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateContext_entry, properties, num_devices, devices, (void *)(intptr_t)pfn_notify, user_data, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  struct clCreateContext_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clCreateContext_callback_entry)) && pfn_notify) {
    _payload = (struct clCreateContext_callback_payload *)malloc(sizeof(struct clCreateContext_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clCreateContext_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_context _retval;
  _retval = CL_CREATE_CONTEXT_PTR(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && !_retval)
    free(_payload);
  tracepoint(lttng_ust_opencl, clCreateContext_exit, properties, num_devices, devices, (void *)(intptr_t)pfn_notify, user_data, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_context CL_API_CALL clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK* pfn_notify )(const char* errinfo, const void* private_info, size_t cb, void* user_data), void * user_data, cl_int * errcode_ret) {
  _init_tracer();
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateContextFromType_entry, properties, device_type, (void *)(intptr_t)pfn_notify, user_data, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  struct clCreateContextFromType_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clCreateContextFromType_callback_entry)) && pfn_notify) {
    _payload = (struct clCreateContextFromType_callback_payload *)malloc(sizeof(struct clCreateContextFromType_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clCreateContextFromType_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_context _retval;
  _retval = CL_CREATE_CONTEXT_FROM_TYPE_PTR(properties, device_type, pfn_notify, user_data, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && !_retval)
    free(_payload);
  tracepoint(lttng_ust_opencl, clCreateContextFromType_exit, properties, device_type, (void *)(intptr_t)pfn_notify, user_data, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainContext(cl_context context) {
  tracepoint(lttng_ust_opencl, clRetainContext_entry, context);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_CONTEXT_PTR(context);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainContext_exit, context, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseContext(cl_context context) {
  tracepoint(lttng_ust_opencl, clReleaseContext_entry, context);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_CONTEXT_PTR(context);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseContext_exit, context, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetContextInfo_entry, context, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_CONTEXT_INFO_PTR(context, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetContextInfo_exit, context, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetContextDestructorCallback(cl_context context, void (CL_CALLBACK* pfn_notify )(cl_context context, void* user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clSetContextDestructorCallback_entry, context, (void *)(intptr_t)pfn_notify, user_data);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_CONTEXT_DESTRUCTOR_CALLBACK_PTR(context, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetContextDestructorCallback_exit, context, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_command_queue CL_API_CALL clCreateCommandQueueWithProperties(cl_context context, cl_device_id device, const cl_queue_properties * properties, cl_int * errcode_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateCommandQueueWithProperties_entry, context, device, properties, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  cl_queue_properties *_profiling_properties = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    int _found_queue_properties = 0;
    int _queue_properties_index = 0;
    int _properties_count = 0;
    if (properties) {
      while(properties[_properties_count]) {
        if (properties[_properties_count] == CL_QUEUE_PROPERTIES){
          _found_queue_properties = 1;
          _queue_properties_index = _properties_count;
        }
        _properties_count += 2;
      }
      _properties_count++;
      if (!_found_queue_properties)
        _properties_count +=2;
    } else
      _properties_count = 3;
    _profiling_properties = (cl_queue_properties *)malloc(_properties_count*sizeof(cl_queue_properties));
    if (_profiling_properties) {
      if (properties) {
        int _i = 0;
        while(properties[_i]) {
          _profiling_properties[_i] = properties[_i];
          _profiling_properties[_i+1] = properties[_i+1];
          _i += 2;
        }
        if (_found_queue_properties) {
          _profiling_properties[_queue_properties_index+1] |= CL_QUEUE_PROFILING_ENABLE;
          _profiling_properties[_i] = 0;
        } else {
          _profiling_properties[_i++] = CL_QUEUE_PROPERTIES;
          _profiling_properties[_i++] = CL_QUEUE_PROFILING_ENABLE;
          _profiling_properties[_i] = 0;
        }
      } else {
        _profiling_properties[0] = CL_QUEUE_PROPERTIES;
        _profiling_properties[1] = CL_QUEUE_PROFILING_ENABLE;
        _profiling_properties[2] = 0;
      }
      properties = _profiling_properties;
    }
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_command_queue _retval;
  _retval = CL_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_PTR(context, device, properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_profiling_properties) free(_profiling_properties);
  tracepoint(lttng_ust_opencl, clCreateCommandQueueWithProperties_exit, context, device, properties, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainCommandQueue(cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clRetainCommandQueue_entry, command_queue);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_COMMAND_QUEUE_PTR(command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainCommandQueue_exit, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseCommandQueue(cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clReleaseCommandQueue_entry, command_queue);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_COMMAND_QUEUE_PTR(command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseCommandQueue_exit, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetCommandQueueInfo_entry, command_queue, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_COMMAND_QUEUE_INFO_PTR(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetCommandQueueInfo_exit, command_queue, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateBuffer_entry, context, flags, size, host_ptr, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (do_dump) {
    flags &= ~CL_MEM_HOST_WRITE_ONLY;
    flags &= ~CL_MEM_HOST_NO_ACCESS;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_BUFFER_PTR(context, flags, size, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _retval != NULL) {
    add_buffer(_retval, size);
  }
  tracepoint(lttng_ust_opencl, clCreateBuffer_exit, context, flags, size, host_ptr, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateBufferWithProperties(cl_context context, const cl_mem_properties * properties, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateBufferWithProperties_entry, context, properties, flags, size, host_ptr, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_BUFFER_WITH_PROPERTIES_PTR(context, properties, flags, size, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateBufferWithProperties_exit, context, properties, flags, size, host_ptr, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, const void * buffer_create_info, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateSubBuffer_entry, buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_SUB_BUFFER_PTR(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateSubBuffer_exit, buffer, flags, buffer_create_type, buffer_create_info, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImage(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, const cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateImage_entry, context, flags, image_format, image_desc, host_ptr, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_IMAGE_PTR(context, flags, image_format, image_desc, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateImage_exit, context, flags, image_format, image_desc, host_ptr, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImageWithProperties(cl_context context, const cl_mem_properties * properties, cl_mem_flags flags, const cl_image_format * image_format, const cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateImageWithProperties_entry, context, properties, flags, image_format, image_desc, host_ptr, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_IMAGE_WITH_PROPERTIES_PTR(context, properties, flags, image_format, image_desc, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateImageWithProperties_exit, context, properties, flags, image_format, image_desc, host_ptr, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreatePipe(cl_context context, cl_mem_flags flags, cl_uint pipe_packet_size, cl_uint pipe_max_packets, const cl_pipe_properties * properties, cl_int * errcode_ret) {
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreatePipe_entry, context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_PIPE_PTR(context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreatePipe_exit, context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret, _retval, _duration, _properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainMemObject(cl_mem memobj) {
  tracepoint(lttng_ust_opencl, clRetainMemObject_entry, memobj);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_MEM_OBJECT_PTR(memobj);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainMemObject_exit, memobj, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseMemObject(cl_mem memobj) {
  tracepoint(lttng_ust_opencl, clReleaseMemObject_entry, memobj);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_MEM_OBJECT_PTR(memobj);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseMemObject_exit, memobj, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetSupportedImageFormats(cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats) {
  tracepoint(lttng_ust_opencl, clGetSupportedImageFormats_entry, context, flags, image_type, num_entries, image_formats, num_image_formats);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_SUPPORTED_IMAGE_FORMATS_PTR(context, flags, image_type, num_entries, image_formats, num_image_formats);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetSupportedImageFormats_exit, context, flags, image_type, num_entries, image_formats, num_image_formats, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetMemObjectInfo_entry, memobj, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_MEM_OBJECT_INFO_PTR(memobj, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetMemObjectInfo_exit, memobj, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetImageInfo(cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetImageInfo_entry, image, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_IMAGE_INFO_PTR(image, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetImageInfo_exit, image, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetPipeInfo(cl_mem pipe, cl_pipe_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetPipeInfo_entry, pipe, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_PIPE_INFO_PTR(pipe, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetPipeInfo_exit, pipe, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetMemObjectDestructorCallback(cl_mem memobj, void (CL_CALLBACK* pfn_notify )(cl_mem memobj, void* user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clSetMemObjectDestructorCallback_entry, memobj, (void *)(intptr_t)pfn_notify, user_data);
  struct clSetMemObjectDestructorCallback_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clSetMemObjectDestructorCallback_callback_entry)) && pfn_notify) {
    _payload = (struct clSetMemObjectDestructorCallback_callback_payload *)malloc(sizeof(struct clSetMemObjectDestructorCallback_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clSetMemObjectDestructorCallback_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_PTR(memobj, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  tracepoint(lttng_ust_opencl, clSetMemObjectDestructorCallback_exit, memobj, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void * CL_API_CALL clSVMAlloc(cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment) {
  tracepoint(lttng_ust_opencl, clSVMAlloc_entry, context, flags, size, alignment);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = CL_SVMALLOC_PTR(context, flags, size, alignment);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _retval != NULL) {
    add_svmptr(_retval, size);
  }
  tracepoint(lttng_ust_opencl, clSVMAlloc_exit, context, flags, size, alignment, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void CL_API_CALL clSVMFree(cl_context context, void * svm_pointer) {
  tracepoint(lttng_ust_opencl, clSVMFree_entry, context, svm_pointer);
  if (do_dump && svm_pointer != NULL) {
    remove_svmptr(svm_pointer);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  CL_SVMFREE_PTR(context, svm_pointer);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSVMFree_exit, context, svm_pointer, _duration);
}

CL_API_ENTRY cl_sampler CL_API_CALL clCreateSamplerWithProperties(cl_context context, const cl_sampler_properties * sampler_properties, cl_int * errcode_ret) {
  size_t _sampler_properties_size;
  _sampler_properties_size = 0;
  if(sampler_properties != NULL) {
    while(sampler_properties[_sampler_properties_size] != 0) {
      _sampler_properties_size += 2;
    }
    _sampler_properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateSamplerWithProperties_entry, context, sampler_properties, errcode_ret, _sampler_properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_sampler _retval;
  _retval = CL_CREATE_SAMPLER_WITH_PROPERTIES_PTR(context, sampler_properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateSamplerWithProperties_exit, context, sampler_properties, errcode_ret, _retval, _duration, _sampler_properties_size);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainSampler(cl_sampler sampler) {
  tracepoint(lttng_ust_opencl, clRetainSampler_entry, sampler);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_SAMPLER_PTR(sampler);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainSampler_exit, sampler, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseSampler(cl_sampler sampler) {
  tracepoint(lttng_ust_opencl, clReleaseSampler_entry, sampler);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_SAMPLER_PTR(sampler);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseSampler_exit, sampler, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetSamplerInfo_entry, sampler, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_SAMPLER_INFO_PTR(sampler, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetSamplerInfo_exit, sampler, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithSource(cl_context context, cl_uint count, const char ** strings, const size_t * lengths, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateProgramWithSource_entry, context, count, strings, lengths, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (tracepoint_enabled(lttng_ust_opencl_source, program_string) && strings != NULL) {
    cl_uint index;
    for (index = 0; index < count; index++) {
      size_t length = 0;
      char path[sizeof(SOURCE_TEMPLATE)];
      strncpy(path, SOURCE_TEMPLATE, sizeof(path));
      if ( strings[index] != NULL ) {
        if (lengths == NULL || lengths[index] == 0)
          length = strlen(strings[index]);
        else
          length = lengths[index];
      }
      create_file_and_write(path, length, strings[index]);
      do_tracepoint(lttng_ust_opencl_source, program_string, index, length, path);
    }
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = CL_CREATE_PROGRAM_WITH_SOURCE_PTR(context, count, strings, lengths, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateProgramWithSource_exit, context, count, strings, lengths, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const size_t * lengths, const unsigned char ** binaries, cl_int * binary_status, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateProgramWithBinary_entry, context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (tracepoint_enabled(lttng_ust_opencl_source, program_binary) && binaries != NULL && lengths != NULL) {
    cl_uint index;
    for (index = 0; index < num_devices; index++) {
      char path[sizeof(BIN_SOURCE_TEMPLATE)];
      strncpy(path, BIN_SOURCE_TEMPLATE, sizeof(path));
      create_file_and_write(path, lengths[index], binaries[index]);
      do_tracepoint(lttng_ust_opencl_source, program_binary, index, lengths[index], path);
    }
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = CL_CREATE_PROGRAM_WITH_BINARY_PTR(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateProgramWithBinary_exit, context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithBuiltInKernels(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const char * kernel_names, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateProgramWithBuiltInKernels_entry, context, num_devices, device_list, kernel_names, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_PTR(context, num_devices, device_list, kernel_names, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateProgramWithBuiltInKernels_exit, context, num_devices, device_list, kernel_names, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithIL(cl_context context, const void * il, size_t length, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateProgramWithIL_entry, context, il, length, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (tracepoint_enabled(lttng_ust_opencl_source, program_il) && il != NULL) {
    char path[sizeof(IL_SOURCE_TEMPLATE)];
    strncpy(path, IL_SOURCE_TEMPLATE, sizeof(path));
    create_file_and_write(path, length, il);
    do_tracepoint(lttng_ust_opencl_source, program_il, length, path);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = CL_CREATE_PROGRAM_WITH_IL_PTR(context, il, length, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateProgramWithIL_exit, context, il, length, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainProgram(cl_program program) {
  tracepoint(lttng_ust_opencl, clRetainProgram_entry, program);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_PROGRAM_PTR(program);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainProgram_exit, program, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseProgram(cl_program program) {
  tracepoint(lttng_ust_opencl, clReleaseProgram_entry, program);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_PROGRAM_PTR(program);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseProgram_exit, program, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, void (CL_CALLBACK* pfn_notify )(cl_program program, void* user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clBuildProgram_entry, program, num_devices, device_list, options, (void *)(intptr_t)pfn_notify, user_data);
  int _free_options = 0;
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info)) {
    struct opencl_version version = {1, 0};
    get_program_platform_version(program, &version);
    if (compare_opencl_version(&version, &opencl_version_1_2) >= 0) {
      if (options) {
        if (!strstr(options, "-cl-kernel-arg-info")) {
          size_t sz = strlen(options) + strlen("-cl-kernel-arg-info") + 2;
          char * new_options = (char *)malloc(sz);
          if (new_options) {
            snprintf(new_options, sz, "%s %s", options, "-cl-kernel-arg-info");
            _free_options = 1;
            options = new_options;
          }
        }
      } else {
        options = "-cl-kernel-arg-info";
      }
    }
  }
  struct clBuildProgram_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clBuildProgram_callback_entry) || tracepoint_enabled(lttng_ust_opencl_build, binaries) || tracepoint_enabled(lttng_ust_opencl_build, infos)) && pfn_notify) {
    _payload = (struct clBuildProgram_callback_payload *)malloc(sizeof(struct clBuildProgram_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clBuildProgram_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_BUILD_PROGRAM_PTR(program, num_devices, device_list, options, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_free_options)
    free((char *)options);
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  if (tracepoint_enabled(lttng_ust_opencl_build, binaries) && !pfn_notify) {
    dump_program_binaries(program);
  }
  if (tracepoint_enabled(lttng_ust_opencl_build, infos) && !pfn_notify) {
    dump_program_build_infos(program);
  }
  tracepoint(lttng_ust_opencl, clBuildProgram_exit, program, num_devices, device_list, options, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clCompileProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, cl_uint num_input_headers, const cl_program * input_headers, const char ** header_include_names, void (CL_CALLBACK* pfn_notify )(cl_program program, void* user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clCompileProgram_entry, program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, (void *)(intptr_t)pfn_notify, user_data);
  int _free_options = 0;
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info)) {
    struct opencl_version version = {1, 0};
    get_program_platform_version(program, &version);
    if (compare_opencl_version(&version, &opencl_version_1_2) >= 0) {
      if (options) {
        if (!strstr(options, "-cl-kernel-arg-info")) {
          size_t sz = strlen(options) + strlen("-cl-kernel-arg-info") + 2;
          char * new_options = (char *)malloc(sz);
          if (new_options) {
            snprintf(new_options, sz, "%s %s", options, "-cl-kernel-arg-info");
            _free_options = 1;
            options = new_options;
          }
        }
      } else {
        options = "-cl-kernel-arg-info";
      }
    }
  }
  struct clCompileProgram_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clCompileProgram_callback_entry) || tracepoint_enabled(lttng_ust_opencl_build, objects) || tracepoint_enabled(lttng_ust_opencl_build, infos)) && pfn_notify) {
    _payload = (struct clCompileProgram_callback_payload *)malloc(sizeof(struct clCompileProgram_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clCompileProgram_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_COMPILE_PROGRAM_PTR(program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_free_options)
    free((char *)options);
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  if (tracepoint_enabled(lttng_ust_opencl_build, objects) && !pfn_notify) {
    dump_program_objects(program);
  }
  if (tracepoint_enabled(lttng_ust_opencl_build, infos) && !pfn_notify) {
    dump_program_build_infos(program);
  }
  tracepoint(lttng_ust_opencl, clCompileProgram_exit, program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_program CL_API_CALL clLinkProgram(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const char * options, cl_uint num_input_programs, const cl_program * input_programs, void (CL_CALLBACK* pfn_notify )(cl_program program, void* user_data), void * user_data, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clLinkProgram_entry, context, num_devices, device_list, options, num_input_programs, input_programs, (void *)(intptr_t)pfn_notify, user_data, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  int _free_options = 0;
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info) && input_programs && num_input_programs > 0) {
    struct opencl_version version = {1, 0};
    get_program_platform_version(*input_programs, &version);
    if (compare_opencl_version(&version, &opencl_version_1_2) >= 0) {
      if (options) {
        if (!strstr(options, "-cl-kernel-arg-info")) {
          size_t sz = strlen(options) + strlen("-cl-kernel-arg-info") + 2;
          char * new_options = (char *)malloc(sz);
          if (new_options) {
            snprintf(new_options, sz, "%s %s", options, "-cl-kernel-arg-info");
            _free_options = 1;
            options = new_options;
          }
        }
      } else {
        options = "-cl-kernel-arg-info";
      }
    }
  }
  struct clLinkProgram_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clLinkProgram_callback_entry) || tracepoint_enabled(lttng_ust_opencl_build, binaries) || tracepoint_enabled(lttng_ust_opencl_build, infos)) && pfn_notify) {
    _payload = (struct clLinkProgram_callback_payload *)malloc(sizeof(struct clLinkProgram_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clLinkProgram_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = CL_LINK_PROGRAM_PTR(context, num_devices, device_list, options, num_input_programs, input_programs, pfn_notify, user_data, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_free_options)
    free((char *)options);
  if (_payload && !_retval)
    free(_payload);
  if (tracepoint_enabled(lttng_ust_opencl_build, binaries) && _retval && !pfn_notify) {
    dump_program_binaries(_retval);
  }
  if (tracepoint_enabled(lttng_ust_opencl_build, infos) && _retval && !pfn_notify) {
    dump_program_build_infos(_retval);
  }
  tracepoint(lttng_ust_opencl, clLinkProgram_exit, context, num_devices, device_list, options, num_input_programs, input_programs, (void *)(intptr_t)pfn_notify, user_data, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetProgramReleaseCallback(cl_program program, void (CL_CALLBACK* pfn_notify )(cl_program program, void* user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clSetProgramReleaseCallback_entry, program, (void *)(intptr_t)pfn_notify, user_data);
  struct clSetProgramReleaseCallback_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clSetProgramReleaseCallback_callback_entry)) && pfn_notify) {
    _payload = (struct clSetProgramReleaseCallback_callback_payload *)malloc(sizeof(struct clSetProgramReleaseCallback_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clSetProgramReleaseCallback_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_PROGRAM_RELEASE_CALLBACK_PTR(program, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  tracepoint(lttng_ust_opencl, clSetProgramReleaseCallback_exit, program, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetProgramSpecializationConstant(cl_program program, cl_uint spec_id, size_t spec_size, const void * spec_value) {
  tracepoint(lttng_ust_opencl, clSetProgramSpecializationConstant_entry, program, spec_id, spec_size, spec_value);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_PROGRAM_SPECIALIZATION_CONSTANT_PTR(program, spec_id, spec_size, spec_value);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetProgramSpecializationConstant_exit, program, spec_id, spec_size, spec_value, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clUnloadPlatformCompiler(cl_platform_id platform) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clUnloadPlatformCompiler_entry, platform);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_UNLOAD_PLATFORM_COMPILER_PTR(platform);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clUnloadPlatformCompiler_exit, platform, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetProgramInfo(cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetProgramInfo_entry, program, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_PROGRAM_INFO_PTR(program, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetProgramInfo_exit, program, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetProgramBuildInfo(cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetProgramBuildInfo_entry, program, device, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_PROGRAM_BUILD_INFO_PTR(program, device, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetProgramBuildInfo_exit, program, device, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_kernel CL_API_CALL clCreateKernel(cl_program program, const char * kernel_name, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateKernel_entry, program, kernel_name, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_kernel _retval;
  _retval = CL_CREATE_KERNEL_PTR(program, kernel_name, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _retval != NULL) {
    add_kernel(_retval);
  }
  if (tracepoint_enabled(lttng_ust_opencl_arguments, kernel_info)) {
    dump_kernel_info(_retval);
  }
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info) && _retval != NULL) {
    dump_kernel_arguments(program, _retval);
  }
  tracepoint(lttng_ust_opencl, clCreateKernel_exit, program, kernel_name, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel * kernels, cl_uint * num_kernels_ret) {
  tracepoint(lttng_ust_opencl, clCreateKernelsInProgram_entry, program, num_kernels, kernels, num_kernels_ret);
  cl_uint n_k = 0;
  if (tracepoint_enabled(lttng_ust_opencl_arguments, kernel_info) && !num_kernels_ret && kernels) {
    num_kernels_ret = &n_k;
  }
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info) && !num_kernels_ret && kernels) {
    num_kernels_ret = &n_k;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_CREATE_KERNELS_IN_PROGRAM_PTR(program, num_kernels, kernels, num_kernels_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (tracepoint_enabled(lttng_ust_opencl_arguments, kernel_info) && _retval == CL_SUCCESS && kernels) {
    for (cl_uint i = 0; i < *num_kernels_ret; i++) {
      dump_kernel_info(kernels[i]);
    }
  }
  if (tracepoint_enabled(lttng_ust_opencl_arguments, argument_info) && _retval == CL_SUCCESS && kernels) {
    for (cl_uint i = 0; i < *num_kernels_ret; i++) {
      dump_kernel_arguments(program, kernels[i]);
    }
  }
  tracepoint(lttng_ust_opencl, clCreateKernelsInProgram_exit, program, num_kernels, kernels, num_kernels_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_kernel CL_API_CALL clCloneKernel(cl_kernel source_kernel, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCloneKernel_entry, source_kernel, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_kernel _retval;
  _retval = CL_CLONE_KERNEL_PTR(source_kernel, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCloneKernel_exit, source_kernel, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainKernel(cl_kernel kernel) {
  tracepoint(lttng_ust_opencl, clRetainKernel_entry, kernel);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_KERNEL_PTR(kernel);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainKernel_exit, kernel, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseKernel(cl_kernel kernel) {
  tracepoint(lttng_ust_opencl, clReleaseKernel_entry, kernel);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_KERNEL_PTR(kernel);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseKernel_exit, kernel, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void * arg_value) {
  tracepoint(lttng_ust_opencl, clSetKernelArg_entry, kernel, arg_index, arg_size, arg_value);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_KERNEL_ARG_PTR(kernel, arg_index, arg_size, arg_value);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _retval == CL_SUCCESS) {
    add_kernel_arg(kernel, arg_index, arg_size, arg_value, 0);
  }
  tracepoint(lttng_ust_opencl, clSetKernelArg_exit, kernel, arg_index, arg_size, arg_value, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void * arg_value) {
  tracepoint(lttng_ust_opencl, clSetKernelArgSVMPointer_entry, kernel, arg_index, arg_value);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_KERNEL_ARG_SVMPOINTER_PTR(kernel, arg_index, arg_value);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _retval == CL_SUCCESS) {
    add_kernel_arg(kernel, arg_index, sizeof(arg_value), arg_value, 1);
  }
  tracepoint(lttng_ust_opencl, clSetKernelArgSVMPointer_exit, kernel, arg_index, arg_value, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetKernelExecInfo(cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void * param_value) {
  tracepoint(lttng_ust_opencl, clSetKernelExecInfo_entry, kernel, param_name, param_value_size, param_value);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_KERNEL_EXEC_INFO_PTR(kernel, param_name, param_value_size, param_value);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetKernelExecInfo_exit, kernel, param_name, param_value_size, param_value, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetKernelInfo_entry, kernel, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_KERNEL_INFO_PTR(kernel, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetKernelInfo_exit, kernel, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetKernelArgInfo_entry, kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_KERNEL_ARG_INFO_PTR(kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetKernelArgInfo_exit, kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetKernelWorkGroupInfo_entry, kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_KERNEL_WORK_GROUP_INFO_PTR(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetKernelWorkGroupInfo_exit, kernel, device, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetKernelSubGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_sub_group_info param_name, size_t input_value_size, const void * input_value, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetKernelSubGroupInfo_entry, kernel, device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_KERNEL_SUB_GROUP_INFO_PTR(kernel, device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetKernelSubGroupInfo_exit, kernel, device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clWaitForEvents(cl_uint num_events, const cl_event * event_list) {
  tracepoint(lttng_ust_opencl, clWaitForEvents_entry, num_events, event_list);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_WAIT_FOR_EVENTS_PTR(num_events, event_list);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clWaitForEvents_exit, num_events, event_list, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetEventInfo(cl_event event, cl_event_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetEventInfo_entry, event, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_EVENT_INFO_PTR(event, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetEventInfo_exit, event, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_event CL_API_CALL clCreateUserEvent(cl_context context, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateUserEvent_entry, context, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_event _retval;
  _retval = CL_CREATE_USER_EVENT_PTR(context, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateUserEvent_exit, context, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainEvent(cl_event event) {
  tracepoint(lttng_ust_opencl, clRetainEvent_entry, event);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RETAIN_EVENT_PTR(event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clRetainEvent_exit, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseEvent(cl_event event) {
  tracepoint(lttng_ust_opencl, clReleaseEvent_entry, event);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_RELEASE_EVENT_PTR(event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clReleaseEvent_exit, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetUserEventStatus(cl_event event, cl_int execution_status) {
  tracepoint(lttng_ust_opencl, clSetUserEventStatus_entry, event, execution_status);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_USER_EVENT_STATUS_PTR(event, execution_status);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetUserEventStatus_exit, event, execution_status, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetEventCallback(cl_event event, cl_int command_exec_callback_type, void (CL_CALLBACK* pfn_notify )(cl_event event, cl_int event_command_status, void *user_data), void * user_data) {
  tracepoint(lttng_ust_opencl, clSetEventCallback_entry, event, command_exec_callback_type, (void *)(intptr_t)pfn_notify, user_data);
  struct clSetEventCallback_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clSetEventCallback_callback_entry)) && pfn_notify) {
    _payload = (struct clSetEventCallback_callback_payload *)malloc(sizeof(struct clSetEventCallback_callback_payload));
    _payload->pfn_notify = pfn_notify;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_notify = &clSetEventCallback_callback;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_EVENT_CALLBACK_PTR(event, command_exec_callback_type, pfn_notify, user_data);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  tracepoint(lttng_ust_opencl, clSetEventCallback_exit, event, command_exec_callback_type, (void *)(intptr_t)pfn_notify, user_data, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) {
  tracepoint(lttng_ust_opencl, clGetEventProfilingInfo_entry, event, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_GET_EVENT_PROFILING_INFO_PTR(event, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetEventProfilingInfo_exit, event, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clFlush(cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clFlush_entry, command_queue);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_FLUSH_PTR(command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clFlush_exit, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clFinish(cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clFinish_entry, command_queue);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_FINISH_PTR(command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clFinish_exit, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t size, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueReadBuffer_entry, command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_READ_BUFFER_PTR(command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueReadBuffer_exit, command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueReadBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueReadBufferRect_entry, command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_READ_BUFFER_RECT_PTR(command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueReadBufferRect_exit, command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueWriteBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t size, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueWriteBuffer_entry, command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_WRITE_BUFFER_PTR(command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueWriteBuffer_exit, command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueWriteBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueWriteBufferRect_entry, command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_WRITE_BUFFER_RECT_PTR(command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueWriteBufferRect_exit, command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueFillBuffer(cl_command_queue command_queue, cl_mem buffer, const void * pattern, size_t pattern_size, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueFillBuffer_entry, command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_FILL_BUFFER_PTR(command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueFillBuffer_exit, command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueCopyBuffer(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueCopyBuffer_entry, command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_COPY_BUFFER_PTR(command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueCopyBuffer_exit, command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueCopyBufferRect(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, const size_t * src_origin, const size_t * dst_origin, const size_t * region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueCopyBufferRect_entry, command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_COPY_BUFFER_RECT_PTR(command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueCopyBufferRect_exit, command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueReadImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, const size_t * origin, const size_t * region, size_t row_pitch, size_t slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueReadImage_entry, command_queue, image, blocking_read, origin, region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_READ_IMAGE_PTR(command_queue, image, blocking_read, origin, region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueReadImage_exit, command_queue, image, blocking_read, origin, region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueWriteImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, const size_t * origin, const size_t * region, size_t input_row_pitch, size_t input_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueWriteImage_entry, command_queue, image, blocking_write, origin, region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_WRITE_IMAGE_PTR(command_queue, image, blocking_write, origin, region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueWriteImage_exit, command_queue, image, blocking_write, origin, region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueFillImage(cl_command_queue command_queue, cl_mem image, const void * fill_color, const size_t * origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueFillImage_entry, command_queue, image, fill_color, origin, region, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_FILL_IMAGE_PTR(command_queue, image, fill_color, origin, region, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueFillImage_exit, command_queue, image, fill_color, origin, region, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueCopyImage(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, const size_t * src_origin, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueCopyImage_entry, command_queue, src_image, dst_image, src_origin, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_COPY_IMAGE_PTR(command_queue, src_image, dst_image, src_origin, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueCopyImage_exit, command_queue, src_image, dst_image, src_origin, dst_origin, region, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueCopyImageToBuffer(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, const size_t * src_origin, const size_t * region, size_t dst_offset, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueCopyImageToBuffer_entry, command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_COPY_IMAGE_TO_BUFFER_PTR(command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueCopyImageToBuffer_exit, command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueCopyBufferToImage(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueCopyBufferToImage_entry, command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_COPY_BUFFER_TO_IMAGE_PTR(command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueCopyBufferToImage_exit, command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void * CL_API_CALL clEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, cl_map_flags map_flags, size_t offset, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clEnqueueMapBuffer_entry, command_queue, buffer, blocking_map, map_flags, offset, size, num_events_in_wait_list, event_wait_list, event, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = CL_ENQUEUE_MAP_BUFFER_PTR(command_queue, buffer, blocking_map, map_flags, offset, size, num_events_in_wait_list, event_wait_list, event, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMapBuffer_exit, command_queue, buffer, blocking_map, map_flags, offset, size, num_events_in_wait_list, event_wait_list, event, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void * CL_API_CALL clEnqueueMapImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, const size_t * origin, const size_t * region, size_t * image_row_pitch, size_t * image_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clEnqueueMapImage_entry, command_queue, image, blocking_map, map_flags, origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = CL_ENQUEUE_MAP_IMAGE_PTR(command_queue, image, blocking_map, map_flags, origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMapImage_exit, command_queue, image, blocking_map, map_flags, origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueUnmapMemObject(cl_command_queue command_queue, cl_mem memobj, void * mapped_ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueUnmapMemObject_entry, command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_UNMAP_MEM_OBJECT_PTR(command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueUnmapMemObject_exit, command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueMigrateMemObjects(cl_command_queue command_queue, cl_uint num_mem_objects, const cl_mem * mem_objects, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemObjects_entry, command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_MIGRATE_MEM_OBJECTS_PTR(command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemObjects_exit, command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueNDRangeKernel(cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, const size_t * global_work_offset, const size_t * global_work_size, const size_t * local_work_size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueNDRangeKernel_entry, command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _dump_release_events = 0;
  int _dump_release_event = 0;
  cl_event extra_event;
  if (do_dump && command_queue != NULL && kernel != NULL && _enqueue_counter >= dump_start && _enqueue_counter <= dump_end) {
    cl_command_queue_properties properties;
    CL_GET_COMMAND_QUEUE_INFO_PTR(command_queue, CL_QUEUE_PROPERTIES, sizeof(cl_command_queue_properties), &properties, NULL);
    _dump_release_events = dump_kernel_args(command_queue, kernel, _enqueue_counter, properties, &num_events_in_wait_list, (cl_event **)&event_wait_list);
    if ((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) && event == NULL) {
      event = &extra_event;
      _dump_release_event = 1;
    }
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_NDRANGE_KERNEL_PTR(command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _dump_release_events) {
    for (cl_uint event_index = 0; event_index < num_events_in_wait_list; event_index++) {
      CL_RELEASE_EVENT_PTR(event_wait_list[event_index]);
    }
    free((void *)event_wait_list);
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  if (do_dump && _enqueue_counter >= dump_start && _enqueue_counter <= dump_end) {
    if (_retval == CL_SUCCESS) {
      cl_event ev = dump_kernel_buffers(command_queue, kernel, _enqueue_counter, event);
      if (_dump_release_event) {
        CL_RELEASE_EVENT_PTR(*event);
        event = NULL;
        if (ev != NULL) {
          CL_RELEASE_EVENT_PTR(ev);
        }
      } else if ( ev != NULL ) {
        if (event != NULL) {
          if (*event != NULL)
            CL_RELEASE_EVENT_PTR(*event);
          *event = ev;
        }
      }
    } else {
      if (_dump_release_event) {
        CL_RELEASE_EVENT_PTR(*event);
        event = NULL;
      }
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueNDRangeKernel_exit, command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueNativeKernel(cl_command_queue command_queue, void (CL_CALLBACK* user_func )(void*), void * args, size_t cb_args, cl_uint num_mem_objects, const cl_mem * mem_list, const void ** args_mem_loc, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueNativeKernel_entry, command_queue, (void *)(intptr_t)user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_NATIVE_KERNEL_PTR(command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueNativeKernel_exit, command_queue, (void *)(intptr_t)user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueMarkerWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueMarkerWithWaitList_entry, command_queue, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_MARKER_WITH_WAIT_LIST_PTR(command_queue, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMarkerWithWaitList_exit, command_queue, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueBarrierWithWaitList(cl_command_queue command_queue, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueBarrierWithWaitList_entry, command_queue, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_BARRIER_WITH_WAIT_LIST_PTR(command_queue, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueBarrierWithWaitList_exit, command_queue, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMFree(cl_command_queue command_queue, cl_uint num_svm_pointers, void * svm_pointers [], void (CL_CALLBACK* pfn_free_func )(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data), void * user_data, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMFree_entry, command_queue, num_svm_pointers, svm_pointers, (void *)(intptr_t)pfn_free_func, user_data, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  struct clEnqueueSVMFree_callback_payload *_payload = NULL;
  if ((tracepoint_enabled(lttng_ust_opencl, clEnqueueSVMFree_callback_entry)) && pfn_free_func) {
    _payload = (struct clEnqueueSVMFree_callback_payload *)malloc(sizeof(struct clEnqueueSVMFree_callback_payload));
    _payload->pfn_free_func = pfn_free_func;
    _payload->user_data = user_data;
    user_data = (void *)_payload;
    pfn_free_func = &clEnqueueSVMFree_callback;
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMFREE_PTR(command_queue, num_svm_pointers, svm_pointers, pfn_free_func, user_data, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_payload && _retval != CL_SUCCESS)
    free(_payload);
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMFree_exit, command_queue, num_svm_pointers, svm_pointers, (void *)(intptr_t)pfn_free_func, user_data, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMMemcpy(cl_command_queue command_queue, cl_bool blocking_copy, void * dst_ptr, const void * src_ptr, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMMemcpy_entry, command_queue, blocking_copy, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMMEMCPY_PTR(command_queue, blocking_copy, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMMemcpy_exit, command_queue, blocking_copy, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMMemFill(cl_command_queue command_queue, void * svm_ptr, const void * pattern, size_t pattern_size, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMMemFill_entry, command_queue, svm_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMMEM_FILL_PTR(command_queue, svm_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMMemFill_exit, command_queue, svm_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMMap(cl_command_queue command_queue, cl_bool blocking_map, cl_map_flags flags, void * svm_ptr, size_t size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMMap_entry, command_queue, blocking_map, flags, svm_ptr, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMMAP_PTR(command_queue, blocking_map, flags, svm_ptr, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMMap_exit, command_queue, blocking_map, flags, svm_ptr, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMUnmap(cl_command_queue command_queue, void * svm_ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMUnmap_entry, command_queue, svm_ptr, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMUNMAP_PTR(command_queue, svm_ptr, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMUnmap_exit, command_queue, svm_ptr, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueSVMMigrateMem(cl_command_queue command_queue, cl_uint num_svm_pointers, const void ** svm_pointers, const size_t * sizes, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueSVMMigrateMem_entry, command_queue, num_svm_pointers, svm_pointers, sizes, flags, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_SVMMIGRATE_MEM_PTR(command_queue, num_svm_pointers, svm_pointers, sizes, flags, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueSVMMigrateMem_exit, command_queue, num_svm_pointers, svm_pointers, sizes, flags, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void * CL_API_CALL clGetExtensionFunctionAddressForPlatform(cl_platform_id platform, const char * func_name) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_entry, platform, func_name);
  if (strcmp(func_name, "clCreateEventFromEGLSyncKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateEventFromEGLSyncKHR);
  }
  else
  if (strcmp(func_name, "clCreateFromEGLImageKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_EGLIMAGE_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromEGLImageKHR);
  }
  else
  if (strcmp(func_name, "clEnqueueAcquireEGLObjectsKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueAcquireEGLObjectsKHR);
  }
  else
  if (strcmp(func_name, "clEnqueueReleaseEGLObjectsKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueReleaseEGLObjectsKHR);
  }
  else
  if (strcmp(func_name, "clReleaseDeviceEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_RELEASE_DEVICE_EXT_PTR, 0);
    return (void *)(intptr_t)(&clReleaseDeviceEXT);
  }
  else
  if (strcmp(func_name, "clRetainDeviceEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_RETAIN_DEVICE_EXT_PTR, 0);
    return (void *)(intptr_t)(&clRetainDeviceEXT);
  }
  else
  if (strcmp(func_name, "clCreateSubDevicesEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_SUB_DEVICES_EXT_PTR, 0);
    return (void *)(intptr_t)(&clCreateSubDevicesEXT);
  }
  else
  if (strcmp(func_name, "clGetKernelSubGroupInfoKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR, 0);
    return (void *)(intptr_t)(&clGetKernelSubGroupInfoKHR);
  }
  else
  if (strcmp(func_name, "clCreateEventFromGLsyncKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateEventFromGLsyncKHR);
  }
  else
  if (strcmp(func_name, "clGetGLContextInfoKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_GET_GLCONTEXT_INFO_KHR_PTR, 0);
    return (void *)(intptr_t)(&clGetGLContextInfoKHR);
  }
  else
  if (strcmp(func_name, "clCreateFromGLBuffer") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLBUFFER_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLBuffer);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture);
  }
  else
  if (strcmp(func_name, "clCreateFromGLRenderbuffer") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLRENDERBUFFER_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLRenderbuffer);
  }
  else
  if (strcmp(func_name, "clGetGLObjectInfo") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_GET_GLOBJECT_INFO_PTR, 0);
    return (void *)(intptr_t)(&clGetGLObjectInfo);
  }
  else
  if (strcmp(func_name, "clGetGLTextureInfo") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_GET_GLTEXTURE_INFO_PTR, 0);
    return (void *)(intptr_t)(&clGetGLTextureInfo);
  }
  else
  if (strcmp(func_name, "clEnqueueAcquireGLObjects") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueAcquireGLObjects);
  }
  else
  if (strcmp(func_name, "clEnqueueReleaseGLObjects") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_ENQUEUE_RELEASE_GLOBJECTS_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueReleaseGLObjects);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture2D") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE2_D_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture2D);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture3D") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE3_D_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture3D);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = CL_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_PTR(platform, func_name);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_retval != NULL) {
    if (tracepoint_enabled(lttng_ust_opencl, clCreateProgramWithILKHR_entry) && strcmp(func_name, "clCreateProgramWithILKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateProgramWithILKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clTerminateContextKHR_entry) && strcmp(func_name, "clTerminateContextKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 1 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 1, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clTerminateContextKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateCommandQueueWithPropertiesKHR_entry) && strcmp(func_name, "clCreateCommandQueueWithPropertiesKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateCommandQueueWithPropertiesKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMigrateMemObjectEXT_entry) && strcmp(func_name, "clEnqueueMigrateMemObjectEXT") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint64;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMigrateMemObjectEXT_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetKernelSuggestedLocalWorkSizeKHR_entry) && strcmp(func_name, "clGetKernelSuggestedLocalWorkSizeKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetKernelSuggestedLocalWorkSizeKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetICDLoaderInfoOCLICD_entry) && strcmp(func_name, "clGetICDLoaderInfoOCLICD") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_uint32;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetICDLoaderInfoOCLICD_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateImageWithPropertiesINTEL_entry) && strcmp(func_name, "clCreateImageWithPropertiesINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateImageWithPropertiesINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetImageParamsINTEL_entry) && strcmp(func_name, "clGetImageParamsINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetImageParamsINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueVerifyMemoryINTEL_entry) && strcmp(func_name, "clEnqueueVerifyMemoryINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueVerifyMemoryINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clAddCommentINTEL_entry) && strcmp(func_name, "clAddCommentINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 2 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 2, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clAddCommentINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreatePerfCountersCommandQueueINTEL_entry) && strcmp(func_name, "clCreatePerfCountersCommandQueueINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint64;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreatePerfCountersCommandQueueINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSetPerformanceConfigurationINTEL_entry) && strcmp(func_name, "clSetPerformanceConfigurationINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSetPerformanceConfigurationINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetDeviceFunctionPointerINTEL_entry) && strcmp(func_name, "clGetDeviceFunctionPointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetDeviceFunctionPointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetDeviceGlobalVariablePointerINTEL_entry) && strcmp(func_name, "clGetDeviceGlobalVariablePointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetDeviceGlobalVariablePointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetExecutionInfoINTEL_entry) && strcmp(func_name, "clGetExecutionInfoINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 9 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          closure->types[8] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 9, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetExecutionInfoINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueNDRangeKernelINTEL_entry) && strcmp(func_name, "clEnqueueNDRangeKernelINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 9 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_uint32;
          closure->types[7] = &ffi_type_pointer;
          closure->types[8] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 9, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueNDRangeKernelINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clHostMemAllocINTEL_entry) && strcmp(func_name, "clHostMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clHostMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clDeviceMemAllocINTEL_entry) && strcmp(func_name, "clDeviceMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clDeviceMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSharedMemAllocINTEL_entry) && strcmp(func_name, "clSharedMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSharedMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clMemFreeINTEL_entry) && strcmp(func_name, "clMemFreeINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 2 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 2, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clMemFreeINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetMemAllocInfoINTEL_entry) && strcmp(func_name, "clGetMemAllocInfoINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetMemAllocInfoINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSetKernelArgMemPointerINTEL_entry) && strcmp(func_name, "clSetKernelArgMemPointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 3 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 3, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSetKernelArgMemPointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemsetINTEL_entry) && strcmp(func_name, "clEnqueueMemsetINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_sint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemsetINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemFillINTEL_entry) && strcmp(func_name, "clEnqueueMemFillINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 8 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 8, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemFillINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemcpyINTEL_entry) && strcmp(func_name, "clEnqueueMemcpyINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 8 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 8, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemcpyINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMigrateMemINTEL_entry) && strcmp(func_name, "clEnqueueMigrateMemINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint64;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMigrateMemINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemAdviseINTEL_entry) && strcmp(func_name, "clEnqueueMemAdviseINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemAdviseINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateBufferWithPropertiesINTEL_entry) && strcmp(func_name, "clCreateBufferWithPropertiesINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint64;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateBufferWithPropertiesINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
  }
  tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddressForPlatform_exit, platform, func_name, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clSetCommandQueueProperty(cl_command_queue command_queue, cl_command_queue_properties properties, cl_bool enable, cl_command_queue_properties * old_properties) {
  tracepoint(lttng_ust_opencl, clSetCommandQueueProperty_entry, command_queue, properties, enable, old_properties);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_SET_COMMAND_QUEUE_PROPERTY_PTR(command_queue, properties, enable, old_properties);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetCommandQueueProperty_exit, command_queue, properties, enable, old_properties, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImage2D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_row_pitch, void * host_ptr, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateImage2D_entry, context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_IMAGE2_D_PTR(context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateImage2D_exit, context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImage3D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, void * host_ptr, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateImage3D_entry, context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = CL_CREATE_IMAGE3_D_PTR(context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateImage3D_exit, context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueMarker(cl_command_queue command_queue, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueMarker_entry, command_queue, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_MARKER_PTR(command_queue, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMarker_exit, command_queue, event, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueWaitForEvents(cl_command_queue command_queue, cl_uint num_events, const cl_event * event_list) {
  tracepoint(lttng_ust_opencl, clEnqueueWaitForEvents_entry, command_queue, num_events, event_list);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_WAIT_FOR_EVENTS_PTR(command_queue, num_events, event_list);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clEnqueueWaitForEvents_exit, command_queue, num_events, event_list, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueBarrier(cl_command_queue command_queue) {
  tracepoint(lttng_ust_opencl, clEnqueueBarrier_entry, command_queue);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_BARRIER_PTR(command_queue);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clEnqueueBarrier_exit, command_queue, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clUnloadCompiler(void ) {
  tracepoint(lttng_ust_opencl, clUnloadCompiler_entry, );
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_UNLOAD_COMPILER_PTR();
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clUnloadCompiler_exit, _retval, _duration);
  return _retval;
}

CL_API_ENTRY void * CL_API_CALL clGetExtensionFunctionAddress(const char * func_name) {
  _init_tracer();
  tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_entry, func_name);
  if (strcmp(func_name, "clCreateEventFromEGLSyncKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_EVENT_FROM_EGLSYNC_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateEventFromEGLSyncKHR);
  }
  else
  if (strcmp(func_name, "clCreateFromEGLImageKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_EGLIMAGE_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromEGLImageKHR);
  }
  else
  if (strcmp(func_name, "clEnqueueAcquireEGLObjectsKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_ENQUEUE_ACQUIRE_EGLOBJECTS_KHR_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueAcquireEGLObjectsKHR);
  }
  else
  if (strcmp(func_name, "clEnqueueReleaseEGLObjectsKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_ENQUEUE_RELEASE_EGLOBJECTS_KHR_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueReleaseEGLObjectsKHR);
  }
  else
  if (strcmp(func_name, "clReleaseDeviceEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_RELEASE_DEVICE_EXT_PTR, 0);
    return (void *)(intptr_t)(&clReleaseDeviceEXT);
  }
  else
  if (strcmp(func_name, "clRetainDeviceEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_RETAIN_DEVICE_EXT_PTR, 0);
    return (void *)(intptr_t)(&clRetainDeviceEXT);
  }
  else
  if (strcmp(func_name, "clCreateSubDevicesEXT") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_SUB_DEVICES_EXT_PTR, 0);
    return (void *)(intptr_t)(&clCreateSubDevicesEXT);
  }
  else
  if (strcmp(func_name, "clGetKernelSubGroupInfoKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_GET_KERNEL_SUB_GROUP_INFO_KHR_PTR, 0);
    return (void *)(intptr_t)(&clGetKernelSubGroupInfoKHR);
  }
  else
  if (strcmp(func_name, "clCreateEventFromGLsyncKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_EVENT_FROM_GLSYNC_KHR_PTR, 0);
    return (void *)(intptr_t)(&clCreateEventFromGLsyncKHR);
  }
  else
  if (strcmp(func_name, "clGetGLContextInfoKHR") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_GET_GLCONTEXT_INFO_KHR_PTR, 0);
    return (void *)(intptr_t)(&clGetGLContextInfoKHR);
  }
  else
  if (strcmp(func_name, "clCreateFromGLBuffer") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLBUFFER_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLBuffer);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture);
  }
  else
  if (strcmp(func_name, "clCreateFromGLRenderbuffer") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLRENDERBUFFER_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLRenderbuffer);
  }
  else
  if (strcmp(func_name, "clGetGLObjectInfo") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_GET_GLOBJECT_INFO_PTR, 0);
    return (void *)(intptr_t)(&clGetGLObjectInfo);
  }
  else
  if (strcmp(func_name, "clGetGLTextureInfo") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_GET_GLTEXTURE_INFO_PTR, 0);
    return (void *)(intptr_t)(&clGetGLTextureInfo);
  }
  else
  if (strcmp(func_name, "clEnqueueAcquireGLObjects") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_ENQUEUE_ACQUIRE_GLOBJECTS_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueAcquireGLObjects);
  }
  else
  if (strcmp(func_name, "clEnqueueReleaseGLObjects") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_ENQUEUE_RELEASE_GLOBJECTS_PTR, 0);
    return (void *)(intptr_t)(&clEnqueueReleaseGLObjects);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture2D") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE2_D_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture2D);
  }
  else
  if (strcmp(func_name, "clCreateFromGLTexture3D") == 0) {
    tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, (void *)(intptr_t)CL_CREATE_FROM_GLTEXTURE3_D_PTR, 0);
    return (void *)(intptr_t)(&clCreateFromGLTexture3D);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = CL_GET_EXTENSION_FUNCTION_ADDRESS_PTR(func_name);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_retval != NULL) {
    if (tracepoint_enabled(lttng_ust_opencl, clCreateProgramWithILKHR_entry) && strcmp(func_name, "clCreateProgramWithILKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateProgramWithILKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clTerminateContextKHR_entry) && strcmp(func_name, "clTerminateContextKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 1 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 1, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clTerminateContextKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateCommandQueueWithPropertiesKHR_entry) && strcmp(func_name, "clCreateCommandQueueWithPropertiesKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateCommandQueueWithPropertiesKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMigrateMemObjectEXT_entry) && strcmp(func_name, "clEnqueueMigrateMemObjectEXT") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint64;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMigrateMemObjectEXT_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetKernelSuggestedLocalWorkSizeKHR_entry) && strcmp(func_name, "clGetKernelSuggestedLocalWorkSizeKHR") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetKernelSuggestedLocalWorkSizeKHR_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetICDLoaderInfoOCLICD_entry) && strcmp(func_name, "clGetICDLoaderInfoOCLICD") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_uint32;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetICDLoaderInfoOCLICD_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateImageWithPropertiesINTEL_entry) && strcmp(func_name, "clCreateImageWithPropertiesINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateImageWithPropertiesINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetImageParamsINTEL_entry) && strcmp(func_name, "clGetImageParamsINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetImageParamsINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueVerifyMemoryINTEL_entry) && strcmp(func_name, "clEnqueueVerifyMemoryINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueVerifyMemoryINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clAddCommentINTEL_entry) && strcmp(func_name, "clAddCommentINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 2 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 2, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clAddCommentINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreatePerfCountersCommandQueueINTEL_entry) && strcmp(func_name, "clCreatePerfCountersCommandQueueINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint64;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreatePerfCountersCommandQueueINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSetPerformanceConfigurationINTEL_entry) && strcmp(func_name, "clSetPerformanceConfigurationINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSetPerformanceConfigurationINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetDeviceFunctionPointerINTEL_entry) && strcmp(func_name, "clGetDeviceFunctionPointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 4 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 4, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetDeviceFunctionPointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetDeviceGlobalVariablePointerINTEL_entry) && strcmp(func_name, "clGetDeviceGlobalVariablePointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetDeviceGlobalVariablePointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetExecutionInfoINTEL_entry) && strcmp(func_name, "clGetExecutionInfoINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 9 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          closure->types[8] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 9, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetExecutionInfoINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueNDRangeKernelINTEL_entry) && strcmp(func_name, "clEnqueueNDRangeKernelINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 9 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_uint32;
          closure->types[7] = &ffi_type_pointer;
          closure->types[8] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 9, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueNDRangeKernelINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clHostMemAllocINTEL_entry) && strcmp(func_name, "clHostMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 5 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 5, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clHostMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clDeviceMemAllocINTEL_entry) && strcmp(func_name, "clDeviceMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clDeviceMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSharedMemAllocINTEL_entry) && strcmp(func_name, "clSharedMemAllocINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSharedMemAllocINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clMemFreeINTEL_entry) && strcmp(func_name, "clMemFreeINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 2 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 2, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clMemFreeINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clGetMemAllocInfoINTEL_entry) && strcmp(func_name, "clGetMemAllocInfoINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clGetMemAllocInfoINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clSetKernelArgMemPointerINTEL_entry) && strcmp(func_name, "clSetKernelArgMemPointerINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 3 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 3, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clSetKernelArgMemPointerINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemsetINTEL_entry) && strcmp(func_name, "clEnqueueMemsetINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_sint32;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemsetINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemFillINTEL_entry) && strcmp(func_name, "clEnqueueMemFillINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 8 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 8, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemFillINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemcpyINTEL_entry) && strcmp(func_name, "clEnqueueMemcpyINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 8 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_uint32;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_uint32;
          closure->types[6] = &ffi_type_pointer;
          closure->types[7] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 8, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemcpyINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMigrateMemINTEL_entry) && strcmp(func_name, "clEnqueueMigrateMemINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint64;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMigrateMemINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clEnqueueMemAdviseINTEL_entry) && strcmp(func_name, "clEnqueueMemAdviseINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 7 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_pointer;
          closure->types[3] = &ffi_type_uint32;
          closure->types[4] = &ffi_type_uint32;
          closure->types[5] = &ffi_type_pointer;
          closure->types[6] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 7, &ffi_type_sint32, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clEnqueueMemAdviseINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
    else
    if (tracepoint_enabled(lttng_ust_opencl, clCreateBufferWithPropertiesINTEL_entry) && strcmp(func_name, "clCreateBufferWithPropertiesINTEL") == 0) {
      struct opencl_closure *closure = NULL;
      pthread_mutex_lock(&opencl_closures_mutex);
      HASH_FIND_PTR(opencl_closures, &_retval, closure);
      pthread_mutex_unlock(&opencl_closures_mutex);
      if (closure != NULL) {
        tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
        return closure->c_ptr;
      }
      closure = (struct opencl_closure *)malloc(sizeof(struct opencl_closure) + 6 * sizeof(ffi_type *));
      if (closure != NULL) {
        closure->types = (ffi_type **)((intptr_t)closure + sizeof(struct opencl_closure));
        closure->closure = ffi_closure_alloc(sizeof(ffi_closure), &(closure->c_ptr));
        if (closure->closure != NULL) {
          closure->ptr = _retval;
          closure->types[0] = &ffi_type_pointer;
          closure->types[1] = &ffi_type_pointer;
          closure->types[2] = &ffi_type_uint64;
          closure->types[3] = &ffi_type_pointer;
          closure->types[4] = &ffi_type_pointer;
          closure->types[5] = &ffi_type_pointer;
          if (ffi_prep_cif(&(closure->cif), FFI_DEFAULT_ABI, 6, &ffi_type_pointer, closure->types) == FFI_OK) {
            if (ffi_prep_closure_loc(closure->closure, &(closure->cif), (void (*)(ffi_cif *, void *, void **, void *))clCreateBufferWithPropertiesINTEL_ffi, _retval, closure->c_ptr) == FFI_OK) {
              pthread_mutex_lock(&opencl_closures_mutex);
              HASH_ADD_PTR(opencl_closures, ptr, closure);
              pthread_mutex_unlock(&opencl_closures_mutex);
              tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
              return closure->c_ptr;
            }
          }
          ffi_closure_free(closure->closure);
        }
        free(closure);
      }
    }
  }
  tracepoint(lttng_ust_opencl, clGetExtensionFunctionAddress_exit, func_name, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_command_queue CL_API_CALL clCreateCommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateCommandQueue_entry, context, device, properties, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    properties |= CL_QUEUE_PROFILING_ENABLE;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_command_queue _retval;
  _retval = CL_CREATE_COMMAND_QUEUE_PTR(context, device, properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateCommandQueue_exit, context, device, properties, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_sampler CL_API_CALL clCreateSampler(cl_context context, cl_bool normalized_coords, cl_addressing_mode addressing_mode, cl_filter_mode filter_mode, cl_int * errcode_ret) {
  tracepoint(lttng_ust_opencl, clCreateSampler_entry, context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_sampler _retval;
  _retval = CL_CREATE_SAMPLER_PTR(context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateSampler_exit, context, normalized_coords, addressing_mode, filter_mode, errcode_ret, _retval, _duration);
  return _retval;
}

CL_API_ENTRY cl_int CL_API_CALL clEnqueueTask(cl_command_queue command_queue, cl_kernel kernel, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) {
  tracepoint(lttng_ust_opencl, clEnqueueTask_entry, command_queue, kernel, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = CL_ENQUEUE_TASK_PTR(command_queue, kernel, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueTask_exit, command_queue, kernel, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  return _retval;
}

static void clCreateProgramWithILKHR_ffi(ffi_cif *cif, cl_program *ffi_ret, void** args, clCreateProgramWithILKHR_t clCreateProgramWithILKHR_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const void * il = *(const void * *)args[1];
  size_t length = *(size_t *)args[2];
  cl_int * errcode_ret = *(cl_int * *)args[3];
  tracepoint(lttng_ust_opencl, clCreateProgramWithILKHR_entry, context, il, length, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  if (tracepoint_enabled(lttng_ust_opencl_source, program_il) && il != NULL) {
    char path[sizeof(IL_SOURCE_TEMPLATE)];
    strncpy(path, IL_SOURCE_TEMPLATE, sizeof(path));
    create_file_and_write(path, length, il);
    do_tracepoint(lttng_ust_opencl_source, program_il, length, path);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_program _retval;
  _retval = clCreateProgramWithILKHR_ptr(context, il, length, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateProgramWithILKHR_exit, context, il, length, errcode_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clTerminateContextKHR_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clTerminateContextKHR_t clTerminateContextKHR_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  tracepoint(lttng_ust_opencl, clTerminateContextKHR_entry, context);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clTerminateContextKHR_ptr(context);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clTerminateContextKHR_exit, context, _retval, _duration);
  *ffi_ret = _retval;
}

static void clCreateCommandQueueWithPropertiesKHR_ffi(ffi_cif *cif, cl_command_queue *ffi_ret, void** args, clCreateCommandQueueWithPropertiesKHR_t clCreateCommandQueueWithPropertiesKHR_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  cl_device_id device = *(cl_device_id *)args[1];
  const cl_queue_properties_khr * properties = *(const cl_queue_properties_khr * *)args[2];
  cl_int * errcode_ret = *(cl_int * *)args[3];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateCommandQueueWithPropertiesKHR_entry, context, device, properties, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_command_queue _retval;
  _retval = clCreateCommandQueueWithPropertiesKHR_ptr(context, device, properties, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateCommandQueueWithPropertiesKHR_exit, context, device, properties, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

static void clEnqueueMigrateMemObjectEXT_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMigrateMemObjectEXT_t clEnqueueMigrateMemObjectEXT_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  cl_uint num_mem_objects = *(cl_uint *)args[1];
  const cl_mem * mem_objects = *(const cl_mem * *)args[2];
  cl_mem_migration_flags_ext flags = *(cl_mem_migration_flags_ext *)args[3];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[4];
  const cl_event * event_wait_list = *(const cl_event * *)args[5];
  cl_event * event = *(cl_event * *)args[6];
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemObjectEXT_entry, command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMigrateMemObjectEXT_ptr(command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemObjectEXT_exit, command_queue, num_mem_objects, mem_objects, flags, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetKernelSuggestedLocalWorkSizeKHR_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetKernelSuggestedLocalWorkSizeKHR_t clGetKernelSuggestedLocalWorkSizeKHR_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  cl_kernel kernel = *(cl_kernel *)args[1];
  cl_uint work_dim = *(cl_uint *)args[2];
  const size_t * global_work_offset = *(const size_t * *)args[3];
  const size_t * global_work_size = *(const size_t * *)args[4];
  size_t * suggested_local_work_size = *(size_t * *)args[5];
  tracepoint(lttng_ust_opencl, clGetKernelSuggestedLocalWorkSizeKHR_entry, command_queue, kernel, work_dim, global_work_offset, global_work_size, suggested_local_work_size);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetKernelSuggestedLocalWorkSizeKHR_ptr(command_queue, kernel, work_dim, global_work_offset, global_work_size, suggested_local_work_size);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetKernelSuggestedLocalWorkSizeKHR_exit, command_queue, kernel, work_dim, global_work_offset, global_work_size, suggested_local_work_size, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetICDLoaderInfoOCLICD_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetICDLoaderInfoOCLICD_t clGetICDLoaderInfoOCLICD_ptr) {
  (void)cif;
  cl_icdl_info param_name = *(cl_icdl_info *)args[0];
  size_t param_value_size = *(size_t *)args[1];
  void * param_value = *(void * *)args[2];
  size_t * param_value_size_ret = *(size_t * *)args[3];
  tracepoint(lttng_ust_opencl, clGetICDLoaderInfoOCLICD_entry, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetICDLoaderInfoOCLICD_ptr(param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetICDLoaderInfoOCLICD_exit, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clCreateImageWithPropertiesINTEL_ffi(ffi_cif *cif, cl_mem *ffi_ret, void** args, clCreateImageWithPropertiesINTEL_t clCreateImageWithPropertiesINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const cl_mem_properties_intel * properties = *(const cl_mem_properties_intel * *)args[1];
  const cl_image_format * image_format = *(const cl_image_format * *)args[2];
  const cl_image_desc * image_desc = *(const cl_image_desc * *)args[3];
  void * host_ptr = *(void * *)args[4];
  cl_int * errcode_ret = *(cl_int * *)args[5];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateImageWithPropertiesINTEL_entry, context, properties, image_format, image_desc, host_ptr, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = clCreateImageWithPropertiesINTEL_ptr(context, properties, image_format, image_desc, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateImageWithPropertiesINTEL_exit, context, properties, image_format, image_desc, host_ptr, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

static void clGetImageParamsINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetImageParamsINTEL_t clGetImageParamsINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const cl_image_format * image_format = *(const cl_image_format * *)args[1];
  const cl_image_desc * image_desc = *(const cl_image_desc * *)args[2];
  size_t * image_row_pitch = *(size_t * *)args[3];
  size_t * image_slice_pitch = *(size_t * *)args[4];
  tracepoint(lttng_ust_opencl, clGetImageParamsINTEL_entry, context, image_format, image_desc, image_row_pitch, image_slice_pitch);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetImageParamsINTEL_ptr(context, image_format, image_desc, image_row_pitch, image_slice_pitch);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetImageParamsINTEL_exit, context, image_format, image_desc, image_row_pitch, image_slice_pitch, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueVerifyMemoryINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueVerifyMemoryINTEL_t clEnqueueVerifyMemoryINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  const void * allocation_ptr = *(const void * *)args[1];
  const void * expected_data = *(const void * *)args[2];
  size_t size_of_comparison = *(size_t *)args[3];
  cl_uint comparison_mode = *(cl_uint *)args[4];
  tracepoint(lttng_ust_opencl, clEnqueueVerifyMemoryINTEL_entry, command_queue, allocation_ptr, expected_data, size_of_comparison, comparison_mode);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueVerifyMemoryINTEL_ptr(command_queue, allocation_ptr, expected_data, size_of_comparison, comparison_mode);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clEnqueueVerifyMemoryINTEL_exit, command_queue, allocation_ptr, expected_data, size_of_comparison, comparison_mode, _retval, _duration);
  *ffi_ret = _retval;
}

static void clAddCommentINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clAddCommentINTEL_t clAddCommentINTEL_ptr) {
  (void)cif;
  cl_device_id device = *(cl_device_id *)args[0];
  const char * comment = *(const char * *)args[1];
  tracepoint(lttng_ust_opencl, clAddCommentINTEL_entry, device, comment);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clAddCommentINTEL_ptr(device, comment);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clAddCommentINTEL_exit, device, comment, _retval, _duration);
  *ffi_ret = _retval;
}

static void clCreatePerfCountersCommandQueueINTEL_ffi(ffi_cif *cif, cl_command_queue *ffi_ret, void** args, clCreatePerfCountersCommandQueueINTEL_t clCreatePerfCountersCommandQueueINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  cl_device_id device = *(cl_device_id *)args[1];
  cl_command_queue_properties properties = *(cl_command_queue_properties *)args[2];
  cl_uint configuration = *(cl_uint *)args[3];
  cl_int * errcode_ret = *(cl_int * *)args[4];
  tracepoint(lttng_ust_opencl, clCreatePerfCountersCommandQueueINTEL_entry, context, device, properties, configuration, errcode_ret);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_command_queue _retval;
  _retval = clCreatePerfCountersCommandQueueINTEL_ptr(context, device, properties, configuration, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreatePerfCountersCommandQueueINTEL_exit, context, device, properties, configuration, errcode_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clSetPerformanceConfigurationINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clSetPerformanceConfigurationINTEL_t clSetPerformanceConfigurationINTEL_ptr) {
  (void)cif;
  cl_device_id device = *(cl_device_id *)args[0];
  cl_uint count = *(cl_uint *)args[1];
  cl_uint * offsets = *(cl_uint * *)args[2];
  cl_uint * values = *(cl_uint * *)args[3];
  tracepoint(lttng_ust_opencl, clSetPerformanceConfigurationINTEL_entry, device, count, offsets, values);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clSetPerformanceConfigurationINTEL_ptr(device, count, offsets, values);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetPerformanceConfigurationINTEL_exit, device, count, offsets, values, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetDeviceFunctionPointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetDeviceFunctionPointerINTEL_t clGetDeviceFunctionPointerINTEL_ptr) {
  (void)cif;
  cl_device_id device = *(cl_device_id *)args[0];
  cl_program program = *(cl_program *)args[1];
  const char * function_name = *(const char * *)args[2];
  cl_ulong * function_pointer_ret = *(cl_ulong * *)args[3];
  tracepoint(lttng_ust_opencl, clGetDeviceFunctionPointerINTEL_entry, device, program, function_name, function_pointer_ret);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetDeviceFunctionPointerINTEL_ptr(device, program, function_name, function_pointer_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetDeviceFunctionPointerINTEL_exit, device, program, function_name, function_pointer_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetDeviceGlobalVariablePointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetDeviceGlobalVariablePointerINTEL_t clGetDeviceGlobalVariablePointerINTEL_ptr) {
  (void)cif;
  cl_device_id device = *(cl_device_id *)args[0];
  cl_program program = *(cl_program *)args[1];
  const char * global_variable_name = *(const char * *)args[2];
  size_t * global_variable_size_ret = *(size_t * *)args[3];
  void ** global_variable_pointer_ret = *(void ** *)args[4];
  tracepoint(lttng_ust_opencl, clGetDeviceGlobalVariablePointerINTEL_entry, device, program, global_variable_name, global_variable_size_ret, global_variable_pointer_ret);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetDeviceGlobalVariablePointerINTEL_ptr(device, program, global_variable_name, global_variable_size_ret, global_variable_pointer_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clGetDeviceGlobalVariablePointerINTEL_exit, device, program, global_variable_name, global_variable_size_ret, global_variable_pointer_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetExecutionInfoINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetExecutionInfoINTEL_t clGetExecutionInfoINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  cl_kernel kernel = *(cl_kernel *)args[1];
  cl_uint work_dim = *(cl_uint *)args[2];
  const size_t * global_work_offset = *(const size_t * *)args[3];
  const size_t * local_work_size = *(const size_t * *)args[4];
  cl_execution_info_intel param_name = *(cl_execution_info_intel *)args[5];
  size_t param_value_size = *(size_t *)args[6];
  void * param_value = *(void * *)args[7];
  size_t * param_value_size_ret = *(size_t * *)args[8];
  tracepoint(lttng_ust_opencl, clGetExecutionInfoINTEL_entry, command_queue, kernel, work_dim, global_work_offset, local_work_size, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetExecutionInfoINTEL_ptr(command_queue, kernel, work_dim, global_work_offset, local_work_size, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetExecutionInfoINTEL_exit, command_queue, kernel, work_dim, global_work_offset, local_work_size, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueNDRangeKernelINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueNDRangeKernelINTEL_t clEnqueueNDRangeKernelINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  cl_kernel kernel = *(cl_kernel *)args[1];
  cl_uint work_dim = *(cl_uint *)args[2];
  const size_t * global_work_offset = *(const size_t * *)args[3];
  const size_t * work_group_count = *(const size_t * *)args[4];
  const size_t * local_work_size = *(const size_t * *)args[5];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[6];
  const cl_event * event_wait_list = *(const cl_event * *)args[7];
  cl_event * event = *(cl_event * *)args[8];
  tracepoint(lttng_ust_opencl, clEnqueueNDRangeKernelINTEL_entry, command_queue, kernel, work_dim, global_work_offset, work_group_count, local_work_size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _dump_release_events = 0;
  int _dump_release_event = 0;
  cl_event extra_event;
  if (do_dump && command_queue != NULL && kernel != NULL && _enqueue_counter >= dump_start && _enqueue_counter <= dump_end) {
    cl_command_queue_properties properties;
    CL_GET_COMMAND_QUEUE_INFO_PTR(command_queue, CL_QUEUE_PROPERTIES, sizeof(cl_command_queue_properties), &properties, NULL);
    _dump_release_events = dump_kernel_args(command_queue, kernel, _enqueue_counter, properties, &num_events_in_wait_list, (cl_event **)&event_wait_list);
    if ((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) && event == NULL) {
      event = &extra_event;
      _dump_release_event = 1;
    }
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueNDRangeKernelINTEL_ptr(command_queue, kernel, work_dim, global_work_offset, work_group_count, local_work_size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (do_dump && _dump_release_events) {
    for (cl_uint event_index = 0; event_index < num_events_in_wait_list; event_index++) {
      CL_RELEASE_EVENT_PTR(event_wait_list[event_index]);
    }
    free((void *)event_wait_list);
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  if (do_dump && _enqueue_counter >= dump_start && _enqueue_counter <= dump_end) {
    if (_retval == CL_SUCCESS) {
      cl_event ev = dump_kernel_buffers(command_queue, kernel, _enqueue_counter, event);
      if (_dump_release_event) {
        CL_RELEASE_EVENT_PTR(*event);
        event = NULL;
        if (ev != NULL) {
          CL_RELEASE_EVENT_PTR(ev);
        }
      } else if ( ev != NULL ) {
        if (event != NULL) {
          if (*event != NULL)
            CL_RELEASE_EVENT_PTR(*event);
          *event = ev;
        }
      }
    } else {
      if (_dump_release_event) {
        CL_RELEASE_EVENT_PTR(*event);
        event = NULL;
      }
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueNDRangeKernelINTEL_exit, command_queue, kernel, work_dim, global_work_offset, work_group_count, local_work_size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clHostMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clHostMemAllocINTEL_t clHostMemAllocINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const cl_mem_properties_intel * properties = *(const cl_mem_properties_intel * *)args[1];
  size_t size = *(size_t *)args[2];
  cl_uint alignment = *(cl_uint *)args[3];
  cl_int * errcode_ret = *(cl_int * *)args[4];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clHostMemAllocINTEL_entry, context, properties, size, alignment, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = clHostMemAllocINTEL_ptr(context, properties, size, alignment, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clHostMemAllocINTEL_exit, context, properties, size, alignment, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

static void clDeviceMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clDeviceMemAllocINTEL_t clDeviceMemAllocINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  cl_device_id device = *(cl_device_id *)args[1];
  const cl_mem_properties_intel * properties = *(const cl_mem_properties_intel * *)args[2];
  size_t size = *(size_t *)args[3];
  cl_uint alignment = *(cl_uint *)args[4];
  cl_int * errcode_ret = *(cl_int * *)args[5];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clDeviceMemAllocINTEL_entry, context, device, properties, size, alignment, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = clDeviceMemAllocINTEL_ptr(context, device, properties, size, alignment, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clDeviceMemAllocINTEL_exit, context, device, properties, size, alignment, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

static void clSharedMemAllocINTEL_ffi(ffi_cif *cif, void * *ffi_ret, void** args, clSharedMemAllocINTEL_t clSharedMemAllocINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  cl_device_id device = *(cl_device_id *)args[1];
  const cl_mem_properties_intel * properties = *(const cl_mem_properties_intel * *)args[2];
  size_t size = *(size_t *)args[3];
  cl_uint alignment = *(cl_uint *)args[4];
  cl_int * errcode_ret = *(cl_int * *)args[5];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clSharedMemAllocINTEL_entry, context, device, properties, size, alignment, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  void * _retval;
  _retval = clSharedMemAllocINTEL_ptr(context, device, properties, size, alignment, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSharedMemAllocINTEL_exit, context, device, properties, size, alignment, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

static void clMemFreeINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clMemFreeINTEL_t clMemFreeINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  void * ptr = *(void * *)args[1];
  tracepoint(lttng_ust_opencl, clMemFreeINTEL_entry, context, ptr);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clMemFreeINTEL_ptr(context, ptr);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clMemFreeINTEL_exit, context, ptr, _retval, _duration);
  *ffi_ret = _retval;
}

static void clGetMemAllocInfoINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clGetMemAllocInfoINTEL_t clGetMemAllocInfoINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const void * ptr = *(const void * *)args[1];
  cl_mem_info_intel param_name = *(cl_mem_info_intel *)args[2];
  size_t param_value_size = *(size_t *)args[3];
  void * param_value = *(void * *)args[4];
  size_t * param_value_size_ret = *(size_t * *)args[5];
  tracepoint(lttng_ust_opencl, clGetMemAllocInfoINTEL_entry, context, ptr, param_name, param_value_size, param_value, param_value_size_ret);
  size_t _new_param_value_size;
  if (!param_value_size_ret)
    param_value_size_ret = &_new_param_value_size;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clGetMemAllocInfoINTEL_ptr(context, ptr, param_name, param_value_size, param_value, param_value_size_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  param_value_size = (param_value_size <= *param_value_size_ret ? param_value_size : *param_value_size_ret );
  tracepoint(lttng_ust_opencl, clGetMemAllocInfoINTEL_exit, context, ptr, param_name, param_value_size, param_value, param_value_size_ret, _retval, _duration);
  *ffi_ret = _retval;
}

static void clSetKernelArgMemPointerINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clSetKernelArgMemPointerINTEL_t clSetKernelArgMemPointerINTEL_ptr) {
  (void)cif;
  cl_kernel kernel = *(cl_kernel *)args[0];
  cl_uint arg_index = *(cl_uint *)args[1];
  const void * arg_value = *(const void * *)args[2];
  tracepoint(lttng_ust_opencl, clSetKernelArgMemPointerINTEL_entry, kernel, arg_index, arg_value);
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clSetKernelArgMemPointerINTEL_ptr(kernel, arg_index, arg_value);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clSetKernelArgMemPointerINTEL_exit, kernel, arg_index, arg_value, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueMemsetINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemsetINTEL_t clEnqueueMemsetINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  void * dst_ptr = *(void * *)args[1];
  cl_int value = *(cl_int *)args[2];
  size_t size = *(size_t *)args[3];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[4];
  const cl_event * event_wait_list = *(const cl_event * *)args[5];
  cl_event * event = *(cl_event * *)args[6];
  tracepoint(lttng_ust_opencl, clEnqueueMemsetINTEL_entry, command_queue, dst_ptr, value, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMemsetINTEL_ptr(command_queue, dst_ptr, value, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMemsetINTEL_exit, command_queue, dst_ptr, value, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueMemFillINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemFillINTEL_t clEnqueueMemFillINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  void * dst_ptr = *(void * *)args[1];
  const void * pattern = *(const void * *)args[2];
  size_t pattern_size = *(size_t *)args[3];
  size_t size = *(size_t *)args[4];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[5];
  const cl_event * event_wait_list = *(const cl_event * *)args[6];
  cl_event * event = *(cl_event * *)args[7];
  tracepoint(lttng_ust_opencl, clEnqueueMemFillINTEL_entry, command_queue, dst_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMemFillINTEL_ptr(command_queue, dst_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMemFillINTEL_exit, command_queue, dst_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueMemcpyINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemcpyINTEL_t clEnqueueMemcpyINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  cl_bool blocking = *(cl_bool *)args[1];
  void * dst_ptr = *(void * *)args[2];
  const void * src_ptr = *(const void * *)args[3];
  size_t size = *(size_t *)args[4];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[5];
  const cl_event * event_wait_list = *(const cl_event * *)args[6];
  cl_event * event = *(cl_event * *)args[7];
  tracepoint(lttng_ust_opencl, clEnqueueMemcpyINTEL_entry, command_queue, blocking, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMemcpyINTEL_ptr(command_queue, blocking, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMemcpyINTEL_exit, command_queue, blocking, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueMigrateMemINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMigrateMemINTEL_t clEnqueueMigrateMemINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  const void * ptr = *(const void * *)args[1];
  size_t size = *(size_t *)args[2];
  cl_mem_migration_flags flags = *(cl_mem_migration_flags *)args[3];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[4];
  const cl_event * event_wait_list = *(const cl_event * *)args[5];
  cl_event * event = *(cl_event * *)args[6];
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemINTEL_entry, command_queue, ptr, size, flags, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMigrateMemINTEL_ptr(command_queue, ptr, size, flags, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMigrateMemINTEL_exit, command_queue, ptr, size, flags, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clEnqueueMemAdviseINTEL_ffi(ffi_cif *cif, cl_int *ffi_ret, void** args, clEnqueueMemAdviseINTEL_t clEnqueueMemAdviseINTEL_ptr) {
  (void)cif;
  cl_command_queue command_queue = *(cl_command_queue *)args[0];
  const void * ptr = *(const void * *)args[1];
  size_t size = *(size_t *)args[2];
  cl_mem_advice_intel advice = *(cl_mem_advice_intel *)args[3];
  cl_uint num_events_in_wait_list = *(cl_uint *)args[4];
  const cl_event * event_wait_list = *(const cl_event * *)args[5];
  cl_event * event = *(cl_event * *)args[6];
  tracepoint(lttng_ust_opencl, clEnqueueMemAdviseINTEL_entry, command_queue, ptr, size, advice, num_events_in_wait_list, event_wait_list, event);
  int64_t _enqueue_counter = 0;
  if (do_dump) {
    pthread_mutex_lock(&enqueue_counter_mutex);
    _enqueue_counter = enqueue_counter;
    enqueue_counter++;
    pthread_mutex_unlock(&enqueue_counter_mutex);
    tracepoint(lttng_ust_opencl_dump, enqueue_counter, _enqueue_counter);
  }
  int _profile_release_event = 0;
  int _event_profiling = 0;
  cl_event _profiling_event = NULL;
  if (tracepoint_enabled(lttng_ust_opencl_profiling, event_profiling)) {
    if (event == NULL) {
      event = &_profiling_event;
      _profile_release_event = 1;
    }
    _event_profiling = 1;
  }
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_int _retval;
  _retval = clEnqueueMemAdviseINTEL_ptr(command_queue, ptr, size, advice, num_events_in_wait_list, event_wait_list, event);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  if (_event_profiling) {
    if (_retval == CL_SUCCESS) {
      int _set_retval = CL_SET_EVENT_CALLBACK_PTR(*event, CL_COMPLETE, event_notify, NULL);
      do_tracepoint(lttng_ust_opencl_profiling, event_profiling, _set_retval, *event);
    }
    if(_profile_release_event) {
      CL_RELEASE_EVENT_PTR(*event);
      event = NULL;
    }
  }
  tracepoint(lttng_ust_opencl, clEnqueueMemAdviseINTEL_exit, command_queue, ptr, size, advice, num_events_in_wait_list, event_wait_list, event, _retval, _duration);
  *ffi_ret = _retval;
}

static void clCreateBufferWithPropertiesINTEL_ffi(ffi_cif *cif, cl_mem *ffi_ret, void** args, clCreateBufferWithPropertiesINTEL_t clCreateBufferWithPropertiesINTEL_ptr) {
  (void)cif;
  cl_context context = *(cl_context *)args[0];
  const cl_mem_properties_intel * properties = *(const cl_mem_properties_intel * *)args[1];
  cl_mem_flags flags = *(cl_mem_flags *)args[2];
  size_t size = *(size_t *)args[3];
  void * host_ptr = *(void * *)args[4];
  cl_int * errcode_ret = *(cl_int * *)args[5];
  size_t _properties_size;
  _properties_size = 0;
  if(properties != NULL) {
    while(properties[_properties_size] != 0) {
      _properties_size += 2;
    }
    _properties_size ++;
  }
  tracepoint(lttng_ust_opencl, clCreateBufferWithPropertiesINTEL_entry, context, properties, flags, size, host_ptr, errcode_ret, _properties_size);
  cl_int _errcode_ret_force;
  if (!errcode_ret)
    errcode_ret = &_errcode_ret_force;
  uint64_t _start_ts = 0;
  uint64_t _stop_ts = 0;
  uint64_t _duration = 0;
  if (do_host_profile)
    _start_ts = get_timestamp_ns();
  cl_mem _retval;
  _retval = clCreateBufferWithPropertiesINTEL_ptr(context, properties, flags, size, host_ptr, errcode_ret);
  if (do_host_profile) {
    _stop_ts = get_timestamp_ns();
    _duration = _stop_ts - _start_ts;
  }
  tracepoint(lttng_ust_opencl, clCreateBufferWithPropertiesINTEL_exit, context, properties, flags, size, host_ptr, errcode_ret, _retval, _duration, _properties_size);
  *ffi_ret = _retval;
}

