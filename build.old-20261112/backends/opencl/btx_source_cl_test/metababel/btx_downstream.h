#pragma once
#include <babeltrace2/babeltrace.h>
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif
void btx_downstream_move_messages(
    btx_message_iterator_t *message_iterator_private_data,
    bt_message_array_const messages, uint64_t capacity, uint64_t *count);

void btx_downstream_push_message(
    btx_message_iterator_t *message_iterator_private_data,
    const bt_message *message);

bt_trace_class *
btx_downstream_trace_class_create_rec(bt_self_component *self_component);

bt_trace *btx_downstream_trace_create_rec(bt_trace_class *trace_class);

void btx_streams_get_ref(bt_trace *trace);
void btx_streams_put_ref(bt_trace *trace);

void btx_push_messages_stream_beginning(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data);
void btx_push_messages_stream_end(
    bt_self_message_iterator *self_message_iterator,
    btx_message_iterator_t *message_iterator_private_data);

void btx_push_message_lttng_ust_opencl_clCreateEventFromEGLSyncKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, CLeglSyncKHR sync, CLeglDisplayKHR display, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateEventFromEGLSyncKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateFromEGLImageKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, CLeglDisplayKHR egldisplay, CLeglImageKHR eglimage, cl_mem_flags flags, cl_egl_image_properties_khr * properties, cl_int * errcode_ret, size_t _properties_vals_length, cl_egl_image_properties_khr * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateFromEGLImageKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_objects, cl_mem * mem_objects, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueAcquireEGLObjectsKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_objects, cl_mem * mem_objects, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueReleaseEGLObjectsKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clReleaseDeviceEXT_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device);
void btx_push_message_lttng_ust_opencl_clReleaseDeviceEXT_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainDeviceEXT_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device);
void btx_push_message_lttng_ust_opencl_clRetainDeviceEXT_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateSubDevicesEXT_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id in_device, cl_device_partition_property_ext * properties, cl_uint num_entries, cl_device_id * out_devices, cl_uint * num_devices, size_t _properties_vals_length, cl_device_partition_property_ext * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateSubDevicesEXT_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_uint num_devices_val, size_t _out_devices_vals_length, cl_device_id * out_devices_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelSubGroupInfoKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel in_kernel, cl_device_id in_device, cl_kernel_sub_group_info param_name, size_t input_value_size, void * input_value, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetKernelSubGroupInfoKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateEventFromGLsyncKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_GLsync sync, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateEventFromGLsyncKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetGLContextInfoKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context_properties * properties, cl_gl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetGLContextInfoKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateFromGLBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_GLuint bufobj, int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateFromGLBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateFromGLRenderbuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_GLuint renderbuffer, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateFromGLRenderbuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetGLObjectInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj, cl_gl_object_type * gl_object_type, cl_GLuint * gl_object_name);
void btx_push_message_lttng_ust_opencl_clGetGLObjectInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_gl_object_type gl_object_type_val, cl_GLuint gl_object_name_val);
void btx_push_message_lttng_ust_opencl_clGetGLTextureInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj, cl_gl_texture_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetGLTextureInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueAcquireGLObjects_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_objects, cl_mem * mem_objects, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueAcquireGLObjects_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueReleaseGLObjects_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_objects, cl_mem * mem_objects, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueReleaseGLObjects_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel, cl_GLuint texture, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateFromGLTexture3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetPlatformIDs_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms);
void btx_push_message_lttng_ust_opencl_clGetPlatformIDs_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_uint num_platforms_val, size_t _platforms_vals_length, cl_platform_id * platforms_vals);
void btx_push_message_lttng_ust_opencl_clGetPlatformInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetPlatformInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetDeviceIDs_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices);
void btx_push_message_lttng_ust_opencl_clGetDeviceIDs_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_uint num_devices_val, size_t _devices_vals_length, cl_device_id * devices_vals);
void btx_push_message_lttng_ust_opencl_clGetDeviceInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetDeviceInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateSubDevices_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id in_device, cl_device_partition_property * properties, cl_uint num_devices, cl_device_id * out_devices, cl_uint * num_devices_ret, size_t _properties_vals_length, cl_device_partition_property * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateSubDevices_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_uint num_devices_ret_val, size_t _out_devices_vals_length, cl_device_id * out_devices_vals);
void btx_push_message_lttng_ust_opencl_clRetainDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device);
void btx_push_message_lttng_ust_opencl_clRetainDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseDevice_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device);
void btx_push_message_lttng_ust_opencl_clReleaseDevice_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetDefaultDeviceCommandQueue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clSetDefaultDeviceCommandQueue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetDeviceAndHostTimer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_ulong * device_timestamp, cl_ulong * host_timestamp);
void btx_push_message_lttng_ust_opencl_clGetDeviceAndHostTimer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_ulong device_timestamp_val, cl_ulong host_timestamp_val);
void btx_push_message_lttng_ust_opencl_clGetHostTimer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_ulong * host_timestamp);
void btx_push_message_lttng_ust_opencl_clGetHostTimer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_ulong host_timestamp_val);
void btx_push_message_lttng_ust_opencl_clCreateContext_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context_properties * properties, cl_uint num_devices, cl_device_id * devices, void * pfn_notify, void * user_data, cl_int * errcode_ret, size_t _properties_vals_length, cl_context_properties * properties_vals, size_t _devices_vals_length, cl_device_id * devices_vals);
void btx_push_message_lttng_ust_opencl_clCreateContext_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateContextFromType_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context_properties * properties, cl_device_type device_type, void * pfn_notify, void * user_data, cl_int * errcode_ret, size_t _properties_vals_length, cl_context_properties * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateContextFromType_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainContext_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context);
void btx_push_message_lttng_ust_opencl_clRetainContext_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseContext_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context);
void btx_push_message_lttng_ust_opencl_clReleaseContext_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetContextInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetContextInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clSetContextDestructorCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * pfn_notify, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetContextDestructorCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueueWithProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_queue_properties * properties, cl_int * errcode_ret, size_t _properties_vals_length, cl_queue_properties * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueueWithProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainCommandQueue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clRetainCommandQueue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseCommandQueue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clReleaseCommandQueue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetCommandQueueInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetCommandQueueInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateBufferWithProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_properties * properties, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateBufferWithProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateSubBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, void * buffer_create_info, cl_int * errcode_ret, size_t _buffer_create_info_vals_length, void * buffer_create_info_vals);
void btx_push_message_lttng_ust_opencl_clCreateSubBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_image_format * image_format, cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret, size_t _image_format_val_length, cl_image_format * image_format_val, size_t _image_desc_val_length, cl_image_desc * image_desc_val);
void btx_push_message_lttng_ust_opencl_clCreateImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateImageWithProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_properties * properties, cl_mem_flags flags, cl_image_format * image_format, cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties * properties_vals, size_t _image_format_val_length, cl_image_format * image_format_val, size_t _image_desc_val_length, cl_image_desc * image_desc_val);
void btx_push_message_lttng_ust_opencl_clCreateImageWithProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreatePipe_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_uint pipe_packet_size, cl_uint pipe_max_packets, cl_pipe_properties * properties, cl_int * errcode_ret, size_t _properties_vals_length, cl_pipe_properties * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreatePipe_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainMemObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj);
void btx_push_message_lttng_ust_opencl_clRetainMemObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseMemObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj);
void btx_push_message_lttng_ust_opencl_clReleaseMemObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetSupportedImageFormats_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats);
void btx_push_message_lttng_ust_opencl_clGetSupportedImageFormats_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_uint num_image_formats_val, size_t _image_formats_vals_length, cl_image_format * image_formats_vals);
void btx_push_message_lttng_ust_opencl_clGetMemObjectInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetMemObjectInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetImageInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetImageInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetPipeInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem pipe, cl_pipe_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetPipeInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clSetMemObjectDestructorCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj, void * pfn_notify, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetMemObjectDestructorCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSVMAlloc_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment);
void btx_push_message_lttng_ust_opencl_clSVMAlloc_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval);
void btx_push_message_lttng_ust_opencl_clSVMFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * svm_pointer);
void btx_push_message_lttng_ust_opencl_clSVMFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clCreateSamplerWithProperties_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_sampler_properties * sampler_properties, cl_int * errcode_ret, size_t _sampler_properties_vals_length, cl_sampler_properties * sampler_properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateSamplerWithProperties_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_sampler sampler, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainSampler_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_sampler sampler);
void btx_push_message_lttng_ust_opencl_clRetainSampler_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseSampler_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_sampler sampler);
void btx_push_message_lttng_ust_opencl_clReleaseSampler_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetSamplerInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetSamplerInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithSource_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_uint count, char* * strings, size_t * lengths, cl_int * errcode_ret, size_t _strings_vals_length, char * * strings_vals, size_t _lengths_vals_length, size_t * lengths_vals);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithSource_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithBinary_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_uint num_devices, cl_device_id * device_list, size_t * lengths, unsigned char* * binaries, cl_int * binary_status, cl_int * errcode_ret, size_t _device_list_vals_length, cl_device_id * device_list_vals, size_t _lengths_vals_length, size_t * lengths_vals, size_t _binaries_vals_length, unsigned char * * binaries_vals);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithBinary_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val, size_t _binary_status_vals_length, cl_int * binary_status_vals);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithBuiltInKernels_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_uint num_devices, cl_device_id * device_list, char * kernel_names, cl_int * errcode_ret, size_t _device_list_vals_length, cl_device_id * device_list_vals, char * kernel_names_val);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithBuiltInKernels_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithIL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * il, size_t length, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithIL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program);
void btx_push_message_lttng_ust_opencl_clRetainProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program);
void btx_push_message_lttng_ust_opencl_clReleaseProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clBuildProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_uint num_devices, cl_device_id * device_list, char * options, void * pfn_notify, void * user_data, size_t _device_list_vals_length, cl_device_id * device_list_vals, char * options_val);
void btx_push_message_lttng_ust_opencl_clBuildProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCompileProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_uint num_devices, cl_device_id * device_list, char * options, cl_uint num_input_headers, cl_program * input_headers, char* * header_include_names, void * pfn_notify, void * user_data, size_t _device_list_vals_length, cl_device_id * device_list_vals, char * options_val, size_t _input_headers_vals_length, cl_program * input_headers_vals, size_t _header_include_names_vals_length, char * * header_include_names_vals);
void btx_push_message_lttng_ust_opencl_clCompileProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clLinkProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_uint num_devices, cl_device_id * device_list, char * options, cl_uint num_input_programs, cl_program * input_programs, void * pfn_notify, void * user_data, cl_int * errcode_ret, size_t _device_list_vals_length, cl_device_id * device_list_vals, char * options_val, size_t _input_programs_vals_length, cl_program * input_programs_vals);
void btx_push_message_lttng_ust_opencl_clLinkProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetProgramReleaseCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, void * pfn_notify, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetProgramReleaseCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetProgramSpecializationConstant_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_uint spec_id, size_t spec_size, void * spec_value, size_t _spec_value_vals_length, void * spec_value_vals);
void btx_push_message_lttng_ust_opencl_clSetProgramSpecializationConstant_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clUnloadPlatformCompiler_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_platform_id platform);
void btx_push_message_lttng_ust_opencl_clUnloadPlatformCompiler_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetProgramInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetProgramInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetProgramBuildInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetProgramBuildInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, char * kernel_name, cl_int * errcode_ret, char * kernel_name_val);
void btx_push_message_lttng_ust_opencl_clCreateKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateKernelsInProgram_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_uint num_kernels, cl_kernel * kernels, cl_uint * num_kernels_ret);
void btx_push_message_lttng_ust_opencl_clCreateKernelsInProgram_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t _kernels_vals_length, cl_kernel * kernels_vals, cl_uint num_kernels_ret_val);
void btx_push_message_lttng_ust_opencl_clCloneKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel source_kernel, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCloneKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel);
void btx_push_message_lttng_ust_opencl_clRetainKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel);
void btx_push_message_lttng_ust_opencl_clReleaseKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetKernelArg_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_uint arg_index, size_t arg_size, void * arg_value, size_t _arg_value_vals_length, void * arg_value_vals);
void btx_push_message_lttng_ust_opencl_clSetKernelArg_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetKernelArgSVMPointer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_uint arg_index, void * arg_value);
void btx_push_message_lttng_ust_opencl_clSetKernelArgSVMPointer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetKernelExecInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, void * param_value, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clSetKernelExecInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetKernelInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetKernelInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelArgInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetKernelArgInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelWorkGroupInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetKernelWorkGroupInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelSubGroupInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_device_id device, cl_kernel_sub_group_info param_name, size_t input_value_size, void * input_value, size_t param_value_size, void * param_value, size_t * param_value_size_ret, size_t _input_value_vals_length, void * input_value_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelSubGroupInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clWaitForEvents_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_uint num_events, cl_event * event_list, size_t _event_list_vals_length, cl_event * event_list_vals);
void btx_push_message_lttng_ust_opencl_clWaitForEvents_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetEventInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_event_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetEventInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateUserEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateUserEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clRetainEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event);
void btx_push_message_lttng_ust_opencl_clRetainEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clReleaseEvent_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event);
void btx_push_message_lttng_ust_opencl_clReleaseEvent_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetUserEventStatus_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int execution_status);
void btx_push_message_lttng_ust_opencl_clSetUserEventStatus_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetEventCallback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int command_exec_callback_type, void * pfn_notify, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetEventCallback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetEventProfilingInfo_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_profiling_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetEventProfilingInfo_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clFlush_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clFlush_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clFinish_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clFinish_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueReadBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t size, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueReadBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueReadBufferRect_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t * buffer_origin, size_t * host_origin, size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * buffer_origin_vals, size_t * host_origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueReadBufferRect_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t size, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteBufferRect_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t * buffer_origin, size_t * host_origin, size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * buffer_origin_vals, size_t * host_origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteBufferRect_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueFillBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, void * pattern, size_t pattern_size, size_t offset, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _pattern_vals_length, void * pattern_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueFillBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBufferRect_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t * src_origin, size_t * dst_origin, size_t * region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * src_origin_vals, size_t * dst_origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBufferRect_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueReadImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, size_t * origin, size_t * region, size_t row_pitch, size_t slice_pitch, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueReadImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, size_t * origin, size_t * region, size_t input_row_pitch, size_t input_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueWriteImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueFillImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem image, void * fill_color, size_t * origin, size_t * region, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueFillImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, size_t * src_origin, size_t * dst_origin, size_t * region, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * src_origin_vals, size_t * dst_origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyImageToBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, size_t * src_origin, size_t * region, size_t dst_offset, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyImageToBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBufferToImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, size_t * dst_origin, size_t * region, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * dst_origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueCopyBufferToImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMapBuffer_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, cl_map_flags map_flags, size_t offset, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMapBuffer_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMapImage_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, size_t * origin, size_t * region, size_t * image_row_pitch, size_t * image_slice_pitch, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t * origin_vals, size_t * region_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMapImage_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval, cl_int errcode_ret_val, cl_event event_val, size_t image_row_pitch_val, size_t image_slice_pitch_val);
void btx_push_message_lttng_ust_opencl_clEnqueueUnmapMemObject_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_mem memobj, void * mapped_ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueUnmapMemObject_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemObjects_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_mem_objects, cl_mem * mem_objects, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemObjects_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueNDRangeKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, size_t * global_work_offset, size_t * global_work_size, size_t * local_work_size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _global_work_offset_vals_length, size_t * global_work_offset_vals, size_t _global_work_size_vals_length, size_t * global_work_size_vals, size_t _local_work_size_vals_length, size_t * local_work_size_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueNDRangeKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueNativeKernel_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * user_func, void * args, size_t cb_args, cl_uint num_mem_objects, cl_mem * mem_list, void* * args_mem_loc, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _args_vals_length, void * args_vals, size_t _mem_list_vals_length, cl_mem * mem_list_vals, size_t _args_mem_loc_vals_length, void * * args_mem_loc_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueNativeKernel_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMarkerWithWaitList_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMarkerWithWaitList_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueBarrierWithWaitList_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueBarrierWithWaitList_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMFree_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_svm_pointers, void* * svm_pointers, void * pfn_free_func, void * user_data, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _svm_pointers_vals_length, void * * svm_pointers_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMFree_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMemcpy_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_bool blocking_copy, void * dst_ptr, void * src_ptr, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMemcpy_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMemFill_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * svm_ptr, void * pattern, size_t pattern_size, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _pattern_vals_length, void * pattern_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMemFill_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_bool blocking_map, cl_map_flags flags, void * svm_ptr, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMUnmap_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * svm_ptr, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMUnmap_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMigrateMem_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_svm_pointers, void* * svm_pointers, size_t * sizes, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _svm_pointers_vals_length, void * * svm_pointers_vals, size_t _sizes_vals_length, size_t * sizes_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMMigrateMem_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_platform_id platform, char * func_name, char * func_name_val);
void btx_push_message_lttng_ust_opencl_clGetExtensionFunctionAddressForPlatform_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval);
void btx_push_message_lttng_ust_opencl_clSetCommandQueueProperty_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_command_queue_properties properties, cl_bool enable, cl_command_queue_properties * old_properties);
void btx_push_message_lttng_ust_opencl_clSetCommandQueueProperty_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_command_queue_properties old_properties_val);
void btx_push_message_lttng_ust_opencl_clCreateImage2D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_row_pitch, void * host_ptr, cl_int * errcode_ret, size_t _image_format_val_length, cl_image_format * image_format_val);
void btx_push_message_lttng_ust_opencl_clCreateImage2D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateImage3D_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_flags flags, cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, void * host_ptr, cl_int * errcode_ret, size_t _image_format_val_length, cl_image_format * image_format_val);
void btx_push_message_lttng_ust_opencl_clCreateImage3D_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMarker_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_event * event);
void btx_push_message_lttng_ust_opencl_clEnqueueMarker_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueWaitForEvents_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_events, cl_event * event_list, size_t _event_list_vals_length, cl_event * event_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueWaitForEvents_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueBarrier_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue);
void btx_push_message_lttng_ust_opencl_clEnqueueBarrier_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clUnloadCompiler_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clUnloadCompiler_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetExtensionFunctionAddress_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, char * func_name, char * func_name_val);
void btx_push_message_lttng_ust_opencl_clGetExtensionFunctionAddress_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueue_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueue_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateSampler_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_bool normalized_coords, cl_addressing_mode addressing_mode, cl_filter_mode filter_mode, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateSampler_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_sampler sampler, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueTask_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_kernel kernel, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueTask_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithILKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * il, size_t length, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreateProgramWithILKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clTerminateContextKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context);
void btx_push_message_lttng_ust_opencl_clTerminateContextKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_queue_properties_khr * properties, cl_int * errcode_ret, size_t _properties_vals_length, cl_queue_properties_khr * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateCommandQueueWithPropertiesKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_mem_objects, cl_mem * mem_objects, cl_mem_migration_flags_ext flags, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _mem_objects_vals_length, cl_mem * mem_objects_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemObjectEXT_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, size_t * global_work_offset, size_t * global_work_size, size_t * suggested_local_work_size, size_t _global_work_offset_vals_length, size_t * global_work_offset_vals, size_t _global_work_size_vals_length, size_t * global_work_size_vals);
void btx_push_message_lttng_ust_opencl_clGetKernelSuggestedLocalWorkSizeKHR_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t _suggested_local_work_size_vals_length, size_t * suggested_local_work_size_vals);
void btx_push_message_lttng_ust_opencl_clGetICDLoaderInfoOCLICD_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_icdl_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetICDLoaderInfoOCLICD_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clCreateImageWithPropertiesINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_properties_intel * properties, cl_image_format * image_format, cl_image_desc * image_desc, void * host_ptr, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties_intel * properties_vals, size_t _image_format_val_length, cl_image_format * image_format_val, size_t _image_desc_val_length, cl_image_desc * image_desc_val);
void btx_push_message_lttng_ust_opencl_clCreateImageWithPropertiesINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetImageParamsINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_image_format * image_format, cl_image_desc * image_desc, size_t * image_row_pitch, size_t * image_slice_pitch, size_t _image_format_val_length, cl_image_format * image_format_val, size_t _image_desc_val_length, cl_image_desc * image_desc_val);
void btx_push_message_lttng_ust_opencl_clGetImageParamsINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t image_row_pitch_val, size_t image_slice_pitch_val);
void btx_push_message_lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * allocation_ptr, void * expected_data, size_t size_of_comparison, cl_uint comparison_mode);
void btx_push_message_lttng_ust_opencl_clEnqueueVerifyMemoryINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clAddCommentINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, char * comment, char * comment_val);
void btx_push_message_lttng_ust_opencl_clAddCommentINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_uint configuration, cl_int * errcode_ret);
void btx_push_message_lttng_ust_opencl_clCreatePerfCountersCommandQueueINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSetPerformanceConfigurationINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_uint count, cl_uint * offsets, cl_uint * values, size_t _offsets_vals_length, cl_uint * offsets_vals, size_t _values_vals_length, cl_uint * values_vals);
void btx_push_message_lttng_ust_opencl_clSetPerformanceConfigurationINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t _offsets_vals_length, cl_uint * offsets_vals, size_t _values_vals_length, cl_uint * values_vals);
void btx_push_message_lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_program program, char * function_name, cl_ulong * function_pointer_ret);
void btx_push_message_lttng_ust_opencl_clGetDeviceFunctionPointerINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_ulong function_pointer_ret_val);
void btx_push_message_lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_program program, char * global_variable_name, size_t * global_variable_size_ret, void* * global_variable_pointer_ret, char * global_variable_name_val);
void btx_push_message_lttng_ust_opencl_clGetDeviceGlobalVariablePointerINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t global_variable_size_ret_val, void * global_variable_pointer_ret_val);
void btx_push_message_lttng_ust_opencl_clGetExecutionInfoINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, size_t * global_work_offset, size_t * local_work_size, cl_execution_info_intel param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret, size_t _global_work_offset_vals_length, size_t * global_work_offset_vals, size_t _local_work_size_vals_length, size_t * local_work_size_vals);
void btx_push_message_lttng_ust_opencl_clGetExecutionInfoINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, size_t * global_work_offset, size_t * work_group_count, size_t * local_work_size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _global_work_offset_vals_length, size_t * global_work_offset_vals, size_t _work_group_count_vals_length, size_t * work_group_count_vals, size_t _local_work_size_vals_length, size_t * local_work_size_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueNDRangeKernelINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clHostMemAllocINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_properties_intel * properties, size_t size, cl_uint alignment, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties_intel * properties_vals);
void btx_push_message_lttng_ust_opencl_clHostMemAllocINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clDeviceMemAllocINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_mem_properties_intel * properties, size_t size, cl_uint alignment, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties_intel * properties_vals);
void btx_push_message_lttng_ust_opencl_clDeviceMemAllocINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clSharedMemAllocINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_device_id device, cl_mem_properties_intel * properties, size_t size, cl_uint alignment, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties_intel * properties_vals);
void btx_push_message_lttng_ust_opencl_clSharedMemAllocINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, void * _retval, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clMemFreeINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * ptr);
void btx_push_message_lttng_ust_opencl_clMemFreeINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clGetMemAllocInfoINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * ptr, cl_mem_info_intel param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret);
void btx_push_message_lttng_ust_opencl_clGetMemAllocInfoINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, size_t param_value_size_ret_val, size_t _param_value_vals_length, void * param_value_vals);
void btx_push_message_lttng_ust_opencl_clSetKernelArgMemPointerINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_uint arg_index, void * arg_value);
void btx_push_message_lttng_ust_opencl_clSetKernelArgMemPointerINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMemsetINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * dst_ptr, cl_int value, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMemsetINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMemFillINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * dst_ptr, void * pattern, size_t pattern_size, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals, size_t _pattern_vals_length, void * pattern_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMemFillINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMemcpyINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_bool blocking, void * dst_ptr, void * src_ptr, size_t size, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMemcpyINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * ptr, size_t size, cl_mem_migration_flags flags, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMigrateMemINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clEnqueueMemAdviseINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, void * ptr, size_t size, cl_mem_advice_intel advice, cl_uint num_events_in_wait_list, cl_event * event_wait_list, cl_event * event, size_t _event_wait_list_vals_length, cl_event * event_wait_list_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueMemAdviseINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_int errcode_ret_val, cl_event event_val);
void btx_push_message_lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, cl_mem_properties_intel * properties, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret, size_t _properties_vals_length, cl_mem_properties_intel * properties_vals);
void btx_push_message_lttng_ust_opencl_clCreateBufferWithPropertiesINTEL_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem mem, cl_int errcode_ret_val);
void btx_push_message_lttng_ust_opencl_clBuildProgram_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, void * user_data);
void btx_push_message_lttng_ust_opencl_clBuildProgram_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clCompileProgram_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, void * user_data);
void btx_push_message_lttng_ust_opencl_clCompileProgram_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clLinkProgram_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, void * user_data);
void btx_push_message_lttng_ust_opencl_clLinkProgram_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clCreateContext_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, const char * errinfo, const void * private_info, size_t cb, void * user_data, const char * errinfo_val, size_t _private_info_vals_length, const void * private_info_vals);
void btx_push_message_lttng_ust_opencl_clCreateContext_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clCreateContextFromType_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, const char * errinfo, const void * private_info, size_t cb, void * user_data, const char * errinfo_val, size_t _private_info_vals_length, const void * private_info_vals);
void btx_push_message_lttng_ust_opencl_clCreateContextFromType_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_mem memobj, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetMemObjectDestructorCallback_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clSetProgramReleaseCallback_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetProgramReleaseCallback_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clSetEventCallback_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int type, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetEventCallback_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMFree_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_command_queue command_queue, cl_uint num_svm_pointers, void * * svm_pointers, void * user_data, size_t _svm_pointers_vals_length, void * * svm_pointers_vals);
void btx_push_message_lttng_ust_opencl_clEnqueueSVMFree_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_clSetContextDestructorCallback_callback_entry(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_context context, void * user_data);
void btx_push_message_lttng_ust_opencl_clSetContextDestructorCallback_callback_exit(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid);
void btx_push_message_lttng_ust_opencl_build_objects(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, size_t size, char * path);
void btx_push_message_lttng_ust_opencl_build_binaries(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, size_t size, char * path);
void btx_push_message_lttng_ust_opencl_build_infos(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, cl_build_status build_status, char * build_options, char * build_log);
void btx_push_message_lttng_ust_opencl_build_infos_1_2(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, cl_program_binary_type binary_type);
void btx_push_message_lttng_ust_opencl_build_infos_2_0(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_program program, cl_device_id device, size_t build_global_variable_total_size);
void btx_push_message_lttng_ust_opencl_arguments_argument_info(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_address_qualifier address_qualifier, cl_kernel_arg_access_qualifier access_qualifier, char * type_name, cl_kernel_arg_type_qualifier type_qualifier, char * name);
void btx_push_message_lttng_ust_opencl_arguments_kernel_info(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_kernel kernel, char * function_name, cl_uint num_args, cl_context context, cl_program program, char * attibutes);
void btx_push_message_lttng_ust_opencl_dump_enqueue_counter(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter);
void btx_push_message_lttng_ust_opencl_dump_kernel_arg_value(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter, cl_uint arg_index, size_t arg_size, size_t _arg_value_length, void * arg_value);
void btx_push_message_lttng_ust_opencl_dump_svmptr_dump_event(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter, cl_uint arg_index, int direction, void * buffer, int status, cl_event event);
void btx_push_message_lttng_ust_opencl_dump_svmptr_dump_result(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter, cl_uint arg_index, int direction, cl_event event, cl_int status, size_t size, char * path);
void btx_push_message_lttng_ust_opencl_dump_buffer_dump_event(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter, cl_uint arg_index, int direction, cl_mem buffer, int status, cl_event event);
void btx_push_message_lttng_ust_opencl_dump_buffer_dump_result(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, uint64_t enqueue_counter, cl_uint arg_index, int direction, cl_event event, cl_int status, size_t size, char * path);
void btx_push_message_lttng_ust_opencl_profiling_event_profiling(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int status, cl_event event);
void btx_push_message_lttng_ust_opencl_profiling_event_profiling_results(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_event event, cl_int event_command_exec_status, cl_int queued_status, cl_ulong queued, cl_int submit_status, cl_ulong submit, cl_int start_status, cl_ulong start, cl_int end_status, cl_ulong end);
void btx_push_message_lttng_ust_opencl_source_program_string(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int index, size_t length, char * path);
void btx_push_message_lttng_ust_opencl_source_program_binary(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, int index, size_t length, char * path);
void btx_push_message_lttng_ust_opencl_source_program_il(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, size_t length, char * path);
void btx_push_message_lttng_ust_opencl_devices_device_name(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, char * name);
void btx_push_message_lttng_ust_opencl_devices_device_timer(
    void *
        btx_handle, int64_t _timestamp, int64_t vpid, uint64_t vtid, cl_device_id device, cl_ulong device_timestamp, cl_ulong host_timestamp);


void btx_downstream_set_environment_hostname(
    void *btx_handle, const char* hostname);

#ifdef __cplusplus
}
#endif
