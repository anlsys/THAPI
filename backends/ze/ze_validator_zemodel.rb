require 'set'

module ZEModel
  INIT_API_NAMES = ['zeInit', 'zeInitDrivers']
  class Object
    attr_reader :handle
    attr_accessor :status
    def self.typename
      @typename
    end

    def initialize(handle)
      @handle = handle
      @lock = nil
      @status = -1
    end

    def lock(state,ctx)
      if @lock
        state.print_race_condition(ctx, @lock, self.class.typename, @handle)
      else
        @lock = ctx
      end
    end

    def unlock(ctx)
      if @lock == ctx
        @lock = nil
      end
    end
  end
  # 'A < B' means A inherits from B
  class Driver < Object
    @typename = 'driver'
    attr_reader :devices

    def initialize(handle)
      super
      @devices = []
    end
  end



  class Device < Object
    @typename = 'device'
    attr_reader :properties
    attr_reader :sub_devices
    # CHANGED: nested by Level Zero context handle -- ctx_handle -> {addr -> Memory}
    # -- for the same reason as Process#memory_allocations: an address is only
    # guaranteed unique within a context, and one device can back allocations in
    # several contexts. Auto-vivifies an empty sub-map per context.
    attr_accessor :memory_allocations
    attr_accessor :property_fetched
    attr_accessor :cmd_queue_group_properties_queried
    #attr_accessor :p2p_list

    def initialize(handle)
      super
      @sub_devices = []
      @memory_allocations = Hash.new { |h, k| h[k] = {} }
      @property_fetched = false
      @cmd_queue_group_properties_queried = false
    end
  end



  class SubDevice < Device
    attr_reader :parent
    def initialize(handle, parent)
      @parent = parent
      super(handle)
    end
  end

  #create memory object so that device, shared, host mem allocs can be differentiated
  class Memory < Object
    @typename = 'memory_allocation'
    attr_reader :context
    attr_reader :size
    attr_reader :owned_by
    attr_accessor :resident
    attr_accessor :memtypestr
    attr_accessor :base
    # ADDED: api-context string of the zeMemFree that released this allocation,
    # or nil while live. A freed allocation is moved to the process-level
    # @freed_memory_allocations registry (kept, not discarded) so a later copy/
    # fill/kernel that still references its address range can be reported as a
    # use-after-free instead of silently passing (unknown pointer).
    attr_accessor :freed_by
    def initialize(handle, context, size, owned_by, memtypestr="shared")
      super(handle)
      @context = context
      @size = size
      @owned_by = owned_by
      @memtypestr = memtypestr
      @base = handle
      @freed_by = nil # ADDED
      #puts "size = #{size}, handle = #{handle}, handle+size=#{handle + size}"
      #for device memory.
      if memtypestr == "device"
        @resident = false
      else
        @resident = true
      end
    end
  end


  # No need to create DeviceMemory class. Just create Memory with the specified type (device,shared,host)
  # class DeviceMemory < Object
  #   @typename = 'memory_allocation_device'
  #   attr_reader :context
  #   attr_reader :size
  #   attr_reader :device

  #   def initialize(handle, context, size, device)
  #     super(handle,context,size,device)
  #     @context = context
  #     @size = size
  #     @device = device
  #   end
  # end





  class Context < Object
    @typename = 'context'
    attr_reader :driver
    attr_reader :desc
    attr_reader :devices

    attr_reader :event_pools
    attr_reader :command_queues
    attr_reader :command_lists
    attr_reader :modules
    attr_reader :module_build_logs

    def initialize(handle, driver, desc, devices = nil)
      super(handle)
      @driver = driver
      @desc = desc
      @devices = devices

      @event_pools = {}
      @command_queues = {}
      @command_lists = {}
      @modules = {} #binaries for gpu
      @module_build_logs = {}
    end
  end

  class EventPool < Object
    @typename = 'event_pool'
    attr_reader :context
    attr_reader :desc
    attr_reader :devices
    attr_reader :events
    attr_reader :indices

    def initialize(handle, context, desc, devices = nil)
      super(handle)
      @context = context
      @desc = desc
      @devices = devices
      @events = {}
      @indices = Set.new(desc[:count].times.to_a)
    end
  end

  class Event < Object
    @typename = 'event'
    attr_reader :event_pool
    attr_reader :desc
    attr_accessor :signaled
    # ADDED: richer event state so we can model Level Zero event semantics.
    #   signaled_by - api-context string of whoever last signaled this event
    #                 (used only for diagnostic messages).
    #   observed    - whether the host has observed the signaled state since the
    #                 last signal (via zeEventHostSynchronize / a successful
    #                 zeEventQueryStatus / a device-wide synchronize). This lets
    #                 us tell a genuine concurrent double-signal (signaled but
    #                 never consumed) from a reuse-without-reset (signaled,
    #                 consumed by the host, then signaled again with no reset).
    attr_reader :signaled_by
    attr_reader :observed

    def initialize(handle, event_pool, desc)
      super(handle)
      @event_pool = event_pool
      @desc = desc
      #event can have 2 states, not signaled or signaled
      @signaled = false
      @signaled_by = nil
      @observed = false
    end

    # ADDED: move the event to the signaled state. `by` records who signaled it
    # (for messages). A fresh signal has not yet been observed by the host.
    def signal(by = nil)
      @signaled = true
      @signaled_by = by
      @observed = false
    end

    # ADDED: zeEventHostReset / zeCommandListAppendEventReset return the event to
    # the unsignaled state so it can be reused as a dependency again.
    def reset
      @signaled = false
      @signaled_by = nil
      @observed = false
    end

    # ADDED: record that the host observed the signaled state. Distinguishes a
    # later reuse-without-reset from a concurrent double-signal.
    def observe
      @observed = true
    end

    def signaled?
      @signaled
    end
  end

  class CommandQueue < Object
    @typename = 'command_queue'
    attr_reader :context
    attr_reader :device
    attr_reader :desc
    attr_reader :fences

    def initialize(handle, context, device, desc)
      super(handle)
      @context = context
      @device = device
      @desc = desc
      @fences = {}
      @valid_fences = Hash.new { |h, k| h[k] = true } #fences that have been reset or haven't been signaled
    end
  end

  class Fence < Object
    @typename = 'fence'
    attr_reader :command_queue
    attr_reader :desc
    attr_accessor :status
    attr_reader :not_signaled
    attr_reader :in_use
    attr_reader :signaled


    def initialize(handle, command_queue, desc)
      super(handle)
      @command_queue = command_queue
      @desc = desc
      @not_signaled = 0
      @in_use = 1
      @signaled = 2
      @status = @not_signaled
    end

  end

  class CommandList < Object
    @typename = 'command_list'
    attr_reader :context
    attr_reader :device
    attr_reader :desc
    attr_reader :altdesc
    attr_accessor :associated_command_queue
    attr_accessor :immediate
    attr_accessor :associated_ordinal
    # ADDED: true when the list was created with ZE_COMMAND_LIST_FLAG_IN_ORDER
    # (or, for immediate lists, ZE_COMMAND_QUEUE_FLAG_IN_ORDER). In-order lists
    # execute their appended ops strictly in append order -- op N+1 will not
    # start until op N completes -- so an earlier op that waits on an event only
    # a later op in the SAME list signals can never complete (an intra-list
    # deadlock the cross-list detector cannot see). See check_in_order_self_deadlock.
    attr_accessor :in_order
    # ADDED: ordered list of RecordedOp appended to this command list. It is
    # replayed when the list is executed on a queue, so that checks depending on
    # event completion (out-of-bounds copy, event-signal reuse) run at the point
    # the op would actually execute -- not at append or execute time.
    attr_accessor :ops
    @@INITIALIZED = 0 #created or being properly recycled
    @@CLOSED = 1
    @@DESTROYED = 2

    def initialize(handle, context, device, desc, altdesc)
      super(handle)
      @context = context
      @device = device
      @desc = desc
      @altdesc = altdesc
      @associated_command_queue = nil
      @status = @@INITIALIZED
      @immediate = false
      @associated_ordinal = 0
      @in_order = false # ADDED
      @api_calls = []
      @ops = [] # ADDED
    end

    def immediate?
      return !desc
    end
  end

  # ADDED: A single operation recorded when it is appended to a command list. It
  # snapshots everything the deferred checks need, because the trace's per-call
  # context (find_param) is gone by the time the op is replayed at execute time.
  #   kind   - :copy, :wait, :signal, :reset, :barrier, :ranges_barrier, :launch
  #   signal - handle of the completion event this op signals (nil/0 if none)
  #   waits  - event handles that must be signaled before this op can execute
  #   params - kind-specific data (copy: api/dst/src/size; reset: reset_handle;
  #            ranges_barrier: api/ctx_handle/ranges, where ranges is an array of
  #            {base:, size:} for each memory range the barrier covers)
  #   api    - the ZE API that appended this op (for diagnostics)
  class RecordedOp
    attr_reader :kind
    attr_reader :signal
    attr_reader :waits
    attr_reader :params
    attr_reader :api

    def initialize(kind, signal: 0, waits: [], params: {}, api: nil)
      @kind = kind
      #normalize a null (0) signal handle to nil so "does this op signal?" is a
      #simple truthiness test
      @signal = (signal && signal != 0) ? signal : nil
      @waits = waits || []
      @params = params
      @api = api || params[:api]
    end
  end

  # ADDED: One deferred-execution unit -- a single submitted command list whose
  # recorded ops are replayed cooperatively by the (non-concurrent) scheduler in
  # StateObject. Instead of a Ruby Fiber, execution state is an explicit integer
  # cursor into `ops`: the scheduler advances the cursor past every op whose
  # waits are satisfied, and leaves it parked on the first op that is still
  # blocked. `blocked_on` / `pending_signals` are the metadata the deadlock
  # detector uses to build a wait-for graph across units.
  #   ops             - snapshot (dup) of the list's ops for this execution
  #   context         - trace context captured at submit time
  #   label           - human label for messages (e.g. "command_list 0x..")
  #   cursor          - index of the next op to execute
  #   blocked_on      - event handles the current op is waiting for (or [])
  #   pending_signals - events this unit may still signal before it finishes
  class DeferredUnit
    attr_reader :ops
    attr_reader :context
    attr_reader :label
    attr_accessor :cursor
    attr_accessor :blocked_on
    attr_accessor :pending_signals
    # ADDED: whether the originating command list is in-order (see CommandList#in_order).
    # The intra-list self-deadlock check only applies to in-order units.
    attr_reader :in_order

    def initialize(ops, context, label, in_order: false)
      @ops = ops
      @context = context
      @label = label
      @cursor = 0
      @blocked_on = []
      @in_order = in_order # ADDED
      #every event this unit will eventually signal, for the wait-for graph
      @pending_signals = ops.map { |op| op.signal }.compact
    end

    # true once every op has executed
    def done?
      @cursor >= @ops.size
    end

    # the op the cursor currently points at (nil when done)
    def current_op
      @ops[@cursor]
    end
  end

  class Module < Object
    @typename = 'module'

    class BuildLog < Object
      @typename = 'module_build_log'
      attr_reader :module

      def initialize(handle, mod = nil)
        super(handle)
        @module = mod
      end
    end

    attr_reader :context
    attr_reader :device
    attr_reader :desc
    attr_accessor :build_log
    attr_reader :kernels

    def initialize(handle, context, device, desc)
      super(handle)
      @context = context
      @device = device
      @desc = desc
      @kernels = {}
    end
  end

  class Kernel < Object
    @typename = 'kernel'
    attr_reader :module
    attr_reader :desc
    attr_reader :name

    def initialize(handle, mod, desc, name)
      super(handle)
      @module = mod
      @desc = desc
      @name = name
    end
  end

  class ApiCall
    attr_reader :name
    attr_reader :params

    def initialize(name, params)
      @name = name
      @params = params
    end
  end

  class Thread
    attr_reader :vtid
    # CHANGED: was a single `last_entry` slot, which broke when a traced API
    # internally calls another traced API on the same thread (e.g.
    # zelLoaderDriverCheck calls zeInit): the inner entry clobbered the outer
    # frame and the outer _exit then failed check_last_entry. Modeling it as a
    # stack lets nested calls push/pop correctly; the top of stack is the
    # currently-executing call.
    attr_reader :call_stack

    def initialize(vtid)
      @vtid = vtid
      @call_stack = []
    end

    # the innermost in-flight ApiCall, or nil if the thread has none.
    # Kept as `last_entry` so existing callers (find_param, etc.) are unchanged.
    def last_entry
      @call_stack.last
    end
  end

  class Process
    attr_reader :vpid
    attr_reader :threads
    attr_reader :drivers
    attr_reader :devices
    attr_reader :contexts
    attr_reader :event_pools
    attr_reader :events
    attr_reader :command_queues
    attr_reader :fences
    attr_reader :command_lists
    attr_reader :modules
    attr_reader :module_build_logs
    # ADDED: address -> freed Memory objects (kept after zeMemFree) so a later
    # reference to a released address can be flagged as use-after-free.
    attr_reader :freed_memory_allocations
    # ADDED: both memory maps are nested by Level Zero context handle --
    # { ctx_handle => { address => Memory } } -- because the L0 unified virtual
    # address space only guarantees non-aliasing addresses WITHIN a context.
    # Two live allocations in different contexts may share a numeric address, so
    # a flat address-keyed map would let the second overwrite the first. Each
    # inner sub-map has the same shape as the old flat map, so code that already
    # holds a sub-map (allocations[ptr], .each_value, .delete) is unchanged.
    attr_reader :memory_allocations

    def initialize(vpid)
      @vpid = vpid
      @threads = Hash.new { |h, k| h[k] = Thread.new(k) }
      #can it model memory imports/exports??
      @drivers = {}
      @event_dependencies = {} #for detecting deadlocks
      @devices = {}
      @contexts = {}
      @event_pools = {}
      @events = {}
      @command_queues = {}
      @fences = {}
      @command_lists = {}
      @modules = {}
      @module_build_logs = {}
      @kernels = {}
      # CHANGED: nested by context handle -- ctx_handle -> { address -> Memory }.
      # Auto-vivify an empty sub-map on first use of a context so callers never
      # get nil for a context that has not allocated yet.
      @memory_allocations = Hash.new { |h, k| h[k] = {} }
      @freed_memory_allocations = Hash.new { |h, k| h[k] = {} } # ADDED: ctx -> {addr -> freed Memory}
      #@initCalled = false
    end

    def objects(type)
      instance_variable_get(:"@#{type}s")
    end
  end

  class Node
    attr_reader :name
    attr_reader :processes

    def initialize(name)
      @name = name
      @processes = Hash.new { |h, k| h[k] = Process.new(k) }
    end
  end

end