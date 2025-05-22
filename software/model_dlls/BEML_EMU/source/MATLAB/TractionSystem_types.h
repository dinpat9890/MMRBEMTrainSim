/*
 * TractionSystem_types.h
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

#ifndef RTW_HEADER_TractionSystem_types_h_
#define RTW_HEADER_TractionSystem_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Prm_

typedef struct {
  real_T DesignMaxTractionTorque;
  real_T DesignMaxTractionPower;
  real_T DesignTimeToMaxTraction;
  real_T DesignMaxBrakingTorque;
  real_T DesignMaxBrakingPower;
  real_T BrakeFadeRampDownSpeeds[2];
  real_T DesignGearingRatio;
  real_T DesignGearingEfficiency;
  real_T DesignWheelDiameter;
  real_T DesignBogieMotorCount;
  real_T AxleHasMotor[2];
  real_T EmergencyBrakeDeactivatesDynamicBrake;
  real_T WheelSlipProtectionEnable;
  real_T WheelSlideProtectionEnable;
  real_T JerkLimit;
  real_T MaxContinuousSlipBeforeTractionCutout;
  real_T MaxContinuousSlideBeforeBrakeCutout;
} BD_TractionSystem_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasMotors;
} BD_TractionSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie_

typedef struct {
  boolean_T TCUPower;
  boolean_T TractionAuthorisation;
  real_T TractionCutoff;
  real_T DynamicBrakingCutoff;
} BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_ElectricalSystem_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_ElectricalSystem_

typedef struct {
  boolean_T PowerAvailable;
  boolean_T ForwardTW;
  boolean_T ReverseTW;
  boolean_T TractionActiveTW;
  boolean_T NoEmergencyBrakeActiveTW;
  boolean_T VCBState;
  boolean_T ContactorsFailure;
  BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie Bogie[2];
} BD_TractionSystem_In_Vehicle_ElectricalSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_Dynamics_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_Dynamics_Bogie_

typedef struct {
  real_T WheelSlip[2];
  real_T WheelSlide[2];
  real_T WheelSpeed[2];
} BD_TractionSystem_In_Vehicle_Dynamics_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_Dynamics_

typedef struct {
  real_T Velocity;
  BD_TractionSystem_In_Vehicle_Dynamics_Bogie Bogie[2];
} BD_TractionSystem_In_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_TCMS_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_TCMS_Bogie_

typedef struct {
  boolean_T TCMSTractionInhibit;
  real_T TCMSDynamicBrakingInhibit;
  real_T BogieSupportedMass;
  real_T BogieIsolationStatus;
} BD_TractionSystem_In_Vehicle_TCMS_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_TCMS_

typedef struct {
  real_T TCMSTractionCmd;
  real_T TCMSEDBrakingCmd;
  real_T TractiveLosses;
  BD_TractionSystem_In_Vehicle_TCMS_Bogie Bogie[2];
} BD_TractionSystem_In_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Vehicle_

typedef struct {
  BD_TractionSystem_In_Vehicle_ElectricalSystem ElectricalSystem;
  BD_TractionSystem_In_Vehicle_Dynamics Dynamics;
  BD_TractionSystem_In_Vehicle_TCMS TCMS;
} BD_TractionSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Overrides_

typedef struct {
  real_T TractionForceVariation;
  real_T DynamicBrakeForceVariation;
} BD_TractionSystem_In_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Faults_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Faults_Bogie_

typedef struct {
  real_T TractionBogieFaulty;
  real_T DynamicBrakeNotAvailable;
} BD_TractionSystem_In_Faults_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Faults_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_In_Faults_

typedef struct {
  BD_TractionSystem_In_Faults_Bogie Bogie[2];
  real_T PCUFailure;
  real_T CIFailure;
  real_T CIIsolated;
  real_T CIMicroprocessorAbnormal;
  real_T CILocalCommunicationFailure;
  real_T CIGateSignalAbnormal;
  real_T CITCMSCommunicationFailure;
  real_T DCLinkOverVoltageLevel1;
  real_T DCLinkLowVoltageLevel1;
  real_T HeavyWheelSlide;
  real_T HeavyWheelSlip;
  real_T CIAKOpenFailure;
  real_T CIKOpenFailure;
  real_T DerailmentDetectedRightSide;
  real_T BogieDerailed;
  real_T WSPActiveBogie1;
  real_T BECU1FailureAllSpeedSensors;
} BD_TractionSystem_In_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Audio_

typedef struct {
  real_T TractionEDPower;
  real_T WheelAngularVelocity;
} BD_TractionSystem_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie_

typedef struct {
  boolean_T Forward;
  boolean_T Reverse;
  boolean_T BogieNotIsolated;
} BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_ElectricalSystem_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_ElectricalSystem_

typedef struct {
  real_T TractionContactorStatus;
  BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie Bogie[2];
} BD_TractionSystem_Out_Vehicle_ElectricalSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_Bogie_

typedef struct {
  boolean_T TCUStatus;
  boolean_T BogieFaulty;
  boolean_T TractionNotIsolated;
  boolean_T EDBrakeNotIsolated;
  boolean_T TCUSlideDetected;
  boolean_T TCUSlipDetected;
  real_T TractiveEffortAchieved;
  real_T EDBrakingEffortAchieved;
  real_T TractiveEffortPossible;
  real_T EDBrakingEffortPossible;
  real_T TractionPower;
  real_T EDBrakingPower;
  real_T TractivePowerPossible;
  real_T EDBrakingPowerPossible;
  real_T MotorSpeeds[2];
  boolean_T WSPTractionCutout;
  real_T SpeedSensorFault;
} BD_TractionSystem_Out_Vehicle_TCMS_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU_

typedef struct {
  real_T TCU_KStatus;
  real_T TCU_AKStatus;
  real_T FilterVoltage;
} BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCMS_

typedef struct {
  BD_TractionSystem_Out_Vehicle_TCMS_Bogie Bogie[2];
  BD_TractionSystem_Out_Vehicle_TCMS_Trafo_TCU Trafo_TCU;
  real_T VehicleDerailed;
  real_T VehicleBogieDerailed;
} BD_TractionSystem_Out_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_BCU_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_BCU_Bogie_

typedef struct {
  boolean_T TCUWheelSlideControlActive;
  boolean_T EDBrakeStatus;
  real_T EDBrakingEffortAchieved;
  real_T EDBrakingEffortPossible;
} BD_TractionSystem_Out_Vehicle_BCU_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_BCU_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_BCU_

typedef struct {
  BD_TractionSystem_Out_Vehicle_BCU_Bogie Bogie[2];
} BD_TractionSystem_Out_Vehicle_BCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCU_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_TCU_

typedef struct {
  BD_TractionSystem_Out_Vehicle_ElectricalSystem ElectricalSystem;
  BD_TractionSystem_Out_Vehicle_TCMS TCMS;
  BD_TractionSystem_Out_Vehicle_BCU BCU;
} BD_TractionSystem_Out_Vehicle_TCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Dynamics_

typedef struct {
  real_T TractionBrakingForce[6];
  real_T TractionForce[6];
  real_T BrakingForce[6];
} BD_TractionSystem_Out_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_

typedef struct {
  BD_TractionSystem_Out_Vehicle_TCU TractionControl;
  BD_TractionSystem_Out_Vehicle_Dynamics Dynamics;
  BD_TractionSystem_Out_Vehicle_Audio Audio;
} BD_TractionSystem_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_BogieControl_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_BogieControl_

typedef struct {
  real_T TractionDemandPct;
  real_T DynamicBrakeTorqueDemand;
  real_T Powering;
  real_T Braking;
  real_T Forward;
  real_T Reverse;
  real_T MotorNotAvailable[2];
  real_T TractionTorqueAvailable;
  real_T DynamicBrakeAvailable;
} BD_TractionSystem_Int_BogieControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_BogieOutputs_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_BogieOutputs_

typedef struct {
  real_T BogieTractiveEffort;
  real_T BogieDynamicBrakingEffort;
  real_T BogieMaxTractionEffortPossible;
  real_T BogieMaxBrakingEffortPossible;
  real_T BogieTractivePower;
  real_T BogieDynamicBrakingPower;
  real_T BogieMaxTractionPowerPossible;
  real_T BogieMaxBrakingPowerPossible;
  real_T BogieMotorSpeeds[2];
} BD_TractionSystem_Int_BogieOutputs;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Int_Vehicle_Dynamics_

typedef struct {
  real_T AxleTractionBrakingForce[2];
  real_T AxleTractionForce[2];
  real_T AxleBrakingForce[2];
} BD_TractionSystem_Int_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TractionCurveSpecificationType_
#define DEFINED_TYPEDEF_FOR_TractionCurveSpecificationType_

typedef enum {
  TractionCurveSpecificationType_NoType = 0,/* Default value */
  TractionCurveSpecificationType_CurveEquationStatic,
  TractionCurveSpecificationType_CurveEquationDynamic,
  TractionCurveSpecificationType_CurveData,
  TractionCurveSpecificationType_ContourData
} TractionCurveSpecificationType;

#endif

/* Parameters for system: '<S3>/ConfigCheck' */
typedef struct P_CoreSubsys_TractionSystem_T_ P_CoreSubsys_TractionSystem_T;

/* Parameters for system: '<S60>/TimerOnDelay NoInit' */
typedef struct P_TimerOnDelayNoInit_TractionSystem_T_
  P_TimerOnDelayNoInit_TractionSystem_T;

/* Parameters for system: '<S71>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_TractionSystem_T_
  P_TimerOffDelayNoInit_TractionSystem_T;

/* Parameters for system: '<S27>/TractionControl (Per Bogie)' */
typedef struct P_CoreSubsys_TractionSystem_gmy0o_T_
  P_CoreSubsys_TractionSystem_gmy0o_T;

/* Parameters for system: '<S102>/MotorVehicle' */
typedef struct P_CoreSubsys_TractionSystem_gmy0ogc_T_
  P_CoreSubsys_TractionSystem_gmy0ogc_T;

/* Parameters for system: '<S101>/TractionMotor' */
typedef struct P_CoreSubsys_TractionSystem_c_T_ P_CoreSubsys_TractionSystem_c_T;

/* Parameters for system: '<S28>/BogieTractionConverterSystem (Per Bogie)' */
typedef struct P_CoreSubsys_TractionSystem_gmy0og_T_
  P_CoreSubsys_TractionSystem_gmy0og_T;

/* Parameters for system: '<Root>/Traction (Per Vehicle)' */
typedef struct P_CoreSubsys_TractionSystem_g_T_ P_CoreSubsys_TractionSystem_g_T;

/* Parameters (default storage) */
typedef struct P_TractionSystem_T_ P_TractionSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TractionSystem_T RT_MODEL_TractionSystem_T;

#endif                                 /* RTW_HEADER_TractionSystem_types_h_ */
