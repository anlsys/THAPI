# Run with the project's Ruby/gem environment; no GPU is required.
require 'tmpdir'
require 'stringio'
require 'json'
$LOAD_PATH.unshift(File.expand_path('../../..', __dir__))
DATADIR = File.expand_path('../../..', __dir__) unless defined?(DATADIR)
# Optional baseline implementation for before/after diagnostic comparisons.
require ENV.fetch('THAPI_VALIDATOR_STATE_FILE', 'ze/validator/state_object')

def assert(value, message)
  raise message unless value
end

Value = Struct.new(:value)
Trace = Struct.new(:hostname) do
  def get_environment_entry_value_by_name(_name) = Value.new(hostname)
end
Stream = Struct.new(:trace)
RawEvent = Struct.new(:name, :context, :payload) do
  def get_common_context_field = Value.new(context)
  def payload_field = Value.new(payload)
  def stream = Stream.new(Trace.new('test'))
end
Message = Struct.new(:event) do
  def type = :BT_MESSAGE_TYPE_EVENT
  def get_default_clock_snapshot = Struct.new(:ns_from_origin).new(123)
end
Iterator = Struct.new(:next_messages)

def emit(state, name, payload = {}, tid: 2)
  raw = RawEvent.new(name, {'vpid'=>1, 'vtid'=>tid}, payload)
  # Non-event messages must be ignored.
  other = Struct.new(:type).new(:BT_MESSAGE_TYPE_STREAM_BEGINNING)
  state.consume.call(Iterator.new([other, Message.new(raw)]), nil)
end

def api(state, name, input = {}, output = {'zeResult'=>0}, tid: 2)
  emit(state, "lttng_ust_ze:#{name}_entry", input, tid: tid)
  emit(state, "lttng_ust_ze:#{name}_exit", output, tid: tid)
end

Dir.mktmpdir do |dir|
  custom = File.join(dir, 'custom.yaml')
  File.write(custom, <<~YAML)
    schema_version: 1
    backend: level_zero
    apis:
      zCustom:
        entry:
          - check: check_null_copy_ptr
            with:
              endpoints:
                source: {ref: input.ptr}
  YAML
  csv = File.join(dir, 'findings.csv')
  state = ZEValidator::StateObject.new(rules: custom, csv_export: csv)
  out = StringIO.new
  state.instance_variable_set(:@reporter, ZEValidator::Reporter.new(out: out))
  ctx = {'hostname'=>'test', 'vpid'=>1, 'vtid'=>2, 'api'=>'zeCommandListAppendMemoryCopy'}
  process = state.get_process(ctx)
  owner = ZEModel::Context.new(10, nil, nil)
  process.contexts[10] = owner
  list = ZEModel::CommandList.new(20, owner, nil, nil, nil)
  process.command_lists[20] = list
  owner.command_lists[20] = list
  allocation = ZEModel::MemoryAllocation.new(100, owner, 8, nil, 'host')
  owner.memory_allocations.insert(allocation)

  # Ignored providers must not create calls.
  emit(state, 'lttng_ust_cuda:cuInit_entry')
  assert(process.threads[2].call_stack.empty?, 'foreign event changed call stack')
  # Original initialization and deprecation checks still run.
  api(state, 'zesRasGetConfig', {}, {'zeResult'=>0x78000001})
  copy = {'hCommandList'=>20, 'dstptr'=>100, 'srcptr'=>0, 'size'=>16, 'hSignalEvent'=>0}
  emit(state, 'lttng_ust_ze:zeCommandListAppendMemoryCopy_entry', copy)
  # A second thread accesses the same locked object.
  api(state, 'zeCommandListAppendMemoryCopy', copy, {'zeResult'=>0}, tid: 3)
  emit(state, 'lttng_ust_ze:zeCommandListAppendMemoryCopy_exit', {'zeResult'=>0})
  assert(list.ops.size == 2, 'successful append lost')
  # Rollback must retain the same allocation object.
  api(state, 'zeMemFree', {'hContext'=>10, 'ptr'=>100}, {'zeResult'=>0x78000001})
  assert(owner.memory_allocations[100].equal?(allocation), 'failed free was not rolled back')
  api(state, 'zeMemFree', {'hContext'=>10, 'ptr'=>100})
  state.run_deferred_list(ctx, list.ops.dup, 'recorded copies')

  # Nesting and per-call locals survive the shared entry/exit lifecycle.
  emit(state, 'lttng_ust_ze:zOuter_entry', {'saved'=>42})
  state.get_last_entry(ctx).locals['saved'] = 'outer'
  api(state, 'zCustom', {'ptr'=>0})
  assert(state.get_last_entry(ctx).params['saved'] == 42, 'outer input lost')
  assert(state.get_last_entry(ctx).locals['saved'] == 'outer', 'outer local lost')
  emit(state, 'lttng_ust_ze:zOuter_exit', {'zeResult'=>0})
  assert(process.threads.values.all? { |thread| thread.call_stack.empty? }, 'finished calls remain')

  # Decode both queue groups from a real FFI layout.
  size = ZE::ZECommandQueueGroupProperties.size
  memory = FFI::MemoryPointer.new(:char, size * 2)
  2.times do |i|
    group = ZE::ZECommandQueueGroupProperties.new(memory + i * size)
    group[:numQueues] = i + 1
  end
  emit(state, 'lttng_ust_ze_properties:command_queue_group',
       {'hDevice'=>7, 'pCount'=>2, 'pGroupProperties_vals'=>memory.read_string_length(size * 2)})
  assert(state.device_properties[7].values.map { |g| g['numQueues'] } == [1, 2], 'queue groups lost')

  pool = ZEModel::EventPool.new(30, owner, {count: 2})
  process.events[40] = ZEModel::Event.new(40, pool, {})
  process.events[41] = ZEModel::Event.new(41, pool, {})
  state.run_deferred_list(ctx, [ZEModel::RecordedOp.new(:signal, waits: [40], signal: 41)], 'A')
  state.run_deferred_list(ctx, [ZEModel::RecordedOp.new(:signal, waits: [41], signal: 40)], 'B')
  emit(state, 'lttng_ust_ze:zUnfinished_entry')
  state.finalize
  expected = %w[init_not_called deprecated_api out_of_bounds_copy null_copy_pointer
                concurrent_object_access use_after_free circular_event_dependency
                unsignaled_wait_event object_leak api_never_returned]
  expected.each { |id| assert(out.string.include?(id), "missing diagnostic: #{id}") }
  assert(File.size?(csv), 'CSV not exported')
  # A deterministic artifact makes parity comparisons cover complete messages,
  # summary counts, CSV output, and decoded properties, not only error presence.
  puts JSON.generate(diagnostics: out.string, csv: File.read(csv),
                     properties: state.device_properties)
end
