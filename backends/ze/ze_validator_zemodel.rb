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
    attr_accessor :memory_allocations
    attr_accessor :property_fetched
    attr_accessor :cmd_queue_group_properties_queried
    def initialize(handle)
      super
      @sub_devices = []
      @memory_allocations = {}
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
    attr_reader :memtype

    def initialize(handle, context, size, memtype, memtypestr="shared")
      super(handle)
      @context = context
      @size = size
      @memtype = memtype
      @memtypestr = memtypestr
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
    
    def initialize(handle, event_pool, desc)
      super(handle)
      @event_pool = event_pool
      @desc = desc
      #event can have 2 states, not signaled or signaled
      @signaled = false
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
    @@INITIALIZED = 0 #for fence create or reset
    @@IN_USE = 1
    @@SIGNALED = 2 #signaled to the host
    @typename = 'fence'
    attr_reader :command_queue
    attr_reader :desc
    attr_accessor :command_queue_history

    def initialize(handle, command_queue, desc)
      super(handle)
      @command_queue = command_queue
      @desc = desc
      @status = @@INITIALIZED 
      @command_queue_history = []
    end

    #is it suitable to put this here?
    def self.get_fence(state,context,defi)
      fences = nil
      curr_fence = nil
      if defi['hFence']
        fences = state.find_objects(context, 'fence')
        curr_fence = fences[defi['hFence']]
      end
      return unless fences && curr_fence
      curr_fence
    end 
  end

  class CommandList < Object
    @typename = 'command_list'
    attr_reader :context
    attr_reader :device
    attr_reader :desc
    attr_reader :altdesc
    attr_accessor :associated_command_queue
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
    end

    def immediate?
      return !desc
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

    def initialize(handle, mod, desc)
      super(handle)
      @module = mod
      @desc = desc
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
    attr_accessor :last_entry

    def initialize(vtid)
      @vtid = vtid
      @last_entry = nil
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
      @memory_allocations = {}
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