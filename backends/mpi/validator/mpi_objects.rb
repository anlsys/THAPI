# frozen_string_literal: true

# The MPI objects the validator models. Every one of them derives from
# MPIObject, which holds what all MPI objects share: the handle (or address)
# that names the object in the trace, and the call context that created it.
#
#   MPIObject
#   +-- Datatype             MPI_Datatype handle; element size of predefined types
#   +-- Buffer               user memory [base_addr, upper_bound)
#   +-- Communicator         MPI_Comm; ranks, recorded messages, attached buffer
#   +-- Message              one point-to-point message (send or receive side)
#   |   +-- PersistentMessage  a message set up by MPI_Send_init / MPI_Psend_init
#   +-- Request              MPI_Request and the buffers it owns while in flight
#       +-- NonblockingRequest   MPI_Isend, MPI_Irecv, MPI_Ibcast, ...: completes once
#       +-- PersistentRequest    MPI_Send_init, MPI_Recv_init, ...: start/complete cycles
#
# Objects only describe and answer questions about themselves; reporting is
# done by the StateObject and the callbacks.

class MPIObject
  attr_reader :handle, :context, :timestamp

  def initialize(handle, context: nil, timestamp: nil)
    @handle = handle
    @context = context
    @timestamp = timestamp || context&.fetch('timestamp', nil)
  end

  def self.hex(value) = value.nil? ? '?' : "0x#{value.to_s(16)}"

  # Human-readable name of the kind of object, e.g. "communicator".
  def self.kind_name = name.gsub(/([a-z])([A-Z])/, '\1 \2').downcase

  def kind_name = self.class.kind_name

  def hex_handle = MPIObject.hex(handle)

  # "host:vpid:vtid" of the call that created the object.
  def location
    return '?' unless context

    "#{context['hostname']}:#{context['vpid']}:#{context['vtid']}"
  end

  def to_s = "#{kind_name} #{hex_handle}"
end

# MPICH encodes predefined datatype handles as 0x4c......, with the element
# size in byte 2: MPI_INT = 0x4c000405 -> 4, MPI_DOUBLE = 0x4c00080b -> 8.
# Derived types (0xcc......) carry no size in the handle, so size is nil and
# callers fall back to byte offsets.
class Datatype < MPIObject
  PREDEFINED_PREFIX = 0x4c
  DERIVED_PREFIX    = 0xcc

  def self.predefined?(handle)
    !handle.nil? && ((handle >> 24) & 0xff) == PREDEFINED_PREFIX
  end

  def self.size(handle)
    predefined?(handle) ? (handle >> 8) & 0xff : nil
  end

  def predefined? = Datatype.predefined?(handle)

  def size = Datatype.size(handle)
end

# User memory handed to MPI: the half-open range [base_addr, upper_bound).
#   mode     'send' (MPI reads it), 'recv' (MPI writes it) or 'attached'
#            (MPI_Buffer_attach / MPI_Comm_attach_buffer)
#   request  the Request that owns the buffer while it is in flight, if any
class Buffer < MPIObject
  attr_reader :upper_bound, :count, :datatype, :mode, :api
  attr_accessor :request

  # Buffer for `count` elements of `datatype`, or nil when that cannot be
  # sized (null pointer, empty, derived datatype).
  def self.for_elements(addr, count, datatype, **opts)
    return nil if addr.nil? || addr.zero? || count.nil? || count <= 0

    elem = Datatype.size(datatype)
    return nil if elem.nil? || elem.zero?

    new(addr, count * elem, count: count, datatype: datatype, **opts)
  end

  def initialize(base_addr, size, count: nil, datatype: nil, mode: nil, api: nil,
                 request: nil, context: nil)
    super(base_addr, context: context)
    @upper_bound = base_addr + size
    @count = count
    @datatype = datatype
    @mode = mode
    @api = api
    @request = request
  end

  def base_addr = handle

  def size = upper_bound - base_addr

  def send? = mode == 'send'

  def recv? = mode == 'recv'

  # Does [start, stop) intersect the buffer?
  def overlaps?(start, stop)
    start < upper_bound && base_addr < stop
  end

  # The intersection of [start, stop) with the buffer, as [lo, hi).
  def intersection(start, stop)
    [[start, base_addr].max, [stop, upper_bound].min]
  end

  # Two buffers handed to MPI at the same time conflict when they intersect
  # and at least one is written by MPI. Concurrent sends from the same memory
  # are legal since MPI-3.
  def conflicts_with?(other)
    overlaps?(other.base_addr, other.upper_bound) && !(send? && other.send?)
  end

  # An application access to [start, stop) races with MPI if it touches a
  # receive buffer at all, or writes into a send buffer.
  def races_with_access?(start, stop, write:)
    overlaps?(start, stop) && (write || !send?)
  end

  # Element index (or nil) of an address, for reports: "element [20]" is far
  # easier to act on than a raw address.
  def element_index(addr)
    elem = Datatype.size(datatype)
    return nil if elem.nil? || elem.zero?

    (addr - base_addr) / elem
  end

  # "element [20]" or "offset +80"
  def position_of(addr)
    idx = element_index(addr)
    idx ? "element [#{idx}]" : "offset +#{addr - base_addr}"
  end

  def range_str = "[#{hex_handle}, #{MPIObject.hex(upper_bound)})"

  def to_s = "#{mode} buffer #{hex_handle} (#{size} bytes)"
end

# Shared by everything a user buffer can be attached to (the process, for
# MPI_Buffer_attach; a communicator, for MPI_Comm_attach_buffer).
module AttachedBufferOwner
  attr_reader :attached_buffer

  def set_user_buffer(addr, size)
    @attached_buffer = Buffer.new(addr, size, mode: 'attached')
  end

  def free_user_buffer(addr)
    @attached_buffer = nil if @attached_buffer&.base_addr == addr
  end

  def user_buffer_addr = @attached_buffer&.base_addr

  def user_buffer_size = @attached_buffer ? @attached_buffer.size : -1
end

# One point-to-point message, as seen from the side that recorded it. The
# handle is the user buffer address.
class Message < MPIObject
  attr_reader :from, :to, :tag, :datatype

  def initialize(context:, from:, to:, tag:, buffer_ptr:, datatype:)
    super(buffer_ptr, context: context)
    @from = from
    @to = to
    @tag = tag
    @datatype = datatype
  end

  def buffer_ptr = handle
end

# A message set up once by MPI_Send_init / MPI_Psend_init and sent each time
# its request is started.
class PersistentMessage < Message
  attr_reader :comm, :request, :partitions, :count
  attr_accessor :recv_initialized, :test_called

  def initialize(context:, buffer_ptr:, dest:, comm:, request:, count:, partitions: 0)
    super(context: context, from: nil, to: dest, tag: nil, buffer_ptr: buffer_ptr, datatype: nil)
    @comm = comm
    @request = request
    @partitions = partitions
    @count = count
    @recv_initialized = false
    @test_called = false
  end

  def dest = to
end

class Communicator < MPIObject
  include AttachedBufferOwner

  attr_accessor :participating_ranks, :sends, :recvs, :partitioned_messages, :bcasts
  # From MPI_Comm_size; nil until that is seen.
  attr_accessor :size

  def initialize(handle, context: nil)
    super
    @participating_ranks = Hash.new { |h, k| h[k] = nil }
    @sends = {}
    @recvs = {}
    @bcasts = {}
    @partitioned_messages = {}
  end

  # Number of ranks, for bounds checks. Unknown until MPI_Comm_size has been
  # seen; treated as unbounded then, so a bounds check cannot misfire.
  def num_ranks = size || Float::INFINITY

  # Rank of a process (by vpid), or nil if it never called MPI_Comm_rank on
  # this communicator. fetch, so that asking does not add an entry.
  def rank_of(vpid) = participating_ranks.fetch(vpid, nil)

  # Possible FN here because we differentiate message by the source, count, and type
  # We only check if a bcast message has been recorded by all the processes
  def record_bcast(context, caller_pid, source, buffer_count, buffer_type)
    key = "#{source}-#{buffer_count}-#{buffer_type}"
    @bcasts[key] ||= Hash.new { |h, k| h[k] = nil }
    @bcasts[key][caller_pid] = context
  end

  def make_key(context, counter)
    "#{context['hostname']}-#{context['vpid']}-#{context['vtid']}-#{counter}"
  end

  def send(context, from, to, tag, buffer, dtype)
    @sends[make_key(context, @sends.size)] =
      Message.new(context: context, from: from, to: to, tag: tag, buffer_ptr: buffer, datatype: dtype)
  end

  def recv(context, from, to, tag, buffer, dtype)
    @recvs[make_key(context, @recvs.size)] =
      Message.new(context: context, from: from, to: to, tag: tag, buffer_ptr: buffer, datatype: dtype)
  end
end

# An MPI_Request and the user buffers MPI owns while it is in flight.
#   slot     address of the application's MPI_Request variable (the `request`
#            argument of the creating call); how the array completion calls
#            (Waitall, Waitany, ...) are matched, since the tracer records only
#            the array's address
#   buffers  one Buffer per user buffer (Isendrecv has two); empty when the call
#            has no buffer or its datatype cannot be sized
#
# Subclasses differ in lifecycle: a NonblockingRequest is active from creation
# until completed and is then gone; a PersistentRequest is inactive until
# started, becomes inactive again on completion, and lives until freed.
class Request < MPIObject
  # Handle encoding. Under classic-ABI MPICH the tracer reads an 8-byte
  # MPI_Request (standard-ABI header) out of a 4-byte int, so the upper half
  # is whatever follows the handle in memory; only the low 32 bits count.
  CLASSIC_KIND_MASK = 0x3c000000
  CLASSIC_REQUEST   = 0x2c000000 # MPICH object kind "request"
  CLASSIC_NULL      = 0x2c000000
  STANDARD_NULL     = 0x180      # MPI-4.2 standard ABI

  def self.normalize(raw)
    return nil if raw.nil?

    low = raw & 0xffffffff
    (low & CLASSIC_KIND_MASK) == CLASSIC_REQUEST ? low : raw
  end

  def self.classic?(handle)
    !handle.nil? && handle <= 0xffffffff && (handle & CLASSIC_KIND_MASK) == CLASSIC_REQUEST
  end

  def self.null?(handle)
    handle.nil? || handle.zero? || handle == CLASSIC_NULL || handle == STANDARD_NULL
  end

  # sizeof(MPI_Request) in the application, inferred from the handle.
  def self.slot_size_for(handle) = classic?(handle) ? 4 : 8

  attr_reader :api, :slot, :buffers, :peer, :tag, :comm
  # uncertain: may have been completed by a call we could not resolve (e.g.
  # Waitany traced without indx_val); excluded from reports rather than guessed.
  attr_accessor :uncertain, :cancelled, :overwritten_by

  def initialize(handle, api:, context:, slot: nil, buffers: [], peer: nil, tag: nil, comm: nil)
    super(handle, context: context)
    @api = api
    @slot = slot
    @buffers = buffers
    @buffers.each { |b| b.request = self }
    @peer = peer
    @tag = tag
    @comm = comm
    @uncertain = false
    @cancelled = false
    @overwritten_by = nil
  end

  def active? = raise(NotImplementedError)

  def persistent? = false

  # Still needs a call from the application (completion or free).
  def live? = active?

  # In flight and known to be: what the buffer checks look at.
  def in_flight? = active? && !uncertain

  def in_flight_buffers = in_flight? ? buffers : []

  def slot_size = Request.slot_size_for(handle)

  def stored_at?(addr) = !slot.nil? && slot == addr

  # Is the MPI_Request variable inside the array [base, base + count)?
  def in_slot_range?(base, count)
    return false if slot.nil? || base.nil? || count.nil? || count <= 0

    slot >= base && slot < base + count * slot_size
  end

  def slot_index(base) = (slot - base) / slot_size

  # Completed by MPI_Wait*/MPI_Test*. Returns true when the request is gone
  # and must be dropped from the table.
  def complete! = raise(NotImplementedError)

  # Why MPI_Start may not be called on this request now, or nil if it may.
  def start_error = raise(NotImplementedError)

  def start!(context) = raise(NotImplementedError)

  def sends? = buffers.any?(&:send?)

  def to_s
    details = []
    details << "peer=#{peer}" unless peer.nil?
    details << "tag=#{tag}" unless tag.nil?
    details.concat(buffers.map(&:to_s))
    s = "#{api} request #{hex_handle}"
    details.empty? ? s : "#{s} (#{details.join(', ')})"
  end
end

class NonblockingRequest < Request
  def initialize(...)
    super
    @active = true
  end

  def active? = @active

  def complete!
    @active = false
    true
  end

  def start_error = 'which is not a persistent request'
end

class PersistentRequest < Request
  def initialize(...)
    super
    @active = false
  end

  def active? = @active

  def persistent? = true

  # A persistent request has to be freed even when inactive.
  def live? = true

  def complete!
    @active = false
    @uncertain = false
    false
  end

  def start_error
    return nil unless in_flight?

    'which is already active: it must be completed with MPI_Wait/MPI_Test before restarting'
  end

  def start!(context)
    @active = true
    @uncertain = false
    @cancelled = false
    @context = context
    @timestamp = context['timestamp']
  end
end
