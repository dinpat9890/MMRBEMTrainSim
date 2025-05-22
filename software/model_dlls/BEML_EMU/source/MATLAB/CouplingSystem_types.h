/*
 * CouplingSystem_types.h
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

#ifndef RTW_HEADER_CouplingSystem_types_h_
#define RTW_HEADER_CouplingSystem_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Prm_

typedef struct {
  real_T DummySignal;
} BD_CouplingSystem_Prm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Cfg_Vehicle_

typedef struct {
  real_T Enabled;
  real_T Orientation;
  boolean_T HasCab;
  boolean_T IsFirstVehicle;
  boolean_T IsLastVehicle;
  real_T UnitConnection;
} BD_CouplingSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplerSystem_InterfaceData_
#define DEFINED_TYPEDEF_FOR_BD_CouplerSystem_InterfaceData_

typedef struct {
  real_T CouplerType;
  real_T ReadyToCouple;
  real_T MechanicallyCoupled;
  real_T CouplerBrakeDemand;
  real_T ElectricallyCoupled;
  real_T PneumaticallyCoupled;
  boolean_T RescueModeCondition;
} BD_CouplerSystem_InterfaceData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplerMimic_InterfaceData_
#define DEFINED_TYPEDEF_FOR_BD_CouplerMimic_InterfaceData_

typedef struct {
  real_T Mass;
  real_T Time;
  real_T Position;
  real_T Velocity;
  real_T Acceleration;
  real_T Gradient;
  real_T Radius;
  real_T TractiveForce;
  real_T BrakingForce;
  real_T OtherCouplerForce;
  real_T OtherCouplerForceRate;
} BD_CouplerMimic_InterfaceData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals_

typedef struct {
  real_T End;
  real_T OtherVehicleID;
  real_T OtherVehicleEnd;
  real_T OtherVehicleOrientation;
  real_T Available;
  real_T Separation;
  real_T SeparationRate;
  real_T OurCouplingPosition;
  real_T OtherCouplingPosition;
  real_T CouplingSeparation;
  real_T Interfacing;
  real_T CoupledChainLength;
  real_T MechanicallyCoupled;
  BD_CouplerMimic_InterfaceData Mimic;
} BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_SingleCoupler_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_SingleCoupler_

typedef struct {
  BD_CouplerSystem_InterfaceData CouplingInterface;
  BD_CouplingSystem_In_Vehicle_Coupler_PhysicalSignals CouplingPhysical;
} BD_CouplingSystem_In_Vehicle_SingleCoupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_Coupler_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_Coupler_Dynamics_

typedef struct {
  real_T Force;
  real_T SpringForce;
  real_T DampingForce;
  real_T BuffForce;
  real_T DraftForce;
  real_T ImpactForce;
  real_T Breakage;
  real_T Extension;
  real_T ExtensionRate;
  real_T ExternalCoupling;
  BD_CouplerMimic_InterfaceData Mimic;
} BD_CouplingSystem_In_Vehicle_Coupler_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_In_Vehicle_

typedef struct {
  boolean_T ReleaseCoupler;
  BD_CouplingSystem_In_Vehicle_SingleCoupler Coupler[2];
  BD_CouplingSystem_In_Vehicle_Coupler_Dynamics DynamicsCouplers[2];
} BD_CouplingSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Audio_

typedef struct {
  real_T MechanicalCouple;
  real_T MechanicalUncouple;
} BD_CouplingSystem_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_OutputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_OutputControlStates_

typedef struct {
  real_T MechanicalCouplerState;
  real_T ExternalCoupling;
} BD_CouplingSystem_Out_Vehicle_OutputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals_

typedef struct {
  real_T MechanicalCouplerState;
  real_T PneumaticCouplerState;
  real_T CouplerDamaged;
} BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_SingleCoupler_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_SingleCoupler_

typedef struct {
  BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals PhysicalSignals;
  BD_CouplerSystem_InterfaceData CouplingInterface;
} BD_CouplingSystem_Out_Vehicle_SingleCoupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler_

typedef struct {
  real_T AutoCouple;
  real_T AvailableReady;
  real_T OurCoupled;
  real_T Uncoupled;
  real_T TheirsCoupled;
  real_T BothCoupled;
  real_T CouplerTypeMatched;
  real_T TheirsExtensionRate;
  real_T ModelledTrainCouplerType;
  real_T OtherTrainCouplerType;
} BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_

typedef struct {
  BD_CouplingSystem_Out_Vehicle_SingleCoupler Coupler[2];
} BD_CouplingSystem_Out_Vehicle_Coupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Debug_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Debug_

typedef struct {
  real_T EPVState;
  real_T ElectricalHeadCommand;
  real_T MainResPressureOk;
  real_T PneuUncouplingCommand[2];
  real_T MechUncouplingCommand[2];
  real_T ElectUncouplingCommand[2];
  real_T ElectCouplingCommand[2];
  real_T VehicleOnAnEnd[2];
  real_T CouplerTypesAcrossUnit[2];
  BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler DebugPerCoupler[2];
} BD_CouplingSystem_Out_Vehicle_Debug;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_

typedef struct {
  BD_CouplingSystem_Out_Vehicle_Coupler Couplers;
  BD_CouplingSystem_Out_Vehicle_Audio CouplerAudio;
  BD_CouplingSystem_Out_Vehicle_OutputControlStates OutputControlStates;
  BD_CouplingSystem_Out_Vehicle_Debug Debug;
  BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals PhysicalSignals[2];
  real_T ElectricalTrainConnection;
  real_T ElectricalUnitConnection;
  real_T ElectricalCoupledCabsConnection;
} BD_CouplingSystem_Out_Vehicle;

#endif

/* Parameters for system: '<S25>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_CouplingSystem_T_
  P_TimerOffDelayNoInit_CouplingSystem_T;

/* Parameters for system: '<S4>/PerEachHeadAndTailCouperGeneralCoupling' */
typedef struct P_CoreSubsys_CouplingSystem_g_T_ P_CoreSubsys_CouplingSystem_g_T;

/* Parameters for system: '<Root>/CouplingSystemPerCar' */
typedef struct P_CoreSubsys_CouplingSystem_T_ P_CoreSubsys_CouplingSystem_T;

/* Parameters (default storage) */
typedef struct P_CouplingSystem_T_ P_CouplingSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_CouplingSystem_T RT_MODEL_CouplingSystem_T;

#endif                                 /* RTW_HEADER_CouplingSystem_types_h_ */
