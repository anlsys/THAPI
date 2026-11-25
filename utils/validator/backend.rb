# frozen_string_literal: true
require_relative 'framework'
require 'find'

module THAPIValidator
  # Registration is explicit. The framework knows no providers, result codes,
  # or programming-model semantics until an adapter is registered by its owner.
  module Backends
    @factories = {}
    @aliases = {}
    class << self
      def register(name, aliases: [], &factory)
        raise ArgumentError, 'a backend factory is required' unless factory
        names = [name, *aliases].map(&:to_s)
        raise ArgumentError, 'backend names must be nonempty and unique' if names.any?(&:empty?) || names.uniq.size != names.size
        names.each { |n| raise ArgumentError, "backend already registered: #{n}" if @aliases.key?(n) }
        @factories[names.first] = factory
        names.each { |n| @aliases[n] = names.first }
      end

      def names
        @factories.keys.sort
      end

      def build(name, **options)
        canonical = @aliases[name.to_s]
        unless canonical
          raise ConfigurationError, "backend #{name.inspect} is not registered; available: #{names.join(', ')}. Load a backend plugin explicitly."
        end
        object = @factories.fetch(canonical).call(**options)
        unless object.respond_to?(:consume) && object.respond_to?(:finalize)
          raise ConfigurationError, "backend #{canonical} must implement consume and finalize"
        end
        object
      end
    end
  end

  Event = Struct.new(:name, :context, :payload, keyword_init: true) do
    def provider
      name.split(':', 2).first
    end
  end

  # Shared trace consumer. Adapters interpret normalized events in on_event.
  # This class does not infer API phases.
  class Backend
    def consume
      lambda do |iterator, _|
        iterator.next_messages.each do |message|
          next unless message.type == :BT_MESSAGE_TYPE_EVENT
          event = message.event
          context = (event.get_common_context_field&.value || {}).dup
          context['hostname'] = event.stream.trace.get_environment_entry_value_by_name('hostname')&.value
          context['timestamp'] = begin
            message.get_default_clock_snapshot.ns_from_origin
          rescue StandardError
            nil
          end
          on_event(Event.new(name: event.name, context: context, payload: event.payload_field&.value || {}))
        end
      end
    end

    # Ignore events unless a subclass provides a handler.
    def on_event(_event)
    end

    def finalize
    end
  end

  # Shared API rule lifecycle. Model-specific hooks retain ownership of call
  # frames, locking, result interpretation, and post-call bookkeeping.
  class APIBackend < Backend
    def configure_rules(registry, backend:, default_path: nil, user_path: nil)
      @rules = Rules.new(registry, backend: backend,
                         default_path: default_path, user_path: user_path)
    end

    def rule_environment(context, payload, output: {}, operation: {})
      frame = current_call(context)
      { state: self, context: context, payload: payload,
        input: frame ? frame.params : {}, output: output,
        local: frame ? frame.locals : {}, operation: operation }
    end

    def dispatch_api_entry(context, payload)
      begin_api_call(context, payload)
      before_entry_rules(context, payload)
      @rules.dispatch(context.fetch('api'), :entry, rule_environment(context, payload))
    end

    def dispatch_api_exit(context, payload)
      before_exit_rules(context, payload)
      env = rule_environment(context, payload, output: payload)
      @rules.dispatch(context.fetch('api'), successful_result?(payload) ? :success : :error, env)
      @rules.dispatch(context.fetch('api'), :exit, env)
      finish_api_call(context)
    end

    def dispatch_operation(kind, context, operation)
      @rules.execute(kind, state: self, context: context, payload: {},
                     input: {}, output: {}, local: {}, operation: operation)
    end

    def finalize_rules
      @rules.finalize(state: self, context: {}, payload: {}, input: {},
                      output: {}, local: {}, operation: {})
    end

    def before_entry_rules(_context, _payload); end
    def before_exit_rules(_context, _payload); end

    def current_call(_context)
      raise NotImplementedError, 'implement call-frame lookup'
    end

    def begin_api_call(_context, _payload)
      raise NotImplementedError, 'implement call-frame creation'
    end

    def finish_api_call(_context)
      raise NotImplementedError, 'implement call-frame completion'
    end

    def successful_result?(_payload)
      raise NotImplementedError, 'implement result-code interpretation'
    end
  end

  module TraceGraph
    def self.run(locations, sink, live: false)
      require 'babeltrace2'
      graph = BT2::BTGraph.new
      ctf = BT2::BTPlugin.find('ctf')
      source = ctf.get_source_component_class_by_name(live ? 'lttng-live' : 'fs')
      if live
        inputs = locations.uniq
      else
        locations.each { |path| raise ConfigurationError, "no such file or directory: #{path}" unless File.exist?(path) }
        inputs = Find.find(*locations).select { |p| File.file?(p) && File.basename(p) == 'metadata' }
                     .map { |p| File.realpath(File.dirname(p)) }.uniq.select do |path|
          query = BT2::BTQueryExecutor.new(component_class: source,
            object_name: 'babeltrace.support-info', params: {'input' => path, 'type' => 'directory'})
          query.query.value['weight'] > 0.5
        end
      end
      raise ConfigurationError, 'no LTTng trace found' if inputs.empty?
      sources = inputs.each_with_index.map do |input, i|
        params = {'inputs' => [input]}
        params['session-not-found-action'] = 'end' if live
        graph.add_component(source, "trace_#{i}", params: params)
      end
      mux = graph.add_component(BT2::BTPlugin.find('utils').get_filter_component_class_by_name('muxer'), 'mux')
      sources.flat_map(&:output_ports).each_with_index { |port, i| graph.connect_ports(port, mux.input_port(i)) }
      terminal = graph.add_simple_sink('thapi_validator', sink.consume)
      graph.connect_ports(mux.output_port(0), terminal.input_port(0))
      graph.run
      result = sink.finalize
      result.is_a?(Integer) ? result : 0
    end
  end
end
