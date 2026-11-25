require_relative 'omp_library.rb'
$event_lambdas["lttng_ust_ompt:ompt_callback_thread_begin"] = lambda { |defi|
  s = "{ "
  s << "thread_type: #{OMP::OMPTThread.from_native(defi["thread_type"], nil)}"
  s << ', '
  s << "thread_data: #{"0x%016x" % defi["thread_data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_thread_end"] = lambda { |defi|
  s = "{ "
  s << "thread_data: #{"0x%016x" % defi["thread_data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_parallel_begin"] = lambda { |defi|
  s = "{ "
  s << "encountering_task_data: #{"0x%016x" % defi["encountering_task_data"]}"
  s << ', '
  s << "encountering_task_frame: #{"0x%016x" % defi["encountering_task_frame"]}"
  s << ', '
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "requested_parallelism: #{defi["requested_parallelism"]}"
  s << ', '
  s << "flags: [ #{OMP::OMPTParallelFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_parallel_end"] = lambda { |defi|
  s = "{ "
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "encountering_task_data: #{"0x%016x" % defi["encountering_task_data"]}"
  s << ', '
  s << "flags: [ #{OMP::OMPTParallelFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_work"] = lambda { |defi|
  s = "{ "
  s << "work_type: #{OMP::OMPTWork.from_native(defi["work_type"], nil)}"
  s << ', '
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_dispatch"] = lambda { |defi|
  s = "{ "
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "kind: #{OMP::OMPTDispatch.from_native(defi["kind"], nil)}"
  s << ', '
  s << "instance: #{defi["instance"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_task_create"] = lambda { |defi|
  s = "{ "
  s << "encountering_task_data: #{"0x%016x" % defi["encountering_task_data"]}"
  s << ', '
  s << "encountering_task_frame: #{"0x%016x" % defi["encountering_task_frame"]}"
  s << ', '
  s << "new_task_data: #{"0x%016x" % defi["new_task_data"]}"
  s << ', '
  s << "flags: [ #{OMP::OMPTTaskFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "has_dependences: #{defi["has_dependences"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_dependences"] = lambda { |defi|
  s = "{ "
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "deps: #{"0x%016x" % defi["deps"]}"
  s << ', '
  s << "ndeps: #{defi["ndeps"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_task_dependence"] = lambda { |defi|
  s = "{ "
  s << "src_task_data: #{"0x%016x" % defi["src_task_data"]}"
  s << ', '
  s << "sink_task_data: #{"0x%016x" % defi["sink_task_data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_task_schedule"] = lambda { |defi|
  s = "{ "
  s << "prior_task_data: #{"0x%016x" % defi["prior_task_data"]}"
  s << ', '
  s << "prior_task_status: #{OMP::OMPTTaskStatus.from_native(defi["prior_task_status"], nil)}"
  s << ', '
  s << "next_task_data: #{"0x%016x" % defi["next_task_data"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_implicit_task"] = lambda { |defi|
  s = "{ "
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "actual_parallelism: #{defi["actual_parallelism"]}"
  s << ', '
  s << "index: #{defi["index"]}"
  s << ', '
  s << "flags: [ #{OMP::OMPTTaskFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_masked"] = lambda { |defi|
  s = "{ "
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_sync_region"] = lambda { |defi|
  s = "{ "
  s << "kind: #{OMP::OMPTSyncRegion.from_native(defi["kind"], nil)}"
  s << ', '
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "parallel_data: #{"0x%016x" % defi["parallel_data"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_mutex_acquire"] = lambda { |defi|
  s = "{ "
  s << "kind: #{OMP::OMPTMutex.from_native(defi["kind"], nil)}"
  s << ', '
  s << "hint: #{defi["hint"]}"
  s << ', '
  s << "impl: #{defi["impl"]}"
  s << ', '
  s << "wait_id: #{defi["wait_id"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_mutex"] = lambda { |defi|
  s = "{ "
  s << "kind: #{OMP::OMPTMutex.from_native(defi["kind"], nil)}"
  s << ', '
  s << "wait_id: #{defi["wait_id"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_nest_lock"] = lambda { |defi|
  s = "{ "
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "wait_id: #{defi["wait_id"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_flush"] = lambda { |defi|
  s = "{ "
  s << "thread_data: #{"0x%016x" % defi["thread_data"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_cancel"] = lambda { |defi|
  s = "{ "
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "flags: [ #{OMP::OMPTCancelFlags.from_native(defi["flags"], nil).join(", ")} ]"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_device_initialize"] = lambda { |defi|
  s = "{ "
  s << "device_num: #{defi["device_num"]}"
  s << ', '
  s << "type: #{"0x%016x" % defi["type"]}"
  s << ', '
  s << "device: #{"0x%016x" % defi["device"]}"
  s << ', '
  s << "lookup: #{"0x%016x" % defi["lookup"]}"
  s << ', '
  s << "documentation: #{"0x%016x" % defi["documentation"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_device_finalize"] = lambda { |defi|
  s = "{ "
  s << "device_num: #{defi["device_num"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_device_load"] = lambda { |defi|
  s = "{ "
  s << "device_num: #{defi["device_num"]}"
  s << ', '
  s << "filename: #{"0x%016x" % defi["filename"]}"
  s << ', '
  s << "offset_in_file: #{defi["offset_in_file"]}"
  s << ', '
  s << "vma_in_file: #{"0x%016x" % defi["vma_in_file"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << ', '
  s << "host_addr: #{"0x%016x" % defi["host_addr"]}"
  s << ', '
  s << "device_addr: #{"0x%016x" % defi["device_addr"]}"
  s << ', '
  s << "module_id: #{defi["module_id"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_device_unload"] = lambda { |defi|
  s = "{ "
  s << "device_num: #{defi["device_num"]}"
  s << ', '
  s << "module_id: #{defi["module_id"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_data_op_emi"] = lambda { |defi|
  s = "{ "
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "target_task_data: #{"0x%016x" % defi["target_task_data"]}"
  s << ', '
  s << "target_data: #{"0x%016x" % defi["target_data"]}"
  s << ', '
  s << "host_op_id: #{"0x%016x" % defi["host_op_id"]}"
  s << ', '
  s << "optype: #{OMP::OMPTTargetDataOp.from_native(defi["optype"], nil)}"
  s << ', '
  s << "src_addr: #{"0x%016x" % defi["src_addr"]}"
  s << ', '
  s << "src_device_num: #{defi["src_device_num"]}"
  s << ', '
  s << "dest_addr: #{"0x%016x" % defi["dest_addr"]}"
  s << ', '
  s << "dest_device_num: #{defi["dest_device_num"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_data_op"] = lambda { |defi|
  s = "{ "
  s << "target_id: #{defi["target_id"]}"
  s << ', '
  s << "host_op_id: #{defi["host_op_id"]}"
  s << ', '
  s << "optype: #{OMP::OMPTTargetDataOp.from_native(defi["optype"], nil)}"
  s << ', '
  s << "src_addr: #{"0x%016x" % defi["src_addr"]}"
  s << ', '
  s << "src_device_num: #{defi["src_device_num"]}"
  s << ', '
  s << "dest_addr: #{"0x%016x" % defi["dest_addr"]}"
  s << ', '
  s << "dest_device_num: #{defi["dest_device_num"]}"
  s << ', '
  s << "bytes: #{defi["bytes"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_emi"] = lambda { |defi|
  s = "{ "
  s << "kind: #{OMP::OMPTTarget.from_native(defi["kind"], nil)}"
  s << ', '
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "device_num: #{defi["device_num"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "target_task_data: #{"0x%016x" % defi["target_task_data"]}"
  s << ', '
  s << "target_data: #{"0x%016x" % defi["target_data"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target"] = lambda { |defi|
  s = "{ "
  s << "kind: #{OMP::OMPTTarget.from_native(defi["kind"], nil)}"
  s << ', '
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "device_num: #{defi["device_num"]}"
  s << ', '
  s << "task_data: #{"0x%016x" % defi["task_data"]}"
  s << ', '
  s << "target_id: #{defi["target_id"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_map_emi"] = lambda { |defi|
  s = "{ "
  s << "target_data: #{"0x%016x" % defi["target_data"]}"
  s << ', '
  s << "nitems: #{defi["nitems"]}"
  s << ', '
  s << "host_addr: #{"0x%016x" % defi["host_addr"]}"
  s << ', '
  s << "device_addr: #{"0x%016x" % defi["device_addr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "mapping_flags: #{"0x%016x" % defi["mapping_flags"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_map"] = lambda { |defi|
  s = "{ "
  s << "target_id: #{defi["target_id"]}"
  s << ', '
  s << "nitems: #{defi["nitems"]}"
  s << ', '
  s << "host_addr: #{"0x%016x" % defi["host_addr"]}"
  s << ', '
  s << "device_addr: #{"0x%016x" % defi["device_addr"]}"
  s << ', '
  s << "bytes: #{"0x%016x" % defi["bytes"]}"
  s << ', '
  s << "mapping_flags: #{"0x%016x" % defi["mapping_flags"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << ', '
  s << "host_addr_vals: [ #{defi["host_addr_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "device_addr_vals: [ #{defi["device_addr_vals"].collect { |v| "0x%016x" % v }.join(", ")} ]"
  s << ', '
  s << "bytes_vals: #{defi["bytes_vals"]}"
  s << ', '
  s << "mapping_flags_vals: #{defi["mapping_flags_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_submit"] = lambda { |defi|
  s = "{ "
  s << "target_id: #{defi["target_id"]}"
  s << ', '
  s << "host_op_id: #{defi["host_op_id"]}"
  s << ', '
  s << "requested_num_teams: #{defi["requested_num_teams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_target_submit_emi"] = lambda { |defi|
  s = "{ "
  s << "endpoint: #{OMP::OMPTScopeEndpoint.from_native(defi["endpoint"], nil)}"
  s << ', '
  s << "target_data: #{"0x%016x" % defi["target_data"]}"
  s << ', '
  s << "host_op_id: #{"0x%016x" % defi["host_op_id"]}"
  s << ', '
  s << "requested_num_teams: #{defi["requested_num_teams"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_control_tool"] = lambda { |defi|
  s = "{ "
  s << "ompResult: #{defi["ompResult"]}"
  s << ', '
  s << "command: #{defi["command"]}"
  s << ', '
  s << "modifier: #{defi["modifier"]}"
  s << ', '
  s << "arg: #{"0x%016x" % defi["arg"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
$event_lambdas["lttng_ust_ompt:ompt_callback_error"] = lambda { |defi|
  s = "{ "
  s << "severity: #{OMP::OMPTSeverity.from_native(defi["severity"], nil)}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "length: #{defi["length"]}"
  s << ', '
  s << "codeptr_ra: #{"0x%016x" % defi["codeptr_ra"]}"
  s << " }"
}
