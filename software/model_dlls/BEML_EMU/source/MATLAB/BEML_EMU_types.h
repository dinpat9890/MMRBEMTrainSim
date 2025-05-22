/*
 * BEML_EMU_types.h
 *
 * Code generation for model "BEML_EMU".
 *
 * Model version              : 1.1244
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BEML_EMU_types_h_
#define RTW_HEADER_BEML_EMU_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_BrakeShoeType_
#define DEFINED_TYPEDEF_FOR_BrakeShoeType_

typedef enum {
  BrakeShoeType_Composition = 0,       /* Default value */
  BrakeShoeType_CastIron,
  BrakeShoeType_HT45,
  BrakeShoeType_LT22,
  BrakeShoeType_LT14,
  BrakeShoeType_RB101202
} BrakeShoeType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_Equipment_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_Equipment_

typedef struct {
  real_T AxleBrakeConfig[6];
  real_T AxleParkBrakeConfig[6];
  real_T NumberOfBrakeCylindersPerAxle;
  BrakeShoeType BrakeShoeType;
} BD_TrainBrakes_Prm_Vehicle_Equipment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeCylinder_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeCylinder_

typedef struct {
  real_T BrakeCylinderPreload;
  real_T BrakeCylinderArea;
  real_T BrakeBeamFactor;
  real_T BrakeEfficiency;
} BD_TrainBrakes_Prm_Vehicle_BrakeCylinder;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeDisc_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeDisc_

typedef struct {
  real_T DiscBrakeRatio;
  real_T DiscBrakeFrictionCoef;
} BD_TrainBrakes_Prm_Vehicle_BrakeDisc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeFade_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_BrakeFade_

typedef struct {
  real_T BrakeTemperatures[10];
  real_T BrakeEfficiencies[10];
} BD_TrainBrakes_Prm_Vehicle_BrakeFade;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_ThermalModel_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_ThermalModel_

typedef struct {
  real_T BrakeInitialTemperature;
  real_T BrakeSpecificHeat;
  real_T BrakeEmissivity;
  real_T BrakeThermalMass;
} BD_TrainBrakes_Prm_Vehicle_ThermalModel;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_ParkBrakes_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_ParkBrakes_

typedef struct {
  real_T ParkBrakePressures[2];
  real_T AxleParkBrakePistonForces[2];
} BD_TrainBrakes_Prm_Vehicle_ParkBrakes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Prm_Vehicle_

typedef struct {
  BD_TrainBrakes_Prm_Vehicle_Equipment Equipment;
  BD_TrainBrakes_Prm_Vehicle_BrakeCylinder BrakeCylinder;
  BD_TrainBrakes_Prm_Vehicle_BrakeDisc BrakeDisc;
  BD_TrainBrakes_Prm_Vehicle_BrakeFade BrakeFade;
  BD_TrainBrakes_Prm_Vehicle_ThermalModel ThermalModel;
  BD_TrainBrakes_Prm_Vehicle_ParkBrakes ParkBrakes;
} BD_TrainBrakes_Prm_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeControl_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeControl_

typedef struct {
  real_T LoadCompensationGains[2];
  real_T MaxPressure;
} BD_PneumaticsSystem_Prm_BrakeControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_MainReservoir_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_MainReservoir_

typedef struct {
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
  real_T CompressorMassFlowRate;
  real_T BlowOffONPressure;
  real_T BlowOffOFFPressure;
} BD_PneumaticsSystem_Prm_MainReservoir;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_MainReservoirPipe_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_MainReservoirPipe_

typedef struct {
  real_T ResetPressure;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_MainReservoirPipe;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Sanding_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Sanding_

typedef struct {
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_Sanding;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_AirSuspension_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_AirSuspension_

typedef struct {
  real_T LoadCompensationMasses[2];
  real_T LoadCompensationPressures[2];
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_AirSuspension;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Horn_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Horn_

typedef struct {
  real_T SwitchONPressure;
} BD_PneumaticsSystem_Prm_Horn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_AuxiliaryReservoir_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_AuxiliaryReservoir_

typedef struct {
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
  real_T CompressorMassFlowRate;
  real_T BlowOffONPressure;
  real_T BlowOffOFFPressure;
} BD_PneumaticsSystem_Prm_AuxiliaryReservoir;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Pantograph_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_Pantograph_

typedef struct {
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
  real_T ORDSwitchONPressure;
  real_T ORDSwitchOFFPressure;
} BD_PneumaticsSystem_Prm_Pantograph;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeReservoir_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeReservoir_

typedef struct {
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_BrakeReservoir;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeCylinder_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_BrakeCylinder_

typedef struct {
  real_T BrakeCylindersPerBogieAxle[2];
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_BrakeCylinder;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_ParkBrakes_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_ParkBrakes_

typedef struct {
  real_T ParkBrakesPerBogieAxle[2];
  real_T ParkBrakePressures[2];
  real_T ParkBrakeForces[2];
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_ParkBrakes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_VCB_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_VCB_

typedef struct {
  real_T ResetPressure;
  real_T MaxPressure;
  real_T Volume;
  real_T SwitchONPressure;
  real_T SwitchOFFPressure;
} BD_PneumaticsSystem_Prm_VCB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Prm_

typedef struct {
  BD_PneumaticsSystem_Prm_BrakeControl BrakeControl;
  BD_PneumaticsSystem_Prm_MainReservoir MainReservoir;
  BD_PneumaticsSystem_Prm_MainReservoirPipe MainReservoirPipe;
  BD_PneumaticsSystem_Prm_Sanding Sanding;
  BD_PneumaticsSystem_Prm_AirSuspension AirSuspension;
  BD_PneumaticsSystem_Prm_Horn Horn;
  BD_PneumaticsSystem_Prm_AuxiliaryReservoir AuxiliaryReservoir;
  BD_PneumaticsSystem_Prm_Pantograph Pantograph;
  BD_PneumaticsSystem_Prm_BrakeReservoir BrakeReservoir;
  BD_PneumaticsSystem_Prm_BrakeCylinder BrakeCylinder;
  BD_PneumaticsSystem_Prm_ParkBrakes ParkBrakes;
  BD_PneumaticsSystem_Prm_VCB VCB;
} BD_PneumaticsSystem_Prm;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Prm_

typedef struct {
  real_T PantoRaiseTime;
  real_T PantoLowerTime;
  real_T PantoEmergencyLowerTime;
} BD_PantographSystem_Prm;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Prm_

typedef struct {
  real_T OverheadLineVoltage;
  real_T BatteryVoltage;
} BD_ElectricalSystem_Prm;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Prm_

typedef struct {
  real_T DummySignal;
} BD_CouplingSystem_Prm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Prm_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Prm_

typedef struct {
  BD_TrainDynamics_Prm Dynamics;
  BD_TrainBrakes_Prm_Vehicle Brakes;
  BD_PneumaticsSystem_Prm Pneumatics;
  BD_TractionSystem_Prm Traction;
  BD_PantographSystem_Prm Pantograph;
  BD_DoorSystem_Prm Doors;
  BD_ElectricalSystem_Prm Electrical;
  BD_TCMSSystem_Prm TCMS;
  BD_CouplingSystem_Prm Coupling;
} BD_SimIntegration_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Cfg_Unit_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Cfg_Unit_

typedef struct {
  boolean_T UnitConnection;
  int32_T UnitID;
  real_T VehiclesPerUnit;
} BD_SimIntegration_Out_Vehicle_Cfg_Unit;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_Location_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_Location_

typedef struct {
  boolean_T IsFirstVehicle;
  boolean_T IsLastVehicle;
  BD_SimIntegration_Out_Vehicle_Cfg_Unit UnitConfig;
} BD_SimIntegration_Cfg_Vehicle_Location;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_Equipment_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_Equipment_

typedef struct {
  boolean_T HasCab;
  boolean_T HasBogie;
  boolean_T HasMotors;
  boolean_T HasPneumaticPanto;
  boolean_T HasElectricPanto;
  boolean_T HasMainCompressor;
  boolean_T HasMainReservoir;
  boolean_T HasPantoReservoir;
  boolean_T HasBrakeSystem;
  boolean_T NumberOfDoors;
  real_T NumberOfTractionBogies;
  real_T NumberOfBrakingBogies;
} BD_SimIntegration_Cfg_Vehicle_Equipment;

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

#ifndef DEFINED_TYPEDEF_FOR_BrakeShoeCoefficientCalculationMethod_
#define DEFINED_TYPEDEF_FOR_BrakeShoeCoefficientCalculationMethod_

typedef enum {
  BrakeShoeCoefficientCalculationMethod_ConstantBSC = 0,/* Default value */
  BrakeShoeCoefficientCalculationMethod_CustomBSC
} BrakeShoeCoefficientCalculationMethod;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Cfg_Vehicle_

typedef struct {
  BrakeShoeCoefficientCalculationMethod BrakeShoeCoefficientCalculationMethod;
  real_T BrakeShoeFrictionCoeff;
  real_T BrakeFadeEnable;
  real_T BrakeTemperatureEnable;
} BD_TrainBrakes_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Cfg_Vehicle_Equipment_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Cfg_Vehicle_Equipment_

typedef struct {
  real_T HasDriverCab;
  real_T HasBogie;
  real_T HasCompressor;
  real_T HasMainReservoir;
  real_T HasBrakeSystem;
  real_T HasPantograph;
} BD_PneumaticsSystem_Cfg_Vehicle_Equipment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Cfg_Vehicle_

typedef struct {
  BD_PneumaticsSystem_Cfg_Vehicle_Equipment Equipment;
} BD_PneumaticsSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasMotors;
} BD_TractionSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasPanto;
  boolean_T PneumaticsPoweredPanto;
  boolean_T ElectricPoweredPanto;
} BD_PantographSystem_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_Cfg_Door_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_Cfg_Door_

typedef struct {
  real_T isLeft;
  real_T NumberOfDoors;
} BD_DoorSystem_Cfg_Door;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Cfg_Vehicle_

typedef struct {
  BD_CommonTrain_Cfg_Vehicle Common;
  BD_SimIntegration_Cfg_Vehicle_Location Location;
  BD_SimIntegration_Cfg_Vehicle_Equipment Equipment;
  BD_TrainDynamics_Cfg_Vehicle Dynamics;
  BD_TrainBrakes_Cfg_Vehicle Brakes;
  BD_PneumaticsSystem_Cfg_Vehicle Pneumatics;
  BD_TractionSystem_Cfg_Vehicle Traction;
  BD_PantographSystem_Cfg_Vehicle Pantograph;
  BD_DoorSystem_Cfg_Door Doors;
  BD_ElectricalSystem_Cfg_Vehicle Electrical;
} BD_SimIntegration_Cfg_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Train_CollisionAndDerailment_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Train_CollisionAndDerailment_

typedef struct {
  real_T Collision;
  real_T Derailment;
  real_T Frozen;
} BD_CommonTrain_In_Train_CollisionAndDerailment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Train_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Train_

typedef struct {
  BD_CommonTrain_In_Train_CollisionAndDerailment CollisionAndDerailment;
} BD_CommonTrain_In_Train;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_Overrides_

typedef struct {
  real_T InitialVelocity;
  real_T AutoPowerOn;
  real_T TrainLoadOverride;
  real_T OrientationSwapRequest;
} BD_SimIntegration_In_Train_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_CBTC_Tuning_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_CBTC_Tuning_

typedef struct {
  real_T ATOTractionP;
  real_T ATOTractionI;
  real_T ATOTractionD;
  real_T ATOBrakeP;
  real_T ATOBrakeI;
  real_T ATOBrakeD;
  real_T ATOProximityBrakeDistance;
} BD_SimIntegration_In_Train_CBTC_Tuning;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Train_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Train_

typedef struct {
  real_T DynamicBrakeCutOut;
  real_T ReverseMotionInForwardCommand;
  real_T FWDREVTrainLineMismatch;
  real_T InternalFireAlarmTLActive;
  real_T FDUFaultAlarmTLActive;
  real_T LowMRPressure;
  real_T TractionCutModeSelectorInATPATOUTO;
  real_T DepotSignalMalfunction;
  real_T TrackCircuitOccupied;
  real_T MainSignalSwitchesToRed;
  real_T PlatformScreenDoorNotWorking;
  real_T DamagedOHE;
  real_T TrainGettingZeroSpeedOrder;
  real_T DoorsNotOpeningFromDOPBOP1;
  real_T ATCEBUnableToReset;
  real_T TrainOvershootATCNotAllowingReverseAlignment;
  real_T FSBAppliedAt10KMPH;
  real_T NeutralZoneVCBBackupFunctionActivated;
  real_T TCMSFailure;
  real_T TCMSDisplayHanged;
  real_T CCUCommunicationError;
  real_T HighTractiveEffortRequired;
  real_T PSDADCLStatusNotAvailable;
  real_T OnePSDBypassedAtStationInOpenCondition;
  real_T PSDStatusUnknown;
} BD_SimIntegration_Faults_Train;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Train_

typedef struct {
  BD_CommonTrain_In_Train Common;
  BD_SimIntegration_In_Train_Overrides Overrides;
  BD_SimIntegration_In_Train_CBTC_Tuning CBTCTuning;
  BD_SimIntegration_Faults_Train Faults;
} BD_SimIntegration_In_Train;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_Adjacencies_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_Adjacencies_

typedef struct {
  real_T Collision;
  real_T SoftCollision;
  real_T Derailment;
  real_T FacingTrackStop;
  real_T TrailingTrackStop;
  real_T Detonator;
} BD_CommonTrain_In_Vehicle_Adjacencies;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_CollisionAndDerailment_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_CollisionAndDerailment_

typedef struct {
  real_T Collision;
  real_T CollisionMass;
  real_T CollisionSpeed;
  real_T Derailment;
  real_T Frozen;
  real_T Freeze;
} BD_CommonTrain_In_Vehicle_CollisionAndDerailment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CommonTrain_In_Vehicle_

typedef struct {
  BD_CommonTrain_In_Vehicle_Adjacencies Adjacencies;
  BD_CommonTrain_In_Vehicle_CollisionAndDerailment CollisionAndDerailment;
} BD_CommonTrain_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_TrackData_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_In_Vehicle_TrackData_

typedef struct {
  real_T Gradient;
  real_T Radius;
  real_T Superelevation;
} BD_TrainDynamics_In_Vehicle_TrackData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Dynamics_

typedef struct {
  BD_TrainDynamics_In_Vehicle_TrackData TrackData;
} BD_SimIntegration_In_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Environment_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Environment_

typedef struct {
  real_T LineVoltage;
  real_T OverheadLinePresent;
  real_T NeutralSection;
  real_T RightDoorsEnable;
  real_T LeftDoorsEnable;
  real_T DoorsPairEnable[4];
  real_T DamagedOHE;
  real_T ObstructionOnTrack;
  real_T ObstructionSoftCollision;
} BD_SimIntegration_In_Vehicle_Environment;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_Onboard_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_Onboard_

typedef struct {
  real_T NoServiceBrakeOrder;
  real_T NoEmergencyBrakeOrder;
  real_T ImmobilisationState;
  real_T ATOState;
  real_T ATOPermittedSpeed;
  real_T ATOPermittedDistance;
  real_T ATOStartIndicator;
  real_T ROSIndicator;
  real_T ATCSBResetIndicator;
  real_T ZeroSpeed;
  real_T LeftHoldDoorClose;
  real_T RightHoldDoorClose;
  real_T WakeUpCommand;
  real_T UTOPBIndicator;
  real_T UTOModeActive;
  real_T ATCCabActivation;
  real_T TractionForward;
  real_T EmergencyDetrainmentDoorLocked;
  real_T RollbackDetected;
} BD_SimIntegration_In_Vehicle_CBTC_Onboard;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_Platform_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_Platform_

typedef struct {
  real_T LeftSideDoorEnable;
  real_T RightSideDoorEnable;
  real_T OpenLeftTrainDoors;
  real_T OpenRightTrainDoors;
  real_T CloseLeftTrainDoors;
  real_T CloseRightTrainDoors;
  real_T LeftDoorOpenIndicator;
  real_T RightDoorOpenIndicator;
  real_T LeftDoorReleaseIndicator;
  real_T RightDoorReleaseIndicator;
  real_T UndergroundSection;
  real_T LeftDoorCloseIndicator;
  real_T RightDoorCloseIndicator;
} BD_SimIntegration_In_Vehicle_CBTC_Platform;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_CBTC_

typedef struct {
  BD_SimIntegration_In_Vehicle_CBTC_Onboard OnBoard;
  BD_SimIntegration_In_Vehicle_CBTC_Platform Platform;
} BD_SimIntegration_In_Vehicle_CBTC;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_Overrides_

typedef struct {
  real_T VehicleLoadOverride;
} BD_SimIntegration_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_

typedef struct {
  BD_CommonTrain_In_Vehicle Common;
  BD_SimIntegration_In_Vehicle_Dynamics Dynamics;
  BD_SimIntegration_In_Vehicle_Environment Environment;
  BD_SimIntegration_Faults_Vehicle Faults;
  BD_TCMSSystem_In_Vehicle_DisplayControl DisplayControl;
  BD_SimIntegration_In_Vehicle_CBTC CBTC;
  BD_CouplingSystem_In_Vehicle Couplers;
  BD_SimIntegration_In_Vehicle_Overrides Overrides;
} BD_SimIntegration_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_In_InputControl_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_In_InputControl_

typedef struct {
  real_T Value;
  real_T Mode;
  real_T InitVal;
  real_T InternalRequest;
  real_T Inhibit;
} BD_IOControls_In_InputControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_In_MCBControl_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_In_MCBControl_

typedef struct {
  real_T Value;
  real_T Mode;
  real_T InitVal;
  real_T InternalRequest;
  real_T Inhibit;
  real_T TripRequest;
} BD_IOControls_In_MCBControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_In_Vehicle_

typedef struct {
  BD_IOControls_In_InputControl EmergencyBrakePB;
  BD_IOControls_In_InputControl HornPB;
  BD_IOControls_In_InputControl CabConsoleLightPB;
  BD_IOControls_In_InputControl DoorProvenLoopCutoutPB;
  BD_IOControls_In_InputControl LeftDoorClosePBOperatingPanel1;
  BD_IOControls_In_InputControl RightDoorClosePBOperatingPanel1;
  BD_IOControls_In_InputControl LeftDoorOpenPBOperatingPanel1;
  BD_IOControls_In_InputControl RightDoorOpenPBOperatingPanel1;
  BD_IOControls_In_InputControl CabMainLightPB;
  BD_IOControls_In_InputControl ParkingBrakeOnSwitch;
  BD_IOControls_In_InputControl ParkingBrakeOffSwitch;
  BD_IOControls_In_InputControl DoorCloseAnnouncementPB;
  BD_IOControls_In_InputControl ROSPB;
  BD_IOControls_In_InputControl UTOPB;
  BD_IOControls_In_InputControl ATOStartPB;
  BD_IOControls_In_InputControl EmergencyBrakeResetPB;
  BD_IOControls_In_InputControl ControlKey;
  BD_IOControls_In_InputControl ModeSelector;
  BD_IOControls_In_InputControl MasterControllerHandle;
  BD_IOControls_In_InputControl DeadmanSafetyDevice;
  BD_IOControls_In_InputControl CallOnLightPB;
  BD_IOControls_In_InputControl VCBOpenPB;
  BD_IOControls_In_InputControl WiperSelectionSwitch;
  BD_IOControls_In_InputControl WiperPump;
  BD_IOControls_In_InputControl LIMPHomePB;
  BD_IOControls_In_InputControl PowerOffPB;
  BD_IOControls_In_InputControl PantoDownPB;
  BD_IOControls_In_InputControl VCBClosePB;
  BD_IOControls_In_InputControl LeftDoorOpenPBOperatingPanel2;
  BD_IOControls_In_InputControl LeftDoorOpenPB1OperatingPanel2;
  BD_IOControls_In_InputControl LeftDoorClosePBOperatingPanel2;
  BD_IOControls_In_InputControl PantoUpPB;
  BD_IOControls_In_InputControl SafetyCutoutSS;
  BD_IOControls_In_InputControl BrakeLoopCutoutSS;
  BD_IOControls_In_InputControl PantoSelector;
  BD_IOControls_In_InputControl DeadmanBypassSwitch;
  BD_IOControls_In_InputControl HeadLightSwitch;
  BD_IOControls_In_InputControl UncouplePB;
  BD_IOControls_In_InputControl FlasherLightPB;
  BD_IOControls_In_InputControl FloodLightPB;
  BD_IOControls_In_InputControl BatteryResetPB;
  BD_IOControls_In_InputControl RightDoorOpenPBOperatingPanel5;
  BD_IOControls_In_InputControl RightDoorOpenPB1OperatingPanel5;
  BD_IOControls_In_InputControl RightDoorClosePBOperatingPanel5;
  BD_IOControls_In_InputControl DoorProvenLoopOutputSwitch;
  BD_IOControls_In_InputControl LampTestPB;
  BD_IOControls_In_InputControl WFLTestPB;
  BD_IOControls_In_InputControl WiperControlSwitch;
  BD_IOControls_In_InputControl EmergencyStopPB;
  BD_IOControls_In_InputControl HoldDoorCloseBypassSS;
  BD_IOControls_In_InputControl CabBoosterFanSS;
  BD_IOControls_In_InputControl EmergencyBrakePBBypassSS;
  BD_IOControls_In_InputControl CabEEDLeft;
  BD_IOControls_In_InputControl CabEEDRight;
  BD_IOControls_In_InputControl SafetyCover;
  BD_IOControls_In_InputControl DummyCover;
  BD_IOControls_In_InputControl RampCoverLockingLever;
  BD_IOControls_In_InputControl RampCover;
  BD_IOControls_In_InputControl RampHandle;
  BD_IOControls_In_InputControl RampEndSupport;
  BD_IOControls_In_InputControl RampMiddleSupport;
  BD_IOControls_In_InputControl WinderHandlesAccessCover;
  BD_IOControls_In_InputControl LargeHandle;
  BD_IOControls_In_InputControl RampWinder;
  BD_IOControls_In_InputControl SmallHandle;
  BD_IOControls_In_InputControl EmergencyDoorGasSpring;
  BD_IOControls_In_InputControl DoorWinder;
  BD_IOControls_In_MCBControl EBLR2CB;
  BD_IOControls_In_MCBControl EBMVCB;
  BD_IOControls_In_MCBControl EDCB;
  BD_IOControls_In_MCBControl ELCB1;
  BD_IOControls_In_MCBControl ELCB2;
  BD_IOControls_In_MCBControl ERCB;
  BD_IOControls_In_MCBControl HCB;
  BD_IOControls_In_MCBControl HLLCB;
  BD_IOControls_In_MCBControl HLRCB;
  BD_IOControls_In_MCBControl ILCB1;
  BD_IOControls_In_MCBControl ILCB2;
  BD_IOControls_In_MCBControl LDICB;
  BD_IOControls_In_MCBControl LDLCB;
  BD_IOControls_In_MCBControl LDRCB;
  BD_IOControls_In_MCBControl MLCB;
  BD_IOControls_In_MCBControl MMCB;
  BD_IOControls_In_MCBControl NBCB;
  BD_IOControls_In_MCBControl NVICB;
  BD_IOControls_In_MCBControl OCCB1;
  BD_IOControls_In_MCBControl OCCB2;
  BD_IOControls_In_MCBControl ODDCB;
  BD_IOControls_In_MCBControl PBCB;
  BD_IOControls_In_MCBControl PISCB1;
  BD_IOControls_In_MCBControl PISCB2;
  BD_IOControls_In_MCBControl POCB;
  BD_IOControls_In_MCBControl PPU1CB;
  BD_IOControls_In_MCBControl PPU2CB;
  BD_IOControls_In_MCBControl PPU3CB;
  BD_IOControls_In_MCBControl RIO1CB;
  BD_IOControls_In_MCBControl RIO2CB;
  BD_IOControls_In_MCBControl SIOCB1;
  BD_IOControls_In_MCBControl SIOCB2;
  BD_IOControls_In_MCBControl SSICB;
  BD_IOControls_In_MCBControl TBCCB1;
  BD_IOControls_In_MCBControl TBCCB2;
  BD_IOControls_In_MCBControl TBNCB;
  BD_IOControls_In_MCBControl TDICB;
  BD_IOControls_In_MCBControl TLLCB;
  BD_IOControls_In_MCBControl TLRCB;
  BD_IOControls_In_MCBControl TRIVCB;
  BD_IOControls_In_MCBControl TVDUCB;
  BD_IOControls_In_MCBControl TWVCB;
  BD_IOControls_In_MCBControl VCCBOrUCCB;
  BD_IOControls_In_MCBControl VCBCCB;
  BD_IOControls_In_MCBControl VIO1CB;
  BD_IOControls_In_MCBControl VIO2CB;
  BD_IOControls_In_MCBControl WFLCB;
  BD_IOControls_In_MCBControl WIFICB;
  BD_IOControls_In_MCBControl WWCB;
  BD_IOControls_In_MCBControl BECUCB1;
  BD_IOControls_In_MCBControl BECUCB2;
  BD_IOControls_In_MCBControl BECUCB3;
  BD_IOControls_In_MCBControl RSACB;
  BD_IOControls_In_MCBControl CMCCB;
  BD_IOControls_In_MCBControl CILCB;
  BD_IOControls_In_MCBControl CICB;
  BD_IOControls_In_MCBControl CELCB;
  BD_IOControls_In_MCBControl CECB;
  BD_IOControls_In_MCBControl CDUCB;
  BD_IOControls_In_MCBControl CCNVIO1CB;
  BD_IOControls_In_MCBControl CBTCCB1;
  BD_IOControls_In_MCBControl CBFCCB;
  BD_IOControls_In_MCBControl CBFCB;
  BD_IOControls_In_MCBControl C1CB;
  BD_IOControls_In_MCBControl BLCB;
  BD_IOControls_In_MCBControl ZVBACB;
  BD_IOControls_In_MCBControl EBLR1CB;
  BD_IOControls_In_MCBControl DRCB;
  BD_IOControls_In_MCBControl DPLCB;
  BD_IOControls_In_MCBControl DMICB;
  BD_IOControls_In_MCBControl DLCB;
  BD_IOControls_In_MCBControl DIOCB2;
  BD_IOControls_In_MCBControl DIOCB1;
  BD_IOControls_In_MCBControl CSCCB;
  BD_IOControls_In_MCBControl CSBCB;
  BD_IOControls_In_MCBControl CSACB;
  BD_IOControls_In_MCBControl CRSBCB;
  BD_IOControls_In_MCBControl SOCB2;
  BD_IOControls_In_MCBControl SOCB1;
  BD_IOControls_In_MCBControl MSOCB5;
  BD_IOControls_In_MCBControl MSOCB4;
  BD_IOControls_In_MCBControl MSOCB3;
  BD_IOControls_In_MCBControl MSOCB2;
  BD_IOControls_In_MCBControl MSOCB1;
  BD_IOControls_In_MCBControl HVAC1;
  BD_IOControls_In_MCBControl SAC2CCB;
  BD_IOControls_In_MCBControl HVAC2;
  BD_IOControls_In_MCBControl SAC1CCB;
  BD_IOControls_In_MCBControl CMCB;
  BD_IOControls_In_MCBControl AC2CB;
  BD_IOControls_In_MCBControl AC1CB;
  BD_IOControls_In_MCBControl FDSCB;
  BD_IOControls_In_MCBControl BCBCB;
  BD_IOControls_In_MCBControl ERVRCB1;
  BD_IOControls_In_MCBControl ERVRCB2;
  BD_IOControls_In_MCBControl ESKCB;
  BD_IOControls_In_MCBControl HMCB;
  BD_IOControls_In_MCBControl SP1CB;
  BD_IOControls_In_MCBControl SP2CB;
  BD_IOControls_In_MCBControl SP3CB;
  BD_IOControls_In_MCBControl SP4CB;
  BD_IOControls_In_MCBControl SP5CB;
  BD_IOControls_In_MCBControl SPCB6;
  BD_IOControls_In_MCBControl SPCB7;
  BD_IOControls_In_MCBControl SPCB8;
  BD_IOControls_In_MCBControl RPTCB;
  BD_IOControls_In_MCBControl TERCB1;
  BD_IOControls_In_MCBControl TERCB2;
  BD_IOControls_In_InputControl SPSW;
  BD_IOControls_In_InputControl SPPB;
  BD_IOControls_In_MCBControl APSCB;
  BD_IOControls_In_MCBControl APSICB;
  BD_IOControls_In_MCBControl BCGCB;
  BD_IOControls_In_MCBControl DSCB;
  BD_IOControls_In_MCBControl MTBMCCB;
  BD_IOControls_In_MCBControl PADCB;
  BD_IOControls_In_MCBControl PANCB;
  BD_IOControls_In_MCBControl SSCB;
  BD_IOControls_In_MCBControl PTCB;
  BD_IOControls_In_MCBControl VCBCB;
  BD_IOControls_In_MCBControl SP12CB;
  BD_IOControls_In_MCBControl MTBM1CB;
  BD_IOControls_In_MCBControl MTBM2CB;
  BD_IOControls_In_MCBControl SP11CB;
  BD_IOControls_In_MCBControl SP6CB;
  BD_IOControls_In_MCBControl MTOPCB;
  BD_IOControls_In_InputControl ORDCOS;
  BD_IOControls_In_InputControl ADDCOS;
  BD_IOControls_In_MCBControl LeftDoor1DCUCB;
  BD_IOControls_In_MCBControl LeftDoor2DCUCB;
  BD_IOControls_In_MCBControl LeftDoor3DCUCB;
  BD_IOControls_In_MCBControl LeftDoor4DCUCB;
  BD_IOControls_In_MCBControl RightDoor1DCUCB;
  BD_IOControls_In_MCBControl RightDoor2DCUCB;
  BD_IOControls_In_MCBControl RightDoor3DCUCB;
  BD_IOControls_In_MCBControl RightDoor4DCUCB;
  BD_IOControls_In_InputControl LeftDoor1Coving;
  BD_IOControls_In_InputControl LeftDoor2Coving;
  BD_IOControls_In_InputControl LeftDoor3Coving;
  BD_IOControls_In_InputControl LeftDoor4Coving;
  BD_IOControls_In_InputControl RightDoor1Coving;
  BD_IOControls_In_InputControl RightDoor2Coving;
  BD_IOControls_In_InputControl RightDoor3Coving;
  BD_IOControls_In_InputControl RightDoor4Coving;
  BD_IOControls_In_InputControl LeftDoor1EED;
  BD_IOControls_In_InputControl LeftDoor2EED;
  BD_IOControls_In_InputControl LeftDoor3EED;
  BD_IOControls_In_InputControl LeftDoor4EED;
  BD_IOControls_In_InputControl RightDoor1EED;
  BD_IOControls_In_InputControl RightDoor2EED;
  BD_IOControls_In_InputControl RightDoor3EED;
  BD_IOControls_In_InputControl RightDoor4EED;
  BD_IOControls_In_InputControl LeftDoor1ManualClose;
  BD_IOControls_In_InputControl LeftDoor2ManualClose;
  BD_IOControls_In_InputControl LeftDoor3ManualClose;
  BD_IOControls_In_InputControl LeftDoor4ManualClose;
  BD_IOControls_In_InputControl RightDoor1ManualClose;
  BD_IOControls_In_InputControl RightDoor2ManualClose;
  BD_IOControls_In_InputControl RightDoor3ManualClose;
  BD_IOControls_In_InputControl RightDoor4ManualClose;
  BD_IOControls_In_InputControl LeftDoor1ManualOpen;
  BD_IOControls_In_InputControl LeftDoor2ManualOpen;
  BD_IOControls_In_InputControl LeftDoor3ManualOpen;
  BD_IOControls_In_InputControl LeftDoor4ManualOpen;
  BD_IOControls_In_InputControl RightDoor1ManualOpen;
  BD_IOControls_In_InputControl RightDoor2ManualOpen;
  BD_IOControls_In_InputControl RightDoor3ManualOpen;
  BD_IOControls_In_InputControl RightDoor4ManualOpen;
  BD_IOControls_In_InputControl LeftDoor1Lockout;
  BD_IOControls_In_InputControl LeftDoor2Lockout;
  BD_IOControls_In_InputControl LeftDoor3Lockout;
  BD_IOControls_In_InputControl LeftDoor4Lockout;
  BD_IOControls_In_InputControl RightDoor1Lockout;
  BD_IOControls_In_InputControl RightDoor2Lockout;
  BD_IOControls_In_InputControl RightDoor3Lockout;
  BD_IOControls_In_InputControl RightDoor4Lockout;
  BD_IOControls_In_InputControl LeftDoorEADCover;
  BD_IOControls_In_InputControl RightDoorEADCover;
  BD_IOControls_In_InputControl LeftDoorEAD;
  BD_IOControls_In_InputControl RightDoorEAD;
  BD_IOControls_In_InputControl ParkBrakeIsolationCockBogie1;
  BD_IOControls_In_InputControl ParkBrakeIsolationCockBogie2;
  BD_IOControls_In_InputControl MRIsolationCock;
  BD_IOControls_In_InputControl UncouplingCock;
  BD_IOControls_In_InputControl Horn1IsolationCock;
  BD_IOControls_In_InputControl Horn2IsolationCock;
  BD_IOControls_In_InputControl MREPIsolationCockEnd1;
  BD_IOControls_In_InputControl BIC1Inside;
  BD_IOControls_In_InputControl BIC1Outside;
  BD_IOControls_In_InputControl BIC2Inside;
  BD_IOControls_In_InputControl BIC2Outside;
  BD_IOControls_In_InputControl MREPIsolationCockEnd2;
  BD_IOControls_In_InputControl EPIC;
  BD_IOControls_In_InputControl ASCOEnd1;
  BD_IOControls_In_InputControl ASCOEnd2;
  BD_IOControls_In_InputControl ASIsolationCock;
  BD_IOControls_In_InputControl SR;
  BD_IOControls_In_InputControl ParkingBrakeManualReleaseBogie1Handle1;
  BD_IOControls_In_InputControl ParkingBrakeManualReleaseBogie1Handle2;
  BD_IOControls_In_InputControl ParkingBrakeManualReleaseBogie2Handle1;
  BD_IOControls_In_InputControl ParkingBrakeManualReleaseBogie2Handle2;
  BD_IOControls_In_InputControl PECUPushButton;
  BD_IOControls_In_InputControl Microphone;
  BD_IOControls_In_InputControl DriversBackDoor;
  BD_IOControls_In_InputControl PantographIsolationCock;
  BD_IOControls_In_InputControl VCBIsolationCock;
  BD_IOControls_In_InputControl ORDPlunger;
} BD_IOControls_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_Effects_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_Effects_

typedef struct {
  real_T DegradedTrack;
  real_T OnRoughTrack;
} BD_SimIntegration_In_Vehicle_MotionBaseController_Effects;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning_

typedef struct {
  real_T HeadingRateLimit;
  real_T PitchRateLimit;
  real_T RollRateLimit;
  real_T LinearVelocitySaturation;
  real_T LinearAccelerationSaturation;
  real_T LinearVelocityLPFConstant;
  real_T LinearAccelerationLPFConstant;
  real_T AngularVelocitySaturation;
  real_T AngularAccelerationSaturation;
  real_T AngularVelocityLPFConstant;
  real_T AngularAccelerationLPFConstant;
  real_T RoughnessProfileType;
  real_T RoughnessProfileFactor;
  real_T RoughnessProfileFrequencyFactor;
  real_T RoughnessProfileSpeedFactor;
  real_T RoughnessProfileSpeedSaturation;
} BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_In_Vehicle_MotionBaseController_

typedef struct {
  BD_SimIntegration_In_Vehicle_MotionBaseController_Effects Effects;
  BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning Tuning;
} BD_SimIntegration_In_Vehicle_MotionBaseController;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_

typedef struct {
  real_T VehicleVelocity;
  real_T WheelSpeed[6];
  real_T BrakeCylinderPressure[6];
  real_T ParkBrakePressure[6];
  real_T ManualHandBrakeApplication;
  real_T ElectricParkBrakeApplication;
} BD_TrainBrakes_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_Overrides_

typedef struct {
  real_T FrictionBrakeForceVariation;
  real_T ParkBrakeOverride;
} BD_TrainBrakes_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_In_Vehicle_Faults_

typedef struct {
  real_T BrakeShoeOverheatFault;
} BD_TrainBrakes_In_Vehicle_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_Axle_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_Axle_

typedef struct {
  real_T BrakingPower;
  real_T BrakingForce;
  real_T BrakeShoeForce;
  real_T BrakeShoeTemperature;
  real_T BrakeShoeEfficiency;
  real_T BrakeDiscForce;
  real_T NormalBrakePistonForce;
} BD_TrainBrakes_Out_Vehicle_Axle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_States_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_States_

typedef struct {
  real_T BCPEngaged;
  real_T BCPEngagedBogie1;
  real_T BCPEngagedBogie2;
  real_T WheelBrakeBlocks;
  real_T WheelBrakeBlocksBogie1;
  real_T WheelBrakeBlocksBogie2;
} BD_TrainBrakes_Out_Vehicle_States;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TrainBrakes_Out_Vehicle_

typedef struct {
  BD_TrainBrakes_Out_Vehicle_Axle Axle[6];
  BD_TrainBrakes_Out_Vehicle_States States;
} BD_TrainBrakes_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Onboard_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Onboard_

typedef struct {
  real_T PowerSupply;
  real_T CabinActivation;
  real_T DriverModeSelection;
  real_T ModeSelectorPosition;
  real_T ATCBypassState;
  real_T TBCPosition;
  real_T ATOStartButton;
  real_T UTOStartButton;
  real_T ATCSBResetButton;
  real_T NoEmergencyBrake;
  real_T NoDoorEnableBypass;
  real_T TrainDoorClosedAndLocked;
  real_T EmergencyDoorNotOpen;
  real_T WakeUpStatus;
  real_T PassengerEmergencyAlarm;
  real_T FireSmokeInd;
  real_T MechanicalCoupling;
  real_T ROSPB;
  real_T UTBPB;
  real_T TrainIntegrity;
  real_T TCMSSpeedLimit;
  real_T TCMSSpeedLimitCause;
} BD_CBTC_Out_Vehicle_Onboard;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Platform_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Platform_

typedef struct {
  real_T LeftSideDoorOpenRequest;
  real_T RightSideDoorOpenRequest;
  real_T LeftSideDoorCloseRequest;
  real_T RightSideDoorCloseRequest;
  real_T Door1Inhibited;
  real_T Door2Inhibited;
  real_T Door3Inhibited;
  real_T Door4Inhibited;
  real_T LeftSideDoorEnable;
  real_T RightSideDoorEnable;
} BD_CBTC_Out_Vehicle_Platform;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Electrical_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_Electrical_

typedef struct {
  boolean_T ATOTraction;
  boolean_T ATONotBrake;
  real_T ATOTBDemand;
  boolean_T NoEmergencyBrakeOrder;
  boolean_T ROSIndication;
  boolean_T ATOStartIndication;
  boolean_T ATCSBResetIndication;
  boolean_T LeftHoldDoorClose;
  boolean_T RightHoldDoorClose;
  boolean_T ATCZeroSpeed;
  real_T WakeUpCommand;
  real_T UTOPBIndicator;
  real_T UTOModeActive;
  real_T ATCCabActivation;
  real_T NotImmobilise;
  real_T TractionForward;
  real_T EmergencyDetrainmentDoorLocked;
} BD_CBTC_Out_Vehicle_Electrical;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_TCMS_

typedef struct {
  boolean_T ATOTraction;
  boolean_T ATOBrake;
  real_T ATOTBDemand;
  boolean_T NoServiceBrake;
  boolean_T NotImmobilise;
  real_T ATOState;
  real_T RollbackDetected;
  real_T LeftDoorCloseIndicator;
  real_T RightDoorCloseIndicator;
  real_T LeftDoorOpenATCReq;
  real_T RightDoorOpenATCReq;
  real_T LeftDoorCloseATCReq;
  real_T RightDoorCloseATCReq;
} BD_CBTC_Out_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_DMI_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_DMI_

typedef struct {
  real_T PowerOn;
  real_T CabActive;
  real_T NeutralSection;
} BD_CBTC_Out_Vehicle_DMI;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_CBTC_Out_Vehicle_

typedef struct {
  BD_CBTC_Out_Vehicle_Onboard OnBoard;
  BD_CBTC_Out_Vehicle_Platform Platform;
  BD_CBTC_Out_Vehicle_Electrical Electrical;
  BD_CBTC_Out_Vehicle_TCMS TCMS;
  BD_CBTC_Out_Vehicle_DMI DMI;
} BD_CBTC_Out_Vehicle;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_
#define DEFINED_TYPEDEF_FOR_BD_CouplingSystem_Out_Vehicle_Coupler_

typedef struct {
  BD_CouplingSystem_Out_Vehicle_SingleCoupler Coupler[2];
} BD_CouplingSystem_Out_Vehicle_Coupler;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_DoorSystem_In_Overrides_

typedef struct {
  real_T AllDoorsLeftOpen;
  real_T AllDoorsRightOpen;
} BD_DoorSystem_In_Overrides;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Drag_
#define DEFINED_TYPEDEF_FOR_BD_TrainDynamics_Out_Vehicle_Drag_

typedef struct {
  real_T AerodynamicDragForce;
  real_T BearingDragForce;
  real_T LateralDragForce;
  real_T AdditionalNonWheelDragForce;
} BD_TrainDynamics_Out_Vehicle_Drag;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Coupling_
#define DEFINED_TYPEDEF_FOR_BD_ElectricalSystem_Out_Vehicle_Coupling_

typedef struct {
  real_T ElectricalCouplerState;
  real_T UncoupleCmd;
} BD_ElectricalSystem_Out_Vehicle_Coupling;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Control_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Control_

typedef struct {
  boolean_T PantoUpCommand;
  boolean_T PantoDownCommand;
  boolean_T PantoEmergencyDownCommand;
  boolean_T PantoIsolationCommand;
} BD_PantographSystem_In_Vehicle_Control;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Electrical_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Electrical_

typedef struct {
  boolean_T PantoControlPower;
  boolean_T PantoMotorPower;
  boolean_T PantoADDFault;
  boolean_T PantoORDFault;
  boolean_T PantoRaiseFailure;
  boolean_T PantoLoweringFailure;
} BD_PantographSystem_In_Vehicle_Electrical;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Pneumatics_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Pneumatics_

typedef struct {
  boolean_T PantoPneumaticSupply;
} BD_PantographSystem_In_Vehicle_Pneumatics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Environment_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Environment_

typedef struct {
  real_T LineVoltage;
  real_T OverheadLinePresent;
  real_T NeutralSection;
} BD_PantographSystem_In_Vehicle_Environment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_

typedef struct {
  BD_PantographSystem_In_Vehicle_Control Control;
  BD_PantographSystem_In_Vehicle_Electrical Electrical;
  BD_PantographSystem_In_Vehicle_Pneumatics Pneumatics;
  BD_PantographSystem_In_Vehicle_Environment Environment;
} BD_PantographSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Faults_

typedef struct {
  real_T PlaceHolder;
} BD_PantographSystem_In_Vehicle_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Overrides_

typedef struct {
  boolean_T PantoUPOverride;
} BD_PantographSystem_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_TCMS_Messages_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_TCMS_Messages_

typedef struct {
  boolean_T PantoADDFaultMessage;
  boolean_T PantoORDFaultMessage;
  boolean_T PantoRaiseFailureMessage;
} BD_PantographSystem_Out_Vehicle_TCMS_Messages;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_TCMS_

typedef struct {
  BD_PantographSystem_Out_Vehicle_TCMS_Messages Messages;
} BD_PantographSystem_Out_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Out_Vehicle_

typedef struct {
  real_T PantographPosition;
  boolean_T PantoUpStatus;
  boolean_T PantoDownStatus;
  boolean_T PantoIsolatedStatus;
  boolean_T PantoRising;
  boolean_T PantoLowering;
  real_T DetectedLineVoltage;
  boolean_T NoOverheadLineDetected;
  boolean_T PantographFault;
  BD_PantographSystem_Out_Vehicle_TCMS TCMS;
} BD_PantographSystem_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie_

typedef struct {
  real_T EPBrakingDemand;
} BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_

typedef struct {
  real_T NoEmergencyBrakeValve;
  real_T SandingValve;
  real_T ParkingBrakeApplyCmd;
  real_T ParkingBrakeReleaseCmd;
  real_T MainCompressorOn;
  real_T AuxiliaryCompressorOn;
  boolean_T RemoteMagnetValve1;
  boolean_T RemoteMagnetValve2;
  real_T PantographRaiseValve;
  real_T PantographEmergencyValve;
  real_T HornLowControl;
  real_T HornHighControl;
  boolean_T RemoteHornIsolate;
  boolean_T VCBCloseCmd;
  real_T TCMSBrakingDemand;
  BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie BogieControl[2];
} BD_PneumaticsSystem_In_Vehicle_ElectricalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_PhysicalSignals_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_PhysicalSignals_

typedef struct {
  real_T BogieSupportedMasses[2];
  real_T PneumaticallyCoupled[2];
} BD_PneumaticsSystem_In_Vehicle_PhysicalSignals;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_InputControlStates_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_InputControlStates_

typedef struct {
  real_T HornLowIsolationCock;
  real_T HornHighIsolationCock;
  real_T BrakeSupplyReservoirIsolationCock;
  real_T BrakeSupplyReservoirDrainCock;
  real_T InterCarIsolationCockEnd1;
  real_T InterCarIsolationCockEnd2;
  real_T MainReservoirIsolationCock;
  real_T MainReservoirDrainCock;
  real_T MainAirSupplyIsolationCock;
  real_T AirSuspensionSystemIsolationCockBogie1;
  real_T AirSuspensionSystemIsolationCockBogie2;
  real_T AirSuspensionSystemDrainCockBogie1;
  real_T AirSuspensionSystemDrainCockBogie2;
  real_T AuxiliaryCompressorIsolationCock;
  real_T AuxiliaryReservoirIsolationCock;
  real_T AuxiliaryReservoirDrainCock;
  real_T PantographAirSupplyIsolationCock;
  real_T BrakeCylinderIsolationCockBogie1;
  real_T BrakeCylinderIsolationCockBogie2;
  real_T ParkingBrakeIsolationCockBogie1;
  real_T ParkingBrakeIsolationCockBogie2;
  real_T ParkingBrakeManualReleaseBogie1Handle1;
  real_T ParkingBrakeManualReleaseBogie1Handle2;
  real_T ParkingBrakeManualReleaseBogie2Handle1;
  real_T ParkingBrakeManualReleaseBogie2Handle2;
  real_T SandingSystemIsolationCockBogie1;
  real_T SandingSystemIsolationCockBogie2;
  real_T UncouplingIsolationCock;
  real_T AirSuspensionReservoirIsolationCock;
  real_T EPIsolationCock;
  real_T VCBIsolationCock;
  real_T ORDPlunger;
} BD_PneumaticsSystem_In_Vehicle_InputControlStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_

typedef struct {
  BD_PneumaticsSystem_In_Vehicle_ElectricalSignals ElectricalSignals;
  BD_PneumaticsSystem_In_Vehicle_PhysicalSignals PhysicalSignals;
  BD_PneumaticsSystem_In_Vehicle_InputControlStates InputControlStates;
} BD_PneumaticsSystem_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Overrides_

typedef struct {
  real_T Reset;
  real_T StartupState;
} BD_PneumaticsSystem_In_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_In_Vehicle_Faults_

typedef struct {
  real_T HeavyWheelSlip;
  real_T BECU1AxleLockedWheelSet1;
  real_T BECU1ServiceBrakeFailure;
  real_T BECU1EmergencyBrakeFailure;
  real_T AirSuspensionBogie1Deflated;
  real_T BrakeDemandSignalFailure;
  real_T ParkingBrakeApplicationFailure;
  real_T ParkingBrakeReleaseFailure;
  real_T BECUMajorFault;
  real_T PressureGuageNotWorking;
  real_T PantographPipeLowPressure;
  real_T BECU2AxleLockedWheelSet2;
  real_T BECU2EmergencyBrakeFailure;
  real_T BECU1BrakeNotApplied;
  real_T BECU1BrakeNotReleased;
  real_T BECU1CarLoadPressureLow;
  real_T BECU2CarLoadPressureLow;
  real_T BECULowRPressure;
  real_T BECU1LoadPressureLow;
  real_T ORDIntervention;
} BD_PneumaticsSystem_In_Vehicle_Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_AxleBrakes_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_AxleBrakes_

typedef struct {
  real_T BrakeCylinderPressures[6];
  real_T ParkBrakePressures[6];
} BD_PneumaticsSystem_Out_Vehicle_AxleBrakes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Audio_

typedef struct {
  real_T HornLow;
  real_T HornHigh;
  real_T PneumaticPressureRelease;
  boolean_T EmergencyBrakeActive;
} BD_PneumaticsSystem_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie_

typedef struct {
  real_T BrakeCylinderControlPressure;
  real_T BrakeCylinderPressure[2];
  real_T ParkBrakePressure;
  real_T SandingSystemPressure;
  real_T AirSuspensionPressure;
  real_T AirSuspPressureDiff;
} BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Debug_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Debug_

typedef struct {
  real_T BrakeReservoirPressure;
  real_T MainReservoirPressure;
  real_T MainReservoirPipePressure;
  real_T AuxiliaryReservoirPressure;
  real_T PantographCylinderPressure;
  real_T VCBCylinderPressure;
  BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie Bogie[2];
} BD_PneumaticsSystem_Out_Vehicle_Debug;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie_

typedef struct {
  real_T BrakeCylinderPressureGauge;
  real_T ParkBrakePressureGauge;
} BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Gauges_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Gauges_

typedef struct {
  real_T MainReservoirPressureGauge;
  real_T SRPressureGauge;
  BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie Bogie[2];
} BD_PneumaticsSystem_Out_Vehicle_Gauges;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie_

typedef struct {
  real_T BrakeCylinderPressureSwitch;
  real_T ParkBrakePressureSwitch;
  real_T AirSuspensionPressureSwitch;
  real_T SandingSystemPressureSwitch;
} BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Switches_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Switches_

typedef struct {
  real_T BrakeReservoirPressureSwitch;
  real_T HornHighPressureSwitch;
  real_T HornLowPressureSwitch;
  real_T MainReservoirPressureSwitch;
  real_T AuxiliaryReservoirPressureSwitch;
  real_T MainReservoirPipePressureSwitch;
  real_T MRPS_TractionCutout;
  real_T PS3;
  real_T PS2;
  real_T VCBPressureSwitch;
  BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie Bogie[2];
} BD_PneumaticsSystem_Out_Vehicle_Switches;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie_

typedef struct {
  real_T BrakeCylinderControlPressure;
  real_T BrakeCylinderControlVolumePressure;
  real_T BrakeReservoirPressure;
  real_T AirSuspensionLoadPressure;
} BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Transducers_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_Transducers_

typedef struct {
  BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie Bogie[2];
} BD_PneumaticsSystem_Out_Vehicle_Transducers;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie_

typedef struct {
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
} BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_TCMS_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_TCMS_

typedef struct {
  BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie Bogie[2];
} BD_PneumaticsSystem_Out_Vehicle_TCMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PneumaticsSystem_Out_Vehicle_

typedef struct {
  BD_PneumaticsSystem_Out_Vehicle_AxleBrakes AxleBrakes;
  BD_PneumaticsSystem_Out_Vehicle_Audio Audio;
  BD_PneumaticsSystem_Out_Vehicle_Debug Debug;
  BD_PneumaticsSystem_Out_Vehicle_Gauges PressureGauges;
  BD_PneumaticsSystem_Out_Vehicle_Switches PressureSwitches;
  BD_PneumaticsSystem_Out_Vehicle_Transducers PressureTransducers;
  BD_PneumaticsSystem_Out_Vehicle_TCMS TCMS;
} BD_PneumaticsSystem_Out_Vehicle;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_BrakingSystem_
#define DEFINED_TYPEDEF_FOR_BD_TCMSSystem_In_Vehicle_BrakingSystem_

typedef struct {
  real_T BrakingForce;
} BD_TCMSSystem_In_Vehicle_BrakingSystem;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_Audio_

typedef struct {
  real_T TractionEDPower;
  real_T WheelAngularVelocity;
} BD_TractionSystem_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_TractionSystem_Out_Vehicle_

typedef struct {
  BD_TractionSystem_Out_Vehicle_TCU TractionControl;
  BD_TractionSystem_Out_Vehicle_Dynamics Dynamics;
  BD_TractionSystem_Out_Vehicle_Audio Audio;
} BD_TractionSystem_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Vehicle_Processed_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_Vehicle_Processed_

typedef struct {
  BD_DoorSystem_In_Door_Faults DoorFaults;
  BD_ElectricalSystem_In_Faults ElectricalFaults;
  BD_PantographSystem_In_Vehicle_Faults PantographFaults;
  BD_PneumaticsSystem_In_Vehicle_Faults PneumaticsFaults;
  BD_TCMSSystem_In_Vehicle_Faults TCMSFaults;
  BD_TractionSystem_In_Faults TractionFaults;
} BD_SimIntegration_Faults_Vehicle_Processed;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_IOControls_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Faults_IOControls_

typedef struct {
  boolean_T CCMCBInternalRequest;
  boolean_T WWCBInternalRequest;
  boolean_T CELCBInternalRequest;
  boolean_T HLCBInternalRequest;
  boolean_T MCBPAGroupOpenInternalRequest;
  boolean_T MCB110VDCGroupOpenInternalRequest;
  boolean_T MCBLightGroupOpenInternalRequest;
  boolean_T MCBLightSaloonGroupOpenInternalRequest;
  boolean_T MCBDoorGroupOpenInternalRequest;
  boolean_T MCBBrakeGroupOpenInternalRequest;
  boolean_T MCBAPSGroupOpenInternalRequest;
  boolean_T MCBTCMSGroupOpenInternalRequest;
  boolean_T MCBSignallingGroupOpenInternalRequest;
  boolean_T CECBOpenInternalRequest;
  boolean_T ELCB1OpenInternalRequest;
  boolean_T ELCB2OpenInternalRequest;
  boolean_T ILCB1OpenInternalRequest;
  boolean_T ILCB2OpenInternalRequest;
  boolean_T APSCBOpenInternalRequest;
  boolean_T UCCBOpenInternalRequest;
  boolean_T PANCBOpenInternalRequest;
  boolean_T MCBHVACGroupOpenInternalRequest;
  boolean_T ORDPlungerInternalRequest;
  boolean_T APSICBInternalRequest;
  boolean_T FDSCBInternalRequest;
  boolean_T SAC1CBInternalRequest;
  boolean_T SAC2CBInternalRequest;
} BD_SimIntegration_Faults_IOControls;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_InputStates_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_InputStates_

typedef struct {
  real_T EmergencyBrakePB;
  real_T HornPB;
  real_T CabConsoleLightPB;
  real_T DoorProvenLoopCutoutPB;
  real_T LeftDoorClosePBOperatingPanel1;
  real_T RightDoorClosePBOperatingPanel1;
  real_T LeftDoorOpenPBOperatingPanel1;
  real_T RightDoorOpenPBOperatingPanel1;
  real_T CabMainLightPB;
  real_T ParkingBrakeOnSwitch;
  real_T ParkingBrakeOffSwitch;
  real_T DoorCloseAnnouncementPB;
  real_T ROSPB;
  real_T UTOPB;
  real_T ATOStartPB;
  real_T EmergencyBrakeResetPB;
  real_T ControlKey;
  real_T ModeSelector;
  real_T MasterControllerHandle;
  real_T DeadmanSafetyDevice;
  real_T CallOnLightPB;
  real_T VCBOpenPB;
  real_T WiperSelectionSwitch;
  real_T WiperPump;
  real_T LIMPHomePB;
  real_T PowerOffPB;
  real_T PantoDownPB;
  real_T VCBClosePB;
  real_T LeftDoorOpenPBOperatingPanel2;
  real_T LeftDoorOpenPB1OperatingPanel2;
  real_T LeftDoorClosePBOperatingPanel2;
  real_T PantoUpPB;
  real_T SafetyCutoutSS;
  real_T BrakeLoopCutoutSS;
  real_T PantoSelector;
  real_T DeadmanBypassSwitch;
  real_T HeadLightSwitch;
  real_T UncouplePB;
  real_T FlasherLightPB;
  real_T FloodLightPB;
  real_T BatteryResetPB;
  real_T RightDoorOpenPBOperatingPanel5;
  real_T RightDoorOpenPB1OperatingPanel5;
  real_T RightDoorClosePBOperatingPanel5;
  real_T DoorProvenLoopOutputSwitch;
  real_T LampTestPB;
  real_T WFLTestPB;
  real_T WiperControlSwitch;
  real_T EmergencyStopPB;
  real_T HoldDoorCloseBypassSS;
  real_T CabBoosterFanSS;
  real_T EmergencyBrakePBBypassSS;
  real_T CabEEDLeft;
  real_T CabEEDRight;
  real_T SafetyCover;
  real_T DummyCover;
  real_T RampCoverLockingLever;
  real_T RampCover;
  real_T RampHandle;
  real_T RampEndSupport;
  real_T RampMiddleSupport;
  real_T WinderHandlesAccessCover;
  real_T LargeHandle;
  real_T RampWinder;
  real_T SmallHandle;
  real_T EmergencyDoorGasSpring;
  real_T DoorWinder;
  real_T EBLR2CB;
  real_T EBMVCB;
  real_T EDCB;
  real_T ELCB1;
  real_T ELCB2;
  real_T ERCB;
  real_T HCB;
  real_T HLLCB;
  real_T HLRCB;
  real_T ILCB1;
  real_T ILCB2;
  real_T LDICB;
  real_T LDLCB;
  real_T LDRCB;
  real_T MLCB;
  real_T MMCB;
  real_T NBCB;
  real_T NVICB;
  real_T OCCB1;
  real_T OCCB2;
  real_T ODDCB;
  real_T PBCB;
  real_T PISCB1;
  real_T PISCB2;
  real_T POCB;
  real_T PPU1CB;
  real_T PPU2CB;
  real_T PPU3CB;
  real_T RIO1CB;
  real_T RIO2CB;
  real_T SIOCB1;
  real_T SIOCB2;
  real_T SSICB;
  real_T TBCCB1;
  real_T TBCCB2;
  real_T TBNCB;
  real_T TDICB;
  real_T TLLCB;
  real_T TLRCB;
  real_T TRIVCB;
  real_T TVDUCB;
  real_T TWVCB;
  real_T VCCBOrUCCB;
  real_T VCBCCB;
  real_T VIO1CB;
  real_T VIO2CB;
  real_T WFLCB;
  real_T WIFICB;
  real_T WWCB;
  real_T BECUCB1;
  real_T BECUCB2;
  real_T BECUCB3;
  real_T RSACB;
  real_T CMCCB;
  real_T CILCB;
  real_T CICB;
  real_T CELCB;
  real_T CECB;
  real_T CDUCB;
  real_T CCNVIO1CB;
  real_T CBTCCB1;
  real_T CBFCCB;
  real_T CBFCB;
  real_T C1CB;
  real_T BLCB;
  real_T ZVBACB;
  real_T EBLR1CB;
  real_T DRCB;
  real_T DPLCB;
  real_T DMICB;
  real_T DLCB;
  real_T DIOCB2;
  real_T DIOCB1;
  real_T CSCCB;
  real_T CSBCB;
  real_T CSACB;
  real_T CRSBCB;
  real_T SOCB2;
  real_T SOCB1;
  real_T MSOCB5;
  real_T MSOCB4;
  real_T MSOCB3;
  real_T MSOCB2;
  real_T MSOCB1;
  real_T HVAC1;
  real_T SAC2CCB;
  real_T HVAC2;
  real_T SAC1CCB;
  real_T CMCB;
  real_T AC2CB;
  real_T AC1CB;
  real_T FDSCB;
  real_T BCBCB;
  real_T ERVRCB1;
  real_T ERVRCB2;
  real_T ESKCB;
  real_T HMCB;
  real_T SP1CB;
  real_T SP2CB;
  real_T SP3CB;
  real_T SP4CB;
  real_T SP5CB;
  real_T SPCB6;
  real_T SPCB7;
  real_T SPCB8;
  real_T RPTCB;
  real_T TERCB1;
  real_T TERCB2;
  real_T SPSW;
  real_T SPPB;
  real_T APSCB;
  real_T APSICB;
  real_T BCGCB;
  real_T DSCB;
  real_T MTBMCCB;
  real_T PADCB;
  real_T PANCB;
  real_T SSCB;
  real_T PTCB;
  real_T VCBCB;
  real_T SP12CB;
  real_T MTBM1CB;
  real_T MTBM2CB;
  real_T SP11CB;
  real_T SP6CB;
  real_T MTOPCB;
  real_T ORDCOS;
  real_T ADDCOS;
  real_T LeftDoor1DCUCB;
  real_T LeftDoor2DCUCB;
  real_T LeftDoor3DCUCB;
  real_T LeftDoor4DCUCB;
  real_T RightDoor1DCUCB;
  real_T RightDoor2DCUCB;
  real_T RightDoor3DCUCB;
  real_T RightDoor4DCUCB;
  real_T LeftDoor1Coving;
  real_T LeftDoor2Coving;
  real_T LeftDoor3Coving;
  real_T LeftDoor4Coving;
  real_T RightDoor1Coving;
  real_T RightDoor2Coving;
  real_T RightDoor3Coving;
  real_T RightDoor4Coving;
  real_T LeftDoor1EED;
  real_T LeftDoor2EED;
  real_T LeftDoor3EED;
  real_T LeftDoor4EED;
  real_T RightDoor1EED;
  real_T RightDoor2EED;
  real_T RightDoor3EED;
  real_T RightDoor4EED;
  real_T LeftDoor1ManualClose;
  real_T LeftDoor2ManualClose;
  real_T LeftDoor3ManualClose;
  real_T LeftDoor4ManualClose;
  real_T RightDoor1ManualClose;
  real_T RightDoor2ManualClose;
  real_T RightDoor3ManualClose;
  real_T RightDoor4ManualClose;
  real_T LeftDoor1ManualOpen;
  real_T LeftDoor2ManualOpen;
  real_T LeftDoor3ManualOpen;
  real_T LeftDoor4ManualOpen;
  real_T RightDoor1ManualOpen;
  real_T RightDoor2ManualOpen;
  real_T RightDoor3ManualOpen;
  real_T RightDoor4ManualOpen;
  real_T LeftDoor1Lockout;
  real_T LeftDoor2Lockout;
  real_T LeftDoor3Lockout;
  real_T LeftDoor4Lockout;
  real_T RightDoor1Lockout;
  real_T RightDoor2Lockout;
  real_T RightDoor3Lockout;
  real_T RightDoor4Lockout;
  real_T LeftDoorEADCover;
  real_T RightDoorEADCover;
  real_T LeftDoorEAD;
  real_T RightDoorEAD;
  real_T ParkBrakeIsolationCockBogie1;
  real_T ParkBrakeIsolationCockBogie2;
  real_T MRIsolationCock;
  real_T UncouplingCock;
  real_T Horn1IsolationCock;
  real_T Horn2IsolationCock;
  real_T MREPIsolationCockEnd1;
  real_T BIC1Inside;
  real_T BIC1Outside;
  real_T BIC2Inside;
  real_T BIC2Outside;
  real_T MREPIsolationCockEnd2;
  real_T EPIC;
  real_T ASCOEnd1;
  real_T ASCOEnd2;
  real_T ASIsolationCock;
  real_T SR;
  real_T ParkingBrakeManualReleaseBogie1Handle1;
  real_T ParkingBrakeManualReleaseBogie1Handle2;
  real_T ParkingBrakeManualReleaseBogie2Handle1;
  real_T ParkingBrakeManualReleaseBogie2Handle2;
  real_T PECUPushButton;
  real_T Microphone;
  real_T DriversBackDoor;
  real_T PantographIsolationCock;
  real_T VCBIsolationCock;
  real_T ORDPlunger;
} BD_IOControls_Out_Vehicle_InputStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_MCBTripStates_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_MCBTripStates_

typedef struct {
  real_T EBLR2CB;
  real_T EBMVCB;
  real_T EDCB;
  real_T ELCB1;
  real_T ELCB2;
  real_T ERCB;
  real_T HCB;
  real_T HLLCB;
  real_T HLRCB;
  real_T ILCB1;
  real_T ILCB2;
  real_T LDICB;
  real_T LDLCB;
  real_T LDRCB;
  real_T MLCB;
  real_T MMCB;
  real_T NBCB;
  real_T NVICB;
  real_T OCCB1;
  real_T OCCB2;
  real_T ODDCB;
  real_T PBCB;
  real_T PISCB1;
  real_T PISCB2;
  real_T POCB;
  real_T PPU1CB;
  real_T PPU2CB;
  real_T PPU3CB;
  real_T RIO1CB;
  real_T RIO2CB;
  real_T SIOCB1;
  real_T SIOCB2;
  real_T SSICB;
  real_T TBCCB1;
  real_T TBCCB2;
  real_T TBNCB;
  real_T TDICB;
  real_T TLLCB;
  real_T TLRCB;
  real_T TRIVCB;
  real_T TVDUCB;
  real_T TWVCB;
  real_T VCCBOrUCCB;
  real_T VCBCCB;
  real_T VIO1CB;
  real_T VIO2CB;
  real_T WFLCB;
  real_T WIFICB;
  real_T WWCB;
  real_T BECUCB1;
  real_T BECUCB2;
  real_T BECUCB3;
  real_T RSACB;
  real_T CMCCB;
  real_T CILCB;
  real_T CICB;
  real_T CELCB;
  real_T CECB;
  real_T CDUCB;
  real_T CCNVIO1CB;
  real_T CBTCCB1;
  real_T CBFCCB;
  real_T CBFCB;
  real_T C1CB;
  real_T BLCB;
  real_T ZVBACB;
  real_T EBLR1CB;
  real_T DRCB;
  real_T DPLCB;
  real_T DMICB;
  real_T DLCB;
  real_T DIOCB2;
  real_T DIOCB1;
  real_T CSCCB;
  real_T CSBCB;
  real_T CSACB;
  real_T CRSBCB;
  real_T SOCB2;
  real_T SOCB1;
  real_T MSOCB5;
  real_T MSOCB4;
  real_T MSOCB3;
  real_T MSOCB2;
  real_T MSOCB1;
  real_T HVAC1;
  real_T SAC2CCB;
  real_T HVAC2;
  real_T SAC1CCB;
  real_T CMCB;
  real_T AC2CB;
  real_T AC1CB;
  real_T FDSCB;
  real_T BCBCB;
  real_T ERVRCB1;
  real_T ERVRCB2;
  real_T ESKCB;
  real_T HMCB;
  real_T SP1CB;
  real_T SP2CB;
  real_T SP3CB;
  real_T SP4CB;
  real_T SP5CB;
  real_T SPCB6;
  real_T SPCB7;
  real_T SPCB8;
  real_T RPTCB;
  real_T TERCB1;
  real_T TERCB2;
  real_T APSCB;
  real_T APSICB;
  real_T BCGCB;
  real_T DSCB;
  real_T MTBMCCB;
  real_T PADCB;
  real_T PANCB;
  real_T SSCB;
  real_T PTCB;
  real_T VCBCB;
  real_T SP12CB;
  real_T MTBM1CB;
  real_T MTBM2CB;
  real_T SP11CB;
  real_T SP6CB;
  real_T MTOPCB;
  real_T LeftDoor1DCUCB;
  real_T LeftDoor2DCUCB;
  real_T LeftDoor3DCUCB;
  real_T LeftDoor4DCUCB;
  real_T RightDoor1DCUCB;
  real_T RightDoor2DCUCB;
  real_T RightDoor3DCUCB;
  real_T RightDoor4DCUCB;
} BD_IOControls_Out_Vehicle_MCBTripStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_OutputStates_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_OutputStates_

typedef struct {
  real_T HornPBLamp;
  real_T CabConsoleLightPBLamp;
  real_T CabConsoleLight;
  real_T LeftDoorClosePBOperatingPanel1Lamp;
  real_T RightDoorClosePBOperatingPanel1Lamp;
  real_T LeftDoorOpenPBOperatingPanel1Lamp;
  real_T RightDoorOpenPBOperatingPanel1Lamp;
  real_T CabMainLightPBLamp;
  real_T CabMainLight;
  real_T ParkingBrakeOnSwitchLamp;
  real_T ParkingBrakeOffSwitchLamp;
  real_T DoorCloseAnnouncementPBLamp;
  real_T ROSPBLamp;
  real_T UTOPBLamp;
  real_T ATOStartPBLamp;
  real_T EmergencyBrakeResetPBLamp;
  real_T MRAirGaugeMRPressure;
  real_T BCSRDualPressureGaugeBCPressure;
  real_T BCSRDualPressureGaugeSRPressure;
  real_T CallOnLightPBLamp;
  real_T VCBOpenPBLamp;
  real_T LIMPHomePBLamp;
  real_T PowerOffPBLamp;
  real_T PantoDownPBLamp;
  real_T VCBClosePBLamp;
  real_T LeftDoorOpenPBOperatingPanel2Lamp;
  real_T LeftDoorOpenPB1OperatingPanel2Lamp;
  real_T LeftDoorClosePBOperatingPanel2Lamp;
  real_T PantoUpPBLamp;
  real_T APSFaultIndicator;
  real_T PowerFaultIndicator;
  real_T EmergencyBrakeIndicator;
  real_T VCBTripIndicator;
  real_T LineVoltageIndicator;
  real_T OtherCabOccupiedIndicator;
  real_T ParkingBrakeIndicator;
  real_T AllDoorCloseIndicator;
  real_T HVACFaultIndicator;
  real_T SaloonDoorCloseIndicator;
  real_T UncouplePBLamp;
  real_T FlasherLightPBLamp;
  real_T FloodLightPBLamp;
  real_T BatteryResetPBLamp;
  real_T RightDoorOpenPBOperatingPanel5Lamp;
  real_T RightDoorOpenPB1OperatingPanel5Lamp;
  real_T RightDoorClosePBOperatingPanel5Lamp;
  real_T LampTestPBLamp;
  real_T WFLTestPBLamp;
  real_T DoorIndicator;
  real_T Ramp;
  real_T EmergencyDoor;
  real_T RampSupportDown;
  real_T GasSpringLocked;
  real_T LeftDoor1Position;
  real_T LeftDoor2Position;
  real_T LeftDoor3Position;
  real_T LeftDoor4Position;
  real_T RightDoor1Position;
  real_T RightDoor2Position;
  real_T RightDoor3Position;
  real_T RightDoor4Position;
  real_T LeftDoor1aPosition;
  real_T LeftDoor1InsideLamp;
  real_T LeftDoor2InsideLamp;
  real_T LeftDoor3InsideLamp;
  real_T LeftDoor4InsideLamp;
  real_T RightDoor1InsideLamp;
  real_T RightDoor2InsideLamp;
  real_T RightDoor3InsideLamp;
  real_T RightDoor4InsideLamp;
  real_T LeftDoor1OutsideLamp;
  real_T LeftDoor2OutsideLamp;
  real_T LeftDoor3OutsideLamp;
  real_T LeftDoor4OutsideLamp;
  real_T RightDoor1OutsideLamp;
  real_T RightDoor2OutsideLamp;
  real_T RightDoor3OutsideLamp;
  real_T RightDoor4OutsideLamp;
  real_T FloodLight;
  real_T FlasherLight;
  real_T UTOOrRMLight;
  real_T MarkerOrTailLight;
  real_T HeadLight;
  real_T WaitIndicator;
  real_T CallIndicator;
  real_T TalkIndicator;
  real_T PantographPosition;
  real_T WiperPositionLeft;
  real_T WiperPositionCenter;
  real_T WiperPositionRight;
  real_T WiperWash;
  real_T VehicleDerailed;
  real_T VehicleBogieDerailed;
} BD_IOControls_Out_Vehicle_OutputStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_IOControls_Out_Vehicle_

typedef struct {
  BD_IOControls_Out_Vehicle_InputStates InputStates;
  BD_IOControls_Out_Vehicle_MCBTripStates MCBTripStates;
  BD_IOControls_Out_Vehicle_OutputStates OutputStates;
} BD_IOControls_Out_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Audio_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Audio_

typedef struct {
  real_T VigilanceAlarm;
  real_T HornHigh;
  real_T HornLow;
  real_T Bell;
  real_T SaloonDoorOpeningBuzzer;
  real_T SaloonDoorClosingBuzzer;
  real_T DoorWarningBuzzer;
  real_T EEDEADOperated;
  real_T VCBOpenSound;
  real_T VCBCloseSound;
  real_T CompressorStartAndRunSound;
  real_T FlasherLightOperationSound;
  real_T DeadmanAlarm;
  real_T PantographLowering;
  real_T WheelSlip;
  real_T WheelSlide;
  real_T AirBrakeRelease;
  real_T PantographRaising;
  real_T WiperSound;
  real_T EmergencyBrakeApplicationSound;
  real_T BPVentAudio;
  real_T CollisionDetectionCoupling;
  real_T Derailment;
  real_T MechanicalUncouple;
  real_T PneumaticPressureRelease;
  real_T ObstacleSoftCollision;
} BD_SimIntegration_Out_Vehicle_Audio;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Train_Scoring_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Train_Scoring_

typedef struct {
  real_T TotalEnergyConsumption;
} BD_SimIntegration_Out_Train_Scoring;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Scoring_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_Scoring_

typedef struct {
  real_T VigilanceIntervention;
  real_T HornActivation;
} BD_SimIntegration_Out_Vehicle_Scoring;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Dynamics_Transform_
#define DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Dynamics_Transform_

typedef struct {
  real_T Position[3];
  real_T OrientationDCM[9];
  real_T OrientationQ[4];
  real_T H;
  real_T P;
  real_T R;
} BD_MotionBase_In_Vehicle_Dynamics_Transform;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Dynamics_
#define DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Dynamics_

typedef struct {
  BD_MotionBase_In_Vehicle_Dynamics_Transform Transform;
  real_T Velocity[3];
  real_T AngularVelocity[3];
  real_T Acceleration[3];
  real_T AngularAcceleration[3];
} BD_MotionBase_In_Vehicle_Dynamics;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Effects_
#define DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Effects_

typedef struct {
  BD_SimIntegration_In_Vehicle_MotionBaseController_Effects ExternalEffects;
  boolean_T LongitudinalJolt;
  boolean_T LateralJolt;
  boolean_T VerticalJolt;
  boolean_T VerticalJoltDown;
} BD_MotionBase_In_Vehicle_Effects;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Environment_
#define DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_Environment_

typedef struct {
  real_T Contact;
} BD_MotionBase_In_Vehicle_Environment;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_MotionBase_In_Vehicle_

typedef struct {
  BD_MotionBase_In_Vehicle_Dynamics Dynamics;
  BD_MotionBase_In_Vehicle_Effects Effects;
  BD_MotionBase_In_Vehicle_Environment Environment;
  BD_SimIntegration_In_Vehicle_MotionBaseController_Tuning Tuning;
  boolean_T MotionBaseSafetyCutout;
} BD_MotionBase_In_Vehicle;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_MotionBaseController_
#define DEFINED_TYPEDEF_FOR_BD_SimIntegration_Out_Vehicle_MotionBaseController_

typedef struct {
  real_T ApplyMotion;
  real_T ManualPosition[3];
  real_T LinearVelocity[3];
  real_T LinearAcceleration[3];
  real_T ManualOrientation[3];
  real_T AngularVelocity[3];
  real_T AngularAcceleration[3];
  real_T GravitationalAcceleration[3];
  real_T OrientationDCM[9];
} BD_SimIntegration_Out_Vehicle_MotionBaseController;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TrackEffectType_
#define DEFINED_TYPEDEF_FOR_TrackEffectType_

typedef enum {
  NoTrackEffect = 0,                   /* Default value */
  DegradedTrack,
  StandardTrack
} TrackEffectType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_iOPQUPViMP7klj2KCOPonE_
#define DEFINED_TYPEDEF_FOR_struct_iOPQUPViMP7klj2KCOPonE_

typedef struct {
  boolean_T ATOBrake;
  boolean_T ATOTraction;
  real_T ATOTBDemand;
} struct_iOPQUPViMP7klj2KCOPonE;

#endif

/* Parameters for system: '<S15>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_j_T_ P_CoreSubsys_BEML_EMU_j_T;

/* Parameters for system: '<S23>/NotInATO' */
typedef struct P_NotInATO_BEML_EMU_T_ P_NotInATO_BEML_EMU_T;

/* Parameters for system: '<S20>/CBTCModel' */
typedef struct P_CoreSubsys_BEML_EMU_i_T_ P_CoreSubsys_BEML_EMU_i_T;

/* Parameters for system: '<S146>/ConvertToCouplerBus' */
typedef struct P_CoreSubsys_BEML_EMU_ct_T_ P_CoreSubsys_BEML_EMU_ct_T;

/* Parameters for system: '<S145>/Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_c_T_ P_CoreSubsys_BEML_EMU_c_T;

/* Parameters for system: '<S148>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_ln_T_ P_CoreSubsys_BEML_EMU_ln_T;

/* Parameters for system: '<S311>/For Each Subsystem1' */
typedef struct P_CoreSubsys_BEML_EMU_ngo_T_ P_CoreSubsys_BEML_EMU_ngo_T;

/* Parameters for system: '<S309>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_ng_T_ P_CoreSubsys_BEML_EMU_ng_T;

/* Parameters for system: '<S316>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_fa_T_ P_CoreSubsys_BEML_EMU_fa_T;

/* Parameters for system: '<S337>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_ctkg_T_ P_CoreSubsys_BEML_EMU_ctkg_T;

/* Parameters for system: '<S351>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_mrlt_T_ P_CoreSubsys_BEML_EMU_mrlt_T;

/* Parameters for system: '<S347>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_mr_T_ P_CoreSubsys_BEML_EMU_mr_T;

/* Parameters for system: '<S359>/ExtractConfig' */
typedef struct P_CoreSubsys_BEML_EMU_ci_T_ P_CoreSubsys_BEML_EMU_ci_T;

/* Parameters for system: '<S373>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_ciae4_T_ P_CoreSubsys_BEML_EMU_ciae4_T;

/* Parameters for system: '<S372>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_ciae4o_T_ P_CoreSubsys_BEML_EMU_ciae4o_T;

/* Parameters for system: '<S366>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_ciae4ow_T_ P_CoreSubsys_BEML_EMU_ciae4ow_T;

/* Parameters for system: '<S358>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_cia_T_ P_CoreSubsys_BEML_EMU_cia_T;

/* Parameters for system: '<S389>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_d5hx4_T_ P_CoreSubsys_BEML_EMU_d5hx4_T;

/* Parameters for system: '<S383>/VehicleInputAdapter' */
typedef struct P_CoreSubsys_BEML_EMU_d5_T_ P_CoreSubsys_BEML_EMU_d5_T;

/* Parameters for system: '<S448>/IRQRequestStateMachine' */
typedef struct P_IRQRequestStateMachine_BEML_EMU_T_
  P_IRQRequestStateMachine_BEML_EMU_T;

/* Parameters for system: '<S426>/ControlStateRequest' */
typedef struct P_ControlStateRequest_BEML_EMU_T_
  P_ControlStateRequest_BEML_EMU_T;

/* Parameters for system: '<S426>/Chart' */
typedef struct P_Chart_BEML_EMU_T_ P_Chart_BEML_EMU_T;

/* Parameters for system: '<S400>/Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_g_T_ P_CoreSubsys_BEML_EMU_g_T;

/* Parameters for system: '<S660>/Subsystem1' */
typedef struct P_CoreSubsys_BEML_EMU_gmy0_T_ P_CoreSubsys_BEML_EMU_gmy0_T;

/* Parameters for system: '<S401>/InhibitsAndInternalRequests' */
typedef struct P_CoreSubsys_BEML_EMU_gmy_T_ P_CoreSubsys_BEML_EMU_gmy_T;

/* Parameters for system: '<S686>/VehicleEquipment' */
typedef struct P_VehicleEquipment_BEML_EMU_T_ P_VehicleEquipment_BEML_EMU_T;

/* Parameters for system: '<S685>/VehicleEquipment' */
typedef struct P_VehicleEquipment_BEML_EMU_b_T_ P_VehicleEquipment_BEML_EMU_b_T;

/* Parameters for system: '<S684>/VehicleEquipment' */
typedef struct P_VehicleEquipment_BEML_EMU_e_T_ P_VehicleEquipment_BEML_EMU_e_T;

/* Parameters for system: '<S683>/VehicleEquipment' */
typedef struct P_VehicleEquipment_BEML_EMU_n_T_ P_VehicleEquipment_BEML_EMU_n_T;

/* Parameters for system: '<S681>/VehicleEquipment4' */
typedef struct P_VehicleEquipment4_BEML_EMU_T_ P_VehicleEquipment4_BEML_EMU_T;

/* Parameters for system: '<S675>/VehicleConfigInterface' */
typedef struct P_CoreSubsys_BEML_EMU_gmy0o_T_ P_CoreSubsys_BEML_EMU_gmy0o_T;

/* Parameters for system: '<S734>/Subsystem1' */
typedef struct P_CoreSubsys_BEML_EMU_gmy0ogcc_T_
  P_CoreSubsys_BEML_EMU_gmy0ogcc_T;

/* Parameters for system: '<S750>/Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_gmy0ogccz5ddgv_T_
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddgv_T;

/* Parameters for system: '<S746>/For Each Subsystem' */
typedef struct P_CoreSubsys_BEML_EMU_gmy0ogccz5ddg_T_
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddg_T;

/* Parameters for system: '<S736>/VehicleLevelScoring' */
typedef struct P_CoreSubsys_BEML_EMU_jb_T_ P_CoreSubsys_BEML_EMU_jb_T;

/* Parameters for system: '<S737>/Input Adapter' */
typedef struct P_CoreSubsys_BEML_EMU_gx_T_ P_CoreSubsys_BEML_EMU_gx_T;

/* Parameters for system: '<S782>/Jolt Duration' */
typedef struct P_JoltDuration_BEML_EMU_T_ P_JoltDuration_BEML_EMU_T;

/* Parameters for system: '<S753>/MotionBasePerVehicle' */
typedef struct P_CoreSubsys_BEML_EMU_l3_T_ P_CoreSubsys_BEML_EMU_l3_T;

/* Parameters (default storage) */
typedef struct P_BEML_EMU_T_ P_BEML_EMU_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_BEML_EMU_T RT_MODEL_BEML_EMU_T;

#endif                                 /* RTW_HEADER_BEML_EMU_types_h_ */
