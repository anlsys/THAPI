require 'ze_validator_zemodel'
require 'ze_library'

def check_valid_index_for_ordinal(state,ctx,queue_handle,ordinal,index)
  #puts "entered"
  if state.device_properties
    command_queue_prop = state.device_properties["devices"][0]["command_queue_groups"]
    command_queue_prop.each do |prop|
      if prop["ordinal"] == ordinal && (index >= prop["numQueues"] || index < 0)#oob index results in segfault
        state.print_usage_error(ctx, "command queue (#{state.get_handle_str(queue_handle)}) with ordinal = #{ordinal} was created " +
                                     "with index = #{index}. Index value should be: 0<= index < #{prop["numQueues"]}")
      end
    end
  end
end

def check_group_property_queued(state, ctx, defi, device)
  #puts "device = #{device}"
  if !(device.cmd_queue_group_properties_queried) && state.print_tracker["check_group_property"] == 0
    state.print_tracker["check_group_property"] = 1
    state.print_usage_error(ctx,"command queue group wasn't queried. Hardcoded group properties may break the code on different devices")
  end
end


def check_valid_ordinal(state, ctx, defi, cqg_ordinal)
  copy_only_ords = []
  if state.device_properties
    command_queue_prop = state.device_properties["devices"][0]["command_queue_groups"]
    command_queue_prop.each do |prop|
      if prop["type"] == "copy"
        copy_only_ords << prop["ordinal"]
        #puts "appended #{prop["ordinal"]}"
      end
    end
  else
    #hardcode if the device property json wasn't generated
    copy_only_ords << 1
    copy_only_ords << 2
  end


  if copy_only_ords.include?(cqg_ordinal) && state.print_tracker["zeCommandListAppendLaunchKernel::K2CopyOrdinal"] == 0
    state.print_tracker["zeCommandListAppendLaunchKernel::K2CopyOrdinal"] = 1
    kernels = state.find_objects(ctx, 'kernel')
    kernel_handle = state.find_param(ctx, 'hKernel')
    kernel_name = "UNKNOWN"
    # CHANGED: was `state.find_object(ctx, 'hCommandList')` -- wrong arity
    # (find_object needs type+handle) and returned an object, not a handle. Read
    # the handle from the entry params and format it for the message.
    command_list_handle = state.find_param(ctx, 'hCommandList')
    if kernels[kernel_handle]
      kernel_name = kernels[kernel_handle].name
    end
    state.print_usage_error(ctx, "Launching kernel (#{kernel_name}) to a command list with Copy Ordinal: #{state.get_handle_str(command_list_handle)}")
  end
end

def check_kernel_created(state, ctx, defi)
  kernels = state.find_objects(ctx, 'kernel')
  kernel_handle = defi['hKernel']
  unless kernels[kernel_handle]
    state.print_usage_error(ctx, "kernel: #{state.get_handle_str(kernel_handle)} wasn't created. Consider calling zeKernelCreate")
  end
end

#Checks for misuse of fences.
#Not a proper use of fence if it was already signaled,
#or being used by other commandslist.
def check_fence_misuse(state, ctx, defi)
  fence_handle = defi['hFence']
  fence = get_fence(state,ctx,fence_handle)
  if fence && (fence.status == fence.signaled || fence.status == fence.in_use)
    state.print_usage_error(ctx, "Used fence: #{state.get_handle_str(fence_handle)} twice without resetting it")
  end
end

def check_valid_command_queue(state,ctx,defi, cmd_queues, cmd_queue_ptr)
  cmd_queue = cmd_queues[cmd_queue_ptr]
  unless cmd_queue 
    state.print_usage_error(ctx, "Invalid commandQueue (#{state.get_handle_str(cmd_queue_ptr)}) was handed to zeCommandQueueExecuteCommandLists")
  end

end

def check_valid_command_lists(state, ctx, defi)
  command_lists = defi['phCommandLists_vals']
  known_command_lists = state.find_objects(ctx, 'command_list')
  if command_lists.nil? || command_lists.empty?
    state.print_usage_error(ctx, "No valid commandlist was chosen at zeCommandQueueExecuteCommandLists")
  end

  command_lists.each do |command_list_handle|
    if !(known_command_lists[command_list_handle])
      state.print_usage_error(ctx, "Invalid commandlist (#{command_list_handle}) was handed to zeCommandQueueExecuteCommandLists")
    elsif known_command_lists[command_list_handle] && known_command_lists[command_list_handle].immediate
        state.print_usage_error(ctx, "Immediate Command List was chosen for the Command Queue: #{state.get_handle_str(command_queue_handle)}")
    end
  end
end

#change it to calculating the memory overlap region?
def get_memory_overlap(mem1, mem2)
	overlap = []
	if mem1 && mem2 && mem1.memtypestr == mem2.memtypestr
		#Check if mem2 is contained in mem1
		if mem1.base <= mem2.base && mem2.base <= mem1.base + mem1.size
			overlap << mem2.base
			overlap << [mem2.base+mem2.size, mem1.base+mem1.size].min
		elsif mem2.base <= mem1.base && mem1.base <= mem2.base + mem2.size
      overlap << mem1.base
      overlap << [mem2.base+mem2.size, mem1.base+mem1.size].min
		end
  end
	overlap
end

# REMOVED: record_copy_over / add_api_call_to_cmd_list.
# These were the earlier "memory_in_transit" and "api_calls history" approaches
# to correlating copies. They are superseded by the RecordedOp / DeferredUnit
# model (each copy is recorded as an op and checked at execute time), and
# add_api_call_to_cmd_list referenced undefined locals (state/ctx) so it could
# never have run. See record_op / record_copy_op below.

def get_fence(state,context,fence_handle)
  fences = state.find_objects(context, 'fence')
  fence = fences[fence_handle] #returns fence
end

# ADDED: read the wait-event handles from an append call's input params. Both
# spellings appear in the trace: copies/barriers/launches use phWaitEvents_vals,
# zeCommandListAppendWaitOnEvents uses phEvents_vals. find_param is used because
# exit callbacks do not see input params in defi. Null/empty entries are dropped.
def wait_event_handles(state, ctx)
  handles = state.find_param(ctx, 'phWaitEvents_vals') ||
            state.find_param(ctx, 'phEvents_vals') || []
  handles.reject { |h| h.nil? || h == 0 }
end

# ADDED: record one op onto its command list. A regular (non-immediate) list
# stores it for replay at execute time; an immediate list executes right away, so
# the op is scheduled immediately. No-op if the list handle is unknown.
def record_op(state, ctx, cmd_list_handle, op)
  cmd_list = state.find_objects(ctx, 'command_list')[cmd_list_handle]
  return unless cmd_list
  if cmd_list.immediate
    state.enqueue_immediate_op(ctx, op, cmd_list_handle)
  else
    cmd_list.ops << op
  end
end

# ADDED: record a memory-copy op (zeCommandListAppendMemoryCopy / MemoryFill).
# Values are snapshotted now (via find_param) because the per-call context is
# gone by the time the op is replayed. The out-of-bounds check is deferred to
# execute time; see check_oob_copy.
def record_copy_op(state, ctx, api, dst_key, src_key)
  cmd_list_handle = state.find_param(ctx, 'hCommandList')
  op = ZEModel::RecordedOp.new(:copy,
        signal: state.find_param(ctx, 'hSignalEvent'),
        waits: wait_event_handles(state, ctx),
        params: { api: api,
                  dst: (dst_key ? state.find_param(ctx, dst_key) : nil),
                  src: (src_key ? state.find_param(ctx, src_key) : nil),
                  size: state.find_param(ctx, 'size') })
  record_op(state, ctx, cmd_list_handle, op)
end

def check_command_list_closed(state, ctx, defi)
  command_queue_handle = defi['hCommandQueue']
  # CHANGED: guard against nil (empty submit) so .each does not crash
  command_lists = defi['phCommandLists_vals'] || []
  known_command_lists = state.find_objects(ctx, 'command_list')
  command_lists.each do |command_list_handle|
    # CHANGED: was `knwon_command_lists` (typo -> NameError). Also skip unknown
    # handles rather than calling .status on nil, and report the actual handle
    # instead of the undefined local `cl`.
    cmd_list = known_command_lists[command_list_handle]
    next unless cmd_list
    if cmd_list.status == ZEModel::CommandList.class_variable_get(:@@INITIALIZED)
      state.print_usage_error(ctx, "commandlist: #{state.get_handle_str(command_list_handle)} wasn't closed before executing on #{state.get_handle_str(command_queue_handle)}")
    elsif cmd_list.status == ZEModel::CommandList.class_variable_get(:@@DESTROYED)
      state.print_usage_error(ctx, "commandlist: #{state.get_handle_str(command_list_handle)} was already destroyed #{state.get_handle_str(command_queue_handle)}")
    end
  end
end


def check_valid_module(state,ctx,defi)
  module_handle = state.find_param(ctx, 'hModule')
  if !module_handle || module_handle == 0
    state.print_usage_error(ctx, "Improper hModule was handed")
  end
end
def check_list_and_fence_have_matching_context(state,ctx,defi,cmd_list,fence)
  if fence 
    unless cmd_list && fence.command_queue &&
          cmd_list.context == fence.command_queue.context
      list_handle = cmd_list ? state.get_handle_str(cmd_list.handle) : "nullptr"
      fence_handle = fence
      state.print_usage_error(ctx, "Mismatching context between command list #{list_handle} and fence #{fence_handle}")
    end
  end
end

def check_fence_and_queue_compatibility(state,ctx,defi,cmd_queue,fence)
  if fence 
    unless cmd_queue && cmd_queue == fence.command_queue
      queue_handle = cmd_queue ? state.get_handle_str(cmd_queue.handle) : "nullptr"
      fence_handle = fence
      state.print_usage_error(ctx, "Associated command queue (#{state.get_handle_str(fence.command_queue)}) of fence #{fence_handle} " +
                                   "is different from the one that was provided #{queue_handle}")
    end
  end
end

def check_list_and_queue_have_matching_context(state,ctx,defi,cmd_list, cmd_queue)
  unless cmd_queue && cmd_list && cmd_list.context == cmd_queue.context
    queue_handle = cmd_queue ? state.get_handle_str(cmd_queue.handle) : "nullptr"
    list_handle = cmd_list ? state.get_handle_str(cmd_list.handle) : "nullptr"
    state.print_usage_error(ctx, "Mismatching context between command queue #{queue_handle} and command list #{list_handle}")
  end
end

# REPLACED check_oob_memory_copy (it iterated a CommandList as if enumerable and
# referenced an undefined `defi`) with the helpers below.

# ADDED: find the allocation that contains ptr, so a copy into an offset of a
# base allocation is matched, not only an exact base-pointer copy.
def find_allocation_containing(allocations, ptr)
  allocations.each_value.find { |m| m.base && m.base <= ptr && ptr < m.base + m.size }
end

# ADDED: out-of-bounds check for one endpoint (source or destination) of a copy.
# Measures the copy size against the bytes remaining from ptr's offset within its
# allocation. An unknown pointer is left alone (nothing to compare against).
def check_copy_endpoint(state, ctx, allocations, ptr, size, api, role)
  return if ptr.nil? || ptr == 0 || size.nil?
  mem = allocations[ptr] || find_allocation_containing(allocations, ptr)
  return unless mem
  offset = ptr - mem.base
  available = mem.size - offset
  if available < size
    state.print_usage_error(ctx, "#{api}: #{role} memory #{state.get_handle_str(ptr)} only has #{available} " \
                                 "bytes available from this offset but the copy needs #{size} bytes")
  end
end

# ADDED: deferred out-of-bounds check for a recorded copy op. Called from the
# scheduler once the copy's wait-events are satisfied, so it runs against the
# memory model as it stands at the point the copy actually executes -- avoiding
# the false positives that checking at execute-entry would give (the destination
# may only be allocated after execute, by whoever signals the wait-event).
def check_oob_copy(state, ctx, params)
  api = params[:api] || 'zeCommandListAppendMemoryCopy'
  size = params[:size]
  allocations = state.find_objects(ctx, 'memory_allocation')
  check_copy_endpoint(state, ctx, allocations, params[:dst], size, api, 'destination')
  check_copy_endpoint(state, ctx, allocations, params[:src], size, api, 'source')
end

# ADDED: a successful allocation may reuse an address previously freed. Drop any
# freed record whose former range overlaps the new allocation so it is not
# mistaken for a still-dangling pointer. Call from the alloc callbacks.
def mark_reallocated(state, ctx, handle, size)
  freed = state.freed_memory_allocations(ctx)
  return if freed.empty?
  freed.delete_if { |_addr, m| ranges_overlap?(m.base, m.size, handle, size) }
end

# ADDED: like find_allocation_containing, but over the freed-allocation registry
# -- finds a released allocation whose (former) range still contains ptr.
def find_freed_allocation_containing(freed, ptr)
  freed.each_value.find { |m| m.base && m.base <= ptr && ptr < m.base + m.size }
end

# ADDED: use-after-free check for one endpoint (dst/src) of a copy/fill. If the
# pointer does NOT resolve to a live allocation but DOES fall inside an
# allocation that was already zeMemFree'd, report a use-after-free. A pointer
# that matches neither is left alone (unknown / untraced -- nothing to assert).
def check_uaf_endpoint(state, ctx, live, freed, ptr, api, role)
  return if ptr.nil? || ptr == 0
  #still live (exact base or an offset within a live allocation) -> fine
  return if live[ptr] || find_allocation_containing(live, ptr)
  mem = freed[ptr] || find_freed_allocation_containing(freed, ptr)
  return unless mem
  #dedup: the same freed pointer can be seen both at append-entry and again at
  #deferred execute time -- report it once per (api, pointer).
  key = "uaf-#{api}-#{state.get_handle_str(ptr)}"
  return unless state.print_tracker[key] == 0
  state.print_tracker[key] = 1
  offset = ptr - mem.base
  where = offset == 0 ? "" : " (offset #{offset} into the freed allocation)"
  state.print_memory_error(ctx, "#{api}: #{role} memory #{state.get_handle_str(ptr)}#{where} was already " \
                                "freed#{mem.freed_by ? " by #{mem.freed_by}" : ""}; use-after-free")
end

# ADDED: deferred use-after-free check for a recorded copy/fill op. Runs from the
# scheduler at the point the copy actually executes (alongside check_oob_copy),
# so a pointer freed before the copy's turn is caught, while a destination only
# allocated later is not falsely flagged.
def check_use_after_free(state, ctx, params)
  api  = params[:api] || 'zeCommandListAppendMemoryCopy'
  live  = state.find_objects(ctx, 'memory_allocation')
  freed = state.freed_memory_allocations(ctx)
  return if freed.empty?
  check_uaf_endpoint(state, ctx, live, freed, params[:dst], api, 'destination')
  check_uaf_endpoint(state, ctx, live, freed, params[:src], api, 'source')
end

# ADDED: true if [a, a+asize) and [b, b+bsize) overlap.
def ranges_overlap?(a, asize, b, bsize)
  return false unless a && b && asize && bsize
  a < b + bsize && b < a + asize
end

# ADDED: free-while-in-flight check. Called from zeMemFree BEFORE the allocation
# is removed. If any copy/fill op still pending in an in-flight deferred command
# list references (overlaps) the allocation being freed, the device may still
# read/write it after the free -- report it. mem is the ZEModel::Memory about to
# be freed.
def check_free_in_flight(state, ctx, mem)
  return unless mem
  state.each_inflight_copy_op(ctx) do |unit, op|
    p = op.params
    hit = [[p[:dst], 'destination'], [p[:src], 'source']].find do |ptr, _role|
      ptr && ptr != 0 && ranges_overlap?(mem.base, mem.size, ptr, p[:size])
    end
    next unless hit
    _ptr, role = hit
    state.print_memory_error(ctx, "memory #{state.get_handle_str(mem.base)} is being freed while still in use as " \
                                  "the #{role} of an in-flight #{p[:api] || 'copy'} on #{unit.label}; the device " \
                                  "may access freed memory")
  end
end

def check_ptrs_have_same_context(state,ctx,params)
  allocations = state.find_objects(ctx, 'memory_allocation')
  if allocations[params[:dst]] && allocations[params[:dst]] && (allocations[params[:dst]].context != allocations[params[:src]].context)
    
  end
end

# ADDED: detect misuse of an event that is signaled while already signaled, with
# no intervening reset. Mirrors the fence double-signal check. Two shapes:
#   * reuse-no-reset -- the prior signal WAS observed by the host (e.g. it
#                       synchronized on the event) and the event is reused as a
#                       signal target without a reset first.
#   * double-signal  -- the prior signal was never observed; two signalers target
#                       the same event with no consumer between them.
# Called just before an op applies its own signal, in execution order, so any
# intervening reset/observe has already been recorded. `who` names the signaler.
def check_event_signal_reuse(state, ctx, handle, who)
  ev = state.event_by_handle(ctx, handle)
  return unless ev && ev.signaled?
  if ev.observed
    state.print_usage_error(ctx, "event #{state.get_handle_str(handle)} was reused as a signal target by #{who} " \
                                 "without calling zeEventHostReset/zeCommandListAppendEventReset after it was " \
                                 "signaled#{ev.signaled_by ? " by #{ev.signaled_by}" : ""}")
  else
    state.print_usage_error(ctx, "event #{state.get_handle_str(handle)} was signaled by #{who} before being reset " \
                                 "or consumed#{ev.signaled_by ? " (already signaled by #{ev.signaled_by})" : ""}; " \
                                 "concurrent signals of the same event are undefined")
  end
end

# ADDED: report wait-events that were never signaled by end of trace -- a
# deferred op that could never complete (missing signal or deadlock).
def report_unsignaled_waits(state, ctx, waits)
  (waits || []).each do |h|
    ev = state.event_by_handle(ctx, h)
    next unless ev && !ev.signaled?
    state.print_usage_error(ctx, "event #{state.get_handle_str(h)} was never signaled; a deferred command list " \
                                 "operation could not complete (possible deadlock or missing signal)")
  end
end

# ADDED: detect a circular event dependency (deadlock) among the deferred units
# still stuck at end of trace, and report the FIRST cycle found. Builds a
# wait-for graph -- unit U points to unit V when U is blocked on an event that
# only V can still signal (it is in V's pending_signals) -- then searches for one
# cycle. A cycle means every unit on it waits for an event another unit on the
# cycle only signals after finishing, so none can ever start (e.g. clA waits
# evB/signals evA while clB waits evA/signals evB).
def check_circular_deadlock(state, units)
  stuck = units.select { |u| u.blocked_on && !u.blocked_on.empty? }
  return if stuck.empty?

  # event handle -> units that may still signal it
  signalers = Hash.new { |h, k| h[k] = [] }
  stuck.each { |u| u.pending_signals.each { |ev| signalers[ev] << u } }

  # adjacency: U -> V if U waits on an event V still owes
  succ = Hash.new { |h, k| h[k] = [] }
  stuck.each do |u|
    u.blocked_on.each do |ev|
      signalers[ev].each { |v| succ[u] << v unless v.equal?(u) }
    end
  end

  # DFS; stop at the first cycle and report only that one
  path = []
  on_path = {}
  visited = {}
  found = nil
  dfs = lambda do |u|
    return true if found
    on_path[u] = true
    path.push(u)
    succ[u].uniq.each do |v|
      if on_path[v]
        found = path[path.index(v)..] # the cycle, from v back to the current node
        break
      elsif !visited[v]
        break if dfs.call(v)
      end
    end
    path.pop
    on_path[u] = false
    visited[u] = true
    !found.nil?
  end
  stuck.each { |u| break if dfs.call(u); }
  report_deadlock_cycle(state, found) if found
end

# ADDED: report one deadlock cycle, naming each unit AND the specific command
# (op) it is stuck on -- e.g. "command_list 0x..::zeCommandListAppendMemoryCopy".
# The blocked command is the unit's current_op (the cursor is parked on it and
# blocked_on holds exactly that op's unsatisfied waits), so the chain reads
# <list>::<blocking API> -> <list>::<blocking API> -> ... back to the first.
def deadlock_node_label(state, unit)
  op = unit.current_op
  # op.api is set for every op that can carry waits (copy/launch/barrier/wait);
  # fall back to the op kind for anything else so the label is never blank.
  api = op ? (op.api || op.kind.to_s) : 'unknown'
  waits = unit.blocked_on.map { |h| state.get_handle_str(h) }.join(', ')
  "#{unit.label}::#{api} (waiting on event #{waits})"
end

def report_deadlock_cycle(state, cycle)
  ctx = cycle.first.context
  desc = cycle.map { |u| deadlock_node_label(state, u) }.join(" -> ")
  # close the loop for readability
  desc << " -> #{deadlock_node_label(state, cycle.first)}"
  state.print_deadlock_error(ctx, "circular event dependency among command list operations; none can start: #{desc}")
end

# ADDED: detect an intra-list deadlock in an IN-ORDER command list. Such a list
# runs its ops strictly in append order (op N+1 cannot start until op N
# completes), so if the op the unit is parked on waits on an event that only a
# LATER op in the SAME list will signal, that later op can never be reached --
# the list deadlocks on itself. The cross-list detector cannot see this because
# it drops self-edges. Run at end-of-trace (flush): a unit still parked here was
# never rescued by an external host signal, so the wait is genuinely unmet.
#
# unit.pending_signals holds exactly the events signaled by ops at/after the
# cursor, so blocked_on & pending_signals = waits only a later op in this list
# owes -- the self-deadlock condition -- with no extra bookkeeping.
def check_in_order_self_deadlock(state, units)
  units.each do |unit|
    next unless unit.in_order
    next if unit.blocked_on.nil? || unit.blocked_on.empty?
    self_waits = unit.blocked_on & unit.pending_signals
    self_waits.each do |ev|
      #the later op in this same list that would signal ev (but never runs)
      later = unit.ops[(unit.cursor + 1)..]&.find { |o| o.signal == ev }
      report_in_order_self_deadlock(state, unit, ev, later)
    end
  end
end

# ADDED: report one intra-list self-deadlock in the op-level arrow format:
#   <list>::<waiting op> (waits on event 0xE) ->
#   <list>::<signaling op> (signals event 0xE later in the same in-order list)
def report_in_order_self_deadlock(state, unit, ev, signaling_op)
  waiting = unit.current_op
  waiting_api = waiting ? (waiting.api || waiting.kind.to_s) : 'unknown'
  signaling_api = signaling_op ? (signaling_op.api || signaling_op.kind.to_s) : 'unknown'
  ev_str = state.get_handle_str(ev)
  desc = "#{unit.label}::#{waiting_api} (waits on event #{ev_str}) -> " \
         "#{unit.label}::#{signaling_api} (signals event #{ev_str} later in the same in-order list)"
  state.print_deadlock_error(unit.context,
    "in-order command list cannot complete; an earlier command waits on an event a later " \
    "command in the same list signals: #{desc}")
end

def check_struct_stype_misuse(state,ctx,defi,expected_stype, observed_stype)
  if expected_stype != observed_stype && state.print_tracker[expected_stype] == 0
      state.print_tracker[expected_stype] = 1
      state.print_usage_error(ctx,"\nExpected stype of #{expected_stype}\nbut #{observed_stype} was observed.")
  end
end
