#pragma once
#include <metababel/btx_component.h>
#ifdef __cplusplus
extern "C" {
#endif

// Dispatcher
typedef void(dispatcher_t)(callbacks_t *callbacks, common_data_t *common_data,
                           const bt_message *upstream_message);

typedef void lttng_ust_mpi_MPI_Abort_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Abort_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Abort_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Abort_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Abort_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Abort_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Accumulate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Accumulate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_class_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_class_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_code_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_code_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_code_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_code_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_code_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_code_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_string_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Add_error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Add_error_string_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Add_error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allgatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allgatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allgatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alloc_mem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Info, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alloc_mem_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alloc_mem_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alloc_mem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alloc_mem_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alloc_mem_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Allreduce_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Allreduce_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Allreduce_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoall_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoall_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoall_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Alltoallw_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Alltoallw_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Alltoallw_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_delete_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_delete_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_put_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_put_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_put_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Attr_put_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Attr_put_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Attr_put_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Barrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Barrier_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Barrier_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Barrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Barrier_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Barrier_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Barrier_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Barrier_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Barrier_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Barrier_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Barrier_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Barrier_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bcast_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bcast_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bcast_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Bsend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Bsend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Bsend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_attach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_attach_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_attach_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_attach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_attach_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_attach_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_attach_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_attach_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_attach_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_attach_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_attach_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_attach_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_detach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_detach_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_detach_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_detach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_detach_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_detach_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_detach_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_detach_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_detach_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_detach_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_detach_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_detach_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_flush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_flush_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_flush_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_flush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_flush_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_flush_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_iflush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_iflush_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_iflush_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Buffer_iflush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Buffer_iflush_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Buffer_iflush_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cancel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cancel_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cancel_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cancel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cancel_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cancel_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_coords_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_coords_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_coords_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_coords_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_coords_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_coords_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_map_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_map_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_map_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_map_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_map_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_map_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_rank_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_rank_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_shift_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_shift_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_shift_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_shift_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_shift_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_shift_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_sub_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_sub_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_sub_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cart_sub_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cart_sub_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cart_sub_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cartdim_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cartdim_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Cartdim_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Cartdim_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Cartdim_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Cartdim_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Close_port_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Close_port_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Close_port_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Close_port_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Close_port_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Close_port_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_accept_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, int, MPI_Comm, MPI_Comm *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_accept_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_accept_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_accept_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_accept_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_accept_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_attach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_attach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_attach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_attach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_attach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_attach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_attach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_attach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_attach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_attach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_attach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_attach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_compare_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_compare_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_compare_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_compare_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_compare_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_compare_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_connect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, int, MPI_Comm, MPI_Comm *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_connect_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_connect_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_connect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_connect_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_connect_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm_errhandler_function *, MPI_Errhandler *, MPI_Comm_errhandler_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_from_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, char *, MPI_Info, MPI_Errhandler, MPI_Comm *, char *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_from_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_from_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_from_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_from_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_from_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *, MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_detach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_detach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_detach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_detach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_detach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_detach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_detach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_detach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_detach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_detach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_detach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_detach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_disconnect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_disconnect_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_disconnect_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_disconnect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_disconnect_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_disconnect_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_dup_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_dup_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_dup_with_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_dup_with_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_dup_with_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_dup_with_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_dup_with_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_dup_with_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_flush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_flush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_flush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_flush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_flush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_flush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_parent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_parent_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_parent_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_get_parent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_get_parent_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_get_parent_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_idup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_idup_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_idup_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_idup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_idup_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_idup_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_idup_with_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Comm *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_idup_with_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_idup_with_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_idup_with_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_idup_with_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_idup_with_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_iflush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_iflush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_iflush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_iflush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_iflush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_iflush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_join_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_join_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_join_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_join_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_join_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_join_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_rank_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_rank_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_remote_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_remote_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_remote_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_remote_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_remote_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_remote_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_remote_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_remote_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_remote_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_remote_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_remote_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_remote_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_set_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_spawn_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char **, int, MPI_Info, int, MPI_Comm, MPI_Comm *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_spawn_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_spawn_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_spawn_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_spawn_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_spawn_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_spawn_multiple_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char **, char ***, int *, MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_spawn_multiple_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_spawn_multiple_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_spawn_multiple_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_spawn_multiple_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_spawn_multiple_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_split_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_split_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_split_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_split_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_split_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_split_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_split_type_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, MPI_Info, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_split_type_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_split_type_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_split_type_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_split_type_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_split_type_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_test_inter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_test_inter_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_test_inter_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_test_inter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_test_inter_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_test_inter_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Compare_and_swap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Compare_and_swap_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Compare_and_swap_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Compare_and_swap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Compare_and_swap_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Compare_and_swap_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dims_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dims_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Dims_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dims_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dims_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Dims_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *, int *, MPI_Info, int, MPI_Comm *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_create_adjacent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, int *, int *, MPI_Info, int, MPI_Comm *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_create_adjacent_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_create_adjacent_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_create_adjacent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_create_adjacent_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_create_adjacent_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_neighbors_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_neighbors_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_neighbors_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_neighbors_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_neighbors_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_neighbors_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_neighbors_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_neighbors_count_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_neighbors_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Dist_graph_neighbors_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Dist_graph_neighbors_count_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Dist_graph_neighbors_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler *, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Error_class_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Error_class_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Error_string_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Error_string_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Exscan_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Exscan_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Exscan_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Fetch_and_op_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Fetch_and_op_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Fetch_and_op_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Fetch_and_op_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Fetch_and_op_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Fetch_and_op_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_close_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File *, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_close_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_close_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_close_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_close_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_close_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File_errhandler_function *, MPI_Errhandler *, MPI_File_errhandler_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_delete_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_delete_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_amode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_amode_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_amode_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_amode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_amode_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_amode_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_atomicity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_atomicity_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_atomicity_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_atomicity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_atomicity_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_atomicity_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_byte_offset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_byte_offset_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_byte_offset_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_byte_offset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_byte_offset_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_byte_offset_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_position_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_position_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_position_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_position_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_position_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_position_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_position_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_position_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_position_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_position_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_position_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_position_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_type_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Datatype, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_type_extent_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_type_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_type_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_type_extent_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_type_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_type_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_type_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_type_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_type_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_type_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_type_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_view_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *, MPI_Datatype *, MPI_Datatype *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_view_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_view_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_get_view_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Offset, MPI_Datatype, MPI_Datatype, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_get_view_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_get_view_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iread_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iread_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iread_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_iwrite_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_iwrite_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_iwrite_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_open_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *, int, MPI_Info, MPI_File *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_open_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_open_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_open_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_open_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_open_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_preallocate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_preallocate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_preallocate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_preallocate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_preallocate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_preallocate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_all_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_at_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_at_all_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_at_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_ordered_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_ordered_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_ordered_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_read_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_read_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_read_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_seek_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_seek_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_seek_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_seek_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_seek_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_seek_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_seek_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_seek_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_seek_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_seek_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_seek_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_seek_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_atomicity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_atomicity_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_atomicity_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_atomicity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_atomicity_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_atomicity_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_view_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, MPI_Datatype, MPI_Datatype, char *, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_view_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_view_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_set_view_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_set_view_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_set_view_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_sync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_sync_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_sync_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_sync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_sync_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_sync_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_all_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_at_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_at_all_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_at_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_begin_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_begin_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_end_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_ordered_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_ordered_end_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_ordered_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_write_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_write_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_write_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_MPI_Finalize_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Finalize_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Finalized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Finalized_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Finalized_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Finalized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Finalized_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Finalized_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Free_mem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Free_mem_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Free_mem_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Free_mem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Free_mem_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Free_mem_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Gatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Gatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Gatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_accumulate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_accumulate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_address_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_address_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_address_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_address_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_address_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_address_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_count_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_count_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_count_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_count_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_count_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_count_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_count_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_count_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_x_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_elements_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_elements_x_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_elements_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_hw_resource_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_hw_resource_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_hw_resource_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_hw_resource_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_hw_resource_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_hw_resource_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_library_version_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_library_version_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_library_version_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_library_version_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_library_version_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_library_version_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_processor_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_processor_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_processor_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_processor_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_processor_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_processor_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_version_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_version_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Get_version_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Get_version_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Get_version_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Get_version_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_map_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_map_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_map_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_map_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_map_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_map_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_neighbors_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_neighbors_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_neighbors_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_neighbors_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_neighbors_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_neighbors_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_neighbors_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_neighbors_count_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_neighbors_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graph_neighbors_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graph_neighbors_count_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graph_neighbors_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graphdims_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graphdims_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Graphdims_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Graphdims_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Graphdims_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Graphdims_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Grequest_complete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Grequest_complete_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Grequest_complete_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Grequest_complete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Grequest_complete_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Grequest_complete_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Grequest_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, void *, MPI_Request *, MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Grequest_start_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Grequest_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Grequest_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Grequest_start_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Grequest_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_compare_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_compare_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_compare_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_compare_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_compare_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_compare_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_difference_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_difference_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_difference_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_difference_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_difference_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_difference_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_excl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_excl_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_excl_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_excl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_excl_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_excl_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group *, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_from_session_pset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, char *, MPI_Group *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_from_session_pset_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_from_session_pset_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_from_session_pset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_from_session_pset_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_from_session_pset_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_incl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_incl_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_incl_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_incl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_incl_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_incl_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_intersection_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_intersection_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_intersection_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_intersection_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_intersection_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_intersection_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_range_excl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_range_excl_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_range_excl_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_range_excl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_range_excl_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_range_excl_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_range_incl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_range_incl_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_range_incl_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_range_incl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_range_incl_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_range_incl_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_rank_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_rank_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_translate_ranks_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_translate_ranks_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_translate_ranks_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_translate_ranks_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_translate_ranks_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_translate_ranks_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_union_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_union_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_union_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_union_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_union_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_union_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallreduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallreduce_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallreduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallreduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallreduce_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallreduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallreduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallreduce_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iallreduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iallreduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iallreduce_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iallreduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallw_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallw_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ialltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ialltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ialltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibarrier_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ibarrier_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibarrier_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ibarrier_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibcast_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibcast_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ibcast_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibcast_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibcast_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ibcast_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibcast_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibcast_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ibcast_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibcast_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibcast_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ibcast_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibsend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ibsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibsend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ibsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibsend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ibsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ibsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ibsend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ibsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iexscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iexscan_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iexscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iexscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iexscan_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iexscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iexscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iexscan_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iexscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iexscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iexscan_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iexscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Igather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Igather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Igather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Igather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Igatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Igatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Igatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Igatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Igatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Igatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Improbe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Improbe_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Improbe_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Improbe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Message, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Improbe_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Improbe_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Imrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, MPI_Message *, MPI_Request *, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_MPI_Imrecv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Imrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Imrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Imrecv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Imrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Imrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, MPI_Message *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Imrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Imrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Imrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Imrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Imrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ineighbor_alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_create_env_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char **, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_create_env_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_create_env_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_create_env_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_create_env_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_create_env_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_delete_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_delete_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_dup_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_dup_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int, char *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_nkeys_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_nkeys_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_nkeys_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_nkeys_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_nkeys_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_nkeys_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_nthkey_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_nthkey_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_nthkey_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_nthkey_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_nthkey_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_nthkey_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int *, char *, int *, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_string_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_string_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_valuelen_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_valuelen_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_valuelen_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_get_valuelen_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_get_valuelen_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_get_valuelen_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_set_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, char *, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_set_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_set_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_set_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_set_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_set_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, char ***, int, char **);

void btx_register_callbacks_lttng_ust_mpi_MPI_Init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Init_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, char ***, int, int *, int, char **);

void btx_register_callbacks_lttng_ust_mpi_MPI_Init_thread_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Init_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Init_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Init_thread_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Init_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Initialized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Initialized_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Initialized_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Initialized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Initialized_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Initialized_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_create_from_groups_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Group, int, char *, MPI_Info, MPI_Errhandler, MPI_Comm *, char *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_create_from_groups_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_create_from_groups_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_create_from_groups_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_create_from_groups_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_create_from_groups_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_merge_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_merge_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_merge_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Intercomm_merge_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Intercomm_merge_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Intercomm_merge_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iprobe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iprobe_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iprobe_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iprobe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iprobe_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iprobe_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irecv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Irecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irecv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Irecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irecv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Irecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irecv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Irecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_block_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_block_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_block_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ireduce_scatter_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ireduce_scatter_block_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ireduce_scatter_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irsend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Irsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irsend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Irsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irsend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Irsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Irsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Irsend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Irsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Is_thread_main_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Is_thread_main_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Is_thread_main_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Is_thread_main_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Is_thread_main_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Is_thread_main_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscan_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscan_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscan_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscan_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatter_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatter_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatter_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatter_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatterv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatterv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatterv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatterv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatterv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatterv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatterv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatterv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatterv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Iscatterv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Iscatterv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Iscatterv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_replace_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_replace_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_replace_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_replace_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_replace_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_replace_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_replace_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_replace_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_replace_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Isendrecv_replace_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Isendrecv_replace_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Isendrecv_replace_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Issend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Issend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Issend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Issend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Issend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Issend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Issend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Issend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Issend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Issend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Issend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Issend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Keyval_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Copy_function *, MPI_Delete_function *, int *, void *, MPI_Copy_function *, MPI_Delete_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Keyval_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Keyval_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Keyval_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Keyval_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Keyval_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Keyval_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Keyval_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Keyval_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Keyval_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Keyval_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Keyval_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Lookup_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Lookup_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Lookup_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Lookup_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Lookup_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Lookup_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mprobe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mprobe_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Mprobe_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mprobe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Message, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mprobe_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Mprobe_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, MPI_Message *, MPI_Status *, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mrecv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Mrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mrecv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Mrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Mrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Mrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Mrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Mrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_allgatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoall_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Neighbor_alltoallw_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_commutative_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_commutative_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_commutative_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_commutative_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_commutative_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_commutative_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_User_function *, int, MPI_Op *, MPI_User_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_create_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_User_function_c *, int, MPI_Op *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_create_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_create_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_create_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_create_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_create_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op *, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Open_port_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Open_port_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Open_port_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Open_port_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Open_port_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Open_port_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, int *, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Count *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, int, MPI_Datatype, void *, MPI_Aint, MPI_Aint *, char *, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, MPI_Datatype, MPI_Aint *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Count, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_size_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_external_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_external_size_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_external_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_size_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pack_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pack_size_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pack_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Parrived_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Parrived_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Parrived_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Parrived_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Parrived_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Parrived_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pcontrol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pcontrol_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pcontrol_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pcontrol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pcontrol_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pcontrol_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_list_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_list_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_list_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_list_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_list_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_list_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_range_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_range_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_range_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Pready_range_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Pready_range_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Pready_range_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Precv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Info, MPI_Request *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Precv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Precv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Precv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Precv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Precv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Probe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Probe_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Probe_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Probe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Probe_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Probe_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Psend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Info, MPI_Request *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Psend_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Psend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Psend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Psend_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Psend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Publish_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Publish_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Publish_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Publish_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Publish_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Publish_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Put_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Put_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Put_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Put_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Put_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Put_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Put_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Put_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Put_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Put_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Put_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Put_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Query_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Query_thread_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Query_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Query_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Query_thread_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Query_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Raccumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Raccumulate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Raccumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Raccumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Raccumulate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Raccumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Raccumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Raccumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Raccumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Raccumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Raccumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Raccumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Recv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Recv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Recv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_local_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_local_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_local_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_local_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_local_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_local_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_local_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_local_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_local_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_local_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_local_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_local_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_block_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Reduce_scatter_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Reduce_scatter_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Reduce_scatter_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Register_datarep_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Datarep_conversion_function *, MPI_Datarep_conversion_function *, MPI_Datarep_extent_function *, void *, char *, MPI_Datarep_conversion_function *, MPI_Datarep_conversion_function *, MPI_Datarep_extent_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Register_datarep_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Register_datarep_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Register_datarep_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Register_datarep_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Register_datarep_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Register_datarep_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Datarep_conversion_function_c *, MPI_Datarep_conversion_function_c *, MPI_Datarep_extent_function *, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Register_datarep_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Register_datarep_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Register_datarep_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Register_datarep_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Register_datarep_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_class_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_class_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_code_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_code_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_code_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_code_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_code_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_code_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_string_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Remove_error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Remove_error_string_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Remove_error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_any_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_any_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_any_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_any_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_any_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_any_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_some_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_some_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_some_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_get_status_some_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_get_status_some_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_get_status_some_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_accumulate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_accumulate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rget_accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rget_accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rget_accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rput_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rput_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rput_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rput_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rput_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rput_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rput_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rput_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rput_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rput_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rput_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rput_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Rsend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Rsend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Rsend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scan_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scan_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scan_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatter_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatter_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatter_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Scatterv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Scatterv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Scatterv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Send_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Send_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Send_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Send_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Send_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Send_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Send_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Send_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Send_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Send_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_replace_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_replace_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_replace_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_replace_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_replace_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_replace_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_replace_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_replace_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_replace_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Sendrecv_replace_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Sendrecv_replace_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Sendrecv_replace_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_attach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_attach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_attach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_attach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_attach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_attach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_attach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_attach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_attach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_attach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_attach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_attach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session_errhandler_function *, MPI_Errhandler *, MPI_Session_errhandler_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_detach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_detach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_detach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_detach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_detach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_detach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_detach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_detach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_detach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_detach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_detach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_detach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session *, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_finalize_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_finalize_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_flush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_flush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_flush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_flush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_flush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_flush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info *, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_nth_pset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info, int, int *, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_nth_pset_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_nth_pset_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_nth_pset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_nth_pset_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_nth_pset_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_num_psets_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_num_psets_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_num_psets_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_num_psets_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_num_psets_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_num_psets_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_pset_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, char *, MPI_Info *, char *, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_pset_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_pset_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_get_pset_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_get_pset_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_get_pset_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_iflush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_iflush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_iflush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_iflush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_iflush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_iflush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Errhandler, MPI_Session *, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_init_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_init_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Ssend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Ssend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Ssend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Start_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Start_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Start_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Start_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Startall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Startall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Startall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Startall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Startall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Startall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_error_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_error_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_error_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_error_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_error_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_error_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_source_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_source_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_tag_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_tag_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_tag_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_get_tag_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_get_tag_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_get_tag_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_cancelled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_cancelled_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_cancelled_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_cancelled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_cancelled_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_cancelled_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_x_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_elements_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_elements_x_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_elements_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_error_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_error_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_error_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_error_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_error_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_error_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_source_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_source_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_tag_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_tag_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_tag_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_set_tag_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_set_tag_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_set_tag_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, int *, MPI_Status *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Test_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Test_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Test_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Test_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Test_cancelled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Test_cancelled_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Test_cancelled_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Test_cancelled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Test_cancelled_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Test_cancelled_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Testall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Testall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testany_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testany_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Testany_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testany_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testany_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Testany_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testsome_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testsome_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Testsome_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Testsome_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Testsome_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Testsome_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Topo_test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Topo_test_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Topo_test_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Topo_test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Topo_test_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Topo_test_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_commit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype *, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_commit_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_commit_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_commit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_commit_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_commit_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_contiguous_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_contiguous_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_contiguous_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_contiguous_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_contiguous_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_contiguous_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_contiguous_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_contiguous_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_contiguous_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_contiguous_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_contiguous_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_contiguous_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_darray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, int *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_darray_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_darray_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_darray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_darray_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_darray_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_darray_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Count *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_darray_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_darray_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_darray_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_darray_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_darray_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_complex_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_complex_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_complex_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_complex_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_complex_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_complex_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_integer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_integer_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_integer_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_integer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_integer_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_integer_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_real_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_real_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_real_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_f90_real_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_f90_real_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_f90_real_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_block_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_block_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_block_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hindexed_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hindexed_block_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hindexed_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hvector_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hvector_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hvector_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hvector_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hvector_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hvector_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hvector_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hvector_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hvector_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_hvector_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_hvector_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_hvector_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_indexed_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_indexed_block_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_indexed_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_indexed_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_indexed_block_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_indexed_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_indexed_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_indexed_block_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_indexed_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_indexed_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_indexed_block_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_indexed_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *, MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_resized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint, MPI_Aint, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_resized_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_resized_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_resized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_resized_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_resized_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_resized_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count, MPI_Count, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_resized_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_resized_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_resized_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_resized_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_resized_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_struct_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_struct_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_struct_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_struct_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_struct_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_struct_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_struct_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_struct_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_struct_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_struct_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_struct_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_struct_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_subarray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_subarray_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_subarray_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_subarray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_subarray_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_subarray_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_subarray_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count *, MPI_Count *, MPI_Count *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_subarray_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_subarray_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_create_subarray_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_create_subarray_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_create_subarray_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_dup_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_dup_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype *, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_contents_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, int, int, int *, MPI_Aint *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_contents_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_contents_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_contents_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_contents_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_contents_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_contents_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count, MPI_Count, MPI_Count, MPI_Count, int *, MPI_Aint *, MPI_Count *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_contents_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_contents_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_contents_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_contents_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_contents_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_envelope_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int *, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_envelope_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_envelope_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_envelope_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_envelope_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_envelope_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_envelope_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *, MPI_Count *, MPI_Count *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_envelope_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_envelope_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_envelope_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_envelope_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_envelope_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_x_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_extent_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_extent_x_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_extent_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_x_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_true_extent_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_true_extent_x_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_true_extent_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_value_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_value_index_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_value_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_get_value_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_get_value_index_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_get_value_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_indexed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, int *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_indexed_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_indexed_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_indexed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_indexed_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_indexed_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_indexed_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_indexed_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_indexed_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_indexed_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_indexed_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_indexed_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_match_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_match_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_match_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_match_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_match_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_match_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_set_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_set_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_x_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_size_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_size_x_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_size_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_vector_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_vector_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_vector_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_vector_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_vector_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_vector_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_vector_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_vector_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_vector_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_vector_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_vector_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_vector_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, int *, void *, int, MPI_Datatype, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Count *, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_external_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Aint, MPI_Aint *, void *, int, MPI_Datatype, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_external_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_external_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_external_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_external_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_external_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_external_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Count, MPI_Count *, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_external_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_external_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpack_external_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpack_external_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Unpack_external_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpublish_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpublish_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Unpublish_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Unpublish_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Unpublish_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Unpublish_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wait_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, MPI_Status *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wait_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Wait_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wait_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wait_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Wait_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitall_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Waitall_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitall_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Waitall_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitany_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitany_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Waitany_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitany_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitany_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Waitany_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitsome_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitsome_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Waitsome_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Waitsome_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, size_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Waitsome_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Waitsome_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_shared_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_shared_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_allocate_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_allocate_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_allocate_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_attach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, void *, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_attach_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_attach_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_attach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_attach_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_attach_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_complete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_complete_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_complete_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_complete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_complete_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_complete_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_dynamic_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_dynamic_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_dynamic_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_dynamic_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_dynamic_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_dynamic_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win_errhandler_function *, MPI_Errhandler *, MPI_Win_errhandler_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win_copy_attr_function *, MPI_Win_delete_attr_function *, int *, void *, MPI_Win_copy_attr_function *, MPI_Win_delete_attr_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_detach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_detach_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_detach_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_detach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_detach_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_detach_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_fence_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_fence_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_fence_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_fence_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_fence_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_fence_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_local_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_local_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_local_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_local_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_local_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_local_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_local_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_local_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_local_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_flush_local_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_flush_local_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_flush_local_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win *, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_group_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_group_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_get_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_lock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_lock_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_lock_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_lock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_lock_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_lock_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_lock_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_lock_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_lock_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_lock_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_lock_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_lock_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_post_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_post_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_post_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_post_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_post_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_post_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_name_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_set_name_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_shared_query_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, MPI_Aint *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_shared_query_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_shared_query_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_shared_query_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Aint, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_shared_query_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_shared_query_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_shared_query_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, MPI_Aint *, MPI_Aint *, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_shared_query_c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_shared_query_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_shared_query_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_shared_query_c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_shared_query_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_start_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_start_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_sync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_sync_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_sync_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_sync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_sync_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_sync_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_test_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_test_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_test_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_test_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_unlock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_unlock_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_unlock_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_unlock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_unlock_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_unlock_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_unlock_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_unlock_all_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_unlock_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_unlock_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_unlock_all_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_unlock_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_wait_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_wait_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_wait_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_wait_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_wait_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_wait_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Aint_add_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Aint_add_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Aint_add_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Aint_add_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Aint_add_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Aint_add_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Aint_diff_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Aint_diff_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Aint_diff_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Aint_diff_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Aint_diff_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Aint_diff_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wtick_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wtick_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Wtick_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wtick_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, double);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wtick_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Wtick_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wtime_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wtime_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Wtime_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Wtime_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, double);

void btx_register_callbacks_lttng_ust_mpi_MPI_Wtime_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Wtime_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Fint *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint *, MPI_Status *, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_c2f08_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_F08_status *, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_c2f08_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_c2f08_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_c2f08_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_c2f08_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_c2f08_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f082c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_F08_status *, MPI_Status *, size_t, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f082c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f082c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f082c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f082c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f082c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f2f08_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint *, MPI_F08_status *, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f2f08_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f2f08_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f2f08_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, size_t, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f2f08_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f2f08_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f082f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_F08_status *, MPI_Fint *, size_t, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f082f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f082f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Status_f082f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Status_f082f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Status_f082f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Comm_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_MPI_Comm_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Comm_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Errhandler_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_MPI_Errhandler_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Errhandler_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Type_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Type_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_MPI_Type_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Type_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_File_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_File_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_MPI_File_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_File_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Group_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Group_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_MPI_Group_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Group_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Info_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Info_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_Info_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Info_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Message_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_MPI_Message_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Message_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Message_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Message_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Message_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Message_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Message_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Message_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Message_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_MPI_Message_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Message_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Op_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Op_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_MPI_Op_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Op_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Request_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Request_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_MPI_Request_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Request_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Session_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Session_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_MPI_Session_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Session_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_c2f_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_c2f_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_f2c_entry(
    void *btx_handle, lttng_ust_mpi_MPI_Win_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_Win_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_MPI_Win_f2c_exit(
    void *btx_handle, lttng_ust_mpi_MPI_Win_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_changed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_changed_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_changed_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_changed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_changed_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_changed_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_categories_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_categories_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_categories_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_categories_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_categories_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_categories_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_cvars_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_cvars_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_cvars_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_cvars_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_cvars_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_cvars_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_events_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_events_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_events_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_events_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_events_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_events_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_index_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_index_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, char *, int *, int *, int *, int *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, char *, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_num_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_num_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_num_events_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_num_events_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_num_events_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_num_events_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_num_events_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_num_events_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_pvars_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_pvars_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_pvars_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_category_get_pvars_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_category_get_pvars_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_category_get_pvars_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_index_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_index_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, MPI_Datatype *, MPI_T_enum *, char *, int *, int *, int *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int, MPI_Datatype, MPI_T_enum, char *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_num_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_get_num_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, void *, MPI_T_cvar_handle *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_T_cvar_handle, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle *, MPI_T_cvar_handle);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_read_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_read_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_write_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_cvar_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_cvar_write_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_cvar_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_enum_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_enum, int *, char *, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_enum_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_enum_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_enum_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_enum_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_enum_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_enum_get_item_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_enum, int, int *, char *, int *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_enum_get_item_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_enum_get_item_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_enum_get_item_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_enum_get_item_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_enum_get_item_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_callback_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_callback_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_callback_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_callback_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_callback_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_callback_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_callback_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_callback_set_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_callback_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_callback_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_callback_set_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_callback_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_copy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_copy_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_copy_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_copy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_copy_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_copy_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_index_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_index_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, MPI_Datatype *, MPI_Aint *, int *, MPI_T_enum *, MPI_Info *, char *, int *, int *, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int, MPI_T_enum, MPI_Info, char *, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_num_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_num_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_source_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_source_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_timestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_timestamp_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_timestamp_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_get_timestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_get_timestamp_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_get_timestamp_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, void *, MPI_Info, MPI_T_event_registration *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_T_event_registration);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, void *, MPI_T_event_free_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_set_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_handle_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_handle_set_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_handle_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, int, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_read_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_read_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_register_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info, void *, MPI_T_event_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_register_callback_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_register_callback_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_register_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_register_callback_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_register_callback_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_set_dropped_handler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_event_dropped_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_set_dropped_handler_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_set_dropped_handler_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_event_set_dropped_handler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_event_set_dropped_handler_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_event_set_dropped_handler_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_finalize_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_finalize_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_init_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_init_thread_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_init_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_init_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_init_thread_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_init_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_index_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_index_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, int *, MPI_Datatype *, MPI_T_enum *, char *, int *, int *, int *, int *, int *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int, int, MPI_Datatype, MPI_T_enum, char *, int, int, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_num_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_get_num_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, int, void *, MPI_T_pvar_handle *, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_T_pvar_handle, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle *, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_read_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_read_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_readreset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_readreset_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_readreset_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_readreset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_readreset_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_readreset_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_reset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_reset_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_reset_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_reset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_reset_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_reset_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_session_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_session_create_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_session_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_session_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_T_pvar_session);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_session_create_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_session_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_session_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session *, MPI_T_pvar_session);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_session_free_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_session_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_session_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_session_free_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_session_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_start_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_start_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_stop_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_stop_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_stop_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_stop_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_stop_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_stop_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_write_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_pvar_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_pvar_write_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_pvar_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, char *, int *, MPI_T_source_order *, MPI_Count *, MPI_Count *, MPI_Info *, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_info_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, char *, MPI_T_source_order, MPI_Count, MPI_Count, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_info_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_num_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_num_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_timestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_timestamp_entry(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_timestamp_entry_callback_f *callback);

typedef void lttng_ust_mpi_MPI_T_source_get_timestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_MPI_T_source_get_timestamp_exit(
    void *btx_handle, lttng_ust_mpi_MPI_T_source_get_timestamp_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Abort_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Abort_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Abort_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Abort_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Abort_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Abort_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Accumulate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Accumulate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_class_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_class_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_code_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_code_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_code_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_code_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_code_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_code_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_string_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Add_error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Add_error_string_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Add_error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allgatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allgatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allgatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alloc_mem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Info, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alloc_mem_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alloc_mem_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alloc_mem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alloc_mem_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alloc_mem_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Allreduce_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Allreduce_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Allreduce_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoall_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoall_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoall_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Alltoallw_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Alltoallw_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Alltoallw_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_delete_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_delete_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_put_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_put_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_put_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Attr_put_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Attr_put_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Attr_put_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Barrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Barrier_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Barrier_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Barrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Barrier_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Barrier_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Barrier_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Barrier_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Barrier_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Barrier_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Barrier_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Barrier_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bcast_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bcast_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bcast_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Bsend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Bsend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Bsend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_attach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_attach_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_attach_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_attach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_attach_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_attach_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_attach_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_attach_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_attach_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_attach_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_attach_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_attach_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_detach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_detach_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_detach_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_detach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_detach_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_detach_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_detach_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_detach_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_detach_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_detach_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_detach_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_detach_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_flush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_flush_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_flush_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_flush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_flush_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_flush_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_iflush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_iflush_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_iflush_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Buffer_iflush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Buffer_iflush_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Buffer_iflush_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cancel_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cancel_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cancel_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cancel_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cancel_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cancel_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_coords_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_coords_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_coords_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_coords_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_coords_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_coords_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_map_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_map_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_map_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_map_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_map_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_map_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_rank_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_rank_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_shift_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_shift_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_shift_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_shift_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_shift_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_shift_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_sub_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_sub_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_sub_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cart_sub_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cart_sub_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cart_sub_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cartdim_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cartdim_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Cartdim_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Cartdim_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Cartdim_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Cartdim_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Close_port_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Close_port_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Close_port_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Close_port_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Close_port_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Close_port_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_accept_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_accept_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_accept_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_accept_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_accept_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_accept_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_attach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_attach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_attach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_attach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_attach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_attach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_attach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_attach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_attach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_attach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_attach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_attach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_compare_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_compare_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_compare_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_compare_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_compare_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_compare_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_connect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, int, MPI_Comm, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_connect_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_connect_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_connect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_connect_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_connect_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm_errhandler_function *, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_from_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, char *, MPI_Info, MPI_Errhandler, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_from_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_from_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_from_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_from_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_from_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_detach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_detach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_detach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_detach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_detach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_detach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_detach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_detach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_detach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_detach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_detach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_detach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_disconnect_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_disconnect_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_disconnect_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_disconnect_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_disconnect_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_disconnect_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_dup_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_dup_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_dup_with_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_dup_with_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_dup_with_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_dup_with_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_dup_with_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_dup_with_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_flush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_flush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_flush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_flush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_flush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_flush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_parent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_parent_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_parent_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_get_parent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_get_parent_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_get_parent_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_idup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Comm *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_idup_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_idup_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_idup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_idup_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_idup_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_idup_with_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info, MPI_Comm *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_idup_with_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_idup_with_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_idup_with_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_idup_with_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_idup_with_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_iflush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_iflush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_iflush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_iflush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_iflush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_iflush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_join_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_join_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_join_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_join_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_join_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_join_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_rank_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_rank_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_remote_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_remote_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_remote_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_remote_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_remote_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_remote_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_remote_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_remote_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_remote_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_remote_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_remote_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_remote_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_set_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_spawn_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, char **, int, MPI_Info, int, MPI_Comm, MPI_Comm *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_spawn_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_spawn_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_spawn_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_spawn_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_spawn_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_spawn_multiple_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char **, char ***, int *, MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_spawn_multiple_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_spawn_multiple_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_spawn_multiple_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_spawn_multiple_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_spawn_multiple_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_split_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_split_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_split_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_split_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_split_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_split_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_split_type_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, MPI_Info, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_split_type_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_split_type_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_split_type_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_split_type_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_split_type_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_test_inter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_test_inter_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_test_inter_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_test_inter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_test_inter_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_test_inter_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Compare_and_swap_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Compare_and_swap_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Compare_and_swap_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Compare_and_swap_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Compare_and_swap_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Compare_and_swap_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dims_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dims_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Dims_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dims_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dims_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Dims_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *, int *, MPI_Info, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, int *, int *, MPI_Info, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_create_adjacent_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_neighbors_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_neighbors_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_neighbors_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_neighbors_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_neighbors_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_neighbors_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Dist_graph_neighbors_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Error_class_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Error_class_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Error_string_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Error_string_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Exscan_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Exscan_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Exscan_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Fetch_and_op_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Fetch_and_op_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Fetch_and_op_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Fetch_and_op_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Fetch_and_op_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Fetch_and_op_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_close_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_close_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_close_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_close_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_close_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_close_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File_errhandler_function *, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_delete_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_delete_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_amode_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_amode_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_amode_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_amode_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_amode_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_amode_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_atomicity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_atomicity_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_atomicity_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_atomicity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_atomicity_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_atomicity_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_byte_offset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_byte_offset_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_byte_offset_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_byte_offset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_byte_offset_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_byte_offset_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_position_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_position_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_position_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_position_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_position_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_position_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_position_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_position_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_position_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_position_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_position_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_position_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_type_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Datatype, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_type_extent_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_type_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_type_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_type_extent_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_type_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_type_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_type_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_type_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_type_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_type_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_type_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_view_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset *, MPI_Datatype *, MPI_Datatype *, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_view_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_view_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_get_view_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_get_view_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_get_view_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iread_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iread_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iread_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_iwrite_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_iwrite_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_iwrite_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_open_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, char *, int, MPI_Info, MPI_File *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_open_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_open_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_open_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_open_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_open_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_preallocate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_preallocate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_preallocate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_preallocate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_preallocate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_preallocate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_all_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_at_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_at_all_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_at_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_ordered_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_ordered_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_ordered_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_read_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_read_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_read_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_seek_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_seek_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_seek_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_seek_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_seek_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_seek_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_seek_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_seek_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_seek_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_seek_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_seek_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_seek_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_atomicity_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_atomicity_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_atomicity_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_atomicity_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_atomicity_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_atomicity_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_view_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, MPI_Datatype, MPI_Datatype, char *, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_view_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_view_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_set_view_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_set_view_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_set_view_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_sync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_sync_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_sync_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_sync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_sync_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_sync_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_all_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, MPI_Offset, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_at_all_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_at_all_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_at_all_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_begin_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_begin_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_begin_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_begin_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_begin_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_begin_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_begin_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_begin_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_begin_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_begin_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_begin_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_begin_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_end_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_end_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_end_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_ordered_end_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_ordered_end_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_ordered_end_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, int, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File, void *, MPI_Count, MPI_Datatype, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_write_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_write_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_write_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Finalize_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Finalize_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Finalized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Finalized_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Finalized_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Finalized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Finalized_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Finalized_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Free_mem_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Free_mem_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Free_mem_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Free_mem_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Free_mem_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Free_mem_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Gatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Gatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Gatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_accumulate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_accumulate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_address_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_address_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_address_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_address_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_address_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_address_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_count_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_count_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_count_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_count_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_count_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_count_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_count_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_count_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_x_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_elements_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_elements_x_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_elements_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_hw_resource_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_hw_resource_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_hw_resource_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_hw_resource_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_hw_resource_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_hw_resource_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_library_version_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_library_version_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_library_version_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_library_version_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_library_version_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_library_version_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_processor_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_processor_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_processor_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_processor_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_processor_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_processor_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_version_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_version_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_version_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Get_version_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Get_version_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Get_version_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_map_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_map_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_map_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_map_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_map_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_map_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_neighbors_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_neighbors_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_neighbors_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_neighbors_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_neighbors_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_neighbors_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_neighbors_count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_neighbors_count_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_neighbors_count_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graph_neighbors_count_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graph_neighbors_count_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graph_neighbors_count_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graphdims_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graphdims_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Graphdims_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Graphdims_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Graphdims_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Graphdims_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Grequest_complete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Grequest_complete_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Grequest_complete_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Grequest_complete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Grequest_complete_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Grequest_complete_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Grequest_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Grequest_query_function *, MPI_Grequest_free_function *, MPI_Grequest_cancel_function *, void *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Grequest_start_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Grequest_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Grequest_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Grequest_start_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Grequest_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_compare_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_compare_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_compare_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_compare_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_compare_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_compare_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_difference_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_difference_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_difference_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_difference_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_difference_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_difference_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_excl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_excl_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_excl_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_excl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_excl_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_excl_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_from_session_pset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, char *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_from_session_pset_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_from_session_pset_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_from_session_pset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_from_session_pset_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_from_session_pset_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_incl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_incl_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_incl_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_incl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_incl_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_incl_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_intersection_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_intersection_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_intersection_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_intersection_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_intersection_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_intersection_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_range_excl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_range_excl_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_range_excl_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_range_excl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_range_excl_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_range_excl_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_range_incl_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_range_incl_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_range_incl_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_range_incl_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_range_incl_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_range_incl_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_rank_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_rank_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_rank_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_rank_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_rank_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_rank_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_translate_ranks_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, int *, MPI_Group, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_translate_ranks_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_translate_ranks_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_translate_ranks_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_translate_ranks_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_translate_ranks_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_union_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, MPI_Group, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_union_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_union_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_union_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_union_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_union_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallreduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallreduce_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallreduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallreduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallreduce_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallreduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallreduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallreduce_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallreduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iallreduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iallreduce_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iallreduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype *, void *, int *, int *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallw_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallw_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ialltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ialltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ialltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibarrier_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibarrier_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibarrier_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibarrier_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibarrier_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibarrier_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibcast_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibcast_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibcast_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibcast_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibcast_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibcast_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibcast_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibcast_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibcast_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibcast_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibcast_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibcast_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibsend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibsend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibsend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ibsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ibsend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ibsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iexscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iexscan_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iexscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iexscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iexscan_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iexscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iexscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iexscan_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iexscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iexscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iexscan_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iexscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Igather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Igather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Igather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Igather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Igatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Igatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Igatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Igatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Igatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Igatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Improbe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Improbe_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Improbe_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Improbe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Improbe_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Improbe_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Imrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, MPI_Message *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Imrecv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Imrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Imrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Imrecv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Imrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Imrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, MPI_Message *, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Imrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Imrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Imrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Imrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Imrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ineighbor_alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_create_env_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char **, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_create_env_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_create_env_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_create_env_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_create_env_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_create_env_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_delete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_delete_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_delete_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_delete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_delete_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_delete_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_dup_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_dup_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_nkeys_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_nkeys_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_nkeys_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_nkeys_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_nkeys_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_nkeys_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_nthkey_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, int, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_nthkey_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_nthkey_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_nthkey_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_nthkey_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_nthkey_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int *, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_string_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_string_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_valuelen_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_valuelen_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_valuelen_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_get_valuelen_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_get_valuelen_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_get_valuelen_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_set_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_set_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_set_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_set_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_set_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_set_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, char ***);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Init_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *, char ***, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Init_thread_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Init_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Init_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Init_thread_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Init_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Initialized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Initialized_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Initialized_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Initialized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Initialized_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Initialized_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_create_from_groups_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Group, int, char *, MPI_Info, MPI_Errhandler, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_create_from_groups_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_create_from_groups_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_create_from_groups_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_create_from_groups_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_create_from_groups_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_merge_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int, MPI_Comm *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_merge_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_merge_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Intercomm_merge_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Intercomm_merge_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Intercomm_merge_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iprobe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iprobe_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iprobe_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iprobe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iprobe_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iprobe_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irecv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Irecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irecv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Irecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irecv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Irecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irecv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Irecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_block_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_block_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ireduce_scatter_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irsend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Irsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irsend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Irsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irsend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Irsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Irsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Irsend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Irsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Is_thread_main_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Is_thread_main_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Is_thread_main_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Is_thread_main_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Is_thread_main_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Is_thread_main_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscan_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscan_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscan_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscan_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscan_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscan_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatter_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatter_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatter_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatter_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatterv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatterv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatterv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatterv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatterv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatterv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatterv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatterv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatterv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Iscatterv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Iscatterv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Iscatterv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_replace_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_replace_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_replace_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_replace_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_replace_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_replace_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_replace_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_replace_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_replace_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Isendrecv_replace_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Isendrecv_replace_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Isendrecv_replace_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Issend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Issend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Issend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Issend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Issend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Issend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Issend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Issend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Issend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Issend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Issend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Issend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Keyval_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Copy_function *, MPI_Delete_function *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Keyval_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Keyval_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Keyval_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Keyval_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Keyval_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Keyval_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Keyval_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Keyval_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Keyval_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Keyval_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Keyval_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Lookup_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Lookup_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Lookup_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Lookup_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Lookup_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Lookup_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mprobe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mprobe_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Mprobe_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mprobe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mprobe_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Mprobe_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mrecv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Mrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mrecv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Mrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, MPI_Message *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Mrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Mrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Mrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Mrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgather_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_allgatherv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoall_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, MPI_Aint *, MPI_Datatype *, void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, void *, MPI_Count *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Neighbor_alltoallw_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_commutative_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_commutative_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_commutative_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_commutative_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_commutative_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_commutative_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_User_function *, int, MPI_Op *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_create_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_User_function_c *, int, MPI_Op *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_create_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_create_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_create_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_create_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_create_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Open_port_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Open_port_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Open_port_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Open_port_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Open_port_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Open_port_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, int *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Count *, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, int, MPI_Datatype, void *, MPI_Aint, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, MPI_Datatype, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Count, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_size_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_external_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_external_size_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_external_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Datatype, MPI_Comm, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_size_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pack_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pack_size_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pack_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Parrived_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Parrived_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Parrived_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Parrived_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Parrived_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Parrived_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pcontrol_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pcontrol_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pcontrol_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pcontrol_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pcontrol_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pcontrol_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_list_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_list_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_list_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_list_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_list_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_list_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_range_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_range_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_range_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Pready_range_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Pready_range_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Pready_range_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Precv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Precv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Precv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Precv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Precv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Precv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Probe_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Probe_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Probe_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Probe_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Probe_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Probe_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Psend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Psend_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Psend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Psend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Psend_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Psend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Publish_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Publish_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Publish_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Publish_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Publish_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Publish_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Put_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Put_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Put_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Put_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Put_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Put_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Put_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Put_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Put_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Put_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Put_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Put_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Query_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Query_thread_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Query_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Query_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Query_thread_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Query_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Raccumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Raccumulate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Raccumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Raccumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Raccumulate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Raccumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Raccumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Raccumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Raccumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Raccumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Raccumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Raccumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Recv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Recv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Recv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_local_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_local_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_local_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_local_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_local_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_local_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_local_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_local_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_local_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_local_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_local_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_local_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_block_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count *, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Reduce_scatter_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Reduce_scatter_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Reduce_scatter_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Register_datarep_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Datarep_conversion_function *, MPI_Datarep_conversion_function *, MPI_Datarep_extent_function *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Register_datarep_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Register_datarep_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Register_datarep_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Register_datarep_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Register_datarep_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Register_datarep_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Datarep_conversion_function_c *, MPI_Datarep_conversion_function_c *, MPI_Datarep_extent_function *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Register_datarep_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Register_datarep_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Register_datarep_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Register_datarep_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Register_datarep_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_class_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_class_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_class_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_class_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_class_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_class_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_code_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_code_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_code_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_code_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_code_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_code_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_string_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_string_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_string_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Remove_error_string_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Remove_error_string_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Remove_error_string_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_any_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_any_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_any_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_any_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_any_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_any_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_some_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_some_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_some_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_get_status_some_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_get_status_some_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_get_status_some_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_accumulate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_accumulate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_accumulate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_accumulate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_accumulate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_accumulate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_accumulate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_accumulate_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_accumulate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rget_accumulate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rget_accumulate_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rget_accumulate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rput_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rput_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rput_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rput_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rput_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rput_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rput_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, MPI_Aint, MPI_Count, MPI_Datatype, MPI_Win, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rput_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rput_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rput_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rput_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rput_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Rsend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Rsend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Rsend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, void *, MPI_Count, MPI_Datatype, MPI_Op, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scan_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scan_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scan_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatter_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatter_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatter_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count *, MPI_Aint *, MPI_Datatype, void *, MPI_Count, MPI_Datatype, int, MPI_Comm, MPI_Info, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Scatterv_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Scatterv_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Scatterv_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Send_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Send_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Send_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_replace_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_replace_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_replace_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_replace_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_replace_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_replace_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_replace_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_replace_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_replace_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Sendrecv_replace_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Sendrecv_replace_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Sendrecv_replace_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_attach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_attach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_attach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_attach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_attach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_attach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_attach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_attach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_attach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_attach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_attach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_attach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session_errhandler_function *, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_detach_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_detach_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_detach_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_detach_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_detach_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_detach_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_detach_buffer_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, void *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_detach_buffer_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_detach_buffer_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_detach_buffer_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_detach_buffer_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_detach_buffer_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_finalize_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_finalize_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_flush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_flush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_flush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_flush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_flush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_flush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_nth_pset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info, int, int *, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_nth_pset_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_nth_pset_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_nth_pset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_nth_pset_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_nth_pset_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_num_psets_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Info, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_num_psets_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_num_psets_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_num_psets_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_num_psets_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_num_psets_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_pset_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, char *, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_pset_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_pset_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_get_pset_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_get_pset_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_get_pset_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_iflush_buffer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_iflush_buffer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_iflush_buffer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_iflush_buffer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_iflush_buffer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_iflush_buffer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Errhandler, MPI_Session *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_init_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_init_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_init_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_init_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_init_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_init_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_init_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_init_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_init_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Ssend_init_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Ssend_init_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Ssend_init_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Start_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Start_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Start_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Start_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Startall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Startall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Startall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Startall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Startall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Startall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_error_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_error_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_error_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_error_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_error_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_error_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_source_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_source_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_tag_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_tag_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_tag_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_get_tag_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_get_tag_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_get_tag_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_cancelled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_cancelled_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_cancelled_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_cancelled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_cancelled_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_cancelled_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Datatype, MPI_Count);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_x_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_elements_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_elements_x_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_elements_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_error_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_error_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_error_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_error_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_error_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_error_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_source_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_source_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_tag_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_tag_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_tag_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_set_tag_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_set_tag_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_set_tag_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Test_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Test_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Test_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Test_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Test_cancelled_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Test_cancelled_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Test_cancelled_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Test_cancelled_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Test_cancelled_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Test_cancelled_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Testall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Testall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testany_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testany_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Testany_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testany_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testany_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Testany_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testsome_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testsome_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Testsome_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Testsome_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Testsome_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Testsome_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Topo_test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Topo_test_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Topo_test_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Topo_test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Topo_test_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Topo_test_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_commit_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_commit_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_commit_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_commit_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_commit_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_commit_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_contiguous_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_contiguous_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_contiguous_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_contiguous_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_contiguous_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_contiguous_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_contiguous_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_contiguous_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_contiguous_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_contiguous_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_contiguous_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_contiguous_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_darray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, int *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_darray_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_darray_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_darray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_darray_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_darray_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_darray_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Count *, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_darray_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_darray_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_darray_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_darray_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_darray_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_complex_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_complex_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_complex_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_complex_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_complex_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_complex_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_integer_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_integer_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_integer_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_integer_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_integer_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_integer_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_real_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_real_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_real_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_f90_real_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_f90_real_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_f90_real_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Aint *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_block_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_block_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hindexed_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hvector_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hvector_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hvector_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hvector_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hvector_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hvector_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hvector_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hvector_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hvector_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_hvector_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_hvector_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_hvector_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_indexed_block_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_indexed_block_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_indexed_block_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_indexed_block_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_indexed_block_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_indexed_block_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_indexed_block_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_indexed_block_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_indexed_block_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_indexed_block_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_indexed_block_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_indexed_block_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_resized_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint, MPI_Aint, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_resized_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_resized_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_resized_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_resized_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_resized_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_resized_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count, MPI_Count, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_resized_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_resized_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_resized_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_resized_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_resized_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_struct_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_struct_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_struct_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_struct_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_struct_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_struct_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_struct_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_struct_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_struct_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_struct_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_struct_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_struct_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_subarray_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, int *, int *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_subarray_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_subarray_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_subarray_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_subarray_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_subarray_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_subarray_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count *, MPI_Count *, MPI_Count *, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_subarray_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_subarray_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_create_subarray_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_create_subarray_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_create_subarray_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_dup_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_dup_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_dup_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_dup_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_dup_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_dup_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_contents_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, int, int, int *, MPI_Aint *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_contents_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_contents_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_contents_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_contents_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_contents_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_contents_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count, MPI_Count, MPI_Count, MPI_Count, int *, MPI_Aint *, MPI_Count *, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_contents_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_contents_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_contents_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_contents_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_contents_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_envelope_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int *, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_envelope_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_envelope_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_envelope_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_envelope_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_envelope_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_envelope_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *, MPI_Count *, MPI_Count *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_envelope_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_envelope_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_envelope_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_envelope_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_envelope_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_x_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_extent_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_extent_x_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_extent_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Aint *, MPI_Aint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_x_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_true_extent_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_true_extent_x_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_true_extent_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_value_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_value_index_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_value_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_get_value_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_get_value_index_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_get_value_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_indexed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *, int *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_indexed_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_indexed_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_indexed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_indexed_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_indexed_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_indexed_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count *, MPI_Count *, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_indexed_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_indexed_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_indexed_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_indexed_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_indexed_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_match_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_match_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_match_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_match_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_match_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_match_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_set_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_set_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_x_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_x_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_x_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_size_x_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_size_x_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_size_x_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_vector_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_vector_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_vector_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_vector_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_vector_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_vector_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_vector_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Count, MPI_Count, MPI_Count, MPI_Datatype, MPI_Datatype *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_vector_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_vector_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_vector_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_vector_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_vector_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, int, int *, void *, int, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Count, MPI_Count *, void *, MPI_Count, MPI_Datatype, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_external_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Aint, MPI_Aint *, void *, int, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_external_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_external_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_external_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_external_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_external_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_external_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, void *, MPI_Count, MPI_Count *, void *, MPI_Count, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_external_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_external_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpack_external_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpack_external_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpack_external_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpublish_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, MPI_Info, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpublish_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpublish_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Unpublish_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Unpublish_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Unpublish_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wait_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wait_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Wait_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wait_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wait_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Wait_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitall_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitall_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitall_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitall_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitall_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitall_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitany_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitany_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitany_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitany_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitany_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitany_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitsome_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Request *, int *, int *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitsome_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitsome_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Waitsome_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Waitsome_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Waitsome_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_shared_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_shared_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_shared_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_shared_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_shared_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_shared_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_shared_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, void *, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_shared_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_shared_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_allocate_shared_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_allocate_shared_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_allocate_shared_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_attach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, void *, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_attach_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_attach_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_attach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_attach_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_attach_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_call_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_call_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_call_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_call_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_call_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_call_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_complete_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_complete_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_complete_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_complete_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_complete_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_complete_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, void *, MPI_Aint, MPI_Aint, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_dynamic_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info, MPI_Comm, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_dynamic_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_dynamic_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_dynamic_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_dynamic_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_dynamic_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win_errhandler_function *, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win_copy_attr_function *, MPI_Win_delete_attr_function *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_create_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_create_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_create_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_delete_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_delete_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_delete_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_delete_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_delete_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_delete_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_detach_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_detach_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_detach_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_detach_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_detach_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_detach_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_fence_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_fence_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_fence_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_fence_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_fence_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_fence_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_local_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_local_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_local_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_local_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_local_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_local_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_local_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_local_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_local_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_flush_local_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_flush_local_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_flush_local_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_free_keyval_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_free_keyval_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_free_keyval_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_free_keyval_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_free_keyval_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_free_keyval_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, void *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Errhandler *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_group_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Group *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_group_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_group_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_group_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_group_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_group_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_get_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_get_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_get_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_lock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_lock_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_lock_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_lock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_lock_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_lock_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_lock_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_lock_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_lock_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_lock_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_lock_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_lock_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_post_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_post_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_post_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_post_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_post_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_post_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_attr_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_attr_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_attr_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_attr_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_attr_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_attr_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_errhandler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_errhandler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_errhandler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_errhandler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_errhandler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_errhandler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_name_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, char *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_name_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_name_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_set_name_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_set_name_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_set_name_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_shared_query_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, MPI_Aint *, int *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_shared_query_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_shared_query_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_shared_query_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_shared_query_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_shared_query_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_shared_query_c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int, MPI_Aint *, MPI_Aint *, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_shared_query_c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_shared_query_c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_shared_query_c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_shared_query_c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_shared_query_c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_start_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_start_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_sync_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_sync_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_sync_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_sync_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_sync_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_sync_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_test_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_test_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_test_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_test_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_test_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_test_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_unlock_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_unlock_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_unlock_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_unlock_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_unlock_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_unlock_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_unlock_all_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_unlock_all_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_unlock_all_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_unlock_all_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_unlock_all_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_unlock_all_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_wait_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_wait_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_wait_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_wait_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_wait_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_wait_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Aint_add_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Aint_add_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Aint_add_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Aint_add_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Aint_add_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Aint_add_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Aint_diff_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Aint_diff_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Aint_diff_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Aint_diff_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Aint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Aint_diff_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Aint_diff_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wtick_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wtick_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Wtick_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wtick_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, double);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wtick_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Wtick_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wtime_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wtime_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Wtime_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Wtime_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, double);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Wtime_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Wtime_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_Fint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_c2f08_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Status *, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_c2f08_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_c2f08_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_c2f08_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_c2f08_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_c2f08_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f082c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_F08_status *, MPI_Status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f082c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f082c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f082c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f082c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f082c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f2f08_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint *, MPI_F08_status *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f2f08_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f2f08_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f2f08_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f2f08_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f2f08_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f082f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_F08_status *, MPI_Fint *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f082f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f082f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Status_f082f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Status_f082f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Status_f082f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Comm_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Comm);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Comm_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Comm_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Errhandler_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Errhandler);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Errhandler_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Errhandler_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Type_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Type_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Type_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_File_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_File_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_File);

void btx_register_callbacks_lttng_ust_mpi_PMPI_File_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_File_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Group_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Group);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Group_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Group_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Info_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Info_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Info_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Message_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Message_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Message_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Message_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Message_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Message_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Message_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Message_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Message_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Message_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Message);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Message_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Message_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Op_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Op);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Op_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Op_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Request_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Request);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Request_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Request_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Session_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Session);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Session_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Session_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_c2f_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_c2f_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_c2f_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_c2f_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_c2f_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_c2f_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_f2c_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Fint);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_f2c_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_f2c_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_Win_f2c_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Win);

void btx_register_callbacks_lttng_ust_mpi_PMPI_Win_f2c_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_Win_f2c_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_changed_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_changed_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_changed_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_changed_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_changed_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_changed_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_categories_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_categories_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_categories_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_categories_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_categories_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_categories_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_cvars_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_cvars_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_cvars_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_cvars_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_cvars_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_cvars_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_events_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_events_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_events_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_events_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_events_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_events_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_index_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_index_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, char *, int *, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_num_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_num_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_num_events_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_num_events_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_num_events_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_num_events_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_num_events_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_num_events_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_pvars_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_pvars_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_pvars_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_category_get_pvars_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_category_get_pvars_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_category_get_pvars_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_index_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_index_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, MPI_Datatype *, MPI_T_enum *, char *, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_num_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_get_num_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, void *, MPI_T_cvar_handle *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_read_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_read_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_cvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_write_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_cvar_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_cvar_write_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_cvar_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_enum_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_enum, int *, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_enum_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_enum_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_enum_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_enum_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_enum_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_enum_get_item_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_enum, int, int *, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_enum_get_item_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_enum_get_item_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_enum_get_item_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_enum_get_item_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_enum_get_item_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_callback_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_callback_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_callback_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_callback_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_callback_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_callback_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_callback_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_callback_set_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_callback_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_callback_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_callback_set_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_callback_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_copy_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_copy_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_copy_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_copy_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_copy_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_copy_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_index_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_index_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, MPI_Datatype *, MPI_Aint *, int *, MPI_T_enum *, MPI_Info *, char *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_num_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_num_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_source_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_source_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_source_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_source_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_source_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_source_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_timestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_timestamp_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_timestamp_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_get_timestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_get_timestamp_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_get_timestamp_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, void *, MPI_Info, MPI_T_event_registration *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, void *, MPI_T_event_free_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_set_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_Info);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_set_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_set_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_handle_set_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_handle_set_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_handle_set_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_instance, int, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_read_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_read_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_register_callback_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_cb_safety, MPI_Info, void *, MPI_T_event_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_register_callback_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_register_callback_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_register_callback_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_register_callback_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_register_callback_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_set_dropped_handler_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_event_registration, MPI_T_event_dropped_cb_function *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_set_dropped_handler_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_set_dropped_handler_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_event_set_dropped_handler_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_event_set_dropped_handler_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_event_set_dropped_handler_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_finalize_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_finalize_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_finalize_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_finalize_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_finalize_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_finalize_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_init_thread_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_init_thread_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_init_thread_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_init_thread_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_init_thread_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_init_thread_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_index_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, char *, int, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_index_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_index_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_index_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_index_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_index_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, int *, int *, MPI_Datatype *, MPI_T_enum *, char *, int *, int *, int *, int *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_num_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_get_num_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_handle_alloc_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, int, void *, MPI_T_pvar_handle *, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_handle_alloc_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_handle_alloc_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_handle_alloc_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_handle_alloc_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_handle_alloc_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_handle_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_handle_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_handle_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_handle_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_handle_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_handle_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_read_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_read_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_read_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_read_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_read_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_read_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_readreset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_readreset_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_readreset_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_readreset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_readreset_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_readreset_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_reset_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_reset_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_reset_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_reset_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_reset_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_reset_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_session_create_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_session_create_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_session_create_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_session_create_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_session_create_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_session_create_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_session_free_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_session_free_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_session_free_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_session_free_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_session_free_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_session_free_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_start_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_start_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_start_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_start_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_start_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_start_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_stop_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_stop_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_stop_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_stop_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_stop_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_stop_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_write_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_T_pvar_session, MPI_T_pvar_handle, void *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_write_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_write_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_pvar_write_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_pvar_write_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_pvar_write_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_info_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, char *, int *, char *, int *, MPI_T_source_order *, MPI_Count *, MPI_Count *, MPI_Info *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_info_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_info_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_info_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_info_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_info_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_num_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_num_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_num_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_num_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_num_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_num_exit_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_timestamp_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int, MPI_Count *);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_timestamp_entry(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_timestamp_entry_callback_f *callback);

typedef void lttng_ust_mpi_PMPI_T_source_get_timestamp_exit_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_lttng_ust_mpi_PMPI_T_source_get_timestamp_exit(
    void *btx_handle, lttng_ust_mpi_PMPI_T_source_get_timestamp_exit_callback_f *callback);

typedef void lttng_ust_mpi_type_property_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char*, int64_t, uint64_t, MPI_Datatype, int);

void btx_register_callbacks_lttng_ust_mpi_type_property(
    void *btx_handle, lttng_ust_mpi_type_property_callback_f *callback);

typedef void entries_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_entries(
    void *btx_handle, entries_callback_f *callback);

typedef void exits_mpiError_present_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, int);

void btx_register_callbacks_exits_mpiError_present(
    void *btx_handle, exits_mpiError_present_callback_f *callback);

typedef void exits_mpiError_absent_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t);

void btx_register_callbacks_exits_mpiError_absent(
    void *btx_handle, exits_mpiError_absent_callback_f *callback);

typedef void traffic_MPI_Count_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, MPI_Count, MPI_Datatype);

void btx_register_callbacks_traffic_MPI_Count_entry(
    void *btx_handle, traffic_MPI_Count_entry_callback_f *callback);

typedef void traffic_int_entry_callback_f(
    void *btx_handle,
    void *
        usr_data, int64_t, const char *, const char*, int64_t, uint64_t, int, MPI_Datatype);

void btx_register_callbacks_traffic_int_entry(
    void *btx_handle, traffic_int_entry_callback_f *callback);

void btx_unregister_callbacks(common_data_t *common_data);

#ifdef __cplusplus
}
#endif
