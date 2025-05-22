/*
 * ElectricalSystem_types.h
 *
 * Code generation for model "ElectricalSystem".
 *
 * Model version              : 1.2076
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ElectricalSystem_types_h_
#define RTW_HEADER_ElectricalSystem_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Prm_

typedef struct {
  real_T OverheadLineVoltage;
  real_T BatteryVoltage;
} BD_ElectricalSystem_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasPanto;
  boolean_T HasCab;
  boolean_T IsNonCab;
  boolean_T HasMotor;
  boolean_T HasMainCompressor;
  boolean_T HasPantoReservoir;
  boolean_T IsT1;
  boolean_T IsT2;
  boolean_T IsT3;
  boolean_T IsM1;
  boolean_T IsM2;
  boolean_T IsM3;
  boolean_T IsDM1;
  boolean_T IsDM2;
  boolean_T IsDM3;
  boolean_T UnitConnection;
  int32_T UnitID;
} BD_ElectricalSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_InputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_InputControlStates_

typedef struct {
  real_T MasterKeySwitch;
  real_T PowerONPB;
  real_T PantographDownPB;
  real_T PantoSelectorSw;
  real_T TractionBrakeController;
  real_T VCBClosePB;
  real_T VCBOpenPB;
  real_T WiperControlSwitch;
  real_T HeadlightSwitch;
  real_T IdentificationLightsSwitch;
  real_T EmergencyBrakePB;
  real_T ParkBrakeApplyPB;
  real_T ParkBrakeReleasePB;
  real_T DoorProvenLoopCutoutPB;
  real_T DoorProvenLoopCutoutSw;
  real_T ZeroSpeedBypassSwitch;
  real_T ObstacleDetectionDisableSwitch;
  real_T LeftDoorReleasePB;
  real_T RightDoorReleasePB;
  real_T ROSPB;
  real_T UTOPB;
  real_T ATOStartPB;
  real_T EBReleasePB;
  real_T SafetyCutoutSS;
  real_T LampTestPB;
  real_T HornPB;
  real_T CabConsolePB;
  real_T LeftDoorClosePBOperatingPanel1;
  real_T RightDoorClosePBOperatingPanel1;
  real_T LeftDoorOpenPBOperatingPanel1;
  real_T RightDoorOpenPBOperatingPanel1;
  real_T CabMainLightPB;
  real_T DoorCloseAnnouncementPB;
  real_T UncouplePB;
  real_T FlasherLightPB;
  real_T FloodLightPB;
  real_T BatteryResetPB;
  real_T RightDoorOpenPBOperatingPanel5;
  real_T RightDoorClosePBOperatingPanel5;
  real_T WFLTestPB;
  real_T LeftDoorOpenPBOperatingPanel2;
  real_T LeftDoorClosePBOperatingPanel2;
  real_T CallOnLightPB;
  real_T LIMPHomePB;
  real_T PowerOFFPB;
  real_T DeadmanSafetyDevice;
  real_T DeadmanBypassSwitch;
  real_T BrakeLoopCutoutSS;
  real_T EmergencyBrakePBBypass;
  real_T ADDCOS;
  real_T ORDCOS;
  real_T HoldDoorCloseBS;
  real_T ModeSelector;
  real_T EmerDoorLimitSwitch;
  real_T PECUPushButton;
  real_T CMCCB;
  real_T LeftDoorOpenPB1OperatingPanel2;
  real_T RightDoorOpenPB1OperatingPanel5;
  boolean_T ParkBrakeIsolationCock;
  real_T RIO1CB;
  real_T RIO2CB;
  real_T TDICB;
  real_T DIOCB2;
  real_T DIOCB1;
  real_T CSCCB;
  real_T CSBCB;
  real_T CSACB;
  real_T CECB;
  real_T UCCB;
  real_T BLCB;
  real_T CRSBCB;
  real_T DMICB;
  real_T NVICB;
  real_T VIO1CB;
  real_T VIO2CB;
  real_T APSCB;
  real_T DLCB;
  real_T DRCB;
  real_T DPLCB;
  real_T HLCB;
  real_T TLCB;
  real_T CELCB;
  real_T ILCB1;
  real_T ILCB2;
  real_T PANCB;
  real_T TBCCB1;
  real_T TBCCB2;
  real_T POCB;
  real_T TVDUCB;
  real_T ODDCB;
  real_T WFLCB;
  real_T WWCB;
  real_T VCBCCB;
  real_T VCBCB;
  real_T PADCB;
  real_T SAC1CCB;
  real_T SAC2CCB;
  real_T AC1CB;
  real_T AC2CB;
  real_T RCCB;
  real_T SFB;
  real_T EIVIB;
  real_T MRIsolationCock;
  real_T EBLR1CB;
  real_T EBLR2CB;
  real_T HCB;
  real_T EmergencyStopPB;
  real_T OCCB1;
  real_T ELCB1;
  real_T ELCB2;
  real_T FDSCB;
  real_T SSICB;
  real_T BCBCB;
  real_T EDCB;
  real_T BCGCB;
  real_T BECUCB1;
  real_T BECUCB2;
  real_T BECUCB3;
  real_T LeftDoor1DCUCB;
  real_T LeftDoor2DCUCB;
  real_T LeftDoor3DCUCB;
  real_T LeftDoor4DCUCB;
  real_T RightDoor1DCUCB;
  real_T RightDoor2DCUCB;
  real_T RightDoor3DCUCB;
  real_T RightDoor4DCUCB;
  real_T WiperSelectionSwitch;
  real_T WiperWash;
} BD_ElectricalSystem_In_Vehicle_InputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Coupling_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Coupling_

typedef struct {
  boolean_T ElectricalTrainConnection;
  boolean_T ElectricalUnitConnection;
  boolean_T ElectricalCoupledCabsConnection;
  boolean_T MechanicalCouplerState[2];
} BD_ElectricalSystem_In_Vehicle_Coupling;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Dynamics_

typedef struct {
  real_T VehicleSpeed;
} BD_ElectricalSystem_In_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Pneumatics_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Pneumatics_

typedef struct {
  boolean_T AuxiliaryReservoirPressureSwitch;
  boolean_T MainReservoirPressureSwitch;
  boolean_T ParkBrakeApplied;
  boolean_T ServiceBrakeApplied;
  boolean_T EmergencyBrakeApplied;
  boolean_T VCBPressureSwitch;
  boolean_T MRPSTractionCutout;
  boolean_T PS3;
  boolean_T PS2;
} BD_ElectricalSystem_In_Vehicle_Pneumatics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Doors_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Doors_

typedef struct {
  boolean_T VehicleDoorInterlock;
  boolean_T AllRightDoorsClosed;
  boolean_T AllLeftDoorsClosed;
  boolean_T EmergencyDoorOpen;
} BD_ElectricalSystem_In_Vehicle_Doors;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Pantograph_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Pantograph_

typedef struct {
  real_T LineVoltageDetected;
  real_T PantographPosition;
} BD_ElectricalSystem_In_Vehicle_Pantograph;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_Out_ModelStatus_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_Out_ModelStatus_

typedef struct {
  boolean_T IsInitialized;
} BD_CommonTrain_Out_ModelStatus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_SignalSys_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_SignalSys_

typedef struct {
  real_T NotImmobilise;
  real_T LeftSideDoorEnable;
  real_T RightSideDoorEnable;
  real_T ATCZeroSpeed;
  real_T NotSafetyBrake;
  real_T LeftSideDoorOpen;
  real_T RightSideDoorOpen;
  boolean_T ATOTraction;
  boolean_T ATONotBrake;
  real_T LeftDoorOpenIndicator;
  real_T RightDoorOpenIndicator;
  real_T UndergroundSection;
  real_T ATOStartIndicator;
  real_T SBResetIndicator;
  real_T LeftDoorReleaseIndicator;
  real_T RightDoorReleaseIndicator;
  real_T ATOState;
  real_T ROSIndication;
  boolean_T NoEmergencyBrakeOrder;
  boolean_T LeftHoldDoorClose;
  boolean_T RightHoldDoorClose;
  real_T EmerDetrainDoorLockRelay;
  real_T WakeUpCommand;
  real_T UTOPBIndicator;
  real_T UTOModeActive;
  real_T ATCCabActivation;
  real_T ATOTBDemand;
  real_T TractionForward;
  real_T DerailmentDetected;
  real_T ObstacleHardCollision;
  real_T ObstacleSoftCollision;
} BD_ElectricalSystem_In_Vehicle_SignalSys;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_TCMS_

typedef struct {
  real_T Overspeed;
  boolean_T EnergizeTLWR;
  boolean_T EnergizeTLRR;
  boolean_T EnergizeHLHBR;
  boolean_T EnergizeHLLBR;
  boolean_T EnergizeFLR;
  boolean_T EnergizeFLDR;
  boolean_T EnergizeRM;
  boolean_T EnergizeCOLR;
  boolean_T NeutralSection;
  boolean_T RecloseAfterNeutralSection;
  boolean_T PantoDownTripCmd;
  boolean_T PantoMVSet;
  boolean_T TCMS_TPOR;
  boolean_T TCMS_TSDR;
  boolean_T TCMS_VCBClose;
  boolean_T TCMS_VCBOpen;
  boolean_T LeftDoorClosePBLight;
  boolean_T LeftDoorOpenPBLight;
  boolean_T RightDoorClosePBLight;
  boolean_T RightDoorOpenPBLight;
  boolean_T HoldingBrakeStatus;
  boolean_T TCMS_PBR;
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
  real_T TCMSIsolatePanto;
  real_T TCMSIsolateVCB;
  real_T TCMSIsolateAPS1;
  real_T TCMSIsolateAPS2;
  real_T TCMSIsolateCI;
  real_T TCMS_TSDDR;
  boolean_T LeftDoorAuth_Opened_Op1;
  boolean_T RightDoorAuth_Opened_Op1;
  real_T TCMSCompressorCmd;
  real_T TCMSFireAlarmReset;
  real_T TCMSFDUReset;
  real_T TCMSHVACSmokeReset;
  real_T TCMSIsolateHVAC1;
  real_T TCMSIsolateHVAC2;
  real_T TCMSResetHVAC1;
  real_T TCMSResetHVAC2;
  real_T TCMSWFLIsolation;
  real_T TCMSPABORBypass;
  real_T HVAC1FireDetectorDisableVDUReq;
  real_T CABSmokeDetectorDisableVDUReq;
  real_T SHDEndCubicleRearLeft2DisableVDUReq;
} BD_ElectricalSystem_In_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Traction_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_Traction_

typedef struct {
  boolean_T ForwardDirection;
  boolean_T ReverseDirection;
  boolean_T TCU_KStatus;
  boolean_T TCU_AKStatus;
  boolean_T ContactorsFailure;
  real_T TractionContactorStatus;
} BD_ElectricalSystem_In_Vehicle_Traction;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Vehicle_

typedef struct {
  BD_ElectricalSystem_In_Vehicle_InputControlStates InputControlStates;
  BD_ElectricalSystem_In_Vehicle_Coupling Coupling;
  BD_ElectricalSystem_In_Vehicle_Dynamics Dynamics;
  BD_ElectricalSystem_In_Vehicle_Pneumatics Pneumatics;
  BD_ElectricalSystem_In_Vehicle_Doors Doors;
  BD_ElectricalSystem_In_Vehicle_Pantograph Pantograph;
  BD_CommonTrain_Out_ModelStatus ModelStatus;
  BD_ElectricalSystem_In_Vehicle_SignalSys SignalSys;
  BD_ElectricalSystem_In_Vehicle_TCMS TCMS;
  BD_ElectricalSystem_In_Vehicle_Traction TractionSys;
} BD_ElectricalSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Overrides_

typedef struct {
  real_T AutoPowerOn;
} BD_ElectricalSystem_In_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Faults_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_In_Faults_

typedef struct {
  real_T PantographDownForADDIntervention;
  real_T PantographDownForORDIntervention;
  real_T PantographRisingFailure;
  real_T FwdRevTrainLineMismatch;
  real_T CCDetectedEmerDoorOpen;
  boolean_T LowMRPressure;
  real_T ReverseMotionInForwardCommand;
  real_T BogieDerailed;
  real_T InternalFireAlarmTLActive;
  real_T FDUFailure;
  real_T TractionCutModeSelectorInATPATOUTO;
  real_T DamagedOHE;
  real_T DoorsNotOpeningFromDOPBOP1;
  real_T DepotSignalMalfunction;
  real_T TrackCircuitOccupied;
  real_T MainSignalSwitchesToRed;
  real_T PlatformScreenDoorNotWorking;
  real_T TrainGettingZeroSpeedOrder;
  real_T ATCEBUnableToReset;
  real_T TrainOvershootATCNotAllowingReverseAlignment;
  real_T FSBAppliedAt10KMPH;
  real_T VEHICLE_LEVEL_SIGNALS_BELOW;
  real_T HVAC1SupplyFanMPCBTrip;
  real_T HVAC1EmergencyInverterTrip;
  real_T HVAC1RCCBTrip;
  real_T HVAC1FireMode;
  real_T HVAC1ExternalSmokeMode;
  real_T HVAC1ReducedMode;
  real_T CabSaloonPartitionDoorOpen;
  real_T WFLFailure;
  real_T ODDFailure;
  real_T ObstacleDetectedRightSide;
  real_T DerailmentDetectedRightSide;
  real_T CouplingCircuitNotPowered;
  real_T CabEnablingCircuitBreakerTripped;
  real_T OHLHighVoltageLevel3;
  real_T OHLLowVoltageLevel2;
  real_T LineConverterOverCurrentLevel2;
  real_T LineConverterIGBTFailure;
  real_T DC110VLowVoltage;
  real_T OverTemperatureOfInverterPowerUnit;
  real_T OverTemperatureOfConverterPowerUnit;
  real_T AKOpenFailure;
  real_T KOpenFailure;
  real_T MainCircuitEarthFaultLevel2;
  boolean_T VCBOpenedByCI;
  real_T PantographDownForBUVDRIntervention;
  real_T PantographCircuitNotEnergized;
  real_T TransformerOilPressureTooLow;
  real_T TransformerOilTemperatureTooHigh;
  boolean_T VCBOpenedByACOvercurrent;
  boolean_T VCBOpenedByMTrProtection;
  boolean_T VCBOpenedByAPS;
  real_T PantographLoweringFailure;
  real_T MCBBrakeGroupTripped;
  real_T MCBDoorGroupTripped;
  real_T MCB110VDCGroupTripped;
  real_T MechanicalCouplerRelayFault;
  real_T BatteryFuseBlown;
  real_T BICContactorActivationFault;
  real_T LowBatteryVoltageAlarm;
  real_T LightGroupMCBTripped;
  real_T MCBHVACGroupTripped;
  real_T HVAC1MajorFault;
  real_T MCBSignalingGroupTripped;
  boolean_T APSMCBGroupTripped;
  boolean_T APSCircuitBreakerTripped;
  real_T SmokeAlarmCABArea;
  real_T HeatAlarmEDB;
  real_T TrainRadioFailure;
  real_T PEA1AlarmActive;
  real_T PEA1CallNotAcknowledged;
  real_T PEA1Failure;
  real_T MCBPAGroupOpen;
  real_T CCUCommunicationError;
  real_T CommunicationErrorRIO1RIO2;
  real_T MCBTCMSGroupTripped;
  real_T ER1MajorFault;
  real_T EmerDoorNotOpenRelayDeactivated;
  real_T AllDoorCloseIndicatorNotWorking;
  real_T TrainDoorLockedClosedRelayFailure;
  real_T WipersNotWorking;
  real_T FloodLightNotWorking;
  real_T ShutdownFailureVCBOpening;
  real_T LightGroupSaloonMCBTripped;
  boolean_T ExteriorLight1CBTripped;
  boolean_T ExteriorLight2CBTripped;
  boolean_T InteriorLight1CBTripped;
  boolean_T InteriorLight2CBTripped;
  real_T CMCContactorActivationFailure;
  real_T CMCContactorDeactivationFailure;
  real_T APSGroup1Failure;
  real_T APSGroup1Isolated;
  real_T BCGGroup1Failure;
  real_T BCGGroup1IsolationFailure;
  real_T BCGGroup1Isolated;
  boolean_T VCBMissingClosing;
  boolean_T VCBMissingOpening;
  real_T HeadlightFailure;
  real_T HornBlowsContinuously;
  real_T LineVoltageIndicatorNotWorking;
  real_T OtherCabOccupiedIndicatorFaulty;
  real_T DoorClosePBOP1NotWorking;
  real_T EmergencyBrakePBOP1NotWorking;
  real_T DoorCloseAnnouncementPBNotWorking;
  real_T ATCFailure;
  real_T DMIFailure;
  real_T TransformerOilLevelLow;
  real_T TransformerOilLevelTooLow;
  real_T TransformerOilFlowWarning;
  real_T TransformerOilPressureWarning;
  real_T TransformerOilTemperatureHigh;
  real_T PCUFailure;
  real_T PEA2Failure;
  real_T PEA3Failure;
  real_T SCU2Failure;
  real_T EBNotReleased;
  real_T CIMicroprocessorAbnormal;
  real_T CILocalCommunicationFailure;
  real_T PantographRisingMissing;
  real_T PantographLoweringMissing;
  real_T PantographRisingInhibited;
  real_T CIFailure;
  real_T CIIsolated;
  real_T EmergencyBrakeDueToEBPB;
  real_T EmergencyBrakeDueDeadman;
} BD_ElectricalSystem_In_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_TrainWires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_TrainWires_

typedef struct {
  real_T TW_TLPC1;
  real_T TW22502;
  real_T TW_UncoupleSignal;
  real_T TW_TLGC1;
  real_T TW25102;
  real_T TW25103;
  real_T TW26201;
  real_T TDI_110VDC;
  real_T TW31203;
  real_T TW51204;
  real_T TW51206;
  real_T TW_ZeroSpeed;
  real_T TW81201;
  real_T TW81203;
  real_T TWPantoDNCmd;
  real_T TW99102;
  real_T TW99103;
  real_T TW99104;
  real_T TW99105;
  real_T TW_LHPBR;
  real_T TW_PADR;
  real_T TW_CC_TrainWakeup;
  real_T TW41701;
  real_T TW41704;
  real_T TW41A04;
  real_T TW_ATOState;
  real_T TWNotBraking;
  real_T TWMotoring;
  real_T TWNotFSB;
  real_T TWCabASelected;
  real_T TWCabAKeySwitchON;
  real_T TWCabBSelected;
  real_T TWCabBKeySwitchON;
  real_T TW31101;
  real_T TW31101V;
  real_T TW31102;
  real_T TW31103;
  real_T TW22212;
  real_T TW11105;
  real_T TW_TSDR;
  real_T TW_TLGC3;
  real_T TW_TLGC2;
  real_T TW_TLGC9;
  real_T TW_TLGC10;
  real_T TW_TLGC11;
  real_T TW_SaloonFire;
  real_T TW_Integrity;
  real_T TW22204;
  real_T TW_VCBTripByCI;
  real_T TW_APSFault;
  real_T TW_VCBTripByAPS;
  real_T TW_LDISRR;
  real_T TW_LDISLR;
  real_T TW_11104;
} BD_ElectricalSystem_Wires_TrainWires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_UnitWires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_UnitWires_

typedef struct {
  real_T UW11104;
  real_T UW26101;
  real_T UW33101;
  real_T LW32101_02_03V;
  real_T UW_TPOR;
  real_T UW_BCGPower;
  real_T UW_VCB;
  real_T UW_TCU_KStatus;
  real_T UW_TCU_AKStatus;
  real_T KContactorState;
  real_T AKContactorState;
  real_T APSPower;
  real_T Contactor_Fault;
  real_T UW_DC110VLowFault;
  real_T UW_VCBTrip;
  real_T UW_PADR;
  real_T UW_BUVDR;
  real_T UW_PantoDown;
  real_T UW_ACOvercurrent;
  real_T UW_KAKContactorCI;
  real_T UW_VCBTripByCI;
  real_T UW_APSFault;
  real_T UW_VCBTripByAPS;
  real_T UW_TSDR;
} BD_ElectricalSystem_Wires_UnitWires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_OrientationWires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_OrientationWires_

typedef struct {
  real_T TWForward;
  real_T TWReverse;
  real_T TW_LeftDoorClose;
  real_T TW_RightDoorClose;
  real_T TW_LeftDoorOpen;
  real_T TW_RightDoorOpen;
  real_T TW81114;
  real_T TW81115;
  real_T TW_LDE;
  real_T TW_RDE;
  real_T TW_LHDC;
  real_T TW_RHDC;
  real_T TW_LDO_LH;
  real_T TW_RDO_LH;
} BD_ElectricalSystem_Wires_OrientationWires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_CoupledCabsWires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_CoupledCabsWires_

typedef struct {
  real_T TWCouplingForward;
  real_T TWCouplingReturn;
} BD_ElectricalSystem_Wires_CoupledCabsWires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_MiscWires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_MiscWires_

typedef struct {
  real_T TW_TLGC3;
  real_T Dummy;
} BD_ElectricalSystem_Wires_MiscWires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Wires_

typedef struct {
  BD_ElectricalSystem_Wires_TrainWires TrainWires;
  BD_ElectricalSystem_Wires_UnitWires UnitWires;
  BD_ElectricalSystem_Wires_OrientationWires OrientationWires;
  BD_ElectricalSystem_Wires_CoupledCabsWires CoupledCabsWires;
  BD_ElectricalSystem_Wires_MiscWires MiscWires;
} BD_ElectricalSystem_Wires;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Audio_

typedef struct {
  boolean_T VCBOpen;
  boolean_T VCBClose;
  boolean_T CompressorOn;
  boolean_T WiperOn;
  boolean_T DeadmanVigilance;
  boolean_T FlasherLightSound;
  real_T ObstacleSoftCollision;
} BD_ElectricalSystem_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_SignalSys_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_SignalSys_

typedef struct {
  real_T ATCPower;
  real_T ATOStartPB;
  real_T UTOStartPB;
  real_T ATCSafetyBrakeResetPB;
  real_T NotSafetyBrake;
  real_T CabActive;
  real_T UTOMode;
  real_T TBCInFSB;
  real_T RMFMode;
  real_T DoorEnableBypass;
  real_T TrainDoorClosedAndLocked;
  real_T RMRMode;
  real_T NoATCBypass;
  real_T TrainIntegrity;
  real_T DMIPower;
  real_T ATOMode;
  real_T ATBMode;
  real_T ROSMode;
  real_T ATPMode;
  real_T EmergencyDoorNotOpen;
  real_T WakeUpStatus;
  real_T PassengerEmergencyAlarm;
  real_T FireSmokeInd;
  real_T MechanicalCoupling;
  real_T ROSPB;
  real_T UTBPB;
  real_T LeftDoorOpenPB;
  real_T RightDoorOpenPB;
  real_T LeftDoorClosePB;
  real_T RightDoorClosePB;
} BD_ElectricalSystem_Out_Vehicle_SignalSys;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_OutputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_OutputControlStates_

typedef struct {
  real_T VCBClosePBLamp;
  real_T VCBOpenPBLamp;
  real_T AllDoorsClosedLight;
  real_T EmergencyBrakePBLight;
  real_T ParkBrakeApplyPBLight;
  real_T BatteryVoltageGauge;
  real_T OverheadLineVoltageGauge;
  real_T FloodLight;
  real_T FlasherLight;
  real_T UTOOrRMLight;
  real_T MarkerOrTailLight;
  real_T HeadLight;
  real_T SignallingLights;
  real_T IdentificationLights;
  real_T Speedometer;
  real_T WiperPosition;
  real_T HornPBLamp;
  real_T LeftDoorClosePBOperatingPanel1Lamp;
  real_T LeftDoorOpenPBOperatingPanel1Lamp;
  real_T RightDoorOpenPBOperatingPanel1Lamp;
  real_T RightDoorClosePBOperatingPanel1Lamp;
  real_T CabMainLight;
  real_T CabConsoleLight;
  real_T DoorCloseAnnouncementLamp;
  real_T LampTestPBLamp;
  real_T UncouplePBLamp;
  real_T FlasherLightPBLamp;
  real_T FloodLightPBLamp;
  real_T BatteryResetPBLamp;
  real_T RightDoorOpenPBOperatingPanel5Lamp;
  real_T RightDoorClosePBOperatingPanel5Lamp;
  real_T WFLTestPBLamp;
  real_T SaloonDoorCloseIndicator;
  real_T ParkBrakeOnPBLamp;
  real_T ParkBrakeOffPBLamp;
  real_T LineVoltageIndicator;
  real_T LeftDoorOpenPBOperatingPanel2Lamp;
  real_T LeftDoorClosePBOperatingPanel2Lamp;
  real_T PantoUpPBLamp;
  real_T PantoDownPBLamp;
  real_T LIMPHomePBLamp;
  real_T PowerOFFPBLamp;
  real_T CallOnLightPBLamp;
  real_T APSFaultIndicator;
  real_T PowerFaultIndicator;
  real_T EmergencyBrakeIndicator;
  real_T VCBTripIndicator;
  real_T OtherCabOccupiedIndicator;
  real_T HVACFaultIndicator;
  real_T ROSPBLamp;
  real_T UTOPBLamp;
  real_T ATOStartPBLamp;
  real_T EBResetPBLamp;
  real_T AuxModuleON;
  real_T LeftDoorOpenPB1OperatingPanel2Lamp;
  real_T RightDoorOpenPB1OperatingPanel5Lamp;
  real_T LeftDoor1LEDIndicator;
  real_T LeftDoor2LEDIndicator;
  real_T LeftDoor3LEDIndicator;
  real_T LeftDoor4LEDIndicator;
  real_T RightDoor1LEDIndicator;
  real_T RightDoor2LEDIndicator;
  real_T RightDoor3LEDIndicator;
  real_T RightDoor4LEDIndicator;
  real_T WiperPositionLeft;
  real_T WiperPositionCenter;
  real_T WiperPositionRight;
  real_T WiperWash;
} BD_ElectricalSystem_Out_Vehicle_OutputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Traction_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Traction_

typedef struct {
  boolean_T TCUPowerAvailable;
  boolean_T MotorPowerAvailable;
  boolean_T ForwardDirection;
  boolean_T ReverseDirection;
  boolean_T TBCTraction;
  boolean_T TBCNotBraking;
  boolean_T TractionSafe;
  boolean_T NoEmergencyBrake;
  boolean_T VCBStatus;
  boolean_T ContactorsFailure;
  real_T CIIsolated;
} BD_ElectricalSystem_Out_Vehicle_Traction;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Braking_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Braking_

typedef struct {
  boolean_T BCUPower;
  boolean_T TBCTraction;
  boolean_T TBCNotBraking;
  boolean_T NoEB;
  boolean_T DeadmanVigilance;
} BD_ElectricalSystem_Out_Vehicle_Braking;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_TCMS_

typedef struct {
  boolean_T TCMSPowerAvailable;
  boolean_T HMIPower;
  boolean_T CabActive;
  boolean_T ForwardDirection;
  boolean_T ReverseDirection;
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
  boolean_T ZeroSpeed;
  real_T Speedometer;
  boolean_T VCBState;
  boolean_T APSKContactorState;
  boolean_T APSAKContactorState;
  real_T FilterVoltage;
  boolean_T APS1Status;
  boolean_T APS2Status;
  boolean_T BCG1Status;
  boolean_T BCG2Status;
  real_T BCGOutputVoltage;
  real_T BatteryVoltage;
  real_T BatteryCurrent;
  real_T BatteryTemperature;
  real_T BCG1OutputCurrent;
  real_T BCG2OutputCurrent;
  boolean_T NoBrakeTrainLine;
  boolean_T MotorTrainLine;
  boolean_T NoFSB1Line;
  boolean_T NoFSB2Line;
  boolean_T NoEB1Line;
  boolean_T NoEB2Line;
  real_T LineVoltage;
  boolean_T NoEB;
  real_T APS1OutputVoltage;
  real_T APS2OutputVoltage;
  boolean_T HLSwitchStatus;
  real_T MarkerAndTailLight;
  boolean_T TCMS_FL_Status;
  boolean_T TCMS_CallOn_Status;
  real_T UTOOrRMLight;
  boolean_T PADPBStatus;
  boolean_T PADRStatus;
  real_T TPOR_ON;
  boolean_T TSDR_ON;
  real_T PowerONPBPressed;
  boolean_T PowerOFFPBPressed;
  boolean_T LeftDoorEnable;
  boolean_T RightDoorEnable;
  boolean_T LeftHoldDoorClose;
  boolean_T RightHoldDoorClose;
  boolean_T LimpHomeMode;
  boolean_T FwdRevTrainLineMismatchMessage;
  boolean_T LowMRPressureFaultMessage;
  boolean_T BCUPower;
  boolean_T APS1Fault;
  boolean_T APS2Fault;
  boolean_T APS1Isolated;
  boolean_T APS2Isolated;
  real_T SaloonLightGroupStatus1;
  real_T SaloonLightGroupStatus2;
  real_T WFLStatus;
  real_T WFLOilLevelStatus;
  real_T WFLPump1Status;
  real_T WFLPump2Status;
  real_T WFLFailure;
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
  boolean_T PECStatus;
  boolean_T EBbyNonCabEnabled;
  boolean_T EBbyMC;
  boolean_T EBbyBrakeLoop;
  boolean_T EBbyDeadMan;
  boolean_T NoLineVoltage;
  boolean_T D1Power;
  boolean_T EBbyCC;
  boolean_T EBdueToATCZeroSpeed;
  real_T HVACFaults[7];
  boolean_T ADDCOSStatus;
  boolean_T ORDCOSStatus;
  boolean_T MRIsolation;
  boolean_T MCBPAGroup;
  boolean_T MCB110VDCGroup;
  boolean_T MCBLightGroup;
  boolean_T MCBLightSaloonGroup;
  boolean_T MCBDoorGroup;
  boolean_T MCBBrakeGroup;
  boolean_T MCBAPSGroup;
  boolean_T MCBTCMSGroup;
  boolean_T MCBSignallingGroup;
  boolean_T VCBTripCommand;
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
  real_T UW_VCB;
  real_T PantoIsolated;
  real_T VCBIsolated;
  real_T PantoDownPBCmd;
  real_T VCBTripByCI;
  real_T CIIsolated;
  real_T BCG1Fault;
  real_T BCG2Fault;
  real_T BCG1Isolated;
  real_T BCG2Isolated;
  real_T BCG1IsolationFailed;
  boolean_T EBbyPB;
  real_T VCBTripByAPS;
  boolean_T MCDR;
  boolean_T MCDRFaulty;
  boolean_T ObstacleDetected;
  real_T ODDFailure;
  boolean_T MCBHVACGroupTripped;
  real_T PANPSR;
  real_T Key_Switch_Status;
  real_T VCBI_ACOvercurrent;
  real_T VCBI_KAKContactorCI;
  real_T EmergencyDoorNotOpenStatus;
  real_T DoorProvenLoopOK;
  real_T BrakeLoopCBTripped;
  boolean_T DeadmanBypassStatus;
  boolean_T BLCOSwitchStatus;
  real_T WFLIsolated;
} BD_ElectricalSystem_Out_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Pneumatics_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Pneumatics_

typedef struct {
  boolean_T ParkBrakeApplicationValve;
  boolean_T ParkBrakeRelease;
  boolean_T PantographRaiseValve;
  boolean_T MainCompressorMotorPower;
  boolean_T AuxCompressorMotorPower;
  boolean_T RemoteMagnetValve1;
  boolean_T RemoteMagnetValve2;
  boolean_T HornLow;
  boolean_T HornHigh;
  boolean_T RemoteHornIsolate;
  boolean_T VCBCloseCmd;
} BD_ElectricalSystem_Out_Vehicle_Pneumatics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Doors_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Doors_

typedef struct {
  boolean_T LeftDoorClose;
  boolean_T RightDoorClose;
  boolean_T LeftDoorOpen;
  boolean_T RightDoorOpen;
  boolean_T LeftDoorRelease;
  boolean_T RightDoorRelease;
  boolean_T ObstacleDetectionDisabled;
  boolean_T ZeroSpeed;
  boolean_T DCUPower[8];
  boolean_T DoorMotorPower;
  boolean_T LeftDoorOpenCmdInLimpHome;
  boolean_T RightDoorOpenCmdInLimpHome;
  boolean_T LeftDoorEnable;
  boolean_T RightDoorEnable;
  boolean_T LeftHoldDoorClose;
  boolean_T RightHoldDoorClose;
  boolean_T EmerDoorLatched;
  boolean_T EmerDoorOpenFault;
} BD_ElectricalSystem_Out_Vehicle_Doors;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Pantograph_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Pantograph_

typedef struct {
  boolean_T PantoUpCommand;
  boolean_T PantoDownCommand;
  boolean_T PantoControlPower;
  boolean_T PantoMotorPower;
  boolean_T PantoADDFault;
  boolean_T PantoORDFault;
  boolean_T PantoRaiseFailure;
  boolean_T PantoLoweringFailure;
} BD_ElectricalSystem_Out_Vehicle_Pantograph;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Coupling_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Coupling_

typedef struct {
  real_T ElectricalCouplerState;
  real_T UncoupleCmd;
} BD_ElectricalSystem_Out_Vehicle_Coupling;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Scoring_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Scoring_

typedef struct {
  boolean_T DeadmanRelay;
} BD_ElectricalSystem_Out_Vehicle_Scoring;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS_

typedef struct {
  real_T PAPIS_CCTV_Power;
  real_T DoorCloseAnnouncement;
  real_T DoorOpen;
  real_T DoorClose;
  real_T EmergencyDoorOpen;
  real_T CabActive;
  real_T AllDoorClose;
  real_T ZeroSpeed;
  real_T PECUAlarmActive;
  real_T Couple;
  real_T FrontObstacleDetected;
} BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_MiscOutputs_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_MiscOutputs_

typedef struct {
  BD_ElectricalSystem_Out_Vehicle_MiscOutputs_PAPIS PAPIS;
} BD_ElectricalSystem_Out_Vehicle_MiscOutputs;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_

typedef struct {
  BD_ElectricalSystem_Out_Vehicle_OutputControlStates OutputControlStates;
  BD_ElectricalSystem_Out_Vehicle_Traction Traction;
  BD_ElectricalSystem_Out_Vehicle_Braking Braking;
  BD_ElectricalSystem_Out_Vehicle_TCMS TCMS;
  BD_ElectricalSystem_Out_Vehicle_Pneumatics Pneumatics;
  BD_ElectricalSystem_Out_Vehicle_Doors Doors;
  BD_ElectricalSystem_Out_Vehicle_Pantograph Pantograph;
  BD_ElectricalSystem_Out_Vehicle_SignalSys SignalSys;
  BD_ElectricalSystem_Out_Vehicle_Coupling CouplingSystem;
  BD_ElectricalSystem_Out_Vehicle_Audio Audio;
  BD_ElectricalSystem_Out_Vehicle_Scoring Scoring;
  BD_ElectricalSystem_Out_Vehicle_MiscOutputs MiscOutputs;
} BD_ElectricalSystem_Out_Vehicle;

#endif

/* Parameters for system: '<S1336>/TimerOnDelay NoInit' */
typedef struct P_TimerOnDelayNoInit_ElectricalSystem_T_
  P_TimerOnDelayNoInit_ElectricalSystem_T;

/* Parameters for system: '<S1085>/TimerOffDelay NoInit' */
typedef struct P_TimerOffDelayNoInit_ElectricalSystem_T_
  P_TimerOffDelayNoInit_ElectricalSystem_T;

/* Parameters for system: '<S220>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_ElectricalSystem_i_T_
  P_IfActionSubsystem_ElectricalSystem_i_T;

/* Parameters for system: '<S220>/If Action Subsystem1' */
typedef struct P_IfActionSubsystem1_ElectricalSystem_T_
  P_IfActionSubsystem1_ElectricalSystem_T;

/* Parameters for system: '<Root>/Model (Per Car)' */
typedef struct P_CoreSubsys_ElectricalSystem_T_ P_CoreSubsys_ElectricalSystem_T;

/* Parameters (default storage) */
typedef struct P_ElectricalSystem_T_ P_ElectricalSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ElectricalSystem_T RT_MODEL_ElectricalSystem_T;

#endif                                /* RTW_HEADER_ElectricalSystem_types_h_ */
