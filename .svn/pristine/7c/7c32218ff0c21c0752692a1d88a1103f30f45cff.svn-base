/*
 * TrainDynamics_types.h
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

#ifndef RTW_HEADER_TrainDynamics_types_h_
#define RTW_HEADER_TrainDynamics_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Prm_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Prm_

typedef struct {
  real_T SnapToZeroVelocity;
} BD_TrainDynamics_Prm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_SimulatorData_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_SimulatorData_

typedef struct {
  real_T SimulationTime;
} BD_CommonTrain_SimulatorData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VehicleType_
#define DEFINED_TYPEDEF_FOR_VehicleType_

typedef enum {
  VehicleType_NoVehicleType = 0,       /* Default value */
  VehicleType_Motor,
  VehicleType_Trailer
} VehicleType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_Cfg_Vehicle_

typedef struct {
  boolean_T Enabled;
  uint32_T VehicleID;
  VehicleType Type;
  real_T Class;
  real_T Orientation;
  real_T Length;
  real_T Height;
  real_T Width;
  real_T TareMass;
  real_T GrossMass;
  real_T LoadingMass;
  real_T NumberOfAxles;
  real_T NumberOfDrivenAxles;
  real_T NumberOfBrakedAxles;
  real_T WheelDiameter;
} BD_CommonTrain_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DragCalculationMethod_
#define DEFINED_TYPEDEF_FOR_DragCalculationMethod_

typedef enum {
  DragCalculationMethod_Fundamental = 0,/* Default value */
  DragCalculationMethod_Davis,
  DragCalculationMethod_Custom
} DragCalculationMethod;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients_

typedef struct {
  real_T DavisCoeffA1;
  real_T DavisCoeffA2;
  real_T DavisCoeffB1;
  real_T DavisCoeffB2;
  real_T DavisCoeffLeadCarC;
  real_T DavisCoeffTailCarC;
} BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Cfg_Vehicle_

typedef struct {
  real_T AerodynamicDragCoeff_Front;
  real_T AerodynamicDragCoeff_Trail;
  real_T BearingFrictionCoeff;
  real_T BearingDynamicFrictionCoeff;
  real_T LateralFrictionCoeff;
  real_T RailStaticFrictionCoeff;
  real_T RailDynamicFrictionCoeff;
  real_T RailSandedStaticFrictionCoeff;
  real_T RailSandedDynamicFrictionCoeff;
  real_T SpringRate;
  real_T SlackSpringRate;
  real_T DampingRate;
  real_T SlackDampingRate;
  boolean_T EnableDampingAdjustmentByMass;
  real_T DampingAdjustmentDesignMass;
  real_T SlackLength;
  real_T DampingLeadIn;
  real_T CouplerShockTime;
  DragCalculationMethod DragCalculationMethod;
  BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients DavisCoefficients;
  real_T UseSandFrictionCoeffs;
  real_T SandStaticFrictionFactor;
  real_T SandDynamicFrictionFactor;
  real_T InitialVelocity;
} BD_TrainDynamics_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_TrackData_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_TrackData_

typedef struct {
  real_T Gradient;
  real_T Radius;
  real_T Superelevation;
} BD_TrainDynamics_In_Vehicle_TrackData;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Coupler_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Coupler_

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
} BD_TrainDynamics_In_Coupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_CustomDragForces_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_CustomDragForces_

typedef struct {
  real_T AerodynamicDragForce;
  real_T BearingDragForce;
} BD_TrainDynamics_In_Vehicle_CustomDragForces;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_

typedef struct {
  real_T TractionForce[6];
  real_T BrakingForce[6];
  BD_TrainDynamics_In_Vehicle_TrackData TrackData;
  BD_TrainDynamics_In_Coupler Couplers[2];
  BD_TrainDynamics_In_Vehicle_CustomDragForces CustomDragForces;
  real_T NonWheelStoppingForce;
  real_T BogieSupportedMass;
} BD_TrainDynamics_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_Overrides_

typedef struct {
  real_T FreezeDynamics;
  real_T SandingApplied;
  real_T TrackAdhesionVariation;
  real_T LoadingVariation;
  real_T CouplerBreakageLimit;
  boolean_T VelocitySetFlag;
  real_T VelocitySetValue;
  real_T BearingFrictionVariation;
  real_T LateralFrictionVariation;
} BD_TrainDynamics_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_Faults_

typedef struct {
  real_T LockedAxle;
  real_T WheelFlat;
  real_T PoorSanding;
} BD_TrainDynamics_In_Vehicle_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_VehicleCouplingData_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_VehicleCouplingData_

typedef struct {
  boolean_T Enabled;
  uint32_T VehicleID;
  real_T HeadPosition;
  real_T TailPosition;
  real_T Velocity;
  real_T Mass;
  real_T MovingForce;
  real_T HeadCouplerForce;
  real_T TailCouplerForce;
} BD_TrainDynamics_VehicleCouplingData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Coupler_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Coupler_

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
} BD_TrainDynamics_Out_Coupler;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplerMimic_Out_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_CouplerMimic_Out_Dynamics_

typedef struct {
  real_T UseMimic;
  real_T MimicPosition;
  real_T MimicVelocity;
  real_T MimicMass;
  real_T MimicMovingForce;
  real_T MimicCouplerForce;
} BD_CouplerMimic_Out_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Drag_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Drag_

typedef struct {
  real_T AerodynamicDragForce;
  real_T BearingDragForce;
  real_T LateralDragForce;
  real_T AdditionalNonWheelDragForce;
} BD_TrainDynamics_Out_Vehicle_Drag;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Inertia_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Inertia_

typedef struct {
  real_T Position;
  real_T Velocity;
  real_T Acceleration;
  real_T Jerk;
  real_T PositionRear;
  real_T MovingForce;
  real_T Mass;
  real_T LoadingMass;
  real_T BogieSupportedMass;
} BD_TrainDynamics_Out_Vehicle_Inertia;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_TrackGeometry_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_TrackGeometry_

typedef struct {
  real_T GravitationalForce;
  real_T LateralForce;
  real_T LateralAcceleration;
  real_T LateralAccelerationRate;
  real_T RailReactionForce;
  real_T DerailmentCoefficient;
} BD_TrainDynamics_Out_Vehicle_TrackGeometry;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Wheel_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Wheel_

typedef struct {
  real_T ForceTransmitted;
  real_T Speed;
  real_T SpeedDelta;
  real_T Spin;
  real_T Skid;
  real_T DrivingForce;
  real_T LateralFrictionForce;
  real_T BrakingForce;
  real_T BrakePower;
} BD_TrainDynamics_Out_Vehicle_Wheel;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_

typedef struct {
  BD_TrainDynamics_Out_Vehicle_Drag Drag;
  BD_TrainDynamics_Out_Coupler Couplers[2];
  BD_TrainDynamics_Out_Vehicle_Inertia Inertia;
  BD_TrainDynamics_Out_Vehicle_TrackGeometry TrackGeometry;
  BD_TrainDynamics_Out_Vehicle_Wheel Wheel[6];
} BD_TrainDynamics_Out_Vehicle;

#endif

/* Parameters for system: '<S144>/AxleModel' */
typedef struct P_CoreSubsys_TrainDynamics_f_T_ P_CoreSubsys_TrainDynamics_f_T;

/* Parameters for system: '<S13>/UpdateMimicPerCoupler' */
typedef struct P_CoreSubsys_TrainDynamics_fx_T_ P_CoreSubsys_TrainDynamics_fx_T;

/* Parameters for system: '<S55>/MimicModelPerCoupler' */
typedef struct P_CoreSubsys_TrainDynamics_fxp_T_
  P_CoreSubsys_TrainDynamics_fxp_T;

/* Parameters for system: '<S57>/CouplerForcesPerCoupler' */
typedef struct P_CoreSubsys_TrainDynamics_fxp4_T_
  P_CoreSubsys_TrainDynamics_fxp4_T;

/* Parameters for system: '<Root>/Train Dynamics' */
typedef struct P_CoreSubsys_TrainDynamics_g_T_ P_CoreSubsys_TrainDynamics_g_T;

/* Parameters (default storage) */
typedef struct P_TrainDynamics_T_ P_TrainDynamics_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TrainDynamics_T RT_MODEL_TrainDynamics_T;

#endif                                 /* RTW_HEADER_TrainDynamics_types_h_ */
