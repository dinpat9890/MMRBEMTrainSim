/*
 * TrainBrakes_types.h
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

#ifndef RTW_HEADER_TrainBrakes_types_h_
#define RTW_HEADER_TrainBrakes_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
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

/* Parameters for system: '<S4>/AxleBrakes' */
typedef struct P_CoreSubsys_TrainBrakes_l_T_ P_CoreSubsys_TrainBrakes_l_T;

/* Parameters for system: '<Root>/VehicleBrakes' */
typedef struct P_CoreSubsys_TrainBrakes_T_ P_CoreSubsys_TrainBrakes_T;

/* Parameters (default storage) */
typedef struct P_TrainBrakes_T_ P_TrainBrakes_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TrainBrakes_T RT_MODEL_TrainBrakes_T;

#endif                                 /* RTW_HEADER_TrainBrakes_types_h_ */
