# frozen_string_literal: true
require 'yaml'

# API-independent rule dispatch. A backend supplies a registry and an environment;
# the core never accesses Level Zero objects or trace fields directly.
module THAPIValidator
  class ConfigurationError < StandardError; end

  class Registry
    def initialize
      @operations = {}
    end

    def register(kind, name, required: [], optional: [], &implementation)
      key = [kind.to_s, name.to_s]
      raise ArgumentError, "duplicate operation #{key.join(':')}" if @operations.key?(key)
      @operations[key] = [required, optional, implementation]
    end

    def fetch(kind, name)
      @operations.fetch([kind.to_s, name.to_s]) do
        raise ConfigurationError, "unknown #{kind} #{name.inspect}"
      end
    end
  end

  class Rules
    attr_reader :executed_rules
    PHASES = %w[entry success error exit].freeze
    ROOTS = %w[input output context local operation event payload].freeze

    def initialize(registry, default_path: nil, backend:, user_path: nil, document: nil)
      @registry = registry
      @backend = backend
      @apis = {}
      @operations = {}
      @finalize = []
      @events = {}
      @executed_rules = 0
      [default_path, user_path].compact.each { |path| load_file(path) }
      load_document(document, "<rules>") if document
    end

    def dispatch(api, phase, env)
      run(@apis.fetch("*", {}).fetch(phase.to_s, []), env) unless api == "*"
      run(@apis.fetch(api, {}).fetch(phase.to_s, []), env)
    end

    def execute(kind, env)
      run(@operations.fetch(kind.to_s, []), env)
    end

    def finalize(env)
      run(@finalize, env)
    end

    def event(name, env)
      @events.each { |pattern, steps| run(steps, env) if File.fnmatch?(pattern, name) }
    end

    def add_document(document, source: '<rules>')
      load_document(document, source)
      self
    end

    def configured?
      !@apis.empty? || !@events.empty? || !@finalize.empty?
    end

    private

    def fail_config(message)
      raise ConfigurationError, message
    end

    def mapping(value, where)
      fail_config("#{where}: expected a mapping") unless value.is_a?(Hash)
      value
    end

    def keys(value, allowed, where)
      mapping(value, where)
      extra = value.keys - allowed
      fail_config("#{where}: unknown keys #{extra.inspect}") unless extra.empty?
    end

    def load_file(path)
      doc = YAML.safe_load(File.read(path), permitted_classes: [], permitted_symbols: [], aliases: false)
      load_document(doc, path)
    rescue ConfigurationError, Psych::Exception, SystemCallError => e
      raise ConfigurationError, "#{path}: #{e.message}"
    end

    def load_document(doc, path)
      keys(doc, %w[schema_version backend apis operations events finalize], path)
      fail_config('schema_version must be 1') unless doc['schema_version'] == 1
      fail_config("backend must be #{@backend}") unless doc['backend'] == @backend
      mapping(doc.fetch('apis', {}), 'apis').each do |api, phases|
        fail_config('API names must be strings') unless api.is_a?(String)
        keys(phases, PHASES, api)
        phases.each do |phase, steps|
          compiled = compile_steps(steps, "#{api}.#{phase}", phase)
          ((@apis[api] ||= {})[phase] ||= []).concat(compiled)
        end
      end
      mapping(doc.fetch('operations', {}), 'operations').each do |kind, steps|
        (@operations[kind] ||= []).concat(compile_steps(steps, "operations.#{kind}", 'execute'))
      end
      mapping(doc.fetch('events', {}), 'events').each do |pattern, steps|
        fail_config('Event patterns must be strings') unless pattern.is_a?(String)
        (@events[pattern] ||= []).concat(compile_steps(steps, "events.#{pattern}", 'event'))
      end
      @finalize.concat(compile_steps(doc.fetch('finalize', []), 'finalize', 'finalize'))
    rescue ConfigurationError, Psych::Exception, SystemCallError => e
      raise ConfigurationError, "#{path}: #{e.message}"
    end

    def compile_steps(steps, where, phase)
      fail_config("#{where}: expected a list") unless steps.is_a?(Array)
      steps.each_with_index.map do |step, i|
        location = "#{where}[#{i}]"
        keys(step, %w[check action with when save_as], location)
        kinds = %w[check action].select { |k| step.key?(k) }
        fail_config("#{location}: specify exactly one check or action") unless kinds.size == 1
        operation = compile_operation(kinds.first, step[kinds.first], step.fetch('with', {}), location, phase)
        predicate = nil
        if step.key?('when')
          condition = step['when']
          keys(condition, %w[predicate with], location)
          predicate = compile_operation('predicate', condition['predicate'], condition.fetch('with', {}), location, phase)
        end
        save = step['save_as']
        fail_config("#{location}: save_as requires an action and a nonempty string") if save &&
          (kinds.first != 'action' || !save.is_a?(String) || save.empty?)
        [operation, predicate, save]
      end
    end

    def compile_operation(kind, name, args, where, phase)
      required, optional, implementation = @registry.fetch(kind, name)
      mapping(args, where)
      missing = required - args.keys
      extra = args.keys - required - optional
      fail_config("#{where}: missing parameters #{missing.inspect}") unless missing.empty?
      fail_config("#{where}: unknown parameters #{extra.inspect}") unless extra.empty?
      validate_references(args, phase, where)
      [implementation, args]
    rescue ConfigurationError => e
      raise ConfigurationError, "#{where}: #{e.message}"
    end

    def validate_references(value, phase, where)
      case value
      when Hash
        if value.key?('ref')
          keys(value, %w[ref], where)
          ref = value['ref']
          fail_config("#{where}: invalid reference #{ref.inspect}") unless ref.is_a?(String) &&
            ROOTS.include?(ref.split('.').first) && ref.split('.').size > 1
          fail_config("#{where}: output unavailable at entry") if phase == 'entry' && ref.start_with?('output.')
          if %w[execute finalize].include?(phase) && %w[input output].include?(ref.split('.').first)
            fail_config("#{where}: API inputs/outputs unavailable during #{phase}; use operation parameters")
          end
        else
          value.each_value { |v| validate_references(v, phase, where) }
        end
      when Array
        value.each { |v| validate_references(v, phase, where) }
      end
    end

    def resolve(value, env)
      case value
      when Hash
        if value.key?('ref')
          parts = value['ref'].split('.')
          current = env.fetch(parts.shift.to_sym)
          parts.each do |part|
            unless current.is_a?(Hash) && (current.key?(part) || current.key?(part.to_sym))
              raise ConfigurationError, "unavailable reference #{value['ref']}"
            end
            current = current.key?(part) ? current[part] : current[part.to_sym]
          end
          current
        else
          value.transform_values { |v| resolve(v, env) }
        end
      when Array
        value.map { |v| resolve(v, env) }
      else
        value
      end
    end

    def invoke(operation, env)
      implementation, args = operation
      implementation.call(env, resolve(args, env))
    end

    def run(steps, env)
      steps.each do |operation, predicate, save|
        next if predicate && !invoke(predicate, env)
        @executed_rules += 1
        result = invoke(operation, env)
        env.fetch(:local)[save] = result if save
      end
    end
  end
end
