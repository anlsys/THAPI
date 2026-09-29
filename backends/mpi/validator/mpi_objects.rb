class MPIObject 
	attr_reader :base
	def initialize(base)
		@base = base
	end
end

Message = Struct.new(:context, :from, :to, :tag, :buffer_ptr, :dtype)
class Communicator < MPIObject
  attr_accessor :num_ranks
  attr_accessor :sends
  attr_accessor :recvs
  def initialize(base, num_ranks=1)
	super(base)
    @num_ranks = num_ranks
	@sends = {} 
	@recvs = {}
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

