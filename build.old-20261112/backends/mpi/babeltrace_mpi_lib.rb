require_relative 'mpi_library.rb'
$event_lambdas["lttng_ust_mpi:MPI_Abort_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Abort_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{"0x%016x" % defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errorclass_val: #{defi["errorclass_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_code_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{defi["errorclass"]}"
  s << ', '
  s << "errorcode: #{"0x%016x" % defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_code_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errorcode_val: #{defi["errorcode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "string: #{"0x%016x" % defi["string"]}"
  s << ', '
  s << "string_val: #{defi["string_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Add_error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allgatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alloc_mem_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alloc_mem_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Allreduce_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoall_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Alltoallw_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_put_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Attr_put_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Barrier_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Barrier_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Barrier_init_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Barrier_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bcast_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Bsend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_attach_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_attach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_attach_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_attach_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_detach_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_detach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_detach_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_detach_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_flush_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_flush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_iflush_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Buffer_iflush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cancel_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cancel_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_coords_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "maxdims: #{defi["maxdims"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_coords_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_cart: #{"0x%016x" % defi["comm_cart"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "comm_cart_val: #{"0x%016x" % defi["comm_cart_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxdims: #{defi["maxdims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_map_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "newrank: #{"0x%016x" % defi["newrank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_map_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newrank_val: #{defi["newrank_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "rank_val: #{defi["rank_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_shift_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "direction: #{defi["direction"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << ', '
  s << "rank_source: #{"0x%016x" % defi["rank_source"]}"
  s << ', '
  s << "rank_dest: #{"0x%016x" % defi["rank_dest"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_shift_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "rank_source_val: #{defi["rank_source_val"]}"
  s << ', '
  s << "rank_dest_val: #{defi["rank_dest_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_sub_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "remain_dims: #{"0x%016x" % defi["remain_dims"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cart_sub_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cartdim_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "ndims: #{"0x%016x" % defi["ndims"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Cartdim_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "ndims_val: #{defi["ndims_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Close_port_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Close_port_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_accept_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_accept_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_attach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_attach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_attach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_attach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_compare_entry"] = lambda { |defi|
  s = "{ "
  s << "comm1: #{"0x%016x" % defi["comm1"]}"
  s << ', '
  s << "comm2: #{"0x%016x" % defi["comm2"]}"
  s << ', '
  s << "result: #{"0x%016x" % defi["result"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_compare_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "result_val: #{defi["result_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_connect_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_connect_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_errhandler_fn: #{"0x%016x" % defi["comm_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "comm_errhandler_fn_val: #{"0x%016x" % defi["comm_errhandler_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_from_group_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "stringtag: #{"0x%016x" % defi["stringtag"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "stringtag_val: #{defi["stringtag_val"].inspect}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_from_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_copy_attr_fn: #{"0x%016x" % defi["comm_copy_attr_fn"]}"
  s << ', '
  s << "comm_delete_attr_fn: #{"0x%016x" % defi["comm_delete_attr_fn"]}"
  s << ', '
  s << "comm_keyval: #{"0x%016x" % defi["comm_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "comm_copy_attr_fn_val: #{"0x%016x" % defi["comm_copy_attr_fn_val"]}"
  s << ', '
  s << "comm_delete_attr_fn_val: #{"0x%016x" % defi["comm_delete_attr_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "comm_keyval_val: #{defi["comm_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_detach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_detach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_detach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_detach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_disconnect_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_val: #{"0x%016x" % defi["comm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_disconnect_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_dup_with_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_dup_with_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_flush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_flush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_free_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_val: #{"0x%016x" % defi["comm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_keyval: #{"0x%016x" % defi["comm_keyval"]}"
  s << ', '
  s << "comm_keyval_val: #{defi["comm_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_name: #{"0x%016x" % defi["comm_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "comm_name_val: #{defi["comm_name_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_parent_entry"] = lambda { |defi|
  s = "{ "
  s << "parent: #{"0x%016x" % defi["parent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_get_parent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "parent_val: #{"0x%016x" % defi["parent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "group_val: #{"0x%016x" % defi["group_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_idup_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_idup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_idup_with_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_idup_with_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_iflush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_iflush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_join_entry"] = lambda { |defi|
  s = "{ "
  s << "fd: #{defi["fd"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_join_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "intercomm_val: #{"0x%016x" % defi["intercomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "rank_val: #{defi["rank_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_remote_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_remote_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "group_val: #{"0x%016x" % defi["group_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_remote_size_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_remote_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_name: #{"0x%016x" % defi["comm_name"]}"
  s << ', '
  s << "comm_name_val: #{defi["comm_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_size_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_spawn_entry"] = lambda { |defi|
  s = "{ "
  s << "command: #{"0x%016x" % defi["command"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "maxprocs: #{defi["maxprocs"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "array_of_errcodes: #{"0x%016x" % defi["array_of_errcodes"]}"
  s << ', '
  s << "command_val: #{defi["command_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_spawn_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "intercomm_val: #{"0x%016x" % defi["intercomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_spawn_multiple_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_commands: #{"0x%016x" % defi["array_of_commands"]}"
  s << ', '
  s << "array_of_argv: #{"0x%016x" % defi["array_of_argv"]}"
  s << ', '
  s << "array_of_maxprocs: #{"0x%016x" % defi["array_of_maxprocs"]}"
  s << ', '
  s << "array_of_info: #{"0x%016x" % defi["array_of_info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "array_of_errcodes: #{"0x%016x" % defi["array_of_errcodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_spawn_multiple_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "intercomm_val: #{"0x%016x" % defi["intercomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_split_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "color: #{defi["color"]}"
  s << ', '
  s << "key: #{defi["key"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_split_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_split_type_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "split_type: #{defi["split_type"]}"
  s << ', '
  s << "key: #{defi["key"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_split_type_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newcomm_val: #{"0x%016x" % defi["newcomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_test_inter_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_test_inter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Compare_and_swap_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "compare_addr: #{"0x%016x" % defi["compare_addr"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Compare_and_swap_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dims_create_entry"] = lambda { |defi|
  s = "{ "
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dims_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "degrees: #{"0x%016x" % defi["degrees"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "weights: #{"0x%016x" % defi["weights"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_dist_graph: #{"0x%016x" % defi["comm_dist_graph"]}"
  s << ', '
  s << "comm_dist_graph_val: #{"0x%016x" % defi["comm_dist_graph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_create_adjacent_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "indegree: #{defi["indegree"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "sourceweights: #{"0x%016x" % defi["sourceweights"]}"
  s << ', '
  s << "outdegree: #{defi["outdegree"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "destweights: #{"0x%016x" % defi["destweights"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_dist_graph: #{"0x%016x" % defi["comm_dist_graph"]}"
  s << ', '
  s << "comm_dist_graph_val: #{"0x%016x" % defi["comm_dist_graph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_create_adjacent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_neighbors_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxindegree: #{defi["maxindegree"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "sourceweights: #{"0x%016x" % defi["sourceweights"]}"
  s << ', '
  s << "maxoutdegree: #{defi["maxoutdegree"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "destweights: #{"0x%016x" % defi["destweights"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_neighbors_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_neighbors_count_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "indegree: #{"0x%016x" % defi["indegree"]}"
  s << ', '
  s << "outdegree: #{"0x%016x" % defi["outdegree"]}"
  s << ', '
  s << "weighted: #{"0x%016x" % defi["weighted"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Dist_graph_neighbors_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "indegree_val: #{defi["indegree_val"]}"
  s << ', '
  s << "outdegree_val: #{defi["outdegree_val"]}"
  s << ', '
  s << "weighted_val: #{defi["weighted_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_free_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "errorclass: #{"0x%016x" % defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errorclass_val: #{defi["errorclass_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "string: #{"0x%016x" % defi["string"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "string_val: #{defi["string_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Exscan_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Fetch_and_op_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Fetch_and_op_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_close_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "fh_val: #{"0x%016x" % defi["fh_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_close_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file_errhandler_fn: #{"0x%016x" % defi["file_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "file_errhandler_fn_val: #{"0x%016x" % defi["file_errhandler_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "filename: #{"0x%016x" % defi["filename"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "filename_val: #{defi["filename_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_amode_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "amode: #{"0x%016x" % defi["amode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_amode_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "amode_val: #{defi["amode_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_atomicity_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_atomicity_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_byte_offset_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "disp: #{"0x%016x" % defi["disp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_byte_offset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "disp_val: #{defi["disp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_group_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "group_val: #{"0x%016x" % defi["group_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_position_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_position_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "offset_val: #{defi["offset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_position_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_position_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "offset_val: #{defi["offset_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_size_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_type_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_type_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "extent_val: #{defi["extent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_type_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_type_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_view_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "disp: #{"0x%016x" % defi["disp"]}"
  s << ', '
  s << "etype: #{"0x%016x" % defi["etype"]}"
  s << ', '
  s << "filetype: #{"0x%016x" % defi["filetype"]}"
  s << ', '
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_get_view_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "disp_val: #{defi["disp_val"]}"
  s << ', '
  s << "etype_val: #{"0x%016x" % defi["etype_val"]}"
  s << ', '
  s << "filetype_val: #{"0x%016x" % defi["filetype_val"]}"
  s << ', '
  s << "datarep_val: #{defi["datarep_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iread_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_iwrite_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_open_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "filename: #{"0x%016x" % defi["filename"]}"
  s << ', '
  s << "amode: #{defi["amode"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "filename_val: #{defi["filename_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_open_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "fh_val: #{"0x%016x" % defi["fh_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_preallocate_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_preallocate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_at_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_ordered_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_read_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_seek_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "whence: #{defi["whence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_seek_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_seek_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "whence: #{defi["whence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_seek_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_atomicity_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_atomicity_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_size_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_view_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << ', '
  s << "etype: #{"0x%016x" % defi["etype"]}"
  s << ', '
  s << "filetype: #{"0x%016x" % defi["filetype"]}"
  s << ', '
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "datarep_val: #{defi["datarep_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_set_view_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_sync_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_sync_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_at_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_ordered_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_write_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Finalize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Finalized_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Finalized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Free_mem_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Free_mem_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Gatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_address_entry"] = lambda { |defi|
  s = "{ "
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "address: #{"0x%016x" % defi["address"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_address_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "address_val: #{defi["address_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_count_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_count_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_count_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_x_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_elements_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_hw_resource_info_entry"] = lambda { |defi|
  s = "{ "
  s << "hw_info: #{"0x%016x" % defi["hw_info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_hw_resource_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "hw_info_val: #{"0x%016x" % defi["hw_info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_library_version_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{"0x%016x" % defi["version"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_library_version_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "version_val: #{defi["version_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_processor_name_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_processor_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_version_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{"0x%016x" % defi["version"]}"
  s << ', '
  s << "subversion: #{"0x%016x" % defi["subversion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Get_version_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "version_val: #{defi["version_val"]}"
  s << ', '
  s << "subversion_val: #{defi["subversion_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_graph: #{"0x%016x" % defi["comm_graph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "comm_graph_val: #{"0x%016x" % defi["comm_graph_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxindex: #{defi["maxindex"]}"
  s << ', '
  s << "maxedges: #{defi["maxedges"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_map_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << ', '
  s << "newrank: #{"0x%016x" % defi["newrank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_map_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newrank_val: #{defi["newrank_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_neighbors_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "maxneighbors: #{defi["maxneighbors"]}"
  s << ', '
  s << "neighbors: #{"0x%016x" % defi["neighbors"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_neighbors_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_neighbors_count_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "nneighbors: #{"0x%016x" % defi["nneighbors"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graph_neighbors_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "nneighbors_val: #{defi["nneighbors_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graphdims_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "nnodes: #{"0x%016x" % defi["nnodes"]}"
  s << ', '
  s << "nedges: #{"0x%016x" % defi["nedges"]}"
  s << ', '
  s << "nnodes_val: #{defi["nnodes_val"]}"
  s << ', '
  s << "nedges_val: #{defi["nedges_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Graphdims_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Grequest_complete_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Grequest_complete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Grequest_start_entry"] = lambda { |defi|
  s = "{ "
  s << "query_fn: #{"0x%016x" % defi["query_fn"]}"
  s << ', '
  s << "free_fn: #{"0x%016x" % defi["free_fn"]}"
  s << ', '
  s << "cancel_fn: #{"0x%016x" % defi["cancel_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "query_fn_val: #{"0x%016x" % defi["query_fn_val"]}"
  s << ', '
  s << "free_fn_val: #{"0x%016x" % defi["free_fn_val"]}"
  s << ', '
  s << "cancel_fn_val: #{"0x%016x" % defi["cancel_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Grequest_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_compare_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "result: #{"0x%016x" % defi["result"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_compare_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "result_val: #{defi["result_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_difference_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_difference_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_excl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks: #{"0x%016x" % defi["ranks"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_excl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_free_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "group_val: #{"0x%016x" % defi["group_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_from_session_pset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << ', '
  s << "pset_name_val: #{defi["pset_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_from_session_pset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_incl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks: #{"0x%016x" % defi["ranks"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_incl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_intersection_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_intersection_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_range_excl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranges: #{"0x%016x" % defi["ranges"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_range_excl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_range_incl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranges: #{"0x%016x" % defi["ranges"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_range_incl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "rank_val: #{defi["rank_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_size_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_translate_ranks_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks1: #{"0x%016x" % defi["ranks1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "ranks2: #{"0x%016x" % defi["ranks2"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_translate_ranks_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_union_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_union_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newgroup_val: #{"0x%016x" % defi["newgroup_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallreduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallreduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallreduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iallreduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ialltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibcast_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibcast_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibcast_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibcast_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ibsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iexscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iexscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iexscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iexscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Igatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Improbe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Improbe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "message_val: #{"0x%016x" % defi["message_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Imrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "message_val: #{"0x%016x" % defi["message_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Imrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Imrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Imrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ineighbor_alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_create_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_create_env_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_create_env_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newinfo: #{"0x%016x" % defi["newinfo"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newinfo_val: #{"0x%016x" % defi["newinfo_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_free_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "valuelen: #{defi["valuelen"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_nkeys_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "nkeys: #{"0x%016x" % defi["nkeys"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_nkeys_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "nkeys_val: #{defi["nkeys_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_nthkey_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_nthkey_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_string_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "buflen: #{"0x%016x" % defi["buflen"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << ', '
  s << "buflen_val: #{defi["buflen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_valuelen_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "valuelen: #{"0x%016x" % defi["valuelen"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_get_valuelen_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "valuelen_val: #{defi["valuelen_val"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_set_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "key_val: #{defi["key_val"].inspect}"
  s << ', '
  s << "value_val: #{defi["value_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_set_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Init_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{"0x%016x" % defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "argc_val: #{defi["argc_val"]}"
  s << ', '
  s << "argv_val: #{"0x%016x" % defi["argv_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Init_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{"0x%016x" % defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "required: #{defi["required"]}"
  s << ', '
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << ', '
  s << "argc_val: #{defi["argc_val"]}"
  s << ', '
  s << "argv_val: #{"0x%016x" % defi["argv_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Init_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "provided_val: #{defi["provided_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Initialized_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Initialized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_create_entry"] = lambda { |defi|
  s = "{ "
  s << "local_comm: #{"0x%016x" % defi["local_comm"]}"
  s << ', '
  s << "local_leader: #{defi["local_leader"]}"
  s << ', '
  s << "peer_comm: #{"0x%016x" % defi["peer_comm"]}"
  s << ', '
  s << "remote_leader: #{defi["remote_leader"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "newintercomm: #{"0x%016x" % defi["newintercomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newintercomm_val: #{"0x%016x" % defi["newintercomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_create_from_groups_entry"] = lambda { |defi|
  s = "{ "
  s << "local_group: #{"0x%016x" % defi["local_group"]}"
  s << ', '
  s << "local_leader: #{defi["local_leader"]}"
  s << ', '
  s << "remote_group: #{"0x%016x" % defi["remote_group"]}"
  s << ', '
  s << "remote_leader: #{defi["remote_leader"]}"
  s << ', '
  s << "stringtag: #{"0x%016x" % defi["stringtag"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "newintercomm: #{"0x%016x" % defi["newintercomm"]}"
  s << ', '
  s << "stringtag_val: #{defi["stringtag_val"].inspect}"
  s << ', '
  s << "newintercomm_val: #{"0x%016x" % defi["newintercomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_create_from_groups_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_merge_entry"] = lambda { |defi|
  s = "{ "
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "high: #{defi["high"]}"
  s << ', '
  s << "newintracomm: #{"0x%016x" % defi["newintracomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Intercomm_merge_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newintracomm_val: #{"0x%016x" % defi["newintracomm_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iprobe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iprobe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_block_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ireduce_scatter_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Irsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Is_thread_main_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Is_thread_main_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatterv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatterv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatterv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Iscatterv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_replace_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_replace_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_replace_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Isendrecv_replace_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Issend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Issend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Issend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Issend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Keyval_create_entry"] = lambda { |defi|
  s = "{ "
  s << "copy_fn: #{"0x%016x" % defi["copy_fn"]}"
  s << ', '
  s << "delete_fn: #{"0x%016x" % defi["delete_fn"]}"
  s << ', '
  s << "keyval: #{"0x%016x" % defi["keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "copy_fn_val: #{"0x%016x" % defi["copy_fn_val"]}"
  s << ', '
  s << "delete_fn_val: #{"0x%016x" % defi["delete_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Keyval_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "keyval_val: #{defi["keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Keyval_free_entry"] = lambda { |defi|
  s = "{ "
  s << "keyval: #{"0x%016x" % defi["keyval"]}"
  s << ', '
  s << "keyval_val: #{defi["keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Keyval_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Lookup_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "service_name_val: #{defi["service_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Lookup_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mprobe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mprobe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "message_val: #{"0x%016x" % defi["message_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "message_val: #{"0x%016x" % defi["message_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Mrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_allgatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoall_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Neighbor_alltoallw_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_commutative_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "commute: #{"0x%016x" % defi["commute"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_commutative_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "commute_val: #{defi["commute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_create_entry"] = lambda { |defi|
  s = "{ "
  s << "user_fn: #{"0x%016x" % defi["user_fn"]}"
  s << ', '
  s << "commute: #{defi["commute"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "user_fn_val: #{"0x%016x" % defi["user_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "op_val: #{"0x%016x" % defi["op_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_create_c_entry"] = lambda { |defi|
  s = "{ "
  s << "user_fn: #{"0x%016x" % defi["user_fn"]}"
  s << ', '
  s << "commute: #{defi["commute"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_create_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_free_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "op_val: #{"0x%016x" % defi["op_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Open_port_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Open_port_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "position_val: #{defi["position_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "datarep_val: #{defi["datarep_val"].inspect}"
  s << ', '
  s << "position_val: #{defi["position_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_size_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "datarep_val: #{defi["datarep_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_external_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_size_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pack_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Parrived_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "partition: #{defi["partition"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Parrived_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pcontrol_entry"] = lambda { |defi|
  s = "{ "
  s << "level: #{defi["level"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pcontrol_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_entry"] = lambda { |defi|
  s = "{ "
  s << "partition: #{defi["partition"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_list_entry"] = lambda { |defi|
  s = "{ "
  s << "length: #{defi["length"]}"
  s << ', '
  s << "array_of_partitions: #{"0x%016x" % defi["array_of_partitions"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_list_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_range_entry"] = lambda { |defi|
  s = "{ "
  s << "partition_low: #{defi["partition_low"]}"
  s << ', '
  s << "partition_high: #{defi["partition_high"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Pready_range_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Precv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "partitions: #{defi["partitions"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Precv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Probe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Probe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Psend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "partitions: #{defi["partitions"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Psend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Publish_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "service_name_val: #{defi["service_name_val"].inspect}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Publish_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Put_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Put_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Put_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Put_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Query_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Query_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "provided_val: #{defi["provided_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Raccumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Raccumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Raccumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Raccumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Recv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_local_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "inoutbuf: #{"0x%016x" % defi["inoutbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_local_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_local_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "inoutbuf: #{"0x%016x" % defi["inoutbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_local_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_block_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Reduce_scatter_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Register_datarep_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "read_conversion_fn: #{"0x%016x" % defi["read_conversion_fn"]}"
  s << ', '
  s << "write_conversion_fn: #{"0x%016x" % defi["write_conversion_fn"]}"
  s << ', '
  s << "dtype_file_extent_fn: #{"0x%016x" % defi["dtype_file_extent_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "datarep_val: #{defi["datarep_val"].inspect}"
  s << ', '
  s << "read_conversion_fn_val: #{"0x%016x" % defi["read_conversion_fn_val"]}"
  s << ', '
  s << "write_conversion_fn_val: #{"0x%016x" % defi["write_conversion_fn_val"]}"
  s << ', '
  s << "dtype_file_extent_fn_val: #{"0x%016x" % defi["dtype_file_extent_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Register_datarep_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Register_datarep_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "read_conversion_fn: #{"0x%016x" % defi["read_conversion_fn"]}"
  s << ', '
  s << "write_conversion_fn: #{"0x%016x" % defi["write_conversion_fn"]}"
  s << ', '
  s << "dtype_file_extent_fn: #{"0x%016x" % defi["dtype_file_extent_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Register_datarep_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_code_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_code_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Remove_error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_free_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_all_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_any_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_any_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_some_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_get_status_some_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "outcount_val: #{defi["outcount_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rget_accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rput_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rput_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rput_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rput_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Rsend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scan_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatter_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Scatterv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Send_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_replace_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_replace_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_replace_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Sendrecv_replace_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_attach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_attach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_attach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_attach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session_errhandler_fn: #{"0x%016x" % defi["session_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "session_errhandler_fn_val: #{"0x%016x" % defi["session_errhandler_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_detach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_detach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_detach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_detach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_finalize_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "session_val: #{"0x%016x" % defi["session_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_flush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_flush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_nth_pset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "pset_len: #{"0x%016x" % defi["pset_len"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << ', '
  s << "pset_len_val: #{defi["pset_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_nth_pset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "pset_name_val: #{defi["pset_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_num_psets_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "npset_names: #{"0x%016x" % defi["npset_names"]}"
  s << ', '
  s << "npset_names_val: #{defi["npset_names_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_num_psets_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_pset_info_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "pset_name_val: #{defi["pset_name_val"].inspect}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_get_pset_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_iflush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_iflush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_init_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "session_val: #{"0x%016x" % defi["session_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Ssend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Start_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Startall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Startall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_error_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "error: #{"0x%016x" % defi["error"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_error_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "error_val: #{defi["error_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_source_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "source: #{"0x%016x" % defi["source"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "source_val: #{defi["source_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_tag_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "tag: #{"0x%016x" % defi["tag"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_get_tag_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "tag_val: #{defi["tag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_cancelled_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_cancelled_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_x_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_elements_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_error_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "error: #{defi["error"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_error_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_source_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_tag_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_set_tag_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Test_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Test_cancelled_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Test_cancelled_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testany_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testany_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "indx_val: #{defi["indx_val"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testsome_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Testsome_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "outcount_val: #{defi["outcount_val"]}"
  s << ', '
  s << "array_of_indices_vals: #{defi["array_of_indices_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Topo_test_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "status_val: #{defi["status_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Topo_test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_commit_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "datatype_val: #{"0x%016x" % defi["datatype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_commit_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_contiguous_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_contiguous_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_contiguous_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_contiguous_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_darray_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_gsizes: #{"0x%016x" % defi["array_of_gsizes"]}"
  s << ', '
  s << "array_of_distribs: #{"0x%016x" % defi["array_of_distribs"]}"
  s << ', '
  s << "array_of_dargs: #{"0x%016x" % defi["array_of_dargs"]}"
  s << ', '
  s << "array_of_psizes: #{"0x%016x" % defi["array_of_psizes"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_darray_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_darray_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_gsizes: #{"0x%016x" % defi["array_of_gsizes"]}"
  s << ', '
  s << "array_of_distribs: #{"0x%016x" % defi["array_of_distribs"]}"
  s << ', '
  s << "array_of_dargs: #{"0x%016x" % defi["array_of_dargs"]}"
  s << ', '
  s << "array_of_psizes: #{"0x%016x" % defi["array_of_psizes"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_darray_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_complex_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{defi["p"]}"
  s << ', '
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_complex_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_integer_entry"] = lambda { |defi|
  s = "{ "
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_integer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_real_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{defi["p"]}"
  s << ', '
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_f90_real_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_block_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hindexed_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hvector_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hvector_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hvector_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_hvector_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_indexed_block_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_indexed_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_indexed_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_indexed_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "type_copy_attr_fn: #{"0x%016x" % defi["type_copy_attr_fn"]}"
  s << ', '
  s << "type_delete_attr_fn: #{"0x%016x" % defi["type_delete_attr_fn"]}"
  s << ', '
  s << "type_keyval: #{"0x%016x" % defi["type_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "type_copy_attr_fn_val: #{"0x%016x" % defi["type_copy_attr_fn_val"]}"
  s << ', '
  s << "type_delete_attr_fn_val: #{"0x%016x" % defi["type_delete_attr_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "type_keyval_val: #{defi["type_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_resized_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "lb: #{defi["lb"]}"
  s << ', '
  s << "extent: #{defi["extent"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_resized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_resized_c_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "lb: #{defi["lb"]}"
  s << ', '
  s << "extent: #{defi["extent"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_resized_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_struct_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "array_of_types: #{"0x%016x" % defi["array_of_types"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_struct_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_struct_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "array_of_types: #{"0x%016x" % defi["array_of_types"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_struct_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_subarray_entry"] = lambda { |defi|
  s = "{ "
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_sizes: #{"0x%016x" % defi["array_of_sizes"]}"
  s << ', '
  s << "array_of_subsizes: #{"0x%016x" % defi["array_of_subsizes"]}"
  s << ', '
  s << "array_of_starts: #{"0x%016x" % defi["array_of_starts"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_subarray_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_subarray_c_entry"] = lambda { |defi|
  s = "{ "
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_sizes: #{"0x%016x" % defi["array_of_sizes"]}"
  s << ', '
  s << "array_of_subsizes: #{"0x%016x" % defi["array_of_subsizes"]}"
  s << ', '
  s << "array_of_starts: #{"0x%016x" % defi["array_of_starts"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_create_subarray_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_free_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "datatype_val: #{"0x%016x" % defi["datatype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "type_keyval: #{"0x%016x" % defi["type_keyval"]}"
  s << ', '
  s << "type_keyval_val: #{defi["type_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_contents_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "max_integers: #{defi["max_integers"]}"
  s << ', '
  s << "max_addresses: #{defi["max_addresses"]}"
  s << ', '
  s << "max_datatypes: #{defi["max_datatypes"]}"
  s << ', '
  s << "array_of_integers: #{"0x%016x" % defi["array_of_integers"]}"
  s << ', '
  s << "array_of_addresses: #{"0x%016x" % defi["array_of_addresses"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_contents_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_contents_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "max_integers: #{defi["max_integers"]}"
  s << ', '
  s << "max_addresses: #{defi["max_addresses"]}"
  s << ', '
  s << "max_large_counts: #{defi["max_large_counts"]}"
  s << ', '
  s << "max_datatypes: #{defi["max_datatypes"]}"
  s << ', '
  s << "array_of_integers: #{"0x%016x" % defi["array_of_integers"]}"
  s << ', '
  s << "array_of_addresses: #{"0x%016x" % defi["array_of_addresses"]}"
  s << ', '
  s << "array_of_large_counts: #{"0x%016x" % defi["array_of_large_counts"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_contents_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_envelope_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "num_integers: #{"0x%016x" % defi["num_integers"]}"
  s << ', '
  s << "num_addresses: #{"0x%016x" % defi["num_addresses"]}"
  s << ', '
  s << "num_datatypes: #{"0x%016x" % defi["num_datatypes"]}"
  s << ', '
  s << "combiner: #{"0x%016x" % defi["combiner"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_envelope_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_integers_val: #{defi["num_integers_val"]}"
  s << ', '
  s << "num_addresses_val: #{defi["num_addresses_val"]}"
  s << ', '
  s << "num_datatypes_val: #{defi["num_datatypes_val"]}"
  s << ', '
  s << "combiner_val: #{defi["combiner_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_envelope_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "num_integers: #{"0x%016x" % defi["num_integers"]}"
  s << ', '
  s << "num_addresses: #{"0x%016x" % defi["num_addresses"]}"
  s << ', '
  s << "num_large_counts: #{"0x%016x" % defi["num_large_counts"]}"
  s << ', '
  s << "num_datatypes: #{"0x%016x" % defi["num_datatypes"]}"
  s << ', '
  s << "combiner: #{"0x%016x" % defi["combiner"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_envelope_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "lb_val: #{defi["lb_val"]}"
  s << ', '
  s << "extent_val: #{defi["extent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_extent_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "lb_val: #{defi["lb_val"]}"
  s << ', '
  s << "extent_val: #{defi["extent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_name: #{"0x%016x" % defi["type_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "type_name_val: #{defi["type_name_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "true_lb_val: #{defi["true_lb_val"]}"
  s << ', '
  s << "true_extent_val: #{defi["true_extent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_true_extent_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "true_lb_val: #{defi["true_lb_val"]}"
  s << ', '
  s << "true_extent_val: #{defi["true_extent_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_value_index_entry"] = lambda { |defi|
  s = "{ "
  s << "value_type: #{"0x%016x" % defi["value_type"]}"
  s << ', '
  s << "index_type: #{"0x%016x" % defi["index_type"]}"
  s << ', '
  s << "pair_type: #{"0x%016x" % defi["pair_type"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_get_value_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "pair_type_val: #{"0x%016x" % defi["pair_type_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_indexed_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_indexed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_indexed_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_indexed_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_match_size_entry"] = lambda { |defi|
  s = "{ "
  s << "typeclass: #{defi["typeclass"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_match_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "datatype_val: #{"0x%016x" % defi["datatype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_name: #{"0x%016x" % defi["type_name"]}"
  s << ', '
  s << "type_name_val: #{defi["type_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_size_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_vector_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_vector_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "newtype_val: #{"0x%016x" % defi["newtype_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_vector_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_vector_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "position_val: #{defi["position_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_external_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "position_val: #{defi["position_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_external_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_external_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpack_external_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpublish_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "service_name_val: #{defi["service_name_val"].inspect}"
  s << ', '
  s << "port_name_val: #{defi["port_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Unpublish_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wait_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "request_val: #{"0x%016x" % defi["request_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wait_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitany_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitany_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "indx_val: #{defi["indx_val"]}"
  s << ', '
  s << "status_val: #{defi["status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitsome_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Waitsome_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "outcount_val: #{defi["outcount_val"]}"
  s << ', '
  s << "array_of_indices_vals: #{defi["array_of_indices_vals"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_val: #{"0x%016x" % defi["win_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_val: #{"0x%016x" % defi["win_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_allocate_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_attach_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_attach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_complete_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_complete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_val: #{"0x%016x" % defi["win_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_c_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_dynamic_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_dynamic_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_val: #{"0x%016x" % defi["win_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win_errhandler_fn: #{"0x%016x" % defi["win_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "win_errhandler_fn_val: #{"0x%016x" % defi["win_errhandler_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "win_copy_attr_fn: #{"0x%016x" % defi["win_copy_attr_fn"]}"
  s << ', '
  s << "win_delete_attr_fn: #{"0x%016x" % defi["win_delete_attr_fn"]}"
  s << ', '
  s << "win_keyval: #{"0x%016x" % defi["win_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "win_copy_attr_fn_val: #{"0x%016x" % defi["win_copy_attr_fn_val"]}"
  s << ', '
  s << "win_delete_attr_fn_val: #{"0x%016x" % defi["win_delete_attr_fn_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_keyval_val: #{defi["win_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_detach_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "base: #{"0x%016x" % defi["base"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_detach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_fence_entry"] = lambda { |defi|
  s = "{ "
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_fence_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_local_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_local_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_local_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_flush_local_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_free_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_val: #{"0x%016x" % defi["win_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "win_keyval: #{"0x%016x" % defi["win_keyval"]}"
  s << ', '
  s << "win_keyval_val: #{defi["win_keyval_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "errhandler_val: #{"0x%016x" % defi["errhandler_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_group_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "group_val: #{"0x%016x" % defi["group_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_name: #{"0x%016x" % defi["win_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "win_name_val: #{defi["win_name_val"].inspect}"
  s << ', '
  s << "resultlen_val: #{defi["resultlen_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_lock_entry"] = lambda { |defi|
  s = "{ "
  s << "lock_type: #{defi["lock_type"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_lock_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_lock_all_entry"] = lambda { |defi|
  s = "{ "
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_lock_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_post_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_post_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_name: #{"0x%016x" % defi["win_name"]}"
  s << ', '
  s << "win_name_val: #{defi["win_name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_shared_query_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "disp_unit: #{"0x%016x" % defi["disp_unit"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_shared_query_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "size_val: #{defi["size_val"]}"
  s << ', '
  s << "disp_unit_val: #{defi["disp_unit_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_shared_query_c_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "disp_unit: #{"0x%016x" % defi["disp_unit"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_shared_query_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_start_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_sync_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_sync_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_test_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "flag_val: #{defi["flag_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_unlock_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_unlock_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_unlock_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_unlock_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_wait_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_wait_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Aint_add_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{defi["base"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Aint_add_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Aint_diff_entry"] = lambda { |defi|
  s = "{ "
  s << "addr1: #{defi["addr1"]}"
  s << ', '
  s << "addr2: #{defi["addr2"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Aint_diff_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wtick_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wtick_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wtime_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Wtime_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "c_status_val: #{defi["c_status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["c_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "f_status_val: #{defi["f_status_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f_status_val: #{defi["f_status_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "c_status_val: #{defi["c_status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["c_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_c2f08_entry"] = lambda { |defi|
  s = "{ "
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "c_status_val: #{defi["c_status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["c_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_c2f08_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "f08_status_val: #{defi["f08_status_val"].size > 0 ? MPI::MPI_F08_status.new(FFI::MemoryPointer.from_string(defi["f08_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f082c_entry"] = lambda { |defi|
  s = "{ "
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f08_status_val: #{defi["f08_status_val"].size > 0 ? MPI::MPI_F08_status.new(FFI::MemoryPointer.from_string(defi["f08_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f082c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "c_status_val: #{defi["c_status_val"].size > 0 ? MPI::MPI_Status.new(FFI::MemoryPointer.from_string(defi["c_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f2f08_entry"] = lambda { |defi|
  s = "{ "
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "f_status_val: #{defi["f_status_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f2f08_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "f08_status_val: #{defi["f08_status_val"].size > 0 ? MPI::MPI_F08_status.new(FFI::MemoryPointer.from_string(defi["f08_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f082f_entry"] = lambda { |defi|
  s = "{ "
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "f08_status_val: #{defi["f08_status_val"].size > 0 ? MPI::MPI_F08_status.new(FFI::MemoryPointer.from_string(defi["f08_status_val"])) : nil}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Status_f082f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "f_status_val: #{defi["f_status_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Comm_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Errhandler_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Type_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{defi["file"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_File_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Group_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Info_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Message_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "message: #{"0x%016x" % defi["message"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Message_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Message_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "message: #{defi["message"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Message_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Op_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Request_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Session_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_Win_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_changed_entry"] = lambda { |defi|
  s = "{ "
  s << "update_number: #{"0x%016x" % defi["update_number"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_changed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "update_number_val: #{defi["update_number_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_categories_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_categories_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_cvars_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_cvars_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_events_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_events_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "cat_index: #{"0x%016x" % defi["cat_index"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "cat_index_val: #{defi["cat_index_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "num_cvars: #{"0x%016x" % defi["num_cvars"]}"
  s << ', '
  s << "num_pvars: #{"0x%016x" % defi["num_pvars"]}"
  s << ', '
  s << "num_categories: #{"0x%016x" % defi["num_categories"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << ', '
  s << "desc_len_val: #{defi["desc_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << ', '
  s << "num_cvars_val: #{defi["num_cvars_val"]}"
  s << ', '
  s << "num_pvars_val: #{defi["num_pvars_val"]}"
  s << ', '
  s << "num_categories_val: #{defi["num_categories_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_cat: #{"0x%016x" % defi["num_cat"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_cat_val: #{defi["num_cat_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_num_events_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "num_events: #{"0x%016x" % defi["num_events"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_num_events_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_events_val: #{defi["num_events_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_pvars_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_category_get_pvars_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "cvar_index: #{"0x%016x" % defi["cvar_index"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "cvar_index_val: #{defi["cvar_index_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "cvar_index: #{defi["cvar_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << ', '
  s << "scope: #{"0x%016x" % defi["scope"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << ', '
  s << "desc_len_val: #{defi["desc_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "verbosity_val: #{defi["verbosity_val"]}"
  s << ', '
  s << "datatype_val: #{"0x%016x" % defi["datatype_val"]}"
  s << ', '
  s << "enumtype_val: #{"0x%016x" % defi["enumtype_val"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << ', '
  s << "bind_val: #{defi["bind_val"]}"
  s << ', '
  s << "scope_val: #{defi["scope_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_cvar: #{"0x%016x" % defi["num_cvar"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_cvar_val: #{defi["num_cvar_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "cvar_index: #{defi["cvar_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_read_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_write_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_cvar_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_enum_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "num: #{"0x%016x" % defi["num"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_enum_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_val: #{defi["num_val"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_enum_get_item_entry"] = lambda { |defi|
  s = "{ "
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "indx: #{defi["indx"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_enum_get_item_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "value_val: #{defi["value_val"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_callback_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_callback_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_callback_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_callback_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_copy_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_copy_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "event_index: #{"0x%016x" % defi["event_index"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "event_index_val: #{defi["event_index_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_index: #{defi["event_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "num_elements: #{"0x%016x" % defi["num_elements"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << ', '
  s << "num_elements_val: #{defi["num_elements_val"]}"
  s << ', '
  s << "desc_len_val: #{defi["desc_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "verbosity_val: #{defi["verbosity_val"]}"
  s << ', '
  s << "enumtype_val: #{"0x%016x" % defi["enumtype_val"]}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << ', '
  s << "bind_val: #{defi["bind_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_events: #{"0x%016x" % defi["num_events"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_events_val: #{defi["num_events_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_source_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "source_index: #{"0x%016x" % defi["source_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "source_index_val: #{defi["source_index_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_timestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "event_timestamp: #{"0x%016x" % defi["event_timestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_get_timestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "event_timestamp_val: #{defi["event_timestamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "event_index: #{defi["event_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "event_registration_val: #{"0x%016x" % defi["event_registration_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "user_data: #{"0x%016x" % defi["user_data"]}"
  s << ', '
  s << "free_cb_function: #{"0x%016x" % defi["free_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "info_used_val: #{"0x%016x" % defi["info_used_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_handle_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_read_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "element_index: #{defi["element_index"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_register_callback_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "user_data: #{"0x%016x" % defi["user_data"]}"
  s << ', '
  s << "event_cb_function: #{"0x%016x" % defi["event_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_register_callback_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_set_dropped_handler_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "dropped_cb_function: #{"0x%016x" % defi["dropped_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_event_set_dropped_handler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_finalize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_init_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "required: #{defi["required"]}"
  s << ', '
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_init_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "provided_val: #{defi["provided_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "var_class: #{defi["var_class"]}"
  s << ', '
  s << "pvar_index: #{"0x%016x" % defi["pvar_index"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "pvar_index_val: #{defi["pvar_index_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "pvar_index: #{defi["pvar_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "var_class: #{"0x%016x" % defi["var_class"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << ', '
  s << "readonly: #{"0x%016x" % defi["readonly"]}"
  s << ', '
  s << "continuous: #{"0x%016x" % defi["continuous"]}"
  s << ', '
  s << "atomic: #{"0x%016x" % defi["atomic"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << ', '
  s << "desc_len_val: #{defi["desc_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "verbosity_val: #{defi["verbosity_val"]}"
  s << ', '
  s << "var_class_val: #{defi["var_class_val"]}"
  s << ', '
  s << "datatype_val: #{"0x%016x" % defi["datatype_val"]}"
  s << ', '
  s << "enumtype_val: #{"0x%016x" % defi["enumtype_val"]}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << ', '
  s << "bind_val: #{defi["bind_val"]}"
  s << ', '
  s << "readonly_val: #{defi["readonly_val"]}"
  s << ', '
  s << "continuous_val: #{defi["continuous_val"]}"
  s << ', '
  s << "atomic_val: #{defi["atomic_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_pvar: #{"0x%016x" % defi["num_pvar"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_pvar_val: #{defi["num_pvar_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pvar_index: #{defi["pvar_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << ', '
  s << "count_val: #{defi["count_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "handle_val: #{"0x%016x" % defi["handle_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_read_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_readreset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_readreset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_reset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_reset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_session_create_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_session_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "session_val: #{"0x%016x" % defi["session_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_session_free_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "session_val: #{"0x%016x" % defi["session_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_session_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_start_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_stop_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_stop_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_write_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_pvar_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "source_index: #{defi["source_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "ordering: #{"0x%016x" % defi["ordering"]}"
  s << ', '
  s << "ticks_per_second: #{"0x%016x" % defi["ticks_per_second"]}"
  s << ', '
  s << "max_ticks: #{"0x%016x" % defi["max_ticks"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "name_len_val: #{defi["name_len_val"]}"
  s << ', '
  s << "desc_len_val: #{defi["desc_len_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "name_val: #{defi["name_val"].inspect}"
  s << ', '
  s << "desc_val: #{defi["desc_val"].inspect}"
  s << ', '
  s << "ordering_val: #{MPI::MPI_T_source_order.from_native(defi["ordering_val"], nil)}"
  s << ', '
  s << "ticks_per_second_val: #{defi["ticks_per_second_val"]}"
  s << ', '
  s << "max_ticks_val: #{defi["max_ticks_val"]}"
  s << ', '
  s << "info_val: #{"0x%016x" % defi["info_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_sources: #{"0x%016x" % defi["num_sources"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "num_sources_val: #{defi["num_sources_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_timestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "source_index: #{defi["source_index"]}"
  s << ', '
  s << "timestamp: #{"0x%016x" % defi["timestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:MPI_T_source_get_timestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << ', '
  s << "timestamp_val: #{defi["timestamp_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Abort_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Abort_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{"0x%016x" % defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_code_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{defi["errorclass"]}"
  s << ', '
  s << "errorcode: #{"0x%016x" % defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_code_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "string: #{"0x%016x" % defi["string"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Add_error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allgatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alloc_mem_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alloc_mem_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Allreduce_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoall_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Alltoallw_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_put_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "keyval: #{defi["keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Attr_put_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Barrier_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Barrier_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Barrier_init_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Barrier_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bcast_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Bsend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_attach_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_attach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_attach_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_attach_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_detach_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_detach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_detach_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_detach_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_flush_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_flush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_iflush_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Buffer_iflush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cancel_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cancel_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_coords_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "maxdims: #{defi["maxdims"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_coords_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_cart: #{"0x%016x" % defi["comm_cart"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxdims: #{defi["maxdims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_map_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << ', '
  s << "periods: #{"0x%016x" % defi["periods"]}"
  s << ', '
  s << "newrank: #{"0x%016x" % defi["newrank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_map_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "coords: #{"0x%016x" % defi["coords"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_shift_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "direction: #{defi["direction"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << ', '
  s << "rank_source: #{"0x%016x" % defi["rank_source"]}"
  s << ', '
  s << "rank_dest: #{"0x%016x" % defi["rank_dest"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_shift_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_sub_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "remain_dims: #{"0x%016x" % defi["remain_dims"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cart_sub_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cartdim_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "ndims: #{"0x%016x" % defi["ndims"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Cartdim_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Close_port_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Close_port_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_accept_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_accept_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_attach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_attach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_attach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_attach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_compare_entry"] = lambda { |defi|
  s = "{ "
  s << "comm1: #{"0x%016x" % defi["comm1"]}"
  s << ', '
  s << "comm2: #{"0x%016x" % defi["comm2"]}"
  s << ', '
  s << "result: #{"0x%016x" % defi["result"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_compare_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_connect_entry"] = lambda { |defi|
  s = "{ "
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_connect_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_errhandler_fn: #{"0x%016x" % defi["comm_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_from_group_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "stringtag: #{"0x%016x" % defi["stringtag"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_from_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_copy_attr_fn: #{"0x%016x" % defi["comm_copy_attr_fn"]}"
  s << ', '
  s << "comm_delete_attr_fn: #{"0x%016x" % defi["comm_delete_attr_fn"]}"
  s << ', '
  s << "comm_keyval: #{"0x%016x" % defi["comm_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_detach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_detach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_detach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_detach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_disconnect_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_disconnect_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_dup_with_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_dup_with_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_flush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_flush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_free_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_keyval: #{"0x%016x" % defi["comm_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_name: #{"0x%016x" % defi["comm_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_parent_entry"] = lambda { |defi|
  s = "{ "
  s << "parent: #{"0x%016x" % defi["parent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_get_parent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_idup_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_idup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_idup_with_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_idup_with_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_iflush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_iflush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_join_entry"] = lambda { |defi|
  s = "{ "
  s << "fd: #{defi["fd"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_join_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_remote_group_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_remote_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_remote_size_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_remote_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_keyval: #{defi["comm_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "comm_name: #{"0x%016x" % defi["comm_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_size_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_spawn_entry"] = lambda { |defi|
  s = "{ "
  s << "command: #{"0x%016x" % defi["command"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "maxprocs: #{defi["maxprocs"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "array_of_errcodes: #{"0x%016x" % defi["array_of_errcodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_spawn_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_spawn_multiple_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_commands: #{"0x%016x" % defi["array_of_commands"]}"
  s << ', '
  s << "array_of_argv: #{"0x%016x" % defi["array_of_argv"]}"
  s << ', '
  s << "array_of_maxprocs: #{"0x%016x" % defi["array_of_maxprocs"]}"
  s << ', '
  s << "array_of_info: #{"0x%016x" % defi["array_of_info"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "array_of_errcodes: #{"0x%016x" % defi["array_of_errcodes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_spawn_multiple_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_split_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "color: #{defi["color"]}"
  s << ', '
  s << "key: #{defi["key"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_split_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_split_type_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "split_type: #{defi["split_type"]}"
  s << ', '
  s << "key: #{defi["key"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newcomm: #{"0x%016x" % defi["newcomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_split_type_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_test_inter_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_test_inter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Compare_and_swap_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "compare_addr: #{"0x%016x" % defi["compare_addr"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Compare_and_swap_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dims_create_entry"] = lambda { |defi|
  s = "{ "
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "dims: #{"0x%016x" % defi["dims"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dims_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "degrees: #{"0x%016x" % defi["degrees"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "weights: #{"0x%016x" % defi["weights"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_dist_graph: #{"0x%016x" % defi["comm_dist_graph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_create_adjacent_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "indegree: #{defi["indegree"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "sourceweights: #{"0x%016x" % defi["sourceweights"]}"
  s << ', '
  s << "outdegree: #{defi["outdegree"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "destweights: #{"0x%016x" % defi["destweights"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_dist_graph: #{"0x%016x" % defi["comm_dist_graph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_create_adjacent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_neighbors_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxindegree: #{defi["maxindegree"]}"
  s << ', '
  s << "sources: #{"0x%016x" % defi["sources"]}"
  s << ', '
  s << "sourceweights: #{"0x%016x" % defi["sourceweights"]}"
  s << ', '
  s << "maxoutdegree: #{defi["maxoutdegree"]}"
  s << ', '
  s << "destinations: #{"0x%016x" % defi["destinations"]}"
  s << ', '
  s << "destweights: #{"0x%016x" % defi["destweights"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_neighbors_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_neighbors_count_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "indegree: #{"0x%016x" % defi["indegree"]}"
  s << ', '
  s << "outdegree: #{"0x%016x" % defi["outdegree"]}"
  s << ', '
  s << "weighted: #{"0x%016x" % defi["weighted"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Dist_graph_neighbors_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_free_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "errorclass: #{"0x%016x" % defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << ', '
  s << "string: #{"0x%016x" % defi["string"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Exscan_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Fetch_and_op_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Fetch_and_op_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_close_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_close_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file_errhandler_fn: #{"0x%016x" % defi["file_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "filename: #{"0x%016x" % defi["filename"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_amode_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "amode: #{"0x%016x" % defi["amode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_amode_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_atomicity_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_atomicity_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_byte_offset_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "disp: #{"0x%016x" % defi["disp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_byte_offset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_group_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_position_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_position_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_position_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{"0x%016x" % defi["offset"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_position_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_size_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_type_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_type_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_type_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_type_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_view_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "disp: #{"0x%016x" % defi["disp"]}"
  s << ', '
  s << "etype: #{"0x%016x" % defi["etype"]}"
  s << ', '
  s << "filetype: #{"0x%016x" % defi["filetype"]}"
  s << ', '
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_get_view_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iread_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_iwrite_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_open_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "filename: #{"0x%016x" % defi["filename"]}"
  s << ', '
  s << "amode: #{defi["amode"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_open_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_preallocate_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_preallocate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_at_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_ordered_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_read_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_seek_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "whence: #{defi["whence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_seek_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_seek_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "whence: #{defi["whence"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_seek_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_atomicity_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_atomicity_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_size_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_view_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << ', '
  s << "etype: #{"0x%016x" % defi["etype"]}"
  s << ', '
  s << "filetype: #{"0x%016x" % defi["filetype"]}"
  s << ', '
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_set_view_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_sync_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_sync_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "offset: #{defi["offset"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_at_all_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_begin_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_begin_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_begin_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_begin_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_end_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_ordered_end_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "fh: #{"0x%016x" % defi["fh"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_write_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Finalize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Finalized_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Finalized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Free_mem_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Free_mem_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Gatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_address_entry"] = lambda { |defi|
  s = "{ "
  s << "location: #{"0x%016x" % defi["location"]}"
  s << ', '
  s << "address: #{"0x%016x" % defi["address"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_address_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_count_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_count_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_count_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_x_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_elements_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_hw_resource_info_entry"] = lambda { |defi|
  s = "{ "
  s << "hw_info: #{"0x%016x" % defi["hw_info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_hw_resource_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_library_version_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{"0x%016x" % defi["version"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_library_version_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_processor_name_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_processor_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_version_entry"] = lambda { |defi|
  s = "{ "
  s << "version: #{"0x%016x" % defi["version"]}"
  s << ', '
  s << "subversion: #{"0x%016x" % defi["subversion"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Get_version_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_create_entry"] = lambda { |defi|
  s = "{ "
  s << "comm_old: #{"0x%016x" % defi["comm_old"]}"
  s << ', '
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << ', '
  s << "reorder: #{defi["reorder"]}"
  s << ', '
  s << "comm_graph: #{"0x%016x" % defi["comm_graph"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "maxindex: #{defi["maxindex"]}"
  s << ', '
  s << "maxedges: #{defi["maxedges"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_map_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "nnodes: #{defi["nnodes"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "edges: #{"0x%016x" % defi["edges"]}"
  s << ', '
  s << "newrank: #{"0x%016x" % defi["newrank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_map_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_neighbors_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "maxneighbors: #{defi["maxneighbors"]}"
  s << ', '
  s << "neighbors: #{"0x%016x" % defi["neighbors"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_neighbors_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_neighbors_count_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "nneighbors: #{"0x%016x" % defi["nneighbors"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graph_neighbors_count_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graphdims_get_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "nnodes: #{"0x%016x" % defi["nnodes"]}"
  s << ', '
  s << "nedges: #{"0x%016x" % defi["nedges"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Graphdims_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Grequest_complete_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Grequest_complete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Grequest_start_entry"] = lambda { |defi|
  s = "{ "
  s << "query_fn: #{"0x%016x" % defi["query_fn"]}"
  s << ', '
  s << "free_fn: #{"0x%016x" % defi["free_fn"]}"
  s << ', '
  s << "cancel_fn: #{"0x%016x" % defi["cancel_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Grequest_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_compare_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "result: #{"0x%016x" % defi["result"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_compare_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_difference_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_difference_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_excl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks: #{"0x%016x" % defi["ranks"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_excl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_free_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_from_session_pset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_from_session_pset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_incl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks: #{"0x%016x" % defi["ranks"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_incl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_intersection_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_intersection_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_range_excl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranges: #{"0x%016x" % defi["ranges"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_range_excl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_range_incl_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranges: #{"0x%016x" % defi["ranges"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_range_incl_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_rank_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "rank: #{"0x%016x" % defi["rank"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_rank_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_size_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_translate_ranks_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "ranks1: #{"0x%016x" % defi["ranks1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "ranks2: #{"0x%016x" % defi["ranks2"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_translate_ranks_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_union_entry"] = lambda { |defi|
  s = "{ "
  s << "group1: #{"0x%016x" % defi["group1"]}"
  s << ', '
  s << "group2: #{"0x%016x" % defi["group2"]}"
  s << ', '
  s << "newgroup: #{"0x%016x" % defi["newgroup"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_union_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallreduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallreduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallreduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iallreduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ialltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibarrier_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibarrier_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibcast_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibcast_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibcast_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibcast_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ibsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iexscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iexscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iexscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iexscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Igatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Improbe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Improbe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Imrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Imrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Imrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Imrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ineighbor_alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_create_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_create_env_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_create_env_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_delete_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_delete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "newinfo: #{"0x%016x" % defi["newinfo"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_free_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "valuelen: #{defi["valuelen"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_nkeys_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "nkeys: #{"0x%016x" % defi["nkeys"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_nkeys_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_nthkey_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_nthkey_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_string_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "buflen: #{"0x%016x" % defi["buflen"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_valuelen_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "valuelen: #{"0x%016x" % defi["valuelen"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_get_valuelen_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_set_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "key: #{"0x%016x" % defi["key"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_set_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Init_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{"0x%016x" % defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Init_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "argc: #{"0x%016x" % defi["argc"]}"
  s << ', '
  s << "argv: #{"0x%016x" % defi["argv"]}"
  s << ', '
  s << "required: #{defi["required"]}"
  s << ', '
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Init_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Initialized_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Initialized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_create_entry"] = lambda { |defi|
  s = "{ "
  s << "local_comm: #{"0x%016x" % defi["local_comm"]}"
  s << ', '
  s << "local_leader: #{defi["local_leader"]}"
  s << ', '
  s << "peer_comm: #{"0x%016x" % defi["peer_comm"]}"
  s << ', '
  s << "remote_leader: #{defi["remote_leader"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "newintercomm: #{"0x%016x" % defi["newintercomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_create_from_groups_entry"] = lambda { |defi|
  s = "{ "
  s << "local_group: #{"0x%016x" % defi["local_group"]}"
  s << ', '
  s << "local_leader: #{defi["local_leader"]}"
  s << ', '
  s << "remote_group: #{"0x%016x" % defi["remote_group"]}"
  s << ', '
  s << "remote_leader: #{defi["remote_leader"]}"
  s << ', '
  s << "stringtag: #{"0x%016x" % defi["stringtag"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "newintercomm: #{"0x%016x" % defi["newintercomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_create_from_groups_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_merge_entry"] = lambda { |defi|
  s = "{ "
  s << "intercomm: #{"0x%016x" % defi["intercomm"]}"
  s << ', '
  s << "high: #{defi["high"]}"
  s << ', '
  s << "newintracomm: #{"0x%016x" % defi["newintracomm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Intercomm_merge_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iprobe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iprobe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_block_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ireduce_scatter_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Irsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Is_thread_main_entry"] = lambda { |defi|
  s = "{ "
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Is_thread_main_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatterv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatterv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatterv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Iscatterv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_replace_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_replace_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_replace_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Isendrecv_replace_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Issend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Issend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Issend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Issend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Keyval_create_entry"] = lambda { |defi|
  s = "{ "
  s << "copy_fn: #{"0x%016x" % defi["copy_fn"]}"
  s << ', '
  s << "delete_fn: #{"0x%016x" % defi["delete_fn"]}"
  s << ', '
  s << "keyval: #{"0x%016x" % defi["keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Keyval_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Keyval_free_entry"] = lambda { |defi|
  s = "{ "
  s << "keyval: #{"0x%016x" % defi["keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Keyval_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Lookup_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Lookup_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mprobe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mprobe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "message: #{"0x%016x" % defi["message"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Mrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgather_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_allgatherv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoall_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "sdispls: #{"0x%016x" % defi["sdispls"]}"
  s << ', '
  s << "sendtypes: #{"0x%016x" % defi["sendtypes"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "rdispls: #{"0x%016x" % defi["rdispls"]}"
  s << ', '
  s << "recvtypes: #{"0x%016x" % defi["recvtypes"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Neighbor_alltoallw_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_commutative_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "commute: #{"0x%016x" % defi["commute"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_commutative_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_create_entry"] = lambda { |defi|
  s = "{ "
  s << "user_fn: #{"0x%016x" % defi["user_fn"]}"
  s << ', '
  s << "commute: #{defi["commute"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_create_c_entry"] = lambda { |defi|
  s = "{ "
  s << "user_fn: #{"0x%016x" % defi["user_fn"]}"
  s << ', '
  s << "commute: #{defi["commute"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_create_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_free_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Open_port_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Open_port_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outsize: #{defi["outsize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_size_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_external_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_size_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pack_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Parrived_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "partition: #{defi["partition"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Parrived_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pcontrol_entry"] = lambda { |defi|
  s = "{ "
  s << "level: #{defi["level"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pcontrol_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_entry"] = lambda { |defi|
  s = "{ "
  s << "partition: #{defi["partition"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_list_entry"] = lambda { |defi|
  s = "{ "
  s << "length: #{defi["length"]}"
  s << ', '
  s << "array_of_partitions: #{"0x%016x" % defi["array_of_partitions"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_list_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_range_entry"] = lambda { |defi|
  s = "{ "
  s << "partition_low: #{defi["partition_low"]}"
  s << ', '
  s << "partition_high: #{defi["partition_high"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Pready_range_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Precv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "partitions: #{defi["partitions"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Precv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Probe_entry"] = lambda { |defi|
  s = "{ "
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Probe_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Psend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "partitions: #{defi["partitions"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Psend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Publish_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Publish_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Put_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Put_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Put_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Put_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Query_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Query_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Raccumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Raccumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Raccumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Raccumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Recv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_local_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "inoutbuf: #{"0x%016x" % defi["inoutbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_local_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_local_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "inoutbuf: #{"0x%016x" % defi["inoutbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_local_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_block_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcounts: #{"0x%016x" % defi["recvcounts"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Reduce_scatter_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Register_datarep_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "read_conversion_fn: #{"0x%016x" % defi["read_conversion_fn"]}"
  s << ', '
  s << "write_conversion_fn: #{"0x%016x" % defi["write_conversion_fn"]}"
  s << ', '
  s << "dtype_file_extent_fn: #{"0x%016x" % defi["dtype_file_extent_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Register_datarep_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Register_datarep_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "read_conversion_fn: #{"0x%016x" % defi["read_conversion_fn"]}"
  s << ', '
  s << "write_conversion_fn: #{"0x%016x" % defi["write_conversion_fn"]}"
  s << ', '
  s << "dtype_file_extent_fn: #{"0x%016x" % defi["dtype_file_extent_fn"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Register_datarep_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_class_entry"] = lambda { |defi|
  s = "{ "
  s << "errorclass: #{defi["errorclass"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_class_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_code_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_code_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_string_entry"] = lambda { |defi|
  s = "{ "
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Remove_error_string_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_free_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_all_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_any_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_any_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_some_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_get_status_some_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_accumulate_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_accumulate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_accumulate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "result_addr: #{"0x%016x" % defi["result_addr"]}"
  s << ', '
  s << "result_count: #{defi["result_count"]}"
  s << ', '
  s << "result_datatype: #{"0x%016x" % defi["result_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rget_accumulate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rput_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rput_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rput_c_entry"] = lambda { |defi|
  s = "{ "
  s << "origin_addr: #{"0x%016x" % defi["origin_addr"]}"
  s << ', '
  s << "origin_count: #{defi["origin_count"]}"
  s << ', '
  s << "origin_datatype: #{"0x%016x" % defi["origin_datatype"]}"
  s << ', '
  s << "target_rank: #{defi["target_rank"]}"
  s << ', '
  s << "target_disp: #{defi["target_disp"]}"
  s << ', '
  s << "target_count: #{defi["target_count"]}"
  s << ', '
  s << "target_datatype: #{"0x%016x" % defi["target_datatype"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rput_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Rsend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "op: #{"0x%016x" % defi["op"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scan_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatter_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_init_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcounts: #{"0x%016x" % defi["sendcounts"]}"
  s << ', '
  s << "displs: #{"0x%016x" % defi["displs"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "root: #{defi["root"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Scatterv_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Send_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_c_entry"] = lambda { |defi|
  s = "{ "
  s << "sendbuf: #{"0x%016x" % defi["sendbuf"]}"
  s << ', '
  s << "sendcount: #{defi["sendcount"]}"
  s << ', '
  s << "sendtype: #{"0x%016x" % defi["sendtype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "recvbuf: #{"0x%016x" % defi["recvbuf"]}"
  s << ', '
  s << "recvcount: #{defi["recvcount"]}"
  s << ', '
  s << "recvtype: #{"0x%016x" % defi["recvtype"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_replace_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_replace_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_replace_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "sendtag: #{defi["sendtag"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << ', '
  s << "recvtag: #{defi["recvtag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Sendrecv_replace_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_attach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_attach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_attach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_attach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session_errhandler_fn: #{"0x%016x" % defi["session_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_detach_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_detach_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_detach_buffer_c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "buffer_addr: #{"0x%016x" % defi["buffer_addr"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_detach_buffer_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_finalize_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_flush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_flush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_nth_pset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "n: #{defi["n"]}"
  s << ', '
  s << "pset_len: #{"0x%016x" % defi["pset_len"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_nth_pset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_num_psets_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "npset_names: #{"0x%016x" % defi["npset_names"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_num_psets_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_pset_info_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pset_name: #{"0x%016x" % defi["pset_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_get_pset_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_iflush_buffer_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_iflush_buffer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_init_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << ', '
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_init_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_init_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_init_c_entry"] = lambda { |defi|
  s = "{ "
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "dest: #{defi["dest"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Ssend_init_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Start_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Startall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Startall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_error_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "error: #{"0x%016x" % defi["error"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_error_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_source_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "source: #{"0x%016x" % defi["source"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_tag_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "tag: #{"0x%016x" % defi["tag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_get_tag_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_cancelled_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "flag: #{defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_cancelled_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_c_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_x_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "count: #{defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_elements_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_error_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "error: #{defi["error"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_error_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_source_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "source: #{defi["source"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_tag_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "tag: #{defi["tag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_set_tag_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Test_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Test_cancelled_entry"] = lambda { |defi|
  s = "{ "
  s << "status: #{"0x%016x" % defi["status"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Test_cancelled_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testany_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testany_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testsome_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Testsome_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Topo_test_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Topo_test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_commit_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_commit_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_contiguous_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_contiguous_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_contiguous_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_contiguous_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_darray_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_gsizes: #{"0x%016x" % defi["array_of_gsizes"]}"
  s << ', '
  s << "array_of_distribs: #{"0x%016x" % defi["array_of_distribs"]}"
  s << ', '
  s << "array_of_dargs: #{"0x%016x" % defi["array_of_dargs"]}"
  s << ', '
  s << "array_of_psizes: #{"0x%016x" % defi["array_of_psizes"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_darray_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_darray_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_gsizes: #{"0x%016x" % defi["array_of_gsizes"]}"
  s << ', '
  s << "array_of_distribs: #{"0x%016x" % defi["array_of_distribs"]}"
  s << ', '
  s << "array_of_dargs: #{"0x%016x" % defi["array_of_dargs"]}"
  s << ', '
  s << "array_of_psizes: #{"0x%016x" % defi["array_of_psizes"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_darray_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_complex_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{defi["p"]}"
  s << ', '
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_complex_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_integer_entry"] = lambda { |defi|
  s = "{ "
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_integer_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_real_entry"] = lambda { |defi|
  s = "{ "
  s << "p: #{defi["p"]}"
  s << ', '
  s << "r: #{defi["r"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_f90_real_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_block_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hindexed_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hvector_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hvector_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hvector_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_hvector_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_indexed_block_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_indexed_block_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_indexed_block_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_indexed_block_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "type_copy_attr_fn: #{"0x%016x" % defi["type_copy_attr_fn"]}"
  s << ', '
  s << "type_delete_attr_fn: #{"0x%016x" % defi["type_delete_attr_fn"]}"
  s << ', '
  s << "type_keyval: #{"0x%016x" % defi["type_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_resized_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "lb: #{defi["lb"]}"
  s << ', '
  s << "extent: #{defi["extent"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_resized_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_resized_c_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "lb: #{defi["lb"]}"
  s << ', '
  s << "extent: #{defi["extent"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_resized_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_struct_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "array_of_types: #{"0x%016x" % defi["array_of_types"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_struct_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_struct_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "array_of_types: #{"0x%016x" % defi["array_of_types"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_struct_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_subarray_entry"] = lambda { |defi|
  s = "{ "
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_sizes: #{"0x%016x" % defi["array_of_sizes"]}"
  s << ', '
  s << "array_of_subsizes: #{"0x%016x" % defi["array_of_subsizes"]}"
  s << ', '
  s << "array_of_starts: #{"0x%016x" % defi["array_of_starts"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_subarray_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_subarray_c_entry"] = lambda { |defi|
  s = "{ "
  s << "ndims: #{defi["ndims"]}"
  s << ', '
  s << "array_of_sizes: #{"0x%016x" % defi["array_of_sizes"]}"
  s << ', '
  s << "array_of_subsizes: #{"0x%016x" % defi["array_of_subsizes"]}"
  s << ', '
  s << "array_of_starts: #{"0x%016x" % defi["array_of_starts"]}"
  s << ', '
  s << "order: #{defi["order"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_create_subarray_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_dup_entry"] = lambda { |defi|
  s = "{ "
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_dup_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_free_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "type_keyval: #{"0x%016x" % defi["type_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_contents_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "max_integers: #{defi["max_integers"]}"
  s << ', '
  s << "max_addresses: #{defi["max_addresses"]}"
  s << ', '
  s << "max_datatypes: #{defi["max_datatypes"]}"
  s << ', '
  s << "array_of_integers: #{"0x%016x" % defi["array_of_integers"]}"
  s << ', '
  s << "array_of_addresses: #{"0x%016x" % defi["array_of_addresses"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_contents_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_contents_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "max_integers: #{defi["max_integers"]}"
  s << ', '
  s << "max_addresses: #{defi["max_addresses"]}"
  s << ', '
  s << "max_large_counts: #{defi["max_large_counts"]}"
  s << ', '
  s << "max_datatypes: #{defi["max_datatypes"]}"
  s << ', '
  s << "array_of_integers: #{"0x%016x" % defi["array_of_integers"]}"
  s << ', '
  s << "array_of_addresses: #{"0x%016x" % defi["array_of_addresses"]}"
  s << ', '
  s << "array_of_large_counts: #{"0x%016x" % defi["array_of_large_counts"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_contents_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_envelope_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "num_integers: #{"0x%016x" % defi["num_integers"]}"
  s << ', '
  s << "num_addresses: #{"0x%016x" % defi["num_addresses"]}"
  s << ', '
  s << "num_datatypes: #{"0x%016x" % defi["num_datatypes"]}"
  s << ', '
  s << "combiner: #{"0x%016x" % defi["combiner"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_envelope_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_envelope_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "num_integers: #{"0x%016x" % defi["num_integers"]}"
  s << ', '
  s << "num_addresses: #{"0x%016x" % defi["num_addresses"]}"
  s << ', '
  s << "num_large_counts: #{"0x%016x" % defi["num_large_counts"]}"
  s << ', '
  s << "num_datatypes: #{"0x%016x" % defi["num_datatypes"]}"
  s << ', '
  s << "combiner: #{"0x%016x" % defi["combiner"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_envelope_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "lb: #{"0x%016x" % defi["lb"]}"
  s << ', '
  s << "extent: #{"0x%016x" % defi["extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_extent_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_name: #{"0x%016x" % defi["type_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "true_lb: #{"0x%016x" % defi["true_lb"]}"
  s << ', '
  s << "true_extent: #{"0x%016x" % defi["true_extent"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_true_extent_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_value_index_entry"] = lambda { |defi|
  s = "{ "
  s << "value_type: #{"0x%016x" % defi["value_type"]}"
  s << ', '
  s << "index_type: #{"0x%016x" % defi["index_type"]}"
  s << ', '
  s << "pair_type: #{"0x%016x" % defi["pair_type"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_get_value_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_indexed_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_indexed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_indexed_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_blocklengths: #{"0x%016x" % defi["array_of_blocklengths"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_indexed_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_match_size_entry"] = lambda { |defi|
  s = "{ "
  s << "typeclass: #{defi["typeclass"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_match_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_keyval: #{defi["type_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "type_name: #{"0x%016x" % defi["type_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_x_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_size_x_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_vector_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_vector_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_vector_c_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "blocklength: #{defi["blocklength"]}"
  s << ', '
  s << "stride: #{defi["stride"]}"
  s << ', '
  s << "oldtype: #{"0x%016x" % defi["oldtype"]}"
  s << ', '
  s << "newtype: #{"0x%016x" % defi["newtype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_vector_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_c_entry"] = lambda { |defi|
  s = "{ "
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_external_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_external_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_external_c_entry"] = lambda { |defi|
  s = "{ "
  s << "datarep: #{"0x%016x" % defi["datarep"]}"
  s << ', '
  s << "inbuf: #{"0x%016x" % defi["inbuf"]}"
  s << ', '
  s << "insize: #{defi["insize"]}"
  s << ', '
  s << "position: #{"0x%016x" % defi["position"]}"
  s << ', '
  s << "outbuf: #{"0x%016x" % defi["outbuf"]}"
  s << ', '
  s << "outcount: #{defi["outcount"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpack_external_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpublish_name_entry"] = lambda { |defi|
  s = "{ "
  s << "service_name: #{"0x%016x" % defi["service_name"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "port_name: #{"0x%016x" % defi["port_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Unpublish_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wait_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wait_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitall_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitall_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitany_entry"] = lambda { |defi|
  s = "{ "
  s << "count: #{defi["count"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "indx: #{"0x%016x" % defi["indx"]}"
  s << ', '
  s << "status: #{"0x%016x" % defi["status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitany_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitsome_entry"] = lambda { |defi|
  s = "{ "
  s << "incount: #{defi["incount"]}"
  s << ', '
  s << "array_of_requests: #{"0x%016x" % defi["array_of_requests"]}"
  s << ', '
  s << "outcount: #{"0x%016x" % defi["outcount"]}"
  s << ', '
  s << "array_of_indices: #{"0x%016x" % defi["array_of_indices"]}"
  s << ', '
  s << "array_of_statuses: #{"0x%016x" % defi["array_of_statuses"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Waitsome_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_shared_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_shared_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_shared_c_entry"] = lambda { |defi|
  s = "{ "
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_allocate_shared_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_attach_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_attach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_call_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errorcode: #{defi["errorcode"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_call_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_complete_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_complete_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_c_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{"0x%016x" % defi["base"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << ', '
  s << "disp_unit: #{defi["disp_unit"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_dynamic_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_dynamic_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win_errhandler_fn: #{"0x%016x" % defi["win_errhandler_fn"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "win_copy_attr_fn: #{"0x%016x" % defi["win_copy_attr_fn"]}"
  s << ', '
  s << "win_delete_attr_fn: #{"0x%016x" % defi["win_delete_attr_fn"]}"
  s << ', '
  s << "win_keyval: #{"0x%016x" % defi["win_keyval"]}"
  s << ', '
  s << "extra_state: #{"0x%016x" % defi["extra_state"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_create_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_delete_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_delete_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_detach_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "base: #{"0x%016x" % defi["base"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_detach_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_fence_entry"] = lambda { |defi|
  s = "{ "
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_fence_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_local_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_local_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_local_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_flush_local_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_free_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_free_keyval_entry"] = lambda { |defi|
  s = "{ "
  s << "win_keyval: #{"0x%016x" % defi["win_keyval"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_free_keyval_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_group_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_group_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_name_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_name: #{"0x%016x" % defi["win_name"]}"
  s << ', '
  s << "resultlen: #{"0x%016x" % defi["resultlen"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_get_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_lock_entry"] = lambda { |defi|
  s = "{ "
  s << "lock_type: #{defi["lock_type"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_lock_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_lock_all_entry"] = lambda { |defi|
  s = "{ "
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_lock_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_post_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_post_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_attr_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_keyval: #{defi["win_keyval"]}"
  s << ', '
  s << "attribute_val: #{"0x%016x" % defi["attribute_val"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_attr_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_errhandler_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_errhandler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_name_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "win_name: #{"0x%016x" % defi["win_name"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_set_name_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_shared_query_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "disp_unit: #{"0x%016x" % defi["disp_unit"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_shared_query_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_shared_query_c_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "size: #{"0x%016x" % defi["size"]}"
  s << ', '
  s << "disp_unit: #{"0x%016x" % defi["disp_unit"]}"
  s << ', '
  s << "baseptr: #{"0x%016x" % defi["baseptr"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_shared_query_c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_start_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << ', '
  s << "assert: #{defi["assert"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_sync_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_sync_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_test_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << ', '
  s << "flag: #{"0x%016x" % defi["flag"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_test_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_unlock_entry"] = lambda { |defi|
  s = "{ "
  s << "rank: #{defi["rank"]}"
  s << ', '
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_unlock_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_unlock_all_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_unlock_all_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_wait_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_wait_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Aint_add_entry"] = lambda { |defi|
  s = "{ "
  s << "base: #{defi["base"]}"
  s << ', '
  s << "disp: #{defi["disp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Aint_add_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Aint_diff_entry"] = lambda { |defi|
  s = "{ "
  s << "addr1: #{defi["addr1"]}"
  s << ', '
  s << "addr2: #{defi["addr2"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Aint_diff_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wtick_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wtick_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wtime_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Wtime_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_c2f08_entry"] = lambda { |defi|
  s = "{ "
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << ', '
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_c2f08_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f082c_entry"] = lambda { |defi|
  s = "{ "
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "c_status: #{"0x%016x" % defi["c_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f082c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f2f08_entry"] = lambda { |defi|
  s = "{ "
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << ', '
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f2f08_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f082f_entry"] = lambda { |defi|
  s = "{ "
  s << "f08_status: #{"0x%016x" % defi["f08_status"]}"
  s << ', '
  s << "f_status: #{"0x%016x" % defi["f_status"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Status_f082f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{"0x%016x" % defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "comm: #{defi["comm"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Comm_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{"0x%016x" % defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "errhandler: #{defi["errhandler"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Errhandler_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{defi["datatype"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Type_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{"0x%016x" % defi["file"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "file: #{defi["file"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_File_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{"0x%016x" % defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "group: #{defi["group"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Group_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "info: #{defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Info_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Message_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "message: #{"0x%016x" % defi["message"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Message_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Message_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "message: #{defi["message"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Message_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{"0x%016x" % defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "op: #{defi["op"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Op_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{"0x%016x" % defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "request: #{defi["request"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Request_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Session_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_c2f_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{"0x%016x" % defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_c2f_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_f2c_entry"] = lambda { |defi|
  s = "{ "
  s << "win: #{defi["win"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_Win_f2c_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{"0x%016x" % defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_changed_entry"] = lambda { |defi|
  s = "{ "
  s << "update_number: #{"0x%016x" % defi["update_number"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_changed_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_categories_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_categories_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_cvars_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_cvars_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_events_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_events_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "cat_index: #{"0x%016x" % defi["cat_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "num_cvars: #{"0x%016x" % defi["num_cvars"]}"
  s << ', '
  s << "num_pvars: #{"0x%016x" % defi["num_pvars"]}"
  s << ', '
  s << "num_categories: #{"0x%016x" % defi["num_categories"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_cat: #{"0x%016x" % defi["num_cat"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_num_events_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "num_events: #{"0x%016x" % defi["num_events"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_num_events_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_pvars_entry"] = lambda { |defi|
  s = "{ "
  s << "cat_index: #{defi["cat_index"]}"
  s << ', '
  s << "len: #{defi["len"]}"
  s << ', '
  s << "indices: #{"0x%016x" % defi["indices"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_category_get_pvars_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "cvar_index: #{"0x%016x" % defi["cvar_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "cvar_index: #{defi["cvar_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << ', '
  s << "scope: #{"0x%016x" % defi["scope"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_cvar: #{"0x%016x" % defi["num_cvar"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "cvar_index: #{defi["cvar_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_read_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_write_entry"] = lambda { |defi|
  s = "{ "
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_cvar_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_enum_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "num: #{"0x%016x" % defi["num"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_enum_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_enum_get_item_entry"] = lambda { |defi|
  s = "{ "
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "indx: #{defi["indx"]}"
  s << ', '
  s << "value: #{"0x%016x" % defi["value"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_enum_get_item_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_callback_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_callback_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_callback_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_callback_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_copy_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_copy_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "event_index: #{"0x%016x" % defi["event_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_index: #{defi["event_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "array_of_datatypes: #{"0x%016x" % defi["array_of_datatypes"]}"
  s << ', '
  s << "array_of_displacements: #{"0x%016x" % defi["array_of_displacements"]}"
  s << ', '
  s << "num_elements: #{"0x%016x" % defi["num_elements"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_events: #{"0x%016x" % defi["num_events"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_source_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "source_index: #{"0x%016x" % defi["source_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_source_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_timestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "event_timestamp: #{"0x%016x" % defi["event_timestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_get_timestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "event_index: #{defi["event_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "user_data: #{"0x%016x" % defi["user_data"]}"
  s << ', '
  s << "free_cb_function: #{"0x%016x" % defi["free_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "info_used: #{"0x%016x" % defi["info_used"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_set_info_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_handle_set_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_read_entry"] = lambda { |defi|
  s = "{ "
  s << "event_instance: #{"0x%016x" % defi["event_instance"]}"
  s << ', '
  s << "element_index: #{defi["element_index"]}"
  s << ', '
  s << "buffer: #{"0x%016x" % defi["buffer"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_register_callback_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "cb_safety: #{MPI::MPI_T_cb_safety.from_native(defi["cb_safety"], nil)}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << ', '
  s << "user_data: #{"0x%016x" % defi["user_data"]}"
  s << ', '
  s << "event_cb_function: #{"0x%016x" % defi["event_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_register_callback_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_set_dropped_handler_entry"] = lambda { |defi|
  s = "{ "
  s << "event_registration: #{"0x%016x" % defi["event_registration"]}"
  s << ', '
  s << "dropped_cb_function: #{"0x%016x" % defi["dropped_cb_function"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_event_set_dropped_handler_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_finalize_entry"] = lambda { |defi|
  s = "{ "
  
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_finalize_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_init_thread_entry"] = lambda { |defi|
  s = "{ "
  s << "required: #{defi["required"]}"
  s << ', '
  s << "provided: #{"0x%016x" % defi["provided"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_init_thread_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_index_entry"] = lambda { |defi|
  s = "{ "
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "var_class: #{defi["var_class"]}"
  s << ', '
  s << "pvar_index: #{"0x%016x" % defi["pvar_index"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_index_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "pvar_index: #{defi["pvar_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "verbosity: #{"0x%016x" % defi["verbosity"]}"
  s << ', '
  s << "var_class: #{"0x%016x" % defi["var_class"]}"
  s << ', '
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "enumtype: #{"0x%016x" % defi["enumtype"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "bind: #{"0x%016x" % defi["bind"]}"
  s << ', '
  s << "readonly: #{"0x%016x" % defi["readonly"]}"
  s << ', '
  s << "continuous: #{"0x%016x" % defi["continuous"]}"
  s << ', '
  s << "atomic: #{"0x%016x" % defi["atomic"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_pvar: #{"0x%016x" % defi["num_pvar"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_handle_alloc_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "pvar_index: #{defi["pvar_index"]}"
  s << ', '
  s << "obj_handle: #{"0x%016x" % defi["obj_handle"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "count: #{"0x%016x" % defi["count"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_handle_alloc_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_handle_free_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_handle_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_read_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_read_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_readreset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_readreset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_reset_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_reset_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_session_create_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_session_create_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_session_free_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_session_free_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_start_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_start_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_stop_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_stop_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_write_entry"] = lambda { |defi|
  s = "{ "
  s << "session: #{"0x%016x" % defi["session"]}"
  s << ', '
  s << "handle: #{"0x%016x" % defi["handle"]}"
  s << ', '
  s << "buf: #{"0x%016x" % defi["buf"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_pvar_write_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_info_entry"] = lambda { |defi|
  s = "{ "
  s << "source_index: #{defi["source_index"]}"
  s << ', '
  s << "name: #{"0x%016x" % defi["name"]}"
  s << ', '
  s << "name_len: #{"0x%016x" % defi["name_len"]}"
  s << ', '
  s << "desc: #{"0x%016x" % defi["desc"]}"
  s << ', '
  s << "desc_len: #{"0x%016x" % defi["desc_len"]}"
  s << ', '
  s << "ordering: #{"0x%016x" % defi["ordering"]}"
  s << ', '
  s << "ticks_per_second: #{"0x%016x" % defi["ticks_per_second"]}"
  s << ', '
  s << "max_ticks: #{"0x%016x" % defi["max_ticks"]}"
  s << ', '
  s << "info: #{"0x%016x" % defi["info"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_info_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_num_entry"] = lambda { |defi|
  s = "{ "
  s << "num_sources: #{"0x%016x" % defi["num_sources"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_num_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_timestamp_entry"] = lambda { |defi|
  s = "{ "
  s << "source_index: #{defi["source_index"]}"
  s << ', '
  s << "timestamp: #{"0x%016x" % defi["timestamp"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi:PMPI_T_source_get_timestamp_exit"] = lambda { |defi|
  s = "{ "
  s << "mpiResult: #{defi["mpiResult"]}"
  s << " }"
}
$event_lambdas["lttng_ust_mpi_type:property"] = lambda { |defi|
  s = "{ "
  s << "datatype: #{"0x%016x" % defi["datatype"]}"
  s << ', '
  s << "size: #{defi["size"]}"
  s << " }"
}
