require 'mpi/validator/mpi_objects'

$upon_entry = {}
$on_successful_exit = {}
$on_erroneous_exit = {}
# Events that are neither _entry nor _exit, keyed by full event name.
$on_other_event = {}


# Entry checks run before the call could crash: validate arguments here.
$upon_entry['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[payload['comm']]
  dest_rank = payload['dest']
  # An unknown communicator is already an error; without this `next` the
  # following line dereferences nil and takes the whole run down with
  # "undefined method `num_ranks' for nil".
  unless comm
    state.print_usage_error(context, "Unknown communicator: #{payload['comm']} at MPI_Send")
    next
  end
  state.print_usage_error(context, "Rank out-of-bounds for MPI_Send. Communicator #{comm} must be [0,#{comm.num_ranks-1}]") if comm.num_ranks <= dest_rank
}

$on_successful_exit['MPI_Send'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.get_thread(context).rank
  dest_rank = state.find_param(context, 'dest')
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  comm.send(context,src_rank,dest_rank,tag,buf_ptr,dtype)
}

# Careful with differentiating ranks/processes
# TODO: try to kill the process responsible for the application it self
# Is data race possible with just the Strong memory operations?? (get precise definition of strong in ptx)
# Create a tag for the ze_validator for AE  
$on_successful_exit['MPI_Comm_size']= lambda { |state, context, payload|
  size = payload['size_val']
  comm = state.find_param(context, 'comm')
  state.communicators[comm]= Communicator.new(payload['comm'], size)
  puts "size = #{size}"
}

$on_successful_exit['MPI_Comm_rank']=lambda { |state, context, payload|
  thread = state.get_thread(context)
  puts "payload for rank = #{payload}"
  thread.set_rank(payload['rank_val']) if payload['rank_val']
}

$upon_entry['MPI_Comm_rank']=lambda { |state, context, payload|
  puts "payload for rank (entry) = #{payload}"
}


$on_successful_exit['MPI_Recv'] = lambda { |state, context, payload|
  comm = state.communicators[state.find_param(context, 'comm')]
  next unless comm # unknown communicator already reported at entry
  src_rank = state.find_param(context, 'source')
  dest_rank = state.get_thread(context).rank
  buf_ptr = state.find_param(context, 'buf')
  tag = state.find_param(context, 'tag')
  dtype = state.find_param(context, 'datatype')
  comm.recv(context,src_rank,dest_rank,tag,buf_ptr,dtype)
}


$on_erroneous_exit.default = lambda { |state, context, payload|
  args = state.get_last_entry(context)&.params
  detail = args && !args.empty? ? " (args: #{args.inspect})" : ''
  state.print_error_return(
    context, "#{context['api']} returned #{payload['mpiResult']}#{detail}"
  )
}
