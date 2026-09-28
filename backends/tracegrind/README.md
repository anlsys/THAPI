# Tracegrind hook

Enriches a THAPI trace with the memory accesses the program performs *between*
two recorded events. Driven by `iprof --valgrind`.

## How it works

`iprof --valgrind` runs the traced program under
[Tracegrind](https://github.com/anlsys/valgrind/tree/tracegrind/tracegrind), a
Valgrind tool that instruments every load/store and enqueues them, per guest
thread, into a self-balancing interval tree that compacts dense/contiguous
accesses (`x[0], x[1], ... x[n]` collapses into `[&x[0] ; &x[n+1])`).

`libTracerTracegrind.so` is `LD_PRELOAD`ed alongside THAPI's own tracers.
Valgrind's redirection engine binds its wrapper onto liblttng-ust's internal
`lttng_event_reserve()` -- the first library call on the per-event emit path.
That symbol is local and has several identical copies, so it is unreachable
through `LD_PRELOAD` alone; only Valgrind, which reads the full symbol table,
can bind to it.

On each interception the hook pauses recording, drains the per-thread load and
store queues into thread-private buffers, emits
`lttng_ust_tracegrind:mem_accesses` with those buffers **as-is**, clears and
resumes, then calls the real `lttng_event_reserve()` so the program's own event
follows. A thread-local guard stops the hook's own emit -- which itself reserves
an event -- from recursing.

Nothing in the traced program, nor in THAPI's backends, is modified or
recompiled for this.

## The event

```
lttng_ust_tracegrind:mem_accesses:
  { seq = 3, user_ctx = 0x..., chunk = 0,
    n_loads = 96,  loads  = [ a0, b0, a1, b1, ... ],
    n_stores = 31, stores = [ a0, b0, a1, b1, ... ] }
```

The intervals are Tracegrind's raw `tracegrind_interval_t` buffer flushed
as-is: each interval occupies two consecutive words, so interval `i` is
`[ loads[2i] ; loads[2i+1] )` (`a` = first byte, `b` = one-past-last).
`n_loads` / `n_stores` are the interval **counts**, so each sequence carries
twice as many words. Having only two sequences (rather than separate
`start[]`/`end[]` arrays) is what lets the hook hand Tracegrind's buffer to
LTTng without deinterleaving it.

| Field | Meaning |
|---|---|
| `seq` | monotonically increasing per-thread interception counter |
| `user_ctx` | ring-buffer ctx address of the event about to be emitted |
| `chunk` | record index within this interception (0-based) |

`vpid` / `vtid` come from the channel context THAPI already adds, which matches
Tracegrind's per-guest-thread queues.

**No loss.** A single record carries at most 16384 intervals per kind
(256 KiB per thread and kind; override with `THAPI_TRACEGRIND_MAX_INTERVALS`).
If a thread accumulated more since the previous event, several records are
emitted back-to-back with the same `seq` and increasing `chunk`.

**Start-up noise.** `iprof` passes `--start-disabled=yes`, so each thread starts
paused and is resumed by the hook at its first event. Process/loader start-up
accesses are therefore not charged to the first recorded window; the first
record of each thread is empty.

## Building

Requires the tracegrind fork's headers at build time:

```sh
./configure --with-tracegrind=/path/to/valgrind-tracegrind-prefix
```

Only `<valgrind/valgrind.h>` and `<valgrind/tracegrind.h>` are needed to
compile; the `valgrind` launcher and the `tracegrind` tool are runtime
dependencies. With Spack: `spack install thapi +tracegrind`.

## Limitations

- Accesses made by THAPI's own preloaded tracers between the hook resuming and
  the next event are attributed to that window. Inherent to the approach.
- Atomics are recorded as ordinary accesses; a CAS shows up as both a load and a
  store of the location.
- Drained intervals are disjoint and non-adjacent but are **not** sorted by
  address (the queue is a tree, drained in tree order).
- GPU runtimes (Level Zero, CUDA, HIP) generally do not run under Valgrind.
- Expect a 10-100x slowdown, and one `mem_accesses` record per THAPI event --
  THAPI emits an entry *and* an exit event per API call.
