/*
 * TrainDynamics_capi.cpp
 *
 * Code generation for model "TrainDynamics".
 *
 * Model version              : 1.788
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
#include "TrainDynamics_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "TrainDynamics.h"
#include "TrainDynamics_capi.h"
#include "TrainDynamics_private.h"
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
  { 0, 111, TARGET_STRING("TrainDynamics/Unit Delay"),
    TARGET_STRING(""), 0, 3, 1, 0, 0 },

  { 1, 3, TARGET_STRING("TrainDynamics/Configuration/AtomicConfigProcessing"),
    TARGET_STRING(""), 0, 2, 1, 0, 1 },

  { 2, 111, TARGET_STRING("TrainDynamics/Initialize/Data Type Conversion"),
    TARGET_STRING("RunInit"), 0, 2, 0, 0, 0 },

  { 3, 110, TARGET_STRING("TrainDynamics/Train Dynamics/For Each"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  { 4, 3, TARGET_STRING("TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing"),
    TARGET_STRING(""), 0, 2, 1, 0, 1 },

  { 5, 108, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing"),
    TARGET_STRING("Dynamics"), 0, 7, 0, 0, 0 },

  { 6, 3, TARGET_STRING("TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing/Initial Positions"),
    TARGET_STRING(""), 0, 2, 1, 0, 1 },

  { 7, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/Unit Delay1"),
    TARGET_STRING(""), 0, 9, 2, 0, 0 },

  { 8, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/Vector Concatenate"),
    TARGET_STRING(""), 0, 2, 3, 0, 0 },

  { 9, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 10, 30, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force"),
    TARGET_STRING(""), 1, 10, 4, 0, 0 },

  { 11, 108, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Bus Creator1"),
    TARGET_STRING(""), 0, 7, 0, 0, 0 },

  { 12, 75, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 13, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 14, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 1, 2, 0, 0, 0 },

  { 15, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 2, 2, 0, 0, 0 },

  { 16, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 3, 2, 0, 0, 0 },

  { 17, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 4, 2, 0, 0, 0 },

  { 18, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 5, 2, 0, 0, 0 },

  { 19, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 6, 2, 0, 0, 0 },

  { 20, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 7, 2, 0, 0, 0 },

  { 21, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 8, 2, 0, 0, 0 },

  { 22, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 9, 2, 0, 0, 0 },

  { 23, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 10, 2, 0, 0, 0 },

  { 24, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection"),
    TARGET_STRING(""), 11, 2, 0, 0, 0 },

  { 25, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/BackMovingForce"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 26, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/BackVehicleMass"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 27, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSeparation"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 28, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSeparationRate"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 29, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/FrontMovingForce"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 30, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/FrontVehicleMass"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 31, 71, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler"),
    TARGET_STRING(""), 0, 11, 3, 0, 0 },

  { 32, 71, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler"),
    TARGET_STRING(""), 1, 0, 2, 0, 0 },

  { 33, 54, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs"),
    TARGET_STRING(""), 0, 8, 0, 0, 0 },

  { 34, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integrator"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 35, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Net Force/Vector Concatenate"),
    TARGET_STRING(""), 0, 2, 5, 0, 0 },

  { 36, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Net Force/Sum1"),
    TARGET_STRING("NetCouplerForce"), 0, 2, 0, 0, 0 },

  { 37, 88, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar"),
    TARGET_STRING(""), 0, 9, 2, 0, 0 },

  { 38, 88, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar"),
    TARGET_STRING(""), 1, 2, 2, 0, 0 },

  { 39, 75, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/If Action Subsystem1"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 40, 75, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Subsystem"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 41, 75, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Merge"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 42, 69, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/ExternalCouplingLogic"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 43, 67, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled"),
    TARGET_STRING(""), 0, 11, 0, 0, 0 },

  { 44, 54, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/Bus Assignment"),
    TARGET_STRING(""), 0, 8, 0, 0, 0 },

  { 45, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Position/PositionIntegrator"),
    TARGET_STRING("Position"), 0, 2, 0, 0, 0 },

  { 46, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/AxleEnabled/Data Type Conversion"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 47, 15, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Braking Force Per Axle"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 48, 16, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Lateral Friction Force Per Axle"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 49, 17, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Reaction Force Per Axle"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 50, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Add"),
    TARGET_STRING("DrivingForce"), 0, 2, 4, 0, 0 },

  { 51, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Stopping Force/BrakePower"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 52, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Stopping Force/BrakingForce"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 53, 30, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel"),
    TARGET_STRING(""), 1, 10, 4, 0, 0 },

  { 54, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Add"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 55, 109, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Sum of Elements1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 56, 88, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler"),
    TARGET_STRING(""), 0, 9, 2, 0, 0 },

  { 57, 88, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler"),
    TARGET_STRING(""), 1, 2, 2, 0, 0 },

  { 58, 69, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/ExternalCouplingLogic/External1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 59, 67, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/Bus Creator"),
    TARGET_STRING(""), 0, 11, 0, 0, 0 },

  { 60, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled"),
    TARGET_STRING("ForceTransmitted"), 0, 2, 0, 0, 0 },

  { 61, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled"),
    TARGET_STRING("Speed"), 1, 2, 0, 0, 0 },

  { 62, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled"),
    TARGET_STRING("SpeedDelta"), 2, 2, 0, 0, 0 },

  { 63, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled"),
    TARGET_STRING("Spin"), 3, 2, 0, 0, 0 },

  { 64, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled"),
    TARGET_STRING("Skid"), 4, 2, 0, 0, 0 },

  { 65, 18, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/PackWheelOutputs"),
    TARGET_STRING(""), 0, 10, 0, 0, 0 },

  { 66, 45, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/LockedAxle/Assignment"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 67, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("Force"), 0, 2, 0, 0, 0 },

  { 68, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("SpringForce"), 1, 2, 0, 0, 0 },

  { 69, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("DampingForce"), 2, 2, 0, 0, 0 },

  { 70, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("BuffForce"), 3, 2, 0, 0, 0 },

  { 71, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("DraftForce"), 4, 2, 0, 0, 0 },

  { 72, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("ImpactForce"), 5, 2, 0, 0, 0 },

  { 73, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces"),
    TARGET_STRING("Breakage"), 6, 2, 0, 0, 0 },

  { 74, 89, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/HeadANDTailEnable/EnableCouplerForceCalc"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 75, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Data Type Conversion2"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 76, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Data Type Conversion3"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 77, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/VehicleSpeedandDelta"),
    TARGET_STRING("WheelSpeed"), 0, 2, 0, 0, 0 },

  { 78, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Switch5"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 79, 18, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/PackWheelOutputs/Bus Creator"),
    TARGET_STRING(""), 0, 10, 0, 0, 0 },

  { 80, 31, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Dynamic Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 81, 32, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Sanding Dynamic Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 82, 33, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Sanding Static Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 83, 34, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Static Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 84, 40, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Dynamic Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 85, 41, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Sanding Dynamic Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 86, 42, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Sanding Static Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 87, 43, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Static Track Adhesion Variation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 88, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Limit"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 89, 28, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/Product"),
    TARGET_STRING("v"), 0, 2, 0, 0, 0 },

  { 90, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/Data Type Conversion1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 91, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/Gain1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 92, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 93, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 94, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/NotShocking"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 95, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 96, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Merge"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 97, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Spring Force/Gain"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 98, 86, TARGET_STRING(
    "TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SignCheck"),
    TARGET_STRING("CouplerImpactForce"), 0, 2, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 99, TARGET_STRING("TrainDynamics/Unit Delay"),
    TARGET_STRING("InitialCondition"), 3, 0, 0 },

  { 100, TARGET_STRING("TrainDynamics/Initialize/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 101, TARGET_STRING("TrainDynamics/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 102, TARGET_STRING("TrainDynamics/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 103, TARGET_STRING("TrainDynamics/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 2, 0, 0 },

  { 104, TARGET_STRING("TrainDynamics/Initialize/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 2, 0, 0 },

  { 105, TARGET_STRING("TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing/InitialPosition"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 106, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/DynamicsVehicleConfig"),
    TARGET_STRING("InitialOutput"), 7, 0, 0 },

  { 107, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 9, 0, 0 },

  { 108, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Unit Delay"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 109, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/VehicleCouplingDataSelection/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 110, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integrator"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 111, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integrator"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 112, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 2, 0, 0 },

  { 113, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 2, 0, 0 },

  { 114, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 115, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Integral Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 116, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Proportional Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 117, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Saturation1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 118, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain/Saturation1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 119, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 120, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/TotalForceTransmitted"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 121, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel_Out"),
    TARGET_STRING("InitialOutput"), 10, 0, 0 },

  { 122, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 2, 0, 0 },

  { 123, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/g"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 124, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 125, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/sim coordinates"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 126, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /VehicleMass/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 127, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /VehicleMass/Saturation1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 128, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /VehicleMass/Saturation1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 129, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingDynamicFriction/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 130, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingDynamicFriction/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 131, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingFriction/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 132, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingFriction/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 133, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Front/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 134, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Front/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 135, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Trail/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 136, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Trail/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 137, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingLeadIn/Max Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 138, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingLeadIn/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 139, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingRate/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 140, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingRate/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 141, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default LateralFriction/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 142, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default LateralFriction/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 143, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailDynamicFrictionCoeff/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 144, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailDynamicFrictionCoeff/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 145, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedDynamicFrictionCoeff/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 146, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedDynamicFrictionCoeff/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 147, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedStaticFrictionCoeff/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 148, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedStaticFrictionCoeff/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 149, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailStaticFrictionCoeff/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 150, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailStaticFrictionCoeff/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 151, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackDampingRate/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 152, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackDampingRate/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 153, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackLength/Max Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 154, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackLength/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 155, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackSpringRate/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 156, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackSpringRate/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 157, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SpringRate/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 158, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SpringRate/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 159, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/DefaultDampingAdjustmentMass/Min Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 160, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/DefaultDampingAdjustmentMass/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 161, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandDynamicFrictionReduction/Max Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 162, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandDynamicFrictionReduction/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 163, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandStaticFrictionReduction/Max Value"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 164, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandStaticFrictionReduction/Default"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 165, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/MimicModelOut"),
    TARGET_STRING("InitialOutput"), 8, 0, 0 },

  { 166, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10"),
    TARGET_STRING("weights"), 2, 6, 0 },

  { 167, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/Mimic"),
    TARGET_STRING("Value"), 8, 0, 0 },

  { 168, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/TimeAtOutput"),
    TARGET_STRING("WtEt"), 2, 0, 0 },

  { 169, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 2, 0, 0 },

  { 170, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 171, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 172, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 173, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Switch"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 174, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Position/PositionIntegrator"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 175, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity/VelocityIntegrator"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 176, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/AxleEnabled/Max Axles2"),
    TARGET_STRING("Value"), 2, 7, 0 },

  { 177, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/AxleEnabled/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 178, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 179, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Derailment Coefficient/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 180, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Derailment Coefficient/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 181, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Derailment Coefficient/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 182, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 2, 0, 0 },

  { 183, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/DivSafe/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 184, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/DivSafe/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 185, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/ApplyBrakingGain/Constant"),
    TARGET_STRING("Value"), 12, 0, 0 },

  { 186, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag/Constant"),
    TARGET_STRING("Value"), 12, 0, 0 },

  { 187, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 188, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 189, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag/Saturation1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 190, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag/Saturation1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 191, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Davis Drag/Constant"),
    TARGET_STRING("Value"), 12, 0, 0 },

  { 192, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/DetermineLeadCar/NegativeMovement"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 193, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/DetermineLeadCar/PositiveMovement"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 194, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag/Compare To Constant"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 195, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag/Air Density kg//m3"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 196, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag/Constant"),
    TARGET_STRING("Value"), 12, 0, 0 },

  { 197, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 198, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Wheel Related Drag Force Axle Check/NoBearingDrag"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 199, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Wheel Related Drag Force Axle Check/NoLateralDrag"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 200, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/Coupler_Out"),
    TARGET_STRING("InitialOutput"), 9, 0, 0 },

  { 201, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/MechanicallyCoupled"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 202, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/If Action Subsystem1/Constant"),
    TARGET_STRING("Value"), 2, 8, 0 },

  { 203, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Subsystem/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 204, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Subsystem/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 205, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/ExternalCouplingLogic/ExternalCoupling"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 206, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicModelDynamicsOut"),
    TARGET_STRING("InitialOutput"), 11, 0, 0 },

  { 207, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicModelDebugOut"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 208, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/UseMimic"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 209, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Tapped Delay"),
    TARGET_STRING("vinit"), 2, 0, 0 },

  { 210, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 2, 0, 0 },

  { 211, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity/SetVelocity/Compare To Constant1"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 212, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity/SetVelocity/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 213, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/LockedAxle/Locked Axle Index"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 214, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/LockedAxle/Max Axles1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 215, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Wheel Related Drag Force Axle Check/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 216, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/Mimic"),
    TARGET_STRING("Value"), 8, 0, 0 },

  { 217, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/HeadANDTailEnable/HeadANDTailEnabled"),
    TARGET_STRING("Value"), 2, 8, 0 },

  { 218, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicForceSimulation/AccGravity"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 219, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicForceSimulation/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 220, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicForceSimulation/Drag"),
    TARGET_STRING("Coefs"), 2, 9, 0 },

  { 221, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicForceSimulation/Switch"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 222, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/PreviousVelocity"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 223, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/Latch Movement"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 224, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MassLimit"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 225, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MassLimit"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 226, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Weighted Average/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 227, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Weighted Average/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 228, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Axle Longitudinal Force"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 229, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Axle Speed"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 230, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Axle Speed Delta"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 231, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Axle Slipping"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 232, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Axle Skidding"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 233, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 234, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Unit Delay"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 235, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 236, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/PackWheelOutputs/Wheel_Out"),
    TARGET_STRING("InitialOutput"), 10, 0, 0 },

  { 237, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 238, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Switch"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 239, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Switch1"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 240, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 241, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Constant11"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 242, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Constant6"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 243, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Constant9"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 244, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Switch"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 245, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Switch1"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 246, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Switch2"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 247, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Switch3"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 248, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerForce_N"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 249, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/SpringForce_N"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 250, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DampingForce_N"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 251, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/BuffForce_N"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 252, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftForce_N"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 253, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerBreakage"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 254, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Limit"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 255, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Limit"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 256, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/ZeroAcceleration"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 257, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/SafeDivide"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 258, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/SafeDivide"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 259, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/SanityLimit"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 260, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/SanityLimit"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 261, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/PositionCalculation/IntegratedPosition"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 262, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout"),
    TARGET_STRING("UpperSaturationLimit"), 2, 0, 0 },

  { 263, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/ZeroVelocity"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 264, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/IntegratedVelocity"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 265, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/Latch Movement/Latch"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 266, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Ours Is 1"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 267, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Ours Is 1:2"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 268, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Theirs Is 1"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 269, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Theirs Is 1:2"),
    TARGET_STRING("const"), 2, 0, 0 },

  { 270, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Weighted Average/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 271, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/FrictionForce/Friction Force1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 272, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/SnapToZero"),
    TARGET_STRING("threshold"), 2, 0, 0 },

  { 273, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/MomentOfInertia"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 274, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/No AdditionalForce"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 275, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 276, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 277, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 278, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CoupledExtension/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 279, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/S-R Flip-Flop"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 280, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/Gain1"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 281, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 282, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 283, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 284, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 285, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff/Saturation1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 286, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/ExtensionPastSlack/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 287, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/ExtensionPastSlack/Gain1"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 288, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Detect Rise Positive"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 289, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Merge"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 290, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Spring Force/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 291, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/PredictStop/VelocityChange"),
    TARGET_STRING("WtEt"), 2, 0, 0 },

  { 292, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/NoUpdate/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 293, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout/Timer"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 294, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout/Timer"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 295, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 2, 0, 0 },

  { 296, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/CouplerSeparationTransform/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 297, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/CouplerSeparationTransform/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 298, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/MimicDirectionTransform/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 299, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/MimicDirectionTransform/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 300, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Detect Change"),
    TARGET_STRING("vinit"), 2, 0, 0 },

  { 301, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Latch DT"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 302, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 303, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Limit"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 304, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/DifferentialWheelSpeed/IC"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 305, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/DifferentialWheelSpeed/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 2, 0, 0 },

  { 306, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/DifferentialWheelSpeed/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 2, 0, 0 },

  { 307, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/SomeSlip/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 308, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 309, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits/BrakingDeltaLimit"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 310, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits/Gain4"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 311, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits/Switch2"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 312, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits/Switch3"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 313, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CoupledExtension/Compression/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 314, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 315, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/S-R Flip-Flop/Logic"),
    TARGET_STRING("TruthTable"), 0, 10, 0 },

  { 316, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 317, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/NotShocking/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 318, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 319, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 320, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 321, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 322, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide2"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 323, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SafeDivide2"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 324, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/Saturation"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 325, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/Saturation"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 326, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/Saturation1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 327, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/Saturation1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 328, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking/SignCheck"),
    TARGET_STRING("Threshold"), 2, 0, 0 },

  { 329, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 330, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 331, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 2, 0, 0 },

  { 332, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 2, 0, 0 },

  { 333, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 2, 0, 0 },

  { 334, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 2, 0, 0 },

  { 335, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 336, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/PredictStop/StoppedOrSignChange/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 337, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 338, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/DampingRate/Damping Rate with lead in/0 to 1"),
    TARGET_STRING("UpperLimit"), 2, 0, 0 },

  { 339, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/DampingRate/Damping Rate with lead in/0 to 1"),
    TARGET_STRING("LowerLimit"), 2, 0, 0 },

  { 340, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Detect Rise Positive/Positive/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 341, TARGET_STRING("TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

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
  { 342, -1, TARGET_STRING("TrainDynamics/Initialize/Discrete-Time\nIntegrator"),
    TARGET_STRING(""), "", 0, 2, 0, 0, 0, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 343, TARGET_STRING("PRM_TrainDynamics"), 13, 0, 0 },

  { 344, TARGET_STRING("MaxAxles"), 2, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void TrainDynamics_InitializeDataAddr(void* dataAddr[],
  B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T *localDW)
{
  dataAddr[0] = (void*) (&localB->UnitDelay[0]);
  dataAddr[1] = (void*) (&localB->y[0]);
  dataAddr[2] = (void*) (&localB->RunInit);
  dataAddr[3] = (void*) (&localB->ForEach);
  dataAddr[4] = (void*) (&localB->y[0]);
  dataAddr[5] = (void*) (&localB->CoreSubsys_p[7].BusCreator1);
  dataAddr[6] = (void*) (&localB->y[0]);
  dataAddr[7] = (void*) (&localB->CoreSubsys_p[7].UnitDelay1[0]);
  dataAddr[8] = (void*) (&localB->CoreSubsys_p[7].VectorConcatenate_k[0]);
  dataAddr[9] = (void*) (( &localB->CoreSubsys_p[7].VectorConcatenate[0] + 4));
  dataAddr[10] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_Wheel_Out_at_inport_0[0]);
  dataAddr[11] = (void*) (&localB->CoreSubsys_p[7].BusCreator1);
  dataAddr[12] = (void*) (&localB->CoreSubsys_p[7].Merge[0]);
  dataAddr[13] = (void*) (&localB->CoreSubsys_p[7].CouplerSeparation[0]);
  dataAddr[14] = (void*) (( &localB->CoreSubsys_p[7].CouplerSeparation[0] + 1));
  dataAddr[15] = (void*) (&localB->CoreSubsys_p[7].CouplerSeparationRate[0]);
  dataAddr[16] = (void*) (( &localB->CoreSubsys_p[7].CouplerSeparationRate[0] +
    1));
  dataAddr[17] = (void*) (&localB->CoreSubsys_p[7].FrontVehicleMass[0]);
  dataAddr[18] = (void*) (( &localB->CoreSubsys_p[7].FrontVehicleMass[0] + 1));
  dataAddr[19] = (void*) (&localB->CoreSubsys_p[7].BackVehicleMass[0]);
  dataAddr[20] = (void*) (( &localB->CoreSubsys_p[7].BackVehicleMass[0] + 1));
  dataAddr[21] = (void*) (&localB->CoreSubsys_p[7].FrontMovingForce[0]);
  dataAddr[22] = (void*) (( &localB->CoreSubsys_p[7].FrontMovingForce[0] + 1));
  dataAddr[23] = (void*) (&localB->CoreSubsys_p[7].BackMovingForce[0]);
  dataAddr[24] = (void*) (( &localB->CoreSubsys_p[7].BackMovingForce[0] + 1));
  dataAddr[25] = (void*) (&localB->CoreSubsys_p[7].BackMovingForce[0]);
  dataAddr[26] = (void*) (&localB->CoreSubsys_p[7].BackVehicleMass[0]);
  dataAddr[27] = (void*) (&localB->CoreSubsys_p[7].CouplerSeparation[0]);
  dataAddr[28] = (void*) (&localB->CoreSubsys_p[7].CouplerSeparationRate[0]);
  dataAddr[29] = (void*) (&localB->CoreSubsys_p[7].FrontMovingForce[0]);
  dataAddr[30] = (void*) (&localB->CoreSubsys_p[7].FrontVehicleMass[0]);
  dataAddr[31] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0]);
  dataAddr[32] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[0]);
  dataAddr[33] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_i[1].BusAssignment);
  dataAddr[34] = (void*) (&localB->CoreSubsys_p[7].Integrator);
  dataAddr[35] = (void*) (&localB->CoreSubsys_p[7].VectorConcatenate[0]);
  dataAddr[36] = (void*) (&localB->CoreSubsys_p[7].VectorConcatenate[0]);
  dataAddr[37] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0]);
  dataAddr[38] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[0]);
  dataAddr[39] = (void*) (&localB->CoreSubsys_p[7].Merge[0]);
  dataAddr[40] = (void*) (&localB->CoreSubsys_p[7].Merge[0]);
  dataAddr[41] = (void*) (&localB->CoreSubsys_p[7].Merge[0]);
  dataAddr[42] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ix[1].External1);
  dataAddr[43] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ix[1].BusCreator);
  dataAddr[44] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_i[1].BusAssignment);
  dataAddr[45] = (void*) (&localB->CoreSubsys_p[7].Position);
  dataAddr[46] = (void*) (&localB->CoreSubsys_p[7].DataTypeConversion[0]);
  dataAddr[47] = (void*) (&localB->CoreSubsys_p[7].
    sf_BrakingForcePerAxle.ForcePerAxle[0]);
  dataAddr[48] = (void*) (&localB->CoreSubsys_p[7].ForcePerAxle[0]);
  dataAddr[49] = (void*) (&localB->CoreSubsys_p[7].
    sf_ReactionForcePerAxle.ForcePerAxle[0]);
  dataAddr[50] = (void*) (&localB->CoreSubsys_p[7].DrivingForce[0]);
  dataAddr[51] = (void*) (&localB->CoreSubsys_p[7].BrakePower[0]);
  dataAddr[52] = (void*) (&localB->CoreSubsys_p[7].BrakingForce[0]);
  dataAddr[53] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_Wheel_Out_at_inport_0[0]);
  dataAddr[54] = (void*) (&localB->CoreSubsys_p[7].Add[0]);
  dataAddr[55] = (void*) (( &localB->CoreSubsys_p[7].VectorConcatenate[0] + 4));
  dataAddr[56] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0]);
  dataAddr[57] = (void*) (&localB->CoreSubsys_p[7].
    ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[0]);
  dataAddr[58] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ix[1].External1);
  dataAddr[59] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ix[1].BusCreator);
  dataAddr[60] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].Switch5);
  dataAddr[61] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].WheelSpeed);
  dataAddr[62] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].v);
  dataAddr[63] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].
    DataTypeConversion2);
  dataAddr[64] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].
    DataTypeConversion3);
  dataAddr[65] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].BusCreator);
  dataAddr[66] = (void*) (&localB->CoreSubsys_p[7].Assignment[0]);
  dataAddr[67] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Limit);
  dataAddr[68] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Gain);
  dataAddr[69] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Gain1);
  dataAddr[70] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Saturation);
  dataAddr[71] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Saturation1);
  dataAddr[72] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Merge);
  dataAddr[73] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].
    DataTypeConversion1);
  dataAddr[74] = (void*) (&localB->CoreSubsys_p[7].EnableCouplerForceCalc[0]);
  dataAddr[75] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].
    DataTypeConversion2);
  dataAddr[76] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].
    DataTypeConversion3);
  dataAddr[77] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].WheelSpeed);
  dataAddr[78] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].Switch5);
  dataAddr[79] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].BusCreator);
  dataAddr[80] = (void*) (&localB->CoreSubsys_p[7].
    sf_DynamicTrackAdhesionVariation.Output);
  dataAddr[81] = (void*) (&localB->CoreSubsys_p[7].
    sf_SandingDynamicTrackAdhesionVariation.Output);
  dataAddr[82] = (void*) (&localB->CoreSubsys_p[7].
    sf_SandingStaticTrackAdhesionVariation.Output);
  dataAddr[83] = (void*) (&localB->CoreSubsys_p[7].
    sf_StaticTrackAdhesionVariation.Output);
  dataAddr[84] = (void*) (&localB->CoreSubsys_p[7].
    sf_DynamicTrackAdhesionVariation_p.Output);
  dataAddr[85] = (void*) (&localB->CoreSubsys_p[7].
    sf_SandingDynamicTrackAdhesionVariation_c.Output);
  dataAddr[86] = (void*) (&localB->CoreSubsys_p[7].
    sf_SandingStaticTrackAdhesionVariation_m.Output);
  dataAddr[87] = (void*) (&localB->CoreSubsys_p[7].
    sf_StaticTrackAdhesionVariation_j.Output);
  dataAddr[88] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Limit);
  dataAddr[89] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys[5].v);
  dataAddr[90] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].
    DataTypeConversion1);
  dataAddr[91] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Gain1);
  dataAddr[92] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Saturation);
  dataAddr[93] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Saturation1);
  dataAddr[94] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Merge);
  dataAddr[95] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Merge);
  dataAddr[96] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Merge);
  dataAddr[97] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Gain);
  dataAddr[98] = (void*) (&localB->CoreSubsys_p[7].CoreSubsys_ixb[1].Merge);
  dataAddr[99] = (void*) (&TrainDynamics_P.UnitDelay_InitialCondition);
  dataAddr[100] = (void*) (&TrainDynamics_P.Constant_Value);
  dataAddr[101] = (void*) (&TrainDynamics_P.DiscreteTimeIntegrator_gainval);
  dataAddr[102] = (void*) (&TrainDynamics_P.DiscreteTimeIntegrator_IC);
  dataAddr[103] = (void*) (&TrainDynamics_P.DiscreteTimeIntegrator_UpperSat);
  dataAddr[104] = (void*) (&TrainDynamics_P.DiscreteTimeIntegrator_LowerSat);
  dataAddr[105] = (void*) (&TrainDynamics_P.InitialPosition_Y0);
  dataAddr[106] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.DynamicsVehicleConfig_Y0);
  dataAddr[107] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.UnitDelay1_InitialCondition);
  dataAddr[108] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.UnitDelay_InitialCondition);
  dataAddr[109] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value);
  dataAddr[110] = (void*) (&TrainDynamics_P.CoreSubsys_p.Integrator_gainval);
  dataAddr[111] = (void*) (&TrainDynamics_P.CoreSubsys_p.Integrator_IC);
  dataAddr[112] = (void*) (&TrainDynamics_P.CoreSubsys_p.Integrator_UpperSat);
  dataAddr[113] = (void*) (&TrainDynamics_P.CoreSubsys_p.Integrator_LowerSat);
  dataAddr[114] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain_c);
  dataAddr[115] = (void*) (&TrainDynamics_P.CoreSubsys_p.IntegralGain_Gain);
  dataAddr[116] = (void*) (&TrainDynamics_P.CoreSubsys_p.ProportionalGain_Gain);
  dataAddr[117] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_h);
  dataAddr[118] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_d);
  dataAddr[119] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_j);
  dataAddr[120] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.TotalForceTransmitted_Y0);
  dataAddr[121] = (void*) (&TrainDynamics_P.CoreSubsys_p.Wheel_Out_Y0);
  dataAddr[122] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput);
  dataAddr[123] = (void*) (&TrainDynamics_P.CoreSubsys_p.g_Value);
  dataAddr[124] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain_o);
  dataAddr[125] = (void*) (&TrainDynamics_P.CoreSubsys_p.simcoordinates_Gain);
  dataAddr[126] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain_p);
  dataAddr[127] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_n);
  dataAddr[128] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_o);
  dataAddr[129] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_o);
  dataAddr[130] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value);
  dataAddr[131] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_b);
  dataAddr[132] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_f);
  dataAddr[133] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const);
  dataAddr[134] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_o);
  dataAddr[135] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_n);
  dataAddr[136] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_f1);
  dataAddr[137] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxValue_const_l);
  dataAddr[138] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_a);
  dataAddr[139] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_aa);
  dataAddr[140] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_c);
  dataAddr[141] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_d);
  dataAddr[142] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_cj);
  dataAddr[143] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_c);
  dataAddr[144] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_k);
  dataAddr[145] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_i);
  dataAddr[146] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_b);
  dataAddr[147] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_a);
  dataAddr[148] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_l);
  dataAddr[149] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_h);
  dataAddr[150] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_n);
  dataAddr[151] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_bl);
  dataAddr[152] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_h);
  dataAddr[153] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxValue_const);
  dataAddr[154] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_g);
  dataAddr[155] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_l);
  dataAddr[156] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_p);
  dataAddr[157] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_nv);
  dataAddr[158] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_a2);
  dataAddr[159] = (void*) (&TrainDynamics_P.CoreSubsys_p.MinValue_const_aae);
  dataAddr[160] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_pa);
  dataAddr[161] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxValue_const_l1);
  dataAddr[162] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_gb);
  dataAddr[163] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxValue_const_g);
  dataAddr[164] = (void*) (&TrainDynamics_P.CoreSubsys_p.Default_Value_o1);
  dataAddr[165] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.MimicModelOut_Y0);
  dataAddr[166] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.WMAV10_weights[0]);
  dataAddr[167] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Mimic_Value);
  dataAddr[168] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.TimeAtOutput_WtEt);
  dataAddr[169] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput_a);
  dataAddr[170] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_d);
  dataAddr[171] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_i);
  dataAddr[172] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_f);
  dataAddr[173] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch_Threshold_o);
  dataAddr[174] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.PositionIntegrator_gainval);
  dataAddr[175] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.VelocityIntegrator_gainval);
  dataAddr[176] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxAxles2_Value[0]);
  dataAddr[177] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_h);
  dataAddr[178] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain_a);
  dataAddr[179] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain_f);
  dataAddr[180] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_d);
  dataAddr[181] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_b);
  dataAddr[182] = (void*) (&TrainDynamics_P.CoreSubsys_p.TSamp_WtEt);
  dataAddr[183] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_b);
  dataAddr[184] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant1_Value);
  dataAddr[185] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_e);
  dataAddr[186] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_g);
  dataAddr[187] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat);
  dataAddr[188] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat);
  dataAddr[189] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat);
  dataAddr[190] = (void*) (&TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat);
  dataAddr[191] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_gl);
  dataAddr[192] = (void*) (&TrainDynamics_P.CoreSubsys_p.NegativeMovement_const);
  dataAddr[193] = (void*) (&TrainDynamics_P.CoreSubsys_p.PositiveMovement_const);
  dataAddr[194] = (void*) (&TrainDynamics_P.CoreSubsys_p.CompareToConstant_const);
  dataAddr[195] = (void*) (&TrainDynamics_P.CoreSubsys_p.AirDensitykgm3_Value);
  dataAddr[196] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_f);
  dataAddr[197] = (void*) (&TrainDynamics_P.CoreSubsys_p.Gain_Gain);
  dataAddr[198] = (void*) (&TrainDynamics_P.CoreSubsys_p.NoBearingDrag_Value);
  dataAddr[199] = (void*) (&TrainDynamics_P.CoreSubsys_p.NoLateralDrag_Value);
  dataAddr[200] = (void*) (&TrainDynamics_P.CoreSubsys_p.Coupler_Out_Y0);
  dataAddr[201] = (void*) (&TrainDynamics_P.CoreSubsys_p.MechanicallyCoupled_Y0);
  dataAddr[202] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_op[0]);
  dataAddr[203] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_bx);
  dataAddr[204] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant1_Value_k);
  dataAddr[205] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ExternalCoupling_Y0);
  dataAddr[206] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MimicModelDynamicsOut_Y0);
  dataAddr[207] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MimicModelDebugOut_Y0);
  dataAddr[208] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.UseMimic_Value);
  dataAddr[209] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.TappedDelay_vinit);
  dataAddr[210] = (void*) (&TrainDynamics_P.CoreSubsys_p.TSamp_WtEt_h);
  dataAddr[211] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CompareToConstant1_const);
  dataAddr[212] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_n);
  dataAddr[213] = (void*) (&TrainDynamics_P.CoreSubsys_p.LockedAxleIndex_Value);
  dataAddr[214] = (void*) (&TrainDynamics_P.CoreSubsys_p.MaxAxles1_Value[0]);
  dataAddr[215] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_k);
  dataAddr[216] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Mimic_Value);
  dataAddr[217] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.HeadANDTailEnabled_Value[0]);
  dataAddr[218] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.AccGravity_Gain);
  dataAddr[219] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain);
  dataAddr[220] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[0]);
  dataAddr[221] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Switch_Threshold);
  dataAddr[222] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.PreviousVelocity_InitialCondition);
  dataAddr[223] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchMovement_InitialCondition);
  dataAddr[224] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_UpperSat);
  dataAddr[225] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_LowerSat);
  dataAddr[226] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Constant_Value);
  dataAddr[227] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Constant1_Value);
  dataAddr[228] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleLongitudinalForce_Y0);
  dataAddr[229] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSpeed_Y0);
  dataAddr[230] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSpeedDelta_Y0);
  dataAddr[231] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSlipping_Y0);
  dataAddr[232] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSkidding_Y0);
  dataAddr[233] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Gain_Gain);
  dataAddr[234] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[235] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_a);
  dataAddr[236] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Wheel_Out_Y0);
  dataAddr[237] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant_Value_o);
  dataAddr[238] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch_Threshold);
  dataAddr[239] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch1_Threshold);
  dataAddr[240] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant1_Value_i);
  dataAddr[241] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant11_Value);
  dataAddr[242] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant6_Value);
  dataAddr[243] = (void*) (&TrainDynamics_P.CoreSubsys_p.Constant9_Value);
  dataAddr[244] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch_Threshold_a);
  dataAddr[245] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch1_Threshold_h);
  dataAddr[246] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch2_Threshold);
  dataAddr[247] = (void*) (&TrainDynamics_P.CoreSubsys_p.Switch3_Threshold);
  dataAddr[248] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.CouplerForce_N_Y0);
  dataAddr[249] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SpringForce_N_Y0);
  dataAddr[250] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DampingForce_N_Y0);
  dataAddr[251] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.BuffForce_N_Y0);
  dataAddr[252] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DraftForce_N_Y0);
  dataAddr[253] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.CouplerBreakage_Y0);
  dataAddr[254] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_UpperSat);
  dataAddr[255] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_LowerSat);
  dataAddr[256] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ZeroAcceleration_Value);
  dataAddr[257] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_UpperSat);
  dataAddr[258] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_LowerSat);
  dataAddr[259] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_UpperSat);
  dataAddr[260] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_LowerSat);
  dataAddr[261] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.IntegratedPosition_gainval);
  dataAddr[262] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.UpdateTimeout_UpperSaturationLimit);
  dataAddr[263] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ZeroVelocity_Value);
  dataAddr[264] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.IntegratedVelocity_gainval);
  dataAddr[265] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Latch_Threshold);
  dataAddr[266] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.OursIs1_const);
  dataAddr[267] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.OursIs12_const);
  dataAddr[268] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.TheirsIs1_const);
  dataAddr[269] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.TheirsIs12_const);
  dataAddr[270] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Constant_Value_m);
  dataAddr[271] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.FrictionForce1_Value);
  dataAddr[272] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.SnapToZero_threshold);
  dataAddr[273] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.MomentOfInertia_Value);
  dataAddr[274] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.NoAdditionalForce_Value);
  dataAddr[275] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_UpperSat);
  dataAddr[276] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_LowerSat);
  dataAddr[277] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_f);
  dataAddr[278] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant1_Value);
  dataAddr[279] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SRFlipFlop_initial_condition);
  dataAddr[280] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain1_Gain_i);
  dataAddr[281] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_l);
  dataAddr[282] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat_i);
  dataAddr[283] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat_g);
  dataAddr[284] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat_n);
  dataAddr[285] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat_g);
  dataAddr[286] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_f);
  dataAddr[287] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain1_Gain);
  dataAddr[288] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DetectRisePositive_vinit);
  dataAddr[289] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Merge_InitialOutput);
  dataAddr[290] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_a);
  dataAddr[291] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.VelocityChange_WtEt);
  dataAddr[292] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_g);
  dataAddr[293] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_gainval);
  dataAddr[294] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_IC);
  dataAddr[295] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_LowerSat);
  dataAddr[296] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_m4);
  dataAddr[297] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain_j);
  dataAddr[298] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_h);
  dataAddr[299] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain_e);
  dataAddr[300] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.DetectChange_vinit);
  dataAddr[301] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchDT_InitialCondition);
  dataAddr[302] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_m);
  dataAddr[303] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Limit_Threshold);
  dataAddr[304] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.IC_Value);
  dataAddr[305] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition);
  dataAddr[306] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.WeightedSampleTime_WtEt);
  dataAddr[307] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value);
  dataAddr[308] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value_m);
  dataAddr[309] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.BrakingDeltaLimit_Gain);
  dataAddr[310] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Gain4_Gain);
  dataAddr[311] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Switch2_Threshold);
  dataAddr[312] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys.Switch3_Threshold);
  dataAddr[313] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_b);
  dataAddr[314] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_j);
  dataAddr[315] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Logic_table[0]);
  dataAddr[316] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_p);
  dataAddr[317] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value);
  dataAddr[318] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat);
  dataAddr[319] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_LowerSat);
  dataAddr[320] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_UpperSat);
  dataAddr[321] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_LowerSat);
  dataAddr[322] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_UpperSat);
  dataAddr[323] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_LowerSat);
  dataAddr[324] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat);
  dataAddr[325] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat);
  dataAddr[326] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat);
  dataAddr[327] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat);
  dataAddr[328] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SignCheck_Threshold);
  dataAddr[329] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Initialise_Value);
  dataAddr[330] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.OffTime_Value);
  dataAddr[331] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_gainval);
  dataAddr[332] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat);
  dataAddr[333] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat);
  dataAddr[334] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain);
  dataAddr[335] = (void*) (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.IC_Value);
  dataAddr[336] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_i);
  dataAddr[337] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value);
  dataAddr[338] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_UpperSat);
  dataAddr[339] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_LowerSat);
  dataAddr[340] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_o);
  dataAddr[341] = (void*)
    (&TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_h);
  dataAddr[342] = (void*) (&localDW->DiscreteTimeIntegrator_DSTATE);
  dataAddr[343] = (void*) (&TrainDynamics_P.PRM_TrainDynamics);
  dataAddr[344] = (void*) (&TrainDynamics_P.MaxAxles);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void TrainDynamics_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void TrainDynamics_InitializeLoggingFunctions(RTWLoggingFcnPtr
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
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_VehicleCouplingData", 9, 1, sizeof
    (BD_TrainDynamics_VehicleCouplingData), SS_STRUCT, 0, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0, 0 },

  { "numeric", "DragCalculationMethod", 0, 0, sizeof(DragCalculationMethod),
    SS_ENUM_TYPE, 0, 0, SS_INT32 },

  { "struct", "BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients", 6, 10, sizeof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Cfg_Vehicle", 24, 16, sizeof
    (BD_TrainDynamics_Cfg_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplerMimic_InterfaceData", 11, 40, sizeof
    (BD_CouplerMimic_InterfaceData), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Coupler", 11, 51, sizeof
    (BD_TrainDynamics_Out_Coupler), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_Wheel", 9, 62, sizeof
    (BD_TrainDynamics_Out_Vehicle_Wheel), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_CouplerMimic_Out_Dynamics", 6, 71, sizeof
    (BD_CouplerMimic_Out_Dynamics), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Out_Vehicle_Drag", 4, 77, sizeof
    (BD_TrainDynamics_Out_Vehicle_Drag), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_TrainDynamics_Prm", 1, 81, sizeof(BD_TrainDynamics_Prm),
    SS_STRUCT, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "Enabled", rt_offsetof(BD_TrainDynamics_VehicleCouplingData, Enabled), 0, 0,
    0 },

  { "VehicleID", rt_offsetof(BD_TrainDynamics_VehicleCouplingData, VehicleID), 1,
    0, 0 },

  { "HeadPosition", rt_offsetof(BD_TrainDynamics_VehicleCouplingData,
    HeadPosition), 2, 0, 0 },

  { "TailPosition", rt_offsetof(BD_TrainDynamics_VehicleCouplingData,
    TailPosition), 2, 0, 0 },

  { "Velocity", rt_offsetof(BD_TrainDynamics_VehicleCouplingData, Velocity), 2,
    0, 0 },

  { "Mass", rt_offsetof(BD_TrainDynamics_VehicleCouplingData, Mass), 2, 0, 0 },

  { "MovingForce", rt_offsetof(BD_TrainDynamics_VehicleCouplingData, MovingForce),
    2, 0, 0 },

  { "HeadCouplerForce", rt_offsetof(BD_TrainDynamics_VehicleCouplingData,
    HeadCouplerForce), 2, 0, 0 },

  { "TailCouplerForce", rt_offsetof(BD_TrainDynamics_VehicleCouplingData,
    TailCouplerForce), 2, 0, 0 },

  { "DavisCoeffA1", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffA1), 2, 0, 0 },

  { "DavisCoeffA2", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffA2), 2, 0, 0 },

  { "DavisCoeffB1", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffB1), 2, 0, 0 },

  { "DavisCoeffB2", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients,
    DavisCoeffB2), 2, 0, 0 },

  { "DavisCoeffLeadCarC", rt_offsetof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients, DavisCoeffLeadCarC), 2, 0,
    0 },

  { "DavisCoeffTailCarC", rt_offsetof
    (BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients, DavisCoeffTailCarC), 2, 0,
    0 },

  { "AerodynamicDragCoeff_Front", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    AerodynamicDragCoeff_Front), 2, 0, 0 },

  { "AerodynamicDragCoeff_Trail", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    AerodynamicDragCoeff_Trail), 2, 0, 0 },

  { "BearingFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    BearingFrictionCoeff), 2, 0, 0 },

  { "BearingDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    BearingDynamicFrictionCoeff), 2, 0, 0 },

  { "LateralFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    LateralFrictionCoeff), 2, 0, 0 },

  { "RailStaticFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailStaticFrictionCoeff), 2, 0, 0 },

  { "RailDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailDynamicFrictionCoeff), 2, 0, 0 },

  { "RailSandedStaticFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailSandedStaticFrictionCoeff), 2, 0, 0 },

  { "RailSandedDynamicFrictionCoeff", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    RailSandedDynamicFrictionCoeff), 2, 0, 0 },

  { "SpringRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SpringRate), 2, 0, 0
  },

  { "SlackSpringRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SlackSpringRate),
    2, 0, 0 },

  { "DampingRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, DampingRate), 2, 0,
    0 },

  { "SlackDampingRate", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SlackDampingRate), 2, 0, 0 },

  { "EnableDampingAdjustmentByMass", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    EnableDampingAdjustmentByMass), 0, 0, 0 },

  { "DampingAdjustmentDesignMass", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DampingAdjustmentDesignMass), 2, 0, 0 },

  { "SlackLength", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, SlackLength), 2, 0,
    0 },

  { "DampingLeadIn", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, DampingLeadIn), 2,
    0, 0 },

  { "CouplerShockTime", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    CouplerShockTime), 2, 0, 0 },

  { "DragCalculationMethod", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DragCalculationMethod), 5, 0, 0 },

  { "DavisCoefficients", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    DavisCoefficients), 6, 0, 0 },

  { "UseSandFrictionCoeffs", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    UseSandFrictionCoeffs), 2, 0, 0 },

  { "SandStaticFrictionFactor", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SandStaticFrictionFactor), 2, 0, 0 },

  { "SandDynamicFrictionFactor", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle,
    SandDynamicFrictionFactor), 2, 0, 0 },

  { "InitialVelocity", rt_offsetof(BD_TrainDynamics_Cfg_Vehicle, InitialVelocity),
    2, 0, 0 },

  { "Mass", rt_offsetof(BD_CouplerMimic_InterfaceData, Mass), 2, 0, 0 },

  { "Time", rt_offsetof(BD_CouplerMimic_InterfaceData, Time), 2, 0, 0 },

  { "Position", rt_offsetof(BD_CouplerMimic_InterfaceData, Position), 2, 0, 0 },

  { "Velocity", rt_offsetof(BD_CouplerMimic_InterfaceData, Velocity), 2, 0, 0 },

  { "Acceleration", rt_offsetof(BD_CouplerMimic_InterfaceData, Acceleration), 2,
    0, 0 },

  { "Gradient", rt_offsetof(BD_CouplerMimic_InterfaceData, Gradient), 2, 0, 0 },

  { "Radius", rt_offsetof(BD_CouplerMimic_InterfaceData, Radius), 2, 0, 0 },

  { "TractiveForce", rt_offsetof(BD_CouplerMimic_InterfaceData, TractiveForce),
    2, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_CouplerMimic_InterfaceData, BrakingForce), 2,
    0, 0 },

  { "OtherCouplerForce", rt_offsetof(BD_CouplerMimic_InterfaceData,
    OtherCouplerForce), 2, 0, 0 },

  { "OtherCouplerForceRate", rt_offsetof(BD_CouplerMimic_InterfaceData,
    OtherCouplerForceRate), 2, 0, 0 },

  { "Force", rt_offsetof(BD_TrainDynamics_Out_Coupler, Force), 2, 0, 0 },

  { "SpringForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, SpringForce), 2, 0,
    0 },

  { "DampingForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, DampingForce), 2,
    0, 0 },

  { "BuffForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, BuffForce), 2, 0, 0 },

  { "DraftForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, DraftForce), 2, 0, 0
  },

  { "ImpactForce", rt_offsetof(BD_TrainDynamics_Out_Coupler, ImpactForce), 2, 0,
    0 },

  { "Breakage", rt_offsetof(BD_TrainDynamics_Out_Coupler, Breakage), 2, 0, 0 },

  { "Extension", rt_offsetof(BD_TrainDynamics_Out_Coupler, Extension), 2, 0, 0 },

  { "ExtensionRate", rt_offsetof(BD_TrainDynamics_Out_Coupler, ExtensionRate), 2,
    0, 0 },

  { "ExternalCoupling", rt_offsetof(BD_TrainDynamics_Out_Coupler,
    ExternalCoupling), 2, 0, 0 },

  { "Mimic", rt_offsetof(BD_TrainDynamics_Out_Coupler, Mimic), 8, 0, 0 },

  { "ForceTransmitted", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel,
    ForceTransmitted), 2, 0, 0 },

  { "Speed", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Speed), 2, 0, 0 },

  { "SpeedDelta", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, SpeedDelta), 2,
    0, 0 },

  { "Spin", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Spin), 2, 0, 0 },

  { "Skid", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, Skid), 2, 0, 0 },

  { "DrivingForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, DrivingForce),
    2, 0, 0 },

  { "LateralFrictionForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel,
    LateralFrictionForce), 2, 0, 0 },

  { "BrakingForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, BrakingForce),
    2, 0, 0 },

  { "BrakePower", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Wheel, BrakePower), 2,
    0, 0 },

  { "UseMimic", rt_offsetof(BD_CouplerMimic_Out_Dynamics, UseMimic), 2, 0, 0 },

  { "MimicPosition", rt_offsetof(BD_CouplerMimic_Out_Dynamics, MimicPosition), 2,
    0, 0 },

  { "MimicVelocity", rt_offsetof(BD_CouplerMimic_Out_Dynamics, MimicVelocity), 2,
    0, 0 },

  { "MimicMass", rt_offsetof(BD_CouplerMimic_Out_Dynamics, MimicMass), 2, 0, 0 },

  { "MimicMovingForce", rt_offsetof(BD_CouplerMimic_Out_Dynamics,
    MimicMovingForce), 2, 0, 0 },

  { "MimicCouplerForce", rt_offsetof(BD_CouplerMimic_Out_Dynamics,
    MimicCouplerForce), 2, 0, 0 },

  { "AerodynamicDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    AerodynamicDragForce), 2, 0, 0 },

  { "BearingDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    BearingDragForce), 2, 0, 0 },

  { "LateralDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    LateralDragForce), 2, 0, 0 },

  { "AdditionalNonWheelDragForce", rt_offsetof(BD_TrainDynamics_Out_Vehicle_Drag,
    AdditionalNonWheelDragForce), 2, 0, 0 },

  { "SnapToZeroVelocity", rt_offsetof(BD_TrainDynamics_Prm, SnapToZeroVelocity),
    2, 0, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  8,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  2,                                   /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  6,                                   /* 8 */
  1,                                   /* 9 */
  5,                                   /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  10,                                  /* 13 */
  1,                                   /* 14 */
  6,                                   /* 15 */
  1,                                   /* 16 */
  3,                                   /* 17 */
  8,                                   /* 18 */
  2                                    /* 19 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.1
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
    (&rtcapiStoredFloats[1]), 1, 0 },

  { (NULL), (NULL), -1, 0 }
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
  { rtBlockSignals, 99,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 243,
    rtModelParameters, 2 },

  { rtBlockStates, 1 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3639644482U,
    2734056263U,
    2140420951U,
    3341851462U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  TrainDynamics_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void TrainDynamics_InitializeDataMapInfo(RT_MODEL_TrainDynamics_T *const
  TrainDynamics_M, B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T *localDW)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(TrainDynamics_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(TrainDynamics_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(TrainDynamics_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  TrainDynamics_InitializeDataAddr(TrainDynamics_M->DataMapInfo.dataAddress,
    localB, localDW);
  rtwCAPI_SetDataAddressMap(TrainDynamics_M->DataMapInfo.mmi,
    TrainDynamics_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  TrainDynamics_InitializeVarDimsAddr
    (TrainDynamics_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(TrainDynamics_M->DataMapInfo.mmi,
    TrainDynamics_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(TrainDynamics_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(TrainDynamics_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  TrainDynamics_InitializeLoggingFunctions
    (TrainDynamics_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(TrainDynamics_M->DataMapInfo.mmi,
    TrainDynamics_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(TrainDynamics_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(TrainDynamics_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(TrainDynamics_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void TrainDynamics_host_InitializeDataMapInfo(TrainDynamics_host_DataMapInfo_T
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

/* EOF: TrainDynamics_capi.cpp */
