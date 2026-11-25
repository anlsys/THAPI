# Validator rule framework

The Level Zero validator uses the shared rule runner in `utils/validator/framework.rb`
(via the local `framework.rb` compatibility shim) and a Level Zero registry (`callbacks.rb` and `semantics.rb`). `rules.yaml` binds
API names and phases to registered operations. The default rules retain all
existing callback behavior, including state updates, early checks for calls that
never return, error-path checks, deferred memory checks, and finalization.

`ZEValidator::StateObject` inherits `THAPIValidator::APIBackend` in
`utils/validator/backend.rb`. The framework consumes Babeltrace messages,
normalizes events, constructs rule environments, and dispatches API phases,
deferred-operation checks, and final checks. The Level Zero class supplies
`on_event` for event interpretation and hooks for call frames, locking, and
Level Zero return codes. Its object model, deferred scheduler, and diagnostics
remain Level Zero code. The local `backend.rb` registers the factory and loads
the shared runtime; it is not a second runtime.

The execution order is preserved: push frame, acquire locks, entry rules;
then on return release locks in reverse order, success/error rules, exit rules,
verify the frame, and pop it. Deferred work is pumped after each API event.
Final rules drain pending work, report unfinished calls and leaks, then the
validator prints its summary and optional CSV.

## User configuration

Run `thapi_validator --rules=custom.yaml TRACE_DIRECTORY`. User rules **append** to
the built-in rules; they cannot replace or disable existing checks or model
updates. Edit `rules.yaml` to change backend bindings deliberately. Keep state
updates ordered: a missing create/record/free action can invalidate later checks.

Example: add a null-pointer precondition to region copies:

```yaml
schema_version: 1
backend: level_zero
apis:
  zeCommandListAppendMemoryCopyRegion:
    entry:
      - check: check_null_copy_ptr
        with:
          endpoints:
            destination: {ref: input.dstptr}
            source: {ref: input.srcptr}
```

Each API accepts `entry`, `success`, `error`, and `exit` lists. `exit` runs after
the selected success/error list, while the call frame still exists. Lists execute
in order. Each item specifies one `check` or `action` and optional `with`, `when`,
and `save_as`. Checks emit diagnostics; actions update state or return values.
`save_as` stores an action's return value in the current call's `local` mapping.
Nested calls and threads have separate local mappings.

Parameters are literals, lists, nested mappings, or explicit `{ref: namespace.field}`
references. Namespaces are:

* `input`: saved API entry fields (also available on return).
* `output`: API exit fields; forbidden in entry rules.
* `context`: hostname, vpid, vtid, api.
* `local`: values saved by actions on this call.
* `operation`: deferred-operation data; `operation.params` is the recorded params.

Deferred and final rules have their own local storage and cannot reference API
inputs/outputs; deferred parameters must use the `operation` namespace.
Missing fields raise an error rather than silently skipping a check. YAML never
evaluates Ruby or dispatches arbitrary method names. Only registered operations
can be invoked. Unknown operation names, parameters, phases, schema versions,
and unsupported YAML object tags are rejected before traces are consumed.

A conditional rule supplies a registered predicate:

```yaml
- check: check_null_copy_ptr
  when:
    predicate: events.waits_satisfied
    with:
      waits: []
  with:
    endpoints:
      source: {ref: input.srcptr}
```

Deriving backend objects or context handles requires a registered action; the
registry is the extension point for these helpers. Quote YAML strings such as
`"yes"` and `"no"` that YAML may interpret as booleans.

## Backend operations

The existing callback bodies are registered as `level_zero.API.PHASE` actions;
shared success/error callbacks keep both bindings. Their bodies, including the
existing queue debug output, are unchanged. Existing `check_*` functions in
`semantics.rb` are also registered as individually reusable checks. Their `with`
keys match Ruby parameter names after `state, ctx`. The framework supplies
`state`, `ctx`, the current event `payload`/`_payload`, and the triggering `api`
name automatically. Do not repeat the enclosing API name inside `with:`; use
`with:` only for check-specific arguments, such as pointers and sizes. Existing
configurations that explicitly supply `api` remain supported. Consult the
semantic function signatures for the remaining arguments.

Deferred checks live in `operations.KIND` lists (currently `copy` and
`ranges_barrier`). The scheduler still owns waits, signals, ordering, and progress;
rules run when an operation becomes eligible. `finalize` runs the default drain,
unfinished-call check, and leak check before summary/CSV output. Existing
`--no-report-leaks` behavior is retained.

To implement another backend, create its model/trace adapter, a `Registry`, and a
versioned YAML file; instantiate `Rules` with that registry and backend name.
The runner only needs an environment hash and dispatch calls. The current
`StateObject` and scheduler remain the Level Zero adapter, not a universal model.

Register an operation with:

```ruby
registry.register(:check, 'custom.check', required: %w[handle]) do |env, args|
  # env[:state], env[:context]; args['handle'] is already resolved
end
```

Use `:action` for state changes and `:predicate` for boolean conditions. Extensions
are trusted Ruby backend code loaded by the application, not paths specified in YAML.

## Verification

In the same Ruby/gem/library environment used for `thapi_validator`, run:

```
ruby -Ibuild/ici/share backends/ze/validator/test/test_framework.rb
ruby -Ibuild/ici/share backends/ze/validator/test/test_consumer.rb
```

Tests cover configuration rejection, additive overrides, references, conditional
execution, local storage, phase/deferred/final dispatch, and Level Zero memory,
rollback, deadlock, leak, and call-stack regressions. No GPU or recorded trace is
required. Building/installing uses the existing ZE_VALIDATOR configure option;
`framework.rb` and `rules.yaml` are installed with the other validator sources.

## Programming other models later

Level Zero remains the only built-in backend. The shared registry/rule engine and
explicit adapter interface are documented in `utils/validator/README.md`.
`--list-backends` lists available registrations. `--plugin=FILE --backend=NAME`
selects a user-programmed backend only after that implementation is provided;
CUDA and other models are not validated automatically. Existing Level Zero rules
and checks remain the default. New integrations should use
`ZEValidator::StateObject` rather than the legacy global alias.

The consumer regression also exercises initialization/deprecation diagnostics,
thread-safety locking, queue-property decoding, nested calls, and CSV output
through the shared message loop. It prints a deterministic JSON result for
before/after comparisons. `THAPI_VALIDATOR_STATE_FILE` can select a saved
pre-refactor state implementation for that comparison.
