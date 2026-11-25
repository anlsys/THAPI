# Run with the same Ruby/dependency environment as thapi_validator.
require 'tmpdir'
require 'stringio'
$LOAD_PATH.unshift(File.expand_path('../../..', __dir__))
DATADIR = File.expand_path('../../..', __dir__) unless defined?(DATADIR)
require 'ze/validator/state_object'

$count = 0
def assert(value, message = 'assertion failed')
  raise message unless value
  $count += 1
end

def rejected
  begin
    yield
  rescue ZEValidator::ConfigurationError
    $count += 1
    return
  end
  raise 'invalid configuration was accepted'
end

Dir.mktmpdir do |dir|
  base = File.join(dir, 'base.yaml')
  user = File.join(dir, 'user.yaml')
  registry = ZEValidator::Registry.new
  log = []
  registry.register(:action, 'record', required: %w[value]) { |_, a| log << a['value']; a['value'] }
  registry.register(:predicate, 'yes') { |_, _| true }
  registry.register(:predicate, 'no') { |_, _| false }
  File.write(base, <<~YAML)
    schema_version: 1
    backend: test
    apis:
      create:
        entry:
          - action: record
            with: {value: {ref: input.handle}}
            save_as: saved
        success:
          - action: record
            with: {value: {ref: local.saved}}
          - action: record
            when: {predicate: no}
            with: {value: skipped}
          - action: record
            when: {predicate: yes}
            with: {value: {ref: output.handle}}
        exit:
          - action: record
            with: {value: exit}
    operations:
      copy:
        - action: record
          with: {value: {ref: operation.pointer}}
    finalize:
      - action: record
        with: {value: final}
  YAML
  # Quote predicate identifiers: YAML 1.1 interprets unquoted yes/no as booleans.
  File.write(base, File.read(base).gsub('predicate: no', 'predicate: "no"').gsub('predicate: yes', 'predicate: "yes"'))
  File.write(user, "schema_version: 1\nbackend: test\napis:\n  create:\n    entry:\n      - action: record\n        with: {value: additional}\n")
  rules = ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user)
  env = {input: {'handle'=>7}, output: {'handle'=>8}, local: {}, operation: {'pointer'=>9}}
  rules.dispatch('create', :entry, env)
  rules.dispatch('create', :success, env)
  rules.dispatch('create', :exit, env)
  rules.execute(:copy, env)
  rules.finalize(env)
  assert(log == [7, 'additional', 7, 8, 'exit', 9, 'final'], log.inspect)
  ['unknown', 'record'].each do |operation|
    File.write(user, "schema_version: 1\nbackend: test\napis:\n  x:\n    entry:\n      - action: #{operation}\n")
    rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
  end
  ["{value: {ref: output.handle}}", "{typo: 1}"].each do |args|
    File.write(user, "schema_version: 1\nbackend: test\napis:\n  x:\n    entry:\n      - action: record\n        with: #{args}\n")
    rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
  end
  File.write(user, "schema_version: 2\nbackend: test\n")
  rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
  File.write(user, "schema_version: 1\nbackend: test\napis:\n  x:\n    entyr: []\n")
  rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
  File.write(user, "--- !ruby/object:Object {}\n")
  rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
  File.write(user, "schema_version: 1\nbackend: test\noperations:\n  copy:\n    - action: record\n      with: {value: {ref: input.handle}}\n")
  rejected { ZEValidator::Rules.new(registry, default_path: base, backend: 'test', user_path: user) }
end

state = StateObject.new
out = StringIO.new
state.instance_variable_set(:@reporter, ZEValidator::Reporter.new(out: out))
ctx = {'hostname'=>'test', 'vpid'=>1, 'vtid'=>2, 'api'=>'zeCommandListAppendMemoryCopy'}
def call_api(state, context, api, input, output = {'zeResult'=>0})
  ctx = context.merge('api'=>api)
  state.on_entry([nil, api], ctx['hostname'], ctx, input)
  state.on_exit([nil, api], ctx['hostname'], ctx, output)
end
process = state.get_process(ctx)
owner = ZEModel::Context.new(10, nil, nil)
process.contexts[10] = owner
list = ZEModel::CommandList.new(20, owner, nil, nil, nil)
process.command_lists[20] = list
owner.command_lists[20] = list
allocation = ZEModel::MemoryAllocation.new(100, owner, 8, nil, 'host')
owner.memory_allocations.insert(allocation)
# OOB at entry remains detectable even if the call never returns.
state.on_entry([nil, ctx['api']], 'test', ctx,
  {'hCommandList'=>20, 'dstptr'=>100, 'srcptr'=>0, 'size'=>16, 'hSignalEvent'=>0})
assert(out.string.include?('out_of_bounds_copy'))
assert(out.string.include?('null_copy_pointer'))
# Complete the call, then exercise successful append recording.
state.on_exit([nil, ctx['api']], 'test', ctx, {'zeResult'=>0})
assert(list.ops.size == 1)
# Free is applied at entry and rolled back on an unsuccessful return.
free_ctx = ctx.merge('api'=>'zeMemFree')
state.on_entry([nil, 'zeMemFree'], 'test', free_ctx, {'hContext'=>10, 'ptr'=>100})
assert(owner.memory_allocations[100].nil?)
state.on_exit([nil, 'zeMemFree'], 'test', free_ctx, {'zeResult'=>0x78000001})
assert(owner.memory_allocations[100] == allocation)
call_api(state, ctx, 'zeMemFree', {'hContext'=>10, 'ptr'=>100})
# Deferred checks still detect UAF after memory was freed.
state.run_deferred_list(ctx, list.ops.dup, 'test list')
assert(out.string.include?('use_after_free'))
# Cross-list cycle and unsignaled waits still reach the same final checks.
pool = ZEModel::EventPool.new(30, owner, {count: 2})
process.events[40] = ZEModel::Event.new(40, pool, {})
process.events[41] = ZEModel::Event.new(41, pool, {})
state.run_deferred_list(ctx, [ZEModel::RecordedOp.new(:signal, waits: [40], signal: 41)], 'A')
state.run_deferred_list(ctx, [ZEModel::RecordedOp.new(:signal, waits: [41], signal: 40)], 'B')
state.finalize
assert(out.string.include?('circular_event_dependency'))
assert(out.string.include?('unsignaled_wait_event'))
assert(out.string.include?('object_leak'))
assert(process.threads[2].call_stack.empty?)
# User rules invoke reusable backend checks and retain the default callbacks.
Dir.mktmpdir do |dir|
  custom = File.join(dir, 'custom.yaml')
  File.write(custom, <<~YAML)
    schema_version: 1
    backend: level_zero
    apis:
      customCopy:
        entry:
          - check: check_null_copy_ptr
            with:
              endpoints:
                source: {ref: input.src}
  YAML
  configured = StateObject.new(rules: custom, report_leaks: false)
  output = StringIO.new
  configured.instance_variable_set(:@reporter, ZEValidator::Reporter.new(out: output))
  call_api(configured, ctx, 'customCopy', {'src'=>0})
  assert(output.string.include?('null_copy_pointer'))
  assert(output.string.include?('customCopy: source pointer is nullptr'))
  assert(configured.get_thread(ctx).call_stack.empty?)
  # An omitted API argument must not make actual check inputs optional.
  missing = File.join(dir, 'missing.yaml')
  File.write(missing, File.read(custom).sub('endpoints:', 'typo:'))
  rejected { StateObject.new(rules: missing) }
  # Existing YAML with an explicit API argument still works.
  legacy = File.join(dir, 'legacy.yaml')
  legacy_document = YAML.safe_load(File.read(custom))
  legacy_document['apis']['customCopy']['entry'].first['with']['api'] = 'customCopy'
  File.write(legacy, YAML.dump(legacy_document))
  compatible = StateObject.new(rules: legacy, report_leaks: false)
  legacy_output = StringIO.new
  compatible.instance_variable_set(:@reporter, ZEValidator::Reporter.new(out: legacy_output))
  call_api(compatible, ctx, 'customCopy', {'src'=>0})
  assert(legacy_output.string == output.string)
  # The inferred API follows each rule's trigger, not the first API used.
  other = File.join(dir, 'other.yaml')
  File.write(other, File.read(custom).sub('customCopy:', 'otherCopy:'))
  another = StateObject.new(rules: other, report_leaks: false)
  other_output = StringIO.new
  another.instance_variable_set(:@reporter, ZEValidator::Reporter.new(out: other_output))
  call_api(another, ctx, 'otherCopy', {'src'=>0})
  assert(other_output.string.include?('otherCopy: source pointer is nullptr'))
  # Nested calls have separate local values and restore the outer frame.
  outer = ctx.merge('api'=>'outer')
  inner = ctx.merge('api'=>'inner')
  configured.on_entry([nil, 'outer'], 'test', outer, {})
  configured.get_last_entry(outer).locals['value'] = 'outer'
  configured.on_entry([nil, 'inner'], 'test', inner, {})
  assert(configured.get_last_entry(inner).locals.empty?)
  configured.on_exit([nil, 'inner'], 'test', inner, {'zeResult'=>0})
  assert(configured.get_last_entry(outer).locals['value'] == 'outer')
  configured.on_exit([nil, 'outer'], 'test', outer, {'zeResult'=>0})
end
puts "#{ $count } assertions passed"
