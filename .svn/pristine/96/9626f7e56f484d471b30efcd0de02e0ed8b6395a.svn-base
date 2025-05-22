/*
 * Code generation for system model 'DoorSystem'
 * For more details, see corresponding source file DoorSystem.c
 *
 */

#ifndef RTW_HEADER_DoorSystem_h_
#define RTW_HEADER_DoorSystem_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef DoorSystem_COMMON_INCLUDES_
# define DoorSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* DoorSystem_COMMON_INCLUDES_ */

#include "DoorSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals for system '<S31>/DoorOpenDelay' */
typedef struct {
  boolean_T Compare;                   /* '<S72>/Compare' */
} B_DoorOpenDelay_DoorSystem_T;

/* Block states (default storage) for system '<S31>/DoorOpenDelay' */
typedef struct {
  real_T Timer_DSTATE;                 /* '<S68>/Timer' */
  int8_T Timer_PrevResetState;         /* '<S68>/Timer' */
} DW_DoorOpenDelay_DoorSystem_T;

/* Block signals for system '<S35>/LeadingEdgePulseTunable' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S39>/Logical Operator1' */
} B_LeadingEdgePulseTunable_DoorSystem_T;

/* Block states (default storage) for system '<S35>/LeadingEdgePulseTunable' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S39>/Discrete-Time Integrator' */
  boolean_T DelayInput1_DSTATE;        /* '<S38>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S39>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S39>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S39>/IC' */
} DW_LeadingEdgePulseTunable_DoorSystem_T;

/* Block signals for system '<S9>/DoorSystem' */
typedef struct {
  boolean_T OpenCMD;                   /* '<S33>/Chart' */
  boolean_T CloseCMD;                  /* '<S33>/Chart' */
  boolean_T ResetOtherCommands;        /* '<S33>/Chart' */
  boolean_T MaxOpenAttempts;           /* '<S33>/Chart' */
  boolean_T MaxCloseAttempts;          /* '<S33>/Chart' */
  B_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable1;/* '<S35>/LeadingEdgePulseTunable1' */
  B_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable;/* '<S35>/LeadingEdgePulseTunable' */
  B_DoorOpenDelay_DoorSystem_T DoorCloseDelay;/* '<S31>/DoorCloseDelay' */
  B_DoorOpenDelay_DoorSystem_T DoorOpenDelay;/* '<S31>/DoorOpenDelay' */
} B_CoreSubsys_DoorSystem_ca_T;

/* Block states (default storage) for system '<S9>/DoorSystem' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S16>/Delay Input1' */
  real_T UnitDelay2_DSTATE;            /* '<S10>/Unit Delay2' */
  real_T DelayInput1_DSTATE_l;         /* '<S81>/Delay Input1' */
  real_T DelayInput1_DSTATE_o;         /* '<S83>/Delay Input1' */
  real_T DelayInput1_DSTATE_g;         /* '<S84>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S82>/Delay Input1' */
  real_T UnitDelay1_DSTATE;            /* '<S18>/Unit Delay1' */
  real_T DelayInput1_DSTATE_c;         /* '<S93>/Delay Input1' */
  real_T DelayInput1_DSTATE_ly;        /* '<S94>/Delay Input1' */
  real_T ObstaclePosition;             /* '<S33>/Chart' */
  real_T OpenAttempt;                  /* '<S33>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S33>/Chart' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S17>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_lq;     /* '<S60>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S10>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S61>/Delay Input1' */
  boolean_T UnitDelay_DSTATE;          /* '<S13>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S10>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_jd;     /* '<S73>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S74>/Delay Input1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S10>/Unit Delay3' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S47>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_md;     /* '<S48>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S49>/Delay Input1' */
  int8_T CloseAttempt;                 /* '<S33>/Chart' */
  uint8_T is_active_c1_DoorSystem;     /* '<S33>/Chart' */
  uint8_T is_c1_DoorSystem;            /* '<S33>/Chart' */
  uint8_T is_Active;                   /* '<S33>/Chart' */
  uint8_T is_Active1;                  /* '<S33>/Chart' */
  boolean_T Memory_PreviousInput;      /* '<S62>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S64>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S18>/IC' */
  boolean_T Memory_PreviousInput_p;    /* '<S76>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S75>/Memory' */
  boolean_T Memory_PreviousInput_bz;   /* '<S86>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S85>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S51>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S52>/Memory' */
  boolean_T Memory_PreviousInput_b2;   /* '<S53>/Memory' */
  DW_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable1;/* '<S35>/LeadingEdgePulseTunable1' */
  DW_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable;/* '<S35>/LeadingEdgePulseTunable' */
  DW_DoorOpenDelay_DoorSystem_T DoorCloseDelay;/* '<S31>/DoorCloseDelay' */
  DW_DoorOpenDelay_DoorSystem_T DoorOpenDelay;/* '<S31>/DoorOpenDelay' */
} DW_CoreSubsys_DoorSystem_fw_T;

/* Block signals for system '<S4>/ForEachDoor' */
typedef struct {
  BD_DoorSystem_Out_Door ImpAsg_InsertedFor_DoorOut_at_inport_0[2];/* '<S10>/DoorOutputsPack' */
  boolean_T AND;                       /* '<S9>/AND' */
  B_CoreSubsys_DoorSystem_ca_T CoreSubsys[2];/* '<S9>/DoorSystem' */
} B_CoreSubsys_DoorSystem_c_T;

/* Block states (default storage) for system '<S4>/ForEachDoor' */
typedef struct {
  boolean_T DoorLogic_MODE;            /* '<S7>/DoorLogic' */
  DW_CoreSubsys_DoorSystem_fw_T CoreSubsys[2];/* '<S9>/DoorSystem' */
} DW_CoreSubsys_DoorSystem_f_T;

/* Block signals for system '<S100>/TimerOffDelay NoInit' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S105>/Logical Operator1' */
} B_TimerOffDelayNoInit_DoorSystem_T;

/* Block states (default storage) for system '<S100>/TimerOffDelay NoInit' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S105>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S105>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S105>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S105>/IC' */
} DW_TimerOffDelayNoInit_DoorSystem_T;

/* Block signals for system '<S5>/For Each Subsystem' */
typedef struct {
  B_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit_n;/* '<S99>/TimerOffDelay NoInit' */
  B_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S100>/TimerOffDelay NoInit' */
} B_CoreSubsys_DoorSystem_caua_T;

/* Block states (default storage) for system '<S5>/For Each Subsystem' */
typedef struct {
  boolean_T DelayInput1_DSTATE;        /* '<S101>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S104>/Delay Input1' */
  DW_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit_n;/* '<S99>/TimerOffDelay NoInit' */
  DW_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S100>/TimerOffDelay NoInit' */
} DW_CoreSubsys_DoorSystem_fwu4_T;

/* Block signals for system '<Root>/DoorSystemPerCar' */
typedef struct {
  BD_DoorSystem_Out_Vehicle BusCreator1;/* '<S6>/Bus Creator1' */
  BD_DoorSystem_In_Vehicle BusAssignment;/* '<S5>/Bus Assignment' */
  B_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit2;/* '<S108>/TimerOnDelay NoInit2' */
  B_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit1;/* '<S108>/TimerOnDelay NoInit1' */
  B_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit2;/* '<S116>/TimerOffDelay NoInit2' */
  B_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit1;/* '<S116>/TimerOffDelay NoInit1' */
  B_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S116>/TimerOffDelay NoInit' */
  B_CoreSubsys_DoorSystem_caua_T CoreSubsys_pn[8];/* '<S5>/For Each Subsystem' */
  B_CoreSubsys_DoorSystem_c_T CoreSubsys[8];/* '<S4>/ForEachDoor' */
} B_CoreSubsys_DoorSystem_T;

/* Block states (default storage) for system '<Root>/DoorSystemPerCar' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S124>/Delay Input1' */
  real_T DelayInput1_DSTATE_j;         /* '<S123>/Delay Input1' */
  real_T DelayInput1_DSTATE_h;         /* '<S125>/Delay Input1' */
  real_T UnitDelay1_DSTATE;            /* '<S127>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE;          /* '<S116>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S110>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S108>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE_h3;     /* '<S126>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S108>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_e;      /* '<S111>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ej;     /* '<S112>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ni;     /* '<S114>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S113>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_hl;     /* '<S115>/Delay Input1' */
  boolean_T IC_FirstOutputTime;        /* '<S127>/IC' */
  boolean_T Memory_PreviousInput;      /* '<S117>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S118>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S119>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S120>/Memory' */
  boolean_T EnabledVehicles_MODE;      /* '<S1>/EnabledVehicles' */
  DW_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit2;/* '<S108>/TimerOnDelay NoInit2' */
  DW_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit1;/* '<S108>/TimerOnDelay NoInit1' */
  DW_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit2;/* '<S116>/TimerOffDelay NoInit2' */
  DW_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit1;/* '<S116>/TimerOffDelay NoInit1' */
  DW_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S116>/TimerOffDelay NoInit' */
  DW_CoreSubsys_DoorSystem_fwu4_T CoreSubsys_pn[8];/* '<S5>/For Each Subsystem' */
  DW_CoreSubsys_DoorSystem_f_T CoreSubsys[8];/* '<S4>/ForEachDoor' */
} DW_CoreSubsys_DoorSystem_T;

/* Block signals for model 'DoorSystem' */
typedef struct {
  BD_DoorSystem_In_Vehicle_TrainWires UnitDelay[8];/* '<Root>/Unit Delay' */
  B_CoreSubsys_DoorSystem_T CoreSubsys[8];/* '<Root>/DoorSystemPerCar' */
} B_DoorSystem_c_T;

/* Block states (default storage) for model 'DoorSystem' */
typedef struct {
  BD_DoorSystem_In_Vehicle_TrainWires UnitDelay_DSTATE[8];/* '<Root>/Unit Delay' */
  DW_CoreSubsys_DoorSystem_T CoreSubsys[8];/* '<Root>/DoorSystemPerCar' */
} DW_DoorSystem_f_T;

/* Parameters for system: '<S31>/DoorClose' */
struct P_DoorClose_DoorSystem_T_ {
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S65>/Constant'
                                        */
};

/* Parameters for system: '<S31>/DoorOpenDelay' */
struct P_DoorOpenDelay_DoorSystem_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T Timer_gainval;                /* Computed Parameter: Timer_gainval
                                        * Referenced by: '<S68>/Timer'
                                        */
  real_T Timer_IC;                     /* Expression: 0
                                        * Referenced by: '<S68>/Timer'
                                        */
  real_T Timer_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S68>/Timer'
                                        */
};

/* Parameters for system: '<S50>/If Action Subsystem1' */
struct P_IfActionSubsystem1_DoorSystem_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S55>/Constant1'
                                        */
};

/* Parameters for system: '<S35>/LeadingEdgePulseTunable' */
struct P_LeadingEdgePulseTunable_DoorSystem_T_ {
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S38>/Delay Input1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S39>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S39>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S39>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S39>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S9>/DoorSystem' */
struct P_CoreSubsys_DoorSystem_gm_T_ {
  real_T ObstacleDetectionFunctionality_MoveAwayFromObstacle;
          /* Mask Parameter: ObstacleDetectionFunctionality_MoveAwayFromObstacle
           * Referenced by: '<S33>/Chart'
           */
  real_T ObstacleDetectionFunctionality_NumOfClosingAttempts;
          /* Mask Parameter: ObstacleDetectionFunctionality_NumOfClosingAttempts
           * Referenced by: '<S33>/Chart'
           */
  real_T ObstacleDetectionFunctionality_NumOfOpeningAttempts;
          /* Mask Parameter: ObstacleDetectionFunctionality_NumOfOpeningAttempts
           * Referenced by: '<S33>/Chart'
           */
  real_T ObstacleDetectionFunctionality_PauseBeforeClosingAttempt;
     /* Mask Parameter: ObstacleDetectionFunctionality_PauseBeforeClosingAttempt
      * Referenced by: '<S33>/Chart'
      */
  real_T ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt;
     /* Mask Parameter: ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt
      * Referenced by: '<S33>/Chart'
      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S12>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S80>/Constant'
                                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S79>/Constant'
                                      */
  real_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S23>/Constant'
                                    */
  real_T CompareToConstant2_const_i;
                                   /* Mask Parameter: CompareToConstant2_const_i
                                    * Referenced by: '<S24>/Constant'
                                    */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S16>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S81>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit_p;       /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S83>/Delay Input1'
                                        */
  real_T DetectIncrease1_vinit;        /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S84>/Delay Input1'
                                        */
  real_T DetectDecrease1_vinit;        /* Mask Parameter: DetectDecrease1_vinit
                                        * Referenced by: '<S82>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_i;       /* Mask Parameter: DetectDecrease_vinit_i
                                        * Referenced by: '<S93>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit_o;       /* Mask Parameter: DetectIncrease_vinit_o
                                        * Referenced by: '<S94>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S51>/Memory'
                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S52>/Memory'
                       */
  boolean_T SRLatchResetPriority2_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority2_initial_condition
                       * Referenced by: '<S53>/Memory'
                       */
  boolean_T SRLatchResetPriority_initial_condition_m;
                     /* Mask Parameter: SRLatchResetPriority_initial_condition_m
                      * Referenced by: '<S62>/Memory'
                      */
  boolean_T SRLatchResetPriority_initial_condition_k;
                     /* Mask Parameter: SRLatchResetPriority_initial_condition_k
                      * Referenced by: '<S64>/Memory'
                      */
  boolean_T MotorOpenLatch_initial_condition;
                             /* Mask Parameter: MotorOpenLatch_initial_condition
                              * Referenced by: '<S76>/Memory'
                              */
  boolean_T MotorCloseLatch_initial_condition;
                            /* Mask Parameter: MotorCloseLatch_initial_condition
                             * Referenced by: '<S75>/Memory'
                             */
  boolean_T SRLatchSetPriority2_initial_condition;
                        /* Mask Parameter: SRLatchSetPriority2_initial_condition
                         * Referenced by: '<S86>/Memory'
                         */
  boolean_T SRLatchSetPriority1_initial_condition;
                        /* Mask Parameter: SRLatchSetPriority1_initial_condition
                         * Referenced by: '<S85>/Memory'
                         */
  boolean_T DetectDecrease_vinit_f;    /* Mask Parameter: DetectDecrease_vinit_f
                                        * Referenced by: '<S47>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S48>/Delay Input1'
                                        */
  boolean_T DetectIncrease1_vinit_i;  /* Mask Parameter: DetectIncrease1_vinit_i
                                       * Referenced by: '<S49>/Delay Input1'
                                       */
  boolean_T DetectIncrease1_vinit_m;  /* Mask Parameter: DetectIncrease1_vinit_m
                                       * Referenced by: '<S17>/Delay Input1'
                                       */
  boolean_T DetectIncrease_vinit_g;    /* Mask Parameter: DetectIncrease_vinit_g
                                        * Referenced by: '<S60>/Delay Input1'
                                        */
  boolean_T DetectIncrease1_vinit_i5;/* Mask Parameter: DetectIncrease1_vinit_i5
                                      * Referenced by: '<S61>/Delay Input1'
                                      */
  boolean_T DetectDecrease_vinit_b;    /* Mask Parameter: DetectDecrease_vinit_b
                                        * Referenced by: '<S73>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_dn;  /* Mask Parameter: DetectIncrease_vinit_dn
                                       * Referenced by: '<S74>/Delay Input1'
                                       */
  BD_DoorSystem_Int_DoorControlIndicators Constant_Value;/* Computed Parameter: Constant_Value
                                                          * Referenced by: '<S44>/Constant'
                                                          */
  BD_DoorSystem_Out_Door_Audio Constant_Value_c;/* Computed Parameter: Constant_Value_c
                                                 * Referenced by: '<S87>/Constant'
                                                 */
  BD_DoorSystem_Int_DoorControlAudio Constant_Value_m;/* Computed Parameter: Constant_Value_m
                                                       * Referenced by: '<S34>/Constant'
                                                       */
  BD_DoorSystem_Out_Door_TCMS Constant_Value_ca;/* Computed Parameter: Constant_Value_ca
                                                 * Referenced by: '<S90>/Constant'
                                                 */
  BD_DoorSystem_Out_Door_OutputControlStates Constant_Value_d;/* Computed Parameter: Constant_Value_d
                                                               * Referenced by: '<S89>/Constant'
                                                               */
  BD_DoorSystem_Out_Door_TCMS_Messages Messages_Value;/* Computed Parameter: Messages_Value
                                                       * Referenced by: '<S45>/Messages'
                                                       */
  BD_DoorSystem_Out_Door_ElectricalSignals Constant_Value_co;/* Computed Parameter: Constant_Value_co
                                                              * Referenced by: '<S88>/Constant'
                                                              */
  real_T YellowON_Value;               /* Expression: 3
                                        * Referenced by: '<S45>/YellowON'
                                        */
  real_T YellowFlashing_Value;         /* Expression: 2
                                        * Referenced by: '<S45>/YellowFlashing'
                                        */
  real_T RedON_Value;                  /* Expression: 1
                                        * Referenced by: '<S45>/RedON'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S21>/Constant7'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Constant7_Value_d;            /* Expression: 0
                                        * Referenced by: '<S20>/Constant7'
                                        */
  real_T Speed_Threshold;              /* Expression: 0
                                        * Referenced by: '<S20>/Speed'
                                        */
  real_T Speed_Threshold_h;            /* Expression: 0
                                        * Referenced by: '<S21>/Speed'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S18>/Weighted Sample Time'
                                   */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 0.05
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 0.25
                                        * Referenced by: '<S13>/Constant5'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S91>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S92>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S10>/Unit Delay2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S18>/Unit Delay1'
                                        */
  boolean_T Constant_Value_e;          /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S46>/Constant'
                                        */
  boolean_T Constant_Value_i4;         /* Expression: true
                                        * Referenced by: '<S13>/Constant'
                                        */
  boolean_T UnitDelay1_InitialCondition_f;
                            /* Computed Parameter: UnitDelay1_InitialCondition_f
                             * Referenced by: '<S10>/Unit Delay1'
                             */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S13>/Unit Delay'
                                */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S18>/IC'
                                        */
  boolean_T UnitDelay_InitialCondition_k;
                             /* Computed Parameter: UnitDelay_InitialCondition_k
                              * Referenced by: '<S10>/Unit Delay'
                              */
  boolean_T UnitDelay3_InitialCondition;
                              /* Computed Parameter: UnitDelay3_InitialCondition
                               * Referenced by: '<S10>/Unit Delay3'
                               */
  int8_T Gain1_Gain;                   /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S70>/Gain1'
                                        */
  P_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable1;/* '<S35>/LeadingEdgePulseTunable1' */
  P_LeadingEdgePulseTunable_DoorSystem_T LeadingEdgePulseTunable;/* '<S35>/LeadingEdgePulseTunable' */
  P_IfActionSubsystem1_DoorSystem_T IfActionSubsystem4;/* '<S50>/If Action Subsystem4' */
  P_IfActionSubsystem1_DoorSystem_T IfActionSubsystem3;/* '<S50>/If Action Subsystem3' */
  P_IfActionSubsystem1_DoorSystem_T IfActionSubsystem2;/* '<S50>/If Action Subsystem2' */
  P_IfActionSubsystem1_DoorSystem_T IfActionSubsystem1;/* '<S50>/If Action Subsystem1' */
  P_DoorOpenDelay_DoorSystem_T DoorCloseDelay;/* '<S31>/DoorCloseDelay' */
  P_DoorOpenDelay_DoorSystem_T DoorOpenDelay;/* '<S31>/DoorOpenDelay' */
  P_DoorClose_DoorSystem_T NoMotorCommand;/* '<S31>/NoMotorCommand' */
  P_DoorClose_DoorSystem_T DoorOpen;   /* '<S31>/DoorOpen' */
  P_DoorClose_DoorSystem_T DoorClose;  /* '<S31>/DoorClose' */
};

/* Parameters for system: '<S4>/ForEachDoor' */
struct P_CoreSubsys_DoorSystem_g_T_ {
  BD_DoorSystem_Out_Door DoorOut_Y0;   /* Computed Parameter: DoorOut_Y0
                                        * Referenced by: '<S9>/DoorOut'
                                        */
  boolean_T Interlock_Y0;              /* Computed Parameter: Interlock_Y0
                                        * Referenced by: '<S9>/Interlock'
                                        */
  P_CoreSubsys_DoorSystem_gm_T CoreSubsys;/* '<S9>/DoorSystem' */
};

/* Parameters for system: '<S100>/TimerOffDelay NoInit' */
struct P_TimerOffDelayNoInit_DoorSystem_T_ {
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S105>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S106>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S105>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S105>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S105>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S105>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S105>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S105>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S5>/For Each Subsystem' */
struct P_CoreSubsys_DoorSystem_gmy0_T_ {
  boolean_T DetectDecrease_vinit;      /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S104>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S101>/Delay Input1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S96>/Switch'
                                        */
  P_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit_n;/* '<S99>/TimerOffDelay NoInit' */
  P_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S100>/TimerOffDelay NoInit' */
};

/* Parameters for system: '<Root>/DoorSystemPerCar' */
struct P_CoreSubsys_DoorSystem_T_ {
  real_T TimerOnDelayNoInit2_UpperSaturationLimit;
                     /* Mask Parameter: TimerOnDelayNoInit2_UpperSaturationLimit
                      * Referenced by: '<S108>/TimerOnDelay NoInit2'
                      */
  real_T TimerOnDelayNoInit1_UpperSaturationLimit;
                     /* Mask Parameter: TimerOnDelayNoInit1_UpperSaturationLimit
                      * Referenced by: '<S108>/TimerOnDelay NoInit1'
                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S109>/Constant'
                                       */
  real_T DetectIncrease1_vinit;        /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S124>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S123>/Delay Input1'
                                        */
  real_T DetectIncrease2_vinit;        /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S125>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S117>/Memory'
                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S118>/Memory'
                       */
  boolean_T SRLatchResetPriority2_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority2_initial_condition
                       * Referenced by: '<S119>/Memory'
                       */
  boolean_T SRLatchResetPriority3_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority3_initial_condition
                       * Referenced by: '<S120>/Memory'
                       */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S110>/Delay Input1'
                                        */
  boolean_T DetectIncrease3_vinit;     /* Mask Parameter: DetectIncrease3_vinit
                                        * Referenced by: '<S126>/Delay Input1'
                                        */
  boolean_T DetectIncrease1_vinit_n;  /* Mask Parameter: DetectIncrease1_vinit_n
                                       * Referenced by: '<S111>/Delay Input1'
                                       */
  boolean_T DetectIncrease2_vinit_a;  /* Mask Parameter: DetectIncrease2_vinit_a
                                       * Referenced by: '<S112>/Delay Input1'
                                       */
  boolean_T DetectIncrease4_vinit;     /* Mask Parameter: DetectIncrease4_vinit
                                        * Referenced by: '<S114>/Delay Input1'
                                        */
  boolean_T DetectIncrease3_vinit_d;  /* Mask Parameter: DetectIncrease3_vinit_d
                                       * Referenced by: '<S113>/Delay Input1'
                                       */
  boolean_T DetectIncrease5_vinit;     /* Mask Parameter: DetectIncrease5_vinit
                                        * Referenced by: '<S115>/Delay Input1'
                                        */
  BD_DoorSystem_Out_Vehicle DoorSystemVehicleOut_Y0;
                                  /* Computed Parameter: DoorSystemVehicleOut_Y0
                                   * Referenced by: '<S3>/DoorSystemVehicleOut'
                                   */
  BD_DoorSystem_Out_Emergency_Door Constant1_Value;/* Computed Parameter: Constant1_Value
                                                    * Referenced by: '<S6>/Constant1'
                                                    */
  BD_DoorSystem_Out_Vehicle_ElectricalSignals Constant_Value;/* Computed Parameter: Constant_Value
                                                              * Referenced by: '<S6>/Constant'
                                                              */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S116>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: -0.5
                                        * Referenced by: '<S116>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 0.5
                                        * Referenced by: '<S116>/Constant5'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S127>/Weighted Sample Time'
                                   */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S116>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S116>/Constant4'
                                        */
  real_T Constant_Value_o[8];          /* Expression: 1:MaxDoors
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real_T Constant1_Value_nk;           /* Expression: 12
                                        * Referenced by: '<S108>/Constant1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S127>/Unit Delay1'
                                        */
  real_T Constant_Value_g;             /* Expression: 12
                                        * Referenced by: '<S108>/Constant'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S116>/Unit Delay'
                                */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S127>/IC'
                                        */
  boolean_T UnitDelay1_InitialCondition_i;
                            /* Computed Parameter: UnitDelay1_InitialCondition_i
                             * Referenced by: '<S108>/Unit Delay1'
                             */
  boolean_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S108>/Unit Delay'
                              */
  boolean_T Constant_Value_c;          /* Expression: true
                                        * Referenced by: '<S116>/Constant'
                                        */
  P_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit2;/* '<S108>/TimerOnDelay NoInit2' */
  P_DoorOpenDelay_DoorSystem_T TimerOnDelayNoInit1;/* '<S108>/TimerOnDelay NoInit1' */
  P_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit2;/* '<S116>/TimerOffDelay NoInit2' */
  P_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit1;/* '<S116>/TimerOffDelay NoInit1' */
  P_TimerOffDelayNoInit_DoorSystem_T TimerOffDelayNoInit;/* '<S116>/TimerOffDelay NoInit' */
  P_CoreSubsys_DoorSystem_gmy0_T CoreSubsys_pn;/* '<S5>/For Each Subsystem' */
  P_CoreSubsys_DoorSystem_g_T CoreSubsys;/* '<S4>/ForEachDoor' */
};

/* Parameters for system: '<S2>/MakeArrayOfBuses' */
struct P_CoreSubsys_DoorSystem_gmy0og_T_ {
  BD_DoorSystem_In_Vehicle_TrainWires Constant_Value;/* Computed Parameter: Constant_Value
                                                      * Referenced by: '<S138>/Constant'
                                                      */
};

/* Parameters (default storage) */
struct P_DoorSystem_T_ {
  BD_DoorSystem_In_Vehicle_TrainWires UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<Root>/Unit Delay'
                                */
  P_CoreSubsys_DoorSystem_gmy0og_T CoreSubsys_pn;/* '<S2>/MakeArrayOfBuses' */
  P_CoreSubsys_DoorSystem_T CoreSubsys;/* '<Root>/DoorSystemPerCar' */
};

/* Real-time Model Data Structure */
struct tag_RTM_DoorSystem_T {
  const char_T **errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[236];
    int32_T* vardimsAddress[236];
    RTWLoggingFcnPtr loggingPtrs[236];
  } DataMapInfo;
};

typedef struct {
  B_DoorSystem_c_T rtb;
  DW_DoorSystem_f_T rtdw;
  RT_MODEL_DoorSystem_T rtm;
} MdlrefDW_DoorSystem_T;

/* Model reference registration function */
extern void DoorSystem_initialize(const char_T **rt_errorStatus,
  RT_MODEL_DoorSystem_T *const DoorSystem_M, B_DoorSystem_c_T *localB,
  DW_DoorSystem_f_T *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const
  char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  DoorSystem_GetCAPIStaticMap(void);
extern void DoorSystem_DoorClose(real_T *rty_MotorCommand,
  P_DoorClose_DoorSystem_T *localP);
extern void DoorSystem_DoorOpenDelay_Init(DW_DoorOpenDelay_DoorSystem_T *localDW,
  P_DoorOpenDelay_DoorSystem_T *localP);
extern void DoorSystem_DoorOpenDelay_Start(B_DoorOpenDelay_DoorSystem_T *localB,
  DW_DoorOpenDelay_DoorSystem_T *localDW);
extern void DoorSystem_DoorOpenDelay(boolean_T rtu_In,
  B_DoorOpenDelay_DoorSystem_T *localB, DW_DoorOpenDelay_DoorSystem_T *localDW,
  P_DoorOpenDelay_DoorSystem_T *localP, real_T rtp_UpperSaturationLimit);
extern void DoorSystem_IfActionSubsystem1(real_T rty_Out2[2],
  P_IfActionSubsystem1_DoorSystem_T *localP);
extern void DoorSystem_LeadingEdgePulseTunable_Init
  (DW_LeadingEdgePulseTunable_DoorSystem_T *localDW,
   P_LeadingEdgePulseTunable_DoorSystem_T *localP);
extern void DoorSystem_LeadingEdgePulseTunable_Start
  (B_LeadingEdgePulseTunable_DoorSystem_T *localB,
   DW_LeadingEdgePulseTunable_DoorSystem_T *localDW);
extern void DoorSystem_LeadingEdgePulseTunable(boolean_T rtu_In,
  B_LeadingEdgePulseTunable_DoorSystem_T *localB,
  DW_LeadingEdgePulseTunable_DoorSystem_T *localDW,
  P_LeadingEdgePulseTunable_DoorSystem_T *localP, real_T rtp_DoorOpenAlarmTime);
extern void DoorSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_DoorSystem_T *localDW);
extern void DoorSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_DoorSystem_T *localB,
   DW_TimerOffDelayNoInit_DoorSystem_T *localDW);
extern void DoorSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_DoorSystem_T *localB,
  DW_TimerOffDelayNoInit_DoorSystem_T *localDW,
  P_TimerOffDelayNoInit_DoorSystem_T *localP);
extern void DoorSystem_Init(B_DoorSystem_c_T *localB, DW_DoorSystem_f_T *localDW);
extern void DoorSystem_Reset(DW_DoorSystem_f_T *localDW);
extern void DoorSystem_Start(B_DoorSystem_c_T *localB, DW_DoorSystem_f_T
  *localDW);
extern void DoorSystem_Disable(DW_DoorSystem_f_T *localDW);
extern void DoorSystem(const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig
  [8], const BD_DoorSystem_In_Vehicle rtu_DoorSystemVehicleInputs[8], const
  BD_DoorSystem_In_Overrides rtu_Overrides[8], const
  BD_DoorSystem_In_Emergency_Door rtu_EmergencyDoorInputs[8],
  BD_DoorSystem_Out_Vehicle rty_DoorSystemVehicleOut[8], B_DoorSystem_c_T
  *localB, DW_DoorSystem_f_T *localDW, const BD_DoorSystem_Prm
  *rtp_PRM_DoorSystem);

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
 * '<Root>' : 'DoorSystem'
 * '<S1>'   : 'DoorSystem/DoorSystemPerCar'
 * '<S2>'   : 'DoorSystem/TrainInterlock'
 * '<S3>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles'
 * '<S4>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical'
 * '<S5>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides'
 * '<S6>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking'
 * '<S7>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor'
 * '<S8>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/LeftRightInterlock'
 * '<S9>'   : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic'
 * '<S10>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem'
 * '<S11>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Compare To Constant2'
 * '<S12>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Compare To Constant3'
 * '<S13>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches'
 * '<S14>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit'
 * '<S15>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack'
 * '<S16>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Detect Increase'
 * '<S17>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Detect Increase1'
 * '<S18>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Discrete Dynamic Limited Integrator1'
 * '<S19>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/DoorSwitches'
 * '<S20>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Manual Control'
 * '<S21>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control'
 * '<S22>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Discrete Dynamic Limited Integrator1/Saturation Dynamic'
 * '<S23>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/DoorSwitches/Compare To Constant1'
 * '<S24>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/DoorSwitches/Compare To Constant2'
 * '<S25>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control/FailToClose'
 * '<S26>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic'
 * '<S27>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic'
 * '<S28>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease'
 * '<S29>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorIsolation'
 * '<S30>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorLock'
 * '<S31>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic'
 * '<S32>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands'
 * '<S33>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality'
 * '<S34>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOffAudio'
 * '<S35>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio'
 * '<S36>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable'
 * '<S37>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1'
 * '<S38>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/Detect Increase'
 * '<S39>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable'
 * '<S40>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Count to 0'
 * '<S41>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/Detect Increase'
 * '<S42>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable'
 * '<S43>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Count to 0'
 * '<S44>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOffIndicators'
 * '<S45>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1'
 * '<S46>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Compare To Zero'
 * '<S47>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Decrease'
 * '<S48>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Increase'
 * '<S49>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Increase1'
 * '<S50>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic'
 * '<S51>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority'
 * '<S52>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority1'
 * '<S53>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority2'
 * '<S54>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem'
 * '<S55>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem1'
 * '<S56>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem2'
 * '<S57>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem3'
 * '<S58>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem4'
 * '<S59>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Compare To Zero'
 * '<S60>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Detect Increase'
 * '<S61>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Detect Increase1'
 * '<S62>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/SR Latch - Reset Priority'
 * '<S63>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorIsolation/Compare To Zero1'
 * '<S64>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorIsolation/SR Latch - Reset Priority'
 * '<S65>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorClose'
 * '<S66>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay'
 * '<S67>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpen'
 * '<S68>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay'
 * '<S69>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/NoMotorCommand'
 * '<S70>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/Obstruction'
 * '<S71>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Compare To Zero'
 * '<S72>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Compare To Zero'
 * '<S73>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/Detect Decrease'
 * '<S74>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/Detect Increase'
 * '<S75>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/MotorCloseLatch'
 * '<S76>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/MotorOpenLatch'
 * '<S77>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart'
 * '<S78>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection'
 * '<S79>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Compare To Constant1'
 * '<S80>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Compare To Constant4'
 * '<S81>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Decrease'
 * '<S82>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Decrease1'
 * '<S83>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Increase'
 * '<S84>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Increase1'
 * '<S85>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/SR Latch - Set Priority1'
 * '<S86>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/SR Latch - Set Priority2'
 * '<S87>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs'
 * '<S88>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorElectricalOutputs'
 * '<S89>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorOutputControlStates'
 * '<S90>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorTCMSOutputs'
 * '<S91>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Compare To Zero'
 * '<S92>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Compare To Zero1'
 * '<S93>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Detect Decrease'
 * '<S94>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Detect Increase'
 * '<S95>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/LeftRightInterlock/For Each Subsystem'
 * '<S96>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem'
 * '<S97>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/Orientation Swap'
 * '<S98>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen'
 * '<S99>'  : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse'
 * '<S100>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse'
 * '<S101>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/Detect Increase'
 * '<S102>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit'
 * '<S103>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Count to 0'
 * '<S104>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/Detect Decrease'
 * '<S105>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit'
 * '<S106>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Count to 0'
 * '<S107>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/Orientation Swap/Orientation Swap'
 * '<S108>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation'
 * '<S109>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Compare To Constant'
 * '<S110>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase'
 * '<S111>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase1'
 * '<S112>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase2'
 * '<S113>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase3'
 * '<S114>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase4'
 * '<S115>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase5'
 * '<S116>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack'
 * '<S117>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority'
 * '<S118>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority1'
 * '<S119>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority2'
 * '<S120>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority3'
 * '<S121>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1'
 * '<S122>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2'
 * '<S123>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Decrease'
 * '<S124>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase1'
 * '<S125>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase2'
 * '<S126>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase3'
 * '<S127>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Discrete Dynamic Limited Integrator1'
 * '<S128>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit'
 * '<S129>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1'
 * '<S130>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2'
 * '<S131>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Discrete Dynamic Limited Integrator1/Saturation Dynamic'
 * '<S132>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Count to 0'
 * '<S133>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Count to 0'
 * '<S134>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Count to 0'
 * '<S135>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Compare To Zero'
 * '<S136>' : 'DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Compare To Zero'
 * '<S137>' : 'DoorSystem/TrainInterlock/CreateBusOfVectorsConfig'
 * '<S138>' : 'DoorSystem/TrainInterlock/MakeArrayOfBuses'
 * '<S139>' : 'DoorSystem/TrainInterlock/TrainWireLogic'
 */
#endif                                 /* RTW_HEADER_DoorSystem_h_ */
