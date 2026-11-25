
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_itt

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./itt_tracepoints.h"

#if !defined(ITT_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ITT_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ittnotify.h"
TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_domain_create,
  TP_ARGS(
    const char *, name,
    __itt_domain *, ittResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ittResult, (uintptr_t)(ittResult))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_string_handle_create,
  TP_ARGS(
    const char *, name,
    __itt_string_handle *, ittResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, ittResult, (uintptr_t)(ittResult))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_task_begin,
  TP_ARGS(
    const __itt_domain *, domain,
    __itt_id, taskid,
    __itt_id, parentid,
    __itt_string_handle *, name
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, domain, (uintptr_t)(domain))
    ctf_array_text(uint8_t, taskid, &taskid, sizeof(__itt_id))
    ctf_array_text(uint8_t, parentid, &parentid, sizeof(__itt_id))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_string(domain__nameA_val, (domain ? domain->nameA : 0))
    ctf_string(name__strA_val, (name ? name->strA : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_task_end,
  TP_ARGS(
    const __itt_domain *, domain
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, domain, (uintptr_t)(domain))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_metadata_add,
  TP_ARGS(
    const __itt_domain *, domain,
    __itt_id, id,
    __itt_string_handle *, key,
    __itt_metadata_type, type,
    size_t, count,
    void *, data
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, domain, (uintptr_t)(domain))
    ctf_array_text(uint8_t, id, &id, sizeof(__itt_id))
    ctf_integer_hex(uintptr_t, key, (uintptr_t)(key))
    ctf_integer(int32_t, type, type)
    ctf_integer(size_t, count, count)
    ctf_integer_hex(uintptr_t, data, (uintptr_t)(data))
    ctf_string(key__strA_val, (key ? key->strA : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_event_create,
  TP_ARGS(
    const char *, name,
    int, namelen,
    __itt_event, ittResult
  ),
  TP_FIELDS(
    ctf_integer(__itt_event, ittResult, ittResult)
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer(int, namelen, namelen)
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_event_start,
  TP_ARGS(
    __itt_event, event,
    int, ittResult
  ),
  TP_FIELDS(
    ctf_integer(int, ittResult, ittResult)
    ctf_integer(__itt_event, event, event)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_itt,
  __itt_event_end,
  TP_ARGS(
    __itt_event, event,
    int, ittResult
  ),
  TP_FIELDS(
    ctf_integer(int, ittResult, ittResult)
    ctf_integer(__itt_event, event, event)
  )
)


#endif /* ITT_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
