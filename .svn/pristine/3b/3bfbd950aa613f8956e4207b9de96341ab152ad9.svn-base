/*
 * DoorSystem_types.h
 *
 * Code generation for model "DoorSystem".
 *
 * Model version              : 1.2208
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DoorSystem_types_h_
#define RTW_HEADER_DoorSystem_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Prm_

typedef struct {
  real_T DoorOpenTime;
  real_T DoorCloseTime;
  real_T DoorOpenAlarmTime;
  real_T DoorCloseAlarmTime;
  real_T DoorOpenDelay;
  real_T DoorCloseDelay;
} BD_DoorSystem_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Cfg_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Cfg_Door_

typedef struct {
  real_T isLeft;
  real_T NumberOfDoors;
} BD_DoorSystem_Cfg_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_InputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_InputControlStates_

typedef struct {
  real_T LocalDoorOpenPB;
  real_T OpenCloseWidget;
  real_T EmergencyAccessDevice;
  real_T EmergencyEgressDevice;
  real_T LocalDoorIsolationLock;
} BD_DoorSystem_In_Door_InputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_ElectricalSignals_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_ElectricalSignals_

typedef struct {
  boolean_T DoorControlPower;
  boolean_T DoorMotorPower;
  boolean_T DoorEnable;
  boolean_T DoorRelease;
  boolean_T DoorOpen;
  boolean_T DoorClose;
  boolean_T DoorEmergencyRelease;
  boolean_T DoorIsolation;
} BD_DoorSystem_In_Door_ElectricalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_Faults_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_Faults_

typedef struct {
  real_T ObjectObstructingDoorWhileClosing;
  real_T ObjectObstructingDoorWhileOpening;
  real_T DoorFailToClose;
  real_T DoorFailToOpen;
  real_T DoorMotorCircuitFailure;
  real_T DoorFailedToLock;
  real_T DoorFailedToUnlock;
  real_T DoorUnexpectedUnlocking;
  real_T DoorDCUFailure;
  real_T DCSRFailure;
  real_T DCSLFailure;
  real_T DLSRFailure;
  real_T DLSLFailure;
  real_T DoorMajorFault;
  real_T DoorUnauthorisedOpen;
  real_T UnexpectedDoorOpeningDetectedByCC;
  real_T EmergencyDoorMechanicalUnlocked;
  real_T DoorEmergencyHandleActivation;
} BD_DoorSystem_In_Door_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Door_

typedef struct {
  BD_DoorSystem_Cfg_Door Config;
  BD_DoorSystem_In_Door_InputControlStates InputControlStates;
  BD_DoorSystem_In_Door_ElectricalSignals ElectricalSignals;
  BD_DoorSystem_In_Door_Faults Faults;
} BD_DoorSystem_In_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Vehicle_

typedef struct {
  BD_DoorSystem_In_Door Doors[8];
} BD_DoorSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Overrides_

typedef struct {
  real_T AllDoorsLeftOpen;
  real_T AllDoorsRightOpen;
} BD_DoorSystem_In_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Emergency_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Emergency_Door_

typedef struct {
  boolean_T RampHandle;
  boolean_T EmergencyDoorHandle;
  real_T DoorWinder;
  real_T RampWinder;
  boolean_T EmerDoorLatched;
  boolean_T EmerDoorOpenFault;
  real_T EmergencyDoorMechanicalUnlocked;
  real_T RampCoverLockingLever;
  boolean_T RampMiddleSupport;
  boolean_T EmergencyDoorGasSpring;
  boolean_T HasCab;
} BD_DoorSystem_In_Emergency_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Int_DoorControlAudio_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Int_DoorControlAudio_

typedef struct {
  real_T DoorOpeningAuthorised;
  real_T DoorOpeningAlarm;
  real_T DoorClosingAlarm;
  real_T DoorEmergencyReleased;
  real_T DoorIsolated;
} BD_DoorSystem_Int_DoorControlAudio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_TCMS_Messages_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_TCMS_Messages_

typedef struct {
  boolean_T DoorOpenObstacleDetected;
  boolean_T DoorCloseObstacleDetected;
  boolean_T DoorFailedToLock;
  boolean_T DoorFailedToUnlock;
  boolean_T DoorMotorFailure;
  boolean_T DoorMajorFault;
  boolean_T DCSRFailure;
  boolean_T DCSLFailure;
  boolean_T DLSRFailure;
  boolean_T DLSLFailure;
  boolean_T DCUFailure;
  boolean_T DoorUnexpectedUnlocking;
  boolean_T DoorIsolatedWire;
  boolean_T DoorEmergencyHandleWire;
  boolean_T UnexpectedDoorOpeningDetectedByCC;
} BD_DoorSystem_Out_Door_TCMS_Messages;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Int_DoorControlIndicators_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Int_DoorControlIndicators_

typedef struct {
  real_T DoorOutsideLamp;
  real_T DoorInsideLamp;
  real_T DoorOpenPBLight;
  real_T DoorClosePBLight;
  boolean_T DoorsFaulty;
  BD_DoorSystem_Out_Door_TCMS_Messages DCUTCMSMessages;
} BD_DoorSystem_Int_DoorControlIndicators;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_ElectricalSignals_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_ElectricalSignals_

typedef struct {
  boolean_T DoorCloseInterlock;
  boolean_T DoorClosed;
} BD_DoorSystem_Out_Door_ElectricalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_OutputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_OutputControlStates_

typedef struct {
  real_T DoorPosition;
  real_T DoorOutsideLamp;
  real_T DoorInsideLamp;
} BD_DoorSystem_Out_Door_OutputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_Audio_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_Audio_

typedef struct {
  real_T DoorOpeningAuthorised;
  real_T DoorOpeningAlarm;
  real_T DoorClosingAlarm;
  real_T DoorEmergencyReleased;
  real_T DoorIsolated;
  real_T DoorClosing;
  real_T DoorOpening;
} BD_DoorSystem_Out_Door_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_TCMS_

typedef struct {
  boolean_T DoorClosedStatus;
  boolean_T DoorOpenStatus;
  boolean_T DoorReleasedAuthorisedToOpenStatus;
  boolean_T DoorEmergencyReleasedStatus;
  boolean_T DoorIsolatedStatus;
  boolean_T DoorFaultStatus;
  boolean_T DoorObstacleDetected;
  boolean_T DoorObstacleUnableToClose;
  boolean_T DoorLockedStatus;
  boolean_T DoorOpenPBLight;
  boolean_T DoorClosedPBLight;
  BD_DoorSystem_Out_Door_TCMS_Messages Messages;
} BD_DoorSystem_Out_Door_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Door_

typedef struct {
  BD_DoorSystem_Out_Door_ElectricalSignals ElectricalSignals;
  BD_DoorSystem_Out_Door_OutputControlStates OutputControlStates;
  BD_DoorSystem_Out_Door_Audio Audio;
  BD_DoorSystem_Out_Door_TCMS TCMS;
} BD_DoorSystem_Out_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Vehicle_ElectricalSignals_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Vehicle_ElectricalSignals_

typedef struct {
  boolean_T TrainDoorInterlockOk;
  boolean_T VehicleDoorInterlockOk;
  boolean_T TrainLeftDoorInterlockOk;
  boolean_T TrainRightDoorInterlockOk;
  boolean_T VehicleLeftDoorInterlockOk;
  boolean_T VehicleRightDoorInterlockOk;
} BD_DoorSystem_Out_Vehicle_ElectricalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Emergency_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Emergency_Door_

typedef struct {
  real_T Ramp;
  real_T EmergencyDoorOpen;
  boolean_T EmergencyDoorLocked;
  real_T GasSpringLocked;
  real_T RampSupportDown;
  real_T LockingLeverUnlockAuth;
  boolean_T EmerDoorOpenFaultMessage;
} BD_DoorSystem_Out_Emergency_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Out_Vehicle_

typedef struct {
  BD_DoorSystem_Out_Vehicle_ElectricalSignals VehicleElectrical;
  BD_DoorSystem_Out_Door Doors[16];
  BD_DoorSystem_Out_Emergency_Door EmergencyDoor;
} BD_DoorSystem_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Vehicle_TrainWires_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Vehicle_TrainWires_

typedef struct {
  boolean_T TrainDoorInterlockOk;
  boolean_T TrainLeftDoorInterlockOk;
  boolean_T TrainRightDoorInterlockOk;
} BD_DoorSystem_In_Vehicle_TrainWires;

#endif

/* Parameters for system: '<S31>/DoorClose' */
typedef struct P_DoorClose_DoorSystem_T_ P_DoorClose_DoorSystem_T;

/* Parameters for system: '<S31>/DoorOpenDelay' */
typedef struct P_DoorOpenDelay_DoorSystem_T_ P_DoorOpenDelay_DoorSystem_T;

/* Parameters for system: '<S50>/If Action Subsystem1' */
typedef struct P_IfActionSubsystem1_DoorSystem_T_
  P_IfActionSubsystem1_DoorSystem_T;

/* Parameters for system: '<S35>/LeadingEdgePulseTunable' */
typedef struct P_LeadingEdgePulseTunable_DoorSystem_T_
  P_LeadingEdgePulseTunable_DoorSystem_T;

/* Parameters for system: '<S9>/DoorSystem' */
typedef struct P_CoreSubsys_DoorSystem_gm_T_ P_CoreSubsys_DoorSystem_gm_T;

/* Parameters for system: '<S4>/ForEachDoor' */
typedef struct P_CoreSubsys_DoorSystem_g_T_ P_CoreSubsys_DoorSystem_g_T;

/* Parameters for system: '<S100>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_DoorSystem_T_
  P_TimerOffDelayNoInit_DoorSystem_T;

/* Parameters for system: '<S5>/For Each Subsystem' */
typedef struct P_CoreSubsys_DoorSystem_gmy0_T_ P_CoreSubsys_DoorSystem_gmy0_T;

/* Parameters for system: '<Root>/DoorSystemPerCar' */
typedef struct P_CoreSubsys_DoorSystem_T_ P_CoreSubsys_DoorSystem_T;

/* Parameters for system: '<S2>/MakeArrayOfBuses' */
typedef struct P_CoreSubsys_DoorSystem_gmy0og_T_
  P_CoreSubsys_DoorSystem_gmy0og_T;

/* Parameters (default storage) */
typedef struct P_DoorSystem_T_ P_DoorSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_DoorSystem_T RT_MODEL_DoorSystem_T;

#endif                                 /* RTW_HEADER_DoorSystem_types_h_ */
