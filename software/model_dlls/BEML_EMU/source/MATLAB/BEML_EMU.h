/*
 * BEML_EMU.h
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

#ifndef RTW_HEADER_BEML_EMU_h_
#define RTW_HEADER_BEML_EMU_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef BEML_EMU_COMMON_INCLUDES_
# define BEML_EMU_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* BEML_EMU_COMMON_INCLUDES_ */

#include "BEML_EMU_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Child system includes */
#include "ElectricalSystem.h"
#include "TCMSSystem.h"
#include "PneumaticsSystem.h"
#include "PantographSystem.h"
#include "DoorSystem.h"
#include "TrainBrakes.h"
#include "TractionSystem.h"
#include "TrainDynamics.h"
#include "IOControls.h"
#include "CouplingSystem.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals for system '<S20>/CBTCModel' */
typedef struct {
  real_T ATOTBDemand;
  boolean_T ATOBrake;
  boolean_T ATOTraction;
} B_CoreSubsys_BEML_EMU_m_T;

/* Block states (default storage) for system '<S20>/CBTCModel' */
typedef struct {
  real_T UnitDelay2_DSTATE;            /* '<S131>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S131>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S131>/Unit Delay' */
  real_T UD_DSTATE;                    /* '<S110>/UD' */
  real_T Integrator_DSTATE;            /* '<S115>/Integrator' */
  real_T UD_DSTATE_k;                  /* '<S65>/UD' */
  real_T Integrator_DSTATE_f;          /* '<S70>/Integrator' */
  int8_T If_ActiveSubsystem;           /* '<S23>/If' */
  boolean_T Memory_PreviousInput;      /* '<S140>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S141>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S142>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S143>/Memory' */
  boolean_T Relay_Mode;                /* '<S23>/Relay' */
  boolean_T ATO_MODE;                  /* '<S21>/ATO' */
} DW_CoreSubsys_BEML_EMU_k_T;

/* Block states (default storage) for system '<S316>/VehicleInputAdapter' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S333>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S334>/Memory' */
} DW_CoreSubsys_BEML_EMU_ep_T;

/* Block states (default storage) for system '<S358>/VehicleInputAdapter' */
typedef struct {
  boolean_T DelayInput1_DSTATE;        /* '<S377>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S378>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S379>/Memory' */
} DW_CoreSubsys_BEML_EMU_kvj_T;

/* Block states (default storage) for system '<S383>/VehicleInputAdapter' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S390>/UD' */
  real_T UD_DSTATE_n;                  /* '<S391>/UD' */
} DW_CoreSubsys_BEML_EMU_n0_T;

/* Block signals for system '<S448>/IRQRequestStateMachine' */
typedef struct {
  real_T TargetStateValue;             /* '<S448>/IRQRequestStateMachine' */
  boolean_T TriggerFaultRequest;       /* '<S448>/IRQRequestStateMachine' */
} B_IRQRequestStateMachine_BEML_EMU_T;

/* Block states (default storage) for system '<S448>/IRQRequestStateMachine' */
typedef struct {
  int32_T chartAbsoluteTimeCounter;    /* '<S448>/IRQRequestStateMachine' */
  int32_T durationLastReferenceTick_1; /* '<S448>/IRQRequestStateMachine' */
  uint8_T is_active_c5_IOStateMachinesLib;/* '<S448>/IRQRequestStateMachine' */
  uint8_T is_c5_IOStateMachinesLib;    /* '<S448>/IRQRequestStateMachine' */
  uint8_T is_ChangeIOControlState;     /* '<S448>/IRQRequestStateMachine' */
  uint8_T is_ApplyFault;               /* '<S448>/IRQRequestStateMachine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<S448>/IRQRequestStateMachine' */
} DW_IRQRequestStateMachine_BEML_EMU_T;

/* Block signals for system '<S426>/ControlStateRequest' */
typedef struct {
  real_T Switch1;                      /* '<S478>/Switch1' */
  boolean_T RelationalOperator;        /* '<S478>/Relational Operator' */
} B_ControlStateRequest_BEML_EMU_T;

/* Block states (default storage) for system '<S426>/ControlStateRequest' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S482>/Discrete-Time Integrator' */
  boolean_T ControlStateRequest_MODE;  /* '<S426>/ControlStateRequest' */
} DW_ControlStateRequest_BEML_EMU_T;

/* Block signals for system '<S426>/Chart' */
typedef struct {
  boolean_T TriggerFaultRequest;       /* '<S426>/Chart' */
  boolean_T UseFaultedTarget;          /* '<S426>/Chart' */
} B_Chart_BEML_EMU_T;

/* Block states (default storage) for system '<S426>/Chart' */
typedef struct {
  uint8_T is_active_c3_IOStateMachinesLib;/* '<S426>/Chart' */
  uint8_T is_c3_IOStateMachinesLib;    /* '<S426>/Chart' */
  uint8_T is_ChangeIOControlState;     /* '<S426>/Chart' */
  uint8_T is_ApplyFault;               /* '<S426>/Chart' */
} DW_Chart_BEML_EMU_T;

/* Block signals for system '<S400>/Subsystem' */
typedef struct {
  B_Chart_BEML_EMU_T sf_Chart_f;       /* '<S423>/Chart' */
  B_ControlStateRequest_BEML_EMU_T ControlStateRequest_a;/* '<S423>/ControlStateRequest' */
  B_Chart_BEML_EMU_T sf_Chart_k;       /* '<S424>/Chart' */
  B_ControlStateRequest_BEML_EMU_T ControlStateRequest_n;/* '<S424>/ControlStateRequest' */
  B_Chart_BEML_EMU_T sf_Chart_e;       /* '<S425>/Chart' */
  B_ControlStateRequest_BEML_EMU_T ControlStateRequest_i;/* '<S425>/ControlStateRequest' */
  B_Chart_BEML_EMU_T sf_Chart;         /* '<S426>/Chart' */
  B_ControlStateRequest_BEML_EMU_T ControlStateRequest;/* '<S426>/ControlStateRequest' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_in;/* '<S427>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_fm;/* '<S428>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_a;/* '<S429>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_d;/* '<S430>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_f;/* '<S431>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_hr;/* '<S432>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e5;/* '<S433>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e2;/* '<S434>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_i;/* '<S435>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h1;/* '<S436>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_c;/* '<S437>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_j;/* '<S438>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h;/* '<S439>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_p;/* '<S440>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_ma;/* '<S441>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_b;/* '<S442>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_o;/* '<S443>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_mb;/* '<S444>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_m;/* '<S445>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_l;/* '<S446>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e;/* '<S447>/IRQRequestStateMachine' */
  B_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine;/* '<S448>/IRQRequestStateMachine' */
  real_T DataTypeConversion6;          /* '<S409>/Data Type Conversion6' */
  real_T DataTypeConversion8;          /* '<S409>/Data Type Conversion8' */
  real_T DataTypeConversion10;         /* '<S409>/Data Type Conversion10' */
  real_T DataTypeConversion11;         /* '<S409>/Data Type Conversion11' */
  real_T DataTypeConversion13;         /* '<S409>/Data Type Conversion13' */
  real_T DataTypeConversion15;         /* '<S409>/Data Type Conversion15' */
  real_T DataTypeConversion17;         /* '<S409>/Data Type Conversion17' */
  real_T DataTypeConversion19;         /* '<S409>/Data Type Conversion19' */
  real_T DataTypeConversion21;         /* '<S409>/Data Type Conversion21' */
  real_T DataTypeConversion23;         /* '<S409>/Data Type Conversion23' */
  real_T DataTypeConversion41;         /* '<S409>/Data Type Conversion41' */
  boolean_T OR;                        /* '<S404>/OR' */
  boolean_T AND;                       /* '<S408>/AND' */
  boolean_T FixPtRelationalOperator;   /* '<S417>/FixPt Relational Operator' */
  boolean_T APSICBInternalRequest;     /* '<S409>/Rate Transition1' */
  boolean_T FDSCBInternalRequest;      /* '<S409>/Rate Transition2' */
  boolean_T SAC1CBInternalRequest;     /* '<S409>/Rate Transition3' */
  boolean_T SAC2CBInternalRequest;     /* '<S409>/Rate Transition4' */
} B_CoreSubsys_BEML_EMU_c_T;

/* Block states (default storage) for system '<S400>/Subsystem' */
typedef struct {
  DW_Chart_BEML_EMU_T sf_Chart_f;      /* '<S423>/Chart' */
  DW_ControlStateRequest_BEML_EMU_T ControlStateRequest_a;/* '<S423>/ControlStateRequest' */
  DW_Chart_BEML_EMU_T sf_Chart_k;      /* '<S424>/Chart' */
  DW_ControlStateRequest_BEML_EMU_T ControlStateRequest_n;/* '<S424>/ControlStateRequest' */
  DW_Chart_BEML_EMU_T sf_Chart_e;      /* '<S425>/Chart' */
  DW_ControlStateRequest_BEML_EMU_T ControlStateRequest_i;/* '<S425>/ControlStateRequest' */
  DW_Chart_BEML_EMU_T sf_Chart;        /* '<S426>/Chart' */
  DW_ControlStateRequest_BEML_EMU_T ControlStateRequest;/* '<S426>/ControlStateRequest' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_in;/* '<S427>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_fm;/* '<S428>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_a;/* '<S429>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_d;/* '<S430>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_f;/* '<S431>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_hr;/* '<S432>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e5;/* '<S433>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e2;/* '<S434>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_i;/* '<S435>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h1;/* '<S436>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_c;/* '<S437>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_j;/* '<S438>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h;/* '<S439>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_p;/* '<S440>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_ma;/* '<S441>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_b;/* '<S442>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_o;/* '<S443>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_mb;/* '<S444>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_m;/* '<S445>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_l;/* '<S446>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e;/* '<S447>/IRQRequestStateMachine' */
  DW_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine;/* '<S448>/IRQRequestStateMachine' */
  BD_SimIntegration_Faults_IOControls RateTransition_Buffer;/* '<S404>/Rate Transition' */
  real_T DelayInput1_DSTATE;           /* '<S419>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;         /* '<S416>/Delay Input1' */
  real_T DelayInput1_DSTATE_iw;        /* '<S415>/Delay Input1' */
  real_T DelayInput1_DSTATE_b;         /* '<S418>/Delay Input1' */
  real_T DelayInput1_DSTATE_l;         /* '<S417>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S490>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S498>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S586>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S610>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S618>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_go;/* '<S626>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S634>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S642>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_dm;/* '<S650>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S658>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S506>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S514>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S522>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_ks;/* '<S530>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_ls;/* '<S538>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S546>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_ik;/* '<S554>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_iq;/* '<S562>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_oh;/* '<S570>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S578>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S594>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_pp;/* '<S602>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S490>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_j;/* '<S498>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S586>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h2;/* '<S610>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_l;/* '<S618>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S626>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_d;/* '<S634>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_f;/* '<S642>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_lt;/* '<S650>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h1;/* '<S658>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_ls;/* '<S506>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_n;/* '<S514>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_ni;/* '<S522>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_f4;/* '<S530>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_ph;/* '<S538>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_c;/* '<S546>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_n1;/* '<S554>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_lo;/* '<S562>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_k;/* '<S570>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_a;/* '<S578>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_m;/* '<S594>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_fg;/* '<S602>/Discrete-Time Integrator' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S420>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE;         /* '<S409>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE;          /* '<S423>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S424>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S425>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S426>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S421>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S422>/Memory' */
  boolean_T RateTransition1_Buffer0;   /* '<S409>/Rate Transition1' */
  boolean_T RateTransition2_Buffer0;   /* '<S409>/Rate Transition2' */
  boolean_T RateTransition3_Buffer0;   /* '<S409>/Rate Transition3' */
  boolean_T RateTransition4_Buffer0;   /* '<S409>/Rate Transition4' */
} DW_CoreSubsys_BEML_EMU_f_T;

/* Block states (default storage) for system '<S734>/Subsystem1' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S739>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;         /* '<S745>/Delay Input1' */
  boolean_T Relay_Mode;                /* '<S738>/Relay' */
} DW_CoreSubsys_BEML_EMU_fwu4sljn_T;

/* Block states (default storage) for system '<S750>/Subsystem' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S751>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S751>/Discrete-Time Integrator1' */
} DW_CoreSubsys_BEML_EMU_fwu4sljnnsfqdu_T;

/* Block states (default storage) for system '<S737>/Input Adapter' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S760>/Discrete-Time Integrator' */
} DW_CoreSubsys_BEML_EMU_jr_T;

/* Block signals for system '<S782>/Jolt Duration' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S793>/Logical Operator1' */
} B_JoltDuration_BEML_EMU_T;

/* Block states (default storage) for system '<S782>/Jolt Duration' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S793>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S793>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S793>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S793>/IC' */
} DW_JoltDuration_BEML_EMU_T;

/* Block signals for system '<S753>/MotionBasePerVehicle' */
typedef struct {
  real_T ManualPosition[3];            /* '<S797>/Merge' */
  real_T IC;                           /* '<S846>/IC' */
  real_T VectorConcatenate1[2];        /* '<S863>/Vector Concatenate1' */
  real_T VectorConcatenate[2];         /* '<S863>/Vector Concatenate' */
  real_T VectorConcatenate1_j[2];      /* '<S859>/Vector Concatenate1' */
  real_T VectorConcatenate_p[2];       /* '<S859>/Vector Concatenate' */
  real_T VectorConcatenate1_jf[2];     /* '<S853>/Vector Concatenate1' */
  real_T VectorConcatenate_m[2];       /* '<S853>/Vector Concatenate' */
  real_T VectorConcatenate1_n[2];      /* '<S849>/Vector Concatenate1' */
  real_T VectorConcatenate_k[2];       /* '<S849>/Vector Concatenate' */
  real_T VectorConcatenate1_i[2];      /* '<S817>/Vector Concatenate1' */
  real_T VectorConcatenate_ko[2];      /* '<S817>/Vector Concatenate' */
  real_T VectorConcatenate1_o[2];      /* '<S818>/Vector Concatenate1' */
  real_T VectorConcatenate_a[2];       /* '<S818>/Vector Concatenate' */
  real_T VectorConcatenate1_c[2];      /* '<S815>/Vector Concatenate1' */
  real_T VectorConcatenate_g[2];       /* '<S815>/Vector Concatenate' */
  real_T VectorConcatenate1_iu[2];     /* '<S816>/Vector Concatenate1' */
  real_T VectorConcatenate_o[2];       /* '<S816>/Vector Concatenate' */
  real_T VectorConcatenate1_h[2];      /* '<S819>/Vector Concatenate1' */
  real_T VectorConcatenate_o4[2];      /* '<S819>/Vector Concatenate' */
  real_T VectorConcatenate1_l[2];      /* '<S820>/Vector Concatenate1' */
  real_T VectorConcatenate_ge[2];      /* '<S820>/Vector Concatenate' */
  real_T VectorConcatenate1_l0[2];     /* '<S838>/Vector Concatenate1' */
  real_T VectorConcatenate_i[2];       /* '<S838>/Vector Concatenate' */
  real_T VectorConcatenate1_g[2];      /* '<S839>/Vector Concatenate1' */
  real_T VectorConcatenate_go[2];      /* '<S839>/Vector Concatenate' */
  real_T VectorConcatenate1_om[2];     /* '<S836>/Vector Concatenate1' */
  real_T VectorConcatenate_n[2];       /* '<S836>/Vector Concatenate' */
  real_T VectorConcatenate1_iv[2];     /* '<S837>/Vector Concatenate1' */
  real_T VectorConcatenate_i4[2];      /* '<S837>/Vector Concatenate' */
  real_T VectorConcatenate1_hg[2];     /* '<S840>/Vector Concatenate1' */
  real_T VectorConcatenate_d[2];       /* '<S840>/Vector Concatenate' */
  real_T VectorConcatenate1_b[2];      /* '<S841>/Vector Concatenate1' */
  real_T VectorConcatenate_oc[2];      /* '<S841>/Vector Concatenate' */
  B_JoltDuration_BEML_EMU_T JoltDuration_o;/* '<S779>/Jolt Duration' */
  B_JoltDuration_BEML_EMU_T JoltDuration_n;/* '<S780>/Jolt Duration' */
  B_JoltDuration_BEML_EMU_T JoltDuration_e;/* '<S781>/Jolt Duration' */
  B_JoltDuration_BEML_EMU_T JoltDuration;/* '<S782>/Jolt Duration' */
} B_CoreSubsys_BEML_EMU_bb_T;

/* Block states (default storage) for system '<S753>/MotionBasePerVehicle' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S846>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states[3];/* '<S863>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S779>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S780>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S781>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S782>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_b[3];/* '<S859>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_c[3];/* '<S853>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_a[3];/* '<S849>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_o; /* '<S817>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_cq;/* '<S818>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_l; /* '<S815>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_d; /* '<S816>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE_hq;/* '<S814>/Discrete-Time Integrator' */
  real_T DelayInput1_DSTATE;           /* '<S813>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S810>/Unit Delay' */
  real_T DiscreteTransferFcn_states_bh;/* '<S819>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_d1;/* '<S820>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_j; /* '<S838>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_ln;/* '<S839>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_l2;/* '<S836>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_m; /* '<S837>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S835>/Discrete-Time Integrator' */
  real_T DelayInput1_DSTATE_p;         /* '<S834>/Delay Input1' */
  real_T UnitDelay_DSTATE_h;           /* '<S831>/Unit Delay' */
  real_T DiscreteTransferFcn_states_op;/* '<S840>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_k; /* '<S841>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S857>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_tmp[3];   /* '<S863>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_p[3]; /* '<S859>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_i[3]; /* '<S853>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_ib[3];/* '<S849>/Discrete Transfer Fcn' */
  real_T NextOutput;                   /* '<S804>/White Noise' */
  real_T NextOutput_m;                 /* '<S805>/White Noise' */
  real_T NextOutput_c;                 /* '<S825>/White Noise' */
  real_T NextOutput_a;                 /* '<S826>/White Noise' */
  int32_T clockTickCounter;            /* '<S802>/Pulse Generator' */
  int32_T clockTickCounter_b;          /* '<S823>/Pulse Generator1' */
  uint32_T RandSeed;                   /* '<S804>/White Noise' */
  uint32_T RandSeed_f;                 /* '<S805>/White Noise' */
  uint32_T RandSeed_p;                 /* '<S825>/White Noise' */
  uint32_T RandSeed_e;                 /* '<S826>/White Noise' */
  boolean_T UnitDelay1_DSTATE;         /* '<S776>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S783>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pk;     /* '<S786>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S789>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S792>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S846>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_l;/* '<S779>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S780>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_f;/* '<S781>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S782>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_m;/* '<S814>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_j;/* '<S835>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S857>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S857>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S846>/IC' */
  boolean_T IC_FirstOutputTime_j;      /* '<S857>/IC' */
  DW_JoltDuration_BEML_EMU_T JoltDuration_o;/* '<S779>/Jolt Duration' */
  DW_JoltDuration_BEML_EMU_T JoltDuration_n;/* '<S780>/Jolt Duration' */
  DW_JoltDuration_BEML_EMU_T JoltDuration_e;/* '<S781>/Jolt Duration' */
  DW_JoltDuration_BEML_EMU_T JoltDuration;/* '<S782>/Jolt Duration' */
} DW_CoreSubsys_BEML_EMU_k4_T;

/* Block signals (default storage) */
typedef struct {
  BD_IOControls_In_Vehicle ImpAsg_InsertedFor_ModelInputs_at_inport_0[8];/* '<S660>/Bus Assignment1' */
  BD_TCMSSystem_Out_Vehicle UnitDelay3[8];/* '<Root>/Unit Delay3' */
  BD_TCMSSystem_Out_Vehicle UnitDelay6[8];/* '<S1>/Unit Delay6' */
  BD_SimIntegration_In_Vehicle ProcessedVehicleInput[8];
    /* '<S3>/BusConversion_InsertedFor_ProcessedInputs_Outport_1_at_inport_0' */
  BD_TCMSSystem_In_Vehicle ImpAsg_InsertedFor_TCMSVehicleInput_at_inport_0[8];/* '<S360>/Bus Assignment' */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay[8];/* '<S3>/Unit Delay' */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay_p[8];/* '<S401>/Unit Delay' */
  BD_IOControls_Out_Vehicle_InputStates
    ImpAsg_InsertedFor_InputControlStates_at_inport_0[8];
  BD_DoorSystem_Out_Vehicle UnitDelay1[8];/* '<Root>/Unit Delay1' */
  BD_DoorSystem_Out_Vehicle UnitDelay3_m[8];/* '<S1>/Unit Delay3' */
  BD_ElectricalSystem_Out_Vehicle UnitDelay_n[8];/* '<Root>/Unit Delay' */
  BD_ElectricalSystem_Out_Vehicle UnitDelay5[8];/* '<S1>/Unit Delay5' */
  BD_DoorSystem_In_Vehicle ImpAsg_InsertedFor_DoorsVehicleInput_at_inport_0[8];/* '<S150>/DoorsInputs' */
  BD_ElectricalSystem_In_Vehicle
    ImpAsg_InsertedFor_ElectricalVehicleInput_at_inport_0[8];/* '<S318>/Bus Assignment' */
  BD_SimIntegration_Faults_Vehicle_Processed
    ImpAsg_InsertedFor_VehicleModelFaults_at_inport_0[8];/* '<S404>/Bus Creator' */
  BD_SimIntegration_Faults_Vehicle
    ImpAsg_InsertedFor_VehicleLevelFaults_at_inport_0[8];
  BD_SimIntegration_Faults_Vehicle
    ImpAsg_InsertedFor_VehicleFaultStates_at_inport_0[8];/* '<S404>/VehicleFaultStatesCompile' */
  BD_ElectricalSystem_In_Faults ImpAsg_InsertedFor_ElectricalFaults_at_inport_0
    [8];
  BD_TrainDynamics_Out_Vehicle UnitDelay_j[8];/* '<S1>/Unit Delay' */
  BD_CouplingSystem_In_Vehicle ImpAsg_InsertedFor_CouplingInput_at_inport_0[8];/* '<S146>/Bus Assignment' */
  BD_ElectricalSystem_Wires ElectricalSystem_o2[8];/* '<S10>/ElectricalSystem' */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay2[8];/* '<Root>/Unit Delay2' */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay1_k[8];/* '<S1>/Unit Delay1' */
  BD_TrainDynamics_In_Vehicle
    ImpAsg_InsertedFor_DynamicsVehicleInput_at_inport_0[8];/* '<S311>/Bus Assignment' */
  BD_TractionSystem_Out_Vehicle UnitDelay4[8];/* '<S1>/Unit Delay4' */
  BD_MotionBase_In_Vehicle ImpAsg_InsertedFor_MotionBaseInput_at_inport_0[8];/* '<S752>/MotionBaseInputAdapter' */
  BD_PneumaticsSystem_In_Vehicle
    ImpAsg_InsertedFor_PneumaticsVehicleInput_at_inport_0[8];/* '<S349>/Bus Assignment' */
  BD_TrainBrakes_Out_Vehicle UnitDelay7[8];/* '<S1>/Unit Delay7' */
  BD_SimIntegration_In_Train BusAssignment;/* '<S402>/Bus Assignment' */
  BD_TractionSystem_In_Vehicle
    ImpAsg_InsertedFor_TractionVehicleInput_at_inport_0[8];/* '<S385>/Bus Assignment' */
  BD_TrainDynamics_Cfg_Vehicle
    ImpAsg_InsertedFor_DynamicsVehicleConfig_at_inport_0[8];
  BD_TrainBrakes_In_Vehicle ImpAsg_InsertedFor_BrakesVehicleInput_at_inport_0[8];/* '<S17>/Bus Assignment' */
  BD_TractionSystem_In_Faults ImpAsg_InsertedFor_TractionFaults_at_inport_0[8];/* '<S385>/Bus Assignment2' */
  BD_PneumaticsSystem_In_Vehicle_Faults
    ImpAsg_InsertedFor_PneumaticsFaults_at_inport_0[8];
  BD_TCMSSystem_In_Vehicle_Faults ImpAsg_InsertedFor_TCMSFaults_at_inport_0[8];
  BD_CommonTrain_Cfg_Vehicle ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0
    [8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_l[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_b[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_a[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_e[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_d[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ds[8];
  BD_CommonTrain_Cfg_Vehicle
    ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0_ly[8];
  BD_TrainDynamics_In_Vehicle_Overrides
    ImpAsg_InsertedFor_Overrides_at_inport_0[8];/* '<S311>/Bus Assignment1' */
  BD_DoorSystem_In_Emergency_Door
    ImpAsg_InsertedFor_EmergencyDoorInputs_at_inport_0[8];/* '<S150>/DoorsInputs' */
  BD_PneumaticsSystem_Cfg_Vehicle
    ImpAsg_InsertedFor_PneumaticsVehicleConfig_at_inport_0[8];
  BD_TrainBrakes_Cfg_Vehicle ImpAsg_InsertedFor_BrakesVehicleConfig_at_inport_0
    [8];
  BD_TCMSSystem_Cfg_Vehicle ImpAsg_InsertedFor_TCMSVehicleConfig_at_inport_0[8];/* '<S361>/Bus Assignment' */
  BD_SimIntegration_Faults_IOControls
    ImpAsg_InsertedFor_IOControlsModelFaults_at_inport_0[8];/* '<S404>/Rate Transition' */
  BD_CouplingSystem_Cfg_Vehicle ImpAsg_InsertedFor_VehConfig_at_inport_0[8];/* '<S146>/Bus Assignment1' */
  BD_TrainDynamics_In_Vehicle_Faults
    ImpAsg_InsertedFor_DynamicsFaults_at_inport_0[8];/* '<S311>/Bus Assignment2' */
  BD_SimIntegration_Cfg_Vehicle_Location
    ImpAsg_InsertedFor_LocationVehicleConfig_at_inport_0[8];
  BD_ElectricalSystem_Cfg_Vehicle
    ImpAsg_InsertedFor_ElectricalVehicleConfig_at_inport_0[8];/* '<S319>/Bus Assignment' */
  BD_TrainBrakes_In_Vehicle_Overrides
    ImpAsg_InsertedFor_Overrides_at_inport_0_n[8];/* '<S17>/Bus Assignment1' */
  BD_TractionSystem_In_Overrides ImpAsg_InsertedFor_Overrides_at_inport_0_i[8];/* '<S385>/Bus Assignment1' */
  BD_PneumaticsSystem_In_Overrides ImpAsg_InsertedFor_Overrides_at_inport_0_im[8];/* '<S349>/Bus Assignment1' */
  BD_DoorSystem_In_Overrides ImpAsg_InsertedFor_Overrides_at_inport_0_j[8];/* '<S150>/Constant1' */
  BD_DoorSystem_Cfg_Door ImpAsg_InsertedFor_DoorsConfig_at_inport_0[8];
  BD_TrainBrakes_In_Vehicle_Faults ImpAsg_InsertedFor_BrakesFaults_at_inport_0[8];/* '<S17>/Bus Assignment2' */
  BD_TractionSystem_Cfg_Vehicle
    ImpAsg_InsertedFor_TractionVehicleConfig_at_inport_0[8];
  BD_PantographSystem_Cfg_Vehicle
    ImpAsg_InsertedFor_PantographVehicleConfig_at_inport_0[8];
  boolean_T NOT;                       /* '<S402>/NOT' */
  boolean_T ImpAsg_InsertedFor_HasCab_at_inport_0[8];
  B_CoreSubsys_BEML_EMU_bb_T CoreSubsys_m[8];/* '<S753>/MotionBasePerVehicle' */
  B_CoreSubsys_BEML_EMU_m_T CoreSubsys_h[8];/* '<S20>/CBTCModel' */
} B_BEML_EMU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  BD_TCMSSystem_Out_Vehicle UnitDelay3_DSTATE[8];/* '<Root>/Unit Delay3' */
  BD_TCMSSystem_Out_Vehicle UnitDelay6_DSTATE[8];/* '<S1>/Unit Delay6' */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay_DSTATE[8];/* '<S3>/Unit Delay' */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay_DSTATE_b[8];/* '<S401>/Unit Delay' */
  BD_DoorSystem_Out_Vehicle UnitDelay1_DSTATE[8];/* '<Root>/Unit Delay1' */
  BD_DoorSystem_Out_Vehicle UnitDelay3_DSTATE_n[8];/* '<S1>/Unit Delay3' */
  BD_ElectricalSystem_Out_Vehicle UnitDelay_DSTATE_i[8];/* '<Root>/Unit Delay' */
  BD_ElectricalSystem_Out_Vehicle UnitDelay5_DSTATE[8];/* '<S1>/Unit Delay5' */
  BD_TrainDynamics_Out_Vehicle UnitDelay_DSTATE_d[8];/* '<S1>/Unit Delay' */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay2_DSTATE[8];/* '<Root>/Unit Delay2' */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay1_DSTATE_l[8];/* '<S1>/Unit Delay1' */
  BD_TractionSystem_Out_Vehicle UnitDelay4_DSTATE[8];/* '<S1>/Unit Delay4' */
  BD_TrainBrakes_Out_Vehicle UnitDelay7_DSTATE[8];/* '<S1>/Unit Delay7' */
  BD_PantographSystem_Out_Vehicle UnitDelay2_DSTATE_d[8];/* '<S1>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S746>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE_h[8];       /* '<S675>/Unit Delay' */
  MdlrefDW_ElectricalSystem_T ElectricalSystem_InstanceData;/* '<S10>/ElectricalSystem' */
  MdlrefDW_TCMSSystem_T TCMSSystem_InstanceData;/* '<S13>/TCMSSystem' */
  MdlrefDW_PneumaticsSystem_T PneumaticsSystem_InstanceData;/* '<S12>/PneumaticsSystem' */
  MdlrefDW_PantographSystem_T PantographSystem_InstanceData;/* '<S11>/PantographSystem' */
  MdlrefDW_DoorSystem_T DoorsSystem_InstanceData;/* '<S8>/DoorsSystem' */
  MdlrefDW_TrainBrakes_T TrainBrakes_InstanceData;/* '<S5>/TrainBrakes' */
  MdlrefDW_TractionSystem_T TractionSystem_InstanceData;/* '<S14>/TractionSystem' */
  MdlrefDW_TrainDynamics_T TrainDynamics_InstanceData;/* '<S9>/TrainDynamics' */
  MdlrefDW_IOControls_T IOControlsModel_InstanceData;/* '<S401>/IOControlsModel' */
  MdlrefDW_CouplingSystem_T Model_InstanceData;/* '<S7>/Model' */
  DW_CoreSubsys_BEML_EMU_k4_T CoreSubsys_m[8];/* '<S753>/MotionBasePerVehicle' */
  DW_CoreSubsys_BEML_EMU_n0_T CoreSubsys_cr[8];/* '<S383>/VehicleInputAdapter' */
  DW_CoreSubsys_BEML_EMU_kvj_T CoreSubsys_gf[8];/* '<S358>/VehicleInputAdapter' */
  DW_CoreSubsys_BEML_EMU_ep_T CoreSubsys_ij1[8];/* '<S316>/VehicleInputAdapter' */
  DW_CoreSubsys_BEML_EMU_k_T CoreSubsys_h[8];/* '<S20>/CBTCModel' */
} DW_BEML_EMU_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BD_CommonTrain_SimulatorData SimData;/* '<Root>/SimData' */
  BD_SimIntegration_Cfg_Vehicle VehicleConfig[8];/* '<Root>/VehicleConfig' */
  BD_SimIntegration_In_Train TrainInput;/* '<Root>/TrainInput' */
  BD_SimIntegration_In_Vehicle VehicleInput[8];/* '<Root>/VehicleInput' */
  BD_IOControls_In_Vehicle IOControlsInput[8];/* '<Root>/IOControlsInput' */
  BD_SimIntegration_In_Vehicle_MotionBaseController MotionBaseControllerInput[8];/* '<Root>/MotionBaseControllerInput' */
} ExtU_BEML_EMU_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  BD_CommonTrain_Out_ModelStatus ModelStatus;/* '<Root>/ModelStatus' */
  BD_ElectricalSystem_Out_Vehicle ElectricalOutput[8];/* '<Root>/ElectricalOutput' */
  BD_TCMSSystem_Out_Vehicle TCMSOutput[8];/* '<Root>/TCMSOutput' */
  BD_PantographSystem_Out_Vehicle PantographVehicleOut[8];/* '<Root>/PantographVehicleOut' */
  BD_DoorSystem_Out_Vehicle DoorsVehicleOut[8];/* '<Root>/DoorsVehicleOut' */
  BD_PneumaticsSystem_Out_Vehicle PneumaticsVehicleOut[8];/* '<Root>/PneumaticsVehicleOut' */
  BD_TrainBrakes_Out_Vehicle BrakesVehicleOut[8];/* '<Root>/BrakesVehicleOut' */
  BD_TractionSystem_Out_Vehicle TractionVehicleOut[8];/* '<Root>/TractionVehicleOut' */
  BD_TrainDynamics_Out_Vehicle DynamicsOutput[8];/* '<Root>/DynamicsOutput' */
  BD_CBTC_Out_Vehicle CBTCVehicleOut[8];/* '<Root>/CBTCVehicleOut' */
  BD_SimIntegration_Out_Vehicle_Audio AudioOutput[8];/* '<Root>/AudioOutput' */
  BD_SimIntegration_Out_Train_Scoring ScoringTrainOutput;/* '<Root>/ScoringTrainOutput ' */
  BD_SimIntegration_Out_Vehicle_Scoring ScoringVehicleOutput[8];/* '<Root>/ScoringVehicleOutput' */
  BD_IOControls_Out_Vehicle IOControlsOutput[8];/* '<Root>/IOControlsOutput' */
  BD_SimIntegration_Faults_Train TrainFaultStates;/* '<Root>/TrainFaultStates' */
  BD_SimIntegration_Faults_Vehicle VehicleFaultStates[8];/* '<Root>/VehicleFaultStates' */
  BD_CouplingSystem_Out_Vehicle CouplingOutput[8];/* '<Root>/CouplingOutput' */
  BD_SimIntegration_Out_Vehicle_MotionBaseController MotionBaseControllerOutput
    [8];                               /* '<Root>/MotionBaseControllerOutput' */
  BD_SimIntegration_Cfg_Vehicle ProcessedVehConf[8];/* '<Root>/ProcessedVehConf' */
} ExtY_BEML_EMU_T;

/* Parameters for system: '<S15>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_j_T_ {
  BD_TrainBrakes_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                            * Referenced by: '<S17>/Constant'
                                            */
  BD_TrainBrakes_In_Vehicle_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                       * Referenced by: '<S17>/Constant1'
                                                       */
  BD_TrainBrakes_In_Vehicle_Faults Constant2_Value;/* Computed Parameter: Constant2_Value
                                                    * Referenced by: '<S17>/Constant2'
                                                    */
};

/* Parameters for system: '<S23>/NotInATO' */
struct P_NotInATO_BEML_EMU_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
};

/* Parameters for system: '<S20>/CBTCModel' */
struct P_CoreSubsys_BEML_EMU_i_T_ {
  real_T BrakeDemandPIDController_DifferentiatorICPrevScaledInput;
     /* Mask Parameter: BrakeDemandPIDController_DifferentiatorICPrevScaledInput
      * Referenced by: '<S65>/UD'
      */
  real_T TractiveDemand_DifferentiatorICPrevScaledInput;
               /* Mask Parameter: TractiveDemand_DifferentiatorICPrevScaledInput
                * Referenced by: '<S110>/UD'
                */
  real_T BrakeDemandPIDController_InitialConditionForIntegrator;
       /* Mask Parameter: BrakeDemandPIDController_InitialConditionForIntegrator
        * Referenced by: '<S70>/Integrator'
        */
  real_T TractiveDemand_InitialConditionForIntegrator;
                 /* Mask Parameter: TractiveDemand_InitialConditionForIntegrator
                  * Referenced by: '<S115>/Integrator'
                  */
  real_T BrakeDemandPIDController_LowerSaturationLimit;
                /* Mask Parameter: BrakeDemandPIDController_LowerSaturationLimit
                 * Referenced by: '<S77>/Saturation'
                 */
  real_T TractiveDemand_LowerSaturationLimit;
                          /* Mask Parameter: TractiveDemand_LowerSaturationLimit
                           * Referenced by: '<S122>/Saturation'
                           */
  real_T BrakeDemandPIDController_UpperSaturationLimit;
                /* Mask Parameter: BrakeDemandPIDController_UpperSaturationLimit
                 * Referenced by: '<S77>/Saturation'
                 */
  real_T TractiveDemand_UpperSaturationLimit;
                          /* Mask Parameter: TractiveDemand_UpperSaturationLimit
                           * Referenced by: '<S122>/Saturation'
                           */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S35>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S36>/Constant'
                                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S33>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S34>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S38>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S37>/Constant'
                                      */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S140>/Memory'
                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S141>/Memory'
                       */
  boolean_T SRLatchResetPriority2_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority2_initial_condition
                       * Referenced by: '<S142>/Memory'
                       */
  boolean_T SRLatchResetPriority3_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority3_initial_condition
                       * Referenced by: '<S143>/Memory'
                       */
  BD_CBTC_Out_Vehicle Constant_Value;  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S21>/Constant'
                                        */
  BD_CBTC_Out_Vehicle_Onboard ToOnBoardUnit_Value;
                                      /* Computed Parameter: ToOnBoardUnit_Value
                                       * Referenced by: '<S26>/ToOnBoardUnit'
                                       */
  BD_CBTC_Out_Vehicle_TCMS ToTCMSSystem_Value;/* Computed Parameter: ToTCMSSystem_Value
                                               * Referenced by: '<S28>/ToTCMSSystem'
                                               */
  BD_CBTC_Out_Vehicle_Electrical ToElectricalSystem_Value;
                                 /* Computed Parameter: ToElectricalSystem_Value
                                  * Referenced by: '<S25>/ToElectricalSystem'
                                  */
  BD_CBTC_Out_Vehicle_Platform ToOnPlatformUnit_Value;
                                   /* Computed Parameter: ToOnPlatformUnit_Value
                                    * Referenced by: '<S27>/ToOnPlatformUnit'
                                    */
  BD_CBTC_Out_Vehicle_DMI ToDMI_Value; /* Computed Parameter: ToDMI_Value
                                        * Referenced by: '<S24>/ToDMI'
                                        */
  struct_iOPQUPViMP7klj2KCOPonE ATOCommands_Y0;/* Computed Parameter: ATOCommands_Y0
                                                * Referenced by: '<S23>/ATOCommands'
                                                */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S65>/TSamp'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S70>/Integrator'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S110>/TSamp'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S115>/Integrator'
                                      */
  real_T Ignoreinvalidv_Permitted_UpperSat;/* Expression: 80/3.6
                                            * Referenced by: '<S23>/Ignore invalid v_Permitted'
                                            */
  real_T Ignoreinvalidv_Permitted_LowerSat;/* Expression: 0
                                            * Referenced by: '<S23>/Ignore invalid v_Permitted'
                                            */
  real_T RealTarget_Value;             /* Expression: 0.5
                                        * Referenced by: '<S23>/Real Target'
                                        */
  real_T Min0_UpperSat;                /* Expression: inf
                                        * Referenced by: '<S23>/Min0'
                                        */
  real_T Min0_LowerSat;                /* Expression: 0
                                        * Referenced by: '<S23>/Min0'
                                        */
  real_T Relay_OnVal;                  /* Expression: 0.5
                                        * Referenced by: '<S23>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: 0.05
                                        * Referenced by: '<S23>/Relay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S131>/Unit Delay2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S131>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S131>/Unit Delay'
                                        */
  real_T ATP_Value;                    /* Expression: 1
                                        * Referenced by: '<S130>/ATP'
                                        */
  real_T ROS_Value;                    /* Expression: 2
                                        * Referenced by: '<S130>/ROS'
                                        */
  real_T RMR_Value;                    /* Expression: 3
                                        * Referenced by: '<S130>/RMR'
                                        */
  real_T RMF_Value;                    /* Expression: 4
                                        * Referenced by: '<S130>/RMF'
                                        */
  real_T Off_Value;                    /* Expression: 0
                                        * Referenced by: '<S130>/Off'
                                        */
  real_T ATB_Value;                    /* Expression: 5
                                        * Referenced by: '<S130>/ATB'
                                        */
  real_T ATO_Value;                    /* Expression: 6
                                        * Referenced by: '<S130>/ATO'
                                        */
  real_T UTO_Value;                    /* Expression: 7
                                        * Referenced by: '<S130>/UTO'
                                        */
  real_T Temp_Fix_Value;               /* Expression: 1
                                        * Referenced by: '<S25>/Temp_Fix'
                                        */
  boolean_T Relay_YOn;                 /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S23>/Relay'
                                        */
  boolean_T Relay_YOff;                /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S23>/Relay'
                                        */
  P_NotInATO_BEML_EMU_T Coasting;      /* '<S23>/Coasting' */
  P_NotInATO_BEML_EMU_T BrakeWhenClosetoStoppingPoint;
                                /* '<S23>/Brake When Close to Stopping Point' */
  P_NotInATO_BEML_EMU_T NotInATO;      /* '<S23>/NotInATO' */
};

/* Parameters for system: '<S146>/ConvertToCouplerBus' */
struct P_CoreSubsys_BEML_EMU_ct_T_ {
  BD_CouplingSystem_In_Vehicle_Coupler_Dynamics Constant1_Value;/* Computed Parameter: Constant1_Value
                                                                 * Referenced by: '<S147>/Constant1'
                                                                 */
};

/* Parameters for system: '<S145>/Subsystem' */
struct P_CoreSubsys_BEML_EMU_c_T_ {
  BD_CouplingSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                               * Referenced by: '<S146>/Constant'
                                               */
  BD_CouplingSystem_Cfg_Vehicle Constant1_Value;/* Computed Parameter: Constant1_Value
                                                 * Referenced by: '<S146>/Constant1'
                                                 */
  P_CoreSubsys_BEML_EMU_ct_T CoreSubsys;/* '<S146>/ConvertToCouplerBus' */
};

/* Parameters for system: '<S148>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_ln_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S229>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S230>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S231>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S232>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S233>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S234>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S235>/Constant'
                                      */
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S236>/Constant'
                                      */
  real_T CompareToConstant_const_o; /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S237>/Constant'
                                     */
  real_T CompareToConstant1_const_i;
                                   /* Mask Parameter: CompareToConstant1_const_i
                                    * Referenced by: '<S238>/Constant'
                                    */
  real_T CompareToConstant2_const_f;
                                   /* Mask Parameter: CompareToConstant2_const_f
                                    * Referenced by: '<S239>/Constant'
                                    */
  real_T CompareToConstant3_const_l;
                                   /* Mask Parameter: CompareToConstant3_const_l
                                    * Referenced by: '<S240>/Constant'
                                    */
  real_T CompareToConstant4_const_f;
                                   /* Mask Parameter: CompareToConstant4_const_f
                                    * Referenced by: '<S241>/Constant'
                                    */
  real_T CompareToConstant5_const_f;
                                   /* Mask Parameter: CompareToConstant5_const_f
                                    * Referenced by: '<S242>/Constant'
                                    */
  real_T CompareToConstant6_const_a;
                                   /* Mask Parameter: CompareToConstant6_const_a
                                    * Referenced by: '<S243>/Constant'
                                    */
  real_T CompareToConstant7_const_g;
                                   /* Mask Parameter: CompareToConstant7_const_g
                                    * Referenced by: '<S244>/Constant'
                                    */
  real_T CompareToConstant_const_g; /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S181>/Constant'
                                     */
  real_T CompareToConstant1_const_m;
                                   /* Mask Parameter: CompareToConstant1_const_m
                                    * Referenced by: '<S182>/Constant'
                                    */
  real_T CompareToConstant2_const_i;
                                   /* Mask Parameter: CompareToConstant2_const_i
                                    * Referenced by: '<S183>/Constant'
                                    */
  real_T CompareToConstant3_const_b;
                                   /* Mask Parameter: CompareToConstant3_const_b
                                    * Referenced by: '<S184>/Constant'
                                    */
  real_T CompareToConstant4_const_l;
                                   /* Mask Parameter: CompareToConstant4_const_l
                                    * Referenced by: '<S185>/Constant'
                                    */
  real_T CompareToConstant5_const_m;
                                   /* Mask Parameter: CompareToConstant5_const_m
                                    * Referenced by: '<S186>/Constant'
                                    */
  real_T CompareToConstant6_const_e;
                                   /* Mask Parameter: CompareToConstant6_const_e
                                    * Referenced by: '<S187>/Constant'
                                    */
  real_T CompareToConstant7_const_d;
                                   /* Mask Parameter: CompareToConstant7_const_d
                                    * Referenced by: '<S188>/Constant'
                                    */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S189>/Constant'
                                     */
  real_T CompareToConstant1_const_l;
                                   /* Mask Parameter: CompareToConstant1_const_l
                                    * Referenced by: '<S190>/Constant'
                                    */
  real_T CompareToConstant2_const_k;
                                   /* Mask Parameter: CompareToConstant2_const_k
                                    * Referenced by: '<S191>/Constant'
                                    */
  real_T CompareToConstant3_const_h;
                                   /* Mask Parameter: CompareToConstant3_const_h
                                    * Referenced by: '<S192>/Constant'
                                    */
  real_T CompareToConstant4_const_g;
                                   /* Mask Parameter: CompareToConstant4_const_g
                                    * Referenced by: '<S193>/Constant'
                                    */
  real_T CompareToConstant5_const_i;
                                   /* Mask Parameter: CompareToConstant5_const_i
                                    * Referenced by: '<S194>/Constant'
                                    */
  real_T CompareToConstant6_const_o;
                                   /* Mask Parameter: CompareToConstant6_const_o
                                    * Referenced by: '<S195>/Constant'
                                    */
  real_T CompareToConstant7_const_f;
                                   /* Mask Parameter: CompareToConstant7_const_f
                                    * Referenced by: '<S196>/Constant'
                                    */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S245>/Constant'
                                     */
  real_T CompareToConstant1_const_f;
                                   /* Mask Parameter: CompareToConstant1_const_f
                                    * Referenced by: '<S246>/Constant'
                                    */
  real_T CompareToConstant2_const_b;
                                   /* Mask Parameter: CompareToConstant2_const_b
                                    * Referenced by: '<S247>/Constant'
                                    */
  real_T CompareToConstant3_const_f;
                                   /* Mask Parameter: CompareToConstant3_const_f
                                    * Referenced by: '<S248>/Constant'
                                    */
  real_T CompareToConstant4_const_e;
                                   /* Mask Parameter: CompareToConstant4_const_e
                                    * Referenced by: '<S249>/Constant'
                                    */
  real_T CompareToConstant5_const_a;
                                   /* Mask Parameter: CompareToConstant5_const_a
                                    * Referenced by: '<S250>/Constant'
                                    */
  real_T CompareToConstant6_const_c;
                                   /* Mask Parameter: CompareToConstant6_const_c
                                    * Referenced by: '<S251>/Constant'
                                    */
  real_T CompareToConstant7_const_o;
                                   /* Mask Parameter: CompareToConstant7_const_o
                                    * Referenced by: '<S252>/Constant'
                                    */
  real_T CompareToConstant_const_a; /* Mask Parameter: CompareToConstant_const_a
                                     * Referenced by: '<S253>/Constant'
                                     */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S254>/Constant'
                                    */
  real_T CompareToConstant2_const_p;
                                   /* Mask Parameter: CompareToConstant2_const_p
                                    * Referenced by: '<S255>/Constant'
                                    */
  real_T CompareToConstant3_const_n;
                                   /* Mask Parameter: CompareToConstant3_const_n
                                    * Referenced by: '<S256>/Constant'
                                    */
  real_T CompareToConstant4_const_fh;
                                  /* Mask Parameter: CompareToConstant4_const_fh
                                   * Referenced by: '<S257>/Constant'
                                   */
  real_T CompareToConstant5_const_d;
                                   /* Mask Parameter: CompareToConstant5_const_d
                                    * Referenced by: '<S258>/Constant'
                                    */
  real_T CompareToConstant6_const_b;
                                   /* Mask Parameter: CompareToConstant6_const_b
                                    * Referenced by: '<S259>/Constant'
                                    */
  real_T CompareToConstant7_const_i;
                                   /* Mask Parameter: CompareToConstant7_const_i
                                    * Referenced by: '<S260>/Constant'
                                    */
  real_T CompareToConstant_const_k; /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S261>/Constant'
                                     */
  real_T CompareToConstant1_const_kw;
                                  /* Mask Parameter: CompareToConstant1_const_kw
                                   * Referenced by: '<S262>/Constant'
                                   */
  real_T CompareToConstant2_const_ko;
                                  /* Mask Parameter: CompareToConstant2_const_ko
                                   * Referenced by: '<S263>/Constant'
                                   */
  real_T CompareToConstant3_const_m;
                                   /* Mask Parameter: CompareToConstant3_const_m
                                    * Referenced by: '<S264>/Constant'
                                    */
  real_T CompareToConstant4_const_et;
                                  /* Mask Parameter: CompareToConstant4_const_et
                                   * Referenced by: '<S265>/Constant'
                                   */
  real_T CompareToConstant5_const_k;
                                   /* Mask Parameter: CompareToConstant5_const_k
                                    * Referenced by: '<S266>/Constant'
                                    */
  real_T CompareToConstant6_const_cp;
                                  /* Mask Parameter: CompareToConstant6_const_cp
                                   * Referenced by: '<S267>/Constant'
                                   */
  real_T CompareToConstant7_const_gl;
                                  /* Mask Parameter: CompareToConstant7_const_gl
                                   * Referenced by: '<S268>/Constant'
                                   */
  real_T CompareToConstant_const_l; /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S269>/Constant'
                                     */
  real_T CompareToConstant1_const_j;
                                   /* Mask Parameter: CompareToConstant1_const_j
                                    * Referenced by: '<S270>/Constant'
                                    */
  real_T CompareToConstant2_const_a;
                                   /* Mask Parameter: CompareToConstant2_const_a
                                    * Referenced by: '<S271>/Constant'
                                    */
  real_T CompareToConstant3_const_fo;
                                  /* Mask Parameter: CompareToConstant3_const_fo
                                   * Referenced by: '<S272>/Constant'
                                   */
  real_T CompareToConstant4_const_ep;
                                  /* Mask Parameter: CompareToConstant4_const_ep
                                   * Referenced by: '<S273>/Constant'
                                   */
  real_T CompareToConstant5_const_b;
                                   /* Mask Parameter: CompareToConstant5_const_b
                                    * Referenced by: '<S274>/Constant'
                                    */
  real_T CompareToConstant6_const_j;
                                   /* Mask Parameter: CompareToConstant6_const_j
                                    * Referenced by: '<S275>/Constant'
                                    */
  real_T CompareToConstant7_const_b;
                                   /* Mask Parameter: CompareToConstant7_const_b
                                    * Referenced by: '<S276>/Constant'
                                    */
  real_T CompareToConstant_const_j; /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S277>/Constant'
                                     */
  real_T CompareToConstant1_const_m0;
                                  /* Mask Parameter: CompareToConstant1_const_m0
                                   * Referenced by: '<S278>/Constant'
                                   */
  real_T CompareToConstant2_const_al;
                                  /* Mask Parameter: CompareToConstant2_const_al
                                   * Referenced by: '<S279>/Constant'
                                   */
  real_T CompareToConstant3_const_hm;
                                  /* Mask Parameter: CompareToConstant3_const_hm
                                   * Referenced by: '<S280>/Constant'
                                   */
  real_T CompareToConstant4_const_j;
                                   /* Mask Parameter: CompareToConstant4_const_j
                                    * Referenced by: '<S281>/Constant'
                                    */
  real_T CompareToConstant5_const_dd;
                                  /* Mask Parameter: CompareToConstant5_const_dd
                                   * Referenced by: '<S282>/Constant'
                                   */
  real_T CompareToConstant6_const_jq;
                                  /* Mask Parameter: CompareToConstant6_const_jq
                                   * Referenced by: '<S283>/Constant'
                                   */
  real_T CompareToConstant7_const_m;
                                   /* Mask Parameter: CompareToConstant7_const_m
                                    * Referenced by: '<S284>/Constant'
                                    */
  real_T CompareToConstant_const_pj;
                                   /* Mask Parameter: CompareToConstant_const_pj
                                    * Referenced by: '<S285>/Constant'
                                    */
  real_T CompareToConstant1_const_f1;
                                  /* Mask Parameter: CompareToConstant1_const_f1
                                   * Referenced by: '<S286>/Constant'
                                   */
  real_T CompareToConstant2_const_h;
                                   /* Mask Parameter: CompareToConstant2_const_h
                                    * Referenced by: '<S287>/Constant'
                                    */
  real_T CompareToConstant3_const_nv;
                                  /* Mask Parameter: CompareToConstant3_const_nv
                                   * Referenced by: '<S288>/Constant'
                                   */
  real_T CompareToConstant4_const_a;
                                   /* Mask Parameter: CompareToConstant4_const_a
                                    * Referenced by: '<S289>/Constant'
                                    */
  real_T CompareToConstant5_const_p;
                                   /* Mask Parameter: CompareToConstant5_const_p
                                    * Referenced by: '<S290>/Constant'
                                    */
  real_T CompareToConstant6_const_l;
                                   /* Mask Parameter: CompareToConstant6_const_l
                                    * Referenced by: '<S291>/Constant'
                                    */
  real_T CompareToConstant7_const_e;
                                   /* Mask Parameter: CompareToConstant7_const_e
                                    * Referenced by: '<S292>/Constant'
                                    */
  real_T CompareToConstant_const_f; /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S293>/Constant'
                                     */
  real_T CompareToConstant1_const_e;
                                   /* Mask Parameter: CompareToConstant1_const_e
                                    * Referenced by: '<S294>/Constant'
                                    */
  real_T CompareToConstant2_const_kq;
                                  /* Mask Parameter: CompareToConstant2_const_kq
                                   * Referenced by: '<S295>/Constant'
                                   */
  real_T CompareToConstant3_const_ls;
                                  /* Mask Parameter: CompareToConstant3_const_ls
                                   * Referenced by: '<S296>/Constant'
                                   */
  real_T CompareToConstant4_const_gs;
                                  /* Mask Parameter: CompareToConstant4_const_gs
                                   * Referenced by: '<S297>/Constant'
                                   */
  real_T CompareToConstant5_const_ft;
                                  /* Mask Parameter: CompareToConstant5_const_ft
                                   * Referenced by: '<S298>/Constant'
                                   */
  real_T CompareToConstant6_const_g;
                                   /* Mask Parameter: CompareToConstant6_const_g
                                    * Referenced by: '<S299>/Constant'
                                    */
  real_T CompareToConstant7_const_k;
                                   /* Mask Parameter: CompareToConstant7_const_k
                                    * Referenced by: '<S300>/Constant'
                                    */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S301>/Constant'
                                     */
  real_T CompareToConstant1_const_h;
                                   /* Mask Parameter: CompareToConstant1_const_h
                                    * Referenced by: '<S302>/Constant'
                                    */
  real_T CompareToConstant2_const_g;
                                   /* Mask Parameter: CompareToConstant2_const_g
                                    * Referenced by: '<S303>/Constant'
                                    */
  real_T CompareToConstant3_const_lm;
                                  /* Mask Parameter: CompareToConstant3_const_lm
                                   * Referenced by: '<S304>/Constant'
                                   */
  real_T CompareToConstant4_const_d;
                                   /* Mask Parameter: CompareToConstant4_const_d
                                    * Referenced by: '<S305>/Constant'
                                    */
  real_T CompareToConstant5_const_l;
                                   /* Mask Parameter: CompareToConstant5_const_l
                                    * Referenced by: '<S306>/Constant'
                                    */
  real_T CompareToConstant6_const_ch;
                                  /* Mask Parameter: CompareToConstant6_const_ch
                                   * Referenced by: '<S307>/Constant'
                                   */
  real_T CompareToConstant7_const_kl;
                                  /* Mask Parameter: CompareToConstant7_const_kl
                                   * Referenced by: '<S308>/Constant'
                                   */
  real_T CompareToConstant_const_iz;
                                   /* Mask Parameter: CompareToConstant_const_iz
                                    * Referenced by: '<S197>/Constant'
                                    */
  real_T CompareToConstant1_const_kp;
                                  /* Mask Parameter: CompareToConstant1_const_kp
                                   * Referenced by: '<S198>/Constant'
                                   */
  real_T CompareToConstant2_const_m;
                                   /* Mask Parameter: CompareToConstant2_const_m
                                    * Referenced by: '<S199>/Constant'
                                    */
  real_T CompareToConstant3_const_j;
                                   /* Mask Parameter: CompareToConstant3_const_j
                                    * Referenced by: '<S200>/Constant'
                                    */
  real_T CompareToConstant4_const_ac;
                                  /* Mask Parameter: CompareToConstant4_const_ac
                                   * Referenced by: '<S201>/Constant'
                                   */
  real_T CompareToConstant5_const_b4;
                                  /* Mask Parameter: CompareToConstant5_const_b4
                                   * Referenced by: '<S202>/Constant'
                                   */
  real_T CompareToConstant6_const_d;
                                   /* Mask Parameter: CompareToConstant6_const_d
                                    * Referenced by: '<S203>/Constant'
                                    */
  real_T CompareToConstant7_const_dk;
                                  /* Mask Parameter: CompareToConstant7_const_dk
                                   * Referenced by: '<S204>/Constant'
                                   */
  real_T CompareToConstant_const_e; /* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S205>/Constant'
                                     */
  real_T CompareToConstant1_const_d;
                                   /* Mask Parameter: CompareToConstant1_const_d
                                    * Referenced by: '<S206>/Constant'
                                    */
  real_T CompareToConstant2_const_d;
                                   /* Mask Parameter: CompareToConstant2_const_d
                                    * Referenced by: '<S207>/Constant'
                                    */
  real_T CompareToConstant3_const_jr;
                                  /* Mask Parameter: CompareToConstant3_const_jr
                                   * Referenced by: '<S208>/Constant'
                                   */
  real_T CompareToConstant4_const_i;
                                   /* Mask Parameter: CompareToConstant4_const_i
                                    * Referenced by: '<S209>/Constant'
                                    */
  real_T CompareToConstant5_const_n;
                                   /* Mask Parameter: CompareToConstant5_const_n
                                    * Referenced by: '<S210>/Constant'
                                    */
  real_T CompareToConstant6_const_i;
                                   /* Mask Parameter: CompareToConstant6_const_i
                                    * Referenced by: '<S211>/Constant'
                                    */
  real_T CompareToConstant7_const_ku;
                                  /* Mask Parameter: CompareToConstant7_const_ku
                                   * Referenced by: '<S212>/Constant'
                                   */
  real_T CompareToConstant_const_ie;
                                   /* Mask Parameter: CompareToConstant_const_ie
                                    * Referenced by: '<S213>/Constant'
                                    */
  real_T CompareToConstant1_const_jh;
                                  /* Mask Parameter: CompareToConstant1_const_jh
                                   * Referenced by: '<S214>/Constant'
                                   */
  real_T CompareToConstant2_const_hc;
                                  /* Mask Parameter: CompareToConstant2_const_hc
                                   * Referenced by: '<S215>/Constant'
                                   */
  real_T CompareToConstant3_const_p;
                                   /* Mask Parameter: CompareToConstant3_const_p
                                    * Referenced by: '<S216>/Constant'
                                    */
  real_T CompareToConstant4_const_k;
                                   /* Mask Parameter: CompareToConstant4_const_k
                                    * Referenced by: '<S217>/Constant'
                                    */
  real_T CompareToConstant5_const_k2;
                                  /* Mask Parameter: CompareToConstant5_const_k2
                                   * Referenced by: '<S218>/Constant'
                                   */
  real_T CompareToConstant6_const_h;
                                   /* Mask Parameter: CompareToConstant6_const_h
                                    * Referenced by: '<S219>/Constant'
                                    */
  real_T CompareToConstant7_const_j;
                                   /* Mask Parameter: CompareToConstant7_const_j
                                    * Referenced by: '<S220>/Constant'
                                    */
  real_T CompareToConstant_const_lp;
                                   /* Mask Parameter: CompareToConstant_const_lp
                                    * Referenced by: '<S221>/Constant'
                                    */
  real_T CompareToConstant1_const_ia;
                                  /* Mask Parameter: CompareToConstant1_const_ia
                                   * Referenced by: '<S222>/Constant'
                                   */
  real_T CompareToConstant2_const_l;
                                   /* Mask Parameter: CompareToConstant2_const_l
                                    * Referenced by: '<S223>/Constant'
                                    */
  real_T CompareToConstant3_const_a;
                                   /* Mask Parameter: CompareToConstant3_const_a
                                    * Referenced by: '<S224>/Constant'
                                    */
  real_T CompareToConstant4_const_b;
                                   /* Mask Parameter: CompareToConstant4_const_b
                                    * Referenced by: '<S225>/Constant'
                                    */
  real_T CompareToConstant5_const_it;
                                  /* Mask Parameter: CompareToConstant5_const_it
                                   * Referenced by: '<S226>/Constant'
                                   */
  real_T CompareToConstant6_const_ji;
                                  /* Mask Parameter: CompareToConstant6_const_ji
                                   * Referenced by: '<S227>/Constant'
                                   */
  real_T CompareToConstant7_const_kn;
                                  /* Mask Parameter: CompareToConstant7_const_kn
                                   * Referenced by: '<S228>/Constant'
                                   */
  real_T DL1_isLeft;                   /* Mask Parameter: DL1_isLeft
                                        * Referenced by: '<S157>/isLeft'
                                        */
  real_T DL2_isLeft;                   /* Mask Parameter: DL2_isLeft
                                        * Referenced by: '<S158>/isLeft'
                                        */
  real_T DL3_isLeft;                   /* Mask Parameter: DL3_isLeft
                                        * Referenced by: '<S159>/isLeft'
                                        */
  real_T DL4_isLeft;                   /* Mask Parameter: DL4_isLeft
                                        * Referenced by: '<S160>/isLeft'
                                        */
  real_T DR1_isLeft;                   /* Mask Parameter: DR1_isLeft
                                        * Referenced by: '<S161>/isLeft'
                                        */
  real_T DR2_isLeft;                   /* Mask Parameter: DR2_isLeft
                                        * Referenced by: '<S162>/isLeft'
                                        */
  real_T DR3_isLeft;                   /* Mask Parameter: DR3_isLeft
                                        * Referenced by: '<S163>/isLeft'
                                        */
  real_T DR4_isLeft;                   /* Mask Parameter: DR4_isLeft
                                        * Referenced by: '<S164>/isLeft'
                                        */
  BD_DoorSystem_In_Door Constant4_Value;/* Computed Parameter: Constant4_Value
                                         * Referenced by: '<S152>/Constant4'
                                         */
  BD_DoorSystem_In_Emergency_Door Constant1_Value;/* Computed Parameter: Constant1_Value
                                                   * Referenced by: '<S155>/Constant1'
                                                   */
  BD_DoorSystem_In_Overrides Constant1_Value_p;/* Computed Parameter: Constant1_Value_p
                                                * Referenced by: '<S150>/Constant1'
                                                */
  real_T Constant4_Value_m;            /* Expression: 1
                                        * Referenced by: '<S154>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S157>/Gain'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S154>/Constant3'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S158>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 3
                                        * Referenced by: '<S154>/Constant2'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S159>/Gain'
                                        */
  real_T Constant1_Value_n;            /* Expression: 4
                                        * Referenced by: '<S154>/Constant1'
                                        */
  real_T Gain_Gain_gx;                 /* Expression: -1
                                        * Referenced by: '<S160>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 5
                                        * Referenced by: '<S154>/Constant5'
                                        */
  real_T Gain_Gain_ng;                 /* Expression: -1
                                        * Referenced by: '<S161>/Gain'
                                        */
  real_T Constant6_Value;              /* Expression: 6
                                        * Referenced by: '<S154>/Constant6'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S162>/Gain'
                                        */
  real_T Constant7_Value;              /* Expression: 7
                                        * Referenced by: '<S154>/Constant7'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S163>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 8
                                        * Referenced by: '<S154>/Constant8'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S164>/Gain'
                                        */
};

/* Parameters for system: '<S311>/For Each Subsystem1' */
struct P_CoreSubsys_BEML_EMU_ngo_T_ {
  BD_TrainDynamics_In_Coupler Constant_Value;/* Computed Parameter: Constant_Value
                                              * Referenced by: '<S315>/Constant'
                                              */
};

/* Parameters for system: '<S309>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_ng_T_ {
  BD_TrainDynamics_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                              * Referenced by: '<S311>/Constant'
                                              */
  BD_TrainDynamics_In_Vehicle_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                         * Referenced by: '<S311>/Constant1'
                                                         */
  BD_TrainDynamics_In_Vehicle_Faults Constant2_Value;/* Computed Parameter: Constant2_Value
                                                      * Referenced by: '<S311>/Constant2'
                                                      */
  BD_TrainDynamics_In_Vehicle_CustomDragForces Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                * Referenced by: '<S313>/Constant3'
                                                                */
  P_CoreSubsys_BEML_EMU_ngo_T CoreSubsys;/* '<S311>/For Each Subsystem1' */
};

/* Parameters for system: '<S316>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_fa_T_ {
  real_T DetectIncrease1_vinit;        /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S333>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S334>/Memory'
                       */
  BD_ElectricalSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                                 * Referenced by: '<S318>/Constant'
                                                 */
  BD_ElectricalSystem_In_Vehicle_InputControlStates Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                     * Referenced by: '<S323>/Constant3'
                                                                     */
  BD_ElectricalSystem_In_Vehicle_TCMS Constant3_Value_i;/* Computed Parameter: Constant3_Value_i
                                                         * Referenced by: '<S328>/Constant3'
                                                         */
  BD_ElectricalSystem_In_Vehicle_SignalSys Constant3_Value_f;/* Computed Parameter: Constant3_Value_f
                                                              * Referenced by: '<S327>/Constant3'
                                                              */
  BD_ElectricalSystem_In_Vehicle_Pantograph Constant3_Value_n;/* Computed Parameter: Constant3_Value_n
                                                               * Referenced by: '<S325>/Constant3'
                                                               */
  BD_ElectricalSystem_In_Vehicle_Pneumatics Constant3_Value_b;/* Computed Parameter: Constant3_Value_b
                                                               * Referenced by: '<S326>/Constant3'
                                                               */
  BD_ElectricalSystem_In_Vehicle_Traction Constant3_Value_fi;/* Computed Parameter: Constant3_Value_fi
                                                              * Referenced by: '<S329>/Constant3'
                                                              */
  BD_ElectricalSystem_In_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                    * Referenced by: '<S324>/Constant1'
                                                    */
  BD_ElectricalSystem_In_Vehicle_Coupling Constant3_Value_c;/* Computed Parameter: Constant3_Value_c
                                                             * Referenced by: '<S320>/Constant3'
                                                             */
  BD_ElectricalSystem_In_Vehicle_Doors Constant3_Value_m;/* Computed Parameter: Constant3_Value_m
                                                          * Referenced by: '<S321>/Constant3'
                                                          */
  BD_ElectricalSystem_In_Vehicle_Dynamics Constant3_Value_f5;/* Computed Parameter: Constant3_Value_f5
                                                              * Referenced by: '<S322>/Constant3'
                                                              */
};

/* Parameters for system: '<S337>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_ctkg_T_ {
  BD_PantographSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                                 * Referenced by: '<S339>/Constant'
                                                 */
  BD_PantographSystem_In_Vehicle_Environment Constant3_Value;/* Computed Parameter: Constant3_Value
                                                              * Referenced by: '<S343>/Constant3'
                                                              */
  BD_PantographSystem_In_Vehicle_Control Constant3_Value_m;/* Computed Parameter: Constant3_Value_m
                                                            * Referenced by: '<S341>/Constant3'
                                                            */
  BD_PantographSystem_In_Vehicle_Electrical Constant3_Value_mr;/* Computed Parameter: Constant3_Value_mr
                                                                * Referenced by: '<S342>/Constant3'
                                                                */
  BD_PantographSystem_In_Vehicle_Faults Constant2_Value;/* Computed Parameter: Constant2_Value
                                                         * Referenced by: '<S344>/Constant2'
                                                         */
  BD_PantographSystem_In_Vehicle_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                            * Referenced by: '<S345>/Constant1'
                                                            */
  BD_PantographSystem_In_Vehicle_Pneumatics Constant3_Value_j;/* Computed Parameter: Constant3_Value_j
                                                               * Referenced by: '<S346>/Constant3'
                                                               */
  real_T Constant_Value_g;             /* Expression: 25000
                                        * Referenced by: '<S343>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1
                                        * Referenced by: '<S343>/Constant1'
                                        */
};

/* Parameters for system: '<S351>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_mrlt_T_ {
  BD_PneumaticsSystem_In_Vehicle_ElectricalSignals_Bogie Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                      * Referenced by: '<S354>/Constant3'
                                                                      */
};

/* Parameters for system: '<S347>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_mr_T_ {
  BD_PneumaticsSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                                 * Referenced by: '<S349>/Constant'
                                                 */
  BD_PneumaticsSystem_In_Vehicle_InputControlStates Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                     * Referenced by: '<S353>/Constant3'
                                                                     */
  BD_PneumaticsSystem_In_Vehicle_ElectricalSignals Constant3_Value_d;/* Computed Parameter: Constant3_Value_d
                                                                      * Referenced by: '<S351>/Constant3'
                                                                      */
  BD_PneumaticsSystem_In_Vehicle_PhysicalSignals Constant3_Value_p;/* Computed Parameter: Constant3_Value_p
                                                                    * Referenced by: '<S352>/Constant3'
                                                                    */
  BD_PneumaticsSystem_In_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                    * Referenced by: '<S349>/Constant1'
                                                    */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S352>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S352>/Gain1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S353>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S353>/Constant2'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S353>/Constant7'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S353>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S353>/Constant5'
                                        */
  real_T Constant16_Value;             /* Expression: 1
                                        * Referenced by: '<S353>/Constant16'
                                        */
  real_T Constant15_Value;             /* Expression: 1
                                        * Referenced by: '<S353>/Constant15'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S353>/Constant6'
                                        */
  real_T Constant22_Value;             /* Expression: 1
                                        * Referenced by: '<S353>/Constant22'
                                        */
  real_T Constant23_Value;             /* Expression: 1
                                        * Referenced by: '<S353>/Constant23'
                                        */
  P_CoreSubsys_BEML_EMU_mrlt_T CoreSubsys_i;/* '<S351>/For Each Subsystem' */
};

/* Parameters for system: '<S359>/ExtractConfig' */
struct P_CoreSubsys_BEML_EMU_ci_T_ {
  BD_TCMSSystem_Cfg_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                            * Referenced by: '<S361>/Constant'
                                            */
};

/* Parameters for system: '<S373>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_ciae4_T_ {
  BD_TCMSSystem_In_Vehicle_TractionSystem_Bogie Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                 * Referenced by: '<S381>/Constant3'
                                                                 */
};

/* Parameters for system: '<S372>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_ciae4o_T_ {
  BD_TCMSSystem_In_Vehicle_PneumaticsSystem_Bogie Constant3_Value;/* Computed Parameter: Constant3_Value
                                                                   * Referenced by: '<S380>/Constant3'
                                                                   */
};

/* Parameters for system: '<S366>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_ciae4ow_T_ {
  BD_TCMSSystem_In_Vehicle_DoorSystem_Door Constant3_Value;/* Computed Parameter: Constant3_Value
                                                            * Referenced by: '<S376>/Constant3'
                                                            */
};

/* Parameters for system: '<S358>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_cia_T_ {
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S379>/Memory'
                        */
  boolean_T DetectDecrease_vinit;      /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S377>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S378>/Delay Input1'
                                        */
  BD_TCMSSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                           * Referenced by: '<S360>/Constant'
                                           */
  BD_TCMSSystem_In_Vehicle_ElectricalSignals Constant3_Value;/* Computed Parameter: Constant3_Value
                                                              * Referenced by: '<S368>/Constant3'
                                                              */
  BD_TCMSSystem_In_Vehicle_DoorSystem Constant3_Value_j;/* Computed Parameter: Constant3_Value_j
                                                         * Referenced by: '<S366>/Constant3'
                                                         */
  BD_TCMSSystem_In_Vehicle_InputControlStates Constant3_Value_js;/* Computed Parameter: Constant3_Value_js
                                                                  * Referenced by: '<S370>/Constant3'
                                                                  */
  BD_TCMSSystem_In_Vehicle_TractionSystem Constant3_Value_h;/* Computed Parameter: Constant3_Value_h
                                                             * Referenced by: '<S373>/Constant3'
                                                             */
  BD_TCMSSystem_In_Vehicle_PneumaticsSystem Constant3_Value_g;/* Computed Parameter: Constant3_Value_g
                                                               * Referenced by: '<S372>/Constant3'
                                                               */
  BD_TCMSSystem_In_Vehicle_CBTC Constant3_Value_g2;/* Computed Parameter: Constant3_Value_g2
                                                    * Referenced by: '<S363>/Constant3'
                                                    */
  BD_TCMSSystem_In_Vehicle_Environment Constant3_Value_c;/* Computed Parameter: Constant3_Value_c
                                                          * Referenced by: '<S369>/Constant3'
                                                          */
  BD_TCMSSystem_In_Vehicle_CouplingSystem Constant3_Value_hv;/* Computed Parameter: Constant3_Value_hv
                                                              * Referenced by: '<S364>/Constant3'
                                                              */
  BD_TCMSSystem_In_Vehicle_PantographSystem Constant3_Value_n;/* Computed Parameter: Constant3_Value_n
                                                               * Referenced by: '<S371>/Constant3'
                                                               */
  BD_TCMSSystem_In_Vehicle_BrakingSystem Constant3_Value_m;/* Computed Parameter: Constant3_Value_m
                                                            * Referenced by: '<S362>/Constant3'
                                                            */
  BD_TCMSSystem_In_Vehicle_DoorSystem_EmergencyDoor Constant_Value_a;/* Computed Parameter: Constant_Value_a
                                                                      * Referenced by: '<S366>/Constant'
                                                                      */
  BD_TCMSSystem_In_Vehicle_DynamicsSystem Constant3_Value_b;/* Computed Parameter: Constant3_Value_b
                                                             * Referenced by: '<S367>/Constant3'
                                                             */
  BD_TCMSSystem_In_Vehicle_Overrides Constant1_Value;/* Computed Parameter: Constant1_Value
                                                      * Referenced by: '<S360>/Constant1'
                                                      */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S368>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S363>/Switch'
                                        */
  P_CoreSubsys_BEML_EMU_ciae4ow_T CoreSubsys_gfy;/* '<S366>/For Each Subsystem' */
  P_CoreSubsys_BEML_EMU_ciae4o_T CoreSubsys_gf;/* '<S372>/For Each Subsystem' */
  P_CoreSubsys_BEML_EMU_ciae4_T CoreSubsys_g;/* '<S373>/For Each Subsystem' */
};

/* Parameters for system: '<S389>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_d5hx4_T_ {
  BD_TractionSystem_In_Vehicle_TCMS_Bogie Constant1_Value;/* Computed Parameter: Constant1_Value
                                                           * Referenced by: '<S394>/Constant1'
                                                           */
};

/* Parameters for system: '<S383>/VehicleInputAdapter' */
struct P_CoreSubsys_BEML_EMU_d5_T_ {
  real_T Difference1_ICPrevInput;     /* Mask Parameter: Difference1_ICPrevInput
                                       * Referenced by: '<S390>/UD'
                                       */
  real_T Difference2_ICPrevInput;     /* Mask Parameter: Difference2_ICPrevInput
                                       * Referenced by: '<S391>/UD'
                                       */
  BD_TractionSystem_In_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                               * Referenced by: '<S385>/Constant'
                                               */
  BD_TractionSystem_In_Vehicle_Dynamics Constant3_Value;/* Computed Parameter: Constant3_Value
                                                         * Referenced by: '<S393>/Constant3'
                                                         */
  BD_TractionSystem_In_Vehicle_TCMS Constant3_Value_o;/* Computed Parameter: Constant3_Value_o
                                                       * Referenced by: '<S389>/Constant3'
                                                       */
  BD_TractionSystem_In_Vehicle_ElectricalSystem Constant3_Value_g;/* Computed Parameter: Constant3_Value_g
                                                                   * Referenced by: '<S392>/Constant3'
                                                                   */
  BD_TractionSystem_In_Vehicle_Dynamics_Bogie Constant1_Value;/* Computed Parameter: Constant1_Value
                                                               * Referenced by: '<S397>/Constant1'
                                                               */
  BD_TractionSystem_In_Vehicle_Dynamics_Bogie Constant1_Value_i;/* Computed Parameter: Constant1_Value_i
                                                                 * Referenced by: '<S398>/Constant1'
                                                                 */
  BD_TractionSystem_In_Vehicle_ElectricalSystem_Bogie Constant1_Value_ip[2];/* Computed Parameter: Constant1_Value_ip
                                                                      * Referenced by: '<S392>/Constant1'
                                                                      */
  BD_TractionSystem_In_Overrides Constant1_Value_n;/* Computed Parameter: Constant1_Value_n
                                                    * Referenced by: '<S385>/Constant1'
                                                    */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S385>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S387>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S388>/Constant'
                                        */
  P_CoreSubsys_BEML_EMU_d5hx4_T CoreSubsys_cr;/* '<S389>/For Each Subsystem' */
};

/* Parameters for system: '<S448>/IRQRequestStateMachine' */
struct P_IRQRequestStateMachine_BEML_EMU_T_ {
  real_T IRQRequestStateMachine_ReturnToNormalState;/* Expression: ReturnToNormalState
                                                     * Referenced by: '<S448>/IRQRequestStateMachine'
                                                     */
  real_T IRQRequestStateMachine_TriggerContinously;/* Expression: TriggerContinously
                                                    * Referenced by: '<S448>/IRQRequestStateMachine'
                                                    */
};

/* Parameters for system: '<S426>/ControlStateRequest' */
struct P_ControlStateRequest_BEML_EMU_T_ {
  real_T Increment_const;              /* Mask Parameter: Increment_const
                                        * Referenced by: '<S480>/Constant'
                                        */
  real_T Momentary_const;              /* Mask Parameter: Momentary_const
                                        * Referenced by: '<S481>/Constant'
                                        */
  real_T ControlStateRq_Y0;            /* Computed Parameter: ControlStateRq_Y0
                                        * Referenced by: '<S478>/ControlStateRq'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S482>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S482>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S482>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 1
                                        * Referenced by: '<S482>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 50
                                        * Referenced by: '<S482>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S482>/Pulse Generator'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S482>/Weighted Sample Time'
                                   */
  boolean_T Complete_Y0;               /* Computed Parameter: Complete_Y0
                                        * Referenced by: '<S478>/Complete'
                                        */
};

/* Parameters for system: '<S426>/Chart' */
struct P_Chart_BEML_EMU_T_ {
  real_T Chart_ReturnToNormalState;    /* Expression: ReturnToNormalState
                                        * Referenced by: '<S426>/Chart'
                                        */
};

/* Parameters for system: '<S400>/Subsystem' */
struct P_CoreSubsys_BEML_EMU_g_T_ {
  real_T ControlStateRequestLogic_ControlType;
                         /* Mask Parameter: ControlStateRequestLogic_ControlType
                          * Referenced by: '<S485>/Constant'
                          */
  real_T ControlStateRequestLogic_ControlType_o;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_o
                        * Referenced by: '<S493>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_g;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_g
                        * Referenced by: '<S581>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_n;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_n
                        * Referenced by: '<S605>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_c;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_c
                        * Referenced by: '<S613>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_k;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_k
                        * Referenced by: '<S621>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_np;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_np
                       * Referenced by: '<S629>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_l;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_l
                        * Referenced by: '<S637>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_d;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_d
                        * Referenced by: '<S645>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_ot;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_ot
                       * Referenced by: '<S653>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_c1;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_c1
                       * Referenced by: '<S501>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_f;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_f
                        * Referenced by: '<S509>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_otb;
                     /* Mask Parameter: ControlStateRequestLogic_ControlType_otb
                      * Referenced by: '<S517>/Constant'
                      */
  real_T ControlStateRequestLogic_ControlType_h;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_h
                        * Referenced by: '<S525>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_le;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_le
                       * Referenced by: '<S533>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_i;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_i
                        * Referenced by: '<S541>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_cp;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_cp
                       * Referenced by: '<S549>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_dh;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_dh
                       * Referenced by: '<S557>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_p;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_p
                        * Referenced by: '<S565>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_e;
                       /* Mask Parameter: ControlStateRequestLogic_ControlType_e
                        * Referenced by: '<S573>/Constant'
                        */
  real_T ControlStateRequestLogic_ControlType_db;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_db
                       * Referenced by: '<S589>/Constant'
                       */
  real_T ControlStateRequestLogic_ControlType_dj;
                      /* Mask Parameter: ControlStateRequestLogic_ControlType_dj
                       * Referenced by: '<S597>/Constant'
                       */
  real_T ControlStateRequest_ControlType;
                              /* Mask Parameter: ControlStateRequest_ControlType
                               * Referenced by: '<S423>/ControlStateRequest'
                               */
  real_T ControlStateRequest_ControlType_b;
                            /* Mask Parameter: ControlStateRequest_ControlType_b
                             * Referenced by: '<S424>/ControlStateRequest'
                             */
  real_T ControlStateRequest_ControlType_k;
                            /* Mask Parameter: ControlStateRequest_ControlType_k
                             * Referenced by: '<S425>/ControlStateRequest'
                             */
  real_T ControlStateRequest_ControlType_l;
                            /* Mask Parameter: ControlStateRequest_ControlType_l
                             * Referenced by: '<S426>/ControlStateRequest'
                             */
  real_T ControlStateFault3_FltStVal;
                                  /* Mask Parameter: ControlStateFault3_FltStVal
                                   * Referenced by: '<S426>/Constant1'
                                   */
  real_T ControlStateFault2_FltStVal;
                                  /* Mask Parameter: ControlStateFault2_FltStVal
                                   * Referenced by: '<S425>/Constant1'
                                   */
  real_T ControlStateFault1_FltStVal;
                                  /* Mask Parameter: ControlStateFault1_FltStVal
                                   * Referenced by: '<S424>/Constant1'
                                   */
  real_T ControlStateFault_FltStVal;
                                   /* Mask Parameter: ControlStateFault_FltStVal
                                    * Referenced by: '<S423>/Constant1'
                                    */
  real_T ControlStateFault3_NormalStVal;
                               /* Mask Parameter: ControlStateFault3_NormalStVal
                                * Referenced by: '<S426>/Constant'
                                */
  real_T ControlStateFault2_NormalStVal;
                               /* Mask Parameter: ControlStateFault2_NormalStVal
                                * Referenced by: '<S425>/Constant'
                                */
  real_T ControlStateFault1_NormalStVal;
                               /* Mask Parameter: ControlStateFault1_NormalStVal
                                * Referenced by: '<S424>/Constant'
                                */
  real_T ControlStateFault_NormalStVal;
                                /* Mask Parameter: ControlStateFault_NormalStVal
                                 * Referenced by: '<S423>/Constant'
                                 */
  real_T Momentary_const;              /* Mask Parameter: Momentary_const
                                        * Referenced by: '<S489>/Constant'
                                        */
  real_T Increment_const;              /* Mask Parameter: Increment_const
                                        * Referenced by: '<S488>/Constant'
                                        */
  real_T Momentary_const_g;            /* Mask Parameter: Momentary_const_g
                                        * Referenced by: '<S497>/Constant'
                                        */
  real_T Increment_const_b;            /* Mask Parameter: Increment_const_b
                                        * Referenced by: '<S496>/Constant'
                                        */
  real_T Momentary_const_f;            /* Mask Parameter: Momentary_const_f
                                        * Referenced by: '<S585>/Constant'
                                        */
  real_T Increment_const_m;            /* Mask Parameter: Increment_const_m
                                        * Referenced by: '<S584>/Constant'
                                        */
  real_T Momentary_const_a;            /* Mask Parameter: Momentary_const_a
                                        * Referenced by: '<S609>/Constant'
                                        */
  real_T Increment_const_a;            /* Mask Parameter: Increment_const_a
                                        * Referenced by: '<S608>/Constant'
                                        */
  real_T Momentary_const_d;            /* Mask Parameter: Momentary_const_d
                                        * Referenced by: '<S617>/Constant'
                                        */
  real_T Increment_const_d;            /* Mask Parameter: Increment_const_d
                                        * Referenced by: '<S616>/Constant'
                                        */
  real_T Momentary_const_c;            /* Mask Parameter: Momentary_const_c
                                        * Referenced by: '<S625>/Constant'
                                        */
  real_T Increment_const_c;            /* Mask Parameter: Increment_const_c
                                        * Referenced by: '<S624>/Constant'
                                        */
  real_T Momentary_const_o;            /* Mask Parameter: Momentary_const_o
                                        * Referenced by: '<S633>/Constant'
                                        */
  real_T Increment_const_i;            /* Mask Parameter: Increment_const_i
                                        * Referenced by: '<S632>/Constant'
                                        */
  real_T Momentary_const_ob;           /* Mask Parameter: Momentary_const_ob
                                        * Referenced by: '<S641>/Constant'
                                        */
  real_T Increment_const_ah;           /* Mask Parameter: Increment_const_ah
                                        * Referenced by: '<S640>/Constant'
                                        */
  real_T Momentary_const_l;            /* Mask Parameter: Momentary_const_l
                                        * Referenced by: '<S649>/Constant'
                                        */
  real_T Increment_const_i0;           /* Mask Parameter: Increment_const_i0
                                        * Referenced by: '<S648>/Constant'
                                        */
  real_T Momentary_const_j;            /* Mask Parameter: Momentary_const_j
                                        * Referenced by: '<S657>/Constant'
                                        */
  real_T Increment_const_h;            /* Mask Parameter: Increment_const_h
                                        * Referenced by: '<S656>/Constant'
                                        */
  real_T Momentary_const_p;            /* Mask Parameter: Momentary_const_p
                                        * Referenced by: '<S505>/Constant'
                                        */
  real_T Increment_const_l;            /* Mask Parameter: Increment_const_l
                                        * Referenced by: '<S504>/Constant'
                                        */
  real_T Momentary_const_cn;           /* Mask Parameter: Momentary_const_cn
                                        * Referenced by: '<S513>/Constant'
                                        */
  real_T Increment_const_m4;           /* Mask Parameter: Increment_const_m4
                                        * Referenced by: '<S512>/Constant'
                                        */
  real_T Momentary_const_k;            /* Mask Parameter: Momentary_const_k
                                        * Referenced by: '<S521>/Constant'
                                        */
  real_T Increment_const_e;            /* Mask Parameter: Increment_const_e
                                        * Referenced by: '<S520>/Constant'
                                        */
  real_T Momentary_const_i;            /* Mask Parameter: Momentary_const_i
                                        * Referenced by: '<S529>/Constant'
                                        */
  real_T Increment_const_ex;           /* Mask Parameter: Increment_const_ex
                                        * Referenced by: '<S528>/Constant'
                                        */
  real_T Momentary_const_b;            /* Mask Parameter: Momentary_const_b
                                        * Referenced by: '<S537>/Constant'
                                        */
  real_T Increment_const_k;            /* Mask Parameter: Increment_const_k
                                        * Referenced by: '<S536>/Constant'
                                        */
  real_T Momentary_const_m;            /* Mask Parameter: Momentary_const_m
                                        * Referenced by: '<S545>/Constant'
                                        */
  real_T Increment_const_f;            /* Mask Parameter: Increment_const_f
                                        * Referenced by: '<S544>/Constant'
                                        */
  real_T Momentary_const_n;            /* Mask Parameter: Momentary_const_n
                                        * Referenced by: '<S553>/Constant'
                                        */
  real_T Increment_const_lv;           /* Mask Parameter: Increment_const_lv
                                        * Referenced by: '<S552>/Constant'
                                        */
  real_T Momentary_const_gc;           /* Mask Parameter: Momentary_const_gc
                                        * Referenced by: '<S561>/Constant'
                                        */
  real_T Increment_const_hk;           /* Mask Parameter: Increment_const_hk
                                        * Referenced by: '<S560>/Constant'
                                        */
  real_T Momentary_const_h;            /* Mask Parameter: Momentary_const_h
                                        * Referenced by: '<S569>/Constant'
                                        */
  real_T Increment_const_g;            /* Mask Parameter: Increment_const_g
                                        * Referenced by: '<S568>/Constant'
                                        */
  real_T Momentary_const_b4;           /* Mask Parameter: Momentary_const_b4
                                        * Referenced by: '<S577>/Constant'
                                        */
  real_T Increment_const_p;            /* Mask Parameter: Increment_const_p
                                        * Referenced by: '<S576>/Constant'
                                        */
  real_T Momentary_const_ah;           /* Mask Parameter: Momentary_const_ah
                                        * Referenced by: '<S593>/Constant'
                                        */
  real_T Increment_const_ik;           /* Mask Parameter: Increment_const_ik
                                        * Referenced by: '<S592>/Constant'
                                        */
  real_T Momentary_const_pg;           /* Mask Parameter: Momentary_const_pg
                                        * Referenced by: '<S601>/Constant'
                                        */
  real_T Increment_const_pd;           /* Mask Parameter: Increment_const_pd
                                        * Referenced by: '<S600>/Constant'
                                        */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S419>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S416>/Delay Input1'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S415>/Delay Input1'
                                        */
  real_T DetectDecrease2_vinit;        /* Mask Parameter: DetectDecrease2_vinit
                                        * Referenced by: '<S418>/Delay Input1'
                                        */
  real_T DetectDecrease1_vinit;        /* Mask Parameter: DetectDecrease1_vinit
                                        * Referenced by: '<S417>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S421>/Memory'
                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S422>/Memory'
                       */
  boolean_T DetectIncrease1_vinit;     /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S420>/Delay Input1'
                                        */
  BD_SimIntegration_Faults_Vehicle Constant1_Value;/* Computed Parameter: Constant1_Value
                                                    * Referenced by: '<S412>/Constant1'
                                                    */
  BD_ElectricalSystem_In_Faults Constant1_Value_n;/* Computed Parameter: Constant1_Value_n
                                                   * Referenced by: '<S406>/Constant1'
                                                   */
  BD_TractionSystem_In_Faults Constant1_Value_i;/* Computed Parameter: Constant1_Value_i
                                                 * Referenced by: '<S411>/Constant1'
                                                 */
  BD_PneumaticsSystem_In_Vehicle_Faults Constant1_Value_b;/* Computed Parameter: Constant1_Value_b
                                                           * Referenced by: '<S408>/Constant1'
                                                           */
  BD_DoorSystem_In_Door_Faults Constant1_Value_e;/* Computed Parameter: Constant1_Value_e
                                                  * Referenced by: '<S405>/Constant1'
                                                  */
  BD_TCMSSystem_In_Vehicle_Faults Constant1_Value_k;/* Computed Parameter: Constant1_Value_k
                                                     * Referenced by: '<S410>/Constant1'
                                                     */
  BD_PantographSystem_In_Vehicle_Faults Constant1_Value_a;/* Computed Parameter: Constant1_Value_a
                                                           * Referenced by: '<S407>/Constant1'
                                                           */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S414>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: FltStVal
                                        * Referenced by: '<S427>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: NormalStVal
                                        * Referenced by: '<S427>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S490>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S490>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: Amplitude
                                        * Referenced by: '<S490>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: Period
                                        * Referenced by: '<S490>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: PulseWidth
                                        * Referenced by: '<S490>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: PhaseDelay
                                        * Referenced by: '<S490>/Pulse Generator'
                                        */
  real_T Constant1_Value_j;            /* Expression: FltStVal
                                        * Referenced by: '<S428>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: NormalStVal
                                        * Referenced by: '<S428>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_o;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_o
                          * Referenced by: '<S498>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S498>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_e;         /* Expression: Amplitude
                                        * Referenced by: '<S498>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_l;      /* Expression: Period
                                        * Referenced by: '<S498>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_m;        /* Expression: PulseWidth
                                        * Referenced by: '<S498>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_h;  /* Expression: PhaseDelay
                                        * Referenced by: '<S498>/Pulse Generator'
                                        */
  real_T Constant1_Value_f;            /* Expression: FltStVal
                                        * Referenced by: '<S439>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: NormalStVal
                                        * Referenced by: '<S439>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_g;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_g
                          * Referenced by: '<S586>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S586>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_o;         /* Expression: Amplitude
                                        * Referenced by: '<S586>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_k;      /* Expression: Period
                                        * Referenced by: '<S586>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_mt;       /* Expression: PulseWidth
                                        * Referenced by: '<S586>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_m;  /* Expression: PhaseDelay
                                        * Referenced by: '<S586>/Pulse Generator'
                                        */
  real_T Constant1_Value_mw;           /* Expression: FltStVal
                                        * Referenced by: '<S442>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: NormalStVal
                                        * Referenced by: '<S442>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_n;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                          * Referenced by: '<S610>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_no; /* Expression: 0
                                        * Referenced by: '<S610>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_m;         /* Expression: Amplitude
                                        * Referenced by: '<S610>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_d;      /* Expression: Period
                                        * Referenced by: '<S610>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_k;        /* Expression: PulseWidth
                                        * Referenced by: '<S610>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_f;  /* Expression: PhaseDelay
                                        * Referenced by: '<S610>/Pulse Generator'
                                        */
  real_T Constant1_Value_jy;           /* Expression: FltStVal
                                        * Referenced by: '<S443>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: NormalStVal
                                        * Referenced by: '<S443>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_d;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_d
                          * Referenced by: '<S618>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S618>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_b;         /* Expression: Amplitude
                                        * Referenced by: '<S618>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_a;      /* Expression: Period
                                        * Referenced by: '<S618>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_g;        /* Expression: PulseWidth
                                        * Referenced by: '<S618>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_b;  /* Expression: PhaseDelay
                                        * Referenced by: '<S618>/Pulse Generator'
                                        */
  real_T Constant1_Value_g;            /* Expression: FltStVal
                                        * Referenced by: '<S444>/Constant1'
                                        */
  real_T Constant_Value_kj;            /* Expression: NormalStVal
                                        * Referenced by: '<S444>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_h;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_h
                          * Referenced by: '<S626>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_ca; /* Expression: 0
                                        * Referenced by: '<S626>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_a;         /* Expression: Amplitude
                                        * Referenced by: '<S626>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_n;      /* Expression: Period
                                        * Referenced by: '<S626>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_c;        /* Expression: PulseWidth
                                        * Referenced by: '<S626>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_i;  /* Expression: PhaseDelay
                                        * Referenced by: '<S626>/Pulse Generator'
                                        */
  real_T Constant1_Value_h;            /* Expression: FltStVal
                                        * Referenced by: '<S445>/Constant1'
                                        */
  real_T Constant_Value_kw;            /* Expression: NormalStVal
                                        * Referenced by: '<S445>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_hb;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_hb
                         * Referenced by: '<S634>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S634>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_az;        /* Expression: Amplitude
                                        * Referenced by: '<S634>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_dh;     /* Expression: Period
                                        * Referenced by: '<S634>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_i;        /* Expression: PulseWidth
                                        * Referenced by: '<S634>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_hv; /* Expression: PhaseDelay
                                        * Referenced by: '<S634>/Pulse Generator'
                                        */
  real_T Constant1_Value_in;           /* Expression: FltStVal
                                        * Referenced by: '<S446>/Constant1'
                                        */
  real_T Constant_Value_bp;            /* Expression: NormalStVal
                                        * Referenced by: '<S446>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_hc;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_hc
                         * Referenced by: '<S642>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_n2; /* Expression: 0
                                        * Referenced by: '<S642>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_h;         /* Expression: Amplitude
                                        * Referenced by: '<S642>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_m;      /* Expression: Period
                                        * Referenced by: '<S642>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_ih;       /* Expression: PulseWidth
                                        * Referenced by: '<S642>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_l;  /* Expression: PhaseDelay
                                        * Referenced by: '<S642>/Pulse Generator'
                                        */
  real_T Constant1_Value_jj;           /* Expression: FltStVal
                                        * Referenced by: '<S447>/Constant1'
                                        */
  real_T Constant_Value_ep;            /* Expression: NormalStVal
                                        * Referenced by: '<S447>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_k;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_k
                          * Referenced by: '<S650>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_c4; /* Expression: 0
                                        * Referenced by: '<S650>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_a1;        /* Expression: Amplitude
                                        * Referenced by: '<S650>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_j;      /* Expression: Period
                                        * Referenced by: '<S650>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_b;        /* Expression: PulseWidth
                                        * Referenced by: '<S650>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_g;  /* Expression: PhaseDelay
                                        * Referenced by: '<S650>/Pulse Generator'
                                        */
  real_T Constant1_Value_mc;           /* Expression: FltStVal
                                        * Referenced by: '<S448>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: NormalStVal
                                        * Referenced by: '<S448>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_j;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_j
                          * Referenced by: '<S658>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S658>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_l;         /* Expression: Amplitude
                                        * Referenced by: '<S658>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p;      /* Expression: Period
                                        * Referenced by: '<S658>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_e;        /* Expression: PulseWidth
                                        * Referenced by: '<S658>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_iz; /* Expression: PhaseDelay
                                        * Referenced by: '<S658>/Pulse Generator'
                                        */
  real_T Constant1_Value_p;            /* Expression: FltStVal
                                        * Referenced by: '<S429>/Constant1'
                                        */
  real_T Constant_Value_eg;            /* Expression: NormalStVal
                                        * Referenced by: '<S429>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_l;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_l
                          * Referenced by: '<S506>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S506>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_f;         /* Expression: Amplitude
                                        * Referenced by: '<S506>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_c;      /* Expression: Period
                                        * Referenced by: '<S506>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_eb;       /* Expression: PulseWidth
                                        * Referenced by: '<S506>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_d;  /* Expression: PhaseDelay
                                        * Referenced by: '<S506>/Pulse Generator'
                                        */
  real_T Constant1_Value_iz;           /* Expression: FltStVal
                                        * Referenced by: '<S430>/Constant1'
                                        */
  real_T Constant_Value_p;             /* Expression: NormalStVal
                                        * Referenced by: '<S430>/Constant'
                                        */
  real_T CDUCB1_FixMe_Value;           /* Expression: 1
                                        * Referenced by: '<S456>/CDUCB1_FixMe'
                                        */
  real_T ERCB1_FixMe1_Value;           /* Expression: 1
                                        * Referenced by: '<S456>/ERCB1_FixMe1'
                                        */
  real_T DiscreteTimeIntegrator_gainval_m;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_m
                          * Referenced by: '<S514>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S514>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_h4;        /* Expression: Amplitude
                                        * Referenced by: '<S514>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_f;      /* Expression: Period
                                        * Referenced by: '<S514>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_ir;       /* Expression: PulseWidth
                                        * Referenced by: '<S514>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_n;  /* Expression: PhaseDelay
                                        * Referenced by: '<S514>/Pulse Generator'
                                        */
  real_T Constant1_Value_d;            /* Expression: FltStVal
                                        * Referenced by: '<S431>/Constant1'
                                        */
  real_T Constant_Value_eq;            /* Expression: NormalStVal
                                        * Referenced by: '<S431>/Constant'
                                        */
  real_T CRSACB_FixME_Value;           /* Expression: 1
                                        * Referenced by: '<S457>/CRSACB_FixME'
                                        */
  real_T DiscreteTimeIntegrator_gainval_ds;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_ds
                         * Referenced by: '<S522>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S522>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_lv;        /* Expression: Amplitude
                                        * Referenced by: '<S522>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_jm;     /* Expression: Period
                                        * Referenced by: '<S522>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_b2;       /* Expression: PulseWidth
                                        * Referenced by: '<S522>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_it; /* Expression: PhaseDelay
                                        * Referenced by: '<S522>/Pulse Generator'
                                        */
  real_T Constant1_Value_j4;           /* Expression: FltStVal
                                        * Referenced by: '<S432>/Constant1'
                                        */
  real_T Constant_Value_m3;            /* Expression: NormalStVal
                                        * Referenced by: '<S432>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_g3;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_g3
                         * Referenced by: '<S530>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S530>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_d;         /* Expression: Amplitude
                                        * Referenced by: '<S530>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_km;     /* Expression: Period
                                        * Referenced by: '<S530>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_km;       /* Expression: PulseWidth
                                        * Referenced by: '<S530>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_bz; /* Expression: PhaseDelay
                                        * Referenced by: '<S530>/Pulse Generator'
                                        */
  real_T Constant1_Value_o;            /* Expression: FltStVal
                                        * Referenced by: '<S433>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: NormalStVal
                                        * Referenced by: '<S433>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_d4;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_d4
                         * Referenced by: '<S538>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S538>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_hk;        /* Expression: Amplitude
                                        * Referenced by: '<S538>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_cz;     /* Expression: Period
                                        * Referenced by: '<S538>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_ck;       /* Expression: PulseWidth
                                        * Referenced by: '<S538>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_k;  /* Expression: PhaseDelay
                                        * Referenced by: '<S538>/Pulse Generator'
                                        */
  real_T Constant1_Value_ph;           /* Expression: FltStVal
                                        * Referenced by: '<S434>/Constant1'
                                        */
  real_T Constant_Value_bu;            /* Expression: NormalStVal
                                        * Referenced by: '<S434>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_gz;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_gz
                         * Referenced by: '<S546>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_ln; /* Expression: 0
                                        * Referenced by: '<S546>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_ly;        /* Expression: Amplitude
                                        * Referenced by: '<S546>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_jo;     /* Expression: Period
                                        * Referenced by: '<S546>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_n;        /* Expression: PulseWidth
                                        * Referenced by: '<S546>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_ic; /* Expression: PhaseDelay
                                        * Referenced by: '<S546>/Pulse Generator'
                                        */
  real_T Constant1_Value_no;           /* Expression: FltStVal
                                        * Referenced by: '<S435>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: NormalStVal
                                        * Referenced by: '<S435>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_e;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_e
                          * Referenced by: '<S554>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_nl; /* Expression: 0
                                        * Referenced by: '<S554>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_c;         /* Expression: Amplitude
                                        * Referenced by: '<S554>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_b;      /* Expression: Period
                                        * Referenced by: '<S554>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_kk;       /* Expression: PulseWidth
                                        * Referenced by: '<S554>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_o;  /* Expression: PhaseDelay
                                        * Referenced by: '<S554>/Pulse Generator'
                                        */
  real_T Constant1_Value_gr;           /* Expression: FltStVal
                                        * Referenced by: '<S436>/Constant1'
                                        */
  real_T Constant_Value_bd;            /* Expression: NormalStVal
                                        * Referenced by: '<S436>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_f;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_f
                          * Referenced by: '<S562>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S562>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_oa;        /* Expression: Amplitude
                                        * Referenced by: '<S562>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_f5;     /* Expression: Period
                                        * Referenced by: '<S562>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_o;        /* Expression: PulseWidth
                                        * Referenced by: '<S562>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_e;  /* Expression: PhaseDelay
                                        * Referenced by: '<S562>/Pulse Generator'
                                        */
  real_T Constant1_Value_f1;           /* Expression: FltStVal
                                        * Referenced by: '<S437>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: NormalStVal
                                        * Referenced by: '<S437>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_fb;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_fb
                         * Referenced by: '<S570>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_np; /* Expression: 0
                                        * Referenced by: '<S570>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_cd;        /* Expression: Amplitude
                                        * Referenced by: '<S570>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_e;      /* Expression: Period
                                        * Referenced by: '<S570>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_f;        /* Expression: PulseWidth
                                        * Referenced by: '<S570>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_hf; /* Expression: PhaseDelay
                                        * Referenced by: '<S570>/Pulse Generator'
                                        */
  real_T Constant1_Value_nk;           /* Expression: FltStVal
                                        * Referenced by: '<S438>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: NormalStVal
                                        * Referenced by: '<S438>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_p;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_p
                          * Referenced by: '<S578>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_po; /* Expression: 0
                                        * Referenced by: '<S578>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_ah;        /* Expression: Amplitude
                                        * Referenced by: '<S578>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_kh;     /* Expression: Period
                                        * Referenced by: '<S578>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_a;        /* Expression: PulseWidth
                                        * Referenced by: '<S578>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_n5; /* Expression: PhaseDelay
                                        * Referenced by: '<S578>/Pulse Generator'
                                        */
  real_T Constant1_Value_k5;           /* Expression: FltStVal
                                        * Referenced by: '<S440>/Constant1'
                                        */
  real_T Constant_Value_b3;            /* Expression: NormalStVal
                                        * Referenced by: '<S440>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_n4;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_n4
                         * Referenced by: '<S594>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_j2; /* Expression: 0
                                        * Referenced by: '<S594>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_dp;        /* Expression: Amplitude
                                        * Referenced by: '<S594>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_kx;     /* Expression: Period
                                        * Referenced by: '<S594>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_j;        /* Expression: PulseWidth
                                        * Referenced by: '<S594>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_c;  /* Expression: PhaseDelay
                                        * Referenced by: '<S594>/Pulse Generator'
                                        */
  real_T Constant1_Value_h4;           /* Expression: FltStVal
                                        * Referenced by: '<S441>/Constant1'
                                        */
  real_T Constant_Value_ac;            /* Expression: NormalStVal
                                        * Referenced by: '<S441>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval_oo;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_oo
                         * Referenced by: '<S602>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_be; /* Expression: 0
                                        * Referenced by: '<S602>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_n;         /* Expression: Amplitude
                                        * Referenced by: '<S602>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_ld;     /* Expression: Period
                                        * Referenced by: '<S602>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_d;        /* Expression: PulseWidth
                                        * Referenced by: '<S602>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_a;  /* Expression: PhaseDelay
                                        * Referenced by: '<S602>/Pulse Generator'
                                        */
  boolean_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S409>/Unit Delay1'
                               */
  boolean_T RateTransition1_InitialCondition;
                         /* Computed Parameter: RateTransition1_InitialCondition
                          * Referenced by: '<S409>/Rate Transition1'
                          */
  boolean_T RateTransition2_InitialCondition;
                         /* Computed Parameter: RateTransition2_InitialCondition
                          * Referenced by: '<S409>/Rate Transition2'
                          */
  boolean_T RateTransition3_InitialCondition;
                         /* Computed Parameter: RateTransition3_InitialCondition
                          * Referenced by: '<S409>/Rate Transition3'
                          */
  boolean_T RateTransition4_InitialCondition;
                         /* Computed Parameter: RateTransition4_InitialCondition
                          * Referenced by: '<S409>/Rate Transition4'
                          */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S423>/Unit Delay'
                                */
  boolean_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S424>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_h;
                             /* Computed Parameter: UnitDelay_InitialCondition_h
                              * Referenced by: '<S425>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_c;
                             /* Computed Parameter: UnitDelay_InitialCondition_c
                              * Referenced by: '<S426>/Unit Delay'
                              */
  P_Chart_BEML_EMU_T sf_Chart_f;       /* '<S423>/Chart' */
  P_ControlStateRequest_BEML_EMU_T ControlStateRequest_a;/* '<S423>/ControlStateRequest' */
  P_Chart_BEML_EMU_T sf_Chart_k;       /* '<S424>/Chart' */
  P_ControlStateRequest_BEML_EMU_T ControlStateRequest_n;/* '<S424>/ControlStateRequest' */
  P_Chart_BEML_EMU_T sf_Chart_e;       /* '<S425>/Chart' */
  P_ControlStateRequest_BEML_EMU_T ControlStateRequest_i;/* '<S425>/ControlStateRequest' */
  P_Chart_BEML_EMU_T sf_Chart;         /* '<S426>/Chart' */
  P_ControlStateRequest_BEML_EMU_T ControlStateRequest;/* '<S426>/ControlStateRequest' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_in;/* '<S427>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_fm;/* '<S428>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_a;/* '<S429>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_d;/* '<S430>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_f;/* '<S431>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_hr;/* '<S432>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e5;/* '<S433>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e2;/* '<S434>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_i;/* '<S435>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h1;/* '<S436>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_c;/* '<S437>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_j;/* '<S438>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_h;/* '<S439>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_p;/* '<S440>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_ma;/* '<S441>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_b;/* '<S442>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_o;/* '<S443>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_mb;/* '<S444>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_m;/* '<S445>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_l;/* '<S446>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine_e;/* '<S447>/IRQRequestStateMachine' */
  P_IRQRequestStateMachine_BEML_EMU_T sf_IRQRequestStateMachine;/* '<S448>/IRQRequestStateMachine' */
};

/* Parameters for system: '<S660>/Subsystem1' */
struct P_CoreSubsys_BEML_EMU_gmy0_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S674>/Constant'
                                        */
};

/* Parameters for system: '<S401>/InhibitsAndInternalRequests' */
struct P_CoreSubsys_BEML_EMU_gmy_T_ {
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S670>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S671>/Constant'
                                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S668>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S669>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S672>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S673>/Constant'
                                      */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S661>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S662>/Constant'
                                        */
  P_CoreSubsys_BEML_EMU_gmy0_T CoreSubsys;/* '<S660>/Subsystem1' */
};

/* Parameters for system: '<S686>/VehicleEquipment' */
struct P_VehicleEquipment_BEML_EMU_T_ {
  BD_TractionSystem_Cfg_Vehicle Constant6_Value;/* Computed Parameter: Constant6_Value
                                                 * Referenced by: '<S719>/Constant6'
                                                 */
};

/* Parameters for system: '<S685>/VehicleEquipment' */
struct P_VehicleEquipment_BEML_EMU_b_T_ {
  BD_PneumaticsSystem_Cfg_Vehicle Constant6_Value;/* Computed Parameter: Constant6_Value
                                                   * Referenced by: '<S715>/Constant6'
                                                   */
};

/* Parameters for system: '<S684>/VehicleEquipment' */
struct P_VehicleEquipment_BEML_EMU_e_T_ {
  BD_PantographSystem_Cfg_Vehicle Constant6_Value;/* Computed Parameter: Constant6_Value
                                                   * Referenced by: '<S711>/Constant6'
                                                   */
};

/* Parameters for system: '<S683>/VehicleEquipment' */
struct P_VehicleEquipment_BEML_EMU_n_T_ {
  BD_SimIntegration_Cfg_Vehicle_Equipment Constant6_Value;/* Computed Parameter: Constant6_Value
                                                           * Referenced by: '<S707>/Constant6'
                                                           */
};

/* Parameters for system: '<S681>/VehicleEquipment4' */
struct P_VehicleEquipment4_BEML_EMU_T_ {
  BD_DoorSystem_Cfg_Door Constant6_Value;/* Computed Parameter: Constant6_Value
                                          * Referenced by: '<S693>/Constant6'
                                          */
};

/* Parameters for system: '<S675>/VehicleConfigInterface' */
struct P_CoreSubsys_BEML_EMU_gmy0o_T_ {
  real_T VehicleEquipment_ElectricPoweredPanto;
                        /* Mask Parameter: VehicleEquipment_ElectricPoweredPanto
                         * Referenced by: '<S684>/VehicleEquipment'
                         */
  real_T VehicleEquipment1_ElectricPoweredPanto;
                       /* Mask Parameter: VehicleEquipment1_ElectricPoweredPanto
                        * Referenced by: '<S684>/VehicleEquipment1'
                        */
  real_T VehicleEquipment3_ElectricPoweredPanto;
                       /* Mask Parameter: VehicleEquipment3_ElectricPoweredPanto
                        * Referenced by: '<S684>/VehicleEquipment3'
                        */
  real_T VehicleEquipment2_ElectricPoweredPanto;
                       /* Mask Parameter: VehicleEquipment2_ElectricPoweredPanto
                        * Referenced by: '<S684>/VehicleEquipment2'
                        */
  real_T VehicleEquipment_HasBogie; /* Mask Parameter: VehicleEquipment_HasBogie
                                     * Referenced by: '<S683>/VehicleEquipment'
                                     */
  real_T VehicleEquipment1_HasBogie;
                                   /* Mask Parameter: VehicleEquipment1_HasBogie
                                    * Referenced by: '<S683>/VehicleEquipment1'
                                    */
  real_T VehicleEquipment2_HasBogie;
                                   /* Mask Parameter: VehicleEquipment2_HasBogie
                                    * Referenced by: '<S683>/VehicleEquipment2'
                                    */
  real_T VehicleEquipment3_HasBogie;
                                   /* Mask Parameter: VehicleEquipment3_HasBogie
                                    * Referenced by: '<S683>/VehicleEquipment3'
                                    */
  real_T VehicleEquipment_HasBogie_m;
                                  /* Mask Parameter: VehicleEquipment_HasBogie_m
                                   * Referenced by: '<S685>/VehicleEquipment'
                                   */
  real_T VehicleEquipment1_HasBogie_d;
                                 /* Mask Parameter: VehicleEquipment1_HasBogie_d
                                  * Referenced by: '<S685>/VehicleEquipment1'
                                  */
  real_T VehicleEquipment2_HasBogie_k;
                                 /* Mask Parameter: VehicleEquipment2_HasBogie_k
                                  * Referenced by: '<S685>/VehicleEquipment2'
                                  */
  real_T VehicleEquipment3_HasBogie_l;
                                 /* Mask Parameter: VehicleEquipment3_HasBogie_l
                                  * Referenced by: '<S685>/VehicleEquipment3'
                                  */
  real_T VehicleEquipment_HasBrakeSystem;
                              /* Mask Parameter: VehicleEquipment_HasBrakeSystem
                               * Referenced by: '<S683>/VehicleEquipment'
                               */
  real_T VehicleEquipment1_HasBrakeSystem;
                             /* Mask Parameter: VehicleEquipment1_HasBrakeSystem
                              * Referenced by: '<S683>/VehicleEquipment1'
                              */
  real_T VehicleEquipment2_HasBrakeSystem;
                             /* Mask Parameter: VehicleEquipment2_HasBrakeSystem
                              * Referenced by: '<S683>/VehicleEquipment2'
                              */
  real_T VehicleEquipment3_HasBrakeSystem;
                             /* Mask Parameter: VehicleEquipment3_HasBrakeSystem
                              * Referenced by: '<S683>/VehicleEquipment3'
                              */
  real_T VehicleEquipment_HasBrakeSystem_e;
                            /* Mask Parameter: VehicleEquipment_HasBrakeSystem_e
                             * Referenced by: '<S685>/VehicleEquipment'
                             */
  real_T VehicleEquipment1_HasBrakeSystem_o;
                           /* Mask Parameter: VehicleEquipment1_HasBrakeSystem_o
                            * Referenced by: '<S685>/VehicleEquipment1'
                            */
  real_T VehicleEquipment2_HasBrakeSystem_j;
                           /* Mask Parameter: VehicleEquipment2_HasBrakeSystem_j
                            * Referenced by: '<S685>/VehicleEquipment2'
                            */
  real_T VehicleEquipment3_HasBrakeSystem_n;
                           /* Mask Parameter: VehicleEquipment3_HasBrakeSystem_n
                            * Referenced by: '<S685>/VehicleEquipment3'
                            */
  real_T VehicleEquipment_HasCab;     /* Mask Parameter: VehicleEquipment_HasCab
                                       * Referenced by: '<S694>/HasCab'
                                       */
  real_T VehicleEquipment1_HasCab;   /* Mask Parameter: VehicleEquipment1_HasCab
                                      * Referenced by: '<S695>/HasCab'
                                      */
  real_T VehicleEquipment3_HasCab;   /* Mask Parameter: VehicleEquipment3_HasCab
                                      * Referenced by: '<S697>/HasCab'
                                      */
  real_T VehicleEquipment2_HasCab;   /* Mask Parameter: VehicleEquipment2_HasCab
                                      * Referenced by: '<S696>/HasCab'
                                      */
  real_T VehicleEquipment_HasCab_p; /* Mask Parameter: VehicleEquipment_HasCab_p
                                     * Referenced by: '<S683>/VehicleEquipment'
                                     */
  real_T VehicleEquipment1_HasCab_c;
                                   /* Mask Parameter: VehicleEquipment1_HasCab_c
                                    * Referenced by: '<S683>/VehicleEquipment1'
                                    */
  real_T VehicleEquipment2_HasCab_g;
                                   /* Mask Parameter: VehicleEquipment2_HasCab_g
                                    * Referenced by: '<S683>/VehicleEquipment2'
                                    */
  real_T VehicleEquipment3_HasCab_l;
                                   /* Mask Parameter: VehicleEquipment3_HasCab_l
                                    * Referenced by: '<S683>/VehicleEquipment3'
                                    */
  real_T VehicleEquipment_HasCab_d; /* Mask Parameter: VehicleEquipment_HasCab_d
                                     * Referenced by: '<S685>/VehicleEquipment'
                                     */
  real_T VehicleEquipment1_HasCab_l;
                                   /* Mask Parameter: VehicleEquipment1_HasCab_l
                                    * Referenced by: '<S685>/VehicleEquipment1'
                                    */
  real_T VehicleEquipment2_HasCab_b;
                                   /* Mask Parameter: VehicleEquipment2_HasCab_b
                                    * Referenced by: '<S685>/VehicleEquipment2'
                                    */
  real_T VehicleEquipment3_HasCab_c;
                                   /* Mask Parameter: VehicleEquipment3_HasCab_c
                                    * Referenced by: '<S685>/VehicleEquipment3'
                                    */
  real_T VehicleEquipment_HasCompressor;
                               /* Mask Parameter: VehicleEquipment_HasCompressor
                                * Referenced by: '<S685>/VehicleEquipment'
                                */
  real_T VehicleEquipment1_HasCompressor;
                              /* Mask Parameter: VehicleEquipment1_HasCompressor
                               * Referenced by: '<S685>/VehicleEquipment1'
                               */
  real_T VehicleEquipment2_HasCompressor;
                              /* Mask Parameter: VehicleEquipment2_HasCompressor
                               * Referenced by: '<S685>/VehicleEquipment2'
                               */
  real_T VehicleEquipment3_HasCompressor;
                              /* Mask Parameter: VehicleEquipment3_HasCompressor
                               * Referenced by: '<S685>/VehicleEquipment3'
                               */
  real_T VehicleEquipment_HasElectricPanto;
                            /* Mask Parameter: VehicleEquipment_HasElectricPanto
                             * Referenced by: '<S683>/VehicleEquipment'
                             */
  real_T VehicleEquipment1_HasElectricPanto;
                           /* Mask Parameter: VehicleEquipment1_HasElectricPanto
                            * Referenced by: '<S683>/VehicleEquipment1'
                            */
  real_T VehicleEquipment2_HasElectricPanto;
                           /* Mask Parameter: VehicleEquipment2_HasElectricPanto
                            * Referenced by: '<S683>/VehicleEquipment2'
                            */
  real_T VehicleEquipment3_HasElectricPanto;
                           /* Mask Parameter: VehicleEquipment3_HasElectricPanto
                            * Referenced by: '<S683>/VehicleEquipment3'
                            */
  real_T VehicleEquipment_HasMainCompressor;
                           /* Mask Parameter: VehicleEquipment_HasMainCompressor
                            * Referenced by: '<S694>/HasSimpleCab'
                            */
  real_T VehicleEquipment1_HasMainCompressor;
                          /* Mask Parameter: VehicleEquipment1_HasMainCompressor
                           * Referenced by: '<S695>/HasSimpleCab'
                           */
  real_T VehicleEquipment3_HasMainCompressor;
                          /* Mask Parameter: VehicleEquipment3_HasMainCompressor
                           * Referenced by: '<S697>/HasSimpleCab'
                           */
  real_T VehicleEquipment2_HasMainCompressor;
                          /* Mask Parameter: VehicleEquipment2_HasMainCompressor
                           * Referenced by: '<S696>/HasSimpleCab'
                           */
  real_T VehicleEquipment_HasMainCompressor_g;
                         /* Mask Parameter: VehicleEquipment_HasMainCompressor_g
                          * Referenced by: '<S683>/VehicleEquipment'
                          */
  real_T VehicleEquipment1_HasMainCompressor_n;
                        /* Mask Parameter: VehicleEquipment1_HasMainCompressor_n
                         * Referenced by: '<S683>/VehicleEquipment1'
                         */
  real_T VehicleEquipment2_HasMainCompressor_h;
                        /* Mask Parameter: VehicleEquipment2_HasMainCompressor_h
                         * Referenced by: '<S683>/VehicleEquipment2'
                         */
  real_T VehicleEquipment3_HasMainCompressor_e;
                        /* Mask Parameter: VehicleEquipment3_HasMainCompressor_e
                         * Referenced by: '<S683>/VehicleEquipment3'
                         */
  real_T VehicleEquipment_HasMainReservoir;
                            /* Mask Parameter: VehicleEquipment_HasMainReservoir
                             * Referenced by: '<S683>/VehicleEquipment'
                             */
  real_T VehicleEquipment1_HasMainReservoir;
                           /* Mask Parameter: VehicleEquipment1_HasMainReservoir
                            * Referenced by: '<S683>/VehicleEquipment1'
                            */
  real_T VehicleEquipment2_HasMainReservoir;
                           /* Mask Parameter: VehicleEquipment2_HasMainReservoir
                            * Referenced by: '<S683>/VehicleEquipment2'
                            */
  real_T VehicleEquipment3_HasMainReservoir;
                           /* Mask Parameter: VehicleEquipment3_HasMainReservoir
                            * Referenced by: '<S683>/VehicleEquipment3'
                            */
  real_T VehicleEquipment_HasMainReservoir_d;
                          /* Mask Parameter: VehicleEquipment_HasMainReservoir_d
                           * Referenced by: '<S685>/VehicleEquipment'
                           */
  real_T VehicleEquipment1_HasMainReservoir_c;
                         /* Mask Parameter: VehicleEquipment1_HasMainReservoir_c
                          * Referenced by: '<S685>/VehicleEquipment1'
                          */
  real_T VehicleEquipment2_HasMainReservoir_m;
                         /* Mask Parameter: VehicleEquipment2_HasMainReservoir_m
                          * Referenced by: '<S685>/VehicleEquipment2'
                          */
  real_T VehicleEquipment3_HasMainReservoir_f;
                         /* Mask Parameter: VehicleEquipment3_HasMainReservoir_f
                          * Referenced by: '<S685>/VehicleEquipment3'
                          */
  real_T VehicleEquipment_HasMotors;
                                   /* Mask Parameter: VehicleEquipment_HasMotors
                                    * Referenced by: '<S694>/HasMotors'
                                    */
  real_T VehicleEquipment1_HasMotors;
                                  /* Mask Parameter: VehicleEquipment1_HasMotors
                                   * Referenced by: '<S695>/HasMotors'
                                   */
  real_T VehicleEquipment3_HasMotors;
                                  /* Mask Parameter: VehicleEquipment3_HasMotors
                                   * Referenced by: '<S697>/HasMotors'
                                   */
  real_T VehicleEquipment2_HasMotors;
                                  /* Mask Parameter: VehicleEquipment2_HasMotors
                                   * Referenced by: '<S696>/HasMotors'
                                   */
  real_T VehicleEquipment_HasMotors_n;
                                 /* Mask Parameter: VehicleEquipment_HasMotors_n
                                  * Referenced by: '<S683>/VehicleEquipment'
                                  */
  real_T VehicleEquipment1_HasMotors_i;
                                /* Mask Parameter: VehicleEquipment1_HasMotors_i
                                 * Referenced by: '<S683>/VehicleEquipment1'
                                 */
  real_T VehicleEquipment2_HasMotors_o;
                                /* Mask Parameter: VehicleEquipment2_HasMotors_o
                                 * Referenced by: '<S683>/VehicleEquipment2'
                                 */
  real_T VehicleEquipment3_HasMotors_n;
                                /* Mask Parameter: VehicleEquipment3_HasMotors_n
                                 * Referenced by: '<S683>/VehicleEquipment3'
                                 */
  real_T VehicleEquipment_HasMotors_j;
                                 /* Mask Parameter: VehicleEquipment_HasMotors_j
                                  * Referenced by: '<S686>/VehicleEquipment'
                                  */
  real_T VehicleEquipment1_HasMotors_a;
                                /* Mask Parameter: VehicleEquipment1_HasMotors_a
                                 * Referenced by: '<S686>/VehicleEquipment1'
                                 */
  real_T VehicleEquipment2_HasMotors_d;
                                /* Mask Parameter: VehicleEquipment2_HasMotors_d
                                 * Referenced by: '<S686>/VehicleEquipment2'
                                 */
  real_T VehicleEquipment3_HasMotors_k;
                                /* Mask Parameter: VehicleEquipment3_HasMotors_k
                                 * Referenced by: '<S686>/VehicleEquipment3'
                                 */
  real_T VehicleEquipment_HasPanto; /* Mask Parameter: VehicleEquipment_HasPanto
                                     * Referenced by: '<S684>/VehicleEquipment'
                                     */
  real_T VehicleEquipment1_HasPanto;
                                   /* Mask Parameter: VehicleEquipment1_HasPanto
                                    * Referenced by: '<S684>/VehicleEquipment1'
                                    */
  real_T VehicleEquipment3_HasPanto;
                                   /* Mask Parameter: VehicleEquipment3_HasPanto
                                    * Referenced by: '<S684>/VehicleEquipment3'
                                    */
  real_T VehicleEquipment2_HasPanto;
                                   /* Mask Parameter: VehicleEquipment2_HasPanto
                                    * Referenced by: '<S684>/VehicleEquipment2'
                                    */
  real_T VehicleEquipment_HasPantoReservoir;
                           /* Mask Parameter: VehicleEquipment_HasPantoReservoir
                            * Referenced by: '<S694>/HasPantoReservoir'
                            */
  real_T VehicleEquipment1_HasPantoReservoir;
                          /* Mask Parameter: VehicleEquipment1_HasPantoReservoir
                           * Referenced by: '<S695>/HasPantoReservoir'
                           */
  real_T VehicleEquipment3_HasPantoReservoir;
                          /* Mask Parameter: VehicleEquipment3_HasPantoReservoir
                           * Referenced by: '<S697>/HasPantoReservoir'
                           */
  real_T VehicleEquipment2_HasPantoReservoir;
                          /* Mask Parameter: VehicleEquipment2_HasPantoReservoir
                           * Referenced by: '<S696>/HasPantoReservoir'
                           */
  real_T VehicleEquipment_HasPantoReservoir_l;
                         /* Mask Parameter: VehicleEquipment_HasPantoReservoir_l
                          * Referenced by: '<S683>/VehicleEquipment'
                          */
  real_T VehicleEquipment1_HasPantoReservoir_d;
                        /* Mask Parameter: VehicleEquipment1_HasPantoReservoir_d
                         * Referenced by: '<S683>/VehicleEquipment1'
                         */
  real_T VehicleEquipment2_HasPantoReservoir_d;
                        /* Mask Parameter: VehicleEquipment2_HasPantoReservoir_d
                         * Referenced by: '<S683>/VehicleEquipment2'
                         */
  real_T VehicleEquipment3_HasPantoReservoir_p;
                        /* Mask Parameter: VehicleEquipment3_HasPantoReservoir_p
                         * Referenced by: '<S683>/VehicleEquipment3'
                         */
  real_T VehicleEquipment_HasPantograph;
                               /* Mask Parameter: VehicleEquipment_HasPantograph
                                * Referenced by: '<S694>/HasPantograph'
                                */
  real_T VehicleEquipment1_HasPantograph;
                              /* Mask Parameter: VehicleEquipment1_HasPantograph
                               * Referenced by: '<S695>/HasPantograph'
                               */
  real_T VehicleEquipment3_HasPantograph;
                              /* Mask Parameter: VehicleEquipment3_HasPantograph
                               * Referenced by: '<S697>/HasPantograph'
                               */
  real_T VehicleEquipment2_HasPantograph;
                              /* Mask Parameter: VehicleEquipment2_HasPantograph
                               * Referenced by: '<S696>/HasPantograph'
                               */
  real_T VehicleEquipment_HasPantograph_e;
                             /* Mask Parameter: VehicleEquipment_HasPantograph_e
                              * Referenced by: '<S685>/VehicleEquipment'
                              */
  real_T VehicleEquipment1_HasPantograph_a;
                            /* Mask Parameter: VehicleEquipment1_HasPantograph_a
                             * Referenced by: '<S685>/VehicleEquipment1'
                             */
  real_T VehicleEquipment2_HasPantograph_p;
                            /* Mask Parameter: VehicleEquipment2_HasPantograph_p
                             * Referenced by: '<S685>/VehicleEquipment2'
                             */
  real_T VehicleEquipment3_HasPantograph_n;
                            /* Mask Parameter: VehicleEquipment3_HasPantograph_n
                             * Referenced by: '<S685>/VehicleEquipment3'
                             */
  real_T VehicleEquipment_HasPneumaticPanto;
                           /* Mask Parameter: VehicleEquipment_HasPneumaticPanto
                            * Referenced by: '<S683>/VehicleEquipment'
                            */
  real_T VehicleEquipment1_HasPneumaticPanto;
                          /* Mask Parameter: VehicleEquipment1_HasPneumaticPanto
                           * Referenced by: '<S683>/VehicleEquipment1'
                           */
  real_T VehicleEquipment2_HasPneumaticPanto;
                          /* Mask Parameter: VehicleEquipment2_HasPneumaticPanto
                           * Referenced by: '<S683>/VehicleEquipment2'
                           */
  real_T VehicleEquipment3_HasPneumaticPanto;
                          /* Mask Parameter: VehicleEquipment3_HasPneumaticPanto
                           * Referenced by: '<S683>/VehicleEquipment3'
                           */
  real_T VehicleEquipment4_IsLeft;   /* Mask Parameter: VehicleEquipment4_IsLeft
                                      * Referenced by: '<S681>/VehicleEquipment4'
                                      */
  real_T VehicleEquipment1_IsLeft;   /* Mask Parameter: VehicleEquipment1_IsLeft
                                      * Referenced by: '<S681>/VehicleEquipment1'
                                      */
  real_T VehicleEquipment2_IsLeft;   /* Mask Parameter: VehicleEquipment2_IsLeft
                                      * Referenced by: '<S681>/VehicleEquipment2'
                                      */
  real_T VehicleEquipment3_IsLeft;   /* Mask Parameter: VehicleEquipment3_IsLeft
                                      * Referenced by: '<S681>/VehicleEquipment3'
                                      */
  real_T VehicleEquipment_NumberOfBrakingBogies;
                       /* Mask Parameter: VehicleEquipment_NumberOfBrakingBogies
                        * Referenced by: '<S683>/VehicleEquipment'
                        */
  real_T VehicleEquipment1_NumberOfBrakingBogies;
                      /* Mask Parameter: VehicleEquipment1_NumberOfBrakingBogies
                       * Referenced by: '<S683>/VehicleEquipment1'
                       */
  real_T VehicleEquipment2_NumberOfBrakingBogies;
                      /* Mask Parameter: VehicleEquipment2_NumberOfBrakingBogies
                       * Referenced by: '<S683>/VehicleEquipment2'
                       */
  real_T VehicleEquipment3_NumberOfBrakingBogies;
                      /* Mask Parameter: VehicleEquipment3_NumberOfBrakingBogies
                       * Referenced by: '<S683>/VehicleEquipment3'
                       */
  real_T VehicleEquipment4_NumberOfDoors;
                              /* Mask Parameter: VehicleEquipment4_NumberOfDoors
                               * Referenced by: '<S681>/VehicleEquipment4'
                               */
  real_T VehicleEquipment1_NumberOfDoors;
                              /* Mask Parameter: VehicleEquipment1_NumberOfDoors
                               * Referenced by: '<S681>/VehicleEquipment1'
                               */
  real_T VehicleEquipment2_NumberOfDoors;
                              /* Mask Parameter: VehicleEquipment2_NumberOfDoors
                               * Referenced by: '<S681>/VehicleEquipment2'
                               */
  real_T VehicleEquipment3_NumberOfDoors;
                              /* Mask Parameter: VehicleEquipment3_NumberOfDoors
                               * Referenced by: '<S681>/VehicleEquipment3'
                               */
  real_T VehicleEquipment_NumberOfDoors;
                               /* Mask Parameter: VehicleEquipment_NumberOfDoors
                                * Referenced by: '<S683>/VehicleEquipment'
                                */
  real_T VehicleEquipment1_NumberOfDoors_g;
                            /* Mask Parameter: VehicleEquipment1_NumberOfDoors_g
                             * Referenced by: '<S683>/VehicleEquipment1'
                             */
  real_T VehicleEquipment2_NumberOfDoors_i;
                            /* Mask Parameter: VehicleEquipment2_NumberOfDoors_i
                             * Referenced by: '<S683>/VehicleEquipment2'
                             */
  real_T VehicleEquipment3_NumberOfDoors_i;
                            /* Mask Parameter: VehicleEquipment3_NumberOfDoors_i
                             * Referenced by: '<S683>/VehicleEquipment3'
                             */
  real_T VehicleEquipment_NumberOfTractionBogies;
                      /* Mask Parameter: VehicleEquipment_NumberOfTractionBogies
                       * Referenced by: '<S683>/VehicleEquipment'
                       */
  real_T VehicleEquipment1_NumberOfTractionBogies;
                     /* Mask Parameter: VehicleEquipment1_NumberOfTractionBogies
                      * Referenced by: '<S683>/VehicleEquipment1'
                      */
  real_T VehicleEquipment2_NumberOfTractionBogies;
                     /* Mask Parameter: VehicleEquipment2_NumberOfTractionBogies
                      * Referenced by: '<S683>/VehicleEquipment2'
                      */
  real_T VehicleEquipment3_NumberOfTractionBogies;
                     /* Mask Parameter: VehicleEquipment3_NumberOfTractionBogies
                      * Referenced by: '<S683>/VehicleEquipment3'
                      */
  real_T VehicleEquipment_PenumaticsPoweredPanto;
                      /* Mask Parameter: VehicleEquipment_PenumaticsPoweredPanto
                       * Referenced by: '<S684>/VehicleEquipment'
                       */
  real_T VehicleEquipment1_PenumaticsPoweredPanto;
                     /* Mask Parameter: VehicleEquipment1_PenumaticsPoweredPanto
                      * Referenced by: '<S684>/VehicleEquipment1'
                      */
  real_T VehicleEquipment3_PenumaticsPoweredPanto;
                     /* Mask Parameter: VehicleEquipment3_PenumaticsPoweredPanto
                      * Referenced by: '<S684>/VehicleEquipment3'
                      */
  real_T VehicleEquipment2_PenumaticsPoweredPanto;
                     /* Mask Parameter: VehicleEquipment2_PenumaticsPoweredPanto
                      * Referenced by: '<S684>/VehicleEquipment2'
                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S726>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S729>/Constant'
                                      */
  real_T CompareToConstant9_const;   /* Mask Parameter: CompareToConstant9_const
                                      * Referenced by: '<S731>/Constant'
                                      */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S725>/Constant'
                                       */
  int32_T CompareToConstant4_const;  /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S728>/Constant'
                                      */
  int32_T CompareToConstant2_const;  /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S727>/Constant'
                                      */
  int32_T CompareToConstant8_const;  /* Mask Parameter: CompareToConstant8_const
                                      * Referenced by: '<S730>/Constant'
                                      */
  BD_SimIntegration_Cfg_Vehicle Constant1_Value;/* Computed Parameter: Constant1_Value
                                                 * Referenced by: '<S677>/Constant1'
                                                 */
  BD_TrainDynamics_Cfg_Vehicle_DavisCoefficients Constant_Value;/* Computed Parameter: Constant_Value
                                                                 * Referenced by: '<S688>/Constant'
                                                                 */
  BD_TrainBrakes_Cfg_Vehicle Constant6_Value;/* Computed Parameter: Constant6_Value
                                              * Referenced by: '<S680>/Constant6'
                                              */
  BD_ElectricalSystem_Cfg_Vehicle Constant6_Value_e;/* Computed Parameter: Constant6_Value_e
                                                     * Referenced by: '<S694>/Constant6'
                                                     */
  BD_ElectricalSystem_Cfg_Vehicle Constant6_Value_l;/* Computed Parameter: Constant6_Value_l
                                                     * Referenced by: '<S695>/Constant6'
                                                     */
  BD_ElectricalSystem_Cfg_Vehicle Constant6_Value_i;/* Computed Parameter: Constant6_Value_i
                                                     * Referenced by: '<S697>/Constant6'
                                                     */
  BD_ElectricalSystem_Cfg_Vehicle Constant6_Value_j;/* Computed Parameter: Constant6_Value_j
                                                     * Referenced by: '<S696>/Constant6'
                                                     */
  BD_SimIntegration_Cfg_Vehicle_Location Constant1_Value_g;/* Computed Parameter: Constant1_Value_g
                                                            * Referenced by: '<S689>/Constant1'
                                                            */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S723>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0.29
                                        * Referenced by: '<S680>/Constant1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 4
                                        * Referenced by: '<S687>/Constant1'
                                        */
  real_T Constant1_Value_l;            /* Expression: 2
                                        * Referenced by: '<S723>/Constant1'
                                        */
  real_T Constant12_Value;             /* Expression: 20e3
                                        * Referenced by: '<S688>/Constant12'
                                        */
  real_T Constant9_Value;              /* Expression: 8.34e-3
                                        * Referenced by: '<S688>/Constant9'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S688>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: 0.044e-3
                                        * Referenced by: '<S688>/Constant5'
                                        */
  real_T Constant1_Value_c;            /* Expression: 12.38
                                        * Referenced by: '<S688>/Constant1'
                                        */
  real_T Constant6_Value_c;            /* Expression: 5.18*0.8
                                        * Referenced by: '<S688>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 5.18*0.2/7
                                        * Referenced by: '<S688>/Constant7'
                                        */
  DragCalculationMethod UseDavisCoeff_Value;
                                      /* Expression: DragCalculationMethod.Davis
                                       * Referenced by: '<S688>/UseDavisCoeff'
                                       */
  boolean_T Constant_Value_e;          /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S698>/Constant'
                                        */
  boolean_T Constant_Value_o;          /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S700>/Constant'
                                        */
  boolean_T Constant_Value_eu;         /* Computed Parameter: Constant_Value_eu
                                        * Referenced by: '<S699>/Constant'
                                        */
  boolean_T Constant_Value_c;          /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S701>/Constant'
                                        */
  boolean_T Constant_Value_d;          /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S702>/Constant'
                                        */
  boolean_T Constant_Value_oq;         /* Computed Parameter: Constant_Value_oq
                                        * Referenced by: '<S703>/Constant'
                                        */
  boolean_T Constant_Value_l;          /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S704>/Constant'
                                        */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S705>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S706>/Constant'
                                        */
  boolean_T Constant8_Value;           /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S688>/Constant8'
                                        */
  P_VehicleEquipment4_BEML_EMU_T VehicleEquipment3_o;/* '<S681>/VehicleEquipment3' */
  P_VehicleEquipment4_BEML_EMU_T VehicleEquipment2_f;/* '<S681>/VehicleEquipment2' */
  P_VehicleEquipment4_BEML_EMU_T VehicleEquipment1_n;/* '<S681>/VehicleEquipment1' */
  P_VehicleEquipment4_BEML_EMU_T VehicleEquipment4;/* '<S681>/VehicleEquipment4' */
  P_VehicleEquipment_BEML_EMU_n_T VehicleEquipment3_ly;/* '<S683>/VehicleEquipment3' */
  P_VehicleEquipment_BEML_EMU_n_T VehicleEquipment2_m;/* '<S683>/VehicleEquipment2' */
  P_VehicleEquipment_BEML_EMU_n_T VehicleEquipment1_m;/* '<S683>/VehicleEquipment1' */
  P_VehicleEquipment_BEML_EMU_n_T VehicleEquipment_o;/* '<S683>/VehicleEquipment' */
  P_VehicleEquipment_BEML_EMU_e_T VehicleEquipment2_h;/* '<S684>/VehicleEquipment2' */
  P_VehicleEquipment_BEML_EMU_e_T VehicleEquipment3_l;/* '<S684>/VehicleEquipment3' */
  P_VehicleEquipment_BEML_EMU_e_T VehicleEquipment1_a;/* '<S684>/VehicleEquipment1' */
  P_VehicleEquipment_BEML_EMU_e_T VehicleEquipment_g;/* '<S684>/VehicleEquipment' */
  P_VehicleEquipment_BEML_EMU_b_T VehicleEquipment3_f;/* '<S685>/VehicleEquipment3' */
  P_VehicleEquipment_BEML_EMU_b_T VehicleEquipment2_n;/* '<S685>/VehicleEquipment2' */
  P_VehicleEquipment_BEML_EMU_b_T VehicleEquipment1_c;/* '<S685>/VehicleEquipment1' */
  P_VehicleEquipment_BEML_EMU_b_T VehicleEquipment_c;/* '<S685>/VehicleEquipment' */
  P_VehicleEquipment_BEML_EMU_T VehicleEquipment3;/* '<S686>/VehicleEquipment3' */
  P_VehicleEquipment_BEML_EMU_T VehicleEquipment2;/* '<S686>/VehicleEquipment2' */
  P_VehicleEquipment_BEML_EMU_T VehicleEquipment1;/* '<S686>/VehicleEquipment1' */
  P_VehicleEquipment_BEML_EMU_T VehicleEquipment;/* '<S686>/VehicleEquipment' */
};

/* Parameters for system: '<S734>/Subsystem1' */
struct P_CoreSubsys_BEML_EMU_gmy0ogcc_T_ {
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S744>/Constant'
                                      */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S739>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S745>/Delay Input1'
                                        */
  BD_SimIntegration_Out_Vehicle_Audio Constant_Value;/* Computed Parameter: Constant_Value
                                                      * Referenced by: '<S738>/Constant'
                                                      */
  real_T Relay_OnVal;                  /* Expression: 3.0e5
                                        * Referenced by: '<S738>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: 2.0e5
                                        * Referenced by: '<S738>/Relay'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S738>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 0
                                        * Referenced by: '<S738>/Relay'
                                        */
};

/* Parameters for system: '<S750>/Subsystem' */
struct P_CoreSubsys_BEML_EMU_gmy0ogccz5ddgv_T_ {
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S751>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S751>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S751>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S751>/Discrete-Time Integrator1'
                                        */
};

/* Parameters for system: '<S746>/For Each Subsystem' */
struct P_CoreSubsys_BEML_EMU_gmy0ogccz5ddg_T_ {
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddgv_T CoreSubsys;/* '<S750>/Subsystem' */
};

/* Parameters for system: '<S736>/VehicleLevelScoring' */
struct P_CoreSubsys_BEML_EMU_jb_T_ {
  BD_SimIntegration_Out_Vehicle_Scoring Constant1_Value;/* Computed Parameter: Constant1_Value
                                                         * Referenced by: '<S747>/Constant1'
                                                         */
};

/* Parameters for system: '<S737>/Input Adapter' */
struct P_CoreSubsys_BEML_EMU_gx_T_ {
  real_T BinarySwitch_value;           /* Mask Parameter: BinarySwitch_value
                                        * Referenced by: '<S756>/InputValue'
                                        */
  BD_MotionBase_In_Vehicle Constant6_Value;/* Computed Parameter: Constant6_Value
                                            * Referenced by: '<S754>/Constant6'
                                            */
  BD_MotionBase_In_Vehicle_Dynamics Constant7_Value;/* Computed Parameter: Constant7_Value
                                                     * Referenced by: '<S760>/Constant7'
                                                     */
  BD_MotionBase_In_Vehicle_Dynamics_Transform Constant8_Value;/* Computed Parameter: Constant8_Value
                                                               * Referenced by: '<S762>/Constant8'
                                                               */
  BD_MotionBase_In_Vehicle_Effects Constant_Value;/* Computed Parameter: Constant_Value
                                                   * Referenced by: '<S757>/Constant'
                                                   */
  BD_MotionBase_In_Vehicle_Environment Constant10_Value;/* Computed Parameter: Constant10_Value
                                                         * Referenced by: '<S758>/Constant10'
                                                         */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S752>/Constant1'
                                        */
  real_T LateralVelocity_Value;        /* Expression: 0
                                        * Referenced by: '<S760>/Lateral Velocity'
                                        */
  real_T VerticalVelocity_Value;       /* Expression: 0
                                        * Referenced by: '<S760>/Vertical Velocity'
                                        */
  real_T VerticalAcceleration_Value;   /* Expression: 0
                                        * Referenced by: '<S760>/Vertical Acceleration'
                                        */
  real_T Constant2_Value[3];           /* Expression: [0, 0, 0]
                                        * Referenced by: '<S760>/Constant2'
                                        */
  real_T Constant3_Value[3];           /* Expression: [0, 0, 0]
                                        * Referenced by: '<S760>/Constant3'
                                        */
  real_T Gain3_Gain[9];                /* Expression: [0 0 1; 0 0 0; -1 0 0]
                                        * Referenced by: '<S766>/Gain3'
                                        */
  real_T Gain1_Gain[9];                /* Expression: [1 0 0; 0 0 0; 0 0 1]
                                        * Referenced by: '<S766>/Gain1'
                                        */
  real_T Constant1_Value_p[9];         /* Expression: [0 0 0; 0 1 0; 0 0 0]
                                        * Referenced by: '<S766>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S760>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S760>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain[9];                 /* Expression: [0 -1 0; 1 0 0; 0 0 0]
                                        * Referenced by: '<S765>/Gain'
                                        */
  real_T Gain2_Gain[9];                /* Expression: [1 0 0; 0 1 0; 0 0 0]
                                        * Referenced by: '<S765>/Gain2'
                                        */
  real_T Constant_Value_c[9];          /* Expression: [0 0 0; 0 0 0; 0 0 1]
                                        * Referenced by: '<S765>/Constant'
                                        */
  real_T Roll_Value;                   /* Expression: 0
                                        * Referenced by: '<S762>/Roll'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S758>/Constant5'
                                        */
  real_T Constant5_Value_h;            /* Expression: 0
                                        * Referenced by: '<S759>/Constant5'
                                        */
};

/* Parameters for system: '<S782>/Jolt Duration' */
struct P_JoltDuration_BEML_EMU_T_ {
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S793>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S794>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S793>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S793>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S793>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S793>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S793>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S793>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S753>/MotionBasePerVehicle' */
struct P_CoreSubsys_BEML_EMU_l3_T_ {
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S825>/Output'
                                     */
  real_T BandLimitedWhiteNoise1_Cov;
                                   /* Mask Parameter: BandLimitedWhiteNoise1_Cov
                                    * Referenced by: '<S826>/Output'
                                    */
  real_T BandLimitedWhiteNoise_Cov_c;
                                  /* Mask Parameter: BandLimitedWhiteNoise_Cov_c
                                   * Referenced by: '<S804>/Output'
                                   */
  real_T BandLimitedWhiteNoise1_Cov_o;
                                 /* Mask Parameter: BandLimitedWhiteNoise1_Cov_o
                                  * Referenced by: '<S805>/Output'
                                  */
  real_T SaturationTuning_DefaultValue;
                                /* Mask Parameter: SaturationTuning_DefaultValue
                                 * Referenced by: '<S866>/Default'
                                 */
  real_T LPFConstantTuning_DefaultValue;
                               /* Mask Parameter: LPFConstantTuning_DefaultValue
                                * Referenced by: '<S864>/Default'
                                */
  real_T SaturationTuning_DefaultValue_n;
                              /* Mask Parameter: SaturationTuning_DefaultValue_n
                               * Referenced by: '<S862>/Default'
                               */
  real_T LPFConstantTuning_DefaultValue_k;
                             /* Mask Parameter: LPFConstantTuning_DefaultValue_k
                              * Referenced by: '<S860>/Default'
                              */
  real_T SaturationTuning_DefaultValue_g;
                              /* Mask Parameter: SaturationTuning_DefaultValue_g
                               * Referenced by: '<S856>/Default'
                               */
  real_T LPFConstantTuning_DefaultValue_l;
                             /* Mask Parameter: LPFConstantTuning_DefaultValue_l
                              * Referenced by: '<S854>/Default'
                              */
  real_T SaturationTuning_DefaultValue_k;
                              /* Mask Parameter: SaturationTuning_DefaultValue_k
                               * Referenced by: '<S852>/Default'
                               */
  real_T LPFConstantTuning_DefaultValue_p;
                             /* Mask Parameter: LPFConstantTuning_DefaultValue_p
                              * Referenced by: '<S850>/Default'
                              */
  real_T SampleandHold_InitialCondition;
                               /* Mask Parameter: SampleandHold_InitialCondition
                                * Referenced by: '<S831>/Unit Delay'
                                */
  real_T SampleandHold_InitialCondition_e;
                             /* Mask Parameter: SampleandHold_InitialCondition_e
                              * Referenced by: '<S810>/Unit Delay'
                              */
  real_T Jolt_JoltBreakPoints[6];      /* Mask Parameter: Jolt_JoltBreakPoints
                                        * Referenced by: '<S779>/Jolt Profile'
                                        */
  real_T Jolt1_JoltBreakPoints[6];     /* Mask Parameter: Jolt1_JoltBreakPoints
                                        * Referenced by: '<S780>/Jolt Profile'
                                        */
  real_T Jolt2_JoltBreakPoints[6];     /* Mask Parameter: Jolt2_JoltBreakPoints
                                        * Referenced by: '<S781>/Jolt Profile'
                                        */
  real_T Jolt3_JoltBreakPoints[6];     /* Mask Parameter: Jolt3_JoltBreakPoints
                                        * Referenced by: '<S782>/Jolt Profile'
                                        */
  real_T Jolt_JoltProfile[6];          /* Mask Parameter: Jolt_JoltProfile
                                        * Referenced by: '<S779>/Jolt Profile'
                                        */
  real_T Jolt1_JoltProfile[6];         /* Mask Parameter: Jolt1_JoltProfile
                                        * Referenced by: '<S780>/Jolt Profile'
                                        */
  real_T Jolt2_JoltProfile[6];         /* Mask Parameter: Jolt2_JoltProfile
                                        * Referenced by: '<S781>/Jolt Profile'
                                        */
  real_T Jolt3_JoltProfile[6];         /* Mask Parameter: Jolt3_JoltProfile
                                        * Referenced by: '<S782>/Jolt Profile'
                                        */
  real_T StandardRoughnessGenerator_SpeedSaturation;
                   /* Mask Parameter: StandardRoughnessGenerator_SpeedSaturation
                    * Referenced by: '<S842>/Default'
                    */
  real_T DegradedRoughnessGenerator_SpeedSaturation;
                   /* Mask Parameter: DegradedRoughnessGenerator_SpeedSaturation
                    * Referenced by: '<S821>/Default'
                    */
  real_T TuningFactor_Threshold;       /* Mask Parameter: TuningFactor_Threshold
                                        * Referenced by: '<S842>/Switch'
                                        */
  real_T TuningFactor_Threshold_c;   /* Mask Parameter: TuningFactor_Threshold_c
                                      * Referenced by: '<S821>/Switch'
                                      */
  real_T SaturationTuning_Threshold;
                                   /* Mask Parameter: SaturationTuning_Threshold
                                    * Referenced by: '<S866>/Switch'
                                    */
  real_T LPFConstantTuning_Threshold;
                                  /* Mask Parameter: LPFConstantTuning_Threshold
                                   * Referenced by: '<S864>/Switch'
                                   */
  real_T SaturationTuning_Threshold_p;
                                 /* Mask Parameter: SaturationTuning_Threshold_p
                                  * Referenced by: '<S862>/Switch'
                                  */
  real_T LPFConstantTuning_Threshold_a;
                                /* Mask Parameter: LPFConstantTuning_Threshold_a
                                 * Referenced by: '<S860>/Switch'
                                 */
  real_T SaturationTuning_Threshold_a;
                                 /* Mask Parameter: SaturationTuning_Threshold_a
                                  * Referenced by: '<S856>/Switch'
                                  */
  real_T LPFConstantTuning_Threshold_d;
                                /* Mask Parameter: LPFConstantTuning_Threshold_d
                                 * Referenced by: '<S854>/Switch'
                                 */
  real_T SaturationTuning_Threshold_k;
                                 /* Mask Parameter: SaturationTuning_Threshold_k
                                  * Referenced by: '<S852>/Switch'
                                  */
  real_T LPFConstantTuning_Threshold_l;
                                /* Mask Parameter: LPFConstantTuning_Threshold_l
                                 * Referenced by: '<S850>/Switch'
                                 */
  real_T Above20Degrees_const;         /* Mask Parameter: Above20Degrees_const
                                        * Referenced by: '<S843>/Constant'
                                        */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S825>/White Noise'
                                    */
  real_T BandLimitedWhiteNoise1_seed;
                                  /* Mask Parameter: BandLimitedWhiteNoise1_seed
                                   * Referenced by: '<S826>/White Noise'
                                   */
  real_T BandLimitedWhiteNoise_seed_f;
                                 /* Mask Parameter: BandLimitedWhiteNoise_seed_f
                                  * Referenced by: '<S804>/White Noise'
                                  */
  real_T BandLimitedWhiteNoise1_seed_l;
                                /* Mask Parameter: BandLimitedWhiteNoise1_seed_l
                                 * Referenced by: '<S805>/White Noise'
                                 */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S834>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit_p;       /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S813>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_ps;  /* Mask Parameter: DetectIncrease_vinit_ps
                                       * Referenced by: '<S783>/Delay Input1'
                                       */
  boolean_T DetectIncrease_vinit_px;  /* Mask Parameter: DetectIncrease_vinit_px
                                       * Referenced by: '<S786>/Delay Input1'
                                       */
  boolean_T DetectIncrease_vinit_o;    /* Mask Parameter: DetectIncrease_vinit_o
                                        * Referenced by: '<S789>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_k;    /* Mask Parameter: DetectIncrease_vinit_k
                                        * Referenced by: '<S792>/Delay Input1'
                                        */
  BD_SimIntegration_Out_Vehicle_MotionBaseController InitMotionBaseOut_Value;
                                  /* Computed Parameter: InitMotionBaseOut_Value
                                   * Referenced by: '<S771>/InitMotionBaseOut'
                                   */
  BD_SimIntegration_Out_Vehicle_MotionBaseController InitMotionBaseOut1_Value;
                                 /* Computed Parameter: InitMotionBaseOut1_Value
                                  * Referenced by: '<S772>/InitMotionBaseOut1'
                                  */
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S857>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S858>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S857>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S857>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S857>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S857>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S857>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S857>/Discrete-Time Integrator'
                                          */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S823>/Constant6'
                                        */
  real_T Constant3_Value;              /* Expression: 0.15
                                        * Referenced by: '<S823>/Constant3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S824>/Switch2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S823>/Gain1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.2
                                        * Referenced by: '<S823>/Gain'
                                        */
  real_T Constant4_Value[2];           /* Expression: [0, 1]
                                        * Referenced by: '<S832>/Constant4'
                                        */
  real_T Constant1_Value;              /* Expression: 0.6
                                        * Referenced by: '<S832>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 0.5
                                        * Referenced by: '<S832>/Constant5'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S833>/Constant'
                                        */
  real_T Zeros_Value[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<S801>/Zeros'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S825>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S825>/White Noise'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S838>/Weighted Sample Time'
                                   */
  real_T FilterSpecification_Value;    /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S838>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S838>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S838>/Saturation'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S838>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S838>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates;/* Expression: 0
                                            * Referenced by: '<S838>/Discrete Transfer Fcn'
                                            */
  real_T WeightedSampleTime_WtEt_g;
                                /* Computed Parameter: WeightedSampleTime_WtEt_g
                                 * Referenced by: '<S839>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_c;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S839>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: inf
                                        * Referenced by: '<S839>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: eps
                                        * Referenced by: '<S839>/Saturation'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S839>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S839>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_b;/* Expression: 0
                                              * Referenced by: '<S839>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_j;
                                /* Computed Parameter: WeightedSampleTime_WtEt_j
                                 * Referenced by: '<S836>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_h;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S836>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_o0;       /* Expression: inf
                                        * Referenced by: '<S836>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: eps
                                        * Referenced by: '<S836>/Saturation'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S836>/Constant1'
                                        */
  real_T Constant_Value_gy;            /* Expression: 1
                                        * Referenced by: '<S836>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_k;/* Expression: 0
                                              * Referenced by: '<S836>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_l;
                                /* Computed Parameter: WeightedSampleTime_WtEt_l
                                 * Referenced by: '<S837>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_b;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S837>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: inf
                                        * Referenced by: '<S837>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: eps
                                        * Referenced by: '<S837>/Saturation'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S837>/Constant1'
                                        */
  real_T Constant_Value_lr;            /* Expression: 1
                                        * Referenced by: '<S837>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_p;/* Expression: 0
                                              * Referenced by: '<S837>/Discrete Transfer Fcn'
                                              */
  real_T WhiteNoise_Mean_m;            /* Expression: 0
                                        * Referenced by: '<S826>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;         /* Computed Parameter: WhiteNoise_StdDev_d
                                       * Referenced by: '<S826>/White Noise'
                                       */
  real_T DiscreteTimeIntegrator_gainval_p;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_p
                          * Referenced by: '<S835>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S835>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: Amplitude
                                        * Referenced by: '<S835>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: Period
                                        * Referenced by: '<S835>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: PulseWidth
                                        * Referenced by: '<S835>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: PhaseDelay
                                        * Referenced by: '<S835>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S823>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: 4800
                                        * Referenced by: '<S823>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: 80
                                        * Referenced by: '<S823>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S823>/Pulse Generator1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S827>/Switch'
                                        */
  real_T Latch_Threshold;              /* Expression: 0
                                        * Referenced by: '<S831>/Latch'
                                        */
  real_T WeightedSampleTime_WtEt_i;
                                /* Computed Parameter: WeightedSampleTime_WtEt_i
                                 * Referenced by: '<S840>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_k;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S840>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: inf
                                        * Referenced by: '<S840>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: eps
                                        * Referenced by: '<S840>/Saturation'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S840>/Constant1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S840>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_i;/* Expression: 0
                                              * Referenced by: '<S840>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_c;
                                /* Computed Parameter: WeightedSampleTime_WtEt_c
                                 * Referenced by: '<S841>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_j;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S841>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: inf
                                        * Referenced by: '<S841>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: eps
                                        * Referenced by: '<S841>/Saturation'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S841>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S841>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_g;/* Expression: 0
                                              * Referenced by: '<S841>/Discrete Transfer Fcn'
                                              */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S801>/Constant'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S823>/Switch4'
                                        */
  real_T Constant6_Value_p;            /* Expression: 0
                                        * Referenced by: '<S802>/Constant6'
                                        */
  real_T Constant2_Value;              /* Expression: 0.3
                                        * Referenced by: '<S802>/Constant2'
                                        */
  real_T Switch2_Threshold_g;          /* Expression: 0
                                        * Referenced by: '<S803>/Switch2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S802>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.2
                                        * Referenced by: '<S802>/Gain'
                                        */
  real_T Constant4_Value_j[2];         /* Expression: [0, 1]
                                        * Referenced by: '<S811>/Constant4'
                                        */
  real_T Constant2_Value_h;            /* Expression: 0.6
                                        * Referenced by: '<S811>/Constant2'
                                        */
  real_T Constant5_Value_a;            /* Expression: 0.5
                                        * Referenced by: '<S811>/Constant5'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S812>/Constant'
                                        */
  real_T Zeros_Value_b[3];             /* Expression: [0 0 0]
                                        * Referenced by: '<S798>/Zeros'
                                        */
  real_T WhiteNoise_Mean_k;            /* Expression: 0
                                        * Referenced by: '<S804>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_b;         /* Computed Parameter: WhiteNoise_StdDev_b
                                       * Referenced by: '<S804>/White Noise'
                                       */
  real_T WeightedSampleTime_WtEt_e;
                                /* Computed Parameter: WeightedSampleTime_WtEt_e
                                 * Referenced by: '<S817>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_b0; /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S817>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S817>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: eps
                                        * Referenced by: '<S817>/Saturation'
                                        */
  real_T Constant1_Value_d5;           /* Expression: 0
                                        * Referenced by: '<S817>/Constant1'
                                        */
  real_T Constant_Value_ks;            /* Expression: 1
                                        * Referenced by: '<S817>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_j;/* Expression: 0
                                              * Referenced by: '<S817>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_c2;
                               /* Computed Parameter: WeightedSampleTime_WtEt_c2
                                * Referenced by: '<S818>/Weighted Sample Time'
                                */
  real_T FilterSpecification_Value_i;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S818>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: inf
                                        * Referenced by: '<S818>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: eps
                                        * Referenced by: '<S818>/Saturation'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S818>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S818>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_c;/* Expression: 0
                                              * Referenced by: '<S818>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_lp;
                               /* Computed Parameter: WeightedSampleTime_WtEt_lp
                                * Referenced by: '<S815>/Weighted Sample Time'
                                */
  real_T FilterSpecification_Value_f;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S815>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S815>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: eps
                                        * Referenced by: '<S815>/Saturation'
                                        */
  real_T Constant1_Value_mz;           /* Expression: 0
                                        * Referenced by: '<S815>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S815>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_l;/* Expression: 0
                                              * Referenced by: '<S815>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_ja;
                               /* Computed Parameter: WeightedSampleTime_WtEt_ja
                                * Referenced by: '<S816>/Weighted Sample Time'
                                */
  real_T FilterSpecification_Value_e;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S816>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_gu;       /* Expression: inf
                                        * Referenced by: '<S816>/Saturation'
                                        */
  real_T Saturation_LowerSat_h5;       /* Expression: eps
                                        * Referenced by: '<S816>/Saturation'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S816>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S816>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_k4;/* Expression: 0
                                               * Referenced by: '<S816>/Discrete Transfer Fcn'
                                               */
  real_T WhiteNoise_Mean_o;            /* Expression: 0
                                        * Referenced by: '<S805>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_e;         /* Computed Parameter: WhiteNoise_StdDev_e
                                       * Referenced by: '<S805>/White Noise'
                                       */
  real_T DiscreteTimeIntegrator_gainval_n;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                          * Referenced by: '<S814>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S814>/Discrete-Time Integrator'
                                        */
  real_T PulseGenerator_Amp_k;         /* Expression: Amplitude
                                        * Referenced by: '<S814>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_b;      /* Expression: Period
                                        * Referenced by: '<S814>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_l;        /* Expression: PulseWidth
                                        * Referenced by: '<S814>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_f;  /* Expression: PhaseDelay
                                        * Referenced by: '<S814>/Pulse Generator'
                                        */
  real_T PulseGenerator_Amp_e;         /* Expression: 1
                                        * Referenced by: '<S802>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_c;      /* Expression: 80
                                        * Referenced by: '<S802>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty_p;        /* Expression: 3
                                        * Referenced by: '<S802>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay_j;  /* Expression: 0
                                        * Referenced by: '<S802>/Pulse Generator'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S806>/Switch'
                                        */
  real_T Latch_Threshold_j;            /* Expression: 0
                                        * Referenced by: '<S810>/Latch'
                                        */
  real_T WeightedSampleTime_WtEt_lr;
                               /* Computed Parameter: WeightedSampleTime_WtEt_lr
                                * Referenced by: '<S819>/Weighted Sample Time'
                                */
  real_T FilterSpecification_Value_fd; /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S819>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: inf
                                        * Referenced by: '<S819>/Saturation'
                                        */
  real_T Saturation_LowerSat_kr;       /* Expression: eps
                                        * Referenced by: '<S819>/Saturation'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S819>/Constant1'
                                        */
  real_T Constant_Value_gv;            /* Expression: 1
                                        * Referenced by: '<S819>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_o;/* Expression: 0
                                              * Referenced by: '<S819>/Discrete Transfer Fcn'
                                              */
  real_T WeightedSampleTime_WtEt_b;
                                /* Computed Parameter: WeightedSampleTime_WtEt_b
                                 * Referenced by: '<S820>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_fm; /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S820>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_fe;       /* Expression: inf
                                        * Referenced by: '<S820>/Saturation'
                                        */
  real_T Saturation_LowerSat_je;       /* Expression: eps
                                        * Referenced by: '<S820>/Saturation'
                                        */
  real_T Constant1_Value_b2;           /* Expression: 0
                                        * Referenced by: '<S820>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S820>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_gi;/* Expression: 0
                                               * Referenced by: '<S820>/Discrete Transfer Fcn'
                                               */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S798>/Constant'
                                        */
  real_T Switch4_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S802>/Switch4'
                                        */
  real_T Zeros_Value_p[3];             /* Expression: [0 0 0]
                                        * Referenced by: '<S800>/Zeros'
                                        */
  real_T Switch_Threshold_cy;          /* Expression: 0
                                        * Referenced by: '<S799>/Switch'
                                        */
  real_T Constant_Value_lv;            /* Expression: 0
                                        * Referenced by: '<S822>/Constant'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S797>/Merge'
                                       */
  real_T ManualOrientationAdjustment_Value[3];/* Expression: [0 0 0]
                                               * Referenced by: '<S775>/ManualOrientationAdjustment'
                                               */
  real_T CollisionGainReset_Value;     /* Expression: 0.1
                                        * Referenced by: '<S846>/CollisionGainReset'
                                        */
  real_T IC_Value_p;                   /* Expression: 1
                                        * Referenced by: '<S846>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval_j;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_j
                          * Referenced by: '<S846>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_UpperSat_i;/* Expression: 1
                                            * Referenced by: '<S846>/Discrete-Time Integrator'
                                            */
  real_T DiscreteTimeIntegrator_LowerSat_c;/* Expression: 0
                                            * Referenced by: '<S846>/Discrete-Time Integrator'
                                            */
  real_T uDLookupTable_tableData[2];   /* Expression: [.01 1]
                                        * Referenced by: '<S848>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[2];    /* Expression: [.1 1]
                                        * Referenced by: '<S848>/1-D Lookup Table'
                                        */
  real_T WeightedSampleTime_WtEt_m;
                                /* Computed Parameter: WeightedSampleTime_WtEt_m
                                 * Referenced by: '<S863>/Weighted Sample Time'
                                 */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S863>/Saturation'
                                        */
  real_T Saturation_LowerSat_nl;       /* Expression: eps
                                        * Referenced by: '<S863>/Saturation'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S863>/Constant1'
                                        */
  real_T Constant_Value_jf;            /* Expression: 1
                                        * Referenced by: '<S863>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_g5;/* Expression: 0
                                               * Referenced by: '<S863>/Discrete Transfer Fcn'
                                               */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S848>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval_k;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_k
                          * Referenced by: '<S779>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S779>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S778>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval_m;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_m
                          * Referenced by: '<S780>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S780>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval_p3;
                        /* Computed Parameter: DiscreteTimeIntegrator_gainval_p3
                         * Referenced by: '<S781>/Discrete-Time Integrator'
                         */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S781>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval_g;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_g
                          * Referenced by: '<S782>/Discrete-Time Integrator'
                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S782>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S778>/Gain1'
                                        */
  real_T WeightedSampleTime_WtEt_mk;
                               /* Computed Parameter: WeightedSampleTime_WtEt_mk
                                * Referenced by: '<S859>/Weighted Sample Time'
                                */
  real_T Saturation_UpperSat_d3;       /* Expression: inf
                                        * Referenced by: '<S859>/Saturation'
                                        */
  real_T Saturation_LowerSat_l3;       /* Expression: eps
                                        * Referenced by: '<S859>/Saturation'
                                        */
  real_T Constant1_Value_eq;           /* Expression: 0
                                        * Referenced by: '<S859>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S859>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_a;/* Expression: 0
                                              * Referenced by: '<S859>/Discrete Transfer Fcn'
                                              */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S847>/Gain'
                                        */
  real_T uDLookupTable_tableData_d[2]; /* Expression: [.4 1]
                                        * Referenced by: '<S845>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data_i[2];  /* Expression: [.1 1]
                                        * Referenced by: '<S845>/1-D Lookup Table'
                                        */
  real_T WeightedSampleTime_WtEt_gw;
                               /* Computed Parameter: WeightedSampleTime_WtEt_gw
                                * Referenced by: '<S853>/Weighted Sample Time'
                                */
  real_T Saturation_UpperSat_a;        /* Expression: inf
                                        * Referenced by: '<S853>/Saturation'
                                        */
  real_T Saturation_LowerSat_a1;       /* Expression: eps
                                        * Referenced by: '<S853>/Saturation'
                                        */
  real_T Constant1_Value_ae;           /* Expression: 0
                                        * Referenced by: '<S853>/Constant1'
                                        */
  real_T Constant_Value_nh;            /* Expression: 1
                                        * Referenced by: '<S853>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_h;/* Expression: 0
                                              * Referenced by: '<S853>/Discrete Transfer Fcn'
                                              */
  real_T Gain_Gain_gb;                 /* Expression: -1
                                        * Referenced by: '<S845>/Gain'
                                        */
  real_T DeadZone_Start;               /* Expression: -1e-05
                                        * Referenced by: '<S777>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 1e-05
                                        * Referenced by: '<S777>/Dead Zone'
                                        */
  real_T uDLookupTable_tableData_a[2]; /* Expression: [.5 1]
                                        * Referenced by: '<S844>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data_im[2]; /* Expression: [.1 1]
                                        * Referenced by: '<S844>/1-D Lookup Table'
                                        */
  real_T WeightedSampleTime_WtEt_f;
                                /* Computed Parameter: WeightedSampleTime_WtEt_f
                                 * Referenced by: '<S849>/Weighted Sample Time'
                                 */
  real_T Saturation_UpperSat_cl;       /* Expression: inf
                                        * Referenced by: '<S849>/Saturation'
                                        */
  real_T Saturation_LowerSat_js;       /* Expression: eps
                                        * Referenced by: '<S849>/Saturation'
                                        */
  real_T Constant1_Value_fm;           /* Expression: 0
                                        * Referenced by: '<S849>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S849>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_m;/* Expression: 0
                                              * Referenced by: '<S849>/Discrete Transfer Fcn'
                                              */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S844>/Gain'
                                        */
  real_T GravitationalAcceleration_Value[3];/* Expression: [0 0 -9.81]
                                             * Referenced by: '<S774>/GravitationalAcceleration'
                                             */
  real_T SafeGravitationalAcceleration_Value[3];/* Expression: [0 0 -9.81]
                                                 * Referenced by: '<S772>/SafeGravitationalAcceleration'
                                                 */
  real_T SafeRotationMatrix_Value[9];  /* Expression: eye(3)
                                        * Referenced by: '<S772>/SafeRotationMatrix'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S770>/Switch1'
                                        */
  real_T RampRate_Value;               /* Expression: 1/5
                                        * Referenced by: '<S846>/RampRate'
                                        */
  TrackEffectType Constant2_Value_ht;
                                    /* Expression: TrackEffectType.StandardTrack
                                     * Referenced by: '<S799>/Constant2'
                                     */
  TrackEffectType Constant_Value_mf;/* Expression: TrackEffectType.DegradedTrack
                                     * Referenced by: '<S799>/Constant'
                                     */
  TrackEffectType Constant1_Value_cc;
                                    /* Expression: TrackEffectType.NoTrackEffect
                                     * Referenced by: '<S799>/Constant1'
                                     */
  boolean_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S776>/Unit Delay1'
                               */
  P_JoltDuration_BEML_EMU_T JoltDuration_o;/* '<S779>/Jolt Duration' */
  P_JoltDuration_BEML_EMU_T JoltDuration_n;/* '<S780>/Jolt Duration' */
  P_JoltDuration_BEML_EMU_T JoltDuration_e;/* '<S781>/Jolt Duration' */
  P_JoltDuration_BEML_EMU_T JoltDuration;/* '<S782>/Jolt Duration' */
};

/* Parameters (default storage) */
struct P_BEML_EMU_T_ {
  BD_TCMSSystem_Out_Vehicle UnitDelay3_InitialCondition;
                              /* Computed Parameter: UnitDelay3_InitialCondition
                               * Referenced by: '<Root>/Unit Delay3'
                               */
  BD_TCMSSystem_Out_Vehicle UnitDelay6_InitialCondition;
                              /* Computed Parameter: UnitDelay6_InitialCondition
                               * Referenced by: '<S1>/Unit Delay6'
                               */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  BD_IOControls_Out_Vehicle_InputStates UnitDelay_InitialCondition_o;
                             /* Computed Parameter: UnitDelay_InitialCondition_o
                              * Referenced by: '<S401>/Unit Delay'
                              */
  BD_DoorSystem_Out_Vehicle UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<Root>/Unit Delay1'
                               */
  BD_DoorSystem_Out_Vehicle UnitDelay3_InitialCondition_a;
                            /* Computed Parameter: UnitDelay3_InitialCondition_a
                             * Referenced by: '<S1>/Unit Delay3'
                             */
  BD_ElectricalSystem_Out_Vehicle UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<Root>/Unit Delay'
                              */
  BD_ElectricalSystem_Out_Vehicle UnitDelay5_InitialCondition;
                              /* Computed Parameter: UnitDelay5_InitialCondition
                               * Referenced by: '<S1>/Unit Delay5'
                               */
  BD_TrainDynamics_Out_Vehicle UnitDelay_InitialCondition_d;
                             /* Computed Parameter: UnitDelay_InitialCondition_d
                              * Referenced by: '<S1>/Unit Delay'
                              */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay2_InitialCondition;
                              /* Computed Parameter: UnitDelay2_InitialCondition
                               * Referenced by: '<Root>/Unit Delay2'
                               */
  BD_PneumaticsSystem_Out_Vehicle UnitDelay1_InitialCondition_c;
                            /* Computed Parameter: UnitDelay1_InitialCondition_c
                             * Referenced by: '<S1>/Unit Delay1'
                             */
  BD_SimIntegration_Cfg_Vehicle VehicleConfigProcessed_Y0;
                                /* Computed Parameter: VehicleConfigProcessed_Y0
                                 * Referenced by: '<S675>/VehicleConfigProcessed'
                                 */
  BD_PneumaticsSystem_Prm PneumaticsSystem_Prm_PneumaticsSystem;
                                    /* Expression: PRM_SimIntegration.Pneumatics
                                     * Referenced by: '<S12>/PneumaticsSystem'
                                     */
  BD_TractionSystem_Out_Vehicle UnitDelay4_InitialCondition;
                              /* Computed Parameter: UnitDelay4_InitialCondition
                               * Referenced by: '<S1>/Unit Delay4'
                               */
  BD_TrainBrakes_Out_Vehicle UnitDelay7_InitialCondition;
                              /* Computed Parameter: UnitDelay7_InitialCondition
                               * Referenced by: '<S1>/Unit Delay7'
                               */
  BD_TrainBrakes_Prm_Vehicle TrainBrakes_PRM_TrainBrakes_Vehicles;/* Expression: PRM_SimIntegration.Brakes
                                                                   * Referenced by: '<S5>/TrainBrakes'
                                                                   */
  BD_TrainDynamics_Cfg_Vehicle DynamicsVehicleCfg_Y0;
                                    /* Computed Parameter: DynamicsVehicleCfg_Y0
                                     * Referenced by: '<S310>/DynamicsVehicleCfg'
                                     */
  BD_TractionSystem_Prm TractionSystem_Prm_TractionSystem;
                                      /* Expression: PRM_SimIntegration.Traction
                                       * Referenced by: '<S14>/TractionSystem'
                                       */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0;
                                      /* Computed Parameter: CommonVehicleCfg_Y0
                                       * Referenced by: '<S16>/CommonVehicleCfg'
                                       */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_e;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_e
                                     * Referenced by: '<S149>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_m;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_m
                                     * Referenced by: '<S310>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_f;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_f
                                     * Referenced by: '<S317>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_o;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_o
                                     * Referenced by: '<S338>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_j;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_j
                                     * Referenced by: '<S348>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_k;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_k
                                     * Referenced by: '<S359>/CommonVehicleCfg'
                                     */
  BD_CommonTrain_Cfg_Vehicle CommonVehicleCfg_Y0_d;
                                    /* Computed Parameter: CommonVehicleCfg_Y0_d
                                     * Referenced by: '<S384>/CommonVehicleCfg'
                                     */
  BD_TCMSSystem_Prm TCMSSystem_Prm_TCMSSystem;/* Expression: PRM_SimIntegration.TCMS
                                               * Referenced by: '<S13>/TCMSSystem'
                                               */
  BD_DoorSystem_Prm DoorsSystem_PRM_DoorSystem;/* Expression: PRM_SimIntegration.Doors
                                                * Referenced by: '<S8>/DoorsSystem'
                                                */
  BD_PneumaticsSystem_Cfg_Vehicle PneumaticsVehicleCfg_Y0;
                                  /* Computed Parameter: PneumaticsVehicleCfg_Y0
                                   * Referenced by: '<S348>/PneumaticsVehicleCfg'
                                   */
  BD_PantographSystem_Out_Vehicle UnitDelay2_InitialCondition_p;
                            /* Computed Parameter: UnitDelay2_InitialCondition_p
                             * Referenced by: '<S1>/Unit Delay2'
                             */
  BD_TCMSSystem_Cfg_Vehicle TCMSVehicleCfg_Y0;/* Computed Parameter: TCMSVehicleCfg_Y0
                                               * Referenced by: '<S359>/TCMSVehicleCfg'
                                               */
  BD_TrainBrakes_Cfg_Vehicle BrakesVehicleCfg_Y0;
                                      /* Computed Parameter: BrakesVehicleCfg_Y0
                                       * Referenced by: '<S16>/BrakesVehicleCfg'
                                       */
  BD_ElectricalSystem_Cfg_Vehicle ElectricalVehicleCfg_Y0;
                                  /* Computed Parameter: ElectricalVehicleCfg_Y0
                                   * Referenced by: '<S317>/ElectricalVehicleCfg'
                                   */
  BD_PantographSystem_Prm PantographSystem_Prm_PantographSystem;
                                    /* Expression: PRM_SimIntegration.Pantograph
                                     * Referenced by: '<S11>/PantographSystem'
                                     */
  BD_SimIntegration_Cfg_Vehicle_Location LocationVehicleConfig_Y0;
                                 /* Computed Parameter: LocationVehicleConfig_Y0
                                  * Referenced by: '<S348>/LocationVehicleConfig'
                                  */
  BD_DoorSystem_Cfg_Door DoorsConfig_Y0;/* Computed Parameter: DoorsConfig_Y0
                                         * Referenced by: '<S149>/DoorsConfig'
                                         */
  BD_ElectricalSystem_Prm ElectricalSystem_Prm_ElectricalSystem;
                                    /* Expression: PRM_SimIntegration.Electrical
                                     * Referenced by: '<S10>/ElectricalSystem'
                                     */
  BD_PantographSystem_Cfg_Vehicle PantographVehicleCfg_Y0;
                                  /* Computed Parameter: PantographVehicleCfg_Y0
                                   * Referenced by: '<S338>/PantographVehicleCfg'
                                   */
  BD_SimIntegration_Out_Train_Scoring Constant1_Value;/* Computed Parameter: Constant1_Value
                                                       * Referenced by: '<S746>/Constant1'
                                                       */
  BD_TractionSystem_Cfg_Vehicle TractionVehicleCfg_Y0;
                                    /* Computed Parameter: TractionVehicleCfg_Y0
                                     * Referenced by: '<S384>/TractionVehicleCfg'
                                     */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S15>/Step'
                                        */
  real_T Step_Time_b;                  /* Expression: 1
                                        * Referenced by: '<S20>/Step'
                                        */
  real_T Step_Y0_m;                    /* Expression: 1
                                        * Referenced by: '<S20>/Step'
                                        */
  real_T Step_YFinal_a;                /* Expression: 0
                                        * Referenced by: '<S20>/Step'
                                        */
  real_T Step_Time_o;                  /* Expression: 1
                                        * Referenced by: '<S148>/Step'
                                        */
  real_T Step_Y0_j;                    /* Expression: 1
                                        * Referenced by: '<S148>/Step'
                                        */
  real_T Step_YFinal_l;                /* Expression: 0
                                        * Referenced by: '<S148>/Step'
                                        */
  real_T Step_Time_h;                  /* Expression: 1
                                        * Referenced by: '<S309>/Step'
                                        */
  real_T Step_Y0_i;                    /* Expression: 1
                                        * Referenced by: '<S309>/Step'
                                        */
  real_T Step_YFinal_d;                /* Expression: 0
                                        * Referenced by: '<S309>/Step'
                                        */
  real_T Step_Time_g;                  /* Expression: 1
                                        * Referenced by: '<S316>/Step'
                                        */
  real_T Step_Y0_g;                    /* Expression: 1
                                        * Referenced by: '<S316>/Step'
                                        */
  real_T Step_YFinal_i;                /* Expression: 0
                                        * Referenced by: '<S316>/Step'
                                        */
  real_T Step_Time_gl;                 /* Expression: 1
                                        * Referenced by: '<S337>/Step'
                                        */
  real_T Step_Y0_o;                    /* Expression: 1
                                        * Referenced by: '<S337>/Step'
                                        */
  real_T Step_YFinal_e;                /* Expression: 0
                                        * Referenced by: '<S337>/Step'
                                        */
  real_T Step_Time_e;                  /* Expression: 1
                                        * Referenced by: '<S347>/Step'
                                        */
  real_T Step_Y0_c;                    /* Expression: 1
                                        * Referenced by: '<S347>/Step'
                                        */
  real_T Step_YFinal_f;                /* Expression: 0
                                        * Referenced by: '<S347>/Step'
                                        */
  real_T Step_Time_b2;                 /* Expression: 1
                                        * Referenced by: '<S358>/Step'
                                        */
  real_T Step_Y0_ob;                   /* Expression: 1
                                        * Referenced by: '<S358>/Step'
                                        */
  real_T Step_YFinal_im;               /* Expression: 0
                                        * Referenced by: '<S358>/Step'
                                        */
  real_T Step_Time_d;                  /* Expression: 1
                                        * Referenced by: '<S383>/Step'
                                        */
  real_T Step_Y0_h;                    /* Expression: 1
                                        * Referenced by: '<S383>/Step'
                                        */
  real_T Step_YFinal_iz;               /* Expression: 0
                                        * Referenced by: '<S383>/Step'
                                        */
  real_T Step_Time_l;                  /* Expression: 2
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_Y0_gx;                   /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal_m;                /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_Time_k;                  /* Expression: 1
                                        * Referenced by: '<S403>/Step'
                                        */
  real_T Step_Y0_l;                    /* Expression: 1
                                        * Referenced by: '<S403>/Step'
                                        */
  real_T Step_YFinal_lp;               /* Expression: 0
                                        * Referenced by: '<S403>/Step'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S746>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 5000
                                        * Referenced by: '<S746>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S746>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S746>/Discrete-Time Integrator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S746>/Switch'
                                        */
  int32_T Constant1_Value_f;           /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S678>/Constant1'
                                        */
  int32_T UnitDelay_InitialCondition_g;
                             /* Computed Parameter: UnitDelay_InitialCondition_g
                              * Referenced by: '<S675>/Unit Delay'
                              */
  boolean_T HasCab_Y0;                 /* Computed Parameter: HasCab_Y0
                                        * Referenced by: '<S149>/HasCab'
                                        */
  boolean_T Constant_Value_g;          /* Expression: false
                                        * Referenced by: '<S678>/Constant'
                                        */
  P_CoreSubsys_BEML_EMU_l3_T CoreSubsys_m;/* '<S753>/MotionBasePerVehicle' */
  P_CoreSubsys_BEML_EMU_gx_T CoreSubsys_pnaevvfpgh5z;/* '<S737>/Input Adapter' */
  P_CoreSubsys_BEML_EMU_jb_T CoreSubsys_pnaevvfpgh5;/* '<S736>/VehicleLevelScoring' */
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddg_T CoreSubsys_pnaevvfpg;/* '<S746>/For Each Subsystem' */
  P_CoreSubsys_BEML_EMU_gmy0ogcc_T CoreSubsys_pnaevvf;/* '<S734>/Subsystem1' */
  P_CoreSubsys_BEML_EMU_gmy0o_T CoreSubsys_pnae;/* '<S675>/VehicleConfigInterface' */
  P_CoreSubsys_BEML_EMU_gmy_T CoreSubsys_pna;
                                      /* '<S401>/InhibitsAndInternalRequests' */
  P_CoreSubsys_BEML_EMU_g_T CoreSubsys_p;/* '<S400>/Subsystem' */
  P_CoreSubsys_BEML_EMU_d5_T CoreSubsys_cr;/* '<S383>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_cia_T CoreSubsys_gf;/* '<S358>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_ci_T CoreSubsys_g;/* '<S359>/ExtractConfig' */
  P_CoreSubsys_BEML_EMU_mr_T CoreSubsys_i2v;/* '<S347>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_ctkg_T CoreSubsys_ls2;/* '<S337>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_fa_T CoreSubsys_ij1;/* '<S316>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_ng_T CoreSubsys_ex;/* '<S309>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_ln_T CoreSubsys_lb;/* '<S148>/VehicleInputAdapter' */
  P_CoreSubsys_BEML_EMU_c_T CoreSubsys_i;/* '<S145>/Subsystem' */
  P_CoreSubsys_BEML_EMU_i_T CoreSubsys_h;/* '<S20>/CBTCModel' */
  P_CoreSubsys_BEML_EMU_j_T CoreSubsys_k;/* '<S15>/VehicleInputAdapter' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BEML_EMU_T {
  const char_T *errorStatus;
  rtTimingBridge timingBridge;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[1549];
    int32_T* vardimsAddress[1549];
    RTWLoggingFcnPtr loggingPtrs[1549];
    rtwCAPI_ModelMappingInfo* childMMI[10];
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    struct {
      uint32_T TID[5];
    } TaskCounters;
  } Timing;
};

/* model data, for system '<S400>/Subsystem' */
typedef struct {
  DW_CoreSubsys_BEML_EMU_f_T dwork;
  B_CoreSubsys_BEML_EMU_c_T blockIO;
  P_CoreSubsys_BEML_EMU_g_T* defaultParam;
} self_CoreSubsys_BEML_EMU_j_T;

/* model data, for system '<S660>/Subsystem1' */
typedef struct {
  P_CoreSubsys_BEML_EMU_gmy0_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2b_T;

/* model data, for system '<S401>/InhibitsAndInternalRequests' */
typedef struct {
  self_CoreSubsys_BEML_EMU_jb2b_T self_CoreSubsys[16];
  P_CoreSubsys_BEML_EMU_gmy_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2_T;

/* model data, for system '<S686>/VehicleEquipment' */
typedef struct {
  P_VehicleEquipment_BEML_EMU_T* defaultParam;
} self_VehicleEquipment_BEML_EMU_T;

/* model data, for system '<S685>/VehicleEquipment' */
typedef struct {
  P_VehicleEquipment_BEML_EMU_b_T* defaultParam;
} self_VehicleEquipment_BEML_EMU_m_T;

/* model data, for system '<S684>/VehicleEquipment' */
typedef struct {
  P_VehicleEquipment_BEML_EMU_e_T* defaultParam;
} self_VehicleEquipment_BEML_EMU_p_T;

/* model data, for system '<S683>/VehicleEquipment' */
typedef struct {
  P_VehicleEquipment_BEML_EMU_n_T* defaultParam;
} self_VehicleEquipment_BEML_EMU_l_T;

/* model data, for system '<S681>/VehicleEquipment4' */
typedef struct {
  P_VehicleEquipment4_BEML_EMU_T* defaultParam;
} self_VehicleEquipment4_BEML_EMU_T;

/* model data, for system '<S675>/VehicleConfigInterface' */
typedef struct {
  self_VehicleEquipment4_BEML_EMU_T self_VehicleEquipment3_o;
  self_VehicleEquipment4_BEML_EMU_T self_VehicleEquipment2_f;
  self_VehicleEquipment4_BEML_EMU_T self_VehicleEquipment1_n;
  self_VehicleEquipment4_BEML_EMU_T self_VehicleEquipment4;
  self_VehicleEquipment_BEML_EMU_l_T self_VehicleEquipment3_ly;
  self_VehicleEquipment_BEML_EMU_l_T self_VehicleEquipment2_m;
  self_VehicleEquipment_BEML_EMU_l_T self_VehicleEquipment1_m;
  self_VehicleEquipment_BEML_EMU_l_T self_VehicleEquipment_o;
  self_VehicleEquipment_BEML_EMU_p_T self_VehicleEquipment2_h;
  self_VehicleEquipment_BEML_EMU_p_T self_VehicleEquipment3_l;
  self_VehicleEquipment_BEML_EMU_p_T self_VehicleEquipment1_a;
  self_VehicleEquipment_BEML_EMU_p_T self_VehicleEquipment_g;
  self_VehicleEquipment_BEML_EMU_m_T self_VehicleEquipment3_f;
  self_VehicleEquipment_BEML_EMU_m_T self_VehicleEquipment2_n;
  self_VehicleEquipment_BEML_EMU_m_T self_VehicleEquipment1_c;
  self_VehicleEquipment_BEML_EMU_m_T self_VehicleEquipment_c;
  self_VehicleEquipment_BEML_EMU_T self_VehicleEquipment3;
  self_VehicleEquipment_BEML_EMU_T self_VehicleEquipment2;
  self_VehicleEquipment_BEML_EMU_T self_VehicleEquipment1;
  self_VehicleEquipment_BEML_EMU_T self_VehicleEquipment;
  P_CoreSubsys_BEML_EMU_gmy0o_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2bn_T;

/* model data, for system '<S734>/Subsystem1' */
typedef struct {
  DW_CoreSubsys_BEML_EMU_fwu4sljn_T dwork;
  P_CoreSubsys_BEML_EMU_gmy0ogcc_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2bnsau_T;

/* model data, for system '<S750>/Subsystem' */
typedef struct {
  DW_CoreSubsys_BEML_EMU_fwu4sljnnsfqdu_T dwork;
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddgv_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2bnsaujtd5ul_T;

/* model data, for system '<S746>/For Each Subsystem' */
typedef struct {
  self_CoreSubsys_BEML_EMU_jb2bnsaujtd5ul_T self_CoreSubsys[2];
  P_CoreSubsys_BEML_EMU_gmy0ogccz5ddg_T* defaultParam;
} self_CoreSubsys_BEML_EMU_jb2bnsaujtd5u_T;

/* model data, for system '<S736>/VehicleLevelScoring' */
typedef struct {
  P_CoreSubsys_BEML_EMU_jb_T* defaultParam;
} self_CoreSubsys_BEML_EMU_o_T;

/* model data, for system '<S737>/Input Adapter' */
typedef struct {
  DW_CoreSubsys_BEML_EMU_jr_T dwork;
  P_CoreSubsys_BEML_EMU_gx_T* defaultParam;
} self_CoreSubsys_BEML_EMU_gj_T;

/* External data declarations for dependent source files */
extern const BD_SimIntegration_Cfg_Vehicle
  BEML_EMU_rtZBD_SimIntegration_Cfg_Vehicle;
                                      /* BD_SimIntegration_Cfg_Vehicle ground */

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  BEML_EMU_GetCAPIStaticMap(void);

/* Class declaration for model BEML_EMU */
class BEML_EMUModelClass {
  /* public data and function members */
 public:
  /* External inputs */
  ExtU_BEML_EMU_T BEML_EMU_U;

  /* External outputs */
  ExtY_BEML_EMU_T BEML_EMU_Y;

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  BEML_EMUModelClass();

  /* Destructor */
  ~BEML_EMUModelClass();

  /* Real-Time Model get method */
  RT_MODEL_BEML_EMU_T * getRTM();

  /* private data and function members */
  /* Tunable parameters */
  static P_BEML_EMU_T BEML_EMU_P;

  /* Block signals */
  B_BEML_EMU_T BEML_EMU_B;

  /* Block states */
  DW_BEML_EMU_T BEML_EMU_DW;

  /* Block variables */
  self_CoreSubsys_BEML_EMU_gj_T self_CoreSubsys_pnaevvfpgh5z[8];
  self_CoreSubsys_BEML_EMU_o_T self_CoreSubsys_pnaevvfpgh5[8];
  self_CoreSubsys_BEML_EMU_jb2bnsaujtd5u_T self_CoreSubsys_pnaevvfpg[8];
  self_CoreSubsys_BEML_EMU_jb2bnsau_T self_CoreSubsys_pnaevvf[8];
  self_CoreSubsys_BEML_EMU_jb2bn_T self_CoreSubsys_pnae[8];
  self_CoreSubsys_BEML_EMU_jb2_T self_CoreSubsys_pna[8];
  self_CoreSubsys_BEML_EMU_j_T self_CoreSubsys_p[8];

  /* Real-Time Model */
  RT_MODEL_BEML_EMU_T BEML_EMU_M;

  /* private member function(s) for subsystem '<S130>/If Action Subsystem'*/
  void BEML_EMU_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1);

  /* private member function(s) for subsystem '<S23>/NotInATO'*/
  void BEML_EMU_NotInATO(real_T *rty_Out1, P_NotInATO_BEML_EMU_T *localP);

  /* private member function(s) for subsystem '<S448>/IRQRequestStateMachine'*/
  void BEML_EMU_IRQRequestStateMachine_Init(DW_IRQRequestStateMachine_BEML_EMU_T
    *localDW);
  void BEML_EMU_IRQRequestStateMachine_Start(B_IRQRequestStateMachine_BEML_EMU_T
    *localB);
  void BEML_EMU_IRQRequestStateMachine(boolean_T rtu_FaultApplied, real_T
    rtu_FaultStateValue, real_T rtu_NormalStateValue, real_T rtu_ControlState,
    B_IRQRequestStateMachine_BEML_EMU_T *localB,
    DW_IRQRequestStateMachine_BEML_EMU_T *localDW,
    P_IRQRequestStateMachine_BEML_EMU_T *localP);

  /* private member function(s) for subsystem '<S426>/ControlStateRequest'*/
  void BEML_EMU_ControlStateRequest_Init(B_ControlStateRequest_BEML_EMU_T
    *localB, DW_ControlStateRequest_BEML_EMU_T *localDW,
    P_ControlStateRequest_BEML_EMU_T *localP);
  void BEML_EMU_ControlStateRequest_Reset(DW_ControlStateRequest_BEML_EMU_T
    *localDW, P_ControlStateRequest_BEML_EMU_T *localP);
  void BEML_EMU_ControlStateRequest_Start(B_ControlStateRequest_BEML_EMU_T
    *localB, DW_ControlStateRequest_BEML_EMU_T *localDW);
  void BEML_EMU_ControlStateRequest_Disable(DW_ControlStateRequest_BEML_EMU_T
    *localDW);
  void BEML_EMU_ControlStateRequest(boolean_T rtu_Enable, real_T rtu_TargetState,
    real_T rtu_ControlState, B_ControlStateRequest_BEML_EMU_T *localB,
    DW_ControlStateRequest_BEML_EMU_T *localDW, P_ControlStateRequest_BEML_EMU_T
    *localP, real_T rtp_ControlType);

  /* private member function(s) for subsystem '<S426>/Chart'*/
  void BEML_EMU_Chart_Init(DW_Chart_BEML_EMU_T *localDW);
  void BEML_EMU_Chart_Start(B_Chart_BEML_EMU_T *localB);
  void BEML_EMU_Chart(boolean_T rtu_FaultApplied, boolean_T
                      rtu_ControlsRequestComplete, B_Chart_BEML_EMU_T *localB,
                      DW_Chart_BEML_EMU_T *localDW, P_Chart_BEML_EMU_T *localP);

  /* private member function(s) for subsystem '<S686>/VehicleEquipment'*/
  void BEML_EMU_VehicleEquipment(self_VehicleEquipment_BEML_EMU_T
    *BEML_EMU_self_arg, BD_TractionSystem_Cfg_Vehicle *rty_EquipmentBus, real_T
    rtp_HasMotors);

  /* private member function(s) for subsystem '<S685>/VehicleEquipment'*/
  void BEML_EMU_VehicleEquipment_c(self_VehicleEquipment_BEML_EMU_m_T
    *BEML_EMU_self_arg, BD_PneumaticsSystem_Cfg_Vehicle *rty_EquipmentBus,
    real_T rtp_HasCab, real_T rtp_HasBogie, real_T rtp_HasCompressor, real_T
    rtp_HasMainReservoir, real_T rtp_HasBrakeSystem, real_T rtp_HasPantograph);

  /* private member function(s) for subsystem '<S684>/VehicleEquipment'*/
  void BEML_EMU_VehicleEquipment_g(self_VehicleEquipment_BEML_EMU_p_T
    *BEML_EMU_self_arg, BD_PantographSystem_Cfg_Vehicle *rty_EquipmentBus,
    real_T rtp_HasPanto, real_T rtp_PenumaticsPoweredPanto, real_T
    rtp_ElectricPoweredPanto);

  /* private member function(s) for subsystem '<S683>/VehicleEquipment'*/
  void BEML_EMU_VehicleEquipment_o(self_VehicleEquipment_BEML_EMU_l_T
    *BEML_EMU_self_arg, BD_SimIntegration_Cfg_Vehicle_Equipment
    *rty_EquipmentBus, real_T rtp_HasCab, real_T rtp_HasBogie, real_T
    rtp_HasMotors, real_T rtp_HasPneumaticPanto, real_T rtp_HasElectricPanto,
    real_T rtp_HasMainCompressor, real_T rtp_HasMainReservoir, real_T
    rtp_HasPantoReservoir, real_T rtp_HasBrakeSystem, real_T rtp_NumberOfDoors,
    real_T rtp_NumberOfTractionBogies, real_T rtp_NumberOfBrakingBogies);

  /* private member function(s) for subsystem '<S681>/VehicleEquipment4'*/
  void BEML_EMU_VehicleEquipment4(self_VehicleEquipment4_BEML_EMU_T
    *BEML_EMU_self_arg, BD_DoorSystem_Cfg_Door *rty_EquipmentBus, real_T
    rtp_IsLeft, real_T rtp_NumberOfDoors);

  /* private member function(s) for subsystem '<S782>/Jolt Duration'*/
  void BEML_EMU_JoltDuration_Init(DW_JoltDuration_BEML_EMU_T *localDW);
  void BEML_EMU_JoltDuration_Start(B_JoltDuration_BEML_EMU_T *localB,
    DW_JoltDuration_BEML_EMU_T *localDW);
  void BEML_EMU_JoltDuration(boolean_T rtu_In, B_JoltDuration_BEML_EMU_T *localB,
    DW_JoltDuration_BEML_EMU_T *localDW, P_JoltDuration_BEML_EMU_T *localP);
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BEML_EMU'
 * '<S1>'   : 'BEML_EMU/BEML_EMU'
 * '<S2>'   : 'BEML_EMU/InitialiseModel'
 * '<S3>'   : 'BEML_EMU/InputsInterface'
 * '<S4>'   : 'BEML_EMU/SimulatorSystems'
 * '<S5>'   : 'BEML_EMU/BEML_EMU/BrakesInterface'
 * '<S6>'   : 'BEML_EMU/BEML_EMU/CBTCInterface'
 * '<S7>'   : 'BEML_EMU/BEML_EMU/CouplingInterface'
 * '<S8>'   : 'BEML_EMU/BEML_EMU/DoorsInterface'
 * '<S9>'   : 'BEML_EMU/BEML_EMU/DynamicsInterface'
 * '<S10>'  : 'BEML_EMU/BEML_EMU/ElectricalInterface'
 * '<S11>'  : 'BEML_EMU/BEML_EMU/PantographInterface'
 * '<S12>'  : 'BEML_EMU/BEML_EMU/PneumaticsInterface'
 * '<S13>'  : 'BEML_EMU/BEML_EMU/TCMSInterface'
 * '<S14>'  : 'BEML_EMU/BEML_EMU/TractionInterface'
 * '<S15>'  : 'BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter'
 * '<S16>'  : 'BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig'
 * '<S17>'  : 'BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter'
 * '<S18>'  : 'BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/ExtractConfig/ExtractConfig'
 * '<S19>'  : 'BEML_EMU/BEML_EMU/BrakesInterface/BrakesInputAdapter/VehicleInputAdapter/For Each Subsystem'
 * '<S20>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit'
 * '<S21>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel'
 * '<S22>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/ExtractConfig'
 * '<S23>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO'
 * '<S24>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/DMIPacking'
 * '<S25>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ElectricalPacking'
 * '<S26>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking'
 * '<S27>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/PlatformUnitPacking'
 * '<S28>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/TCMSPacking'
 * '<S29>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand'
 * '<S30>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand'
 * '<S31>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Brake When Close to Stopping Point'
 * '<S32>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Coasting'
 * '<S33>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant'
 * '<S34>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant1'
 * '<S35>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant2'
 * '<S36>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant3'
 * '<S37>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant5'
 * '<S38>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/Compare To Constant6'
 * '<S39>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/NotInATO'
 * '<S40>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller'
 * '<S41>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Anti-windup'
 * '<S42>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/D Gain'
 * '<S43>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Filter'
 * '<S44>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Filter ICs'
 * '<S45>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/I Gain'
 * '<S46>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Ideal P Gain'
 * '<S47>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Ideal P Gain Fdbk'
 * '<S48>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Integrator'
 * '<S49>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Integrator ICs'
 * '<S50>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/N Copy'
 * '<S51>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/N Gain'
 * '<S52>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/P Copy'
 * '<S53>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Parallel P Gain'
 * '<S54>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Reset Signal'
 * '<S55>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Saturation'
 * '<S56>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Saturation Fdbk'
 * '<S57>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Sum'
 * '<S58>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Sum Fdbk'
 * '<S59>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Tracking Mode'
 * '<S60>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Tracking Mode Sum'
 * '<S61>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/postSat Signal'
 * '<S62>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/preSat Signal'
 * '<S63>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Anti-windup/Passthrough'
 * '<S64>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/D Gain/External Parameters'
 * '<S65>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Filter/Differentiator'
 * '<S66>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S67>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/I Gain/External Parameters'
 * '<S68>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Ideal P Gain/Passthrough'
 * '<S69>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S70>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Integrator/Discrete'
 * '<S71>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Integrator ICs/Internal IC'
 * '<S72>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/N Copy/Disabled wSignal Specification'
 * '<S73>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/N Gain/Passthrough'
 * '<S74>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/P Copy/Disabled'
 * '<S75>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Parallel P Gain/External Parameters'
 * '<S76>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Reset Signal/Disabled'
 * '<S77>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Saturation/Enabled'
 * '<S78>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Saturation Fdbk/Disabled'
 * '<S79>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Sum/Sum_PID'
 * '<S80>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Sum Fdbk/Disabled'
 * '<S81>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Tracking Mode/Disabled'
 * '<S82>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/Tracking Mode Sum/Passthrough'
 * '<S83>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/postSat Signal/Forward_Path'
 * '<S84>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Braking Demand/Brake Demand PID Controller/preSat Signal/Forward_Path'
 * '<S85>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand'
 * '<S86>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Anti-windup'
 * '<S87>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/D Gain'
 * '<S88>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Filter'
 * '<S89>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Filter ICs'
 * '<S90>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/I Gain'
 * '<S91>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Ideal P Gain'
 * '<S92>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Ideal P Gain Fdbk'
 * '<S93>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Integrator'
 * '<S94>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Integrator ICs'
 * '<S95>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/N Copy'
 * '<S96>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/N Gain'
 * '<S97>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/P Copy'
 * '<S98>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Parallel P Gain'
 * '<S99>'  : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Reset Signal'
 * '<S100>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Saturation'
 * '<S101>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Saturation Fdbk'
 * '<S102>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Sum'
 * '<S103>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Sum Fdbk'
 * '<S104>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Tracking Mode'
 * '<S105>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Tracking Mode Sum'
 * '<S106>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/postSat Signal'
 * '<S107>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/preSat Signal'
 * '<S108>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Anti-windup/Passthrough'
 * '<S109>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/D Gain/External Parameters'
 * '<S110>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Filter/Differentiator'
 * '<S111>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Filter ICs/Internal IC - Differentiator'
 * '<S112>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/I Gain/External Parameters'
 * '<S113>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Ideal P Gain/Passthrough'
 * '<S114>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Integrator/Discrete'
 * '<S116>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Integrator ICs/Internal IC'
 * '<S117>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/N Copy/Disabled wSignal Specification'
 * '<S118>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/N Gain/Passthrough'
 * '<S119>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/P Copy/Disabled'
 * '<S120>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Parallel P Gain/External Parameters'
 * '<S121>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Reset Signal/Disabled'
 * '<S122>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Saturation/Enabled'
 * '<S123>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Saturation Fdbk/Disabled'
 * '<S124>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Sum/Sum_PID'
 * '<S125>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Sum Fdbk/Disabled'
 * '<S126>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Tracking Mode/Disabled'
 * '<S127>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/postSat Signal/Forward_Path'
 * '<S129>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/ATO/ATO Traction Demand/Tractive Demand/preSat Signal/Forward_Path'
 * '<S130>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus'
 * '<S131>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching'
 * '<S132>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem'
 * '<S133>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem1'
 * '<S134>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem2'
 * '<S135>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem3'
 * '<S136>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem4'
 * '<S137>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem5'
 * '<S138>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem6'
 * '<S139>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/DriverModeStatus/If Action Subsystem7'
 * '<S140>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority'
 * '<S141>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority1'
 * '<S142>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority2'
 * '<S143>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/CBTCModel/OnBoardUnitPacking/ModeLatching/SR Latch - Reset Priority3'
 * '<S144>' : 'BEML_EMU/BEML_EMU/CBTCInterface/CBTCInterfacingUnit/ExtractConfig/ExtractConfig'
 * '<S145>' : 'BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter'
 * '<S146>' : 'BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem'
 * '<S147>' : 'BEML_EMU/BEML_EMU/CouplingInterface/CouplingInputAdapter/Subsystem/ConvertToCouplerBus'
 * '<S148>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter'
 * '<S149>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig'
 * '<S150>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter'
 * '<S151>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/ExtractConfig/ExtractConfig'
 * '<S152>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs'
 * '<S153>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorControls'
 * '<S154>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement'
 * '<S155>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/EmergencyDoorInputsExtraction'
 * '<S156>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem'
 * '<S157>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL1'
 * '<S158>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL2'
 * '<S159>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL3'
 * '<S160>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DL4'
 * '<S161>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR1'
 * '<S162>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR2'
 * '<S163>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR3'
 * '<S164>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/DoorsArrangement/DR4'
 * '<S165>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem'
 * '<S166>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1'
 * '<S167>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10'
 * '<S168>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11'
 * '<S169>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12'
 * '<S170>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13'
 * '<S171>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14'
 * '<S172>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15'
 * '<S173>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2'
 * '<S174>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3'
 * '<S175>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4'
 * '<S176>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5'
 * '<S177>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6'
 * '<S178>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7'
 * '<S179>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8'
 * '<S180>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9'
 * '<S181>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant'
 * '<S182>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant1'
 * '<S183>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant2'
 * '<S184>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant3'
 * '<S185>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant4'
 * '<S186>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant5'
 * '<S187>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant6'
 * '<S188>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem/Compare To Constant7'
 * '<S189>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant'
 * '<S190>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant1'
 * '<S191>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant2'
 * '<S192>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant3'
 * '<S193>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant4'
 * '<S194>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant5'
 * '<S195>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant6'
 * '<S196>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem1/Compare To Constant7'
 * '<S197>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant'
 * '<S198>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant1'
 * '<S199>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant2'
 * '<S200>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant3'
 * '<S201>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant4'
 * '<S202>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant5'
 * '<S203>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant6'
 * '<S204>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem10/Compare To Constant7'
 * '<S205>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant'
 * '<S206>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant1'
 * '<S207>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant2'
 * '<S208>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant3'
 * '<S209>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant4'
 * '<S210>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant5'
 * '<S211>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant6'
 * '<S212>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem11/Compare To Constant7'
 * '<S213>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant'
 * '<S214>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant1'
 * '<S215>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant2'
 * '<S216>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant3'
 * '<S217>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant4'
 * '<S218>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant5'
 * '<S219>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant6'
 * '<S220>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem12/Compare To Constant7'
 * '<S221>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant'
 * '<S222>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant1'
 * '<S223>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant2'
 * '<S224>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant3'
 * '<S225>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant4'
 * '<S226>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant5'
 * '<S227>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant6'
 * '<S228>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem13/Compare To Constant7'
 * '<S229>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant'
 * '<S230>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant1'
 * '<S231>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant2'
 * '<S232>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant3'
 * '<S233>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant4'
 * '<S234>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant5'
 * '<S235>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant6'
 * '<S236>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem14/Compare To Constant7'
 * '<S237>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant'
 * '<S238>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant1'
 * '<S239>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant2'
 * '<S240>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant3'
 * '<S241>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant4'
 * '<S242>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant5'
 * '<S243>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant6'
 * '<S244>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem15/Compare To Constant7'
 * '<S245>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant'
 * '<S246>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant1'
 * '<S247>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant2'
 * '<S248>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant3'
 * '<S249>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant4'
 * '<S250>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant5'
 * '<S251>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant6'
 * '<S252>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem2/Compare To Constant7'
 * '<S253>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant'
 * '<S254>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant1'
 * '<S255>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant2'
 * '<S256>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant3'
 * '<S257>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant4'
 * '<S258>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant5'
 * '<S259>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant6'
 * '<S260>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem3/Compare To Constant7'
 * '<S261>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant'
 * '<S262>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant1'
 * '<S263>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant2'
 * '<S264>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant3'
 * '<S265>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant4'
 * '<S266>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant5'
 * '<S267>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant6'
 * '<S268>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem4/Compare To Constant7'
 * '<S269>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant'
 * '<S270>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant1'
 * '<S271>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant2'
 * '<S272>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant3'
 * '<S273>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant4'
 * '<S274>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant5'
 * '<S275>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant6'
 * '<S276>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem5/Compare To Constant7'
 * '<S277>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant'
 * '<S278>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant1'
 * '<S279>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant2'
 * '<S280>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant3'
 * '<S281>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant4'
 * '<S282>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant5'
 * '<S283>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant6'
 * '<S284>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem6/Compare To Constant7'
 * '<S285>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant'
 * '<S286>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant1'
 * '<S287>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant2'
 * '<S288>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant3'
 * '<S289>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant4'
 * '<S290>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant5'
 * '<S291>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant6'
 * '<S292>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem7/Compare To Constant7'
 * '<S293>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant'
 * '<S294>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant1'
 * '<S295>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant2'
 * '<S296>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant3'
 * '<S297>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant4'
 * '<S298>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant5'
 * '<S299>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant6'
 * '<S300>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem8/Compare To Constant7'
 * '<S301>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant'
 * '<S302>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant1'
 * '<S303>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant2'
 * '<S304>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant3'
 * '<S305>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant4'
 * '<S306>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant5'
 * '<S307>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant6'
 * '<S308>' : 'BEML_EMU/BEML_EMU/DoorsInterface/DoorsInputAdapter/VehicleInputAdapter/DoorsInputs/Subsystem/Subsystem9/Compare To Constant7'
 * '<S309>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter'
 * '<S310>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig'
 * '<S311>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter'
 * '<S312>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/ExtractConfig/ExtractConfig'
 * '<S313>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/CustomDragForces'
 * '<S314>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/For Each Subsystem'
 * '<S315>' : 'BEML_EMU/BEML_EMU/DynamicsInterface/DynamicsInputAdapter/VehicleInputAdapter/For Each Subsystem1'
 * '<S316>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter'
 * '<S317>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig'
 * '<S318>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter'
 * '<S319>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/ExtractConfig/ExtractConfig'
 * '<S320>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/CouplingSignals'
 * '<S321>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/DoorsSignals'
 * '<S322>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/DynamicsSignals'
 * '<S323>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals'
 * '<S324>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/OverrideAssignment'
 * '<S325>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/PantographSignals'
 * '<S326>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/PneumaticsSignals'
 * '<S327>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/SignSignals'
 * '<S328>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/TCMSSignals'
 * '<S329>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/TractionSignals'
 * '<S330>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/CouplingSignals/For Each Subsystem'
 * '<S331>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/FIXME'
 * '<S332>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Overrides AutoPowerOn'
 * '<S333>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Overrides AutoPowerOn/Detect Increase1'
 * '<S334>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/IOSignals/Overrides AutoPowerOn/SR Latch - Reset Priority1'
 * '<S335>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/PneumaticsSignals/For Each Subsystem'
 * '<S336>' : 'BEML_EMU/BEML_EMU/ElectricalInterface/ElectricalInputAdapter/VehicleInputAdapter/TractionSignals/Subsystem'
 * '<S337>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter'
 * '<S338>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig'
 * '<S339>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter'
 * '<S340>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/ExtractConfig/ExtractConfig'
 * '<S341>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/ControlSignals'
 * '<S342>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/ElectricalSignals'
 * '<S343>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/EnvironmentSignals'
 * '<S344>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/FaultsAssignment'
 * '<S345>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/OverrideAssignment'
 * '<S346>' : 'BEML_EMU/BEML_EMU/PantographInterface/PantographInputAdapter/VehicleInputAdapter/PneumaticsSignals'
 * '<S347>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter'
 * '<S348>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig'
 * '<S349>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter'
 * '<S350>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/ExtractConfig/ExtractConfig'
 * '<S351>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/ElectricalSignals'
 * '<S352>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PhysicalSignals'
 * '<S353>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates'
 * '<S354>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/ElectricalSignals/For Each Subsystem'
 * '<S355>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PhysicalSignals/Subsystem'
 * '<S356>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Orientation Swap'
 * '<S357>' : 'BEML_EMU/BEML_EMU/PneumaticsInterface/PneumaticsInputAdapter/VehicleInputAdapter/PneumaticControlStates/Orientation Swap/Orientation Swap'
 * '<S358>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter'
 * '<S359>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig'
 * '<S360>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter'
 * '<S361>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/ExtractConfig/ExtractConfig'
 * '<S362>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/BrakeSignals'
 * '<S363>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CBTC'
 * '<S364>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CouplingSignals'
 * '<S365>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DisplayControlSignals'
 * '<S366>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DoorsSignals'
 * '<S367>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DynamicSignals'
 * '<S368>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals'
 * '<S369>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/EnvironmentSignals'
 * '<S370>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/IOSignals'
 * '<S371>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PantographSignals'
 * '<S372>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PneumaticsSignals'
 * '<S373>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/TractionSignals'
 * '<S374>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/BrakeSignals/For Each Subsystem'
 * '<S375>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/CouplingSignals/Subsystem'
 * '<S376>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/DoorsSignals/For Each Subsystem'
 * '<S377>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Detect Decrease'
 * '<S378>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/Detect Increase'
 * '<S379>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/ElectricalSignals/SR Latch - Reset Priority'
 * '<S380>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/PneumaticsSignals/For Each Subsystem'
 * '<S381>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/TractionSignals/For Each Subsystem'
 * '<S382>' : 'BEML_EMU/BEML_EMU/TCMSInterface/TCMSInputAdapter/VehicleInputAdapter/TractionSignals/Subsystem'
 * '<S383>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter'
 * '<S384>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig'
 * '<S385>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter'
 * '<S386>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/ExtractConfig/ExtractConfig'
 * '<S387>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Compare To Zero1'
 * '<S388>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Compare To Zero2'
 * '<S389>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ComputerSignals'
 * '<S390>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Difference1'
 * '<S391>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/Difference2'
 * '<S392>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ElectricalSignals'
 * '<S393>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals'
 * '<S394>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ComputerSignals/For Each Subsystem'
 * '<S395>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/ElectricalSignals/BogieAssignment'
 * '<S396>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals'
 * '<S397>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals/Bogie1'
 * '<S398>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals/Bogie2'
 * '<S399>' : 'BEML_EMU/BEML_EMU/TractionInterface/TractionInputAdapter/VehicleInputAdapter/PhysicalSignals/BogieSignals/For Each Subsystem'
 * '<S400>' : 'BEML_EMU/InputsInterface/FaultHandler'
 * '<S401>' : 'BEML_EMU/InputsInterface/IOControlsInterface'
 * '<S402>' : 'BEML_EMU/InputsInterface/TrainProcessing'
 * '<S403>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing'
 * '<S404>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem'
 * '<S405>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/DoorFaults'
 * '<S406>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/ElectricalFaults'
 * '<S407>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PantographFaults'
 * '<S408>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults'
 * '<S409>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem'
 * '<S410>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/TCMSFaults'
 * '<S411>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/TractionFaults'
 * '<S412>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/VehicleFaultStatesCompile'
 * '<S413>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/ElectricalFaults/FIXME'
 * '<S414>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Compare To Zero'
 * '<S415>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Change'
 * '<S416>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease'
 * '<S417>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease1'
 * '<S418>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Decrease2'
 * '<S419>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Increase'
 * '<S420>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/Detect Increase1'
 * '<S421>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/SR Latch - Reset Priority'
 * '<S422>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/PneumaticsFaults/SR Latch - Reset Priority1'
 * '<S423>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault'
 * '<S424>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1'
 * '<S425>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2'
 * '<S426>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3'
 * '<S427>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine'
 * '<S428>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1'
 * '<S429>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10'
 * '<S430>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11'
 * '<S431>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12'
 * '<S432>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13'
 * '<S433>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14'
 * '<S434>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15'
 * '<S435>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16'
 * '<S436>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17'
 * '<S437>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18'
 * '<S438>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19'
 * '<S439>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2'
 * '<S440>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20'
 * '<S441>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21'
 * '<S442>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3'
 * '<S443>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4'
 * '<S444>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5'
 * '<S445>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6'
 * '<S446>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7'
 * '<S447>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8'
 * '<S448>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9'
 * '<S449>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem'
 * '<S450>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem1'
 * '<S451>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem2'
 * '<S452>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem3'
 * '<S453>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem4'
 * '<S454>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem5'
 * '<S455>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem6'
 * '<S456>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem7'
 * '<S457>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem8'
 * '<S458>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/Subsystem9'
 * '<S459>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/Chart'
 * '<S460>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest'
 * '<S461>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/SR Latch - Set Priority2'
 * '<S462>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Increment'
 * '<S463>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Momentary'
 * '<S464>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault/ControlStateRequest/Subsystem'
 * '<S465>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/Chart'
 * '<S466>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest'
 * '<S467>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/SR Latch - Set Priority2'
 * '<S468>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Increment'
 * '<S469>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Momentary'
 * '<S470>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault1/ControlStateRequest/Subsystem'
 * '<S471>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/Chart'
 * '<S472>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest'
 * '<S473>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/SR Latch - Set Priority2'
 * '<S474>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Increment'
 * '<S475>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Momentary'
 * '<S476>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault2/ControlStateRequest/Subsystem'
 * '<S477>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/Chart'
 * '<S478>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest'
 * '<S479>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/SR Latch - Set Priority2'
 * '<S480>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Increment'
 * '<S481>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Momentary'
 * '<S482>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/ControlStateFault3/ControlStateRequest/Subsystem'
 * '<S483>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/Compare To Constant'
 * '<S484>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/Compare To Constant1'
 * '<S485>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic'
 * '<S486>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/IRQRequestStateMachine'
 * '<S487>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/SR Latch - Reset Priority'
 * '<S488>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Increment'
 * '<S489>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Momentary'
 * '<S490>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S491>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/Compare To Constant'
 * '<S492>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/Compare To Constant1'
 * '<S493>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic'
 * '<S494>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/IRQRequestStateMachine'
 * '<S495>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/SR Latch - Reset Priority'
 * '<S496>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Increment'
 * '<S497>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Momentary'
 * '<S498>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine1/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S499>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/Compare To Constant'
 * '<S500>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/Compare To Constant1'
 * '<S501>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic'
 * '<S502>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/IRQRequestStateMachine'
 * '<S503>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/SR Latch - Reset Priority'
 * '<S504>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Increment'
 * '<S505>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Momentary'
 * '<S506>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine10/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S507>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/Compare To Constant'
 * '<S508>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/Compare To Constant1'
 * '<S509>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic'
 * '<S510>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/IRQRequestStateMachine'
 * '<S511>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/SR Latch - Reset Priority'
 * '<S512>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Increment'
 * '<S513>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Momentary'
 * '<S514>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine11/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S515>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/Compare To Constant'
 * '<S516>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/Compare To Constant1'
 * '<S517>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic'
 * '<S518>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/IRQRequestStateMachine'
 * '<S519>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/SR Latch - Reset Priority'
 * '<S520>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Increment'
 * '<S521>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Momentary'
 * '<S522>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine12/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S523>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/Compare To Constant'
 * '<S524>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/Compare To Constant1'
 * '<S525>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic'
 * '<S526>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/IRQRequestStateMachine'
 * '<S527>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/SR Latch - Reset Priority'
 * '<S528>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Increment'
 * '<S529>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Momentary'
 * '<S530>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine13/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S531>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/Compare To Constant'
 * '<S532>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/Compare To Constant1'
 * '<S533>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic'
 * '<S534>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/IRQRequestStateMachine'
 * '<S535>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/SR Latch - Reset Priority'
 * '<S536>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Increment'
 * '<S537>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Momentary'
 * '<S538>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine14/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S539>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/Compare To Constant'
 * '<S540>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/Compare To Constant1'
 * '<S541>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic'
 * '<S542>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/IRQRequestStateMachine'
 * '<S543>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/SR Latch - Reset Priority'
 * '<S544>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Increment'
 * '<S545>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Momentary'
 * '<S546>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine15/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S547>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/Compare To Constant'
 * '<S548>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/Compare To Constant1'
 * '<S549>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic'
 * '<S550>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/IRQRequestStateMachine'
 * '<S551>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/SR Latch - Reset Priority'
 * '<S552>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Increment'
 * '<S553>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Momentary'
 * '<S554>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine16/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S555>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/Compare To Constant'
 * '<S556>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/Compare To Constant1'
 * '<S557>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic'
 * '<S558>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/IRQRequestStateMachine'
 * '<S559>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/SR Latch - Reset Priority'
 * '<S560>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Increment'
 * '<S561>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Momentary'
 * '<S562>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine17/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S563>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/Compare To Constant'
 * '<S564>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/Compare To Constant1'
 * '<S565>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic'
 * '<S566>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/IRQRequestStateMachine'
 * '<S567>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/SR Latch - Reset Priority'
 * '<S568>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Increment'
 * '<S569>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Momentary'
 * '<S570>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine18/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S571>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/Compare To Constant'
 * '<S572>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/Compare To Constant1'
 * '<S573>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic'
 * '<S574>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/IRQRequestStateMachine'
 * '<S575>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/SR Latch - Reset Priority'
 * '<S576>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Increment'
 * '<S577>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Momentary'
 * '<S578>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine19/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S579>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/Compare To Constant'
 * '<S580>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/Compare To Constant1'
 * '<S581>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic'
 * '<S582>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/IRQRequestStateMachine'
 * '<S583>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/SR Latch - Reset Priority'
 * '<S584>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Increment'
 * '<S585>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Momentary'
 * '<S586>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine2/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S587>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/Compare To Constant'
 * '<S588>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/Compare To Constant1'
 * '<S589>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic'
 * '<S590>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/IRQRequestStateMachine'
 * '<S591>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/SR Latch - Reset Priority'
 * '<S592>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Increment'
 * '<S593>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Momentary'
 * '<S594>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine20/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S595>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/Compare To Constant'
 * '<S596>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/Compare To Constant1'
 * '<S597>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic'
 * '<S598>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/IRQRequestStateMachine'
 * '<S599>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/SR Latch - Reset Priority'
 * '<S600>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Increment'
 * '<S601>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Momentary'
 * '<S602>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine21/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S603>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/Compare To Constant'
 * '<S604>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/Compare To Constant1'
 * '<S605>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic'
 * '<S606>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/IRQRequestStateMachine'
 * '<S607>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/SR Latch - Reset Priority'
 * '<S608>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Increment'
 * '<S609>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Momentary'
 * '<S610>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine3/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S611>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/Compare To Constant'
 * '<S612>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/Compare To Constant1'
 * '<S613>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic'
 * '<S614>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/IRQRequestStateMachine'
 * '<S615>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/SR Latch - Reset Priority'
 * '<S616>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Increment'
 * '<S617>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Momentary'
 * '<S618>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine4/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S619>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/Compare To Constant'
 * '<S620>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/Compare To Constant1'
 * '<S621>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic'
 * '<S622>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/IRQRequestStateMachine'
 * '<S623>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/SR Latch - Reset Priority'
 * '<S624>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Increment'
 * '<S625>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Momentary'
 * '<S626>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine5/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S627>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/Compare To Constant'
 * '<S628>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/Compare To Constant1'
 * '<S629>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic'
 * '<S630>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/IRQRequestStateMachine'
 * '<S631>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/SR Latch - Reset Priority'
 * '<S632>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Increment'
 * '<S633>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Momentary'
 * '<S634>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine6/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S635>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/Compare To Constant'
 * '<S636>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/Compare To Constant1'
 * '<S637>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic'
 * '<S638>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/IRQRequestStateMachine'
 * '<S639>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/SR Latch - Reset Priority'
 * '<S640>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Increment'
 * '<S641>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Momentary'
 * '<S642>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine7/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S643>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/Compare To Constant'
 * '<S644>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/Compare To Constant1'
 * '<S645>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic'
 * '<S646>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/IRQRequestStateMachine'
 * '<S647>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/SR Latch - Reset Priority'
 * '<S648>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Increment'
 * '<S649>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Momentary'
 * '<S650>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine8/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S651>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/Compare To Constant'
 * '<S652>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/Compare To Constant1'
 * '<S653>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic'
 * '<S654>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/IRQRequestStateMachine'
 * '<S655>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/SR Latch - Reset Priority'
 * '<S656>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Increment'
 * '<S657>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Momentary'
 * '<S658>' : 'BEML_EMU/InputsInterface/FaultHandler/Subsystem/Subsystem/IRQStateMachine9/ControlStateRequestLogic/Triggered Pulse Generator1'
 * '<S659>' : 'BEML_EMU/InputsInterface/IOControlsInterface/For Each Subsystem'
 * '<S660>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests'
 * '<S661>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Compare To Zero'
 * '<S662>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Compare To Zero1'
 * '<S663>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Folding_Interlocks'
 * '<S664>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem'
 * '<S665>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem1'
 * '<S666>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem2'
 * '<S667>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Unfolding_interlocks'
 * '<S668>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant1'
 * '<S669>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant2'
 * '<S670>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant3'
 * '<S671>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant4'
 * '<S672>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant5'
 * '<S673>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem/Compare To Constant6'
 * '<S674>' : 'BEML_EMU/InputsInterface/IOControlsInterface/InhibitsAndInternalRequests/Subsystem1/Compare To Zero'
 * '<S675>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface'
 * '<S676>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/Enumerated Voltages'
 * '<S677>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface'
 * '<S678>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleEnabled'
 * '<S679>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/Enumerated Voltages/Enumerated Voltages'
 * '<S680>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignBrakes'
 * '<S681>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors'
 * '<S682>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical'
 * '<S683>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment'
 * '<S684>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto'
 * '<S685>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics'
 * '<S686>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction'
 * '<S687>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Common'
 * '<S688>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/Dynamics'
 * '<S689>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig'
 * '<S690>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment1'
 * '<S691>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment2'
 * '<S692>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment3'
 * '<S693>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignDoors/VehicleEquipment4'
 * '<S694>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment'
 * '<S695>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1'
 * '<S696>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment2'
 * '<S697>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3'
 * '<S698>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem'
 * '<S699>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem1'
 * '<S700>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment/If Action Subsystem2'
 * '<S701>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem'
 * '<S702>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem1'
 * '<S703>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment1/If Action Subsystem2'
 * '<S704>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem'
 * '<S705>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem1'
 * '<S706>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignElectrical/VehicleEquipment3/If Action Subsystem2'
 * '<S707>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment'
 * '<S708>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment1'
 * '<S709>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment2'
 * '<S710>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignEquipment/VehicleEquipment3'
 * '<S711>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment'
 * '<S712>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment1'
 * '<S713>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment2'
 * '<S714>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPanto/VehicleEquipment3'
 * '<S715>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment'
 * '<S716>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment1'
 * '<S717>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment2'
 * '<S718>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignPneumatics/VehicleEquipment3'
 * '<S719>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment'
 * '<S720>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment1'
 * '<S721>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment2'
 * '<S722>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/AssignTraction/VehicleEquipment3'
 * '<S723>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/Subsystem'
 * '<S724>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf'
 * '<S725>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant'
 * '<S726>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant1'
 * '<S727>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant2'
 * '<S728>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant4'
 * '<S729>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant5'
 * '<S730>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant8'
 * '<S731>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleConfigInterface/LocationConfig/UnitConf/Compare To Constant9'
 * '<S732>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleEnabled/Subsystem'
 * '<S733>' : 'BEML_EMU/InputsInterface/VehicleConfigProcessing/VehicleConfigInterface/VehicleEnabled/Subsystem1'
 * '<S734>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface'
 * '<S735>' : 'BEML_EMU/SimulatorSystems/Dynamics'
 * '<S736>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface'
 * '<S737>' : 'BEML_EMU/SimulatorSystems/Subsystem'
 * '<S738>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1'
 * '<S739>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Detect Decrease'
 * '<S740>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/For Each Subsystem'
 * '<S741>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/For Each Subsystem1'
 * '<S742>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/For Each Subsystem2'
 * '<S743>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Subsystem1'
 * '<S744>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Subsystem1/Compare To Constant1'
 * '<S745>' : 'BEML_EMU/SimulatorSystems/AudioSystemInterface/Subsystem1/Subsystem1/Detect Increase'
 * '<S746>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring'
 * '<S747>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/VehicleLevelScoring'
 * '<S748>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem'
 * '<S749>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem1'
 * '<S750>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem'
 * '<S751>' : 'BEML_EMU/SimulatorSystems/ScoringSystemInterface/TrainLevelScoring/For Each Subsystem/Subsystem/Subsystem'
 * '<S752>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter'
 * '<S753>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface'
 * '<S754>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter'
 * '<S755>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/OnRoughTrackFix'
 * '<S756>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/BinarySwitch'
 * '<S757>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Effects In Processing'
 * '<S758>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Environment Dynamics In Processing'
 * '<S759>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Tuning In Processing'
 * '<S760>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing'
 * '<S761>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Effects In Processing/FIXME'
 * '<S762>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations'
 * '<S763>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/SafeDivide'
 * '<S764>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM'
 * '<S765>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Heave Matrix'
 * '<S766>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/Coordinate Transformations/Orientation DCM/Pitch Matrix'
 * '<S767>' : 'BEML_EMU/SimulatorSystems/Subsystem/Input Adapter/MotionBaseInputAdapter/Vehicle Dynamics In Processing/SafeDivide/Replace Zeros'
 * '<S768>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle'
 * '<S769>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/StopConditionLogging'
 * '<S770>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter'
 * '<S771>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing'
 * '<S772>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/SafeMotionBaseOut'
 * '<S773>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects'
 * '<S774>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/GravitationalAcceleration'
 * '<S775>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments'
 * '<S776>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Motion Cutout'
 * '<S777>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits'
 * '<S778>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts'
 * '<S779>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt'
 * '<S780>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1'
 * '<S781>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2'
 * '<S782>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3'
 * '<S783>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Detect Increase'
 * '<S784>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration'
 * '<S785>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt/Jolt Duration/Count to 0'
 * '<S786>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Detect Increase'
 * '<S787>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration'
 * '<S788>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt1/Jolt Duration/Count to 0'
 * '<S789>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Detect Increase'
 * '<S790>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration'
 * '<S791>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt2/Jolt Duration/Count to 0'
 * '<S792>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Detect Increase'
 * '<S793>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration'
 * '<S794>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Dynamic Effects/Acceleration Jolts/Jolt3/Jolt Duration/Count to 0'
 * '<S795>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/GravitationalAcceleration/DCM Invert'
 * '<S796>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/GravitationalAcceleration/DCM Multiply'
 * '<S797>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment'
 * '<S798>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel'
 * '<S799>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection'
 * '<S800>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/NoTrackFeel'
 * '<S801>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel'
 * '<S802>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator'
 * '<S803>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/AmplitudeOverride'
 * '<S804>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise'
 * '<S805>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Band-Limited White Noise1'
 * '<S806>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride'
 * '<S807>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order'
 * '<S808>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order'
 * '<S809>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1'
 * '<S810>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/Sample and Hold'
 * '<S811>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor'
 * '<S812>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Compare To Zero'
 * '<S813>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Detect Increase'
 * '<S814>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed'
 * '<S815>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter'
 * '<S816>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/HP 2nd order/LP Filter1'
 * '<S817>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter'
 * '<S818>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order/LP Filter1'
 * '<S819>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter'
 * '<S820>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/LP 2nd order1/LP Filter1'
 * '<S821>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/DegradedTrackFeel/DegradedRoughnessGenerator/VelocityFactor/Tuning Factor'
 * '<S822>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/EffectSelection/Compare To Zero'
 * '<S823>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator'
 * '<S824>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/AmplitudeOverride'
 * '<S825>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise'
 * '<S826>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Band-Limited White Noise1'
 * '<S827>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride'
 * '<S828>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order'
 * '<S829>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order'
 * '<S830>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1'
 * '<S831>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/Sample and Hold'
 * '<S832>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor'
 * '<S833>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Compare To Zero'
 * '<S834>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Detect Increase'
 * '<S835>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/FrequencyOverride/Triggered Pulse Generator Variable Speed'
 * '<S836>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter'
 * '<S837>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/HP 2nd order/LP Filter1'
 * '<S838>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter'
 * '<S839>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order/LP Filter1'
 * '<S840>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter'
 * '<S841>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/LP 2nd order1/LP Filter1'
 * '<S842>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/ManualAdjustments/ManualPositionAdjustment/StandardTrackFeel/StandardRoughnessGenerator/VelocityFactor/Tuning Factor'
 * '<S843>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Motion Cutout/Above 20 Degrees'
 * '<S844>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing'
 * '<S845>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing'
 * '<S846>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain'
 * '<S847>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing'
 * '<S848>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing'
 * '<S849>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/First Order Low Pass Filter'
 * '<S850>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/LPFConstantTuning'
 * '<S851>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/Saturation Dynamic'
 * '<S852>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularAccelerationProcessing/SaturationTuning'
 * '<S853>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/First Order Low Pass Filter'
 * '<S854>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/LPFConstantTuning'
 * '<S855>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/Saturation Dynamic'
 * '<S856>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/AngularVelocityProcessing/SaturationTuning'
 * '<S857>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit'
 * '<S858>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/CollisionGain/TimerOffDelay NoInit/Count to 0'
 * '<S859>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/First Order Low Pass Filter'
 * '<S860>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/LPFConstantTuning'
 * '<S861>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/Saturation Dynamic'
 * '<S862>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearAccelerationProcessing/SaturationTuning'
 * '<S863>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/First Order Low Pass Filter'
 * '<S864>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/LPFConstantTuning'
 * '<S865>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/Saturation Dynamic'
 * '<S866>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/MotionBasePerVehicle/MotionBaseAdapter/MotionBaseProcessing/Safety Limits/LinearVelocityProcessing/SaturationTuning'
 * '<S867>' : 'BEML_EMU/SimulatorSystems/Subsystem/MotionBaseAdaptorInterface/StopConditionLogging/Log On Stop Motion'
 */
#endif                                 /* RTW_HEADER_BEML_EMU_h_ */
