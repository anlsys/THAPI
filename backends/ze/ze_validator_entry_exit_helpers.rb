require 'ze_validator_zemodel'
require 'ze_library'

def check_group_property_queued(state, ctx, device)
  #puts "device = #{device}"
  unless device.cmd_queue_group_properties_queried
    state.print_usage_error(ctx,"command queue group wasn't queried. Hardcoded group properties may break the code on different devices")   
  end
end

def check_memory_residency(state,ctx,defi,src_ptr, dst_ptr, api_name)
  if state.device_agnostic || state.performance
    memory_allocations =  state.find_objects(ctx, 'memory_allocation')
    dst_mem = memory_allocations[dst_ptr]
    src_mem = memory_allocations[src_ptr]

    if dst_mem && dst_mem.memtypestr == "device" && !dst_mem.resident
      if state.performance
        state.print_performance_issue(ctx, "ptr #{state.get_handle_str(defi['dstptr'])} might not be resident. Call zeContextMakeMemoryResident or zeContextMakeImageResident before #{api_name}")
      end
      if state.device_agnostic 
        state.print_usage_error(ctx, "ptr #{state.get_handle_str(defi['dstptr'])} might not be resident. Call zeContextMakeMemoryResident or zeContextMakeImageResident before #{api_name}")   
      end
    elsif src_mem != dst_mem && src_mem && src_mem.memtypestr == "device" && !src_mem.resident
      if state.performance
        state.print_performance_issue(ctx, "ptr #{state.get_handle_str(defi['srcptr'])} might not be resident. Call zeContextMakeMemoryResident or zeContextMakeImageResident before #{api_name}") 
      end
      if state.device_agnostic
        state.print_usage_error(ctx, "ptr #{state.get_handle_str(defi['srcptr'])} might not be resident. Call zeContextMakeMemoryResident or zeContextMakeImageResident before #{api_name}") 
      end 
    end 
  end
end

def check_valid_ordinal(state, ctx, defi, cqg_ordinal)
  #hardcoded for now, change it once the trace can output which ordinals are computes
  if cqg_ordinal != 0 && state.print_tracker["zeCommandListAppendLaunchKernel::K2CopyOrdinal"] == 0
    state.print_tracker["zeCommandListAppendLaunchKernel::K2CopyOrdinal"] = 1
    state.print_usage_error(ctx, "Launching kernel to a command list with Copy Ordinal: #{state.get_handle_str(defi['hCommandList'])}")
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
  curr_fence = ZEModel::Fence.get_fence(state,ctx,defi)
  if curr_fence
    if curr_fence.status == ZEModel::Fence.class_variable_get(:@@SIGNALED)
      state.print_usage_error(ctx, "Used fence: #{state.get_handle_str(defi['hFence'])} twice without resetting it")
    elsif curr_fence.status == ZEModel::Fence.class_variable_get(:@@IN_USE)
      state.print_usage_error(ctx, "Used fence: #{state.get_handle_str(defi['hFence'])} twice on two or more commandQueues")
    end
    curr_fence.status = ZEModel::Fence.class_variable_get(:@@IN_USE)
  end 
end 

def check_valid_command_list(state, ctx, defi)
  #check if commanlist is not null
  pclv = defi['phCommandLists_vals']
  if pclv.nil? || pclv.empty?
    state.print_usage_error(ctx, "No commandlist was chosen for: #{state.get_handle_str(defi['hCommandQueue'])}")
  end 
  command_lists = state.find_objects(ctx, 'command_list')
  #command list must not be immediate
  pclv.each do |pclv_el|
	if command_lists[pclv_el] && command_lists[pclv_el].immediate
    	state.print_usage_error(ctx, "Immediate Command List was chosen for the Command Queue: #{state.get_handle_str(defi['hCommandQueue'])}")
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

def record_copy_over(state,ctx,ptr1,ptr2)
  if ptr1 != 0
    state.memory_in_transit[ctx['vpid']] << [ptr1, "src"]
  end
  if ptr2 != 0
    state.memory_in_transit[ctx['vpid']] << [ptr2, "dst"]
  end
end

def check_copy_over_data_race(state,ctx,src_ptr,dst_ptr)
	memory_allocations =  state.find_objects(ctx, 'memory_allocation')
	src = memory_allocations[src_ptr]
	dst = memory_allocations[dst_ptr]
  #puts "src = #{src}"
  #puts "dst = #{dst}"
	pid = ctx['vpid']
	state.memory_in_transit[pid].each do |transit_info|
    overlap_region = get_memory_overlap(src,memory_allocations[transit_info[0]])
		if transit_info[1] == "dst" && !overlap_region.empty?
			state.print_usage_error(ctx, "Potential Data Race on memory #{state.get_handle_str(overlap_region[0])} ~ #{state.get_handle_str(overlap_region[1])}")
		end

    overlap_region = get_memory_overlap(dst,memory_allocations[transit_info[0]])
		if (transit_info[1] == "dst" || transit_info[1] == "src") && !overlap_region.empty?
			state.print_usage_error(ctx, "Potential Data Race on memory #{state.get_handle_str(overlap_region[0])} ~ #{state.get_handle_str(overlap_region[1])}")
		end
	end
end

def check_command_list_closed(state, ctx, defi)
  pclv = defi['phCommandLists_vals']
  command_lists = state.find_objects(ctx, 'command_list')
  pclv.each do |cl|
    cmd_list = command_lists[cl]
    if cmd_list.status == ZEModel::CommandList.class_variable_get(:@@INITIALIZED)
      state.print_usage_error(ctx, "commandlist: #{state.get_handle_str(cl)} wasn't closed before executing on #{state.get_handle_str(defi['hCommandQueue'])}") 
    elsif cmd_list.status == ZEModel::CommandList.class_variable_get(:@@DESTROYED)
      state.print_usage_error(ctx, "commandlist: #{state.get_handle_str(cl)} was already destroyed #{state.get_handle_str(defi['hCommandQueue'])}") 
    end
  end
end


def check_valid_module(state,ctx,defi)
  if defi['hModule'] == 0
    state.print_usage_error(ctx, "Improper hModule was handed")
  end
end

def check_oob_memory_copy(state,ctx,defi)
  src_ptr = defi['srcptr']
  dst_ptr = defi['dstptr']
  cpy_size = defi['size']
  memory_allocations =  state.find_objects(ctx, 'memory_allocation')
  dst_mem = memory_allocations[dst_ptr]
  src_mem = memory_allocations[src_ptr]
  #puts "dst = #{dst_mem}, #{src_mem}"
  if dst_mem && dst_mem.size < cpy_size
      state.print_usage_error(ctx, "destination memory: #{dst_ptr} only has #{dst_mem.size} bytes allocated but zeCommandListAppendMemoryCopy is trying to copy #{cpy_size} bytes")
  end 

  if src_mem && src_mem.size < cpy_size
     state.print_usage_error(ctx, "source memory: #{src_ptr} only has #{src_mem.size} bytes allocated but zeCommandListAppendMemoryCopy is trying to copy #{cpy_size} bytes")
  end 
end

def check_struct_stype_misuse(state,ctx,expected_stype, observed_stype)
  if state.device_agnostic && expected_stype != observed_stype
      state.print_usage_error(ctx,"\nExpected stype of #{expected_stype}\nbut #{observed_stype} was observed.")
  end
end