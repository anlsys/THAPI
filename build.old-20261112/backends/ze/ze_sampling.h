
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_ze_sampling

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ze_sampling.h"

#if !defined(ZE_SAMPLING_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZE_SAMPLING_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  deviceProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t, deviceIdx,
    zes_device_properties_t *, pDeviceProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer(uint32_t, deviceIdx, deviceIdx)
    ctf_sequence_text(uint8_t, pDeviceProperties_val, pDeviceProperties, size_t, sizeof(zes_device_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  engineProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_engine_handle_t, hEngines,
    zes_engine_properties_t *, pEngineProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hEngines, (uintptr_t)hEngines)
    ctf_sequence_text(uint8_t, pEngineProperties_val, pEngineProperties, size_t, sizeof(zes_engine_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  engineStats,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_engine_handle_t, hEngines,
    zes_engine_stats_t *, pEngineStats
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hEngines, (uintptr_t)hEngines)
    ctf_sequence_text(uint8_t, pEngineStats_val, pEngineStats, size_t, sizeof(zes_engine_stats_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  powerProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pwr_handle_t, hPowers,
    zes_power_properties_t *, pPowerProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hPowers, (uintptr_t)hPowers)
    ctf_sequence_text(uint8_t, pPowerProperties_val, pPowerProperties, size_t, sizeof(zes_power_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  gpu_energy,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pwr_handle_t, hPowers,
    uint32_t, domainIdx,
    zes_power_energy_counter_t *, pEnergyCounter
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hPowers, (uintptr_t)hPowers)
    ctf_integer(uint32_t, domainIdx, domainIdx)
    ctf_sequence_text(uint8_t, pEnergyCounter_val, pEnergyCounter, size_t, sizeof(zes_power_energy_counter_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  freqProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_freq_handle_t, hFrequency,
    zes_freq_properties_t *, pFreqProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)hFrequency)
    ctf_sequence_text(uint8_t, pFreqProperties_val, pFreqProperties, size_t, sizeof(zes_freq_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  gpu_frequency,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_freq_handle_t, hFrequency,
    uint32_t, domainIdx,
    zes_freq_state_t *, pFreqState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)hFrequency)
    ctf_integer(uint32_t, domainIdx, domainIdx)
    ctf_sequence_text(uint8_t, pFreqState_val, pFreqState, size_t, sizeof(zes_freq_state_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  fabricPortProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_fabric_port_handle_t, hFabricPort,
    zes_fabric_port_properties_t *, pFabricPortProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hFabricPort, (uintptr_t)hFabricPort)
    ctf_sequence_text(uint8_t, pFabricPortProperties_val, pFabricPortProperties, size_t, sizeof(zes_fabric_port_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  fabricPort,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_fabric_port_handle_t, hFabricPort,
    zes_fabric_port_state_t *, pFabricPortState,
    zes_fabric_port_throughput_t *, pFabricPortThroughput
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hFabricPort, (uintptr_t)hFabricPort)
    ctf_sequence_text(uint8_t, pFabricPortState_val, pFabricPortState, size_t, sizeof(zes_fabric_port_state_t))
    ctf_sequence_text(uint8_t, pFabricPortThroughput_val, pFabricPortThroughput, size_t, sizeof(zes_fabric_port_throughput_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  memoryProperties,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_mem_handle_t, hMemModule,
    zes_mem_properties_t *, pMemModuleProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hMemModule, (uintptr_t)hMemModule)
    ctf_sequence_text(uint8_t, pMemModuleProperties_val, pMemModuleProperties, size_t, sizeof(zes_mem_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_ze_sampling,
  memStats,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_mem_handle_t, hMemModule,
    zes_mem_state_t *, pMemState,
    zes_mem_bandwidth_t *, pMemBandwidth
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)hDevice)
    ctf_integer_hex(uintptr_t, hMemModule, (uintptr_t)hMemModule)
    ctf_sequence_text(uint8_t, pMemState_val, pMemState, size_t, sizeof(zes_mem_state_t))
    ctf_sequence_text(uint8_t, pMemBandwidth_val, pMemBandwidth, size_t, sizeof(zes_mem_bandwidth_t))
  )
)


#endif /* ZE_SAMPLING_H */

#include <lttng/tracepoint-event.h>
