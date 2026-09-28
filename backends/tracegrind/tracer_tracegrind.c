/*
 * Valgrind function-wrapper for the lowest-level LTTng-UST emit call. It emits
 * a SECOND LTTng event (lttng_ust_tracegrind:mem_accesses) carrying the
 * compacted load/store intervals Tracegrind recorded, just BEFORE every event
 * the traced process emits -- THAPI's own ze/cl/cuda/hip/mpi/omp/itt
 * tracepoints included.
 *
 * Nothing is recompiled to get this: iprof --valgrind runs the program under
 * `valgrind --tool=tracegrind` with this object LD_PRELOAD'd, and Valgrind's
 * redirection engine binds the wrapper below onto liblttng-ust's internal
 * lttng_event_reserve(struct lttng_ust_ring_buffer_ctx *) -- the per-event
 * ring-buffer reservation, the first library call on the emit path. That symbol
 * is local and has several identical copies, so it is unreachable through
 * LD_PRELOAD alone; only Valgrind, which reads the full symbol table, can bind
 * to it.
 *
 * Z-encoding (valgrind/pub_tool_redir.h):
 *   soname "liblttng-ust.so.1" -> liblttngZhustZdsoZd1   ('-' = Zh, '.' = Zd)
 *
 * RE-ENTRANCY: emitting our own event itself calls lttng_event_reserve, which
 * Valgrind redirects back here. A thread-local guard breaks the recursion.
 *
 * ZERO-COPY DRAIN: Tracegrind drains straight into a per-thread
 * 'tracegrind_interval_t' buffer that is handed to LTTng as-is. Each interval
 * is two consecutive words (a, b), so one sequence per kind carries
 * [a0, b0, a1, b1, ...] -- no deinterleaving into start[]/end[].
 *
 * NO LOSS: a single record carries at most MAX_INTERVALS intervals per kind; if
 * a thread accumulated more since the previous event, several records are
 * emitted back-to-back (same seq, increasing chunk) so nothing is dropped.
 */

#include <stdlib.h> /* getenv, malloc, strtoul */

#include <valgrind/tracegrind.h>
#include <valgrind/valgrind.h>

/* Our provider. TRACEPOINT_DEFINE/CREATE_PROBES live in the generated
 * tracegrind_tracepoints.c, linked in through libtracegrindtracepoints.la. */
#include "tracegrind_tracepoints.h"

/* Per-thread guard: true while we are emitting our own event, so the nested
 * lttng_event_reserve it triggers is passed straight through. */
static __thread int in_wrapper;

/*
 * Maximum number of compacted intervals carried by a SINGLE mem_accesses
 * record, per kind. Thread-private, so it can be tuned per thread; the default
 * 16384 intervals means a 256 KiB drain buffer per kind
 * (sizeof(tracegrind_interval_t) == 2 words == 16 bytes, x 16384).
 */
#define DEFAULT_MAX_INTERVALS 16384UL

static __thread unsigned long max_intervals;

/*
 * Per-thread drain buffers, lazily allocated to hold max_intervals intervals.
 * Tracegrind drains straight into these and they are forwarded to LTTng as-is,
 * so there is a single copy out of the queue. They live for the thread's
 * lifetime (intentionally not freed).
 */
static __thread tracegrind_interval_t *load_buf;
static __thread tracegrind_interval_t *store_buf;

/* Sized once per thread, from THAPI_TRACEGRIND_MAX_INTERVALS when set. */
static unsigned long tracer_max_intervals(void) {
  if (max_intervals == 0) {
    const char *s = getenv("THAPI_TRACEGRIND_MAX_INTERVALS");
    unsigned long n = s ? strtoul(s, NULL, 0) : 0;
    max_intervals = n ? n : DEFAULT_MAX_INTERVALS;
  }
  return max_intervals;
}

int I_WRAP_SONAME_FNNAME_ZU(liblttngZhustZdsoZd1, lttng_event_reserve)(void *ctx);

int I_WRAP_SONAME_FNNAME_ZU(liblttngZhustZdsoZd1, lttng_event_reserve)(void *ctx) {
  static __thread unsigned long seq; /* per-thread interception counter */
  OrigFn fn;
  int result;

  VALGRIND_GET_ORIG_FN(fn);

  /* If this reservation is the one our own event is making, don't recurse --
   * just call the real function and return. */
  if (in_wrapper) {
    CALL_FN_W_W(result, fn, ctx);
    return result;
  }

  in_wrapper = 1;

  /* Pause recording so our own bookkeeping (drain, emit, reserve) does not
   * pollute the NEXT window. */
  TRACEGRIND_DISABLE();

  {
    const unsigned long cap = tracer_max_intervals();

    if (load_buf == NULL)
      load_buf = malloc(cap * sizeof(*load_buf));
    if (store_buf == NULL)
      store_buf = malloc(cap * sizeof(*store_buf));

    if (load_buf != NULL && store_buf != NULL) {
      unsigned long this_seq = ++seq;
      unsigned int chunk = 0;
      unsigned long nl, ns;

      /* Drain everything, emitting as many records as needed. Each drain
       * removes at most `cap` intervals of a kind; when a kind fills the
       * buffer, more may remain, so we loop -> no loss. The first iteration
       * always emits (even when empty) so that every event still gets exactly
       * one leading 'seq'. */
      do {
        nl = TRACEGRIND_EMPTY_QUEUE(TRACEGRIND_LOADS, load_buf, cap);
        ns = TRACEGRIND_EMPTY_QUEUE(TRACEGRIND_STORES, store_buf, cap);

        /* Both queues already fully flushed by a previous chunk: stop without
         * emitting a trailing empty record. */
        if (chunk > 0 && nl == 0 && ns == 0)
          break;

        /* Flush the tracegrind_interval_t buffers as-is: interval i is
         * [ loads[2i] ; loads[2i+1] ), likewise for stores. */
        tracepoint(lttng_ust_tracegrind, mem_accesses, this_seq, (unsigned long)ctx, chunk,
                   (unsigned int)nl, (unsigned long *)load_buf, (unsigned int)ns,
                   (unsigned long *)store_buf);
        chunk++;
      } while (nl == cap || ns == cap);
    }
  }

  /* Drop anything our emit touched, then resume so the event and the following
   * user code are recorded into a fresh window. */
  TRACEGRIND_CLEAR_QUEUE(TRACEGRIND_LOADS);
  TRACEGRIND_CLEAR_QUEUE(TRACEGRIND_STORES);
  TRACEGRIND_ENABLE();

  in_wrapper = 0;

  /* Now let the real reservation proceed -> the event follows. */
  CALL_FN_W_W(result, fn, ctx);
  return result;
}
