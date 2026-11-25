#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_opencl_clCreateEventFromEGLSyncKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, CLeglSyncKHR, CLeglDisplayKHR, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateEventFromEGLSyncKHR_entry(
    void *btx_handle, lttng_ust_opencl_clCreateEventFromEGLSyncKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateEventFromEGLSyncKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateEventFromEGLSyncKHR_exit(
    void *btx_handle, lttng_ust_opencl_clCreateEventFromEGLSyncKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromEGLImageKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, CLeglDisplayKHR, CLeglImageKHR, cl_mem_flags, cl_egl_image_properties_khr *, cl_int *, size_t, cl_egl_image_properties_khr *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromEGLImageKHR_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromEGLImageKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromEGLImageKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromEGLImageKHR_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromEGLImageKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseDeviceEXT_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_lttng_ust_opencl_clReleaseDeviceEXT_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseDeviceEXT_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseDeviceEXT_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseDeviceEXT_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseDeviceEXT_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainDeviceEXT_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_lttng_ust_opencl_clRetainDeviceEXT_entry(
    void *btx_handle, lttng_ust_opencl_clRetainDeviceEXT_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainDeviceEXT_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainDeviceEXT_exit(
    void *btx_handle, lttng_ust_opencl_clRetainDeviceEXT_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubDevicesEXT_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_device_partition_property_ext *, cl_uint, cl_device_id *, cl_uint *, size_t, cl_device_partition_property_ext *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubDevicesEXT_entry(
    void *btx_handle, lttng_ust_opencl_clCreateSubDevicesEXT_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubDevicesEXT_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_uint, size_t, cl_device_id *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubDevicesEXT_exit(
    void *btx_handle, lttng_ust_opencl_clCreateSubDevicesEXT_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSubGroupInfoKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_device_id, cl_kernel_sub_group_info, size_t, void *, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSubGroupInfoKHR_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelSubGroupInfoKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSubGroupInfoKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSubGroupInfoKHR_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelSubGroupInfoKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateEventFromGLsyncKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_GLsync, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateEventFromGLsyncKHR_entry(
    void *btx_handle, lttng_ust_opencl_clCreateEventFromGLsyncKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateEventFromGLsyncKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateEventFromGLsyncKHR_exit(
    void *btx_handle, lttng_ust_opencl_clCreateEventFromGLsyncKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLContextInfoKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context_properties *, cl_gl_context_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetGLContextInfoKHR_entry(
    void *btx_handle, lttng_ust_opencl_clGetGLContextInfoKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLContextInfoKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetGLContextInfoKHR_exit(
    void *btx_handle, lttng_ust_opencl_clGetGLContextInfoKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_GLuint, int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLRenderbuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_GLuint, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLRenderbuffer_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLRenderbuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLRenderbuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLRenderbuffer_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLRenderbuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLObjectInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_gl_object_type *, cl_GLuint *);

void btx_register_callbacks_lttng_ust_opencl_clGetGLObjectInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetGLObjectInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLObjectInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_gl_object_type, cl_GLuint);

void btx_register_callbacks_lttng_ust_opencl_clGetGLObjectInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetGLObjectInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLTextureInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_gl_texture_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetGLTextureInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetGLTextureInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetGLTextureInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetGLTextureInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetGLTextureInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueAcquireGLObjects_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueAcquireGLObjects_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueAcquireGLObjects_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueAcquireGLObjects_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueAcquireGLObjects_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueAcquireGLObjects_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReleaseGLObjects_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReleaseGLObjects_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueReleaseGLObjects_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReleaseGLObjects_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReleaseGLObjects_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueReleaseGLObjects_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture2D_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture2D_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture2D_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture2D_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_GLenum, cl_GLint, cl_GLuint, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture3D_entry(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture3D_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateFromGLTexture3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateFromGLTexture3D_exit(
    void *btx_handle, lttng_ust_opencl_clCreateFromGLTexture3D_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetPlatformIDs_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_uint, cl_platform_id *, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clGetPlatformIDs_entry(
    void *btx_handle, lttng_ust_opencl_clGetPlatformIDs_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetPlatformIDs_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_uint, size_t, cl_platform_id *);

void btx_register_callbacks_lttng_ust_opencl_clGetPlatformIDs_exit(
    void *btx_handle, lttng_ust_opencl_clGetPlatformIDs_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetPlatformInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_platform_id, cl_platform_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetPlatformInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetPlatformInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetPlatformInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetPlatformInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetPlatformInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceIDs_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_platform_id, cl_device_type, cl_uint, cl_device_id *, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceIDs_entry(
    void *btx_handle, lttng_ust_opencl_clGetDeviceIDs_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceIDs_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_uint, size_t, cl_device_id *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceIDs_exit(
    void *btx_handle, lttng_ust_opencl_clGetDeviceIDs_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_device_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetDeviceInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetDeviceInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubDevices_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_device_partition_property *, cl_uint, cl_device_id *, cl_uint *, size_t, cl_device_partition_property *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubDevices_entry(
    void *btx_handle, lttng_ust_opencl_clCreateSubDevices_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubDevices_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_uint, size_t, cl_device_id *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubDevices_exit(
    void *btx_handle, lttng_ust_opencl_clCreateSubDevices_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_lttng_ust_opencl_clRetainDevice_entry(
    void *btx_handle, lttng_ust_opencl_clRetainDevice_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainDevice_exit(
    void *btx_handle, lttng_ust_opencl_clRetainDevice_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseDevice_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_lttng_ust_opencl_clReleaseDevice_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseDevice_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseDevice_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseDevice_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseDevice_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetDefaultDeviceCommandQueue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clSetDefaultDeviceCommandQueue_entry(
    void *btx_handle, lttng_ust_opencl_clSetDefaultDeviceCommandQueue_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetDefaultDeviceCommandQueue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetDefaultDeviceCommandQueue_exit(
    void *btx_handle, lttng_ust_opencl_clSetDefaultDeviceCommandQueue_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceAndHostTimer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_ulong *, cl_ulong *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceAndHostTimer_entry(
    void *btx_handle, lttng_ust_opencl_clGetDeviceAndHostTimer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceAndHostTimer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_ulong, cl_ulong);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceAndHostTimer_exit(
    void *btx_handle, lttng_ust_opencl_clGetDeviceAndHostTimer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetHostTimer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_ulong *);

void btx_register_callbacks_lttng_ust_opencl_clGetHostTimer_entry(
    void *btx_handle, lttng_ust_opencl_clGetHostTimer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetHostTimer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_ulong);

void btx_register_callbacks_lttng_ust_opencl_clGetHostTimer_exit(
    void *btx_handle, lttng_ust_opencl_clGetHostTimer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContext_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context_properties *, cl_uint, cl_device_id *, void *, void *, cl_int *, size_t, cl_context_properties *, size_t, cl_device_id *);

void btx_register_callbacks_lttng_ust_opencl_clCreateContext_entry(
    void *btx_handle, lttng_ust_opencl_clCreateContext_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContext_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateContext_exit(
    void *btx_handle, lttng_ust_opencl_clCreateContext_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContextFromType_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context_properties *, cl_device_type, void *, void *, cl_int *, size_t, cl_context_properties *);

void btx_register_callbacks_lttng_ust_opencl_clCreateContextFromType_entry(
    void *btx_handle, lttng_ust_opencl_clCreateContextFromType_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContextFromType_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateContextFromType_exit(
    void *btx_handle, lttng_ust_opencl_clCreateContextFromType_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainContext_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context);

void btx_register_callbacks_lttng_ust_opencl_clRetainContext_entry(
    void *btx_handle, lttng_ust_opencl_clRetainContext_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainContext_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainContext_exit(
    void *btx_handle, lttng_ust_opencl_clRetainContext_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseContext_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context);

void btx_register_callbacks_lttng_ust_opencl_clReleaseContext_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseContext_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseContext_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseContext_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseContext_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetContextInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_context_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetContextInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetContextInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetContextInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetContextInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetContextInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetContextDestructorCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetContextDestructorCallback_entry(
    void *btx_handle, lttng_ust_opencl_clSetContextDestructorCallback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetContextDestructorCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetContextDestructorCallback_exit(
    void *btx_handle, lttng_ust_opencl_clSetContextDestructorCallback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueueWithProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_queue_properties *, cl_int *, size_t, cl_queue_properties *);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueueWithProperties_entry(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueueWithProperties_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueueWithProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueueWithProperties_exit(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueueWithProperties_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainCommandQueue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clRetainCommandQueue_entry(
    void *btx_handle, lttng_ust_opencl_clRetainCommandQueue_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainCommandQueue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainCommandQueue_exit(
    void *btx_handle, lttng_ust_opencl_clRetainCommandQueue_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseCommandQueue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clReleaseCommandQueue_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseCommandQueue_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseCommandQueue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseCommandQueue_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseCommandQueue_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetCommandQueueInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_command_queue_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetCommandQueueInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetCommandQueueInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetCommandQueueInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetCommandQueueInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetCommandQueueInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, size_t, void *, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clCreateBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clCreateBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBufferWithProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_properties *, cl_mem_flags, size_t, void *, cl_int *, size_t, cl_mem_properties *);

void btx_register_callbacks_lttng_ust_opencl_clCreateBufferWithProperties_entry(
    void *btx_handle, lttng_ust_opencl_clCreateBufferWithProperties_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBufferWithProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateBufferWithProperties_exit(
    void *btx_handle, lttng_ust_opencl_clCreateBufferWithProperties_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_mem_flags, cl_buffer_create_type, void *, cl_int *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clCreateSubBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSubBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateSubBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clCreateSubBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_image_format *, cl_image_desc *, void *, cl_int *, size_t, cl_image_format *, size_t, cl_image_desc *);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage_entry(
    void *btx_handle, lttng_ust_opencl_clCreateImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage_exit(
    void *btx_handle, lttng_ust_opencl_clCreateImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImageWithProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_properties *, cl_mem_flags, cl_image_format *, cl_image_desc *, void *, cl_int *, size_t, cl_mem_properties *, size_t, cl_image_format *, size_t, cl_image_desc *);

void btx_register_callbacks_lttng_ust_opencl_clCreateImageWithProperties_entry(
    void *btx_handle, lttng_ust_opencl_clCreateImageWithProperties_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImageWithProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateImageWithProperties_exit(
    void *btx_handle, lttng_ust_opencl_clCreateImageWithProperties_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreatePipe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_uint, cl_uint, cl_pipe_properties *, cl_int *, size_t, cl_pipe_properties *);

void btx_register_callbacks_lttng_ust_opencl_clCreatePipe_entry(
    void *btx_handle, lttng_ust_opencl_clCreatePipe_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreatePipe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreatePipe_exit(
    void *btx_handle, lttng_ust_opencl_clCreatePipe_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainMemObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem);

void btx_register_callbacks_lttng_ust_opencl_clRetainMemObject_entry(
    void *btx_handle, lttng_ust_opencl_clRetainMemObject_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainMemObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainMemObject_exit(
    void *btx_handle, lttng_ust_opencl_clRetainMemObject_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseMemObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem);

void btx_register_callbacks_lttng_ust_opencl_clReleaseMemObject_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseMemObject_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseMemObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseMemObject_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseMemObject_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetSupportedImageFormats_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_mem_object_type, cl_uint, cl_image_format *, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clGetSupportedImageFormats_entry(
    void *btx_handle, lttng_ust_opencl_clGetSupportedImageFormats_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetSupportedImageFormats_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_uint, size_t, cl_image_format *);

void btx_register_callbacks_lttng_ust_opencl_clGetSupportedImageFormats_exit(
    void *btx_handle, lttng_ust_opencl_clGetSupportedImageFormats_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetMemObjectInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_mem_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetMemObjectInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetMemObjectInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetMemObjectInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetMemObjectInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetMemObjectInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetImageInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_image_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetImageInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetImageInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetImageInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetImageInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetImageInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetPipeInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_pipe_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetPipeInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetPipeInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetPipeInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetPipeInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetPipeInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetMemObjectDestructorCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, void *, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetMemObjectDestructorCallback_entry(
    void *btx_handle, lttng_ust_opencl_clSetMemObjectDestructorCallback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetMemObjectDestructorCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetMemObjectDestructorCallback_exit(
    void *btx_handle, lttng_ust_opencl_clSetMemObjectDestructorCallback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSVMAlloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_svm_mem_flags, size_t, cl_uint);

void btx_register_callbacks_lttng_ust_opencl_clSVMAlloc_entry(
    void *btx_handle, lttng_ust_opencl_clSVMAlloc_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSVMAlloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clSVMAlloc_exit(
    void *btx_handle, lttng_ust_opencl_clSVMAlloc_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSVMFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *);

void btx_register_callbacks_lttng_ust_opencl_clSVMFree_entry(
    void *btx_handle, lttng_ust_opencl_clSVMFree_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSVMFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clSVMFree_exit(
    void *btx_handle, lttng_ust_opencl_clSVMFree_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSamplerWithProperties_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_sampler_properties *, cl_int *, size_t, cl_sampler_properties *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSamplerWithProperties_entry(
    void *btx_handle, lttng_ust_opencl_clCreateSamplerWithProperties_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSamplerWithProperties_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_sampler, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateSamplerWithProperties_exit(
    void *btx_handle, lttng_ust_opencl_clCreateSamplerWithProperties_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainSampler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_sampler);

void btx_register_callbacks_lttng_ust_opencl_clRetainSampler_entry(
    void *btx_handle, lttng_ust_opencl_clRetainSampler_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainSampler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainSampler_exit(
    void *btx_handle, lttng_ust_opencl_clRetainSampler_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseSampler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_sampler);

void btx_register_callbacks_lttng_ust_opencl_clReleaseSampler_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseSampler_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseSampler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseSampler_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseSampler_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetSamplerInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_sampler, cl_sampler_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetSamplerInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetSamplerInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetSamplerInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetSamplerInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetSamplerInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithSource_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_uint, char* *, size_t *, cl_int *, size_t, char * *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithSource_entry(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithSource_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithSource_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithSource_exit(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithSource_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithBinary_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_uint, cl_device_id *, size_t *, unsigned char* *, cl_int *, cl_int *, size_t, cl_device_id *, size_t, size_t *, size_t, unsigned char * *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithBinary_entry(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithBinary_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithBinary_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int, size_t, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithBinary_exit(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithBinary_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithBuiltInKernels_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_uint, cl_device_id *, char *, cl_int *, size_t, cl_device_id *, char *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithBuiltInKernels_entry(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithBuiltInKernels_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithBuiltInKernels_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithBuiltInKernels_exit(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithBuiltInKernels_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithIL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *, size_t, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithIL_entry(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithIL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithIL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithIL_exit(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithIL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program);

void btx_register_callbacks_lttng_ust_opencl_clRetainProgram_entry(
    void *btx_handle, lttng_ust_opencl_clRetainProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainProgram_exit(
    void *btx_handle, lttng_ust_opencl_clRetainProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program);

void btx_register_callbacks_lttng_ust_opencl_clReleaseProgram_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseProgram_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clBuildProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_uint, cl_device_id *, char *, void *, void *, size_t, cl_device_id *, char *);

void btx_register_callbacks_lttng_ust_opencl_clBuildProgram_entry(
    void *btx_handle, lttng_ust_opencl_clBuildProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clBuildProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clBuildProgram_exit(
    void *btx_handle, lttng_ust_opencl_clBuildProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCompileProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_uint, cl_device_id *, char *, cl_uint, cl_program *, char* *, void *, void *, size_t, cl_device_id *, char *, size_t, cl_program *, size_t, char * *);

void btx_register_callbacks_lttng_ust_opencl_clCompileProgram_entry(
    void *btx_handle, lttng_ust_opencl_clCompileProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCompileProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCompileProgram_exit(
    void *btx_handle, lttng_ust_opencl_clCompileProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clLinkProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_uint, cl_device_id *, char *, cl_uint, cl_program *, void *, void *, cl_int *, size_t, cl_device_id *, char *, size_t, cl_program *);

void btx_register_callbacks_lttng_ust_opencl_clLinkProgram_entry(
    void *btx_handle, lttng_ust_opencl_clLinkProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clLinkProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clLinkProgram_exit(
    void *btx_handle, lttng_ust_opencl_clLinkProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramReleaseCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, void *, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramReleaseCallback_entry(
    void *btx_handle, lttng_ust_opencl_clSetProgramReleaseCallback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramReleaseCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramReleaseCallback_exit(
    void *btx_handle, lttng_ust_opencl_clSetProgramReleaseCallback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramSpecializationConstant_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_uint, size_t, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramSpecializationConstant_entry(
    void *btx_handle, lttng_ust_opencl_clSetProgramSpecializationConstant_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramSpecializationConstant_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramSpecializationConstant_exit(
    void *btx_handle, lttng_ust_opencl_clSetProgramSpecializationConstant_exit_callback_f *callback);

typedef void lttng_ust_opencl_clUnloadPlatformCompiler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_platform_id);

void btx_register_callbacks_lttng_ust_opencl_clUnloadPlatformCompiler_entry(
    void *btx_handle, lttng_ust_opencl_clUnloadPlatformCompiler_entry_callback_f *callback);

typedef void lttng_ust_opencl_clUnloadPlatformCompiler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clUnloadPlatformCompiler_exit(
    void *btx_handle, lttng_ust_opencl_clUnloadPlatformCompiler_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetProgramInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_program_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetProgramInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetProgramInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetProgramInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetProgramInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetProgramInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetProgramBuildInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, cl_program_build_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetProgramBuildInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetProgramBuildInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetProgramBuildInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetProgramBuildInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetProgramBuildInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, char *, cl_int *, char *);

void btx_register_callbacks_lttng_ust_opencl_clCreateKernel_entry(
    void *btx_handle, lttng_ust_opencl_clCreateKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateKernel_exit(
    void *btx_handle, lttng_ust_opencl_clCreateKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateKernelsInProgram_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_uint, cl_kernel *, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clCreateKernelsInProgram_entry(
    void *btx_handle, lttng_ust_opencl_clCreateKernelsInProgram_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateKernelsInProgram_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, cl_kernel *, cl_uint);

void btx_register_callbacks_lttng_ust_opencl_clCreateKernelsInProgram_exit(
    void *btx_handle, lttng_ust_opencl_clCreateKernelsInProgram_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCloneKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCloneKernel_entry(
    void *btx_handle, lttng_ust_opencl_clCloneKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCloneKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCloneKernel_exit(
    void *btx_handle, lttng_ust_opencl_clCloneKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel);

void btx_register_callbacks_lttng_ust_opencl_clRetainKernel_entry(
    void *btx_handle, lttng_ust_opencl_clRetainKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainKernel_exit(
    void *btx_handle, lttng_ust_opencl_clRetainKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel);

void btx_register_callbacks_lttng_ust_opencl_clReleaseKernel_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseKernel_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArg_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_uint, size_t, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArg_entry(
    void *btx_handle, lttng_ust_opencl_clSetKernelArg_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArg_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArg_exit(
    void *btx_handle, lttng_ust_opencl_clSetKernelArg_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArgSVMPointer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_uint, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArgSVMPointer_entry(
    void *btx_handle, lttng_ust_opencl_clSetKernelArgSVMPointer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArgSVMPointer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArgSVMPointer_exit(
    void *btx_handle, lttng_ust_opencl_clSetKernelArgSVMPointer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelExecInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_kernel_exec_info, size_t, void *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelExecInfo_entry(
    void *btx_handle, lttng_ust_opencl_clSetKernelExecInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelExecInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelExecInfo_exit(
    void *btx_handle, lttng_ust_opencl_clSetKernelExecInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_kernel_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelArgInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_uint, cl_kernel_arg_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelArgInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelArgInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelArgInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelArgInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelArgInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelWorkGroupInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_device_id, cl_kernel_work_group_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelWorkGroupInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelWorkGroupInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelWorkGroupInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelWorkGroupInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelWorkGroupInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSubGroupInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_device_id, cl_kernel_sub_group_info, size_t, void *, size_t, void *, size_t *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSubGroupInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelSubGroupInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSubGroupInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSubGroupInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelSubGroupInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clWaitForEvents_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_uint, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clWaitForEvents_entry(
    void *btx_handle, lttng_ust_opencl_clWaitForEvents_entry_callback_f *callback);

typedef void lttng_ust_opencl_clWaitForEvents_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clWaitForEvents_exit(
    void *btx_handle, lttng_ust_opencl_clWaitForEvents_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetEventInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_event_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetEventInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetEventInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetEventInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetEventInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetEventInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateUserEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateUserEvent_entry(
    void *btx_handle, lttng_ust_opencl_clCreateUserEvent_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateUserEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateUserEvent_exit(
    void *btx_handle, lttng_ust_opencl_clCreateUserEvent_exit_callback_f *callback);

typedef void lttng_ust_opencl_clRetainEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clRetainEvent_entry(
    void *btx_handle, lttng_ust_opencl_clRetainEvent_entry_callback_f *callback);

typedef void lttng_ust_opencl_clRetainEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clRetainEvent_exit(
    void *btx_handle, lttng_ust_opencl_clRetainEvent_exit_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseEvent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clReleaseEvent_entry(
    void *btx_handle, lttng_ust_opencl_clReleaseEvent_entry_callback_f *callback);

typedef void lttng_ust_opencl_clReleaseEvent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clReleaseEvent_exit(
    void *btx_handle, lttng_ust_opencl_clReleaseEvent_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetUserEventStatus_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetUserEventStatus_entry(
    void *btx_handle, lttng_ust_opencl_clSetUserEventStatus_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetUserEventStatus_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetUserEventStatus_exit(
    void *btx_handle, lttng_ust_opencl_clSetUserEventStatus_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetEventCallback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int, void *, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetEventCallback_entry(
    void *btx_handle, lttng_ust_opencl_clSetEventCallback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetEventCallback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetEventCallback_exit(
    void *btx_handle, lttng_ust_opencl_clSetEventCallback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetEventProfilingInfo_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_profiling_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetEventProfilingInfo_entry(
    void *btx_handle, lttng_ust_opencl_clGetEventProfilingInfo_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetEventProfilingInfo_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetEventProfilingInfo_exit(
    void *btx_handle, lttng_ust_opencl_clGetEventProfilingInfo_exit_callback_f *callback);

typedef void lttng_ust_opencl_clFlush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clFlush_entry(
    void *btx_handle, lttng_ust_opencl_clFlush_entry_callback_f *callback);

typedef void lttng_ust_opencl_clFlush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clFlush_exit(
    void *btx_handle, lttng_ust_opencl_clFlush_exit_callback_f *callback);

typedef void lttng_ust_opencl_clFinish_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clFinish_entry(
    void *btx_handle, lttng_ust_opencl_clFinish_entry_callback_f *callback);

typedef void lttng_ust_opencl_clFinish_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clFinish_exit(
    void *btx_handle, lttng_ust_opencl_clFinish_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadBufferRect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t *, size_t *, size_t *, size_t, size_t, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadBufferRect_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadBufferRect_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadBufferRect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadBufferRect_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadBufferRect_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteBufferRect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t *, size_t *, size_t *, size_t, size_t, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteBufferRect_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteBufferRect_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteBufferRect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteBufferRect_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteBufferRect_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueFillBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, void *, size_t, size_t, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueFillBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueFillBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueFillBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueFillBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueFillBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_mem, size_t, size_t, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBufferRect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_mem, size_t *, size_t *, size_t *, size_t, size_t, size_t, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBufferRect_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBufferRect_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBufferRect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBufferRect_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBufferRect_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t *, size_t *, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueReadImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueReadImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueReadImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, size_t *, size_t *, size_t, size_t, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWriteImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWriteImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueWriteImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueFillImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, void *, size_t *, size_t *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueFillImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueFillImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueFillImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueFillImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueFillImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_mem, size_t *, size_t *, size_t *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyImageToBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_mem, size_t *, size_t *, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyImageToBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyImageToBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyImageToBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyImageToBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyImageToBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBufferToImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_mem, size_t, size_t *, size_t *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBufferToImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBufferToImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueCopyBufferToImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueCopyBufferToImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueCopyBufferToImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMapBuffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, cl_map_flags, size_t, size_t, cl_uint, cl_event *, cl_event *, cl_int *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMapBuffer_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMapBuffer_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMapBuffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMapBuffer_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMapBuffer_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMapImage_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, cl_bool, cl_map_flags, size_t *, size_t *, size_t *, size_t *, cl_uint, cl_event *, cl_event *, cl_int *, size_t, cl_event *, size_t *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMapImage_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMapImage_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMapImage_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, cl_int, cl_event, size_t, size_t);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMapImage_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMapImage_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueUnmapMemObject_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_mem, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueUnmapMemObject_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueUnmapMemObject_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueUnmapMemObject_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueUnmapMemObject_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueUnmapMemObject_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemObjects_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_mem_migration_flags, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemObjects_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemObjects_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemObjects_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemObjects_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemObjects_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNDRangeKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel, cl_uint, size_t *, size_t *, size_t *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, size_t *, size_t, size_t *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNDRangeKernel_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueNDRangeKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNDRangeKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNDRangeKernel_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueNDRangeKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNativeKernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, void *, size_t, cl_uint, cl_mem *, void* *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void *, size_t, cl_mem *, size_t, void * *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNativeKernel_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueNativeKernel_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNativeKernel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNativeKernel_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueNativeKernel_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMarkerWithWaitList_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMarkerWithWaitList_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMarkerWithWaitList_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMarkerWithWaitList_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMarkerWithWaitList_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMarkerWithWaitList_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueBarrierWithWaitList_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueBarrierWithWaitList_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueBarrierWithWaitList_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueBarrierWithWaitList_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueBarrierWithWaitList_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueBarrierWithWaitList_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMFree_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, void* *, void *, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void * *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMFree_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMFree_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMFree_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMFree_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMFree_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMemcpy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_bool, void *, void *, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMemcpy_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMemcpy_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMemcpy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMemcpy_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMemcpy_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMemFill_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, void *, size_t, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMemFill_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMemFill_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMemFill_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMemFill_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMemFill_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_bool, cl_map_flags, void *, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMap_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMap_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMap_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMap_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMUnmap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMUnmap_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMUnmap_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMUnmap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMUnmap_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMUnmap_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMigrateMem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, void* *, size_t *, cl_mem_migration_flags, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void * *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMigrateMem_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMigrateMem_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMMigrateMem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMMigrateMem_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMMigrateMem_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_platform_id, char *, char *);

void btx_register_callbacks_lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_entry(
    void *btx_handle, lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_exit(
    void *btx_handle, lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetCommandQueueProperty_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_command_queue_properties, cl_bool, cl_command_queue_properties *);

void btx_register_callbacks_lttng_ust_opencl_clSetCommandQueueProperty_entry(
    void *btx_handle, lttng_ust_opencl_clSetCommandQueueProperty_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetCommandQueueProperty_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_command_queue_properties);

void btx_register_callbacks_lttng_ust_opencl_clSetCommandQueueProperty_exit(
    void *btx_handle, lttng_ust_opencl_clSetCommandQueueProperty_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage2D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_image_format *, size_t, size_t, size_t, void *, cl_int *, size_t, cl_image_format *);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage2D_entry(
    void *btx_handle, lttng_ust_opencl_clCreateImage2D_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage2D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage2D_exit(
    void *btx_handle, lttng_ust_opencl_clCreateImage2D_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage3D_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_flags, cl_image_format *, size_t, size_t, size_t, size_t, size_t, void *, cl_int *, size_t, cl_image_format *);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage3D_entry(
    void *btx_handle, lttng_ust_opencl_clCreateImage3D_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImage3D_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateImage3D_exit(
    void *btx_handle, lttng_ust_opencl_clCreateImage3D_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMarker_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMarker_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMarker_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMarker_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMarker_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMarker_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWaitForEvents_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWaitForEvents_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueWaitForEvents_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueWaitForEvents_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueWaitForEvents_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueWaitForEvents_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueBarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueBarrier_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueBarrier_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueBarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueBarrier_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueBarrier_exit_callback_f *callback);

typedef void lttng_ust_opencl_clUnloadCompiler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clUnloadCompiler_entry(
    void *btx_handle, lttng_ust_opencl_clUnloadCompiler_entry_callback_f *callback);

typedef void lttng_ust_opencl_clUnloadCompiler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clUnloadCompiler_exit(
    void *btx_handle, lttng_ust_opencl_clUnloadCompiler_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetExtensionFunctionAddress_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_opencl_clGetExtensionFunctionAddress_entry(
    void *btx_handle, lttng_ust_opencl_clGetExtensionFunctionAddress_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetExtensionFunctionAddress_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetExtensionFunctionAddress_exit(
    void *btx_handle, lttng_ust_opencl_clGetExtensionFunctionAddress_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_command_queue_properties, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueue_entry(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueue_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueue_exit(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueue_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSampler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_bool, cl_addressing_mode, cl_filter_mode, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateSampler_entry(
    void *btx_handle, lttng_ust_opencl_clCreateSampler_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateSampler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_sampler, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateSampler_exit(
    void *btx_handle, lttng_ust_opencl_clCreateSampler_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueTask_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueTask_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueTask_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueTask_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueTask_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueTask_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithILKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *, size_t, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithILKHR_entry(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithILKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateProgramWithILKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateProgramWithILKHR_exit(
    void *btx_handle, lttng_ust_opencl_clCreateProgramWithILKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clTerminateContextKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context);

void btx_register_callbacks_lttng_ust_opencl_clTerminateContextKHR_entry(
    void *btx_handle, lttng_ust_opencl_clTerminateContextKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clTerminateContextKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clTerminateContextKHR_exit(
    void *btx_handle, lttng_ust_opencl_clTerminateContextKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_queue_properties_khr *, cl_int *, size_t, cl_queue_properties_khr *);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_entry(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_exit(
    void *btx_handle, lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, cl_mem *, cl_mem_migration_flags_ext, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, cl_mem *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel, cl_uint, size_t *, size_t *, size_t *, size_t, size_t *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_entry(
    void *btx_handle, lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_exit(
    void *btx_handle, lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetICDLoaderInfoOCLICD_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_icdl_info, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetICDLoaderInfoOCLICD_entry(
    void *btx_handle, lttng_ust_opencl_clGetICDLoaderInfoOCLICD_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetICDLoaderInfoOCLICD_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetICDLoaderInfoOCLICD_exit(
    void *btx_handle, lttng_ust_opencl_clGetICDLoaderInfoOCLICD_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImageWithPropertiesINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_properties_intel *, cl_image_format *, cl_image_desc *, void *, cl_int *, size_t, cl_mem_properties_intel *, size_t, cl_image_format *, size_t, cl_image_desc *);

void btx_register_callbacks_lttng_ust_opencl_clCreateImageWithPropertiesINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clCreateImageWithPropertiesINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateImageWithPropertiesINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateImageWithPropertiesINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clCreateImageWithPropertiesINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetImageParamsINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_image_format *, cl_image_desc *, size_t *, size_t *, size_t, cl_image_format *, size_t, cl_image_desc *);

void btx_register_callbacks_lttng_ust_opencl_clGetImageParamsINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clGetImageParamsINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetImageParamsINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t);

void btx_register_callbacks_lttng_ust_opencl_clGetImageParamsINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clGetImageParamsINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, void *, size_t, cl_uint);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clAddCommentINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, char *, char *);

void btx_register_callbacks_lttng_ust_opencl_clAddCommentINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clAddCommentINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clAddCommentINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clAddCommentINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clAddCommentINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_command_queue_properties, cl_uint, cl_int *);

void btx_register_callbacks_lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetPerformanceConfigurationINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_uint, cl_uint *, cl_uint *, size_t, cl_uint *, size_t, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clSetPerformanceConfigurationINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clSetPerformanceConfigurationINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetPerformanceConfigurationINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, cl_uint *, size_t, cl_uint *);

void btx_register_callbacks_lttng_ust_opencl_clSetPerformanceConfigurationINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clSetPerformanceConfigurationINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_program, char *, cl_ulong *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_ulong);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_program, char *, size_t *, void* *, char *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetExecutionInfoINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel, cl_uint, size_t *, size_t *, cl_execution_info_intel, size_t, void *, size_t *, size_t, size_t *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetExecutionInfoINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clGetExecutionInfoINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetExecutionInfoINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetExecutionInfoINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clGetExecutionInfoINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel, cl_uint, size_t *, size_t *, size_t *, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, size_t *, size_t, size_t *, size_t, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clHostMemAllocINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_properties_intel *, size_t, cl_uint, cl_int *, size_t, cl_mem_properties_intel *);

void btx_register_callbacks_lttng_ust_opencl_clHostMemAllocINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clHostMemAllocINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clHostMemAllocINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clHostMemAllocINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clHostMemAllocINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clDeviceMemAllocINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_mem_properties_intel *, size_t, cl_uint, cl_int *, size_t, cl_mem_properties_intel *);

void btx_register_callbacks_lttng_ust_opencl_clDeviceMemAllocINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clDeviceMemAllocINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clDeviceMemAllocINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clDeviceMemAllocINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clDeviceMemAllocINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSharedMemAllocINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_device_id, cl_mem_properties_intel *, size_t, cl_uint, cl_int *, size_t, cl_mem_properties_intel *);

void btx_register_callbacks_lttng_ust_opencl_clSharedMemAllocINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clSharedMemAllocINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSharedMemAllocINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSharedMemAllocINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clSharedMemAllocINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clMemFreeINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *);

void btx_register_callbacks_lttng_ust_opencl_clMemFreeINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clMemFreeINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clMemFreeINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clMemFreeINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clMemFreeINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clGetMemAllocInfoINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *, cl_mem_info_intel, size_t, void *, size_t *);

void btx_register_callbacks_lttng_ust_opencl_clGetMemAllocInfoINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clGetMemAllocInfoINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clGetMemAllocInfoINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clGetMemAllocInfoINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clGetMemAllocInfoINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArgMemPointerINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_uint, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArgMemPointerINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clSetKernelArgMemPointerINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetKernelArgMemPointerINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clSetKernelArgMemPointerINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clSetKernelArgMemPointerINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemsetINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, cl_int, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemsetINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemsetINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemsetINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemsetINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemsetINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemFillINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, void *, size_t, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemFillINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemFillINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemFillINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemFillINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemFillINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemcpyINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_bool, void *, void *, size_t, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemcpyINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemcpyINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemcpyINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemcpyINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemcpyINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, size_t, cl_mem_migration_flags, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMigrateMemINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMigrateMemINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMigrateMemINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemAdviseINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, void *, size_t, cl_mem_advice_intel, cl_uint, cl_event *, cl_event *, size_t, cl_event *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemAdviseINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemAdviseINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueMemAdviseINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueMemAdviseINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueMemAdviseINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, cl_mem_properties_intel *, cl_mem_flags, size_t, void *, cl_int *, size_t, cl_mem_properties_intel *);

void btx_register_callbacks_lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_entry(
    void *btx_handle, lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, cl_int);

void btx_register_callbacks_lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_exit(
    void *btx_handle, lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_exit_callback_f *callback);

typedef void lttng_ust_opencl_clBuildProgram_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, void *);

void btx_register_callbacks_lttng_ust_opencl_clBuildProgram_callback_entry(
    void *btx_handle, lttng_ust_opencl_clBuildProgram_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clBuildProgram_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clBuildProgram_callback_exit(
    void *btx_handle, lttng_ust_opencl_clBuildProgram_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCompileProgram_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, void *);

void btx_register_callbacks_lttng_ust_opencl_clCompileProgram_callback_entry(
    void *btx_handle, lttng_ust_opencl_clCompileProgram_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCompileProgram_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clCompileProgram_callback_exit(
    void *btx_handle, lttng_ust_opencl_clCompileProgram_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clLinkProgram_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, void *);

void btx_register_callbacks_lttng_ust_opencl_clLinkProgram_callback_entry(
    void *btx_handle, lttng_ust_opencl_clLinkProgram_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clLinkProgram_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clLinkProgram_callback_exit(
    void *btx_handle, lttng_ust_opencl_clLinkProgram_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContext_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, const char *, const void *, size_t, void *, const char *, size_t, const void *);

void btx_register_callbacks_lttng_ust_opencl_clCreateContext_callback_entry(
    void *btx_handle, lttng_ust_opencl_clCreateContext_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContext_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clCreateContext_callback_exit(
    void *btx_handle, lttng_ust_opencl_clCreateContext_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContextFromType_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, const char *, const void *, size_t, void *, const char *, size_t, const void *);

void btx_register_callbacks_lttng_ust_opencl_clCreateContextFromType_callback_entry(
    void *btx_handle, lttng_ust_opencl_clCreateContextFromType_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clCreateContextFromType_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clCreateContextFromType_callback_exit(
    void *btx_handle, lttng_ust_opencl_clCreateContextFromType_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_mem, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_entry(
    void *btx_handle, lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_exit(
    void *btx_handle, lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramReleaseCallback_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramReleaseCallback_callback_entry(
    void *btx_handle, lttng_ust_opencl_clSetProgramReleaseCallback_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetProgramReleaseCallback_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clSetProgramReleaseCallback_callback_exit(
    void *btx_handle, lttng_ust_opencl_clSetProgramReleaseCallback_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetEventCallback_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetEventCallback_callback_entry(
    void *btx_handle, lttng_ust_opencl_clSetEventCallback_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetEventCallback_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clSetEventCallback_callback_exit(
    void *btx_handle, lttng_ust_opencl_clSetEventCallback_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMFree_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_command_queue, cl_uint, void * *, void *, size_t, void * *);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMFree_callback_entry(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMFree_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clEnqueueSVMFree_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clEnqueueSVMFree_callback_exit(
    void *btx_handle, lttng_ust_opencl_clEnqueueSVMFree_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_clSetContextDestructorCallback_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_context, void *);

void btx_register_callbacks_lttng_ust_opencl_clSetContextDestructorCallback_callback_entry(
    void *btx_handle, lttng_ust_opencl_clSetContextDestructorCallback_callback_entry_callback_f *callback);

typedef void lttng_ust_opencl_clSetContextDestructorCallback_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_clSetContextDestructorCallback_callback_exit(
    void *btx_handle, lttng_ust_opencl_clSetContextDestructorCallback_callback_exit_callback_f *callback);

typedef void lttng_ust_opencl_build_objects_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_build_objects(
    void *btx_handle, lttng_ust_opencl_build_objects_callback_f *callback);

typedef void lttng_ust_opencl_build_binaries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_build_binaries(
    void *btx_handle, lttng_ust_opencl_build_binaries_callback_f *callback);

typedef void lttng_ust_opencl_build_infos_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, cl_build_status, char *, char *);

void btx_register_callbacks_lttng_ust_opencl_build_infos(
    void *btx_handle, lttng_ust_opencl_build_infos_callback_f *callback);

typedef void lttng_ust_opencl_build_infos_1_2_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, cl_program_binary_type);

void btx_register_callbacks_lttng_ust_opencl_build_infos_1_2(
    void *btx_handle, lttng_ust_opencl_build_infos_1_2_callback_f *callback);

typedef void lttng_ust_opencl_build_infos_2_0_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_program, cl_device_id, size_t);

void btx_register_callbacks_lttng_ust_opencl_build_infos_2_0(
    void *btx_handle, lttng_ust_opencl_build_infos_2_0_callback_f *callback);

typedef void lttng_ust_opencl_arguments_argument_info_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, cl_uint, cl_kernel_arg_address_qualifier, cl_kernel_arg_access_qualifier, char *, cl_kernel_arg_type_qualifier, char *);

void btx_register_callbacks_lttng_ust_opencl_arguments_argument_info(
    void *btx_handle, lttng_ust_opencl_arguments_argument_info_callback_f *callback);

typedef void lttng_ust_opencl_arguments_kernel_info_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_kernel, char *, cl_uint, cl_context, cl_program, char *);

void btx_register_callbacks_lttng_ust_opencl_arguments_kernel_info(
    void *btx_handle, lttng_ust_opencl_arguments_kernel_info_callback_f *callback);

typedef void lttng_ust_opencl_dump_enqueue_counter_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t);

void btx_register_callbacks_lttng_ust_opencl_dump_enqueue_counter(
    void *btx_handle, lttng_ust_opencl_dump_enqueue_counter_callback_f *callback);

typedef void lttng_ust_opencl_dump_kernel_arg_value_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t, cl_uint, size_t, size_t, void *);

void btx_register_callbacks_lttng_ust_opencl_dump_kernel_arg_value(
    void *btx_handle, lttng_ust_opencl_dump_kernel_arg_value_callback_f *callback);

typedef void lttng_ust_opencl_dump_svmptr_dump_event_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t, cl_uint, int, void *, int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_dump_svmptr_dump_event(
    void *btx_handle, lttng_ust_opencl_dump_svmptr_dump_event_callback_f *callback);

typedef void lttng_ust_opencl_dump_svmptr_dump_result_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t, cl_uint, int, cl_event, cl_int, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_dump_svmptr_dump_result(
    void *btx_handle, lttng_ust_opencl_dump_svmptr_dump_result_callback_f *callback);

typedef void lttng_ust_opencl_dump_buffer_dump_event_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t, cl_uint, int, cl_mem, int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_dump_buffer_dump_event(
    void *btx_handle, lttng_ust_opencl_dump_buffer_dump_event_callback_f *callback);

typedef void lttng_ust_opencl_dump_buffer_dump_result_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, uint64_t, cl_uint, int, cl_event, cl_int, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_dump_buffer_dump_result(
    void *btx_handle, lttng_ust_opencl_dump_buffer_dump_result_callback_f *callback);

typedef void lttng_ust_opencl_profiling_event_profiling_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, cl_event);

void btx_register_callbacks_lttng_ust_opencl_profiling_event_profiling(
    void *btx_handle, lttng_ust_opencl_profiling_event_profiling_callback_f *callback);

typedef void lttng_ust_opencl_profiling_event_profiling_results_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_event, cl_int, cl_int, cl_ulong, cl_int, cl_ulong, cl_int, cl_ulong, cl_int, cl_ulong);

void btx_register_callbacks_lttng_ust_opencl_profiling_event_profiling_results(
    void *btx_handle, lttng_ust_opencl_profiling_event_profiling_results_callback_f *callback);

typedef void lttng_ust_opencl_source_program_string_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_source_program_string(
    void *btx_handle, lttng_ust_opencl_source_program_string_callback_f *callback);

typedef void lttng_ust_opencl_source_program_binary_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_source_program_binary(
    void *btx_handle, lttng_ust_opencl_source_program_binary_callback_f *callback);

typedef void lttng_ust_opencl_source_program_il_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, size_t, char *);

void btx_register_callbacks_lttng_ust_opencl_source_program_il(
    void *btx_handle, lttng_ust_opencl_source_program_il_callback_f *callback);

typedef void lttng_ust_opencl_devices_device_name_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, char *);

void btx_register_callbacks_lttng_ust_opencl_devices_device_name(
    void *btx_handle, lttng_ust_opencl_devices_device_name_callback_f *callback);

typedef void lttng_ust_opencl_devices_device_timer_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, cl_device_id, cl_ulong, cl_ulong);

void btx_register_callbacks_lttng_ust_opencl_devices_device_timer(
    void *btx_handle, lttng_ust_opencl_devices_device_timer_callback_f *callback);

typedef void entries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_entries(
    void *btx_handle, entries_callback_f *callback);

typedef void exits_error_present_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_exits_error_present(
    void *btx_handle, exits_error_present_callback_f *callback);

typedef void exits_error_absent_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_exits_error_absent(
    void *btx_handle, exits_error_absent_callback_f *callback);

typedef void traffic_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, size_t);

void btx_register_callbacks_traffic_entry(
    void *btx_handle, traffic_entry_callback_f *callback);

typedef void enqueue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_int);

void btx_register_callbacks_enqueue_exit(
    void *btx_handle, enqueue_exit_callback_f *callback);

typedef void get_device_ids_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_int, cl_uint, cl_device_id *);

void btx_register_callbacks_get_device_ids_exit(
    void *btx_handle, get_device_ids_exit_callback_f *callback);

typedef void create_sub_devices_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_create_sub_devices_entry(
    void *btx_handle, create_sub_devices_entry_callback_f *callback);

typedef void create_sub_devices_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_int, cl_uint, cl_device_id *);

void btx_register_callbacks_create_sub_devices_exit(
    void *btx_handle, create_sub_devices_exit_callback_f *callback);

typedef void create_command_queue_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_device_id);

void btx_register_callbacks_create_command_queue_entry(
    void *btx_handle, create_command_queue_entry_callback_f *callback);

typedef void create_command_queue_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_command_queue, cl_int);

void btx_register_callbacks_create_command_queue_exit(
    void *btx_handle, create_command_queue_exit_callback_f *callback);

typedef void kernel_info_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_kernel, char *);

void btx_register_callbacks_kernel_info(
    void *btx_handle, kernel_info_callback_f *callback);

typedef void launch_kernel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_command_queue, cl_kernel);

void btx_register_callbacks_launch_kernel_entry(
    void *btx_handle, launch_kernel_entry_callback_f *callback);

typedef void launch_function_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, cl_command_queue);

void btx_register_callbacks_launch_function_entry(
    void *btx_handle, launch_function_entry_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
