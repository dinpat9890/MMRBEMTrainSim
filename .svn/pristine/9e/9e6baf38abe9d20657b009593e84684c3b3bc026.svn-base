/*
 * PantographSystem_types.h
 *
 * Code generation for model "PantographSystem".
 *
 * Model version              : 1.936
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PantographSystem_types_h_
#define RTW_HEADER_PantographSystem_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Prm_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Prm_

typedef struct {
  real_T PantoRaiseTime;
  real_T PantoLowerTime;
  real_T PantoEmergencyLowerTime;
} BD_PantographSystem_Prm;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_Cfg_Vehicle_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_Cfg_Vehicle_

typedef struct {
  boolean_T HasPanto;
  boolean_T PneumaticsPoweredPanto;
  boolean_T ElectricPoweredPanto;
} BD_PantographSystem_Cfg_Vehicle;

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

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Overrides_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Overrides_

typedef struct {
  boolean_T PantoUPOverride;
} BD_PantographSystem_In_Vehicle_Overrides;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Faults_
#define DEFINED_TYPEDEF_FOR_BD_PantographSystem_In_Vehicle_Faults_

typedef struct {
  real_T PlaceHolder;
} BD_PantographSystem_In_Vehicle_Faults;

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

/* Parameters for system: '<S18>/DOWN' */
typedef struct P_DOWN_PantographSystem_T_ P_DOWN_PantographSystem_T;

/* Parameters for system: '<Root>/PantographSystemPerVehicle' */
typedef struct P_CoreSubsys_PantographSystem_T_ P_CoreSubsys_PantographSystem_T;

/* Parameters (default storage) */
typedef struct P_PantographSystem_T_ P_PantographSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PantographSystem_T RT_MODEL_PantographSystem_T;

#endif                                /* RTW_HEADER_PantographSystem_types_h_ */
