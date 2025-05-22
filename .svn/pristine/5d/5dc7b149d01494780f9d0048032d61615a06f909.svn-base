/*
 * TCMSSystem_types.h
 *
 * Code generation for model "TCMSSystem".
 *
 * Model version              : 1.2333
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TCMSSystem_types_h_
#define RTW_HEADER_TCMSSystem_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Prm_

typedef struct {
  real_T LoadCompensationMasses[2];
  real_T LoadCompensationPressures[2];
  real_T TractionAccelerationTargets[2];
  real_T BrakingDecelerationTargets[2];
  real_T TractionBrakingDemands[2];
  real_T AW3TractionAccelerationTargets[2];
  real_T AW3BrakingDecelerationTargets[2];
} BD_TCMSSystem_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasCab;
  real_T NumberOfTractionBogies;
  real_T NumberOfBrakingBogies;
  boolean_T IsLastVehicle;
  boolean_T IsFirstVehicle;
  boolean_T IsMCar;
  boolean_T IsTCar;
  boolean_T HasVCB;
} BD_TCMSSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_InputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_InputControlStates_

typedef struct {
  real_T TractionBrakeController;
  real_T HeadLightSwitch;
  real_T ParkBrakeIsolationCockBogie1;
  real_T ParkBrakeIsolationCockBogie2;
  real_T Bogie1IsolationCmd;
  real_T Bogie2IsolationCmd;
  real_T EPIC;
  real_T ASCOEnd1;
  real_T ASCOEnd2;
  real_T ASIsolationCock;
  real_T SR;
  real_T ModeSelector;
  real_T EBPB;
  real_T SafetyCutoutSS;
  real_T MREPICEnd1;
  real_T MREPICEnd2;
  real_T CabSaloonPartitionDoorOpen;
  real_T EmergencyDoorCoverRemoved;
  real_T DoorLoopBypassActive;
  real_T DeadManBypass;
  real_T ControlKey;
  real_T LeftDoor1Lockout;
  real_T LeftDoor2Lockout;
  real_T LeftDoor3Lockout;
  real_T LeftDoor4Lockout;
  real_T RightDoor1Lockout;
  real_T RightDoor2Lockout;
  real_T RightDoor3Lockout;
  real_T RightDoor4Lockout;
  real_T LeftDoor1EED;
  real_T LeftDoor2EED;
  real_T LeftDoor3EED;
  real_T LeftDoor4EED;
  real_T RightDoor1EED;
  real_T RightDoor2EED;
  real_T RightDoor3EED;
  real_T RightDoor4EED;
  real_T RampCoverLockingLever;
  boolean_T HornManuallyIsolated;
  real_T BIC1Inside;
  real_T BIC1Outside;
  real_T BIC2Inside;
  real_T BIC2Outside;
} BD_TCMSSystem_In_Vehicle_InputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie_

typedef struct {
  boolean_T TractionInhibit;
  real_T EDBrakingInhibit;
  real_T EPBrakingInhibit;
} BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DisplayControl_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DisplayControl_

typedef struct {
  real_T TractionPowerLimit;
  real_T EDBrakingPowerLimit;
  real_T EnableTractionPowerLimit;
  real_T EnableEDBrakingPowerLimit;
  real_T MaxTractionAccelerationTargetOverride;
  real_T MaxBrakingDecelerationTargetOverride;
  real_T EnableTractionTargetOverride;
  real_T EnableBrakingTargetOverride;
  BD_TCMSSystem_In_Vehicle_DisplayControl_Bogie BogieControl[2];
  real_T PantographIsolationCommand;
  real_T RightDoorsEmergencyReleaseCommand;
  real_T LeftDoorsEmergencyReleaseCommand;
  real_T DoorRight1DisableCommand;
  real_T DoorLeft1DisableCommand;
  real_T DoorRight2DisableCommand;
  real_T DoorLeft2DisableCommand;
  real_T DoorRight3DisableCommand;
  real_T DoorLeft3DisableCommand;
  real_T DoorRight4DisableCommand;
  real_T DoorLeft4DisableCommand;
  real_T DoorA1IsolateVDUReq;
  real_T DoorA2IsolateVDUReq;
  real_T DoorA3IsolateVDUReq;
  real_T DoorA4IsolateVDUReq;
  real_T DoorB1IsolateVDUReq;
  real_T DoorB2IsolateVDUReq;
  real_T DoorB3IsolateVDUReq;
  real_T DoorB4IsolateVDUReq;
  real_T LVIsolateBCG1;
  real_T LVIsolateBCG2;
  real_T LVCommandPOPB;
  real_T ParkBrakeApplyVDUReq;
  real_T ParkBrakeReleaseVDUReq;
  real_T ParkBrakeBypassVDUReq;
  real_T Bogie1IsolateVDUReq;
  real_T Bogie2IsolateVDUReq;
  real_T HornHigh;
  real_T HornLow;
  real_T HornIsolate;
  real_T TCMSPantoLowerReq;
  real_T TCMSPantoResetReq;
  real_T TCMSPantoRiseReq;
  real_T TCMSReqCtrlVCBNS;
  real_T TCMSVCBResetReq;
  real_T TCMSVCBOpenReq;
  real_T TCMSVCBCloseReq;
  real_T TCMSIsolateCI;
  real_T TCMSIsolatePanto;
  real_T TCMSIsolateVCB;
  real_T TCMSIsolateAPS1;
  real_T TCMSIsolateAPS2;
  real_T ActivateHTE;
  real_T ActivateWashing3Kmph;
  real_T ActivateWashing4Kmph;
  real_T ActivateWashing5Kmph;
  real_T TCMSAPSICBOpen;
  real_T TCMSAPSICBClose;
  real_T TCMSHVAC1Close;
  real_T TCMSHVAC1Open;
  real_T TCMSHVAC2Open;
  real_T TCMSHVAC2Close;
  real_T TCMSFDSCBClose;
  real_T TCMSFDSCBOpen;
  real_T MVMainCompForcing;
  real_T MVMTrBlowersForcingHigh;
  real_T MVMTrBlowersForcingLow;
  real_T MVCompHoursReset;
  real_T TEBEFeedback;
  real_T TCMSHVAC1ResetReq;
  real_T TCMSHVAC2ResetReq;
  real_T TCMSHVAC1IsolateReq;
  real_T TCMSHVAC2IsolateReq;
  real_T TCMSHVACSmokeResetReq;
  real_T TCMSFireAlarmResetReq;
  real_T TCMSFDUResetReq;
  real_T ShuntModeMaxSpeed;
  real_T ShuntModeMinSpeed;
  real_T ATPLowModeMaxSpeed;
  real_T ATPLowModeActivated;
  real_T ShuntModeActivated;
  real_T TCMSWFLIsolationReq;
  real_T TCMSPABORBypassReq;
  real_T HVAC1FireDetectorDisableVDUReq;
  real_T EDBHeatAlarmDisableVDUReq;
  real_T CABSmokeDetectorDisableVDUReq;
  real_T SHDEndCubicleRearRight1DisableVDUReq;
  real_T SHDEndCubicleRearRight2DisableVDUReq;
  real_T SHDEndCubicleRearLeft1DisableVDUReq;
  real_T SHDEndCubicleRearLeft2DisableVDUReq;
  real_T LHDDriverDeskDisableVDUReq;
  real_T LHDCIDisableVDUReq;
  real_T LHDLTJBDisableVDUReq;
  real_T SaloonR1FireDetectorDisableVDUReq;
  real_T SaloonR2FireDetectorDisableVDUReq;
  real_T AuxiliaryDeskFireDetectorDisableVDUReq;
} BD_TCMSSystem_In_Vehicle_DisplayControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Environment_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Environment_

typedef struct {
  real_T RightDoorsEnable;
  real_T LeftDoorsEnable;
  real_T DoorsPairEnable[4];
  real_T LineVoltage;
  real_T OverheadLinePresent;
  real_T NeutralSection;
  real_T VehiclesPassedNS;
  real_T DamagedOHE;
} BD_TCMSSystem_In_Vehicle_Environment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie_

typedef struct {
  real_T BrakeCylinderPressureGauge;
  real_T ParkBrakePressureGauge;
  real_T AirSuspensionLoadPressure;
  real_T EstimatedBogieSupportedMass;
  real_T ServiceBrakeSwitchStatus;
  real_T PrakingBrakeSwitchStatus;
  real_T AirSuspensionSwitchStatus;
  real_T AirSuspensionPressure;
  boolean_T BECU1EmergencyBrakeFailure;
  boolean_T BECU2EmergencyBrakeFailure;
  boolean_T BECU1ServiceBrakeFailure;
  boolean_T BECU1BrakeNotApplied;
  boolean_T BECU1BrakeNotReleased;
  boolean_T BECU1CarLoadPressureLow;
  boolean_T BECU2CarLoadPressureLow;
  boolean_T BECULowRPressure;
  boolean_T AirSuspensionBogie1Deflated;
  boolean_T BECU1LoadPressureLow;
} BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PneumaticsSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PneumaticsSystem_

typedef struct {
  real_T MainReservoirPressureGauge;
  real_T MainReservoirPipePressure;
  real_T PantographPressure;
  BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie Bogie[2];
  real_T BrakeDemandSignalFailure;
  real_T LowMRTractionCutoutSwitch;
} BD_TCMSSystem_In_Vehicle_PneumaticsSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_Door_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_Door_

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
  real_T DoorPosition;
  boolean_T DoorOpenObstruction;
  boolean_T DoorCloseObstruction;
  boolean_T DoorOpenPBLight;
  boolean_T DoorClosedPBLight;
  boolean_T DoorMotorCircuitFailure;
  boolean_T DoorFailedToLock;
  boolean_T DoorFailedToUnlock;
  boolean_T DoorUnexpectedUnlocking;
  boolean_T DCUFailure;
  boolean_T DCSRFailure;
  boolean_T DCSLFailure;
  boolean_T DLSRFailure;
  boolean_T DLSLFailure;
  boolean_T DoorMajorFault;
  boolean_T UnexpectedDoorOpeningDetectedByCC;
} BD_TCMSSystem_In_Vehicle_DoorSystem_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor_

typedef struct {
  boolean_T Ramp;
  boolean_T EmergencyDoorOpen;
  boolean_T EmergencyDoorLocked;
  boolean_T EmerDoorOpenFaultMessage;
} BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DoorSystem_

typedef struct {
  BD_TCMSSystem_In_Vehicle_DoorSystem_Door Doors[16];
  BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor EmergencyDoor;
  boolean_T AllLeftDoorClosed;
  boolean_T AllRightDoorClosed;
} BD_TCMSSystem_In_Vehicle_DoorSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_ElectricalSignals_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_ElectricalSignals_

typedef struct {
  boolean_T TCMSPowerAvailable;
  boolean_T CabActive;
  boolean_T ForwardDirection;
  boolean_T ReverseDirection;
  real_T Speedometer;
  boolean_T ZeroSpeed;
  boolean_T TractionOn;
  boolean_T BrakeOn;
  boolean_T TractionSafe;
  boolean_T AllRightDoorsClosed;
  boolean_T AllLeftDoorsClosed;
  boolean_T ServiceBrakesReleased;
  boolean_T ParkBrakesReleased;
  boolean_T ParkBrakeApplication;
  boolean_T ServiceBrakeApplication;
  boolean_T PantoLowered;
  boolean_T PantoRaised;
  boolean_T PantoPowerDetected;
  boolean_T VCBState;
  boolean_T AK1Status;
  boolean_T AK2Status;
  boolean_T K1Status;
  boolean_T K2Status;
  real_T FilterVoltage;
  boolean_T BCG1Status;
  boolean_T BCG2Status;
  real_T BCGOutputVoltage;
  real_T BatteryVoltage;
  real_T BatteryCurrent;
  real_T BatteryTemperature;
  real_T BCG1OutputCurrent;
  real_T BCG2OutputCurrent;
  boolean_T BrakeTrainLine;
  boolean_T MotorTrainLine;
  boolean_T FSB1Line;
  boolean_T FSB2Line;
  boolean_T EB1Line;
  boolean_T EB2Line;
  real_T LineVoltage;
  boolean_T NoEB;
  boolean_T VCBTripCommand;
  boolean_T MotorPowerAvailable;
  boolean_T LeftDoorRelease;
  boolean_T RightDoorRelease;
  boolean_T LeftDoorOpen;
  boolean_T RightDoorOpen;
  boolean_T LeftDoorClose;
  boolean_T RightDoorClose;
  boolean_T APS1Status;
  boolean_T APS2Status;
  boolean_T APS1Fault;
  boolean_T APS2Fault;
  boolean_T APS1Isolated;
  boolean_T APS2Isolated;
  real_T APS1OutputVoltage;
  real_T APS2OutputVoltage;
  boolean_T HLSwitchStatus;
  real_T MarkerAndTailLight;
  boolean_T FlasherLightStatus;
  boolean_T CallOnLightStatus;
  real_T UTOOrRMLight;
  boolean_T PADPBStatus;
  boolean_T PADRStatus;
  boolean_T PowerONPBPressed;
  boolean_T PowerOFFPBPressed;
  boolean_T TPOR_ON;
  boolean_T TSDR_ON;
  boolean_T LeftDoorOpenCmdInLimpHome;
  boolean_T RightDoorOpenCmdInLimpHome;
  boolean_T LeftDoorEnable;
  boolean_T RightDoorEnable;
  boolean_T LeftHoldDoorClose;
  boolean_T RightHoldDoorClose;
  boolean_T LimpHomeMode;
  boolean_T FwdRevTrainLineMismatchMessage;
  boolean_T LowMRPressureFaultMessage;
  boolean_T BCUPower;
  real_T SaloonLightGroupStatus1;
  real_T SaloonLightGroupStatus2;
  real_T WFLStatus;
  real_T WFLOilLevelStatus;
  real_T WFLPump1Status;
  real_T WFLPump2Status;
  boolean_T BatteryIsolationContactor;
  boolean_T TrainControlContactor;
  boolean_T MainCompressor;
  boolean_T AuxCompressor;
  real_T HVAC1Status;
  real_T HVAC1SetPointTemperature;
  real_T HVAC1IntTemperature;
  real_T HVAC1ExtTemperature;
  boolean_T HVAC1Faulty;
  boolean_T HVAC1Isolated;
  real_T HVAC2Status;
  real_T HVAC2SetPointTemperature;
  real_T HVAC2IntTemperature;
  real_T HVAC2ExtTemperature;
  boolean_T HVAC2Faulty;
  boolean_T HVAC2Isolated;
  real_T NoOfAPSFailed;
  boolean_T PECStatus;
  boolean_T EBbyNonCabEnabled;
  boolean_T EBbyMC;
  boolean_T EBbyBrakeLoop;
  boolean_T EBbyDeadMan;
  boolean_T NoLineVoltage;
  boolean_T D1Power;
  boolean_T EBApplied;
  boolean_T EBbyCC;
  boolean_T EBdueToATCZeroSpeed;
  boolean_T ADDCOSStatus;
  boolean_T ORDCOSStatus;
  boolean_T MRIsolation;
  boolean_T MCBPAGroupStatus;
  boolean_T MCB110VDCGroup;
  boolean_T MCBLightGroup;
  boolean_T MCBLightSaloonGroup;
  boolean_T MCBDoorGroup;
  boolean_T MCBBrakeGroup;
  boolean_T MCBAPSGroup;
  boolean_T MCBTCMSGroup;
  boolean_T MCBSignallingGroup;
  real_T HVACFaults[7];
  real_T WFLFault;
  boolean_T CECBTripped;
  boolean_T UCCBTripped;
  boolean_T PANCBTripped;
  boolean_T ELCB1Tripped;
  boolean_T ELCB2Tripped;
  boolean_T ILCB1Tripped;
  boolean_T ILCB2Tripped;
  boolean_T APSCBTripped;
  boolean_T FDUFailure;
  boolean_T InternalFireAlarmTLActive;
  boolean_T SmokeAlarmCABArea;
  boolean_T HeatAlarmEDB;
  boolean_T FDUStatus;
  boolean_T SFARStatus;
  boolean_T UFARStatus;
  boolean_T BUVDR_Active;
  boolean_T CMCActivationFault;
  boolean_T CMCDeactivationFault;
  boolean_T HMIPower;
  boolean_T ReverseMotionInForwardCommandMessage;
  boolean_T ParkBrakeApplyCommand;
  boolean_T ParkBrakeReleaseCommand;
  real_T UW_VCB;
  real_T PantoDownPBCmd;
  boolean_T DCUPower[8];
  real_T VCBTripByCI;
  real_T CIIsolated;
  real_T BCG1Fault;
  real_T BCG2Fault;
  real_T BCG1Isolated;
  real_T BCG2Isolated;
  real_T BCG1IsolationFailed;
  boolean_T EBbyPB;
  real_T VCBTripByAPS;
  real_T VCBIsolated;
  boolean_T MCDR;
  boolean_T MCDRFaulty;
  boolean_T ObstacleDetected;
  real_T ODDFailure;
  boolean_T MCBHVACGroupTripped;
  real_T Key_Switch_Status;
  real_T VCBI_ACOvercurrent;
  real_T VCBI_KAKContactorCI;
  real_T EmergencyDoorNotOpenStatus;
  real_T DoorProvenLoopOK;
  real_T BrakeLoopCBTripped;
  boolean_T DeadmanBypassStatus;
  boolean_T BLCOSwitchStatus;
  real_T NoOfEPICCutout;
  real_T WFLIsolated;
  real_T RemoteMagnetValve1;
  real_T RemoteMagnetValve2;
} BD_TCMSSystem_In_Vehicle_ElectricalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PantographSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_PantographSystem_

typedef struct {
  real_T PantographPosition;
  boolean_T PantoUpStatus;
  boolean_T PantoDownStatus;
  boolean_T PantoIsolatedStatus;
  boolean_T PantoRising;
  boolean_T PantoLowering;
  boolean_T PantographFault;
  boolean_T PantoADDFaultMessage;
  boolean_T PantoORDFaultMessage;
  boolean_T PantoRaiseFailureMessage;
  boolean_T BrakeLoopADDIntervention;
} BD_TCMSSystem_In_Vehicle_PantographSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie_

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
  boolean_T SpeedSensorFault;
} BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_TractionSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_TractionSystem_

typedef struct {
  BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie Bogie[2];
  boolean_T TCU_KStatus;
  boolean_T TCU_AKStatus;
  real_T FilterVoltage;
  real_T VehicleDerailed;
  real_T TractionForce;
} BD_TCMSSystem_In_Vehicle_TractionSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_CouplingSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_CouplingSystem_

typedef struct {
  real_T UnitConnection;
  real_T TrainConnection;
  real_T TrainsCoupled[2];
  boolean_T RescueModeCondition[2];
} BD_TCMSSystem_In_Vehicle_CouplingSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_CBTC_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_CBTC_

typedef struct {
  real_T LeftDoorOpenRequest;
  real_T RightDoorOpenRequest;
  real_T LeftDoorCloseRequest;
  real_T RightDoorCloseRequest;
  real_T ATOTBDemandPct;
  boolean_T NoServiceBrakeOrder;
  boolean_T ATOTraction;
  boolean_T ATOBraking;
  boolean_T NotImmobilise;
  real_T DriverModeSelection;
  real_T ATCBypassState;
  real_T LeftSideDoorEnable;
  real_T RightSideDoorEnable;
  real_T ATCWakeup;
  real_T RollbackDetected;
  real_T LeftDoorCloseIndicator;
  real_T RightDoorCloseIndicator;
} BD_TCMSSystem_In_Vehicle_CBTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_BrakingSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_BrakingSystem_

typedef struct {
  real_T BrakingForce;
} BD_TCMSSystem_In_Vehicle_BrakingSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DynamicsSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_DynamicsSystem_

typedef struct {
  real_T VehicleSpeed;
} BD_TCMSSystem_In_Vehicle_DynamicsSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_

typedef struct {
  BD_TCMSSystem_In_Vehicle_InputControlStates InputControlStates;
  BD_TCMSSystem_In_Vehicle_DisplayControl DisplayControl;
  BD_TCMSSystem_In_Vehicle_Environment Environment;
  BD_TCMSSystem_In_Vehicle_PneumaticsSystem PneumaticsSystem;
  BD_TCMSSystem_In_Vehicle_DoorSystem DoorSystem;
  BD_TCMSSystem_In_Vehicle_ElectricalSignals ElectricalSignals;
  BD_TCMSSystem_In_Vehicle_PantographSystem PantographSystem;
  BD_TCMSSystem_In_Vehicle_TractionSystem TractionSystem;
  BD_TCMSSystem_In_Vehicle_CouplingSystem CouplingSystem;
  BD_TCMSSystem_In_Vehicle_CBTC CBTC;
  BD_TCMSSystem_In_Vehicle_BrakingSystem BrakingSystem;
  BD_TCMSSystem_In_Vehicle_DynamicsSystem DynamicsSystem;
} BD_TCMSSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Overrides_

typedef struct {
  boolean_T PlaceHolder;
} BD_TCMSSystem_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_Faults_

typedef struct {
  real_T MasterControllerandTrainLineIncongruence;
  boolean_T TCMSDisplayHanged;
  real_T TCMSFailure;
  boolean_T NeutralZoneVCBBackupFunctionActivated;
  real_T CCUCommunicationError;
  real_T UnexpectedDoorOpeningDetectedByCC;
  real_T RIO1Fault;
  real_T RIO1RIO2Fault;
  real_T ERFault;
  real_T TractionCutModeSelectorInATPATOUTO;
  real_T HighTractiveEffortRequired;
  real_T DynamicBrakeCutOut;
  real_T BECUPWRAndBRKCmdAtSameTime;
  real_T BECU2MinorFault;
  real_T BECUMajorFault;
  real_T BECUMajorFaultWired;
} BD_TCMSSystem_In_Vehicle_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Vehicle_

typedef struct {
  real_T WFLFailure;
  real_T ODDFailure;
  real_T ObstacleDetectedRightSide;
  real_T DerailmentDetectedRightSide;
  real_T ShutdownFailureVCBOpening;
  real_T MCBLightGroupSaloonTripped;
  real_T CouplingCircuitNotPowered;
  real_T CabEnablingCircuitBreakerTripped;
  real_T ExteriorLight1CBTripped;
  real_T ExteriorLight2CBTripped;
  real_T InteriorLight1CBTripped;
  real_T InteriorLight2CBTripped;
  real_T CMCContactorActivationFailure;
  real_T CIFailure;
  real_T CIIsolated;
  real_T OHLHighVoltageLevel3;
  real_T OHLLowVoltageLevel2;
  real_T LineConverterOverCurrentLevel2;
  real_T DCLinkOverVoltageLevel1;
  real_T DCLinkLowVoltageLevel1;
  real_T LineConverterIGBTFailure;
  real_T DC110VLowVoltage;
  real_T CIMicroprocessorAbnormal;
  real_T CILocalCommunicationFailure;
  real_T OverTemperatureOfInverterPowerUnit;
  real_T OverTemperatureOfConverterPowerUnit;
  real_T AKOpenFailure;
  real_T KOpenFailure;
  real_T MainCircuitEarthFaultLevel2;
  real_T HeavyWheelSlip;
  real_T BrakeDemandSignalFailure;
  real_T CIGateSignalAbnormal;
  real_T CITCMSCommunicationFailure;
  real_T VCBOpenedByCI;
  real_T PantographDownForADDIntervention;
  real_T PantographDownForORDIntervention;
  real_T PantographDownForBUVDRIntervention;
  real_T PantographCircuitNotEnergized;
  real_T PantographPipeLowPressure;
  real_T TransformerOilPressureTooLow;
  real_T TransformerOilTemperatureTooHigh;
  real_T VCBOpenedByACOvercurrent;
  real_T VCBOpenedByMTrProtection;
  real_T VCBOpenedByAPS;
  real_T PantographRaiseFailure;
  real_T PantographLoweringFailure;
  real_T CMCContactorDeactivationFailure;
  real_T MCB110VDCGroupTripped;
  real_T MechanicalCouplerRelayFault;
  real_T MasterControllerandTrainLineIncongruence;
  real_T BatteryFuseBlown;
  real_T BICContactorActivationFault;
  real_T LowBatteryVoltageAlarm;
  real_T MCBLightGroupTripped;
  real_T BECU1MissingOnSegment;
  real_T DLSLFailure;
  real_T DCSRFailure;
  real_T APSGroup1Failure;
  real_T APSGroup1Isolated;
  real_T MCBHVACGroupTripped;
  real_T HVAC1MajorFault;
  real_T HVAC1SupplyFanMPCBTrip;
  real_T HVAC1EmergencyInverterTrip;
  real_T HVAC1RCCBTrip;
  real_T HVAC1FireMode;
  real_T HVAC1ExternalSmokeMode;
  real_T HVAC1ReducedMode;
  real_T BCGGroup1Failure;
  real_T BCGGroup1IsolationFailure;
  real_T BCGGroup1Isolated;
  real_T MCBSignalingGroupTripped;
  real_T TrainRadioFailure;
  real_T PEA2AlarmActive;
  real_T PEA2Failure;
  real_T PEA3Failure;
  real_T SCU2Failure;
  real_T MCBDoorGroupTripped;
  real_T EmergencyDoorMechanicalUnlocked;
  real_T BECU1FailureAllSpeedSensors;
  real_T BECU1LoadPressureLow;
  real_T DoorMajorFault;
  real_T DoorDCUFailure;
  real_T DoorMotorCircuitFailure;
  real_T BECU1CarLoadPressureLow;
  real_T DCSLFailure;
  real_T DoorUnexpectedUnlocking;
  real_T DoorFailedToLock;
  real_T BECU1BrakeNotApplied;
  real_T DoorCloseObstruction;
  real_T DoorOpenObstruction;
  real_T DoorFailedToUnlock;
  real_T BECU2MinorFault;
  real_T BECUMajorFault;
  real_T BECUMajorFaultWired;
  real_T BECUPWRAndBRKCmdAtSameTime;
  real_T MCBAPSGroupTripped;
  real_T BECU1BrakeNotReleased;
  real_T BECULowRPressure;
  real_T BECU2AxleLockedWheelSet2;
  real_T TransformerOilLevelTooLow;
  real_T PantographRisingMissing;
  real_T PantographLoweringMissing;
  real_T PantographRisingInhibited;
  real_T VCBMissingClosing;
  real_T VCBMissingOpening;
  real_T FailureOfTrainborneATCEquipment;
  real_T DMIFailure;
  real_T TrainDoorsNotOpeningInATOMode;
  real_T APSCircuitBreakerTripped;
  real_T CCTVDisplayHanged;
  real_T HeadlightFailure;
  real_T HornBlowsContinuously;
  real_T EBNotReleased;
  real_T TrainDoorLockedClosedRelayFailure;
  real_T EmergencyBrakePBOP1NotWorking;
  real_T AllDoorCloseIndicatorNotWorking;
  real_T DoorClosePBOP1NotWorking;
  real_T DoorCloseAnnouncementPBNotWorking;
  real_T LineVoltageIndicatorNotWorking;
  real_T SmokeAlarmCABArea;
  real_T HeatAlarmEDB;
  real_T PEA1AlarmActive;
  real_T PEA1CallNotAcknowledged;
  real_T PEA1Failure;
  real_T PCUFailure;
  real_T MCBPAGroupOpen;
  real_T TrainDoorNotClosingAtPlatform;
  real_T DM1A1DoorNotOpeningAtPlatform;
  real_T WipersNotWorking;
  real_T CCDetectDetrainmentDoorOpen;
  real_T BECU1AxleLockedWheelSet1;
  real_T BECU1ServiceBrakeFailure;
  real_T BECU1EmergencyBrakeFailure;
  real_T AirSuspensionBogie1Deflated;
  real_T WSPActiveBogie1;
  real_T MCBBrakeGroupTripped;
  real_T ParkingBrakeApplicationFailure;
  real_T ParkingBrakeReleaseFailure;
  real_T CommunicationErrorRIO1RIO2;
  real_T MCBTCMSGroupTripped;
  real_T ER1MajorFault;
  real_T FloodLightNotWorking;
  real_T HornIsolatedByVDU;
  real_T DLSRFailure;
  real_T BECU2CarLoadPressureLow;
  real_T BECU2EmergencyBrakeFailure;
  real_T OtherCabOccupiedIndicatorFaulty;
  real_T EDNORDeactivatedInRunningTrain;
  real_T PressureGuageNotWorking;
  real_T RIOMastershipError;
  real_T TransformerOilLevelLow;
  real_T TransformerOilFlowWarning;
  real_T TransformerOilPressureWarning;
  real_T TransformerOilTemperatureHigh;
  real_T UnexpectedDoorOpeningDetectedByCC;
  real_T EmergencyBrakeDueToEBPB;
  real_T EmergencyBrakeDueDeadman;
  real_T DoorEmergencyHandleActivation;
  real_T BogieDerailed;
} BD_SimIntegration_Faults_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBUnitSum_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBUnitSum_

typedef struct {
  real_T TractionBogiesEquipped;
  real_T BrakingBogiesEquipped;
  real_T TractiveEffortAchieved;
  real_T EDBrakingEffortAchieved;
  real_T TractiveEffortPossible;
  real_T EDBrakingEffortPossible;
  real_T TractivePowerAchieved;
  real_T EDBrakingPowerAchieved;
  real_T TractivePowerPossible;
  real_T EDBrakingPowerPossible;
  real_T EstimatedMass;
  real_T TractionBogiesAvailable;
  real_T EDBrakingBogiesAvailable;
} BD_TCMSSystem_Wires_TBUnitSum;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBTrainWire_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBTrainWire_

typedef struct {
  real_T TractionPowerLimit;
  real_T EDBrakingPowerLimit;
  real_T EnableTractionPowerLimit;
  real_T EnableEDBrakingPowerLimit;
  real_T MaxTractionAccelerationTargetOverride;
  real_T MaxBrakingDecelerationTargetOverride;
  real_T EnableTractionTargetOverride;
  real_T EnableBrakingTargetOverride;
  real_T TractionCommand;
  real_T BrakingCommand;
  real_T HoldingBrakeStatus;
  real_T TCMSSpeedLimit;
  real_T Overspeed;
  real_T EstimatedMass;
  real_T HTERequired;
  real_T WashModeActive;
  real_T TractionForce;
  real_T ShuntModeActive;
  real_T ATPLowSpeedCutoutModeActive;
} BD_TCMSSystem_Wires_TBTrainWire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_DoorsTrainWire_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_DoorsTrainWire_

typedef struct {
  real_T LeftDoorOpenRequest;
  real_T RightDoorOpenRequest;
  real_T LeftDoorCloseRequest;
  real_T RightDoorCloseRequest;
} BD_TCMSSystem_Wires_DoorsTrainWire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_PneumaticTrainSum_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_PneumaticTrainSum_

typedef struct {
  real_T NoOfBogieIsolated;
  real_T NoOfBrakesIsolated;
  real_T NoOfRPressCutout;
  real_T NoOfEPICCutout;
} BD_TCMSSystem_Wires_PneumaticTrainSum;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_ElectricalTrainSum_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_ElectricalTrainSum_

typedef struct {
  real_T ControlKey;
} BD_TCMSSystem_Wires_ElectricalTrainSum;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_ElectricalTrainWire_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_ElectricalTrainWire_

typedef struct {
  real_T TW_EnergizeTLWRFb;
  real_T TW_RMF_RMRFb;
  real_T TW_ATPFb;
  real_T TW_PantoDownCmdTrip;
  real_T TW_TPOR;
  real_T TW_POFFPB;
  real_T TW_TSDR;
  real_T TW_TSDDR;
  real_T TW_ForwardDirection;
  real_T TW_ReverseDirection;
  real_T TW_HLSwitchStatus;
  real_T TW_EmerDoorOpened;
  real_T TW_CallOnLightStatus;
  real_T TW_ZeroSpeed;
  real_T TW_UTOModeActive;
  real_T TW_DriverModeSelection;
  real_T TW_KeySwitchStatus;
  real_T TW_ShutdownFailure;
} BD_TCMSSystem_Wires_ElectricalTrainWire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBUnitWire_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_TBUnitWire_

typedef struct {
  real_T PropulsionIsolated;
  real_T PropulsionFault;
  real_T PropulsionActive;
  real_T PropulsionEnabled;
  real_T CI_K_AK_Status;
} BD_TCMSSystem_Wires_TBUnitWire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Wires_

typedef struct {
  BD_TCMSSystem_Wires_TBUnitSum TractionBrakingUnitSum;
  BD_TCMSSystem_Wires_TBTrainWire TractionBrakingTrainWire;
  BD_TCMSSystem_Wires_DoorsTrainWire DoorsTrainWire;
  BD_TCMSSystem_Wires_ElectricalTrainWire ElectricalTrainWire;
  BD_TCMSSystem_Wires_TBUnitWire TractionBrakingUnitWire;
  BD_TCMSSystem_Wires_PneumaticTrainSum PneumaticTrainSum;
  BD_TCMSSystem_Wires_ElectricalTrainSum ElectricalTrainSum;
} BD_TCMSSystem_Wires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_DoorSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_DoorSystem_

typedef struct {
  boolean_T RightDoorEmergencyRelease;
  boolean_T LeftDoorEmergencyRelease;
  boolean_T DoorRight1Isolation;
  boolean_T DoorLeft1Isolation;
  boolean_T DoorRight2Isolation;
  boolean_T DoorLeft2Isolation;
  boolean_T DoorRight3Isolation;
  boolean_T DoorLeft3Isolation;
  boolean_T DoorRight4Isolation;
  boolean_T DoorLeft4Isolation;
  boolean_T LeftSideDoorOpenRequest;
  boolean_T LeftSideDoorCloseRequest;
  boolean_T RightSideDoorOpenRequest;
  boolean_T RightSideDoorCloseRequest;
  boolean_T LeftSideDoorRelease;
  boolean_T RightSideDoorRelease;
} BD_TCMSSystem_Out_Vehicle_Control_DoorSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_PantographSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_PantographSystem_

typedef struct {
  boolean_T PantoIsolationCommand;
} BD_TCMSSystem_Out_Vehicle_Control_PantographSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie_

typedef struct {
  real_T EPBrakingDemand;
  boolean_T TractionInhibit;
  real_T EDBrakingInhibit;
  real_T EPBrakingInhibit;
  real_T BogieSupportedMass;
  real_T BogieIsolationStatus;
} BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_

typedef struct {
  real_T PWRandBRKBothApplied;
  real_T TractionCutModeSelectorInATPATOUTO;
  real_T BECUFaulty;
  real_T TractionCommand;
  real_T EDBrakingCommand;
  real_T HTERequired;
  real_T VehicleDerailed;
  real_T TCMSIsolateCI;
  real_T CIIsolated;
  BD_TCMSSystem_Out_Vehicle_Control_TractionBraking_Bogie Bogie[2];
  boolean_T SpeedSensorFault;
  real_T TCMSSpeedLimit;
  real_T TCMSSpeedLimitCause;
  real_T BECU1AxleLockedWheelSet1;
  real_T BECU2AxleLockedWheelSet2;
} BD_TCMSSystem_Out_Vehicle_Control_TractionBraking;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem_

typedef struct {
  real_T Overspeed;
  boolean_T EnergizeTLWR;
  boolean_T EnergizeTLRR;
  boolean_T EnergizeHLHBR;
  boolean_T EnergizeHLLBR;
  boolean_T EnergizeFLR;
  boolean_T EnergizeFLDR;
  boolean_T EnergizeUTO;
  boolean_T EnergizeRM;
  boolean_T EnergizeCOLR;
  boolean_T PantoDownCmdTrip;
  boolean_T PantoMVSet;
  real_T NeutralSection;
  boolean_T RecloseAfterNeutralSection;
  boolean_T TCMS_TPOR;
  boolean_T TCMS_TSDR;
  boolean_T TCMS_VCBClose;
  boolean_T TCMS_VCBOpen;
  boolean_T TCMS_PBR;
  boolean_T LeftDoorAuth_Closed;
  boolean_T LeftDoorAuth_Opened;
  boolean_T RightDoorAuth_Closed;
  boolean_T RightDoorAuth_Opened;
  boolean_T TCMSIsolateBCG1;
  boolean_T TCMSIsolateBCG2;
  real_T ParkBrakeApplyVDUReq;
  real_T ParkBrakeBypassVDUReq;
  real_T Bogie1IsolateVDUReq;
  real_T Bogie2IsolateVDUReq;
  boolean_T RightDoorAuth_Opened_Op2_5;
  boolean_T LeftDoorAuth_Opened_Op2_5;
  real_T HornHighVDUReq;
  real_T HornLowVDUReq;
  real_T HornIsolateReinstateVDUReq;
  real_T NeutralZoneBackupModeActive;
  real_T BatteryLowFault;
  boolean_T BUVDR_Active;
  boolean_T CMCActivationFault;
  boolean_T CMCDeactivationFault;
  real_T OHLHighVoltageLevel3;
  real_T OHLLowVoltageLevel2;
  boolean_T VCBOpenedByCI;
  boolean_T VCBOpenedByACOvercurrent;
  boolean_T VCBOpenedByMTrProtection;
  boolean_T VCBOpenedByAPS;
  real_T DCLinkOverVoltageLevel1;
  real_T DCLinkLowVoltageLevel1;
  real_T BICContactorActivationFault;
  real_T ShutdownFailureVCBNotOpening;
  real_T PantographRisingMissing;
  real_T PantographLoweringMissing;
  real_T PantographRisingInhibited;
  real_T PantographLoweringFailure;
  real_T AKOpenFailure;
  real_T KOpenFailure;
  real_T TCMSIsolatePanto;
  real_T TCMSIsolateVCB;
  real_T TCMSIsolateAPS1;
  real_T TCMSIsolateAPS2;
  real_T VCBMissingClosing;
  real_T VCBMissingOpening;
  real_T FwdRevTrainLineMismatchMessage;
  real_T LowMRPressureFaultMessage;
  real_T DeadmanBypass;
  real_T ADDCOSStatus;
  real_T ORDCOSStatus;
  real_T AirSupplyIC;
  real_T MCBPAGroupStatus;
  real_T MCB110VDCGroup;
  real_T MCBLightGroup;
  real_T MCBLightSaloonGroup;
  real_T MCBDoorGroup;
  real_T MCBBrakeGroup;
  real_T MCBAPSGroup;
  real_T MCBTCMSGroup;
  real_T MCBSignallingGroup;
  real_T DoubleCabKeyInsertion;
  real_T CabEnableNotEnergized;
  real_T CouplingCircuitNotEnergized;
  real_T PantoCircuitNotEnergized;
  real_T ExternalLightCB1Tripped;
  real_T ExternalLightCB2Tripped;
  real_T InternalLightCB1Tripped;
  real_T InternalLightCB2Tripped;
  real_T APSCBTripped;
  real_T ReverseMotionInForwardCommandMessage;
  real_T MCDRFaulty;
  real_T ObstacleDetected;
  real_T ODDFailure;
  real_T VehiclesPassedNS;
  real_T TW_TSDDR;
  real_T TrainInNeutralSection;
  boolean_T LeftDoorAuth_OpenedOP1;
  boolean_T RightDoorAuth_OpenedOP1;
  real_T TCMSCompressorCmd;
  real_T TCMSFireAlarmReset;
  real_T TCMSFDUReset;
  real_T TCMSHVACSmokeReset;
  real_T TCMSIsolateHVAC1;
  real_T TCMSIsolateHVAC2;
  real_T TCMSResetHVAC1;
  real_T TCMSResetHVAC2;
  real_T TCMSAPSCBTripCmd;
  real_T TCMSFDSCBTripCmd;
  real_T TCMSHVAC1CBTripCmd;
  real_T TCMSHVAC2CBTripCmd;
  real_T DeadmanBypassStatus;
  real_T BLCOSwitchStatus;
  real_T TooManyBogiesIsolated;
  real_T TooManyEPICCutout;
  real_T TCMSWFLIsolation;
  real_T TCMSPABORBypass;
  real_T WFLIsolated;
  real_T HVAC1FireDetectorDisableVDUReq;
  real_T EDBHeatAlarmDisableVDUReq;
  real_T CABSmokeDetectorDisableVDUReq;
  real_T SHDEndCubicleRearRight1DisableVDUReq;
  real_T SHDEndCubicleRearRight2DisableVDUReq;
  real_T SHDEndCubicleRearLeft1DisableVDUReq;
  real_T SHDEndCubicleRearLeft2DisableVDUReq;
  real_T LHDDriverDeskDisableVDUReq;
  real_T LHDCIDisableVDUReq;
  real_T LHDLTJBDisableVDUReq;
  real_T SaloonR1FireDetectorDisableVDUReq;
  real_T SaloonR2FireDetectorDisableVDUReq;
  real_T AuxiliaryDeskFireDetectorDisableVDUReq;
  real_T RemoteMagnetValve1;
  real_T RemoteMagnetValve2;
} BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem_

typedef struct {
  real_T BrakingDemand;
  real_T ASCOEnd1;
  real_T ASCOEnd2;
  real_T HornManuallyIsolated;
  real_T BIC1Inside;
  real_T BIC1Outside;
  real_T BIC2Inside;
  real_T BIC2Outside;
} BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Control_

typedef struct {
  BD_TCMSSystem_Out_Vehicle_Control_DoorSystem DoorSystem;
  BD_TCMSSystem_Out_Vehicle_Control_PantographSystem PantographSystem;
  BD_TCMSSystem_Out_Vehicle_Control_TractionBraking TractionSBraking;
  BD_TCMSSystem_Out_Vehicle_Control_ElectricalSystem ElectricalSystem;
  BD_TCMSSystem_Out_Vehicle_Control_PneumaticSystem PneumaticSystem;
} BD_TCMSSystem_Out_Vehicle_Control;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door_

typedef struct {
  real_T DoorA1Open;
  real_T DoorA2Open;
  real_T DoorA3Open;
  real_T DoorA4Open;
  real_T DoorB1Open;
  real_T DoorB2Open;
  real_T DoorB3Open;
  real_T DoorB4Open;
  real_T DoorA1Locked;
  real_T DoorA2Locked;
  real_T DoorA3Locked;
  real_T DoorA4Locked;
  real_T DoorB1Locked;
  real_T DoorB2Locked;
  real_T DoorB3Locked;
  real_T DoorB4Locked;
  real_T DoorA1Isolated;
  real_T DoorA2Isolated;
  real_T DoorA3Isolated;
  real_T DoorA4Isolated;
  real_T DoorB1Isolated;
  real_T DoorB2Isolated;
  real_T DoorB3Isolated;
  real_T DoorB4Isolated;
  real_T DoorA1Fault;
  real_T DoorA2Fault;
  real_T DoorA3Fault;
  real_T DoorA4Fault;
  real_T DoorB1Fault;
  real_T DoorB2Fault;
  real_T DoorB3Fault;
  real_T DoorB4Fault;
  real_T DoorA1EmergencyReleased;
  real_T DoorA2EmergencyReleased;
  real_T DoorA3EmergencyReleased;
  real_T DoorA4EmergencyReleased;
  real_T DoorB1EmergencyReleased;
  real_T DoorB2EmergencyReleased;
  real_T DoorB3EmergencyReleased;
  real_T DoorB4EmergencyReleased;
  real_T DCU1Status;
  real_T DCU2Status;
  real_T DCU3Status;
  real_T DCU4Status;
  real_T DCU5Status;
  real_T DCU6Status;
  real_T DCU7Status;
  real_T DCU8Status;
  boolean_T DoorA1CloseObstruction;
  boolean_T DoorA2CloseObstruction;
  boolean_T DoorA3CloseObstruction;
  boolean_T DoorA4CloseObstruction;
  boolean_T DoorB1CloseObstruction;
  boolean_T DoorB2CloseObstruction;
  boolean_T DoorB3CloseObstruction;
  boolean_T DoorB4CloseObstruction;
  boolean_T DoorA1OpenObstruction;
  boolean_T DoorA2OpenObstruction;
  boolean_T DoorA3OpenObstruction;
  boolean_T DoorA4OpenObstruction;
  boolean_T DoorB1OpenObstruction;
  boolean_T DoorB2OpenObstruction;
  boolean_T DoorB3OpenObstruction;
  boolean_T DoorB4OpenObstruction;
  real_T DoorA1OpenDummyForLeaf;
  boolean_T DoorA1MotorCircuitFailure;
  boolean_T DoorA2MotorCircuitFailure;
  boolean_T DoorA3MotorCircuitFailure;
  boolean_T DoorA4MotorCircuitFailure;
  boolean_T DoorB1MotorCircuitFailure;
  boolean_T DoorB2MotorCircuitFailure;
  boolean_T DoorB3MotorCircuitFailure;
  boolean_T DoorB4MotorCircuitFailure;
  boolean_T DoorA1FailedToLock;
  boolean_T DoorA2FailedToLock;
  boolean_T DoorA3FailedToLock;
  boolean_T DoorA4FailedToLock;
  boolean_T DoorB1FailedToLock;
  boolean_T DoorB2FailedToLock;
  boolean_T DoorB3FailedToLock;
  boolean_T DoorB4FailedToLock;
  boolean_T DoorA1FailedToUnlock;
  boolean_T DoorA2FailedToUnlock;
  boolean_T DoorA3FailedToUnlock;
  boolean_T DoorA4FailedToUnlock;
  boolean_T DoorB1FailedToUnlock;
  boolean_T DoorB2FailedToUnlock;
  boolean_T DoorB3FailedToUnlock;
  boolean_T DoorB4FailedToUnlock;
  boolean_T DoorA1UnexpectedUnlocking;
  boolean_T DoorA2UnexpectedUnlocking;
  boolean_T DoorA3UnexpectedUnlocking;
  boolean_T DoorA4UnexpectedUnlocking;
  boolean_T DoorB1UnexpectedUnlocking;
  boolean_T DoorB2UnexpectedUnlocking;
  boolean_T DoorB3UnexpectedUnlocking;
  boolean_T DoorB4UnexpectedUnlocking;
  boolean_T DoorA1DCSRFailure;
  boolean_T DoorA2DCSRFailure;
  boolean_T DoorA3DCSRFailure;
  boolean_T DoorA4DCSRFailure;
  boolean_T DoorB1DCSRFailure;
  boolean_T DoorB2DCSRFailure;
  boolean_T DoorB3DCSRFailure;
  boolean_T DoorB4DCSRFailure;
  boolean_T DoorA1DCSLFailure;
  boolean_T DoorA2DCSLFailure;
  boolean_T DoorA3DCSLFailure;
  boolean_T DoorA4DCSLFailure;
  boolean_T DoorB1DCSLFailure;
  boolean_T DoorB2DCSLFailure;
  boolean_T DoorB3DCSLFailure;
  boolean_T DoorB4DCSLFailure;
  boolean_T DoorA1DLSRFailure;
  boolean_T DoorA2DLSRFailure;
  boolean_T DoorA3DLSRFailure;
  boolean_T DoorA4DLSRFailure;
  boolean_T DoorB1DLSRFailure;
  boolean_T DoorB2DLSRFailure;
  boolean_T DoorB3DLSRFailure;
  boolean_T DoorB4DLSRFailure;
  boolean_T DoorA1DLSLFailure;
  boolean_T DoorA2DLSLFailure;
  boolean_T DoorA3DLSLFailure;
  boolean_T DoorA4DLSLFailure;
  boolean_T DoorB1DLSLFailure;
  boolean_T DoorB2DLSLFailure;
  boolean_T DoorB3DLSLFailure;
  boolean_T DoorB4DLSLFailure;
  boolean_T DoorA1DoorMajorFault;
  boolean_T DoorA2DoorMajorFault;
  boolean_T DoorA3DoorMajorFault;
  boolean_T DoorA4DoorMajorFault;
  boolean_T DoorB1DoorMajorFault;
  boolean_T DoorB2DoorMajorFault;
  boolean_T DoorB3DoorMajorFault;
  boolean_T DoorB4DoorMajorFault;
  boolean_T DoorA1DCUFailure;
  boolean_T DoorA2DCUFailure;
  boolean_T DoorA3DCUFailure;
  boolean_T DoorA4DCUFailure;
  boolean_T DoorB1DCUFailure;
  boolean_T DoorB2DCUFailure;
  boolean_T DoorB3DCUFailure;
  boolean_T DoorB4DCUFailure;
  real_T DCU1Fault;
  real_T DCU2Fault;
  real_T DCU3Fault;
  real_T DCU4Fault;
  real_T DCU5Fault;
  real_T DCU6Fault;
  real_T DCU7Fault;
  real_T DCU8Fault;
  real_T DoorA1UnexpectedOpen;
  real_T DoorA2UnexpectedOpen;
  real_T DoorA3UnexpectedOpen;
  real_T DoorA4UnexpectedOpen;
  real_T DoorB1UnexpectedOpen;
  real_T DoorB2UnexpectedOpen;
  real_T DoorB3UnexpectedOpen;
  real_T DoorB4UnexpectedOpen;
  real_T DoorA1LocalEED;
  real_T DoorA2LocalEED;
  real_T DoorA3LocalEED;
  real_T DoorA4LocalEED;
  real_T DoorB1LocalEED;
  real_T DoorB2LocalEED;
  real_T DoorB3LocalEED;
  real_T DoorB4LocalEED;
} BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_

typedef struct {
  real_T AllRightDoorsClosed;
  real_T AllLeftDoorsClosed;
  real_T AllDoorsClosed;
  real_T EmerDoorFaultMessage;
  real_T EmergencyEscapeDoorFault;
  real_T EmergencyEscapeDoorIsolated;
  real_T EmergencyEscapeDoorLocked;
  real_T EmergencyEscapeDoorUnlocked;
  real_T EmergencyEscapeDoorOpen;
  real_T EmergencyEscapeDoorReleased;
  real_T CabSaloonPartitionDoorOpen;
  real_T EmergencyDoorCoverRemoved;
  real_T DoorLoopBypassActive;
  real_T LeftDoor1Lockout;
  real_T LeftDoor2Lockout;
  real_T LeftDoor3Lockout;
  real_T LeftDoor4Lockout;
  real_T RightDoor1Lockout;
  real_T RightDoor2Lockout;
  real_T RightDoor3Lockout;
  real_T RightDoor4Lockout;
  real_T UnexpectedDoorOpeningDetectedByCC;
  BD_TCMSSystem_Out_Vehicle_Display_DoorSystem_Door Doors;
} BD_TCMSSystem_Out_Vehicle_Display_DoorSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PantographSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PantographSystem_

typedef struct {
  real_T UnitAtLeastOnePantoUp;
  real_T UnitAllPantoDown;
  real_T UnitPantoPowerDetected;
  real_T VehiclePantoUp;
  real_T VehiclePantoDown;
  real_T PantographIsolated;
  real_T VehiclePantoRising;
  real_T VehiclePantoLowering;
  real_T PantographPosition;
  real_T PantographFault;
  real_T PantoADDFaultMessage;
  real_T PantoORDFaultMessage;
  real_T PantoRaiseFailureMessage;
} BD_TCMSSystem_Out_Vehicle_Display_PantographSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie_

typedef struct {
  real_T BrakeCylinderPressureGauge;
  real_T ParkBrakePressureGauge;
} BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_

typedef struct {
  real_T AllServiceBrakesReleased;
  real_T ServiceBrakesApplied;
  real_T AllParkBrakesReleased;
  real_T ParkBrakeApplied;
  real_T MainPipePressure;
  real_T BrakeCylinderPressure;
  real_T Bogie1BrakeCylinderPressure;
  real_T Bogie2BrakeCylinderPressure;
  real_T AirSuspensionPressure;
  real_T MainReservoirPressureGauge;
  real_T ParkBrakeIsolated;
  boolean_T ParkBrakeApplyFailure;
  boolean_T ParkBrakeReleaseFailure;
  BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem_Bogie Bogie[2];
  real_T Bogie1ServiceBrakeStatus;
  real_T Bogie2ServiceBrakeStatus;
  real_T Bogie1ServiceBrakeIsolated;
  real_T Bogie2ServiceBrakeIsolated;
  real_T Bogie1ParkingBrakeStatus;
  real_T Bogie2ParkingBrakeStatus;
  real_T Bogie1ParkingBrakeIsolated;
  real_T Bogie2ParkingBrakeIsolated;
  real_T Bogie1IsolationStatus;
  real_T Bogie2IsolationStatus;
  real_T Bogie1SUSPStatus;
  real_T Bogie2SUSPStatus;
  real_T Bogie1SUSPFault;
  real_T Bogie2SUSPFault;
  real_T BrakeDemandSignalFailure;
  real_T BECU1EmergencyBrakeFailure;
  real_T BECU2EmergencyBrakeFailure;
  real_T BECU1ServiceBrakeFailure;
  real_T BECU1BrakeNotApplied;
  real_T BECU1BrakeNotReleased;
  real_T BECU1CarLoadPressureLow;
  real_T BECU2CarLoadPressureLow;
  real_T BECULowRPressure;
  real_T Bogie1ServiceBrakeFault;
  real_T BECU1LoadPressureLow;
  real_T AirSuspensionBogie1Deflated;
  real_T PantographPipePressureLow;
  real_T MainReservoirPressureLow;
} BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TractionBraking_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TractionBraking_

typedef struct {
  real_T ForwardDirection;
  real_T ReverseDirection;
  real_T TrainSpeed;
  real_T ZeroSpeed;
  real_T TCMSSpeedLimit;
  real_T TractionOn;
  real_T BrakeOn;
  real_T TractionSafe;
  real_T UnitTractiveEffortAchieved;
  real_T UnitTractiveEffortPossible;
  real_T UnitEDBrakingEffortAchieved;
  real_T UnitEDBrakingEffortPossible;
  real_T UnitTractivePower;
  real_T UnitTractivePowerPossible;
  real_T UnitEDBrakingPower;
  real_T UnitEDBrakingPowerPossible;
  real_T VehicleTractiveEffortAchieved;
  real_T VehicleTractiveEffortPossible;
  real_T VehicleEDBrakingEffortAchieved;
  real_T VehicleEDBrakingEffortPossible;
  real_T VehicleTractivePower;
  real_T VehicleTractivePowerPossible;
  real_T VehicleEDBrakingPower;
  real_T VehicleEDBrakingPowerPossible;
  real_T ServiceBrakeActive;
  real_T ServiceBrakeFault;
  real_T TEBEFeedback;
  real_T BELOW_SIGNALS_ARE_PROPULSION_SCREEN_SIGNALS;
  real_T PropulsionActive;
  real_T PropulsionFault;
  real_T PropulsionIsolated;
  real_T PropulsionEnableStatus;
  real_T EDBrakeStatus;
  real_T TractiveEffort;
  real_T AKContactorStatus;
  real_T KContactorStatus;
  real_T FilterVoltage;
  real_T BELOW_SIGNALS_ARE_BRAKE_SCREEN_SIGNALS;
  real_T HoldingBrakeStatus;
  real_T BECUStatus;
  real_T BECUMinorFault;
  real_T BECUMajorFault;
  real_T EPBrakeDelivered;
  real_T EDBrakeRequested;
  real_T EPICIsolationStatus;
  real_T EDCutoutStatus;
  real_T RPRESSIsolationStatus;
  real_T CarWeight;
  real_T TotalWeight;
  real_T CIStatus;
  real_T CIFault;
  real_T CIIsolated;
  real_T BELOW_SIGNALS_ARE_FOR_SPEEDLIMIT_INTERLOCK_SCREEN;
  real_T SpeedLimitASCutout;
  real_T SpeedLimitASDeflated;
  real_T SpeedLimitBogieIsolated;
  real_T SpeedLimitBrakeFailure;
  real_T SpeedLimitEPICCutout;
  real_T SpeedLimitExcessiveSlip;
  real_T SpeedLimitJogMode;
  real_T SpeedLimitLowSpeedCutoutMode;
  real_T SpeedLimitNoEDAvailable;
  real_T SpeedLimitOverrideTractionBlock;
  real_T SpeedLimitRPRESSIsolated;
  real_T SpeedLimitSCSMode;
  real_T CIKAKContactor;
  real_T BELOW_SIGNALS_ARE_AT_BOGIE_LEVEL;
  real_T Bogie1WSPStatus;
  real_T Bogie2WSPStatus;
  real_T HeavyWheelSlipDetected;
  real_T DynamicBrakeCutoutDueToSlide;
  real_T RollbackDetected;
  real_T HTERequired;
  real_T WashingModeStatus;
  real_T ShuntModeStatus;
  real_T ATPLowSpeedCutoutStatus;
} BD_TCMSSystem_Out_Vehicle_Display_TractionBraking;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem_

typedef struct {
  real_T HMIPower;
  real_T CabActive;
  real_T TBCPosition;
  real_T UTOMode;
  real_T ATOMode;
  real_T ATPMode;
  real_T ROSMode;
  real_T RMRMode;
  real_T ATBMode;
  real_T RMFMode;
  real_T APS1Status;
  real_T APS2Status;
  real_T APS1Active;
  real_T APS2Active;
  real_T APS1Fault;
  real_T APS2Fault;
  real_T APS1Isolated;
  real_T APS2Isolated;
  real_T APS1OutputVoltage;
  real_T APS2OutputVoltage;
  real_T AK1Status;
  real_T K1Status;
  real_T AK2Status;
  real_T K2Status;
  real_T BCG1Status;
  real_T BCG2Status;
  real_T BCG1Fault;
  real_T BCG2Fault;
  real_T BCGOutputVoltage;
  real_T BatteryVoltage;
  real_T TotalOutputCurrent;
  real_T OutputCurrent;
  real_T BatteryCurrent;
  real_T BatteryTemperature;
  real_T BCG1OutputCurrent;
  real_T BCG2OutputCurrent;
  real_T ATCBypassMode;
  real_T BrakeTrainLineStatus;
  real_T MotorTrainLineStatus;
  real_T FSB1LineStatus;
  real_T FSB2LineStatus;
  real_T EB1LineStatus;
  real_T EB2LineStatus;
  real_T VCBFault;
  real_T VCBIsolated;
  real_T VCBState;
  real_T LineVoltage;
  real_T Odometer;
  real_T TotalWeight;
  real_T OperationalMode;
  real_T RescueMode;
  real_T JogMode;
  real_T EnableToRun;
  real_T ShoreSupply;
  real_T Coupled;
  real_T VCBTripCommandStatus;
  real_T StandbyMode;
  real_T SaloonLightGroupStatus1;
  real_T SaloonLightGroupStatus2;
  real_T FlasherLightStatus;
  real_T WFLStatus;
  real_T WFLFault;
  real_T WFLOilLevelStatus;
  real_T WFLPump1Status;
  real_T WFLPump2Status;
  real_T TrainControlContactor;
  real_T BatteryIsolationContactor;
  real_T DUMMY_HVAC_SCREEN_SIGNALS_BELOW;
  real_T HVAC1Status;
  real_T HVAC2Status;
  real_T HVAC1ReducedMode;
  real_T HVAC2ReducedMode;
  real_T HVAC1Fault;
  real_T HVAC2Fault;
  real_T HVAC1Isolated;
  real_T HVAC2Isolated;
  real_T HVAC1SetPointTemperature;
  real_T HVAC2SetPointTemperature;
  real_T HVAC1InternalTemperature;
  real_T HVAC2InternalTemperature;
  real_T HVAC1ExternalTemperature;
  real_T HVAC2ExternalTemperature;
  real_T DUMMY_MV_SCREEN_SIGNALS_BELOW;
  real_T MainCompressor;
  real_T PowerExtensionContactor;
  real_T AuxCompressor;
  real_T DUMMY_TCMS_ECN_SCREEN_SIGNALS_BELOW;
  real_T ComponentSwitchStatusA;
  real_T ComponentSwitchStatusB;
  real_T ComponentSwitchStatusC;
  real_T TrainEthernetRepeaterStatus;
  real_T TrainBackboneNodeStatus;
  real_T ECNALGStatus;
  real_T DUMMY_FIRE_DETECTION_SCREEN_SIGNALS_BELOW;
  real_T UnderframeFireAlarmStatus;
  real_T SaloonFireAlarmStatus;
  real_T SensorFireAlarmStatus;
  real_T FireDetectionUnit;
  real_T ExternalSmoke;
  real_T InternalFire;
  real_T DUMMY_EB_INTERLOCK_SCREEN_SIGNALS_BELOW;
  real_T EBForNonCabEnabled;
  real_T EBDueToATCZeroSpeed;
  real_T EBByCC;
  real_T EBForNonDirectionSelected;
  real_T EBDueToPushButton;
  real_T EBByMC;
  real_T EBByBrakeLoop;
  real_T EBDueToDeadman;
  real_T DUMMY_PANTO_INTERLOCK_SCREEN_SIGNALS_BELOW;
  real_T EGSOperatedACPM;
  real_T EGSOperatedOSPM;
  real_T DUMMY_VCB_INTERLOCK_SCREEN_SIGNALS_BELOW;
  real_T TransformerOilTemperature;
  real_T VCBOpenedByACOverCurrent;
  real_T VCBOpenedByMTrProtection;
  real_T VCBOpenedByICM;
  real_T VCBOpenedByICDM;
  real_T VCBOpenedByAPS;
  real_T NoLineVoltage;
  real_T APSKAKContactor;
  real_T RCCBTripped;
  real_T SupplyFanTripped;
  real_T ExtSmokeDetectedinHVAC;
  real_T EmergencyInverterTripped;
  real_T HVACFireMode;
  real_T HVACReducedMode;
  real_T HVACGroupMCBTripped;
  real_T HVACMajorFault;
  real_T SmokeAlarmCABArea;
  real_T HeatAlarmEDB;
  real_T FDUFault;
  real_T SFARFault;
  real_T BCG1Isolated;
  real_T BCG2Isolated;
  real_T BCG1IsolationFailed;
  real_T PowerOffPressed;
  real_T ObstructionDetectedLeft;
  real_T ObstructionDetectedRight;
  real_T DerailmentDetectedLeft;
  real_T DerailmentDetectedRight;
  real_T HighVoltageMissing;
  real_T CabNotEnabled;
  real_T DrivingModeNotOK;
  real_T TrainDirectionMissing;
  real_T ATCStatusNotOK;
  real_T TrainReadyNotOK;
  real_T TooManyRPressureCutout;
  real_T TooManyEPICCutout;
  real_T TooManyBogieIsolated;
  real_T ZVRDNotActive;
  real_T MotoringTLDeenergized;
  real_T BrakeLoopOpenTL;
  real_T ParkingBrakeActiveTL;
  real_T DoorLoopOpenTL;
  real_T ADDIntervention;
  real_T BrakeLoopCBTripped;
  real_T WFLIsolated;
  real_T HVAC1FireSmokeActive;
  real_T EDBHeatAlarmActive;
  real_T CABSmokeAlarmActive;
} BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem_

typedef struct {
  real_T ConsistSwitchStatusA;
  real_T ConsistSwitchStatusB;
  real_T ConsistSwitchStatusC;
  real_T TrainEthernetRepeaterStatus;
  real_T TrainBackboneNodeStatus;
  real_T ECNALGStatus;
  real_T RemoteHornIsolated;
  real_T CCUFault;
  real_T RIO1Fault;
  real_T RIO1Status;
  real_T RIO2Fault;
  real_T RIO2Status;
  real_T RIO1RIO2Fault;
  real_T ERFault;
} BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_Message_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_Message_

typedef struct {
  real_T MessageID;
  real_T MessageStatus;
} BD_TCMSSystem_Out_Vehicle_Display_Message;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_MessageList_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_MessageList_

typedef struct {
  BD_TCMSSystem_Out_Vehicle_Display_Message Message[10];
} BD_TCMSSystem_Out_Vehicle_Display_MessageList;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_

typedef struct {
  BD_TCMSSystem_Out_Vehicle_Display_DoorSystem DoorSystem;
  BD_TCMSSystem_Out_Vehicle_Display_PantographSystem PantographSystem;
  BD_TCMSSystem_Out_Vehicle_Display_PneumaticsSystem PneumaticsSystem;
  BD_TCMSSystem_Out_Vehicle_Display_TractionBraking TractionBraking;
  BD_TCMSSystem_Out_Vehicle_Display_ElectricalSystem ElectricalSystem;
  BD_TCMSSystem_Out_Vehicle_Display_TCMSSystem TCMSSystem;
  BD_TCMSSystem_Out_Vehicle_Display_MessageList MessageList;
} BD_TCMSSystem_Out_Vehicle_Display;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_

typedef struct {
  BD_TCMSSystem_Out_Vehicle_Control Control;
  BD_TCMSSystem_Out_Vehicle_Display Display;
} BD_TCMSSystem_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TractionBraking_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_Out_Vehicle_Display_TractionBraking_Bogie_

typedef struct {
  real_T TCUStatus;
  real_T BogieFaulty;
  real_T TractionNotIsolated;
  real_T EDBrakeNotIsolated;
  real_T TCUSlideDetected;
  real_T TCUSlipDetected;
  real_T TractiveEffortAchieved;
  real_T EDBrakingEffortAchieved;
  real_T TractiveEffortPossible;
  real_T EDBrakingEffortPossible;
  real_T TractionPower;
  real_T EDBrakingPower;
  real_T TractivePowerPossible;
  real_T EDBrakingPowerPossible;
  real_T MotorSpeeds[2];
  real_T ASPressureSwitchStatus;
  real_T EstimatedSupportedMass;
} BD_TCMSSystem_Out_Vehicle_Display_TractionBraking_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_zNFhULoKccakLSUX9FFUEB_
#define DEFINED_TYPEDEF_FOR_struct_zNFhULoKccakLSUX9FFUEB_

typedef struct {
  real_T HMIPower;
} struct_zNFhULoKccakLSUX9FFUEB;

#endif

/* Parameters for system: '<S114>/TimerOnDelay NoInit1' */
typedef struct P_TimerOnDelayNoInit1_TCMSSystem_T_
  P_TimerOnDelayNoInit1_TCMSSystem_T;

/* Parameters for system: '<S114>/TimerOnDelay NoInit14' */
typedef struct P_TimerOnDelayNoInit14_TCMSSystem_T_
  P_TimerOnDelayNoInit14_TCMSSystem_T;

/* Parameters for system: '<S871>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_TCMSSystem_T_
  P_TimerOffDelayNoInit_TCMSSystem_T;

/* Parameters for system: '<S985>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_TCMSSystem_h_T_
  P_TimerOffDelayNoInit_TCMSSystem_h_T;

/* Parameters for system: '<S1071>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_TCMSSystem_T_
  P_IfActionSubsystem_TCMSSystem_T;

/* Parameters for system: '<S1091>/For Each Subsystem' */
typedef struct P_CoreSubsys_TCMSSystem_gmy0ogccz_T_
  P_CoreSubsys_TCMSSystem_gmy0ogccz_T;

/* Parameters for system: '<S1119>/CabInactiveNoTrainControl' */
typedef struct P_CabInactiveNoTrainControl_TCMSSystem_T_
  P_CabInactiveNoTrainControl_TCMSSystem_T;

/* Parameters for system: '<S1145>/For Each Subsystem' */
typedef struct P_CoreSubsys_TCMSSystem_gmy0ogccz5dd_T_
  P_CoreSubsys_TCMSSystem_gmy0ogccz5dd_T;

/* Parameters for system: '<S1114>/ForEachBogie' */
typedef struct P_CoreSubsys_TCMSSystem_j_T_ P_CoreSubsys_TCMSSystem_j_T;

/* Parameters for system: '<S1115>/TCMSTractionBogie' */
typedef struct P_CoreSubsys_TCMSSystem_l_T_ P_CoreSubsys_TCMSSystem_l_T;

/* Parameters for system: '<S1228>/ForEachBogie' */
typedef struct P_CoreSubsys_TCMSSystem_lr_T_ P_CoreSubsys_TCMSSystem_lr_T;

/* Parameters for system: '<S1229>/TCMSTractionBogie' */
typedef struct P_CoreSubsys_TCMSSystem_jf_T_ P_CoreSubsys_TCMSSystem_jf_T;

/* Parameters for system: '<Root>/TCMSSystemPerVehicle' */
typedef struct P_CoreSubsys_TCMSSystem_gmy0_T_ P_CoreSubsys_TCMSSystem_gmy0_T;

/* Parameters for system: '<S3>/Subsystem2' */
typedef struct P_CoreSubsys_TCMSSystem_nv_T_ P_CoreSubsys_TCMSSystem_nv_T;

/* Parameters (default storage) */
typedef struct P_TCMSSystem_T_ P_TCMSSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TCMSSystem_T RT_MODEL_TCMSSystem_T;

#endif                                 /* RTW_HEADER_TCMSSystem_types_h_ */
