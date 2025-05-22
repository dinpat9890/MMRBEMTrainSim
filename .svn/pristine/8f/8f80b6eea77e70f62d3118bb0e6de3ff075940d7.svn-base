/*
 * CouplingSystem_capi.cpp
 *
 * Code generation for model "CouplingSystem".
 *
 * Model version              : 1.2185
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
#include "CouplingSystem_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "CouplingSystem.h"
#include "CouplingSystem_capi.h"
#include "CouplingSystem_private.h"
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
  { 0, 33, TARGET_STRING("CouplingSystem/NOT"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 24, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem"),
    TARGET_STRING(""), 0, 10, 1, 0, 0 },

  { 2, 28, TARGET_STRING(
    "CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/Subsystem"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 3, 32, TARGET_STRING(
    "CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/VehicleCouplingSystem"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 33, TARGET_STRING(
    "CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/VehicleCouplingSystem"),
    TARGET_STRING(""), 1, 0, 3, 0, 0 },

  { 5, 33, TARGET_STRING(
    "CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/Vector Concatenate2"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 6, 33, TARGET_STRING(
    "CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/SelectVehicleUp1/Vector Concatenate2"),
    TARGET_STRING(""), 0, 0, 5, 0, 0 },

  { 7, 24, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/OutputsPacking/Bus Assignment"),
    TARGET_STRING(""), 0, 10, 1, 0, 0 },

  { 8, 14, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 9, 17, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 10, 24, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers/Override if DMS"),
    TARGET_STRING(""), 0, 1, 6, 0, 0 },

  { 11, 24, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1/Override if DMS"),
    TARGET_STRING(""), 0, 1, 6, 0, 0 },

  { 12, 24, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2/Override if DMS"),
    TARGET_STRING(""), 0, 1, 6, 0, 0 },

  { 13, 24, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4/Override if DMS"),
    TARGET_STRING(""), 0, 1, 6, 0, 0 },

  { 14, 14, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 15, 17, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 16, 14, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 17, 17, TARGET_STRING(
    "CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 18, TARGET_STRING("CouplingSystem/Step"),
    TARGET_STRING("Time"), 1, 1, 0 },

  { 19, TARGET_STRING("CouplingSystem/Step"),
    TARGET_STRING("Before"), 1, 1, 0 },

  { 20, TARGET_STRING("CouplingSystem/Step"),
    TARGET_STRING("After"), 1, 1, 0 },

  { 21, TARGET_STRING("CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/ForUnitConnection"),
    TARGET_STRING("Value"), 0, 1, 0 },

  { 22, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplerSystemOut"),
    TARGET_STRING("InitialOutput"), 10, 1, 0 },

  { 23, TARGET_STRING("CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/SelectVehicleUp1/ForTrainConnection"),
    TARGET_STRING("Value"), 0, 1, 0 },

  { 24, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Unit Delay"),
    TARGET_STRING("InitialCondition"), 4, 1, 0 },

  { 25, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/OutputsPacking/Constant"),
    TARGET_STRING("Value"), 10, 1, 0 },

  { 26, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant1"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 27, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant11"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 28, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant12"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 29, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant2"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 30, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant3"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 31, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant4"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 32, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant5"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 33, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant6"),
    TARGET_STRING("Value"), 1, 7, 0 },

  { 34, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Constant7"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 35, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/Temporary_ReadyToCouple"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 36, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/Switch1"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 37, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/Switch2"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 38, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling"),
    TARGET_STRING("UpperSaturationLimit"), 1, 1, 0 },

  { 39, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/Constant"),
    TARGET_STRING("Value"), 3, 1, 0 },

  { 40, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/Constant1"),
    TARGET_STRING("Value"), 2, 1, 0 },

  { 41, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/OutputsPacking/Subsystem/Constant1"),
    TARGET_STRING("Value"), 9, 1, 0 },

  { 42, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 43, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 44, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 45, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 46, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 47, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 48, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 49, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 50, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 51, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers3/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 52, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers3/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 53, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers3/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 54, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 55, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 56, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 57, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers5/Compare To Constant"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 58, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers5/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 59, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers5/Constant1"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 60, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/SR Latch - Set Priority1"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 61, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/SR Latch - Set Priority2"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 62, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 63, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/Saturation"),
    TARGET_STRING("UpperLimit"), 1, 1, 0 },

  { 64, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/Saturation"),
    TARGET_STRING("LowerLimit"), 1, 1, 0 },

  { 65, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/Detect Increase"),
    TARGET_STRING("vinit"), 1, 1, 0 },

  { 66, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/MaskInitalisation/Switch3"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 67, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/MaskInitalisation1/Switch3"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 68, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/Detect Decrease"),
    TARGET_STRING("vinit"), 1, 1, 0 },

  { 69, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled/Head"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 70, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled/Switch2"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 71, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Close Range"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 72, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/CoupledState"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 73, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Detect Decrease"),
    TARGET_STRING("vinit"), 1, 1, 0 },

  { 74, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/MaxAutoCouplingSpeed"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 75, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/MinAutoCouplingSpeed"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 76, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Switch"),
    TARGET_STRING("Threshold"), 1, 1, 0 },

  { 77, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling/Timer"),
    TARGET_STRING("gainval"), 1, 1, 0 },

  { 78, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling/Timer"),
    TARGET_STRING("InitialCondition"), 1, 1, 0 },

  { 79, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 1, 1, 0 },

  { 80, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 81, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 82, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 1, 1, 0 },

  { 83, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 1, 1, 0 },

  { 84, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 1, 1, 0 },

  { 85, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 1, 1, 0 },

  { 86, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 87, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 88, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 89, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 1, 1, 0 },

  { 90, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 1, 1, 0 },

  { 91, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 1, 1, 0 },

  { 92, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 1, 1, 0 },

  { 93, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 94, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled/NotInterfacing/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 95, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/AutocoupleEvent/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 96, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/AutocoupleEvent/ApproachSpeed"),
    TARGET_STRING("Gain"), 1, 1, 0 },

  { 97, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/NotInterfacing/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 98, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/MovedAway"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 99, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/SRR"),
    TARGET_STRING("initial_condition"), 0, 1, 0 },

  { 100, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/Within Range"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 101, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/Within Range1"),
    TARGET_STRING("const"), 1, 1, 0 },

  { 102, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Subsystem/Constant"),
    TARGET_STRING("Value"), 8, 1, 0 },

  { 103, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 104, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 105, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 106, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/DoCouplersMatch/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

  { 107, TARGET_STRING("CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/DoCouplersMatch/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 1, 1, 0 },

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
static void CouplingSystem_InitializeDataAddr(void* dataAddr[],
  B_CouplingSystem_c_T *localB)
{
  dataAddr[0] = (void*) (&localB->NOT[0]);
  dataAddr[1] = (void*) (&localB->CoreSubsys[7].BusAssignment);
  dataAddr[2] = (void*) (&localB->ImpAsg_InsertedFor_HasCab_at_inport_0[0]);
  dataAddr[3] = (void*)
    (&localB->ImpAsg_InsertedFor_ElectricallyCoupledVehicle_at_inport_0[0]);
  dataAddr[4] = (void*) (( &localB->VectorConcatenate2_h[0] + 1));
  dataAddr[5] = (void*) (&localB->VectorConcatenate2[0]);
  dataAddr[6] = (void*) (&localB->VectorConcatenate2_h[0]);
  dataAddr[7] = (void*) (&localB->CoreSubsys[7].BusAssignment);
  dataAddr[8] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[9] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit_f.LogicalOperator1);
  dataAddr[10] = (void*) (&localB->CoreSubsys[7].OverrideifDMS[0]);
  dataAddr[11] = (void*) (&localB->CoreSubsys[7].OverrideifDMS_h[0]);
  dataAddr[12] = (void*) (&localB->CoreSubsys[7].OverrideifDMS_o[0]);
  dataAddr[13] = (void*) (&localB->CoreSubsys[7].OverrideifDMS_l[0]);
  dataAddr[14] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[15] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit_f.LogicalOperator1);
  dataAddr[16] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[17] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit_f.LogicalOperator1);
  dataAddr[18] = (void*) (&CouplingSystem_P.Step_Time);
  dataAddr[19] = (void*) (&CouplingSystem_P.Step_Y0);
  dataAddr[20] = (void*) (&CouplingSystem_P.Step_YFinal);
  dataAddr[21] = (void*) (&CouplingSystem_P.ForUnitConnection_Value);
  dataAddr[22] = (void*) (&CouplingSystem_P.CoreSubsys.CouplerSystemOut_Y0);
  dataAddr[23] = (void*) (&CouplingSystem_P.ForTrainConnection_Value);
  dataAddr[24] = (void*)
    (&CouplingSystem_P.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[25] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value);
  dataAddr[26] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_jn[0]);
  dataAddr[27] = (void*) (&CouplingSystem_P.CoreSubsys.Constant11_Value[0]);
  dataAddr[28] = (void*) (&CouplingSystem_P.CoreSubsys.Constant12_Value[0]);
  dataAddr[29] = (void*) (&CouplingSystem_P.CoreSubsys.Constant2_Value[0]);
  dataAddr[30] = (void*) (&CouplingSystem_P.CoreSubsys.Constant3_Value[0]);
  dataAddr[31] = (void*) (&CouplingSystem_P.CoreSubsys.Constant4_Value[0]);
  dataAddr[32] = (void*) (&CouplingSystem_P.CoreSubsys.Constant5_Value[0]);
  dataAddr[33] = (void*) (&CouplingSystem_P.CoreSubsys.Constant6_Value[0]);
  dataAddr[34] = (void*) (&CouplingSystem_P.CoreSubsys.Constant7_Value);
  dataAddr[35] = (void*)
    (&CouplingSystem_P.CoreSubsys.Temporary_ReadyToCouple_Value);
  dataAddr[36] = (void*) (&CouplingSystem_P.CoreSubsys.Switch1_Threshold);
  dataAddr[37] = (void*) (&CouplingSystem_P.CoreSubsys.Switch2_Threshold);
  dataAddr[38] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.TriggerOtherCoupling_UpperSaturationLimit);
  dataAddr[39] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_k);
  dataAddr[40] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant1_Value);
  dataAddr[41] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value);
  dataAddr[42] = (void*) (&CouplingSystem_P.CoreSubsys.CompareToConstant_const);
  dataAddr[43] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_d);
  dataAddr[44] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_f);
  dataAddr[45] = (void*) (&CouplingSystem_P.CoreSubsys.CompareToConstant_const_j);
  dataAddr[46] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_f);
  dataAddr[47] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_c);
  dataAddr[48] = (void*) (&CouplingSystem_P.CoreSubsys.CompareToConstant_const_a);
  dataAddr[49] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_k);
  dataAddr[50] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_g);
  dataAddr[51] = (void*) (&CouplingSystem_P.CoreSubsys.CompareToConstant_const_d);
  dataAddr[52] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_kt);
  dataAddr[53] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_k);
  dataAddr[54] = (void*) (&CouplingSystem_P.CoreSubsys.CompareToConstant_const_h);
  dataAddr[55] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_b);
  dataAddr[56] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_j);
  dataAddr[57] = (void*)
    (&CouplingSystem_P.CoreSubsys.CompareToConstant_const_dg);
  dataAddr[58] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_a);
  dataAddr[59] = (void*) (&CouplingSystem_P.CoreSubsys.Constant1_Value_p);
  dataAddr[60] = (void*)
    (&CouplingSystem_P.CoreSubsys.SRLatchSetPriority1_initial_condition);
  dataAddr[61] = (void*)
    (&CouplingSystem_P.CoreSubsys.SRLatchSetPriority2_initial_condition);
  dataAddr[62] = (void*) (&CouplingSystem_P.CoreSubsys.Constant_Value_e);
  dataAddr[63] = (void*) (&CouplingSystem_P.CoreSubsys.Saturation_UpperSat);
  dataAddr[64] = (void*) (&CouplingSystem_P.CoreSubsys.Saturation_LowerSat);
  dataAddr[65] = (void*) (&CouplingSystem_P.CoreSubsys.DetectIncrease_vinit);
  dataAddr[66] = (void*) (&CouplingSystem_P.CoreSubsys.Switch3_Threshold);
  dataAddr[67] = (void*) (&CouplingSystem_P.CoreSubsys.Switch3_Threshold_o);
  dataAddr[68] = (void*) (&CouplingSystem_P.CoreSubsys.DetectDecrease_vinit);
  dataAddr[69] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Head_initial_condition);
  dataAddr[70] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Switch2_Threshold);
  dataAddr[71] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.CloseRange_const);
  dataAddr[72] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.CoupledState_initial_condition);
  dataAddr[73] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.DetectDecrease_vinit);
  dataAddr[74] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.MaxAutoCouplingSpeed_Value);
  dataAddr[75] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.MinAutoCouplingSpeed_Value);
  dataAddr[76] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Switch_Threshold);
  dataAddr[77] = (void*) (&CouplingSystem_P.CoreSubsys.CoreSubsys.Timer_gainval);
  dataAddr[78] = (void*) (&CouplingSystem_P.CoreSubsys.CoreSubsys.Timer_IC);
  dataAddr[79] = (void*) (&CouplingSystem_P.CoreSubsys.CoreSubsys.Timer_LowerSat);
  dataAddr[80] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.Initialise_Value);
  dataAddr[81] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.OffTime_Value);
  dataAddr[82] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_gainval);
  dataAddr[83] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_UpperSat);
  dataAddr[84] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_LowerSat);
  dataAddr[85] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.Gain_Gain);
  dataAddr[86] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.IC_Value);
  dataAddr[87] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.Initialise_Value);
  dataAddr[88] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.OffTime_Value);
  dataAddr[89] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.DiscreteTimeIntegrator_gainval);
  dataAddr[90] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.DiscreteTimeIntegrator_UpperSat);
  dataAddr[91] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.DiscreteTimeIntegrator_LowerSat);
  dataAddr[92] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.Gain_Gain);
  dataAddr[93] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.IC_Value);
  dataAddr[94] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_b);
  dataAddr[95] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition);
  dataAddr[96] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.ApproachSpeed_Gain);
  dataAddr[97] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_n);
  dataAddr[98] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.MovedAway_const);
  dataAddr[99] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.SRR_initial_condition);
  dataAddr[100] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.WithinRange_const);
  dataAddr[101] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.WithinRange1_const);
  dataAddr[102] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value);
  dataAddr[103] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_j);
  dataAddr[104] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit.Constant_Value);
  dataAddr[105] = (void*)
    (&CouplingSystem_P.CoreSubsys.TimerOffDelayNoInit_f.Constant_Value);
  dataAddr[106] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_i);
  dataAddr[107] = (void*)
    (&CouplingSystem_P.CoreSubsys.CoreSubsys.Constant_Value_o);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void CouplingSystem_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void CouplingSystem_InitializeLoggingFunctions(RTWLoggingFcnPtr
  loggingPtrs[])
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
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals", 3, 1,
    sizeof(BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals), SS_STRUCT, 0,
    0, 0 },

  { "struct", "BD_CouplerSystem_InterfaceData", 7, 4, sizeof
    (BD_CouplerSystem_InterfaceData), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_SingleCoupler", 2, 11, sizeof
    (BD_CouplingSystem_Out_Vehicle_SingleCoupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_Coupler", 1, 13, sizeof
    (BD_CouplingSystem_Out_Vehicle_Coupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_Audio", 2, 14, sizeof
    (BD_CouplingSystem_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_OutputControlStates", 2, 16, sizeof
    (BD_CouplingSystem_Out_Vehicle_OutputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler", 10, 18, sizeof
    (BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle_Debug", 10, 28, sizeof
    (BD_CouplingSystem_Out_Vehicle_Debug), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplingSystem_Out_Vehicle", 8, 38, sizeof
    (BD_CouplingSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "MechanicalCouplerState", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals,
     MechanicalCouplerState), 1, 1, 0 },

  { "PneumaticCouplerState", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals,
     PneumaticCouplerState), 1, 1, 0 },

  { "CouplerDamaged", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals, CouplerDamaged), 1,
    1, 0 },

  { "CouplerType", rt_offsetof(BD_CouplerSystem_InterfaceData, CouplerType), 1,
    1, 0 },

  { "ReadyToCouple", rt_offsetof(BD_CouplerSystem_InterfaceData, ReadyToCouple),
    1, 1, 0 },

  { "MechanicallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    MechanicallyCoupled), 1, 1, 0 },

  { "CouplerBrakeDemand", rt_offsetof(BD_CouplerSystem_InterfaceData,
    CouplerBrakeDemand), 1, 1, 0 },

  { "ElectricallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    ElectricallyCoupled), 1, 1, 0 },

  { "PneumaticallyCoupled", rt_offsetof(BD_CouplerSystem_InterfaceData,
    PneumaticallyCoupled), 1, 1, 0 },

  { "RescueModeCondition", rt_offsetof(BD_CouplerSystem_InterfaceData,
    RescueModeCondition), 0, 1, 0 },

  { "PhysicalSignals", rt_offsetof(BD_CouplingSystem_Out_Vehicle_SingleCoupler,
    PhysicalSignals), 2, 1, 0 },

  { "CouplingInterface", rt_offsetof(BD_CouplingSystem_Out_Vehicle_SingleCoupler,
    CouplingInterface), 3, 1, 0 },

  { "Coupler", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Coupler, Coupler), 4, 2,
    0 },

  { "MechanicalCouple", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Audio,
    MechanicalCouple), 1, 1, 0 },

  { "MechanicalUncouple", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Audio,
    MechanicalUncouple), 1, 1, 0 },

  { "MechanicalCouplerState", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_OutputControlStates, MechanicalCouplerState),
    1, 1, 0 },

  { "ExternalCoupling", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_OutputControlStates, ExternalCoupling), 1, 1,
    0 },

  { "AutoCouple", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    AutoCouple), 1, 1, 0 },

  { "AvailableReady", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    AvailableReady), 1, 1, 0 },

  { "OurCoupled", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    OurCoupled), 1, 1, 0 },

  { "Uncoupled", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    Uncoupled), 1, 1, 0 },

  { "TheirsCoupled", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    TheirsCoupled), 1, 1, 0 },

  { "BothCoupled", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler,
    BothCoupled), 1, 1, 0 },

  { "CouplerTypeMatched", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler, CouplerTypeMatched), 1, 1,
    0 },

  { "TheirsExtensionRate", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler, TheirsExtensionRate), 1, 1,
    0 },

  { "ModelledTrainCouplerType", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler, ModelledTrainCouplerType),
    1, 1, 0 },

  { "OtherTrainCouplerType", rt_offsetof
    (BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler, OtherTrainCouplerType), 1,
    1, 0 },

  { "EPVState", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug, EPVState), 1, 1,
    0 },

  { "ElectricalHeadCommand", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    ElectricalHeadCommand), 1, 1, 0 },

  { "MainResPressureOk", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    MainResPressureOk), 1, 1, 0 },

  { "PneuUncouplingCommand", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    PneuUncouplingCommand), 1, 2, 0 },

  { "MechUncouplingCommand", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    MechUncouplingCommand), 1, 2, 0 },

  { "ElectUncouplingCommand", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    ElectUncouplingCommand), 1, 2, 0 },

  { "ElectCouplingCommand", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    ElectCouplingCommand), 1, 2, 0 },

  { "VehicleOnAnEnd", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    VehicleOnAnEnd), 1, 2, 0 },

  { "CouplerTypesAcrossUnit", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    CouplerTypesAcrossUnit), 1, 2, 0 },

  { "DebugPerCoupler", rt_offsetof(BD_CouplingSystem_Out_Vehicle_Debug,
    DebugPerCoupler), 8, 2, 0 },

  { "Couplers", rt_offsetof(BD_CouplingSystem_Out_Vehicle, Couplers), 5, 1, 0 },

  { "CouplerAudio", rt_offsetof(BD_CouplingSystem_Out_Vehicle, CouplerAudio), 6,
    1, 0 },

  { "OutputControlStates", rt_offsetof(BD_CouplingSystem_Out_Vehicle,
    OutputControlStates), 7, 1, 0 },

  { "Debug", rt_offsetof(BD_CouplingSystem_Out_Vehicle, Debug), 9, 1, 0 },

  { "PhysicalSignals", rt_offsetof(BD_CouplingSystem_Out_Vehicle,
    PhysicalSignals), 2, 2, 0 },

  { "ElectricalTrainConnection", rt_offsetof(BD_CouplingSystem_Out_Vehicle,
    ElectricalTrainConnection), 1, 1, 0 },

  { "ElectricalUnitConnection", rt_offsetof(BD_CouplingSystem_Out_Vehicle,
    ElectricalUnitConnection), 1, 1, 0 },

  { "ElectricalCoupledCabsConnection", rt_offsetof(BD_CouplingSystem_Out_Vehicle,
    ElectricalCoupledCabsConnection), 1, 1, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2, 0 },

  { rtwCAPI_SCALAR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  8,                                   /* 0 */
  2,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  8,                                   /* 6 */
  1,                                   /* 7 */
  10,                                  /* 8 */
  1,                                   /* 9 */
  1,                                   /* 10 */
  2                                    /* 11 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.05, 0.0
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
    (&rtcapiStoredFloats[1]), 0, 0 }
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
  { rtBlockSignals, 18,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 90,
    rtModelParameters, 0 },

  { rtBlockStates, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3519362522U,
    3540735649U,
    3782480462U,
    847323537U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  CouplingSystem_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void CouplingSystem_InitializeDataMapInfo(RT_MODEL_CouplingSystem_T *const
  CouplingSystem_M, B_CouplingSystem_c_T *localB)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(CouplingSystem_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(CouplingSystem_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(CouplingSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  CouplingSystem_InitializeDataAddr(CouplingSystem_M->DataMapInfo.dataAddress,
    localB);
  rtwCAPI_SetDataAddressMap(CouplingSystem_M->DataMapInfo.mmi,
    CouplingSystem_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  CouplingSystem_InitializeVarDimsAddr
    (CouplingSystem_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(CouplingSystem_M->DataMapInfo.mmi,
    CouplingSystem_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(CouplingSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(CouplingSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  CouplingSystem_InitializeLoggingFunctions
    (CouplingSystem_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(CouplingSystem_M->DataMapInfo.mmi,
    CouplingSystem_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(CouplingSystem_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(CouplingSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(CouplingSystem_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void CouplingSystem_host_InitializeDataMapInfo
    (CouplingSystem_host_DataMapInfo_T *dataMap, const char *path)
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
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: CouplingSystem_capi.cpp */
