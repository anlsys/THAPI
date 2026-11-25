# Validator extension framework

**Level Zero remains the only built-in validator.** This change does not add CUDA,
MPI, OpenCL, HIP, or OpenMP validation. It separates the reusable infrastructure
from Level Zero so another programming model can be programmed later.

## Components

* `framework.rb`: model-independent registry, YAML loading/validation, references,
  conditions, API-phase rules, deferred-operation rules, and finalization rules.
* `backend.rb`: explicit backend registration, a normalized-event consumer,
  a shared API rule lifecycle, and Babeltrace graph construction.
* `backends/ze/validator/backend.rb`: the only built-in registration. It loads the
  existing Level Zero state model/checks when selected.
* `backends/ze/validator/framework.rb`: compatibility names for existing Level
  Zero rule extensions; its classes alias the shared implementation.

The framework has no provider catalog, inferred CUDA semantics, default generic
semantic checks, or automatic backend discovery from events. The existing Level
Zero callbacks, state updates, deferred scheduling, diagnostics, and YAML defaults
remain the Level Zero implementation. MPI is unchanged and is not registered here.

## Current usage

```
thapi_validator TRACE_DIRECTORY
thapi_validator --rules=custom.yaml TRACE_DIRECTORY
thapi_validator --list-backends
```

The built-in list contains only `level_zero`; `ze` is an alias for that name.
Selecting an unregistered backend fails explicitly. Existing Level Zero YAML
files remain valid. User rules still append to the Level Zero defaults.

## Programming a future backend

A new model needs its own event interpretation, state model, return-code policy,
checks/actions, diagnostics, and YAML API bindings. These cannot be inferred from
API names or borrowed from Level Zero. It can reuse the shared trace reader and
rule runner without modifying either one.

An adapter implements:

1. `consume`: a Babeltrace sink callback, compatible with the current Level Zero
   consumer; or inherit `THAPIValidator::Backend` and implement `on_event(event)`.
2. `finalize`: finish deferred work, perform final checks, and report findings.
   Return an integer to choose the command's exit status; other return values
   preserve the current successful-command behavior.

The base class supplies `event.name`, `event.provider`, `event.payload`,
and `event.context` (hostname, vpid/vtid when recorded, timestamp when available).
It does not guess which events are API calls or what success means. A backend
must preserve its own call stacks and saved entry arguments as appropriate.
Property/callback/sampling events can therefore be handled without pretending
they are Level Zero API calls.

### Shared API lifecycle

Level Zero now inherits `THAPIValidator::APIBackend < Backend`. It uses the shared
Babeltrace consumer instead of implementing a separate message loop.

Call `configure_rules` with the registry, backend name, default YAML path, and
optional user YAML path. In `on_event`, identify the API and phase, put the API
name in `context['api']`, and call `dispatch_api_entry(context, payload)` or
`dispatch_api_exit(context, payload)`.

Implement these model-specific hooks:

* `current_call(context)`: return the active frame, exposing `params` and `locals`.
* `begin_api_call(context, payload)`: push a frame containing saved inputs.
* `before_entry_rules(context, payload)`: optional work after pushing, before checks.
* `before_exit_rules(context, payload)`: optional work before success/error checks.
* `successful_result?(payload)`: interpret the programming model's return value.
* `finish_api_call(context)`: verify and pop the frame after exit rules.

The runtime builds the rule environment, dispatches entry rules, selects success
or error rules, then runs exit rules. The frame remains available throughout.
Exceptions propagate; frames are not discarded when rule execution fails.

Level Zero uses these hooks for its existing call stack and thread-safety locks.
Its scheduler invokes `dispatch_operation(kind, context, operation)` when work is
eligible. Its `finalize` invokes `finalize_rules` before printing the summary and
exporting CSV. These shared methods supply fresh rule environments for deferred
and final checks. Scheduling, result interpretation, diagnostics, and object
semantics remain model-specific.

Register trusted Ruby code explicitly:

```ruby
# my_cuda_backend.rb -- implemented by the backend author
require 'my_cuda_validation/state'
THAPIValidator::Backends.register('cuda') do |**options|
  MyCUDAValidation::State.new(**options)
end
```

Only after that implementation exists can it be selected:

```
thapi_validator --plugin=./my_cuda_backend.rb --backend=cuda \
  --rules=./cuda_rules.yaml TRACE_DIRECTORY
```

`--plugin` is repeatable and executes a user-specified Ruby file. YAML itself
cannot load Ruby files or execute expressions. Registration is explicit; merely
recording CUDA events never enables a CUDA validator. Backend factories are
loaded lazily, so a future backend can own its SDK dependencies instead of
requiring Level Zero's bindings to initialize.

A future programming model can also provide its own launcher using
`THAPIValidator::Backends` and `THAPIValidator::TraceGraph`, without depending on
the `thapi_validator` executable or enabling its build option.

## Reusing YAML rules

Each backend supplies its own registry and rules:

```ruby
registry = THAPIValidator::Registry.new
registry.register(:check, 'pointer.non_null', required: %w[value]) do |env, args|
  # Backend-specific reporting; API name is already in env[:context]['api'].
end
rules = THAPIValidator::Rules.new(registry,
  backend: 'cuda', default_path: 'cuda_defaults.yaml', user_path: user_rules)
```

Its adapter dispatches `entry`, `success`, `error`, and `exit` at the appropriate
points. That adapter chooses result interpretation and model updates. It supplies
an environment containing `state`, `context`, `payload`, saved `input`, `output`,
call-scoped `local`, and any deferred `operation`. `event` may supply normalized
metadata for raw-event rules.

```yaml
schema_version: 1
backend: cuda
apis:
  cuSomeAPI:
    entry:
      - check: pointer.non_null
        with:
          value: {ref: input.buffer}
```

This is a template for a backend author, not a shipped CUDA validator. The shared
runner also supports `apis: {'*': ...}` and optional `events` mappings keyed by
full event-name glob patterns. The adapter decides when to call
`rules.event(name, env)`. No programming-model-specific checks are supplied by the
shared runner. Each backend owns its `operations` scheduling and `finalize` calls.

## Compatibility and testing

The existing state class is now `ZEValidator::StateObject`; its legacy global
`StateObject` alias remains available for existing standalone integrations.
Use the qualified name in new code. Existing `ZEValidator::Registry`, `Rules`,
and `ConfigurationError` names alias the shared framework classes.

From the THAPI source root in the project's Ruby/gem environment:

```
ruby utils/validator/test/test_runtime.rb
ruby -Ibuild/ici/share backends/ze/validator/test/test_framework.rb
ruby -Ibuild/ici/share backends/ze/validator/test/test_consumer.rb
```

Tests verify that Level Zero is the only built-in backend, unregistered CUDA/MPI
selection fails, an explicitly programmed test backend can use YAML and the trace
reader, and existing Level Zero checks remain active. The optional integration
check uses the repository's generated MPI CTF fixture solely as input data for a
user-programmed event counter; it does not install or enable an MPI validator.
