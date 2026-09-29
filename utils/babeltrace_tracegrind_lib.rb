# Pretty-printer for the Tracegrind hook's event.
#
# Registers a lambda in $event_lambdas for lttng_ust_tracegrind:mem_accesses,
# the single event the Valgrind hook injects before every LTTng event the
# traced process emits (see backends/tracegrind/README.md).
#
# Unlike the per-backend babeltrace_*_lib.rb files, this one is not generated
# from an API model: the backend has exactly one event, with a fixed layout
# described by backends/tracegrind/tracegrind_events.yaml.
#
# Wire layout: intervals are flushed straight out of Tracegrind's drain buffer,
# where each tracegrind_interval_t is two consecutive words, so a sequence is
# [a0, b0, a1, b1, ...] and interval i is [ seq[2i] ; seq[2i+1] ) -- a = first
# byte, b = one-past-last. n_loads/n_stores count INTERVALS, so each sequence
# carries twice as many words.

# Intervals printed per kind before eliding the rest. Set to 0 to print all.
THAPI_TRACEGRIND_MAX_PRINT =
  begin
    v = ENV.fetch('THAPI_TRACEGRIND_MAX_PRINT', '8')
    Integer(v)
  rescue ArgumentError, TypeError
    8
  end

# "[0x12c9dce8-0x12c9dcfc, 0x12a70098-0x12a7009c, ...(+16382)]"
def thapi_tracegrind_intervals(words, count)
  return '[]' if count.nil? || count.zero? || words.nil?

  # Trust the smaller of the declared count and what the sequence can supply,
  # so a truncated payload cannot raise here.
  n = [count, words.length / 2].min
  shown = THAPI_TRACEGRIND_MAX_PRINT.zero? ? n : [n, THAPI_TRACEGRIND_MAX_PRINT].min

  s = +'['
  s << (0...shown).collect { |i|
    "0x#{words[2 * i].to_s(16)}-0x#{words[(2 * i) + 1].to_s(16)}"
  }.join(', ')
  s << ", ...(+#{n - shown})" if n > shown
  s << ']'
end

$event_lambdas['lttng_ust_tracegrind:mem_accesses'] = lambda { |defi|
  n_loads  = defi['n_loads']
  n_stores = defi['n_stores']
  {
    'seq' => defi['seq'].inspect,
    'chunk' => defi['chunk'].inspect,
    'loads' => "#{n_loads} #{thapi_tracegrind_intervals(defi['loads'], n_loads)}",
    'stores' => "#{n_stores} #{thapi_tracegrind_intervals(defi['stores'], n_stores)}",
    'user_ctx' => format('0x%016x', defi['user_ctx'])
  }.collect { |k, v| "#{k}: #{v}" }.join(', ')
}
