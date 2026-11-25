
#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER lttng_ust_zes

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./zes_tracepoints.h"

#if !defined(ZES_TRACEPOINTS_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define ZES_TRACEPOINTS_H

#include <lttng/tracepoint.h>

#include "lttng/tracepoint_gen.h"
#include "ze.h.include"
TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesInit_entry,
  TP_ARGS(
    zes_init_flags_t, flags
  ),
  TP_FIELDS(
    ctf_integer(zes_init_flags_t, flags, flags)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesInit_exit,
  TP_ARGS(
    zes_init_flags_t, flags,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGet_entry,
  TP_ARGS(
    uint32_t *, pCount,
    zes_driver_handle_t *, phDrivers
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phDrivers, (uintptr_t)(phDrivers))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGet_exit,
  TP_ARGS(
    uint32_t *, pCount,
    zes_driver_handle_t *, phDrivers,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phDrivers_vals, phDrivers, uint32_t, (pCount && phDrivers ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetExtensionProperties_entry,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    uint32_t *, pCount,
    zes_driver_extension_properties_t *, pExtensionProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pExtensionProperties, (uintptr_t)(pExtensionProperties))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetExtensionProperties_exit,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    uint32_t *, pCount,
    zes_driver_extension_properties_t *, pExtensionProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pExtensionProperties_vals, pExtensionProperties, size_t, ((pCount && pExtensionProperties ? *pCount : 0)) * sizeof(zes_driver_extension_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetExtensionFunctionAddress_entry,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    const char *, name,
    void **, ppFunctionAddress
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_integer_hex(uintptr_t, name, (uintptr_t)(name))
    ctf_integer_hex(uintptr_t, ppFunctionAddress, (uintptr_t)(ppFunctionAddress))
    ctf_string(name_val, name)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetExtensionFunctionAddress_exit,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    const char *, name,
    void **, ppFunctionAddress,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer_hex(uintptr_t, ppFunctionAddress_val, (uintptr_t)((ppFunctionAddress ? *ppFunctionAddress : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGet_entry,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    uint32_t *, pCount,
    zes_device_handle_t *, phDevices
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phDevices, (uintptr_t)(phDevices))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGet_exit,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    uint32_t *, pCount,
    zes_device_handle_t *, phDevices,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phDevices_vals, phDevices, uint32_t, (pCount && phDevices ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetProperties_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetProperties_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_device_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_device_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceReset_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t, force
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer(ze_bool_t, force, force)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceReset_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t, force,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceResetExt_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_reset_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_reset_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceResetExt_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_reset_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceProcessesGetState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_process_state_t *, pProcesses
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pProcesses, (uintptr_t)(pProcesses))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceProcessesGetState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_process_state_t *, pProcesses,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pProcesses_vals, pProcesses, size_t, ((pCount && pProcesses ? *pCount : 0)) * sizeof(zes_process_state_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetProperties_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetProperties_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_pci_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_pci_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetBars_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_pci_bar_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetBars_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_pci_bar_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pProperties_vals, pProperties, size_t, ((pCount && pProperties ? *pCount : 0)) * sizeof(zes_pci_bar_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetStats_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_stats_t *, pStats
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pStats, (uintptr_t)(pStats))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDevicePciGetStats_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pci_stats_t *, pStats,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pStats_val, pStats, size_t, (pStats ? sizeof(zes_pci_stats_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceSetOverclockWaiver_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceSetOverclockWaiver_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetOverclockDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pOverclockDomains
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pOverclockDomains, (uintptr_t)(pOverclockDomains))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetOverclockDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pOverclockDomains,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pOverclockDomains_val, (pOverclockDomains ? *pOverclockDomains : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetOverclockControls_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_overclock_domain_t, domainType,
    uint32_t *, pAvailableControls
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer(int32_t, domainType, domainType)
    ctf_integer_hex(uintptr_t, pAvailableControls, (uintptr_t)(pAvailableControls))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetOverclockControls_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_overclock_domain_t, domainType,
    uint32_t *, pAvailableControls,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pAvailableControls_val, (pAvailableControls ? *pAvailableControls : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceResetOverclockSettings_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t, onShippedState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer(ze_bool_t, onShippedState, onShippedState)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceResetOverclockSettings_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t, onShippedState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceReadOverclockState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_overclock_mode_t *, pOverclockMode,
    ze_bool_t *, pWaiverSetting,
    ze_bool_t *, pOverclockState,
    zes_pending_action_t *, pPendingAction,
    ze_bool_t *, pPendingReset
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pOverclockMode, (uintptr_t)(pOverclockMode))
    ctf_integer_hex(uintptr_t, pWaiverSetting, (uintptr_t)(pWaiverSetting))
    ctf_integer_hex(uintptr_t, pOverclockState, (uintptr_t)(pOverclockState))
    ctf_integer_hex(uintptr_t, pPendingAction, (uintptr_t)(pPendingAction))
    ctf_integer_hex(uintptr_t, pPendingReset, (uintptr_t)(pPendingReset))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceReadOverclockState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_overclock_mode_t *, pOverclockMode,
    ze_bool_t *, pWaiverSetting,
    ze_bool_t *, pOverclockState,
    zes_pending_action_t *, pPendingAction,
    ze_bool_t *, pPendingReset,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pOverclockMode_val, (pOverclockMode ? *pOverclockMode : 0))
    ctf_integer(ze_bool_t, pWaiverSetting_val, (pWaiverSetting ? *pWaiverSetting : 0))
    ctf_integer(ze_bool_t, pOverclockState_val, (pOverclockState ? *pOverclockState : 0))
    ctf_integer(int32_t, pPendingAction_val, (pPendingAction ? *pPendingAction : 0))
    ctf_integer(ze_bool_t, pPendingReset_val, (pPendingReset ? *pPendingReset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumOverclockDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_overclock_handle_t *, phDomainHandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phDomainHandle, (uintptr_t)(phDomainHandle))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumOverclockDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_overclock_handle_t *, phDomainHandle,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phDomainHandle_vals, phDomainHandle, uint32_t, (pCount && phDomainHandle ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainProperties_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_properties_t *, pDomainProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer_hex(uintptr_t, pDomainProperties, (uintptr_t)(pDomainProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainProperties_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_properties_t *, pDomainProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pDomainProperties_val, pDomainProperties, size_t, (pDomainProperties ? sizeof(zes_overclock_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainVFProperties_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_property_t *, pVFProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer_hex(uintptr_t, pVFProperties, (uintptr_t)(pVFProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainVFProperties_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_property_t *, pVFProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pVFProperties_val, pVFProperties, size_t, (pVFProperties ? sizeof(zes_vf_property_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainControlProperties_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    zes_control_property_t *, pControlProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, DomainControl, DomainControl)
    ctf_integer_hex(uintptr_t, pControlProperties, (uintptr_t)(pControlProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetDomainControlProperties_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    zes_control_property_t *, pControlProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pControlProperties_val, pControlProperties, size_t, (pControlProperties ? sizeof(zes_control_property_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlCurrentValue_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double *, pValue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, DomainControl, DomainControl)
    ctf_integer_hex(uintptr_t, pValue, (uintptr_t)(pValue))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlCurrentValue_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double *, pValue,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pValue_val, (pValue ? *pValue : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlPendingValue_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double *, pValue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, DomainControl, DomainControl)
    ctf_integer_hex(uintptr_t, pValue, (uintptr_t)(pValue))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlPendingValue_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double *, pValue,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pValue_val, (pValue ? *pValue : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockSetControlUserValue_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double, pValue,
    zes_pending_action_t *, pPendingAction
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, DomainControl, DomainControl)
    ctf_float(double, pValue, pValue)
    ctf_integer_hex(uintptr_t, pPendingAction, (uintptr_t)(pPendingAction))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockSetControlUserValue_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    double, pValue,
    zes_pending_action_t *, pPendingAction,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pPendingAction_val, (pPendingAction ? *pPendingAction : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlState_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    zes_control_state_t *, pControlState,
    zes_pending_action_t *, pPendingAction
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, DomainControl, DomainControl)
    ctf_integer_hex(uintptr_t, pControlState, (uintptr_t)(pControlState))
    ctf_integer_hex(uintptr_t, pPendingAction, (uintptr_t)(pPendingAction))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetControlState_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_overclock_control_t, DomainControl,
    zes_control_state_t *, pControlState,
    zes_pending_action_t *, pPendingAction,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pControlState_val, (pControlState ? *pControlState : 0))
    ctf_integer(int32_t, pPendingAction_val, (pPendingAction ? *pPendingAction : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetVFPointValues_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_type_t, VFType,
    zes_vf_array_type_t, VFArrayType,
    uint32_t, PointIndex,
    uint32_t *, PointValue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, VFType, VFType)
    ctf_integer(int32_t, VFArrayType, VFArrayType)
    ctf_integer(uint32_t, PointIndex, PointIndex)
    ctf_integer_hex(uintptr_t, PointValue, (uintptr_t)(PointValue))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockGetVFPointValues_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_type_t, VFType,
    zes_vf_array_type_t, VFArrayType,
    uint32_t, PointIndex,
    uint32_t *, PointValue,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, PointValue_val, (PointValue ? *PointValue : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockSetVFPointValues_entry,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_type_t, VFType,
    uint32_t, PointIndex,
    uint32_t, PointValue
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDomainHandle, (uintptr_t)(hDomainHandle))
    ctf_integer(int32_t, VFType, VFType)
    ctf_integer(uint32_t, PointIndex, PointIndex)
    ctf_integer(uint32_t, PointValue, PointValue)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesOverclockSetVFPointValues_exit,
  TP_ARGS(
    zes_overclock_handle_t, hDomainHandle,
    zes_vf_type_t, VFType,
    uint32_t, PointIndex,
    uint32_t, PointValue,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumDiagnosticTestSuites_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_diag_handle_t *, phDiagnostics
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phDiagnostics, (uintptr_t)(phDiagnostics))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumDiagnosticTestSuites_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_diag_handle_t *, phDiagnostics,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phDiagnostics_vals, phDiagnostics, uint32_t, (pCount && phDiagnostics ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsGetProperties_entry,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    zes_diag_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDiagnostics, (uintptr_t)(hDiagnostics))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsGetProperties_exit,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    zes_diag_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_diag_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsGetTests_entry,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    uint32_t *, pCount,
    zes_diag_test_t *, pTests
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDiagnostics, (uintptr_t)(hDiagnostics))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pTests, (uintptr_t)(pTests))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsGetTests_exit,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    uint32_t *, pCount,
    zes_diag_test_t *, pTests,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pTests_vals, pTests, size_t, ((pCount && pTests ? *pCount : 0)) * sizeof(zes_diag_test_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsRunTests_entry,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    uint32_t, startIndex,
    uint32_t, endIndex,
    zes_diag_result_t *, pResult
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDiagnostics, (uintptr_t)(hDiagnostics))
    ctf_integer(uint32_t, startIndex, startIndex)
    ctf_integer(uint32_t, endIndex, endIndex)
    ctf_integer_hex(uintptr_t, pResult, (uintptr_t)(pResult))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDiagnosticsRunTests_exit,
  TP_ARGS(
    zes_diag_handle_t, hDiagnostics,
    uint32_t, startIndex,
    uint32_t, endIndex,
    zes_diag_result_t *, pResult,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pResult_val, (pResult ? *pResult : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEccAvailable_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t *, pAvailable
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pAvailable, (uintptr_t)(pAvailable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEccAvailable_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t *, pAvailable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(ze_bool_t, pAvailable_val, (pAvailable ? *pAvailable : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEccConfigurable_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t *, pConfigurable
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pConfigurable, (uintptr_t)(pConfigurable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEccConfigurable_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    ze_bool_t *, pConfigurable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(ze_bool_t, pConfigurable_val, (pConfigurable ? *pConfigurable : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetEccState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_ecc_properties_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetEccState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_device_ecc_properties_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_device_ecc_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceSetEccState_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    const zes_device_ecc_desc_t *, newState,
    zes_device_ecc_properties_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, newState, (uintptr_t)(newState))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
    ctf_sequence_text(uint8_t, newState_val, newState, size_t, (newState ? sizeof(zes_device_ecc_desc_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceSetEccState_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    const zes_device_ecc_desc_t *, newState,
    zes_device_ecc_properties_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_device_ecc_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumEngineGroups_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_engine_handle_t *, phEngine
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phEngine, (uintptr_t)(phEngine))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumEngineGroups_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_engine_handle_t *, phEngine,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phEngine_vals, phEngine, uint32_t, (pCount && phEngine ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetProperties_entry,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    zes_engine_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEngine, (uintptr_t)(hEngine))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetProperties_exit,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    zes_engine_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_engine_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetActivity_entry,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    zes_engine_stats_t *, pStats
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEngine, (uintptr_t)(hEngine))
    ctf_integer_hex(uintptr_t, pStats, (uintptr_t)(pStats))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetActivity_exit,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    zes_engine_stats_t *, pStats,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pStats_val, pStats, size_t, (pStats ? sizeof(zes_engine_stats_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEventRegister_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_event_type_flags_t, events
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer(zes_event_type_flags_t, events, events)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEventRegister_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_event_type_flags_t, events,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverEventListen_entry,
  TP_ARGS(
    ze_driver_handle_t, hDriver,
    uint32_t, timeout,
    uint32_t, count,
    zes_device_handle_t *, phDevices,
    uint32_t *, pNumDeviceEvents,
    zes_event_type_flags_t *, pEvents
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_integer(uint32_t, timeout, timeout)
    ctf_integer(uint32_t, count, count)
    ctf_integer_hex(uintptr_t, phDevices, (uintptr_t)(phDevices))
    ctf_integer_hex(uintptr_t, pNumDeviceEvents, (uintptr_t)(pNumDeviceEvents))
    ctf_integer_hex(uintptr_t, pEvents, (uintptr_t)(pEvents))
    ctf_sequence_hex(uintptr_t, phDevices_vals, phDevices, uint32_t, (phDevices ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverEventListen_exit,
  TP_ARGS(
    ze_driver_handle_t, hDriver,
    uint32_t, timeout,
    uint32_t, count,
    zes_device_handle_t *, phDevices,
    uint32_t *, pNumDeviceEvents,
    zes_event_type_flags_t *, pEvents,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pNumDeviceEvents_val, (pNumDeviceEvents ? *pNumDeviceEvents : 0))
    ctf_sequence(zes_event_type_flags_t, pEvents_vals, pEvents, uint32_t, (pEvents ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverEventListenEx_entry,
  TP_ARGS(
    ze_driver_handle_t, hDriver,
    uint64_t, timeout,
    uint32_t, count,
    zes_device_handle_t *, phDevices,
    uint32_t *, pNumDeviceEvents,
    zes_event_type_flags_t *, pEvents
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_integer(uint64_t, timeout, timeout)
    ctf_integer(uint32_t, count, count)
    ctf_integer_hex(uintptr_t, phDevices, (uintptr_t)(phDevices))
    ctf_integer_hex(uintptr_t, pNumDeviceEvents, (uintptr_t)(pNumDeviceEvents))
    ctf_integer_hex(uintptr_t, pEvents, (uintptr_t)(pEvents))
    ctf_sequence_hex(uintptr_t, phDevices_vals, phDevices, uint32_t, (phDevices ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverEventListenEx_exit,
  TP_ARGS(
    ze_driver_handle_t, hDriver,
    uint64_t, timeout,
    uint32_t, count,
    zes_device_handle_t *, phDevices,
    uint32_t *, pNumDeviceEvents,
    zes_event_type_flags_t *, pEvents,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pNumDeviceEvents_val, (pNumDeviceEvents ? *pNumDeviceEvents : 0))
    ctf_sequence(zes_event_type_flags_t, pEvents_vals, pEvents, uint32_t, (pEvents ? count : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFabricPorts_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_fabric_port_handle_t *, phPort
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phPort, (uintptr_t)(phPort))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFabricPorts_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_fabric_port_handle_t *, phPort,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phPort_vals, phPort, uint32_t, (pCount && phPort ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetProperties_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetProperties_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_fabric_port_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetLinkType_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_link_type_t *, pLinkType
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pLinkType, (uintptr_t)(pLinkType))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetLinkType_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_link_type_t *, pLinkType,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pLinkType_val, pLinkType, size_t, (pLinkType ? sizeof(zes_fabric_link_type_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetConfig_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetConfig_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_fabric_port_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortSetConfig_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    const zes_fabric_port_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_fabric_port_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortSetConfig_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    const zes_fabric_port_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetState_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetState_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_fabric_port_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetThroughput_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_throughput_t *, pThroughput
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pThroughput, (uintptr_t)(pThroughput))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetThroughput_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_throughput_t *, pThroughput,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pThroughput_val, pThroughput, size_t, (pThroughput ? sizeof(zes_fabric_port_throughput_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetFabricErrorCounters_entry,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_error_counters_t *, pErrors
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPort, (uintptr_t)(hPort))
    ctf_integer_hex(uintptr_t, pErrors, (uintptr_t)(pErrors))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetFabricErrorCounters_exit,
  TP_ARGS(
    zes_fabric_port_handle_t, hPort,
    zes_fabric_port_error_counters_t *, pErrors,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pErrors_val, pErrors, size_t, (pErrors ? sizeof(zes_fabric_port_error_counters_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetMultiPortThroughput_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t, numPorts,
    zes_fabric_port_handle_t *, phPort,
    zes_fabric_port_throughput_t **, pThroughput
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer(uint32_t, numPorts, numPorts)
    ctf_integer_hex(uintptr_t, phPort, (uintptr_t)(phPort))
    ctf_integer_hex(uintptr_t, pThroughput, (uintptr_t)(pThroughput))
    ctf_sequence_hex(uintptr_t, phPort_vals, phPort, uint32_t, (phPort ? numPorts : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFabricPortGetMultiPortThroughput_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t, numPorts,
    zes_fabric_port_handle_t *, phPort,
    zes_fabric_port_throughput_t **, pThroughput,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_hex(uintptr_t, pThroughput_vals, pThroughput, uint32_t, (pThroughput ? numPorts : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFans_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_fan_handle_t *, phFan
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phFan, (uintptr_t)(phFan))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFans_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_fan_handle_t *, phFan,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phFan_vals, phFan, uint32_t, (pCount && phFan ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetProperties_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetProperties_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_fan_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetConfig_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetConfig_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_fan_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetDefaultMode_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetDefaultMode_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetFixedSpeedMode_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    const zes_fan_speed_t *, speed
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
    ctf_integer_hex(uintptr_t, speed, (uintptr_t)(speed))
    ctf_sequence_text(uint8_t, speed_val, speed, size_t, (speed ? sizeof(zes_fan_speed_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetFixedSpeedMode_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    const zes_fan_speed_t *, speed,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetSpeedTableMode_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    const zes_fan_speed_table_t *, speedTable
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
    ctf_integer_hex(uintptr_t, speedTable, (uintptr_t)(speedTable))
    ctf_sequence_text(uint8_t, speedTable_val, speedTable, size_t, (speedTable ? sizeof(zes_fan_speed_table_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanSetSpeedTableMode_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    const zes_fan_speed_table_t *, speedTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetState_entry,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_speed_units_t, units,
    int32_t *, pSpeed
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFan, (uintptr_t)(hFan))
    ctf_integer(int32_t, units, units)
    ctf_integer_hex(uintptr_t, pSpeed, (uintptr_t)(pSpeed))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFanGetState_exit,
  TP_ARGS(
    zes_fan_handle_t, hFan,
    zes_fan_speed_units_t, units,
    int32_t *, pSpeed,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pSpeed_val, (pSpeed ? *pSpeed : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFirmwares_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_firmware_handle_t *, phFirmware
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phFirmware, (uintptr_t)(phFirmware))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFirmwares_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_firmware_handle_t *, phFirmware,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phFirmware_vals, phFirmware, uint32_t, (pCount && phFirmware ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetProperties_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    zes_firmware_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetProperties_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    zes_firmware_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_firmware_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareFlash_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    void *, pImage,
    uint32_t, size
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
    ctf_integer_hex(uintptr_t, pImage, (uintptr_t)(pImage))
    ctf_integer(uint32_t, size, size)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareFlash_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    void *, pImage,
    uint32_t, size,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetFlashProgress_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    uint32_t *, pCompletionPercent
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
    ctf_integer_hex(uintptr_t, pCompletionPercent, (uintptr_t)(pCompletionPercent))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetFlashProgress_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    uint32_t *, pCompletionPercent,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCompletionPercent_val, (pCompletionPercent ? *pCompletionPercent : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetConsoleLogs_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    size_t *, pSize,
    char *, pFirmwareLog
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
    ctf_integer_hex(uintptr_t, pSize, (uintptr_t)(pSize))
    ctf_integer_hex(uintptr_t, pFirmwareLog, (uintptr_t)(pFirmwareLog))
    ctf_integer(size_t, pSize_val, (pSize ? *pSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetConsoleLogs_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    size_t *, pSize,
    char *, pFirmwareLog,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(size_t, pSize_val, (pSize ? *pSize : 0))
    ctf_sequence_text(char, pFirmwareLog_vals, pFirmwareLog, size_t, (pSize && pFirmwareLog ? *pSize : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFrequencyDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_freq_handle_t *, phFrequency
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phFrequency, (uintptr_t)(phFrequency))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumFrequencyDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_freq_handle_t *, phFrequency,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phFrequency_vals, phFrequency, uint32_t, (pCount && phFrequency ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetProperties_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetProperties_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_freq_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetAvailableClocks_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    uint32_t *, pCount,
    double *, phFrequency
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phFrequency, (uintptr_t)(phFrequency))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetAvailableClocks_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    uint32_t *, pCount,
    double *, phFrequency,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uint64_t, phFrequency_vals, phFrequency, uint32_t, (pCount && phFrequency ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetRange_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_range_t *, pLimits
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pLimits, (uintptr_t)(pLimits))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetRange_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_range_t *, pLimits,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pLimits_val, pLimits, size_t, (pLimits ? sizeof(zes_freq_range_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencySetRange_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    const zes_freq_range_t *, pLimits
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pLimits, (uintptr_t)(pLimits))
    ctf_sequence_text(uint8_t, pLimits_val, pLimits, size_t, (pLimits ? sizeof(zes_freq_range_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencySetRange_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    const zes_freq_range_t *, pLimits,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetState_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetState_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_freq_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetThrottleTime_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_throttle_time_t *, pThrottleTime
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pThrottleTime, (uintptr_t)(pThrottleTime))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyGetThrottleTime_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_freq_throttle_time_t *, pThrottleTime,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pThrottleTime_val, pThrottleTime, size_t, (pThrottleTime ? sizeof(zes_freq_throttle_time_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetCapabilities_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_capabilities_t *, pOcCapabilities
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pOcCapabilities, (uintptr_t)(pOcCapabilities))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetCapabilities_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_capabilities_t *, pOcCapabilities,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pOcCapabilities_val, pOcCapabilities, size_t, (pOcCapabilities ? sizeof(zes_oc_capabilities_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetFrequencyTarget_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pCurrentOcFrequency
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pCurrentOcFrequency, (uintptr_t)(pCurrentOcFrequency))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetFrequencyTarget_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pCurrentOcFrequency,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pCurrentOcFrequency_val, (pCurrentOcFrequency ? *pCurrentOcFrequency : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetFrequencyTarget_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, CurrentOcFrequency
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_float(double, CurrentOcFrequency, CurrentOcFrequency)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetFrequencyTarget_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, CurrentOcFrequency,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetVoltageTarget_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pCurrentVoltageTarget,
    double *, pCurrentVoltageOffset
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pCurrentVoltageTarget, (uintptr_t)(pCurrentVoltageTarget))
    ctf_integer_hex(uintptr_t, pCurrentVoltageOffset, (uintptr_t)(pCurrentVoltageOffset))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetVoltageTarget_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pCurrentVoltageTarget,
    double *, pCurrentVoltageOffset,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pCurrentVoltageTarget_val, (pCurrentVoltageTarget ? *pCurrentVoltageTarget : 0))
    ctf_float(double, pCurrentVoltageOffset_val, (pCurrentVoltageOffset ? *pCurrentVoltageOffset : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetVoltageTarget_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, CurrentVoltageTarget,
    double, CurrentVoltageOffset
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_float(double, CurrentVoltageTarget, CurrentVoltageTarget)
    ctf_float(double, CurrentVoltageOffset, CurrentVoltageOffset)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetVoltageTarget_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, CurrentVoltageTarget,
    double, CurrentVoltageOffset,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetMode_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_mode_t, CurrentOcMode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer(int32_t, CurrentOcMode, CurrentOcMode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetMode_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_mode_t, CurrentOcMode,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetMode_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_mode_t *, pCurrentOcMode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pCurrentOcMode, (uintptr_t)(pCurrentOcMode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetMode_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    zes_oc_mode_t *, pCurrentOcMode,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pCurrentOcMode_val, (pCurrentOcMode ? *pCurrentOcMode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetIccMax_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pOcIccMax
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pOcIccMax, (uintptr_t)(pOcIccMax))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetIccMax_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pOcIccMax,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pOcIccMax_val, (pOcIccMax ? *pOcIccMax : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetIccMax_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, ocIccMax
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_float(double, ocIccMax, ocIccMax)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetIccMax_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, ocIccMax,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetTjMax_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pOcTjMax
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_integer_hex(uintptr_t, pOcTjMax, (uintptr_t)(pOcTjMax))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcGetTjMax_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double *, pOcTjMax,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pOcTjMax_val, (pOcTjMax ? *pOcTjMax : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetTjMax_entry,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, ocTjMax
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFrequency, (uintptr_t)(hFrequency))
    ctf_float(double, ocTjMax, ocTjMax)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFrequencyOcSetTjMax_exit,
  TP_ARGS(
    zes_freq_handle_t, hFrequency,
    double, ocTjMax,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumLeds_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_led_handle_t *, phLed
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phLed, (uintptr_t)(phLed))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumLeds_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_led_handle_t *, phLed,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phLed_vals, phLed, uint32_t, (pCount && phLed ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedGetProperties_entry,
  TP_ARGS(
    zes_led_handle_t, hLed,
    zes_led_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hLed, (uintptr_t)(hLed))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedGetProperties_exit,
  TP_ARGS(
    zes_led_handle_t, hLed,
    zes_led_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_led_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedGetState_entry,
  TP_ARGS(
    zes_led_handle_t, hLed,
    zes_led_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hLed, (uintptr_t)(hLed))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedGetState_exit,
  TP_ARGS(
    zes_led_handle_t, hLed,
    zes_led_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_led_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedSetState_entry,
  TP_ARGS(
    zes_led_handle_t, hLed,
    ze_bool_t, enable
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hLed, (uintptr_t)(hLed))
    ctf_integer(ze_bool_t, enable, enable)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedSetState_exit,
  TP_ARGS(
    zes_led_handle_t, hLed,
    ze_bool_t, enable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedSetColor_entry,
  TP_ARGS(
    zes_led_handle_t, hLed,
    const zes_led_color_t *, pColor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hLed, (uintptr_t)(hLed))
    ctf_integer_hex(uintptr_t, pColor, (uintptr_t)(pColor))
    ctf_sequence_text(uint8_t, pColor_val, pColor, size_t, (pColor ? sizeof(zes_led_color_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesLedSetColor_exit,
  TP_ARGS(
    zes_led_handle_t, hLed,
    const zes_led_color_t *, pColor,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumMemoryModules_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_mem_handle_t *, phMemory
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phMemory, (uintptr_t)(phMemory))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumMemoryModules_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_mem_handle_t *, phMemory,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phMemory_vals, phMemory, uint32_t, (pCount && phMemory ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetProperties_entry,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hMemory, (uintptr_t)(hMemory))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetProperties_exit,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_mem_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetState_entry,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hMemory, (uintptr_t)(hMemory))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetState_exit,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_mem_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetBandwidth_entry,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_bandwidth_t *, pBandwidth
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hMemory, (uintptr_t)(hMemory))
    ctf_integer_hex(uintptr_t, pBandwidth, (uintptr_t)(pBandwidth))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesMemoryGetBandwidth_exit,
  TP_ARGS(
    zes_mem_handle_t, hMemory,
    zes_mem_bandwidth_t *, pBandwidth,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pBandwidth_val, pBandwidth, size_t, (pBandwidth ? sizeof(zes_mem_bandwidth_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPerformanceFactorDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_perf_handle_t *, phPerf
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phPerf, (uintptr_t)(phPerf))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPerformanceFactorDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_perf_handle_t *, phPerf,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phPerf_vals, phPerf, uint32_t, (pCount && phPerf ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorGetProperties_entry,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    zes_perf_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPerf, (uintptr_t)(hPerf))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorGetProperties_exit,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    zes_perf_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_perf_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorGetConfig_entry,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    double *, pFactor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPerf, (uintptr_t)(hPerf))
    ctf_integer_hex(uintptr_t, pFactor, (uintptr_t)(pFactor))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorGetConfig_exit,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    double *, pFactor,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pFactor_val, (pFactor ? *pFactor : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorSetConfig_entry,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    double, factor
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPerf, (uintptr_t)(hPerf))
    ctf_float(double, factor, factor)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPerformanceFactorSetConfig_exit,
  TP_ARGS(
    zes_perf_handle_t, hPerf,
    double, factor,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPowerDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_pwr_handle_t *, phPower
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phPower, (uintptr_t)(phPower))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPowerDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_pwr_handle_t *, phPower,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phPower_vals, phPower, uint32_t, (pCount && phPower ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetCardPowerDomain_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pwr_handle_t *, phPower
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, phPower, (uintptr_t)(phPower))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetCardPowerDomain_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    zes_pwr_handle_t *, phPower,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer_hex(uintptr_t, phPower_val, (uintptr_t)((phPower ? *phPower : 0)))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetProperties_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetProperties_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_power_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetEnergyCounter_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_energy_counter_t *, pEnergy
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pEnergy, (uintptr_t)(pEnergy))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetEnergyCounter_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_energy_counter_t *, pEnergy,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pEnergy_val, pEnergy, size_t, (pEnergy ? sizeof(zes_power_energy_counter_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetLimits_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_sustained_limit_t *, pSustained,
    zes_power_burst_limit_t *, pBurst,
    zes_power_peak_limit_t *, pPeak
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pSustained, (uintptr_t)(pSustained))
    ctf_integer_hex(uintptr_t, pBurst, (uintptr_t)(pBurst))
    ctf_integer_hex(uintptr_t, pPeak, (uintptr_t)(pPeak))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetLimits_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_power_sustained_limit_t *, pSustained,
    zes_power_burst_limit_t *, pBurst,
    zes_power_peak_limit_t *, pPeak,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pSustained_val, pSustained, size_t, (pSustained ? sizeof(zes_power_sustained_limit_t) : 0))
    ctf_sequence_text(uint8_t, pBurst_val, pBurst, size_t, (pBurst ? sizeof(zes_power_burst_limit_t) : 0))
    ctf_sequence_text(uint8_t, pPeak_val, pPeak, size_t, (pPeak ? sizeof(zes_power_peak_limit_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetLimits_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    const zes_power_sustained_limit_t *, pSustained,
    const zes_power_burst_limit_t *, pBurst,
    const zes_power_peak_limit_t *, pPeak
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pSustained, (uintptr_t)(pSustained))
    ctf_integer_hex(uintptr_t, pBurst, (uintptr_t)(pBurst))
    ctf_integer_hex(uintptr_t, pPeak, (uintptr_t)(pPeak))
    ctf_sequence_text(uint8_t, pSustained_val, pSustained, size_t, (pSustained ? sizeof(zes_power_sustained_limit_t) : 0))
    ctf_sequence_text(uint8_t, pBurst_val, pBurst, size_t, (pBurst ? sizeof(zes_power_burst_limit_t) : 0))
    ctf_sequence_text(uint8_t, pPeak_val, pPeak, size_t, (pPeak ? sizeof(zes_power_peak_limit_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetLimits_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    const zes_power_sustained_limit_t *, pSustained,
    const zes_power_burst_limit_t *, pBurst,
    const zes_power_peak_limit_t *, pPeak,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetEnergyThreshold_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_energy_threshold_t *, pThreshold
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pThreshold, (uintptr_t)(pThreshold))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetEnergyThreshold_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    zes_energy_threshold_t *, pThreshold,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pThreshold_val, pThreshold, size_t, (pThreshold ? sizeof(zes_energy_threshold_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetEnergyThreshold_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    double, threshold
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_float(double, threshold, threshold)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetEnergyThreshold_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    double, threshold,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPsus_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_psu_handle_t *, phPsu
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phPsu, (uintptr_t)(phPsu))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumPsus_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_psu_handle_t *, phPsu,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phPsu_vals, phPsu, uint32_t, (pCount && phPsu ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPsuGetProperties_entry,
  TP_ARGS(
    zes_psu_handle_t, hPsu,
    zes_psu_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPsu, (uintptr_t)(hPsu))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPsuGetProperties_exit,
  TP_ARGS(
    zes_psu_handle_t, hPsu,
    zes_psu_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_psu_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPsuGetState_entry,
  TP_ARGS(
    zes_psu_handle_t, hPsu,
    zes_psu_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPsu, (uintptr_t)(hPsu))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPsuGetState_exit,
  TP_ARGS(
    zes_psu_handle_t, hPsu,
    zes_psu_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_psu_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumRasErrorSets_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_ras_handle_t *, phRas
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phRas, (uintptr_t)(phRas))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumRasErrorSets_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_ras_handle_t *, phRas,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phRas_vals, phRas, uint32_t, (pCount && phRas ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetProperties_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetProperties_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_ras_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetConfig_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetConfig_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_ras_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasSetConfig_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    const zes_ras_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_ras_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasSetConfig_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    const zes_ras_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetState_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    ze_bool_t, clear,
    zes_ras_state_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer(ze_bool_t, clear, clear)
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetState_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    ze_bool_t, clear,
    zes_ras_state_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pState_val, pState, size_t, (pState ? sizeof(zes_ras_state_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumSchedulers_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_sched_handle_t *, phScheduler
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phScheduler, (uintptr_t)(phScheduler))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumSchedulers_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_sched_handle_t *, phScheduler,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phScheduler_vals, phScheduler, uint32_t, (pCount && phScheduler ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetProperties_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetProperties_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_sched_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetCurrentMode_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_mode_t *, pMode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pMode, (uintptr_t)(pMode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetCurrentMode_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_mode_t *, pMode,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pMode_val, (pMode ? *pMode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetTimeoutModeProperties_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t, getDefaults,
    zes_sched_timeout_properties_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer(ze_bool_t, getDefaults, getDefaults)
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetTimeoutModeProperties_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t, getDefaults,
    zes_sched_timeout_properties_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_sched_timeout_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetTimesliceModeProperties_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t, getDefaults,
    zes_sched_timeslice_properties_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer(ze_bool_t, getDefaults, getDefaults)
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerGetTimesliceModeProperties_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t, getDefaults,
    zes_sched_timeslice_properties_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_sched_timeslice_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetTimeoutMode_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_timeout_properties_t *, pProperties,
    ze_bool_t *, pNeedReload
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
    ctf_integer_hex(uintptr_t, pNeedReload, (uintptr_t)(pNeedReload))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetTimeoutMode_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_timeout_properties_t *, pProperties,
    ze_bool_t *, pNeedReload,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_sched_timeout_properties_t) : 0))
    ctf_integer(ze_bool_t, pNeedReload_val, (pNeedReload ? *pNeedReload : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetTimesliceMode_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_timeslice_properties_t *, pProperties,
    ze_bool_t *, pNeedReload
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
    ctf_integer_hex(uintptr_t, pNeedReload, (uintptr_t)(pNeedReload))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetTimesliceMode_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    zes_sched_timeslice_properties_t *, pProperties,
    ze_bool_t *, pNeedReload,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_sched_timeslice_properties_t) : 0))
    ctf_integer(ze_bool_t, pNeedReload_val, (pNeedReload ? *pNeedReload : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetExclusiveMode_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t *, pNeedReload
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pNeedReload, (uintptr_t)(pNeedReload))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetExclusiveMode_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t *, pNeedReload,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(ze_bool_t, pNeedReload_val, (pNeedReload ? *pNeedReload : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetComputeUnitDebugMode_entry,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t *, pNeedReload
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hScheduler, (uintptr_t)(hScheduler))
    ctf_integer_hex(uintptr_t, pNeedReload, (uintptr_t)(pNeedReload))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesSchedulerSetComputeUnitDebugMode_exit,
  TP_ARGS(
    zes_sched_handle_t, hScheduler,
    ze_bool_t *, pNeedReload,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(ze_bool_t, pNeedReload_val, (pNeedReload ? *pNeedReload : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumStandbyDomains_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_standby_handle_t *, phStandby
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phStandby, (uintptr_t)(phStandby))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumStandbyDomains_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_standby_handle_t *, phStandby,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phStandby_vals, phStandby, uint32_t, (pCount && phStandby ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbyGetProperties_entry,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStandby, (uintptr_t)(hStandby))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbyGetProperties_exit,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_standby_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbyGetMode_entry,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_promo_mode_t *, pMode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStandby, (uintptr_t)(hStandby))
    ctf_integer_hex(uintptr_t, pMode, (uintptr_t)(pMode))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbyGetMode_exit,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_promo_mode_t *, pMode,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(int32_t, pMode_val, (pMode ? *pMode : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbySetMode_entry,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_promo_mode_t, mode
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hStandby, (uintptr_t)(hStandby))
    ctf_integer(int32_t, mode, mode)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesStandbySetMode_exit,
  TP_ARGS(
    zes_standby_handle_t, hStandby,
    zes_standby_promo_mode_t, mode,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumTemperatureSensors_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_temp_handle_t *, phTemperature
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phTemperature, (uintptr_t)(phTemperature))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumTemperatureSensors_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_temp_handle_t *, phTemperature,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phTemperature_vals, phTemperature, uint32_t, (pCount && phTemperature ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetProperties_entry,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    zes_temp_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTemperature, (uintptr_t)(hTemperature))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetProperties_exit,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    zes_temp_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_temp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetConfig_entry,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    zes_temp_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTemperature, (uintptr_t)(hTemperature))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetConfig_exit,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    zes_temp_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_temp_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureSetConfig_entry,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    const zes_temp_config_t *, pConfig
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTemperature, (uintptr_t)(hTemperature))
    ctf_integer_hex(uintptr_t, pConfig, (uintptr_t)(pConfig))
    ctf_sequence_text(uint8_t, pConfig_val, pConfig, size_t, (pConfig ? sizeof(zes_temp_config_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureSetConfig_exit,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    const zes_temp_config_t *, pConfig,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetState_entry,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    double *, pTemperature
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hTemperature, (uintptr_t)(hTemperature))
    ctf_integer_hex(uintptr_t, pTemperature, (uintptr_t)(pTemperature))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesTemperatureGetState_exit,
  TP_ARGS(
    zes_temp_handle_t, hTemperature,
    double *, pTemperature,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_float(double, pTemperature_val, (pTemperature ? *pTemperature : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetLimitsExt_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    uint32_t *, pCount,
    zes_power_limit_ext_desc_t *, pSustained
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pSustained, (uintptr_t)(pSustained))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerGetLimitsExt_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    uint32_t *, pCount,
    zes_power_limit_ext_desc_t *, pSustained,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pSustained_vals, pSustained, size_t, ((pCount && pSustained ? *pCount : 0)) * sizeof(zes_power_limit_ext_desc_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetLimitsExt_entry,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    uint32_t *, pCount,
    zes_power_limit_ext_desc_t *, pSustained
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hPower, (uintptr_t)(hPower))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pSustained, (uintptr_t)(pSustained))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pSustained_vals, pSustained, size_t, ((pCount && pSustained ? *pCount : 0)) * sizeof(zes_power_limit_ext_desc_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesPowerSetLimitsExt_exit,
  TP_ARGS(
    zes_pwr_handle_t, hPower,
    uint32_t *, pCount,
    zes_power_limit_ext_desc_t *, pSustained,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetActivityExt_entry,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    uint32_t *, pCount,
    zes_engine_stats_t *, pStats
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hEngine, (uintptr_t)(hEngine))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pStats, (uintptr_t)(pStats))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesEngineGetActivityExt_exit,
  TP_ARGS(
    zes_engine_handle_t, hEngine,
    uint32_t *, pCount,
    zes_engine_stats_t *, pStats,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pStats_vals, pStats, size_t, ((pCount && pStats ? *pCount : 0)) * sizeof(zes_engine_stats_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetStateExp_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    uint32_t *, pCount,
    zes_ras_state_exp_t *, pState
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pState, (uintptr_t)(pState))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasGetStateExp_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    uint32_t *, pCount,
    zes_ras_state_exp_t *, pState,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pState_vals, pState, size_t, ((pCount && pState ? *pCount : 0)) * sizeof(zes_ras_state_exp_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasClearStateExp_entry,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_error_category_exp_t, category
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hRas, (uintptr_t)(hRas))
    ctf_integer(int32_t, category, category)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesRasClearStateExp_exit,
  TP_ARGS(
    zes_ras_handle_t, hRas,
    zes_ras_error_category_exp_t, category,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetSecurityVersionExp_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    char *, pVersion
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
    ctf_integer_hex(uintptr_t, pVersion, (uintptr_t)(pVersion))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareGetSecurityVersionExp_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    char *, pVersion,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_string(pVersion_val, pVersion)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareSetSecurityVersionExp_entry,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hFirmware, (uintptr_t)(hFirmware))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesFirmwareSetSecurityVersionExp_exit,
  TP_ARGS(
    zes_firmware_handle_t, hFirmware,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetSubDevicePropertiesExp_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_subdevice_exp_properties_t *, pSubdeviceProps
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pSubdeviceProps, (uintptr_t)(pSubdeviceProps))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceGetSubDevicePropertiesExp_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_subdevice_exp_properties_t *, pSubdeviceProps,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pSubdeviceProps_vals, pSubdeviceProps, size_t, ((pCount && pSubdeviceProps ? *pCount : 0)) * sizeof(zes_subdevice_exp_properties_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetDeviceByUuidExp_entry,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    zes_uuid_t, uuid,
    zes_device_handle_t *, phDevice,
    ze_bool_t *, onSubdevice,
    uint32_t *, subdeviceId
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDriver, (uintptr_t)(hDriver))
    ctf_array_text(uint8_t, uuid, &uuid, sizeof(zes_uuid_t))
    ctf_integer_hex(uintptr_t, phDevice, (uintptr_t)(phDevice))
    ctf_integer_hex(uintptr_t, onSubdevice, (uintptr_t)(onSubdevice))
    ctf_integer_hex(uintptr_t, subdeviceId, (uintptr_t)(subdeviceId))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDriverGetDeviceByUuidExp_exit,
  TP_ARGS(
    zes_driver_handle_t, hDriver,
    zes_uuid_t, uuid,
    zes_device_handle_t *, phDevice,
    ze_bool_t *, onSubdevice,
    uint32_t *, subdeviceId,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer_hex(uintptr_t, phDevice_val, (uintptr_t)((phDevice ? *phDevice : 0)))
    ctf_integer(ze_bool_t, onSubdevice_val, (onSubdevice ? *onSubdevice : 0))
    ctf_integer(uint32_t, subdeviceId_val, (subdeviceId ? *subdeviceId : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumActiveVFExp_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_vf_handle_t *, phVFhandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phVFhandle, (uintptr_t)(phVFhandle))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumActiveVFExp_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_vf_handle_t *, phVFhandle,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_hex(uintptr_t, phVFhandle_vals, phVFhandle, uint32_t, (pCount && phVFhandle ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFPropertiesExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp_properties_t *, pProperties
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pProperties, (uintptr_t)(pProperties))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFPropertiesExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp_properties_t *, pProperties,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_sequence_text(uint8_t, pProperties_val, pProperties, size_t, (pProperties ? sizeof(zes_vf_exp_properties_t) : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFMemoryUtilizationExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_mem_exp_t *, pMemUtil
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pMemUtil, (uintptr_t)(pMemUtil))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFMemoryUtilizationExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_mem_exp_t *, pMemUtil,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pMemUtil_vals, pMemUtil, size_t, ((pCount && pMemUtil ? *pCount : 0)) * sizeof(zes_vf_util_mem_exp_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFEngineUtilizationExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_engine_exp_t *, pEngineUtil
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pEngineUtil, (uintptr_t)(pEngineUtil))
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFEngineUtilizationExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_engine_exp_t *, pEngineUtil,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
    ctf_integer(uint32_t, pCount_val, (pCount ? *pCount : 0))
    ctf_sequence_text(uint8_t, pEngineUtil_vals, pEngineUtil, size_t, ((pCount && pEngineUtil ? *pCount : 0)) * sizeof(zes_vf_util_engine_exp_t))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementSetVFTelemetryModeExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_info_util_exp_flags_t, flags,
    ze_bool_t, enable
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer(zes_vf_info_util_exp_flags_t, flags, flags)
    ctf_integer(ze_bool_t, enable, enable)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementSetVFTelemetryModeExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_info_util_exp_flags_t, flags,
    ze_bool_t, enable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementSetVFTelemetrySamplingIntervalExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_info_util_exp_flags_t, flag,
    uint64_t, samplingInterval
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer(zes_vf_info_util_exp_flags_t, flag, flag)
    ctf_integer(uint64_t, samplingInterval, samplingInterval)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementSetVFTelemetrySamplingIntervalExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_info_util_exp_flags_t, flag,
    uint64_t, samplingInterval,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumEnabledVFExp_entry,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_vf_handle_t *, phVFhandle
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hDevice, (uintptr_t)(hDevice))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, phVFhandle, (uintptr_t)(phVFhandle))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesDeviceEnumEnabledVFExp_exit,
  TP_ARGS(
    zes_device_handle_t, hDevice,
    uint32_t *, pCount,
    zes_vf_handle_t *, phVFhandle,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFCapabilitiesExp_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp_capabilities_t *, pCapability
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCapability, (uintptr_t)(pCapability))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFCapabilitiesExp_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp_capabilities_t *, pCapability,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFMemoryUtilizationExp2_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_mem_exp2_t *, pMemUtil
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pMemUtil, (uintptr_t)(pMemUtil))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFMemoryUtilizationExp2_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_mem_exp2_t *, pMemUtil,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFEngineUtilizationExp2_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_engine_exp2_t *, pEngineUtil
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCount, (uintptr_t)(pCount))
    ctf_integer_hex(uintptr_t, pEngineUtil, (uintptr_t)(pEngineUtil))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFEngineUtilizationExp2_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    uint32_t *, pCount,
    zes_vf_util_engine_exp2_t *, pEngineUtil,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFCapabilitiesExp2_entry,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp2_capabilities_t *, pCapability
  ),
  TP_FIELDS(
    ctf_integer_hex(uintptr_t, hVFhandle, (uintptr_t)(hVFhandle))
    ctf_integer_hex(uintptr_t, pCapability, (uintptr_t)(pCapability))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesVFManagementGetVFCapabilitiesExp2_exit,
  TP_ARGS(
    zes_vf_handle_t, hVFhandle,
    zes_vf_exp2_capabilities_t *, pCapability,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetGlobalProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_global_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetGlobalProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_global_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDeviceProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_device_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDeviceProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_device_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDeviceExpProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_device_exp_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDeviceExpProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_device_exp_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDriverProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_driver_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDriverProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_driver_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDriverExpProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_driver_exp_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDriverExpProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_driver_exp_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetOverclockProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_overclock_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetOverclockProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_overclock_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetSchedulerProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_scheduler_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetSchedulerProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_scheduler_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPerformanceFactorProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_performance_factor_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPerformanceFactorProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_performance_factor_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPowerProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_power_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPowerProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_power_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFrequencyProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_frequency_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFrequencyProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_frequency_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetEngineProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_engine_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetEngineProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_engine_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetStandbyProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_standby_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetStandbyProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_standby_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFirmwareProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_firmware_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFirmwareProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_firmware_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFirmwareExpProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_firmware_exp_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFirmwareExpProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_firmware_exp_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetMemoryProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_memory_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetMemoryProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_memory_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFabricPortProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_fabric_port_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFabricPortProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_fabric_port_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetTemperatureProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_temperature_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetTemperatureProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_temperature_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPsuProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_psu_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetPsuProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_psu_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFanProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_fan_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetFanProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_fan_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetLedProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_led_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetLedProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_led_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetRasProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_ras_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetRasProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_ras_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetRasExpProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_ras_exp_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetRasExpProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_ras_exp_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDiagnosticsProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_diagnostics_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetDiagnosticsProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_diagnostics_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetVFManagementExpProcAddrTable_entry,
  TP_ARGS(
    ze_api_version_t, version,
    zes_vf_management_exp_dditable_t *, pDdiTable
  ),
  TP_FIELDS(
    ctf_integer(int32_t, version, version)
    ctf_integer_hex(uintptr_t, pDdiTable, (uintptr_t)(pDdiTable))
  )
)

TRACEPOINT_EVENT(
  lttng_ust_zes,
  zesGetVFManagementExpProcAddrTable_exit,
  TP_ARGS(
    ze_api_version_t, version,
    zes_vf_management_exp_dditable_t *, pDdiTable,
    ze_result_t, zeResult
  ),
  TP_FIELDS(
    ctf_integer(int32_t, zeResult, zeResult)
  )
)


#endif /* ZES_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
