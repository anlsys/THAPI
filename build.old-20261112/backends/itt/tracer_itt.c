#define INTEL_NO_MACRO_BODY
#define INTEL_ITTNOTIFY_API_PRIVATE
#include "itt_tracepoints.h"
#include "itt_metadata.h"

#include "ittnotify.h"
#include "ittnotify_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

static _Atomic uint32_t event_counter = 0;

static inline size_t __itt_metadata_type_size(__itt_metadata_type type)
{
    switch (type) {
        case __itt_metadata_u64:
        case __itt_metadata_s64:
        case __itt_metadata_double:
            return 8;
        case __itt_metadata_u32:
        case __itt_metadata_s32:
        case __itt_metadata_float:
            return 4;
        case __itt_metadata_u16:
        case __itt_metadata_s16:
            return 2;
        case __itt_metadata_unknown:
        default:
            return 0;
    }
}
__itt_domain *__itt_domain_create(const char *name) {
  __itt_domain * _retval = calloc(1, sizeof(*_retval));
  _retval->flags = 1; _retval->nameA=name;
  tracepoint(lttng_ust_itt, __itt_domain_create, name, _retval);
  return _retval;
}

__itt_string_handle *__itt_string_handle_create(const char *name) {
  __itt_string_handle * _retval = calloc(1, sizeof(*_retval));
  _retval->strA=name;
  tracepoint(lttng_ust_itt, __itt_string_handle_create, name, _retval);
  return _retval;
}

void __itt_task_begin(const __itt_domain *domain, __itt_id taskid, __itt_id parentid, __itt_string_handle *name) {
  if (domain->flags == 0) return;
  tracepoint(lttng_ust_itt, __itt_task_begin, domain, taskid, parentid, name);
}

void __itt_task_end(const __itt_domain *domain) {
  if (domain->flags == 0) return;
  tracepoint(lttng_ust_itt, __itt_task_end, domain);
}

void __itt_metadata_add(const __itt_domain *domain, __itt_id id, __itt_string_handle *key, __itt_metadata_type type, size_t count, void *data) {
  tracepoint(lttng_ust_itt_metadata, metadata, type, count, count * __itt_metadata_type_size(type), data);
  tracepoint(lttng_ust_itt, __itt_metadata_add, domain, id, key, type, count, data);
}

__itt_event __itt_event_create(const char *name, int namelen) {
  __itt_event _retval = {0};
  _retval = atomic_fetch_add(&event_counter, 1);
  tracepoint(lttng_ust_itt, __itt_event_create, name, namelen, _retval);
  return _retval;
}

int __itt_event_start(__itt_event event) {
  int _retval = {0};
  tracepoint(lttng_ust_itt, __itt_event_start, event, _retval);
  return _retval;
}

int __itt_event_end(__itt_event event) {
  int _retval = {0};
  tracepoint(lttng_ust_itt, __itt_event_end, event, _retval);
  return _retval;
}

static void fill_func_ptr_per_lib(__itt_global* p)
{
    __itt_api_info* api_list = (__itt_api_info*)p->api_list_ptr;

    for (int i = 0; api_list[i].name != NULL; i++)
    {
        *(api_list[i].func_ptr) = (void*)__itt_get_proc(p->lib, api_list[i].name);
        if (*(api_list[i].func_ptr) == NULL)
        {
            *(api_list[i].func_ptr) = api_list[i].null_func;
        }
    }
}

extern void ITTAPI __itt_api_init(__itt_global* p, __itt_group_id init_groups)
{
    if (p != NULL)
    {
        (void)init_groups;
        fill_func_ptr_per_lib(p);
    }
    else
    {
        printf("ERROR: Failed to initialize dynamic library\n");
    }
}
