# frozen_string_literal: true
require 'tmpdir'
require 'open3'
require_relative '../backend'
root = File.expand_path('../../..', __dir__)
$LOAD_PATH.unshift(File.join(root, 'backends'), File.join(root, 'build', 'ici', 'share'))
DATADIR = File.join(root, 'backends') unless defined?(DATADIR)
require 'ze/validator/backend'

$count = 0
def assert(value, message = 'assertion failed')
  raise message unless value
  $count += 1
end

def rejected(error = THAPIValidator::ConfigurationError)
  yield
rescue error
  $count += 1
else
  raise 'expected rejection'
end

# Registration alone must not load any Level Zero SDK or semantic state.
assert(THAPIValidator::Backends.names == ['level_zero'])
assert($LOADED_FEATURES.none? { |p| p.end_with?('/ze_library.rb') })
rejected { THAPIValidator::Backends.build('cuda') }
rejected { THAPIValidator::Backends.build('mpi') }
rejected(ArgumentError) { THAPIValidator::Backends.register('level_zero') { Object.new } }

class ProgrammedBackend < THAPIValidator::Backend
  attr_reader :errors, :phases
  def initialize(rules: nil, **_options)
    @errors, @phases = [], []
    registry = THAPIValidator::Registry.new
    registry.register(:check, 'pointer.non_null', required: %w[value]) do |env, args|
      @errors << "#{env[:context]['api']}: null pointer" if args['value'].nil? || args['value'] == 0
    end
    registry.register(:action, 'record_phase', required: %w[phase]) { |_, a| @phases << a['phase'] }
    @rules = THAPIValidator::Rules.new(registry, backend: 'example', user_path: rules)
  end

  def on_event(event)
    # Event naming and result interpretation belong to the programmed backend.
    return unless event.provider == 'lttng_ust_example'
    match = event.name.match(/:(.*)_(entry|exit)\z/)
    return unless match
    api, phase = match[1], match[2]
    context = event.context.merge('api' => api)
    env = {state: self, context: context, payload: event.payload,
           input: event.payload, output: event.payload, local: {}, operation: {}, event: {'name' => event.name}}
    if phase == 'entry'
      @rules.dispatch(api, :entry, env)
    else
      @rules.dispatch(api, event.payload['status'] == 7 ? :success : :error, env)
      @rules.dispatch(api, :exit, env)
    end
    @rules.event(event.name, env)
  end

  def finalize
    @rules.finalize(state: self, context: {}, payload: {}, input: {}, output: {}, local: {}, operation: {}, event: {})
    @errors.empty? ? 0 : 1
  end
end

Dir.mktmpdir do |dir|
  rules = File.join(dir, 'rules.yaml')
  File.write(rules, <<~YAML)
    schema_version: 1
    backend: example
    apis:
      '*':
        exit:
          - action: record_phase
            with: {phase: exit}
      ExampleCall:
        entry:
          - check: pointer.non_null
            with:
              value: {ref: input.buffer}
        success:
          - action: record_phase
            with: {phase: success}
        error:
          - action: record_phase
            with: {phase: error}
    events:
      'lttng_ust_example:*_entry':
        - action: record_phase
          with: {phase: raw_event}
  YAML
  THAPIValidator::Backends.register('example', aliases: ['example_alias']) do |**options|
    ProgrammedBackend.new(**options)
  end
  programmed = THAPIValidator::Backends.build('example_alias', rules: rules)
  context = {'hostname' => 'host', 'vpid' => 1, 'vtid' => 2}
  make_event = ->(name, payload) { THAPIValidator::Event.new(name: name, context: context, payload: payload) }
  programmed.on_event(make_event.call('lttng_ust_example:ExampleCall_entry', {'buffer' => 0}))
  programmed.on_event(make_event.call('lttng_ust_example:ExampleCall_exit', {'status' => 7}))
  programmed.on_event(make_event.call('lttng_ust_example:ExampleCall_exit', {'status' => -1}))
  assert(programmed.finalize == 1)
  assert(programmed.errors == ['ExampleCall: null pointer'])
  assert(programmed.phases == %w[raw_event success exit error exit], programmed.phases.inspect)
  assert(THAPIValidator::Backends.names == %w[example level_zero])
  assert(!THAPIValidator::Backends.names.include?('cuda'))
  THAPIValidator::Backends.register('invalid') { Object.new }
  rejected { THAPIValidator::Backends.build('invalid') }

  # The optional base class normalizes events without guessing their model/API.
  class RecordingBackend < THAPIValidator::Backend
    attr_reader :events
    def initialize = @events = []
    def on_event(event) = @events << event
    def finalize = 0
  end
  value = Struct.new(:value)
  trace = Object.new
  trace.define_singleton_method(:get_environment_entry_value_by_name) { |_| value.new('host') }
  raw = Object.new
  raw.define_singleton_method(:name) { 'arbitrary_provider:callback' }
  raw.define_singleton_method(:get_common_context_field) { value.new({'vpid' => 3, 'vtid' => 4}) }
  raw.define_singleton_method(:payload_field) { value.new({'data' => 12}) }
  raw.define_singleton_method(:stream) { Struct.new(:trace).new(trace) }
  message = Object.new
  message.define_singleton_method(:type) { :BT_MESSAGE_TYPE_EVENT }
  message.define_singleton_method(:event) { raw }
  message.define_singleton_method(:get_default_clock_snapshot) { Struct.new(:ns_from_origin).new(99) }
  iterator = Object.new
  iterator.define_singleton_method(:next_messages) { [message] }
  recording = RecordingBackend.new
  recording.consume.call(iterator, nil)
  normalized = recording.events.first
  assert(normalized.name == 'arbitrary_provider:callback')
  assert(normalized.provider == 'arbitrary_provider')
  assert(normalized.payload == {'data' => 12})
  assert(normalized.context == {'hostname' => 'host', 'vpid' => 3, 'vtid' => 4, 'timestamp' => 99})
  assert(!normalized.context.key?('api'))

  # Exercise the actual source launcher. The only built-in option is Level Zero.
  cli = File.join(dir, 'thapi_validator')
  text = File.read(File.join(root, 'backends/ze/validator/thapi_validator.in'))
  text.sub!(/^DATADIR = .*$/, 'DATADIR = ' + File.join(root, 'backends').inspect)
  File.write(cli, text)
  run = ->(*args) { Open3.capture3(RbConfig.ruby, '-I' + File.join(root, 'build/ici/share'), cli, *args) }
  stdout, stderr, status = run.call('--list-backends')
  assert(status.success? && stdout.strip == 'level_zero', stderr)
  stdout, stderr, status = run.call('--backend=cuda', '/nonexistent-trace')
  assert(!status.success? && stderr.include?('not registered'), stderr)
  # A user-written plugin is usable only after it is explicitly loaded.
  plugin = File.join(dir, 'plugin.rb')
  File.write(plugin, <<~CODE)
    class CountingBackend < THAPIValidator::Backend
      def initialize(**_options); @count = 0; end
      def on_event(_event); @count += 1; end
      def finalize; puts "custom event count=\#{@count}"; 0; end
    end
    THAPIValidator::Backends.register('example') { |**options| CountingBackend.new(**options) }
  CODE
  stdout, stderr, status = run.call('--plugin=' + plugin, '--list-backends')
  assert(status.success? && stdout.lines.map(&:strip) == %w[example level_zero], stderr)
  fixture = File.join(root, 'backends/mpi/validator/test/ctf_trace')
  if File.file?(File.join(fixture, 'metadata'))
    stdout, stderr, status = run.call('--plugin=' + plugin, '--backend=example', fixture)
    assert(status.success? && stdout.include?('custom event count=8'), stderr + stdout)
  end
end

# The default factory still constructs the complete existing ZE validator.
selected = THAPIValidator::Backends.build('ze', report_leaks: false)
assert(selected.is_a?(ZEValidator::StateObject))
assert(selected.is_a?(THAPIValidator::APIBackend))
assert(selected.method(:consume).owner == THAPIValidator::Backend)
assert(selected.method(:dispatch_api_entry).owner == THAPIValidator::APIBackend)
assert(selected.method(:dispatch_api_exit).owner == THAPIValidator::APIBackend)
assert(selected.method(:rule_environment).owner == THAPIValidator::APIBackend)
assert(selected.method(:dispatch_operation).owner == THAPIValidator::APIBackend)
assert(selected.method(:finalize_rules).owner == THAPIValidator::APIBackend)
assert(THAPIValidator::Registry.equal?(ZEValidator::Registry))
assert(THAPIValidator::Rules.equal?(ZEValidator::Rules))
puts "#{$count} backend-extension assertions passed"
