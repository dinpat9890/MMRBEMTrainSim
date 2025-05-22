/*
 * TrainBrakes_capi.cpp
 *
 * Code generation for model "TrainBrakes".
 *
 * Model version              : 1.18
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
#include "TrainBrakes_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "TrainBrakes.h"
#include "TrainBrakes_capi.h"
#include "TrainBrakes_private.h"
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
  { 0, 19, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 1, 18, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing"),
    TARGET_STRING(""), 0, 5, 0, 0, 0 },

  { 2, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce"),
    TARGET_STRING("BrakingForce"), 0, 0, 0, 0, 0 },

  { 3, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce"),
    TARGET_STRING("BrakeShoeForce"), 1, 0, 0, 0, 0 },

  { 4, 12, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce"),
    TARGET_STRING("BrakeShoeTemperature"), 2, 0, 0, 0, 0 },

  { 5, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce"),
    TARGET_STRING("BrakeShoeEfficiency"), 3, 0, 0, 0, 0 },

  { 6, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce"),
    TARGET_STRING("BrakeDiscForce"), 4, 0, 0, 0, 0 },

  { 7, 3, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce"),
    TARGET_STRING("ParkBrakePistonForce"), 0, 0, 0, 0, 0 },

  { 8, 19, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxlePressureDistribution/Selector"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 9, 19, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxlePressureDistribution/Selector1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 10, 19, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 6, 1, 0, 0 },

  { 11, 19, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero1/Compare"),
    TARGET_STRING(""), 0, 6, 1, 0, 0 },

  { 12, 19, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/Bus Assignment"),
    TARGET_STRING("TrainBrakesOut"), 0, 3, 0, 0, 0 },

  { 13, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/Sum1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 3, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce/Max"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 18, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/ConfigCheck/Bus Creator1"),
    TARGET_STRING(""), 0, 5, 0, 0, 0 },

  { 16, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/Gain"),
    TARGET_STRING("BrakeFadePercentage"), 0, 0, 0, 0, 0 },

  { 17, 12, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 15, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionDiscBrake/DiscBrakeNormalForce/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 12, TARGET_STRING(
    "TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/Add"),
    TARGET_STRING("BrakeTemperature"), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 21, TARGET_STRING("TrainBrakes/Initialize/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 22, TARGET_STRING("TrainBrakes/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 23, TARGET_STRING("TrainBrakes/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 24, TARGET_STRING("TrainBrakes/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 25, TARGET_STRING("TrainBrakes/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 26, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/TrainBrakesOut"),
    TARGET_STRING("InitialOutput"), 3, 0, 0 },

  { 27, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxlePressureDistribution/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 28, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxlePressureDistribution/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 29, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 30, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 31, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/BrakesVehicleConfig"),
    TARGET_STRING("InitialOutput"), 5, 0, 0 },

  { 32, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 33, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakeCylinderPistonForce/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 34, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakeCylinderPistonForce/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 35, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakeCylinderPistonForce/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 36, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/BrakingForceAxle_N"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 37, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/BrakeShoeForceAxle_N"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 38, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/BrakeShoeEfficiency"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 39, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/DiscBrakeForceAxle_N"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 40, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce/ParkBrakePistonForce"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 41, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 42, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 43, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 44, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 45, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant3"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 46, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant5"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 47, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant6"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 48, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 49, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("ConvectiveArea"), 0, 0, 0 },

  { 50, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("AmbientTemperature"), 0, 0, 0 },

  { 51, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("AirDensity"), 0, 0, 0 },

  { 52, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("AirThermalConductivity"), 0, 0, 0 },

  { 53, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("AirSpecificHeat"), 0, 0, 0 },

  { 54, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade"),
    TARGET_STRING("AirDynamicViscosity"), 0, 0, 0 },

  { 55, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 56, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/Multiply"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 57, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/ConfigCheck/BrakeShoeFrictionAssert/InvalidZeroOrNegativeFriction"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 58, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 59, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionDiscBrake/DiscBrakeNormalForce/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 60, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionDiscBrake/DiscBrakeNormalForce/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 61, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Default/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 62, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/BrakeTemperature"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 63, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 64, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/StefanBoltzmannSigma"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 65, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 66, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 67, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 68, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/TemperatureBrakeFade/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 69, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/TemperatureBrakeFade/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 70, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/TemperatureBrakeFade/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 71, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/TemperatureBrakeFade/Switch2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 72, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/Detect Change"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 73, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/DiscreteIntegratorWithReset"),
    TARGET_STRING("InitValue"), 0, 0, 0 },

  { 74, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 75, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/OvertemperatureEnergy"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 76, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 77, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/Mean of Non-Zero Elements/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 78, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/Mean of Non-Zero Elements/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 79, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/DiscreteIntegratorWithReset/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 80, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/DiscreteIntegratorWithReset/IC"),
    TARGET_STRING("Value"), 6, 0, 0 },

  { 81, TARGET_STRING("TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/Mean of Non-Zero Elements/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

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
  { 82, -1, TARGET_STRING("TrainBrakes/Initialize/Discrete-Time\nIntegrator"),
    TARGET_STRING(""), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 83, TARGET_STRING("pAtm"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void TrainBrakes_InitializeDataAddr(void* dataAddr[], B_TrainBrakes_c_T
  *localB, DW_TrainBrakes_f_T *localDW)
{
  dataAddr[0] = (void*) (&localB->CoreSubsys[7].TrainBrakesOut);
  dataAddr[1] = (void*) (&localB->CoreSubsys[7].BusCreator1);
  dataAddr[2] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Product);
  dataAddr[3] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Sum1);
  dataAddr[4] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].BrakeTemperature);
  dataAddr[5] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].
    BrakeFadePercentage);
  dataAddr[6] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Saturation);
  dataAddr[7] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Max);
  dataAddr[8] = (void*) (&localB->CoreSubsys[7].Selector[0]);
  dataAddr[9] = (void*) (&localB->CoreSubsys[7].Selector1[0]);
  dataAddr[10] = (void*) (&localB->CoreSubsys[7].Compare[0]);
  dataAddr[11] = (void*) (&localB->CoreSubsys[7].Compare_a[0]);
  dataAddr[12] = (void*) (&localB->CoreSubsys[7].TrainBrakesOut);
  dataAddr[13] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Sum1);
  dataAddr[14] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Max);
  dataAddr[15] = (void*) (&localB->CoreSubsys[7].BusCreator1);
  dataAddr[16] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].
    BrakeFadePercentage);
  dataAddr[17] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].BrakeTemperature);
  dataAddr[18] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Product);
  dataAddr[19] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].Saturation);
  dataAddr[20] = (void*) (&localB->CoreSubsys[7].CoreSubsys[5].BrakeTemperature);
  dataAddr[21] = (void*) (&TrainBrakes_P.Constant_Value);
  dataAddr[22] = (void*) (&TrainBrakes_P.DiscreteTimeIntegrator_gainval);
  dataAddr[23] = (void*) (&TrainBrakes_P.DiscreteTimeIntegrator_IC);
  dataAddr[24] = (void*) (&TrainBrakes_P.DiscreteTimeIntegrator_UpperSat);
  dataAddr[25] = (void*) (&TrainBrakes_P.DiscreteTimeIntegrator_LowerSat);
  dataAddr[26] = (void*) (&TrainBrakes_P.CoreSubsys.TrainBrakesOut_Y0);
  dataAddr[27] = (void*) (&TrainBrakes_P.CoreSubsys.Constant1_Value);
  dataAddr[28] = (void*) (&TrainBrakes_P.CoreSubsys.Constant3_Value);
  dataAddr[29] = (void*) (&TrainBrakes_P.CoreSubsys.Constant_Value_iu);
  dataAddr[30] = (void*) (&TrainBrakes_P.CoreSubsys.Constant_Value_iw);
  dataAddr[31] = (void*) (&TrainBrakes_P.CoreSubsys.BrakesVehicleConfig_Y0);
  dataAddr[32] = (void*) (&TrainBrakes_P.CoreSubsys.Constant_Value);
  dataAddr[33] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant4_Value);
  dataAddr[34] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_i);
  dataAddr[35] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_o);
  dataAddr[36] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakingForceAxle_N_Y0);
  dataAddr[37] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeShoeForceAxle_N_Y0);
  dataAddr[38] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeShoeEfficiency_Y0);
  dataAddr[39] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.DiscBrakeForceAxle_N_Y0);
  dataAddr[40] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.ParkBrakePistonForce_Y0);
  dataAddr[41] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat);
  dataAddr[42] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat);
  dataAddr[43] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Switch_Threshold);
  dataAddr[44] = (void*) (&TrainBrakes_P.CoreSubsys.CompareToConstant2_const);
  dataAddr[45] = (void*) (&TrainBrakes_P.CoreSubsys.CompareToConstant3_const);
  dataAddr[46] = (void*) (&TrainBrakes_P.CoreSubsys.CompareToConstant5_const);
  dataAddr[47] = (void*) (&TrainBrakes_P.CoreSubsys.CompareToConstant6_const);
  dataAddr[48] = (void*) (&TrainBrakes_P.CoreSubsys.Constant_Value_i);
  dataAddr[49] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_ConvectiveArea);
  dataAddr[50] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AmbientTemperature);
  dataAddr[51] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirDensity);
  dataAddr[52] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirThermalConductivity);
  dataAddr[53] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirSpecificHeat);
  dataAddr[54] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirDynamicViscosity);
  dataAddr[55] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Gain_Gain);
  dataAddr[56] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Multiply_Gain);
  dataAddr[57] = (void*)
    (&TrainBrakes_P.CoreSubsys.InvalidZeroOrNegativeFriction_const);
  dataAddr[58] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition_c);
  dataAddr[59] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_e);
  dataAddr[60] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_ar);
  dataAddr[61] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_f);
  dataAddr[62] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeTemperature_Y0);
  dataAddr[63] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_n);
  dataAddr[64] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.StefanBoltzmannSigma_Value);
  dataAddr[65] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_m);
  dataAddr[66] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_a);
  dataAddr[67] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[68] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant1_Value);
  dataAddr[69] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_fq);
  dataAddr[70] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_j);
  dataAddr[71] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Switch2_Threshold);
  dataAddr[72] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.DetectChange_vinit);
  dataAddr[73] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.DiscreteIntegratorWithReset_InitValue);
  dataAddr[74] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_a);
  dataAddr[75] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.OvertemperatureEnergy_Value);
  dataAddr[76] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Switch_Threshold_l);
  dataAddr[77] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_f);
  dataAddr[78] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_b);
  dataAddr[79] = (void*)
    (&TrainBrakes_P.CoreSubsys.CoreSubsys.DiscreteTimeIntegrator_gainval);
  dataAddr[80] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.IC_Value);
  dataAddr[81] = (void*) (&TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value);
  dataAddr[82] = (void*) (&localDW->DiscreteTimeIntegrator_DSTATE);
  dataAddr[83] = (void*) (&TrainBrakes_P.pAtm);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void TrainBrakes_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void TrainBrakes_InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
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
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle_Axle", 7, 1, sizeof
    (BD_TrainBrakes_Out_Vehicle_Axle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle_States", 6, 8, sizeof
    (BD_TrainBrakes_Out_Vehicle_States), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainBrakes_Out_Vehicle", 2, 14, sizeof
    (BD_TrainBrakes_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "numeric", "BrakeShoeCoefficientCalculationMethod", 0, 0, sizeof
    (BrakeShoeCoefficientCalculationMethod), SS_ENUM_TYPE, 0, 0, SS_INT32 },

  { "struct", "BD_TrainBrakes_Cfg_Vehicle", 4, 16, sizeof
    (BD_TrainBrakes_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

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

  { "Axle", rt_offsetof(BD_TrainBrakes_Out_Vehicle, Axle), 1, 1, 0 },

  { "States", rt_offsetof(BD_TrainBrakes_Out_Vehicle, States), 2, 0, 0 },

  { "BrakeShoeCoefficientCalculationMethod", rt_offsetof
    (BD_TrainBrakes_Cfg_Vehicle, BrakeShoeCoefficientCalculationMethod), 4, 0, 0
  },

  { "BrakeShoeFrictionCoeff", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle,
    BrakeShoeFrictionCoeff), 0, 0, 0 },

  { "BrakeFadeEnable", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle, BrakeFadeEnable),
    0, 0, 0 },

  { "BrakeTemperatureEnable", rt_offsetof(BD_TrainBrakes_Cfg_Vehicle,
    BrakeTemperatureEnable), 0, 0, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  6,                                   /* 2 */
  1                                    /* 3 */
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
  { rtBlockSignals, 21,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 61,
    rtModelParameters, 1 },

  { rtBlockStates, 1 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2737881292U,
    13858136U,
    222353724U,
    4294153494U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  TrainBrakes_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void TrainBrakes_InitializeDataMapInfo(RT_MODEL_TrainBrakes_T *const
  TrainBrakes_M, B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T *localDW)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(TrainBrakes_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(TrainBrakes_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(TrainBrakes_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  TrainBrakes_InitializeDataAddr(TrainBrakes_M->DataMapInfo.dataAddress, localB,
    localDW);
  rtwCAPI_SetDataAddressMap(TrainBrakes_M->DataMapInfo.mmi,
    TrainBrakes_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  TrainBrakes_InitializeVarDimsAddr(TrainBrakes_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(TrainBrakes_M->DataMapInfo.mmi,
    TrainBrakes_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(TrainBrakes_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(TrainBrakes_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  TrainBrakes_InitializeLoggingFunctions(TrainBrakes_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(TrainBrakes_M->DataMapInfo.mmi,
    TrainBrakes_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(TrainBrakes_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(TrainBrakes_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(TrainBrakes_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void TrainBrakes_host_InitializeDataMapInfo(TrainBrakes_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: TrainBrakes_capi.cpp */
