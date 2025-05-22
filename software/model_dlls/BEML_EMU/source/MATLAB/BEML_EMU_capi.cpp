/*
 * BEML_EMU_capi.cpp
 *
 * Code generation for model "BEML_EMU".
 *
 * Model version              : 1.1244
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "BEML_EMU_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "BEML_EMU.h"
#include "BEML_EMU_capi.h"
#include "BEML_EMU_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 251, TARGET_STRING("BEML_EMU/InputsInterface"),
    TARGET_STRING(""), 0, 6, 0, 0, 0 },

  { 1, 251, TARGET_STRING("BEML_EMU/InputsInterface"),
    TARGET_STRING("ProcessedVehicleInput"), 0, 27, 3, 0, 0 },

  { 2, 203, TARGET_STRING("BEML_EMU/InputsInterface"),
    TARGET_STRING(""), 0, 28, 3, 0, 1 },

  { 3, 201, TARGET_STRING("BEML_EMU/InputsInterface"),
    TARGET_STRING(""), 0, 36, 3, 0, 0 },

  { 4, 0, TARGET_STRING("BEML_EMU/Unit Delay"),
    TARGET_STRING(""), 0, 50, 3, 0, 1 },

  { 5, 0, TARGET_STRING("BEML_EMU/Unit Delay1"),
    TARGET_STRING(""), 0, 59, 3, 0, 1 },

  { 6, 0, TARGET_STRING("BEML_EMU/Unit Delay2"),
    TARGET_STRING(""), 0, 72, 3, 0, 2 },

  { 7, 0, TARGET_STRING("BEML_EMU/Unit Delay3"),
    TARGET_STRING(""), 0, 91, 3, 0, 1 },

  { 8, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay"),
    TARGET_STRING(""), 0, 97, 3, 0, 0 },

  { 9, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay1"),
    TARGET_STRING(""), 0, 72, 3, 0, 2 },

  { 10, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay4"),
    TARGET_STRING(""), 0, 108, 3, 0, 2 },

  { 11, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay5"),
    TARGET_STRING(""), 0, 50, 3, 0, 1 },

  { 12, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay6"),
    TARGET_STRING(""), 0, 91, 3, 0, 1 },

  { 13, 0, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay7"),
    TARGET_STRING(""), 0, 111, 3, 0, 2 },

  { 14, 251, TARGET_STRING(
    "BEML_EMU/InputsInterface/BusConversion_InsertedFor_ProcessedInputs_Outport_1_at_inport_0"),
    TARGET_STRING("ProcessedVehicleInput"), 0, 27, 3, 0, 0 },

  { 15, 251, TARGET_STRING("BEML_EMU/InputsInterface/Unit Delay"),
    TARGET_STRING(""), 0, 28, 3, 0, 1 },

  { 16, 2, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 17, 2, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter"),
    TARGET_STRING(""), 1, 116, 3, 0, 2 },

  { 18, 7, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter"),
    TARGET_STRING(""), 2, 117, 3, 0, 2 },

  { 19, 7, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter"),
    TARGET_STRING(""), 3, 118, 3, 0, 2 },

  { 20, 7, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter"),
    TARGET_STRING(""), 4, 119, 3, 0, 2 },

  { 21, 35, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 22, 38, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter"),
    TARGET_STRING(""), 1, 124, 3, 0, 1 },

  { 23, 38, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter"),
    TARGET_STRING(""), 2, 125, 3, 0, 1 },

  { 24, 38, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter"),
    TARGET_STRING(""), 3, 126, 3, 0, 1 },

  { 25, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 0 },

  { 26, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter"),
    TARGET_STRING(""), 1, 129, 3, 0, 0 },

  { 27, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter"),
    TARGET_STRING(""), 2, 132, 3, 0, 0 },

  { 28, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter"),
    TARGET_STRING(""), 3, 133, 3, 0, 0 },

  { 29, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter"),
    TARGET_STRING(""), 4, 134, 3, 0, 0 },

  { 30, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 31, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter"),
    TARGET_STRING(""), 1, 136, 3, 0, 1 },

  { 32, 60, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter"),
    TARGET_STRING(""), 2, 147, 3, 0, 1 },

  { 33, 60, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter"),
    TARGET_STRING(""), 4, 30, 3, 0, 1 },

  { 34, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 35, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter"),
    TARGET_STRING(""), 1, 148, 3, 0, 1 },

  { 36, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 37, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter"),
    TARGET_STRING(""), 1, 150, 3, 0, 2 },

  { 38, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter"),
    TARGET_STRING(""), 2, 155, 3, 0, 2 },

  { 39, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter"),
    TARGET_STRING(""), 3, 156, 3, 0, 2 },

  { 40, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter"),
    TARGET_STRING(""), 4, 32, 3, 0, 2 },

  { 41, 80, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 42, 80, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter"),
    TARGET_STRING(""), 1, 157, 3, 0, 1 },

  { 43, 95, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter"),
    TARGET_STRING(""), 2, 173, 3, 0, 1 },

  { 44, 95, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter"),
    TARGET_STRING(""), 4, 33, 3, 0, 1 },

  { 45, 95, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter"),
    TARGET_STRING(""), 5, 13, 3, 0, 1 },

  { 46, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 47, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter"),
    TARGET_STRING(""), 1, 174, 3, 0, 2 },

  { 48, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter"),
    TARGET_STRING(""), 2, 181, 3, 0, 2 },

  { 49, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter"),
    TARGET_STRING(""), 3, 182, 3, 0, 2 },

  { 50, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter"),
    TARGET_STRING(""), 4, 35, 3, 0, 2 },

  { 51, 201, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem"),
    TARGET_STRING(""), 0, 183, 3, 0, 1 },

  { 52, 201, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem"),
    TARGET_STRING(""), 1, 36, 3, 0, 0 },

  { 53, 203, TARGET_STRING(
    "BEML_EMU/InputsInterface/IOControlsInterface/For Each Subsystem"),
    TARGET_STRING(""), 0, 28, 3, 0, 1 },

  { 54, 207, TARGET_STRING(
    "BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests"),
    TARGET_STRING(""), 0, 186, 3, 0, 1 },

  { 55, 251, TARGET_STRING(
    "BEML_EMU/InputsInterface/IOControlsInterface/Unit Delay"),
    TARGET_STRING(""), 0, 28, 3, 0, 1 },

  { 56, 251, TARGET_STRING(
    "BEML_EMU/InputsInterface/TrainProcessing/Bus Assignment"),
    TARGET_STRING(""), 0, 6, 0, 0, 0 },

  { 57, 251, TARGET_STRING("BEML_EMU/InputsInterface/TrainProcessing/NOT"),
    TARGET_STRING(""), 0, 14, 0, 0, 3 },

  { 58, 276, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter"),
    TARGET_STRING(""), 0, 193, 3, 0, 0 },

  { 59, 2, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 60, 2, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 116, 3, 0, 2 },

  { 61, 7, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 117, 3, 0, 2 },

  { 62, 7, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 1, 118, 3, 0, 2 },

  { 63, 7, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 119, 3, 0, 2 },

  { 64, 32, TARGET_STRING(
    "BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem"),
    TARGET_STRING(""), 0, 194, 3, 0, 1 },

  { 65, 32, TARGET_STRING(
    "BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem"),
    TARGET_STRING(""), 1, 25, 3, 0, 1 },

  { 66, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 67, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 120, 3, 0, 1 },

  { 68, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 2, 14, 3, 0, 1 },

  { 69, 38, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 124, 3, 0, 1 },

  { 70, 38, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 1, 125, 3, 0, 1 },

  { 71, 38, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 126, 3, 0, 1 },

  { 72, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 0 },

  { 73, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 129, 3, 0, 0 },

  { 74, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 132, 3, 0, 0 },

  { 75, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 1, 133, 3, 0, 0 },

  { 76, 48, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 134, 3, 0, 0 },

  { 77, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 78, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 136, 3, 0, 1 },

  { 79, 60, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 147, 3, 0, 1 },

  { 80, 60, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 30, 3, 0, 1 },

  { 81, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 82, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 148, 3, 0, 1 },

  { 83, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 84, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 150, 3, 0, 2 },

  { 85, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 2, 196, 3, 0, 2 },

  { 86, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 155, 3, 0, 2 },

  { 87, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 1, 156, 3, 0, 2 },

  { 88, 77, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 32, 3, 0, 2 },

  { 89, 80, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 90, 80, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 157, 3, 0, 1 },

  { 91, 95, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 173, 3, 0, 1 },

  { 92, 95, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 33, 3, 0, 1 },

  { 93, 95, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 3, 13, 3, 0, 1 },

  { 94, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 95, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig"),
    TARGET_STRING(""), 1, 174, 3, 0, 2 },

  { 96, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 0, 181, 3, 0, 2 },

  { 97, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 1, 182, 3, 0, 2 },

  { 98, 107, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter"),
    TARGET_STRING(""), 2, 35, 3, 0, 2 },

  { 99, 200, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/OR"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 100, 2, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 101, 2, TARGET_STRING(
    "BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 116, 3, 0, 2 },

  { 102, 22, TARGET_STRING(
    "BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO"),
    TARGET_STRING("ATOBrake"), 0, 14, 0, 0, 2 },

  { 103, 22, TARGET_STRING(
    "BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO"),
    TARGET_STRING("ATOTraction"), 0, 14, 0, 0, 2 },

  { 104, 22, TARGET_STRING(
    "BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO"),
    TARGET_STRING("ATOTBDemand"), 0, 0, 0, 0, 2 },

  { 105, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 106, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 120, 3, 0, 1 },

  { 107, 35, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 2, 14, 3, 0, 1 },

  { 108, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 0 },

  { 109, 41, TARGET_STRING(
    "BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 129, 3, 0, 0 },

  { 110, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 111, 51, TARGET_STRING(
    "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 136, 3, 0, 1 },

  { 112, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 113, 63, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 148, 3, 0, 1 },

  { 114, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 115, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 150, 3, 0, 2 },

  { 116, 69, TARGET_STRING(
    "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 2, 196, 3, 0, 2 },

  { 117, 80, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 1 },

  { 118, 80, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 157, 3, 0, 1 },

  { 119, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 0, 114, 3, 0, 2 },

  { 120, 98, TARGET_STRING(
    "BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig/ExtractConfig"),
    TARGET_STRING(""), 1, 174, 3, 0, 2 },

  { 121, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/AND"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 122, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion10"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 123, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion11"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 124, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion13"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 125, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion15"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 126, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion17"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 127, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion19"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 128, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion21"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 129, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion23"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 130, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion41"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 131, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion6"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 132, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Data Type Conversion8"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 133, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition1"),
    TARGET_STRING("APSICBInternalRequest"), 0, 14, 0, 0, 0 },

  { 134, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition2"),
    TARGET_STRING("FDSCBInternalRequest"), 0, 14, 0, 0, 0 },

  { 135, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition3"),
    TARGET_STRING("SAC1CBInternalRequest"), 0, 14, 0, 0, 0 },

  { 136, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition4"),
    TARGET_STRING("SAC2CBInternalRequest"), 0, 14, 0, 0, 0 },

  { 137, 200, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease1/FixPt Relational Operator"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 138, 198, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 139, 198, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 140, 199, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/Chart"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 141, 199, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/Chart"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 142, 192, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 143, 192, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 144, 193, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/Chart"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 145, 193, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/Chart"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 146, 186, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 147, 186, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 148, 187, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/Chart"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 149, 187, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/Chart"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 150, 180, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 151, 180, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 152, 181, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/Chart"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 153, 181, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/Chart"),
    TARGET_STRING(""), 1, 14, 0, 0, 1 },

  { 154, 173, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 155, 173, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 156, 170, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 157, 170, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 158, 167, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 159, 167, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 160, 164, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 161, 164, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 162, 161, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 163, 161, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 164, 158, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 165, 158, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 166, 155, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 167, 155, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 168, 152, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 169, 152, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 170, 149, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 171, 149, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 172, 146, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 173, 146, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 174, 143, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 175, 143, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 176, 140, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 177, 140, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 178, 137, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 179, 137, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 180, 134, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 181, 134, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 182, 131, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 183, 131, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 184, 128, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 185, 128, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 186, 125, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 187, 125, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 188, 122, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 189, 122, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 190, 119, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 191, 119, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 192, 116, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 193, 116, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 194, 113, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 195, 113, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 196, 110, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/IRQRequestStateMachine"),
    TARGET_STRING("TriggerFaultRequest"), 0, 14, 0, 0, 0 },

  { 197, 110, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/IRQRequestStateMachine"),
    TARGET_STRING("TargetStateValue"), 1, 0, 0, 0, 0 },

  { 198, 198, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Relational Operator"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 199, 198, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 200, 192, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Relational Operator"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 201, 192, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 202, 186, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Relational Operator"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 203, 186, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 204, 180, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Relational Operator"),
    TARGET_STRING(""), 0, 14, 0, 0, 1 },

  { 205, 180, TARGET_STRING(
    "BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 206, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel"),
    TARGET_STRING(""), 0, 0, 8, 0, 0 },

  { 207, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/NoTrackFeel"),
    TARGET_STRING(""), 0, 0, 8, 0, 0 },

  { 208, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel"),
    TARGET_STRING(""), 0, 0, 8, 0, 0 },

  { 209, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/Merge"),
    TARGET_STRING("ManualPosition"), 0, 0, 8, 0, 0 },

  { 210, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/IC"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 211, 311, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 212, 309, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 213, 307, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 214, 305, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 215, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/AssignZ"),
    TARGET_STRING(""), 0, 0, 8, 0, 0 },

  { 216, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/AssignZ"),
    TARGET_STRING(""), 0, 0, 8, 0, 0 },

  { 217, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 218, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 219, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 220, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 221, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 222, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 223, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 224, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 225, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 226, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 227, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 228, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 229, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 230, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 231, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 232, 312, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 233, 311, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Logical Operator1"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 234, 309, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Logical Operator1"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 235, 307, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Logical Operator1"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 236, 305, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Logical Operator1"),
    TARGET_STRING(""), 0, 14, 0, 0, 0 },

  { 237, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 238, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 239, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 240, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 241, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 242, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 243, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 244, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 245, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 246, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 247, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 248, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 249, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 250, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 251, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 252, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 253, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 254, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 255, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 256, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 257, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 258, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 259, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 260, 303, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 261, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 262, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 263, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 264, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 265, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 266, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 267, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 268, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 269, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 270, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 271, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 272, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 273, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 274, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 275, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 276, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 277, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 278, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 279, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 280, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 281, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Vector Concatenate"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 282, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Vector Concatenate1"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 283, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 284, 292, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Subtract"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 285, TARGET_STRING("BEML_EMU/Unit Delay"),
    TARGET_STRING("InitialCondition"), 50, 0, 0 },

  { 286, TARGET_STRING("BEML_EMU/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 59, 0, 0 },

  { 287, TARGET_STRING("BEML_EMU/Unit Delay2"),
    TARGET_STRING("InitialCondition"), 72, 0, 0 },

  { 288, TARGET_STRING("BEML_EMU/Unit Delay3"),
    TARGET_STRING("InitialCondition"), 91, 0, 0 },

  { 289, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay"),
    TARGET_STRING("InitialCondition"), 97, 0, 0 },

  { 290, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 72, 0, 0 },

  { 291, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay2"),
    TARGET_STRING("InitialCondition"), 199, 0, 0 },

  { 292, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay3"),
    TARGET_STRING("InitialCondition"), 59, 0, 0 },

  { 293, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay4"),
    TARGET_STRING("InitialCondition"), 108, 0, 0 },

  { 294, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay5"),
    TARGET_STRING("InitialCondition"), 50, 0, 0 },

  { 295, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay6"),
    TARGET_STRING("InitialCondition"), 91, 0, 0 },

  { 296, TARGET_STRING("BEML_EMU/BEML_EMU/Unit Delay7"),
    TARGET_STRING("InitialCondition"), 111, 0, 0 },

  { 297, TARGET_STRING("BEML_EMU/InitialiseModel/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 298, TARGET_STRING("BEML_EMU/InitialiseModel/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 299, TARGET_STRING("BEML_EMU/InitialiseModel/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 300, TARGET_STRING("BEML_EMU/InputsInterface/Unit Delay"),
    TARGET_STRING("InitialCondition"), 28, 0, 0 },

  { 301, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/TrainBrakes"),
    TARGET_STRING("PRM_TrainBrakes_Vehicles"), 207, 0, 0 },

  { 302, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsSystem"),
    TARGET_STRING("PRM_DoorSystem"), 208, 0, 0 },

  { 303, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalSystem"),
    TARGET_STRING("Prm_ElectricalSystem"), 209, 0, 0 },

  { 304, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographSystem"),
    TARGET_STRING("Prm_PantographSystem"), 210, 0, 0 },

  { 305, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsSystem"),
    TARGET_STRING("Prm_PneumaticsSystem"), 223, 0, 0 },

  { 306, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSSystem"),
    TARGET_STRING("Prm_TCMSSystem"), 224, 0, 0 },

  { 307, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionSystem"),
    TARGET_STRING("Prm_TractionSystem"), 225, 0, 0 },

  { 308, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/Unit Delay"),
    TARGET_STRING("InitialCondition"), 28, 0, 0 },

  { 309, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 310, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 311, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 312, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 313, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 314, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 315, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 316, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 317, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 318, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 319, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 320, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 321, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 322, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 323, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 324, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 325, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 326, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 327, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 328, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 329, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 330, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 331, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 332, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 333, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 334, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 335, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 336, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 337, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 338, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 339, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigProcessed"),
    TARGET_STRING("InitialOutput"), 227, 0, 0 },

  { 340, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/Unit Delay"),
    TARGET_STRING("InitialCondition"), 135, 0, 0 },

  { 341, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 342, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Constant"),
    TARGET_STRING("Value"), 228, 0, 0 },

  { 343, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Relay"),
    TARGET_STRING("OnSwitchValue"), 0, 0, 0 },

  { 344, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Relay"),
    TARGET_STRING("OffSwitchValue"), 0, 0, 0 },

  { 345, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Relay"),
    TARGET_STRING("OnOutputValue"), 0, 0, 0 },

  { 346, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Relay"),
    TARGET_STRING("OffOutputValue"), 0, 0, 0 },

  { 347, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 348, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Constant1"),
    TARGET_STRING("Value"), 229, 0, 0 },

  { 349, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 350, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 351, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 352, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 353, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/VehicleLevelScoring/Constant1"),
    TARGET_STRING("Value"), 230, 0, 0 },

  { 354, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 355, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 356, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig/BrakesVehicleCfg"),
    TARGET_STRING("InitialOutput"), 116, 0, 0 },

  { 357, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 117, 0, 0 },

  { 358, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 118, 0, 0 },

  { 359, TARGET_STRING("BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter/Constant2"),
    TARGET_STRING("Value"), 119, 0, 0 },

  { 360, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/Constant"),
    TARGET_STRING("Value"), 236, 0, 0 },

  { 361, TARGET_STRING("BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem/Constant"),
    TARGET_STRING("Value"), 25, 0, 0 },

  { 362, TARGET_STRING("BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem/Constant1"),
    TARGET_STRING("Value"), 194, 0, 0 },

  { 363, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 364, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/DoorsConfig"),
    TARGET_STRING("InitialOutput"), 120, 0, 0 },

  { 365, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/HasCab"),
    TARGET_STRING("InitialOutput"), 14, 0, 0 },

  { 366, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 125, 0, 0 },

  { 367, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 368, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig/DynamicsVehicleCfg"),
    TARGET_STRING("InitialOutput"), 129, 0, 0 },

  { 369, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 132, 0, 0 },

  { 370, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 133, 0, 0 },

  { 371, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/Constant2"),
    TARGET_STRING("Value"), 134, 0, 0 },

  { 372, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 373, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig/ElectricalVehicleCfg"),
    TARGET_STRING("InitialOutput"), 136, 0, 0 },

  { 374, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 147, 0, 0 },

  { 375, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 376, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig/PantographVehicleCfg"),
    TARGET_STRING("InitialOutput"), 148, 0, 0 },

  { 377, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 241, 0, 0 },

  { 378, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 379, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/PneumaticsVehicleCfg"),
    TARGET_STRING("InitialOutput"), 150, 0, 0 },

  { 380, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/LocationVehicleConfig"),
    TARGET_STRING("InitialOutput"), 196, 0, 0 },

  { 381, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 155, 0, 0 },

  { 382, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 156, 0, 0 },

  { 383, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 384, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/TCMSVehicleCfg"),
    TARGET_STRING("InitialOutput"), 157, 0, 0 },

  { 385, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 173, 0, 0 },

  { 386, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 242, 0, 0 },

  { 387, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig/CommonVehicleCfg"),
    TARGET_STRING("InitialOutput"), 114, 0, 0 },

  { 388, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig/TractionVehicleCfg"),
    TARGET_STRING("InitialOutput"), 174, 0, 0 },

  { 389, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Difference1"),
    TARGET_STRING("ICPrevInput"), 0, 0, 0 },

  { 390, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Difference2"),
    TARGET_STRING("ICPrevInput"), 0, 0, 0 },

  { 391, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Constant"),
    TARGET_STRING("Value"), 181, 0, 0 },

  { 392, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Constant1"),
    TARGET_STRING("Value"), 182, 0, 0 },

  { 393, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 394, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/DoorFaults/Constant1"),
    TARGET_STRING("Value"), 29, 0, 0 },

  { 395, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/ElectricalFaults/Constant1"),
    TARGET_STRING("Value"), 30, 0, 0 },

  { 396, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PantographFaults/Constant1"),
    TARGET_STRING("Value"), 31, 0, 0 },

  { 397, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Change"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 398, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 399, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 400, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease2"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 401, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 402, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Increase1"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 403, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 404, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 405, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Constant1"),
    TARGET_STRING("Value"), 32, 0, 0 },

  { 406, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault"),
    TARGET_STRING("FltStVal"), 0, 0, 0 },

  { 407, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault"),
    TARGET_STRING("NormalStVal"), 0, 0, 0 },

  { 408, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1"),
    TARGET_STRING("FltStVal"), 0, 0, 0 },

  { 409, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1"),
    TARGET_STRING("NormalStVal"), 0, 0, 0 },

  { 410, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2"),
    TARGET_STRING("FltStVal"), 0, 0, 0 },

  { 411, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2"),
    TARGET_STRING("NormalStVal"), 0, 0, 0 },

  { 412, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3"),
    TARGET_STRING("FltStVal"), 0, 0, 0 },

  { 413, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3"),
    TARGET_STRING("NormalStVal"), 0, 0, 0 },

  { 414, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition1"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 415, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition2"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 416, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition3"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 417, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Rate Transition4"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 418, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 419, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/TCMSFaults/Constant1"),
    TARGET_STRING("Value"), 33, 0, 0 },

  { 420, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/TractionFaults/Constant1"),
    TARGET_STRING("Value"), 35, 0, 0 },

  { 421, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/VehicleFaultStatesCompile/Constant1"),
    TARGET_STRING("Value"), 13, 0, 0 },

  { 422, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 423, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 424, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 425, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 426, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 427, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 428, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 429, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 430, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Constant1"),
    TARGET_STRING("Value"), 227, 0, 0 },

  { 431, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleEnabled/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 432, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleEnabled/Constant1"),
    TARGET_STRING("Value"), 135, 0, 0 },

  { 433, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Subsystem1/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 434, TARGET_STRING("BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Subsystem1/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 435, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/BinarySwitch"),
    TARGET_STRING("value"), 0, 0, 0 },

  { 436, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Constant6"),
    TARGET_STRING("Value"), 193, 0, 0 },

  { 437, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATOCommands"),
    TARGET_STRING("InitialOutput"), 243, 0, 0 },

  { 438, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 439, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 440, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 441, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 442, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 443, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 444, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Real Target"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 445, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Relay"),
    TARGET_STRING("OnSwitchValue"), 0, 0, 0 },

  { 446, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Relay"),
    TARGET_STRING("OffSwitchValue"), 0, 0, 0 },

  { 447, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Relay"),
    TARGET_STRING("OnOutputValue"), 14, 0, 0 },

  { 448, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Relay"),
    TARGET_STRING("OffOutputValue"), 14, 0, 0 },

  { 449, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Ignore invalid v_Permitted"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 450, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Ignore invalid v_Permitted"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 451, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Min0"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 452, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Min0"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 453, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/DMIPacking/ToDMI"),
    TARGET_STRING("Value"), 235, 0, 0 },

  { 454, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ElectricalPacking/Temp_Fix"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 455, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ElectricalPacking/ToElectricalSystem"),
    TARGET_STRING("Value"), 233, 0, 0 },

  { 456, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ToOnBoardUnit"),
    TARGET_STRING("Value"), 231, 0, 0 },

  { 457, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/PlatformUnitPacking/ToOnPlatformUnit"),
    TARGET_STRING("Value"), 232, 0, 0 },

  { 458, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/TCMSPacking/ToTCMSSystem"),
    TARGET_STRING("Value"), 234, 0, 0 },

  { 459, TARGET_STRING("BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem/ConvertToCouplerBus/Constant1"),
    TARGET_STRING("Value"), 24, 0, 0 },

  { 460, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Constant4"),
    TARGET_STRING("Value"), 123, 0, 0 },

  { 461, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/CustomDragForces/Constant3"),
    TARGET_STRING("Value"), 131, 0, 0 },

  { 462, TARGET_STRING("BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/For Each Subsystem1/Constant"),
    TARGET_STRING("Value"), 130, 0, 0 },

  { 463, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/CouplingSignals/Constant3"),
    TARGET_STRING("Value"), 138, 0, 0 },

  { 464, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/DoorsSignals/Constant3"),
    TARGET_STRING("Value"), 141, 0, 0 },

  { 465, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/DynamicsSignals/Constant3"),
    TARGET_STRING("Value"), 139, 0, 0 },

  { 466, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Constant3"),
    TARGET_STRING("Value"), 137, 0, 0 },

  { 467, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/OverrideAssignment/Constant1"),
    TARGET_STRING("Value"), 244, 0, 0 },

  { 468, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/PantographSignals/Constant3"),
    TARGET_STRING("Value"), 142, 0, 0 },

  { 469, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/PneumaticsSignals/Constant3"),
    TARGET_STRING("Value"), 140, 0, 0 },

  { 470, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/SignSignals/Constant3"),
    TARGET_STRING("Value"), 144, 0, 0 },

  { 471, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/TCMSSignals/Constant3"),
    TARGET_STRING("Value"), 145, 0, 0 },

  { 472, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/TractionSignals/Constant3"),
    TARGET_STRING("Value"), 146, 0, 0 },

  { 473, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/ControlSignals/Constant3"),
    TARGET_STRING("Value"), 237, 0, 0 },

  { 474, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant3"),
    TARGET_STRING("Value"), 238, 0, 0 },

  { 475, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/EnvironmentSignals/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 476, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/EnvironmentSignals/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 477, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/EnvironmentSignals/Constant3"),
    TARGET_STRING("Value"), 240, 0, 0 },

  { 478, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/FaultsAssignment/Constant2"),
    TARGET_STRING("Value"), 31, 0, 0 },

  { 479, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/OverrideAssignment/Constant1"),
    TARGET_STRING("Value"), 245, 0, 0 },

  { 480, TARGET_STRING("BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/PneumaticsSignals/Constant3"),
    TARGET_STRING("Value"), 239, 0, 0 },

  { 481, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant3"),
    TARGET_STRING("Value"), 152, 0, 0 },

  { 482, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PhysicalSignals/Constant3"),
    TARGET_STRING("Value"), 153, 0, 0 },

  { 483, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PhysicalSignals/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 484, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PhysicalSignals/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 485, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 486, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant15"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 487, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant16"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 488, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 489, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant22"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 490, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant23"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 491, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant3"),
    TARGET_STRING("Value"), 154, 0, 0 },

  { 492, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 493, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 494, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 495, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Constant7"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 496, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/ExtractConfig/Constant"),
    TARGET_STRING("Value"), 157, 0, 0 },

  { 497, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/BrakeSignals/Constant3"),
    TARGET_STRING("Value"), 171, 0, 0 },

  { 498, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CBTC/Constant3"),
    TARGET_STRING("Value"), 170, 0, 0 },

  { 499, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CBTC/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 500, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CouplingSignals/Constant3"),
    TARGET_STRING("Value"), 169, 0, 0 },

  { 501, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DoorsSignals/Constant"),
    TARGET_STRING("Value"), 163, 0, 0 },

  { 502, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DoorsSignals/Constant3"),
    TARGET_STRING("Value"), 164, 0, 0 },

  { 503, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DynamicSignals/Constant3"),
    TARGET_STRING("Value"), 172, 0, 0 },

  { 504, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Detect Decrease"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 505, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Detect Increase"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 506, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 507, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 508, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant3"),
    TARGET_STRING("Value"), 165, 0, 0 },

  { 509, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/EnvironmentSignals/Constant3"),
    TARGET_STRING("Value"), 159, 0, 0 },

  { 510, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/IOSignals/Constant3"),
    TARGET_STRING("Value"), 158, 0, 0 },

  { 511, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PantographSignals/Constant3"),
    TARGET_STRING("Value"), 166, 0, 0 },

  { 512, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PneumaticsSignals/Constant3"),
    TARGET_STRING("Value"), 161, 0, 0 },

  { 513, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/TractionSignals/Constant3"),
    TARGET_STRING("Value"), 168, 0, 0 },

  { 514, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 515, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Compare To Zero2/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 516, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ComputerSignals/Constant3"),
    TARGET_STRING("Value"), 180, 0, 0 },

  { 517, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant1"),
    TARGET_STRING("Value"), 175, 11, 0 },

  { 518, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ElectricalSignals/Constant3"),
    TARGET_STRING("Value"), 176, 0, 0 },

  { 519, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/Constant3"),
    TARGET_STRING("Value"), 178, 0, 0 },

  { 520, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 521, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 522, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/Chart"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 523, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/Unit Delay"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 524, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 525, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/Chart"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 526, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/Unit Delay"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 527, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 528, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/Chart"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 529, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/Unit Delay"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 530, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 531, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/Chart"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 532, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/Unit Delay"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 533, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 534, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 535, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 536, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 537, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 538, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 539, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 540, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 541, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 542, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 543, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 544, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 545, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 546, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 547, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 548, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 549, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 550, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 551, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 552, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 553, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 554, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 555, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 556, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 557, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 558, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 559, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 560, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 561, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 562, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 563, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 564, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 565, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 566, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 567, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 568, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 569, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 570, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 571, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 572, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 573, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 574, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 575, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 576, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 577, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 578, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 579, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 580, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 581, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 582, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 583, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 584, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 585, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 586, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 587, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 588, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 589, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 590, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 591, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 592, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 593, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 594, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 595, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 596, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 597, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 598, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 599, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 600, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 601, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 602, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 603, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 604, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 605, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 606, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 607, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 608, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 609, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 610, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 611, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 612, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 613, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 614, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 615, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 616, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 617, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 618, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 619, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 620, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 621, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 622, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 623, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 624, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 625, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 626, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 627, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 628, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 629, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 630, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 631, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 632, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 633, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 634, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 635, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 636, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 637, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 638, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic"),
    TARGET_STRING("ControlType"), 0, 0, 0 },

  { 639, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/IRQRequestStateMachine"),
    TARGET_STRING("ReturnToNormalState"), 0, 0, 0 },

  { 640, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/IRQRequestStateMachine"),
    TARGET_STRING("TriggerContinously"), 0, 0, 0 },

  { 641, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 642, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 643, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem7/CDUCB1_FixMe"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 644, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem7/ERCB1_FixMe1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 645, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem8/CRSACB_FixME"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 646, TARGET_STRING("BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem1/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 647, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignBrakes/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 648, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignBrakes/Constant6"),
    TARGET_STRING("Value"), 116, 0, 0 },

  { 649, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment1"),
    TARGET_STRING("IsLeft"), 0, 0, 0 },

  { 650, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment1"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 651, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment2"),
    TARGET_STRING("IsLeft"), 0, 0, 0 },

  { 652, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment2"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 653, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment3"),
    TARGET_STRING("IsLeft"), 0, 0, 0 },

  { 654, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment3"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 655, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment4"),
    TARGET_STRING("IsLeft"), 0, 0, 0 },

  { 656, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment4"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 657, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 658, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 659, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 660, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 661, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 662, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 663, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 664, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 665, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 666, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 667, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 668, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 669, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 670, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 671, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 672, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 673, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 674, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 675, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 676, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 677, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 678, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 679, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 680, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 681, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 682, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 683, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 684, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasPneumaticPanto"), 0, 0, 0 },

  { 685, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("HasElectricPanto"), 0, 0, 0 },

  { 686, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 687, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("NumberOfTractionBogies"), 0, 0, 0 },

  { 688, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment"),
    TARGET_STRING("NumberOfBrakingBogies"), 0, 0, 0 },

  { 689, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 690, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 691, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 692, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 693, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 694, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 695, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 696, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasPneumaticPanto"), 0, 0, 0 },

  { 697, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("HasElectricPanto"), 0, 0, 0 },

  { 698, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 699, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("NumberOfTractionBogies"), 0, 0, 0 },

  { 700, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1"),
    TARGET_STRING("NumberOfBrakingBogies"), 0, 0, 0 },

  { 701, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 702, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 703, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 704, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 705, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 706, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 707, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 708, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasPneumaticPanto"), 0, 0, 0 },

  { 709, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("HasElectricPanto"), 0, 0, 0 },

  { 710, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 711, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("NumberOfTractionBogies"), 0, 0, 0 },

  { 712, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2"),
    TARGET_STRING("NumberOfBrakingBogies"), 0, 0, 0 },

  { 713, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 714, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 715, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 716, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasMainCompressor"), 0, 0, 0 },

  { 717, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 718, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasPantoReservoir"), 0, 0, 0 },

  { 719, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 720, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasPneumaticPanto"), 0, 0, 0 },

  { 721, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("HasElectricPanto"), 0, 0, 0 },

  { 722, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("NumberOfDoors"), 0, 0, 0 },

  { 723, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("NumberOfTractionBogies"), 0, 0, 0 },

  { 724, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3"),
    TARGET_STRING("NumberOfBrakingBogies"), 0, 0, 0 },

  { 725, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment"),
    TARGET_STRING("HasPanto"), 0, 0, 0 },

  { 726, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment"),
    TARGET_STRING("PenumaticsPoweredPanto"), 0, 0, 0 },

  { 727, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment"),
    TARGET_STRING("ElectricPoweredPanto"), 0, 0, 0 },

  { 728, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment1"),
    TARGET_STRING("HasPanto"), 0, 0, 0 },

  { 729, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment1"),
    TARGET_STRING("PenumaticsPoweredPanto"), 0, 0, 0 },

  { 730, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment1"),
    TARGET_STRING("ElectricPoweredPanto"), 0, 0, 0 },

  { 731, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment2"),
    TARGET_STRING("HasPanto"), 0, 0, 0 },

  { 732, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment2"),
    TARGET_STRING("PenumaticsPoweredPanto"), 0, 0, 0 },

  { 733, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment2"),
    TARGET_STRING("ElectricPoweredPanto"), 0, 0, 0 },

  { 734, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment3"),
    TARGET_STRING("HasPanto"), 0, 0, 0 },

  { 735, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment3"),
    TARGET_STRING("PenumaticsPoweredPanto"), 0, 0, 0 },

  { 736, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment3"),
    TARGET_STRING("ElectricPoweredPanto"), 0, 0, 0 },

  { 737, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 738, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 739, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 740, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasCompressor"), 0, 0, 0 },

  { 741, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 742, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 743, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 744, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 745, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 746, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasCompressor"), 0, 0, 0 },

  { 747, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 748, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 749, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 750, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 751, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 752, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasCompressor"), 0, 0, 0 },

  { 753, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 754, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 755, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasCab"), 0, 0, 0 },

  { 756, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasBogie"), 0, 0, 0 },

  { 757, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasPantograph"), 0, 0, 0 },

  { 758, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasCompressor"), 0, 0, 0 },

  { 759, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasMainReservoir"), 0, 0, 0 },

  { 760, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3"),
    TARGET_STRING("HasBrakeSystem"), 0, 0, 0 },

  { 761, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 762, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment1"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 763, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment2"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 764, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment3"),
    TARGET_STRING("HasMotors"), 0, 0, 0 },

  { 765, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Common/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 766, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant"),
    TARGET_STRING("Value"), 128, 0, 0 },

  { 767, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 768, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant12"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 769, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 770, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 771, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 772, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant7"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 773, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant8"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 774, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/Constant9"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 775, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics/UseDavisCoeff"),
    TARGET_STRING("Value"), 127, 0, 0 },

  { 776, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/Constant1"),
    TARGET_STRING("Value"), 196, 0, 0 },

  { 777, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Effects In Processing/Constant"),
    TARGET_STRING("Value"), 190, 0, 0 },

  { 778, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Environment Dynamics In Processing/Constant10"),
    TARGET_STRING("Value"), 191, 0, 0 },

  { 779, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Environment Dynamics In Processing/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 780, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Tuning In Processing/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 781, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Constant2"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 782, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Constant3"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 783, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Constant7"),
    TARGET_STRING("Value"), 188, 0, 0 },

  { 784, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Lateral Velocity"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 785, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Vertical Acceleration"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 786, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Vertical Velocity"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 787, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 788, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 789, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 790, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 791, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller"),
    TARGET_STRING("DifferentiatorICPrevScaledInput"), 0, 0, 0 },

  { 792, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 793, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 794, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 795, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand"),
    TARGET_STRING("DifferentiatorICPrevScaledInput"), 0, 0, 0 },

  { 796, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 797, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 798, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Brake When Close to Stopping Point/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 799, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Coasting/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 800, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/NotInATO/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 801, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/ATB"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 802, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/ATO"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 803, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/ATP"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 804, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/Off"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 805, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/RMF"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 806, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/RMR"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 807, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/ROS"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 808, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/UTO"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 809, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 810, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 811, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority2"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 812, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority3"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 813, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 814, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 815, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/Unit Delay2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 816, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL1"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 817, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL2"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 818, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL3"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 819, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL4"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 820, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR1"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 821, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR2"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 822, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR3"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 823, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR4"),
    TARGET_STRING("isLeft"), 0, 0, 0 },

  { 824, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 825, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 826, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 827, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 828, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 829, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 830, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant7"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 831, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/Constant8"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 832, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/EmergencyDoorInputsExtraction/Constant1"),
    TARGET_STRING("Value"), 126, 0, 0 },

  { 833, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Overrides AutoPowerOn/Detect Increase1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 834, TARGET_STRING("BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Overrides AutoPowerOn/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 14, 0, 0 },

  { 835, TARGET_STRING("BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/ElectricalSignals/For Each Subsystem/Constant3"),
    TARGET_STRING("Value"), 151, 0, 0 },

  { 836, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DoorsSignals/For Each Subsystem/Constant3"),
    TARGET_STRING("Value"), 162, 0, 0 },

  { 837, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PneumaticsSignals/For Each Subsystem/Constant3"),
    TARGET_STRING("Value"), 160, 0, 0 },

  { 838, TARGET_STRING("BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/TractionSignals/For Each Subsystem/Constant3"),
    TARGET_STRING("Value"), 167, 0, 0 },

  { 839, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ComputerSignals/For Each Subsystem/Constant1"),
    TARGET_STRING("Value"), 179, 0, 0 },

  { 840, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/ControlStateRq"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 841, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Complete"),
    TARGET_STRING("InitialOutput"), 14, 0, 0 },

  { 842, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 843, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 844, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/ControlStateRq"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 845, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Complete"),
    TARGET_STRING("InitialOutput"), 14, 0, 0 },

  { 846, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 847, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 848, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/ControlStateRq"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 849, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Complete"),
    TARGET_STRING("InitialOutput"), 14, 0, 0 },

  { 850, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 851, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 852, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/ControlStateRq"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 853, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Complete"),
    TARGET_STRING("InitialOutput"), 14, 0, 0 },

  { 854, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 855, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 856, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 857, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 858, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 859, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 860, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 861, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 862, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 863, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 864, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 865, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 866, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 867, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 868, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 869, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 870, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 871, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 872, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 873, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 874, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 875, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 876, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 877, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 878, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 879, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 880, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 881, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 882, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 883, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 884, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 885, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 886, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 887, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 888, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 889, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 890, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 891, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 892, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 893, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 894, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 895, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 896, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 897, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 898, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Increment"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 899, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Momentary"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 900, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 120, 0, 0 },

  { 901, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 120, 0, 0 },

  { 902, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 120, 0, 0 },

  { 903, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment4/Constant6"),
    TARGET_STRING("Value"), 120, 0, 0 },

  { 904, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/Constant6"),
    TARGET_STRING("Value"), 136, 0, 0 },

  { 905, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 136, 0, 0 },

  { 906, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 136, 0, 0 },

  { 907, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 136, 0, 0 },

  { 908, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment/Constant6"),
    TARGET_STRING("Value"), 226, 0, 0 },

  { 909, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 226, 0, 0 },

  { 910, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 226, 0, 0 },

  { 911, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 226, 0, 0 },

  { 912, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment/Constant6"),
    TARGET_STRING("Value"), 148, 0, 0 },

  { 913, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 148, 0, 0 },

  { 914, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 148, 0, 0 },

  { 915, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 148, 0, 0 },

  { 916, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment/Constant6"),
    TARGET_STRING("Value"), 150, 0, 0 },

  { 917, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 150, 0, 0 },

  { 918, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 150, 0, 0 },

  { 919, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 150, 0, 0 },

  { 920, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment/Constant6"),
    TARGET_STRING("Value"), 174, 0, 0 },

  { 921, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment1/Constant6"),
    TARGET_STRING("Value"), 174, 0, 0 },

  { 922, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment2/Constant6"),
    TARGET_STRING("Value"), 174, 0, 0 },

  { 923, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment3/Constant6"),
    TARGET_STRING("Value"), 174, 0, 0 },

  { 924, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/Subsystem/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 925, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/Subsystem/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 926, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant"),
    TARGET_STRING("const"), 135, 0, 0 },

  { 927, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 928, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant2"),
    TARGET_STRING("const"), 135, 0, 0 },

  { 929, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant4"),
    TARGET_STRING("const"), 135, 0, 0 },

  { 930, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 931, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant8"),
    TARGET_STRING("const"), 135, 0, 0 },

  { 932, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant9"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 933, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 934, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 935, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem/Subsystem/Discrete-Time Integrator1"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 936, TARGET_STRING("BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem/Subsystem/Discrete-Time Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 937, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Constant8"),
    TARGET_STRING("Value"), 187, 0, 0 },

  { 938, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Roll"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 939, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/InitMotionBaseOut"),
    TARGET_STRING("Value"), 246, 0, 0 },

  { 940, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/SafeMotionBaseOut/InitMotionBaseOut1"),
    TARGET_STRING("Value"), 246, 0, 0 },

  { 941, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/SafeMotionBaseOut/SafeGravitationalAcceleration"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 942, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/SafeMotionBaseOut/SafeRotationMatrix"),
    TARGET_STRING("Value"), 0, 9, 0 },

  { 943, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL1/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 944, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL2/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 945, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL3/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 946, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL4/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 947, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR1/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 948, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR2/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 949, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR3/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 950, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR4/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 951, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 952, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 953, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 954, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 955, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 956, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 957, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 958, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 959, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 960, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 961, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 962, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 963, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 964, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 965, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 966, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 967, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 968, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 969, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 970, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 971, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 972, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 973, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 974, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 975, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 976, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 977, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 978, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 979, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 980, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 981, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 982, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 983, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 984, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 985, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 986, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 987, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 988, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 989, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 990, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 991, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 992, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 993, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 994, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 995, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 996, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 997, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 998, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 999, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1000, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1001, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1002, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1003, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1004, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1005, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1006, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1007, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1008, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1009, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1010, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1011, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1012, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1013, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1014, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1015, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1016, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1017, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1018, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1019, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1020, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1021, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1022, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1023, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1024, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1025, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1026, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1027, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1028, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1029, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1030, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1031, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1032, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1033, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1034, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1035, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1036, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1037, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1038, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1039, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1040, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1041, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1042, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1043, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1044, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1045, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1046, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1047, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1048, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1049, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1050, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1051, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1052, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1053, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1054, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1055, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1056, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1057, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1058, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1059, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1060, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1061, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1062, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1063, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1064, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1065, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1066, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1067, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1068, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1069, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1070, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1071, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1072, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1073, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1074, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1075, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant4"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1076, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1077, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1078, TARGET_STRING("BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant7"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1079, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals/Bogie1/Constant1"),
    TARGET_STRING("Value"), 177, 0, 0 },

  { 1080, TARGET_STRING("BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals/Bogie2/Constant1"),
    TARGET_STRING("Value"), 177, 0, 0 },

  { 1081, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1082, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1083, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1084, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1085, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1086, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1087, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1088, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1089, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1090, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1091, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1092, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1093, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1094, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1095, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1096, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1097, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1098, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1099, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1100, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1101, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1102, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1103, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1104, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1105, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1106, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1107, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1108, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1109, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1110, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1111, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1112, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1113, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1114, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1115, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1116, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1117, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1118, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1119, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1120, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1121, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1122, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1123, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1124, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1125, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1126, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1127, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1128, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1129, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1130, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1131, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1132, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1133, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1134, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1135, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1136, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1137, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1138, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1139, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1140, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1141, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1142, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1143, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1144, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1145, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1146, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1147, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1148, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1149, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1150, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1151, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1152, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1153, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1154, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1155, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1156, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1157, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1158, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1159, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1160, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1161, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1162, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1163, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1164, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1165, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1166, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1167, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1168, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1169, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1170, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1171, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1172, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1173, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1174, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1175, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1176, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1177, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1178, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1179, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1180, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1181, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1182, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1183, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1184, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1185, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1186, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1187, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1188, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1189, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1190, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1191, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1192, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1193, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1194, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1195, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1196, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1197, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1198, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1199, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1200, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1201, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1202, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1203, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1204, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1205, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1206, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1207, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1208, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1209, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1210, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1211, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1212, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1213, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1214, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1215, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1216, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1217, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1218, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1219, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1220, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1221, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1222, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1223, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1224, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1225, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1226, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1227, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1228, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1229, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1230, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1231, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1232, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1233, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1234, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1235, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1236, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1237, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1238, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1239, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1240, TARGET_STRING("BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1241, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1242, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem1/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1243, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem2/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1244, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1245, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem1/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1246, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem2/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1247, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1248, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem1/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1249, TARGET_STRING("BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem2/Constant"),
    TARGET_STRING("Value"), 14, 0, 0 },

  { 1250, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/GravitationalAcceleration/GravitationalAcceleration"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 1251, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualOrientationAdjustment"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 1252, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Motion Cutout/Above 20 Degrees"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 1253, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Motion Cutout/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 14, 0, 0 },

  { 1254, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/Dead Zone"),
    TARGET_STRING("LowerValue"), 0, 0, 0 },

  { 1255, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/Dead Zone"),
    TARGET_STRING("UpperValue"), 0, 0, 0 },

  { 1256, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Heave Matrix/Constant"),
    TARGET_STRING("Value"), 0, 9, 0 },

  { 1257, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Heave Matrix/Gain"),
    TARGET_STRING("Gain"), 0, 9, 0 },

  { 1258, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Heave Matrix/Gain2"),
    TARGET_STRING("Gain"), 0, 9, 0 },

  { 1259, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Pitch Matrix/Constant1"),
    TARGET_STRING("Value"), 0, 9, 0 },

  { 1260, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Pitch Matrix/Gain1"),
    TARGET_STRING("Gain"), 0, 9, 0 },

  { 1261, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Pitch Matrix/Gain3"),
    TARGET_STRING("Gain"), 0, 9, 0 },

  { 1262, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt"),
    TARGET_STRING("JoltProfile"), 0, 13, 0 },

  { 1263, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt"),
    TARGET_STRING("JoltBreakPoints"), 0, 13, 0 },

  { 1264, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1"),
    TARGET_STRING("JoltProfile"), 0, 13, 0 },

  { 1265, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1"),
    TARGET_STRING("JoltBreakPoints"), 0, 13, 0 },

  { 1266, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2"),
    TARGET_STRING("JoltProfile"), 0, 13, 0 },

  { 1267, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2"),
    TARGET_STRING("JoltBreakPoints"), 0, 13, 0 },

  { 1268, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3"),
    TARGET_STRING("JoltProfile"), 0, 13, 0 },

  { 1269, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3"),
    TARGET_STRING("JoltBreakPoints"), 0, 13, 0 },

  { 1270, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1271, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1272, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/Merge"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 1273, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/LPFConstantTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1274, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/LPFConstantTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1275, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/SaturationTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1276, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/SaturationTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1277, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1278, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/1-D Lookup Table"),
    TARGET_STRING("Table"), 0, 11, 0 },

  { 1279, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/1-D Lookup Table"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 11, 0 },

  { 1280, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/LPFConstantTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1281, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/LPFConstantTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1282, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/SaturationTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1283, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/SaturationTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1284, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1285, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/1-D Lookup Table"),
    TARGET_STRING("Table"), 0, 11, 0 },

  { 1286, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/1-D Lookup Table"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 11, 0 },

  { 1287, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/CollisionGainReset"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1288, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/RampRate"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1289, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1290, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1291, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1292, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1293, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/LPFConstantTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1294, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/LPFConstantTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1295, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/SaturationTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1296, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/SaturationTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1297, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1298, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/LPFConstantTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1299, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/LPFConstantTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1300, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/SaturationTuning"),
    TARGET_STRING("DefaultValue"), 0, 0, 0 },

  { 1301, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/SaturationTuning"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1302, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1303, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/1-D Lookup Table"),
    TARGET_STRING("Table"), 0, 11, 0 },

  { 1304, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/1-D Lookup Table"),
    TARGET_STRING("BreakpointsForDimension1"), 0, 11, 0 },

  { 1305, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Filter/Differentiator/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1306, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1307, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Filter/Differentiator/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1308, TARGET_STRING("BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1309, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Detect Increase"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 1310, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1311, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1312, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Detect Increase"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 1313, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1314, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1315, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Detect Increase"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 1316, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1317, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1318, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Detect Increase"),
    TARGET_STRING("vinit"), 14, 0, 0 },

  { 1319, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1320, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1321, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator"),
    TARGET_STRING("SpeedSaturation"), 0, 0, 0 },

  { 1322, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1323, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/Zeros"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 1324, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Constant"),
    TARGET_STRING("Value"), 247, 0, 0 },

  { 1325, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Constant1"),
    TARGET_STRING("Value"), 247, 0, 0 },

  { 1326, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Constant2"),
    TARGET_STRING("Value"), 247, 0, 0 },

  { 1327, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1328, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/NoTrackFeel/Zeros"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 1329, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator"),
    TARGET_STRING("SpeedSaturation"), 0, 0, 0 },

  { 1330, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1331, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/Zeros"),
    TARGET_STRING("Value"), 0, 12, 0 },

  { 1332, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1333, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1334, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1335, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1336, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1337, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1338, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1339, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1340, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1341, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1342, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1343, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1344, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1345, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1346, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1347, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1348, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1349, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1350, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1351, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1352, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1353, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1354, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1355, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1356, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1357, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1358, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1359, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1360, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1361, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1362, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1363, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Initialise"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1364, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/OffTime"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1365, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1366, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1367, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1368, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1369, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1370, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Initialise"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1371, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/OffTime"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1372, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1373, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1374, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1375, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1376, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1377, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Initialise"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1378, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/OffTime"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1379, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1380, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1381, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1382, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1383, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1384, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Initialise"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1385, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/OffTime"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1386, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1387, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 1388, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 1389, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1390, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1391, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise"),
    TARGET_STRING("Cov"), 0, 0, 0 },

  { 1392, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise"),
    TARGET_STRING("seed"), 0, 0, 0 },

  { 1393, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise1"),
    TARGET_STRING("Cov"), 0, 0, 0 },

  { 1394, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise1"),
    TARGET_STRING("seed"), 0, 0, 0 },

  { 1395, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Sample and Hold"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1396, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1397, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1398, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1399, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1400, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1401, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1402, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1403, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1404, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Switch4"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1405, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1406, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise"),
    TARGET_STRING("Cov"), 0, 0, 0 },

  { 1407, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise"),
    TARGET_STRING("seed"), 0, 0, 0 },

  { 1408, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise1"),
    TARGET_STRING("Cov"), 0, 0, 0 },

  { 1409, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise1"),
    TARGET_STRING("seed"), 0, 0, 0 },

  { 1410, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Sample and Hold"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1411, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1412, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1413, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Pulse Generator1"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1414, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Pulse Generator1"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1415, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Pulse Generator1"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1416, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Pulse Generator1"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1417, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1418, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1419, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Switch4"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1420, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1421, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Count to 0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1422, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Count to 0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1423, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Count to 0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1424, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Count to 0/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1425, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/AmplitudeOverride/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1426, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise/White Noise"),
    TARGET_STRING("Mean"), 0, 0, 0 },

  { 1427, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise/White Noise"),
    TARGET_STRING("StdDev"), 0, 0, 0 },

  { 1428, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise1/White Noise"),
    TARGET_STRING("Mean"), 0, 0, 0 },

  { 1429, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise1/White Noise"),
    TARGET_STRING("StdDev"), 0, 0, 0 },

  { 1430, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 1431, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1432, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Sample and Hold/Latch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1433, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor/Tuning Factor"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1434, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1435, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor/Constant4"),
    TARGET_STRING("Value"), 0, 11, 0 },

  { 1436, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1437, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/AmplitudeOverride/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1438, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise/White Noise"),
    TARGET_STRING("Mean"), 0, 0, 0 },

  { 1439, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise/White Noise"),
    TARGET_STRING("StdDev"), 0, 0, 0 },

  { 1440, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise1/White Noise"),
    TARGET_STRING("Mean"), 0, 0, 0 },

  { 1441, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise1/White Noise"),
    TARGET_STRING("StdDev"), 0, 0, 0 },

  { 1442, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 1443, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1444, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Sample and Hold/Latch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1445, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor/Tuning Factor"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 1446, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1447, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor/Constant4"),
    TARGET_STRING("Value"), 0, 11, 0 },

  { 1448, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1449, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1450, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1451, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1452, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1453, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1454, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1455, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1456, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1457, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1458, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1459, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1460, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1461, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1462, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1463, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1464, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1465, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1466, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1467, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1468, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1469, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1470, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1471, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1472, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1473, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1474, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1475, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1476, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1477, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1478, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1479, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1480, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1481, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1482, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1483, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1484, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1485, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1486, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1487, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1488, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1489, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1490, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1491, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1492, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1493, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1494, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1495, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1496, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1497, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1498, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1499, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 1500, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 1501, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 1502, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 1503, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 1504, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 1505, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1506, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1507, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1508, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1509, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1510, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1511, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1512, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1513, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1514, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1515, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1516, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1517, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1518, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1519, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1520, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1521, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1522, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1523, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1524, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1525, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1526, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1527, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1528, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1529, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1530, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1531, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1532, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1533, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1534, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1535, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1536, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1537, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1538, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1539, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 1540, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1541, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1542, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/FilterSpecification"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 1543, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 1544, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 1545, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Discrete Transfer Fcn"),
    TARGET_STRING("InitialStates"), 0, 0, 0 },

  { 1546, TARGET_STRING("BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  { 1547, -1, TARGET_STRING(
    "BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/Unit Delay"),
    TARGET_STRING(""), "", 0, 135, 3, 0, 1, 0, -1, 0 },

  { 1548, -1, TARGET_STRING(
    "BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/Discrete-Time\nIntegrator"),
    TARGET_STRING(""), "", 0, 0, 0, 0, 1, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void BEML_EMU_InitializeDataAddr(RT_MODEL_BEML_EMU_T *const BEML_EMU_M,
  void* dataAddr[], B_BEML_EMU_T *BEML_EMU_B, P_BEML_EMU_T *BEML_EMU_P,
  DW_BEML_EMU_T *BEML_EMU_DW, self_CoreSubsys_BEML_EMU_gj_T
  self_CoreSubsys_pnaevvfpgh5z[8], self_CoreSubsys_BEML_EMU_o_T
  self_CoreSubsys_pnaevvfpgh5[8], self_CoreSubsys_BEML_EMU_jb2bnsaujtd5u_T
  self_CoreSubsys_pnaevvfpg[8], self_CoreSubsys_BEML_EMU_jb2bnsau_T
  self_CoreSubsys_pnaevvf[8], self_CoreSubsys_BEML_EMU_jb2bn_T
  self_CoreSubsys_pnae[8], self_CoreSubsys_BEML_EMU_jb2_T self_CoreSubsys_pna[8],
  self_CoreSubsys_BEML_EMU_j_T self_CoreSubsys_p[8])
{
  dataAddr[0] = (void*) (&BEML_EMU_B->BusAssignment);
  dataAddr[1] = (void*) (&BEML_EMU_B->ProcessedVehicleInput[0]);
  dataAddr[2] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_InputControlStates_at_inport_0[0]);
  dataAddr[3] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_VehicleModelFaults_at_inport_0[0]);
  dataAddr[4] = (void*) (&BEML_EMU_B->UnitDelay_n[0]);
  dataAddr[5] = (void*) (&BEML_EMU_B->UnitDelay1[0]);
  dataAddr[6] = (void*) (&BEML_EMU_B->UnitDelay2[0]);
  dataAddr[7] = (void*) (&BEML_EMU_B->UnitDelay3[0]);
  dataAddr[8] = (void*) (&BEML_EMU_B->UnitDelay_j[0]);
  dataAddr[9] = (void*) (&BEML_EMU_B->UnitDelay1_k[0]);
  dataAddr[10] = (void*) (&BEML_EMU_B->UnitDelay4[0]);
  dataAddr[11] = (void*) (&BEML_EMU_B->UnitDelay5[0]);
  dataAddr[12] = (void*) (&BEML_EMU_B->UnitDelay6[0]);
  dataAddr[13] = (void*) (&BEML_EMU_B->UnitDelay7[0]);
  dataAddr[14] = (void*) (&BEML_EMU_B->ProcessedVehicleInput[0]);
  dataAddr[15] = (void*) (&BEML_EMU_B->UnitDelay[0]);
  dataAddr[16] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ly[0]);
  dataAddr[17] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesVehicleConfig_at_inport_0[0]);
  dataAddr[18] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesVehicleInput_at_inport_0[0]);
  dataAddr[19] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_n[0]);
  dataAddr[20] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesFaults_at_inport_0[0]);
  dataAddr[21] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ds[0]);
  dataAddr[22] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DoorsVehicleInput_at_inport_0[0]);
  dataAddr[23] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_j[0]);
  dataAddr[24] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_EmergencyDoorInputs_at_inport_0[0]);
  dataAddr[25] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_d[0]);
  dataAddr[26] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsVehicleConfig_at_inport_0[0]);
  dataAddr[27] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsVehicleInput_at_inport_0[0]);
  dataAddr[28] = (void*) (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0
    [0]);
  dataAddr[29] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsFaults_at_inport_0[0]);
  dataAddr[30] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_e[0]);
  dataAddr[31] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalVehicleConfig_at_inport_0[0]);
  dataAddr[32] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalVehicleInput_at_inport_0[0]);
  dataAddr[33] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalFaults_at_inport_0[0]);
  dataAddr[34] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_a[0]);
  dataAddr[35] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PantographVehicleConfig_at_inport_0[0]);
  dataAddr[36] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_b[0]);
  dataAddr[37] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsVehicleConfig_at_inport_0[0]);
  dataAddr[38] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsVehicleInput_at_inport_0[0]);
  dataAddr[39] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_im[0]);
  dataAddr[40] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsFaults_at_inport_0[0]);
  dataAddr[41] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_l[0]);
  dataAddr[42] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TCMSVehicleConfig_at_inport_0[0]);
  dataAddr[43] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TCMSVehicleInput_at_inport_0[0]);
  dataAddr[44] = (void*) (&BEML_EMU_B->
    ImpAsg_InsertedFor_TCMSFaults_at_inport_0[0]);
  dataAddr[45] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_VehicleLevelFaults_at_inport_0[0]);
  dataAddr[46] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[0]);
  dataAddr[47] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionVehicleConfig_at_inport_0[0]);
  dataAddr[48] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionVehicleInput_at_inport_0[0]);
  dataAddr[49] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_i[0]);
  dataAddr[50] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionFaults_at_inport_0[0]);
  dataAddr[51] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_IOControlsModelFaults_at_inport_0[0]);
  dataAddr[52] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_VehicleModelFaults_at_inport_0[0]);
  dataAddr[53] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_InputControlStates_at_inport_0[0]);
  dataAddr[54] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ModelInputs_at_inport_0[0]);
  dataAddr[55] = (void*) (&BEML_EMU_B->UnitDelay_p[0]);
  dataAddr[56] = (void*) (&BEML_EMU_B->BusAssignment);
  dataAddr[57] = (void*) (&BEML_EMU_B->NOT);
  dataAddr[58] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_MotionBaseInput_at_inport_0[0]);
  dataAddr[59] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ly[0]);
  dataAddr[60] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesVehicleConfig_at_inport_0[0]);
  dataAddr[61] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesVehicleInput_at_inport_0[0]);
  dataAddr[62] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_n[0]);
  dataAddr[63] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesFaults_at_inport_0[0]);
  dataAddr[64] = (void*) (&BEML_EMU_B->ImpAsg_InsertedFor_VehConfig_at_inport_0
    [0]);
  dataAddr[65] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CouplingInput_at_inport_0[0]);
  dataAddr[66] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ds[0]);
  dataAddr[67] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DoorsConfig_at_inport_0[0]);
  dataAddr[68] = (void*) (&BEML_EMU_B->ImpAsg_InsertedFor_HasCab_at_inport_0[0]);
  dataAddr[69] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DoorsVehicleInput_at_inport_0[0]);
  dataAddr[70] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_j[0]);
  dataAddr[71] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_EmergencyDoorInputs_at_inport_0[0]);
  dataAddr[72] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_d[0]);
  dataAddr[73] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsVehicleConfig_at_inport_0[0]);
  dataAddr[74] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsVehicleInput_at_inport_0[0]);
  dataAddr[75] = (void*) (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0
    [0]);
  dataAddr[76] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsFaults_at_inport_0[0]);
  dataAddr[77] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_e[0]);
  dataAddr[78] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalVehicleConfig_at_inport_0[0]);
  dataAddr[79] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalVehicleInput_at_inport_0[0]);
  dataAddr[80] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalFaults_at_inport_0[0]);
  dataAddr[81] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_a[0]);
  dataAddr[82] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PantographVehicleConfig_at_inport_0[0]);
  dataAddr[83] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_b[0]);
  dataAddr[84] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsVehicleConfig_at_inport_0[0]);
  dataAddr[85] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_LocationVehicleConfig_at_inport_0[0]);
  dataAddr[86] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsVehicleInput_at_inport_0[0]);
  dataAddr[87] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_im[0]);
  dataAddr[88] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsFaults_at_inport_0[0]);
  dataAddr[89] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_l[0]);
  dataAddr[90] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TCMSVehicleConfig_at_inport_0[0]);
  dataAddr[91] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TCMSVehicleInput_at_inport_0[0]);
  dataAddr[92] = (void*) (&BEML_EMU_B->
    ImpAsg_InsertedFor_TCMSFaults_at_inport_0[0]);
  dataAddr[93] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_VehicleLevelFaults_at_inport_0[0]);
  dataAddr[94] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[0]);
  dataAddr[95] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionVehicleConfig_at_inport_0[0]);
  dataAddr[96] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionVehicleInput_at_inport_0[0]);
  dataAddr[97] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_Overrides_at_inport_0_i[0]);
  dataAddr[98] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionFaults_at_inport_0[0]);
  dataAddr[99] = (void*) (&self_CoreSubsys_p[7].blockIO.OR);
  dataAddr[100] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ly[0]);
  dataAddr[101] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_BrakesVehicleConfig_at_inport_0[0]);
  dataAddr[102] = (void*) (&BEML_EMU_B->CoreSubsys_h[7].ATOBrake);
  dataAddr[103] = (void*) (&BEML_EMU_B->CoreSubsys_h[7].ATOTraction);
  dataAddr[104] = (void*) (&BEML_EMU_B->CoreSubsys_h[7].ATOTBDemand);
  dataAddr[105] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ds[0]);
  dataAddr[106] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DoorsConfig_at_inport_0[0]);
  dataAddr[107] = (void*) (&BEML_EMU_B->ImpAsg_InsertedFor_HasCab_at_inport_0[0]);
  dataAddr[108] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_d[0]);
  dataAddr[109] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_DynamicsVehicleConfig_at_inport_0[0]);
  dataAddr[110] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_e[0]);
  dataAddr[111] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_ElectricalVehicleConfig_at_inport_0[0]);
  dataAddr[112] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_a[0]);
  dataAddr[113] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PantographVehicleConfig_at_inport_0[0]);
  dataAddr[114] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_b[0]);
  dataAddr[115] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_PneumaticsVehicleConfig_at_inport_0[0]);
  dataAddr[116] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_LocationVehicleConfig_at_inport_0[0]);
  dataAddr[117] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_l[0]);
  dataAddr[118] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TCMSVehicleConfig_at_inport_0[0]);
  dataAddr[119] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[0]);
  dataAddr[120] = (void*)
    (&BEML_EMU_B->ImpAsg_InsertedFor_TractionVehicleConfig_at_inport_0[0]);
  dataAddr[121] = (void*) (&self_CoreSubsys_p[7].blockIO.AND);
  dataAddr[122] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion10);
  dataAddr[123] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion11);
  dataAddr[124] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion13);
  dataAddr[125] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion15);
  dataAddr[126] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion17);
  dataAddr[127] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion19);
  dataAddr[128] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion21);
  dataAddr[129] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion23);
  dataAddr[130] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion41);
  dataAddr[131] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion6);
  dataAddr[132] = (void*) (&self_CoreSubsys_p[7].blockIO.DataTypeConversion8);
  dataAddr[133] = (void*) (&self_CoreSubsys_p[7].blockIO.APSICBInternalRequest);
  dataAddr[134] = (void*) (&self_CoreSubsys_p[7].blockIO.FDSCBInternalRequest);
  dataAddr[135] = (void*) (&self_CoreSubsys_p[7].blockIO.SAC1CBInternalRequest);
  dataAddr[136] = (void*) (&self_CoreSubsys_p[7].blockIO.SAC2CBInternalRequest);
  dataAddr[137] = (void*) (&self_CoreSubsys_p[7].blockIO.FixPtRelationalOperator);
  dataAddr[138] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_a.Switch1);
  dataAddr[139] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_a.RelationalOperator);
  dataAddr[140] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_f.TriggerFaultRequest);
  dataAddr[141] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_f.UseFaultedTarget);
  dataAddr[142] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_n.Switch1);
  dataAddr[143] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_n.RelationalOperator);
  dataAddr[144] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_k.TriggerFaultRequest);
  dataAddr[145] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_k.UseFaultedTarget);
  dataAddr[146] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_i.Switch1);
  dataAddr[147] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_i.RelationalOperator);
  dataAddr[148] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_e.TriggerFaultRequest);
  dataAddr[149] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart_e.UseFaultedTarget);
  dataAddr[150] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest.Switch1);
  dataAddr[151] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest.RelationalOperator);
  dataAddr[152] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart.TriggerFaultRequest);
  dataAddr[153] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_Chart.UseFaultedTarget);
  dataAddr[154] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_in.TriggerFaultRequest);
  dataAddr[155] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_in.TargetStateValue);
  dataAddr[156] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_fm.TriggerFaultRequest);
  dataAddr[157] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_fm.TargetStateValue);
  dataAddr[158] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_a.TriggerFaultRequest);
  dataAddr[159] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_a.TargetStateValue);
  dataAddr[160] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_d.TriggerFaultRequest);
  dataAddr[161] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_d.TargetStateValue);
  dataAddr[162] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_f.TriggerFaultRequest);
  dataAddr[163] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_f.TargetStateValue);
  dataAddr[164] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_hr.TriggerFaultRequest);
  dataAddr[165] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_hr.TargetStateValue);
  dataAddr[166] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e5.TriggerFaultRequest);
  dataAddr[167] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e5.TargetStateValue);
  dataAddr[168] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e2.TriggerFaultRequest);
  dataAddr[169] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e2.TargetStateValue);
  dataAddr[170] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_i.TriggerFaultRequest);
  dataAddr[171] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_i.TargetStateValue);
  dataAddr[172] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_h1.TriggerFaultRequest);
  dataAddr[173] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_h1.TargetStateValue);
  dataAddr[174] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_c.TriggerFaultRequest);
  dataAddr[175] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_c.TargetStateValue);
  dataAddr[176] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_j.TriggerFaultRequest);
  dataAddr[177] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_j.TargetStateValue);
  dataAddr[178] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_h.TriggerFaultRequest);
  dataAddr[179] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_h.TargetStateValue);
  dataAddr[180] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_p.TriggerFaultRequest);
  dataAddr[181] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_p.TargetStateValue);
  dataAddr[182] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_ma.TriggerFaultRequest);
  dataAddr[183] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_ma.TargetStateValue);
  dataAddr[184] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_b.TriggerFaultRequest);
  dataAddr[185] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_b.TargetStateValue);
  dataAddr[186] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_o.TriggerFaultRequest);
  dataAddr[187] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_o.TargetStateValue);
  dataAddr[188] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_mb.TriggerFaultRequest);
  dataAddr[189] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_mb.TargetStateValue);
  dataAddr[190] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_m.TriggerFaultRequest);
  dataAddr[191] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_m.TargetStateValue);
  dataAddr[192] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_l.TriggerFaultRequest);
  dataAddr[193] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_l.TargetStateValue);
  dataAddr[194] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e.TriggerFaultRequest);
  dataAddr[195] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine_e.TargetStateValue);
  dataAddr[196] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine.TriggerFaultRequest);
  dataAddr[197] = (void*) (&self_CoreSubsys_p[7].
    blockIO.sf_IRQRequestStateMachine.TargetStateValue);
  dataAddr[198] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_a.RelationalOperator);
  dataAddr[199] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_a.Switch1);
  dataAddr[200] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_n.RelationalOperator);
  dataAddr[201] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_n.Switch1);
  dataAddr[202] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_i.RelationalOperator);
  dataAddr[203] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest_i.Switch1);
  dataAddr[204] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest.RelationalOperator);
  dataAddr[205] = (void*) (&self_CoreSubsys_p[7].
    blockIO.ControlStateRequest.Switch1);
  dataAddr[206] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[207] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[208] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[209] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[210] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].IC);
  dataAddr[211] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_o.LogicalOperator1);
  dataAddr[212] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_n.LogicalOperator1);
  dataAddr[213] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_e.LogicalOperator1);
  dataAddr[214] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration.LogicalOperator1);
  dataAddr[215] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[216] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].ManualPosition[0]);
  dataAddr[217] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_k[0]);
  dataAddr[218] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_n[0]);
  dataAddr[219] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_n[0]
    + 1));
  dataAddr[220] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_k[0]
    + 1));
  dataAddr[221] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_m[0]);
  dataAddr[222] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_jf[0]);
  dataAddr[223] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_jf
    [0] + 1));
  dataAddr[224] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_m[0]
    + 1));
  dataAddr[225] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_p[0]);
  dataAddr[226] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_j[0]);
  dataAddr[227] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_j[0]
    + 1));
  dataAddr[228] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_p[0]
    + 1));
  dataAddr[229] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate[0]);
  dataAddr[230] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1[0]);
  dataAddr[231] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1[0]
    + 1));
  dataAddr[232] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate[0] +
    1));
  dataAddr[233] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_o.LogicalOperator1);
  dataAddr[234] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_n.LogicalOperator1);
  dataAddr[235] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration_e.LogicalOperator1);
  dataAddr[236] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].
    JoltDuration.LogicalOperator1);
  dataAddr[237] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_g[0]);
  dataAddr[238] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_c[0]);
  dataAddr[239] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_c[0]
    + 1));
  dataAddr[240] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_g[0]
    + 1));
  dataAddr[241] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_o[0]);
  dataAddr[242] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_iu[0]);
  dataAddr[243] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_iu
    [0] + 1));
  dataAddr[244] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_o[0]
    + 1));
  dataAddr[245] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_ko[0]);
  dataAddr[246] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_i[0]);
  dataAddr[247] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_i[0]
    + 1));
  dataAddr[248] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_ko[0]
    + 1));
  dataAddr[249] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_a[0]);
  dataAddr[250] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_o[0]);
  dataAddr[251] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_o[0]
    + 1));
  dataAddr[252] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_a[0]
    + 1));
  dataAddr[253] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_o4[0]);
  dataAddr[254] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_h[0]);
  dataAddr[255] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_h[0]
    + 1));
  dataAddr[256] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_o4[0]
    + 1));
  dataAddr[257] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_ge[0]);
  dataAddr[258] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_l[0]);
  dataAddr[259] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_l[0]
    + 1));
  dataAddr[260] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_ge[0]
    + 1));
  dataAddr[261] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_n[0]);
  dataAddr[262] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_om[0]);
  dataAddr[263] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_om
    [0] + 1));
  dataAddr[264] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_n[0]
    + 1));
  dataAddr[265] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_i4[0]);
  dataAddr[266] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_iv[0]);
  dataAddr[267] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_iv
    [0] + 1));
  dataAddr[268] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_i4[0]
    + 1));
  dataAddr[269] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_i[0]);
  dataAddr[270] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_l0[0]);
  dataAddr[271] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_l0
    [0] + 1));
  dataAddr[272] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_i[0]
    + 1));
  dataAddr[273] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_go[0]);
  dataAddr[274] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_g[0]);
  dataAddr[275] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_g[0]
    + 1));
  dataAddr[276] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_go[0]
    + 1));
  dataAddr[277] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_d[0]);
  dataAddr[278] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_hg[0]);
  dataAddr[279] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_hg
    [0] + 1));
  dataAddr[280] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_d[0]
    + 1));
  dataAddr[281] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_oc[0]);
  dataAddr[282] = (void*) (&BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_b[0]);
  dataAddr[283] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate1_b[0]
    + 1));
  dataAddr[284] = (void*) (( &BEML_EMU_B->CoreSubsys_m[7].VectorConcatenate_oc[0]
    + 1));
  dataAddr[285] = (void*) (&BEML_EMU_P->UnitDelay_InitialCondition_b);
  dataAddr[286] = (void*) (&BEML_EMU_P->UnitDelay1_InitialCondition);
  dataAddr[287] = (void*) (&BEML_EMU_P->UnitDelay2_InitialCondition);
  dataAddr[288] = (void*) (&BEML_EMU_P->UnitDelay3_InitialCondition);
  dataAddr[289] = (void*) (&BEML_EMU_P->UnitDelay_InitialCondition_d);
  dataAddr[290] = (void*) (&BEML_EMU_P->UnitDelay1_InitialCondition_c);
  dataAddr[291] = (void*) (&BEML_EMU_P->UnitDelay2_InitialCondition_p);
  dataAddr[292] = (void*) (&BEML_EMU_P->UnitDelay3_InitialCondition_a);
  dataAddr[293] = (void*) (&BEML_EMU_P->UnitDelay4_InitialCondition);
  dataAddr[294] = (void*) (&BEML_EMU_P->UnitDelay5_InitialCondition);
  dataAddr[295] = (void*) (&BEML_EMU_P->UnitDelay6_InitialCondition);
  dataAddr[296] = (void*) (&BEML_EMU_P->UnitDelay7_InitialCondition);
  dataAddr[297] = (void*) (&BEML_EMU_P->Step_Time_l);
  dataAddr[298] = (void*) (&BEML_EMU_P->Step_Y0_gx);
  dataAddr[299] = (void*) (&BEML_EMU_P->Step_YFinal_m);
  dataAddr[300] = (void*) (&BEML_EMU_P->UnitDelay_InitialCondition);
  dataAddr[301] = (void*) (&BEML_EMU_P->TrainBrakes_PRM_TrainBrakes_Vehicles);
  dataAddr[302] = (void*) (&BEML_EMU_P->DoorsSystem_PRM_DoorSystem);
  dataAddr[303] = (void*) (&BEML_EMU_P->ElectricalSystem_Prm_ElectricalSystem);
  dataAddr[304] = (void*) (&BEML_EMU_P->PantographSystem_Prm_PantographSystem);
  dataAddr[305] = (void*) (&BEML_EMU_P->PneumaticsSystem_Prm_PneumaticsSystem);
  dataAddr[306] = (void*) (&BEML_EMU_P->TCMSSystem_Prm_TCMSSystem);
  dataAddr[307] = (void*) (&BEML_EMU_P->TractionSystem_Prm_TractionSystem);
  dataAddr[308] = (void*) (&BEML_EMU_P->UnitDelay_InitialCondition_o);
  dataAddr[309] = (void*) (&BEML_EMU_P->Step_Time_k);
  dataAddr[310] = (void*) (&BEML_EMU_P->Step_Y0_l);
  dataAddr[311] = (void*) (&BEML_EMU_P->Step_YFinal_lp);
  dataAddr[312] = (void*) (&BEML_EMU_P->Step_Time);
  dataAddr[313] = (void*) (&BEML_EMU_P->Step_Y0);
  dataAddr[314] = (void*) (&BEML_EMU_P->Step_YFinal);
  dataAddr[315] = (void*) (&BEML_EMU_P->Step_Time_b);
  dataAddr[316] = (void*) (&BEML_EMU_P->Step_Y0_m);
  dataAddr[317] = (void*) (&BEML_EMU_P->Step_YFinal_a);
  dataAddr[318] = (void*) (&BEML_EMU_P->Step_Time_o);
  dataAddr[319] = (void*) (&BEML_EMU_P->Step_Y0_j);
  dataAddr[320] = (void*) (&BEML_EMU_P->Step_YFinal_l);
  dataAddr[321] = (void*) (&BEML_EMU_P->Step_Time_h);
  dataAddr[322] = (void*) (&BEML_EMU_P->Step_Y0_i);
  dataAddr[323] = (void*) (&BEML_EMU_P->Step_YFinal_d);
  dataAddr[324] = (void*) (&BEML_EMU_P->Step_Time_g);
  dataAddr[325] = (void*) (&BEML_EMU_P->Step_Y0_g);
  dataAddr[326] = (void*) (&BEML_EMU_P->Step_YFinal_i);
  dataAddr[327] = (void*) (&BEML_EMU_P->Step_Time_gl);
  dataAddr[328] = (void*) (&BEML_EMU_P->Step_Y0_o);
  dataAddr[329] = (void*) (&BEML_EMU_P->Step_YFinal_e);
  dataAddr[330] = (void*) (&BEML_EMU_P->Step_Time_e);
  dataAddr[331] = (void*) (&BEML_EMU_P->Step_Y0_c);
  dataAddr[332] = (void*) (&BEML_EMU_P->Step_YFinal_f);
  dataAddr[333] = (void*) (&BEML_EMU_P->Step_Time_b2);
  dataAddr[334] = (void*) (&BEML_EMU_P->Step_Y0_ob);
  dataAddr[335] = (void*) (&BEML_EMU_P->Step_YFinal_im);
  dataAddr[336] = (void*) (&BEML_EMU_P->Step_Time_d);
  dataAddr[337] = (void*) (&BEML_EMU_P->Step_Y0_h);
  dataAddr[338] = (void*) (&BEML_EMU_P->Step_YFinal_iz);
  dataAddr[339] = (void*) (&BEML_EMU_P->VehicleConfigProcessed_Y0);
  dataAddr[340] = (void*) (&BEML_EMU_P->UnitDelay_InitialCondition_g);
  dataAddr[341] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.DetectDecrease_vinit);
  dataAddr[342] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.Constant_Value);
  dataAddr[343] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.Relay_OnVal);
  dataAddr[344] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.Relay_OffVal);
  dataAddr[345] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.Relay_YOn);
  dataAddr[346] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.Relay_YOff);
  dataAddr[347] = (void*) (&BEML_EMU_P->Constant_Value);
  dataAddr[348] = (void*) (&BEML_EMU_P->Constant1_Value);
  dataAddr[349] = (void*) (&BEML_EMU_P->Constant2_Value);
  dataAddr[350] = (void*) (&BEML_EMU_P->DiscreteTimeIntegrator_gainval);
  dataAddr[351] = (void*) (&BEML_EMU_P->DiscreteTimeIntegrator_IC);
  dataAddr[352] = (void*) (&BEML_EMU_P->Switch_Threshold);
  dataAddr[353] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5.Constant1_Value);
  dataAddr[354] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant1_Value);
  dataAddr[355] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0);
  dataAddr[356] = (void*) (&BEML_EMU_P->BrakesVehicleCfg_Y0);
  dataAddr[357] = (void*) (&BEML_EMU_P->CoreSubsys_k.Constant_Value);
  dataAddr[358] = (void*) (&BEML_EMU_P->CoreSubsys_k.Constant1_Value);
  dataAddr[359] = (void*) (&BEML_EMU_P->CoreSubsys_k.Constant2_Value);
  dataAddr[360] = (void*) (&BEML_EMU_P->CoreSubsys_h.Constant_Value);
  dataAddr[361] = (void*) (&BEML_EMU_P->CoreSubsys_i.Constant_Value);
  dataAddr[362] = (void*) (&BEML_EMU_P->CoreSubsys_i.Constant1_Value);
  dataAddr[363] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_e);
  dataAddr[364] = (void*) (&BEML_EMU_P->DoorsConfig_Y0);
  dataAddr[365] = (void*) (&BEML_EMU_P->HasCab_Y0);
  dataAddr[366] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant1_Value_p);
  dataAddr[367] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_m);
  dataAddr[368] = (void*) (&BEML_EMU_P->DynamicsVehicleCfg_Y0);
  dataAddr[369] = (void*) (&BEML_EMU_P->CoreSubsys_ex.Constant_Value);
  dataAddr[370] = (void*) (&BEML_EMU_P->CoreSubsys_ex.Constant1_Value);
  dataAddr[371] = (void*) (&BEML_EMU_P->CoreSubsys_ex.Constant2_Value);
  dataAddr[372] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_f);
  dataAddr[373] = (void*) (&BEML_EMU_P->ElectricalVehicleCfg_Y0);
  dataAddr[374] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant_Value);
  dataAddr[375] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_o);
  dataAddr[376] = (void*) (&BEML_EMU_P->PantographVehicleCfg_Y0);
  dataAddr[377] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant_Value);
  dataAddr[378] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_j);
  dataAddr[379] = (void*) (&BEML_EMU_P->PneumaticsVehicleCfg_Y0);
  dataAddr[380] = (void*) (&BEML_EMU_P->LocationVehicleConfig_Y0);
  dataAddr[381] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant_Value);
  dataAddr[382] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant1_Value);
  dataAddr[383] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_k);
  dataAddr[384] = (void*) (&BEML_EMU_P->TCMSVehicleCfg_Y0);
  dataAddr[385] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant_Value);
  dataAddr[386] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant1_Value);
  dataAddr[387] = (void*) (&BEML_EMU_P->CommonVehicleCfg_Y0_d);
  dataAddr[388] = (void*) (&BEML_EMU_P->TractionVehicleCfg_Y0);
  dataAddr[389] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Difference1_ICPrevInput);
  dataAddr[390] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Difference2_ICPrevInput);
  dataAddr[391] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant_Value);
  dataAddr[392] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant1_Value_n);
  dataAddr[393] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Gain_Gain);
  dataAddr[394] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_e);
  dataAddr[395] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_n);
  dataAddr[396] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_a);
  dataAddr[397] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectChange_vinit);
  dataAddr[398] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectDecrease_vinit);
  dataAddr[399] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectDecrease1_vinit);
  dataAddr[400] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectDecrease2_vinit);
  dataAddr[401] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectIncrease_vinit);
  dataAddr[402] = (void*) (&BEML_EMU_P->CoreSubsys_p.DetectIncrease1_vinit);
  dataAddr[403] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.SRLatchResetPriority_initial_condition);
  dataAddr[404] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.SRLatchResetPriority1_initial_condition);
  dataAddr[405] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_b);
  dataAddr[406] = (void*) (&BEML_EMU_P->CoreSubsys_p.ControlStateFault_FltStVal);
  dataAddr[407] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateFault_NormalStVal);
  dataAddr[408] = (void*) (&BEML_EMU_P->CoreSubsys_p.ControlStateFault1_FltStVal);
  dataAddr[409] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateFault1_NormalStVal);
  dataAddr[410] = (void*) (&BEML_EMU_P->CoreSubsys_p.ControlStateFault2_FltStVal);
  dataAddr[411] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateFault2_NormalStVal);
  dataAddr[412] = (void*) (&BEML_EMU_P->CoreSubsys_p.ControlStateFault3_FltStVal);
  dataAddr[413] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateFault3_NormalStVal);
  dataAddr[414] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.RateTransition1_InitialCondition);
  dataAddr[415] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.RateTransition2_InitialCondition);
  dataAddr[416] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.RateTransition3_InitialCondition);
  dataAddr[417] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.RateTransition4_InitialCondition);
  dataAddr[418] = (void*) (&BEML_EMU_P->CoreSubsys_p.UnitDelay1_InitialCondition);
  dataAddr[419] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_k);
  dataAddr[420] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_i);
  dataAddr[421] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value);
  dataAddr[422] = (void*) (&BEML_EMU_P->CoreSubsys_pna.Constant_Value);
  dataAddr[423] = (void*) (&BEML_EMU_P->CoreSubsys_pna.Constant_Value_l);
  dataAddr[424] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant1_const);
  dataAddr[425] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant2_const);
  dataAddr[426] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant3_const);
  dataAddr[427] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant4_const);
  dataAddr[428] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant5_const);
  dataAddr[429] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CompareToConstant6_const);
  dataAddr[430] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value);
  dataAddr[431] = (void*) (&BEML_EMU_P->Constant_Value_g);
  dataAddr[432] = (void*) (&BEML_EMU_P->Constant1_Value_f);
  dataAddr[433] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvf.CompareToConstant1_const);
  dataAddr[434] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvf.DetectIncrease_vinit);
  dataAddr[435] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.BinarySwitch_value);
  dataAddr[436] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant6_Value);
  dataAddr[437] = (void*) (&BEML_EMU_P->CoreSubsys_h.ATOCommands_Y0);
  dataAddr[438] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant_const);
  dataAddr[439] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant1_const);
  dataAddr[440] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant2_const);
  dataAddr[441] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant3_const);
  dataAddr[442] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant5_const);
  dataAddr[443] = (void*) (&BEML_EMU_P->CoreSubsys_h.CompareToConstant6_const);
  dataAddr[444] = (void*) (&BEML_EMU_P->CoreSubsys_h.RealTarget_Value);
  dataAddr[445] = (void*) (&BEML_EMU_P->CoreSubsys_h.Relay_OnVal);
  dataAddr[446] = (void*) (&BEML_EMU_P->CoreSubsys_h.Relay_OffVal);
  dataAddr[447] = (void*) (&BEML_EMU_P->CoreSubsys_h.Relay_YOn);
  dataAddr[448] = (void*) (&BEML_EMU_P->CoreSubsys_h.Relay_YOff);
  dataAddr[449] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.Ignoreinvalidv_Permitted_UpperSat);
  dataAddr[450] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.Ignoreinvalidv_Permitted_LowerSat);
  dataAddr[451] = (void*) (&BEML_EMU_P->CoreSubsys_h.Min0_UpperSat);
  dataAddr[452] = (void*) (&BEML_EMU_P->CoreSubsys_h.Min0_LowerSat);
  dataAddr[453] = (void*) (&BEML_EMU_P->CoreSubsys_h.ToDMI_Value);
  dataAddr[454] = (void*) (&BEML_EMU_P->CoreSubsys_h.Temp_Fix_Value);
  dataAddr[455] = (void*) (&BEML_EMU_P->CoreSubsys_h.ToElectricalSystem_Value);
  dataAddr[456] = (void*) (&BEML_EMU_P->CoreSubsys_h.ToOnBoardUnit_Value);
  dataAddr[457] = (void*) (&BEML_EMU_P->CoreSubsys_h.ToOnPlatformUnit_Value);
  dataAddr[458] = (void*) (&BEML_EMU_P->CoreSubsys_h.ToTCMSSystem_Value);
  dataAddr[459] = (void*) (&BEML_EMU_P->CoreSubsys_i.CoreSubsys.Constant1_Value);
  dataAddr[460] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant4_Value);
  dataAddr[461] = (void*) (&BEML_EMU_P->CoreSubsys_ex.Constant3_Value);
  dataAddr[462] = (void*) (&BEML_EMU_P->CoreSubsys_ex.CoreSubsys.Constant_Value);
  dataAddr[463] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_c);
  dataAddr[464] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_m);
  dataAddr[465] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_f5);
  dataAddr[466] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value);
  dataAddr[467] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant1_Value);
  dataAddr[468] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_n);
  dataAddr[469] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_b);
  dataAddr[470] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_f);
  dataAddr[471] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_i);
  dataAddr[472] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.Constant3_Value_fi);
  dataAddr[473] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant3_Value_m);
  dataAddr[474] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant3_Value_mr);
  dataAddr[475] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant_Value_g);
  dataAddr[476] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant1_Value_j);
  dataAddr[477] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant3_Value);
  dataAddr[478] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant2_Value);
  dataAddr[479] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant1_Value);
  dataAddr[480] = (void*) (&BEML_EMU_P->CoreSubsys_ls2.Constant3_Value_j);
  dataAddr[481] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant3_Value_d);
  dataAddr[482] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant3_Value_p);
  dataAddr[483] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Gain_Gain);
  dataAddr[484] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Gain1_Gain);
  dataAddr[485] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant1_Value_c);
  dataAddr[486] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant15_Value);
  dataAddr[487] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant16_Value);
  dataAddr[488] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant2_Value);
  dataAddr[489] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant22_Value);
  dataAddr[490] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant23_Value);
  dataAddr[491] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant3_Value);
  dataAddr[492] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant4_Value);
  dataAddr[493] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant5_Value);
  dataAddr[494] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant6_Value);
  dataAddr[495] = (void*) (&BEML_EMU_P->CoreSubsys_i2v.Constant7_Value);
  dataAddr[496] = (void*) (&BEML_EMU_P->CoreSubsys_g.Constant_Value);
  dataAddr[497] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_m);
  dataAddr[498] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_g2);
  dataAddr[499] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Switch_Threshold);
  dataAddr[500] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_hv);
  dataAddr[501] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant_Value_a);
  dataAddr[502] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_j);
  dataAddr[503] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_b);
  dataAddr[504] = (void*) (&BEML_EMU_P->CoreSubsys_gf.DetectDecrease_vinit);
  dataAddr[505] = (void*) (&BEML_EMU_P->CoreSubsys_gf.DetectIncrease_vinit);
  dataAddr[506] = (void*)
    (&BEML_EMU_P->CoreSubsys_gf.SRLatchResetPriority_initial_condition);
  dataAddr[507] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant1_Value_d);
  dataAddr[508] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value);
  dataAddr[509] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_c);
  dataAddr[510] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_js);
  dataAddr[511] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_n);
  dataAddr[512] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_g);
  dataAddr[513] = (void*) (&BEML_EMU_P->CoreSubsys_gf.Constant3_Value_h);
  dataAddr[514] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant_Value_c);
  dataAddr[515] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant_Value_i);
  dataAddr[516] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant3_Value_o);
  dataAddr[517] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant1_Value_ip[0]);
  dataAddr[518] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant3_Value_g);
  dataAddr[519] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant3_Value);
  dataAddr[520] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value);
  dataAddr[521] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_ControlType);
  dataAddr[522] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_Chart_f.Chart_ReturnToNormalState);
  dataAddr[523] = (void*) (&BEML_EMU_P->CoreSubsys_p.UnitDelay_InitialCondition);
  dataAddr[524] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_ControlType_b);
  dataAddr[525] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_Chart_k.Chart_ReturnToNormalState);
  dataAddr[526] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.UnitDelay_InitialCondition_e);
  dataAddr[527] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_ControlType_k);
  dataAddr[528] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_Chart_e.Chart_ReturnToNormalState);
  dataAddr[529] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.UnitDelay_InitialCondition_h);
  dataAddr[530] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_ControlType_l);
  dataAddr[531] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_Chart.Chart_ReturnToNormalState);
  dataAddr[532] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.UnitDelay_InitialCondition_c);
  dataAddr[533] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType);
  dataAddr[534] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_in.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[535] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_in.IRQRequestStateMachine_TriggerContinously);
  dataAddr[536] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_k);
  dataAddr[537] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_m);
  dataAddr[538] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_o);
  dataAddr[539] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_fm.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[540] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_fm.IRQRequestStateMachine_TriggerContinously);
  dataAddr[541] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_j);
  dataAddr[542] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_j);
  dataAddr[543] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_c1);
  dataAddr[544] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_a.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[545] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_a.IRQRequestStateMachine_TriggerContinously);
  dataAddr[546] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_eg);
  dataAddr[547] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_p);
  dataAddr[548] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_f);
  dataAddr[549] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_d.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[550] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_d.IRQRequestStateMachine_TriggerContinously);
  dataAddr[551] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_p);
  dataAddr[552] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_iz);
  dataAddr[553] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_otb);
  dataAddr[554] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_f.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[555] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_f.IRQRequestStateMachine_TriggerContinously);
  dataAddr[556] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_eq);
  dataAddr[557] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_d);
  dataAddr[558] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_h);
  dataAddr[559] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_hr.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[560] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_hr.IRQRequestStateMachine_TriggerContinously);
  dataAddr[561] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_m3);
  dataAddr[562] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_j4);
  dataAddr[563] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_le);
  dataAddr[564] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e5.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[565] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e5.IRQRequestStateMachine_TriggerContinously);
  dataAddr[566] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_l);
  dataAddr[567] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_o);
  dataAddr[568] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_i);
  dataAddr[569] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e2.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[570] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e2.IRQRequestStateMachine_TriggerContinously);
  dataAddr[571] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_bu);
  dataAddr[572] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_ph);
  dataAddr[573] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_cp);
  dataAddr[574] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_i.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[575] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_i.IRQRequestStateMachine_TriggerContinously);
  dataAddr[576] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_f);
  dataAddr[577] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_no);
  dataAddr[578] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_dh);
  dataAddr[579] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_h1.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[580] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_h1.IRQRequestStateMachine_TriggerContinously);
  dataAddr[581] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_bd);
  dataAddr[582] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_gr);
  dataAddr[583] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_p);
  dataAddr[584] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_c.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[585] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_c.IRQRequestStateMachine_TriggerContinously);
  dataAddr[586] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_a);
  dataAddr[587] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_f1);
  dataAddr[588] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_e);
  dataAddr[589] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_j.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[590] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_j.IRQRequestStateMachine_TriggerContinously);
  dataAddr[591] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_o);
  dataAddr[592] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_nk);
  dataAddr[593] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_g);
  dataAddr[594] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_h.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[595] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_h.IRQRequestStateMachine_TriggerContinously);
  dataAddr[596] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_h);
  dataAddr[597] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_f);
  dataAddr[598] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_db);
  dataAddr[599] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_p.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[600] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_p.IRQRequestStateMachine_TriggerContinously);
  dataAddr[601] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_b3);
  dataAddr[602] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_k5);
  dataAddr[603] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_dj);
  dataAddr[604] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_ma.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[605] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_ma.IRQRequestStateMachine_TriggerContinously);
  dataAddr[606] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_ac);
  dataAddr[607] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_h4);
  dataAddr[608] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_n);
  dataAddr[609] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_b.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[610] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_b.IRQRequestStateMachine_TriggerContinously);
  dataAddr[611] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_b);
  dataAddr[612] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_mw);
  dataAddr[613] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_c);
  dataAddr[614] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_o.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[615] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_o.IRQRequestStateMachine_TriggerContinously);
  dataAddr[616] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_e);
  dataAddr[617] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_jy);
  dataAddr[618] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_k);
  dataAddr[619] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_mb.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[620] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_mb.IRQRequestStateMachine_TriggerContinously);
  dataAddr[621] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_kj);
  dataAddr[622] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_g);
  dataAddr[623] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_np);
  dataAddr[624] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_m.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[625] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_m.IRQRequestStateMachine_TriggerContinously);
  dataAddr[626] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_kw);
  dataAddr[627] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_h);
  dataAddr[628] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_l);
  dataAddr[629] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_l.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[630] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_l.IRQRequestStateMachine_TriggerContinously);
  dataAddr[631] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_bp);
  dataAddr[632] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_in);
  dataAddr[633] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_d);
  dataAddr[634] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[635] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine_e.IRQRequestStateMachine_TriggerContinously);
  dataAddr[636] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_ep);
  dataAddr[637] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_jj);
  dataAddr[638] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequestLogic_ControlType_ot);
  dataAddr[639] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine.IRQRequestStateMachine_ReturnToNormalState);
  dataAddr[640] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.sf_IRQRequestStateMachine.IRQRequestStateMachine_TriggerContinously);
  dataAddr[641] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant_Value_m);
  dataAddr[642] = (void*) (&BEML_EMU_P->CoreSubsys_p.Constant1_Value_mc);
  dataAddr[643] = (void*) (&BEML_EMU_P->CoreSubsys_p.CDUCB1_FixMe_Value);
  dataAddr[644] = (void*) (&BEML_EMU_P->CoreSubsys_p.ERCB1_FixMe1_Value);
  dataAddr[645] = (void*) (&BEML_EMU_P->CoreSubsys_p.CRSACB_FixME_Value);
  dataAddr[646] = (void*) (&BEML_EMU_P->CoreSubsys_pna.CoreSubsys.Constant_Value);
  dataAddr[647] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value_a);
  dataAddr[648] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value);
  dataAddr[649] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_IsLeft);
  dataAddr[650] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_NumberOfDoors);
  dataAddr[651] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_IsLeft);
  dataAddr[652] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_NumberOfDoors);
  dataAddr[653] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_IsLeft);
  dataAddr[654] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_NumberOfDoors);
  dataAddr[655] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment4_IsLeft);
  dataAddr[656] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment4_NumberOfDoors);
  dataAddr[657] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasCab);
  dataAddr[658] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMotors);
  dataAddr[659] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPantograph);
  dataAddr[660] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPantoReservoir);
  dataAddr[661] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMainCompressor);
  dataAddr[662] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasCab);
  dataAddr[663] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMotors);
  dataAddr[664] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPantograph);
  dataAddr[665] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPantoReservoir);
  dataAddr[666] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMainCompressor);
  dataAddr[667] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasCab);
  dataAddr[668] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMotors);
  dataAddr[669] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPantograph);
  dataAddr[670] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPantoReservoir);
  dataAddr[671] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMainCompressor);
  dataAddr[672] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasCab);
  dataAddr[673] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMotors);
  dataAddr[674] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPantograph);
  dataAddr[675] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPantoReservoir);
  dataAddr[676] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMainCompressor);
  dataAddr[677] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasCab_p);
  dataAddr[678] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasBogie);
  dataAddr[679] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMotors_n);
  dataAddr[680] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMainCompressor_g);
  dataAddr[681] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMainReservoir);
  dataAddr[682] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPantoReservoir_l);
  dataAddr[683] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasBrakeSystem);
  dataAddr[684] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPneumaticPanto);
  dataAddr[685] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasElectricPanto);
  dataAddr[686] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_NumberOfDoors);
  dataAddr[687] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_NumberOfTractionBogies);
  dataAddr[688] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_NumberOfBrakingBogies);
  dataAddr[689] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasCab_c);
  dataAddr[690] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasBogie);
  dataAddr[691] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMotors_i);
  dataAddr[692] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMainCompressor_n);
  dataAddr[693] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMainReservoir);
  dataAddr[694] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPantoReservoir_d);
  dataAddr[695] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasBrakeSystem);
  dataAddr[696] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPneumaticPanto);
  dataAddr[697] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasElectricPanto);
  dataAddr[698] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_NumberOfDoors_g);
  dataAddr[699] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_NumberOfTractionBogies);
  dataAddr[700] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_NumberOfBrakingBogies);
  dataAddr[701] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasCab_g);
  dataAddr[702] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasBogie);
  dataAddr[703] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMotors_o);
  dataAddr[704] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMainCompressor_h);
  dataAddr[705] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMainReservoir);
  dataAddr[706] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPantoReservoir_d);
  dataAddr[707] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasBrakeSystem);
  dataAddr[708] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPneumaticPanto);
  dataAddr[709] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasElectricPanto);
  dataAddr[710] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_NumberOfDoors_i);
  dataAddr[711] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_NumberOfTractionBogies);
  dataAddr[712] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_NumberOfBrakingBogies);
  dataAddr[713] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasCab_l);
  dataAddr[714] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasBogie);
  dataAddr[715] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMotors_n);
  dataAddr[716] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMainCompressor_e);
  dataAddr[717] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMainReservoir);
  dataAddr[718] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPantoReservoir_p);
  dataAddr[719] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasBrakeSystem);
  dataAddr[720] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPneumaticPanto);
  dataAddr[721] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasElectricPanto);
  dataAddr[722] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_NumberOfDoors_i);
  dataAddr[723] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_NumberOfTractionBogies);
  dataAddr[724] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_NumberOfBrakingBogies);
  dataAddr[725] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPanto);
  dataAddr[726] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_PenumaticsPoweredPanto);
  dataAddr[727] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_ElectricPoweredPanto);
  dataAddr[728] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPanto);
  dataAddr[729] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_PenumaticsPoweredPanto);
  dataAddr[730] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_ElectricPoweredPanto);
  dataAddr[731] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPanto);
  dataAddr[732] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_PenumaticsPoweredPanto);
  dataAddr[733] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_ElectricPoweredPanto);
  dataAddr[734] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPanto);
  dataAddr[735] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_PenumaticsPoweredPanto);
  dataAddr[736] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_ElectricPoweredPanto);
  dataAddr[737] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasCab_d);
  dataAddr[738] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasBogie_m);
  dataAddr[739] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasPantograph_e);
  dataAddr[740] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasCompressor);
  dataAddr[741] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMainReservoir_d);
  dataAddr[742] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasBrakeSystem_e);
  dataAddr[743] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasCab_l);
  dataAddr[744] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasBogie_d);
  dataAddr[745] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasPantograph_a);
  dataAddr[746] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasCompressor);
  dataAddr[747] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMainReservoir_c);
  dataAddr[748] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasBrakeSystem_o);
  dataAddr[749] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasCab_b);
  dataAddr[750] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasBogie_k);
  dataAddr[751] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasPantograph_p);
  dataAddr[752] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasCompressor);
  dataAddr[753] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMainReservoir_m);
  dataAddr[754] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasBrakeSystem_j);
  dataAddr[755] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasCab_c);
  dataAddr[756] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasBogie_l);
  dataAddr[757] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasPantograph_n);
  dataAddr[758] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasCompressor);
  dataAddr[759] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMainReservoir_f);
  dataAddr[760] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasBrakeSystem_n);
  dataAddr[761] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_HasMotors_j);
  dataAddr[762] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_HasMotors_a);
  dataAddr[763] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_HasMotors_d);
  dataAddr[764] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_HasMotors_k);
  dataAddr[765] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value_o);
  dataAddr[766] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value);
  dataAddr[767] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value_c);
  dataAddr[768] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant12_Value);
  dataAddr[769] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant2_Value);
  dataAddr[770] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant5_Value);
  dataAddr[771] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value_c);
  dataAddr[772] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant7_Value);
  dataAddr[773] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant8_Value);
  dataAddr[774] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant9_Value);
  dataAddr[775] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.UseDavisCoeff_Value);
  dataAddr[776] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value_g);
  dataAddr[777] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant_Value);
  dataAddr[778] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant10_Value);
  dataAddr[779] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant5_Value);
  dataAddr[780] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant5_Value_h);
  dataAddr[781] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant2_Value
    [0]);
  dataAddr[782] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant3_Value
    [0]);
  dataAddr[783] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant7_Value);
  dataAddr[784] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.LateralVelocity_Value);
  dataAddr[785] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.VerticalAcceleration_Value);
  dataAddr[786] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.VerticalVelocity_Value);
  dataAddr[787] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.DiscreteTimeIntegrator_gainval);
  dataAddr[788] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.DiscreteTimeIntegrator_IC);
  dataAddr[789] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch1_Threshold);
  dataAddr[790] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.BrakeDemandPIDController_InitialConditionForIntegrator);
  dataAddr[791] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.BrakeDemandPIDController_DifferentiatorICPrevScaledInput);
  dataAddr[792] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.BrakeDemandPIDController_UpperSaturationLimit);
  dataAddr[793] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.BrakeDemandPIDController_LowerSaturationLimit);
  dataAddr[794] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.TractiveDemand_InitialConditionForIntegrator);
  dataAddr[795] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.TractiveDemand_DifferentiatorICPrevScaledInput);
  dataAddr[796] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.TractiveDemand_UpperSaturationLimit);
  dataAddr[797] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.TractiveDemand_LowerSaturationLimit);
  dataAddr[798] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.BrakeWhenClosetoStoppingPoint.Constant_Value);
  dataAddr[799] = (void*) (&BEML_EMU_P->CoreSubsys_h.Coasting.Constant_Value);
  dataAddr[800] = (void*) (&BEML_EMU_P->CoreSubsys_h.NotInATO.Constant_Value);
  dataAddr[801] = (void*) (&BEML_EMU_P->CoreSubsys_h.ATB_Value);
  dataAddr[802] = (void*) (&BEML_EMU_P->CoreSubsys_h.ATO_Value);
  dataAddr[803] = (void*) (&BEML_EMU_P->CoreSubsys_h.ATP_Value);
  dataAddr[804] = (void*) (&BEML_EMU_P->CoreSubsys_h.Off_Value);
  dataAddr[805] = (void*) (&BEML_EMU_P->CoreSubsys_h.RMF_Value);
  dataAddr[806] = (void*) (&BEML_EMU_P->CoreSubsys_h.RMR_Value);
  dataAddr[807] = (void*) (&BEML_EMU_P->CoreSubsys_h.ROS_Value);
  dataAddr[808] = (void*) (&BEML_EMU_P->CoreSubsys_h.UTO_Value);
  dataAddr[809] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.SRLatchResetPriority_initial_condition);
  dataAddr[810] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.SRLatchResetPriority1_initial_condition);
  dataAddr[811] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.SRLatchResetPriority2_initial_condition);
  dataAddr[812] = (void*)
    (&BEML_EMU_P->CoreSubsys_h.SRLatchResetPriority3_initial_condition);
  dataAddr[813] = (void*) (&BEML_EMU_P->CoreSubsys_h.UnitDelay_InitialCondition);
  dataAddr[814] = (void*) (&BEML_EMU_P->CoreSubsys_h.UnitDelay1_InitialCondition);
  dataAddr[815] = (void*) (&BEML_EMU_P->CoreSubsys_h.UnitDelay2_InitialCondition);
  dataAddr[816] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DL1_isLeft);
  dataAddr[817] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DL2_isLeft);
  dataAddr[818] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DL3_isLeft);
  dataAddr[819] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DL4_isLeft);
  dataAddr[820] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DR1_isLeft);
  dataAddr[821] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DR2_isLeft);
  dataAddr[822] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DR3_isLeft);
  dataAddr[823] = (void*) (&BEML_EMU_P->CoreSubsys_lb.DR4_isLeft);
  dataAddr[824] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant1_Value_n);
  dataAddr[825] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant2_Value);
  dataAddr[826] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant3_Value);
  dataAddr[827] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant4_Value_m);
  dataAddr[828] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant5_Value);
  dataAddr[829] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant6_Value);
  dataAddr[830] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant7_Value);
  dataAddr[831] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant8_Value);
  dataAddr[832] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Constant1_Value);
  dataAddr[833] = (void*) (&BEML_EMU_P->CoreSubsys_ij1.DetectIncrease1_vinit);
  dataAddr[834] = (void*)
    (&BEML_EMU_P->CoreSubsys_ij1.SRLatchResetPriority1_initial_condition);
  dataAddr[835] = (void*)
    (&BEML_EMU_P->CoreSubsys_i2v.CoreSubsys_i.Constant3_Value);
  dataAddr[836] = (void*)
    (&BEML_EMU_P->CoreSubsys_gf.CoreSubsys_gfy.Constant3_Value);
  dataAddr[837] = (void*)
    (&BEML_EMU_P->CoreSubsys_gf.CoreSubsys_gf.Constant3_Value);
  dataAddr[838] = (void*)
    (&BEML_EMU_P->CoreSubsys_gf.CoreSubsys_g.Constant3_Value);
  dataAddr[839] = (void*)
    (&BEML_EMU_P->CoreSubsys_cr.CoreSubsys_cr.Constant1_Value);
  dataAddr[840] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.ControlStateRq_Y0);
  dataAddr[841] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.Complete_Y0);
  dataAddr[842] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.Increment_const);
  dataAddr[843] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.Momentary_const);
  dataAddr[844] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.ControlStateRq_Y0);
  dataAddr[845] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.Complete_Y0);
  dataAddr[846] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.Increment_const);
  dataAddr[847] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.Momentary_const);
  dataAddr[848] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.ControlStateRq_Y0);
  dataAddr[849] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.Complete_Y0);
  dataAddr[850] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.Increment_const);
  dataAddr[851] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.Momentary_const);
  dataAddr[852] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.ControlStateRq_Y0);
  dataAddr[853] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.Complete_Y0);
  dataAddr[854] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.Increment_const);
  dataAddr[855] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.Momentary_const);
  dataAddr[856] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const);
  dataAddr[857] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const);
  dataAddr[858] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_b);
  dataAddr[859] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_g);
  dataAddr[860] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_l);
  dataAddr[861] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_p);
  dataAddr[862] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_m4);
  dataAddr[863] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_cn);
  dataAddr[864] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_e);
  dataAddr[865] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_k);
  dataAddr[866] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_ex);
  dataAddr[867] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_i);
  dataAddr[868] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_k);
  dataAddr[869] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_b);
  dataAddr[870] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_f);
  dataAddr[871] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_m);
  dataAddr[872] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_lv);
  dataAddr[873] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_n);
  dataAddr[874] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_hk);
  dataAddr[875] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_gc);
  dataAddr[876] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_g);
  dataAddr[877] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_h);
  dataAddr[878] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_p);
  dataAddr[879] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_b4);
  dataAddr[880] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_m);
  dataAddr[881] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_f);
  dataAddr[882] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_ik);
  dataAddr[883] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_ah);
  dataAddr[884] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_pd);
  dataAddr[885] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_pg);
  dataAddr[886] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_a);
  dataAddr[887] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_a);
  dataAddr[888] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_d);
  dataAddr[889] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_d);
  dataAddr[890] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_c);
  dataAddr[891] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_c);
  dataAddr[892] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_i);
  dataAddr[893] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_o);
  dataAddr[894] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_ah);
  dataAddr[895] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_ob);
  dataAddr[896] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_i0);
  dataAddr[897] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_l);
  dataAddr[898] = (void*) (&BEML_EMU_P->CoreSubsys_p.Increment_const_h);
  dataAddr[899] = (void*) (&BEML_EMU_P->CoreSubsys_p.Momentary_const_j);
  dataAddr[900] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_n.Constant6_Value);
  dataAddr[901] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_f.Constant6_Value);
  dataAddr[902] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_o.Constant6_Value);
  dataAddr[903] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment4.Constant6_Value);
  dataAddr[904] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value_e);
  dataAddr[905] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value_l);
  dataAddr[906] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value_j);
  dataAddr[907] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant6_Value_i);
  dataAddr[908] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_o.Constant6_Value);
  dataAddr[909] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_m.Constant6_Value);
  dataAddr[910] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_m.Constant6_Value);
  dataAddr[911] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_ly.Constant6_Value);
  dataAddr[912] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_g.Constant6_Value);
  dataAddr[913] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_a.Constant6_Value);
  dataAddr[914] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_h.Constant6_Value);
  dataAddr[915] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_l.Constant6_Value);
  dataAddr[916] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment_c.Constant6_Value);
  dataAddr[917] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1_c.Constant6_Value);
  dataAddr[918] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2_n.Constant6_Value);
  dataAddr[919] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3_f.Constant6_Value);
  dataAddr[920] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment.Constant6_Value);
  dataAddr[921] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment1.Constant6_Value);
  dataAddr[922] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment2.Constant6_Value);
  dataAddr[923] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnae.VehicleEquipment3.Constant6_Value);
  dataAddr[924] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_n);
  dataAddr[925] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant1_Value_l);
  dataAddr[926] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant_const);
  dataAddr[927] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant1_const);
  dataAddr[928] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant2_const);
  dataAddr[929] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant4_const);
  dataAddr[930] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant5_const);
  dataAddr[931] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant8_const);
  dataAddr[932] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.CompareToConstant9_const);
  dataAddr[933] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpg.CoreSubsys.DiscreteTimeIntegrator_gainval);
  dataAddr[934] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpg.CoreSubsys.DiscreteTimeIntegrator_IC);
  dataAddr[935] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpg.CoreSubsys.DiscreteTimeIntegrator1_gainval);
  dataAddr[936] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpg.CoreSubsys.DiscreteTimeIntegrator1_IC);
  dataAddr[937] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant8_Value);
  dataAddr[938] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Roll_Value);
  dataAddr[939] = (void*) (&BEML_EMU_P->CoreSubsys_m.InitMotionBaseOut_Value);
  dataAddr[940] = (void*) (&BEML_EMU_P->CoreSubsys_m.InitMotionBaseOut1_Value);
  dataAddr[941] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SafeGravitationalAcceleration_Value[0]);
  dataAddr[942] = (void*) (&BEML_EMU_P->CoreSubsys_m.SafeRotationMatrix_Value[0]);
  dataAddr[943] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain);
  dataAddr[944] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_g);
  dataAddr[945] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_n);
  dataAddr[946] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_gx);
  dataAddr[947] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_ng);
  dataAddr[948] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_h);
  dataAddr[949] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_o);
  dataAddr[950] = (void*) (&BEML_EMU_P->CoreSubsys_lb.Gain_Gain_j);
  dataAddr[951] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_g);
  dataAddr[952] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_m);
  dataAddr[953] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_i);
  dataAddr[954] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_b);
  dataAddr[955] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_l);
  dataAddr[956] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_m);
  dataAddr[957] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_e);
  dataAddr[958] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_d);
  dataAddr[959] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_i);
  dataAddr[960] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_l);
  dataAddr[961] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_k);
  dataAddr[962] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_h);
  dataAddr[963] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_g);
  dataAddr[964] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_i);
  dataAddr[965] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_o);
  dataAddr[966] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_f);
  dataAddr[967] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_iz);
  dataAddr[968] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_kp);
  dataAddr[969] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_m);
  dataAddr[970] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_j);
  dataAddr[971] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_ac);
  dataAddr[972] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_b4);
  dataAddr[973] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_d);
  dataAddr[974] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_dk);
  dataAddr[975] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_e);
  dataAddr[976] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_d);
  dataAddr[977] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_d);
  dataAddr[978] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_jr);
  dataAddr[979] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_i);
  dataAddr[980] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_n);
  dataAddr[981] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_i);
  dataAddr[982] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_ku);
  dataAddr[983] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_ie);
  dataAddr[984] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_jh);
  dataAddr[985] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_hc);
  dataAddr[986] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_p);
  dataAddr[987] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_k);
  dataAddr[988] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_k2);
  dataAddr[989] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_h);
  dataAddr[990] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_j);
  dataAddr[991] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_lp);
  dataAddr[992] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_ia);
  dataAddr[993] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_l);
  dataAddr[994] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_a);
  dataAddr[995] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_b);
  dataAddr[996] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_it);
  dataAddr[997] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_ji);
  dataAddr[998] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_kn);
  dataAddr[999] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const);
  dataAddr[1000] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const);
  dataAddr[1001] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const);
  dataAddr[1002] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const);
  dataAddr[1003] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const);
  dataAddr[1004] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const);
  dataAddr[1005] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const);
  dataAddr[1006] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const);
  dataAddr[1007] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_o);
  dataAddr[1008] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_i);
  dataAddr[1009] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_f);
  dataAddr[1010] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_l);
  dataAddr[1011] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_f);
  dataAddr[1012] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_f);
  dataAddr[1013] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_a);
  dataAddr[1014] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_g);
  dataAddr[1015] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_p);
  dataAddr[1016] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_f);
  dataAddr[1017] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_b);
  dataAddr[1018] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_f);
  dataAddr[1019] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_e);
  dataAddr[1020] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_a);
  dataAddr[1021] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_c);
  dataAddr[1022] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_o);
  dataAddr[1023] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_a);
  dataAddr[1024] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_k);
  dataAddr[1025] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_p);
  dataAddr[1026] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_n);
  dataAddr[1027] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_fh);
  dataAddr[1028] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_d);
  dataAddr[1029] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_b);
  dataAddr[1030] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_i);
  dataAddr[1031] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_k);
  dataAddr[1032] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_kw);
  dataAddr[1033] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_ko);
  dataAddr[1034] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_m);
  dataAddr[1035] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_et);
  dataAddr[1036] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_k);
  dataAddr[1037] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_cp);
  dataAddr[1038] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_gl);
  dataAddr[1039] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_l);
  dataAddr[1040] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_j);
  dataAddr[1041] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_a);
  dataAddr[1042] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_fo);
  dataAddr[1043] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_ep);
  dataAddr[1044] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_b);
  dataAddr[1045] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_j);
  dataAddr[1046] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_b);
  dataAddr[1047] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_j);
  dataAddr[1048] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_m0);
  dataAddr[1049] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_al);
  dataAddr[1050] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_hm);
  dataAddr[1051] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_j);
  dataAddr[1052] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_dd);
  dataAddr[1053] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_jq);
  dataAddr[1054] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_m);
  dataAddr[1055] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_pj);
  dataAddr[1056] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_f1);
  dataAddr[1057] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_h);
  dataAddr[1058] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_nv);
  dataAddr[1059] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_a);
  dataAddr[1060] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_p);
  dataAddr[1061] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_l);
  dataAddr[1062] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_e);
  dataAddr[1063] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_f);
  dataAddr[1064] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_e);
  dataAddr[1065] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_kq);
  dataAddr[1066] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_ls);
  dataAddr[1067] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_gs);
  dataAddr[1068] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_ft);
  dataAddr[1069] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_g);
  dataAddr[1070] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_k);
  dataAddr[1071] = (void*) (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant_const_m);
  dataAddr[1072] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant1_const_h);
  dataAddr[1073] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant2_const_g);
  dataAddr[1074] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant3_const_lm);
  dataAddr[1075] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant4_const_d);
  dataAddr[1076] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant5_const_l);
  dataAddr[1077] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant6_const_ch);
  dataAddr[1078] = (void*)
    (&BEML_EMU_P->CoreSubsys_lb.CompareToConstant7_const_kl);
  dataAddr[1079] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant1_Value);
  dataAddr[1080] = (void*) (&BEML_EMU_P->CoreSubsys_cr.Constant1_Value_i);
  dataAddr[1081] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.DiscreteTimeIntegrator_gainval);
  dataAddr[1082] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.DiscreteTimeIntegrator_IC);
  dataAddr[1083] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.PulseGenerator_Amp);
  dataAddr[1084] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.PulseGenerator_Period);
  dataAddr[1085] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.PulseGenerator_Duty);
  dataAddr[1086] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.PulseGenerator_PhaseDelay);
  dataAddr[1087] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_a.WeightedSampleTime_WtEt);
  dataAddr[1088] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.DiscreteTimeIntegrator_gainval);
  dataAddr[1089] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.DiscreteTimeIntegrator_IC);
  dataAddr[1090] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.PulseGenerator_Amp);
  dataAddr[1091] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.PulseGenerator_Period);
  dataAddr[1092] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.PulseGenerator_Duty);
  dataAddr[1093] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.PulseGenerator_PhaseDelay);
  dataAddr[1094] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_n.WeightedSampleTime_WtEt);
  dataAddr[1095] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.DiscreteTimeIntegrator_gainval);
  dataAddr[1096] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.DiscreteTimeIntegrator_IC);
  dataAddr[1097] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.PulseGenerator_Amp);
  dataAddr[1098] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.PulseGenerator_Period);
  dataAddr[1099] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.PulseGenerator_Duty);
  dataAddr[1100] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.PulseGenerator_PhaseDelay);
  dataAddr[1101] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest_i.WeightedSampleTime_WtEt);
  dataAddr[1102] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.DiscreteTimeIntegrator_gainval);
  dataAddr[1103] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.DiscreteTimeIntegrator_IC);
  dataAddr[1104] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.PulseGenerator_Amp);
  dataAddr[1105] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.PulseGenerator_Period);
  dataAddr[1106] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.PulseGenerator_Duty);
  dataAddr[1107] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.PulseGenerator_PhaseDelay);
  dataAddr[1108] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.ControlStateRequest.WeightedSampleTime_WtEt);
  dataAddr[1109] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval);
  dataAddr[1110] = (void*) (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC);
  dataAddr[1111] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp);
  dataAddr[1112] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period);
  dataAddr[1113] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty);
  dataAddr[1114] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay);
  dataAddr[1115] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_o);
  dataAddr[1116] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_n);
  dataAddr[1117] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_e);
  dataAddr[1118] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_l);
  dataAddr[1119] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_m);
  dataAddr[1120] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_h);
  dataAddr[1121] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_l);
  dataAddr[1122] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_f);
  dataAddr[1123] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_f);
  dataAddr[1124] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_c);
  dataAddr[1125] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_eb);
  dataAddr[1126] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_d);
  dataAddr[1127] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_m);
  dataAddr[1128] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_e);
  dataAddr[1129] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_h4);
  dataAddr[1130] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_f);
  dataAddr[1131] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_ir);
  dataAddr[1132] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_n);
  dataAddr[1133] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_ds);
  dataAddr[1134] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_b);
  dataAddr[1135] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_lv);
  dataAddr[1136] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_jm);
  dataAddr[1137] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_b2);
  dataAddr[1138] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_it);
  dataAddr[1139] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_g3);
  dataAddr[1140] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_h);
  dataAddr[1141] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_d);
  dataAddr[1142] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_km);
  dataAddr[1143] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_km);
  dataAddr[1144] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_bz);
  dataAddr[1145] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_d4);
  dataAddr[1146] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_p);
  dataAddr[1147] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_hk);
  dataAddr[1148] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_cz);
  dataAddr[1149] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_ck);
  dataAddr[1150] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_k);
  dataAddr[1151] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_gz);
  dataAddr[1152] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_ln);
  dataAddr[1153] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_ly);
  dataAddr[1154] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_jo);
  dataAddr[1155] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_n);
  dataAddr[1156] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_ic);
  dataAddr[1157] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_e);
  dataAddr[1158] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_nl);
  dataAddr[1159] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_c);
  dataAddr[1160] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_b);
  dataAddr[1161] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_kk);
  dataAddr[1162] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_o);
  dataAddr[1163] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_f);
  dataAddr[1164] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_m);
  dataAddr[1165] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_oa);
  dataAddr[1166] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_f5);
  dataAddr[1167] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_o);
  dataAddr[1168] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_e);
  dataAddr[1169] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_fb);
  dataAddr[1170] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_np);
  dataAddr[1171] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_cd);
  dataAddr[1172] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_e);
  dataAddr[1173] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_f);
  dataAddr[1174] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_hf);
  dataAddr[1175] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_p);
  dataAddr[1176] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_po);
  dataAddr[1177] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_ah);
  dataAddr[1178] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_kh);
  dataAddr[1179] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_a);
  dataAddr[1180] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_n5);
  dataAddr[1181] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_g);
  dataAddr[1182] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_k);
  dataAddr[1183] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_o);
  dataAddr[1184] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_k);
  dataAddr[1185] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_mt);
  dataAddr[1186] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_m);
  dataAddr[1187] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_n4);
  dataAddr[1188] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_j2);
  dataAddr[1189] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_dp);
  dataAddr[1190] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_kx);
  dataAddr[1191] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_j);
  dataAddr[1192] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_c);
  dataAddr[1193] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_oo);
  dataAddr[1194] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_be);
  dataAddr[1195] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_n);
  dataAddr[1196] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_ld);
  dataAddr[1197] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_d);
  dataAddr[1198] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_a);
  dataAddr[1199] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_n);
  dataAddr[1200] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_no);
  dataAddr[1201] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_m);
  dataAddr[1202] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_d);
  dataAddr[1203] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_k);
  dataAddr[1204] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_f);
  dataAddr[1205] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_d);
  dataAddr[1206] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_c);
  dataAddr[1207] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_b);
  dataAddr[1208] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_a);
  dataAddr[1209] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_g);
  dataAddr[1210] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_b);
  dataAddr[1211] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_h);
  dataAddr[1212] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_ca);
  dataAddr[1213] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_a);
  dataAddr[1214] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_n);
  dataAddr[1215] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_c);
  dataAddr[1216] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_i);
  dataAddr[1217] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_hb);
  dataAddr[1218] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_l);
  dataAddr[1219] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_az);
  dataAddr[1220] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_dh);
  dataAddr[1221] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_i);
  dataAddr[1222] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_hv);
  dataAddr[1223] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_hc);
  dataAddr[1224] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_n2);
  dataAddr[1225] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_h);
  dataAddr[1226] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_m);
  dataAddr[1227] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_ih);
  dataAddr[1228] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_l);
  dataAddr[1229] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_k);
  dataAddr[1230] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_c4);
  dataAddr[1231] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_a1);
  dataAddr[1232] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_j);
  dataAddr[1233] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_b);
  dataAddr[1234] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_g);
  dataAddr[1235] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_gainval_j);
  dataAddr[1236] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.DiscreteTimeIntegrator_IC_j);
  dataAddr[1237] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Amp_l);
  dataAddr[1238] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Period_p);
  dataAddr[1239] = (void*) (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_Duty_e);
  dataAddr[1240] = (void*)
    (&BEML_EMU_P->CoreSubsys_p.PulseGenerator_PhaseDelay_iz);
  dataAddr[1241] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_e);
  dataAddr[1242] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_eu);
  dataAddr[1243] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_o);
  dataAddr[1244] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_c);
  dataAddr[1245] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_d);
  dataAddr[1246] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_oq);
  dataAddr[1247] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_l);
  dataAddr[1248] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_f);
  dataAddr[1249] = (void*) (&BEML_EMU_P->CoreSubsys_pnae.Constant_Value_p);
  dataAddr[1250] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.GravitationalAcceleration_Value[0]);
  dataAddr[1251] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.ManualOrientationAdjustment_Value[0]);
  dataAddr[1252] = (void*) (&BEML_EMU_P->CoreSubsys_m.Above20Degrees_const);
  dataAddr[1253] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.UnitDelay1_InitialCondition);
  dataAddr[1254] = (void*) (&BEML_EMU_P->CoreSubsys_m.DeadZone_Start);
  dataAddr[1255] = (void*) (&BEML_EMU_P->CoreSubsys_m.DeadZone_End);
  dataAddr[1256] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant_Value_c[0]);
  dataAddr[1257] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Gain_Gain[0]);
  dataAddr[1258] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Gain2_Gain[0]);
  dataAddr[1259] = (void*)
    (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Constant1_Value_p[0]);
  dataAddr[1260] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Gain1_Gain[0]);
  dataAddr[1261] = (void*) (&BEML_EMU_P->CoreSubsys_pnaevvfpgh5z.Gain3_Gain[0]);
  dataAddr[1262] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt_JoltProfile[0]);
  dataAddr[1263] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt_JoltBreakPoints[0]);
  dataAddr[1264] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt1_JoltProfile[0]);
  dataAddr[1265] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt1_JoltBreakPoints[0]);
  dataAddr[1266] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt2_JoltProfile[0]);
  dataAddr[1267] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt2_JoltBreakPoints[0]);
  dataAddr[1268] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt3_JoltProfile[0]);
  dataAddr[1269] = (void*) (&BEML_EMU_P->CoreSubsys_m.Jolt3_JoltBreakPoints[0]);
  dataAddr[1270] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_o);
  dataAddr[1271] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain1_Gain_d);
  dataAddr[1272] = (void*) (&BEML_EMU_P->CoreSubsys_m.Merge_InitialOutput);
  dataAddr[1273] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_DefaultValue_p);
  dataAddr[1274] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_Threshold_l);
  dataAddr[1275] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_DefaultValue_k);
  dataAddr[1276] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_Threshold_k);
  dataAddr[1277] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_d);
  dataAddr[1278] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_tableData_a
    [0]);
  dataAddr[1279] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_bp01Data_im
    [0]);
  dataAddr[1280] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_DefaultValue_l);
  dataAddr[1281] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_Threshold_d);
  dataAddr[1282] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_DefaultValue_g);
  dataAddr[1283] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_Threshold_a);
  dataAddr[1284] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_gb);
  dataAddr[1285] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_tableData_d
    [0]);
  dataAddr[1286] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_bp01Data_i[0]);
  dataAddr[1287] = (void*) (&BEML_EMU_P->CoreSubsys_m.CollisionGainReset_Value);
  dataAddr[1288] = (void*) (&BEML_EMU_P->CoreSubsys_m.RampRate_Value);
  dataAddr[1289] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_j);
  dataAddr[1290] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_UpperSat_i);
  dataAddr[1291] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_LowerSat_c);
  dataAddr[1292] = (void*) (&BEML_EMU_P->CoreSubsys_m.IC_Value_p);
  dataAddr[1293] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_DefaultValue_k);
  dataAddr[1294] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_Threshold_a);
  dataAddr[1295] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_DefaultValue_n);
  dataAddr[1296] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_Threshold_p);
  dataAddr[1297] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_e);
  dataAddr[1298] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_DefaultValue);
  dataAddr[1299] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.LPFConstantTuning_Threshold);
  dataAddr[1300] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_DefaultValue);
  dataAddr[1301] = (void*) (&BEML_EMU_P->CoreSubsys_m.SaturationTuning_Threshold);
  dataAddr[1302] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_a);
  dataAddr[1303] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_tableData[0]);
  dataAddr[1304] = (void*) (&BEML_EMU_P->CoreSubsys_m.uDLookupTable_bp01Data[0]);
  dataAddr[1305] = (void*) (&BEML_EMU_P->CoreSubsys_h.TSamp_WtEt);
  dataAddr[1306] = (void*) (&BEML_EMU_P->CoreSubsys_h.Integrator_gainval);
  dataAddr[1307] = (void*) (&BEML_EMU_P->CoreSubsys_h.TSamp_WtEt_e);
  dataAddr[1308] = (void*) (&BEML_EMU_P->CoreSubsys_h.Integrator_gainval_i);
  dataAddr[1309] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit_ps);
  dataAddr[1310] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_k);
  dataAddr[1311] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC_i);
  dataAddr[1312] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit_px);
  dataAddr[1313] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_m);
  dataAddr[1314] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC_p);
  dataAddr[1315] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit_o);
  dataAddr[1316] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_p3);
  dataAddr[1317] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC_a);
  dataAddr[1318] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit_k);
  dataAddr[1319] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_g);
  dataAddr[1320] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC_k);
  dataAddr[1321] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DegradedRoughnessGenerator_SpeedSaturation);
  dataAddr[1322] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_n);
  dataAddr[1323] = (void*) (&BEML_EMU_P->CoreSubsys_m.Zeros_Value_b[0]);
  dataAddr[1324] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_mf);
  dataAddr[1325] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_cc);
  dataAddr[1326] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant2_Value_ht);
  dataAddr[1327] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch_Threshold_cy);
  dataAddr[1328] = (void*) (&BEML_EMU_P->CoreSubsys_m.Zeros_Value_p[0]);
  dataAddr[1329] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.StandardRoughnessGenerator_SpeedSaturation);
  dataAddr[1330] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_b);
  dataAddr[1331] = (void*) (&BEML_EMU_P->CoreSubsys_m.Zeros_Value[0]);
  dataAddr[1332] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_m);
  dataAddr[1333] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_fm);
  dataAddr[1334] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_cl);
  dataAddr[1335] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_js);
  dataAddr[1336] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_m);
  dataAddr[1337] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_f);
  dataAddr[1338] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_nh);
  dataAddr[1339] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_ae);
  dataAddr[1340] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_a);
  dataAddr[1341] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_a1);
  dataAddr[1342] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_h);
  dataAddr[1343] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_gw);
  dataAddr[1344] = (void*) (&BEML_EMU_P->CoreSubsys_m.Initialise_Value);
  dataAddr[1345] = (void*) (&BEML_EMU_P->CoreSubsys_m.OffTime_Value);
  dataAddr[1346] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval);
  dataAddr[1347] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_UpperSat);
  dataAddr[1348] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_LowerSat);
  dataAddr[1349] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain);
  dataAddr[1350] = (void*) (&BEML_EMU_P->CoreSubsys_m.IC_Value);
  dataAddr[1351] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_h);
  dataAddr[1352] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_eq);
  dataAddr[1353] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_d3);
  dataAddr[1354] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_l3);
  dataAddr[1355] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_a);
  dataAddr[1356] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_mk);
  dataAddr[1357] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_jf);
  dataAddr[1358] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_c);
  dataAddr[1359] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_e);
  dataAddr[1360] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_nl);
  dataAddr[1361] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_g5);
  dataAddr[1362] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_m);
  dataAddr[1363] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.Initialise_Value);
  dataAddr[1364] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.OffTime_Value);
  dataAddr[1365] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.DiscreteTimeIntegrator_gainval);
  dataAddr[1366] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.DiscreteTimeIntegrator_UpperSat);
  dataAddr[1367] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.DiscreteTimeIntegrator_LowerSat);
  dataAddr[1368] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.Gain_Gain);
  dataAddr[1369] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.IC_Value);
  dataAddr[1370] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.Initialise_Value);
  dataAddr[1371] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.OffTime_Value);
  dataAddr[1372] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.DiscreteTimeIntegrator_gainval);
  dataAddr[1373] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.DiscreteTimeIntegrator_UpperSat);
  dataAddr[1374] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.DiscreteTimeIntegrator_LowerSat);
  dataAddr[1375] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.Gain_Gain);
  dataAddr[1376] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.IC_Value);
  dataAddr[1377] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.Initialise_Value);
  dataAddr[1378] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.OffTime_Value);
  dataAddr[1379] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.DiscreteTimeIntegrator_gainval);
  dataAddr[1380] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.DiscreteTimeIntegrator_UpperSat);
  dataAddr[1381] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.DiscreteTimeIntegrator_LowerSat);
  dataAddr[1382] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.Gain_Gain);
  dataAddr[1383] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.IC_Value);
  dataAddr[1384] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration.Initialise_Value);
  dataAddr[1385] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration.OffTime_Value);
  dataAddr[1386] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration.DiscreteTimeIntegrator_gainval);
  dataAddr[1387] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration.DiscreteTimeIntegrator_UpperSat);
  dataAddr[1388] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration.DiscreteTimeIntegrator_LowerSat);
  dataAddr[1389] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration.Gain_Gain);
  dataAddr[1390] = (void*) (&BEML_EMU_P->CoreSubsys_m.JoltDuration.IC_Value);
  dataAddr[1391] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise_Cov_c);
  dataAddr[1392] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise_seed_f);
  dataAddr[1393] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise1_Cov_o);
  dataAddr[1394] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise1_seed_l);
  dataAddr[1395] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SampleandHold_InitialCondition_e);
  dataAddr[1396] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant2_Value);
  dataAddr[1397] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant6_Value_p);
  dataAddr[1398] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Amp_e);
  dataAddr[1399] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Period_c);
  dataAddr[1400] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Duty_p);
  dataAddr[1401] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_PhaseDelay_j);
  dataAddr[1402] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_m);
  dataAddr[1403] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain1_Gain_j);
  dataAddr[1404] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch4_Threshold_a);
  dataAddr[1405] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_lv);
  dataAddr[1406] = (void*) (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise_Cov);
  dataAddr[1407] = (void*) (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise_seed);
  dataAddr[1408] = (void*) (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise1_Cov);
  dataAddr[1409] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.BandLimitedWhiteNoise1_seed);
  dataAddr[1410] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.SampleandHold_InitialCondition);
  dataAddr[1411] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant3_Value);
  dataAddr[1412] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant6_Value);
  dataAddr[1413] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator1_Amp);
  dataAddr[1414] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator1_Period);
  dataAddr[1415] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator1_Duty);
  dataAddr[1416] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator1_PhaseDelay);
  dataAddr[1417] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain_Gain_g);
  dataAddr[1418] = (void*) (&BEML_EMU_P->CoreSubsys_m.Gain1_Gain);
  dataAddr[1419] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch4_Threshold);
  dataAddr[1420] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value);
  dataAddr[1421] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_o.Constant_Value);
  dataAddr[1422] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_n.Constant_Value);
  dataAddr[1423] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration_e.Constant_Value);
  dataAddr[1424] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.JoltDuration.Constant_Value);
  dataAddr[1425] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch2_Threshold_g);
  dataAddr[1426] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_Mean_k);
  dataAddr[1427] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_StdDev_b);
  dataAddr[1428] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_Mean_o);
  dataAddr[1429] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_StdDev_e);
  dataAddr[1430] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit_p);
  dataAddr[1431] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch_Threshold_c);
  dataAddr[1432] = (void*) (&BEML_EMU_P->CoreSubsys_m.Latch_Threshold_j);
  dataAddr[1433] = (void*) (&BEML_EMU_P->CoreSubsys_m.TuningFactor_Threshold_c);
  dataAddr[1434] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant2_Value_h);
  dataAddr[1435] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant4_Value_j[0]);
  dataAddr[1436] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant5_Value_a);
  dataAddr[1437] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch2_Threshold);
  dataAddr[1438] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_Mean);
  dataAddr[1439] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_StdDev);
  dataAddr[1440] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_Mean_m);
  dataAddr[1441] = (void*) (&BEML_EMU_P->CoreSubsys_m.WhiteNoise_StdDev_d);
  dataAddr[1442] = (void*) (&BEML_EMU_P->CoreSubsys_m.DetectIncrease_vinit);
  dataAddr[1443] = (void*) (&BEML_EMU_P->CoreSubsys_m.Switch_Threshold);
  dataAddr[1444] = (void*) (&BEML_EMU_P->CoreSubsys_m.Latch_Threshold);
  dataAddr[1445] = (void*) (&BEML_EMU_P->CoreSubsys_m.TuningFactor_Threshold);
  dataAddr[1446] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value);
  dataAddr[1447] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant4_Value[0]);
  dataAddr[1448] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant5_Value);
  dataAddr[1449] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_f);
  dataAddr[1450] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_n);
  dataAddr[1451] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC_g);
  dataAddr[1452] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Amp_k);
  dataAddr[1453] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Period_b);
  dataAddr[1454] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Duty_l);
  dataAddr[1455] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_PhaseDelay_f);
  dataAddr[1456] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_d);
  dataAddr[1457] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_mz);
  dataAddr[1458] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_f);
  dataAddr[1459] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_d);
  dataAddr[1460] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_i);
  dataAddr[1461] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_l);
  dataAddr[1462] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_lp);
  dataAddr[1463] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_e);
  dataAddr[1464] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_b);
  dataAddr[1465] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_e);
  dataAddr[1466] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_gu);
  dataAddr[1467] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_h5);
  dataAddr[1468] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_k4);
  dataAddr[1469] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_ja);
  dataAddr[1470] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_ks);
  dataAddr[1471] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_d5);
  dataAddr[1472] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_b0);
  dataAddr[1473] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_f);
  dataAddr[1474] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_j);
  dataAddr[1475] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_j);
  dataAddr[1476] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_e);
  dataAddr[1477] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_c);
  dataAddr[1478] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_a);
  dataAddr[1479] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_i);
  dataAddr[1480] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_k);
  dataAddr[1481] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_f);
  dataAddr[1482] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_c);
  dataAddr[1483] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_c2);
  dataAddr[1484] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_gv);
  dataAddr[1485] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_l);
  dataAddr[1486] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_fd);
  dataAddr[1487] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_p);
  dataAddr[1488] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_kr);
  dataAddr[1489] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_o);
  dataAddr[1490] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_lr);
  dataAddr[1491] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_j);
  dataAddr[1492] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_b2);
  dataAddr[1493] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_fm);
  dataAddr[1494] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_fe);
  dataAddr[1495] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_je);
  dataAddr[1496] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_gi);
  dataAddr[1497] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_b);
  dataAddr[1498] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_g);
  dataAddr[1499] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_gainval_p);
  dataAddr[1500] = (void*) (&BEML_EMU_P->CoreSubsys_m.DiscreteTimeIntegrator_IC);
  dataAddr[1501] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Amp);
  dataAddr[1502] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Period);
  dataAddr[1503] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_Duty);
  dataAddr[1504] = (void*) (&BEML_EMU_P->CoreSubsys_m.PulseGenerator_PhaseDelay);
  dataAddr[1505] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_gy);
  dataAddr[1506] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_d);
  dataAddr[1507] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_h);
  dataAddr[1508] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_o0);
  dataAddr[1509] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_k);
  dataAddr[1510] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_k);
  dataAddr[1511] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_j);
  dataAddr[1512] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_lr);
  dataAddr[1513] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_f);
  dataAddr[1514] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_b);
  dataAddr[1515] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_c);
  dataAddr[1516] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_l);
  dataAddr[1517] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_p);
  dataAddr[1518] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_l);
  dataAddr[1519] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_l);
  dataAddr[1520] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_k);
  dataAddr[1521] = (void*) (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value);
  dataAddr[1522] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat);
  dataAddr[1523] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat);
  dataAddr[1524] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates);
  dataAddr[1525] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt);
  dataAddr[1526] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_o);
  dataAddr[1527] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_m);
  dataAddr[1528] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_c);
  dataAddr[1529] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_o);
  dataAddr[1530] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_n);
  dataAddr[1531] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_b);
  dataAddr[1532] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_g);
  dataAddr[1533] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_p);
  dataAddr[1534] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_e);
  dataAddr[1535] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_k);
  dataAddr[1536] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_g);
  dataAddr[1537] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_h);
  dataAddr[1538] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_i);
  dataAddr[1539] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_i);
  dataAddr[1540] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant_Value_k);
  dataAddr[1541] = (void*) (&BEML_EMU_P->CoreSubsys_m.Constant1_Value_g);
  dataAddr[1542] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.FilterSpecification_Value_j);
  dataAddr[1543] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_UpperSat_i);
  dataAddr[1544] = (void*) (&BEML_EMU_P->CoreSubsys_m.Saturation_LowerSat_a);
  dataAddr[1545] = (void*)
    (&BEML_EMU_P->CoreSubsys_m.DiscreteTransferFcn_InitialStates_g);
  dataAddr[1546] = (void*) (&BEML_EMU_P->CoreSubsys_m.WeightedSampleTime_WtEt_c);
  dataAddr[1547] = (void*) (&BEML_EMU_DW->UnitDelay_DSTATE_h[0]);
  dataAddr[1548] = (void*) (&BEML_EMU_DW->DiscreteTimeIntegrator_DSTATE);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void BEML_EMU_InitializeVarDimsAddr(RT_MODEL_BEML_EMU_T *const BEML_EMU_M,
  int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void BEML_EMU_InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
  loggingPtrs[16] = (NULL);
  loggingPtrs[17] = (NULL);
  loggingPtrs[18] = (NULL);
  loggingPtrs[19] = (NULL);
  loggingPtrs[20] = (NULL);
  loggingPtrs[21] = (NULL);
  loggingPtrs[22] = (NULL);
  loggingPtrs[23] = (NULL);
  loggingPtrs[24] = (NULL);
  loggingPtrs[25] = (NULL);
  loggingPtrs[26] = (NULL);
  loggingPtrs[27] = (NULL);
  loggingPtrs[28] = (NULL);
  loggingPtrs[29] = (NULL);
  loggingPtrs[30] = (NULL);
  loggingPtrs[31] = (NULL);
  loggingPtrs[32] = (NULL);
  loggingPtrs[33] = (NULL);
  loggingPtrs[34] = (NULL);
  loggingPtrs[35] = (NULL);
  loggingPtrs[36] = (NULL);
  loggingPtrs[37] = (NULL);
  loggingPtrs[38] = (NULL);
  loggingPtrs[39] = (NULL);
  loggingPtrs[40] = (NULL);
  loggingPtrs[41] = (NULL);
  loggingPtrs[42] = (NULL);
  loggingPtrs[43] = (NULL);
  loggingPtrs[44] = (NULL);
  loggingPtrs[45] = (NULL);
  loggingPtrs[46] = (NULL);
  loggingPtrs[47] = (NULL);
  loggingPtrs[48] = (NULL);
  loggingPtrs[49] = (NULL);
  loggingPtrs[50] = (NULL);
  loggingPtrs[51] = (NULL);
  loggingPtrs[52] = (NULL);
  loggingPtrs[53] = (NULL);
  loggingPtrs[54] = (NULL);
  loggingPtrs[55] = (NULL);
  loggingPtrs[56] = (NULL);
  loggingPtrs[57] = (NULL);
  loggingPtrs[58] = (NULL);
  loggingPtrs[59] = (NULL);
  loggingPtrs[60] = (NULL);
  loggingPtrs[61] = (NULL);
  loggingPtrs[62] = (NULL);
  loggingPtrs[63] = (NULL);
  loggingPtrs[64] = (NULL);
  loggingPtrs[65] = (NULL);
  loggingPtrs[66] = (NULL);
  loggingPtrs[67] = (NULL);
  loggingPtrs[68] = (NULL);
  loggingPtrs[69] = (NULL);
  loggingPtrs[70] = (NULL);
  loggingPtrs[71] = (NULL);
  loggingPtrs[72] = (NULL);
  loggingPtrs[73] = (NULL);
  loggingPtrs[74] = (NULL);
  loggingPtrs[75] = (NULL);
  loggingPtrs[76] = (NULL);
  loggingPtrs[77] = (NULL);
  loggingPtrs[78] = (NULL);
  loggingPtrs[79] = (NULL);
  loggingPtrs[80] = (NULL);
  loggingPtrs[81] = (NULL);
  loggingPtrs[82] = (NULL);
  loggingPtrs[83] = (NULL);
  loggingPtrs[84] = (NULL);
  loggingPtrs[85] = (NULL);
  loggingPtrs[86] = (NULL);
  loggingPtrs[87] = (NULL);
  loggingPtrs[88] = (NULL);
  loggingPtrs[89] = (NULL);
  loggingPtrs[90] = (NULL);
  loggingPtrs[91] = (NULL);
  loggingPtrs[92] = (NULL);
  loggingPtrs[93] = (NULL);
  loggingPtrs[94] = (NULL);
  loggingPtrs[95] = (NULL);
  loggingPtrs[96] = (NULL);
  loggingPtrs[97] = (NULL);
  loggingPtrs[98] = (NULL);
  loggingPtrs[99] = (NULL);
  loggingPtrs[100] = (NULL);
  loggingPtrs[101] = (NULL);
  loggingPtrs[102] = (NULL);
  loggingPtrs[103] = (NULL);
  loggingPtrs[104] = (NULL);
  loggingPtrs[105] = (NULL);
  loggingPtrs[106] = (NULL);
  loggingPtrs[107] = (NULL);
  loggingPtrs[108] = (NULL);
  loggingPtrs[109] = (NULL);
  loggingPtrs[110] = (NULL);
  loggingPtrs[111] = (NULL);
  loggingPtrs[112] = (NULL);
  loggingPtrs[113] = (NULL);
  loggingPtrs[114] = (NULL);
  loggingPtrs[115] = (NULL);
  loggingPtrs[116] = (NULL);
  loggingPtrs[117] = (NULL);
  loggingPtrs[118] = (NULL);
  loggingPtrs[119] = (NULL);
  loggingPtrs[120] = (NULL);
  loggingPtrs[121] = (NULL);
  loggingPtrs[122] = (NULL);
  loggingPtrs[123] = (NULL);
  loggingPtrs[124] = (NULL);
  loggingPtrs[125] = (NULL);
  loggingPtrs[126] = (NULL);
  loggingPtrs[127] = (NULL);
  loggingPtrs[128] = (NULL);
  loggingPtrs[129] = (NULL);
  loggingPtrs[130] = (NULL);
  loggingPtrs[131] = (NULL);
  loggingPtrs[132] = (NULL);
  loggingPtrs[133] = (NULL);
  loggingPtrs[134] = (NULL);
  loggingPtrs[135] = (NULL);
  loggingPtrs[136] = (NULL);
  loggingPtrs[137] = (NULL);
  loggingPtrs[138] = (NULL);
  loggingPtrs[139] = (NULL);
  loggingPtrs[140] = (NULL);
  loggingPtrs[141] = (NULL);
  loggingPtrs[142] = (NULL);
  loggingPtrs[143] = (NULL);
  loggingPtrs[144] = (NULL);
  loggingPtrs[145] = (NULL);
  loggingPtrs[146] = (NULL);
  loggingPtrs[147] = (NULL);
  loggingPtrs[148] = (NULL);
  loggingPtrs[149] = (NULL);
  loggingPtrs[150] = (NULL);
  loggingPtrs[151] = (NULL);
  loggingPtrs[152] = (NULL);
  loggingPtrs[153] = (NULL);
  loggingPtrs[154] = (NULL);
  loggingPtrs[155] = (NULL);
  loggingPtrs[156] = (NULL);
  loggingPtrs[157] = (NULL);
  loggingPtrs[158] = (NULL);
  loggingPtrs[159] = (NULL);
  loggingPtrs[160] = (NULL);
  loggingPtrs[161] = (NULL);
  loggingPtrs[162] = (NULL);
  loggingPtrs[163] = (NULL);
  loggingPtrs[164] = (NULL);
  loggingPtrs[165] = (NULL);
  loggingPtrs[166] = (NULL);
  loggingPtrs[167] = (NULL);
  loggingPtrs[168] = (NULL);
  loggingPtrs[169] = (NULL);
  loggingPtrs[170] = (NULL);
  loggingPtrs[171] = (NULL);
  loggingPtrs[172] = (NULL);
  loggingPtrs[173] = (NULL);
  loggingPtrs[174] = (NULL);
  loggingPtrs[175] = (NULL);
  loggingPtrs[176] = (NULL);
  loggingPtrs[177] = (NULL);
  loggingPtrs[178] = (NULL);
  loggingPtrs[179] = (NULL);
  loggingPtrs[180] = (NULL);
  loggingPtrs[181] = (NULL);
  loggingPtrs[182] = (NULL);
  loggingPtrs[183] = (NULL);
  loggingPtrs[184] = (NULL);
  loggingPtrs[185] = (NULL);
  loggingPtrs[186] = (NULL);
  loggingPtrs[187] = (NULL);
  loggingPtrs[188] = (NULL);
  loggingPtrs[189] = (NULL);
  loggingPtrs[190] = (NULL);
  loggingPtrs[191] = (NULL);
  loggingPtrs[192] = (NULL);
  loggingPtrs[193] = (NULL);
  loggingPtrs[194] = (NULL);
  loggingPtrs[195] = (NULL);
  loggingPtrs[196] = (NULL);
  loggingPtrs[197] = (NULL);
  loggingPtrs[198] = (NULL);
  loggingPtrs[199] = (NULL);
  loggingPtrs[200] = (NULL);
  loggingPtrs[201] = (NULL);
  loggingPtrs[202] = (NULL);
  loggingPtrs[203] = (NULL);
  loggingPtrs[204] = (NULL);
  loggingPtrs[205] = (NULL);
  loggingPtrs[206] = (NULL);
  loggingPtrs[207] = (NULL);
  loggingPtrs[208] = (NULL);
  loggingPtrs[209] = (NULL);
  loggingPtrs[210] = (NULL);
  loggingPtrs[211] = (NULL);
  loggingPtrs[212] = (NULL);
  loggingPtrs[213] = (NULL);
  loggingPtrs[214] = (NULL);
  loggingPtrs[215] = (NULL);
  loggingPtrs[216] = (NULL);
  loggingPtrs[217] = (NULL);
  loggingPtrs[218] = (NULL);
  loggingPtrs[219] = (NULL);
  loggingPtrs[220] = (NULL);
  loggingPtrs[221] = (NULL);
  loggingPtrs[222] = (NULL);
  loggingPtrs[223] = (NULL);
  loggingPtrs[224] = (NULL);
  loggingPtrs[225] = (NULL);
  loggingPtrs[226] = (NULL);
  loggingPtrs[227] = (NULL);
  loggingPtrs[228] = (NULL);
  loggingPtrs[229] = (NULL);
  loggingPtrs[230] = (NULL);
  loggingPtrs[231] = (NULL);
  loggingPtrs[232] = (NULL);
  loggingPtrs[233] = (NULL);
  loggingPtrs[234] = (NULL);
  loggingPtrs[235] = (NULL);
  loggingPtrs[236] = (NULL);
  loggingPtrs[237] = (NULL);
  loggingPtrs[238] = (NULL);
  loggingPtrs[239] = (NULL);
  loggingPtrs[240] = (NULL);
  loggingPtrs[241] = (NULL);
  loggingPtrs[242] = (NULL);
  loggingPtrs[243] = (NULL);
  loggingPtrs[244] = (NULL);
  loggingPtrs[245] = (NULL);
  loggingPtrs[246] = (NULL);
  loggingPtrs[247] = (NULL);
  loggingPtrs[248] = (NULL);
  loggingPtrs[249] = (NULL);
  loggingPtrs[250] = (NULL);
  loggingPtrs[251] = (NULL);
  loggingPtrs[252] = (NULL);
  loggingPtrs[253] = (NULL);
  loggingPtrs[254] = (NULL);
  loggingPtrs[255] = (NULL);
  loggingPtrs[256] = (NULL);
  loggingPtrs[257] = (NULL);
  loggingPtrs[258] = (NULL);
  loggingPtrs[259] = (NULL);
  loggingPtrs[260] = (NULL);
  loggingPtrs[261] = (NULL);
  loggingPtrs[262] = (NULL);
  loggingPtrs[263] = (NULL);
  loggingPtrs[264] = (NULL);
  loggingPtrs[265] = (NULL);
  loggingPtrs[266] = (NULL);
  loggingPtrs[267] = (NULL);
  loggingPtrs[268] = (NULL);
  loggingPtrs[269] = (NULL);
  loggingPtrs[270] = (NULL);
  loggingPtrs[271] = (NULL);
  loggingPtrs[272] = (NULL);
  loggingPtrs[273] = (NULL);
  loggingPtrs[274] = (NULL);
  loggingPtrs[275] = (NULL);
  loggingPtrs[276] = (NULL);
  loggingPtrs[277] = (NULL);
  loggingPtrs[278] = (NULL);
  loggingPtrs[279] = (NULL);
  loggingPtrs[280] = (NULL);
  loggingPtrs[281] = (NULL);
  loggingPtrs[282] = (NULL);
  loggingPtrs[283] = (NULL);
  loggingPtrs[284] = (NULL);
  loggingPtrs[285] = (NULL);
  loggingPtrs[286] = (NULL);
  loggingPtrs[287] = (NULL);
  loggingPtrs[288] = (NULL);
  loggingPtrs[289] = (NULL);
  loggingPtrs[290] = (NULL);
  loggingPtrs[291] = (NULL);
  loggingPtrs[292] = (NULL);
  loggingPtrs[293] = (NULL);
  loggingPtrs[294] = (NULL);
  loggingPtrs[295] = (NULL);
  loggingPtrs[296] = (NULL);
  loggingPtrs[297] = (NULL);
  loggingPtrs[298] = (NULL);
  loggingPtrs[299] = (NULL);
  loggingPtrs[300] = (NULL);
  loggingPtrs[301] = (NULL);
  loggingPtrs[302] = (NULL);
  loggingPtrs[303] = (NULL);
  loggingPtrs[304] = (NULL);
  loggingPtrs[305] = (NULL);
  loggingPtrs[306] = (NULL);
  loggingPtrs[307] = (NULL);
  loggingPtrs[308] = (NULL);
  loggingPtrs[309] = (NULL);
  loggingPtrs[310] = (NULL);
  loggingPtrs[311] = (NULL);
  loggingPtrs[312] = (NULL);
  loggingPtrs[313] = (NULL);
  loggingPtrs[314] = (NULL);
  loggingPtrs[315] = (NULL);
  loggingPtrs[316] = (NULL);
  loggingPtrs[317] = (NULL);
  loggingPtrs[318] = (NULL);
  loggingPtrs[319] = (NULL);
  loggingPtrs[320] = (NULL);
  loggingPtrs[321] = (NULL);
  loggingPtrs[322] = (NULL);
  loggingPtrs[323] = (NULL);
  loggingPtrs[324] = (NULL);
  loggingPtrs[325] = (NULL);
  loggingPtrs[326] = (NULL);
  loggingPtrs[327] = (NULL);
  loggingPtrs[328] = (NULL);
  loggingPtrs[329] = (NULL);
  loggingPtrs[330] = (NULL);
  loggingPtrs[331] = (NULL);
  loggingPtrs[332] = (NULL);
  loggingPtrs[333] = (NULL);
  loggingPtrs[334] = (NULL);
  loggingPtrs[335] = (NULL);
  loggingPtrs[336] = (NULL);
  loggingPtrs[337] = (NULL);
  loggingPtrs[338] = (NULL);
  loggingPtrs[339] = (NULL);
  loggingPtrs[340] = (NULL);
  loggingPtrs[341] = (NULL);
  loggingPtrs[342] = (NULL);
  loggingPtrs[343] = (NULL);
  loggingPtrs[344] = (NULL);
  loggingPtrs[345] = (NULL);
  loggingPtrs[346] = (NULL);
  loggingPtrs[347] = (NULL);
  loggingPtrs[348] = (NULL);
  loggingPtrs[349] = (NULL);
  loggingPtrs[350] = (NULL);
  loggingPtrs[351] = (NULL);
  loggingPtrs[352] = (NULL);
  loggingPtrs[353] = (NULL);
  loggingPtrs[354] = (NULL);
  loggingPtrs[355] = (NULL);
  loggingPtrs[356] = (NULL);
  loggingPtrs[357] = (NULL);
  loggingPtrs[358] = (NULL);
  loggingPtrs[359] = (NULL);
  loggingPtrs[360] = (NULL);
  loggingPtrs[361] = (NULL);
  loggingPtrs[362] = (NULL);
  loggingPtrs[363] = (NULL);
  loggingPtrs[364] = (NULL);
  loggingPtrs[365] = (NULL);
  loggingPtrs[366] = (NULL);
  loggingPtrs[367] = (NULL);
  loggingPtrs[368] = (NULL);
  loggingPtrs[369] = (NULL);
  loggingPtrs[370] = (NULL);
  loggingPtrs[371] = (NULL);
  loggingPtrs[372] = (NULL);
  loggingPtrs[373] = (NULL);
  loggingPtrs[374] = (NULL);
  loggingPtrs[375] = (NULL);
  loggingPtrs[376] = (NULL);
  loggingPtrs[377] = (NULL);
  loggingPtrs[378] = (NULL);
  loggingPtrs[379] = (NULL);
  loggingPtrs[380] = (NULL);
  loggingPtrs[381] = (NULL);
  loggingPtrs[382] = (NULL);
  loggingPtrs[383] = (NULL);
  loggingPtrs[384] = (NULL);
  loggingPtrs[385] = (NULL);
  loggingPtrs[386] = (NULL);
  loggingPtrs[387] = (NULL);
  loggingPtrs[388] = (NULL);
  loggingPtrs[389] = (NULL);
  loggingPtrs[390] = (NULL);
  loggingPtrs[391] = (NULL);
  loggingPtrs[392] = (NULL);
  loggingPtrs[393] = (NULL);
  loggingPtrs[394] = (NULL);
  loggingPtrs[395] = (NULL);
  loggingPtrs[396] = (NULL);
  loggingPtrs[397] = (NULL);
  loggingPtrs[398] = (NULL);
  loggingPtrs[399] = (NULL);
  loggingPtrs[400] = (NULL);
  loggingPtrs[401] = (NULL);
  loggingPtrs[402] = (NULL);
  loggingPtrs[403] = (NULL);
  loggingPtrs[404] = (NULL);
  loggingPtrs[405] = (NULL);
  loggingPtrs[406] = (NULL);
  loggingPtrs[407] = (NULL);
  loggingPtrs[408] = (NULL);
  loggingPtrs[409] = (NULL);
  loggingPtrs[410] = (NULL);
  loggingPtrs[411] = (NULL);
  loggingPtrs[412] = (NULL);
  loggingPtrs[413] = (NULL);
  loggingPtrs[414] = (NULL);
  loggingPtrs[415] = (NULL);
  loggingPtrs[416] = (NULL);
  loggingPtrs[417] = (NULL);
  loggingPtrs[418] = (NULL);
  loggingPtrs[419] = (NULL);
  loggingPtrs[420] = (NULL);
  loggingPtrs[421] = (NULL);
  loggingPtrs[422] = (NULL);
  loggingPtrs[423] = (NULL);
  loggingPtrs[424] = (NULL);
  loggingPtrs[425] = (NULL);
  loggingPtrs[426] = (NULL);
  loggingPtrs[427] = (NULL);
  loggingPtrs[428] = (NULL);
  loggingPtrs[429] = (NULL);
  loggingPtrs[430] = (NULL);
  loggingPtrs[431] = (NULL);
  loggingPtrs[432] = (NULL);
  loggingPtrs[433] = (NULL);
  loggingPtrs[434] = (NULL);
  loggingPtrs[435] = (NULL);
  loggingPtrs[436] = (NULL);
  loggingPtrs[437] = (NULL);
  loggingPtrs[438] = (NULL);
  loggingPtrs[439] = (NULL);
  loggingPtrs[440] = (NULL);
  loggingPtrs[441] = (NULL);
  loggingPtrs[442] = (NULL);
  loggingPtrs[443] = (NULL);
  loggingPtrs[444] = (NULL);
  loggingPtrs[445] = (NULL);
  loggingPtrs[446] = (NULL);
  loggingPtrs[447] = (NULL);
  loggingPtrs[448] = (NULL);
  loggingPtrs[449] = (NULL);
  loggingPtrs[450] = (NULL);
  loggingPtrs[451] = (NULL);
  loggingPtrs[452] = (NULL);
  loggingPtrs[453] = (NULL);
  loggingPtrs[454] = (NULL);
  loggingPtrs[455] = (NULL);
  loggingPtrs[456] = (NULL);
  loggingPtrs[457] = (NULL);
  loggingPtrs[458] = (NULL);
  loggingPtrs[459] = (NULL);
  loggingPtrs[460] = (NULL);
  loggingPtrs[461] = (NULL);
  loggingPtrs[462] = (NULL);
  loggingPtrs[463] = (NULL);
  loggingPtrs[464] = (NULL);
  loggingPtrs[465] = (NULL);
  loggingPtrs[466] = (NULL);
  loggingPtrs[467] = (NULL);
  loggingPtrs[468] = (NULL);
  loggingPtrs[469] = (NULL);
  loggingPtrs[470] = (NULL);
  loggingPtrs[471] = (NULL);
  loggingPtrs[472] = (NULL);
  loggingPtrs[473] = (NULL);
  loggingPtrs[474] = (NULL);
  loggingPtrs[475] = (NULL);
  loggingPtrs[476] = (NULL);
  loggingPtrs[477] = (NULL);
  loggingPtrs[478] = (NULL);
  loggingPtrs[479] = (NULL);
  loggingPtrs[480] = (NULL);
  loggingPtrs[481] = (NULL);
  loggingPtrs[482] = (NULL);
  loggingPtrs[483] = (NULL);
  loggingPtrs[484] = (NULL);
  loggingPtrs[485] = (NULL);
  loggingPtrs[486] = (NULL);
  loggingPtrs[487] = (NULL);
  loggingPtrs[488] = (NULL);
  loggingPtrs[489] = (NULL);
  loggingPtrs[490] = (NULL);
  loggingPtrs[491] = (NULL);
  loggingPtrs[492] = (NULL);
  loggingPtrs[493] = (NULL);
  loggingPtrs[494] = (NULL);
  loggingPtrs[495] = (NULL);
  loggingPtrs[496] = (NULL);
  loggingPtrs[497] = (NULL);
  loggingPtrs[498] = (NULL);
  loggingPtrs[499] = (NULL);
  loggingPtrs[500] = (NULL);
  loggingPtrs[501] = (NULL);
  loggingPtrs[502] = (NULL);
  loggingPtrs[503] = (NULL);
  loggingPtrs[504] = (NULL);
  loggingPtrs[505] = (NULL);
  loggingPtrs[506] = (NULL);
  loggingPtrs[507] = (NULL);
  loggingPtrs[508] = (NULL);
  loggingPtrs[509] = (NULL);
  loggingPtrs[510] = (NULL);
  loggingPtrs[511] = (NULL);
  loggingPtrs[512] = (NULL);
  loggingPtrs[513] = (NULL);
  loggingPtrs[514] = (NULL);
  loggingPtrs[515] = (NULL);
  loggingPtrs[516] = (NULL);
  loggingPtrs[517] = (NULL);
  loggingPtrs[518] = (NULL);
  loggingPtrs[519] = (NULL);
  loggingPtrs[520] = (NULL);
  loggingPtrs[521] = (NULL);
  loggingPtrs[522] = (NULL);
  loggingPtrs[523] = (NULL);
  loggingPtrs[524] = (NULL);
  loggingPtrs[525] = (NULL);
  loggingPtrs[526] = (NULL);
  loggingPtrs[527] = (NULL);
  loggingPtrs[528] = (NULL);
  loggingPtrs[529] = (NULL);
  loggingPtrs[530] = (NULL);
  loggingPtrs[531] = (NULL);
  loggingPtrs[532] = (NULL);
  loggingPtrs[533] = (NULL);
  loggingPtrs[534] = (NULL);
  loggingPtrs[535] = (NULL);
  loggingPtrs[536] = (NULL);
  loggingPtrs[537] = (NULL);
  loggingPtrs[538] = (NULL);
  loggingPtrs[539] = (NULL);
  loggingPtrs[540] = (NULL);
  loggingPtrs[541] = (NULL);
  loggingPtrs[542] = (NULL);
  loggingPtrs[543] = (NULL);
  loggingPtrs[544] = (NULL);
  loggingPtrs[545] = (NULL);
  loggingPtrs[546] = (NULL);
  loggingPtrs[547] = (NULL);
  loggingPtrs[548] = (NULL);
  loggingPtrs[549] = (NULL);
  loggingPtrs[550] = (NULL);
  loggingPtrs[551] = (NULL);
  loggingPtrs[552] = (NULL);
  loggingPtrs[553] = (NULL);
  loggingPtrs[554] = (NULL);
  loggingPtrs[555] = (NULL);
  loggingPtrs[556] = (NULL);
  loggingPtrs[557] = (NULL);
  loggingPtrs[558] = (NULL);
  loggingPtrs[559] = (NULL);
  loggingPtrs[560] = (NULL);
  loggingPtrs[561] = (NULL);
  loggingPtrs[562] = (NULL);
  loggingPtrs[563] = (NULL);
  loggingPtrs[564] = (NULL);
  loggingPtrs[565] = (NULL);
  loggingPtrs[566] = (NULL);
  loggingPtrs[567] = (NULL);
  loggingPtrs[568] = (NULL);
  loggingPtrs[569] = (NULL);
  loggingPtrs[570] = (NULL);
  loggingPtrs[571] = (NULL);
  loggingPtrs[572] = (NULL);
  loggingPtrs[573] = (NULL);
  loggingPtrs[574] = (NULL);
  loggingPtrs[575] = (NULL);
  loggingPtrs[576] = (NULL);
  loggingPtrs[577] = (NULL);
  loggingPtrs[578] = (NULL);
  loggingPtrs[579] = (NULL);
  loggingPtrs[580] = (NULL);
  loggingPtrs[581] = (NULL);
  loggingPtrs[582] = (NULL);
  loggingPtrs[583] = (NULL);
  loggingPtrs[584] = (NULL);
  loggingPtrs[585] = (NULL);
  loggingPtrs[586] = (NULL);
  loggingPtrs[587] = (NULL);
  loggingPtrs[588] = (NULL);
  loggingPtrs[589] = (NULL);
  loggingPtrs[590] = (NULL);
  loggingPtrs[591] = (NULL);
  loggingPtrs[592] = (NULL);
  loggingPtrs[593] = (NULL);
  loggingPtrs[594] = (NULL);
  loggingPtrs[595] = (NULL);
  loggingPtrs[596] = (NULL);
  loggingPtrs[597] = (NULL);
  loggingPtrs[598] = (NULL);
  loggingPtrs[599] = (NULL);
  loggingPtrs[600] = (NULL);
  loggingPtrs[601] = (NULL);
  loggingPtrs[602] = (NULL);
  loggingPtrs[603] = (NULL);
  loggingPtrs[604] = (NULL);
  loggingPtrs[605] = (NULL);
  loggingPtrs[606] = (NULL);
  loggingPtrs[607] = (NULL);
  loggingPtrs[608] = (NULL);
  loggingPtrs[609] = (NULL);
  loggingPtrs[610] = (NULL);
  loggingPtrs[611] = (NULL);
  loggingPtrs[612] = (NULL);
  loggingPtrs[613] = (NULL);
  loggingPtrs[614] = (NULL);
  loggingPtrs[615] = (NULL);
  loggingPtrs[616] = (NULL);
  loggingPtrs[617] = (NULL);
  loggingPtrs[618] = (NULL);
  loggingPtrs[619] = (NULL);
  loggingPtrs[620] = (NULL);
  loggingPtrs[621] = (NULL);
  loggingPtrs[622] = (NULL);
  loggingPtrs[623] = (NULL);
  loggingPtrs[624] = (NULL);
  loggingPtrs[625] = (NULL);
  loggingPtrs[626] = (NULL);
  loggingPtrs[627] = (NULL);
  loggingPtrs[628] = (NULL);
  loggingPtrs[629] = (NULL);
  loggingPtrs[630] = (NULL);
  loggingPtrs[631] = (NULL);
  loggingPtrs[632] = (NULL);
  loggingPtrs[633] = (NULL);
  loggingPtrs[634] = (NULL);
  loggingPtrs[635] = (NULL);
  loggingPtrs[636] = (NULL);
  loggingPtrs[637] = (NULL);
  loggingPtrs[638] = (NULL);
  loggingPtrs[639] = (NULL);
  loggingPtrs[640] = (NULL);
  loggingPtrs[641] = (NULL);
  loggingPtrs[642] = (NULL);
  loggingPtrs[643] = (NULL);
  loggingPtrs[644] = (NULL);
  loggingPtrs[645] = (NULL);
  loggingPtrs[646] = (NULL);
  loggingPtrs[647] = (NULL);
  loggingPtrs[648] = (NULL);
  loggingPtrs[649] = (NULL);
  loggingPtrs[650] = (NULL);
  loggingPtrs[651] = (NULL);
  loggingPtrs[652] = (NULL);
  loggingPtrs[653] = (NULL);
  loggingPtrs[654] = (NULL);
  loggingPtrs[655] = (NULL);
  loggingPtrs[656] = (NULL);
  loggingPtrs[657] = (NULL);
  loggingPtrs[658] = (NULL);
  loggingPtrs[659] = (NULL);
  loggingPtrs[660] = (NULL);
  loggingPtrs[661] = (NULL);
  loggingPtrs[662] = (NULL);
  loggingPtrs[663] = (NULL);
  loggingPtrs[664] = (NULL);
  loggingPtrs[665] = (NULL);
  loggingPtrs[666] = (NULL);
  loggingPtrs[667] = (NULL);
  loggingPtrs[668] = (NULL);
  loggingPtrs[669] = (NULL);
  loggingPtrs[670] = (NULL);
  loggingPtrs[671] = (NULL);
  loggingPtrs[672] = (NULL);
  loggingPtrs[673] = (NULL);
  loggingPtrs[674] = (NULL);
  loggingPtrs[675] = (NULL);
  loggingPtrs[676] = (NULL);
  loggingPtrs[677] = (NULL);
  loggingPtrs[678] = (NULL);
  loggingPtrs[679] = (NULL);
  loggingPtrs[680] = (NULL);
  loggingPtrs[681] = (NULL);
  loggingPtrs[682] = (NULL);
  loggingPtrs[683] = (NULL);
  loggingPtrs[684] = (NULL);
  loggingPtrs[685] = (NULL);
  loggingPtrs[686] = (NULL);
  loggingPtrs[687] = (NULL);
  loggingPtrs[688] = (NULL);
  loggingPtrs[689] = (NULL);
  loggingPtrs[690] = (NULL);
  loggingPtrs[691] = (NULL);
  loggingPtrs[692] = (NULL);
  loggingPtrs[693] = (NULL);
  loggingPtrs[694] = (NULL);
  loggingPtrs[695] = (NULL);
  loggingPtrs[696] = (NULL);
  loggingPtrs[697] = (NULL);
  loggingPtrs[698] = (NULL);
  loggingPtrs[699] = (NULL);
  loggingPtrs[700] = (NULL);
  loggingPtrs[701] = (NULL);
  loggingPtrs[702] = (NULL);
  loggingPtrs[703] = (NULL);
  loggingPtrs[704] = (NULL);
  loggingPtrs[705] = (NULL);
  loggingPtrs[706] = (NULL);
  loggingPtrs[707] = (NULL);
  loggingPtrs[708] = (NULL);
  loggingPtrs[709] = (NULL);
  loggingPtrs[710] = (NULL);
  loggingPtrs[711] = (NULL);
  loggingPtrs[712] = (NULL);
  loggingPtrs[713] = (NULL);
  loggingPtrs[714] = (NULL);
  loggingPtrs[715] = (NULL);
  loggingPtrs[716] = (NULL);
  loggingPtrs[717] = (NULL);
  loggingPtrs[718] = (NULL);
  loggingPtrs[719] = (NULL);
  loggingPtrs[720] = (NULL);
  loggingPtrs[721] = (NULL);
  loggingPtrs[722] = (NULL);
  loggingPtrs[723] = (NULL);
  loggingPtrs[724] = (NULL);
  loggingPtrs[725] = (NULL);
  loggingPtrs[726] = (NULL);
  loggingPtrs[727] = (NULL);
  loggingPtrs[728] = (NULL);
  loggingPtrs[729] = (NULL);
  loggingPtrs[730] = (NULL);
  loggingPtrs[731] = (NULL);
  loggingPtrs[732] = (NULL);
  loggingPtrs[733] = (NULL);
  loggingPtrs[734] = (NULL);
  loggingPtrs[735] = (NULL);
  loggingPtrs[736] = (NULL);
  loggingPtrs[737] = (NULL);
  loggingPtrs[738] = (NULL);
  loggingPtrs[739] = (NULL);
  loggingPtrs[740] = (NULL);
  loggingPtrs[741] = (NULL);
  loggingPtrs[742] = (NULL);
  loggingPtrs[743] = (NULL);
  loggingPtrs[744] = (NULL);
  loggingPtrs[745] = (NULL);
  loggingPtrs[746] = (NULL);
  loggingPtrs[747] = (NULL);
  loggingPtrs[748] = (NULL);
  loggingPtrs[749] = (NULL);
  loggingPtrs[750] = (NULL);
  loggingPtrs[751] = (NULL);
  loggingPtrs[752] = (NULL);
  loggingPtrs[753] = (NULL);
  loggingPtrs[754] = (NULL);
  loggingPtrs[755] = (NULL);
  loggingPtrs[756] = (NULL);
  loggingPtrs[757] = (NULL);
  loggingPtrs[758] = (NULL);
  loggingPtrs[759] = (NULL);
  loggingPtrs[760] = (NULL);
  loggingPtrs[761] = (NULL);
  loggingPtrs[762] = (NULL);
  loggingPtrs[763] = (NULL);
  loggingPtrs[764] = (NULL);
  loggingPtrs[765] = (NULL);
  loggingPtrs[766] = (NULL);
  loggingPtrs[767] = (NULL);
  loggingPtrs[768] = (NULL);
  loggingPtrs[769] = (NULL);
  loggingPtrs[770] = (NULL);
  loggingPtrs[771] = (NULL);
  loggingPtrs[772] = (NULL);
  loggingPtrs[773] = (NULL);
  loggingPtrs[774] = (NULL);
  loggingPtrs[775] = (NULL);
  loggingPtrs[776] = (NULL);
  loggingPtrs[777] = (NULL);
  loggingPtrs[778] = (NULL);
  loggingPtrs[779] = (NULL);
  loggingPtrs[780] = (NULL);
  loggingPtrs[781] = (NULL);
  loggingPtrs[782] = (NULL);
  loggingPtrs[783] = (NULL);
  loggingPtrs[784] = (NULL);
  loggingPtrs[785] = (NULL);
  loggingPtrs[786] = (NULL);
  loggingPtrs[787] = (NULL);
  loggingPtrs[788] = (NULL);
  loggingPtrs[789] = (NULL);
  loggingPtrs[790] = (NULL);
  loggingPtrs[791] = (NULL);
  loggingPtrs[792] = (NULL);
  loggingPtrs[793] = (NULL);
  loggingPtrs[794] = (NULL);
  loggingPtrs[795] = (NULL);
  loggingPtrs[796] = (NULL);
  loggingPtrs[797] = (NULL);
  loggingPtrs[798] = (NULL);
  loggingPtrs[799] = (NULL);
  loggingPtrs[800] = (NULL);
  loggingPtrs[801] = (NULL);
  loggingPtrs[802] = (NULL);
  loggingPtrs[803] = (NULL);
  loggingPtrs[804] = (NULL);
  loggingPtrs[805] = (NULL);
  loggingPtrs[806] = (NULL);
  loggingPtrs[807] = (NULL);
  loggingPtrs[808] = (NULL);
  loggingPtrs[809] = (NULL);
  loggingPtrs[810] = (NULL);
  loggingPtrs[811] = (NULL);
  loggingPtrs[812] = (NULL);
  loggingPtrs[813] = (NULL);
  loggingPtrs[814] = (NULL);
  loggingPtrs[815] = (NULL);
  loggingPtrs[816] = (NULL);
  loggingPtrs[817] = (NULL);
  loggingPtrs[818] = (NULL);
  loggingPtrs[819] = (NULL);
  loggingPtrs[820] = (NULL);
  loggingPtrs[821] = (NULL);
  loggingPtrs[822] = (NULL);
  loggingPtrs[823] = (NULL);
  loggingPtrs[824] = (NULL);
  loggingPtrs[825] = (NULL);
  loggingPtrs[826] = (NULL);
  loggingPtrs[827] = (NULL);
  loggingPtrs[828] = (NULL);
  loggingPtrs[829] = (NULL);
  loggingPtrs[830] = (NULL);
  loggingPtrs[831] = (NULL);
  loggingPtrs[832] = (NULL);
  loggingPtrs[833] = (NULL);
  loggingPtrs[834] = (NULL);
  loggingPtrs[835] = (NULL);
  loggingPtrs[836] = (NULL);
  loggingPtrs[837] = (NULL);
  loggingPtrs[838] = (NULL);
  loggingPtrs[839] = (NULL);
  loggingPtrs[840] = (NULL);
  loggingPtrs[841] = (NULL);
  loggingPtrs[842] = (NULL);
  loggingPtrs[843] = (NULL);
  loggingPtrs[844] = (NULL);
  loggingPtrs[845] = (NULL);
  loggingPtrs[846] = (NULL);
  loggingPtrs[847] = (NULL);
  loggingPtrs[848] = (NULL);
  loggingPtrs[849] = (NULL);
  loggingPtrs[850] = (NULL);
  loggingPtrs[851] = (NULL);
  loggingPtrs[852] = (NULL);
  loggingPtrs[853] = (NULL);
  loggingPtrs[854] = (NULL);
  loggingPtrs[855] = (NULL);
  loggingPtrs[856] = (NULL);
  loggingPtrs[857] = (NULL);
  loggingPtrs[858] = (NULL);
  loggingPtrs[859] = (NULL);
  loggingPtrs[860] = (NULL);
  loggingPtrs[861] = (NULL);
  loggingPtrs[862] = (NULL);
  loggingPtrs[863] = (NULL);
  loggingPtrs[864] = (NULL);
  loggingPtrs[865] = (NULL);
  loggingPtrs[866] = (NULL);
  loggingPtrs[867] = (NULL);
  loggingPtrs[868] = (NULL);
  loggingPtrs[869] = (NULL);
  loggingPtrs[870] = (NULL);
  loggingPtrs[871] = (NULL);
  loggingPtrs[872] = (NULL);
  loggingPtrs[873] = (NULL);
  loggingPtrs[874] = (NULL);
  loggingPtrs[875] = (NULL);
  loggingPtrs[876] = (NULL);
  loggingPtrs[877] = (NULL);
  loggingPtrs[878] = (NULL);
  loggingPtrs[879] = (NULL);
  loggingPtrs[880] = (NULL);
  loggingPtrs[881] = (NULL);
  loggingPtrs[882] = (NULL);
  loggingPtrs[883] = (NULL);
  loggingPtrs[884] = (NULL);
  loggingPtrs[885] = (NULL);
  loggingPtrs[886] = (NULL);
  loggingPtrs[887] = (NULL);
  loggingPtrs[888] = (NULL);
  loggingPtrs[889] = (NULL);
  loggingPtrs[890] = (NULL);
  loggingPtrs[891] = (NULL);
  loggingPtrs[892] = (NULL);
  loggingPtrs[893] = (NULL);
  loggingPtrs[894] = (NULL);
  loggingPtrs[895] = (NULL);
  loggingPtrs[896] = (NULL);
  loggingPtrs[897] = (NULL);
  loggingPtrs[898] = (NULL);
  loggingPtrs[899] = (NULL);
  loggingPtrs[900] = (NULL);
  loggingPtrs[901] = (NULL);
  loggingPtrs[902] = (NULL);
  loggingPtrs[903] = (NULL);
  loggingPtrs[904] = (NULL);
  loggingPtrs[905] = (NULL);
  loggingPtrs[906] = (NULL);
  loggingPtrs[907] = (NULL);
  loggingPtrs[908] = (NULL);
  loggingPtrs[909] = (NULL);
  loggingPtrs[910] = (NULL);
  loggingPtrs[911] = (NULL);
  loggingPtrs[912] = (NULL);
  loggingPtrs[913] = (NULL);
  loggingPtrs[914] = (NULL);
  loggingPtrs[915] = (NULL);
  loggingPtrs[916] = (NULL);
  loggingPtrs[917] = (NULL);
  loggingPtrs[918] = (NULL);
  loggingPtrs[919] = (NULL);
  loggingPtrs[920] = (NULL);
  loggingPtrs[921] = (NULL);
  loggingPtrs[922] = (NULL);
  loggingPtrs[923] = (NULL);
  loggingPtrs[924] = (NULL);
  loggingPtrs[925] = (NULL);
  loggingPtrs[926] = (NULL);
  loggingPtrs[927] = (NULL);
  loggingPtrs[928] = (NULL);
  loggingPtrs[929] = (NULL);
  loggingPtrs[930] = (NULL);
  loggingPtrs[931] = (NULL);
  loggingPtrs[932] = (NULL);
  loggingPtrs[933] = (NULL);
  loggingPtrs[934] = (NULL);
  loggingPtrs[935] = (NULL);
  loggingPtrs[936] = (NULL);
  loggingPtrs[937] = (NULL);
  loggingPtrs[938] = (NULL);
  loggingPtrs[939] = (NULL);
  loggingPtrs[940] = (NULL);
  loggingPtrs[941] = (NULL);
  loggingPtrs[942] = (NULL);
  loggingPtrs[943] = (NULL);
  loggingPtrs[944] = (NULL);
  loggingPtrs[945] = (NULL);
  loggingPtrs[946] = (NULL);
  loggingPtrs[947] = (NULL);
  loggingPtrs[948] = (NULL);
  loggingPtrs[949] = (NULL);
  loggingPtrs[950] = (NULL);
  loggingPtrs[951] = (NULL);
  loggingPtrs[952] = (NULL);
  loggingPtrs[953] = (NULL);
  loggingPtrs[954] = (NULL);
  loggingPtrs[955] = (NULL);
  loggingPtrs[956] = (NULL);
  loggingPtrs[957] = (NULL);
  loggingPtrs[958] = (NULL);
  loggingPtrs[959] = (NULL);
  loggingPtrs[960] = (NULL);
  loggingPtrs[961] = (NULL);
  loggingPtrs[962] = (NULL);
  loggingPtrs[963] = (NULL);
  loggingPtrs[964] = (NULL);
  loggingPtrs[965] = (NULL);
  loggingPtrs[966] = (NULL);
  loggingPtrs[967] = (NULL);
  loggingPtrs[968] = (NULL);
  loggingPtrs[969] = (NULL);
  loggingPtrs[970] = (NULL);
  loggingPtrs[971] = (NULL);
  loggingPtrs[972] = (NULL);
  loggingPtrs[973] = (NULL);
  loggingPtrs[974] = (NULL);
  loggingPtrs[975] = (NULL);
  loggingPtrs[976] = (NULL);
  loggingPtrs[977] = (NULL);
  loggingPtrs[978] = (NULL);
  loggingPtrs[979] = (NULL);
  loggingPtrs[980] = (NULL);
  loggingPtrs[981] = (NULL);
  loggingPtrs[982] = (NULL);
  loggingPtrs[983] = (NULL);
  loggingPtrs[984] = (NULL);
  loggingPtrs[985] = (NULL);
  loggingPtrs[986] = (NULL);
  loggingPtrs[987] = (NULL);
  loggingPtrs[988] = (NULL);
  loggingPtrs[989] = (NULL);
  loggingPtrs[990] = (NULL);
  loggingPtrs[991] = (NULL);
  loggingPtrs[992] = (NULL);
  loggingPtrs[993] = (NULL);
  loggingPtrs[994] = (NULL);
  loggingPtrs[995] = (NULL);
  loggingPtrs[996] = (NULL);
  loggingPtrs[997] = (NULL);
  loggingPtrs[998] = (NULL);
  loggingPtrs[999] = (NULL);
  loggingPtrs[1000] = (NULL);
  loggingPtrs[1001] = (NULL);
  loggingPtrs[1002] = (NULL);
  loggingPtrs[1003] = (NULL);
  loggingPtrs[1004] = (NULL);
  loggingPtrs[1005] = (NULL);
  loggingPtrs[1006] = (NULL);
  loggingPtrs[1007] = (NULL);
  loggingPtrs[1008] = (NULL);
  loggingPtrs[1009] = (NULL);
  loggingPtrs[1010] = (NULL);
  loggingPtrs[1011] = (NULL);
  loggingPtrs[1012] = (NULL);
  loggingPtrs[1013] = (NULL);
  loggingPtrs[1014] = (NULL);
  loggingPtrs[1015] = (NULL);
  loggingPtrs[1016] = (NULL);
  loggingPtrs[1017] = (NULL);
  loggingPtrs[1018] = (NULL);
  loggingPtrs[1019] = (NULL);
  loggingPtrs[1020] = (NULL);
  loggingPtrs[1021] = (NULL);
  loggingPtrs[1022] = (NULL);
  loggingPtrs[1023] = (NULL);
  loggingPtrs[1024] = (NULL);
  loggingPtrs[1025] = (NULL);
  loggingPtrs[1026] = (NULL);
  loggingPtrs[1027] = (NULL);
  loggingPtrs[1028] = (NULL);
  loggingPtrs[1029] = (NULL);
  loggingPtrs[1030] = (NULL);
  loggingPtrs[1031] = (NULL);
  loggingPtrs[1032] = (NULL);
  loggingPtrs[1033] = (NULL);
  loggingPtrs[1034] = (NULL);
  loggingPtrs[1035] = (NULL);
  loggingPtrs[1036] = (NULL);
  loggingPtrs[1037] = (NULL);
  loggingPtrs[1038] = (NULL);
  loggingPtrs[1039] = (NULL);
  loggingPtrs[1040] = (NULL);
  loggingPtrs[1041] = (NULL);
  loggingPtrs[1042] = (NULL);
  loggingPtrs[1043] = (NULL);
  loggingPtrs[1044] = (NULL);
  loggingPtrs[1045] = (NULL);
  loggingPtrs[1046] = (NULL);
  loggingPtrs[1047] = (NULL);
  loggingPtrs[1048] = (NULL);
  loggingPtrs[1049] = (NULL);
  loggingPtrs[1050] = (NULL);
  loggingPtrs[1051] = (NULL);
  loggingPtrs[1052] = (NULL);
  loggingPtrs[1053] = (NULL);
  loggingPtrs[1054] = (NULL);
  loggingPtrs[1055] = (NULL);
  loggingPtrs[1056] = (NULL);
  loggingPtrs[1057] = (NULL);
  loggingPtrs[1058] = (NULL);
  loggingPtrs[1059] = (NULL);
  loggingPtrs[1060] = (NULL);
  loggingPtrs[1061] = (NULL);
  loggingPtrs[1062] = (NULL);
  loggingPtrs[1063] = (NULL);
  loggingPtrs[1064] = (NULL);
  loggingPtrs[1065] = (NULL);
  loggingPtrs[1066] = (NULL);
  loggingPtrs[1067] = (NULL);
  loggingPtrs[1068] = (NULL);
  loggingPtrs[1069] = (NULL);
  loggingPtrs[1070] = (NULL);
  loggingPtrs[1071] = (NULL);
  loggingPtrs[1072] = (NULL);
  loggingPtrs[1073] = (NULL);
  loggingPtrs[1074] = (NULL);
  loggingPtrs[1075] = (NULL);
  loggingPtrs[1076] = (NULL);
  loggingPtrs[1077] = (NULL);
  loggingPtrs[1078] = (NULL);
  loggingPtrs[1079] = (NULL);
  loggingPtrs[1080] = (NULL);
  loggingPtrs[1081] = (NULL);
  loggingPtrs[1082] = (NULL);
  loggingPtrs[1083] = (NULL);
  loggingPtrs[1084] = (NULL);
  loggingPtrs[1085] = (NULL);
  loggingPtrs[1086] = (NULL);
  loggingPtrs[1087] = (NULL);
  loggingPtrs[1088] = (NULL);
  loggingPtrs[1089] = (NULL);
  loggingPtrs[1090] = (NULL);
  loggingPtrs[1091] = (NULL);
  loggingPtrs[1092] = (NULL);
  loggingPtrs[1093] = (NULL);
  loggingPtrs[1094] = (NULL);
  loggingPtrs[1095] = (NULL);
  loggingPtrs[1096] = (NULL);
  loggingPtrs[1097] = (NULL);
  loggingPtrs[1098] = (NULL);
  loggingPtrs[1099] = (NULL);
  loggingPtrs[1100] = (NULL);
  loggingPtrs[1101] = (NULL);
  loggingPtrs[1102] = (NULL);
  loggingPtrs[1103] = (NULL);
  loggingPtrs[1104] = (NULL);
  loggingPtrs[1105] = (NULL);
  loggingPtrs[1106] = (NULL);
  loggingPtrs[1107] = (NULL);
  loggingPtrs[1108] = (NULL);
  loggingPtrs[1109] = (NULL);
  loggingPtrs[1110] = (NULL);
  loggingPtrs[1111] = (NULL);
  loggingPtrs[1112] = (NULL);
  loggingPtrs[1113] = (NULL);
  loggingPtrs[1114] = (NULL);
  loggingPtrs[1115] = (NULL);
  loggingPtrs[1116] = (NULL);
  loggingPtrs[1117] = (NULL);
  loggingPtrs[1118] = (NULL);
  loggingPtrs[1119] = (NULL);
  loggingPtrs[1120] = (NULL);
  loggingPtrs[1121] = (NULL);
  loggingPtrs[1122] = (NULL);
  loggingPtrs[1123] = (NULL);
  loggingPtrs[1124] = (NULL);
  loggingPtrs[1125] = (NULL);
  loggingPtrs[1126] = (NULL);
  loggingPtrs[1127] = (NULL);
  loggingPtrs[1128] = (NULL);
  loggingPtrs[1129] = (NULL);
  loggingPtrs[1130] = (NULL);
  loggingPtrs[1131] = (NULL);
  loggingPtrs[1132] = (NULL);
  loggingPtrs[1133] = (NULL);
  loggingPtrs[1134] = (NULL);
  loggingPtrs[1135] = (NULL);
  loggingPtrs[1136] = (NULL);
  loggingPtrs[1137] = (NULL);
  loggingPtrs[1138] = (NULL);
  loggingPtrs[1139] = (NULL);
  loggingPtrs[1140] = (NULL);
  loggingPtrs[1141] = (NULL);
  loggingPtrs[1142] = (NULL);
  loggingPtrs[1143] = (NULL);
  loggingPtrs[1144] = (NULL);
  loggingPtrs[1145] = (NULL);
  loggingPtrs[1146] = (NULL);
  loggingPtrs[1147] = (NULL);
  loggingPtrs[1148] = (NULL);
  loggingPtrs[1149] = (NULL);
  loggingPtrs[1150] = (NULL);
  loggingPtrs[1151] = (NULL);
  loggingPtrs[1152] = (NULL);
  loggingPtrs[1153] = (NULL);
  loggingPtrs[1154] = (NULL);
  loggingPtrs[1155] = (NULL);
  loggingPtrs[1156] = (NULL);
  loggingPtrs[1157] = (NULL);
  loggingPtrs[1158] = (NULL);
  loggingPtrs[1159] = (NULL);
  loggingPtrs[1160] = (NULL);
  loggingPtrs[1161] = (NULL);
  loggingPtrs[1162] = (NULL);
  loggingPtrs[1163] = (NULL);
  loggingPtrs[1164] = (NULL);
  loggingPtrs[1165] = (NULL);
  loggingPtrs[1166] = (NULL);
  loggingPtrs[1167] = (NULL);
  loggingPtrs[1168] = (NULL);
  loggingPtrs[1169] = (NULL);
  loggingPtrs[1170] = (NULL);
  loggingPtrs[1171] = (NULL);
  loggingPtrs[1172] = (NULL);
  loggingPtrs[1173] = (NULL);
  loggingPtrs[1174] = (NULL);
  loggingPtrs[1175] = (NULL);
  loggingPtrs[1176] = (NULL);
  loggingPtrs[1177] = (NULL);
  loggingPtrs[1178] = (NULL);
  loggingPtrs[1179] = (NULL);
  loggingPtrs[1180] = (NULL);
  loggingPtrs[1181] = (NULL);
  loggingPtrs[1182] = (NULL);
  loggingPtrs[1183] = (NULL);
  loggingPtrs[1184] = (NULL);
  loggingPtrs[1185] = (NULL);
  loggingPtrs[1186] = (NULL);
  loggingPtrs[1187] = (NULL);
  loggingPtrs[1188] = (NULL);
  loggingPtrs[1189] = (NULL);
  loggingPtrs[1190] = (NULL);
  loggingPtrs[1191] = (NULL);
  loggingPtrs[1192] = (NULL);
  loggingPtrs[1193] = (NULL);
  loggingPtrs[1194] = (NULL);
  loggingPtrs[1195] = (NULL);
  loggingPtrs[1196] = (NULL);
  loggingPtrs[1197] = (NULL);
  loggingPtrs[1198] = (NULL);
  loggingPtrs[1199] = (NULL);
  loggingPtrs[1200] = (NULL);
  loggingPtrs[1201] = (NULL);
  loggingPtrs[1202] = (NULL);
  loggingPtrs[1203] = (NULL);
  loggingPtrs[1204] = (NULL);
  loggingPtrs[1205] = (NULL);
  loggingPtrs[1206] = (NULL);
  loggingPtrs[1207] = (NULL);
  loggingPtrs[1208] = (NULL);
  loggingPtrs[1209] = (NULL);
  loggingPtrs[1210] = (NULL);
  loggingPtrs[1211] = (NULL);
  loggingPtrs[1212] = (NULL);
  loggingPtrs[1213] = (NULL);
  loggingPtrs[1214] = (NULL);
  loggingPtrs[1215] = (NULL);
  loggingPtrs[1216] = (NULL);
  loggingPtrs[1217] = (NULL);
  loggingPtrs[1218] = (NULL);
  loggingPtrs[1219] = (NULL);
  loggingPtrs[1220] = (NULL);
  loggingPtrs[1221] = (NULL);
  loggingPtrs[1222] = (NULL);
  loggingPtrs[1223] = (NULL);
  loggingPtrs[1224] = (NULL);
  loggingPtrs[1225] = (NULL);
  loggingPtrs[1226] = (NULL);
  loggingPtrs[1227] = (NULL);
  loggingPtrs[1228] = (NULL);
  loggingPtrs[1229] = (NULL);
  loggingPtrs[1230] = (NULL);
  loggingPtrs[1231] = (NULL);
  loggingPtrs[1232] = (NULL);
  loggingPtrs[1233] = (NULL);
  loggingPtrs[1234] = (NULL);
  loggingPtrs[1235] = (NULL);
  loggingPtrs[1236] = (NULL);
  loggingPtrs[1237] = (NULL);
  loggingPtrs[1238] = (NULL);
  loggingPtrs[1239] = (NULL);
  loggingPtrs[1240] = (NULL);
  loggingPtrs[1241] = (NULL);
  loggingPtrs[1242] = (NULL);
  loggingPtrs[1243] = (NULL);
  loggingPtrs[1244] = (NULL);
  loggingPtrs[1245] = (NULL);
  loggingPtrs[1246] = (NULL);
  loggingPtrs[1247] = (NULL);
  loggingPtrs[1248] = (NULL);
  loggingPtrs[1249] = (NULL);
  loggingPtrs[1250] = (NULL);
  loggingPtrs[1251] = (NULL);
  loggingPtrs[1252] = (NULL);
  loggingPtrs[1253] = (NULL);
  loggingPtrs[1254] = (NULL);
  loggingPtrs[1255] = (NULL);
  loggingPtrs[1256] = (NULL);
  loggingPtrs[1257] = (NULL);
  loggingPtrs[1258] = (NULL);
  loggingPtrs[1259] = (NULL);
  loggingPtrs[1260] = (NULL);
  loggingPtrs[1261] = (NULL);
  loggingPtrs[1262] = (NULL);
  loggingPtrs[1263] = (NULL);
  loggingPtrs[1264] = (NULL);
  loggingPtrs[1265] = (NULL);
  loggingPtrs[1266] = (NULL);
  loggingPtrs[1267] = (NULL);
  loggingPtrs[1268] = (NULL);
  loggingPtrs[1269] = (NULL);
  loggingPtrs[1270] = (NULL);
  loggingPtrs[1271] = (NULL);
  loggingPtrs[1272] = (NULL);
  loggingPtrs[1273] = (NULL);
  loggingPtrs[1274] = (NULL);
  loggingPtrs[1275] = (NULL);
  loggingPtrs[1276] = (NULL);
  loggingPtrs[1277] = (NULL);
  loggingPtrs[1278] = (NULL);
  loggingPtrs[1279] = (NULL);
  loggingPtrs[1280] = (NULL);
  loggingPtrs[1281] = (NULL);
  loggingPtrs[1282] = (NULL);
  loggingPtrs[1283] = (NULL);
  loggingPtrs[1284] = (NULL);
  loggingPtrs[1285] = (NULL);
  loggingPtrs[1286] = (NULL);
  loggingPtrs[1287] = (NULL);
  loggingPtrs[1288] = (NULL);
  loggingPtrs[1289] = (NULL);
  loggingPtrs[1290] = (NULL);
  loggingPtrs[1291] = (NULL);
  loggingPtrs[1292] = (NULL);
  loggingPtrs[1293] = (NULL);
  loggingPtrs[1294] = (NULL);
  loggingPtrs[1295] = (NULL);
  loggingPtrs[1296] = (NULL);
  loggingPtrs[1297] = (NULL);
  loggingPtrs[1298] = (NULL);
  loggingPtrs[1299] = (NULL);
  loggingPtrs[1300] = (NULL);
  loggingPtrs[1301] = (NULL);
  loggingPtrs[1302] = (NULL);
  loggingPtrs[1303] = (NULL);
  loggingPtrs[1304] = (NULL);
  loggingPtrs[1305] = (NULL);
  loggingPtrs[1306] = (NULL);
  loggingPtrs[1307] = (NULL);
  loggingPtrs[1308] = (NULL);
  loggingPtrs[1309] = (NULL);
  loggingPtrs[1310] = (NULL);
  loggingPtrs[1311] = (NULL);
  loggingPtrs[1312] = (NULL);
  loggingPtrs[1313] = (NULL);
  loggingPtrs[1314] = (NULL);
  loggingPtrs[1315] = (NULL);
  loggingPtrs[1316] = (NULL);
  loggingPtrs[1317] = (NULL);
  loggingPtrs[1318] = (NULL);
  loggingPtrs[1319] = (NULL);
  loggingPtrs[1320] = (NULL);
  loggingPtrs[1321] = (NULL);
  loggingPtrs[1322] = (NULL);
  loggingPtrs[1323] = (NULL);
  loggingPtrs[1324] = (NULL);
  loggingPtrs[1325] = (NULL);
  loggingPtrs[1326] = (NULL);
  loggingPtrs[1327] = (NULL);
  loggingPtrs[1328] = (NULL);
  loggingPtrs[1329] = (NULL);
  loggingPtrs[1330] = (NULL);
  loggingPtrs[1331] = (NULL);
  loggingPtrs[1332] = (NULL);
  loggingPtrs[1333] = (NULL);
  loggingPtrs[1334] = (NULL);
  loggingPtrs[1335] = (NULL);
  loggingPtrs[1336] = (NULL);
  loggingPtrs[1337] = (NULL);
  loggingPtrs[1338] = (NULL);
  loggingPtrs[1339] = (NULL);
  loggingPtrs[1340] = (NULL);
  loggingPtrs[1341] = (NULL);
  loggingPtrs[1342] = (NULL);
  loggingPtrs[1343] = (NULL);
  loggingPtrs[1344] = (NULL);
  loggingPtrs[1345] = (NULL);
  loggingPtrs[1346] = (NULL);
  loggingPtrs[1347] = (NULL);
  loggingPtrs[1348] = (NULL);
  loggingPtrs[1349] = (NULL);
  loggingPtrs[1350] = (NULL);
  loggingPtrs[1351] = (NULL);
  loggingPtrs[1352] = (NULL);
  loggingPtrs[1353] = (NULL);
  loggingPtrs[1354] = (NULL);
  loggingPtrs[1355] = (NULL);
  loggingPtrs[1356] = (NULL);
  loggingPtrs[1357] = (NULL);
  loggingPtrs[1358] = (NULL);
  loggingPtrs[1359] = (NULL);
  loggingPtrs[1360] = (NULL);
  loggingPtrs[1361] = (NULL);
  loggingPtrs[1362] = (NULL);
  loggingPtrs[1363] = (NULL);
  loggingPtrs[1364] = (NULL);
  loggingPtrs[1365] = (NULL);
  loggingPtrs[1366] = (NULL);
  loggingPtrs[1367] = (NULL);
  loggingPtrs[1368] = (NULL);
  loggingPtrs[1369] = (NULL);
  loggingPtrs[1370] = (NULL);
  loggingPtrs[1371] = (NULL);
  loggingPtrs[1372] = (NULL);
  loggingPtrs[1373] = (NULL);
  loggingPtrs[1374] = (NULL);
  loggingPtrs[1375] = (NULL);
  loggingPtrs[1376] = (NULL);
  loggingPtrs[1377] = (NULL);
  loggingPtrs[1378] = (NULL);
  loggingPtrs[1379] = (NULL);
  loggingPtrs[1380] = (NULL);
  loggingPtrs[1381] = (NULL);
  loggingPtrs[1382] = (NULL);
  loggingPtrs[1383] = (NULL);
  loggingPtrs[1384] = (NULL);
  loggingPtrs[1385] = (NULL);
  loggingPtrs[1386] = (NULL);
  loggingPtrs[1387] = (NULL);
  loggingPtrs[1388] = (NULL);
  loggingPtrs[1389] = (NULL);
  loggingPtrs[1390] = (NULL);
  loggingPtrs[1391] = (NULL);
  loggingPtrs[1392] = (NULL);
  loggingPtrs[1393] = (NULL);
  loggingPtrs[1394] = (NULL);
  loggingPtrs[1395] = (NULL);
  loggingPtrs[1396] = (NULL);
  loggingPtrs[1397] = (NULL);
  loggingPtrs[1398] = (NULL);
  loggingPtrs[1399] = (NULL);
  loggingPtrs[1400] = (NULL);
  loggingPtrs[1401] = (NULL);
  loggingPtrs[1402] = (NULL);
  loggingPtrs[1403] = (NULL);
  loggingPtrs[1404] = (NULL);
  loggingPtrs[1405] = (NULL);
  loggingPtrs[1406] = (NULL);
  loggingPtrs[1407] = (NULL);
  loggingPtrs[1408] = (NULL);
  loggingPtrs[1409] = (NULL);
  loggingPtrs[1410] = (NULL);
  loggingPtrs[1411] = (NULL);
  loggingPtrs[1412] = (NULL);
  loggingPtrs[1413] = (NULL);
  loggingPtrs[1414] = (NULL);
  loggingPtrs[1415] = (NULL);
  loggingPtrs[1416] = (NULL);
  loggingPtrs[1417] = (NULL);
  loggingPtrs[1418] = (NULL);
  loggingPtrs[1419] = (NULL);
  loggingPtrs[1420] = (NULL);
  loggingPtrs[1421] = (NULL);
  loggingPtrs[1422] = (NULL);
  loggingPtrs[1423] = (NULL);
  loggingPtrs[1424] = (NULL);
  loggingPtrs[1425] = (NULL);
  loggingPtrs[1426] = (NULL);
  loggingPtrs[1427] = (NULL);
  loggingPtrs[1428] = (NULL);
  loggingPtrs[1429] = (NULL);
  loggingPtrs[1430] = (NULL);
  loggingPtrs[1431] = (NULL);
  loggingPtrs[1432] = (NULL);
  loggingPtrs[1433] = (NULL);
  loggingPtrs[1434] = (NULL);
  loggingPtrs[1435] = (NULL);
  loggingPtrs[1436] = (NULL);
  loggingPtrs[1437] = (NULL);
  loggingPtrs[1438] = (NULL);
  loggingPtrs[1439] = (NULL);
  loggingPtrs[1440] = (NULL);
  loggingPtrs[1441] = (NULL);
  loggingPtrs[1442] = (NULL);
  loggingPtrs[1443] = (NULL);
  loggingPtrs[1444] = (NULL);
  loggingPtrs[1445] = (NULL);
  loggingPtrs[1446] = (NULL);
  loggingPtrs[1447] = (NULL);
  loggingPtrs[1448] = (NULL);
  loggingPtrs[1449] = (NULL);
  loggingPtrs[1450] = (NULL);
  loggingPtrs[1451] = (NULL);
  loggingPtrs[1452] = (NULL);
  loggingPtrs[1453] = (NULL);
  loggingPtrs[1454] = (NULL);
  loggingPtrs[1455] = (NULL);
  loggingPtrs[1456] = (NULL);
  loggingPtrs[1457] = (NULL);
  loggingPtrs[1458] = (NULL);
  loggingPtrs[1459] = (NULL);
  loggingPtrs[1460] = (NULL);
  loggingPtrs[1461] = (NULL);
  loggingPtrs[1462] = (NULL);
  loggingPtrs[1463] = (NULL);
  loggingPtrs[1464] = (NULL);
  loggingPtrs[1465] = (NULL);
  loggingPtrs[1466] = (NULL);
  loggingPtrs[1467] = (NULL);
  loggingPtrs[1468] = (NULL);
  loggingPtrs[1469] = (NULL);
  loggingPtrs[1470] = (NULL);
  loggingPtrs[1471] = (NULL);
  loggingPtrs[1472] = (NULL);
  loggingPtrs[1473] = (NULL);
  loggingPtrs[1474] = (NULL);
  loggingPtrs[1475] = (NULL);
  loggingPtrs[1476] = (NULL);
  loggingPtrs[1477] = (NULL);
  loggingPtrs[1478] = (NULL);
  loggingPtrs[1479] = (NULL);
  loggingPtrs[1480] = (NULL);
  loggingPtrs[1481] = (NULL);
  loggingPtrs[1482] = (NULL);
  loggingPtrs[1483] = (NULL);
  loggingPtrs[1484] = (NULL);
  loggingPtrs[1485] = (NULL);
  loggingPtrs[1486] = (NULL);
  loggingPtrs[1487] = (NULL);
  loggingPtrs[1488] = (NULL);
  loggingPtrs[1489] = (NULL);
  loggingPtrs[1490] = (NULL);
  loggingPtrs[1491] = (NULL);
  loggingPtrs[1492] = (NULL);
  loggingPtrs[1493] = (NULL);
  loggingPtrs[1494] = (NULL);
  loggingPtrs[1495] = (NULL);
  loggingPtrs[1496] = (NULL);
  loggingPtrs[1497] = (NULL);
  loggingPtrs[1498] = (NULL);
  loggingPtrs[1499] = (NULL);
  loggingPtrs[1500] = (NULL);
  loggingPtrs[1501] = (NULL);
  loggingPtrs[1502] = (NULL);
  loggingPtrs[1503] = (NULL);
  loggingPtrs[1504] = (NULL);
  loggingPtrs[1505] = (NULL);
  loggingPtrs[1506] = (NULL);
  loggingPtrs[1507] = (NULL);
  loggingPtrs[1508] = (NULL);
  loggingPtrs[1509] = (NULL);
  loggingPtrs[1510] = (NULL);
  loggingPtrs[1511] = (NULL);
  loggingPtrs[1512] = (NULL);
  loggingPtrs[1513] = (NULL);
  loggingPtrs[1514] = (NULL);
  loggingPtrs[1515] = (NULL);
  loggingPtrs[1516] = (NULL);
  loggingPtrs[1517] = (NULL);
  loggingPtrs[1518] = (NULL);
  loggingPtrs[1519] = (NULL);
  loggingPtrs[1520] = (NULL);
  loggingPtrs[1521] = (NULL);
  loggingPtrs[1522] = (NULL);
  loggingPtrs[1523] = (NULL);
  loggingPtrs[1524] = (NULL);
  loggingPtrs[1525] = (NULL);
  loggingPtrs[1526] = (NULL);
  loggingPtrs[1527] = (NULL);
  loggingPtrs[1528] = (NULL);
  loggingPtrs[1529] = (NULL);
  loggingPtrs[1530] = (NULL);
  loggingPtrs[1531] = (NULL);
  loggingPtrs[1532] = (NULL);
  loggingPtrs[1533] = (NULL);
  loggingPtrs[1534] = (NULL);
  loggingPtrs[1535] = (NULL);
  loggingPtrs[1536] = (NULL);
  loggingPtrs[1537] = (NULL);
  loggingPtrs[1538] = (NULL);
  loggingPtrs[1539] = (NULL);
  loggingPtrs[1540] = (NULL);
  loggingPtrs[1541] = (NULL);
  loggingPtrs[1542] = (NULL);
  loggingPtrs[1543] = (NULL);
  loggingPtrs[1544] = (NULL);
  loggingPtrs[1545] = (NULL);
  loggingPtrs[1546] = (NULL);
  loggingPtrs[1547] = (NULL);
  loggingPtrs[1548] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_CommonTrain_In_Train_CollisionAndDerailment", 3, 1, sizeof
    (BD_CommonTrain_In_Train_CollisionAndDerailment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CommonTrain_In_Train", 1, 4, sizeof(BD_CommonTrain_In_Train),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Train_Overrides", 4, 5, sizeof
    (BD_SimIntegration_In_Train_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Train_CBTC_Tuning", 7, 9, sizeof
    (BD_SimIntegration_In_Train_CBTC_Tuning), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Faults_Train", 25, 16, sizeof
    (BD_SimIntegration_Faults_Train), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Train", 4, 41, sizeof
    (BD_SimIntegration_In_Train), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CommonTrain_In_Vehicle_Adjacencies", 6, 45, sizeof
    (BD_CommonTrain_In_Vehicle_Adjacencies), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CommonTrain_In_Vehicle_CollisionAndDerailment", 6, 51, sizeof
    (BD_CommonTrain_In_Vehicle_CollisionAndDerailment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CommonTrain_In_Vehicle", 2, 57, sizeof
    (BD_CommonTrain_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Vehicle_TrackData", 3, 59, sizeof
    (BD_TrainDynamics_In_Vehicle_TrackData), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_Dynamics", 1, 62, sizeof
    (BD_SimIntegration_In_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_Environment", 9, 63, sizeof
    (BD_SimIntegration_In_Vehicle_Environment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Faults_Vehicle", 159, 72, sizeof
    (BD_SimIntegration_Faults_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie", 3, 231, sizeof
    (BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DisplayControl", 95, 234, sizeof
    (BD_TCMSSystem_In_Vehicle_DisplayControl), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_CBTC_Onboard", 19, 329, sizeof
    (BD_SimIntegration_In_Vehicle_CBTC_Onboard), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_CBTC_Platform", 13, 348, sizeof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_CBTC", 2, 361, sizeof
    (BD_SimIntegration_In_Vehicle_CBTC), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplerSystem_InterfaceData", 7, 363, sizeof
    (BD_CouplerSystem_InterfaceData), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplerMimic_InterfaceData", 11, 370, sizeof
    (BD_CouplerMimic_InterfaceData), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals", 14, 381,
    sizeof(BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals), SS_STRUCT, 0,
    0, 0 },

  { "struct", "BD_CouplingSystem_In_Vehicle_SingleCoupler", 2, 395, sizeof
    (BD_CouplingSystem_In_Vehicle_SingleCoupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_In_Vehicle_Coupler_Dynamics", 11, 397, sizeof
    (BD_CouplingSystem_In_Vehicle_Coupler_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_In_Vehicle", 3, 408, sizeof
    (BD_CouplingSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_Overrides", 1, 411, sizeof
    (BD_SimIntegration_In_Vehicle_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle", 8, 412, sizeof
    (BD_SimIntegration_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_IOControls_Out_Vehicle_InputStates", 274, 420, sizeof
    (BD_IOControls_Out_Vehicle_InputStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_Faults", 18, 694, sizeof
    (BD_DoorSystem_In_Door_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Faults", 126, 712, sizeof
    (BD_ElectricalSystem_In_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Faults", 1, 838, sizeof
    (BD_PantographSystem_In_Vehicle_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_In_Vehicle_Faults", 20, 839, sizeof
    (BD_PneumaticsSystem_In_Vehicle_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_Faults", 16, 859, sizeof
    (BD_TCMSSystem_In_Vehicle_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Faults_Bogie", 2, 875, sizeof
    (BD_TractionSystem_In_Faults_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Faults", 18, 877, sizeof
    (BD_TractionSystem_In_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Faults_Vehicle_Processed", 6, 895, sizeof
    (BD_SimIntegration_Faults_Vehicle_Processed), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_OutputControlStates", 68, 901,
    sizeof(BD_ElectricalSystem_Out_Vehicle_OutputControlStates), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Traction", 11, 969, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Traction), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Braking", 5, 980, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Braking), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_TCMS", 158, 985, sizeof
    (BD_ElectricalSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Pneumatics", 11, 1143, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Pneumatics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Doors", 18, 1154, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Doors), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Pantograph", 8, 1172, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Pantograph), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_SignalSys", 30, 1180, sizeof
    (BD_ElectricalSystem_Out_Vehicle_SignalSys), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Coupling", 2, 1210, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Coupling), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Audio", 7, 1212, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_Scoring", 1, 1219, sizeof
    (BD_ElectricalSystem_Out_Vehicle_Scoring), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS", 11, 1220,
    sizeof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle_MiscOutputs", 1, 1231, sizeof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Out_Vehicle", 12, 1232, sizeof
    (BD_ElectricalSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Vehicle_ElectricalSignals", 6, 1244, sizeof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_ElectricalSignals", 2, 1250, sizeof
    (BD_DoorSystem_Out_Door_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_OutputControlStates", 3, 1252, sizeof
    (BD_DoorSystem_Out_Door_OutputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_Audio", 7, 1255, sizeof
    (BD_DoorSystem_Out_Door_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_TCMS_Messages", 15, 1262, sizeof
    (BD_DoorSystem_Out_Door_TCMS_Messages), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_TCMS", 12, 1277, sizeof
    (BD_DoorSystem_Out_Door_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door", 4, 1289, sizeof(BD_DoorSystem_Out_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Emergency_Door", 7, 1293, sizeof
    (BD_DoorSystem_Out_Emergency_Door), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Vehicle", 3, 1300, sizeof
    (BD_DoorSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_AxleBrakes", 2, 1303, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_AxleBrakes), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Audio", 4, 1305, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie", 6, 1309, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Debug", 7, 1315, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Debug), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie", 2, 1322, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Gauges", 3, 1324, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Gauges), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie", 4, 1327, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Switches", 11, 1331, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Switches), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie", 4, 1342,
    sizeof(BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_Transducers", 1, 1346, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_Transducers), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie", 10, 1347, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle_TCMS", 1, 1357, sizeof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Out_Vehicle", 7, 1358, sizeof
    (BD_PneumaticsSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_DoorSystem", 16, 1365, sizeof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_PantographSystem", 1, 1381,
    sizeof(BD_TCMSSystem_Out_Vehicle_Control_PantographSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie", 6, 1382,
    sizeof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie), SS_STRUCT,
    0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_TractionBraking", 15, 1388,
    sizeof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem", 128, 1403,
    sizeof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem", 8, 1531,
    sizeof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Control", 5, 1539, sizeof
    (BD_TCMSSystem_Out_Vehicle_Control), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door", 169, 1544,
    sizeof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_DoorSystem", 23, 1713, sizeof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_PantographSystem", 13, 1736,
    sizeof(BD_TCMSSystem_Out_Vehicle_Display_PantographSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie", 2,
    1749, sizeof(BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem", 42, 1751,
    sizeof(BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_TractionBraking", 76, 1793,
    sizeof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem", 161, 1869,
    sizeof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem", 14, 2030, sizeof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_Message", 2, 2044, sizeof
    (BD_TCMSSystem_Out_Vehicle_Display_Message), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display_MessageList", 1, 2046, sizeof
    (BD_TCMSSystem_Out_Vehicle_Display_MessageList), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle_Display", 7, 2047, sizeof
    (BD_TCMSSystem_Out_Vehicle_Display), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Out_Vehicle", 2, 2054, sizeof
    (BD_TCMSSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_Drag", 4, 2056, sizeof
    (BD_TrainDynamics_Out_Vehicle_Drag), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Coupler", 11, 2060, sizeof
    (BD_TrainDynamics_Out_Coupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_Inertia", 9, 2071, sizeof
    (BD_TrainDynamics_Out_Vehicle_Inertia), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_TrackGeometry", 6, 2080, sizeof
    (BD_TrainDynamics_Out_Vehicle_TrackGeometry), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_Wheel", 9, 2086, sizeof
    (BD_TrainDynamics_Out_Vehicle_Wheel), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle", 5, 2095, sizeof
    (BD_TrainDynamics_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie", 3, 2100,
    sizeof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie), SS_STRUCT, 0,
    0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_ElectricalSystem", 2, 2103, sizeof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS_Bogie", 17, 2105, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU", 3, 2122, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS", 4, 2125, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_BCU_Bogie", 4, 2129, sizeof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_BCU", 1, 2133, sizeof
    (BD_TractionSystem_Out_Vehicle_BCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCU", 3, 2134, sizeof
    (BD_TractionSystem_Out_Vehicle_TCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_Dynamics", 3, 2137, sizeof
    (BD_TractionSystem_Out_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_Audio", 2, 2140, sizeof
    (BD_TractionSystem_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle", 3, 2142, sizeof
    (BD_TractionSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle_Axle", 7, 2145, sizeof
    (BD_TrainBrakes_Out_Vehicle_Axle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle_States", 6, 2152, sizeof
    (BD_TrainBrakes_Out_Vehicle_States), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle", 2, 2158, sizeof
    (BD_TrainBrakes_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0, 0 },

  { "numeric", "VehicleType", 0, 0, sizeof(VehicleType), SS_ENUM_TYPE, 0, 0,
    SS_INT32 },

  { "struct", "BD_CommonTrain_Cfg_Vehicle", 15, 2160, sizeof
    (BD_CommonTrain_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "numeric", "BrakeShoeCoefficientCalculationMethod", 0, 0, sizeof
    (BrakeShoeCoefficientCalculationMethod), SS_ENUM_TYPE, 0, 0, SS_INT32 },

  { "struct", "BD_TrainBrakes_Cfg_Vehicle", 4, 2175, sizeof
    (BD_TrainBrakes_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_In_Vehicle", 6, 2179, sizeof
    (BD_TrainBrakes_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_In_Vehicle_Overrides", 2, 2185, sizeof
    (BD_TrainBrakes_In_Vehicle_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_In_Vehicle_Faults", 1, 2187, sizeof
    (BD_TrainBrakes_In_Vehicle_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Cfg_Door", 2, 2188, sizeof(BD_DoorSystem_Cfg_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_InputControlStates", 5, 2190, sizeof
    (BD_DoorSystem_In_Door_InputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_ElectricalSignals", 8, 2195, sizeof
    (BD_DoorSystem_In_Door_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door", 4, 2203, sizeof(BD_DoorSystem_In_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Vehicle", 1, 2207, sizeof
    (BD_DoorSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Overrides", 2, 2208, sizeof
    (BD_DoorSystem_In_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Emergency_Door", 11, 2210, sizeof
    (BD_DoorSystem_In_Emergency_Door), SS_STRUCT, 0, 0, 0 },

  { "numeric", "DragCalculationMethod", 0, 0, sizeof(DragCalculationMethod),
    SS_ENUM_TYPE, 0, 0, SS_INT32 },

  { "struct", "BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients", 6, 2221, sizeof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Cfg_Vehicle", 24, 2227, sizeof
    (BD_TrainDynamics_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Coupler", 14, 2251, sizeof
    (BD_TrainDynamics_In_Coupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Vehicle_CustomDragForces", 2, 2265, sizeof
    (BD_TrainDynamics_In_Vehicle_CustomDragForces), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Vehicle", 7, 2267, sizeof
    (BD_TrainDynamics_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Vehicle_Overrides", 9, 2274, sizeof
    (BD_TrainDynamics_In_Vehicle_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_In_Vehicle_Faults", 3, 2283, sizeof
    (BD_TrainDynamics_In_Vehicle_Faults), SS_STRUCT, 0, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Cfg_Vehicle", 17, 2286, sizeof
    (BD_ElectricalSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_InputControlStates", 128, 2303,
    sizeof(BD_ElectricalSystem_In_Vehicle_InputControlStates), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Coupling", 4, 2431, sizeof
    (BD_ElectricalSystem_In_Vehicle_Coupling), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Dynamics", 1, 2435, sizeof
    (BD_ElectricalSystem_In_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Pneumatics", 9, 2436, sizeof
    (BD_ElectricalSystem_In_Vehicle_Pneumatics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Doors", 4, 2445, sizeof
    (BD_ElectricalSystem_In_Vehicle_Doors), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Pantograph", 2, 2449, sizeof
    (BD_ElectricalSystem_In_Vehicle_Pantograph), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CommonTrain_Out_ModelStatus", 1, 2451, sizeof
    (BD_CommonTrain_Out_ModelStatus), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_SignalSys", 31, 2452, sizeof
    (BD_ElectricalSystem_In_Vehicle_SignalSys), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_TCMS", 55, 2483, sizeof
    (BD_ElectricalSystem_In_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle_Traction", 6, 2538, sizeof
    (BD_ElectricalSystem_In_Vehicle_Traction), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Vehicle", 10, 2544, sizeof
    (BD_ElectricalSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Cfg_Vehicle", 3, 2554, sizeof
    (BD_PantographSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Cfg_Vehicle_Equipment", 6, 2557, sizeof
    (BD_PneumaticsSystem_Cfg_Vehicle_Equipment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Cfg_Vehicle", 1, 2563, sizeof
    (BD_PneumaticsSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie", 1, 2564,
    sizeof(BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie), SS_STRUCT, 0,
    0, 0 },

  { "struct", "BD_PneumaticsSystem_In_Vehicle_ElectricalSignals", 16, 2565,
    sizeof(BD_PneumaticsSystem_In_Vehicle_ElectricalSignals), SS_STRUCT, 0, 0, 0
  },

  { "struct", "BD_PneumaticsSystem_In_Vehicle_PhysicalSignals", 2, 2581, sizeof
    (BD_PneumaticsSystem_In_Vehicle_PhysicalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_In_Vehicle_InputControlStates", 32, 2583,
    sizeof(BD_PneumaticsSystem_In_Vehicle_InputControlStates), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_PneumaticsSystem_In_Vehicle", 3, 2615, sizeof
    (BD_PneumaticsSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_In_Overrides", 2, 2618, sizeof
    (BD_PneumaticsSystem_In_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Cfg_Vehicle", 8, 2620, sizeof
    (BD_TCMSSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_InputControlStates", 43, 2628, sizeof
    (BD_TCMSSystem_In_Vehicle_InputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_Environment", 8, 2671, sizeof
    (BD_TCMSSystem_In_Vehicle_Environment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie", 18, 2679,
    sizeof(BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie), SS_STRUCT, 0, 0, 0
  },

  { "struct", "BD_TCMSSystem_In_Vehicle_PneumaticsSystem", 6, 2697, sizeof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DoorSystem_Door", 25, 2703, sizeof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor", 4, 2728,
    sizeof(BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DoorSystem", 4, 2732, sizeof
    (BD_TCMSSystem_In_Vehicle_DoorSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_ElectricalSignals", 176, 2736, sizeof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_PantographSystem", 11, 2912, sizeof
    (BD_TCMSSystem_In_Vehicle_PantographSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie", 17, 2923, sizeof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_TractionSystem", 6, 2940, sizeof
    (BD_TCMSSystem_In_Vehicle_TractionSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_CouplingSystem", 4, 2946, sizeof
    (BD_TCMSSystem_In_Vehicle_CouplingSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_CBTC", 17, 2950, sizeof
    (BD_TCMSSystem_In_Vehicle_CBTC), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_BrakingSystem", 1, 2967, sizeof
    (BD_TCMSSystem_In_Vehicle_BrakingSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_DynamicsSystem", 1, 2968, sizeof
    (BD_TCMSSystem_In_Vehicle_DynamicsSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle", 12, 2969, sizeof
    (BD_TCMSSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Cfg_Vehicle", 1, 2981, sizeof
    (BD_TractionSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie", 4, 2982,
    sizeof(BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie), SS_STRUCT, 0, 0,
    0 },

  { "struct", "BD_TractionSystem_In_Vehicle_ElectricalSystem", 8, 2986, sizeof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle_Dynamics_Bogie", 3, 2994, sizeof
    (BD_TractionSystem_In_Vehicle_Dynamics_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle_Dynamics", 2, 2997, sizeof
    (BD_TractionSystem_In_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle_TCMS_Bogie", 4, 2999, sizeof
    (BD_TractionSystem_In_Vehicle_TCMS_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle_TCMS", 4, 3003, sizeof
    (BD_TractionSystem_In_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Vehicle", 3, 3007, sizeof
    (BD_TractionSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_In_Overrides", 2, 3010, sizeof
    (BD_TractionSystem_In_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Faults_IOControls", 27, 3012, sizeof
    (BD_SimIntegration_Faults_IOControls), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_IOControls_In_InputControl", 5, 3039, sizeof
    (BD_IOControls_In_InputControl), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_IOControls_In_MCBControl", 6, 3044, sizeof
    (BD_IOControls_In_MCBControl), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_IOControls_In_Vehicle", 274, 3050, sizeof
    (BD_IOControls_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_MotionBase_In_Vehicle_Dynamics_Transform", 6, 3324, sizeof
    (BD_MotionBase_In_Vehicle_Dynamics_Transform), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_MotionBase_In_Vehicle_Dynamics", 5, 3330, sizeof
    (BD_MotionBase_In_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_MotionBaseController_Effects", 2,
    3335, sizeof(BD_SimIntegration_In_Vehicle_MotionBaseController_Effects),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_MotionBase_In_Vehicle_Effects", 5, 3337, sizeof
    (BD_MotionBase_In_Vehicle_Effects), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_MotionBase_In_Vehicle_Environment", 1, 3342, sizeof
    (BD_MotionBase_In_Vehicle_Environment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning", 16,
    3343, sizeof(BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_MotionBase_In_Vehicle", 5, 3359, sizeof
    (BD_MotionBase_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Cfg_Vehicle", 6, 3364, sizeof
    (BD_CouplingSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Out_Vehicle_Cfg_Unit", 3, 3370, sizeof
    (BD_SimIntegration_Out_Vehicle_Cfg_Unit), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Cfg_Vehicle_Location", 3, 3373, sizeof
    (BD_SimIntegration_Cfg_Vehicle_Location), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle_TCMS_Messages", 3, 3376, sizeof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle_TCMS", 1, 3379, sizeof
    (BD_PantographSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle", 10, 3380, sizeof
    (BD_PantographSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "numeric", "BrakeShoeType", 0, 0, sizeof(BrakeShoeType), SS_ENUM_TYPE, 0, 0,
    SS_INT32 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_Equipment", 4, 3390, sizeof
    (BD_TrainBrakes_Prm_Vehicle_Equipment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_BrakeCylinder", 4, 3394, sizeof
    (BD_TrainBrakes_Prm_Vehicle_BrakeCylinder), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_BrakeDisc", 2, 3398, sizeof
    (BD_TrainBrakes_Prm_Vehicle_BrakeDisc), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_BrakeFade", 2, 3400, sizeof
    (BD_TrainBrakes_Prm_Vehicle_BrakeFade), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_ThermalModel", 4, 3402, sizeof
    (BD_TrainBrakes_Prm_Vehicle_ThermalModel), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle_ParkBrakes", 2, 3406, sizeof
    (BD_TrainBrakes_Prm_Vehicle_ParkBrakes), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Prm_Vehicle", 6, 3408, sizeof
    (BD_TrainBrakes_Prm_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Prm", 6, 3414, sizeof(BD_DoorSystem_Prm), SS_STRUCT,
    0, 0, 0 },

  { "struct", "BD_ElectricalSystem_Prm", 2, 3420, sizeof(BD_ElectricalSystem_Prm),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Prm", 3, 3422, sizeof(BD_PantographSystem_Prm),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_BrakeControl", 2, 3425, sizeof
    (BD_PneumaticsSystem_Prm_BrakeControl), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_MainReservoir", 8, 3427, sizeof
    (BD_PneumaticsSystem_Prm_MainReservoir), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_MainReservoirPipe", 3, 3435, sizeof
    (BD_PneumaticsSystem_Prm_MainReservoirPipe), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_Sanding", 2, 3438, sizeof
    (BD_PneumaticsSystem_Prm_Sanding), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_AirSuspension", 6, 3440, sizeof
    (BD_PneumaticsSystem_Prm_AirSuspension), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_Horn", 1, 3446, sizeof
    (BD_PneumaticsSystem_Prm_Horn), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_AuxiliaryReservoir", 8, 3447, sizeof
    (BD_PneumaticsSystem_Prm_AuxiliaryReservoir), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_Pantograph", 7, 3455, sizeof
    (BD_PneumaticsSystem_Prm_Pantograph), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_BrakeReservoir", 5, 3462, sizeof
    (BD_PneumaticsSystem_Prm_BrakeReservoir), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_BrakeCylinder", 6, 3467, sizeof
    (BD_PneumaticsSystem_Prm_BrakeCylinder), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_ParkBrakes", 5, 3473, sizeof
    (BD_PneumaticsSystem_Prm_ParkBrakes), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm_VCB", 5, 3478, sizeof
    (BD_PneumaticsSystem_Prm_VCB), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PneumaticsSystem_Prm", 12, 3483, sizeof
    (BD_PneumaticsSystem_Prm), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_Prm", 7, 3495, sizeof(BD_TCMSSystem_Prm), SS_STRUCT,
    0, 0, 0 },

  { "struct", "BD_TractionSystem_Prm", 17, 3502, sizeof(BD_TractionSystem_Prm),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Cfg_Vehicle_Equipment", 12, 3519, sizeof
    (BD_SimIntegration_Cfg_Vehicle_Equipment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Cfg_Vehicle", 10, 3531, sizeof
    (BD_SimIntegration_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Out_Vehicle_Audio", 26, 3541, sizeof
    (BD_SimIntegration_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Out_Train_Scoring", 1, 3567, sizeof
    (BD_SimIntegration_Out_Train_Scoring), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Out_Vehicle_Scoring", 2, 3568, sizeof
    (BD_SimIntegration_Out_Vehicle_Scoring), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle_Onboard", 22, 3570, sizeof
    (BD_CBTC_Out_Vehicle_Onboard), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle_Platform", 10, 3592, sizeof
    (BD_CBTC_Out_Vehicle_Platform), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle_Electrical", 17, 3602, sizeof
    (BD_CBTC_Out_Vehicle_Electrical), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle_TCMS", 13, 3619, sizeof
    (BD_CBTC_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle_DMI", 3, 3632, sizeof(BD_CBTC_Out_Vehicle_DMI),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CBTC_Out_Vehicle", 5, 3635, sizeof(BD_CBTC_Out_Vehicle),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Control", 4, 3640, sizeof
    (BD_PantographSystem_In_Vehicle_Control), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Electrical", 6, 3644, sizeof
    (BD_PantographSystem_In_Vehicle_Electrical), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Pneumatics", 1, 3650, sizeof
    (BD_PantographSystem_In_Vehicle_Pneumatics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Environment", 3, 3651, sizeof
    (BD_PantographSystem_In_Vehicle_Environment), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle", 4, 3654, sizeof
    (BD_PantographSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TCMSSystem_In_Vehicle_Overrides", 1, 3658, sizeof
    (BD_TCMSSystem_In_Vehicle_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "struct_iOPQUPViMP7klj2KCOPonE", 3, 3659, sizeof
    (struct_iOPQUPViMP7klj2KCOPonE), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_ElectricalSystem_In_Overrides", 1, 3662, sizeof
    (BD_ElectricalSystem_In_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_In_Vehicle_Overrides", 1, 3663, sizeof
    (BD_PantographSystem_In_Vehicle_Overrides), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_SimIntegration_Out_Vehicle_MotionBaseController", 9, 3664,
    sizeof(BD_SimIntegration_Out_Vehicle_MotionBaseController), SS_STRUCT, 0, 0,
    0 },

  { "numeric", "TrackEffectType", 0, 0, sizeof(TrackEffectType), SS_ENUM_TYPE, 0,
    0, SS_INT32 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "Collision", rt_offsetof(BD_CommonTrain_In_Train_CollisionAndDerailment,
    Collision), 0, 0, 0 },

  { "Derailment", rt_offsetof(BD_CommonTrain_In_Train_CollisionAndDerailment,
    Derailment), 0, 0, 0 },

  { "Frozen", rt_offsetof(BD_CommonTrain_In_Train_CollisionAndDerailment, Frozen),
    0, 0, 0 },

  { "CollisionAndDerailment", rt_offsetof(BD_CommonTrain_In_Train,
    CollisionAndDerailment), 1, 0, 0 },

  { "InitialVelocity", rt_offsetof(BD_SimIntegration_In_Train_Overrides,
    InitialVelocity), 0, 0, 0 },

  { "AutoPowerOn", rt_offsetof(BD_SimIntegration_In_Train_Overrides, AutoPowerOn),
    0, 0, 0 },

  { "TrainLoadOverride", rt_offsetof(BD_SimIntegration_In_Train_Overrides,
    TrainLoadOverride), 0, 0, 0 },

  { "OrientationSwapRequest", rt_offsetof(BD_SimIntegration_In_Train_Overrides,
    OrientationSwapRequest), 0, 0, 0 },

  { "ATOTractionP", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning,
    ATOTractionP), 0, 0, 0 },

  { "ATOTractionI", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning,
    ATOTractionI), 0, 0, 0 },

  { "ATOTractionD", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning,
    ATOTractionD), 0, 0, 0 },

  { "ATOBrakeP", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning, ATOBrakeP),
    0, 0, 0 },

  { "ATOBrakeI", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning, ATOBrakeI),
    0, 0, 0 },

  { "ATOBrakeD", rt_offsetof(BD_SimIntegration_In_Train_CBTC_Tuning, ATOBrakeD),
    0, 0, 0 },

  { "ATOProximityBrakeDistance", rt_offsetof
    (BD_SimIntegration_In_Train_CBTC_Tuning, ATOProximityBrakeDistance), 0, 0, 0
  },

  { "DynamicBrakeCutOut", rt_offsetof(BD_SimIntegration_Faults_Train,
    DynamicBrakeCutOut), 0, 0, 0 },

  { "ReverseMotionInForwardCommand", rt_offsetof(BD_SimIntegration_Faults_Train,
    ReverseMotionInForwardCommand), 0, 0, 0 },

  { "FWDREVTrainLineMismatch", rt_offsetof(BD_SimIntegration_Faults_Train,
    FWDREVTrainLineMismatch), 0, 0, 0 },

  { "InternalFireAlarmTLActive", rt_offsetof(BD_SimIntegration_Faults_Train,
    InternalFireAlarmTLActive), 0, 0, 0 },

  { "FDUFaultAlarmTLActive", rt_offsetof(BD_SimIntegration_Faults_Train,
    FDUFaultAlarmTLActive), 0, 0, 0 },

  { "LowMRPressure", rt_offsetof(BD_SimIntegration_Faults_Train, LowMRPressure),
    0, 0, 0 },

  { "TractionCutModeSelectorInATPATOUTO", rt_offsetof
    (BD_SimIntegration_Faults_Train, TractionCutModeSelectorInATPATOUTO), 0, 0,
    0 },

  { "DepotSignalMalfunction", rt_offsetof(BD_SimIntegration_Faults_Train,
    DepotSignalMalfunction), 0, 0, 0 },

  { "TrackCircuitOccupied", rt_offsetof(BD_SimIntegration_Faults_Train,
    TrackCircuitOccupied), 0, 0, 0 },

  { "MainSignalSwitchesToRed", rt_offsetof(BD_SimIntegration_Faults_Train,
    MainSignalSwitchesToRed), 0, 0, 0 },

  { "PlatformScreenDoorNotWorking", rt_offsetof(BD_SimIntegration_Faults_Train,
    PlatformScreenDoorNotWorking), 0, 0, 0 },

  { "DamagedOHE", rt_offsetof(BD_SimIntegration_Faults_Train, DamagedOHE), 0, 0,
    0 },

  { "TrainGettingZeroSpeedOrder", rt_offsetof(BD_SimIntegration_Faults_Train,
    TrainGettingZeroSpeedOrder), 0, 0, 0 },

  { "DoorsNotOpeningFromDOPBOP1", rt_offsetof(BD_SimIntegration_Faults_Train,
    DoorsNotOpeningFromDOPBOP1), 0, 0, 0 },

  { "ATCEBUnableToReset", rt_offsetof(BD_SimIntegration_Faults_Train,
    ATCEBUnableToReset), 0, 0, 0 },

  { "TrainOvershootATCNotAllowingReverseAlignment", rt_offsetof
    (BD_SimIntegration_Faults_Train,
     TrainOvershootATCNotAllowingReverseAlignment), 0, 0, 0 },

  { "FSBAppliedAt10KMPH", rt_offsetof(BD_SimIntegration_Faults_Train,
    FSBAppliedAt10KMPH), 0, 0, 0 },

  { "NeutralZoneVCBBackupFunctionActivated", rt_offsetof
    (BD_SimIntegration_Faults_Train, NeutralZoneVCBBackupFunctionActivated), 0,
    0, 0 },

  { "TCMSFailure", rt_offsetof(BD_SimIntegration_Faults_Train, TCMSFailure), 0,
    0, 0 },

  { "TCMSDisplayHanged", rt_offsetof(BD_SimIntegration_Faults_Train,
    TCMSDisplayHanged), 0, 0, 0 },

  { "CCUCommunicationError", rt_offsetof(BD_SimIntegration_Faults_Train,
    CCUCommunicationError), 0, 0, 0 },

  { "HighTractiveEffortRequired", rt_offsetof(BD_SimIntegration_Faults_Train,
    HighTractiveEffortRequired), 0, 0, 0 },

  { "PSDADCLStatusNotAvailable", rt_offsetof(BD_SimIntegration_Faults_Train,
    PSDADCLStatusNotAvailable), 0, 0, 0 },

  { "OnePSDBypassedAtStationInOpenCondition", rt_offsetof
    (BD_SimIntegration_Faults_Train, OnePSDBypassedAtStationInOpenCondition), 0,
    0, 0 },

  { "PSDStatusUnknown", rt_offsetof(BD_SimIntegration_Faults_Train,
    PSDStatusUnknown), 0, 0, 0 },

  { "Common", rt_offsetof(BD_SimIntegration_In_Train, Common), 2, 0, 0 },

  { "Overrides", rt_offsetof(BD_SimIntegration_In_Train, Overrides), 3, 0, 0 },

  { "CBTCTuning", rt_offsetof(BD_SimIntegration_In_Train, CBTCTuning), 4, 0, 0 },

  { "Faults", rt_offsetof(BD_SimIntegration_In_Train, Faults), 5, 0, 0 },

  { "Collision", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies, Collision),
    0, 0, 0 },

  { "SoftCollision", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies,
    SoftCollision), 0, 0, 0 },

  { "Derailment", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies, Derailment),
    0, 0, 0 },

  { "FacingTrackStop", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies,
    FacingTrackStop), 0, 0, 0 },

  { "TrailingTrackStop", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies,
    TrailingTrackStop), 0, 0, 0 },

  { "Detonator", rt_offsetof(BD_CommonTrain_In_Vehicle_Adjacencies, Detonator),
    0, 0, 0 },

  { "Collision", rt_offsetof(BD_CommonTrain_In_Vehicle_CollisionAndDerailment,
    Collision), 0, 0, 0 },

  { "CollisionMass", rt_offsetof
    (BD_CommonTrain_In_Vehicle_CollisionAndDerailment, CollisionMass), 0, 0, 0 },

  { "CollisionSpeed", rt_offsetof
    (BD_CommonTrain_In_Vehicle_CollisionAndDerailment, CollisionSpeed), 0, 0, 0
  },

  { "Derailment", rt_offsetof(BD_CommonTrain_In_Vehicle_CollisionAndDerailment,
    Derailment), 0, 0, 0 },

  { "Frozen", rt_offsetof(BD_CommonTrain_In_Vehicle_CollisionAndDerailment,
    Frozen), 0, 0, 0 },

  { "Freeze", rt_offsetof(BD_CommonTrain_In_Vehicle_CollisionAndDerailment,
    Freeze), 0, 0, 0 },

  { "Adjacencies", rt_offsetof(BD_CommonTrain_In_Vehicle, Adjacencies), 7, 0, 0
  },

  { "CollisionAndDerailment", rt_offsetof(BD_CommonTrain_In_Vehicle,
    CollisionAndDerailment), 8, 0, 0 },

  { "Gradient", rt_offsetof(BD_TrainDynamics_In_Vehicle_TrackData, Gradient), 0,
    0, 0 },

  { "Radius", rt_offsetof(BD_TrainDynamics_In_Vehicle_TrackData, Radius), 0, 0,
    0 },

  { "Superelevation", rt_offsetof(BD_TrainDynamics_In_Vehicle_TrackData,
    Superelevation), 0, 0, 0 },

  { "TrackData", rt_offsetof(BD_SimIntegration_In_Vehicle_Dynamics, TrackData),
    10, 0, 0 },

  { "LineVoltage", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    LineVoltage), 0, 0, 0 },

  { "OverheadLinePresent", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    OverheadLinePresent), 0, 0, 0 },

  { "NeutralSection", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    NeutralSection), 0, 0, 0 },

  { "RightDoorsEnable", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    RightDoorsEnable), 0, 0, 0 },

  { "LeftDoorsEnable", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    LeftDoorsEnable), 0, 0, 0 },

  { "DoorsPairEnable", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    DoorsPairEnable), 0, 1, 0 },

  { "DamagedOHE", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    DamagedOHE), 0, 0, 0 },

  { "ObstructionOnTrack", rt_offsetof(BD_SimIntegration_In_Vehicle_Environment,
    ObstructionOnTrack), 0, 0, 0 },

  { "ObstructionSoftCollision", rt_offsetof
    (BD_SimIntegration_In_Vehicle_Environment, ObstructionSoftCollision), 0, 0,
    0 },

  { "WFLFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, WFLFailure), 0,
    0, 0 },

  { "ODDFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, ODDFailure), 0,
    0, 0 },

  { "ObstacleDetectedRightSide", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    ObstacleDetectedRightSide), 0, 0, 0 },

  { "DerailmentDetectedRightSide", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DerailmentDetectedRightSide), 0, 0, 0 },

  { "ShutdownFailureVCBOpening", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    ShutdownFailureVCBOpening), 0, 0, 0 },

  { "MCBLightGroupSaloonTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBLightGroupSaloonTripped), 0, 0, 0 },

  { "CouplingCircuitNotPowered", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CouplingCircuitNotPowered), 0, 0, 0 },

  { "CabEnablingCircuitBreakerTripped", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, CabEnablingCircuitBreakerTripped), 0, 0,
    0 },

  { "ExteriorLight1CBTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    ExteriorLight1CBTripped), 0, 0, 0 },

  { "ExteriorLight2CBTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    ExteriorLight2CBTripped), 0, 0, 0 },

  { "InteriorLight1CBTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    InteriorLight1CBTripped), 0, 0, 0 },

  { "InteriorLight2CBTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    InteriorLight2CBTripped), 0, 0, 0 },

  { "CMCContactorActivationFailure", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, CMCContactorActivationFailure), 0, 0, 0 },

  { "CIFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, CIFailure), 0, 0,
    0 },

  { "CIIsolated", rt_offsetof(BD_SimIntegration_Faults_Vehicle, CIIsolated), 0,
    0, 0 },

  { "OHLHighVoltageLevel3", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    OHLHighVoltageLevel3), 0, 0, 0 },

  { "OHLLowVoltageLevel2", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    OHLLowVoltageLevel2), 0, 0, 0 },

  { "LineConverterOverCurrentLevel2", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, LineConverterOverCurrentLevel2), 0, 0, 0
  },

  { "DCLinkOverVoltageLevel1", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DCLinkOverVoltageLevel1), 0, 0, 0 },

  { "DCLinkLowVoltageLevel1", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DCLinkLowVoltageLevel1), 0, 0, 0 },

  { "LineConverterIGBTFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    LineConverterIGBTFailure), 0, 0, 0 },

  { "DC110VLowVoltage", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DC110VLowVoltage), 0, 0, 0 },

  { "CIMicroprocessorAbnormal", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CIMicroprocessorAbnormal), 0, 0, 0 },

  { "CILocalCommunicationFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CILocalCommunicationFailure), 0, 0, 0 },

  { "OverTemperatureOfInverterPowerUnit", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, OverTemperatureOfInverterPowerUnit), 0, 0,
    0 },

  { "OverTemperatureOfConverterPowerUnit", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, OverTemperatureOfConverterPowerUnit), 0,
    0, 0 },

  { "AKOpenFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, AKOpenFailure),
    0, 0, 0 },

  { "KOpenFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, KOpenFailure),
    0, 0, 0 },

  { "MainCircuitEarthFaultLevel2", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MainCircuitEarthFaultLevel2), 0, 0, 0 },

  { "HeavyWheelSlip", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HeavyWheelSlip), 0, 0, 0 },

  { "BrakeDemandSignalFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BrakeDemandSignalFailure), 0, 0, 0 },

  { "CIGateSignalAbnormal", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CIGateSignalAbnormal), 0, 0, 0 },

  { "CITCMSCommunicationFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CITCMSCommunicationFailure), 0, 0, 0 },

  { "VCBOpenedByCI", rt_offsetof(BD_SimIntegration_Faults_Vehicle, VCBOpenedByCI),
    0, 0, 0 },

  { "PantographDownForADDIntervention", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, PantographDownForADDIntervention), 0, 0,
    0 },

  { "PantographDownForORDIntervention", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, PantographDownForORDIntervention), 0, 0,
    0 },

  { "PantographDownForBUVDRIntervention", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, PantographDownForBUVDRIntervention), 0, 0,
    0 },

  { "PantographCircuitNotEnergized", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, PantographCircuitNotEnergized), 0, 0, 0 },

  { "PantographPipeLowPressure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographPipeLowPressure), 0, 0, 0 },

  { "TransformerOilPressureTooLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    TransformerOilPressureTooLow), 0, 0, 0 },

  { "TransformerOilTemperatureTooHigh", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TransformerOilTemperatureTooHigh), 0, 0,
    0 },

  { "VCBOpenedByACOvercurrent", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    VCBOpenedByACOvercurrent), 0, 0, 0 },

  { "VCBOpenedByMTrProtection", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    VCBOpenedByMTrProtection), 0, 0, 0 },

  { "VCBOpenedByAPS", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    VCBOpenedByAPS), 0, 0, 0 },

  { "PantographRaiseFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographRaiseFailure), 0, 0, 0 },

  { "PantographLoweringFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographLoweringFailure), 0, 0, 0 },

  { "CMCContactorDeactivationFailure", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, CMCContactorDeactivationFailure), 0, 0, 0
  },

  { "MCB110VDCGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCB110VDCGroupTripped), 0, 0, 0 },

  { "MechanicalCouplerRelayFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MechanicalCouplerRelayFault), 0, 0, 0 },

  { "MasterControllerandTrainLineIncongruence", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, MasterControllerandTrainLineIncongruence),
    0, 0, 0 },

  { "BatteryFuseBlown", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BatteryFuseBlown), 0, 0, 0 },

  { "BICContactorActivationFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BICContactorActivationFault), 0, 0, 0 },

  { "LowBatteryVoltageAlarm", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    LowBatteryVoltageAlarm), 0, 0, 0 },

  { "MCBLightGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBLightGroupTripped), 0, 0, 0 },

  { "BECU1MissingOnSegment", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1MissingOnSegment), 0, 0, 0 },

  { "DLSLFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, DLSLFailure), 0,
    0, 0 },

  { "DCSRFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, DCSRFailure), 0,
    0, 0 },

  { "APSGroup1Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    APSGroup1Failure), 0, 0, 0 },

  { "APSGroup1Isolated", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    APSGroup1Isolated), 0, 0, 0 },

  { "MCBHVACGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBHVACGroupTripped), 0, 0, 0 },

  { "HVAC1MajorFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HVAC1MajorFault), 0, 0, 0 },

  { "HVAC1SupplyFanMPCBTrip", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HVAC1SupplyFanMPCBTrip), 0, 0, 0 },

  { "HVAC1EmergencyInverterTrip", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HVAC1EmergencyInverterTrip), 0, 0, 0 },

  { "HVAC1RCCBTrip", rt_offsetof(BD_SimIntegration_Faults_Vehicle, HVAC1RCCBTrip),
    0, 0, 0 },

  { "HVAC1FireMode", rt_offsetof(BD_SimIntegration_Faults_Vehicle, HVAC1FireMode),
    0, 0, 0 },

  { "HVAC1ExternalSmokeMode", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HVAC1ExternalSmokeMode), 0, 0, 0 },

  { "HVAC1ReducedMode", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HVAC1ReducedMode), 0, 0, 0 },

  { "BCGGroup1Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BCGGroup1Failure), 0, 0, 0 },

  { "BCGGroup1IsolationFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BCGGroup1IsolationFailure), 0, 0, 0 },

  { "BCGGroup1Isolated", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BCGGroup1Isolated), 0, 0, 0 },

  { "MCBSignalingGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBSignalingGroupTripped), 0, 0, 0 },

  { "TrainRadioFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    TrainRadioFailure), 0, 0, 0 },

  { "PEA2AlarmActive", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PEA2AlarmActive), 0, 0, 0 },

  { "PEA2Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, PEA2Failure), 0,
    0, 0 },

  { "PEA3Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, PEA3Failure), 0,
    0, 0 },

  { "SCU2Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, SCU2Failure), 0,
    0, 0 },

  { "MCBDoorGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBDoorGroupTripped), 0, 0, 0 },

  { "EmergencyDoorMechanicalUnlocked", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, EmergencyDoorMechanicalUnlocked), 0, 0, 0
  },

  { "BECU1FailureAllSpeedSensors", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1FailureAllSpeedSensors), 0, 0, 0 },

  { "BECU1LoadPressureLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1LoadPressureLow), 0, 0, 0 },

  { "DoorMajorFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorMajorFault), 0, 0, 0 },

  { "DoorDCUFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorDCUFailure), 0, 0, 0 },

  { "DoorMotorCircuitFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorMotorCircuitFailure), 0, 0, 0 },

  { "BECU1CarLoadPressureLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1CarLoadPressureLow), 0, 0, 0 },

  { "DCSLFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, DCSLFailure), 0,
    0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorUnexpectedUnlocking), 0, 0, 0 },

  { "DoorFailedToLock", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorFailedToLock), 0, 0, 0 },

  { "BECU1BrakeNotApplied", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1BrakeNotApplied), 0, 0, 0 },

  { "DoorCloseObstruction", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorCloseObstruction), 0, 0, 0 },

  { "DoorOpenObstruction", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorOpenObstruction), 0, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorFailedToUnlock), 0, 0, 0 },

  { "BECU2MinorFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU2MinorFault), 0, 0, 0 },

  { "BECUMajorFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECUMajorFault), 0, 0, 0 },

  { "BECUMajorFaultWired", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECUMajorFaultWired), 0, 0, 0 },

  { "BECUPWRAndBRKCmdAtSameTime", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECUPWRAndBRKCmdAtSameTime), 0, 0, 0 },

  { "MCBAPSGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBAPSGroupTripped), 0, 0, 0 },

  { "BECU1BrakeNotReleased", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1BrakeNotReleased), 0, 0, 0 },

  { "BECULowRPressure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECULowRPressure), 0, 0, 0 },

  { "BECU2AxleLockedWheelSet2", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU2AxleLockedWheelSet2), 0, 0, 0 },

  { "TransformerOilLevelTooLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    TransformerOilLevelTooLow), 0, 0, 0 },

  { "PantographRisingMissing", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographRisingMissing), 0, 0, 0 },

  { "PantographLoweringMissing", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographLoweringMissing), 0, 0, 0 },

  { "PantographRisingInhibited", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PantographRisingInhibited), 0, 0, 0 },

  { "VCBMissingClosing", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    VCBMissingClosing), 0, 0, 0 },

  { "VCBMissingOpening", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    VCBMissingOpening), 0, 0, 0 },

  { "FailureOfTrainborneATCEquipment", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, FailureOfTrainborneATCEquipment), 0, 0, 0
  },

  { "DMIFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, DMIFailure), 0,
    0, 0 },

  { "TrainDoorsNotOpeningInATOMode", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TrainDoorsNotOpeningInATOMode), 0, 0, 0 },

  { "APSCircuitBreakerTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    APSCircuitBreakerTripped), 0, 0, 0 },

  { "CCTVDisplayHanged", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CCTVDisplayHanged), 0, 0, 0 },

  { "HeadlightFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HeadlightFailure), 0, 0, 0 },

  { "HornBlowsContinuously", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HornBlowsContinuously), 0, 0, 0 },

  { "EBNotReleased", rt_offsetof(BD_SimIntegration_Faults_Vehicle, EBNotReleased),
    0, 0, 0 },

  { "TrainDoorLockedClosedRelayFailure", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TrainDoorLockedClosedRelayFailure), 0, 0,
    0 },

  { "EmergencyBrakePBOP1NotWorking", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, EmergencyBrakePBOP1NotWorking), 0, 0, 0 },

  { "AllDoorCloseIndicatorNotWorking", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, AllDoorCloseIndicatorNotWorking), 0, 0, 0
  },

  { "DoorClosePBOP1NotWorking", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    DoorClosePBOP1NotWorking), 0, 0, 0 },

  { "DoorCloseAnnouncementPBNotWorking", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, DoorCloseAnnouncementPBNotWorking), 0, 0,
    0 },

  { "LineVoltageIndicatorNotWorking", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, LineVoltageIndicatorNotWorking), 0, 0, 0
  },

  { "SmokeAlarmCABArea", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    SmokeAlarmCABArea), 0, 0, 0 },

  { "HeatAlarmEDB", rt_offsetof(BD_SimIntegration_Faults_Vehicle, HeatAlarmEDB),
    0, 0, 0 },

  { "PEA1AlarmActive", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PEA1AlarmActive), 0, 0, 0 },

  { "PEA1CallNotAcknowledged", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PEA1CallNotAcknowledged), 0, 0, 0 },

  { "PEA1Failure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, PEA1Failure), 0,
    0, 0 },

  { "PCUFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, PCUFailure), 0,
    0, 0 },

  { "MCBPAGroupOpen", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBPAGroupOpen), 0, 0, 0 },

  { "TrainDoorNotClosingAtPlatform", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TrainDoorNotClosingAtPlatform), 0, 0, 0 },

  { "DM1A1DoorNotOpeningAtPlatform", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, DM1A1DoorNotOpeningAtPlatform), 0, 0, 0 },

  { "WipersNotWorking", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    WipersNotWorking), 0, 0, 0 },

  { "CCDetectDetrainmentDoorOpen", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CCDetectDetrainmentDoorOpen), 0, 0, 0 },

  { "BECU1AxleLockedWheelSet1", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1AxleLockedWheelSet1), 0, 0, 0 },

  { "BECU1ServiceBrakeFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1ServiceBrakeFailure), 0, 0, 0 },

  { "BECU1EmergencyBrakeFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU1EmergencyBrakeFailure), 0, 0, 0 },

  { "AirSuspensionBogie1Deflated", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    AirSuspensionBogie1Deflated), 0, 0, 0 },

  { "WSPActiveBogie1", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    WSPActiveBogie1), 0, 0, 0 },

  { "MCBBrakeGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBBrakeGroupTripped), 0, 0, 0 },

  { "ParkingBrakeApplicationFailure", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, ParkingBrakeApplicationFailure), 0, 0, 0
  },

  { "ParkingBrakeReleaseFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    ParkingBrakeReleaseFailure), 0, 0, 0 },

  { "CommunicationErrorRIO1RIO2", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    CommunicationErrorRIO1RIO2), 0, 0, 0 },

  { "MCBTCMSGroupTripped", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    MCBTCMSGroupTripped), 0, 0, 0 },

  { "ER1MajorFault", rt_offsetof(BD_SimIntegration_Faults_Vehicle, ER1MajorFault),
    0, 0, 0 },

  { "FloodLightNotWorking", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    FloodLightNotWorking), 0, 0, 0 },

  { "HornIsolatedByVDU", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    HornIsolatedByVDU), 0, 0, 0 },

  { "DLSRFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle, DLSRFailure), 0,
    0, 0 },

  { "BECU2CarLoadPressureLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU2CarLoadPressureLow), 0, 0, 0 },

  { "BECU2EmergencyBrakeFailure", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    BECU2EmergencyBrakeFailure), 0, 0, 0 },

  { "OtherCabOccupiedIndicatorFaulty", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, OtherCabOccupiedIndicatorFaulty), 0, 0, 0
  },

  { "EDNORDeactivatedInRunningTrain", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, EDNORDeactivatedInRunningTrain), 0, 0, 0
  },

  { "PressureGuageNotWorking", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    PressureGuageNotWorking), 0, 0, 0 },

  { "RIOMastershipError", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    RIOMastershipError), 0, 0, 0 },

  { "TransformerOilLevelLow", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    TransformerOilLevelLow), 0, 0, 0 },

  { "TransformerOilFlowWarning", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    TransformerOilFlowWarning), 0, 0, 0 },

  { "TransformerOilPressureWarning", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TransformerOilPressureWarning), 0, 0, 0 },

  { "TransformerOilTemperatureHigh", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, TransformerOilTemperatureHigh), 0, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, UnexpectedDoorOpeningDetectedByCC), 0, 0,
    0 },

  { "EmergencyBrakeDueToEBPB", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    EmergencyBrakeDueToEBPB), 0, 0, 0 },

  { "EmergencyBrakeDueDeadman", rt_offsetof(BD_SimIntegration_Faults_Vehicle,
    EmergencyBrakeDueDeadman), 0, 0, 0 },

  { "DoorEmergencyHandleActivation", rt_offsetof
    (BD_SimIntegration_Faults_Vehicle, DoorEmergencyHandleActivation), 0, 0, 0 },

  { "BogieDerailed", rt_offsetof(BD_SimIntegration_Faults_Vehicle, BogieDerailed),
    0, 0, 0 },

  { "TractionInhibit", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie,
    TractionInhibit), 14, 0, 0 },

  { "EDBrakingInhibit", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie, EDBrakingInhibit), 0, 0, 0 },

  { "EPBrakingInhibit", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie, EPBrakingInhibit), 0, 0, 0 },

  { "TractionPowerLimit", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TractionPowerLimit), 0, 0, 0 },

  { "EDBrakingPowerLimit", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    EDBrakingPowerLimit), 0, 0, 0 },

  { "EnableTractionPowerLimit", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, EnableTractionPowerLimit), 0, 0, 0
  },

  { "EnableEDBrakingPowerLimit", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, EnableEDBrakingPowerLimit), 0, 0,
    0 },

  { "MaxTractionAccelerationTargetOverride", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     MaxTractionAccelerationTargetOverride), 0, 0, 0 },

  { "MaxBrakingDecelerationTargetOverride", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     MaxBrakingDecelerationTargetOverride), 0, 0, 0 },

  { "EnableTractionTargetOverride", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, EnableTractionTargetOverride), 0,
    0, 0 },

  { "EnableBrakingTargetOverride", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, EnableBrakingTargetOverride), 0, 0,
    0 },

  { "BogieControl", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    BogieControl), 15, 2, 0 },

  { "PantographIsolationCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, PantographIsolationCommand), 0, 0,
    0 },

  { "RightDoorsEmergencyReleaseCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, RightDoorsEmergencyReleaseCommand),
    0, 0, 0 },

  { "LeftDoorsEmergencyReleaseCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, LeftDoorsEmergencyReleaseCommand),
    0, 0, 0 },

  { "DoorRight1DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorRight1DisableCommand), 0, 0, 0
  },

  { "DoorLeft1DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorLeft1DisableCommand), 0, 0, 0
  },

  { "DoorRight2DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorRight2DisableCommand), 0, 0, 0
  },

  { "DoorLeft2DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorLeft2DisableCommand), 0, 0, 0
  },

  { "DoorRight3DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorRight3DisableCommand), 0, 0, 0
  },

  { "DoorLeft3DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorLeft3DisableCommand), 0, 0, 0
  },

  { "DoorRight4DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorRight4DisableCommand), 0, 0, 0
  },

  { "DoorLeft4DisableCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, DoorLeft4DisableCommand), 0, 0, 0
  },

  { "DoorA1IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorA1IsolateVDUReq), 0, 0, 0 },

  { "DoorA2IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorA2IsolateVDUReq), 0, 0, 0 },

  { "DoorA3IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorA3IsolateVDUReq), 0, 0, 0 },

  { "DoorA4IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorA4IsolateVDUReq), 0, 0, 0 },

  { "DoorB1IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorB1IsolateVDUReq), 0, 0, 0 },

  { "DoorB2IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorB2IsolateVDUReq), 0, 0, 0 },

  { "DoorB3IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorB3IsolateVDUReq), 0, 0, 0 },

  { "DoorB4IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    DoorB4IsolateVDUReq), 0, 0, 0 },

  { "LVIsolateBCG1", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    LVIsolateBCG1), 0, 0, 0 },

  { "LVIsolateBCG2", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    LVIsolateBCG2), 0, 0, 0 },

  { "LVCommandPOPB", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    LVCommandPOPB), 0, 0, 0 },

  { "ParkBrakeApplyVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ParkBrakeApplyVDUReq), 0, 0, 0 },

  { "ParkBrakeReleaseVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, ParkBrakeReleaseVDUReq), 0, 0, 0 },

  { "ParkBrakeBypassVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ParkBrakeBypassVDUReq), 0, 0, 0 },

  { "Bogie1IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    Bogie1IsolateVDUReq), 0, 0, 0 },

  { "Bogie2IsolateVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    Bogie2IsolateVDUReq), 0, 0, 0 },

  { "HornHigh", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl, HornHigh),
    0, 0, 0 },

  { "HornLow", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl, HornLow), 0,
    0, 0 },

  { "HornIsolate", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    HornIsolate), 0, 0, 0 },

  { "TCMSPantoLowerReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSPantoLowerReq), 0, 0, 0 },

  { "TCMSPantoResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSPantoResetReq), 0, 0, 0 },

  { "TCMSPantoRiseReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSPantoRiseReq), 0, 0, 0 },

  { "TCMSReqCtrlVCBNS", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSReqCtrlVCBNS), 0, 0, 0 },

  { "TCMSVCBResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSVCBResetReq), 0, 0, 0 },

  { "TCMSVCBOpenReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSVCBOpenReq), 0, 0, 0 },

  { "TCMSVCBCloseReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSVCBCloseReq), 0, 0, 0 },

  { "TCMSIsolateCI", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSIsolateCI), 0, 0, 0 },

  { "TCMSIsolatePanto", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSIsolatePanto), 0, 0, 0 },

  { "TCMSIsolateVCB", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSIsolateVCB), 0, 0, 0 },

  { "TCMSIsolateAPS1", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSIsolateAPS1), 0, 0, 0 },

  { "TCMSIsolateAPS2", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSIsolateAPS2), 0, 0, 0 },

  { "ActivateHTE", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ActivateHTE), 0, 0, 0 },

  { "ActivateWashing3Kmph", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ActivateWashing3Kmph), 0, 0, 0 },

  { "ActivateWashing4Kmph", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ActivateWashing4Kmph), 0, 0, 0 },

  { "ActivateWashing5Kmph", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ActivateWashing5Kmph), 0, 0, 0 },

  { "TCMSAPSICBOpen", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSAPSICBOpen), 0, 0, 0 },

  { "TCMSAPSICBClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSAPSICBClose), 0, 0, 0 },

  { "TCMSHVAC1Close", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC1Close), 0, 0, 0 },

  { "TCMSHVAC1Open", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC1Open), 0, 0, 0 },

  { "TCMSHVAC2Open", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC2Open), 0, 0, 0 },

  { "TCMSHVAC2Close", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC2Close), 0, 0, 0 },

  { "TCMSFDSCBClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSFDSCBClose), 0, 0, 0 },

  { "TCMSFDSCBOpen", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSFDSCBOpen), 0, 0, 0 },

  { "MVMainCompForcing", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    MVMainCompForcing), 0, 0, 0 },

  { "MVMTrBlowersForcingHigh", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, MVMTrBlowersForcingHigh), 0, 0, 0
  },

  { "MVMTrBlowersForcingLow", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, MVMTrBlowersForcingLow), 0, 0, 0 },

  { "MVCompHoursReset", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    MVCompHoursReset), 0, 0, 0 },

  { "TEBEFeedback", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TEBEFeedback), 0, 0, 0 },

  { "TCMSHVAC1ResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC1ResetReq), 0, 0, 0 },

  { "TCMSHVAC2ResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC2ResetReq), 0, 0, 0 },

  { "TCMSHVAC1IsolateReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC1IsolateReq), 0, 0, 0 },

  { "TCMSHVAC2IsolateReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVAC2IsolateReq), 0, 0, 0 },

  { "TCMSHVACSmokeResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSHVACSmokeResetReq), 0, 0, 0 },

  { "TCMSFireAlarmResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSFireAlarmResetReq), 0, 0, 0 },

  { "TCMSFDUResetReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSFDUResetReq), 0, 0, 0 },

  { "ShuntModeMaxSpeed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ShuntModeMaxSpeed), 0, 0, 0 },

  { "ShuntModeMinSpeed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ShuntModeMinSpeed), 0, 0, 0 },

  { "ATPLowModeMaxSpeed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ATPLowModeMaxSpeed), 0, 0, 0 },

  { "ATPLowModeActivated", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ATPLowModeActivated), 0, 0, 0 },

  { "ShuntModeActivated", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    ShuntModeActivated), 0, 0, 0 },

  { "TCMSWFLIsolationReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSWFLIsolationReq), 0, 0, 0 },

  { "TCMSPABORBypassReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    TCMSPABORBypassReq), 0, 0, 0 },

  { "HVAC1FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, HVAC1FireDetectorDisableVDUReq), 0,
    0, 0 },

  { "EDBHeatAlarmDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, EDBHeatAlarmDisableVDUReq), 0, 0,
    0 },

  { "CABSmokeDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, CABSmokeDetectorDisableVDUReq), 0,
    0, 0 },

  { "SHDEndCubicleRearRight1DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     SHDEndCubicleRearRight1DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearRight2DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     SHDEndCubicleRearRight2DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearLeft1DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     SHDEndCubicleRearLeft1DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearLeft2DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     SHDEndCubicleRearLeft2DisableVDUReq), 0, 0, 0 },

  { "LHDDriverDeskDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, LHDDriverDeskDisableVDUReq), 0, 0,
    0 },

  { "LHDCIDisableVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    LHDCIDisableVDUReq), 0, 0, 0 },

  { "LHDLTJBDisableVDUReq", rt_offsetof(BD_TCMSSystem_In_Vehicle_DisplayControl,
    LHDLTJBDisableVDUReq), 0, 0, 0 },

  { "SaloonR1FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, SaloonR1FireDetectorDisableVDUReq),
    0, 0, 0 },

  { "SaloonR2FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl, SaloonR2FireDetectorDisableVDUReq),
    0, 0, 0 },

  { "AuxiliaryDeskFireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DisplayControl,
     AuxiliaryDeskFireDetectorDisableVDUReq), 0, 0, 0 },

  { "NoServiceBrakeOrder", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    NoServiceBrakeOrder), 0, 0, 0 },

  { "NoEmergencyBrakeOrder", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Onboard, NoEmergencyBrakeOrder), 0, 0, 0
  },

  { "ImmobilisationState", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ImmobilisationState), 0, 0, 0 },

  { "ATOState", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard, ATOState),
    0, 0, 0 },

  { "ATOPermittedSpeed", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ATOPermittedSpeed), 0, 0, 0 },

  { "ATOPermittedDistance", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Onboard, ATOPermittedDistance), 0, 0, 0 },

  { "ATOStartIndicator", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ATOStartIndicator), 0, 0, 0 },

  { "ROSIndicator", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ROSIndicator), 0, 0, 0 },

  { "ATCSBResetIndicator", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ATCSBResetIndicator), 0, 0, 0 },

  { "ZeroSpeed", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ZeroSpeed), 0, 0, 0 },

  { "LeftHoldDoorClose", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    LeftHoldDoorClose), 0, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    RightHoldDoorClose), 0, 0, 0 },

  { "WakeUpCommand", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    WakeUpCommand), 0, 0, 0 },

  { "UTOPBIndicator", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    UTOPBIndicator), 0, 0, 0 },

  { "UTOModeActive", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    UTOModeActive), 0, 0, 0 },

  { "ATCCabActivation", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    ATCCabActivation), 0, 0, 0 },

  { "TractionForward", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    TractionForward), 0, 0, 0 },

  { "EmergencyDetrainmentDoorLocked", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Onboard, EmergencyDetrainmentDoorLocked),
    0, 0, 0 },

  { "RollbackDetected", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Onboard,
    RollbackDetected), 0, 0, 0 },

  { "LeftSideDoorEnable", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Platform,
    LeftSideDoorEnable), 0, 0, 0 },

  { "RightSideDoorEnable", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, RightSideDoorEnable), 0, 0, 0 },

  { "OpenLeftTrainDoors", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Platform,
    OpenLeftTrainDoors), 0, 0, 0 },

  { "OpenRightTrainDoors", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, OpenRightTrainDoors), 0, 0, 0 },

  { "CloseLeftTrainDoors", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, CloseLeftTrainDoors), 0, 0, 0 },

  { "CloseRightTrainDoors", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, CloseRightTrainDoors), 0, 0, 0
  },

  { "LeftDoorOpenIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, LeftDoorOpenIndicator), 0, 0, 0
  },

  { "RightDoorOpenIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, RightDoorOpenIndicator), 0, 0,
    0 },

  { "LeftDoorReleaseIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, LeftDoorReleaseIndicator), 0, 0,
    0 },

  { "RightDoorReleaseIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, RightDoorReleaseIndicator), 0,
    0, 0 },

  { "UndergroundSection", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC_Platform,
    UndergroundSection), 0, 0, 0 },

  { "LeftDoorCloseIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, LeftDoorCloseIndicator), 0, 0,
    0 },

  { "RightDoorCloseIndicator", rt_offsetof
    (BD_SimIntegration_In_Vehicle_CBTC_Platform, RightDoorCloseIndicator), 0, 0,
    0 },

  { "OnBoard", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC, OnBoard), 17, 0, 0
  },

  { "Platform", rt_offsetof(BD_SimIntegration_In_Vehicle_CBTC, Platform), 18, 0,
    0 },

  { "CouplerType", rt_offsetof(BD_CouplerSystem_InterfaceData, CouplerType), 0,
    0, 0 },

  { "ReadyToCouple", rt_offsetof(BD_CouplerSystem_InterfaceData, ReadyToCouple),
    0, 0, 0 },

  { "MechanicallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    MechanicallyCoupled), 0, 0, 0 },

  { "CouplerBrakeDemand", rt_offsetof(BD_CouplerSystem_InterfaceData,
    CouplerBrakeDemand), 0, 0, 0 },

  { "ElectricallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    ElectricallyCoupled), 0, 0, 0 },

  { "PneumaticallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    PneumaticallyCoupled), 0, 0, 0 },

  { "RescueModeCondition", rt_offsetof(BD_CouplerSystem_InterfaceData,
    RescueModeCondition), 14, 0, 0 },

  { "Mass", rt_offsetof(BD_CouplerMimic_InterfaceData, Mass), 0, 0, 0 },

  { "Time", rt_offsetof(BD_CouplerMimic_InterfaceData, Time), 0, 0, 0 },

  { "Position", rt_offsetof(BD_CouplerMimic_InterfaceData, Position), 0, 0, 0 },

  { "Velocity", rt_offsetof(BD_CouplerMimic_InterfaceData, Velocity), 0, 0, 0 },

  { "Acceleration", rt_offsetof(BD_CouplerMimic_InterfaceData, Acceleration), 0,
    0, 0 },

  { "Gradient", rt_offsetof(BD_CouplerMimic_InterfaceData, Gradient), 0, 0, 0 },

  { "Radius", rt_offsetof(BD_CouplerMimic_InterfaceData, Radius), 0, 0, 0 },

  { "TractiveForce", rt_offsetof(BD_CouplerMimic_InterfaceData, TractiveForce),
    0, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_CouplerMimic_InterfaceData, BrakingForce), 0,
    0, 0 },

  { "OtherCouplerForce", rt_offsetof(BD_CouplerMimic_InterfaceData,
    OtherCouplerForce), 0, 0, 0 },

  { "OtherCouplerForceRate", rt_offsetof(BD_CouplerMimic_InterfaceData,
    OtherCouplerForceRate), 0, 0, 0 },

  { "End", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, End),
    0, 0, 0 },

  { "OtherVehicleID", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, OtherVehicleID), 0, 0,
    0 },

  { "OtherVehicleEnd", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, OtherVehicleEnd), 0,
    0, 0 },

  { "OtherVehicleOrientation", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals,
     OtherVehicleOrientation), 0, 0, 0 },

  { "Available", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, Available), 0, 0, 0 },

  { "Separation", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, Separation), 0, 0, 0
  },

  { "SeparationRate", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, SeparationRate), 0, 0,
    0 },

  { "OurCouplingPosition", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, OurCouplingPosition),
    0, 0, 0 },

  { "OtherCouplingPosition", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, OtherCouplingPosition),
    0, 0, 0 },

  { "CouplingSeparation", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, CouplingSeparation),
    0, 0, 0 },

  { "Interfacing", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, Interfacing), 0, 0, 0
  },

  { "CoupledChainLength", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, CoupledChainLength),
    0, 0, 0 },

  { "MechanicallyCoupled", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals, MechanicallyCoupled),
    0, 0, 0 },

  { "Mimic", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals,
    Mimic), 21, 0, 0 },

  { "CouplingInterface", rt_offsetof(BD_CouplingSystem_In_Vehicle_SingleCoupler,
    CouplingInterface), 20, 0, 0 },

  { "CouplingPhysical", rt_offsetof(BD_CouplingSystem_In_Vehicle_SingleCoupler,
    CouplingPhysical), 22, 0, 0 },

  { "Force", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics, Force),
    0, 0, 0 },

  { "SpringForce", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    SpringForce), 0, 0, 0 },

  { "DampingForce", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    DampingForce), 0, 0, 0 },

  { "BuffForce", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    BuffForce), 0, 0, 0 },

  { "DraftForce", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    DraftForce), 0, 0, 0 },

  { "ImpactForce", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    ImpactForce), 0, 0, 0 },

  { "Breakage", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    Breakage), 0, 0, 0 },

  { "Extension", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    Extension), 0, 0, 0 },

  { "ExtensionRate", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics,
    ExtensionRate), 0, 0, 0 },

  { "ExternalCoupling", rt_offsetof
    (BD_CouplingSystem_In_Vehicle_Coupler_Dynamics, ExternalCoupling), 0, 0, 0 },

  { "Mimic", rt_offsetof(BD_CouplingSystem_In_Vehicle_Coupler_Dynamics, Mimic),
    21, 0, 0 },

  { "ReleaseCoupler", rt_offsetof(BD_CouplingSystem_In_Vehicle, ReleaseCoupler),
    14, 0, 0 },

  { "Coupler", rt_offsetof(BD_CouplingSystem_In_Vehicle, Coupler), 23, 2, 0 },

  { "DynamicsCouplers", rt_offsetof(BD_CouplingSystem_In_Vehicle,
    DynamicsCouplers), 24, 2, 0 },

  { "VehicleLoadOverride", rt_offsetof(BD_SimIntegration_In_Vehicle_Overrides,
    VehicleLoadOverride), 0, 0, 0 },

  { "Common", rt_offsetof(BD_SimIntegration_In_Vehicle, Common), 9, 0, 0 },

  { "Dynamics", rt_offsetof(BD_SimIntegration_In_Vehicle, Dynamics), 11, 0, 0 },

  { "Environment", rt_offsetof(BD_SimIntegration_In_Vehicle, Environment), 12, 0,
    0 },

  { "Faults", rt_offsetof(BD_SimIntegration_In_Vehicle, Faults), 13, 0, 0 },

  { "DisplayControl", rt_offsetof(BD_SimIntegration_In_Vehicle, DisplayControl),
    16, 0, 0 },

  { "CBTC", rt_offsetof(BD_SimIntegration_In_Vehicle, CBTC), 19, 0, 0 },

  { "Couplers", rt_offsetof(BD_SimIntegration_In_Vehicle, Couplers), 25, 0, 0 },

  { "Overrides", rt_offsetof(BD_SimIntegration_In_Vehicle, Overrides), 26, 0, 0
  },

  { "EmergencyBrakePB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    EmergencyBrakePB), 0, 0, 0 },

  { "HornPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HornPB), 0, 0,
    0 },

  { "CabConsoleLightPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    CabConsoleLightPB), 0, 0, 0 },

  { "DoorProvenLoopCutoutPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    DoorProvenLoopCutoutPB), 0, 0, 0 },

  { "LeftDoorClosePBOperatingPanel1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, LeftDoorClosePBOperatingPanel1), 0,
    0, 0 },

  { "RightDoorClosePBOperatingPanel1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, RightDoorClosePBOperatingPanel1), 0,
    0, 0 },

  { "LeftDoorOpenPBOperatingPanel1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, LeftDoorOpenPBOperatingPanel1), 0, 0,
    0 },

  { "RightDoorOpenPBOperatingPanel1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, RightDoorOpenPBOperatingPanel1), 0,
    0, 0 },

  { "CabMainLightPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    CabMainLightPB), 0, 0, 0 },

  { "ParkingBrakeOnSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    ParkingBrakeOnSwitch), 0, 0, 0 },

  { "ParkingBrakeOffSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    ParkingBrakeOffSwitch), 0, 0, 0 },

  { "DoorCloseAnnouncementPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    DoorCloseAnnouncementPB), 0, 0, 0 },

  { "ROSPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ROSPB), 0, 0, 0
  },

  { "UTOPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, UTOPB), 0, 0, 0
  },

  { "ATOStartPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ATOStartPB),
    0, 0, 0 },

  { "EmergencyBrakeResetPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    EmergencyBrakeResetPB), 0, 0, 0 },

  { "ControlKey", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ControlKey),
    0, 0, 0 },

  { "ModeSelector", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    ModeSelector), 0, 0, 0 },

  { "MasterControllerHandle", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    MasterControllerHandle), 0, 0, 0 },

  { "DeadmanSafetyDevice", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    DeadmanSafetyDevice), 0, 0, 0 },

  { "CallOnLightPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    CallOnLightPB), 0, 0, 0 },

  { "VCBOpenPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VCBOpenPB),
    0, 0, 0 },

  { "WiperSelectionSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    WiperSelectionSwitch), 0, 0, 0 },

  { "WiperPump", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, WiperPump),
    0, 0, 0 },

  { "LIMPHomePB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, LIMPHomePB),
    0, 0, 0 },

  { "PowerOffPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PowerOffPB),
    0, 0, 0 },

  { "PantoDownPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    PantoDownPB), 0, 0, 0 },

  { "VCBClosePB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VCBClosePB),
    0, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, LeftDoorOpenPBOperatingPanel2), 0, 0,
    0 },

  { "LeftDoorOpenPB1OperatingPanel2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, LeftDoorOpenPB1OperatingPanel2), 0,
    0, 0 },

  { "LeftDoorClosePBOperatingPanel2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, LeftDoorClosePBOperatingPanel2), 0,
    0, 0 },

  { "PantoUpPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PantoUpPB),
    0, 0, 0 },

  { "SafetyCutoutSS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    SafetyCutoutSS), 0, 0, 0 },

  { "BrakeLoopCutoutSS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    BrakeLoopCutoutSS), 0, 0, 0 },

  { "PantoSelector", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    PantoSelector), 0, 0, 0 },

  { "DeadmanBypassSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    DeadmanBypassSwitch), 0, 0, 0 },

  { "HeadLightSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    HeadLightSwitch), 0, 0, 0 },

  { "UncouplePB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, UncouplePB),
    0, 0, 0 },

  { "FlasherLightPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    FlasherLightPB), 0, 0, 0 },

  { "FloodLightPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    FloodLightPB), 0, 0, 0 },

  { "BatteryResetPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    BatteryResetPB), 0, 0, 0 },

  { "RightDoorOpenPBOperatingPanel5", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, RightDoorOpenPBOperatingPanel5), 0,
    0, 0 },

  { "RightDoorOpenPB1OperatingPanel5", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, RightDoorOpenPB1OperatingPanel5), 0,
    0, 0 },

  { "RightDoorClosePBOperatingPanel5", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, RightDoorClosePBOperatingPanel5), 0,
    0, 0 },

  { "DoorProvenLoopOutputSwitch", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, DoorProvenLoopOutputSwitch), 0, 0, 0
  },

  { "LampTestPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, LampTestPB),
    0, 0, 0 },

  { "WFLTestPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, WFLTestPB),
    0, 0, 0 },

  { "WiperControlSwitch", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    WiperControlSwitch), 0, 0, 0 },

  { "EmergencyStopPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    EmergencyStopPB), 0, 0, 0 },

  { "HoldDoorCloseBypassSS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    HoldDoorCloseBypassSS), 0, 0, 0 },

  { "CabBoosterFanSS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    CabBoosterFanSS), 0, 0, 0 },

  { "EmergencyBrakePBBypassSS", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, EmergencyBrakePBBypassSS), 0, 0, 0 },

  { "CabEEDLeft", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CabEEDLeft),
    0, 0, 0 },

  { "CabEEDRight", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    CabEEDRight), 0, 0, 0 },

  { "SafetyCover", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    SafetyCover), 0, 0, 0 },

  { "DummyCover", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DummyCover),
    0, 0, 0 },

  { "RampCoverLockingLever", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RampCoverLockingLever), 0, 0, 0 },

  { "RampCover", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RampCover),
    0, 0, 0 },

  { "RampHandle", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RampHandle),
    0, 0, 0 },

  { "RampEndSupport", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RampEndSupport), 0, 0, 0 },

  { "RampMiddleSupport", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RampMiddleSupport), 0, 0, 0 },

  { "WinderHandlesAccessCover", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, WinderHandlesAccessCover), 0, 0, 0 },

  { "LargeHandle", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LargeHandle), 0, 0, 0 },

  { "RampWinder", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RampWinder),
    0, 0, 0 },

  { "SmallHandle", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    SmallHandle), 0, 0, 0 },

  { "EmergencyDoorGasSpring", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    EmergencyDoorGasSpring), 0, 0, 0 },

  { "DoorWinder", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DoorWinder),
    0, 0, 0 },

  { "EBLR2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, EBLR2CB), 0, 0,
    0 },

  { "EBMVCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, EBMVCB), 0, 0,
    0 },

  { "EDCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, EDCB), 0, 0, 0 },

  { "ELCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ELCB1), 0, 0, 0
  },

  { "ELCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ELCB2), 0, 0, 0
  },

  { "ERCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ERCB), 0, 0, 0 },

  { "HCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HCB), 0, 0, 0 },

  { "HLLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HLLCB), 0, 0, 0
  },

  { "HLRCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HLRCB), 0, 0, 0
  },

  { "ILCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ILCB1), 0, 0, 0
  },

  { "ILCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ILCB2), 0, 0, 0
  },

  { "LDICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, LDICB), 0, 0, 0
  },

  { "LDLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, LDLCB), 0, 0, 0
  },

  { "LDRCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, LDRCB), 0, 0, 0
  },

  { "MLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MLCB), 0, 0, 0 },

  { "MMCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MMCB), 0, 0, 0 },

  { "NBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, NBCB), 0, 0, 0 },

  { "NVICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, NVICB), 0, 0, 0
  },

  { "OCCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, OCCB1), 0, 0, 0
  },

  { "OCCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, OCCB2), 0, 0, 0
  },

  { "ODDCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ODDCB), 0, 0, 0
  },

  { "PBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PBCB), 0, 0, 0 },

  { "PISCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PISCB1), 0, 0,
    0 },

  { "PISCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PISCB2), 0, 0,
    0 },

  { "POCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, POCB), 0, 0, 0 },

  { "PPU1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PPU1CB), 0, 0,
    0 },

  { "PPU2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PPU2CB), 0, 0,
    0 },

  { "PPU3CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PPU3CB), 0, 0,
    0 },

  { "RIO1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RIO1CB), 0, 0,
    0 },

  { "RIO2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RIO2CB), 0, 0,
    0 },

  { "SIOCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SIOCB1), 0, 0,
    0 },

  { "SIOCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SIOCB2), 0, 0,
    0 },

  { "SSICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SSICB), 0, 0, 0
  },

  { "TBCCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TBCCB1), 0, 0,
    0 },

  { "TBCCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TBCCB2), 0, 0,
    0 },

  { "TBNCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TBNCB), 0, 0, 0
  },

  { "TDICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TDICB), 0, 0, 0
  },

  { "TLLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TLLCB), 0, 0, 0
  },

  { "TLRCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TLRCB), 0, 0, 0
  },

  { "TRIVCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TRIVCB), 0, 0,
    0 },

  { "TVDUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TVDUCB), 0, 0,
    0 },

  { "TWVCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TWVCB), 0, 0, 0
  },

  { "VCCBOrUCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VCCBOrUCCB),
    0, 0, 0 },

  { "VCBCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VCBCCB), 0, 0,
    0 },

  { "VIO1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VIO1CB), 0, 0,
    0 },

  { "VIO2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VIO2CB), 0, 0,
    0 },

  { "WFLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, WFLCB), 0, 0, 0
  },

  { "WIFICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, WIFICB), 0, 0,
    0 },

  { "WWCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, WWCB), 0, 0, 0 },

  { "BECUCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BECUCB1), 0, 0,
    0 },

  { "BECUCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BECUCB2), 0, 0,
    0 },

  { "BECUCB3", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BECUCB3), 0, 0,
    0 },

  { "RSACB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RSACB), 0, 0, 0
  },

  { "CMCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CMCCB), 0, 0, 0
  },

  { "CILCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CILCB), 0, 0, 0
  },

  { "CICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CICB), 0, 0, 0 },

  { "CELCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CELCB), 0, 0, 0
  },

  { "CECB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CECB), 0, 0, 0 },

  { "CDUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CDUCB), 0, 0, 0
  },

  { "CCNVIO1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CCNVIO1CB),
    0, 0, 0 },

  { "CBTCCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CBTCCB1), 0, 0,
    0 },

  { "CBFCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CBFCCB), 0, 0,
    0 },

  { "CBFCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CBFCB), 0, 0, 0
  },

  { "C1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, C1CB), 0, 0, 0 },

  { "BLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BLCB), 0, 0, 0 },

  { "ZVBACB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ZVBACB), 0, 0,
    0 },

  { "EBLR1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, EBLR1CB), 0, 0,
    0 },

  { "DRCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DRCB), 0, 0, 0 },

  { "DPLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DPLCB), 0, 0, 0
  },

  { "DMICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DMICB), 0, 0, 0
  },

  { "DLCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DLCB), 0, 0, 0 },

  { "DIOCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DIOCB2), 0, 0,
    0 },

  { "DIOCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DIOCB1), 0, 0,
    0 },

  { "CSCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CSCCB), 0, 0, 0
  },

  { "CSBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CSBCB), 0, 0, 0
  },

  { "CSACB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CSACB), 0, 0, 0
  },

  { "CRSBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CRSBCB), 0, 0,
    0 },

  { "SOCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SOCB2), 0, 0, 0
  },

  { "SOCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SOCB1), 0, 0, 0
  },

  { "MSOCB5", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MSOCB5), 0, 0,
    0 },

  { "MSOCB4", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MSOCB4), 0, 0,
    0 },

  { "MSOCB3", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MSOCB3), 0, 0,
    0 },

  { "MSOCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MSOCB2), 0, 0,
    0 },

  { "MSOCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MSOCB1), 0, 0,
    0 },

  { "HVAC1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HVAC1), 0, 0, 0
  },

  { "SAC2CCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SAC2CCB), 0, 0,
    0 },

  { "HVAC2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HVAC2), 0, 0, 0
  },

  { "SAC1CCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SAC1CCB), 0, 0,
    0 },

  { "CMCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, CMCB), 0, 0, 0 },

  { "AC2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, AC2CB), 0, 0, 0
  },

  { "AC1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, AC1CB), 0, 0, 0
  },

  { "FDSCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, FDSCB), 0, 0, 0
  },

  { "BCBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BCBCB), 0, 0, 0
  },

  { "ERVRCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ERVRCB1), 0, 0,
    0 },

  { "ERVRCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ERVRCB2), 0, 0,
    0 },

  { "ESKCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ESKCB), 0, 0, 0
  },

  { "HMCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, HMCB), 0, 0, 0 },

  { "SP1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP1CB), 0, 0, 0
  },

  { "SP2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP2CB), 0, 0, 0
  },

  { "SP3CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP3CB), 0, 0, 0
  },

  { "SP4CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP4CB), 0, 0, 0
  },

  { "SP5CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP5CB), 0, 0, 0
  },

  { "SPCB6", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SPCB6), 0, 0, 0
  },

  { "SPCB7", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SPCB7), 0, 0, 0
  },

  { "SPCB8", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SPCB8), 0, 0, 0
  },

  { "RPTCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, RPTCB), 0, 0, 0
  },

  { "TERCB1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TERCB1), 0, 0,
    0 },

  { "TERCB2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, TERCB2), 0, 0,
    0 },

  { "SPSW", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SPSW), 0, 0, 0 },

  { "SPPB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SPPB), 0, 0, 0 },

  { "APSCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, APSCB), 0, 0, 0
  },

  { "APSICB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, APSICB), 0, 0,
    0 },

  { "BCGCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BCGCB), 0, 0, 0
  },

  { "DSCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, DSCB), 0, 0, 0 },

  { "MTBMCCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MTBMCCB), 0, 0,
    0 },

  { "PADCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PADCB), 0, 0, 0
  },

  { "PANCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PANCB), 0, 0, 0
  },

  { "SSCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SSCB), 0, 0, 0 },

  { "PTCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, PTCB), 0, 0, 0 },

  { "VCBCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, VCBCB), 0, 0, 0
  },

  { "SP12CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP12CB), 0, 0,
    0 },

  { "MTBM1CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MTBM1CB), 0, 0,
    0 },

  { "MTBM2CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MTBM2CB), 0, 0,
    0 },

  { "SP11CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP11CB), 0, 0,
    0 },

  { "SP6CB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SP6CB), 0, 0, 0
  },

  { "MTOPCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, MTOPCB), 0, 0,
    0 },

  { "ORDCOS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ORDCOS), 0, 0,
    0 },

  { "ADDCOS", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ADDCOS), 0, 0,
    0 },

  { "LeftDoor1DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1DCUCB), 0, 0, 0 },

  { "LeftDoor2DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2DCUCB), 0, 0, 0 },

  { "LeftDoor3DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3DCUCB), 0, 0, 0 },

  { "LeftDoor4DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4DCUCB), 0, 0, 0 },

  { "RightDoor1DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1DCUCB), 0, 0, 0 },

  { "RightDoor2DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2DCUCB), 0, 0, 0 },

  { "RightDoor3DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3DCUCB), 0, 0, 0 },

  { "RightDoor4DCUCB", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4DCUCB), 0, 0, 0 },

  { "LeftDoor1Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1Coving), 0, 0, 0 },

  { "LeftDoor2Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2Coving), 0, 0, 0 },

  { "LeftDoor3Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3Coving), 0, 0, 0 },

  { "LeftDoor4Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4Coving), 0, 0, 0 },

  { "RightDoor1Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1Coving), 0, 0, 0 },

  { "RightDoor2Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2Coving), 0, 0, 0 },

  { "RightDoor3Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3Coving), 0, 0, 0 },

  { "RightDoor4Coving", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4Coving), 0, 0, 0 },

  { "LeftDoor1EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1EED), 0, 0, 0 },

  { "LeftDoor2EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2EED), 0, 0, 0 },

  { "LeftDoor3EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3EED), 0, 0, 0 },

  { "LeftDoor4EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4EED), 0, 0, 0 },

  { "RightDoor1EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1EED), 0, 0, 0 },

  { "RightDoor2EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2EED), 0, 0, 0 },

  { "RightDoor3EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3EED), 0, 0, 0 },

  { "RightDoor4EED", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4EED), 0, 0, 0 },

  { "LeftDoor1ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1ManualClose), 0, 0, 0 },

  { "LeftDoor2ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2ManualClose), 0, 0, 0 },

  { "LeftDoor3ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3ManualClose), 0, 0, 0 },

  { "LeftDoor4ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4ManualClose), 0, 0, 0 },

  { "RightDoor1ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1ManualClose), 0, 0, 0 },

  { "RightDoor2ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2ManualClose), 0, 0, 0 },

  { "RightDoor3ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3ManualClose), 0, 0, 0 },

  { "RightDoor4ManualClose", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4ManualClose), 0, 0, 0 },

  { "LeftDoor1ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1ManualOpen), 0, 0, 0 },

  { "LeftDoor2ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2ManualOpen), 0, 0, 0 },

  { "LeftDoor3ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3ManualOpen), 0, 0, 0 },

  { "LeftDoor4ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4ManualOpen), 0, 0, 0 },

  { "RightDoor1ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1ManualOpen), 0, 0, 0 },

  { "RightDoor2ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2ManualOpen), 0, 0, 0 },

  { "RightDoor3ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3ManualOpen), 0, 0, 0 },

  { "RightDoor4ManualOpen", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4ManualOpen), 0, 0, 0 },

  { "LeftDoor1Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor1Lockout), 0, 0, 0 },

  { "LeftDoor2Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor2Lockout), 0, 0, 0 },

  { "LeftDoor3Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor3Lockout), 0, 0, 0 },

  { "LeftDoor4Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoor4Lockout), 0, 0, 0 },

  { "RightDoor1Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor1Lockout), 0, 0, 0 },

  { "RightDoor2Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor2Lockout), 0, 0, 0 },

  { "RightDoor3Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor3Lockout), 0, 0, 0 },

  { "RightDoor4Lockout", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoor4Lockout), 0, 0, 0 },

  { "LeftDoorEADCover", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoorEADCover), 0, 0, 0 },

  { "RightDoorEADCover", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoorEADCover), 0, 0, 0 },

  { "LeftDoorEAD", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    LeftDoorEAD), 0, 0, 0 },

  { "RightDoorEAD", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    RightDoorEAD), 0, 0, 0 },

  { "ParkBrakeIsolationCockBogie1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, ParkBrakeIsolationCockBogie1), 0, 0,
    0 },

  { "ParkBrakeIsolationCockBogie2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates, ParkBrakeIsolationCockBogie2), 0, 0,
    0 },

  { "MRIsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    MRIsolationCock), 0, 0, 0 },

  { "UncouplingCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    UncouplingCock), 0, 0, 0 },

  { "Horn1IsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    Horn1IsolationCock), 0, 0, 0 },

  { "Horn2IsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    Horn2IsolationCock), 0, 0, 0 },

  { "MREPIsolationCockEnd1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    MREPIsolationCockEnd1), 0, 0, 0 },

  { "BIC1Inside", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BIC1Inside),
    0, 0, 0 },

  { "BIC1Outside", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    BIC1Outside), 0, 0, 0 },

  { "BIC2Inside", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, BIC2Inside),
    0, 0, 0 },

  { "BIC2Outside", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    BIC2Outside), 0, 0, 0 },

  { "MREPIsolationCockEnd2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    MREPIsolationCockEnd2), 0, 0, 0 },

  { "EPIC", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, EPIC), 0, 0, 0 },

  { "ASCOEnd1", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ASCOEnd1), 0,
    0, 0 },

  { "ASCOEnd2", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ASCOEnd2), 0,
    0, 0 },

  { "ASIsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    ASIsolationCock), 0, 0, 0 },

  { "SR", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, SR), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie1Handle1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates,
     ParkingBrakeManualReleaseBogie1Handle1), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie1Handle2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates,
     ParkingBrakeManualReleaseBogie1Handle2), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie2Handle1", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates,
     ParkingBrakeManualReleaseBogie2Handle1), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie2Handle2", rt_offsetof
    (BD_IOControls_Out_Vehicle_InputStates,
     ParkingBrakeManualReleaseBogie2Handle2), 0, 0, 0 },

  { "PECUPushButton", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    PECUPushButton), 0, 0, 0 },

  { "Microphone", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, Microphone),
    0, 0, 0 },

  { "DriversBackDoor", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    DriversBackDoor), 0, 0, 0 },

  { "PantographIsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    PantographIsolationCock), 0, 0, 0 },

  { "VCBIsolationCock", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates,
    VCBIsolationCock), 0, 0, 0 },

  { "ORDPlunger", rt_offsetof(BD_IOControls_Out_Vehicle_InputStates, ORDPlunger),
    0, 0, 0 },

  { "ObjectObstructingDoorWhileClosing", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, ObjectObstructingDoorWhileClosing), 0, 0, 0 },

  { "ObjectObstructingDoorWhileOpening", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, ObjectObstructingDoorWhileOpening), 0, 0, 0 },

  { "DoorFailToClose", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorFailToClose),
    0, 0, 0 },

  { "DoorFailToOpen", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorFailToOpen),
    0, 0, 0 },

  { "DoorMotorCircuitFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorMotorCircuitFailure), 0, 0, 0 },

  { "DoorFailedToLock", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorFailedToLock), 0, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorFailedToUnlock), 0, 0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorUnexpectedUnlocking), 0, 0, 0 },

  { "DoorDCUFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorDCUFailure),
    0, 0, 0 },

  { "DCSRFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DCSRFailure), 0, 0,
    0 },

  { "DCSLFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DCSLFailure), 0, 0,
    0 },

  { "DLSRFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DLSRFailure), 0, 0,
    0 },

  { "DLSLFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DLSLFailure), 0, 0,
    0 },

  { "DoorMajorFault", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorMajorFault),
    0, 0, 0 },

  { "DoorUnauthorisedOpen", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorUnauthorisedOpen), 0, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, UnexpectedDoorOpeningDetectedByCC), 0, 0, 0 },

  { "EmergencyDoorMechanicalUnlocked", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    EmergencyDoorMechanicalUnlocked), 0, 0, 0 },

  { "DoorEmergencyHandleActivation", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorEmergencyHandleActivation), 0, 0, 0 },

  { "PantographDownForADDIntervention", rt_offsetof
    (BD_ElectricalSystem_In_Faults, PantographDownForADDIntervention), 0, 0, 0 },

  { "PantographDownForORDIntervention", rt_offsetof
    (BD_ElectricalSystem_In_Faults, PantographDownForORDIntervention), 0, 0, 0 },

  { "PantographRisingFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographRisingFailure), 0, 0, 0 },

  { "FwdRevTrainLineMismatch", rt_offsetof(BD_ElectricalSystem_In_Faults,
    FwdRevTrainLineMismatch), 0, 0, 0 },

  { "CCDetectedEmerDoorOpen", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CCDetectedEmerDoorOpen), 0, 0, 0 },

  { "LowMRPressure", rt_offsetof(BD_ElectricalSystem_In_Faults, LowMRPressure),
    14, 0, 0 },

  { "ReverseMotionInForwardCommand", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ReverseMotionInForwardCommand), 0, 0, 0 },

  { "BogieDerailed", rt_offsetof(BD_ElectricalSystem_In_Faults, BogieDerailed),
    0, 0, 0 },

  { "InternalFireAlarmTLActive", rt_offsetof(BD_ElectricalSystem_In_Faults,
    InternalFireAlarmTLActive), 0, 0, 0 },

  { "FDUFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, FDUFailure), 0, 0,
    0 },

  { "TractionCutModeSelectorInATPATOUTO", rt_offsetof
    (BD_ElectricalSystem_In_Faults, TractionCutModeSelectorInATPATOUTO), 0, 0, 0
  },

  { "DamagedOHE", rt_offsetof(BD_ElectricalSystem_In_Faults, DamagedOHE), 0, 0,
    0 },

  { "DoorsNotOpeningFromDOPBOP1", rt_offsetof(BD_ElectricalSystem_In_Faults,
    DoorsNotOpeningFromDOPBOP1), 0, 0, 0 },

  { "DepotSignalMalfunction", rt_offsetof(BD_ElectricalSystem_In_Faults,
    DepotSignalMalfunction), 0, 0, 0 },

  { "TrackCircuitOccupied", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TrackCircuitOccupied), 0, 0, 0 },

  { "MainSignalSwitchesToRed", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MainSignalSwitchesToRed), 0, 0, 0 },

  { "PlatformScreenDoorNotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PlatformScreenDoorNotWorking), 0, 0, 0 },

  { "TrainGettingZeroSpeedOrder", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TrainGettingZeroSpeedOrder), 0, 0, 0 },

  { "ATCEBUnableToReset", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ATCEBUnableToReset), 0, 0, 0 },

  { "TrainOvershootATCNotAllowingReverseAlignment", rt_offsetof
    (BD_ElectricalSystem_In_Faults, TrainOvershootATCNotAllowingReverseAlignment),
    0, 0, 0 },

  { "FSBAppliedAt10KMPH", rt_offsetof(BD_ElectricalSystem_In_Faults,
    FSBAppliedAt10KMPH), 0, 0, 0 },

  { "VEHICLE_LEVEL_SIGNALS_BELOW", rt_offsetof(BD_ElectricalSystem_In_Faults,
    VEHICLE_LEVEL_SIGNALS_BELOW), 0, 0, 0 },

  { "HVAC1SupplyFanMPCBTrip", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HVAC1SupplyFanMPCBTrip), 0, 0, 0 },

  { "HVAC1EmergencyInverterTrip", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HVAC1EmergencyInverterTrip), 0, 0, 0 },

  { "HVAC1RCCBTrip", rt_offsetof(BD_ElectricalSystem_In_Faults, HVAC1RCCBTrip),
    0, 0, 0 },

  { "HVAC1FireMode", rt_offsetof(BD_ElectricalSystem_In_Faults, HVAC1FireMode),
    0, 0, 0 },

  { "HVAC1ExternalSmokeMode", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HVAC1ExternalSmokeMode), 0, 0, 0 },

  { "HVAC1ReducedMode", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HVAC1ReducedMode), 0, 0, 0 },

  { "CabSaloonPartitionDoorOpen", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CabSaloonPartitionDoorOpen), 0, 0, 0 },

  { "WFLFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, WFLFailure), 0, 0,
    0 },

  { "ODDFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, ODDFailure), 0, 0,
    0 },

  { "ObstacleDetectedRightSide", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ObstacleDetectedRightSide), 0, 0, 0 },

  { "DerailmentDetectedRightSide", rt_offsetof(BD_ElectricalSystem_In_Faults,
    DerailmentDetectedRightSide), 0, 0, 0 },

  { "CouplingCircuitNotPowered", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CouplingCircuitNotPowered), 0, 0, 0 },

  { "CabEnablingCircuitBreakerTripped", rt_offsetof
    (BD_ElectricalSystem_In_Faults, CabEnablingCircuitBreakerTripped), 0, 0, 0 },

  { "OHLHighVoltageLevel3", rt_offsetof(BD_ElectricalSystem_In_Faults,
    OHLHighVoltageLevel3), 0, 0, 0 },

  { "OHLLowVoltageLevel2", rt_offsetof(BD_ElectricalSystem_In_Faults,
    OHLLowVoltageLevel2), 0, 0, 0 },

  { "LineConverterOverCurrentLevel2", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LineConverterOverCurrentLevel2), 0, 0, 0 },

  { "LineConverterIGBTFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LineConverterIGBTFailure), 0, 0, 0 },

  { "DC110VLowVoltage", rt_offsetof(BD_ElectricalSystem_In_Faults,
    DC110VLowVoltage), 0, 0, 0 },

  { "OverTemperatureOfInverterPowerUnit", rt_offsetof
    (BD_ElectricalSystem_In_Faults, OverTemperatureOfInverterPowerUnit), 0, 0, 0
  },

  { "OverTemperatureOfConverterPowerUnit", rt_offsetof
    (BD_ElectricalSystem_In_Faults, OverTemperatureOfConverterPowerUnit), 0, 0,
    0 },

  { "AKOpenFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, AKOpenFailure),
    0, 0, 0 },

  { "KOpenFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, KOpenFailure), 0,
    0, 0 },

  { "MainCircuitEarthFaultLevel2", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MainCircuitEarthFaultLevel2), 0, 0, 0 },

  { "VCBOpenedByCI", rt_offsetof(BD_ElectricalSystem_In_Faults, VCBOpenedByCI),
    14, 0, 0 },

  { "PantographDownForBUVDRIntervention", rt_offsetof
    (BD_ElectricalSystem_In_Faults, PantographDownForBUVDRIntervention), 0, 0, 0
  },

  { "PantographCircuitNotEnergized", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographCircuitNotEnergized), 0, 0, 0 },

  { "TransformerOilPressureTooLow", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilPressureTooLow), 0, 0, 0 },

  { "TransformerOilTemperatureTooHigh", rt_offsetof
    (BD_ElectricalSystem_In_Faults, TransformerOilTemperatureTooHigh), 0, 0, 0 },

  { "VCBOpenedByACOvercurrent", rt_offsetof(BD_ElectricalSystem_In_Faults,
    VCBOpenedByACOvercurrent), 14, 0, 0 },

  { "VCBOpenedByMTrProtection", rt_offsetof(BD_ElectricalSystem_In_Faults,
    VCBOpenedByMTrProtection), 14, 0, 0 },

  { "VCBOpenedByAPS", rt_offsetof(BD_ElectricalSystem_In_Faults, VCBOpenedByAPS),
    14, 0, 0 },

  { "PantographLoweringFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographLoweringFailure), 0, 0, 0 },

  { "MCBBrakeGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCBBrakeGroupTripped), 0, 0, 0 },

  { "MCBDoorGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCBDoorGroupTripped), 0, 0, 0 },

  { "MCB110VDCGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCB110VDCGroupTripped), 0, 0, 0 },

  { "MechanicalCouplerRelayFault", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MechanicalCouplerRelayFault), 0, 0, 0 },

  { "BatteryFuseBlown", rt_offsetof(BD_ElectricalSystem_In_Faults,
    BatteryFuseBlown), 0, 0, 0 },

  { "BICContactorActivationFault", rt_offsetof(BD_ElectricalSystem_In_Faults,
    BICContactorActivationFault), 0, 0, 0 },

  { "LowBatteryVoltageAlarm", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LowBatteryVoltageAlarm), 0, 0, 0 },

  { "LightGroupMCBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LightGroupMCBTripped), 0, 0, 0 },

  { "MCBHVACGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCBHVACGroupTripped), 0, 0, 0 },

  { "HVAC1MajorFault", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HVAC1MajorFault), 0, 0, 0 },

  { "MCBSignalingGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCBSignalingGroupTripped), 0, 0, 0 },

  { "APSMCBGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    APSMCBGroupTripped), 14, 0, 0 },

  { "APSCircuitBreakerTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    APSCircuitBreakerTripped), 14, 0, 0 },

  { "SmokeAlarmCABArea", rt_offsetof(BD_ElectricalSystem_In_Faults,
    SmokeAlarmCABArea), 0, 0, 0 },

  { "HeatAlarmEDB", rt_offsetof(BD_ElectricalSystem_In_Faults, HeatAlarmEDB), 0,
    0, 0 },

  { "TrainRadioFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TrainRadioFailure), 0, 0, 0 },

  { "PEA1AlarmActive", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PEA1AlarmActive), 0, 0, 0 },

  { "PEA1CallNotAcknowledged", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PEA1CallNotAcknowledged), 0, 0, 0 },

  { "PEA1Failure", rt_offsetof(BD_ElectricalSystem_In_Faults, PEA1Failure), 0, 0,
    0 },

  { "MCBPAGroupOpen", rt_offsetof(BD_ElectricalSystem_In_Faults, MCBPAGroupOpen),
    0, 0, 0 },

  { "CCUCommunicationError", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CCUCommunicationError), 0, 0, 0 },

  { "CommunicationErrorRIO1RIO2", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CommunicationErrorRIO1RIO2), 0, 0, 0 },

  { "MCBTCMSGroupTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    MCBTCMSGroupTripped), 0, 0, 0 },

  { "ER1MajorFault", rt_offsetof(BD_ElectricalSystem_In_Faults, ER1MajorFault),
    0, 0, 0 },

  { "EmerDoorNotOpenRelayDeactivated", rt_offsetof(BD_ElectricalSystem_In_Faults,
    EmerDoorNotOpenRelayDeactivated), 0, 0, 0 },

  { "AllDoorCloseIndicatorNotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    AllDoorCloseIndicatorNotWorking), 0, 0, 0 },

  { "TrainDoorLockedClosedRelayFailure", rt_offsetof
    (BD_ElectricalSystem_In_Faults, TrainDoorLockedClosedRelayFailure), 0, 0, 0
  },

  { "WipersNotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    WipersNotWorking), 0, 0, 0 },

  { "FloodLightNotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    FloodLightNotWorking), 0, 0, 0 },

  { "ShutdownFailureVCBOpening", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ShutdownFailureVCBOpening), 0, 0, 0 },

  { "LightGroupSaloonMCBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LightGroupSaloonMCBTripped), 0, 0, 0 },

  { "ExteriorLight1CBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ExteriorLight1CBTripped), 14, 0, 0 },

  { "ExteriorLight2CBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    ExteriorLight2CBTripped), 14, 0, 0 },

  { "InteriorLight1CBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    InteriorLight1CBTripped), 14, 0, 0 },

  { "InteriorLight2CBTripped", rt_offsetof(BD_ElectricalSystem_In_Faults,
    InteriorLight2CBTripped), 14, 0, 0 },

  { "CMCContactorActivationFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CMCContactorActivationFailure), 0, 0, 0 },

  { "CMCContactorDeactivationFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CMCContactorDeactivationFailure), 0, 0, 0 },

  { "APSGroup1Failure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    APSGroup1Failure), 0, 0, 0 },

  { "APSGroup1Isolated", rt_offsetof(BD_ElectricalSystem_In_Faults,
    APSGroup1Isolated), 0, 0, 0 },

  { "BCGGroup1Failure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    BCGGroup1Failure), 0, 0, 0 },

  { "BCGGroup1IsolationFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    BCGGroup1IsolationFailure), 0, 0, 0 },

  { "BCGGroup1Isolated", rt_offsetof(BD_ElectricalSystem_In_Faults,
    BCGGroup1Isolated), 0, 0, 0 },

  { "VCBMissingClosing", rt_offsetof(BD_ElectricalSystem_In_Faults,
    VCBMissingClosing), 14, 0, 0 },

  { "VCBMissingOpening", rt_offsetof(BD_ElectricalSystem_In_Faults,
    VCBMissingOpening), 14, 0, 0 },

  { "HeadlightFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HeadlightFailure), 0, 0, 0 },

  { "HornBlowsContinuously", rt_offsetof(BD_ElectricalSystem_In_Faults,
    HornBlowsContinuously), 0, 0, 0 },

  { "LineVoltageIndicatorNotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    LineVoltageIndicatorNotWorking), 0, 0, 0 },

  { "OtherCabOccupiedIndicatorFaulty", rt_offsetof(BD_ElectricalSystem_In_Faults,
    OtherCabOccupiedIndicatorFaulty), 0, 0, 0 },

  { "DoorClosePBOP1NotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    DoorClosePBOP1NotWorking), 0, 0, 0 },

  { "EmergencyBrakePBOP1NotWorking", rt_offsetof(BD_ElectricalSystem_In_Faults,
    EmergencyBrakePBOP1NotWorking), 0, 0, 0 },

  { "DoorCloseAnnouncementPBNotWorking", rt_offsetof
    (BD_ElectricalSystem_In_Faults, DoorCloseAnnouncementPBNotWorking), 0, 0, 0
  },

  { "ATCFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, ATCFailure), 0, 0,
    0 },

  { "DMIFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, DMIFailure), 0, 0,
    0 },

  { "TransformerOilLevelLow", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilLevelLow), 0, 0, 0 },

  { "TransformerOilLevelTooLow", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilLevelTooLow), 0, 0, 0 },

  { "TransformerOilFlowWarning", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilFlowWarning), 0, 0, 0 },

  { "TransformerOilPressureWarning", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilPressureWarning), 0, 0, 0 },

  { "TransformerOilTemperatureHigh", rt_offsetof(BD_ElectricalSystem_In_Faults,
    TransformerOilTemperatureHigh), 0, 0, 0 },

  { "PCUFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, PCUFailure), 0, 0,
    0 },

  { "PEA2Failure", rt_offsetof(BD_ElectricalSystem_In_Faults, PEA2Failure), 0, 0,
    0 },

  { "PEA3Failure", rt_offsetof(BD_ElectricalSystem_In_Faults, PEA3Failure), 0, 0,
    0 },

  { "SCU2Failure", rt_offsetof(BD_ElectricalSystem_In_Faults, SCU2Failure), 0, 0,
    0 },

  { "EBNotReleased", rt_offsetof(BD_ElectricalSystem_In_Faults, EBNotReleased),
    0, 0, 0 },

  { "CIMicroprocessorAbnormal", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CIMicroprocessorAbnormal), 0, 0, 0 },

  { "CILocalCommunicationFailure", rt_offsetof(BD_ElectricalSystem_In_Faults,
    CILocalCommunicationFailure), 0, 0, 0 },

  { "PantographRisingMissing", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographRisingMissing), 0, 0, 0 },

  { "PantographLoweringMissing", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographLoweringMissing), 0, 0, 0 },

  { "PantographRisingInhibited", rt_offsetof(BD_ElectricalSystem_In_Faults,
    PantographRisingInhibited), 0, 0, 0 },

  { "CIFailure", rt_offsetof(BD_ElectricalSystem_In_Faults, CIFailure), 0, 0, 0
  },

  { "CIIsolated", rt_offsetof(BD_ElectricalSystem_In_Faults, CIIsolated), 0, 0,
    0 },

  { "EmergencyBrakeDueToEBPB", rt_offsetof(BD_ElectricalSystem_In_Faults,
    EmergencyBrakeDueToEBPB), 0, 0, 0 },

  { "EmergencyBrakeDueDeadman", rt_offsetof(BD_ElectricalSystem_In_Faults,
    EmergencyBrakeDueDeadman), 0, 0, 0 },

  { "PlaceHolder", rt_offsetof(BD_PantographSystem_In_Vehicle_Faults,
    PlaceHolder), 0, 0, 0 },

  { "HeavyWheelSlip", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    HeavyWheelSlip), 0, 0, 0 },

  { "BECU1AxleLockedWheelSet1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BECU1AxleLockedWheelSet1), 0, 0, 0 },

  { "BECU1ServiceBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BECU1ServiceBrakeFailure), 0, 0, 0 },

  { "BECU1EmergencyBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BECU1EmergencyBrakeFailure), 0, 0, 0
  },

  { "AirSuspensionBogie1Deflated", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, AirSuspensionBogie1Deflated), 0, 0,
    0 },

  { "BrakeDemandSignalFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BrakeDemandSignalFailure), 0, 0, 0 },

  { "ParkingBrakeApplicationFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, ParkingBrakeApplicationFailure), 0,
    0, 0 },

  { "ParkingBrakeReleaseFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, ParkingBrakeReleaseFailure), 0, 0, 0
  },

  { "BECUMajorFault", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECUMajorFault), 0, 0, 0 },

  { "PressureGuageNotWorking", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    PressureGuageNotWorking), 0, 0, 0 },

  { "PantographPipeLowPressure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, PantographPipeLowPressure), 0, 0, 0
  },

  { "BECU2AxleLockedWheelSet2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BECU2AxleLockedWheelSet2), 0, 0, 0 },

  { "BECU2EmergencyBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_Faults, BECU2EmergencyBrakeFailure), 0, 0, 0
  },

  { "BECU1BrakeNotApplied", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECU1BrakeNotApplied), 0, 0, 0 },

  { "BECU1BrakeNotReleased", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECU1BrakeNotReleased), 0, 0, 0 },

  { "BECU1CarLoadPressureLow", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECU1CarLoadPressureLow), 0, 0, 0 },

  { "BECU2CarLoadPressureLow", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECU2CarLoadPressureLow), 0, 0, 0 },

  { "BECULowRPressure", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECULowRPressure), 0, 0, 0 },

  { "BECU1LoadPressureLow", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    BECU1LoadPressureLow), 0, 0, 0 },

  { "ORDIntervention", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_Faults,
    ORDIntervention), 0, 0, 0 },

  { "MasterControllerandTrainLineIncongruence", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_Faults, MasterControllerandTrainLineIncongruence),
    0, 0, 0 },

  { "TCMSDisplayHanged", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    TCMSDisplayHanged), 14, 0, 0 },

  { "TCMSFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults, TCMSFailure), 0,
    0, 0 },

  { "NeutralZoneVCBBackupFunctionActivated", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_Faults, NeutralZoneVCBBackupFunctionActivated), 14,
    0, 0 },

  { "CCUCommunicationError", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    CCUCommunicationError), 0, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_Faults, UnexpectedDoorOpeningDetectedByCC), 0, 0,
    0 },

  { "RIO1Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults, RIO1Fault), 0, 0,
    0 },

  { "RIO1RIO2Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults, RIO1RIO2Fault),
    0, 0, 0 },

  { "ERFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults, ERFault), 0, 0, 0 },

  { "TractionCutModeSelectorInATPATOUTO", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_Faults, TractionCutModeSelectorInATPATOUTO), 0, 0,
    0 },

  { "HighTractiveEffortRequired", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    HighTractiveEffortRequired), 0, 0, 0 },

  { "DynamicBrakeCutOut", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    DynamicBrakeCutOut), 0, 0, 0 },

  { "BECUPWRAndBRKCmdAtSameTime", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    BECUPWRAndBRKCmdAtSameTime), 0, 0, 0 },

  { "BECU2MinorFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    BECU2MinorFault), 0, 0, 0 },

  { "BECUMajorFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    BECUMajorFault), 0, 0, 0 },

  { "BECUMajorFaultWired", rt_offsetof(BD_TCMSSystem_In_Vehicle_Faults,
    BECUMajorFaultWired), 0, 0, 0 },

  { "TractionBogieFaulty", rt_offsetof(BD_TractionSystem_In_Faults_Bogie,
    TractionBogieFaulty), 0, 0, 0 },

  { "DynamicBrakeNotAvailable", rt_offsetof(BD_TractionSystem_In_Faults_Bogie,
    DynamicBrakeNotAvailable), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_In_Faults, Bogie), 34, 2, 0 },

  { "PCUFailure", rt_offsetof(BD_TractionSystem_In_Faults, PCUFailure), 0, 0, 0
  },

  { "CIFailure", rt_offsetof(BD_TractionSystem_In_Faults, CIFailure), 0, 0, 0 },

  { "CIIsolated", rt_offsetof(BD_TractionSystem_In_Faults, CIIsolated), 0, 0, 0
  },

  { "CIMicroprocessorAbnormal", rt_offsetof(BD_TractionSystem_In_Faults,
    CIMicroprocessorAbnormal), 0, 0, 0 },

  { "CILocalCommunicationFailure", rt_offsetof(BD_TractionSystem_In_Faults,
    CILocalCommunicationFailure), 0, 0, 0 },

  { "CIGateSignalAbnormal", rt_offsetof(BD_TractionSystem_In_Faults,
    CIGateSignalAbnormal), 0, 0, 0 },

  { "CITCMSCommunicationFailure", rt_offsetof(BD_TractionSystem_In_Faults,
    CITCMSCommunicationFailure), 0, 0, 0 },

  { "DCLinkOverVoltageLevel1", rt_offsetof(BD_TractionSystem_In_Faults,
    DCLinkOverVoltageLevel1), 0, 0, 0 },

  { "DCLinkLowVoltageLevel1", rt_offsetof(BD_TractionSystem_In_Faults,
    DCLinkLowVoltageLevel1), 0, 0, 0 },

  { "HeavyWheelSlide", rt_offsetof(BD_TractionSystem_In_Faults, HeavyWheelSlide),
    0, 0, 0 },

  { "HeavyWheelSlip", rt_offsetof(BD_TractionSystem_In_Faults, HeavyWheelSlip),
    0, 0, 0 },

  { "CIAKOpenFailure", rt_offsetof(BD_TractionSystem_In_Faults, CIAKOpenFailure),
    0, 0, 0 },

  { "CIKOpenFailure", rt_offsetof(BD_TractionSystem_In_Faults, CIKOpenFailure),
    0, 0, 0 },

  { "DerailmentDetectedRightSide", rt_offsetof(BD_TractionSystem_In_Faults,
    DerailmentDetectedRightSide), 0, 0, 0 },

  { "BogieDerailed", rt_offsetof(BD_TractionSystem_In_Faults, BogieDerailed), 0,
    0, 0 },

  { "WSPActiveBogie1", rt_offsetof(BD_TractionSystem_In_Faults, WSPActiveBogie1),
    0, 0, 0 },

  { "BECU1FailureAllSpeedSensors", rt_offsetof(BD_TractionSystem_In_Faults,
    BECU1FailureAllSpeedSensors), 0, 0, 0 },

  { "DoorFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    DoorFaults), 29, 0, 0 },

  { "ElectricalFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    ElectricalFaults), 30, 0, 0 },

  { "PantographFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    PantographFaults), 31, 0, 0 },

  { "PneumaticsFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    PneumaticsFaults), 32, 0, 0 },

  { "TCMSFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    TCMSFaults), 33, 0, 0 },

  { "TractionFaults", rt_offsetof(BD_SimIntegration_Faults_Vehicle_Processed,
    TractionFaults), 35, 0, 0 },

  { "VCBClosePBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, VCBClosePBLamp), 0, 0,
    0 },

  { "VCBOpenPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, VCBOpenPBLamp), 0, 0,
    0 },

  { "AllDoorsClosedLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, AllDoorsClosedLight),
    0, 0, 0 },

  { "EmergencyBrakePBLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, EmergencyBrakePBLight),
    0, 0, 0 },

  { "ParkBrakeApplyPBLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, ParkBrakeApplyPBLight),
    0, 0, 0 },

  { "BatteryVoltageGauge", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, BatteryVoltageGauge),
    0, 0, 0 },

  { "OverheadLineVoltageGauge", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     OverheadLineVoltageGauge), 0, 0, 0 },

  { "FloodLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, FloodLight), 0, 0, 0 },

  { "FlasherLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, FlasherLight), 0, 0, 0
  },

  { "UTOOrRMLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, UTOOrRMLight), 0, 0, 0
  },

  { "MarkerOrTailLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, MarkerOrTailLight), 0,
    0, 0 },

  { "HeadLight", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
    HeadLight), 0, 0, 0 },

  { "SignallingLights", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, SignallingLights), 0,
    0, 0 },

  { "IdentificationLights", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, IdentificationLights),
    0, 0, 0 },

  { "Speedometer", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, Speedometer), 0, 0, 0
  },

  { "WiperPosition", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, WiperPosition), 0, 0,
    0 },

  { "HornPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, HornPBLamp), 0, 0, 0 },

  { "LeftDoorClosePBOperatingPanel1Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     LeftDoorClosePBOperatingPanel1Lamp), 0, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel1Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     LeftDoorOpenPBOperatingPanel1Lamp), 0, 0, 0 },

  { "RightDoorOpenPBOperatingPanel1Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     RightDoorOpenPBOperatingPanel1Lamp), 0, 0, 0 },

  { "RightDoorClosePBOperatingPanel1Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     RightDoorClosePBOperatingPanel1Lamp), 0, 0, 0 },

  { "CabMainLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, CabMainLight), 0, 0, 0
  },

  { "CabConsoleLight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, CabConsoleLight), 0, 0,
    0 },

  { "DoorCloseAnnouncementLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     DoorCloseAnnouncementLamp), 0, 0, 0 },

  { "LampTestPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LampTestPBLamp), 0, 0,
    0 },

  { "UncouplePBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, UncouplePBLamp), 0, 0,
    0 },

  { "FlasherLightPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, FlasherLightPBLamp), 0,
    0, 0 },

  { "FloodLightPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, FloodLightPBLamp), 0,
    0, 0 },

  { "BatteryResetPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, BatteryResetPBLamp), 0,
    0, 0 },

  { "RightDoorOpenPBOperatingPanel5Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     RightDoorOpenPBOperatingPanel5Lamp), 0, 0, 0 },

  { "RightDoorClosePBOperatingPanel5Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     RightDoorClosePBOperatingPanel5Lamp), 0, 0, 0 },

  { "WFLTestPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, WFLTestPBLamp), 0, 0,
    0 },

  { "SaloonDoorCloseIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     SaloonDoorCloseIndicator), 0, 0, 0 },

  { "ParkBrakeOnPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, ParkBrakeOnPBLamp), 0,
    0, 0 },

  { "ParkBrakeOffPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, ParkBrakeOffPBLamp), 0,
    0, 0 },

  { "LineVoltageIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LineVoltageIndicator),
    0, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel2Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     LeftDoorOpenPBOperatingPanel2Lamp), 0, 0, 0 },

  { "LeftDoorClosePBOperatingPanel2Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     LeftDoorClosePBOperatingPanel2Lamp), 0, 0, 0 },

  { "PantoUpPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, PantoUpPBLamp), 0, 0,
    0 },

  { "PantoDownPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, PantoDownPBLamp), 0, 0,
    0 },

  { "LIMPHomePBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LIMPHomePBLamp), 0, 0,
    0 },

  { "PowerOFFPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, PowerOFFPBLamp), 0, 0,
    0 },

  { "CallOnLightPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, CallOnLightPBLamp), 0,
    0, 0 },

  { "APSFaultIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, APSFaultIndicator), 0,
    0, 0 },

  { "PowerFaultIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, PowerFaultIndicator),
    0, 0, 0 },

  { "EmergencyBrakeIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     EmergencyBrakeIndicator), 0, 0, 0 },

  { "VCBTripIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, VCBTripIndicator), 0,
    0, 0 },

  { "OtherCabOccupiedIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     OtherCabOccupiedIndicator), 0, 0, 0 },

  { "HVACFaultIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, HVACFaultIndicator), 0,
    0, 0 },

  { "ROSPBLamp", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
    ROSPBLamp), 0, 0, 0 },

  { "UTOPBLamp", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
    UTOPBLamp), 0, 0, 0 },

  { "ATOStartPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, ATOStartPBLamp), 0, 0,
    0 },

  { "EBResetPBLamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, EBResetPBLamp), 0, 0,
    0 },

  { "AuxModuleON", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, AuxModuleON), 0, 0, 0
  },

  { "LeftDoorOpenPB1OperatingPanel2Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     LeftDoorOpenPB1OperatingPanel2Lamp), 0, 0, 0 },

  { "RightDoorOpenPB1OperatingPanel5Lamp", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
     RightDoorOpenPB1OperatingPanel5Lamp), 0, 0, 0 },

  { "LeftDoor1LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LeftDoor1LEDIndicator),
    0, 0, 0 },

  { "LeftDoor2LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LeftDoor2LEDIndicator),
    0, 0, 0 },

  { "LeftDoor3LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LeftDoor3LEDIndicator),
    0, 0, 0 },

  { "LeftDoor4LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, LeftDoor4LEDIndicator),
    0, 0, 0 },

  { "RightDoor1LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, RightDoor1LEDIndicator),
    0, 0, 0 },

  { "RightDoor2LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, RightDoor2LEDIndicator),
    0, 0, 0 },

  { "RightDoor3LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, RightDoor3LEDIndicator),
    0, 0, 0 },

  { "RightDoor4LEDIndicator", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, RightDoor4LEDIndicator),
    0, 0, 0 },

  { "WiperPositionLeft", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, WiperPositionLeft), 0,
    0, 0 },

  { "WiperPositionCenter", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, WiperPositionCenter),
    0, 0, 0 },

  { "WiperPositionRight", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_OutputControlStates, WiperPositionRight), 0,
    0, 0 },

  { "WiperWash", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_OutputControlStates,
    WiperWash), 0, 0, 0 },

  { "TCUPowerAvailable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    TCUPowerAvailable), 14, 0, 0 },

  { "MotorPowerAvailable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    MotorPowerAvailable), 14, 0, 0 },

  { "ForwardDirection", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    ForwardDirection), 14, 0, 0 },

  { "ReverseDirection", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    ReverseDirection), 14, 0, 0 },

  { "TBCTraction", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    TBCTraction), 14, 0, 0 },

  { "TBCNotBraking", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    TBCNotBraking), 14, 0, 0 },

  { "TractionSafe", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    TractionSafe), 14, 0, 0 },

  { "NoEmergencyBrake", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    NoEmergencyBrake), 14, 0, 0 },

  { "VCBStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction, VCBStatus),
    14, 0, 0 },

  { "ContactorsFailure", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    ContactorsFailure), 14, 0, 0 },

  { "CIIsolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Traction,
    CIIsolated), 0, 0, 0 },

  { "BCUPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Braking, BCUPower),
    14, 0, 0 },

  { "TBCTraction", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Braking,
    TBCTraction), 14, 0, 0 },

  { "TBCNotBraking", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Braking,
    TBCNotBraking), 14, 0, 0 },

  { "NoEB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Braking, NoEB), 14, 0, 0
  },

  { "DeadmanVigilance", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Braking,
    DeadmanVigilance), 14, 0, 0 },

  { "TCMSPowerAvailable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    TCMSPowerAvailable), 14, 0, 0 },

  { "HMIPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HMIPower), 14,
    0, 0 },

  { "CabActive", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, CabActive),
    14, 0, 0 },

  { "ForwardDirection", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ForwardDirection), 14, 0, 0 },

  { "ReverseDirection", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ReverseDirection), 14, 0, 0 },

  { "TractionOn", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, TractionOn),
    14, 0, 0 },

  { "BrakeOn", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BrakeOn), 14, 0,
    0 },

  { "TractionSafe", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    TractionSafe), 14, 0, 0 },

  { "AllRightDoorsClosed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    AllRightDoorsClosed), 14, 0, 0 },

  { "AllLeftDoorsClosed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    AllLeftDoorsClosed), 14, 0, 0 },

  { "ServiceBrakesReleased", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ServiceBrakesReleased), 14, 0, 0 },

  { "ParkBrakesReleased", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ParkBrakesReleased), 14, 0, 0 },

  { "ParkBrakeApplication", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ParkBrakeApplication), 14, 0, 0 },

  { "ServiceBrakeApplication", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ServiceBrakeApplication), 14, 0, 0 },

  { "PantoLowered", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PantoLowered), 14, 0, 0 },

  { "PantoRaised", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, PantoRaised),
    14, 0, 0 },

  { "PantoPowerDetected", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PantoPowerDetected), 14, 0, 0 },

  { "ZeroSpeed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, ZeroSpeed),
    14, 0, 0 },

  { "Speedometer", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, Speedometer),
    0, 0, 0 },

  { "VCBState", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, VCBState), 14,
    0, 0 },

  { "APSKContactorState", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APSKContactorState), 14, 0, 0 },

  { "APSAKContactorState", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APSAKContactorState), 14, 0, 0 },

  { "FilterVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    FilterVoltage), 0, 0, 0 },

  { "APS1Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, APS1Status),
    14, 0, 0 },

  { "APS2Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, APS2Status),
    14, 0, 0 },

  { "BCG1Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BCG1Status),
    14, 0, 0 },

  { "BCG2Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BCG2Status),
    14, 0, 0 },

  { "BCGOutputVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCGOutputVoltage), 0, 0, 0 },

  { "BatteryVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BatteryVoltage), 0, 0, 0 },

  { "BatteryCurrent", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BatteryCurrent), 0, 0, 0 },

  { "BatteryTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BatteryTemperature), 0, 0, 0 },

  { "BCG1OutputCurrent", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCG1OutputCurrent), 0, 0, 0 },

  { "BCG2OutputCurrent", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCG2OutputCurrent), 0, 0, 0 },

  { "NoBrakeTrainLine", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    NoBrakeTrainLine), 14, 0, 0 },

  { "MotorTrainLine", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MotorTrainLine), 14, 0, 0 },

  { "NoFSB1Line", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, NoFSB1Line),
    14, 0, 0 },

  { "NoFSB2Line", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, NoFSB2Line),
    14, 0, 0 },

  { "NoEB1Line", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, NoEB1Line),
    14, 0, 0 },

  { "NoEB2Line", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, NoEB2Line),
    14, 0, 0 },

  { "LineVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, LineVoltage),
    0, 0, 0 },

  { "NoEB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, NoEB), 14, 0, 0 },

  { "APS1OutputVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APS1OutputVoltage), 0, 0, 0 },

  { "APS2OutputVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APS2OutputVoltage), 0, 0, 0 },

  { "HLSwitchStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HLSwitchStatus), 14, 0, 0 },

  { "MarkerAndTailLight", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MarkerAndTailLight), 0, 0, 0 },

  { "TCMS_FL_Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    TCMS_FL_Status), 14, 0, 0 },

  { "TCMS_CallOn_Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    TCMS_CallOn_Status), 14, 0, 0 },

  { "UTOOrRMLight", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    UTOOrRMLight), 0, 0, 0 },

  { "PADPBStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, PADPBStatus),
    14, 0, 0 },

  { "PADRStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, PADRStatus),
    14, 0, 0 },

  { "TPOR_ON", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, TPOR_ON), 0, 0,
    0 },

  { "TSDR_ON", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, TSDR_ON), 14, 0,
    0 },

  { "PowerONPBPressed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PowerONPBPressed), 0, 0, 0 },

  { "PowerOFFPBPressed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PowerOFFPBPressed), 14, 0, 0 },

  { "LeftDoorEnable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    LeftDoorEnable), 14, 0, 0 },

  { "RightDoorEnable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    RightDoorEnable), 14, 0, 0 },

  { "LeftHoldDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    LeftHoldDoorClose), 14, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    RightHoldDoorClose), 14, 0, 0 },

  { "LimpHomeMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    LimpHomeMode), 14, 0, 0 },

  { "FwdRevTrainLineMismatchMessage", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_TCMS, FwdRevTrainLineMismatchMessage), 14,
    0, 0 },

  { "LowMRPressureFaultMessage", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_TCMS, LowMRPressureFaultMessage), 14, 0, 0
  },

  { "BCUPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BCUPower), 14,
    0, 0 },

  { "APS1Fault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, APS1Fault),
    14, 0, 0 },

  { "APS2Fault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, APS2Fault),
    14, 0, 0 },

  { "APS1Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APS1Isolated), 14, 0, 0 },

  { "APS2Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APS2Isolated), 14, 0, 0 },

  { "SaloonLightGroupStatus1", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    SaloonLightGroupStatus1), 0, 0, 0 },

  { "SaloonLightGroupStatus2", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    SaloonLightGroupStatus2), 0, 0, 0 },

  { "WFLStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, WFLStatus), 0,
    0, 0 },

  { "WFLOilLevelStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    WFLOilLevelStatus), 0, 0, 0 },

  { "WFLPump1Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    WFLPump1Status), 0, 0, 0 },

  { "WFLPump2Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    WFLPump2Status), 0, 0, 0 },

  { "WFLFailure", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, WFLFailure),
    0, 0, 0 },

  { "BatteryIsolationContactor", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_TCMS, BatteryIsolationContactor), 14, 0, 0
  },

  { "TrainControlContactor", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    TrainControlContactor), 14, 0, 0 },

  { "MainCompressor", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MainCompressor), 14, 0, 0 },

  { "AuxCompressor", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    AuxCompressor), 14, 0, 0 },

  { "HVAC1Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HVAC1Status),
    0, 0, 0 },

  { "HVAC1SetPointTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC1SetPointTemperature), 0, 0, 0 },

  { "HVAC1IntTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC1IntTemperature), 0, 0, 0 },

  { "HVAC1ExtTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC1ExtTemperature), 0, 0, 0 },

  { "HVAC1Faulty", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HVAC1Faulty),
    14, 0, 0 },

  { "HVAC1Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC1Isolated), 14, 0, 0 },

  { "HVAC2Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HVAC2Status),
    0, 0, 0 },

  { "HVAC2SetPointTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC2SetPointTemperature), 0, 0, 0 },

  { "HVAC2IntTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC2IntTemperature), 0, 0, 0 },

  { "HVAC2ExtTemperature", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC2ExtTemperature), 0, 0, 0 },

  { "HVAC2Faulty", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HVAC2Faulty),
    14, 0, 0 },

  { "HVAC2Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HVAC2Isolated), 14, 0, 0 },

  { "PECStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, PECStatus),
    14, 0, 0 },

  { "EBbyNonCabEnabled", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    EBbyNonCabEnabled), 14, 0, 0 },

  { "EBbyMC", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, EBbyMC), 14, 0,
    0 },

  { "EBbyBrakeLoop", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    EBbyBrakeLoop), 14, 0, 0 },

  { "EBbyDeadMan", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, EBbyDeadMan),
    14, 0, 0 },

  { "NoLineVoltage", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    NoLineVoltage), 14, 0, 0 },

  { "D1Power", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, D1Power), 14, 0,
    0 },

  { "EBbyCC", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, EBbyCC), 14, 0,
    0 },

  { "EBdueToATCZeroSpeed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    EBdueToATCZeroSpeed), 14, 0, 0 },

  { "HVACFaults", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, HVACFaults),
    0, 4, 0 },

  { "ADDCOSStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ADDCOSStatus), 14, 0, 0 },

  { "ORDCOSStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ORDCOSStatus), 14, 0, 0 },

  { "MRIsolation", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, MRIsolation),
    14, 0, 0 },

  { "MCBPAGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, MCBPAGroup),
    14, 0, 0 },

  { "MCB110VDCGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCB110VDCGroup), 14, 0, 0 },

  { "MCBLightGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBLightGroup), 14, 0, 0 },

  { "MCBLightSaloonGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBLightSaloonGroup), 14, 0, 0 },

  { "MCBDoorGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBDoorGroup), 14, 0, 0 },

  { "MCBBrakeGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBBrakeGroup), 14, 0, 0 },

  { "MCBAPSGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, MCBAPSGroup),
    14, 0, 0 },

  { "MCBTCMSGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBTCMSGroup), 14, 0, 0 },

  { "MCBSignallingGroup", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBSignallingGroup), 14, 0, 0 },

  { "VCBTripCommand", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    VCBTripCommand), 14, 0, 0 },

  { "CECBTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, CECBTripped),
    14, 0, 0 },

  { "UCCBTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, UCCBTripped),
    14, 0, 0 },

  { "PANCBTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PANCBTripped), 14, 0, 0 },

  { "ELCB1Tripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ELCB1Tripped), 14, 0, 0 },

  { "ELCB2Tripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ELCB2Tripped), 14, 0, 0 },

  { "ILCB1Tripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ILCB1Tripped), 14, 0, 0 },

  { "ILCB2Tripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ILCB2Tripped), 14, 0, 0 },

  { "APSCBTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    APSCBTripped), 14, 0, 0 },

  { "FDUFailure", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, FDUFailure),
    14, 0, 0 },

  { "InternalFireAlarmTLActive", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_TCMS, InternalFireAlarmTLActive), 14, 0, 0
  },

  { "SmokeAlarmCABArea", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    SmokeAlarmCABArea), 14, 0, 0 },

  { "HeatAlarmEDB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    HeatAlarmEDB), 14, 0, 0 },

  { "FDUStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, FDUStatus),
    14, 0, 0 },

  { "SFARStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, SFARStatus),
    14, 0, 0 },

  { "UFARStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, UFARStatus),
    14, 0, 0 },

  { "BUVDR_Active", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BUVDR_Active), 14, 0, 0 },

  { "CMCActivationFault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    CMCActivationFault), 14, 0, 0 },

  { "CMCDeactivationFault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    CMCDeactivationFault), 14, 0, 0 },

  { "UW_VCB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, UW_VCB), 0, 0, 0
  },

  { "PantoIsolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PantoIsolated), 0, 0, 0 },

  { "VCBIsolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, VCBIsolated),
    0, 0, 0 },

  { "PantoDownPBCmd", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    PantoDownPBCmd), 0, 0, 0 },

  { "VCBTripByCI", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, VCBTripByCI),
    0, 0, 0 },

  { "CIIsolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, CIIsolated),
    0, 0, 0 },

  { "BCG1Fault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BCG1Fault), 0,
    0, 0 },

  { "BCG2Fault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, BCG2Fault), 0,
    0, 0 },

  { "BCG1Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCG1Isolated), 0, 0, 0 },

  { "BCG2Isolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCG2Isolated), 0, 0, 0 },

  { "BCG1IsolationFailed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BCG1IsolationFailed), 0, 0, 0 },

  { "EBbyPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, EBbyPB), 14, 0,
    0 },

  { "VCBTripByAPS", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    VCBTripByAPS), 0, 0, 0 },

  { "MCDR", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, MCDR), 14, 0, 0 },

  { "MCDRFaulty", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, MCDRFaulty),
    14, 0, 0 },

  { "ObstacleDetected", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    ObstacleDetected), 14, 0, 0 },

  { "ODDFailure", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, ODDFailure),
    0, 0, 0 },

  { "MCBHVACGroupTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    MCBHVACGroupTripped), 14, 0, 0 },

  { "PANPSR", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, PANPSR), 0, 0, 0
  },

  { "Key_Switch_Status", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    Key_Switch_Status), 0, 0, 0 },

  { "VCBI_ACOvercurrent", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    VCBI_ACOvercurrent), 0, 0, 0 },

  { "VCBI_KAKContactorCI", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    VCBI_KAKContactorCI), 0, 0, 0 },

  { "EmergencyDoorNotOpenStatus", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_TCMS, EmergencyDoorNotOpenStatus), 0, 0, 0
  },

  { "DoorProvenLoopOK", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    DoorProvenLoopOK), 0, 0, 0 },

  { "BrakeLoopCBTripped", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BrakeLoopCBTripped), 0, 0, 0 },

  { "DeadmanBypassStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    DeadmanBypassStatus), 14, 0, 0 },

  { "BLCOSwitchStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS,
    BLCOSwitchStatus), 14, 0, 0 },

  { "WFLIsolated", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_TCMS, WFLIsolated),
    0, 0, 0 },

  { "ParkBrakeApplicationValve", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Pneumatics, ParkBrakeApplicationValve), 14,
    0, 0 },

  { "ParkBrakeRelease", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics,
    ParkBrakeRelease), 14, 0, 0 },

  { "PantographRaiseValve", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Pneumatics, PantographRaiseValve), 14, 0, 0
  },

  { "MainCompressorMotorPower", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Pneumatics, MainCompressorMotorPower), 14,
    0, 0 },

  { "AuxCompressorMotorPower", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Pneumatics, AuxCompressorMotorPower), 14, 0,
    0 },

  { "RemoteMagnetValve1", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics,
    RemoteMagnetValve1), 14, 0, 0 },

  { "RemoteMagnetValve2", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics,
    RemoteMagnetValve2), 14, 0, 0 },

  { "HornLow", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics, HornLow),
    14, 0, 0 },

  { "HornHigh", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics, HornHigh),
    14, 0, 0 },

  { "RemoteHornIsolate", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics,
    RemoteHornIsolate), 14, 0, 0 },

  { "VCBCloseCmd", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pneumatics,
    VCBCloseCmd), 14, 0, 0 },

  { "LeftDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    LeftDoorClose), 14, 0, 0 },

  { "RightDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    RightDoorClose), 14, 0, 0 },

  { "LeftDoorOpen", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    LeftDoorOpen), 14, 0, 0 },

  { "RightDoorOpen", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    RightDoorOpen), 14, 0, 0 },

  { "LeftDoorRelease", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    LeftDoorRelease), 14, 0, 0 },

  { "RightDoorRelease", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    RightDoorRelease), 14, 0, 0 },

  { "ObstacleDetectionDisabled", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Doors, ObstacleDetectionDisabled), 14, 0, 0
  },

  { "ZeroSpeed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors, ZeroSpeed),
    14, 0, 0 },

  { "DCUPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors, DCUPower), 14,
    3, 0 },

  { "DoorMotorPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    DoorMotorPower), 14, 0, 0 },

  { "LeftDoorOpenCmdInLimpHome", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Doors, LeftDoorOpenCmdInLimpHome), 14, 0, 0
  },

  { "RightDoorOpenCmdInLimpHome", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Doors, RightDoorOpenCmdInLimpHome), 14, 0,
    0 },

  { "LeftDoorEnable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    LeftDoorEnable), 14, 0, 0 },

  { "RightDoorEnable", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    RightDoorEnable), 14, 0, 0 },

  { "LeftHoldDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    LeftHoldDoorClose), 14, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    RightHoldDoorClose), 14, 0, 0 },

  { "EmerDoorLatched", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    EmerDoorLatched), 14, 0, 0 },

  { "EmerDoorOpenFault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Doors,
    EmerDoorOpenFault), 14, 0, 0 },

  { "PantoUpCommand", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoUpCommand), 14, 0, 0 },

  { "PantoDownCommand", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoDownCommand), 14, 0, 0 },

  { "PantoControlPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoControlPower), 14, 0, 0 },

  { "PantoMotorPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoMotorPower), 14, 0, 0 },

  { "PantoADDFault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoADDFault), 14, 0, 0 },

  { "PantoORDFault", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoORDFault), 14, 0, 0 },

  { "PantoRaiseFailure", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Pantograph,
    PantoRaiseFailure), 14, 0, 0 },

  { "PantoLoweringFailure", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Pantograph, PantoLoweringFailure), 14, 0, 0
  },

  { "ATCPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ATCPower),
    0, 0, 0 },

  { "ATOStartPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    ATOStartPB), 0, 0, 0 },

  { "UTOStartPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    UTOStartPB), 0, 0, 0 },

  { "ATCSafetyBrakeResetPB", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_SignalSys, ATCSafetyBrakeResetPB), 0, 0, 0
  },

  { "NotSafetyBrake", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    NotSafetyBrake), 0, 0, 0 },

  { "CabActive", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    CabActive), 0, 0, 0 },

  { "UTOMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, UTOMode),
    0, 0, 0 },

  { "TBCInFSB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, TBCInFSB),
    0, 0, 0 },

  { "RMFMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, RMFMode),
    0, 0, 0 },

  { "DoorEnableBypass", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    DoorEnableBypass), 0, 0, 0 },

  { "TrainDoorClosedAndLocked", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_SignalSys, TrainDoorClosedAndLocked), 0, 0,
    0 },

  { "RMRMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, RMRMode),
    0, 0, 0 },

  { "NoATCBypass", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    NoATCBypass), 0, 0, 0 },

  { "TrainIntegrity", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    TrainIntegrity), 0, 0, 0 },

  { "DMIPower", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, DMIPower),
    0, 0, 0 },

  { "ATOMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ATOMode),
    0, 0, 0 },

  { "ATBMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ATBMode),
    0, 0, 0 },

  { "ROSMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ROSMode),
    0, 0, 0 },

  { "ATPMode", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ATPMode),
    0, 0, 0 },

  { "EmergencyDoorNotOpen", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_SignalSys, EmergencyDoorNotOpen), 0, 0, 0 },

  { "WakeUpStatus", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    WakeUpStatus), 0, 0, 0 },

  { "PassengerEmergencyAlarm", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_SignalSys, PassengerEmergencyAlarm), 0, 0,
    0 },

  { "FireSmokeInd", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    FireSmokeInd), 0, 0, 0 },

  { "MechanicalCoupling", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    MechanicalCoupling), 0, 0, 0 },

  { "ROSPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, ROSPB), 0, 0,
    0 },

  { "UTBPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys, UTBPB), 0, 0,
    0 },

  { "LeftDoorOpenPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    LeftDoorOpenPB), 0, 0, 0 },

  { "RightDoorOpenPB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    RightDoorOpenPB), 0, 0, 0 },

  { "LeftDoorClosePB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    LeftDoorClosePB), 0, 0, 0 },

  { "RightDoorClosePB", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_SignalSys,
    RightDoorClosePB), 0, 0, 0 },

  { "ElectricalCouplerState", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_Coupling, ElectricalCouplerState), 0, 0, 0
  },

  { "UncoupleCmd", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Coupling,
    UncoupleCmd), 0, 0, 0 },

  { "VCBOpen", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio, VCBOpen), 14,
    0, 0 },

  { "VCBClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio, VCBClose), 14,
    0, 0 },

  { "CompressorOn", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio,
    CompressorOn), 14, 0, 0 },

  { "WiperOn", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio, WiperOn), 14,
    0, 0 },

  { "DeadmanVigilance", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio,
    DeadmanVigilance), 14, 0, 0 },

  { "FlasherLightSound", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio,
    FlasherLightSound), 14, 0, 0 },

  { "ObstacleSoftCollision", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Audio,
    ObstacleSoftCollision), 0, 0, 0 },

  { "DeadmanRelay", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_Scoring,
    DeadmanRelay), 14, 0, 0 },

  { "PAPIS_CCTV_Power", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, PAPIS_CCTV_Power), 0, 0,
    0 },

  { "DoorCloseAnnouncement", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, DoorCloseAnnouncement),
    0, 0, 0 },

  { "DoorOpen", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS,
    DoorOpen), 0, 0, 0 },

  { "DoorClose", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS,
    DoorClose), 0, 0, 0 },

  { "EmergencyDoorOpen", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, EmergencyDoorOpen), 0, 0,
    0 },

  { "CabActive", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS,
    CabActive), 0, 0, 0 },

  { "AllDoorClose", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, AllDoorClose), 0, 0, 0 },

  { "ZeroSpeed", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS,
    ZeroSpeed), 0, 0, 0 },

  { "PECUAlarmActive", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, PECUAlarmActive), 0, 0,
    0 },

  { "Couple", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS,
    Couple), 0, 0, 0 },

  { "FrontObstacleDetected", rt_offsetof
    (BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS, FrontObstacleDetected),
    0, 0, 0 },

  { "PAPIS", rt_offsetof(BD_ElectricalSystem_Out_Vehicle_MiscOutputs, PAPIS), 48,
    0, 0 },

  { "OutputControlStates", rt_offsetof(BD_ElectricalSystem_Out_Vehicle,
    OutputControlStates), 37, 0, 0 },

  { "Traction", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Traction), 38, 0, 0
  },

  { "Braking", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Braking), 39, 0, 0 },

  { "TCMS", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, TCMS), 40, 0, 0 },

  { "Pneumatics", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Pneumatics), 41,
    0, 0 },

  { "Doors", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Doors), 42, 0, 0 },

  { "Pantograph", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Pantograph), 43,
    0, 0 },

  { "SignalSys", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, SignalSys), 44, 0,
    0 },

  { "CouplingSystem", rt_offsetof(BD_ElectricalSystem_Out_Vehicle,
    CouplingSystem), 45, 0, 0 },

  { "Audio", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Audio), 46, 0, 0 },

  { "Scoring", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, Scoring), 47, 0, 0 },

  { "MiscOutputs", rt_offsetof(BD_ElectricalSystem_Out_Vehicle, MiscOutputs), 49,
    0, 0 },

  { "TrainDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainDoorInterlockOk), 14, 0,
    0 },

  { "VehicleDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleDoorInterlockOk), 14, 0,
    0 },

  { "TrainLeftDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainLeftDoorInterlockOk), 14,
    0, 0 },

  { "TrainRightDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainRightDoorInterlockOk), 14,
    0, 0 },

  { "VehicleLeftDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleLeftDoorInterlockOk),
    14, 0, 0 },

  { "VehicleRightDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleRightDoorInterlockOk),
    14, 0, 0 },

  { "DoorCloseInterlock", rt_offsetof(BD_DoorSystem_Out_Door_ElectricalSignals,
    DoorCloseInterlock), 14, 0, 0 },

  { "DoorClosed", rt_offsetof(BD_DoorSystem_Out_Door_ElectricalSignals,
    DoorClosed), 14, 0, 0 },

  { "DoorPosition", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorPosition), 0, 0, 0 },

  { "DoorOutsideLamp", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorOutsideLamp), 0, 0, 0 },

  { "DoorInsideLamp", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorInsideLamp), 0, 0, 0 },

  { "DoorOpeningAuthorised", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorOpeningAuthorised), 0, 0, 0 },

  { "DoorOpeningAlarm", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorOpeningAlarm), 0, 0, 0 },

  { "DoorClosingAlarm", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorClosingAlarm), 0, 0, 0 },

  { "DoorEmergencyReleased", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorEmergencyReleased), 0, 0, 0 },

  { "DoorIsolated", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorIsolated), 0,
    0, 0 },

  { "DoorClosing", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorClosing), 0, 0,
    0 },

  { "DoorOpening", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorOpening), 0, 0,
    0 },

  { "DoorOpenObstacleDetected", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorOpenObstacleDetected), 14, 0, 0 },

  { "DoorCloseObstacleDetected", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS_Messages, DoorCloseObstacleDetected), 14, 0, 0
  },

  { "DoorFailedToLock", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorFailedToLock), 14, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorFailedToUnlock), 14, 0, 0 },

  { "DoorMotorFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorMotorFailure), 14, 0, 0 },

  { "DoorMajorFault", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorMajorFault), 14, 0, 0 },

  { "DCSRFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCSRFailure),
    14, 0, 0 },

  { "DCSLFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCSLFailure),
    14, 0, 0 },

  { "DLSRFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DLSRFailure),
    14, 0, 0 },

  { "DLSLFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DLSLFailure),
    14, 0, 0 },

  { "DCUFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCUFailure),
    14, 0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorUnexpectedUnlocking), 14, 0, 0 },

  { "DoorIsolatedWire", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorIsolatedWire), 14, 0, 0 },

  { "DoorEmergencyHandleWire", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorEmergencyHandleWire), 14, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS_Messages, UnexpectedDoorOpeningDetectedByCC),
    14, 0, 0 },

  { "DoorClosedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorClosedStatus), 14, 0, 0 },

  { "DoorOpenStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorOpenStatus),
    14, 0, 0 },

  { "DoorReleasedAuthorisedToOpenStatus", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS, DoorReleasedAuthorisedToOpenStatus), 14, 0, 0
  },

  { "DoorEmergencyReleasedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorEmergencyReleasedStatus), 14, 0, 0 },

  { "DoorIsolatedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorIsolatedStatus), 14, 0, 0 },

  { "DoorFaultStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorFaultStatus),
    14, 0, 0 },

  { "DoorObstacleDetected", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorObstacleDetected), 14, 0, 0 },

  { "DoorObstacleUnableToClose", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorObstacleUnableToClose), 14, 0, 0 },

  { "DoorLockedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorLockedStatus), 14, 0, 0 },

  { "DoorOpenPBLight", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorOpenPBLight),
    14, 0, 0 },

  { "DoorClosedPBLight", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorClosedPBLight), 14, 0, 0 },

  { "Messages", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, Messages), 55, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_DoorSystem_Out_Door, ElectricalSignals),
    52, 0, 0 },

  { "OutputControlStates", rt_offsetof(BD_DoorSystem_Out_Door,
    OutputControlStates), 53, 0, 0 },

  { "Audio", rt_offsetof(BD_DoorSystem_Out_Door, Audio), 54, 0, 0 },

  { "TCMS", rt_offsetof(BD_DoorSystem_Out_Door, TCMS), 56, 0, 0 },

  { "Ramp", rt_offsetof(BD_DoorSystem_Out_Emergency_Door, Ramp), 0, 0, 0 },

  { "EmergencyDoorOpen", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmergencyDoorOpen), 0, 0, 0 },

  { "EmergencyDoorLocked", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmergencyDoorLocked), 14, 0, 0 },

  { "GasSpringLocked", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    GasSpringLocked), 0, 0, 0 },

  { "RampSupportDown", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    RampSupportDown), 0, 0, 0 },

  { "LockingLeverUnlockAuth", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    LockingLeverUnlockAuth), 0, 0, 0 },

  { "EmerDoorOpenFaultMessage", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmerDoorOpenFaultMessage), 14, 0, 0 },

  { "VehicleElectrical", rt_offsetof(BD_DoorSystem_Out_Vehicle,
    VehicleElectrical), 51, 0, 0 },

  { "Doors", rt_offsetof(BD_DoorSystem_Out_Vehicle, Doors), 57, 5, 0 },

  { "EmergencyDoor", rt_offsetof(BD_DoorSystem_Out_Vehicle, EmergencyDoor), 58,
    0, 0 },

  { "BrakeCylinderPressures", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_AxleBrakes, BrakeCylinderPressures), 0, 6,
    0 },

  { "ParkBrakePressures", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_AxleBrakes,
    ParkBrakePressures), 0, 6, 0 },

  { "HornLow", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Audio, HornLow), 0, 0,
    0 },

  { "HornHigh", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Audio, HornHigh), 0,
    0, 0 },

  { "PneumaticPressureRelease", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Audio, PneumaticPressureRelease), 0, 0, 0 },

  { "EmergencyBrakeActive", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Audio,
    EmergencyBrakeActive), 14, 0, 0 },

  { "BrakeCylinderControlPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie, BrakeCylinderControlPressure),
    0, 0, 0 },

  { "BrakeCylinderPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie, BrakeCylinderPressure), 0, 2,
    0 },

  { "ParkBrakePressure", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie,
    ParkBrakePressure), 0, 0, 0 },

  { "SandingSystemPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie, SandingSystemPressure), 0, 0,
    0 },

  { "AirSuspensionPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie, AirSuspensionPressure), 0, 0,
    0 },

  { "AirSuspPressureDiff", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie, AirSuspPressureDiff), 0, 0, 0
  },

  { "BrakeReservoirPressure", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Debug,
    BrakeReservoirPressure), 0, 0, 0 },

  { "MainReservoirPressure", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Debug,
    MainReservoirPressure), 0, 0, 0 },

  { "MainReservoirPipePressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug, MainReservoirPipePressure), 0, 0, 0
  },

  { "AuxiliaryReservoirPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug, AuxiliaryReservoirPressure), 0, 0, 0
  },

  { "PantographCylinderPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Debug, PantographCylinderPressure), 0, 0, 0
  },

  { "VCBCylinderPressure", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Debug,
    VCBCylinderPressure), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Debug, Bogie), 62, 2, 0
  },

  { "BrakeCylinderPressureGauge", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie, BrakeCylinderPressureGauge),
    0, 0, 0 },

  { "ParkBrakePressureGauge", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie, ParkBrakePressureGauge), 0, 0,
    0 },

  { "MainReservoirPressureGauge", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Gauges, MainReservoirPressureGauge), 0, 0,
    0 },

  { "SRPressureGauge", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Gauges,
    SRPressureGauge), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Gauges, Bogie), 64, 2,
    0 },

  { "BrakeCylinderPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie, BrakeCylinderPressureSwitch),
    0, 0, 0 },

  { "ParkBrakePressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie, ParkBrakePressureSwitch), 0,
    0, 0 },

  { "AirSuspensionPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie, AirSuspensionPressureSwitch),
    0, 0, 0 },

  { "SandingSystemPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie, SandingSystemPressureSwitch),
    0, 0, 0 },

  { "BrakeReservoirPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, BrakeReservoirPressureSwitch), 0,
    0, 0 },

  { "HornHighPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, HornHighPressureSwitch), 0, 0, 0
  },

  { "HornLowPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, HornLowPressureSwitch), 0, 0, 0 },

  { "MainReservoirPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, MainReservoirPressureSwitch), 0,
    0, 0 },

  { "AuxiliaryReservoirPressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, AuxiliaryReservoirPressureSwitch),
    0, 0, 0 },

  { "MainReservoirPipePressureSwitch", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Switches, MainReservoirPipePressureSwitch),
    0, 0, 0 },

  { "MRPS_TractionCutout", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Switches,
    MRPS_TractionCutout), 0, 0, 0 },

  { "PS3", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Switches, PS3), 0, 0, 0 },

  { "PS2", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Switches, PS2), 0, 0, 0 },

  { "VCBPressureSwitch", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Switches,
    VCBPressureSwitch), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Switches, Bogie), 66, 2,
    0 },

  { "BrakeCylinderControlPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie,
     BrakeCylinderControlPressure), 0, 0, 0 },

  { "BrakeCylinderControlVolumePressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie,
     BrakeCylinderControlVolumePressure), 0, 0, 0 },

  { "BrakeReservoirPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie, BrakeReservoirPressure),
    0, 0, 0 },

  { "AirSuspensionLoadPressure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie,
     AirSuspensionLoadPressure), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_Transducers, Bogie), 68,
    2, 0 },

  { "BECU1EmergencyBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1EmergencyBrakeFailure), 14,
    0, 0 },

  { "BECU2EmergencyBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU2EmergencyBrakeFailure), 14,
    0, 0 },

  { "BECU1ServiceBrakeFailure", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1ServiceBrakeFailure), 14,
    0, 0 },

  { "BECU1BrakeNotApplied", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1BrakeNotApplied), 14, 0, 0
  },

  { "BECU1BrakeNotReleased", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1BrakeNotReleased), 14, 0,
    0 },

  { "BECU1CarLoadPressureLow", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1CarLoadPressureLow), 14, 0,
    0 },

  { "BECU2CarLoadPressureLow", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU2CarLoadPressureLow), 14, 0,
    0 },

  { "BECULowRPressure", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie,
    BECULowRPressure), 14, 0, 0 },

  { "AirSuspensionBogie1Deflated", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, AirSuspensionBogie1Deflated),
    14, 0, 0 },

  { "BECU1LoadPressureLow", rt_offsetof
    (BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie, BECU1LoadPressureLow), 14, 0, 0
  },

  { "Bogie", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle_TCMS, Bogie), 70, 2, 0
  },

  { "AxleBrakes", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle, AxleBrakes), 60,
    0, 0 },

  { "Audio", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle, Audio), 61, 0, 0 },

  { "Debug", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle, Debug), 63, 0, 0 },

  { "PressureGauges", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle,
    PressureGauges), 65, 0, 0 },

  { "PressureSwitches", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle,
    PressureSwitches), 67, 0, 0 },

  { "PressureTransducers", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle,
    PressureTransducers), 69, 0, 0 },

  { "TCMS", rt_offsetof(BD_PneumaticsSystem_Out_Vehicle, TCMS), 71, 0, 0 },

  { "RightDoorEmergencyRelease", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, RightDoorEmergencyRelease),
    14, 0, 0 },

  { "LeftDoorEmergencyRelease", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, LeftDoorEmergencyRelease), 14,
    0, 0 },

  { "DoorRight1Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorRight1Isolation), 14, 0,
    0 },

  { "DoorLeft1Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorLeft1Isolation), 14, 0, 0
  },

  { "DoorRight2Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorRight2Isolation), 14, 0,
    0 },

  { "DoorLeft2Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorLeft2Isolation), 14, 0, 0
  },

  { "DoorRight3Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorRight3Isolation), 14, 0,
    0 },

  { "DoorLeft3Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorLeft3Isolation), 14, 0, 0
  },

  { "DoorRight4Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorRight4Isolation), 14, 0,
    0 },

  { "DoorLeft4Isolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, DoorLeft4Isolation), 14, 0, 0
  },

  { "LeftSideDoorOpenRequest", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, LeftSideDoorOpenRequest), 14,
    0, 0 },

  { "LeftSideDoorCloseRequest", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, LeftSideDoorCloseRequest), 14,
    0, 0 },

  { "RightSideDoorOpenRequest", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, RightSideDoorOpenRequest), 14,
    0, 0 },

  { "RightSideDoorCloseRequest", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, RightSideDoorCloseRequest),
    14, 0, 0 },

  { "LeftSideDoorRelease", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, LeftSideDoorRelease), 14, 0,
    0 },

  { "RightSideDoorRelease", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_DoorSystem, RightSideDoorRelease), 14, 0,
    0 },

  { "PantoIsolationCommand", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_PantographSystem, PantoIsolationCommand),
    14, 0, 0 },

  { "EPBrakingDemand", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie, EPBrakingDemand),
    0, 0, 0 },

  { "TractionInhibit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie, TractionInhibit),
    14, 0, 0 },

  { "EDBrakingInhibit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie, EDBrakingInhibit),
    0, 0, 0 },

  { "EPBrakingInhibit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie, EPBrakingInhibit),
    0, 0, 0 },

  { "BogieSupportedMass", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie, BogieSupportedMass),
    0, 0, 0 },

  { "BogieIsolationStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie,
     BogieIsolationStatus), 0, 0, 0 },

  { "PWRandBRKBothApplied", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, PWRandBRKBothApplied), 0,
    0, 0 },

  { "TractionCutModeSelectorInATPATOUTO", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking,
     TractionCutModeSelectorInATPATOUTO), 0, 0, 0 },

  { "BECUFaulty", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking,
    BECUFaulty), 0, 0, 0 },

  { "TractionCommand", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, TractionCommand), 0, 0,
    0 },

  { "EDBrakingCommand", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, EDBrakingCommand), 0, 0,
    0 },

  { "HTERequired", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking,
    HTERequired), 0, 0, 0 },

  { "VehicleDerailed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, VehicleDerailed), 0, 0,
    0 },

  { "TCMSIsolateCI", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, TCMSIsolateCI), 0, 0, 0
  },

  { "CIIsolated", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking,
    CIIsolated), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_TractionBraking,
    Bogie), 75, 2, 0 },

  { "SpeedSensorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, SpeedSensorFault), 14, 0,
    0 },

  { "TCMSSpeedLimit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, TCMSSpeedLimit), 0, 0, 0
  },

  { "TCMSSpeedLimitCause", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, TCMSSpeedLimitCause), 0,
    0, 0 },

  { "BECU1AxleLockedWheelSet1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, BECU1AxleLockedWheelSet1),
    0, 0, 0 },

  { "BECU2AxleLockedWheelSet2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_TractionBraking, BECU2AxleLockedWheelSet2),
    0, 0, 0 },

  { "Overspeed", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    Overspeed), 0, 0, 0 },

  { "EnergizeTLWR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeTLWR), 14, 0, 0
  },

  { "EnergizeTLRR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeTLRR), 14, 0, 0
  },

  { "EnergizeHLHBR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeHLHBR), 14, 0,
    0 },

  { "EnergizeHLLBR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeHLLBR), 14, 0,
    0 },

  { "EnergizeFLR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeFLR), 14, 0, 0
  },

  { "EnergizeFLDR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeFLDR), 14, 0, 0
  },

  { "EnergizeUTO", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeUTO), 14, 0, 0
  },

  { "EnergizeRM", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    EnergizeRM), 14, 0, 0 },

  { "EnergizeCOLR", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, EnergizeCOLR), 14, 0, 0
  },

  { "PantoDownCmdTrip", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, PantoDownCmdTrip), 14,
    0, 0 },

  { "PantoMVSet", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    PantoMVSet), 14, 0, 0 },

  { "NeutralSection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, NeutralSection), 0, 0,
    0 },

  { "RecloseAfterNeutralSection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     RecloseAfterNeutralSection), 14, 0, 0 },

  { "TCMS_TPOR", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    TCMS_TPOR), 14, 0, 0 },

  { "TCMS_TSDR", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    TCMS_TSDR), 14, 0, 0 },

  { "TCMS_VCBClose", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMS_VCBClose), 14, 0,
    0 },

  { "TCMS_VCBOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMS_VCBOpen), 14, 0, 0
  },

  { "TCMS_PBR", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    TCMS_PBR), 14, 0, 0 },

  { "LeftDoorAuth_Closed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, LeftDoorAuth_Closed),
    14, 0, 0 },

  { "LeftDoorAuth_Opened", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, LeftDoorAuth_Opened),
    14, 0, 0 },

  { "RightDoorAuth_Closed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, RightDoorAuth_Closed),
    14, 0, 0 },

  { "RightDoorAuth_Opened", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, RightDoorAuth_Opened),
    14, 0, 0 },

  { "TCMSIsolateBCG1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateBCG1), 14, 0,
    0 },

  { "TCMSIsolateBCG2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateBCG2), 14, 0,
    0 },

  { "ParkBrakeApplyVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ParkBrakeApplyVDUReq),
    0, 0, 0 },

  { "ParkBrakeBypassVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ParkBrakeBypassVDUReq),
    0, 0, 0 },

  { "Bogie1IsolateVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, Bogie1IsolateVDUReq), 0,
    0, 0 },

  { "Bogie2IsolateVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, Bogie2IsolateVDUReq), 0,
    0, 0 },

  { "RightDoorAuth_Opened_Op2_5", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     RightDoorAuth_Opened_Op2_5), 14, 0, 0 },

  { "LeftDoorAuth_Opened_Op2_5", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     LeftDoorAuth_Opened_Op2_5), 14, 0, 0 },

  { "HornHighVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, HornHighVDUReq), 0, 0,
    0 },

  { "HornLowVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, HornLowVDUReq), 0, 0, 0
  },

  { "HornIsolateReinstateVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     HornIsolateReinstateVDUReq), 0, 0, 0 },

  { "NeutralZoneBackupModeActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     NeutralZoneBackupModeActive), 0, 0, 0 },

  { "BatteryLowFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, BatteryLowFault), 0, 0,
    0 },

  { "BUVDR_Active", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, BUVDR_Active), 14, 0, 0
  },

  { "CMCActivationFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, CMCActivationFault), 14,
    0, 0 },

  { "CMCDeactivationFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, CMCDeactivationFault),
    14, 0, 0 },

  { "OHLHighVoltageLevel3", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, OHLHighVoltageLevel3),
    0, 0, 0 },

  { "OHLLowVoltageLevel2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, OHLLowVoltageLevel2), 0,
    0, 0 },

  { "VCBOpenedByCI", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, VCBOpenedByCI), 14, 0,
    0 },

  { "VCBOpenedByACOvercurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     VCBOpenedByACOvercurrent), 14, 0, 0 },

  { "VCBOpenedByMTrProtection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     VCBOpenedByMTrProtection), 14, 0, 0 },

  { "VCBOpenedByAPS", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, VCBOpenedByAPS), 14, 0,
    0 },

  { "DCLinkOverVoltageLevel1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, DCLinkOverVoltageLevel1),
    0, 0, 0 },

  { "DCLinkLowVoltageLevel1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, DCLinkLowVoltageLevel1),
    0, 0, 0 },

  { "BICContactorActivationFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     BICContactorActivationFault), 0, 0, 0 },

  { "ShutdownFailureVCBNotOpening", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     ShutdownFailureVCBNotOpening), 0, 0, 0 },

  { "PantographRisingMissing", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, PantographRisingMissing),
    0, 0, 0 },

  { "PantographLoweringMissing", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     PantographLoweringMissing), 0, 0, 0 },

  { "PantographRisingInhibited", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     PantographRisingInhibited), 0, 0, 0 },

  { "PantographLoweringFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     PantographLoweringFailure), 0, 0, 0 },

  { "AKOpenFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, AKOpenFailure), 0, 0, 0
  },

  { "KOpenFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, KOpenFailure), 0, 0, 0
  },

  { "TCMSIsolatePanto", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolatePanto), 0, 0,
    0 },

  { "TCMSIsolateVCB", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateVCB), 0, 0,
    0 },

  { "TCMSIsolateAPS1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateAPS1), 0, 0,
    0 },

  { "TCMSIsolateAPS2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateAPS2), 0, 0,
    0 },

  { "VCBMissingClosing", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, VCBMissingClosing), 0,
    0, 0 },

  { "VCBMissingOpening", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, VCBMissingOpening), 0,
    0, 0 },

  { "FwdRevTrainLineMismatchMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     FwdRevTrainLineMismatchMessage), 0, 0, 0 },

  { "LowMRPressureFaultMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     LowMRPressureFaultMessage), 0, 0, 0 },

  { "DeadmanBypass", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, DeadmanBypass), 0, 0, 0
  },

  { "ADDCOSStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ADDCOSStatus), 0, 0, 0
  },

  { "ORDCOSStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ORDCOSStatus), 0, 0, 0
  },

  { "AirSupplyIC", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, AirSupplyIC), 0, 0, 0 },

  { "MCBPAGroupStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBPAGroupStatus), 0, 0,
    0 },

  { "MCB110VDCGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCB110VDCGroup), 0, 0,
    0 },

  { "MCBLightGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBLightGroup), 0, 0, 0
  },

  { "MCBLightSaloonGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBLightSaloonGroup), 0,
    0, 0 },

  { "MCBDoorGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBDoorGroup), 0, 0, 0
  },

  { "MCBBrakeGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBBrakeGroup), 0, 0, 0
  },

  { "MCBAPSGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBAPSGroup), 0, 0, 0 },

  { "MCBTCMSGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBTCMSGroup), 0, 0, 0
  },

  { "MCBSignallingGroup", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, MCBSignallingGroup), 0,
    0, 0 },

  { "DoubleCabKeyInsertion", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, DoubleCabKeyInsertion),
    0, 0, 0 },

  { "CabEnableNotEnergized", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, CabEnableNotEnergized),
    0, 0, 0 },

  { "CouplingCircuitNotEnergized", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     CouplingCircuitNotEnergized), 0, 0, 0 },

  { "PantoCircuitNotEnergized", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     PantoCircuitNotEnergized), 0, 0, 0 },

  { "ExternalLightCB1Tripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ExternalLightCB1Tripped),
    0, 0, 0 },

  { "ExternalLightCB2Tripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ExternalLightCB2Tripped),
    0, 0, 0 },

  { "InternalLightCB1Tripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, InternalLightCB1Tripped),
    0, 0, 0 },

  { "InternalLightCB2Tripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, InternalLightCB2Tripped),
    0, 0, 0 },

  { "APSCBTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, APSCBTripped), 0, 0, 0
  },

  { "ReverseMotionInForwardCommandMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     ReverseMotionInForwardCommandMessage), 0, 0, 0 },

  { "MCDRFaulty", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    MCDRFaulty), 0, 0, 0 },

  { "ObstacleDetected", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, ObstacleDetected), 0, 0,
    0 },

  { "ODDFailure", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    ODDFailure), 0, 0, 0 },

  { "VehiclesPassedNS", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, VehiclesPassedNS), 0, 0,
    0 },

  { "TW_TSDDR", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
    TW_TSDDR), 0, 0, 0 },

  { "TrainInNeutralSection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TrainInNeutralSection),
    0, 0, 0 },

  { "LeftDoorAuth_OpenedOP1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, LeftDoorAuth_OpenedOP1),
    14, 0, 0 },

  { "RightDoorAuth_OpenedOP1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, RightDoorAuth_OpenedOP1),
    14, 0, 0 },

  { "TCMSCompressorCmd", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSCompressorCmd), 0,
    0, 0 },

  { "TCMSFireAlarmReset", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSFireAlarmReset), 0,
    0, 0 },

  { "TCMSFDUReset", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSFDUReset), 0, 0, 0
  },

  { "TCMSHVACSmokeReset", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSHVACSmokeReset), 0,
    0, 0 },

  { "TCMSIsolateHVAC1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateHVAC1), 0, 0,
    0 },

  { "TCMSIsolateHVAC2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSIsolateHVAC2), 0, 0,
    0 },

  { "TCMSResetHVAC1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSResetHVAC1), 0, 0,
    0 },

  { "TCMSResetHVAC2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSResetHVAC2), 0, 0,
    0 },

  { "TCMSAPSCBTripCmd", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSAPSCBTripCmd), 0, 0,
    0 },

  { "TCMSFDSCBTripCmd", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSFDSCBTripCmd), 0, 0,
    0 },

  { "TCMSHVAC1CBTripCmd", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSHVAC1CBTripCmd), 0,
    0, 0 },

  { "TCMSHVAC2CBTripCmd", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSHVAC2CBTripCmd), 0,
    0, 0 },

  { "DeadmanBypassStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, DeadmanBypassStatus), 0,
    0, 0 },

  { "BLCOSwitchStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, BLCOSwitchStatus), 0, 0,
    0 },

  { "TooManyBogiesIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TooManyBogiesIsolated),
    0, 0, 0 },

  { "TooManyEPICCutout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TooManyEPICCutout), 0,
    0, 0 },

  { "TCMSWFLIsolation", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSWFLIsolation), 0, 0,
    0 },

  { "TCMSPABORBypass", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, TCMSPABORBypass), 0, 0,
    0 },

  { "WFLIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, WFLIsolated), 0, 0, 0 },

  { "HVAC1FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     HVAC1FireDetectorDisableVDUReq), 0, 0, 0 },

  { "EDBHeatAlarmDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     EDBHeatAlarmDisableVDUReq), 0, 0, 0 },

  { "CABSmokeDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     CABSmokeDetectorDisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearRight1DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SHDEndCubicleRearRight1DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearRight2DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SHDEndCubicleRearRight2DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearLeft1DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SHDEndCubicleRearLeft1DisableVDUReq), 0, 0, 0 },

  { "SHDEndCubicleRearLeft2DisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SHDEndCubicleRearLeft2DisableVDUReq), 0, 0, 0 },

  { "LHDDriverDeskDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     LHDDriverDeskDisableVDUReq), 0, 0, 0 },

  { "LHDCIDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, LHDCIDisableVDUReq), 0,
    0, 0 },

  { "LHDLTJBDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, LHDLTJBDisableVDUReq),
    0, 0, 0 },

  { "SaloonR1FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SaloonR1FireDetectorDisableVDUReq), 0, 0, 0 },

  { "SaloonR2FireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     SaloonR2FireDetectorDisableVDUReq), 0, 0, 0 },

  { "AuxiliaryDeskFireDetectorDisableVDUReq", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem,
     AuxiliaryDeskFireDetectorDisableVDUReq), 0, 0, 0 },

  { "RemoteMagnetValve1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, RemoteMagnetValve1), 0,
    0, 0 },

  { "RemoteMagnetValve2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem, RemoteMagnetValve2), 0,
    0, 0 },

  { "BrakingDemand", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem, BrakingDemand), 0, 0, 0
  },

  { "ASCOEnd1", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    ASCOEnd1), 0, 0, 0 },

  { "ASCOEnd2", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    ASCOEnd2), 0, 0, 0 },

  { "HornManuallyIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem, HornManuallyIsolated), 0,
    0, 0 },

  { "BIC1Inside", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    BIC1Inside), 0, 0, 0 },

  { "BIC1Outside", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    BIC1Outside), 0, 0, 0 },

  { "BIC2Inside", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    BIC2Inside), 0, 0, 0 },

  { "BIC2Outside", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem,
    BIC2Outside), 0, 0, 0 },

  { "DoorSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control, DoorSystem), 73,
    0, 0 },

  { "PantographSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control,
    PantographSystem), 74, 0, 0 },

  { "TractionSBraking", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control,
    TractionSBraking), 76, 0, 0 },

  { "ElectricalSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control,
    ElectricalSystem), 77, 0, 0 },

  { "PneumaticSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Control,
    PneumaticSystem), 78, 0, 0 },

  { "DoorA1Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA1Open), 0, 0, 0 },

  { "DoorA2Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA2Open), 0, 0, 0 },

  { "DoorA3Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA3Open), 0, 0, 0 },

  { "DoorA4Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA4Open), 0, 0, 0 },

  { "DoorB1Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB1Open), 0, 0, 0 },

  { "DoorB2Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB2Open), 0, 0, 0 },

  { "DoorB3Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB3Open), 0, 0, 0 },

  { "DoorB4Open", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB4Open), 0, 0, 0 },

  { "DoorA1Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1Locked), 0, 0, 0 },

  { "DoorA2Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2Locked), 0, 0, 0 },

  { "DoorA3Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3Locked), 0, 0, 0 },

  { "DoorA4Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4Locked), 0, 0, 0 },

  { "DoorB1Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1Locked), 0, 0, 0 },

  { "DoorB2Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2Locked), 0, 0, 0 },

  { "DoorB3Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3Locked), 0, 0, 0 },

  { "DoorB4Locked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4Locked), 0, 0, 0 },

  { "DoorA1Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1Isolated), 0, 0, 0
  },

  { "DoorA2Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2Isolated), 0, 0, 0
  },

  { "DoorA3Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3Isolated), 0, 0, 0
  },

  { "DoorA4Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4Isolated), 0, 0, 0
  },

  { "DoorB1Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1Isolated), 0, 0, 0
  },

  { "DoorB2Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2Isolated), 0, 0, 0
  },

  { "DoorB3Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3Isolated), 0, 0, 0
  },

  { "DoorB4Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4Isolated), 0, 0, 0
  },

  { "DoorA1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA1Fault), 0, 0, 0 },

  { "DoorA2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA2Fault), 0, 0, 0 },

  { "DoorA3Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA3Fault), 0, 0, 0 },

  { "DoorA4Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorA4Fault), 0, 0, 0 },

  { "DoorB1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB1Fault), 0, 0, 0 },

  { "DoorB2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB2Fault), 0, 0, 0 },

  { "DoorB3Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB3Fault), 0, 0, 0 },

  { "DoorB4Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DoorB4Fault), 0, 0, 0 },

  { "DoorA1EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1EmergencyReleased),
    0, 0, 0 },

  { "DoorA2EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2EmergencyReleased),
    0, 0, 0 },

  { "DoorA3EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3EmergencyReleased),
    0, 0, 0 },

  { "DoorA4EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4EmergencyReleased),
    0, 0, 0 },

  { "DoorB1EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1EmergencyReleased),
    0, 0, 0 },

  { "DoorB2EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2EmergencyReleased),
    0, 0, 0 },

  { "DoorB3EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3EmergencyReleased),
    0, 0, 0 },

  { "DoorB4EmergencyReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4EmergencyReleased),
    0, 0, 0 },

  { "DCU1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU1Status), 0, 0, 0 },

  { "DCU2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU2Status), 0, 0, 0 },

  { "DCU3Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU3Status), 0, 0, 0 },

  { "DCU4Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU4Status), 0, 0, 0 },

  { "DCU5Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU5Status), 0, 0, 0 },

  { "DCU6Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU6Status), 0, 0, 0 },

  { "DCU7Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU7Status), 0, 0, 0 },

  { "DCU8Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU8Status), 0, 0, 0 },

  { "DoorA1CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1CloseObstruction),
    14, 0, 0 },

  { "DoorA2CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2CloseObstruction),
    14, 0, 0 },

  { "DoorA3CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3CloseObstruction),
    14, 0, 0 },

  { "DoorA4CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4CloseObstruction),
    14, 0, 0 },

  { "DoorB1CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1CloseObstruction),
    14, 0, 0 },

  { "DoorB2CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2CloseObstruction),
    14, 0, 0 },

  { "DoorB3CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3CloseObstruction),
    14, 0, 0 },

  { "DoorB4CloseObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4CloseObstruction),
    14, 0, 0 },

  { "DoorA1OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1OpenObstruction),
    14, 0, 0 },

  { "DoorA2OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2OpenObstruction),
    14, 0, 0 },

  { "DoorA3OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3OpenObstruction),
    14, 0, 0 },

  { "DoorA4OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4OpenObstruction),
    14, 0, 0 },

  { "DoorB1OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1OpenObstruction),
    14, 0, 0 },

  { "DoorB2OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2OpenObstruction),
    14, 0, 0 },

  { "DoorB3OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3OpenObstruction),
    14, 0, 0 },

  { "DoorB4OpenObstruction", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4OpenObstruction),
    14, 0, 0 },

  { "DoorA1OpenDummyForLeaf", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1OpenDummyForLeaf),
    0, 0, 0 },

  { "DoorA1MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA1MotorCircuitFailure), 14, 0, 0 },

  { "DoorA2MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA2MotorCircuitFailure), 14, 0, 0 },

  { "DoorA3MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA3MotorCircuitFailure), 14, 0, 0 },

  { "DoorA4MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA4MotorCircuitFailure), 14, 0, 0 },

  { "DoorB1MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB1MotorCircuitFailure), 14, 0, 0 },

  { "DoorB2MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB2MotorCircuitFailure), 14, 0, 0 },

  { "DoorB3MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB3MotorCircuitFailure), 14, 0, 0 },

  { "DoorB4MotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB4MotorCircuitFailure), 14, 0, 0 },

  { "DoorA1FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1FailedToLock), 14,
    0, 0 },

  { "DoorA2FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2FailedToLock), 14,
    0, 0 },

  { "DoorA3FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3FailedToLock), 14,
    0, 0 },

  { "DoorA4FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4FailedToLock), 14,
    0, 0 },

  { "DoorB1FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1FailedToLock), 14,
    0, 0 },

  { "DoorB2FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2FailedToLock), 14,
    0, 0 },

  { "DoorB3FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3FailedToLock), 14,
    0, 0 },

  { "DoorB4FailedToLock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4FailedToLock), 14,
    0, 0 },

  { "DoorA1FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1FailedToUnlock),
    14, 0, 0 },

  { "DoorA2FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2FailedToUnlock),
    14, 0, 0 },

  { "DoorA3FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3FailedToUnlock),
    14, 0, 0 },

  { "DoorA4FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4FailedToUnlock),
    14, 0, 0 },

  { "DoorB1FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1FailedToUnlock),
    14, 0, 0 },

  { "DoorB2FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2FailedToUnlock),
    14, 0, 0 },

  { "DoorB3FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3FailedToUnlock),
    14, 0, 0 },

  { "DoorB4FailedToUnlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4FailedToUnlock),
    14, 0, 0 },

  { "DoorA1UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA1UnexpectedUnlocking), 14, 0, 0 },

  { "DoorA2UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA2UnexpectedUnlocking), 14, 0, 0 },

  { "DoorA3UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA3UnexpectedUnlocking), 14, 0, 0 },

  { "DoorA4UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorA4UnexpectedUnlocking), 14, 0, 0 },

  { "DoorB1UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB1UnexpectedUnlocking), 14, 0, 0 },

  { "DoorB2UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB2UnexpectedUnlocking), 14, 0, 0 },

  { "DoorB3UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB3UnexpectedUnlocking), 14, 0, 0 },

  { "DoorB4UnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
     DoorB4UnexpectedUnlocking), 14, 0, 0 },

  { "DoorA1DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DCSRFailure), 14,
    0, 0 },

  { "DoorA2DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DCSRFailure), 14,
    0, 0 },

  { "DoorA3DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DCSRFailure), 14,
    0, 0 },

  { "DoorA4DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DCSRFailure), 14,
    0, 0 },

  { "DoorB1DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DCSRFailure), 14,
    0, 0 },

  { "DoorB2DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DCSRFailure), 14,
    0, 0 },

  { "DoorB3DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DCSRFailure), 14,
    0, 0 },

  { "DoorB4DCSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DCSRFailure), 14,
    0, 0 },

  { "DoorA1DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DCSLFailure), 14,
    0, 0 },

  { "DoorA2DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DCSLFailure), 14,
    0, 0 },

  { "DoorA3DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DCSLFailure), 14,
    0, 0 },

  { "DoorA4DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DCSLFailure), 14,
    0, 0 },

  { "DoorB1DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DCSLFailure), 14,
    0, 0 },

  { "DoorB2DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DCSLFailure), 14,
    0, 0 },

  { "DoorB3DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DCSLFailure), 14,
    0, 0 },

  { "DoorB4DCSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DCSLFailure), 14,
    0, 0 },

  { "DoorA1DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DLSRFailure), 14,
    0, 0 },

  { "DoorA2DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DLSRFailure), 14,
    0, 0 },

  { "DoorA3DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DLSRFailure), 14,
    0, 0 },

  { "DoorA4DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DLSRFailure), 14,
    0, 0 },

  { "DoorB1DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DLSRFailure), 14,
    0, 0 },

  { "DoorB2DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DLSRFailure), 14,
    0, 0 },

  { "DoorB3DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DLSRFailure), 14,
    0, 0 },

  { "DoorB4DLSRFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DLSRFailure), 14,
    0, 0 },

  { "DoorA1DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DLSLFailure), 14,
    0, 0 },

  { "DoorA2DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DLSLFailure), 14,
    0, 0 },

  { "DoorA3DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DLSLFailure), 14,
    0, 0 },

  { "DoorA4DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DLSLFailure), 14,
    0, 0 },

  { "DoorB1DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DLSLFailure), 14,
    0, 0 },

  { "DoorB2DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DLSLFailure), 14,
    0, 0 },

  { "DoorB3DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DLSLFailure), 14,
    0, 0 },

  { "DoorB4DLSLFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DLSLFailure), 14,
    0, 0 },

  { "DoorA1DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DoorMajorFault),
    14, 0, 0 },

  { "DoorA2DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DoorMajorFault),
    14, 0, 0 },

  { "DoorA3DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DoorMajorFault),
    14, 0, 0 },

  { "DoorA4DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DoorMajorFault),
    14, 0, 0 },

  { "DoorB1DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DoorMajorFault),
    14, 0, 0 },

  { "DoorB2DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DoorMajorFault),
    14, 0, 0 },

  { "DoorB3DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DoorMajorFault),
    14, 0, 0 },

  { "DoorB4DoorMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DoorMajorFault),
    14, 0, 0 },

  { "DoorA1DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1DCUFailure), 14, 0,
    0 },

  { "DoorA2DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2DCUFailure), 14, 0,
    0 },

  { "DoorA3DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3DCUFailure), 14, 0,
    0 },

  { "DoorA4DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4DCUFailure), 14, 0,
    0 },

  { "DoorB1DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1DCUFailure), 14, 0,
    0 },

  { "DoorB2DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2DCUFailure), 14, 0,
    0 },

  { "DoorB3DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3DCUFailure), 14, 0,
    0 },

  { "DoorB4DCUFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4DCUFailure), 14, 0,
    0 },

  { "DCU1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU1Fault), 0, 0, 0 },

  { "DCU2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU2Fault), 0, 0, 0 },

  { "DCU3Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU3Fault), 0, 0, 0 },

  { "DCU4Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU4Fault), 0, 0, 0 },

  { "DCU5Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU5Fault), 0, 0, 0 },

  { "DCU6Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU6Fault), 0, 0, 0 },

  { "DCU7Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU7Fault), 0, 0, 0 },

  { "DCU8Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door,
    DCU8Fault), 0, 0, 0 },

  { "DoorA1UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1UnexpectedOpen), 0,
    0, 0 },

  { "DoorA2UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2UnexpectedOpen), 0,
    0, 0 },

  { "DoorA3UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3UnexpectedOpen), 0,
    0, 0 },

  { "DoorA4UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4UnexpectedOpen), 0,
    0, 0 },

  { "DoorB1UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1UnexpectedOpen), 0,
    0, 0 },

  { "DoorB2UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2UnexpectedOpen), 0,
    0, 0 },

  { "DoorB3UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3UnexpectedOpen), 0,
    0, 0 },

  { "DoorB4UnexpectedOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4UnexpectedOpen), 0,
    0, 0 },

  { "DoorA1LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA1LocalEED), 0, 0, 0
  },

  { "DoorA2LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA2LocalEED), 0, 0, 0
  },

  { "DoorA3LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA3LocalEED), 0, 0, 0
  },

  { "DoorA4LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorA4LocalEED), 0, 0, 0
  },

  { "DoorB1LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB1LocalEED), 0, 0, 0
  },

  { "DoorB2LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB2LocalEED), 0, 0, 0
  },

  { "DoorB3LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB3LocalEED), 0, 0, 0
  },

  { "DoorB4LocalEED", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door, DoorB4LocalEED), 0, 0, 0
  },

  { "AllRightDoorsClosed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, AllRightDoorsClosed), 0, 0, 0
  },

  { "AllLeftDoorsClosed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, AllLeftDoorsClosed), 0, 0, 0
  },

  { "AllDoorsClosed", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
    AllDoorsClosed), 0, 0, 0 },

  { "EmerDoorFaultMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmerDoorFaultMessage), 0, 0,
    0 },

  { "EmergencyEscapeDoorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorFault), 0,
    0, 0 },

  { "EmergencyEscapeDoorIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorIsolated),
    0, 0, 0 },

  { "EmergencyEscapeDoorLocked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorLocked), 0,
    0, 0 },

  { "EmergencyEscapeDoorUnlocked", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorUnlocked),
    0, 0, 0 },

  { "EmergencyEscapeDoorOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorOpen), 0,
    0, 0 },

  { "EmergencyEscapeDoorReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyEscapeDoorReleased),
    0, 0, 0 },

  { "CabSaloonPartitionDoorOpen", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, CabSaloonPartitionDoorOpen),
    0, 0, 0 },

  { "EmergencyDoorCoverRemoved", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, EmergencyDoorCoverRemoved), 0,
    0, 0 },

  { "DoorLoopBypassActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, DoorLoopBypassActive), 0, 0,
    0 },

  { "LeftDoor1Lockout", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
    LeftDoor1Lockout), 0, 0, 0 },

  { "LeftDoor2Lockout", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
    LeftDoor2Lockout), 0, 0, 0 },

  { "LeftDoor3Lockout", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
    LeftDoor3Lockout), 0, 0, 0 },

  { "LeftDoor4Lockout", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
    LeftDoor4Lockout), 0, 0, 0 },

  { "RightDoor1Lockout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, RightDoor1Lockout), 0, 0, 0 },

  { "RightDoor2Lockout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, RightDoor2Lockout), 0, 0, 0 },

  { "RightDoor3Lockout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, RightDoor3Lockout), 0, 0, 0 },

  { "RightDoor4Lockout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, RightDoor4Lockout), 0, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_DoorSystem,
     UnexpectedDoorOpeningDetectedByCC), 0, 0, 0 },

  { "Doors", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_DoorSystem, Doors),
    80, 0, 0 },

  { "UnitAtLeastOnePantoUp", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, UnitAtLeastOnePantoUp),
    0, 0, 0 },

  { "UnitAllPantoDown", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, UnitAllPantoDown), 0, 0,
    0 },

  { "UnitPantoPowerDetected", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, UnitPantoPowerDetected),
    0, 0, 0 },

  { "VehiclePantoUp", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, VehiclePantoUp), 0, 0,
    0 },

  { "VehiclePantoDown", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, VehiclePantoDown), 0, 0,
    0 },

  { "PantographIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, PantographIsolated), 0,
    0, 0 },

  { "VehiclePantoRising", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, VehiclePantoRising), 0,
    0, 0 },

  { "VehiclePantoLowering", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, VehiclePantoLowering),
    0, 0, 0 },

  { "PantographPosition", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, PantographPosition), 0,
    0, 0 },

  { "PantographFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, PantographFault), 0, 0,
    0 },

  { "PantoADDFaultMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, PantoADDFaultMessage),
    0, 0, 0 },

  { "PantoORDFaultMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem, PantoORDFaultMessage),
    0, 0, 0 },

  { "PantoRaiseFailureMessage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PantographSystem,
     PantoRaiseFailureMessage), 0, 0, 0 },

  { "BrakeCylinderPressureGauge", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie,
     BrakeCylinderPressureGauge), 0, 0, 0 },

  { "ParkBrakePressureGauge", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie,
     ParkBrakePressureGauge), 0, 0, 0 },

  { "AllServiceBrakesReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     AllServiceBrakesReleased), 0, 0, 0 },

  { "ServiceBrakesApplied", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, ServiceBrakesApplied),
    0, 0, 0 },

  { "AllParkBrakesReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, AllParkBrakesReleased),
    0, 0, 0 },

  { "ParkBrakeApplied", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, ParkBrakeApplied), 0, 0,
    0 },

  { "MainPipePressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, MainPipePressure), 0, 0,
    0 },

  { "BrakeCylinderPressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BrakeCylinderPressure),
    0, 0, 0 },

  { "Bogie1BrakeCylinderPressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie1BrakeCylinderPressure), 0, 0, 0 },

  { "Bogie2BrakeCylinderPressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie2BrakeCylinderPressure), 0, 0, 0 },

  { "AirSuspensionPressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, AirSuspensionPressure),
    0, 0, 0 },

  { "MainReservoirPressureGauge", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     MainReservoirPressureGauge), 0, 0, 0 },

  { "ParkBrakeIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, ParkBrakeIsolated), 0,
    0, 0 },

  { "ParkBrakeApplyFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, ParkBrakeApplyFailure),
    14, 0, 0 },

  { "ParkBrakeReleaseFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, ParkBrakeReleaseFailure),
    14, 0, 0 },

  { "Bogie", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
    Bogie), 83, 2, 0 },

  { "Bogie1ServiceBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie1ServiceBrakeStatus), 0, 0, 0 },

  { "Bogie2ServiceBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie2ServiceBrakeStatus), 0, 0, 0 },

  { "Bogie1ServiceBrakeIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie1ServiceBrakeIsolated), 0, 0, 0 },

  { "Bogie2ServiceBrakeIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie2ServiceBrakeIsolated), 0, 0, 0 },

  { "Bogie1ParkingBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie1ParkingBrakeStatus), 0, 0, 0 },

  { "Bogie2ParkingBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie2ParkingBrakeStatus), 0, 0, 0 },

  { "Bogie1ParkingBrakeIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie1ParkingBrakeIsolated), 0, 0, 0 },

  { "Bogie2ParkingBrakeIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     Bogie2ParkingBrakeIsolated), 0, 0, 0 },

  { "Bogie1IsolationStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie1IsolationStatus),
    0, 0, 0 },

  { "Bogie2IsolationStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie2IsolationStatus),
    0, 0, 0 },

  { "Bogie1SUSPStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie1SUSPStatus), 0, 0,
    0 },

  { "Bogie2SUSPStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie2SUSPStatus), 0, 0,
    0 },

  { "Bogie1SUSPFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie1SUSPFault), 0, 0,
    0 },

  { "Bogie2SUSPFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie2SUSPFault), 0, 0,
    0 },

  { "BrakeDemandSignalFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     BrakeDemandSignalFailure), 0, 0, 0 },

  { "BECU1EmergencyBrakeFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     BECU1EmergencyBrakeFailure), 0, 0, 0 },

  { "BECU2EmergencyBrakeFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     BECU2EmergencyBrakeFailure), 0, 0, 0 },

  { "BECU1ServiceBrakeFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     BECU1ServiceBrakeFailure), 0, 0, 0 },

  { "BECU1BrakeNotApplied", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECU1BrakeNotApplied),
    0, 0, 0 },

  { "BECU1BrakeNotReleased", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECU1BrakeNotReleased),
    0, 0, 0 },

  { "BECU1CarLoadPressureLow", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECU1CarLoadPressureLow),
    0, 0, 0 },

  { "BECU2CarLoadPressureLow", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECU2CarLoadPressureLow),
    0, 0, 0 },

  { "BECULowRPressure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECULowRPressure), 0, 0,
    0 },

  { "Bogie1ServiceBrakeFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, Bogie1ServiceBrakeFault),
    0, 0, 0 },

  { "BECU1LoadPressureLow", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem, BECU1LoadPressureLow),
    0, 0, 0 },

  { "AirSuspensionBogie1Deflated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     AirSuspensionBogie1Deflated), 0, 0, 0 },

  { "PantographPipePressureLow", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     PantographPipePressureLow), 0, 0, 0 },

  { "MainReservoirPressureLow", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem,
     MainReservoirPressureLow), 0, 0, 0 },

  { "ForwardDirection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ForwardDirection), 0, 0,
    0 },

  { "ReverseDirection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ReverseDirection), 0, 0,
    0 },

  { "TrainSpeed", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    TrainSpeed), 0, 0, 0 },

  { "ZeroSpeed", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    ZeroSpeed), 0, 0, 0 },

  { "TCMSSpeedLimit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, TCMSSpeedLimit), 0, 0, 0
  },

  { "TractionOn", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    TractionOn), 0, 0, 0 },

  { "BrakeOn", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    BrakeOn), 0, 0, 0 },

  { "TractionSafe", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, TractionSafe), 0, 0, 0 },

  { "UnitTractiveEffortAchieved", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitTractiveEffortAchieved), 0, 0, 0 },

  { "UnitTractiveEffortPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitTractiveEffortPossible), 0, 0, 0 },

  { "UnitEDBrakingEffortAchieved", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitEDBrakingEffortAchieved), 0, 0, 0 },

  { "UnitEDBrakingEffortPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitEDBrakingEffortPossible), 0, 0, 0 },

  { "UnitTractivePower", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, UnitTractivePower), 0, 0,
    0 },

  { "UnitTractivePowerPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitTractivePowerPossible), 0, 0, 0 },

  { "UnitEDBrakingPower", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, UnitEDBrakingPower), 0,
    0, 0 },

  { "UnitEDBrakingPowerPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     UnitEDBrakingPowerPossible), 0, 0, 0 },

  { "VehicleTractiveEffortAchieved", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleTractiveEffortAchieved), 0, 0, 0 },

  { "VehicleTractiveEffortPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleTractiveEffortPossible), 0, 0, 0 },

  { "VehicleEDBrakingEffortAchieved", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleEDBrakingEffortAchieved), 0, 0, 0 },

  { "VehicleEDBrakingEffortPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleEDBrakingEffortPossible), 0, 0, 0 },

  { "VehicleTractivePower", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, VehicleTractivePower), 0,
    0, 0 },

  { "VehicleTractivePowerPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleTractivePowerPossible), 0, 0, 0 },

  { "VehicleEDBrakingPower", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, VehicleEDBrakingPower),
    0, 0, 0 },

  { "VehicleEDBrakingPowerPossible", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     VehicleEDBrakingPowerPossible), 0, 0, 0 },

  { "ServiceBrakeActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ServiceBrakeActive), 0,
    0, 0 },

  { "ServiceBrakeFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ServiceBrakeFault), 0, 0,
    0 },

  { "TEBEFeedback", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, TEBEFeedback), 0, 0, 0 },

  { "BELOW_SIGNALS_ARE_PROPULSION_SCREEN_SIGNALS", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     BELOW_SIGNALS_ARE_PROPULSION_SCREEN_SIGNALS), 0, 0, 0 },

  { "PropulsionActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, PropulsionActive), 0, 0,
    0 },

  { "PropulsionFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, PropulsionFault), 0, 0,
    0 },

  { "PropulsionIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, PropulsionIsolated), 0,
    0, 0 },

  { "PropulsionEnableStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, PropulsionEnableStatus),
    0, 0, 0 },

  { "EDBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, EDBrakeStatus), 0, 0, 0
  },

  { "TractiveEffort", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, TractiveEffort), 0, 0, 0
  },

  { "AKContactorStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, AKContactorStatus), 0, 0,
    0 },

  { "KContactorStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, KContactorStatus), 0, 0,
    0 },

  { "FilterVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, FilterVoltage), 0, 0, 0
  },

  { "BELOW_SIGNALS_ARE_BRAKE_SCREEN_SIGNALS", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     BELOW_SIGNALS_ARE_BRAKE_SCREEN_SIGNALS), 0, 0, 0 },

  { "HoldingBrakeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, HoldingBrakeStatus), 0,
    0, 0 },

  { "BECUStatus", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    BECUStatus), 0, 0, 0 },

  { "BECUMinorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, BECUMinorFault), 0, 0, 0
  },

  { "BECUMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, BECUMajorFault), 0, 0, 0
  },

  { "EPBrakeDelivered", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, EPBrakeDelivered), 0, 0,
    0 },

  { "EDBrakeRequested", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, EDBrakeRequested), 0, 0,
    0 },

  { "EPICIsolationStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, EPICIsolationStatus), 0,
    0, 0 },

  { "EDCutoutStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, EDCutoutStatus), 0, 0, 0
  },

  { "RPRESSIsolationStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, RPRESSIsolationStatus),
    0, 0, 0 },

  { "CarWeight", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    CarWeight), 0, 0, 0 },

  { "TotalWeight", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    TotalWeight), 0, 0, 0 },

  { "CIStatus", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    CIStatus), 0, 0, 0 },

  { "CIFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    CIFault), 0, 0, 0 },

  { "CIIsolated", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    CIIsolated), 0, 0, 0 },

  { "BELOW_SIGNALS_ARE_FOR_SPEEDLIMIT_INTERLOCK_SCREEN", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     BELOW_SIGNALS_ARE_FOR_SPEEDLIMIT_INTERLOCK_SCREEN), 0, 0, 0 },

  { "SpeedLimitASCutout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitASCutout), 0,
    0, 0 },

  { "SpeedLimitASDeflated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitASDeflated), 0,
    0, 0 },

  { "SpeedLimitBogieIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitBogieIsolated),
    0, 0, 0 },

  { "SpeedLimitBrakeFailure", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitBrakeFailure),
    0, 0, 0 },

  { "SpeedLimitEPICCutout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitEPICCutout), 0,
    0, 0 },

  { "SpeedLimitExcessiveSlip", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitExcessiveSlip),
    0, 0, 0 },

  { "SpeedLimitJogMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitJogMode), 0, 0,
    0 },

  { "SpeedLimitLowSpeedCutoutMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     SpeedLimitLowSpeedCutoutMode), 0, 0, 0 },

  { "SpeedLimitNoEDAvailable", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitNoEDAvailable),
    0, 0, 0 },

  { "SpeedLimitOverrideTractionBlock", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     SpeedLimitOverrideTractionBlock), 0, 0, 0 },

  { "SpeedLimitRPRESSIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitRPRESSIsolated),
    0, 0, 0 },

  { "SpeedLimitSCSMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, SpeedLimitSCSMode), 0, 0,
    0 },

  { "CIKAKContactor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, CIKAKContactor), 0, 0, 0
  },

  { "BELOW_SIGNALS_ARE_AT_BOGIE_LEVEL", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     BELOW_SIGNALS_ARE_AT_BOGIE_LEVEL), 0, 0, 0 },

  { "Bogie1WSPStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, Bogie1WSPStatus), 0, 0,
    0 },

  { "Bogie2WSPStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, Bogie2WSPStatus), 0, 0,
    0 },

  { "HeavyWheelSlipDetected", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, HeavyWheelSlipDetected),
    0, 0, 0 },

  { "DynamicBrakeCutoutDueToSlide", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
     DynamicBrakeCutoutDueToSlide), 0, 0, 0 },

  { "RollbackDetected", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, RollbackDetected), 0, 0,
    0 },

  { "HTERequired", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TractionBraking,
    HTERequired), 0, 0, 0 },

  { "WashingModeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, WashingModeStatus), 0, 0,
    0 },

  { "ShuntModeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ShuntModeStatus), 0, 0,
    0 },

  { "ATPLowSpeedCutoutStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TractionBraking, ATPLowSpeedCutoutStatus),
    0, 0, 0 },

  { "HMIPower", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    HMIPower), 0, 0, 0 },

  { "CabActive", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    CabActive), 0, 0, 0 },

  { "TBCPosition", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TBCPosition), 0, 0, 0 },

  { "UTOMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    UTOMode), 0, 0, 0 },

  { "ATOMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    ATOMode), 0, 0, 0 },

  { "ATPMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    ATPMode), 0, 0, 0 },

  { "ROSMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    ROSMode), 0, 0, 0 },

  { "RMRMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    RMRMode), 0, 0, 0 },

  { "ATBMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    ATBMode), 0, 0, 0 },

  { "RMFMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    RMFMode), 0, 0, 0 },

  { "APS1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS1Status), 0, 0, 0 },

  { "APS2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS2Status), 0, 0, 0 },

  { "APS1Active", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS1Active), 0, 0, 0 },

  { "APS2Active", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS2Active), 0, 0, 0 },

  { "APS1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS1Fault), 0, 0, 0 },

  { "APS2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    APS2Fault), 0, 0, 0 },

  { "APS1Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, APS1Isolated), 0, 0, 0
  },

  { "APS2Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, APS2Isolated), 0, 0, 0
  },

  { "APS1OutputVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, APS1OutputVoltage), 0,
    0, 0 },

  { "APS2OutputVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, APS2OutputVoltage), 0,
    0, 0 },

  { "AK1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    AK1Status), 0, 0, 0 },

  { "K1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    K1Status), 0, 0, 0 },

  { "AK2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    AK2Status), 0, 0, 0 },

  { "K2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    K2Status), 0, 0, 0 },

  { "BCG1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    BCG1Status), 0, 0, 0 },

  { "BCG2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    BCG2Status), 0, 0, 0 },

  { "BCG1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    BCG1Fault), 0, 0, 0 },

  { "BCG2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    BCG2Fault), 0, 0, 0 },

  { "BCGOutputVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCGOutputVoltage), 0, 0,
    0 },

  { "BatteryVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BatteryVoltage), 0, 0,
    0 },

  { "TotalOutputCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TotalOutputCurrent), 0,
    0, 0 },

  { "OutputCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, OutputCurrent), 0, 0, 0
  },

  { "BatteryCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BatteryCurrent), 0, 0,
    0 },

  { "BatteryTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BatteryTemperature), 0,
    0, 0 },

  { "BCG1OutputCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCG1OutputCurrent), 0,
    0, 0 },

  { "BCG2OutputCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCG2OutputCurrent), 0,
    0, 0 },

  { "ATCBypassMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ATCBypassMode), 0, 0, 0
  },

  { "BrakeTrainLineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BrakeTrainLineStatus),
    0, 0, 0 },

  { "MotorTrainLineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, MotorTrainLineStatus),
    0, 0, 0 },

  { "FSB1LineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, FSB1LineStatus), 0, 0,
    0 },

  { "FSB2LineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, FSB2LineStatus), 0, 0,
    0 },

  { "EB1LineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EB1LineStatus), 0, 0, 0
  },

  { "EB2LineStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EB2LineStatus), 0, 0, 0
  },

  { "VCBFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    VCBFault), 0, 0, 0 },

  { "VCBIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, VCBIsolated), 0, 0, 0 },

  { "VCBState", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    VCBState), 0, 0, 0 },

  { "LineVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, LineVoltage), 0, 0, 0 },

  { "Odometer", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    Odometer), 0, 0, 0 },

  { "TotalWeight", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TotalWeight), 0, 0, 0 },

  { "OperationalMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, OperationalMode), 0, 0,
    0 },

  { "RescueMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    RescueMode), 0, 0, 0 },

  { "JogMode", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    JogMode), 0, 0, 0 },

  { "EnableToRun", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EnableToRun), 0, 0, 0 },

  { "ShoreSupply", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ShoreSupply), 0, 0, 0 },

  { "Coupled", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    Coupled), 0, 0, 0 },

  { "VCBTripCommandStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, VCBTripCommandStatus),
    0, 0, 0 },

  { "StandbyMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, StandbyMode), 0, 0, 0 },

  { "SaloonLightGroupStatus1", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SaloonLightGroupStatus1),
    0, 0, 0 },

  { "SaloonLightGroupStatus2", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SaloonLightGroupStatus2),
    0, 0, 0 },

  { "FlasherLightStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, FlasherLightStatus), 0,
    0, 0 },

  { "WFLStatus", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    WFLStatus), 0, 0, 0 },

  { "WFLFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    WFLFault), 0, 0, 0 },

  { "WFLOilLevelStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, WFLOilLevelStatus), 0,
    0, 0 },

  { "WFLPump1Status", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, WFLPump1Status), 0, 0,
    0 },

  { "WFLPump2Status", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, WFLPump2Status), 0, 0,
    0 },

  { "TrainControlContactor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TrainControlContactor),
    0, 0, 0 },

  { "BatteryIsolationContactor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     BatteryIsolationContactor), 0, 0, 0 },

  { "DUMMY_HVAC_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_HVAC_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "HVAC1Status", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC1Status), 0, 0, 0 },

  { "HVAC2Status", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC2Status), 0, 0, 0 },

  { "HVAC1ReducedMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC1ReducedMode), 0, 0,
    0 },

  { "HVAC2ReducedMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC2ReducedMode), 0, 0,
    0 },

  { "HVAC1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    HVAC1Fault), 0, 0, 0 },

  { "HVAC2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    HVAC2Fault), 0, 0, 0 },

  { "HVAC1Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC1Isolated), 0, 0, 0
  },

  { "HVAC2Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC2Isolated), 0, 0, 0
  },

  { "HVAC1SetPointTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC1SetPointTemperature), 0, 0, 0 },

  { "HVAC2SetPointTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC2SetPointTemperature), 0, 0, 0 },

  { "HVAC1InternalTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC1InternalTemperature), 0, 0, 0 },

  { "HVAC2InternalTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC2InternalTemperature), 0, 0, 0 },

  { "HVAC1ExternalTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC1ExternalTemperature), 0, 0, 0 },

  { "HVAC2ExternalTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     HVAC2ExternalTemperature), 0, 0, 0 },

  { "DUMMY_MV_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_MV_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "MainCompressor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, MainCompressor), 0, 0,
    0 },

  { "PowerExtensionContactor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, PowerExtensionContactor),
    0, 0, 0 },

  { "AuxCompressor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, AuxCompressor), 0, 0, 0
  },

  { "DUMMY_TCMS_ECN_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_TCMS_ECN_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "ComponentSwitchStatusA", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ComponentSwitchStatusA),
    0, 0, 0 },

  { "ComponentSwitchStatusB", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ComponentSwitchStatusB),
    0, 0, 0 },

  { "ComponentSwitchStatusC", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ComponentSwitchStatusC),
    0, 0, 0 },

  { "TrainEthernetRepeaterStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     TrainEthernetRepeaterStatus), 0, 0, 0 },

  { "TrainBackboneNodeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TrainBackboneNodeStatus),
    0, 0, 0 },

  { "ECNALGStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ECNALGStatus), 0, 0, 0
  },

  { "DUMMY_FIRE_DETECTION_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_FIRE_DETECTION_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "UnderframeFireAlarmStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     UnderframeFireAlarmStatus), 0, 0, 0 },

  { "SaloonFireAlarmStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SaloonFireAlarmStatus),
    0, 0, 0 },

  { "SensorFireAlarmStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SensorFireAlarmStatus),
    0, 0, 0 },

  { "FireDetectionUnit", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, FireDetectionUnit), 0,
    0, 0 },

  { "ExternalSmoke", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ExternalSmoke), 0, 0, 0
  },

  { "InternalFire", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, InternalFire), 0, 0, 0
  },

  { "DUMMY_EB_INTERLOCK_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_EB_INTERLOCK_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "EBForNonCabEnabled", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EBForNonCabEnabled), 0,
    0, 0 },

  { "EBDueToATCZeroSpeed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EBDueToATCZeroSpeed), 0,
    0, 0 },

  { "EBByCC", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    EBByCC), 0, 0, 0 },

  { "EBForNonDirectionSelected", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     EBForNonDirectionSelected), 0, 0, 0 },

  { "EBDueToPushButton", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EBDueToPushButton), 0,
    0, 0 },

  { "EBByMC", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    EBByMC), 0, 0, 0 },

  { "EBByBrakeLoop", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EBByBrakeLoop), 0, 0, 0
  },

  { "EBDueToDeadman", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EBDueToDeadman), 0, 0,
    0 },

  { "DUMMY_PANTO_INTERLOCK_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_PANTO_INTERLOCK_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "EGSOperatedACPM", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EGSOperatedACPM), 0, 0,
    0 },

  { "EGSOperatedOSPM", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EGSOperatedOSPM), 0, 0,
    0 },

  { "DUMMY_VCB_INTERLOCK_SCREEN_SIGNALS_BELOW", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     DUMMY_VCB_INTERLOCK_SCREEN_SIGNALS_BELOW), 0, 0, 0 },

  { "TransformerOilTemperature", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     TransformerOilTemperature), 0, 0, 0 },

  { "VCBOpenedByACOverCurrent", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     VCBOpenedByACOverCurrent), 0, 0, 0 },

  { "VCBOpenedByMTrProtection", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     VCBOpenedByMTrProtection), 0, 0, 0 },

  { "VCBOpenedByICM", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, VCBOpenedByICM), 0, 0,
    0 },

  { "VCBOpenedByICDM", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, VCBOpenedByICDM), 0, 0,
    0 },

  { "VCBOpenedByAPS", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, VCBOpenedByAPS), 0, 0,
    0 },

  { "NoLineVoltage", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, NoLineVoltage), 0, 0, 0
  },

  { "APSKAKContactor", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, APSKAKContactor), 0, 0,
    0 },

  { "RCCBTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, RCCBTripped), 0, 0, 0 },

  { "SupplyFanTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SupplyFanTripped), 0, 0,
    0 },

  { "ExtSmokeDetectedinHVAC", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ExtSmokeDetectedinHVAC),
    0, 0, 0 },

  { "EmergencyInverterTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     EmergencyInverterTripped), 0, 0, 0 },

  { "HVACFireMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVACFireMode), 0, 0, 0
  },

  { "HVACReducedMode", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVACReducedMode), 0, 0,
    0 },

  { "HVACGroupMCBTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVACGroupMCBTripped), 0,
    0, 0 },

  { "HVACMajorFault", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVACMajorFault), 0, 0,
    0 },

  { "SmokeAlarmCABArea", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, SmokeAlarmCABArea), 0,
    0, 0 },

  { "HeatAlarmEDB", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HeatAlarmEDB), 0, 0, 0
  },

  { "FDUFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    FDUFault), 0, 0, 0 },

  { "SFARFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
    SFARFault), 0, 0, 0 },

  { "BCG1Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCG1Isolated), 0, 0, 0
  },

  { "BCG2Isolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCG2Isolated), 0, 0, 0
  },

  { "BCG1IsolationFailed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BCG1IsolationFailed), 0,
    0, 0 },

  { "PowerOffPressed", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, PowerOffPressed), 0, 0,
    0 },

  { "ObstructionDetectedLeft", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ObstructionDetectedLeft),
    0, 0, 0 },

  { "ObstructionDetectedRight", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem,
     ObstructionDetectedRight), 0, 0, 0 },

  { "DerailmentDetectedLeft", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, DerailmentDetectedLeft),
    0, 0, 0 },

  { "DerailmentDetectedRight", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, DerailmentDetectedRight),
    0, 0, 0 },

  { "HighVoltageMissing", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HighVoltageMissing), 0,
    0, 0 },

  { "CabNotEnabled", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, CabNotEnabled), 0, 0, 0
  },

  { "DrivingModeNotOK", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, DrivingModeNotOK), 0, 0,
    0 },

  { "TrainDirectionMissing", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TrainDirectionMissing),
    0, 0, 0 },

  { "ATCStatusNotOK", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ATCStatusNotOK), 0, 0,
    0 },

  { "TrainReadyNotOK", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TrainReadyNotOK), 0, 0,
    0 },

  { "TooManyRPressureCutout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TooManyRPressureCutout),
    0, 0, 0 },

  { "TooManyEPICCutout", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TooManyEPICCutout), 0,
    0, 0 },

  { "TooManyBogieIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, TooManyBogieIsolated),
    0, 0, 0 },

  { "ZVRDNotActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ZVRDNotActive), 0, 0, 0
  },

  { "MotoringTLDeenergized", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, MotoringTLDeenergized),
    0, 0, 0 },

  { "BrakeLoopOpenTL", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BrakeLoopOpenTL), 0, 0,
    0 },

  { "ParkingBrakeActiveTL", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ParkingBrakeActiveTL),
    0, 0, 0 },

  { "DoorLoopOpenTL", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, DoorLoopOpenTL), 0, 0,
    0 },

  { "ADDIntervention", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, ADDIntervention), 0, 0,
    0 },

  { "BrakeLoopCBTripped", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, BrakeLoopCBTripped), 0,
    0, 0 },

  { "WFLIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, WFLIsolated), 0, 0, 0 },

  { "HVAC1FireSmokeActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, HVAC1FireSmokeActive),
    0, 0, 0 },

  { "EDBHeatAlarmActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, EDBHeatAlarmActive), 0,
    0, 0 },

  { "CABSmokeAlarmActive", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem, CABSmokeAlarmActive), 0,
    0, 0 },

  { "ConsistSwitchStatusA", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, ConsistSwitchStatusA), 0, 0,
    0 },

  { "ConsistSwitchStatusB", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, ConsistSwitchStatusB), 0, 0,
    0 },

  { "ConsistSwitchStatusC", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, ConsistSwitchStatusC), 0, 0,
    0 },

  { "TrainEthernetRepeaterStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, TrainEthernetRepeaterStatus),
    0, 0, 0 },

  { "TrainBackboneNodeStatus", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, TrainBackboneNodeStatus), 0,
    0, 0 },

  { "ECNALGStatus", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    ECNALGStatus), 0, 0, 0 },

  { "RemoteHornIsolated", rt_offsetof
    (BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, RemoteHornIsolated), 0, 0, 0
  },

  { "CCUFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    CCUFault), 0, 0, 0 },

  { "RIO1Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    RIO1Fault), 0, 0, 0 },

  { "RIO1Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    RIO1Status), 0, 0, 0 },

  { "RIO2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    RIO2Fault), 0, 0, 0 },

  { "RIO2Status", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    RIO2Status), 0, 0, 0 },

  { "RIO1RIO2Fault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem,
    RIO1RIO2Fault), 0, 0, 0 },

  { "ERFault", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem, ERFault),
    0, 0, 0 },

  { "MessageID", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_Message,
    MessageID), 0, 0, 0 },

  { "MessageStatus", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_Message,
    MessageStatus), 0, 0, 0 },

  { "Message", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display_MessageList,
    Message), 88, 7, 0 },

  { "DoorSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display, DoorSystem), 81,
    0, 0 },

  { "PantographSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display,
    PantographSystem), 82, 0, 0 },

  { "PneumaticsSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display,
    PneumaticsSystem), 84, 0, 0 },

  { "TractionBraking", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display,
    TractionBraking), 85, 0, 0 },

  { "ElectricalSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display,
    ElectricalSystem), 86, 0, 0 },

  { "TCMSSystem", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display, TCMSSystem), 87,
    0, 0 },

  { "MessageList", rt_offsetof(BD_TCMSSystem_Out_Vehicle_Display, MessageList),
    89, 0, 0 },

  { "Control", rt_offsetof(BD_TCMSSystem_Out_Vehicle, Control), 79, 0, 0 },

  { "Display", rt_offsetof(BD_TCMSSystem_Out_Vehicle, Display), 90, 0, 0 },

  { "AerodynamicDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    AerodynamicDragForce), 0, 0, 0 },

  { "BearingDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    BearingDragForce), 0, 0, 0 },

  { "LateralDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    LateralDragForce), 0, 0, 0 },

  { "AdditionalNonWheelDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    AdditionalNonWheelDragForce), 0, 0, 0 },

  { "Force", rt_offsetof(BD_TrainDynamics_Out_Coupler, Force), 0, 0, 0 },

  { "SpringForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, SpringForce), 0, 0,
    0 },

  { "DampingForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, DampingForce), 0,
    0, 0 },

  { "BuffForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, BuffForce), 0, 0, 0 },

  { "DraftForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, DraftForce), 0, 0, 0
  },

  { "ImpactForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, ImpactForce), 0, 0,
    0 },

  { "Breakage", rt_offsetof(BD_TrainDynamics_Out_Coupler, Breakage), 0, 0, 0 },

  { "Extension", rt_offsetof(BD_TrainDynamics_Out_Coupler, Extension), 0, 0, 0 },

  { "ExtensionRate", rt_offsetof(BD_TrainDynamics_Out_Coupler, ExtensionRate), 0,
    0, 0 },

  { "ExternalCoupling", rt_offsetof(BD_TrainDynamics_Out_Coupler,
    ExternalCoupling), 0, 0, 0 },

  { "Mimic", rt_offsetof(BD_TrainDynamics_Out_Coupler, Mimic), 21, 0, 0 },

  { "Position", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, Position), 0,
    0, 0 },

  { "Velocity", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, Velocity), 0,
    0, 0 },

  { "Acceleration", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia,
    Acceleration), 0, 0, 0 },

  { "Jerk", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, Jerk), 0, 0, 0 },

  { "PositionRear", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia,
    PositionRear), 0, 0, 0 },

  { "MovingForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, MovingForce),
    0, 0, 0 },

  { "Mass", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, Mass), 0, 0, 0 },

  { "LoadingMass", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia, LoadingMass),
    0, 0, 0 },

  { "BogieSupportedMass", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Inertia,
    BogieSupportedMass), 0, 0, 0 },

  { "GravitationalForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_TrackGeometry,
    GravitationalForce), 0, 0, 0 },

  { "LateralForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_TrackGeometry,
    LateralForce), 0, 0, 0 },

  { "LateralAcceleration", rt_offsetof
    (BD_TrainDynamics_Out_Vehicle_TrackGeometry, LateralAcceleration), 0, 0, 0 },

  { "LateralAccelerationRate", rt_offsetof
    (BD_TrainDynamics_Out_Vehicle_TrackGeometry, LateralAccelerationRate), 0, 0,
    0 },

  { "RailReactionForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_TrackGeometry,
    RailReactionForce), 0, 0, 0 },

  { "DerailmentCoefficient", rt_offsetof
    (BD_TrainDynamics_Out_Vehicle_TrackGeometry, DerailmentCoefficient), 0, 0, 0
  },

  { "ForceTransmitted", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel,
    ForceTransmitted), 0, 0, 0 },

  { "Speed", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Speed), 0, 0, 0 },

  { "SpeedDelta", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, SpeedDelta), 0,
    0, 0 },

  { "Spin", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Spin), 0, 0, 0 },

  { "Skid", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Skid), 0, 0, 0 },

  { "DrivingForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, DrivingForce),
    0, 0, 0 },

  { "LateralFrictionForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel,
    LateralFrictionForce), 0, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, BrakingForce),
    0, 0, 0 },

  { "BrakePower", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, BrakePower), 0,
    0, 0 },

  { "Drag", rt_offsetof(BD_TrainDynamics_Out_Vehicle, Drag), 92, 0, 0 },

  { "Couplers", rt_offsetof(BD_TrainDynamics_Out_Vehicle, Couplers), 93, 2, 0 },

  { "Inertia", rt_offsetof(BD_TrainDynamics_Out_Vehicle, Inertia), 94, 0, 0 },

  { "TrackGeometry", rt_offsetof(BD_TrainDynamics_Out_Vehicle, TrackGeometry),
    95, 0, 0 },

  { "Wheel", rt_offsetof(BD_TrainDynamics_Out_Vehicle, Wheel), 96, 6, 0 },

  { "Forward", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie,
    Forward), 14, 0, 0 },

  { "Reverse", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie,
    Reverse), 14, 0, 0 },

  { "BogieNotIsolated", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie, BogieNotIsolated), 14,
    0, 0 },

  { "TractionContactorStatus", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem, TractionContactorStatus), 0,
    0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem, Bogie),
    98, 2, 0 },

  { "TCUStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TCUStatus),
    14, 0, 0 },

  { "BogieFaulty", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    BogieFaulty), 14, 0, 0 },

  { "TractionNotIsolated", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TractionNotIsolated), 14, 0, 0 },

  { "EDBrakeNotIsolated", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    EDBrakeNotIsolated), 14, 0, 0 },

  { "TCUSlideDetected", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TCUSlideDetected), 14, 0, 0 },

  { "TCUSlipDetected", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TCUSlipDetected), 14, 0, 0 },

  { "TractiveEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractiveEffortAchieved), 0, 0, 0
  },

  { "EDBrakingEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingEffortAchieved), 0, 0, 0
  },

  { "TractiveEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractiveEffortPossible), 0, 0, 0
  },

  { "EDBrakingEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingEffortPossible), 0, 0, 0
  },

  { "TractionPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TractionPower), 0, 0, 0 },

  { "EDBrakingPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    EDBrakingPower), 0, 0, 0 },

  { "TractivePowerPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractivePowerPossible), 0, 0, 0 },

  { "EDBrakingPowerPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingPowerPossible), 0, 0, 0
  },

  { "MotorSpeeds", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    MotorSpeeds), 0, 2, 0 },

  { "WSPTractionCutout", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    WSPTractionCutout), 14, 0, 0 },

  { "SpeedSensorFault", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    SpeedSensorFault), 0, 0, 0 },

  { "TCU_KStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    TCU_KStatus), 0, 0, 0 },

  { "TCU_AKStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    TCU_AKStatus), 0, 0, 0 },

  { "FilterVoltage", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    FilterVoltage), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS, Bogie), 100, 2, 0 },

  { "Trafo_TCU", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS, Trafo_TCU), 101,
    0, 0 },

  { "VehicleDerailed", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS,
    VehicleDerailed), 0, 0, 0 },

  { "VehicleBogieDerailed", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS,
    VehicleBogieDerailed), 0, 0, 0 },

  { "TCUWheelSlideControlActive", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, TCUWheelSlideControlActive), 14, 0,
    0 },

  { "EDBrakeStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_BCU_Bogie,
    EDBrakeStatus), 14, 0, 0 },

  { "EDBrakingEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, EDBrakingEffortAchieved), 0, 0, 0
  },

  { "EDBrakingEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, EDBrakingEffortPossible), 0, 0, 0
  },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_BCU, Bogie), 103, 2, 0 },

  { "ElectricalSystem", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU,
    ElectricalSystem), 99, 0, 0 },

  { "TCMS", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU, TCMS), 102, 0, 0 },

  { "BCU", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU, BCU), 104, 0, 0 },

  { "TractionBrakingForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    TractionBrakingForce), 0, 6, 0 },

  { "TractionForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    TractionForce), 0, 6, 0 },

  { "BrakingForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    BrakingForce), 0, 6, 0 },

  { "TractionEDPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_Audio,
    TractionEDPower), 0, 0, 0 },

  { "WheelAngularVelocity", rt_offsetof(BD_TractionSystem_Out_Vehicle_Audio,
    WheelAngularVelocity), 0, 0, 0 },

  { "TractionControl", rt_offsetof(BD_TractionSystem_Out_Vehicle,
    TractionControl), 105, 0, 0 },

  { "Dynamics", rt_offsetof(BD_TractionSystem_Out_Vehicle, Dynamics), 106, 0, 0
  },

  { "Audio", rt_offsetof(BD_TractionSystem_Out_Vehicle, Audio), 107, 0, 0 },

  { "BrakingPower", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle, BrakingPower),
    0, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle, BrakingForce),
    0, 0, 0 },

  { "BrakeShoeForce", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle,
    BrakeShoeForce), 0, 0, 0 },

  { "BrakeShoeTemperature", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle,
    BrakeShoeTemperature), 0, 0, 0 },

  { "BrakeShoeEfficiency", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle,
    BrakeShoeEfficiency), 0, 0, 0 },

  { "BrakeDiscForce", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle,
    BrakeDiscForce), 0, 0, 0 },

  { "NormalBrakePistonForce", rt_offsetof(BD_TrainBrakes_Out_Vehicle_Axle,
    NormalBrakePistonForce), 0, 0, 0 },

  { "BCPEngaged", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States, BCPEngaged), 0,
    0, 0 },

  { "BCPEngagedBogie1", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States,
    BCPEngagedBogie1), 0, 0, 0 },

  { "BCPEngagedBogie2", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States,
    BCPEngagedBogie2), 0, 0, 0 },

  { "WheelBrakeBlocks", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States,
    WheelBrakeBlocks), 0, 0, 0 },

  { "WheelBrakeBlocksBogie1", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States,
    WheelBrakeBlocksBogie1), 0, 0, 0 },

  { "WheelBrakeBlocksBogie2", rt_offsetof(BD_TrainBrakes_Out_Vehicle_States,
    WheelBrakeBlocksBogie2), 0, 0, 0 },

  { "Axle", rt_offsetof(BD_TrainBrakes_Out_Vehicle, Axle), 109, 6, 0 },

  { "States", rt_offsetof(BD_TrainBrakes_Out_Vehicle, States), 110, 0, 0 },

  { "Enabled", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Enabled), 14, 0, 0 },

  { "VehicleID", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, VehicleID), 112, 0, 0 },

  { "Type", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Type), 113, 0, 0 },

  { "Class", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Class), 0, 0, 0 },

  { "Orientation", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Orientation), 0, 0, 0
  },

  { "Length", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Length), 0, 0, 0 },

  { "Height", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Height), 0, 0, 0 },

  { "Width", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Width), 0, 0, 0 },

  { "TareMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, TareMass), 0, 0, 0 },

  { "GrossMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, GrossMass), 0, 0, 0 },

  { "LoadingMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, LoadingMass), 0, 0, 0
  },

  { "NumberOfAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, NumberOfAxles), 0,
    0, 0 },

  { "NumberOfDrivenAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle,
    NumberOfDrivenAxles), 0, 0, 0 },

  { "NumberOfBrakedAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle,
    NumberOfBrakedAxles), 0, 0, 0 },

  { "WheelDiameter", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, WheelDiameter), 0,
    0, 0 },

  { "BrakeShoeCoefficientCalculationMethod", rt_offsetof
    (BD_TrainBrakes_Cfg_Vehicle, BrakeShoeCoefficientCalculationMethod), 115, 0,
    0 },

  { "BrakeShoeFrictionCoeff", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle,
    BrakeShoeFrictionCoeff), 0, 0, 0 },

  { "BrakeFadeEnable", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle, BrakeFadeEnable),
    0, 0, 0 },

  { "BrakeTemperatureEnable", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle,
    BrakeTemperatureEnable), 0, 0, 0 },

  { "VehicleVelocity", rt_offsetof(BD_TrainBrakes_In_Vehicle, VehicleVelocity),
    0, 0, 0 },

  { "WheelSpeed", rt_offsetof(BD_TrainBrakes_In_Vehicle, WheelSpeed), 0, 6, 0 },

  { "BrakeCylinderPressure", rt_offsetof(BD_TrainBrakes_In_Vehicle,
    BrakeCylinderPressure), 0, 6, 0 },

  { "ParkBrakePressure", rt_offsetof(BD_TrainBrakes_In_Vehicle,
    ParkBrakePressure), 0, 6, 0 },

  { "ManualHandBrakeApplication", rt_offsetof(BD_TrainBrakes_In_Vehicle,
    ManualHandBrakeApplication), 0, 0, 0 },

  { "ElectricParkBrakeApplication", rt_offsetof(BD_TrainBrakes_In_Vehicle,
    ElectricParkBrakeApplication), 0, 0, 0 },

  { "FrictionBrakeForceVariation", rt_offsetof
    (BD_TrainBrakes_In_Vehicle_Overrides, FrictionBrakeForceVariation), 0, 0, 0
  },

  { "ParkBrakeOverride", rt_offsetof(BD_TrainBrakes_In_Vehicle_Overrides,
    ParkBrakeOverride), 0, 0, 0 },

  { "BrakeShoeOverheatFault", rt_offsetof(BD_TrainBrakes_In_Vehicle_Faults,
    BrakeShoeOverheatFault), 0, 0, 0 },

  { "isLeft", rt_offsetof(BD_DoorSystem_Cfg_Door, isLeft), 0, 0, 0 },

  { "NumberOfDoors", rt_offsetof(BD_DoorSystem_Cfg_Door, NumberOfDoors), 0, 0, 0
  },

  { "LocalDoorOpenPB", rt_offsetof(BD_DoorSystem_In_Door_InputControlStates,
    LocalDoorOpenPB), 0, 0, 0 },

  { "OpenCloseWidget", rt_offsetof(BD_DoorSystem_In_Door_InputControlStates,
    OpenCloseWidget), 0, 0, 0 },

  { "EmergencyAccessDevice", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, EmergencyAccessDevice), 0, 0, 0 },

  { "EmergencyEgressDevice", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, EmergencyEgressDevice), 0, 0, 0 },

  { "LocalDoorIsolationLock", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, LocalDoorIsolationLock), 0, 0, 0
  },

  { "DoorControlPower", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorControlPower), 14, 0, 0 },

  { "DoorMotorPower", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorMotorPower), 14, 0, 0 },

  { "DoorEnable", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorEnable), 14, 0, 0 },

  { "DoorRelease", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorRelease), 14, 0, 0 },

  { "DoorOpen", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals, DoorOpen),
    14, 0, 0 },

  { "DoorClose", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals, DoorClose),
    14, 0, 0 },

  { "DoorEmergencyRelease", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorEmergencyRelease), 14, 0, 0 },

  { "DoorIsolation", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorIsolation), 14, 0, 0 },

  { "Config", rt_offsetof(BD_DoorSystem_In_Door, Config), 120, 0, 0 },

  { "InputControlStates", rt_offsetof(BD_DoorSystem_In_Door, InputControlStates),
    121, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_DoorSystem_In_Door, ElectricalSignals),
    122, 0, 0 },

  { "Faults", rt_offsetof(BD_DoorSystem_In_Door, Faults), 29, 0, 0 },

  { "Doors", rt_offsetof(BD_DoorSystem_In_Vehicle, Doors), 123, 3, 0 },

  { "AllDoorsLeftOpen", rt_offsetof(BD_DoorSystem_In_Overrides, AllDoorsLeftOpen),
    0, 0, 0 },

  { "AllDoorsRightOpen", rt_offsetof(BD_DoorSystem_In_Overrides,
    AllDoorsRightOpen), 0, 0, 0 },

  { "RampHandle", rt_offsetof(BD_DoorSystem_In_Emergency_Door, RampHandle), 14,
    0, 0 },

  { "EmergencyDoorHandle", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    EmergencyDoorHandle), 14, 0, 0 },

  { "DoorWinder", rt_offsetof(BD_DoorSystem_In_Emergency_Door, DoorWinder), 0, 0,
    0 },

  { "RampWinder", rt_offsetof(BD_DoorSystem_In_Emergency_Door, RampWinder), 0, 0,
    0 },

  { "EmerDoorLatched", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    EmerDoorLatched), 14, 0, 0 },

  { "EmerDoorOpenFault", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    EmerDoorOpenFault), 14, 0, 0 },

  { "EmergencyDoorMechanicalUnlocked", rt_offsetof
    (BD_DoorSystem_In_Emergency_Door, EmergencyDoorMechanicalUnlocked), 0, 0, 0
  },

  { "RampCoverLockingLever", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    RampCoverLockingLever), 0, 0, 0 },

  { "RampMiddleSupport", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    RampMiddleSupport), 14, 0, 0 },

  { "EmergencyDoorGasSpring", rt_offsetof(BD_DoorSystem_In_Emergency_Door,
    EmergencyDoorGasSpring), 14, 0, 0 },

  { "HasCab", rt_offsetof(BD_DoorSystem_In_Emergency_Door, HasCab), 14, 0, 0 },

  { "DavisCoeffA1", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffA1), 0, 0, 0 },

  { "DavisCoeffA2", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffA2), 0, 0, 0 },

  { "DavisCoeffB1", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffB1), 0, 0, 0 },

  { "DavisCoeffB2", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffB2), 0, 0, 0 },

  { "DavisCoeffLeadCarC", rt_offsetof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients, DavisCoeffLeadCarC), 0, 0,
    0 },

  { "DavisCoeffTailCarC", rt_offsetof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients, DavisCoeffTailCarC), 0, 0,
    0 },

  { "AerodynamicDragCoeff_Front", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    AerodynamicDragCoeff_Front), 0, 0, 0 },

  { "AerodynamicDragCoeff_Trail", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    AerodynamicDragCoeff_Trail), 0, 0, 0 },

  { "BearingFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    BearingFrictionCoeff), 0, 0, 0 },

  { "BearingDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    BearingDynamicFrictionCoeff), 0, 0, 0 },

  { "LateralFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    LateralFrictionCoeff), 0, 0, 0 },

  { "RailStaticFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailStaticFrictionCoeff), 0, 0, 0 },

  { "RailDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailDynamicFrictionCoeff), 0, 0, 0 },

  { "RailSandedStaticFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailSandedStaticFrictionCoeff), 0, 0, 0 },

  { "RailSandedDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailSandedDynamicFrictionCoeff), 0, 0, 0 },

  { "SpringRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SpringRate), 0, 0, 0
  },

  { "SlackSpringRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SlackSpringRate),
    0, 0, 0 },

  { "DampingRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, DampingRate), 0, 0,
    0 },

  { "SlackDampingRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SlackDampingRate), 0, 0, 0 },

  { "EnableDampingAdjustmentByMass", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    EnableDampingAdjustmentByMass), 14, 0, 0 },

  { "DampingAdjustmentDesignMass", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DampingAdjustmentDesignMass), 0, 0, 0 },

  { "SlackLength", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SlackLength), 0, 0,
    0 },

  { "DampingLeadIn", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, DampingLeadIn), 0,
    0, 0 },

  { "CouplerShockTime", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    CouplerShockTime), 0, 0, 0 },

  { "DragCalculationMethod", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DragCalculationMethod), 127, 0, 0 },

  { "DavisCoefficients", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DavisCoefficients), 128, 0, 0 },

  { "UseSandFrictionCoeffs", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    UseSandFrictionCoeffs), 0, 0, 0 },

  { "SandStaticFrictionFactor", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SandStaticFrictionFactor), 0, 0, 0 },

  { "SandDynamicFrictionFactor", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SandDynamicFrictionFactor), 0, 0, 0 },

  { "InitialVelocity", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, InitialVelocity),
    0, 0, 0 },

  { "End", rt_offsetof(BD_TrainDynamics_In_Coupler, End), 0, 0, 0 },

  { "OtherVehicleID", rt_offsetof(BD_TrainDynamics_In_Coupler, OtherVehicleID),
    0, 0, 0 },

  { "OtherVehicleEnd", rt_offsetof(BD_TrainDynamics_In_Coupler, OtherVehicleEnd),
    0, 0, 0 },

  { "OtherVehicleOrientation", rt_offsetof(BD_TrainDynamics_In_Coupler,
    OtherVehicleOrientation), 0, 0, 0 },

  { "Available", rt_offsetof(BD_TrainDynamics_In_Coupler, Available), 0, 0, 0 },

  { "Separation", rt_offsetof(BD_TrainDynamics_In_Coupler, Separation), 0, 0, 0
  },

  { "SeparationRate", rt_offsetof(BD_TrainDynamics_In_Coupler, SeparationRate),
    0, 0, 0 },

  { "OurCouplingPosition", rt_offsetof(BD_TrainDynamics_In_Coupler,
    OurCouplingPosition), 0, 0, 0 },

  { "OtherCouplingPosition", rt_offsetof(BD_TrainDynamics_In_Coupler,
    OtherCouplingPosition), 0, 0, 0 },

  { "CouplingSeparation", rt_offsetof(BD_TrainDynamics_In_Coupler,
    CouplingSeparation), 0, 0, 0 },

  { "Interfacing", rt_offsetof(BD_TrainDynamics_In_Coupler, Interfacing), 0, 0,
    0 },

  { "CoupledChainLength", rt_offsetof(BD_TrainDynamics_In_Coupler,
    CoupledChainLength), 0, 0, 0 },

  { "MechanicallyCoupled", rt_offsetof(BD_TrainDynamics_In_Coupler,
    MechanicallyCoupled), 0, 0, 0 },

  { "Mimic", rt_offsetof(BD_TrainDynamics_In_Coupler, Mimic), 21, 0, 0 },

  { "AerodynamicDragForce", rt_offsetof
    (BD_TrainDynamics_In_Vehicle_CustomDragForces, AerodynamicDragForce), 0, 0,
    0 },

  { "BearingDragForce", rt_offsetof(BD_TrainDynamics_In_Vehicle_CustomDragForces,
    BearingDragForce), 0, 0, 0 },

  { "TractionForce", rt_offsetof(BD_TrainDynamics_In_Vehicle, TractionForce), 0,
    6, 0 },

  { "BrakingForce", rt_offsetof(BD_TrainDynamics_In_Vehicle, BrakingForce), 0, 6,
    0 },

  { "TrackData", rt_offsetof(BD_TrainDynamics_In_Vehicle, TrackData), 10, 0, 0 },

  { "Couplers", rt_offsetof(BD_TrainDynamics_In_Vehicle, Couplers), 130, 2, 0 },

  { "CustomDragForces", rt_offsetof(BD_TrainDynamics_In_Vehicle,
    CustomDragForces), 131, 0, 0 },

  { "NonWheelStoppingForce", rt_offsetof(BD_TrainDynamics_In_Vehicle,
    NonWheelStoppingForce), 0, 0, 0 },

  { "BogieSupportedMass", rt_offsetof(BD_TrainDynamics_In_Vehicle,
    BogieSupportedMass), 0, 0, 0 },

  { "FreezeDynamics", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    FreezeDynamics), 0, 0, 0 },

  { "SandingApplied", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    SandingApplied), 0, 0, 0 },

  { "TrackAdhesionVariation", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    TrackAdhesionVariation), 0, 0, 0 },

  { "LoadingVariation", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    LoadingVariation), 0, 0, 0 },

  { "CouplerBreakageLimit", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    CouplerBreakageLimit), 0, 0, 0 },

  { "VelocitySetFlag", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    VelocitySetFlag), 14, 0, 0 },

  { "VelocitySetValue", rt_offsetof(BD_TrainDynamics_In_Vehicle_Overrides,
    VelocitySetValue), 0, 0, 0 },

  { "BearingFrictionVariation", rt_offsetof
    (BD_TrainDynamics_In_Vehicle_Overrides, BearingFrictionVariation), 0, 0, 0 },

  { "LateralFrictionVariation", rt_offsetof
    (BD_TrainDynamics_In_Vehicle_Overrides, LateralFrictionVariation), 0, 0, 0 },

  { "LockedAxle", rt_offsetof(BD_TrainDynamics_In_Vehicle_Faults, LockedAxle), 0,
    0, 0 },

  { "WheelFlat", rt_offsetof(BD_TrainDynamics_In_Vehicle_Faults, WheelFlat), 0,
    0, 0 },

  { "PoorSanding", rt_offsetof(BD_TrainDynamics_In_Vehicle_Faults, PoorSanding),
    0, 0, 0 },

  { "HasPanto", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, HasPanto), 14, 0, 0
  },

  { "HasCab", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, HasCab), 14, 0, 0 },

  { "IsNonCab", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsNonCab), 14, 0, 0
  },

  { "HasMotor", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, HasMotor), 14, 0, 0
  },

  { "HasMainCompressor", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle,
    HasMainCompressor), 14, 0, 0 },

  { "HasPantoReservoir", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle,
    HasPantoReservoir), 14, 0, 0 },

  { "IsT1", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsT1), 14, 0, 0 },

  { "IsT2", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsT2), 14, 0, 0 },

  { "IsT3", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsT3), 14, 0, 0 },

  { "IsM1", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsM1), 14, 0, 0 },

  { "IsM2", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsM2), 14, 0, 0 },

  { "IsM3", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsM3), 14, 0, 0 },

  { "IsDM1", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsDM1), 14, 0, 0 },

  { "IsDM2", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsDM2), 14, 0, 0 },

  { "IsDM3", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, IsDM3), 14, 0, 0 },

  { "UnitConnection", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle,
    UnitConnection), 14, 0, 0 },

  { "UnitID", rt_offsetof(BD_ElectricalSystem_Cfg_Vehicle, UnitID), 135, 0, 0 },

  { "MasterKeySwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, MasterKeySwitch), 0, 0,
    0 },

  { "PowerONPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    PowerONPB), 0, 0, 0 },

  { "PantographDownPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, PantographDownPB), 0, 0,
    0 },

  { "PantoSelectorSw", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, PantoSelectorSw), 0, 0,
    0 },

  { "TractionBrakeController", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, TractionBrakeController),
    0, 0, 0 },

  { "VCBClosePB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VCBClosePB), 0, 0, 0 },

  { "VCBOpenPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VCBOpenPB), 0, 0, 0 },

  { "WiperControlSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, WiperControlSwitch), 0,
    0, 0 },

  { "HeadlightSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, HeadlightSwitch), 0, 0,
    0 },

  { "IdentificationLightsSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     IdentificationLightsSwitch), 0, 0, 0 },

  { "EmergencyBrakePB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, EmergencyBrakePB), 0, 0,
    0 },

  { "ParkBrakeApplyPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, ParkBrakeApplyPB), 0, 0,
    0 },

  { "ParkBrakeReleasePB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, ParkBrakeReleasePB), 0,
    0, 0 },

  { "DoorProvenLoopCutoutPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, DoorProvenLoopCutoutPB),
    0, 0, 0 },

  { "DoorProvenLoopCutoutSw", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, DoorProvenLoopCutoutSw),
    0, 0, 0 },

  { "ZeroSpeedBypassSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, ZeroSpeedBypassSwitch),
    0, 0, 0 },

  { "ObstacleDetectionDisableSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     ObstacleDetectionDisableSwitch), 0, 0, 0 },

  { "LeftDoorReleasePB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, LeftDoorReleasePB), 0, 0,
    0 },

  { "RightDoorReleasePB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, RightDoorReleasePB), 0,
    0, 0 },

  { "ROSPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ROSPB), 0, 0, 0 },

  { "UTOPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    UTOPB), 0, 0, 0 },

  { "ATOStartPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ATOStartPB), 0, 0, 0 },

  { "EBReleasePB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    EBReleasePB), 0, 0, 0 },

  { "SafetyCutoutSS", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, SafetyCutoutSS), 0, 0, 0
  },

  { "LampTestPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    LampTestPB), 0, 0, 0 },

  { "HornPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    HornPB), 0, 0, 0 },

  { "CabConsolePB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, CabConsolePB), 0, 0, 0 },

  { "LeftDoorClosePBOperatingPanel1", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     LeftDoorClosePBOperatingPanel1), 0, 0, 0 },

  { "RightDoorClosePBOperatingPanel1", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     RightDoorClosePBOperatingPanel1), 0, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel1", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     LeftDoorOpenPBOperatingPanel1), 0, 0, 0 },

  { "RightDoorOpenPBOperatingPanel1", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     RightDoorOpenPBOperatingPanel1), 0, 0, 0 },

  { "CabMainLightPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, CabMainLightPB), 0, 0, 0
  },

  { "DoorCloseAnnouncementPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, DoorCloseAnnouncementPB),
    0, 0, 0 },

  { "UncouplePB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    UncouplePB), 0, 0, 0 },

  { "FlasherLightPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, FlasherLightPB), 0, 0, 0
  },

  { "FloodLightPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, FloodLightPB), 0, 0, 0 },

  { "BatteryResetPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, BatteryResetPB), 0, 0, 0
  },

  { "RightDoorOpenPBOperatingPanel5", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     RightDoorOpenPBOperatingPanel5), 0, 0, 0 },

  { "RightDoorClosePBOperatingPanel5", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     RightDoorClosePBOperatingPanel5), 0, 0, 0 },

  { "WFLTestPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    WFLTestPB), 0, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel2", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     LeftDoorOpenPBOperatingPanel2), 0, 0, 0 },

  { "LeftDoorClosePBOperatingPanel2", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     LeftDoorClosePBOperatingPanel2), 0, 0, 0 },

  { "CallOnLightPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, CallOnLightPB), 0, 0, 0
  },

  { "LIMPHomePB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    LIMPHomePB), 0, 0, 0 },

  { "PowerOFFPB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    PowerOFFPB), 0, 0, 0 },

  { "DeadmanSafetyDevice", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, DeadmanSafetyDevice), 0,
    0, 0 },

  { "DeadmanBypassSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, DeadmanBypassSwitch), 0,
    0, 0 },

  { "BrakeLoopCutoutSS", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, BrakeLoopCutoutSS), 0, 0,
    0 },

  { "EmergencyBrakePBBypass", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, EmergencyBrakePBBypass),
    0, 0, 0 },

  { "ADDCOS", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ADDCOS), 0, 0, 0 },

  { "ORDCOS", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ORDCOS), 0, 0, 0 },

  { "HoldDoorCloseBS", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, HoldDoorCloseBS), 0, 0,
    0 },

  { "ModeSelector", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, ModeSelector), 0, 0, 0 },

  { "EmerDoorLimitSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, EmerDoorLimitSwitch), 0,
    0, 0 },

  { "PECUPushButton", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, PECUPushButton), 0, 0, 0
  },

  { "CMCCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CMCCB), 0, 0, 0 },

  { "LeftDoorOpenPB1OperatingPanel2", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     LeftDoorOpenPB1OperatingPanel2), 0, 0, 0 },

  { "RightDoorOpenPB1OperatingPanel5", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates,
     RightDoorOpenPB1OperatingPanel5), 0, 0, 0 },

  { "ParkBrakeIsolationCock", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, ParkBrakeIsolationCock),
    14, 0, 0 },

  { "RIO1CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    RIO1CB), 0, 0, 0 },

  { "RIO2CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    RIO2CB), 0, 0, 0 },

  { "TDICB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    TDICB), 0, 0, 0 },

  { "DIOCB2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    DIOCB2), 0, 0, 0 },

  { "DIOCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    DIOCB1), 0, 0, 0 },

  { "CSCCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CSCCB), 0, 0, 0 },

  { "CSBCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CSBCB), 0, 0, 0 },

  { "CSACB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CSACB), 0, 0, 0 },

  { "CECB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, CECB),
    0, 0, 0 },

  { "UCCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, UCCB),
    0, 0, 0 },

  { "BLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, BLCB),
    0, 0, 0 },

  { "CRSBCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CRSBCB), 0, 0, 0 },

  { "DMICB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    DMICB), 0, 0, 0 },

  { "NVICB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    NVICB), 0, 0, 0 },

  { "VIO1CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VIO1CB), 0, 0, 0 },

  { "VIO2CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VIO2CB), 0, 0, 0 },

  { "APSCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    APSCB), 0, 0, 0 },

  { "DLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, DLCB),
    0, 0, 0 },

  { "DRCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, DRCB),
    0, 0, 0 },

  { "DPLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    DPLCB), 0, 0, 0 },

  { "HLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, HLCB),
    0, 0, 0 },

  { "TLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, TLCB),
    0, 0, 0 },

  { "CELCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    CELCB), 0, 0, 0 },

  { "ILCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ILCB1), 0, 0, 0 },

  { "ILCB2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ILCB2), 0, 0, 0 },

  { "PANCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    PANCB), 0, 0, 0 },

  { "TBCCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    TBCCB1), 0, 0, 0 },

  { "TBCCB2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    TBCCB2), 0, 0, 0 },

  { "POCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, POCB),
    0, 0, 0 },

  { "TVDUCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    TVDUCB), 0, 0, 0 },

  { "ODDCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ODDCB), 0, 0, 0 },

  { "WFLCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    WFLCB), 0, 0, 0 },

  { "WWCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, WWCB),
    0, 0, 0 },

  { "VCBCCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VCBCCB), 0, 0, 0 },

  { "VCBCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    VCBCB), 0, 0, 0 },

  { "PADCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    PADCB), 0, 0, 0 },

  { "SAC1CCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    SAC1CCB), 0, 0, 0 },

  { "SAC2CCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    SAC2CCB), 0, 0, 0 },

  { "AC1CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    AC1CB), 0, 0, 0 },

  { "AC2CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    AC2CB), 0, 0, 0 },

  { "RCCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, RCCB),
    0, 0, 0 },

  { "SFB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, SFB),
    0, 0, 0 },

  { "EIVIB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    EIVIB), 0, 0, 0 },

  { "MRIsolationCock", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, MRIsolationCock), 0, 0,
    0 },

  { "EBLR1CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    EBLR1CB), 0, 0, 0 },

  { "EBLR2CB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    EBLR2CB), 0, 0, 0 },

  { "HCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, HCB),
    0, 0, 0 },

  { "EmergencyStopPB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, EmergencyStopPB), 0, 0,
    0 },

  { "OCCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    OCCB1), 0, 0, 0 },

  { "ELCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ELCB1), 0, 0, 0 },

  { "ELCB2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    ELCB2), 0, 0, 0 },

  { "FDSCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    FDSCB), 0, 0, 0 },

  { "SSICB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    SSICB), 0, 0, 0 },

  { "BCBCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    BCBCB), 0, 0, 0 },

  { "EDCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates, EDCB),
    0, 0, 0 },

  { "BCGCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    BCGCB), 0, 0, 0 },

  { "BECUCB1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    BECUCB1), 0, 0, 0 },

  { "BECUCB2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    BECUCB2), 0, 0, 0 },

  { "BECUCB3", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    BECUCB3), 0, 0, 0 },

  { "LeftDoor1DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, LeftDoor1DCUCB), 0, 0, 0
  },

  { "LeftDoor2DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, LeftDoor2DCUCB), 0, 0, 0
  },

  { "LeftDoor3DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, LeftDoor3DCUCB), 0, 0, 0
  },

  { "LeftDoor4DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, LeftDoor4DCUCB), 0, 0, 0
  },

  { "RightDoor1DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, RightDoor1DCUCB), 0, 0,
    0 },

  { "RightDoor2DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, RightDoor2DCUCB), 0, 0,
    0 },

  { "RightDoor3DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, RightDoor3DCUCB), 0, 0,
    0 },

  { "RightDoor4DCUCB", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, RightDoor4DCUCB), 0, 0,
    0 },

  { "WiperSelectionSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_InputControlStates, WiperSelectionSwitch), 0,
    0, 0 },

  { "WiperWash", rt_offsetof(BD_ElectricalSystem_In_Vehicle_InputControlStates,
    WiperWash), 0, 0, 0 },

  { "ElectricalTrainConnection", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Coupling, ElectricalTrainConnection), 14, 0,
    0 },

  { "ElectricalUnitConnection", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Coupling, ElectricalUnitConnection), 14, 0,
    0 },

  { "ElectricalCoupledCabsConnection", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Coupling, ElectricalCoupledCabsConnection),
    14, 0, 0 },

  { "MechanicalCouplerState", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Coupling, MechanicalCouplerState), 14, 2, 0
  },

  { "VehicleSpeed", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Dynamics,
    VehicleSpeed), 0, 0, 0 },

  { "AuxiliaryReservoirPressureSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Pneumatics, AuxiliaryReservoirPressureSwitch),
    14, 0, 0 },

  { "MainReservoirPressureSwitch", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Pneumatics, MainReservoirPressureSwitch), 14,
    0, 0 },

  { "ParkBrakeApplied", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics,
    ParkBrakeApplied), 14, 0, 0 },

  { "ServiceBrakeApplied", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics,
    ServiceBrakeApplied), 14, 0, 0 },

  { "EmergencyBrakeApplied", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Pneumatics, EmergencyBrakeApplied), 14, 0, 0
  },

  { "VCBPressureSwitch", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics,
    VCBPressureSwitch), 14, 0, 0 },

  { "MRPSTractionCutout", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics,
    MRPSTractionCutout), 14, 0, 0 },

  { "PS3", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics, PS3), 14, 0, 0
  },

  { "PS2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pneumatics, PS2), 14, 0, 0
  },

  { "VehicleDoorInterlock", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Doors,
    VehicleDoorInterlock), 14, 0, 0 },

  { "AllRightDoorsClosed", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Doors,
    AllRightDoorsClosed), 14, 0, 0 },

  { "AllLeftDoorsClosed", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Doors,
    AllLeftDoorsClosed), 14, 0, 0 },

  { "EmergencyDoorOpen", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Doors,
    EmergencyDoorOpen), 14, 0, 0 },

  { "LineVoltageDetected", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pantograph,
    LineVoltageDetected), 0, 0, 0 },

  { "PantographPosition", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Pantograph,
    PantographPosition), 0, 0, 0 },

  { "IsInitialized", rt_offsetof(BD_CommonTrain_Out_ModelStatus, IsInitialized),
    14, 0, 0 },

  { "NotImmobilise", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    NotImmobilise), 0, 0, 0 },

  { "LeftSideDoorEnable", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    LeftSideDoorEnable), 0, 0, 0 },

  { "RightSideDoorEnable", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    RightSideDoorEnable), 0, 0, 0 },

  { "ATCZeroSpeed", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATCZeroSpeed), 0, 0, 0 },

  { "NotSafetyBrake", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    NotSafetyBrake), 0, 0, 0 },

  { "LeftSideDoorOpen", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    LeftSideDoorOpen), 0, 0, 0 },

  { "RightSideDoorOpen", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    RightSideDoorOpen), 0, 0, 0 },

  { "ATOTraction", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATOTraction), 14, 0, 0 },

  { "ATONotBrake", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATONotBrake), 14, 0, 0 },

  { "LeftDoorOpenIndicator", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, LeftDoorOpenIndicator), 0, 0, 0 },

  { "RightDoorOpenIndicator", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, RightDoorOpenIndicator), 0, 0, 0
  },

  { "UndergroundSection", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    UndergroundSection), 0, 0, 0 },

  { "ATOStartIndicator", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATOStartIndicator), 0, 0, 0 },

  { "SBResetIndicator", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    SBResetIndicator), 0, 0, 0 },

  { "LeftDoorReleaseIndicator", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, LeftDoorReleaseIndicator), 0, 0,
    0 },

  { "RightDoorReleaseIndicator", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, RightDoorReleaseIndicator), 0, 0,
    0 },

  { "ATOState", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys, ATOState),
    0, 0, 0 },

  { "ROSIndication", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ROSIndication), 0, 0, 0 },

  { "NoEmergencyBrakeOrder", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, NoEmergencyBrakeOrder), 14, 0, 0
  },

  { "LeftHoldDoorClose", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    LeftHoldDoorClose), 14, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    RightHoldDoorClose), 14, 0, 0 },

  { "EmerDetrainDoorLockRelay", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, EmerDetrainDoorLockRelay), 0, 0,
    0 },

  { "WakeUpCommand", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    WakeUpCommand), 0, 0, 0 },

  { "UTOPBIndicator", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    UTOPBIndicator), 0, 0, 0 },

  { "UTOModeActive", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    UTOModeActive), 0, 0, 0 },

  { "ATCCabActivation", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATCCabActivation), 0, 0, 0 },

  { "ATOTBDemand", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    ATOTBDemand), 0, 0, 0 },

  { "TractionForward", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    TractionForward), 0, 0, 0 },

  { "DerailmentDetected", rt_offsetof(BD_ElectricalSystem_In_Vehicle_SignalSys,
    DerailmentDetected), 0, 0, 0 },

  { "ObstacleHardCollision", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, ObstacleHardCollision), 0, 0, 0 },

  { "ObstacleSoftCollision", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_SignalSys, ObstacleSoftCollision), 0, 0, 0 },

  { "Overspeed", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, Overspeed), 0,
    0, 0 },

  { "EnergizeTLWR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeTLWR), 14, 0, 0 },

  { "EnergizeTLRR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeTLRR), 14, 0, 0 },

  { "EnergizeHLHBR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeHLHBR), 14, 0, 0 },

  { "EnergizeHLLBR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeHLLBR), 14, 0, 0 },

  { "EnergizeFLR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, EnergizeFLR),
    14, 0, 0 },

  { "EnergizeFLDR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeFLDR), 14, 0, 0 },

  { "EnergizeRM", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, EnergizeRM),
    14, 0, 0 },

  { "EnergizeCOLR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    EnergizeCOLR), 14, 0, 0 },

  { "NeutralSection", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    NeutralSection), 14, 0, 0 },

  { "RecloseAfterNeutralSection", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, RecloseAfterNeutralSection), 14, 0, 0
  },

  { "PantoDownTripCmd", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    PantoDownTripCmd), 14, 0, 0 },

  { "PantoMVSet", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, PantoMVSet),
    14, 0, 0 },

  { "TCMS_TPOR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, TCMS_TPOR), 14,
    0, 0 },

  { "TCMS_TSDR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, TCMS_TSDR), 14,
    0, 0 },

  { "TCMS_VCBClose", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMS_VCBClose), 14, 0, 0 },

  { "TCMS_VCBOpen", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMS_VCBOpen), 14, 0, 0 },

  { "LeftDoorClosePBLight", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    LeftDoorClosePBLight), 14, 0, 0 },

  { "LeftDoorOpenPBLight", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    LeftDoorOpenPBLight), 14, 0, 0 },

  { "RightDoorClosePBLight", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    RightDoorClosePBLight), 14, 0, 0 },

  { "RightDoorOpenPBLight", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    RightDoorOpenPBLight), 14, 0, 0 },

  { "HoldingBrakeStatus", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    HoldingBrakeStatus), 14, 0, 0 },

  { "TCMS_PBR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, TCMS_PBR), 14,
    0, 0 },

  { "TCMSIsolateBCG1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateBCG1), 14, 0, 0 },

  { "TCMSIsolateBCG2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateBCG2), 14, 0, 0 },

  { "ParkBrakeApplyVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    ParkBrakeApplyVDUReq), 0, 0, 0 },

  { "ParkBrakeBypassVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    ParkBrakeBypassVDUReq), 0, 0, 0 },

  { "Bogie1IsolateVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    Bogie1IsolateVDUReq), 0, 0, 0 },

  { "Bogie2IsolateVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    Bogie2IsolateVDUReq), 0, 0, 0 },

  { "RightDoorAuth_Opened_Op2_5", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, RightDoorAuth_Opened_Op2_5), 14, 0, 0
  },

  { "LeftDoorAuth_Opened_Op2_5", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    LeftDoorAuth_Opened_Op2_5), 14, 0, 0 },

  { "HornHighVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    HornHighVDUReq), 0, 0, 0 },

  { "HornLowVDUReq", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    HornLowVDUReq), 0, 0, 0 },

  { "HornIsolateReinstateVDUReq", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, HornIsolateReinstateVDUReq), 0, 0, 0 },

  { "TCMSIsolatePanto", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolatePanto), 0, 0, 0 },

  { "TCMSIsolateVCB", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateVCB), 0, 0, 0 },

  { "TCMSIsolateAPS1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateAPS1), 0, 0, 0 },

  { "TCMSIsolateAPS2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateAPS2), 0, 0, 0 },

  { "TCMSIsolateCI", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateCI), 0, 0, 0 },

  { "TCMS_TSDDR", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS, TCMS_TSDDR),
    0, 0, 0 },

  { "LeftDoorAuth_Opened_Op1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    LeftDoorAuth_Opened_Op1), 14, 0, 0 },

  { "RightDoorAuth_Opened_Op1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    RightDoorAuth_Opened_Op1), 14, 0, 0 },

  { "TCMSCompressorCmd", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSCompressorCmd), 0, 0, 0 },

  { "TCMSFireAlarmReset", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSFireAlarmReset), 0, 0, 0 },

  { "TCMSFDUReset", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSFDUReset), 0, 0, 0 },

  { "TCMSHVACSmokeReset", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSHVACSmokeReset), 0, 0, 0 },

  { "TCMSIsolateHVAC1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateHVAC1), 0, 0, 0 },

  { "TCMSIsolateHVAC2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSIsolateHVAC2), 0, 0, 0 },

  { "TCMSResetHVAC1", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSResetHVAC1), 0, 0, 0 },

  { "TCMSResetHVAC2", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSResetHVAC2), 0, 0, 0 },

  { "TCMSWFLIsolation", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSWFLIsolation), 0, 0, 0 },

  { "TCMSPABORBypass", rt_offsetof(BD_ElectricalSystem_In_Vehicle_TCMS,
    TCMSPABORBypass), 0, 0, 0 },

  { "HVAC1FireDetectorDisableVDUReq", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, HVAC1FireDetectorDisableVDUReq), 0, 0,
    0 },

  { "CABSmokeDetectorDisableVDUReq", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, CABSmokeDetectorDisableVDUReq), 0, 0,
    0 },

  { "SHDEndCubicleRearLeft2DisableVDUReq", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_TCMS, SHDEndCubicleRearLeft2DisableVDUReq),
    0, 0, 0 },

  { "ForwardDirection", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Traction,
    ForwardDirection), 14, 0, 0 },

  { "ReverseDirection", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Traction,
    ReverseDirection), 14, 0, 0 },

  { "TCU_KStatus", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Traction,
    TCU_KStatus), 14, 0, 0 },

  { "TCU_AKStatus", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Traction,
    TCU_AKStatus), 14, 0, 0 },

  { "ContactorsFailure", rt_offsetof(BD_ElectricalSystem_In_Vehicle_Traction,
    ContactorsFailure), 14, 0, 0 },

  { "TractionContactorStatus", rt_offsetof
    (BD_ElectricalSystem_In_Vehicle_Traction, TractionContactorStatus), 0, 0, 0
  },

  { "InputControlStates", rt_offsetof(BD_ElectricalSystem_In_Vehicle,
    InputControlStates), 137, 0, 0 },

  { "Coupling", rt_offsetof(BD_ElectricalSystem_In_Vehicle, Coupling), 138, 0, 0
  },

  { "Dynamics", rt_offsetof(BD_ElectricalSystem_In_Vehicle, Dynamics), 139, 0, 0
  },

  { "Pneumatics", rt_offsetof(BD_ElectricalSystem_In_Vehicle, Pneumatics), 140,
    0, 0 },

  { "Doors", rt_offsetof(BD_ElectricalSystem_In_Vehicle, Doors), 141, 0, 0 },

  { "Pantograph", rt_offsetof(BD_ElectricalSystem_In_Vehicle, Pantograph), 142,
    0, 0 },

  { "ModelStatus", rt_offsetof(BD_ElectricalSystem_In_Vehicle, ModelStatus), 143,
    0, 0 },

  { "SignalSys", rt_offsetof(BD_ElectricalSystem_In_Vehicle, SignalSys), 144, 0,
    0 },

  { "TCMS", rt_offsetof(BD_ElectricalSystem_In_Vehicle, TCMS), 145, 0, 0 },

  { "TractionSys", rt_offsetof(BD_ElectricalSystem_In_Vehicle, TractionSys), 146,
    0, 0 },

  { "HasPanto", rt_offsetof(BD_PantographSystem_Cfg_Vehicle, HasPanto), 14, 0, 0
  },

  { "PneumaticsPoweredPanto", rt_offsetof(BD_PantographSystem_Cfg_Vehicle,
    PneumaticsPoweredPanto), 14, 0, 0 },

  { "ElectricPoweredPanto", rt_offsetof(BD_PantographSystem_Cfg_Vehicle,
    ElectricPoweredPanto), 14, 0, 0 },

  { "HasDriverCab", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment,
    HasDriverCab), 0, 0, 0 },

  { "HasBogie", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment, HasBogie),
    0, 0, 0 },

  { "HasCompressor", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment,
    HasCompressor), 0, 0, 0 },

  { "HasMainReservoir", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment,
    HasMainReservoir), 0, 0, 0 },

  { "HasBrakeSystem", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment,
    HasBrakeSystem), 0, 0, 0 },

  { "HasPantograph", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle_Equipment,
    HasPantograph), 0, 0, 0 },

  { "Equipment", rt_offsetof(BD_PneumaticsSystem_Cfg_Vehicle, Equipment), 149, 0,
    0 },

  { "EPBrakingDemand", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie, EPBrakingDemand), 0,
    0, 0 },

  { "NoEmergencyBrakeValve", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, NoEmergencyBrakeValve), 0,
    0, 0 },

  { "SandingValve", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_ElectricalSignals,
    SandingValve), 0, 0, 0 },

  { "ParkingBrakeApplyCmd", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, ParkingBrakeApplyCmd), 0,
    0, 0 },

  { "ParkingBrakeReleaseCmd", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, ParkingBrakeReleaseCmd),
    0, 0, 0 },

  { "MainCompressorOn", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, MainCompressorOn), 0, 0,
    0 },

  { "AuxiliaryCompressorOn", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, AuxiliaryCompressorOn), 0,
    0, 0 },

  { "RemoteMagnetValve1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, RemoteMagnetValve1), 14,
    0, 0 },

  { "RemoteMagnetValve2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, RemoteMagnetValve2), 14,
    0, 0 },

  { "PantographRaiseValve", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, PantographRaiseValve), 0,
    0, 0 },

  { "PantographEmergencyValve", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, PantographEmergencyValve),
    0, 0, 0 },

  { "HornLowControl", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, HornLowControl), 0, 0, 0
  },

  { "HornHighControl", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, HornHighControl), 0, 0, 0
  },

  { "RemoteHornIsolate", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, RemoteHornIsolate), 14, 0,
    0 },

  { "VCBCloseCmd", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_ElectricalSignals,
    VCBCloseCmd), 14, 0, 0 },

  { "TCMSBrakingDemand", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_ElectricalSignals, TCMSBrakingDemand), 0, 0,
    0 },

  { "BogieControl", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_ElectricalSignals,
    BogieControl), 151, 2, 0 },

  { "BogieSupportedMasses", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_PhysicalSignals, BogieSupportedMasses), 0, 2,
    0 },

  { "PneumaticallyCoupled", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_PhysicalSignals, PneumaticallyCoupled), 0, 2,
    0 },

  { "HornLowIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, HornLowIsolationCock), 0,
    0, 0 },

  { "HornHighIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, HornHighIsolationCock),
    0, 0, 0 },

  { "BrakeSupplyReservoirIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     BrakeSupplyReservoirIsolationCock), 0, 0, 0 },

  { "BrakeSupplyReservoirDrainCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     BrakeSupplyReservoirDrainCock), 0, 0, 0 },

  { "InterCarIsolationCockEnd1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     InterCarIsolationCockEnd1), 0, 0, 0 },

  { "InterCarIsolationCockEnd2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     InterCarIsolationCockEnd2), 0, 0, 0 },

  { "MainReservoirIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     MainReservoirIsolationCock), 0, 0, 0 },

  { "MainReservoirDrainCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, MainReservoirDrainCock),
    0, 0, 0 },

  { "MainAirSupplyIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     MainAirSupplyIsolationCock), 0, 0, 0 },

  { "AirSuspensionSystemIsolationCockBogie1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AirSuspensionSystemIsolationCockBogie1), 0, 0, 0 },

  { "AirSuspensionSystemIsolationCockBogie2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AirSuspensionSystemIsolationCockBogie2), 0, 0, 0 },

  { "AirSuspensionSystemDrainCockBogie1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AirSuspensionSystemDrainCockBogie1), 0, 0, 0 },

  { "AirSuspensionSystemDrainCockBogie2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AirSuspensionSystemDrainCockBogie2), 0, 0, 0 },

  { "AuxiliaryCompressorIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AuxiliaryCompressorIsolationCock), 0, 0, 0 },

  { "AuxiliaryReservoirIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AuxiliaryReservoirIsolationCock), 0, 0, 0 },

  { "AuxiliaryReservoirDrainCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AuxiliaryReservoirDrainCock), 0, 0, 0 },

  { "PantographAirSupplyIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     PantographAirSupplyIsolationCock), 0, 0, 0 },

  { "BrakeCylinderIsolationCockBogie1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     BrakeCylinderIsolationCockBogie1), 0, 0, 0 },

  { "BrakeCylinderIsolationCockBogie2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     BrakeCylinderIsolationCockBogie2), 0, 0, 0 },

  { "ParkingBrakeIsolationCockBogie1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeIsolationCockBogie1), 0, 0, 0 },

  { "ParkingBrakeIsolationCockBogie2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeIsolationCockBogie2), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie1Handle1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeManualReleaseBogie1Handle1), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie1Handle2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeManualReleaseBogie1Handle2), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie2Handle1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeManualReleaseBogie2Handle1), 0, 0, 0 },

  { "ParkingBrakeManualReleaseBogie2Handle2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     ParkingBrakeManualReleaseBogie2Handle2), 0, 0, 0 },

  { "SandingSystemIsolationCockBogie1", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     SandingSystemIsolationCockBogie1), 0, 0, 0 },

  { "SandingSystemIsolationCockBogie2", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     SandingSystemIsolationCockBogie2), 0, 0, 0 },

  { "UncouplingIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, UncouplingIsolationCock),
    0, 0, 0 },

  { "AirSuspensionReservoirIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates,
     AirSuspensionReservoirIsolationCock), 0, 0, 0 },

  { "EPIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, EPIsolationCock), 0, 0,
    0 },

  { "VCBIsolationCock", rt_offsetof
    (BD_PneumaticsSystem_In_Vehicle_InputControlStates, VCBIsolationCock), 0, 0,
    0 },

  { "ORDPlunger", rt_offsetof(BD_PneumaticsSystem_In_Vehicle_InputControlStates,
    ORDPlunger), 0, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_PneumaticsSystem_In_Vehicle,
    ElectricalSignals), 152, 0, 0 },

  { "PhysicalSignals", rt_offsetof(BD_PneumaticsSystem_In_Vehicle,
    PhysicalSignals), 153, 0, 0 },

  { "InputControlStates", rt_offsetof(BD_PneumaticsSystem_In_Vehicle,
    InputControlStates), 154, 0, 0 },

  { "Reset", rt_offsetof(BD_PneumaticsSystem_In_Overrides, Reset), 0, 0, 0 },

  { "StartupState", rt_offsetof(BD_PneumaticsSystem_In_Overrides, StartupState),
    0, 0, 0 },

  { "HasCab", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, HasCab), 14, 0, 0 },

  { "NumberOfTractionBogies", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle,
    NumberOfTractionBogies), 0, 0, 0 },

  { "NumberOfBrakingBogies", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle,
    NumberOfBrakingBogies), 0, 0, 0 },

  { "IsLastVehicle", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, IsLastVehicle), 14,
    0, 0 },

  { "IsFirstVehicle", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, IsFirstVehicle), 14,
    0, 0 },

  { "IsMCar", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, IsMCar), 14, 0, 0 },

  { "IsTCar", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, IsTCar), 14, 0, 0 },

  { "HasVCB", rt_offsetof(BD_TCMSSystem_Cfg_Vehicle, HasVCB), 14, 0, 0 },

  { "TractionBrakeController", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, TractionBrakeController), 0, 0,
    0 },

  { "HeadLightSwitch", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    HeadLightSwitch), 0, 0, 0 },

  { "ParkBrakeIsolationCockBogie1", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, ParkBrakeIsolationCockBogie1),
    0, 0, 0 },

  { "ParkBrakeIsolationCockBogie2", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, ParkBrakeIsolationCockBogie2),
    0, 0, 0 },

  { "Bogie1IsolationCmd", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, Bogie1IsolationCmd), 0, 0, 0 },

  { "Bogie2IsolationCmd", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, Bogie2IsolationCmd), 0, 0, 0 },

  { "EPIC", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates, EPIC), 0, 0,
    0 },

  { "ASCOEnd1", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    ASCOEnd1), 0, 0, 0 },

  { "ASCOEnd2", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    ASCOEnd2), 0, 0, 0 },

  { "ASIsolationCock", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    ASIsolationCock), 0, 0, 0 },

  { "SR", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates, SR), 0, 0, 0
  },

  { "ModeSelector", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    ModeSelector), 0, 0, 0 },

  { "EBPB", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates, EBPB), 0, 0,
    0 },

  { "SafetyCutoutSS", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    SafetyCutoutSS), 0, 0, 0 },

  { "MREPICEnd1", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    MREPICEnd1), 0, 0, 0 },

  { "MREPICEnd2", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    MREPICEnd2), 0, 0, 0 },

  { "CabSaloonPartitionDoorOpen", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, CabSaloonPartitionDoorOpen), 0,
    0, 0 },

  { "EmergencyDoorCoverRemoved", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, EmergencyDoorCoverRemoved), 0,
    0, 0 },

  { "DoorLoopBypassActive", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, DoorLoopBypassActive), 0, 0, 0
  },

  { "DeadManBypass", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    DeadManBypass), 0, 0, 0 },

  { "ControlKey", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    ControlKey), 0, 0, 0 },

  { "LeftDoor1Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor1Lockout), 0, 0, 0 },

  { "LeftDoor2Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor2Lockout), 0, 0, 0 },

  { "LeftDoor3Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor3Lockout), 0, 0, 0 },

  { "LeftDoor4Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor4Lockout), 0, 0, 0 },

  { "RightDoor1Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor1Lockout), 0, 0, 0 },

  { "RightDoor2Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor2Lockout), 0, 0, 0 },

  { "RightDoor3Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor3Lockout), 0, 0, 0 },

  { "RightDoor4Lockout", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor4Lockout), 0, 0, 0 },

  { "LeftDoor1EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor1EED), 0, 0, 0 },

  { "LeftDoor2EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor2EED), 0, 0, 0 },

  { "LeftDoor3EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor3EED), 0, 0, 0 },

  { "LeftDoor4EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    LeftDoor4EED), 0, 0, 0 },

  { "RightDoor1EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor1EED), 0, 0, 0 },

  { "RightDoor2EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor2EED), 0, 0, 0 },

  { "RightDoor3EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor3EED), 0, 0, 0 },

  { "RightDoor4EED", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    RightDoor4EED), 0, 0, 0 },

  { "RampCoverLockingLever", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, RampCoverLockingLever), 0, 0,
    0 },

  { "HornManuallyIsolated", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_InputControlStates, HornManuallyIsolated), 14, 0,
    0 },

  { "BIC1Inside", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    BIC1Inside), 0, 0, 0 },

  { "BIC1Outside", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    BIC1Outside), 0, 0, 0 },

  { "BIC2Inside", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    BIC2Inside), 0, 0, 0 },

  { "BIC2Outside", rt_offsetof(BD_TCMSSystem_In_Vehicle_InputControlStates,
    BIC2Outside), 0, 0, 0 },

  { "RightDoorsEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    RightDoorsEnable), 0, 0, 0 },

  { "LeftDoorsEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    LeftDoorsEnable), 0, 0, 0 },

  { "DoorsPairEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    DoorsPairEnable), 0, 1, 0 },

  { "LineVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment, LineVoltage),
    0, 0, 0 },

  { "OverheadLinePresent", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    OverheadLinePresent), 0, 0, 0 },

  { "NeutralSection", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    NeutralSection), 0, 0, 0 },

  { "VehiclesPassedNS", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment,
    VehiclesPassedNS), 0, 0, 0 },

  { "DamagedOHE", rt_offsetof(BD_TCMSSystem_In_Vehicle_Environment, DamagedOHE),
    0, 0, 0 },

  { "BrakeCylinderPressureGauge", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BrakeCylinderPressureGauge),
    0, 0, 0 },

  { "ParkBrakePressureGauge", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, ParkBrakePressureGauge), 0,
    0, 0 },

  { "AirSuspensionLoadPressure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, AirSuspensionLoadPressure),
    0, 0, 0 },

  { "EstimatedBogieSupportedMass", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie,
     EstimatedBogieSupportedMass), 0, 0, 0 },

  { "ServiceBrakeSwitchStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, ServiceBrakeSwitchStatus),
    0, 0, 0 },

  { "PrakingBrakeSwitchStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, PrakingBrakeSwitchStatus),
    0, 0, 0 },

  { "AirSuspensionSwitchStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, AirSuspensionSwitchStatus),
    0, 0, 0 },

  { "AirSuspensionPressure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, AirSuspensionPressure), 0,
    0, 0 },

  { "BECU1EmergencyBrakeFailure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1EmergencyBrakeFailure),
    14, 0, 0 },

  { "BECU2EmergencyBrakeFailure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU2EmergencyBrakeFailure),
    14, 0, 0 },

  { "BECU1ServiceBrakeFailure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1ServiceBrakeFailure),
    14, 0, 0 },

  { "BECU1BrakeNotApplied", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1BrakeNotApplied), 14,
    0, 0 },

  { "BECU1BrakeNotReleased", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1BrakeNotReleased), 14,
    0, 0 },

  { "BECU1CarLoadPressureLow", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1CarLoadPressureLow),
    14, 0, 0 },

  { "BECU2CarLoadPressureLow", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU2CarLoadPressureLow),
    14, 0, 0 },

  { "BECULowRPressure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECULowRPressure), 14, 0,
    0 },

  { "AirSuspensionBogie1Deflated", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie,
     AirSuspensionBogie1Deflated), 14, 0, 0 },

  { "BECU1LoadPressureLow", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie, BECU1LoadPressureLow), 14,
    0, 0 },

  { "MainReservoirPressureGauge", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem, MainReservoirPressureGauge), 0,
    0, 0 },

  { "MainReservoirPipePressure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem, MainReservoirPipePressure), 0, 0,
    0 },

  { "PantographPressure", rt_offsetof(BD_TCMSSystem_In_Vehicle_PneumaticsSystem,
    PantographPressure), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_TCMSSystem_In_Vehicle_PneumaticsSystem, Bogie), 160,
    2, 0 },

  { "BrakeDemandSignalFailure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem, BrakeDemandSignalFailure), 0, 0,
    0 },

  { "LowMRTractionCutoutSwitch", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PneumaticsSystem, LowMRTractionCutoutSwitch), 0, 0,
    0 },

  { "DoorClosedStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorClosedStatus), 14, 0, 0 },

  { "DoorOpenStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorOpenStatus), 14, 0, 0 },

  { "DoorReleasedAuthorisedToOpenStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
     DoorReleasedAuthorisedToOpenStatus), 14, 0, 0 },

  { "DoorEmergencyReleasedStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door, DoorEmergencyReleasedStatus), 14,
    0, 0 },

  { "DoorIsolatedStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorIsolatedStatus), 14, 0, 0 },

  { "DoorFaultStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorFaultStatus), 14, 0, 0 },

  { "DoorObstacleDetected", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorObstacleDetected), 14, 0, 0 },

  { "DoorObstacleUnableToClose", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door, DoorObstacleUnableToClose), 14, 0,
    0 },

  { "DoorLockedStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorLockedStatus), 14, 0, 0 },

  { "DoorPosition", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorPosition), 0, 0, 0 },

  { "DoorOpenObstruction", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorOpenObstruction), 14, 0, 0 },

  { "DoorCloseObstruction", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorCloseObstruction), 14, 0, 0 },

  { "DoorOpenPBLight", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorOpenPBLight), 14, 0, 0 },

  { "DoorClosedPBLight", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorClosedPBLight), 14, 0, 0 },

  { "DoorMotorCircuitFailure", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door, DoorMotorCircuitFailure), 14, 0,
    0 },

  { "DoorFailedToLock", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorFailedToLock), 14, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorFailedToUnlock), 14, 0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door, DoorUnexpectedUnlocking), 14, 0,
    0 },

  { "DCUFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DCUFailure), 14, 0, 0 },

  { "DCSRFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DCSRFailure), 14, 0, 0 },

  { "DCSLFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DCSLFailure), 14, 0, 0 },

  { "DLSRFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DLSRFailure), 14, 0, 0 },

  { "DLSLFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DLSLFailure), 14, 0, 0 },

  { "DoorMajorFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_Door,
    DoorMajorFault), 14, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_Door, UnexpectedDoorOpeningDetectedByCC),
    14, 0, 0 },

  { "Ramp", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor, Ramp),
    14, 0, 0 },

  { "EmergencyDoorOpen", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor, EmergencyDoorOpen), 14,
    0, 0 },

  { "EmergencyDoorLocked", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor, EmergencyDoorLocked), 14,
    0, 0 },

  { "EmerDoorOpenFaultMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor, EmerDoorOpenFaultMessage),
    14, 0, 0 },

  { "Doors", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem, Doors), 162, 5, 0
  },

  { "EmergencyDoor", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem,
    EmergencyDoor), 163, 0, 0 },

  { "AllLeftDoorClosed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem,
    AllLeftDoorClosed), 14, 0, 0 },

  { "AllRightDoorClosed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DoorSystem,
    AllRightDoorClosed), 14, 0, 0 },

  { "TCMSPowerAvailable", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    TCMSPowerAvailable), 14, 0, 0 },

  { "CabActive", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    CabActive), 14, 0, 0 },

  { "ForwardDirection", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ForwardDirection), 14, 0, 0 },

  { "ReverseDirection", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ReverseDirection), 14, 0, 0 },

  { "Speedometer", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    Speedometer), 0, 0, 0 },

  { "ZeroSpeed", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ZeroSpeed), 14, 0, 0 },

  { "TractionOn", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    TractionOn), 14, 0, 0 },

  { "BrakeOn", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, BrakeOn),
    14, 0, 0 },

  { "TractionSafe", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    TractionSafe), 14, 0, 0 },

  { "AllRightDoorsClosed", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, AllRightDoorsClosed), 14, 0, 0
  },

  { "AllLeftDoorsClosed", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    AllLeftDoorsClosed), 14, 0, 0 },

  { "ServiceBrakesReleased", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, ServiceBrakesReleased), 14, 0,
    0 },

  { "ParkBrakesReleased", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ParkBrakesReleased), 14, 0, 0 },

  { "ParkBrakeApplication", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, ParkBrakeApplication), 14, 0, 0
  },

  { "ServiceBrakeApplication", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, ServiceBrakeApplication), 14, 0,
    0 },

  { "PantoLowered", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PantoLowered), 14, 0, 0 },

  { "PantoRaised", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PantoRaised), 14, 0, 0 },

  { "PantoPowerDetected", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PantoPowerDetected), 14, 0, 0 },

  { "VCBState", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, VCBState),
    14, 0, 0 },

  { "AK1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    AK1Status), 14, 0, 0 },

  { "AK2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    AK2Status), 14, 0, 0 },

  { "K1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, K1Status),
    14, 0, 0 },

  { "K2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, K2Status),
    14, 0, 0 },

  { "FilterVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    FilterVoltage), 0, 0, 0 },

  { "BCG1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG1Status), 14, 0, 0 },

  { "BCG2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG2Status), 14, 0, 0 },

  { "BCGOutputVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCGOutputVoltage), 0, 0, 0 },

  { "BatteryVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BatteryVoltage), 0, 0, 0 },

  { "BatteryCurrent", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BatteryCurrent), 0, 0, 0 },

  { "BatteryTemperature", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BatteryTemperature), 0, 0, 0 },

  { "BCG1OutputCurrent", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG1OutputCurrent), 0, 0, 0 },

  { "BCG2OutputCurrent", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG2OutputCurrent), 0, 0, 0 },

  { "BrakeTrainLine", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BrakeTrainLine), 14, 0, 0 },

  { "MotorTrainLine", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MotorTrainLine), 14, 0, 0 },

  { "FSB1Line", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, FSB1Line),
    14, 0, 0 },

  { "FSB2Line", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, FSB2Line),
    14, 0, 0 },

  { "EB1Line", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, EB1Line),
    14, 0, 0 },

  { "EB2Line", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, EB2Line),
    14, 0, 0 },

  { "LineVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LineVoltage), 0, 0, 0 },

  { "NoEB", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, NoEB), 14, 0,
    0 },

  { "VCBTripCommand", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    VCBTripCommand), 14, 0, 0 },

  { "MotorPowerAvailable", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, MotorPowerAvailable), 14, 0, 0
  },

  { "LeftDoorRelease", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LeftDoorRelease), 14, 0, 0 },

  { "RightDoorRelease", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RightDoorRelease), 14, 0, 0 },

  { "LeftDoorOpen", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LeftDoorOpen), 14, 0, 0 },

  { "RightDoorOpen", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RightDoorOpen), 14, 0, 0 },

  { "LeftDoorClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LeftDoorClose), 14, 0, 0 },

  { "RightDoorClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RightDoorClose), 14, 0, 0 },

  { "APS1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS1Status), 14, 0, 0 },

  { "APS2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS2Status), 14, 0, 0 },

  { "APS1Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS1Fault), 14, 0, 0 },

  { "APS2Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS2Fault), 14, 0, 0 },

  { "APS1Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS1Isolated), 14, 0, 0 },

  { "APS2Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS2Isolated), 14, 0, 0 },

  { "APS1OutputVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS1OutputVoltage), 0, 0, 0 },

  { "APS2OutputVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APS2OutputVoltage), 0, 0, 0 },

  { "HLSwitchStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HLSwitchStatus), 14, 0, 0 },

  { "MarkerAndTailLight", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MarkerAndTailLight), 0, 0, 0 },

  { "FlasherLightStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    FlasherLightStatus), 14, 0, 0 },

  { "CallOnLightStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    CallOnLightStatus), 14, 0, 0 },

  { "UTOOrRMLight", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    UTOOrRMLight), 0, 0, 0 },

  { "PADPBStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PADPBStatus), 14, 0, 0 },

  { "PADRStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PADRStatus), 14, 0, 0 },

  { "PowerONPBPressed", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PowerONPBPressed), 14, 0, 0 },

  { "PowerOFFPBPressed", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PowerOFFPBPressed), 14, 0, 0 },

  { "TPOR_ON", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, TPOR_ON),
    14, 0, 0 },

  { "TSDR_ON", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, TSDR_ON),
    14, 0, 0 },

  { "LeftDoorOpenCmdInLimpHome", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, LeftDoorOpenCmdInLimpHome), 14,
    0, 0 },

  { "RightDoorOpenCmdInLimpHome", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, RightDoorOpenCmdInLimpHome), 14,
    0, 0 },

  { "LeftDoorEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LeftDoorEnable), 14, 0, 0 },

  { "RightDoorEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RightDoorEnable), 14, 0, 0 },

  { "LeftHoldDoorClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LeftHoldDoorClose), 14, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RightHoldDoorClose), 14, 0, 0 },

  { "LimpHomeMode", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    LimpHomeMode), 14, 0, 0 },

  { "FwdRevTrainLineMismatchMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, FwdRevTrainLineMismatchMessage),
    14, 0, 0 },

  { "LowMRPressureFaultMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, LowMRPressureFaultMessage), 14,
    0, 0 },

  { "BCUPower", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, BCUPower),
    14, 0, 0 },

  { "SaloonLightGroupStatus1", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, SaloonLightGroupStatus1), 0, 0,
    0 },

  { "SaloonLightGroupStatus2", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, SaloonLightGroupStatus2), 0, 0,
    0 },

  { "WFLStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    WFLStatus), 0, 0, 0 },

  { "WFLOilLevelStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    WFLOilLevelStatus), 0, 0, 0 },

  { "WFLPump1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    WFLPump1Status), 0, 0, 0 },

  { "WFLPump2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    WFLPump2Status), 0, 0, 0 },

  { "BatteryIsolationContactor", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, BatteryIsolationContactor), 14,
    0, 0 },

  { "TrainControlContactor", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, TrainControlContactor), 14, 0,
    0 },

  { "MainCompressor", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MainCompressor), 14, 0, 0 },

  { "AuxCompressor", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    AuxCompressor), 14, 0, 0 },

  { "HVAC1Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC1Status), 0, 0, 0 },

  { "HVAC1SetPointTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC1SetPointTemperature), 0, 0,
    0 },

  { "HVAC1IntTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC1IntTemperature), 0, 0, 0 },

  { "HVAC1ExtTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC1ExtTemperature), 0, 0, 0 },

  { "HVAC1Faulty", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC1Faulty), 14, 0, 0 },

  { "HVAC1Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC1Isolated), 14, 0, 0 },

  { "HVAC2Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC2Status), 0, 0, 0 },

  { "HVAC2SetPointTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC2SetPointTemperature), 0, 0,
    0 },

  { "HVAC2IntTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC2IntTemperature), 0, 0, 0 },

  { "HVAC2ExtTemperature", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, HVAC2ExtTemperature), 0, 0, 0 },

  { "HVAC2Faulty", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC2Faulty), 14, 0, 0 },

  { "HVAC2Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVAC2Isolated), 14, 0, 0 },

  { "NoOfAPSFailed", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    NoOfAPSFailed), 0, 0, 0 },

  { "PECStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PECStatus), 14, 0, 0 },

  { "EBbyNonCabEnabled", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    EBbyNonCabEnabled), 14, 0, 0 },

  { "EBbyMC", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, EBbyMC),
    14, 0, 0 },

  { "EBbyBrakeLoop", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    EBbyBrakeLoop), 14, 0, 0 },

  { "EBbyDeadMan", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    EBbyDeadMan), 14, 0, 0 },

  { "NoLineVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    NoLineVoltage), 14, 0, 0 },

  { "D1Power", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, D1Power),
    14, 0, 0 },

  { "EBApplied", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    EBApplied), 14, 0, 0 },

  { "EBbyCC", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, EBbyCC),
    14, 0, 0 },

  { "EBdueToATCZeroSpeed", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, EBdueToATCZeroSpeed), 14, 0, 0
  },

  { "ADDCOSStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ADDCOSStatus), 14, 0, 0 },

  { "ORDCOSStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ORDCOSStatus), 14, 0, 0 },

  { "MRIsolation", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MRIsolation), 14, 0, 0 },

  { "MCBPAGroupStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBPAGroupStatus), 14, 0, 0 },

  { "MCB110VDCGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCB110VDCGroup), 14, 0, 0 },

  { "MCBLightGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBLightGroup), 14, 0, 0 },

  { "MCBLightSaloonGroup", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, MCBLightSaloonGroup), 14, 0, 0
  },

  { "MCBDoorGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBDoorGroup), 14, 0, 0 },

  { "MCBBrakeGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBBrakeGroup), 14, 0, 0 },

  { "MCBAPSGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBAPSGroup), 14, 0, 0 },

  { "MCBTCMSGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBTCMSGroup), 14, 0, 0 },

  { "MCBSignallingGroup", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCBSignallingGroup), 14, 0, 0 },

  { "HVACFaults", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HVACFaults), 0, 4, 0 },

  { "WFLFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, WFLFault),
    0, 0, 0 },

  { "CECBTripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    CECBTripped), 14, 0, 0 },

  { "UCCBTripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    UCCBTripped), 14, 0, 0 },

  { "PANCBTripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PANCBTripped), 14, 0, 0 },

  { "ELCB1Tripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ELCB1Tripped), 14, 0, 0 },

  { "ELCB2Tripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ELCB2Tripped), 14, 0, 0 },

  { "ILCB1Tripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ILCB1Tripped), 14, 0, 0 },

  { "ILCB2Tripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ILCB2Tripped), 14, 0, 0 },

  { "APSCBTripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    APSCBTripped), 14, 0, 0 },

  { "FDUFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    FDUFailure), 14, 0, 0 },

  { "InternalFireAlarmTLActive", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, InternalFireAlarmTLActive), 14,
    0, 0 },

  { "SmokeAlarmCABArea", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    SmokeAlarmCABArea), 14, 0, 0 },

  { "HeatAlarmEDB", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    HeatAlarmEDB), 14, 0, 0 },

  { "FDUStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    FDUStatus), 14, 0, 0 },

  { "SFARStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    SFARStatus), 14, 0, 0 },

  { "UFARStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    UFARStatus), 14, 0, 0 },

  { "BUVDR_Active", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BUVDR_Active), 14, 0, 0 },

  { "CMCActivationFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    CMCActivationFault), 14, 0, 0 },

  { "CMCDeactivationFault", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, CMCDeactivationFault), 14, 0, 0
  },

  { "HMIPower", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, HMIPower),
    14, 0, 0 },

  { "ReverseMotionInForwardCommandMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals,
     ReverseMotionInForwardCommandMessage), 14, 0, 0 },

  { "ParkBrakeApplyCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, ParkBrakeApplyCommand), 14, 0,
    0 },

  { "ParkBrakeReleaseCommand", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, ParkBrakeReleaseCommand), 14, 0,
    0 },

  { "UW_VCB", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, UW_VCB), 0,
    0, 0 },

  { "PantoDownPBCmd", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    PantoDownPBCmd), 0, 0, 0 },

  { "DCUPower", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, DCUPower),
    14, 3, 0 },

  { "VCBTripByCI", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    VCBTripByCI), 0, 0, 0 },

  { "CIIsolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    CIIsolated), 0, 0, 0 },

  { "BCG1Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG1Fault), 0, 0, 0 },

  { "BCG2Fault", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG2Fault), 0, 0, 0 },

  { "BCG1Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG1Isolated), 0, 0, 0 },

  { "BCG2Isolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BCG2Isolated), 0, 0, 0 },

  { "BCG1IsolationFailed", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, BCG1IsolationFailed), 0, 0, 0 },

  { "EBbyPB", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, EBbyPB),
    14, 0, 0 },

  { "VCBTripByAPS", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    VCBTripByAPS), 0, 0, 0 },

  { "VCBIsolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    VCBIsolated), 0, 0, 0 },

  { "MCDR", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals, MCDR), 14, 0,
    0 },

  { "MCDRFaulty", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    MCDRFaulty), 14, 0, 0 },

  { "ObstacleDetected", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ObstacleDetected), 14, 0, 0 },

  { "ODDFailure", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    ODDFailure), 0, 0, 0 },

  { "MCBHVACGroupTripped", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, MCBHVACGroupTripped), 14, 0, 0
  },

  { "Key_Switch_Status", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    Key_Switch_Status), 0, 0, 0 },

  { "VCBI_ACOvercurrent", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    VCBI_ACOvercurrent), 0, 0, 0 },

  { "VCBI_KAKContactorCI", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, VCBI_KAKContactorCI), 0, 0, 0 },

  { "EmergencyDoorNotOpenStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, EmergencyDoorNotOpenStatus), 0,
    0, 0 },

  { "DoorProvenLoopOK", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    DoorProvenLoopOK), 0, 0, 0 },

  { "BrakeLoopCBTripped", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BrakeLoopCBTripped), 0, 0, 0 },

  { "DeadmanBypassStatus", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_ElectricalSignals, DeadmanBypassStatus), 14, 0, 0
  },

  { "BLCOSwitchStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    BLCOSwitchStatus), 14, 0, 0 },

  { "NoOfEPICCutout", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    NoOfEPICCutout), 0, 0, 0 },

  { "WFLIsolated", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    WFLIsolated), 0, 0, 0 },

  { "RemoteMagnetValve1", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RemoteMagnetValve1), 0, 0, 0 },

  { "RemoteMagnetValve2", rt_offsetof(BD_TCMSSystem_In_Vehicle_ElectricalSignals,
    RemoteMagnetValve2), 0, 0, 0 },

  { "PantographPosition", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantographPosition), 0, 0, 0 },

  { "PantoUpStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantoUpStatus), 14, 0, 0 },

  { "PantoDownStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantoDownStatus), 14, 0, 0 },

  { "PantoIsolatedStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantoIsolatedStatus), 14, 0, 0 },

  { "PantoRising", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantoRising), 14, 0, 0 },

  { "PantoLowering", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantoLowering), 14, 0, 0 },

  { "PantographFault", rt_offsetof(BD_TCMSSystem_In_Vehicle_PantographSystem,
    PantographFault), 14, 0, 0 },

  { "PantoADDFaultMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PantographSystem, PantoADDFaultMessage), 14, 0, 0
  },

  { "PantoORDFaultMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PantographSystem, PantoORDFaultMessage), 14, 0, 0
  },

  { "PantoRaiseFailureMessage", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PantographSystem, PantoRaiseFailureMessage), 14, 0,
    0 },

  { "BrakeLoopADDIntervention", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_PantographSystem, BrakeLoopADDIntervention), 14, 0,
    0 },

  { "TCUStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    TCUStatus), 14, 0, 0 },

  { "BogieFaulty", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    BogieFaulty), 14, 0, 0 },

  { "TractionNotIsolated", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, TractionNotIsolated), 14, 0,
    0 },

  { "EDBrakeNotIsolated", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, EDBrakeNotIsolated), 14, 0,
    0 },

  { "TCUSlideDetected", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, TCUSlideDetected), 14, 0, 0
  },

  { "TCUSlipDetected", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    TCUSlipDetected), 14, 0, 0 },

  { "TractiveEffortAchieved", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, TractiveEffortAchieved), 0,
    0, 0 },

  { "EDBrakingEffortAchieved", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, EDBrakingEffortAchieved), 0,
    0, 0 },

  { "TractiveEffortPossible", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, TractiveEffortPossible), 0,
    0, 0 },

  { "EDBrakingEffortPossible", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, EDBrakingEffortPossible), 0,
    0, 0 },

  { "TractionPower", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    TractionPower), 0, 0, 0 },

  { "EDBrakingPower", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    EDBrakingPower), 0, 0, 0 },

  { "TractivePowerPossible", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, TractivePowerPossible), 0, 0,
    0 },

  { "EDBrakingPowerPossible", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, EDBrakingPowerPossible), 0,
    0, 0 },

  { "MotorSpeeds", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie,
    MotorSpeeds), 0, 2, 0 },

  { "WSPTractionCutout", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, WSPTractionCutout), 14, 0, 0
  },

  { "SpeedSensorFault", rt_offsetof
    (BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie, SpeedSensorFault), 14, 0, 0
  },

  { "Bogie", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem, Bogie), 167, 2,
    0 },

  { "TCU_KStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem,
    TCU_KStatus), 14, 0, 0 },

  { "TCU_AKStatus", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem,
    TCU_AKStatus), 14, 0, 0 },

  { "FilterVoltage", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem,
    FilterVoltage), 0, 0, 0 },

  { "VehicleDerailed", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem,
    VehicleDerailed), 0, 0, 0 },

  { "TractionForce", rt_offsetof(BD_TCMSSystem_In_Vehicle_TractionSystem,
    TractionForce), 0, 0, 0 },

  { "UnitConnection", rt_offsetof(BD_TCMSSystem_In_Vehicle_CouplingSystem,
    UnitConnection), 0, 0, 0 },

  { "TrainConnection", rt_offsetof(BD_TCMSSystem_In_Vehicle_CouplingSystem,
    TrainConnection), 0, 0, 0 },

  { "TrainsCoupled", rt_offsetof(BD_TCMSSystem_In_Vehicle_CouplingSystem,
    TrainsCoupled), 0, 2, 0 },

  { "RescueModeCondition", rt_offsetof(BD_TCMSSystem_In_Vehicle_CouplingSystem,
    RescueModeCondition), 14, 2, 0 },

  { "LeftDoorOpenRequest", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    LeftDoorOpenRequest), 0, 0, 0 },

  { "RightDoorOpenRequest", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    RightDoorOpenRequest), 0, 0, 0 },

  { "LeftDoorCloseRequest", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    LeftDoorCloseRequest), 0, 0, 0 },

  { "RightDoorCloseRequest", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    RightDoorCloseRequest), 0, 0, 0 },

  { "ATOTBDemandPct", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, ATOTBDemandPct),
    0, 0, 0 },

  { "NoServiceBrakeOrder", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    NoServiceBrakeOrder), 14, 0, 0 },

  { "ATOTraction", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, ATOTraction), 14,
    0, 0 },

  { "ATOBraking", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, ATOBraking), 14, 0,
    0 },

  { "NotImmobilise", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, NotImmobilise),
    14, 0, 0 },

  { "DriverModeSelection", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    DriverModeSelection), 0, 0, 0 },

  { "ATCBypassState", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, ATCBypassState),
    0, 0, 0 },

  { "LeftSideDoorEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    LeftSideDoorEnable), 0, 0, 0 },

  { "RightSideDoorEnable", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    RightSideDoorEnable), 0, 0, 0 },

  { "ATCWakeup", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC, ATCWakeup), 0, 0, 0
  },

  { "RollbackDetected", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    RollbackDetected), 0, 0, 0 },

  { "LeftDoorCloseIndicator", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    LeftDoorCloseIndicator), 0, 0, 0 },

  { "RightDoorCloseIndicator", rt_offsetof(BD_TCMSSystem_In_Vehicle_CBTC,
    RightDoorCloseIndicator), 0, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_TCMSSystem_In_Vehicle_BrakingSystem,
    BrakingForce), 0, 0, 0 },

  { "VehicleSpeed", rt_offsetof(BD_TCMSSystem_In_Vehicle_DynamicsSystem,
    VehicleSpeed), 0, 0, 0 },

  { "InputControlStates", rt_offsetof(BD_TCMSSystem_In_Vehicle,
    InputControlStates), 158, 0, 0 },

  { "DisplayControl", rt_offsetof(BD_TCMSSystem_In_Vehicle, DisplayControl), 16,
    0, 0 },

  { "Environment", rt_offsetof(BD_TCMSSystem_In_Vehicle, Environment), 159, 0, 0
  },

  { "PneumaticsSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, PneumaticsSystem),
    161, 0, 0 },

  { "DoorSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, DoorSystem), 164, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_TCMSSystem_In_Vehicle, ElectricalSignals),
    165, 0, 0 },

  { "PantographSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, PantographSystem),
    166, 0, 0 },

  { "TractionSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, TractionSystem), 168,
    0, 0 },

  { "CouplingSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, CouplingSystem), 169,
    0, 0 },

  { "CBTC", rt_offsetof(BD_TCMSSystem_In_Vehicle, CBTC), 170, 0, 0 },

  { "BrakingSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, BrakingSystem), 171,
    0, 0 },

  { "DynamicsSystem", rt_offsetof(BD_TCMSSystem_In_Vehicle, DynamicsSystem), 172,
    0, 0 },

  { "HasMotors", rt_offsetof(BD_TractionSystem_Cfg_Vehicle, HasMotors), 14, 0, 0
  },

  { "TCUPower", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie,
    TCUPower), 14, 0, 0 },

  { "TractionAuthorisation", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie, TractionAuthorisation),
    14, 0, 0 },

  { "TractionCutoff", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie, TractionCutoff), 0, 0,
    0 },

  { "DynamicBrakingCutoff", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie, DynamicBrakingCutoff),
    0, 0, 0 },

  { "PowerAvailable", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem,
    PowerAvailable), 14, 0, 0 },

  { "ForwardTW", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem,
    ForwardTW), 14, 0, 0 },

  { "ReverseTW", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem,
    ReverseTW), 14, 0, 0 },

  { "TractionActiveTW", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem, TractionActiveTW), 14, 0, 0
  },

  { "NoEmergencyBrakeActiveTW", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem, NoEmergencyBrakeActiveTW),
    14, 0, 0 },

  { "VCBState", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem,
    VCBState), 14, 0, 0 },

  { "ContactorsFailure", rt_offsetof
    (BD_TractionSystem_In_Vehicle_ElectricalSystem, ContactorsFailure), 14, 0, 0
  },

  { "Bogie", rt_offsetof(BD_TractionSystem_In_Vehicle_ElectricalSystem, Bogie),
    175, 2, 0 },

  { "WheelSlip", rt_offsetof(BD_TractionSystem_In_Vehicle_Dynamics_Bogie,
    WheelSlip), 0, 2, 0 },

  { "WheelSlide", rt_offsetof(BD_TractionSystem_In_Vehicle_Dynamics_Bogie,
    WheelSlide), 0, 2, 0 },

  { "WheelSpeed", rt_offsetof(BD_TractionSystem_In_Vehicle_Dynamics_Bogie,
    WheelSpeed), 0, 2, 0 },

  { "Velocity", rt_offsetof(BD_TractionSystem_In_Vehicle_Dynamics, Velocity), 0,
    0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_In_Vehicle_Dynamics, Bogie), 177, 2,
    0 },

  { "TCMSTractionInhibit", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS_Bogie,
    TCMSTractionInhibit), 14, 0, 0 },

  { "TCMSDynamicBrakingInhibit", rt_offsetof
    (BD_TractionSystem_In_Vehicle_TCMS_Bogie, TCMSDynamicBrakingInhibit), 0, 0,
    0 },

  { "BogieSupportedMass", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS_Bogie,
    BogieSupportedMass), 0, 0, 0 },

  { "BogieIsolationStatus", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS_Bogie,
    BogieIsolationStatus), 0, 0, 0 },

  { "TCMSTractionCmd", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS,
    TCMSTractionCmd), 0, 0, 0 },

  { "TCMSEDBrakingCmd", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS,
    TCMSEDBrakingCmd), 0, 0, 0 },

  { "TractiveLosses", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS,
    TractiveLosses), 0, 0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_In_Vehicle_TCMS, Bogie), 179, 2, 0 },

  { "ElectricalSystem", rt_offsetof(BD_TractionSystem_In_Vehicle,
    ElectricalSystem), 176, 0, 0 },

  { "Dynamics", rt_offsetof(BD_TractionSystem_In_Vehicle, Dynamics), 178, 0, 0 },

  { "TCMS", rt_offsetof(BD_TractionSystem_In_Vehicle, TCMS), 180, 0, 0 },

  { "TractionForceVariation", rt_offsetof(BD_TractionSystem_In_Overrides,
    TractionForceVariation), 0, 0, 0 },

  { "DynamicBrakeForceVariation", rt_offsetof(BD_TractionSystem_In_Overrides,
    DynamicBrakeForceVariation), 0, 0, 0 },

  { "CCMCBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    CCMCBInternalRequest), 14, 0, 0 },

  { "WWCBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    WWCBInternalRequest), 14, 0, 0 },

  { "CELCBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    CELCBInternalRequest), 14, 0, 0 },

  { "HLCBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    HLCBInternalRequest), 14, 0, 0 },

  { "MCBPAGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBPAGroupOpenInternalRequest), 14, 0,
    0 },

  { "MCB110VDCGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCB110VDCGroupOpenInternalRequest), 14,
    0, 0 },

  { "MCBLightGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBLightGroupOpenInternalRequest), 14,
    0, 0 },

  { "MCBLightSaloonGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBLightSaloonGroupOpenInternalRequest),
    14, 0, 0 },

  { "MCBDoorGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBDoorGroupOpenInternalRequest), 14,
    0, 0 },

  { "MCBBrakeGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBBrakeGroupOpenInternalRequest), 14,
    0, 0 },

  { "MCBAPSGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBAPSGroupOpenInternalRequest), 14, 0,
    0 },

  { "MCBTCMSGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBTCMSGroupOpenInternalRequest), 14,
    0, 0 },

  { "MCBSignallingGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBSignallingGroupOpenInternalRequest),
    14, 0, 0 },

  { "CECBOpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    CECBOpenInternalRequest), 14, 0, 0 },

  { "ELCB1OpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    ELCB1OpenInternalRequest), 14, 0, 0 },

  { "ELCB2OpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    ELCB2OpenInternalRequest), 14, 0, 0 },

  { "ILCB1OpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    ILCB1OpenInternalRequest), 14, 0, 0 },

  { "ILCB2OpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    ILCB2OpenInternalRequest), 14, 0, 0 },

  { "APSCBOpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    APSCBOpenInternalRequest), 14, 0, 0 },

  { "UCCBOpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    UCCBOpenInternalRequest), 14, 0, 0 },

  { "PANCBOpenInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    PANCBOpenInternalRequest), 14, 0, 0 },

  { "MCBHVACGroupOpenInternalRequest", rt_offsetof
    (BD_SimIntegration_Faults_IOControls, MCBHVACGroupOpenInternalRequest), 14,
    0, 0 },

  { "ORDPlungerInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    ORDPlungerInternalRequest), 14, 0, 0 },

  { "APSICBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    APSICBInternalRequest), 14, 0, 0 },

  { "FDSCBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    FDSCBInternalRequest), 14, 0, 0 },

  { "SAC1CBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    SAC1CBInternalRequest), 14, 0, 0 },

  { "SAC2CBInternalRequest", rt_offsetof(BD_SimIntegration_Faults_IOControls,
    SAC2CBInternalRequest), 14, 0, 0 },

  { "Value", rt_offsetof(BD_IOControls_In_InputControl, Value), 0, 0, 0 },

  { "Mode", rt_offsetof(BD_IOControls_In_InputControl, Mode), 0, 0, 0 },

  { "InitVal", rt_offsetof(BD_IOControls_In_InputControl, InitVal), 0, 0, 0 },

  { "InternalRequest", rt_offsetof(BD_IOControls_In_InputControl,
    InternalRequest), 0, 0, 0 },

  { "Inhibit", rt_offsetof(BD_IOControls_In_InputControl, Inhibit), 0, 0, 0 },

  { "Value", rt_offsetof(BD_IOControls_In_MCBControl, Value), 0, 0, 0 },

  { "Mode", rt_offsetof(BD_IOControls_In_MCBControl, Mode), 0, 0, 0 },

  { "InitVal", rt_offsetof(BD_IOControls_In_MCBControl, InitVal), 0, 0, 0 },

  { "InternalRequest", rt_offsetof(BD_IOControls_In_MCBControl, InternalRequest),
    0, 0, 0 },

  { "Inhibit", rt_offsetof(BD_IOControls_In_MCBControl, Inhibit), 0, 0, 0 },

  { "TripRequest", rt_offsetof(BD_IOControls_In_MCBControl, TripRequest), 0, 0,
    0 },

  { "EmergencyBrakePB", rt_offsetof(BD_IOControls_In_Vehicle, EmergencyBrakePB),
    184, 0, 0 },

  { "HornPB", rt_offsetof(BD_IOControls_In_Vehicle, HornPB), 184, 0, 0 },

  { "CabConsoleLightPB", rt_offsetof(BD_IOControls_In_Vehicle, CabConsoleLightPB),
    184, 0, 0 },

  { "DoorProvenLoopCutoutPB", rt_offsetof(BD_IOControls_In_Vehicle,
    DoorProvenLoopCutoutPB), 184, 0, 0 },

  { "LeftDoorClosePBOperatingPanel1", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoorClosePBOperatingPanel1), 184, 0, 0 },

  { "RightDoorClosePBOperatingPanel1", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoorClosePBOperatingPanel1), 184, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel1", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoorOpenPBOperatingPanel1), 184, 0, 0 },

  { "RightDoorOpenPBOperatingPanel1", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoorOpenPBOperatingPanel1), 184, 0, 0 },

  { "CabMainLightPB", rt_offsetof(BD_IOControls_In_Vehicle, CabMainLightPB), 184,
    0, 0 },

  { "ParkingBrakeOnSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    ParkingBrakeOnSwitch), 184, 0, 0 },

  { "ParkingBrakeOffSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    ParkingBrakeOffSwitch), 184, 0, 0 },

  { "DoorCloseAnnouncementPB", rt_offsetof(BD_IOControls_In_Vehicle,
    DoorCloseAnnouncementPB), 184, 0, 0 },

  { "ROSPB", rt_offsetof(BD_IOControls_In_Vehicle, ROSPB), 184, 0, 0 },

  { "UTOPB", rt_offsetof(BD_IOControls_In_Vehicle, UTOPB), 184, 0, 0 },

  { "ATOStartPB", rt_offsetof(BD_IOControls_In_Vehicle, ATOStartPB), 184, 0, 0 },

  { "EmergencyBrakeResetPB", rt_offsetof(BD_IOControls_In_Vehicle,
    EmergencyBrakeResetPB), 184, 0, 0 },

  { "ControlKey", rt_offsetof(BD_IOControls_In_Vehicle, ControlKey), 184, 0, 0 },

  { "ModeSelector", rt_offsetof(BD_IOControls_In_Vehicle, ModeSelector), 184, 0,
    0 },

  { "MasterControllerHandle", rt_offsetof(BD_IOControls_In_Vehicle,
    MasterControllerHandle), 184, 0, 0 },

  { "DeadmanSafetyDevice", rt_offsetof(BD_IOControls_In_Vehicle,
    DeadmanSafetyDevice), 184, 0, 0 },

  { "CallOnLightPB", rt_offsetof(BD_IOControls_In_Vehicle, CallOnLightPB), 184,
    0, 0 },

  { "VCBOpenPB", rt_offsetof(BD_IOControls_In_Vehicle, VCBOpenPB), 184, 0, 0 },

  { "WiperSelectionSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    WiperSelectionSwitch), 184, 0, 0 },

  { "WiperPump", rt_offsetof(BD_IOControls_In_Vehicle, WiperPump), 184, 0, 0 },

  { "LIMPHomePB", rt_offsetof(BD_IOControls_In_Vehicle, LIMPHomePB), 184, 0, 0 },

  { "PowerOffPB", rt_offsetof(BD_IOControls_In_Vehicle, PowerOffPB), 184, 0, 0 },

  { "PantoDownPB", rt_offsetof(BD_IOControls_In_Vehicle, PantoDownPB), 184, 0, 0
  },

  { "VCBClosePB", rt_offsetof(BD_IOControls_In_Vehicle, VCBClosePB), 184, 0, 0 },

  { "LeftDoorOpenPBOperatingPanel2", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoorOpenPBOperatingPanel2), 184, 0, 0 },

  { "LeftDoorOpenPB1OperatingPanel2", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoorOpenPB1OperatingPanel2), 184, 0, 0 },

  { "LeftDoorClosePBOperatingPanel2", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoorClosePBOperatingPanel2), 184, 0, 0 },

  { "PantoUpPB", rt_offsetof(BD_IOControls_In_Vehicle, PantoUpPB), 184, 0, 0 },

  { "SafetyCutoutSS", rt_offsetof(BD_IOControls_In_Vehicle, SafetyCutoutSS), 184,
    0, 0 },

  { "BrakeLoopCutoutSS", rt_offsetof(BD_IOControls_In_Vehicle, BrakeLoopCutoutSS),
    184, 0, 0 },

  { "PantoSelector", rt_offsetof(BD_IOControls_In_Vehicle, PantoSelector), 184,
    0, 0 },

  { "DeadmanBypassSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    DeadmanBypassSwitch), 184, 0, 0 },

  { "HeadLightSwitch", rt_offsetof(BD_IOControls_In_Vehicle, HeadLightSwitch),
    184, 0, 0 },

  { "UncouplePB", rt_offsetof(BD_IOControls_In_Vehicle, UncouplePB), 184, 0, 0 },

  { "FlasherLightPB", rt_offsetof(BD_IOControls_In_Vehicle, FlasherLightPB), 184,
    0, 0 },

  { "FloodLightPB", rt_offsetof(BD_IOControls_In_Vehicle, FloodLightPB), 184, 0,
    0 },

  { "BatteryResetPB", rt_offsetof(BD_IOControls_In_Vehicle, BatteryResetPB), 184,
    0, 0 },

  { "RightDoorOpenPBOperatingPanel5", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoorOpenPBOperatingPanel5), 184, 0, 0 },

  { "RightDoorOpenPB1OperatingPanel5", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoorOpenPB1OperatingPanel5), 184, 0, 0 },

  { "RightDoorClosePBOperatingPanel5", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoorClosePBOperatingPanel5), 184, 0, 0 },

  { "DoorProvenLoopOutputSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    DoorProvenLoopOutputSwitch), 184, 0, 0 },

  { "LampTestPB", rt_offsetof(BD_IOControls_In_Vehicle, LampTestPB), 184, 0, 0 },

  { "WFLTestPB", rt_offsetof(BD_IOControls_In_Vehicle, WFLTestPB), 184, 0, 0 },

  { "WiperControlSwitch", rt_offsetof(BD_IOControls_In_Vehicle,
    WiperControlSwitch), 184, 0, 0 },

  { "EmergencyStopPB", rt_offsetof(BD_IOControls_In_Vehicle, EmergencyStopPB),
    184, 0, 0 },

  { "HoldDoorCloseBypassSS", rt_offsetof(BD_IOControls_In_Vehicle,
    HoldDoorCloseBypassSS), 184, 0, 0 },

  { "CabBoosterFanSS", rt_offsetof(BD_IOControls_In_Vehicle, CabBoosterFanSS),
    184, 0, 0 },

  { "EmergencyBrakePBBypassSS", rt_offsetof(BD_IOControls_In_Vehicle,
    EmergencyBrakePBBypassSS), 184, 0, 0 },

  { "CabEEDLeft", rt_offsetof(BD_IOControls_In_Vehicle, CabEEDLeft), 184, 0, 0 },

  { "CabEEDRight", rt_offsetof(BD_IOControls_In_Vehicle, CabEEDRight), 184, 0, 0
  },

  { "SafetyCover", rt_offsetof(BD_IOControls_In_Vehicle, SafetyCover), 184, 0, 0
  },

  { "DummyCover", rt_offsetof(BD_IOControls_In_Vehicle, DummyCover), 184, 0, 0 },

  { "RampCoverLockingLever", rt_offsetof(BD_IOControls_In_Vehicle,
    RampCoverLockingLever), 184, 0, 0 },

  { "RampCover", rt_offsetof(BD_IOControls_In_Vehicle, RampCover), 184, 0, 0 },

  { "RampHandle", rt_offsetof(BD_IOControls_In_Vehicle, RampHandle), 184, 0, 0 },

  { "RampEndSupport", rt_offsetof(BD_IOControls_In_Vehicle, RampEndSupport), 184,
    0, 0 },

  { "RampMiddleSupport", rt_offsetof(BD_IOControls_In_Vehicle, RampMiddleSupport),
    184, 0, 0 },

  { "WinderHandlesAccessCover", rt_offsetof(BD_IOControls_In_Vehicle,
    WinderHandlesAccessCover), 184, 0, 0 },

  { "LargeHandle", rt_offsetof(BD_IOControls_In_Vehicle, LargeHandle), 184, 0, 0
  },

  { "RampWinder", rt_offsetof(BD_IOControls_In_Vehicle, RampWinder), 184, 0, 0 },

  { "SmallHandle", rt_offsetof(BD_IOControls_In_Vehicle, SmallHandle), 184, 0, 0
  },

  { "EmergencyDoorGasSpring", rt_offsetof(BD_IOControls_In_Vehicle,
    EmergencyDoorGasSpring), 184, 0, 0 },

  { "DoorWinder", rt_offsetof(BD_IOControls_In_Vehicle, DoorWinder), 184, 0, 0 },

  { "EBLR2CB", rt_offsetof(BD_IOControls_In_Vehicle, EBLR2CB), 185, 0, 0 },

  { "EBMVCB", rt_offsetof(BD_IOControls_In_Vehicle, EBMVCB), 185, 0, 0 },

  { "EDCB", rt_offsetof(BD_IOControls_In_Vehicle, EDCB), 185, 0, 0 },

  { "ELCB1", rt_offsetof(BD_IOControls_In_Vehicle, ELCB1), 185, 0, 0 },

  { "ELCB2", rt_offsetof(BD_IOControls_In_Vehicle, ELCB2), 185, 0, 0 },

  { "ERCB", rt_offsetof(BD_IOControls_In_Vehicle, ERCB), 185, 0, 0 },

  { "HCB", rt_offsetof(BD_IOControls_In_Vehicle, HCB), 185, 0, 0 },

  { "HLLCB", rt_offsetof(BD_IOControls_In_Vehicle, HLLCB), 185, 0, 0 },

  { "HLRCB", rt_offsetof(BD_IOControls_In_Vehicle, HLRCB), 185, 0, 0 },

  { "ILCB1", rt_offsetof(BD_IOControls_In_Vehicle, ILCB1), 185, 0, 0 },

  { "ILCB2", rt_offsetof(BD_IOControls_In_Vehicle, ILCB2), 185, 0, 0 },

  { "LDICB", rt_offsetof(BD_IOControls_In_Vehicle, LDICB), 185, 0, 0 },

  { "LDLCB", rt_offsetof(BD_IOControls_In_Vehicle, LDLCB), 185, 0, 0 },

  { "LDRCB", rt_offsetof(BD_IOControls_In_Vehicle, LDRCB), 185, 0, 0 },

  { "MLCB", rt_offsetof(BD_IOControls_In_Vehicle, MLCB), 185, 0, 0 },

  { "MMCB", rt_offsetof(BD_IOControls_In_Vehicle, MMCB), 185, 0, 0 },

  { "NBCB", rt_offsetof(BD_IOControls_In_Vehicle, NBCB), 185, 0, 0 },

  { "NVICB", rt_offsetof(BD_IOControls_In_Vehicle, NVICB), 185, 0, 0 },

  { "OCCB1", rt_offsetof(BD_IOControls_In_Vehicle, OCCB1), 185, 0, 0 },

  { "OCCB2", rt_offsetof(BD_IOControls_In_Vehicle, OCCB2), 185, 0, 0 },

  { "ODDCB", rt_offsetof(BD_IOControls_In_Vehicle, ODDCB), 185, 0, 0 },

  { "PBCB", rt_offsetof(BD_IOControls_In_Vehicle, PBCB), 185, 0, 0 },

  { "PISCB1", rt_offsetof(BD_IOControls_In_Vehicle, PISCB1), 185, 0, 0 },

  { "PISCB2", rt_offsetof(BD_IOControls_In_Vehicle, PISCB2), 185, 0, 0 },

  { "POCB", rt_offsetof(BD_IOControls_In_Vehicle, POCB), 185, 0, 0 },

  { "PPU1CB", rt_offsetof(BD_IOControls_In_Vehicle, PPU1CB), 185, 0, 0 },

  { "PPU2CB", rt_offsetof(BD_IOControls_In_Vehicle, PPU2CB), 185, 0, 0 },

  { "PPU3CB", rt_offsetof(BD_IOControls_In_Vehicle, PPU3CB), 185, 0, 0 },

  { "RIO1CB", rt_offsetof(BD_IOControls_In_Vehicle, RIO1CB), 185, 0, 0 },

  { "RIO2CB", rt_offsetof(BD_IOControls_In_Vehicle, RIO2CB), 185, 0, 0 },

  { "SIOCB1", rt_offsetof(BD_IOControls_In_Vehicle, SIOCB1), 185, 0, 0 },

  { "SIOCB2", rt_offsetof(BD_IOControls_In_Vehicle, SIOCB2), 185, 0, 0 },

  { "SSICB", rt_offsetof(BD_IOControls_In_Vehicle, SSICB), 185, 0, 0 },

  { "TBCCB1", rt_offsetof(BD_IOControls_In_Vehicle, TBCCB1), 185, 0, 0 },

  { "TBCCB2", rt_offsetof(BD_IOControls_In_Vehicle, TBCCB2), 185, 0, 0 },

  { "TBNCB", rt_offsetof(BD_IOControls_In_Vehicle, TBNCB), 185, 0, 0 },

  { "TDICB", rt_offsetof(BD_IOControls_In_Vehicle, TDICB), 185, 0, 0 },

  { "TLLCB", rt_offsetof(BD_IOControls_In_Vehicle, TLLCB), 185, 0, 0 },

  { "TLRCB", rt_offsetof(BD_IOControls_In_Vehicle, TLRCB), 185, 0, 0 },

  { "TRIVCB", rt_offsetof(BD_IOControls_In_Vehicle, TRIVCB), 185, 0, 0 },

  { "TVDUCB", rt_offsetof(BD_IOControls_In_Vehicle, TVDUCB), 185, 0, 0 },

  { "TWVCB", rt_offsetof(BD_IOControls_In_Vehicle, TWVCB), 185, 0, 0 },

  { "VCCBOrUCCB", rt_offsetof(BD_IOControls_In_Vehicle, VCCBOrUCCB), 185, 0, 0 },

  { "VCBCCB", rt_offsetof(BD_IOControls_In_Vehicle, VCBCCB), 185, 0, 0 },

  { "VIO1CB", rt_offsetof(BD_IOControls_In_Vehicle, VIO1CB), 185, 0, 0 },

  { "VIO2CB", rt_offsetof(BD_IOControls_In_Vehicle, VIO2CB), 185, 0, 0 },

  { "WFLCB", rt_offsetof(BD_IOControls_In_Vehicle, WFLCB), 185, 0, 0 },

  { "WIFICB", rt_offsetof(BD_IOControls_In_Vehicle, WIFICB), 185, 0, 0 },

  { "WWCB", rt_offsetof(BD_IOControls_In_Vehicle, WWCB), 185, 0, 0 },

  { "BECUCB1", rt_offsetof(BD_IOControls_In_Vehicle, BECUCB1), 185, 0, 0 },

  { "BECUCB2", rt_offsetof(BD_IOControls_In_Vehicle, BECUCB2), 185, 0, 0 },

  { "BECUCB3", rt_offsetof(BD_IOControls_In_Vehicle, BECUCB3), 185, 0, 0 },

  { "RSACB", rt_offsetof(BD_IOControls_In_Vehicle, RSACB), 185, 0, 0 },

  { "CMCCB", rt_offsetof(BD_IOControls_In_Vehicle, CMCCB), 185, 0, 0 },

  { "CILCB", rt_offsetof(BD_IOControls_In_Vehicle, CILCB), 185, 0, 0 },

  { "CICB", rt_offsetof(BD_IOControls_In_Vehicle, CICB), 185, 0, 0 },

  { "CELCB", rt_offsetof(BD_IOControls_In_Vehicle, CELCB), 185, 0, 0 },

  { "CECB", rt_offsetof(BD_IOControls_In_Vehicle, CECB), 185, 0, 0 },

  { "CDUCB", rt_offsetof(BD_IOControls_In_Vehicle, CDUCB), 185, 0, 0 },

  { "CCNVIO1CB", rt_offsetof(BD_IOControls_In_Vehicle, CCNVIO1CB), 185, 0, 0 },

  { "CBTCCB1", rt_offsetof(BD_IOControls_In_Vehicle, CBTCCB1), 185, 0, 0 },

  { "CBFCCB", rt_offsetof(BD_IOControls_In_Vehicle, CBFCCB), 185, 0, 0 },

  { "CBFCB", rt_offsetof(BD_IOControls_In_Vehicle, CBFCB), 185, 0, 0 },

  { "C1CB", rt_offsetof(BD_IOControls_In_Vehicle, C1CB), 185, 0, 0 },

  { "BLCB", rt_offsetof(BD_IOControls_In_Vehicle, BLCB), 185, 0, 0 },

  { "ZVBACB", rt_offsetof(BD_IOControls_In_Vehicle, ZVBACB), 185, 0, 0 },

  { "EBLR1CB", rt_offsetof(BD_IOControls_In_Vehicle, EBLR1CB), 185, 0, 0 },

  { "DRCB", rt_offsetof(BD_IOControls_In_Vehicle, DRCB), 185, 0, 0 },

  { "DPLCB", rt_offsetof(BD_IOControls_In_Vehicle, DPLCB), 185, 0, 0 },

  { "DMICB", rt_offsetof(BD_IOControls_In_Vehicle, DMICB), 185, 0, 0 },

  { "DLCB", rt_offsetof(BD_IOControls_In_Vehicle, DLCB), 185, 0, 0 },

  { "DIOCB2", rt_offsetof(BD_IOControls_In_Vehicle, DIOCB2), 185, 0, 0 },

  { "DIOCB1", rt_offsetof(BD_IOControls_In_Vehicle, DIOCB1), 185, 0, 0 },

  { "CSCCB", rt_offsetof(BD_IOControls_In_Vehicle, CSCCB), 185, 0, 0 },

  { "CSBCB", rt_offsetof(BD_IOControls_In_Vehicle, CSBCB), 185, 0, 0 },

  { "CSACB", rt_offsetof(BD_IOControls_In_Vehicle, CSACB), 185, 0, 0 },

  { "CRSBCB", rt_offsetof(BD_IOControls_In_Vehicle, CRSBCB), 185, 0, 0 },

  { "SOCB2", rt_offsetof(BD_IOControls_In_Vehicle, SOCB2), 185, 0, 0 },

  { "SOCB1", rt_offsetof(BD_IOControls_In_Vehicle, SOCB1), 185, 0, 0 },

  { "MSOCB5", rt_offsetof(BD_IOControls_In_Vehicle, MSOCB5), 185, 0, 0 },

  { "MSOCB4", rt_offsetof(BD_IOControls_In_Vehicle, MSOCB4), 185, 0, 0 },

  { "MSOCB3", rt_offsetof(BD_IOControls_In_Vehicle, MSOCB3), 185, 0, 0 },

  { "MSOCB2", rt_offsetof(BD_IOControls_In_Vehicle, MSOCB2), 185, 0, 0 },

  { "MSOCB1", rt_offsetof(BD_IOControls_In_Vehicle, MSOCB1), 185, 0, 0 },

  { "HVAC1", rt_offsetof(BD_IOControls_In_Vehicle, HVAC1), 185, 0, 0 },

  { "SAC2CCB", rt_offsetof(BD_IOControls_In_Vehicle, SAC2CCB), 185, 0, 0 },

  { "HVAC2", rt_offsetof(BD_IOControls_In_Vehicle, HVAC2), 185, 0, 0 },

  { "SAC1CCB", rt_offsetof(BD_IOControls_In_Vehicle, SAC1CCB), 185, 0, 0 },

  { "CMCB", rt_offsetof(BD_IOControls_In_Vehicle, CMCB), 185, 0, 0 },

  { "AC2CB", rt_offsetof(BD_IOControls_In_Vehicle, AC2CB), 185, 0, 0 },

  { "AC1CB", rt_offsetof(BD_IOControls_In_Vehicle, AC1CB), 185, 0, 0 },

  { "FDSCB", rt_offsetof(BD_IOControls_In_Vehicle, FDSCB), 185, 0, 0 },

  { "BCBCB", rt_offsetof(BD_IOControls_In_Vehicle, BCBCB), 185, 0, 0 },

  { "ERVRCB1", rt_offsetof(BD_IOControls_In_Vehicle, ERVRCB1), 185, 0, 0 },

  { "ERVRCB2", rt_offsetof(BD_IOControls_In_Vehicle, ERVRCB2), 185, 0, 0 },

  { "ESKCB", rt_offsetof(BD_IOControls_In_Vehicle, ESKCB), 185, 0, 0 },

  { "HMCB", rt_offsetof(BD_IOControls_In_Vehicle, HMCB), 185, 0, 0 },

  { "SP1CB", rt_offsetof(BD_IOControls_In_Vehicle, SP1CB), 185, 0, 0 },

  { "SP2CB", rt_offsetof(BD_IOControls_In_Vehicle, SP2CB), 185, 0, 0 },

  { "SP3CB", rt_offsetof(BD_IOControls_In_Vehicle, SP3CB), 185, 0, 0 },

  { "SP4CB", rt_offsetof(BD_IOControls_In_Vehicle, SP4CB), 185, 0, 0 },

  { "SP5CB", rt_offsetof(BD_IOControls_In_Vehicle, SP5CB), 185, 0, 0 },

  { "SPCB6", rt_offsetof(BD_IOControls_In_Vehicle, SPCB6), 185, 0, 0 },

  { "SPCB7", rt_offsetof(BD_IOControls_In_Vehicle, SPCB7), 185, 0, 0 },

  { "SPCB8", rt_offsetof(BD_IOControls_In_Vehicle, SPCB8), 185, 0, 0 },

  { "RPTCB", rt_offsetof(BD_IOControls_In_Vehicle, RPTCB), 185, 0, 0 },

  { "TERCB1", rt_offsetof(BD_IOControls_In_Vehicle, TERCB1), 185, 0, 0 },

  { "TERCB2", rt_offsetof(BD_IOControls_In_Vehicle, TERCB2), 185, 0, 0 },

  { "SPSW", rt_offsetof(BD_IOControls_In_Vehicle, SPSW), 184, 0, 0 },

  { "SPPB", rt_offsetof(BD_IOControls_In_Vehicle, SPPB), 184, 0, 0 },

  { "APSCB", rt_offsetof(BD_IOControls_In_Vehicle, APSCB), 185, 0, 0 },

  { "APSICB", rt_offsetof(BD_IOControls_In_Vehicle, APSICB), 185, 0, 0 },

  { "BCGCB", rt_offsetof(BD_IOControls_In_Vehicle, BCGCB), 185, 0, 0 },

  { "DSCB", rt_offsetof(BD_IOControls_In_Vehicle, DSCB), 185, 0, 0 },

  { "MTBMCCB", rt_offsetof(BD_IOControls_In_Vehicle, MTBMCCB), 185, 0, 0 },

  { "PADCB", rt_offsetof(BD_IOControls_In_Vehicle, PADCB), 185, 0, 0 },

  { "PANCB", rt_offsetof(BD_IOControls_In_Vehicle, PANCB), 185, 0, 0 },

  { "SSCB", rt_offsetof(BD_IOControls_In_Vehicle, SSCB), 185, 0, 0 },

  { "PTCB", rt_offsetof(BD_IOControls_In_Vehicle, PTCB), 185, 0, 0 },

  { "VCBCB", rt_offsetof(BD_IOControls_In_Vehicle, VCBCB), 185, 0, 0 },

  { "SP12CB", rt_offsetof(BD_IOControls_In_Vehicle, SP12CB), 185, 0, 0 },

  { "MTBM1CB", rt_offsetof(BD_IOControls_In_Vehicle, MTBM1CB), 185, 0, 0 },

  { "MTBM2CB", rt_offsetof(BD_IOControls_In_Vehicle, MTBM2CB), 185, 0, 0 },

  { "SP11CB", rt_offsetof(BD_IOControls_In_Vehicle, SP11CB), 185, 0, 0 },

  { "SP6CB", rt_offsetof(BD_IOControls_In_Vehicle, SP6CB), 185, 0, 0 },

  { "MTOPCB", rt_offsetof(BD_IOControls_In_Vehicle, MTOPCB), 185, 0, 0 },

  { "ORDCOS", rt_offsetof(BD_IOControls_In_Vehicle, ORDCOS), 184, 0, 0 },

  { "ADDCOS", rt_offsetof(BD_IOControls_In_Vehicle, ADDCOS), 184, 0, 0 },

  { "LeftDoor1DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor1DCUCB), 185,
    0, 0 },

  { "LeftDoor2DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor2DCUCB), 185,
    0, 0 },

  { "LeftDoor3DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor3DCUCB), 185,
    0, 0 },

  { "LeftDoor4DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor4DCUCB), 185,
    0, 0 },

  { "RightDoor1DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor1DCUCB),
    185, 0, 0 },

  { "RightDoor2DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor2DCUCB),
    185, 0, 0 },

  { "RightDoor3DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor3DCUCB),
    185, 0, 0 },

  { "RightDoor4DCUCB", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor4DCUCB),
    185, 0, 0 },

  { "LeftDoor1Coving", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor1Coving),
    184, 0, 0 },

  { "LeftDoor2Coving", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor2Coving),
    184, 0, 0 },

  { "LeftDoor3Coving", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor3Coving),
    184, 0, 0 },

  { "LeftDoor4Coving", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor4Coving),
    184, 0, 0 },

  { "RightDoor1Coving", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor1Coving),
    184, 0, 0 },

  { "RightDoor2Coving", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor2Coving),
    184, 0, 0 },

  { "RightDoor3Coving", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor3Coving),
    184, 0, 0 },

  { "RightDoor4Coving", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor4Coving),
    184, 0, 0 },

  { "LeftDoor1EED", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor1EED), 184, 0,
    0 },

  { "LeftDoor2EED", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor2EED), 184, 0,
    0 },

  { "LeftDoor3EED", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor3EED), 184, 0,
    0 },

  { "LeftDoor4EED", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor4EED), 184, 0,
    0 },

  { "RightDoor1EED", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor1EED), 184,
    0, 0 },

  { "RightDoor2EED", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor2EED), 184,
    0, 0 },

  { "RightDoor3EED", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor3EED), 184,
    0, 0 },

  { "RightDoor4EED", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor4EED), 184,
    0, 0 },

  { "LeftDoor1ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor1ManualClose), 184, 0, 0 },

  { "LeftDoor2ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor2ManualClose), 184, 0, 0 },

  { "LeftDoor3ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor3ManualClose), 184, 0, 0 },

  { "LeftDoor4ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor4ManualClose), 184, 0, 0 },

  { "RightDoor1ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor1ManualClose), 184, 0, 0 },

  { "RightDoor2ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor2ManualClose), 184, 0, 0 },

  { "RightDoor3ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor3ManualClose), 184, 0, 0 },

  { "RightDoor4ManualClose", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor4ManualClose), 184, 0, 0 },

  { "LeftDoor1ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor1ManualOpen), 184, 0, 0 },

  { "LeftDoor2ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor2ManualOpen), 184, 0, 0 },

  { "LeftDoor3ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor3ManualOpen), 184, 0, 0 },

  { "LeftDoor4ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    LeftDoor4ManualOpen), 184, 0, 0 },

  { "RightDoor1ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor1ManualOpen), 184, 0, 0 },

  { "RightDoor2ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor2ManualOpen), 184, 0, 0 },

  { "RightDoor3ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor3ManualOpen), 184, 0, 0 },

  { "RightDoor4ManualOpen", rt_offsetof(BD_IOControls_In_Vehicle,
    RightDoor4ManualOpen), 184, 0, 0 },

  { "LeftDoor1Lockout", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor1Lockout),
    184, 0, 0 },

  { "LeftDoor2Lockout", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor2Lockout),
    184, 0, 0 },

  { "LeftDoor3Lockout", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor3Lockout),
    184, 0, 0 },

  { "LeftDoor4Lockout", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoor4Lockout),
    184, 0, 0 },

  { "RightDoor1Lockout", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor1Lockout),
    184, 0, 0 },

  { "RightDoor2Lockout", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor2Lockout),
    184, 0, 0 },

  { "RightDoor3Lockout", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor3Lockout),
    184, 0, 0 },

  { "RightDoor4Lockout", rt_offsetof(BD_IOControls_In_Vehicle, RightDoor4Lockout),
    184, 0, 0 },

  { "LeftDoorEADCover", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoorEADCover),
    184, 0, 0 },

  { "RightDoorEADCover", rt_offsetof(BD_IOControls_In_Vehicle, RightDoorEADCover),
    184, 0, 0 },

  { "LeftDoorEAD", rt_offsetof(BD_IOControls_In_Vehicle, LeftDoorEAD), 184, 0, 0
  },

  { "RightDoorEAD", rt_offsetof(BD_IOControls_In_Vehicle, RightDoorEAD), 184, 0,
    0 },

  { "ParkBrakeIsolationCockBogie1", rt_offsetof(BD_IOControls_In_Vehicle,
    ParkBrakeIsolationCockBogie1), 184, 0, 0 },

  { "ParkBrakeIsolationCockBogie2", rt_offsetof(BD_IOControls_In_Vehicle,
    ParkBrakeIsolationCockBogie2), 184, 0, 0 },

  { "MRIsolationCock", rt_offsetof(BD_IOControls_In_Vehicle, MRIsolationCock),
    184, 0, 0 },

  { "UncouplingCock", rt_offsetof(BD_IOControls_In_Vehicle, UncouplingCock), 184,
    0, 0 },

  { "Horn1IsolationCock", rt_offsetof(BD_IOControls_In_Vehicle,
    Horn1IsolationCock), 184, 0, 0 },

  { "Horn2IsolationCock", rt_offsetof(BD_IOControls_In_Vehicle,
    Horn2IsolationCock), 184, 0, 0 },

  { "MREPIsolationCockEnd1", rt_offsetof(BD_IOControls_In_Vehicle,
    MREPIsolationCockEnd1), 184, 0, 0 },

  { "BIC1Inside", rt_offsetof(BD_IOControls_In_Vehicle, BIC1Inside), 184, 0, 0 },

  { "BIC1Outside", rt_offsetof(BD_IOControls_In_Vehicle, BIC1Outside), 184, 0, 0
  },

  { "BIC2Inside", rt_offsetof(BD_IOControls_In_Vehicle, BIC2Inside), 184, 0, 0 },

  { "BIC2Outside", rt_offsetof(BD_IOControls_In_Vehicle, BIC2Outside), 184, 0, 0
  },

  { "MREPIsolationCockEnd2", rt_offsetof(BD_IOControls_In_Vehicle,
    MREPIsolationCockEnd2), 184, 0, 0 },

  { "EPIC", rt_offsetof(BD_IOControls_In_Vehicle, EPIC), 184, 0, 0 },

  { "ASCOEnd1", rt_offsetof(BD_IOControls_In_Vehicle, ASCOEnd1), 184, 0, 0 },

  { "ASCOEnd2", rt_offsetof(BD_IOControls_In_Vehicle, ASCOEnd2), 184, 0, 0 },

  { "ASIsolationCock", rt_offsetof(BD_IOControls_In_Vehicle, ASIsolationCock),
    184, 0, 0 },

  { "SR", rt_offsetof(BD_IOControls_In_Vehicle, SR), 184, 0, 0 },

  { "ParkingBrakeManualReleaseBogie1Handle1", rt_offsetof
    (BD_IOControls_In_Vehicle, ParkingBrakeManualReleaseBogie1Handle1), 184, 0,
    0 },

  { "ParkingBrakeManualReleaseBogie1Handle2", rt_offsetof
    (BD_IOControls_In_Vehicle, ParkingBrakeManualReleaseBogie1Handle2), 184, 0,
    0 },

  { "ParkingBrakeManualReleaseBogie2Handle1", rt_offsetof
    (BD_IOControls_In_Vehicle, ParkingBrakeManualReleaseBogie2Handle1), 184, 0,
    0 },

  { "ParkingBrakeManualReleaseBogie2Handle2", rt_offsetof
    (BD_IOControls_In_Vehicle, ParkingBrakeManualReleaseBogie2Handle2), 184, 0,
    0 },

  { "PECUPushButton", rt_offsetof(BD_IOControls_In_Vehicle, PECUPushButton), 184,
    0, 0 },

  { "Microphone", rt_offsetof(BD_IOControls_In_Vehicle, Microphone), 184, 0, 0 },

  { "DriversBackDoor", rt_offsetof(BD_IOControls_In_Vehicle, DriversBackDoor),
    184, 0, 0 },

  { "PantographIsolationCock", rt_offsetof(BD_IOControls_In_Vehicle,
    PantographIsolationCock), 184, 0, 0 },

  { "VCBIsolationCock", rt_offsetof(BD_IOControls_In_Vehicle, VCBIsolationCock),
    184, 0, 0 },

  { "ORDPlunger", rt_offsetof(BD_IOControls_In_Vehicle, ORDPlunger), 184, 0, 0 },

  { "Position", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform,
    Position), 0, 8, 0 },

  { "OrientationDCM", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform,
    OrientationDCM), 0, 9, 0 },

  { "OrientationQ", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform,
    OrientationQ), 0, 1, 0 },

  { "H", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform, H), 0, 0, 0 },

  { "P", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform, P), 0, 0, 0 },

  { "R", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics_Transform, R), 0, 0, 0 },

  { "Transform", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics, Transform), 187,
    0, 0 },

  { "Velocity", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics, Velocity), 0, 8,
    0 },

  { "AngularVelocity", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics,
    AngularVelocity), 0, 8, 0 },

  { "Acceleration", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics, Acceleration),
    0, 8, 0 },

  { "AngularAcceleration", rt_offsetof(BD_MotionBase_In_Vehicle_Dynamics,
    AngularAcceleration), 0, 8, 0 },

  { "DegradedTrack", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Effects, DegradedTrack),
    0, 0, 0 },

  { "OnRoughTrack", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Effects, OnRoughTrack), 0,
    0, 0 },

  { "ExternalEffects", rt_offsetof(BD_MotionBase_In_Vehicle_Effects,
    ExternalEffects), 189, 0, 0 },

  { "LongitudinalJolt", rt_offsetof(BD_MotionBase_In_Vehicle_Effects,
    LongitudinalJolt), 14, 0, 0 },

  { "LateralJolt", rt_offsetof(BD_MotionBase_In_Vehicle_Effects, LateralJolt),
    14, 0, 0 },

  { "VerticalJolt", rt_offsetof(BD_MotionBase_In_Vehicle_Effects, VerticalJolt),
    14, 0, 0 },

  { "VerticalJoltDown", rt_offsetof(BD_MotionBase_In_Vehicle_Effects,
    VerticalJoltDown), 14, 0, 0 },

  { "Contact", rt_offsetof(BD_MotionBase_In_Vehicle_Environment, Contact), 0, 0,
    0 },

  { "HeadingRateLimit", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning, HeadingRateLimit),
    0, 0, 0 },

  { "PitchRateLimit", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning, PitchRateLimit),
    0, 0, 0 },

  { "RollRateLimit", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning, RollRateLimit), 0,
    0, 0 },

  { "LinearVelocitySaturation", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     LinearVelocitySaturation), 0, 0, 0 },

  { "LinearAccelerationSaturation", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     LinearAccelerationSaturation), 0, 0, 0 },

  { "LinearVelocityLPFConstant", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     LinearVelocityLPFConstant), 0, 0, 0 },

  { "LinearAccelerationLPFConstant", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     LinearAccelerationLPFConstant), 0, 0, 0 },

  { "AngularVelocitySaturation", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     AngularVelocitySaturation), 0, 0, 0 },

  { "AngularAccelerationSaturation", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     AngularAccelerationSaturation), 0, 0, 0 },

  { "AngularVelocityLPFConstant", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     AngularVelocityLPFConstant), 0, 0, 0 },

  { "AngularAccelerationLPFConstant", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     AngularAccelerationLPFConstant), 0, 0, 0 },

  { "RoughnessProfileType", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     RoughnessProfileType), 0, 0, 0 },

  { "RoughnessProfileFactor", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     RoughnessProfileFactor), 0, 0, 0 },

  { "RoughnessProfileFrequencyFactor", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     RoughnessProfileFrequencyFactor), 0, 0, 0 },

  { "RoughnessProfileSpeedFactor", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     RoughnessProfileSpeedFactor), 0, 0, 0 },

  { "RoughnessProfileSpeedSaturation", rt_offsetof
    (BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning,
     RoughnessProfileSpeedSaturation), 0, 0, 0 },

  { "Dynamics", rt_offsetof(BD_MotionBase_In_Vehicle, Dynamics), 188, 0, 0 },

  { "Effects", rt_offsetof(BD_MotionBase_In_Vehicle, Effects), 190, 0, 0 },

  { "Environment", rt_offsetof(BD_MotionBase_In_Vehicle, Environment), 191, 0, 0
  },

  { "Tuning", rt_offsetof(BD_MotionBase_In_Vehicle, Tuning), 192, 0, 0 },

  { "MotionBaseSafetyCutout", rt_offsetof(BD_MotionBase_In_Vehicle,
    MotionBaseSafetyCutout), 14, 0, 0 },

  { "Enabled", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, Enabled), 0, 0, 0 },

  { "Orientation", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, Orientation), 0, 0,
    0 },

  { "HasCab", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, HasCab), 14, 0, 0 },

  { "IsFirstVehicle", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, IsFirstVehicle),
    14, 0, 0 },

  { "IsLastVehicle", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, IsLastVehicle),
    14, 0, 0 },

  { "UnitConnection", rt_offsetof(BD_CouplingSystem_Cfg_Vehicle, UnitConnection),
    0, 0, 0 },

  { "UnitConnection", rt_offsetof(BD_SimIntegration_Out_Vehicle_Cfg_Unit,
    UnitConnection), 14, 0, 0 },

  { "UnitID", rt_offsetof(BD_SimIntegration_Out_Vehicle_Cfg_Unit, UnitID), 135,
    0, 0 },

  { "VehiclesPerUnit", rt_offsetof(BD_SimIntegration_Out_Vehicle_Cfg_Unit,
    VehiclesPerUnit), 0, 0, 0 },

  { "IsFirstVehicle", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Location,
    IsFirstVehicle), 14, 0, 0 },

  { "IsLastVehicle", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Location,
    IsLastVehicle), 14, 0, 0 },

  { "UnitConfig", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Location, UnitConfig),
    195, 0, 0 },

  { "PantoADDFaultMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoADDFaultMessage), 14, 0,
    0 },

  { "PantoORDFaultMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoORDFaultMessage), 14, 0,
    0 },

  { "PantoRaiseFailureMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoRaiseFailureMessage),
    14, 0, 0 },

  { "Messages", rt_offsetof(BD_PantographSystem_Out_Vehicle_TCMS, Messages), 197,
    0, 0 },

  { "PantographPosition", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantographPosition), 0, 0, 0 },

  { "PantoUpStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoUpStatus),
    14, 0, 0 },

  { "PantoDownStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantoDownStatus), 14, 0, 0 },

  { "PantoIsolatedStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantoIsolatedStatus), 14, 0, 0 },

  { "PantoRising", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoRising), 14,
    0, 0 },

  { "PantoLowering", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoLowering),
    14, 0, 0 },

  { "DetectedLineVoltage", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    DetectedLineVoltage), 0, 0, 0 },

  { "NoOverheadLineDetected", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    NoOverheadLineDetected), 14, 0, 0 },

  { "PantographFault", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantographFault), 14, 0, 0 },

  { "TCMS", rt_offsetof(BD_PantographSystem_Out_Vehicle, TCMS), 198, 0, 0 },

  { "AxleBrakeConfig", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_Equipment,
    AxleBrakeConfig), 0, 6, 0 },

  { "AxleParkBrakeConfig", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_Equipment,
    AxleParkBrakeConfig), 0, 6, 0 },

  { "NumberOfBrakeCylindersPerAxle", rt_offsetof
    (BD_TrainBrakes_Prm_Vehicle_Equipment, NumberOfBrakeCylindersPerAxle), 0, 0,
    0 },

  { "BrakeShoeType", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_Equipment,
    BrakeShoeType), 200, 0, 0 },

  { "BrakeCylinderPreload", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeCylinder,
    BrakeCylinderPreload), 0, 0, 0 },

  { "BrakeCylinderArea", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeCylinder,
    BrakeCylinderArea), 0, 0, 0 },

  { "BrakeBeamFactor", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeCylinder,
    BrakeBeamFactor), 0, 0, 0 },

  { "BrakeEfficiency", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeCylinder,
    BrakeEfficiency), 0, 0, 0 },

  { "DiscBrakeRatio", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeDisc,
    DiscBrakeRatio), 0, 0, 0 },

  { "DiscBrakeFrictionCoef", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeDisc,
    DiscBrakeFrictionCoef), 0, 0, 0 },

  { "BrakeTemperatures", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeFade,
    BrakeTemperatures), 0, 7, 0 },

  { "BrakeEfficiencies", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_BrakeFade,
    BrakeEfficiencies), 0, 7, 0 },

  { "BrakeInitialTemperature", rt_offsetof
    (BD_TrainBrakes_Prm_Vehicle_ThermalModel, BrakeInitialTemperature), 0, 0, 0
  },

  { "BrakeSpecificHeat", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_ThermalModel,
    BrakeSpecificHeat), 0, 0, 0 },

  { "BrakeEmissivity", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_ThermalModel,
    BrakeEmissivity), 0, 0, 0 },

  { "BrakeThermalMass", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_ThermalModel,
    BrakeThermalMass), 0, 0, 0 },

  { "ParkBrakePressures", rt_offsetof(BD_TrainBrakes_Prm_Vehicle_ParkBrakes,
    ParkBrakePressures), 0, 2, 0 },

  { "AxleParkBrakePistonForces", rt_offsetof
    (BD_TrainBrakes_Prm_Vehicle_ParkBrakes, AxleParkBrakePistonForces), 0, 2, 0
  },

  { "Equipment", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, Equipment), 201, 0, 0 },

  { "BrakeCylinder", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, BrakeCylinder), 202,
    0, 0 },

  { "BrakeDisc", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, BrakeDisc), 203, 0, 0 },

  { "BrakeFade", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, BrakeFade), 204, 0, 0 },

  { "ThermalModel", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, ThermalModel), 205,
    0, 0 },

  { "ParkBrakes", rt_offsetof(BD_TrainBrakes_Prm_Vehicle, ParkBrakes), 206, 0, 0
  },

  { "DoorOpenTime", rt_offsetof(BD_DoorSystem_Prm, DoorOpenTime), 0, 0, 0 },

  { "DoorCloseTime", rt_offsetof(BD_DoorSystem_Prm, DoorCloseTime), 0, 0, 0 },

  { "DoorOpenAlarmTime", rt_offsetof(BD_DoorSystem_Prm, DoorOpenAlarmTime), 0, 0,
    0 },

  { "DoorCloseAlarmTime", rt_offsetof(BD_DoorSystem_Prm, DoorCloseAlarmTime), 0,
    0, 0 },

  { "DoorOpenDelay", rt_offsetof(BD_DoorSystem_Prm, DoorOpenDelay), 0, 0, 0 },

  { "DoorCloseDelay", rt_offsetof(BD_DoorSystem_Prm, DoorCloseDelay), 0, 0, 0 },

  { "OverheadLineVoltage", rt_offsetof(BD_ElectricalSystem_Prm,
    OverheadLineVoltage), 0, 0, 0 },

  { "BatteryVoltage", rt_offsetof(BD_ElectricalSystem_Prm, BatteryVoltage), 0, 0,
    0 },

  { "PantoRaiseTime", rt_offsetof(BD_PantographSystem_Prm, PantoRaiseTime), 0, 0,
    0 },

  { "PantoLowerTime", rt_offsetof(BD_PantographSystem_Prm, PantoLowerTime), 0, 0,
    0 },

  { "PantoEmergencyLowerTime", rt_offsetof(BD_PantographSystem_Prm,
    PantoEmergencyLowerTime), 0, 0, 0 },

  { "LoadCompensationGains", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeControl,
    LoadCompensationGains), 0, 2, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeControl, MaxPressure),
    0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    ResetPressure), 0, 0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    MaxPressure), 0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir, Volume), 0, 0,
    0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    SwitchOFFPressure), 0, 0, 0 },

  { "CompressorMassFlowRate", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    CompressorMassFlowRate), 0, 0, 0 },

  { "BlowOffONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    BlowOffONPressure), 0, 0, 0 },

  { "BlowOffOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoir,
    BlowOffOFFPressure), 0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoirPipe,
    ResetPressure), 0, 0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoirPipe,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_MainReservoirPipe,
    SwitchOFFPressure), 0, 0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Sanding,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Sanding,
    SwitchOFFPressure), 0, 0, 0 },

  { "LoadCompensationMasses", rt_offsetof(BD_PneumaticsSystem_Prm_AirSuspension,
    LoadCompensationMasses), 0, 2, 0 },

  { "LoadCompensationPressures", rt_offsetof
    (BD_PneumaticsSystem_Prm_AirSuspension, LoadCompensationPressures), 0, 2, 0
  },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AirSuspension,
    MaxPressure), 0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_AirSuspension, Volume), 0, 0,
    0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AirSuspension,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AirSuspension,
    SwitchOFFPressure), 0, 0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Horn,
    SwitchONPressure), 0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    ResetPressure), 0, 0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    MaxPressure), 0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir, Volume), 0,
    0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    SwitchOFFPressure), 0, 0, 0 },

  { "CompressorMassFlowRate", rt_offsetof
    (BD_PneumaticsSystem_Prm_AuxiliaryReservoir, CompressorMassFlowRate), 0, 0,
    0 },

  { "BlowOffONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    BlowOffONPressure), 0, 0, 0 },

  { "BlowOffOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_AuxiliaryReservoir,
    BlowOffOFFPressure), 0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph,
    ResetPressure), 0, 0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph, MaxPressure),
    0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph, Volume), 0, 0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph,
    SwitchOFFPressure), 0, 0, 0 },

  { "ORDSwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph,
    ORDSwitchONPressure), 0, 0, 0 },

  { "ORDSwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_Pantograph,
    ORDSwitchOFFPressure), 0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeReservoir,
    ResetPressure), 0, 0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeReservoir,
    MaxPressure), 0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeReservoir, Volume), 0, 0,
    0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeReservoir,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeReservoir,
    SwitchOFFPressure), 0, 0, 0 },

  { "BrakeCylindersPerBogieAxle", rt_offsetof
    (BD_PneumaticsSystem_Prm_BrakeCylinder, BrakeCylindersPerBogieAxle), 0, 2, 0
  },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeCylinder,
    ResetPressure), 0, 0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeCylinder,
    MaxPressure), 0, 0, 0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeCylinder, Volume), 0, 0,
    0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeCylinder,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_BrakeCylinder,
    SwitchOFFPressure), 0, 0, 0 },

  { "ParkBrakesPerBogieAxle", rt_offsetof(BD_PneumaticsSystem_Prm_ParkBrakes,
    ParkBrakesPerBogieAxle), 0, 2, 0 },

  { "ParkBrakePressures", rt_offsetof(BD_PneumaticsSystem_Prm_ParkBrakes,
    ParkBrakePressures), 0, 2, 0 },

  { "ParkBrakeForces", rt_offsetof(BD_PneumaticsSystem_Prm_ParkBrakes,
    ParkBrakeForces), 0, 2, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_ParkBrakes,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_ParkBrakes,
    SwitchOFFPressure), 0, 0, 0 },

  { "ResetPressure", rt_offsetof(BD_PneumaticsSystem_Prm_VCB, ResetPressure), 0,
    0, 0 },

  { "MaxPressure", rt_offsetof(BD_PneumaticsSystem_Prm_VCB, MaxPressure), 0, 0,
    0 },

  { "Volume", rt_offsetof(BD_PneumaticsSystem_Prm_VCB, Volume), 0, 0, 0 },

  { "SwitchONPressure", rt_offsetof(BD_PneumaticsSystem_Prm_VCB,
    SwitchONPressure), 0, 0, 0 },

  { "SwitchOFFPressure", rt_offsetof(BD_PneumaticsSystem_Prm_VCB,
    SwitchOFFPressure), 0, 0, 0 },

  { "BrakeControl", rt_offsetof(BD_PneumaticsSystem_Prm, BrakeControl), 211, 0,
    0 },

  { "MainReservoir", rt_offsetof(BD_PneumaticsSystem_Prm, MainReservoir), 212, 0,
    0 },

  { "MainReservoirPipe", rt_offsetof(BD_PneumaticsSystem_Prm, MainReservoirPipe),
    213, 0, 0 },

  { "Sanding", rt_offsetof(BD_PneumaticsSystem_Prm, Sanding), 214, 0, 0 },

  { "AirSuspension", rt_offsetof(BD_PneumaticsSystem_Prm, AirSuspension), 215, 0,
    0 },

  { "Horn", rt_offsetof(BD_PneumaticsSystem_Prm, Horn), 216, 0, 0 },

  { "AuxiliaryReservoir", rt_offsetof(BD_PneumaticsSystem_Prm,
    AuxiliaryReservoir), 217, 0, 0 },

  { "Pantograph", rt_offsetof(BD_PneumaticsSystem_Prm, Pantograph), 218, 0, 0 },

  { "BrakeReservoir", rt_offsetof(BD_PneumaticsSystem_Prm, BrakeReservoir), 219,
    0, 0 },

  { "BrakeCylinder", rt_offsetof(BD_PneumaticsSystem_Prm, BrakeCylinder), 220, 0,
    0 },

  { "ParkBrakes", rt_offsetof(BD_PneumaticsSystem_Prm, ParkBrakes), 221, 0, 0 },

  { "VCB", rt_offsetof(BD_PneumaticsSystem_Prm, VCB), 222, 0, 0 },

  { "LoadCompensationMasses", rt_offsetof(BD_TCMSSystem_Prm,
    LoadCompensationMasses), 0, 2, 0 },

  { "LoadCompensationPressures", rt_offsetof(BD_TCMSSystem_Prm,
    LoadCompensationPressures), 0, 2, 0 },

  { "TractionAccelerationTargets", rt_offsetof(BD_TCMSSystem_Prm,
    TractionAccelerationTargets), 0, 2, 0 },

  { "BrakingDecelerationTargets", rt_offsetof(BD_TCMSSystem_Prm,
    BrakingDecelerationTargets), 0, 2, 0 },

  { "TractionBrakingDemands", rt_offsetof(BD_TCMSSystem_Prm,
    TractionBrakingDemands), 0, 2, 0 },

  { "AW3TractionAccelerationTargets", rt_offsetof(BD_TCMSSystem_Prm,
    AW3TractionAccelerationTargets), 0, 2, 0 },

  { "AW3BrakingDecelerationTargets", rt_offsetof(BD_TCMSSystem_Prm,
    AW3BrakingDecelerationTargets), 0, 2, 0 },

  { "DesignMaxTractionTorque", rt_offsetof(BD_TractionSystem_Prm,
    DesignMaxTractionTorque), 0, 0, 0 },

  { "DesignMaxTractionPower", rt_offsetof(BD_TractionSystem_Prm,
    DesignMaxTractionPower), 0, 0, 0 },

  { "DesignTimeToMaxTraction", rt_offsetof(BD_TractionSystem_Prm,
    DesignTimeToMaxTraction), 0, 0, 0 },

  { "DesignMaxBrakingTorque", rt_offsetof(BD_TractionSystem_Prm,
    DesignMaxBrakingTorque), 0, 0, 0 },

  { "DesignMaxBrakingPower", rt_offsetof(BD_TractionSystem_Prm,
    DesignMaxBrakingPower), 0, 0, 0 },

  { "BrakeFadeRampDownSpeeds", rt_offsetof(BD_TractionSystem_Prm,
    BrakeFadeRampDownSpeeds), 0, 2, 0 },

  { "DesignGearingRatio", rt_offsetof(BD_TractionSystem_Prm, DesignGearingRatio),
    0, 0, 0 },

  { "DesignGearingEfficiency", rt_offsetof(BD_TractionSystem_Prm,
    DesignGearingEfficiency), 0, 0, 0 },

  { "DesignWheelDiameter", rt_offsetof(BD_TractionSystem_Prm,
    DesignWheelDiameter), 0, 0, 0 },

  { "DesignBogieMotorCount", rt_offsetof(BD_TractionSystem_Prm,
    DesignBogieMotorCount), 0, 0, 0 },

  { "AxleHasMotor", rt_offsetof(BD_TractionSystem_Prm, AxleHasMotor), 0, 2, 0 },

  { "EmergencyBrakeDeactivatesDynamicBrake", rt_offsetof(BD_TractionSystem_Prm,
    EmergencyBrakeDeactivatesDynamicBrake), 0, 0, 0 },

  { "WheelSlipProtectionEnable", rt_offsetof(BD_TractionSystem_Prm,
    WheelSlipProtectionEnable), 0, 0, 0 },

  { "WheelSlideProtectionEnable", rt_offsetof(BD_TractionSystem_Prm,
    WheelSlideProtectionEnable), 0, 0, 0 },

  { "JerkLimit", rt_offsetof(BD_TractionSystem_Prm, JerkLimit), 0, 0, 0 },

  { "MaxContinuousSlipBeforeTractionCutout", rt_offsetof(BD_TractionSystem_Prm,
    MaxContinuousSlipBeforeTractionCutout), 0, 0, 0 },

  { "MaxContinuousSlideBeforeBrakeCutout", rt_offsetof(BD_TractionSystem_Prm,
    MaxContinuousSlideBeforeBrakeCutout), 0, 0, 0 },

  { "HasCab", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment, HasCab), 14,
    0, 0 },

  { "HasBogie", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment, HasBogie),
    14, 0, 0 },

  { "HasMotors", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment, HasMotors),
    14, 0, 0 },

  { "HasPneumaticPanto", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasPneumaticPanto), 14, 0, 0 },

  { "HasElectricPanto", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasElectricPanto), 14, 0, 0 },

  { "HasMainCompressor", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasMainCompressor), 14, 0, 0 },

  { "HasMainReservoir", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasMainReservoir), 14, 0, 0 },

  { "HasPantoReservoir", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasPantoReservoir), 14, 0, 0 },

  { "HasBrakeSystem", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    HasBrakeSystem), 14, 0, 0 },

  { "NumberOfDoors", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    NumberOfDoors), 14, 0, 0 },

  { "NumberOfTractionBogies", rt_offsetof
    (BD_SimIntegration_Cfg_Vehicle_Equipment, NumberOfTractionBogies), 0, 0, 0 },

  { "NumberOfBrakingBogies", rt_offsetof(BD_SimIntegration_Cfg_Vehicle_Equipment,
    NumberOfBrakingBogies), 0, 0, 0 },

  { "Common", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Common), 114, 0, 0 },

  { "Location", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Location), 196, 0, 0
  },

  { "Equipment", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Equipment), 226, 0,
    0 },

  { "Dynamics", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Dynamics), 129, 0, 0
  },

  { "Brakes", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Brakes), 116, 0, 0 },

  { "Pneumatics", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Pneumatics), 150, 0,
    0 },

  { "Traction", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Traction), 174, 0, 0
  },

  { "Pantograph", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Pantograph), 148, 0,
    0 },

  { "Doors", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Doors), 120, 0, 0 },

  { "Electrical", rt_offsetof(BD_SimIntegration_Cfg_Vehicle, Electrical), 136, 0,
    0 },

  { "VigilanceAlarm", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    VigilanceAlarm), 0, 0, 0 },

  { "HornHigh", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, HornHigh), 0, 0,
    0 },

  { "HornLow", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, HornLow), 0, 0,
    0 },

  { "Bell", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, Bell), 0, 0, 0 },

  { "SaloonDoorOpeningBuzzer", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    SaloonDoorOpeningBuzzer), 0, 0, 0 },

  { "SaloonDoorClosingBuzzer", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    SaloonDoorClosingBuzzer), 0, 0, 0 },

  { "DoorWarningBuzzer", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    DoorWarningBuzzer), 0, 0, 0 },

  { "EEDEADOperated", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    EEDEADOperated), 0, 0, 0 },

  { "VCBOpenSound", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    VCBOpenSound), 0, 0, 0 },

  { "VCBCloseSound", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    VCBCloseSound), 0, 0, 0 },

  { "CompressorStartAndRunSound", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_Audio, CompressorStartAndRunSound), 0, 0, 0 },

  { "FlasherLightOperationSound", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_Audio, FlasherLightOperationSound), 0, 0, 0 },

  { "DeadmanAlarm", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    DeadmanAlarm), 0, 0, 0 },

  { "PantographLowering", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    PantographLowering), 0, 0, 0 },

  { "WheelSlip", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, WheelSlip), 0,
    0, 0 },

  { "WheelSlide", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, WheelSlide),
    0, 0, 0 },

  { "AirBrakeRelease", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    AirBrakeRelease), 0, 0, 0 },

  { "PantographRaising", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    PantographRaising), 0, 0, 0 },

  { "WiperSound", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, WiperSound),
    0, 0, 0 },

  { "EmergencyBrakeApplicationSound", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_Audio, EmergencyBrakeApplicationSound), 0, 0,
    0 },

  { "BPVentAudio", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, BPVentAudio),
    0, 0, 0 },

  { "CollisionDetectionCoupling", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_Audio, CollisionDetectionCoupling), 0, 0, 0 },

  { "Derailment", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio, Derailment),
    0, 0, 0 },

  { "MechanicalUncouple", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    MechanicalUncouple), 0, 0, 0 },

  { "PneumaticPressureRelease", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    PneumaticPressureRelease), 0, 0, 0 },

  { "ObstacleSoftCollision", rt_offsetof(BD_SimIntegration_Out_Vehicle_Audio,
    ObstacleSoftCollision), 0, 0, 0 },

  { "TotalEnergyConsumption", rt_offsetof(BD_SimIntegration_Out_Train_Scoring,
    TotalEnergyConsumption), 0, 0, 0 },

  { "VigilanceIntervention", rt_offsetof(BD_SimIntegration_Out_Vehicle_Scoring,
    VigilanceIntervention), 0, 0, 0 },

  { "HornActivation", rt_offsetof(BD_SimIntegration_Out_Vehicle_Scoring,
    HornActivation), 0, 0, 0 },

  { "PowerSupply", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, PowerSupply), 0, 0,
    0 },

  { "CabinActivation", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, CabinActivation),
    0, 0, 0 },

  { "DriverModeSelection", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    DriverModeSelection), 0, 0, 0 },

  { "ModeSelectorPosition", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    ModeSelectorPosition), 0, 0, 0 },

  { "ATCBypassState", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, ATCBypassState),
    0, 0, 0 },

  { "TBCPosition", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, TBCPosition), 0, 0,
    0 },

  { "ATOStartButton", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, ATOStartButton),
    0, 0, 0 },

  { "UTOStartButton", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, UTOStartButton),
    0, 0, 0 },

  { "ATCSBResetButton", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    ATCSBResetButton), 0, 0, 0 },

  { "NoEmergencyBrake", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    NoEmergencyBrake), 0, 0, 0 },

  { "NoDoorEnableBypass", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    NoDoorEnableBypass), 0, 0, 0 },

  { "TrainDoorClosedAndLocked", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    TrainDoorClosedAndLocked), 0, 0, 0 },

  { "EmergencyDoorNotOpen", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    EmergencyDoorNotOpen), 0, 0, 0 },

  { "WakeUpStatus", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, WakeUpStatus), 0, 0,
    0 },

  { "PassengerEmergencyAlarm", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    PassengerEmergencyAlarm), 0, 0, 0 },

  { "FireSmokeInd", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, FireSmokeInd), 0, 0,
    0 },

  { "MechanicalCoupling", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    MechanicalCoupling), 0, 0, 0 },

  { "ROSPB", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, ROSPB), 0, 0, 0 },

  { "UTBPB", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, UTBPB), 0, 0, 0 },

  { "TrainIntegrity", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, TrainIntegrity),
    0, 0, 0 },

  { "TCMSSpeedLimit", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard, TCMSSpeedLimit),
    0, 0, 0 },

  { "TCMSSpeedLimitCause", rt_offsetof(BD_CBTC_Out_Vehicle_Onboard,
    TCMSSpeedLimitCause), 0, 0, 0 },

  { "LeftSideDoorOpenRequest", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    LeftSideDoorOpenRequest), 0, 0, 0 },

  { "RightSideDoorOpenRequest", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    RightSideDoorOpenRequest), 0, 0, 0 },

  { "LeftSideDoorCloseRequest", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    LeftSideDoorCloseRequest), 0, 0, 0 },

  { "RightSideDoorCloseRequest", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    RightSideDoorCloseRequest), 0, 0, 0 },

  { "Door1Inhibited", rt_offsetof(BD_CBTC_Out_Vehicle_Platform, Door1Inhibited),
    0, 0, 0 },

  { "Door2Inhibited", rt_offsetof(BD_CBTC_Out_Vehicle_Platform, Door2Inhibited),
    0, 0, 0 },

  { "Door3Inhibited", rt_offsetof(BD_CBTC_Out_Vehicle_Platform, Door3Inhibited),
    0, 0, 0 },

  { "Door4Inhibited", rt_offsetof(BD_CBTC_Out_Vehicle_Platform, Door4Inhibited),
    0, 0, 0 },

  { "LeftSideDoorEnable", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    LeftSideDoorEnable), 0, 0, 0 },

  { "RightSideDoorEnable", rt_offsetof(BD_CBTC_Out_Vehicle_Platform,
    RightSideDoorEnable), 0, 0, 0 },

  { "ATOTraction", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, ATOTraction), 14,
    0, 0 },

  { "ATONotBrake", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, ATONotBrake), 14,
    0, 0 },

  { "ATOTBDemand", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, ATOTBDemand), 0,
    0, 0 },

  { "NoEmergencyBrakeOrder", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    NoEmergencyBrakeOrder), 14, 0, 0 },

  { "ROSIndication", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, ROSIndication),
    14, 0, 0 },

  { "ATOStartIndication", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    ATOStartIndication), 14, 0, 0 },

  { "ATCSBResetIndication", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    ATCSBResetIndication), 14, 0, 0 },

  { "LeftHoldDoorClose", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    LeftHoldDoorClose), 14, 0, 0 },

  { "RightHoldDoorClose", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    RightHoldDoorClose), 14, 0, 0 },

  { "ATCZeroSpeed", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, ATCZeroSpeed),
    14, 0, 0 },

  { "WakeUpCommand", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, WakeUpCommand),
    0, 0, 0 },

  { "UTOPBIndicator", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, UTOPBIndicator),
    0, 0, 0 },

  { "UTOModeActive", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, UTOModeActive),
    0, 0, 0 },

  { "ATCCabActivation", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    ATCCabActivation), 0, 0, 0 },

  { "NotImmobilise", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical, NotImmobilise),
    0, 0, 0 },

  { "TractionForward", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    TractionForward), 0, 0, 0 },

  { "EmergencyDetrainmentDoorLocked", rt_offsetof(BD_CBTC_Out_Vehicle_Electrical,
    EmergencyDetrainmentDoorLocked), 0, 0, 0 },

  { "ATOTraction", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, ATOTraction), 14, 0, 0
  },

  { "ATOBrake", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, ATOBrake), 14, 0, 0 },

  { "ATOTBDemand", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, ATOTBDemand), 0, 0, 0 },

  { "NoServiceBrake", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, NoServiceBrake), 14,
    0, 0 },

  { "NotImmobilise", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, NotImmobilise), 14, 0,
    0 },

  { "ATOState", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, ATOState), 0, 0, 0 },

  { "RollbackDetected", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS, RollbackDetected),
    0, 0, 0 },

  { "LeftDoorCloseIndicator", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    LeftDoorCloseIndicator), 0, 0, 0 },

  { "RightDoorCloseIndicator", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    RightDoorCloseIndicator), 0, 0, 0 },

  { "LeftDoorOpenATCReq", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    LeftDoorOpenATCReq), 0, 0, 0 },

  { "RightDoorOpenATCReq", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    RightDoorOpenATCReq), 0, 0, 0 },

  { "LeftDoorCloseATCReq", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    LeftDoorCloseATCReq), 0, 0, 0 },

  { "RightDoorCloseATCReq", rt_offsetof(BD_CBTC_Out_Vehicle_TCMS,
    RightDoorCloseATCReq), 0, 0, 0 },

  { "PowerOn", rt_offsetof(BD_CBTC_Out_Vehicle_DMI, PowerOn), 0, 0, 0 },

  { "CabActive", rt_offsetof(BD_CBTC_Out_Vehicle_DMI, CabActive), 0, 0, 0 },

  { "NeutralSection", rt_offsetof(BD_CBTC_Out_Vehicle_DMI, NeutralSection), 0, 0,
    0 },

  { "OnBoard", rt_offsetof(BD_CBTC_Out_Vehicle, OnBoard), 231, 0, 0 },

  { "Platform", rt_offsetof(BD_CBTC_Out_Vehicle, Platform), 232, 0, 0 },

  { "Electrical", rt_offsetof(BD_CBTC_Out_Vehicle, Electrical), 233, 0, 0 },

  { "TCMS", rt_offsetof(BD_CBTC_Out_Vehicle, TCMS), 234, 0, 0 },

  { "DMI", rt_offsetof(BD_CBTC_Out_Vehicle, DMI), 235, 0, 0 },

  { "PantoUpCommand", rt_offsetof(BD_PantographSystem_In_Vehicle_Control,
    PantoUpCommand), 14, 0, 0 },

  { "PantoDownCommand", rt_offsetof(BD_PantographSystem_In_Vehicle_Control,
    PantoDownCommand), 14, 0, 0 },

  { "PantoEmergencyDownCommand", rt_offsetof
    (BD_PantographSystem_In_Vehicle_Control, PantoEmergencyDownCommand), 14, 0,
    0 },

  { "PantoIsolationCommand", rt_offsetof(BD_PantographSystem_In_Vehicle_Control,
    PantoIsolationCommand), 14, 0, 0 },

  { "PantoControlPower", rt_offsetof(BD_PantographSystem_In_Vehicle_Electrical,
    PantoControlPower), 14, 0, 0 },

  { "PantoMotorPower", rt_offsetof(BD_PantographSystem_In_Vehicle_Electrical,
    PantoMotorPower), 14, 0, 0 },

  { "PantoADDFault", rt_offsetof(BD_PantographSystem_In_Vehicle_Electrical,
    PantoADDFault), 14, 0, 0 },

  { "PantoORDFault", rt_offsetof(BD_PantographSystem_In_Vehicle_Electrical,
    PantoORDFault), 14, 0, 0 },

  { "PantoRaiseFailure", rt_offsetof(BD_PantographSystem_In_Vehicle_Electrical,
    PantoRaiseFailure), 14, 0, 0 },

  { "PantoLoweringFailure", rt_offsetof
    (BD_PantographSystem_In_Vehicle_Electrical, PantoLoweringFailure), 14, 0, 0
  },

  { "PantoPneumaticSupply", rt_offsetof
    (BD_PantographSystem_In_Vehicle_Pneumatics, PantoPneumaticSupply), 14, 0, 0
  },

  { "LineVoltage", rt_offsetof(BD_PantographSystem_In_Vehicle_Environment,
    LineVoltage), 0, 0, 0 },

  { "OverheadLinePresent", rt_offsetof
    (BD_PantographSystem_In_Vehicle_Environment, OverheadLinePresent), 0, 0, 0 },

  { "NeutralSection", rt_offsetof(BD_PantographSystem_In_Vehicle_Environment,
    NeutralSection), 0, 0, 0 },

  { "Control", rt_offsetof(BD_PantographSystem_In_Vehicle, Control), 237, 0, 0 },

  { "Electrical", rt_offsetof(BD_PantographSystem_In_Vehicle, Electrical), 238,
    0, 0 },

  { "Pneumatics", rt_offsetof(BD_PantographSystem_In_Vehicle, Pneumatics), 239,
    0, 0 },

  { "Environment", rt_offsetof(BD_PantographSystem_In_Vehicle, Environment), 240,
    0, 0 },

  { "PlaceHolder", rt_offsetof(BD_TCMSSystem_In_Vehicle_Overrides, PlaceHolder),
    14, 0, 0 },

  { "ATOBrake", rt_offsetof(struct_iOPQUPViMP7klj2KCOPonE, ATOBrake), 14, 10, 0
  },

  { "ATOTraction", rt_offsetof(struct_iOPQUPViMP7klj2KCOPonE, ATOTraction), 14,
    10, 0 },

  { "ATOTBDemand", rt_offsetof(struct_iOPQUPViMP7klj2KCOPonE, ATOTBDemand), 0,
    10, 0 },

  { "AutoPowerOn", rt_offsetof(BD_ElectricalSystem_In_Overrides, AutoPowerOn), 0,
    0, 0 },

  { "PantoUPOverride", rt_offsetof(BD_PantographSystem_In_Vehicle_Overrides,
    PantoUPOverride), 14, 0, 0 },

  { "ApplyMotion", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, ApplyMotion), 0, 0, 0 },

  { "ManualPosition", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, ManualPosition), 0, 8,
    0 },

  { "LinearVelocity", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, LinearVelocity), 0, 8,
    0 },

  { "LinearAcceleration", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, LinearAcceleration), 0,
    8, 0 },

  { "ManualOrientation", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, ManualOrientation), 0,
    8, 0 },

  { "AngularVelocity", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, AngularVelocity), 0, 8,
    0 },

  { "AngularAcceleration", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, AngularAcceleration), 0,
    8, 0 },

  { "GravitationalAcceleration", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController,
     GravitationalAcceleration), 0, 8, 0 },

  { "OrientationDCM", rt_offsetof
    (BD_SimIntegration_Out_Vehicle_MotionBaseController, OrientationDCM), 0, 9,
    0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 },

  { rtwCAPI_VECTOR, 22, 2, 0 },

  { rtwCAPI_VECTOR, 24, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  4,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  8,                                   /* 6 */
  1,                                   /* 7 */
  7,                                   /* 8 */
  1,                                   /* 9 */
  16,                                  /* 10 */
  1,                                   /* 11 */
  6,                                   /* 12 */
  1,                                   /* 13 */
  10,                                  /* 14 */
  1,                                   /* 15 */
  3,                                   /* 16 */
  1,                                   /* 17 */
  3,                                   /* 18 */
  3,                                   /* 19 */
  1,                                   /* 20 */
  2,                                   /* 21 */
  1,                                   /* 22 */
  3,                                   /* 23 */
  1,                                   /* 24 */
  6                                    /* 25 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.05, 0.01, 0.5
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 0, 0 },

  { static_cast<const void *>(&rtcapiStoredFloats[2]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 2, 0 },

  { static_cast<const void *>(&rtcapiStoredFloats[3]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 1, 0 },

  { static_cast<const void *>(&rtcapiStoredFloats[4]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 4, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 285,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 1262,
    rtModelParameters, 0 },

  { rtBlockStates, 2 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 4277785387U,
    1502451535U,
    3284454416U,
    2629641008U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  BEML_EMU_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void BEML_EMU_InitializeDataMapInfo(RT_MODEL_BEML_EMU_T *const BEML_EMU_M,
  B_BEML_EMU_T *BEML_EMU_B, P_BEML_EMU_T *BEML_EMU_P, DW_BEML_EMU_T *BEML_EMU_DW,
  self_CoreSubsys_BEML_EMU_gj_T self_CoreSubsys_pnaevvfpgh5z[8],
  self_CoreSubsys_BEML_EMU_o_T self_CoreSubsys_pnaevvfpgh5[8],
  self_CoreSubsys_BEML_EMU_jb2bnsaujtd5u_T self_CoreSubsys_pnaevvfpg[8],
  self_CoreSubsys_BEML_EMU_jb2bnsau_T self_CoreSubsys_pnaevvf[8],
  self_CoreSubsys_BEML_EMU_jb2bn_T self_CoreSubsys_pnae[8],
  self_CoreSubsys_BEML_EMU_jb2_T self_CoreSubsys_pna[8],
  self_CoreSubsys_BEML_EMU_j_T self_CoreSubsys_p[8])
{
  /* Set C-API version */
  rtwCAPI_SetVersion(BEML_EMU_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(BEML_EMU_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(BEML_EMU_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  BEML_EMU_InitializeDataAddr(BEML_EMU_M, BEML_EMU_M->DataMapInfo.dataAddress,
    BEML_EMU_B, BEML_EMU_P, BEML_EMU_DW, self_CoreSubsys_pnaevvfpgh5z,
    self_CoreSubsys_pnaevvfpgh5, self_CoreSubsys_pnaevvfpg,
    self_CoreSubsys_pnaevvf, self_CoreSubsys_pnae, self_CoreSubsys_pna,
    self_CoreSubsys_p);
  rtwCAPI_SetDataAddressMap(BEML_EMU_M->DataMapInfo.mmi,
    BEML_EMU_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  BEML_EMU_InitializeVarDimsAddr(BEML_EMU_M,
    BEML_EMU_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(BEML_EMU_M->DataMapInfo.mmi,
    BEML_EMU_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(BEML_EMU_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(BEML_EMU_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  BEML_EMU_InitializeLoggingFunctions(BEML_EMU_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(BEML_EMU_M->DataMapInfo.mmi,
    BEML_EMU_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(BEML_EMU_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(BEML_EMU_M->DataMapInfo.mmi,
    BEML_EMU_M->DataMapInfo.childMMI);
  rtwCAPI_SetChildMMIArrayLen(BEML_EMU_M->DataMapInfo.mmi, 10);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void BEML_EMU_host_InitializeDataMapInfo(BEML_EMU_host_DataMapInfo_T *dataMap,
    const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    dataMap->childMMI[0] = &(dataMap->child0.mmi);
    TrainBrakes_host_InitializeDataMapInfo(&(dataMap->child0),
      "BEML_EMU/BEML_EMU/BrakesInterface/TrainBrakes");
    dataMap->childMMI[1] = &(dataMap->child1.mmi);
    CouplingSystem_host_InitializeDataMapInfo(&(dataMap->child1),
      "BEML_EMU/BEML_EMU/CouplingInterface/Model");
    dataMap->childMMI[2] = &(dataMap->child2.mmi);
    DoorSystem_host_InitializeDataMapInfo(&(dataMap->child2),
      "BEML_EMU/BEML_EMU/DoorsInterface/DoorsSystem");
    dataMap->childMMI[3] = &(dataMap->child3.mmi);
    TrainDynamics_host_InitializeDataMapInfo(&(dataMap->child3),
      "BEML_EMU/BEML_EMU/DynamicsInterface/TrainDynamics");
    dataMap->childMMI[4] = &(dataMap->child4.mmi);
    ElectricalSystem_host_InitializeDataMapInfo(&(dataMap->child4),
      "BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalSystem");
    dataMap->childMMI[5] = &(dataMap->child5.mmi);
    PantographSystem_host_InitializeDataMapInfo(&(dataMap->child5),
      "BEML_EMU/BEML_EMU/PantographInterface/PantographSystem");
    dataMap->childMMI[6] = &(dataMap->child6.mmi);
    PneumaticsSystem_host_InitializeDataMapInfo(&(dataMap->child6),
      "BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsSystem");
    dataMap->childMMI[7] = &(dataMap->child7.mmi);
    TCMSSystem_host_InitializeDataMapInfo(&(dataMap->child7),
      "BEML_EMU/BEML_EMU/TCMSInterface/TCMSSystem");
    dataMap->childMMI[8] = &(dataMap->child8.mmi);
    TractionSystem_host_InitializeDataMapInfo(&(dataMap->child8),
      "BEML_EMU/BEML_EMU/TractionInterface/TractionSystem");
    dataMap->childMMI[9] = &(dataMap->child9.mmi);
    IOControls_host_InitializeDataMapInfo(&(dataMap->child9),
      "BEML_EMU/InputsInterface/IOControlsInterface/IOControlsModel");
    rtwCAPI_SetChildMMIArray(dataMap->mmi, dataMap->childMMI);
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 10);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: BEML_EMU_capi.cpp */
