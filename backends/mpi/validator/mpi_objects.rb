class MPIObject 
	attr_reader :base
	def initialize(base)
		@base = base
	end
end

Message = Struct.new(:context, :from, :to, :tag, :buffer_ptr, :dtype)

InflightBuffer = Struct.new(:context, :api, :request, :base_addr, :upper_bound, :count,
                            :dtype, :timestamp, :peer, :tag) do
  
  def overlaps?(start, _end)
    (base_addr <= start  &&  _end < upper_bound) || (start <= base_addr && upper_bound < _end) 
  end

  # Byte offset and element index of an address inside the buffer, for
  # reporting: "data[20]" is far easier to act on than a raw address.
  def element_index(addr, elem_size)
    return nil if elem_size.nil? || elem_size.zero?

    (addr - base_addr) / elem_size
  end

  def size
    upper_bound - base_addr
  end
end

# MPICH encodes predefined handles as 0x4c......, with the element size in
# byte 2: MPI_INT = 0x4c000405 -> 4, MPI_DOUBLE = 0x4c00080b -> 8. Derived
# types (0xcc......) carry no size in the handle, so we return nil and the
# caller falls back to reporting byte offsets instead of element indices.
module MPIDatatype
  PREDEFINED_PREFIX = 0x4c
  DERIVED_PREFIX    = 0xcc

  def self.size(handle)
    return nil if handle.nil?

    ((handle >> 24) & 0xff) == PREDEFINED_PREFIX ? (handle >> 8) & 0xff : nil
  end

  def self.predefined?(handle)
    !handle.nil? && ((handle >> 24) & 0xff) == PREDEFINED_PREFIX
  end
end

class Communicator < MPIObject
  attr_accessor :num_ranks
  attr_accessor :sends
  attr_accessor :recvs
  attr_reader :user_buffer_addr
  attr_reader :user_buffer_size 
  def initialize(base, num_ranks=1)
	  super(base)
    @num_ranks = num_ranks
	  @sends = {} 
	  @recvs = {}
    @user_buffer_addr = nil
    @user_buffer_size = -1
  end

  def set_user_buffer(addr, size)
    @user_buffer_addr = addr
    @user_buffer_size = size
  end
 
  def free_user_buffer(addr)
    if addr == @user_buffer_addr
      @user_buffer_addr = nil
      @user_buffer_size = -1
    end
  end

  def make_key(context, counter)
	  hid = context['hostname']
	  pid = context['vpid']
	  tid = context['vtid']
  	"#{hid}-#{pid}-#{tid}-#{counter}"
  end 


  def send(context, from, to, tag, buffer, dtype)
	  key = make_key(context,@sends.size)
	  @sends[key]= Message.new(context,from,to,tag,buffer,dtype)
  end

  def recv(context, from, to, tag, buffer, dtype)
	  key = make_key(context,@recvs.size)
	  @recvs[key]= Message.new(context,from,to,tag,buffer,dtype)
  end   
end

