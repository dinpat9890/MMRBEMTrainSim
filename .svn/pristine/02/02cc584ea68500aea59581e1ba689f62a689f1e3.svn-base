/*
 * TractionSystem_capi.cpp
 *
 * Code generation for model "TractionSystem".
 *
 * Model version              : 1.676
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
#include "TractionSystem_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "TractionSystem.h"
#include "TractionSystem_capi.h"
#include "TractionSystem_private.h"
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
  { 0, 12, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing"),
    TARGET_STRING(""), 0, 4, 1, 0, 0 },

  { 1, 12, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing"),
    TARGET_STRING(""), 1, 5, 1, 0, 0 },

  { 2, 105, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle"),
    TARGET_STRING(""), 0, 16, 0, 0, 0 },

  { 3, 12, TARGET_STRING(
    "TractionSystem/Configuration/ConfigProcessing/ConfigCheck"),
    TARGET_STRING(""), 0, 4, 1, 0, 0 },

  { 4, 12, TARGET_STRING(
    "TractionSystem/Configuration/ConfigProcessing/ConfigCheck"),
    TARGET_STRING(""), 1, 5, 1, 0, 0 },

  { 5, 105, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/Unit Delay"),
    TARGET_STRING(""), 0, 17, 2, 0, 0 },

  { 6, 105, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/Bus Assignment"),
    TARGET_STRING(""), 0, 16, 0, 0, 0 },

  { 7, 105, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/Subsystem"),
    TARGET_STRING(""), 0, 17, 2, 0, 0 },

  { 8, 53, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)"),
    TARGET_STRING(""), 0, 18, 2, 0, 0 },

  { 9, 25, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 38, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 25, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 34, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 38, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 47, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 34, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 47, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 87, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/SafeDivide/Replace Zeros"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 18, 90, TARGET_STRING(
    "TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/SafeDivide/Replace Zeros"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 19, TARGET_STRING("TractionSystem/Configuration/Step"),
    TARGET_STRING("Time"), 3, 0, 0 },

  { 20, TARGET_STRING("TractionSystem/Configuration/Step"),
    TARGET_STRING("Before"), 3, 0, 0 },

  { 21, TARGET_STRING("TractionSystem/Configuration/Step"),
    TARGET_STRING("After"), 3, 0, 0 },

  { 22, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/CommonVehicleConfig"),
    TARGET_STRING("InitialOutput"), 4, 0, 0 },

  { 23, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/TractionSystemVehicleConfig"),
    TARGET_STRING("InitialOutput"), 5, 0, 0 },

  { 24, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/TractionSystemOut"),
    TARGET_STRING("InitialOutput"), 16, 0, 0 },

  { 25, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/Unit Delay"),
    TARGET_STRING("InitialCondition"), 17, 0, 0 },

  { 26, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/Constant1"),
    TARGET_STRING("Value"), 16, 0, 0 },

  { 27, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gearing Ratio/Min Value"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 28, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gearing Ratio/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 29, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gross1/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 30, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gross1/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 31, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Height1/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 32, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Height1/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 33, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Length1/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 34, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Length1/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 35, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles3/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 36, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles3/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 37, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles4/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 38, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles4/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 39, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles5/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 40, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles5/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 41, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Tare1/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 42, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Tare1/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 43, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default WheelDiameter/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 44, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default WheelDiameter/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 45, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Width1/Min Value"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 46, TARGET_STRING("TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Width1/Default"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 47, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/AudioOutputsRepack/Constant2"),
    TARGET_STRING("Value"), 15, 0, 0 },

  { 48, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/AudioOutputsRepack/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 49, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/DynamicsOutputsRepack/Constant"),
    TARGET_STRING("Value"), 3, 4, 0 },

  { 50, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/Constant1"),
    TARGET_STRING("Value"), 13, 0, 0 },

  { 51, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 52, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 53, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 54, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Link_NominalVoltage"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 55, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Link_OverVoltage"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 56, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Link_UnderVoltage"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 57, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/RC_AK"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 58, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/RC_K"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 59, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 3, 0, 0 },

  { 60, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 61, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Multiply"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 62, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Multiply1"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 63, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 64, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Switch1"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 65, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 66, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/BCUOutputsRepack/Constant2"),
    TARGET_STRING("Value"), 12, 0, 0 },

  { 67, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/ElectricalOutputsRepack/Constant2"),
    TARGET_STRING("Value"), 7, 0, 0 },

  { 68, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/TCMSOutputsRepack/Constant4"),
    TARGET_STRING("Value"), 10, 0, 0 },

  { 69, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Compare To Constant"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 70, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Detect Decrease"),
    TARGET_STRING("vinit"), 3, 0, 0 },

  { 71, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 72, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 73, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 74, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUOFFLogic/Constant1"),
    TARGET_STRING("Value"), 8, 0, 0 },

  { 75, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUOFFLogic/Constant2"),
    TARGET_STRING("Value"), 11, 0, 0 },

  { 76, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUOFFLogic/Constant3"),
    TARGET_STRING("Value"), 18, 0, 0 },

  { 77, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUOFFLogic/Constant4"),
    TARGET_STRING("Value"), 6, 0, 0 },

  { 78, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState/Logic"),
    TARGET_STRING("TruthTable"), 0, 5, 0 },

  { 79, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState1/Logic"),
    TARGET_STRING("TruthTable"), 0, 5, 0 },

  { 80, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/Constant3"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 81, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 82, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/Gain1"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 83, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/Multiply1"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 84, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/Saturation"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 85, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/Saturation"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 86, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/Saturation1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 87, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/Saturation1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 88, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/safedivide2"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 89, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/safedivide2"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 90, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingInterlocks/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 91, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingInterlocks/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 92, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/BCUOutCompile/Constant1"),
    TARGET_STRING("Value"), 11, 0, 0 },

  { 93, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/BogieElectricalOutCompile/Constant4"),
    TARGET_STRING("Value"), 6, 0, 0 },

  { 94, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/TCMSOutCompile/Constant4"),
    TARGET_STRING("Value"), 8, 0, 0 },

  { 95, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/MotorBrakingEffortComputation/Multiply"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 96, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/MotorTractionEffortComputation/Multiply"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 97, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio/Multiply1"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 98, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio/safedivide1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 99, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio/safedivide1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 100, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio/safedivide2"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 101, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio/safedivide2"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 102, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidBrakingDemandPct/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 103, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidBrakingDemandPct/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 104, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidTractionDemandPct/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 105, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Compare To Constant"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 106, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Compare To Constant1"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 107, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 108, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Stop"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 109, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 110, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Switch1"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 111, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 112, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Compare To Constant1"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 113, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Compare To Constant2"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 114, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 115, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Stop"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 116, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 117, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Switch1"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 118, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 119, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidTractionDemandPct/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 120, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("gainval"), 3, 0, 0 },

  { 121, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 122, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 3, 0, 0 },

  { 123, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 124, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 125, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/min0"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 126, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/min0"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 127, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Delay"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 128, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 129, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 130, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("gainval"), 3, 0, 0 },

  { 131, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 132, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 3, 0, 0 },

  { 133, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 134, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 135, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/min0"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 136, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/min0"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 137, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Delay"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 138, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 139, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 140, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 141, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 142, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 143, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant3"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 144, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant4"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 145, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled/Constant5"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 146, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/apply opposite to direction of movement"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 147, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/NoMotorAxle/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 148, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/NoMotorAxle/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 149, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/NoMotorAxle/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 150, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/NoMotorAxle/Constant3"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 151, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 152, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Rate Limiter Dynamic/Delay Input2"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 153, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Rate Limiter Dynamic/sample time"),
    TARGET_STRING("WtEt"), 3, 0, 0 },

  { 154, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Decrease"),
    TARGET_STRING("vinit"), 3, 0, 0 },

  { 155, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Increase"),
    TARGET_STRING("vinit"), 3, 0, 0 },

  { 156, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 157, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Sample and Hold"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 158, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 159, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 160, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Rate Limiter Dynamic/Delay Input2"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 161, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Rate Limiter Dynamic/sample time"),
    TARGET_STRING("WtEt"), 3, 0, 0 },

  { 162, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Decrease"),
    TARGET_STRING("vinit"), 3, 0, 0 },

  { 163, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Increase"),
    TARGET_STRING("vinit"), 3, 0, 0 },

  { 164, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 165, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Sample and Hold"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 166, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 167, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable/No Braking"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 168, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveInputType"),
    TARGET_STRING("Value"), 19, 0, 0 },

  { 169, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/PerformanceFactor"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 170, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/Rate Limiter"),
    TARGET_STRING("RisingSlewLimit"), 3, 0, 0 },

  { 171, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/Rate Limiter"),
    TARGET_STRING("FallingSlewLimit"), 3, 0, 0 },

  { 172, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/Rate Limiter"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 173, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/SpeedRatio/safedivide1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 174, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/SpeedRatio/safedivide1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 175, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionAvailable/No Power"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 176, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionAvailable/Switch2"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 177, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveInputType"),
    TARGET_STRING("Value"), 19, 0, 0 },

  { 178, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/PerformanceFactor"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 179, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/Rate Limiter"),
    TARGET_STRING("RisingSlewLimit"), 3, 0, 0 },

  { 180, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/Rate Limiter"),
    TARGET_STRING("FallingSlewLimit"), 3, 0, 0 },

  { 181, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/Rate Limiter"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 182, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumBraking/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 183, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumBraking/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 184, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/Saturation1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 185, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/Saturation1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 186, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/Saturation3"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 187, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/Saturation3"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 188, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 189, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 190, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/SpeedRatio/safedivide1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 191, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/SpeedRatio/safedivide1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 192, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 193, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 194, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 195, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 3, 0, 0 },

  { 196, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 3, 0, 0 },

  { 197, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 3, 0, 0 },

  { 198, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 199, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 200, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 201, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 202, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 203, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 3, 0, 0 },

  { 204, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 3, 0, 0 },

  { 205, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 3, 0, 0 },

  { 206, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 207, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 208, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 209, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 210, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_z_data"), 3, 6, 0 },

  { 211, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_size"), 3, 6, 0 },

  { 212, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_xy_data"), 3, 7, 0 },

  { 213, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 214, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 215, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("x_data"), 3, 2, 0 },

  { 216, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("y_data"), 3, 2, 0 },

  { 217, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("subset_size"), 3, 0, 0 },

  { 218, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 219, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 220, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/NoData/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 221, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection/Orientation Inversion/Compare To Constant"),
    TARGET_STRING("const"), 3, 0, 0 },

  { 222, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection/Orientation Inversion/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 223, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection/Orientation Inversion/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 224, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_z_data"), 3, 6, 0 },

  { 225, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_size"), 3, 6, 0 },

  { 226, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Contour Interpolation 2D y"),
    TARGET_STRING("contour_xy_data"), 3, 7, 0 },

  { 227, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 228, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 229, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("x_data"), 3, 2, 0 },

  { 230, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("y_data"), 3, 2, 0 },

  { 231, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Subset Interpolation 1D"),
    TARGET_STRING("subset_size"), 3, 0, 0 },

  { 232, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Percentage to fraction"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 233, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Saturation"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 234, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Saturation"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 235, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Percentage to fraction"),
    TARGET_STRING("Gain"), 3, 0, 0 },

  { 236, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 237, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 238, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 239, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 240, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation3"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 241, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/Saturation3"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 242, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 243, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 244, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/NoData/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 245, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumBraking/RampUpCurve/Constant"),
    TARGET_STRING("Value"), 3, 8, 0 },

  { 246, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 247, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 248, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 249, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/Constant3"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 250, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/NoLimit"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 251, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 252, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 253, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 254, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves/Switch1"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 255, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/RampUpCurve/Constant"),
    TARGET_STRING("Value"), 3, 8, 0 },

  { 256, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxPowerLookup"),
    TARGET_STRING("x_data"), 3, 6, 0 },

  { 257, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxPowerLookup"),
    TARGET_STRING("y_data"), 3, 9, 0 },

  { 258, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxPowerLookup"),
    TARGET_STRING("subset_size"), 3, 0, 0 },

  { 259, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxTorqueLookup"),
    TARGET_STRING("x_data"), 3, 6, 0 },

  { 260, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxTorqueLookup"),
    TARGET_STRING("y_data"), 3, 9, 0 },

  { 261, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxTorqueLookup"),
    TARGET_STRING("subset_size"), 3, 0, 0 },

  { 262, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/Saturation1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 263, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/Saturation1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 264, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/Saturation3"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 265, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/Saturation3"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 266, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 267, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Constant1"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 268, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Saturation1"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 269, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Saturation1"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 270, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Saturation3"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 271, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/Saturation3"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 272, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/Constant2"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 273, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/Constant3"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 274, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/NoLimit"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 275, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/safedivide"),
    TARGET_STRING("UpperLimit"), 3, 0, 0 },

  { 276, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/safedivide"),
    TARGET_STRING("LowerLimit"), 3, 0, 0 },

  { 277, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/Switch"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

  { 278, TARGET_STRING("TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves/Switch1"),
    TARGET_STRING("Threshold"), 3, 0, 0 },

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
static void TractionSystem_InitializeDataAddr(void* dataAddr[],
  B_TractionSystem_c_T *localB)
{
  dataAddr[0] = (void*)
    (&localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[0]);
  dataAddr[1] = (void*)
    (&localB->ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[0]);
  dataAddr[2] = (void*) (&localB->CoreSubsys_p[7].BusAssignment);
  dataAddr[3] = (void*)
    (&localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[0]);
  dataAddr[4] = (void*)
    (&localB->ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[0]);
  dataAddr[5] = (void*) (&localB->CoreSubsys_p[7].UnitDelay[0]);
  dataAddr[6] = (void*) (&localB->CoreSubsys_p[7].BusAssignment);
  dataAddr[7] = (void*) (&localB->CoreSubsys_p[7].UnitDelay[0]);
  dataAddr[8] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[0]);
  dataAddr[9] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOnDelayNoInit.Compare);
  dataAddr[10] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOnDelayNoInit_h.Compare);
  dataAddr[11] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOnDelayNoInit.Compare);
  dataAddr[12] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[13] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOnDelayNoInit_h.Compare);
  dataAddr[14] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOffDelayNoInit_h.LogicalOperator1);
  dataAddr[15] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[16] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pna[1].
    TimerOffDelayNoInit_h.LogicalOperator1);
  dataAddr[17] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pnae[1].
    CoreSubsys_h[1].sf_ReplaceZeros_k.y);
  dataAddr[18] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_pnae[1].
    CoreSubsys_h[1].sf_ReplaceZeros.y);
  dataAddr[19] = (void*) (&TractionSystem_P.Step_Time);
  dataAddr[20] = (void*) (&TractionSystem_P.Step_Y0);
  dataAddr[21] = (void*) (&TractionSystem_P.Step_YFinal);
  dataAddr[22] = (void*) (&TractionSystem_P.CommonVehicleConfig_Y0);
  dataAddr[23] = (void*) (&TractionSystem_P.TractionSystemVehicleConfig_Y0);
  dataAddr[24] = (void*) (&TractionSystem_P.CoreSubsys_p.TractionSystemOut_Y0);
  dataAddr[25] = (void*)
    (&TractionSystem_P.CoreSubsys_p.UnitDelay_InitialCondition);
  dataAddr[26] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant1_Value);
  dataAddr[27] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_g);
  dataAddr[28] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_mh);
  dataAddr[29] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_h);
  dataAddr[30] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_m);
  dataAddr[31] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_o);
  dataAddr[32] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_de);
  dataAddr[33] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const);
  dataAddr[34] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_h);
  dataAddr[35] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_i);
  dataAddr[36] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_e);
  dataAddr[37] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_m);
  dataAddr[38] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_f);
  dataAddr[39] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_n);
  dataAddr[40] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_n);
  dataAddr[41] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_p);
  dataAddr[42] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_a);
  dataAddr[43] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_d);
  dataAddr[44] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value_d);
  dataAddr[45] = (void*) (&TractionSystem_P.CoreSubsys.MinValue_const_b);
  dataAddr[46] = (void*) (&TractionSystem_P.CoreSubsys.Default_Value);
  dataAddr[47] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant2_Value_i);
  dataAddr[48] = (void*) (&TractionSystem_P.CoreSubsys_p.Gain_Gain);
  dataAddr[49] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant_Value[0]);
  dataAddr[50] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant1_Value_i);
  dataAddr[51] = (void*)
    (&TractionSystem_P.CoreSubsys_p.AKState_initial_condition);
  dataAddr[52] = (void*)
    (&TractionSystem_P.CoreSubsys_p.AKState1_initial_condition);
  dataAddr[53] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant1_Value_f);
  dataAddr[54] = (void*)
    (&TractionSystem_P.CoreSubsys_p.Link_NominalVoltage_Value);
  dataAddr[55] = (void*) (&TractionSystem_P.CoreSubsys_p.Link_OverVoltage_Value);
  dataAddr[56] = (void*) (&TractionSystem_P.CoreSubsys_p.Link_UnderVoltage_Value);
  dataAddr[57] = (void*) (&TractionSystem_P.CoreSubsys_p.RC_AK_Value);
  dataAddr[58] = (void*) (&TractionSystem_P.CoreSubsys_p.RC_K_Value);
  dataAddr[59] = (void*)
    (&TractionSystem_P.CoreSubsys_p.DiscreteTimeIntegrator_gainval);
  dataAddr[60] = (void*)
    (&TractionSystem_P.CoreSubsys_p.DiscreteTimeIntegrator_IC);
  dataAddr[61] = (void*) (&TractionSystem_P.CoreSubsys_p.Multiply_Gain);
  dataAddr[62] = (void*) (&TractionSystem_P.CoreSubsys_p.Multiply1_Gain);
  dataAddr[63] = (void*) (&TractionSystem_P.CoreSubsys_p.Switch_Threshold);
  dataAddr[64] = (void*) (&TractionSystem_P.CoreSubsys_p.Switch1_Threshold);
  dataAddr[65] = (void*)
    (&TractionSystem_P.CoreSubsys_p.UnitDelay_InitialCondition_e);
  dataAddr[66] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant2_Value);
  dataAddr[67] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant2_Value_m);
  dataAddr[68] = (void*) (&TractionSystem_P.CoreSubsys_p.Constant4_Value);
  dataAddr[69] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant_const_c);
  dataAddr[70] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit_j);
  dataAddr[71] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition_m);
  dataAddr[72] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value);
  dataAddr[73] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold_f);
  dataAddr[74] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value);
  dataAddr[75] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value);
  dataAddr[76] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant3_Value);
  dataAddr[77] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant4_Value_ko);
  dataAddr[78] = (void*) (&TractionSystem_P.CoreSubsys_p.Logic_table_f[0]);
  dataAddr[79] = (void*) (&TractionSystem_P.CoreSubsys_p.Logic_table[0]);
  dataAddr[80] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value);
  dataAddr[81] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Gain_Gain);
  dataAddr[82] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Gain1_Gain);
  dataAddr[83] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply1_Gain);
  dataAddr[84] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_UpperSat);
  dataAddr[85] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_LowerSat);
  dataAddr[86] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_UpperSat);
  dataAddr[87] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_LowerSat);
  dataAddr[88] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat);
  dataAddr[89] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat);
  dataAddr[90] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_i4);
  dataAddr[91] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold);
  dataAddr[92] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value_d);
  dataAddr[93] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant4_Value_k);
  dataAddr[94] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant4_Value);
  dataAddr[95] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply_Gain_b);
  dataAddr[96] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply_Gain);
  dataAddr[97] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply1_Gain_k);
  dataAddr[98] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_UpperSat);
  dataAddr[99] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_LowerSat);
  dataAddr[100] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat_a);
  dataAddr[101] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat_e);
  dataAddr[102] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_d);
  dataAddr[103] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold_a);
  dataAddr[104] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_c);
  dataAddr[105] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant_const);
  dataAddr[106] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant1_const_j);
  dataAddr[107] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition_e);
  dataAddr[108] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Stop_const_o);
  dataAddr[109] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_i);
  dataAddr[110] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch1_Threshold_k);
  dataAddr[111] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_a);
  dataAddr[112] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant1_const);
  dataAddr[113] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant2_const);
  dataAddr[114] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition);
  dataAddr[115] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Stop_const);
  dataAddr[116] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_m);
  dataAddr[117] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch1_Threshold);
  dataAddr[118] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition);
  dataAddr[119] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_a);
  dataAddr[120] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit.Timer_gainval);
  dataAddr[121] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit.Timer_IC);
  dataAddr[122] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit.Timer_LowerSat);
  dataAddr[123] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value_dh);
  dataAddr[124] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value_l);
  dataAddr[125] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat);
  dataAddr[126] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat);
  dataAddr[127] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition_l);
  dataAddr[128] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_h);
  dataAddr[129] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay1_InitialCondition);
  dataAddr[130] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h.Timer_gainval);
  dataAddr[131] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h.Timer_IC);
  dataAddr[132] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h.Timer_LowerSat);
  dataAddr[133] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value_i);
  dataAddr[134] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value_o);
  dataAddr[135] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat_f);
  dataAddr[136] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat_j);
  dataAddr[137] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition);
  dataAddr[138] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_i);
  dataAddr[139] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay1_InitialCondition_k);
  dataAddr[140] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_az);
  dataAddr[141] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value_g);
  dataAddr[142] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value_l);
  dataAddr[143] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value_k);
  dataAddr[144] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant4_Value);
  dataAddr[145] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant5_Value);
  dataAddr[146] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.applyoppositetodirectionofmovement_Gain);
  dataAddr[147] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant_Value_i);
  dataAddr[148] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant1_Value);
  dataAddr[149] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant2_Value);
  dataAddr[150] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant3_Value);
  dataAddr[151] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit.Constant_Value);
  dataAddr[152] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DelayInput2_InitialCondition);
  dataAddr[153] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt);
  dataAddr[154] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit);
  dataAddr[155] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectIncrease_vinit);
  dataAddr[156] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority1_initial_condition);
  dataAddr[157] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SampleandHold_InitialCondition);
  dataAddr[158] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Gain_Gain);
  dataAddr[159] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h.Constant_Value);
  dataAddr[160] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DelayInput2_InitialCondition_f);
  dataAddr[161] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt_h);
  dataAddr[162] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit_i);
  dataAddr[163] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectIncrease_vinit_d);
  dataAddr[164] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority1_initial_condition_f);
  dataAddr[165] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SampleandHold_InitialCondition_m);
  dataAddr[166] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Gain_Gain_o);
  dataAddr[167] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoBraking_Value);
  dataAddr[168] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CurveInputType_Value_f);
  dataAddr[169] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.PerformanceFactor_Value_h);
  dataAddr[170] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim_g);
  dataAddr[171] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim_h);
  dataAddr[172] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_IC_p);
  dataAddr[173] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_UpperSat);
  dataAddr[174] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_LowerSat);
  dataAddr[175] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoPower_Value);
  dataAddr[176] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch2_Threshold);
  dataAddr[177] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CurveInputType_Value);
  dataAddr[178] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.PerformanceFactor_Value);
  dataAddr[179] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim);
  dataAddr[180] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim);
  dataAddr[181] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_IC);
  dataAddr[182] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat_o);
  dataAddr[183] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat_d);
  dataAddr[184] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_UpperSat);
  dataAddr[185] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_LowerSat);
  dataAddr[186] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_UpperSat);
  dataAddr[187] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_LowerSat);
  dataAddr[188] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat);
  dataAddr[189] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat);
  dataAddr[190] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_UpperSat);
  dataAddr[191] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_LowerSat);
  dataAddr[192] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_e);
  dataAddr[193] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.Initialise_Value);
  dataAddr[194] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.OffTime_Value);
  dataAddr[195] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.DiscreteTimeIntegrator_gainval);
  dataAddr[196] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.DiscreteTimeIntegrator_UpperSat);
  dataAddr[197] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.DiscreteTimeIntegrator_LowerSat);
  dataAddr[198] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.Gain_Gain);
  dataAddr[199] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.IC_Value);
  dataAddr[200] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_cd);
  dataAddr[201] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.Initialise_Value);
  dataAddr[202] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.OffTime_Value);
  dataAddr[203] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.DiscreteTimeIntegrator_gainval);
  dataAddr[204] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.DiscreteTimeIntegrator_UpperSat);
  dataAddr[205] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.DiscreteTimeIntegrator_LowerSat);
  dataAddr[206] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.Gain_Gain);
  dataAddr[207] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.IC_Value);
  dataAddr[208] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_p);
  dataAddr[209] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_g);
  dataAddr[210] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
     [0]);
  dataAddr[211] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
     [0]);
  dataAddr[212] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
     [0]);
  dataAddr[213] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_e);
  dataAddr[214] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_a);
  dataAddr[215] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
     [0]);
  dataAddr[216] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
     [0]);
  dataAddr[217] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size);
  dataAddr[218] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_j);
  dataAddr[219] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_d);
  dataAddr[220] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_f);
  dataAddr[221] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CompareToConstant_const);
  dataAddr[222] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_j);
  dataAddr[223] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value);
  dataAddr[224] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
     [0]);
  dataAddr[225] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
     [0]);
  dataAddr[226] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
     [0]);
  dataAddr[227] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_a);
  dataAddr[228] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_c);
  dataAddr[229] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
     [0]);
  dataAddr[230] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
     [0]);
  dataAddr[231] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size_b);
  dataAddr[232] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Percentagetofraction_Gain_n);
  dataAddr[233] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat_o);
  dataAddr[234] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat_j);
  dataAddr[235] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Percentagetofraction_Gain);
  dataAddr[236] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat);
  dataAddr[237] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat);
  dataAddr[238] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat);
  dataAddr[239] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat);
  dataAddr[240] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat);
  dataAddr[241] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat);
  dataAddr[242] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_h);
  dataAddr[243] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_e);
  dataAddr[244] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_jf);
  dataAddr[245] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant_Value[0]);
  dataAddr[246] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit.Constant_Value);
  dataAddr[247] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h.Constant_Value);
  dataAddr[248] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value);
  dataAddr[249] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value);
  dataAddr[250] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value);
  dataAddr[251] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat);
  dataAddr[252] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat);
  dataAddr[253] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold);
  dataAddr[254] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch1_Threshold);
  dataAddr[255] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value
     [0]);
  dataAddr[256] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
     [0]);
  dataAddr[257] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
     [0]);
  dataAddr[258] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_subset_size);
  dataAddr[259] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
     [0]);
  dataAddr[260] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
     [0]);
  dataAddr[261] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_subset_size);
  dataAddr[262] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_j);
  dataAddr[263] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_e);
  dataAddr[264] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_k);
  dataAddr[265] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_c);
  dataAddr[266] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_m);
  dataAddr[267] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value_e);
  dataAddr[268] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_f);
  dataAddr[269] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_a);
  dataAddr[270] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_f);
  dataAddr[271] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_d);
  dataAddr[272] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value_c);
  dataAddr[273] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value_g);
  dataAddr[274] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value_o);
  dataAddr[275] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_f);
  dataAddr[276] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_a);
  dataAddr[277] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_m);
  dataAddr[278] = (void*)
    (&TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch1_Threshold_e);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void TractionSystem_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void TractionSystem_InitializeLoggingFunctions(RTWLoggingFcnPtr
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
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0, 0 },

  { "numeric", "VehicleType", 0, 0, sizeof(VehicleType), SS_ENUM_TYPE, 0, 0,
    SS_INT32 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_CommonTrain_Cfg_Vehicle", 15, 1, sizeof
    (BD_CommonTrain_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Cfg_Vehicle", 1, 16, sizeof
    (BD_TractionSystem_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie", 3, 17,
    sizeof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie), SS_STRUCT, 0,
    0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_ElectricalSystem", 2, 20, sizeof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS_Bogie", 17, 22, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU", 3, 39, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCMS", 4, 42, sizeof
    (BD_TractionSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_BCU_Bogie", 4, 46, sizeof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_BCU", 1, 50, sizeof
    (BD_TractionSystem_Out_Vehicle_BCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_TCU", 3, 51, sizeof
    (BD_TractionSystem_Out_Vehicle_TCU), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_Dynamics", 3, 54, sizeof
    (BD_TractionSystem_Out_Vehicle_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle_Audio", 2, 57, sizeof
    (BD_TractionSystem_Out_Vehicle_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Out_Vehicle", 3, 59, sizeof
    (BD_TractionSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Int_BogieOutputs", 9, 62, sizeof
    (BD_TractionSystem_Int_BogieOutputs), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TractionSystem_Int_BogieControl", 9, 71, sizeof
    (BD_TractionSystem_Int_BogieControl), SS_STRUCT, 0, 0, 0 },

  { "numeric", "TractionCurveSpecificationType", 0, 0, sizeof
    (TractionCurveSpecificationType), SS_ENUM_TYPE, 0, 0, SS_INT32 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "Enabled", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Enabled), 0, 0, 0 },

  { "VehicleID", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, VehicleID), 1, 0, 0 },

  { "Type", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Type), 2, 0, 0 },

  { "Class", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Class), 3, 0, 0 },

  { "Orientation", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Orientation), 3, 0, 0
  },

  { "Length", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Length), 3, 0, 0 },

  { "Height", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Height), 3, 0, 0 },

  { "Width", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, Width), 3, 0, 0 },

  { "TareMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, TareMass), 3, 0, 0 },

  { "GrossMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, GrossMass), 3, 0, 0 },

  { "LoadingMass", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, LoadingMass), 3, 0, 0
  },

  { "NumberOfAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, NumberOfAxles), 3,
    0, 0 },

  { "NumberOfDrivenAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle,
    NumberOfDrivenAxles), 3, 0, 0 },

  { "NumberOfBrakedAxles", rt_offsetof(BD_CommonTrain_Cfg_Vehicle,
    NumberOfBrakedAxles), 3, 0, 0 },

  { "WheelDiameter", rt_offsetof(BD_CommonTrain_Cfg_Vehicle, WheelDiameter), 3,
    0, 0 },

  { "HasMotors", rt_offsetof(BD_TractionSystem_Cfg_Vehicle, HasMotors), 0, 0, 0
  },

  { "Forward", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie,
    Forward), 0, 0, 0 },

  { "Reverse", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie,
    Reverse), 0, 0, 0 },

  { "BogieNotIsolated", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie, BogieNotIsolated), 0,
    0, 0 },

  { "TractionContactorStatus", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_ElectricalSystem, TractionContactorStatus), 3,
    0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_ElectricalSystem, Bogie),
    6, 2, 0 },

  { "TCUStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TCUStatus),
    0, 0, 0 },

  { "BogieFaulty", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    BogieFaulty), 0, 0, 0 },

  { "TractionNotIsolated", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TractionNotIsolated), 0, 0, 0 },

  { "EDBrakeNotIsolated", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    EDBrakeNotIsolated), 0, 0, 0 },

  { "TCUSlideDetected", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TCUSlideDetected), 0, 0, 0 },

  { "TCUSlipDetected", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TCUSlipDetected), 0, 0, 0 },

  { "TractiveEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractiveEffortAchieved), 3, 0, 0
  },

  { "EDBrakingEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingEffortAchieved), 3, 0, 0
  },

  { "TractiveEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractiveEffortPossible), 3, 0, 0
  },

  { "EDBrakingEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingEffortPossible), 3, 0, 0
  },

  { "TractionPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    TractionPower), 3, 0, 0 },

  { "EDBrakingPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    EDBrakingPower), 3, 0, 0 },

  { "TractivePowerPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, TractivePowerPossible), 3, 0, 0 },

  { "EDBrakingPowerPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_TCMS_Bogie, EDBrakingPowerPossible), 3, 0, 0
  },

  { "MotorSpeeds", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    MotorSpeeds), 3, 2, 0 },

  { "WSPTractionCutout", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    WSPTractionCutout), 0, 0, 0 },

  { "SpeedSensorFault", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Bogie,
    SpeedSensorFault), 3, 0, 0 },

  { "TCU_KStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    TCU_KStatus), 3, 0, 0 },

  { "TCU_AKStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    TCU_AKStatus), 3, 0, 0 },

  { "FilterVoltage", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU,
    FilterVoltage), 3, 0, 0 },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS, Bogie), 8, 2, 0 },

  { "Trafo_TCU", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS, Trafo_TCU), 9,
    0, 0 },

  { "VehicleDerailed", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS,
    VehicleDerailed), 3, 0, 0 },

  { "VehicleBogieDerailed", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCMS,
    VehicleBogieDerailed), 3, 0, 0 },

  { "TCUWheelSlideControlActive", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, TCUWheelSlideControlActive), 0, 0,
    0 },

  { "EDBrakeStatus", rt_offsetof(BD_TractionSystem_Out_Vehicle_BCU_Bogie,
    EDBrakeStatus), 0, 0, 0 },

  { "EDBrakingEffortAchieved", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, EDBrakingEffortAchieved), 3, 0, 0
  },

  { "EDBrakingEffortPossible", rt_offsetof
    (BD_TractionSystem_Out_Vehicle_BCU_Bogie, EDBrakingEffortPossible), 3, 0, 0
  },

  { "Bogie", rt_offsetof(BD_TractionSystem_Out_Vehicle_BCU, Bogie), 11, 2, 0 },

  { "ElectricalSystem", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU,
    ElectricalSystem), 7, 0, 0 },

  { "TCMS", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU, TCMS), 10, 0, 0 },

  { "BCU", rt_offsetof(BD_TractionSystem_Out_Vehicle_TCU, BCU), 12, 0, 0 },

  { "TractionBrakingForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    TractionBrakingForce), 3, 3, 0 },

  { "TractionForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    TractionForce), 3, 3, 0 },

  { "BrakingForce", rt_offsetof(BD_TractionSystem_Out_Vehicle_Dynamics,
    BrakingForce), 3, 3, 0 },

  { "TractionEDPower", rt_offsetof(BD_TractionSystem_Out_Vehicle_Audio,
    TractionEDPower), 3, 0, 0 },

  { "WheelAngularVelocity", rt_offsetof(BD_TractionSystem_Out_Vehicle_Audio,
    WheelAngularVelocity), 3, 0, 0 },

  { "TractionControl", rt_offsetof(BD_TractionSystem_Out_Vehicle,
    TractionControl), 13, 0, 0 },

  { "Dynamics", rt_offsetof(BD_TractionSystem_Out_Vehicle, Dynamics), 14, 0, 0 },

  { "Audio", rt_offsetof(BD_TractionSystem_Out_Vehicle, Audio), 15, 0, 0 },

  { "BogieTractiveEffort", rt_offsetof(BD_TractionSystem_Int_BogieOutputs,
    BogieTractiveEffort), 3, 0, 0 },

  { "BogieDynamicBrakingEffort", rt_offsetof(BD_TractionSystem_Int_BogieOutputs,
    BogieDynamicBrakingEffort), 3, 0, 0 },

  { "BogieMaxTractionEffortPossible", rt_offsetof
    (BD_TractionSystem_Int_BogieOutputs, BogieMaxTractionEffortPossible), 3, 0,
    0 },

  { "BogieMaxBrakingEffortPossible", rt_offsetof
    (BD_TractionSystem_Int_BogieOutputs, BogieMaxBrakingEffortPossible), 3, 0, 0
  },

  { "BogieTractivePower", rt_offsetof(BD_TractionSystem_Int_BogieOutputs,
    BogieTractivePower), 3, 0, 0 },

  { "BogieDynamicBrakingPower", rt_offsetof(BD_TractionSystem_Int_BogieOutputs,
    BogieDynamicBrakingPower), 3, 0, 0 },

  { "BogieMaxTractionPowerPossible", rt_offsetof
    (BD_TractionSystem_Int_BogieOutputs, BogieMaxTractionPowerPossible), 3, 0, 0
  },

  { "BogieMaxBrakingPowerPossible", rt_offsetof
    (BD_TractionSystem_Int_BogieOutputs, BogieMaxBrakingPowerPossible), 3, 0, 0
  },

  { "BogieMotorSpeeds", rt_offsetof(BD_TractionSystem_Int_BogieOutputs,
    BogieMotorSpeeds), 3, 2, 0 },

  { "TractionDemandPct", rt_offsetof(BD_TractionSystem_Int_BogieControl,
    TractionDemandPct), 3, 0, 0 },

  { "DynamicBrakeTorqueDemand", rt_offsetof(BD_TractionSystem_Int_BogieControl,
    DynamicBrakeTorqueDemand), 3, 0, 0 },

  { "Powering", rt_offsetof(BD_TractionSystem_Int_BogieControl, Powering), 3, 0,
    0 },

  { "Braking", rt_offsetof(BD_TractionSystem_Int_BogieControl, Braking), 3, 0, 0
  },

  { "Forward", rt_offsetof(BD_TractionSystem_Int_BogieControl, Forward), 3, 0, 0
  },

  { "Reverse", rt_offsetof(BD_TractionSystem_Int_BogieControl, Reverse), 3, 0, 0
  },

  { "MotorNotAvailable", rt_offsetof(BD_TractionSystem_Int_BogieControl,
    MotorNotAvailable), 3, 2, 0 },

  { "TractionTorqueAvailable", rt_offsetof(BD_TractionSystem_Int_BogieControl,
    TractionTorqueAvailable), 3, 0, 0 },

  { "DynamicBrakeAvailable", rt_offsetof(BD_TractionSystem_Int_BogieControl,
    DynamicBrakeAvailable), 3, 0, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR_ND, 14, 3, 0 },

  { rtwCAPI_VECTOR, 17, 2, 0 },

  { rtwCAPI_VECTOR, 19, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  8,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  6,                                   /* 6 */
  1,                                   /* 7 */
  1,                                   /* 8 */
  6,                                   /* 9 */
  8,                                   /* 10 */
  2,                                   /* 11 */
  1,                                   /* 12 */
  5,                                   /* 13 */
  5,                                   /* 14 */
  2,                                   /* 15 */
  5,                                   /* 16 */
  1,                                   /* 17 */
  2,                                   /* 18 */
  5,                                   /* 19 */
  1                                    /* 20 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.01, 0.0
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
  { rtBlockSignals, 19,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 260,
    rtModelParameters, 0 },

  { rtBlockStates, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 514669590U,
    3195070820U,
    603474247U,
    762208443U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  TractionSystem_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void TractionSystem_InitializeDataMapInfo(RT_MODEL_TractionSystem_T *const
  TractionSystem_M, B_TractionSystem_c_T *localB)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(TractionSystem_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(TractionSystem_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(TractionSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  TractionSystem_InitializeDataAddr(TractionSystem_M->DataMapInfo.dataAddress,
    localB);
  rtwCAPI_SetDataAddressMap(TractionSystem_M->DataMapInfo.mmi,
    TractionSystem_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  TractionSystem_InitializeVarDimsAddr
    (TractionSystem_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(TractionSystem_M->DataMapInfo.mmi,
    TractionSystem_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(TractionSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(TractionSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  TractionSystem_InitializeLoggingFunctions
    (TractionSystem_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(TractionSystem_M->DataMapInfo.mmi,
    TractionSystem_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(TractionSystem_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(TractionSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(TractionSystem_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void TractionSystem_host_InitializeDataMapInfo
    (TractionSystem_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: TractionSystem_capi.cpp */
