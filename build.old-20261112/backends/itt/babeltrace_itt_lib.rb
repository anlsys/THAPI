require_relative 'itt_library.rb'
$event_lambdas["lttng_ust_itt:__itt_domain_create"] = lambda { |defi|
  s = "{ "
  s << "ittResult: #{"0x%016x" % defi["ittResult"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_string_handle_create"] = lambda { |defi|
  s = "{ "
  s << "ittResult: #{"0x%016x" % defi["ittResult"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_task_begin"] = lambda { |defi|
  s = "{ "
  s << "domain: #{"0x%016x" % defi["domain"]}"
  s << ', '
  s << "taskid: #{defi["taskid"].size > 0 ? ITT::IttId.new(FFI::MemoryPointer.from_string(defi["taskid"])) : nil}"
  s << ', '
  s << "parentid: #{defi["parentid"].size > 0 ? ITT::IttId.new(FFI::MemoryPointer.from_string(defi["parentid"])) : nil}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "domain__nameA_val: #{defi["domain__nameA_val"].inspect}"
  s << ', '
  s << "name__strA_val: #{defi["name__strA_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_task_end"] = lambda { |defi|
  s = "{ "
  s << "domain: #{"0x%016x" % defi["domain"]}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_metadata_add"] = lambda { |defi|
  s = "{ "
  s << "domain: #{"0x%016x" % defi["domain"]}"
  s << ', '
  s << "id: #{defi["id"].size > 0 ? ITT::IttId.new(FFI::MemoryPointer.from_string(defi["id"])) : nil}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "type: #{ITT::IttMetadataType.from_native(defi["type"], nil)}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "key__strA_val: #{defi["key__strA_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_event_create"] = lambda { |defi|
  s = "{ "
  s << "ittResult: #{defi["ittResult"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "namelen: #{defi["namelen"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_event_start"] = lambda { |defi|
  s = "{ "
  s << "ittResult: #{defi["ittResult"]}"
  s << ', '
  s << "event: #{defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_itt:__itt_event_end"] = lambda { |defi|
  s = "{ "
  s << "ittResult: #{defi["ittResult"]}"
  s << ', '
  s << "event: #{defi["event"]}"
  s << " }"
}
$event_lambdas["lttng_ust_itt_metadata:metadata"] = lambda { |defi|
  s = "{ "
  s << "type: #{ITT::IttMetadataType.from_native(defi["type"], nil)}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "data: #{"0x%016x" % defi["data"]}"
  s << ', '
  s << "data_val: #{defi["data_val"].inspect}"
  s << " }"
}
