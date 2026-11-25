
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_opencl

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./opencl_tracepoints.h"

#if !defined(OPENCL_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define OPENCL_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#define CL_TARGET_OPENCL_VERSION 300
#include "lttng/tracepoint_gen.h"
#include <CL/opencl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl.h>
#include <CL/cl_gl_ext.h>
#include <CL/cl_egl.h>
#include "./tracer_opencl.h"

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateEventFromEGLSyncKHR_entry,
  TP_ARGS(
    cl_context, context,
    CLeglSyncKHR, sync,
    CLeglDisplayKHR, display,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, sync, (uintptr_t)sync)
    ctf_integer_hex(uintptr_t, display, (uintptr_t)display)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateEventFromEGLSyncKHR_exit,
  TP_ARGS(
    cl_context, context,
    CLeglSyncKHR, sync,
    CLeglDisplayKHR, display,
    cl_int *, errcode_ret,
    cl_event, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromEGLImageKHR_entry,
  TP_ARGS(
    cl_context, context,
    CLeglDisplayKHR, egldisplay,
    CLeglImageKHR, eglimage,
    cl_mem_flags, flags,
    const cl_egl_image_properties_khr *, properties,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, egldisplay, (uintptr_t)egldisplay)
    ctf_integer_hex(uintptr_t, eglimage, (uintptr_t)eglimage)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(intptr_t, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromEGLImageKHR_exit,
  TP_ARGS(
    cl_context, context,
    CLeglDisplayKHR, egldisplay,
    CLeglImageKHR, eglimage,
    cl_mem_flags, flags,
    const cl_egl_image_properties_khr *, properties,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueAcquireEGLObjectsKHR_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_objects, num_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueAcquireEGLObjectsKHR_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReleaseEGLObjectsKHR_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_objects, num_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReleaseEGLObjectsKHR_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseDeviceEXT_entry,
  TP_ARGS(
    cl_device_id, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseDeviceEXT_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainDeviceEXT_entry,
  TP_ARGS(
    cl_device_id, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainDeviceEXT_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubDevicesEXT_entry,
  TP_ARGS(
    cl_device_id, in_device,
    const cl_device_partition_property_ext *, properties,
    cl_uint, num_entries,
    cl_device_id *, out_devices,
    cl_uint *, num_devices,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, in_device, (uintptr_t)in_device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_uint, num_entries, num_entries)
    ctf_integer_hex(uintptr_t, out_devices, (uintptr_t)out_devices)
    ctf_integer_hex(uintptr_t, num_devices, (uintptr_t)num_devices)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubDevicesEXT_exit,
  TP_ARGS(
    cl_device_id, in_device,
    const cl_device_partition_property_ext *, properties,
    cl_uint, num_entries,
    cl_device_id *, out_devices,
    cl_uint *, num_devices,
    cl_int, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, num_devices_val, num_devices == NULL ? 0 : *num_devices)
    ctf_sequence_hex(uintptr_t, out_devices_vals, out_devices, cl_uint, out_devices == NULL ? 0 : num_entries)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSubGroupInfoKHR_entry,
  TP_ARGS(
    cl_kernel, in_kernel,
    cl_device_id, in_device,
    cl_kernel_sub_group_info, param_name,
    size_t, input_value_size,
    const void *, input_value,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, in_kernel, (uintptr_t)in_kernel)
    ctf_integer_hex(uintptr_t, in_device, (uintptr_t)in_device)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, input_value_size, input_value_size)
    ctf_integer_hex(uintptr_t, input_value, (uintptr_t)input_value)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSubGroupInfoKHR_exit,
  TP_ARGS(
    cl_kernel, in_kernel,
    cl_device_id, in_device,
    cl_kernel_sub_group_info, param_name,
    size_t, input_value_size,
    const void *, input_value,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_kernel_sub_group_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateEventFromGLsyncKHR_entry,
  TP_ARGS(
    cl_context, context,
    cl_GLsync, sync,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, sync, (uintptr_t)sync)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateEventFromGLsyncKHR_exit,
  TP_ARGS(
    cl_context, context,
    cl_GLsync, sync,
    cl_int *, errcode_ret,
    cl_event, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLContextInfoKHR_entry,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_gl_context_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLContextInfoKHR_exit,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_gl_context_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_gl_context_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLBuffer_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLuint, bufobj,
    int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(unsigned int, bufobj, bufobj)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLBuffer_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLuint, bufobj,
    int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(unsigned int, target, target)
    ctf_integer(int, miplevel, miplevel)
    ctf_integer(unsigned int, texture, texture)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLRenderbuffer_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLuint, renderbuffer,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(unsigned int, renderbuffer, renderbuffer)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLRenderbuffer_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLuint, renderbuffer,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLObjectInfo_entry,
  TP_ARGS(
    cl_mem, memobj,
    cl_gl_object_type *, gl_object_type,
    cl_GLuint *, gl_object_name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer_hex(uintptr_t, gl_object_type, (uintptr_t)gl_object_type)
    ctf_integer_hex(uintptr_t, gl_object_name, (uintptr_t)gl_object_name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLObjectInfo_exit,
  TP_ARGS(
    cl_mem, memobj,
    cl_gl_object_type *, gl_object_type,
    cl_GLuint *, gl_object_name,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, gl_object_type_val, gl_object_type == NULL ? 0 : *gl_object_type)
    ctf_integer(unsigned int, gl_object_name_val, gl_object_name == NULL ? 0 : *gl_object_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLTextureInfo_entry,
  TP_ARGS(
    cl_mem, memobj,
    cl_gl_texture_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetGLTextureInfo_exit,
  TP_ARGS(
    cl_mem, memobj,
    cl_gl_texture_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_gl_texture_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueAcquireGLObjects_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_objects, num_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueAcquireGLObjects_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReleaseGLObjects_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_objects, num_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReleaseGLObjects_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_objects,
    const cl_mem *, mem_objects,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture2D_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(unsigned int, target, target)
    ctf_integer(int, miplevel, miplevel)
    ctf_integer(unsigned int, texture, texture)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture2D_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture3D_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(unsigned int, target, target)
    ctf_integer(int, miplevel, miplevel)
    ctf_integer(unsigned int, texture, texture)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateFromGLTexture3D_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_GLenum, target,
    cl_GLint, miplevel,
    cl_GLuint, texture,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPlatformIDs_entry,
  TP_ARGS(
    cl_uint, num_entries,
    cl_platform_id *, platforms,
    cl_uint *, num_platforms
  ),
  TP_FIELDS(
    ctf_integer(cl_uint, num_entries, num_entries)
    ctf_integer_hex(uintptr_t, platforms, (uintptr_t)platforms)
    ctf_integer_hex(uintptr_t, num_platforms, (uintptr_t)num_platforms)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPlatformIDs_exit,
  TP_ARGS(
    cl_uint, num_entries,
    cl_platform_id *, platforms,
    cl_uint *, num_platforms,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, num_platforms_val, num_platforms == NULL ? 0 : *num_platforms)
    ctf_sequence_hex(uintptr_t, platforms_vals, platforms, cl_uint, platforms == NULL ? 0 : num_entries)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPlatformInfo_entry,
  TP_ARGS(
    cl_platform_id, platform,
    cl_platform_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, platform, (uintptr_t)platform)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPlatformInfo_exit,
  TP_ARGS(
    cl_platform_id, platform,
    cl_platform_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_platform_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceIDs_entry,
  TP_ARGS(
    cl_platform_id, platform,
    cl_device_type, device_type,
    cl_uint, num_entries,
    cl_device_id *, devices,
    cl_uint *, num_devices
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, platform, (uintptr_t)platform)
    ctf_integer(cl_ulong, device_type, device_type)
    ctf_integer(cl_uint, num_entries, num_entries)
    ctf_integer_hex(uintptr_t, devices, (uintptr_t)devices)
    ctf_integer_hex(uintptr_t, num_devices, (uintptr_t)num_devices)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceIDs_exit,
  TP_ARGS(
    cl_platform_id, platform,
    cl_device_type, device_type,
    cl_uint, num_entries,
    cl_device_id *, devices,
    cl_uint *, num_devices,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, num_devices_val, num_devices == NULL ? 0 : *num_devices)
    ctf_sequence_hex(uintptr_t, devices_vals, devices, cl_uint, devices == NULL ? 0 : num_entries)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceInfo_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_device_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceInfo_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_device_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_device_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubDevices_entry,
  TP_ARGS(
    cl_device_id, in_device,
    const cl_device_partition_property *, properties,
    cl_uint, num_devices,
    cl_device_id *, out_devices,
    cl_uint *, num_devices_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, in_device, (uintptr_t)in_device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, out_devices, (uintptr_t)out_devices)
    ctf_integer_hex(uintptr_t, num_devices_ret, (uintptr_t)num_devices_ret)
    ctf_sequence(intptr_t, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubDevices_exit,
  TP_ARGS(
    cl_device_id, in_device,
    const cl_device_partition_property *, properties,
    cl_uint, num_devices,
    cl_device_id *, out_devices,
    cl_uint *, num_devices_ret,
    cl_int, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, num_devices_ret_val, num_devices_ret == NULL ? 0 : *num_devices_ret)
    ctf_sequence_hex(uintptr_t, out_devices_vals, out_devices, cl_uint, out_devices == NULL ? 0 : num_devices)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainDevice_entry,
  TP_ARGS(
    cl_device_id, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainDevice_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseDevice_entry,
  TP_ARGS(
    cl_device_id, device
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseDevice_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetDefaultDeviceCommandQueue_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetDefaultDeviceCommandQueue_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceAndHostTimer_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_ulong *, device_timestamp,
    cl_ulong *, host_timestamp
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, device_timestamp, (uintptr_t)device_timestamp)
    ctf_integer_hex(uintptr_t, host_timestamp, (uintptr_t)host_timestamp)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceAndHostTimer_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_ulong *, device_timestamp,
    cl_ulong *, host_timestamp,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_ulong, device_timestamp_val, device_timestamp == NULL ? 0 : *device_timestamp)
    ctf_integer(cl_ulong, host_timestamp_val, host_timestamp == NULL ? 0 : *host_timestamp)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetHostTimer_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_ulong *, host_timestamp
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, host_timestamp, (uintptr_t)host_timestamp)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetHostTimer_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_ulong *, host_timestamp,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_ulong, host_timestamp_val, host_timestamp == NULL ? 0 : *host_timestamp)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContext_entry,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_uint, num_devices,
    const cl_device_id *, devices,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, devices, (uintptr_t)devices)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(intptr_t, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
    ctf_sequence_hex(uintptr_t, devices_vals, devices, cl_uint, devices == NULL ? 0 : num_devices)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContext_exit,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_uint, num_devices,
    const cl_device_id *, devices,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret,
    cl_context, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContextFromType_entry,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_device_type, device_type,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_ulong, device_type, device_type)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(intptr_t, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContextFromType_exit,
  TP_ARGS(
    const cl_context_properties *, properties,
    cl_device_type, device_type,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret,
    cl_context, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainContext_entry,
  TP_ARGS(
    cl_context, context
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainContext_exit,
  TP_ARGS(
    cl_context, context,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseContext_entry,
  TP_ARGS(
    cl_context, context
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseContext_exit,
  TP_ARGS(
    cl_context, context,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetContextInfo_entry,
  TP_ARGS(
    cl_context, context,
    cl_context_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetContextInfo_exit,
  TP_ARGS(
    cl_context, context,
    cl_context_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_context_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetContextDestructorCallback_entry,
  TP_ARGS(
    cl_context, context,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetContextDestructorCallback_exit,
  TP_ARGS(
    cl_context, context,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueueWithProperties_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_queue_properties *, properties,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueueWithProperties_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_queue_properties *, properties,
    cl_int *, errcode_ret,
    cl_command_queue, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainCommandQueue_entry,
  TP_ARGS(
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainCommandQueue_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseCommandQueue_entry,
  TP_ARGS(
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseCommandQueue_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetCommandQueueInfo_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_command_queue_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetCommandQueueInfo_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_command_queue_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_command_queue_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBuffer_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBuffer_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBufferWithProperties_entry,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties *, properties,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBufferWithProperties_exit,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties *, properties,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubBuffer_entry,
  TP_ARGS(
    cl_mem, buffer,
    cl_mem_flags, flags,
    cl_buffer_create_type, buffer_create_type,
    const void *, buffer_create_info,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, buffer_create_type, buffer_create_type)
    ctf_integer_hex(uintptr_t, buffer_create_info, (uintptr_t)buffer_create_info)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_text(uint8_t, buffer_create_info_vals, buffer_create_info, size_t, buffer_create_info == NULL ? 0 : (buffer_create_type == CL_BUFFER_CREATE_TYPE_REGION ? sizeof(cl_buffer_region) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSubBuffer_exit,
  TP_ARGS(
    cl_mem, buffer,
    cl_mem_flags, flags,
    cl_buffer_create_type, buffer_create_type,
    const void *, buffer_create_info,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer_hex(uintptr_t, image_desc, (uintptr_t)image_desc)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
    ctf_sequence_text(uint8_t, image_desc_val, (uint8_t *)image_desc, size_t, image_desc == NULL ? 0 : sizeof(cl_image_desc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImageWithProperties_entry,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties *, properties,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer_hex(uintptr_t, image_desc, (uintptr_t)image_desc)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
    ctf_sequence_text(uint8_t, image_desc_val, (uint8_t *)image_desc, size_t, image_desc == NULL ? 0 : sizeof(cl_image_desc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImageWithProperties_exit,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties *, properties,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreatePipe_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_uint, pipe_packet_size,
    cl_uint, pipe_max_packets,
    const cl_pipe_properties *, properties,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, pipe_packet_size, pipe_packet_size)
    ctf_integer(cl_uint, pipe_max_packets, pipe_max_packets)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(intptr_t, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreatePipe_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_uint, pipe_packet_size,
    cl_uint, pipe_max_packets,
    const cl_pipe_properties *, properties,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainMemObject_entry,
  TP_ARGS(
    cl_mem, memobj
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainMemObject_exit,
  TP_ARGS(
    cl_mem, memobj,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseMemObject_entry,
  TP_ARGS(
    cl_mem, memobj
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseMemObject_exit,
  TP_ARGS(
    cl_mem, memobj,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetSupportedImageFormats_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_mem_object_type, image_type,
    cl_uint, num_entries,
    cl_image_format *, image_formats,
    cl_uint *, num_image_formats
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, image_type, image_type)
    ctf_integer(cl_uint, num_entries, num_entries)
    ctf_integer_hex(uintptr_t, image_formats, (uintptr_t)image_formats)
    ctf_integer_hex(uintptr_t, num_image_formats, (uintptr_t)num_image_formats)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetSupportedImageFormats_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    cl_mem_object_type, image_type,
    cl_uint, num_entries,
    cl_image_format *, image_formats,
    cl_uint *, num_image_formats,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_uint, num_image_formats_val, num_image_formats == NULL ? 0 : *num_image_formats)
    ctf_sequence_text(uint8_t, image_formats_vals, image_formats, cl_uint, image_formats == NULL ? 0 : num_entries)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetMemObjectInfo_entry,
  TP_ARGS(
    cl_mem, memobj,
    cl_mem_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetMemObjectInfo_exit,
  TP_ARGS(
    cl_mem, memobj,
    cl_mem_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_mem_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetImageInfo_entry,
  TP_ARGS(
    cl_mem, image,
    cl_image_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, image, (uintptr_t)image)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetImageInfo_exit,
  TP_ARGS(
    cl_mem, image,
    cl_image_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_image_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPipeInfo_entry,
  TP_ARGS(
    cl_mem, pipe,
    cl_pipe_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pipe, (uintptr_t)pipe)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetPipeInfo_exit,
  TP_ARGS(
    cl_mem, pipe,
    cl_pipe_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_pipe_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetMemObjectDestructorCallback_entry,
  TP_ARGS(
    cl_mem, memobj,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetMemObjectDestructorCallback_exit,
  TP_ARGS(
    cl_mem, memobj,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSVMAlloc_entry,
  TP_ARGS(
    cl_context, context,
    cl_svm_mem_flags, flags,
    size_t, size,
    cl_uint, alignment
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, alignment, alignment)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSVMAlloc_exit,
  TP_ARGS(
    cl_context, context,
    cl_svm_mem_flags, flags,
    size_t, size,
    cl_uint, alignment,
    void *, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSVMFree_entry,
  TP_ARGS(
    cl_context, context,
    void *, svm_pointer
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, svm_pointer, (uintptr_t)svm_pointer)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSVMFree_exit,
  TP_ARGS(
    cl_context, context,
    void *, svm_pointer,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSamplerWithProperties_entry,
  TP_ARGS(
    cl_context, context,
    const cl_sampler_properties *, sampler_properties,
    cl_int *, errcode_ret,
    size_t, _sampler_properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, sampler_properties, (uintptr_t)sampler_properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, sampler_properties_vals, sampler_properties, size_t, sampler_properties == NULL ? 0 : _sampler_properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSamplerWithProperties_exit,
  TP_ARGS(
    cl_context, context,
    const cl_sampler_properties *, sampler_properties,
    cl_int *, errcode_ret,
    cl_sampler, _retval,
    uint64_t, _duration,
    size_t, _sampler_properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sampler, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainSampler_entry,
  TP_ARGS(
    cl_sampler, sampler
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sampler, (uintptr_t)sampler)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainSampler_exit,
  TP_ARGS(
    cl_sampler, sampler,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseSampler_entry,
  TP_ARGS(
    cl_sampler, sampler
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sampler, (uintptr_t)sampler)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseSampler_exit,
  TP_ARGS(
    cl_sampler, sampler,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetSamplerInfo_entry,
  TP_ARGS(
    cl_sampler, sampler,
    cl_sampler_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sampler, (uintptr_t)sampler)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetSamplerInfo_exit,
  TP_ARGS(
    cl_sampler, sampler,
    cl_sampler_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_sampler_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithSource_entry,
  TP_ARGS(
    cl_context, context,
    cl_uint, count,
    const char **, strings,
    const size_t *, lengths,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, count, count)
    ctf_integer_hex(uintptr_t, strings, (uintptr_t)strings)
    ctf_integer_hex(uintptr_t, lengths, (uintptr_t)lengths)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, strings_vals, strings, cl_uint, strings == NULL ? 0 : count)
    ctf_sequence(size_t, lengths_vals, lengths, cl_uint, lengths == NULL ? 0 : count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithSource_exit,
  TP_ARGS(
    cl_context, context,
    cl_uint, count,
    const char **, strings,
    const size_t *, lengths,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithBinary_entry,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const size_t *, lengths,
    const unsigned char **, binaries,
    cl_int *, binary_status,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, device_list, (uintptr_t)device_list)
    ctf_integer_hex(uintptr_t, lengths, (uintptr_t)lengths)
    ctf_integer_hex(uintptr_t, binaries, (uintptr_t)binaries)
    ctf_integer_hex(uintptr_t, binary_status, (uintptr_t)binary_status)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, device_list_vals, device_list, cl_uint, device_list == NULL ? 0 : num_devices)
    ctf_sequence(size_t, lengths_vals, lengths, cl_uint, lengths == NULL ? 0 : num_devices)
    ctf_sequence_hex(uintptr_t, binaries_vals, binaries, cl_uint, binaries == NULL ? 0 : num_devices)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithBinary_exit,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const size_t *, lengths,
    const unsigned char **, binaries,
    cl_int *, binary_status,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_sequence(cl_int, binary_status_vals, binary_status, cl_uint, binary_status == NULL ? 0 : num_devices)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithBuiltInKernels_entry,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, kernel_names,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, device_list, (uintptr_t)device_list)
    ctf_integer_hex(uintptr_t, kernel_names, (uintptr_t)kernel_names)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, device_list_vals, device_list, cl_uint, device_list == NULL ? 0 : num_devices)
    ctf_string(kernel_names_val, kernel_names)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithBuiltInKernels_exit,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, kernel_names,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithIL_entry,
  TP_ARGS(
    cl_context, context,
    const void *, il,
    size_t, length,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, il, (uintptr_t)il)
    ctf_integer(size_t, length, length)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithIL_exit,
  TP_ARGS(
    cl_context, context,
    const void *, il,
    size_t, length,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainProgram_entry,
  TP_ARGS(
    cl_program, program
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainProgram_exit,
  TP_ARGS(
    cl_program, program,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseProgram_entry,
  TP_ARGS(
    cl_program, program
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseProgram_exit,
  TP_ARGS(
    cl_program, program,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clBuildProgram_entry,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, device_list, (uintptr_t)device_list)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)options)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_sequence_hex(uintptr_t, device_list_vals, device_list, cl_uint, device_list == NULL ? 0 : num_devices)
    ctf_string(options_val, options)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clBuildProgram_exit,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCompileProgram_entry,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    cl_uint, num_input_headers,
    const cl_program *, input_headers,
    const char **, header_include_names,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, device_list, (uintptr_t)device_list)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)options)
    ctf_integer(cl_uint, num_input_headers, num_input_headers)
    ctf_integer_hex(uintptr_t, input_headers, (uintptr_t)input_headers)
    ctf_integer_hex(uintptr_t, header_include_names, (uintptr_t)header_include_names)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_sequence_hex(uintptr_t, device_list_vals, device_list, cl_uint, device_list == NULL ? 0 : num_devices)
    ctf_string(options_val, options)
    ctf_sequence_hex(uintptr_t, input_headers_vals, input_headers, cl_uint, input_headers == NULL ? 0 : num_input_headers)
    ctf_sequence_hex(uintptr_t, header_include_names_vals, header_include_names, cl_uint, header_include_names == NULL ? 0 : num_input_headers)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCompileProgram_exit,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    cl_uint, num_input_headers,
    const cl_program *, input_headers,
    const char **, header_include_names,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clLinkProgram_entry,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    cl_uint, num_input_programs,
    const cl_program *, input_programs,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, num_devices, num_devices)
    ctf_integer_hex(uintptr_t, device_list, (uintptr_t)device_list)
    ctf_integer_hex(uintptr_t, options, (uintptr_t)options)
    ctf_integer(cl_uint, num_input_programs, num_input_programs)
    ctf_integer_hex(uintptr_t, input_programs, (uintptr_t)input_programs)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, device_list_vals, device_list, cl_uint, device_list == NULL ? 0 : num_devices)
    ctf_string(options_val, options)
    ctf_sequence_hex(uintptr_t, input_programs_vals, input_programs, cl_uint, input_programs == NULL ? 0 : num_input_programs)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clLinkProgram_exit,
  TP_ARGS(
    cl_context, context,
    cl_uint, num_devices,
    const cl_device_id *, device_list,
    const char *, options,
    cl_uint, num_input_programs,
    const cl_program *, input_programs,
    void *, pfn_notify,
    void *, user_data,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramReleaseCallback_entry,
  TP_ARGS(
    cl_program, program,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramReleaseCallback_exit,
  TP_ARGS(
    cl_program, program,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramSpecializationConstant_entry,
  TP_ARGS(
    cl_program, program,
    cl_uint, spec_id,
    size_t, spec_size,
    const void *, spec_value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer(cl_uint, spec_id, spec_id)
    ctf_integer(size_t, spec_size, spec_size)
    ctf_integer_hex(uintptr_t, spec_value, (uintptr_t)spec_value)
    ctf_sequence_text(uint8_t, spec_value_vals, spec_value, size_t, spec_value == NULL ? 0 : spec_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramSpecializationConstant_exit,
  TP_ARGS(
    cl_program, program,
    cl_uint, spec_id,
    size_t, spec_size,
    const void *, spec_value,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clUnloadPlatformCompiler_entry,
  TP_ARGS(
    cl_platform_id, platform
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, platform, (uintptr_t)platform)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clUnloadPlatformCompiler_exit,
  TP_ARGS(
    cl_platform_id, platform,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetProgramInfo_entry,
  TP_ARGS(
    cl_program, program,
    cl_program_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetProgramInfo_exit,
  TP_ARGS(
    cl_program, program,
    cl_program_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_program_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetProgramBuildInfo_entry,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    cl_program_build_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetProgramBuildInfo_exit,
  TP_ARGS(
    cl_program, program,
    cl_device_id, device,
    cl_program_build_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_program_build_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateKernel_entry,
  TP_ARGS(
    cl_program, program,
    const char *, kernel_name,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, kernel_name, (uintptr_t)kernel_name)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_string(kernel_name_val, kernel_name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateKernel_exit,
  TP_ARGS(
    cl_program, program,
    const char *, kernel_name,
    cl_int *, errcode_ret,
    cl_kernel, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateKernelsInProgram_entry,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_kernels,
    cl_kernel *, kernels,
    cl_uint *, num_kernels_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer(cl_uint, num_kernels, num_kernels)
    ctf_integer_hex(uintptr_t, kernels, (uintptr_t)kernels)
    ctf_integer_hex(uintptr_t, num_kernels_ret, (uintptr_t)num_kernels_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateKernelsInProgram_exit,
  TP_ARGS(
    cl_program, program,
    cl_uint, num_kernels,
    cl_kernel *, kernels,
    cl_uint *, num_kernels_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_sequence_hex(uintptr_t, kernels_vals, kernels, cl_uint, kernels == NULL ? 0 : num_kernels)
    ctf_integer(cl_uint, num_kernels_ret_val, num_kernels_ret == NULL ? 0 : *num_kernels_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCloneKernel_entry,
  TP_ARGS(
    cl_kernel, source_kernel,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, source_kernel, (uintptr_t)source_kernel)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCloneKernel_exit,
  TP_ARGS(
    cl_kernel, source_kernel,
    cl_int *, errcode_ret,
    cl_kernel, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainKernel_entry,
  TP_ARGS(
    cl_kernel, kernel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainKernel_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseKernel_entry,
  TP_ARGS(
    cl_kernel, kernel
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseKernel_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArg_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    size_t, arg_size,
    const void *, arg_value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_integer(size_t, arg_size, arg_size)
    ctf_integer_hex(uintptr_t, arg_value, (uintptr_t)arg_value)
    ctf_sequence_text(uint8_t, arg_value_vals, arg_value, size_t, arg_value == NULL ? 0 : arg_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArg_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    size_t, arg_size,
    const void *, arg_value,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArgSVMPointer_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    const void *, arg_value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_integer_hex(uintptr_t, arg_value, (uintptr_t)arg_value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArgSVMPointer_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    const void *, arg_value,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelExecInfo_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_kernel_exec_info, param_name,
    size_t, param_value_size,
    const void *, param_value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelExecInfo_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_kernel_exec_info, param_name,
    size_t, param_value_size,
    const void *, param_value,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelInfo_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_kernel_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelInfo_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_kernel_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_kernel_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelArgInfo_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    cl_kernel_arg_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelArgInfo_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    cl_kernel_arg_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_kernel_arg_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelWorkGroupInfo_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_device_id, device,
    cl_kernel_work_group_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelWorkGroupInfo_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_device_id, device,
    cl_kernel_work_group_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_kernel_work_group_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSubGroupInfo_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_device_id, device,
    cl_kernel_sub_group_info, param_name,
    size_t, input_value_size,
    const void *, input_value,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, input_value_size, input_value_size)
    ctf_integer_hex(uintptr_t, input_value, (uintptr_t)input_value)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
    ctf_sequence_text(uint8_t, input_value_vals, input_value, size_t, input_value == NULL ? 0 : input_value_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSubGroupInfo_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_device_id, device,
    cl_kernel_sub_group_info, param_name,
    size_t, input_value_size,
    const void *, input_value,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_kernel_sub_group_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clWaitForEvents_entry,
  TP_ARGS(
    cl_uint, num_events,
    const cl_event *, event_list
  ),
  TP_FIELDS(
    ctf_integer(cl_uint, num_events, num_events)
    ctf_integer_hex(uintptr_t, event_list, (uintptr_t)event_list)
    ctf_sequence_hex(uintptr_t, event_list_vals, event_list, cl_uint, event_list == NULL ? 0 : num_events)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clWaitForEvents_exit,
  TP_ARGS(
    cl_uint, num_events,
    const cl_event *, event_list,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetEventInfo_entry,
  TP_ARGS(
    cl_event, event,
    cl_event_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetEventInfo_exit,
  TP_ARGS(
    cl_event, event,
    cl_event_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_event_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateUserEvent_entry,
  TP_ARGS(
    cl_context, context,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateUserEvent_exit,
  TP_ARGS(
    cl_context, context,
    cl_int *, errcode_ret,
    cl_event, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainEvent_entry,
  TP_ARGS(
    cl_event, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clRetainEvent_exit,
  TP_ARGS(
    cl_event, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseEvent_entry,
  TP_ARGS(
    cl_event, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clReleaseEvent_exit,
  TP_ARGS(
    cl_event, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetUserEventStatus_entry,
  TP_ARGS(
    cl_event, event,
    cl_int, execution_status
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(cl_int, execution_status, execution_status)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetUserEventStatus_exit,
  TP_ARGS(
    cl_event, event,
    cl_int, execution_status,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetEventCallback_entry,
  TP_ARGS(
    cl_event, event,
    cl_int, command_exec_callback_type,
    void *, pfn_notify,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(cl_int, command_exec_callback_type, command_exec_callback_type)
    ctf_integer_hex(uintptr_t, pfn_notify, (uintptr_t)pfn_notify)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetEventCallback_exit,
  TP_ARGS(
    cl_event, event,
    cl_int, command_exec_callback_type,
    void *, pfn_notify,
    void *, user_data,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetEventProfilingInfo_entry,
  TP_ARGS(
    cl_event, event,
    cl_profiling_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetEventProfilingInfo_exit,
  TP_ARGS(
    cl_event, event,
    cl_profiling_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_profiling_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clFlush_entry,
  TP_ARGS(
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clFlush_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clFinish_entry,
  TP_ARGS(
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clFinish_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_read,
    size_t, offset,
    size_t, size,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_uint, blocking_read, blocking_read)
    ctf_integer(size_t, offset, offset)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_read,
    size_t, offset,
    size_t, size,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadBufferRect_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_read,
    const size_t *, buffer_origin,
    const size_t *, host_origin,
    const size_t *, region,
    size_t, buffer_row_pitch,
    size_t, buffer_slice_pitch,
    size_t, host_row_pitch,
    size_t, host_slice_pitch,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_uint, blocking_read, blocking_read)
    ctf_integer_hex(uintptr_t, buffer_origin, (uintptr_t)buffer_origin)
    ctf_integer_hex(uintptr_t, host_origin, (uintptr_t)host_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, buffer_row_pitch, buffer_row_pitch)
    ctf_integer(size_t, buffer_slice_pitch, buffer_slice_pitch)
    ctf_integer(size_t, host_row_pitch, host_row_pitch)
    ctf_integer(size_t, host_slice_pitch, host_slice_pitch)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, buffer_origin_vals, buffer_origin, 3)
    ctf_array(size_t, host_origin_vals, host_origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadBufferRect_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_read,
    const size_t *, buffer_origin,
    const size_t *, host_origin,
    const size_t *, region,
    size_t, buffer_row_pitch,
    size_t, buffer_slice_pitch,
    size_t, host_row_pitch,
    size_t, host_slice_pitch,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_write,
    size_t, offset,
    size_t, size,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_uint, blocking_write, blocking_write)
    ctf_integer(size_t, offset, offset)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_write,
    size_t, offset,
    size_t, size,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteBufferRect_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_write,
    const size_t *, buffer_origin,
    const size_t *, host_origin,
    const size_t *, region,
    size_t, buffer_row_pitch,
    size_t, buffer_slice_pitch,
    size_t, host_row_pitch,
    size_t, host_slice_pitch,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_uint, blocking_write, blocking_write)
    ctf_integer_hex(uintptr_t, buffer_origin, (uintptr_t)buffer_origin)
    ctf_integer_hex(uintptr_t, host_origin, (uintptr_t)host_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, buffer_row_pitch, buffer_row_pitch)
    ctf_integer(size_t, buffer_slice_pitch, buffer_slice_pitch)
    ctf_integer(size_t, host_row_pitch, host_row_pitch)
    ctf_integer(size_t, host_slice_pitch, host_slice_pitch)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, buffer_origin_vals, buffer_origin, 3)
    ctf_array(size_t, host_origin_vals, host_origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteBufferRect_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_write,
    const size_t *, buffer_origin,
    const size_t *, host_origin,
    const size_t *, region,
    size_t, buffer_row_pitch,
    size_t, buffer_slice_pitch,
    size_t, host_row_pitch,
    size_t, host_slice_pitch,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueFillBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    const void *, pattern,
    size_t, pattern_size,
    size_t, offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer_hex(uintptr_t, pattern, (uintptr_t)pattern)
    ctf_integer(size_t, pattern_size, pattern_size)
    ctf_integer(size_t, offset, offset)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_text(uint8_t, pattern_vals, pattern, size_t, pattern == NULL ? 0 : pattern_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueFillBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    const void *, pattern,
    size_t, pattern_size,
    size_t, offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_buffer,
    size_t, src_offset,
    size_t, dst_offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, src_buffer, (uintptr_t)src_buffer)
    ctf_integer_hex(uintptr_t, dst_buffer, (uintptr_t)dst_buffer)
    ctf_integer(size_t, src_offset, src_offset)
    ctf_integer(size_t, dst_offset, dst_offset)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_buffer,
    size_t, src_offset,
    size_t, dst_offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBufferRect_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_buffer,
    const size_t *, src_origin,
    const size_t *, dst_origin,
    const size_t *, region,
    size_t, src_row_pitch,
    size_t, src_slice_pitch,
    size_t, dst_row_pitch,
    size_t, dst_slice_pitch,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, src_buffer, (uintptr_t)src_buffer)
    ctf_integer_hex(uintptr_t, dst_buffer, (uintptr_t)dst_buffer)
    ctf_integer_hex(uintptr_t, src_origin, (uintptr_t)src_origin)
    ctf_integer_hex(uintptr_t, dst_origin, (uintptr_t)dst_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, src_row_pitch, src_row_pitch)
    ctf_integer(size_t, src_slice_pitch, src_slice_pitch)
    ctf_integer(size_t, dst_row_pitch, dst_row_pitch)
    ctf_integer(size_t, dst_slice_pitch, dst_slice_pitch)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, src_origin_vals, src_origin, 3)
    ctf_array(size_t, dst_origin_vals, dst_origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBufferRect_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_buffer,
    const size_t *, src_origin,
    const size_t *, dst_origin,
    const size_t *, region,
    size_t, src_row_pitch,
    size_t, src_slice_pitch,
    size_t, dst_row_pitch,
    size_t, dst_slice_pitch,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_read,
    const size_t *, origin,
    const size_t *, region,
    size_t, row_pitch,
    size_t, slice_pitch,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, image, (uintptr_t)image)
    ctf_integer(cl_uint, blocking_read, blocking_read)
    ctf_integer_hex(uintptr_t, origin, (uintptr_t)origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, row_pitch, row_pitch)
    ctf_integer(size_t, slice_pitch, slice_pitch)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, origin_vals, origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueReadImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_read,
    const size_t *, origin,
    const size_t *, region,
    size_t, row_pitch,
    size_t, slice_pitch,
    void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_write,
    const size_t *, origin,
    const size_t *, region,
    size_t, input_row_pitch,
    size_t, input_slice_pitch,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, image, (uintptr_t)image)
    ctf_integer(cl_uint, blocking_write, blocking_write)
    ctf_integer_hex(uintptr_t, origin, (uintptr_t)origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, input_row_pitch, input_row_pitch)
    ctf_integer(size_t, input_slice_pitch, input_slice_pitch)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, origin_vals, origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWriteImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_write,
    const size_t *, origin,
    const size_t *, region,
    size_t, input_row_pitch,
    size_t, input_slice_pitch,
    const void *, ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueFillImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    const void *, fill_color,
    const size_t *, origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, image, (uintptr_t)image)
    ctf_integer_hex(uintptr_t, fill_color, (uintptr_t)fill_color)
    ctf_integer_hex(uintptr_t, origin, (uintptr_t)origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, origin_vals, origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueFillImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    const void *, fill_color,
    const size_t *, origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_image,
    cl_mem, dst_image,
    const size_t *, src_origin,
    const size_t *, dst_origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, src_image, (uintptr_t)src_image)
    ctf_integer_hex(uintptr_t, dst_image, (uintptr_t)dst_image)
    ctf_integer_hex(uintptr_t, src_origin, (uintptr_t)src_origin)
    ctf_integer_hex(uintptr_t, dst_origin, (uintptr_t)dst_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, src_origin_vals, src_origin, 3)
    ctf_array(size_t, dst_origin_vals, dst_origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_image,
    cl_mem, dst_image,
    const size_t *, src_origin,
    const size_t *, dst_origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyImageToBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_image,
    cl_mem, dst_buffer,
    const size_t *, src_origin,
    const size_t *, region,
    size_t, dst_offset,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, src_image, (uintptr_t)src_image)
    ctf_integer_hex(uintptr_t, dst_buffer, (uintptr_t)dst_buffer)
    ctf_integer_hex(uintptr_t, src_origin, (uintptr_t)src_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(size_t, dst_offset, dst_offset)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyImageToBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_image,
    cl_mem, dst_buffer,
    const size_t *, src_origin,
    const size_t *, region,
    size_t, dst_offset,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBufferToImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_image,
    size_t, src_offset,
    const size_t *, dst_origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, src_buffer, (uintptr_t)src_buffer)
    ctf_integer_hex(uintptr_t, dst_image, (uintptr_t)dst_image)
    ctf_integer(size_t, src_offset, src_offset)
    ctf_integer_hex(uintptr_t, dst_origin, (uintptr_t)dst_origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, dst_origin_vals, dst_origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueCopyBufferToImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, src_buffer,
    cl_mem, dst_image,
    size_t, src_offset,
    const size_t *, dst_origin,
    const size_t *, region,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMapBuffer_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_map,
    cl_map_flags, map_flags,
    size_t, offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, buffer, (uintptr_t)buffer)
    ctf_integer(cl_uint, blocking_map, blocking_map)
    ctf_integer(cl_ulong, map_flags, map_flags)
    ctf_integer(size_t, offset, offset)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMapBuffer_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, buffer,
    cl_bool, blocking_map,
    cl_map_flags, map_flags,
    size_t, offset,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int *, errcode_ret,
    void *, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMapImage_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_map,
    cl_map_flags, map_flags,
    const size_t *, origin,
    const size_t *, region,
    size_t *, image_row_pitch,
    size_t *, image_slice_pitch,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, image, (uintptr_t)image)
    ctf_integer(cl_uint, blocking_map, blocking_map)
    ctf_integer(cl_ulong, map_flags, map_flags)
    ctf_integer_hex(uintptr_t, origin, (uintptr_t)origin)
    ctf_integer_hex(uintptr_t, region, (uintptr_t)region)
    ctf_integer_hex(uintptr_t, image_row_pitch, (uintptr_t)image_row_pitch)
    ctf_integer_hex(uintptr_t, image_slice_pitch, (uintptr_t)image_slice_pitch)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_array(size_t, origin_vals, origin, 3)
    ctf_array(size_t, region_vals, region, 3)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMapImage_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, image,
    cl_bool, blocking_map,
    cl_map_flags, map_flags,
    const size_t *, origin,
    const size_t *, region,
    size_t *, image_row_pitch,
    size_t *, image_slice_pitch,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int *, errcode_ret,
    void *, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(size_t, image_row_pitch_val, image_row_pitch == NULL ? 0 : *image_row_pitch)
    ctf_integer(size_t, image_slice_pitch_val, image_slice_pitch == NULL ? 0 : *image_slice_pitch)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueUnmapMemObject_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, memobj,
    void *, mapped_ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer_hex(uintptr_t, mapped_ptr, (uintptr_t)mapped_ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueUnmapMemObject_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_mem, memobj,
    void *, mapped_ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemObjects_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_objects,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_mem_objects, num_mem_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_mem_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemObjects_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_objects,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNDRangeKernel_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, global_work_size,
    const size_t *, local_work_size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, work_dim, work_dim)
    ctf_integer_hex(uintptr_t, global_work_offset, (uintptr_t)global_work_offset)
    ctf_integer_hex(uintptr_t, global_work_size, (uintptr_t)global_work_size)
    ctf_integer_hex(uintptr_t, local_work_size, (uintptr_t)local_work_size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence(size_t, global_work_offset_vals, global_work_offset, cl_uint, global_work_offset == NULL ? 0 : work_dim)
    ctf_sequence(size_t, global_work_size_vals, global_work_size, cl_uint, global_work_size == NULL ? 0 : work_dim)
    ctf_sequence(size_t, local_work_size_vals, local_work_size, cl_uint, local_work_size == NULL ? 0 : work_dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNDRangeKernel_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, global_work_size,
    const size_t *, local_work_size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNativeKernel_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, user_func,
    void *, args,
    size_t, cb_args,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_list,
    const void **, args_mem_loc,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, user_func, (uintptr_t)user_func)
    ctf_integer_hex(uintptr_t, args, (uintptr_t)args)
    ctf_integer(size_t, cb_args, cb_args)
    ctf_integer(cl_uint, num_mem_objects, num_mem_objects)
    ctf_integer_hex(uintptr_t, mem_list, (uintptr_t)mem_list)
    ctf_integer_hex(uintptr_t, args_mem_loc, (uintptr_t)args_mem_loc)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_text(uint8_t, args_vals, args, size_t, args == NULL ? 0 : cb_args)
    ctf_sequence_hex(uintptr_t, mem_list_vals, mem_list, cl_uint, mem_list == NULL ? 0 : num_mem_objects)
    ctf_sequence_hex(uintptr_t, args_mem_loc_vals, args_mem_loc, cl_uint, args_mem_loc == NULL ? 0 : num_mem_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNativeKernel_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, user_func,
    void *, args,
    size_t, cb_args,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_list,
    const void **, args_mem_loc,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMarkerWithWaitList_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMarkerWithWaitList_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueBarrierWithWaitList_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueBarrierWithWaitList_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMFree_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    void * *, svm_pointers,
    void *, pfn_free_func,
    void *, user_data,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_svm_pointers, num_svm_pointers)
    ctf_integer_hex(uintptr_t, svm_pointers, (uintptr_t)svm_pointers)
    ctf_integer_hex(uintptr_t, pfn_free_func, (uintptr_t)pfn_free_func)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, svm_pointers_vals, svm_pointers, cl_uint, svm_pointers == NULL ? 0 : num_svm_pointers)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMFree_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    void * *, svm_pointers,
    void *, pfn_free_func,
    void *, user_data,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMemcpy_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking_copy,
    void *, dst_ptr,
    const void *, src_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, blocking_copy, blocking_copy)
    ctf_integer_hex(uintptr_t, dst_ptr, (uintptr_t)dst_ptr)
    ctf_integer_hex(uintptr_t, src_ptr, (uintptr_t)src_ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMemcpy_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking_copy,
    void *, dst_ptr,
    const void *, src_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMemFill_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, svm_ptr,
    const void *, pattern,
    size_t, pattern_size,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, svm_ptr, (uintptr_t)svm_ptr)
    ctf_integer_hex(uintptr_t, pattern, (uintptr_t)pattern)
    ctf_integer(size_t, pattern_size, pattern_size)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_text(uint8_t, pattern_vals, pattern, size_t, pattern == NULL ? 0 : pattern_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMemFill_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, svm_ptr,
    const void *, pattern,
    size_t, pattern_size,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMap_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking_map,
    cl_map_flags, flags,
    void *, svm_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, blocking_map, blocking_map)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, svm_ptr, (uintptr_t)svm_ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMap_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking_map,
    cl_map_flags, flags,
    void *, svm_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMUnmap_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, svm_ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, svm_ptr, (uintptr_t)svm_ptr)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMUnmap_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, svm_ptr,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMigrateMem_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    const void **, svm_pointers,
    const size_t *, sizes,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_svm_pointers, num_svm_pointers)
    ctf_integer_hex(uintptr_t, svm_pointers, (uintptr_t)svm_pointers)
    ctf_integer_hex(uintptr_t, sizes, (uintptr_t)sizes)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, svm_pointers_vals, svm_pointers, cl_uint, svm_pointers == NULL ? 0 : num_svm_pointers)
    ctf_sequence(size_t, sizes_vals, sizes, cl_uint, sizes == NULL ? 0 : num_svm_pointers)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMMigrateMem_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    const void **, svm_pointers,
    const size_t *, sizes,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExtensionFunctionAddressForPlatform_entry,
  TP_ARGS(
    cl_platform_id, platform,
    const char *, func_name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, platform, (uintptr_t)platform)
    ctf_integer_hex(uintptr_t, func_name, (uintptr_t)func_name)
    ctf_string(func_name_val, func_name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExtensionFunctionAddressForPlatform_exit,
  TP_ARGS(
    cl_platform_id, platform,
    const char *, func_name,
    void *, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetCommandQueueProperty_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_command_queue_properties, properties,
    cl_bool, enable,
    cl_command_queue_properties *, old_properties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_ulong, properties, properties)
    ctf_integer(cl_uint, enable, enable)
    ctf_integer_hex(uintptr_t, old_properties, (uintptr_t)old_properties)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetCommandQueueProperty_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_command_queue_properties, properties,
    cl_bool, enable,
    cl_command_queue_properties *, old_properties,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_ulong, old_properties_val, old_properties == NULL ? 0 : *old_properties)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage2D_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    size_t, image_width,
    size_t, image_height,
    size_t, image_row_pitch,
    void *, host_ptr,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer(size_t, image_width, image_width)
    ctf_integer(size_t, image_height, image_height)
    ctf_integer(size_t, image_row_pitch, image_row_pitch)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage2D_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    size_t, image_width,
    size_t, image_height,
    size_t, image_row_pitch,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage3D_entry,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    size_t, image_width,
    size_t, image_height,
    size_t, image_depth,
    size_t, image_row_pitch,
    size_t, image_slice_pitch,
    void *, host_ptr,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer(size_t, image_width, image_width)
    ctf_integer(size_t, image_height, image_height)
    ctf_integer(size_t, image_depth, image_depth)
    ctf_integer(size_t, image_row_pitch, image_row_pitch)
    ctf_integer(size_t, image_slice_pitch, image_slice_pitch)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImage3D_exit,
  TP_ARGS(
    cl_context, context,
    cl_mem_flags, flags,
    const cl_image_format *, image_format,
    size_t, image_width,
    size_t, image_height,
    size_t, image_depth,
    size_t, image_row_pitch,
    size_t, image_slice_pitch,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMarker_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMarker_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWaitForEvents_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events,
    const cl_event *, event_list
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_events, num_events)
    ctf_integer_hex(uintptr_t, event_list, (uintptr_t)event_list)
    ctf_sequence_hex(uintptr_t, event_list_vals, event_list, cl_uint, event_list == NULL ? 0 : num_events)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueWaitForEvents_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_events,
    const cl_event *, event_list,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueBarrier_entry,
  TP_ARGS(
    cl_command_queue, command_queue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueBarrier_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clUnloadCompiler_entry,
  TP_ARGS(
    void
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clUnloadCompiler_exit,
  TP_ARGS(
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExtensionFunctionAddress_entry,
  TP_ARGS(
    const char *, func_name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, func_name, (uintptr_t)func_name)
    ctf_string(func_name_val, func_name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExtensionFunctionAddress_exit,
  TP_ARGS(
    const char *, func_name,
    void *, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueue_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue_properties, properties,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_ulong, properties, properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueue_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue_properties, properties,
    cl_int *, errcode_ret,
    cl_command_queue, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSampler_entry,
  TP_ARGS(
    cl_context, context,
    cl_bool, normalized_coords,
    cl_addressing_mode, addressing_mode,
    cl_filter_mode, filter_mode,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer(cl_uint, normalized_coords, normalized_coords)
    ctf_integer(cl_uint, addressing_mode, addressing_mode)
    ctf_integer(cl_uint, filter_mode, filter_mode)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateSampler_exit,
  TP_ARGS(
    cl_context, context,
    cl_bool, normalized_coords,
    cl_addressing_mode, addressing_mode,
    cl_filter_mode, filter_mode,
    cl_int *, errcode_ret,
    cl_sampler, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, sampler, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueTask_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueTask_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithILKHR_entry,
  TP_ARGS(
    cl_context, context,
    const void *, il,
    size_t, length,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, il, (uintptr_t)il)
    ctf_integer(size_t, length, length)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateProgramWithILKHR_exit,
  TP_ARGS(
    cl_context, context,
    const void *, il,
    size_t, length,
    cl_int *, errcode_ret,
    cl_program, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clTerminateContextKHR_entry,
  TP_ARGS(
    cl_context, context
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clTerminateContextKHR_exit,
  TP_ARGS(
    cl_context, context,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueueWithPropertiesKHR_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_queue_properties_khr *, properties,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateCommandQueueWithPropertiesKHR_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_queue_properties_khr *, properties,
    cl_int *, errcode_ret,
    cl_command_queue, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemObjectEXT_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_objects,
    cl_mem_migration_flags_ext, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_mem_objects, num_mem_objects)
    ctf_integer_hex(uintptr_t, mem_objects, (uintptr_t)mem_objects)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_hex(uintptr_t, mem_objects_vals, mem_objects, cl_uint, mem_objects == NULL ? 0 : num_mem_objects)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemObjectEXT_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_mem_objects,
    const cl_mem *, mem_objects,
    cl_mem_migration_flags_ext, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSuggestedLocalWorkSizeKHR_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, global_work_size,
    size_t *, suggested_local_work_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, work_dim, work_dim)
    ctf_integer_hex(uintptr_t, global_work_offset, (uintptr_t)global_work_offset)
    ctf_integer_hex(uintptr_t, global_work_size, (uintptr_t)global_work_size)
    ctf_integer_hex(uintptr_t, suggested_local_work_size, (uintptr_t)suggested_local_work_size)
    ctf_sequence(size_t, global_work_offset_vals, global_work_offset, cl_uint, global_work_offset == NULL ? 0 : work_dim)
    ctf_sequence(size_t, global_work_size_vals, global_work_size, cl_uint, global_work_size == NULL ? 0 : work_dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetKernelSuggestedLocalWorkSizeKHR_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, global_work_size,
    size_t *, suggested_local_work_size,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_sequence(size_t, suggested_local_work_size_vals, suggested_local_work_size, cl_uint, suggested_local_work_size == NULL ? 0 : work_dim)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetICDLoaderInfoOCLICD_entry,
  TP_ARGS(
    cl_icdl_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetICDLoaderInfoOCLICD_exit,
  TP_ARGS(
    cl_icdl_info, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_icdl_info, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImageWithPropertiesINTEL_entry,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer_hex(uintptr_t, image_desc, (uintptr_t)image_desc)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
    ctf_sequence_text(uint8_t, image_desc_val, (uint8_t *)image_desc, size_t, image_desc == NULL ? 0 : sizeof(cl_image_desc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateImageWithPropertiesINTEL_exit,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetImageParamsINTEL_entry,
  TP_ARGS(
    cl_context, context,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    size_t *, image_row_pitch,
    size_t *, image_slice_pitch
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, image_format, (uintptr_t)image_format)
    ctf_integer_hex(uintptr_t, image_desc, (uintptr_t)image_desc)
    ctf_integer_hex(uintptr_t, image_row_pitch, (uintptr_t)image_row_pitch)
    ctf_integer_hex(uintptr_t, image_slice_pitch, (uintptr_t)image_slice_pitch)
    ctf_sequence_text(uint8_t, image_format_val, (uint8_t *)image_format, size_t, image_format == NULL ? 0 : sizeof(cl_image_format))
    ctf_sequence_text(uint8_t, image_desc_val, (uint8_t *)image_desc, size_t, image_desc == NULL ? 0 : sizeof(cl_image_desc))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetImageParamsINTEL_exit,
  TP_ARGS(
    cl_context, context,
    const cl_image_format *, image_format,
    const cl_image_desc *, image_desc,
    size_t *, image_row_pitch,
    size_t *, image_slice_pitch,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, image_row_pitch_val, image_row_pitch == NULL ? 0 : *image_row_pitch)
    ctf_integer(size_t, image_slice_pitch_val, image_slice_pitch == NULL ? 0 : *image_slice_pitch)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueVerifyMemoryINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, allocation_ptr,
    const void *, expected_data,
    size_t, size_of_comparison,
    cl_uint, comparison_mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, allocation_ptr, (uintptr_t)allocation_ptr)
    ctf_integer_hex(uintptr_t, expected_data, (uintptr_t)expected_data)
    ctf_integer(size_t, size_of_comparison, size_of_comparison)
    ctf_integer(cl_uint, comparison_mode, comparison_mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueVerifyMemoryINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, allocation_ptr,
    const void *, expected_data,
    size_t, size_of_comparison,
    cl_uint, comparison_mode,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clAddCommentINTEL_entry,
  TP_ARGS(
    cl_device_id, device,
    const char *, comment
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, comment, (uintptr_t)comment)
    ctf_string(comment_val, comment)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clAddCommentINTEL_exit,
  TP_ARGS(
    cl_device_id, device,
    const char *, comment,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreatePerfCountersCommandQueueINTEL_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue_properties, properties,
    cl_uint, configuration,
    cl_int *, errcode_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_ulong, properties, properties)
    ctf_integer(cl_uint, configuration, configuration)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreatePerfCountersCommandQueueINTEL_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    cl_command_queue_properties, properties,
    cl_uint, configuration,
    cl_int *, errcode_ret,
    cl_command_queue, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetPerformanceConfigurationINTEL_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_uint, count,
    cl_uint *, offsets,
    cl_uint *, values
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer(cl_uint, count, count)
    ctf_integer_hex(uintptr_t, offsets, (uintptr_t)offsets)
    ctf_integer_hex(uintptr_t, values, (uintptr_t)values)
    ctf_sequence(cl_uint, offsets_vals, offsets, cl_uint, offsets == NULL ? 0 : count)
    ctf_sequence(cl_uint, values_vals, values, cl_uint, values == NULL ? 0 : count)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetPerformanceConfigurationINTEL_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_uint, count,
    cl_uint *, offsets,
    cl_uint *, values,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_sequence(cl_uint, offsets_vals, offsets, cl_uint, offsets == NULL ? 0 : count)
    ctf_sequence(cl_uint, values_vals, values, cl_uint, values == NULL ? 0 : count)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceFunctionPointerINTEL_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_program, program,
    const char *, function_name,
    cl_ulong *, function_pointer_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, function_name, (uintptr_t)function_name)
    ctf_integer_hex(uintptr_t, function_pointer_ret, (uintptr_t)function_pointer_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceFunctionPointerINTEL_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_program, program,
    const char *, function_name,
    cl_ulong *, function_pointer_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(cl_ulong, function_pointer_ret_val, function_pointer_ret == NULL ? 0 : *function_pointer_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceGlobalVariablePointerINTEL_entry,
  TP_ARGS(
    cl_device_id, device,
    cl_program, program,
    const char *, global_variable_name,
    size_t *, global_variable_size_ret,
    void **, global_variable_pointer_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, global_variable_name, (uintptr_t)global_variable_name)
    ctf_integer_hex(uintptr_t, global_variable_size_ret, (uintptr_t)global_variable_size_ret)
    ctf_integer_hex(uintptr_t, global_variable_pointer_ret, (uintptr_t)global_variable_pointer_ret)
    ctf_string(global_variable_name_val, global_variable_name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetDeviceGlobalVariablePointerINTEL_exit,
  TP_ARGS(
    cl_device_id, device,
    cl_program, program,
    const char *, global_variable_name,
    size_t *, global_variable_size_ret,
    void **, global_variable_pointer_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, global_variable_size_ret_val, global_variable_size_ret == NULL ? 0 : *global_variable_size_ret)
    ctf_integer_hex(uintptr_t, global_variable_pointer_ret_val, (uintptr_t)(global_variable_pointer_ret == NULL ? 0 : *global_variable_pointer_ret))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExecutionInfoINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, local_work_size,
    cl_execution_info_intel, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, work_dim, work_dim)
    ctf_integer_hex(uintptr_t, global_work_offset, (uintptr_t)global_work_offset)
    ctf_integer_hex(uintptr_t, local_work_size, (uintptr_t)local_work_size)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
    ctf_sequence(size_t, global_work_offset_vals, global_work_offset, cl_uint, global_work_offset == NULL ? 0 : work_dim)
    ctf_sequence(size_t, local_work_size_vals, local_work_size, cl_uint, local_work_size == NULL ? 0 : work_dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetExecutionInfoINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, local_work_size,
    cl_execution_info_intel, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_execution_info_intel, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNDRangeKernelINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, work_group_count,
    const size_t *, local_work_size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, work_dim, work_dim)
    ctf_integer_hex(uintptr_t, global_work_offset, (uintptr_t)global_work_offset)
    ctf_integer_hex(uintptr_t, work_group_count, (uintptr_t)work_group_count)
    ctf_integer_hex(uintptr_t, local_work_size, (uintptr_t)local_work_size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence(size_t, global_work_offset_vals, global_work_offset, cl_uint, global_work_offset == NULL ? 0 : work_dim)
    ctf_sequence(size_t, work_group_count_vals, work_group_count, cl_uint, work_group_count == NULL ? 0 : work_dim)
    ctf_sequence(size_t, local_work_size_vals, local_work_size, cl_uint, local_work_size == NULL ? 0 : work_dim)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueNDRangeKernelINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_kernel, kernel,
    cl_uint, work_dim,
    const size_t *, global_work_offset,
    const size_t *, work_group_count,
    const size_t *, local_work_size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clHostMemAllocINTEL_entry,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, alignment, alignment)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clHostMemAllocINTEL_exit,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    void *, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clDeviceMemAllocINTEL_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, alignment, alignment)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clDeviceMemAllocINTEL_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    void *, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSharedMemAllocINTEL_entry,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, device, (uintptr_t)device)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, alignment, alignment)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSharedMemAllocINTEL_exit,
  TP_ARGS(
    cl_context, context,
    cl_device_id, device,
    const cl_mem_properties_intel *, properties,
    size_t, size,
    cl_uint, alignment,
    cl_int *, errcode_ret,
    void *, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, _retval, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clMemFreeINTEL_entry,
  TP_ARGS(
    cl_context, context,
    void *, ptr
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clMemFreeINTEL_exit,
  TP_ARGS(
    cl_context, context,
    void *, ptr,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetMemAllocInfoINTEL_entry,
  TP_ARGS(
    cl_context, context,
    const void *, ptr,
    cl_mem_info_intel, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(cl_uint, param_name, param_name)
    ctf_integer(size_t, param_value_size, param_value_size)
    ctf_integer_hex(uintptr_t, param_value, (uintptr_t)param_value)
    ctf_integer_hex(uintptr_t, param_value_size_ret, (uintptr_t)param_value_size_ret)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clGetMemAllocInfoINTEL_exit,
  TP_ARGS(
    cl_context, context,
    const void *, ptr,
    cl_mem_info_intel, param_name,
    size_t, param_value_size,
    void *, param_value,
    size_t *, param_value_size_ret,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(size_t, param_value_size_ret_val, *param_value_size_ret)
    ctf_sequence_text(uint8_t, param_value_vals, param_value, size_t, param_value == NULL ? 0 : param_value_size)
    ctf_integer_hex(cl_mem_info_intel, _param_name, param_name)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArgMemPointerINTEL_entry,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    const void *, arg_value
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, kernel, (uintptr_t)kernel)
    ctf_integer(cl_uint, arg_index, arg_index)
    ctf_integer_hex(uintptr_t, arg_value, (uintptr_t)arg_value)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetKernelArgMemPointerINTEL_exit,
  TP_ARGS(
    cl_kernel, kernel,
    cl_uint, arg_index,
    const void *, arg_value,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemsetINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, dst_ptr,
    cl_int, value,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, dst_ptr, (uintptr_t)dst_ptr)
    ctf_integer(cl_int, value, value)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemsetINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, dst_ptr,
    cl_int, value,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemFillINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, dst_ptr,
    const void *, pattern,
    size_t, pattern_size,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, dst_ptr, (uintptr_t)dst_ptr)
    ctf_integer_hex(uintptr_t, pattern, (uintptr_t)pattern)
    ctf_integer(size_t, pattern_size, pattern_size)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
    ctf_sequence_text(uint8_t, pattern_vals, pattern, size_t, pattern == NULL ? 0 : pattern_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemFillINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    void *, dst_ptr,
    const void *, pattern,
    size_t, pattern_size,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemcpyINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking,
    void *, dst_ptr,
    const void *, src_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, blocking, blocking)
    ctf_integer_hex(uintptr_t, dst_ptr, (uintptr_t)dst_ptr)
    ctf_integer_hex(uintptr_t, src_ptr, (uintptr_t)src_ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemcpyINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_bool, blocking,
    void *, dst_ptr,
    const void *, src_ptr,
    size_t, size,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, ptr,
    size_t, size,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMigrateMemINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, ptr,
    size_t, size,
    cl_mem_migration_flags, flags,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemAdviseINTEL_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, ptr,
    size_t, size,
    cl_mem_advice_intel, advice,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer_hex(uintptr_t, ptr, (uintptr_t)ptr)
    ctf_integer(size_t, size, size)
    ctf_integer(cl_uint, advice, advice)
    ctf_integer(cl_uint, num_events_in_wait_list, num_events_in_wait_list)
    ctf_integer_hex(uintptr_t, event_wait_list, (uintptr_t)event_wait_list)
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_sequence_hex(uintptr_t, event_wait_list_vals, event_wait_list, cl_uint, event_wait_list == NULL ? 0 : num_events_in_wait_list)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueMemAdviseINTEL_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    const void *, ptr,
    size_t, size,
    cl_mem_advice_intel, advice,
    cl_uint, num_events_in_wait_list,
    const cl_event *, event_wait_list,
    cl_event *, event,
    cl_int, _retval,
    uint64_t, _duration
  ),
  TP_FIELDS(
    ctf_integer(cl_int, errcode_ret_val, _retval)
    ctf_integer_hex(uintptr_t, event_val, (uintptr_t)(event == NULL ? 0 : *event))
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBufferWithPropertiesINTEL_entry,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, properties, (uintptr_t)properties)
    ctf_integer(cl_ulong, flags, flags)
    ctf_integer(size_t, size, size)
    ctf_integer_hex(uintptr_t, host_ptr, (uintptr_t)host_ptr)
    ctf_integer_hex(uintptr_t, errcode_ret, (uintptr_t)errcode_ret)
    ctf_sequence(cl_ulong, properties_vals, properties, size_t, properties == NULL ? 0 : _properties_size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateBufferWithPropertiesINTEL_exit,
  TP_ARGS(
    cl_context, context,
    const cl_mem_properties_intel *, properties,
    cl_mem_flags, flags,
    size_t, size,
    void *, host_ptr,
    cl_int *, errcode_ret,
    cl_mem, _retval,
    uint64_t, _duration,
    size_t, _properties_size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, mem, (uintptr_t)_retval)
    ctf_integer(cl_int, errcode_ret_val, *errcode_ret)
    ctf_integer(uint64_t, _duration, _duration)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clBuildProgram_callback_entry,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clBuildProgram_callback_exit,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCompileProgram_callback_entry,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCompileProgram_callback_exit,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clLinkProgram_callback_entry,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clLinkProgram_callback_exit,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContext_callback_entry,
  TP_ARGS(
    const char *, errinfo,
    const void *, private_info,
    size_t, cb,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, errinfo, (uintptr_t)errinfo)
    ctf_integer_hex(uintptr_t, private_info, (uintptr_t)private_info)
    ctf_integer(size_t, cb, cb)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_string(errinfo_val, errinfo)
    ctf_sequence_text(uint8_t, private_info_vals, private_info, size_t, (private_info ? cb : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContext_callback_exit,
  TP_ARGS(
    const char *, errinfo,
    const void *, private_info,
    size_t, cb,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContextFromType_callback_entry,
  TP_ARGS(
    const char *, errinfo,
    const void *, private_info,
    size_t, cb,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, errinfo, (uintptr_t)errinfo)
    ctf_integer_hex(uintptr_t, private_info, (uintptr_t)private_info)
    ctf_integer(size_t, cb, cb)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_string(errinfo_val, errinfo)
    ctf_sequence_text(uint8_t, private_info_vals, private_info, size_t, (private_info ? cb : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clCreateContextFromType_callback_exit,
  TP_ARGS(
    const char *, errinfo,
    const void *, private_info,
    size_t, cb,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetMemObjectDestructorCallback_callback_entry,
  TP_ARGS(
    cl_mem, memobj,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, memobj, (uintptr_t)memobj)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetMemObjectDestructorCallback_callback_exit,
  TP_ARGS(
    cl_mem, memobj,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramReleaseCallback_callback_entry,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, program, (uintptr_t)program)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetProgramReleaseCallback_callback_exit,
  TP_ARGS(
    cl_program, program,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetEventCallback_callback_entry,
  TP_ARGS(
    cl_event, event,
    cl_int, type,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, event, (uintptr_t)event)
    ctf_integer(cl_int, type, type)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetEventCallback_callback_exit,
  TP_ARGS(
    cl_event, event,
    cl_int, type,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMFree_callback_entry,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    void **, svm_pointers,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, command_queue, (uintptr_t)command_queue)
    ctf_integer(cl_uint, num_svm_pointers, num_svm_pointers)
    ctf_integer_hex(uintptr_t, svm_pointers, (uintptr_t)svm_pointers)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
    ctf_sequence_hex(uintptr_t, svm_pointers_vals, svm_pointers, cl_uint, svm_pointers ? num_svm_pointers : 0)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clEnqueueSVMFree_callback_exit,
  TP_ARGS(
    cl_command_queue, command_queue,
    cl_uint, num_svm_pointers,
    void **, svm_pointers,
    void *, user_data
  ),
  TP_FIELDS(
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetContextDestructorCallback_callback_entry,
  TP_ARGS(
    cl_context, context,
    void *, user_data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, context, (uintptr_t)context)
    ctf_integer_hex(uintptr_t, user_data, (uintptr_t)user_data)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_opencl,
  clSetContextDestructorCallback_callback_exit,
  TP_ARGS(
    cl_context, context,
    void *, user_data
  ),
  TP_FIELDS(
  )
)


#endif /* OPENCL_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
