/*
 * Code generation for system model 'TractionSystem'
 * For more details, see corresponding source file TractionSystem.c
 *
 */

#ifndef RTW_HEADER_TractionSystem_h_
#define RTW_HEADER_TractionSystem_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef TractionSystem_COMMON_INCLUDES_
# define TractionSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* TractionSystem_COMMON_INCLUDES_ */

#include "TractionSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals for system '<S60>/TimerOnDelay NoInit' */
typedef struct {
  boolean_T Compare;                   /* '<S69>/Compare' */
} B_TimerOnDelayNoInit_TractionSystem_T;

/* Block states (default storage) for system '<S60>/TimerOnDelay NoInit' */
typedef struct {
  real_T Timer_DSTATE;                 /* '<S67>/Timer' */
  int8_T Timer_PrevResetState;         /* '<S67>/Timer' */
} DW_TimerOnDelayNoInit_TractionSystem_T;

/* Block signals for system '<S71>/TimerOffDelay NoInit' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S78>/Logical Operator1' */
} B_TimerOffDelayNoInit_TractionSystem_T;

/* Block states (default storage) for system '<S71>/TimerOffDelay NoInit' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S78>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S78>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S78>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S78>/IC' */
} DW_TimerOffDelayNoInit_TractionSystem_T;

/* Block signals for system '<S27>/TractionControl (Per Bogie)' */
typedef struct {
  B_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit_h;/* '<S88>/TimerOffDelay NoInit' */
  B_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit_h;/* '<S61>/TimerOnDelay NoInit' */
  B_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit;/* '<S71>/TimerOffDelay NoInit' */
  B_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit;/* '<S60>/TimerOnDelay NoInit' */
} B_CoreSubsys_TractionSystem_cauao_T;

/* Block states (default storage) for system '<S27>/TractionControl (Per Bogie)' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S44>/Delay Input1' */
  real_T Delay_DSTATE[2];              /* '<S85>/Delay' */
  real_T Delay_DSTATE_b[2];            /* '<S68>/Delay' */
  real_T DelayInput2_DSTATE;           /* '<S70>/Delay Input2' */
  real_T UnitDelay1_DSTATE;            /* '<S68>/Unit Delay1' */
  real_T DelayInput1_DSTATE_n;         /* '<S74>/Delay Input1' */
  real_T DelayInput1_DSTATE_o;         /* '<S75>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S77>/Unit Delay' */
  real_T DelayInput2_DSTATE_e;         /* '<S87>/Delay Input2' */
  real_T UnitDelay1_DSTATE_p;          /* '<S85>/Unit Delay1' */
  real_T DelayInput1_DSTATE_c;         /* '<S91>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S92>/Delay Input1' */
  real_T UnitDelay_DSTATE_p;           /* '<S94>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S61>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S60>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S68>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_j;        /* '<S85>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S45>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S82>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S65>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S76>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S93>/Memory' */
  DW_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit_h;/* '<S88>/TimerOffDelay NoInit' */
  DW_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit_h;/* '<S61>/TimerOnDelay NoInit' */
  DW_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit;/* '<S71>/TimerOffDelay NoInit' */
  DW_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit;/* '<S60>/TimerOnDelay NoInit' */
} DW_CoreSubsys_TractionSystem_fwu4s_T;

/* Block signals for system '<S140>/Replace Zeros' */
typedef struct {
  real_T y;                            /* '<S140>/Replace Zeros' */
} B_ReplaceZeros_TractionSystem_T;

/* Block signals for system '<S101>/TractionMotor' */
typedef struct {
  B_ReplaceZeros_TractionSystem_T sf_ReplaceZeros_k;/* '<S136>/Replace Zeros' */
  B_ReplaceZeros_TractionSystem_T sf_ReplaceZeros;/* '<S140>/Replace Zeros' */
} B_CoreSubsys_TractionSystem_o_T;

/* Block states (default storage) for system '<S101>/TractionMotor' */
typedef struct {
  real_T PrevY;                        /* '<S111>/Rate Limiter' */
  real_T PrevY_j;                      /* '<S107>/Rate Limiter' */
  real_T n_countours;                  /* '<S126>/Contour Interpolation 2D y' */
  real_T previous_contour_index;       /* '<S126>/Contour Interpolation 2D y' */
  real_T previous_contour_x_index_c1;  /* '<S126>/Contour Interpolation 2D y' */
  real_T previous_contour_x_index_c2;  /* '<S126>/Contour Interpolation 2D y' */
  real_T n_countours_c;                /* '<S114>/Contour Interpolation 2D y' */
  real_T previous_contour_index_n;     /* '<S114>/Contour Interpolation 2D y' */
  real_T previous_contour_x_index_c1_b;/* '<S114>/Contour Interpolation 2D y' */
  real_T previous_contour_x_index_c2_i;/* '<S114>/Contour Interpolation 2D y' */
  boolean_T n_countours_not_empty;     /* '<S126>/Contour Interpolation 2D y' */
  boolean_T n_countours_not_empty_m;   /* '<S114>/Contour Interpolation 2D y' */
} DW_CoreSubsys_TractionSystem_f0_T;

/* Block signals for system '<S28>/BogieTractionConverterSystem (Per Bogie)' */
typedef struct {
  B_CoreSubsys_TractionSystem_o_T CoreSubsys_h[2];/* '<S101>/TractionMotor' */
} B_CoreSubsys_TractionSystem_cauaoh_T;

/* Block states (default storage) for system '<S28>/BogieTractionConverterSystem (Per Bogie)' */
typedef struct {
  DW_CoreSubsys_TractionSystem_f0_T CoreSubsys_h[2];/* '<S101>/TractionMotor' */
} DW_CoreSubsys_TractionSystem_fwu4sl_T;

/* Block signals for system '<Root>/Traction (Per Vehicle)' */
typedef struct {
  BD_TractionSystem_Out_Vehicle BusAssignment;/* '<S26>/Bus Assignment' */
  BD_TractionSystem_Int_BogieOutputs UnitDelay[2];/* '<S25>/Unit Delay' */
  BD_TractionSystem_Int_BogieControl
    ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[2];/* '<S35>/Merge4' */
  B_CoreSubsys_TractionSystem_cauaoh_T CoreSubsys_pnae[2];
                          /* '<S28>/BogieTractionConverterSystem (Per Bogie)' */
  B_CoreSubsys_TractionSystem_cauao_T CoreSubsys_pna[2];/* '<S27>/TractionControl (Per Bogie)' */
} B_CoreSubsys_TractionSystem_c_T;

/* Block states (default storage) for system '<Root>/Traction (Per Vehicle)' */
typedef struct {
  BD_TractionSystem_Int_BogieOutputs UnitDelay_DSTATE[2];/* '<S25>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S36>/Discrete-Time Integrator' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S36>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S98>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S97>/Memory' */
  DW_CoreSubsys_TractionSystem_fwu4sl_T CoreSubsys_pnae[2];
                          /* '<S28>/BogieTractionConverterSystem (Per Bogie)' */
  DW_CoreSubsys_TractionSystem_fwu4s_T CoreSubsys_pna[2];/* '<S27>/TractionControl (Per Bogie)' */
} DW_CoreSubsys_TractionSystem_f_T;

/* Block signals for model 'TractionSystem' */
typedef struct {
  BD_CommonTrain_Cfg_Vehicle ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0
    [8];                               /* '<S4>/Bus Creator2' */
  BD_TractionSystem_Cfg_Vehicle
    ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[8];/* '<S4>/Bus Creator1' */
  B_CoreSubsys_TractionSystem_c_T CoreSubsys_p[8];/* '<Root>/Traction (Per Vehicle)' */
} B_TractionSystem_c_T;

/* Block states (default storage) for model 'TractionSystem' */
typedef struct {
  DW_CoreSubsys_TractionSystem_f_T CoreSubsys_p[8];/* '<Root>/Traction (Per Vehicle)' */
} DW_TractionSystem_f_T;

/* Parameters for system: '<S3>/ConfigCheck' */
struct P_CoreSubsys_TractionSystem_T_ {
  real_T MinValue_const;               /* Mask Parameter: MinValue_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T MinValue_const_o;             /* Mask Parameter: MinValue_const_o
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T MinValue_const_b;             /* Mask Parameter: MinValue_const_b
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T MinValue_const_p;             /* Mask Parameter: MinValue_const_p
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T MinValue_const_h;             /* Mask Parameter: MinValue_const_h
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T MinValue_const_i;             /* Mask Parameter: MinValue_const_i
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T MinValue_const_m;             /* Mask Parameter: MinValue_const_m
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T MinValue_const_n;             /* Mask Parameter: MinValue_const_n
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T MinValue_const_d;             /* Mask Parameter: MinValue_const_d
                                        * Referenced by: '<S23>/Constant'
                                        */
  boolean_T MinValue_const_g;          /* Mask Parameter: MinValue_const_g
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Default_Value;                /* Expression: 3
                                        * Referenced by: '<S14>/Default'
                                        */
  real_T Default_Value_d;              /* Expression: 0.580
                                        * Referenced by: '<S13>/Default'
                                        */
  real_T Default_Value_a;              /* Expression: 16000
                                        * Referenced by: '<S12>/Default'
                                        */
  real_T Default_Value_n;              /* Expression: 2
                                        * Referenced by: '<S11>/Default'
                                        */
  real_T Default_Value_f;              /* Expression: 2
                                        * Referenced by: '<S10>/Default'
                                        */
  real_T Default_Value_e;              /* Expression: 6
                                        * Referenced by: '<S9>/Default'
                                        */
  real_T Default_Value_h;              /* Expression: 20
                                        * Referenced by: '<S8>/Default'
                                        */
  real_T Default_Value_de;             /* Expression: 3
                                        * Referenced by: '<S7>/Default'
                                        */
  real_T Default_Value_m;              /* Expression: 16000
                                        * Referenced by: '<S6>/Default'
                                        */
  real_T Default_Value_mh;             /* Expression: 0
                                        * Referenced by: '<S5>/Default'
                                        */
};

/* Parameters for system: '<S60>/TimerOnDelay NoInit' */
struct P_TimerOnDelayNoInit_TractionSystem_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Timer_gainval;                /* Computed Parameter: Timer_gainval
                                        * Referenced by: '<S67>/Timer'
                                        */
  real_T Timer_IC;                     /* Expression: 0
                                        * Referenced by: '<S67>/Timer'
                                        */
  real_T Timer_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S67>/Timer'
                                        */
};

/* Parameters for system: '<S71>/TimerOffDelay NoInit' */
struct P_TimerOffDelayNoInit_TractionSystem_T_ {
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S78>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S78>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S78>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S78>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S78>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S78>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S78>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S27>/TractionControl (Per Bogie)' */
struct P_CoreSubsys_TractionSystem_gmy0o_T_ {
  real_T SampleandHold_InitialCondition;
                               /* Mask Parameter: SampleandHold_InitialCondition
                                * Referenced by: '<S77>/Unit Delay'
                                */
  real_T SampleandHold_InitialCondition_m;
                             /* Mask Parameter: SampleandHold_InitialCondition_m
                              * Referenced by: '<S94>/Unit Delay'
                              */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S80>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S81>/Constant'
                                      */
  real_T Stop_const;                   /* Mask Parameter: Stop_const
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T CompareToConstant1_const_j;
                                   /* Mask Parameter: CompareToConstant1_const_j
                                    * Referenced by: '<S64>/Constant'
                                    */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S63>/Constant'
                                       */
  real_T Stop_const_o;                 /* Mask Parameter: Stop_const_o
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T CompareToConstant_const_c; /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S43>/Constant'
                                     */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S74>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S75>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_i;       /* Mask Parameter: DetectDecrease_vinit_i
                                        * Referenced by: '<S91>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit_d;       /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S92>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_j;       /* Mask Parameter: DetectDecrease_vinit_j
                                        * Referenced by: '<S44>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S82>/Memory'
                        */
  boolean_T SRLatchResetPriority_initial_condition_e;
                     /* Mask Parameter: SRLatchResetPriority_initial_condition_e
                      * Referenced by: '<S65>/Memory'
                      */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S76>/Memory'
                       */
  boolean_T SRLatchResetPriority1_initial_condition_f;
                    /* Mask Parameter: SRLatchResetPriority1_initial_condition_f
                     * Referenced by: '<S93>/Memory'
                     */
  boolean_T SRLatchResetPriority_initial_condition_m;
                     /* Mask Parameter: SRLatchResetPriority_initial_condition_m
                      * Referenced by: '<S45>/Memory'
                      */
  BD_TractionSystem_Out_Vehicle_TCMS_Bogie Constant4_Value;/* Computed Parameter: Constant4_Value
                                                            * Referenced by: '<S54>/Constant4'
                                                            */
  BD_TractionSystem_Out_Vehicle_TCMS_Bogie Constant1_Value;/* Computed Parameter: Constant1_Value
                                                            * Referenced by: '<S41>/Constant1'
                                                            */
  BD_TractionSystem_Int_BogieControl Constant3_Value;/* Computed Parameter: Constant3_Value
                                                      * Referenced by: '<S41>/Constant3'
                                                      */
  BD_TractionSystem_Out_Vehicle_BCU_Bogie Constant1_Value_d;/* Computed Parameter: Constant1_Value_d
                                                             * Referenced by: '<S52>/Constant1'
                                                             */
  BD_TractionSystem_Out_Vehicle_BCU_Bogie Constant2_Value;/* Computed Parameter: Constant2_Value
                                                           * Referenced by: '<S41>/Constant2'
                                                           */
  BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie Constant4_Value_k;/* Computed Parameter: Constant4_Value_k
                                                                      * Referenced by: '<S53>/Constant4'
                                                                      */
  BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie Constant4_Value_ko;/* Computed Parameter: Constant4_Value_ko
                                                                      * Referenced by: '<S41>/Constant4'
                                                                      */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T min0_UpperSat;                /* Expression: inf
                                        * Referenced by: '<S68>/min0'
                                        */
  real_T min0_LowerSat;                /* Expression: 0
                                        * Referenced by: '<S68>/min0'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S68>/Constant2'
                                        */
  real_T Constant1_Value_dh;           /* Expression: 0
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real_T min0_UpperSat_f;              /* Expression: inf
                                        * Referenced by: '<S85>/min0'
                                        */
  real_T min0_LowerSat_j;              /* Expression: 0
                                        * Referenced by: '<S85>/min0'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S85>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S85>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S51>/Switch'
                                        */
  real_T Multiply_Gain;                /* Expression: 0.01
                                        * Referenced by: '<S56>/Multiply'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S85>/Delay'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S61>/Switch1'
                                        */
  real_T safedivide2_UpperSat;         /* Expression: 1e8
                                        * Referenced by: '<S50>/safedivide2'
                                        */
  real_T safedivide2_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S50>/safedivide2'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S50>/Multiply1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100
                                        * Referenced by: '<S50>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S50>/Saturation1'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S58>/Switch'
                                        */
  real_T Multiply_Gain_b;              /* Expression: 0.01
                                        * Referenced by: '<S55>/Multiply'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0.0
                                        * Referenced by: '<S68>/Delay'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S60>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S50>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S50>/Saturation'
                                        */
  real_T Multiply1_Gain_k;             /* Expression: 0.5
                                        * Referenced by: '<S57>/Multiply1'
                                        */
  real_T safedivide1_UpperSat;         /* Expression: 1e6
                                        * Referenced by: '<S57>/safedivide1'
                                        */
  real_T safedivide1_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S57>/safedivide1'
                                        */
  real_T safedivide2_UpperSat_a;       /* Expression: 1e6
                                        * Referenced by: '<S57>/safedivide2'
                                        */
  real_T safedivide2_LowerSat_e;       /* Expression: eps
                                        * Referenced by: '<S57>/safedivide2'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S70>/Delay Input2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay1'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S70>/sample time'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T DelayInput2_InitialCondition_f;/* Expression: 0
                                         * Referenced by: '<S87>/Delay Input2'
                                         */
  real_T UnitDelay1_InitialCondition_k;/* Expression: 0
                                        * Referenced by: '<S85>/Unit Delay1'
                                        */
  real_T sampletime_WtEt_h;            /* Computed Parameter: sampletime_WtEt_h
                                        * Referenced by: '<S87>/sample time'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 0.5
                                        * Referenced by: '<S88>/Gain'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S40>/Switch'
                                        */
  boolean_T Constant_Value_i4;         /* Expression: true
                                        * Referenced by: '<S51>/Constant'
                                        */
  boolean_T Constant_Value_e;          /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S73>/Constant'
                                        */
  boolean_T Constant_Value_cd;         /* Computed Parameter: Constant_Value_cd
                                        * Referenced by: '<S90>/Constant'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S61>/Unit Delay'
                                */
  boolean_T UnitDelay_InitialCondition_a;
                             /* Computed Parameter: UnitDelay_InitialCondition_a
                              * Referenced by: '<S60>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_h;
                             /* Computed Parameter: UnitDelay_InitialCondition_h
                              * Referenced by: '<S68>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S85>/Unit Delay'
                              */
  P_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit_h;/* '<S88>/TimerOffDelay NoInit' */
  P_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit_h;/* '<S61>/TimerOnDelay NoInit' */
  P_TimerOffDelayNoInit_TractionSystem_T TimerOffDelayNoInit;/* '<S71>/TimerOffDelay NoInit' */
  P_TimerOnDelayNoInit_TractionSystem_T TimerOnDelayNoInit;/* '<S60>/TimerOnDelay NoInit' */
};

/* Parameters for system: '<S102>/MotorVehicle' */
struct P_CoreSubsys_TractionSystem_gmy0ogc_T_ {
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S147>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S147>/Saturation1'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S147>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S147>/Saturation3'
                                        */
  real_T safedivide1_UpperSat;         /* Expression: 1e6
                                        * Referenced by: '<S148>/safedivide1'
                                        */
  real_T safedivide1_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S148>/safedivide1'
                                        */
  real_T safedivide_UpperSat;          /* Expression: 1e6
                                        * Referenced by: '<S147>/safedivide'
                                        */
  real_T safedivide_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S147>/safedivide'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,1]
                                        * Referenced by: '<S149>/Constant'
                                        */
  real_T safedivide_UpperSat_o;        /* Expression: 1e6
                                        * Referenced by: '<S146>/safedivide'
                                        */
  real_T safedivide_LowerSat_d;        /* Expression: eps
                                        * Referenced by: '<S146>/safedivide'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S145>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S145>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S145>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S145>/Constant3'
                                        */
};

/* Parameters for system: '<S101>/TractionMotor' */
struct P_CoreSubsys_TractionSystem_c_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S125>/Constant'
                                       */
  real_T ContourInterpolation2Dy_contour_size[5];
                         /* Mask Parameter: ContourInterpolation2Dy_contour_size
                          * Referenced by: '<S114>/Contour Interpolation 2D y'
                          */
  real_T ContourInterpolation2Dy_contour_size_a[5];
                       /* Mask Parameter: ContourInterpolation2Dy_contour_size_a
                        * Referenced by: '<S126>/Contour Interpolation 2D y'
                        */
  real_T ContourInterpolation2Dy_contour_xy_data[50];
                      /* Mask Parameter: ContourInterpolation2Dy_contour_xy_data
                       * Referenced by: '<S114>/Contour Interpolation 2D y'
                       */
  real_T ContourInterpolation2Dy_contour_xy_data_d[50];
                    /* Mask Parameter: ContourInterpolation2Dy_contour_xy_data_d
                     * Referenced by: '<S126>/Contour Interpolation 2D y'
                     */
  real_T ContourInterpolation2Dy_contour_z_data[5];
                       /* Mask Parameter: ContourInterpolation2Dy_contour_z_data
                        * Referenced by: '<S114>/Contour Interpolation 2D y'
                        */
  real_T ContourInterpolation2Dy_contour_z_data_i[5];
                     /* Mask Parameter: ContourInterpolation2Dy_contour_z_data_i
                      * Referenced by: '<S126>/Contour Interpolation 2D y'
                      */
  real_T SubsetInterpolation1D_subset_size;
                            /* Mask Parameter: SubsetInterpolation1D_subset_size
                             * Referenced by: '<S115>/Subset Interpolation 1D'
                             */
  real_T SubsetInterpolation1D_subset_size_b;
                          /* Mask Parameter: SubsetInterpolation1D_subset_size_b
                           * Referenced by: '<S127>/Subset Interpolation 1D'
                           */
  real_T MaxPowerLookup_subset_size;
                                   /* Mask Parameter: MaxPowerLookup_subset_size
                                    * Referenced by: '<S133>/MaxPowerLookup'
                                    */
  real_T MaxTorqueLookup_subset_size;
                                  /* Mask Parameter: MaxTorqueLookup_subset_size
                                   * Referenced by: '<S133>/MaxTorqueLookup'
                                   */
  real_T SubsetInterpolation1D_x_data[2];
                                 /* Mask Parameter: SubsetInterpolation1D_x_data
                                  * Referenced by: '<S115>/Subset Interpolation 1D'
                                  */
  real_T SubsetInterpolation1D_x_data_j[2];
                               /* Mask Parameter: SubsetInterpolation1D_x_data_j
                                * Referenced by: '<S127>/Subset Interpolation 1D'
                                */
  real_T MaxPowerLookup_x_data[5];     /* Mask Parameter: MaxPowerLookup_x_data
                                        * Referenced by: '<S133>/MaxPowerLookup'
                                        */
  real_T MaxTorqueLookup_x_data[5];    /* Mask Parameter: MaxTorqueLookup_x_data
                                        * Referenced by: '<S133>/MaxTorqueLookup'
                                        */
  real_T SubsetInterpolation1D_y_data[2];
                                 /* Mask Parameter: SubsetInterpolation1D_y_data
                                  * Referenced by: '<S115>/Subset Interpolation 1D'
                                  */
  real_T SubsetInterpolation1D_y_data_o[2];
                               /* Mask Parameter: SubsetInterpolation1D_y_data_o
                                * Referenced by: '<S127>/Subset Interpolation 1D'
                                */
  real_T MaxPowerLookup_y_data[5];     /* Mask Parameter: MaxPowerLookup_y_data
                                        * Referenced by: '<S133>/MaxPowerLookup'
                                        */
  real_T MaxTorqueLookup_y_data[5];    /* Mask Parameter: MaxTorqueLookup_y_data
                                        * Referenced by: '<S133>/MaxTorqueLookup'
                                        */
  TractionCurveSpecificationType CurveInputType_Value;/* Mask Parameter: CurveInputType_Value
                                                       * Referenced by: '<S129>/Constant'
                                                       */
  TractionCurveSpecificationType CurveInputType_Value_f;/* Mask Parameter: CurveInputType_Value_f
                                                         * Referenced by: '<S117>/Constant'
                                                         */
  real_T applyoppositetodirectionofmovement_Gain;/* Expression: -1
                                                  * Referenced by: '<S105>/apply opposite to direction of movement'
                                                  */
  real_T NoBraking_Value;              /* Expression: 0
                                        * Referenced by: '<S106>/No Braking'
                                        */
  real_T NoLimit_Value;                /* Expression: inf
                                        * Referenced by: '<S122>/NoLimit'
                                        */
  real_T safedivide_UpperSat;          /* Expression: 1e6
                                        * Referenced by: '<S122>/safedivide'
                                        */
  real_T safedivide_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S122>/safedivide'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S122>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S122>/Switch1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S122>/Constant2'
                                        */
  real_T safedivide_UpperSat_j;        /* Expression: 1e6
                                        * Referenced by: '<S116>/safedivide'
                                        */
  real_T safedivide_LowerSat_d;        /* Expression: eps
                                        * Referenced by: '<S116>/safedivide'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S122>/Switch'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,1]
                                        * Referenced by: '<S123>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S114>/Constant'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S114>/Switch'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S118>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S124>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: -1
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T NoPower_Value;                /* Expression: 0
                                        * Referenced by: '<S110>/No Power'
                                        */
  real_T NoLimit_Value_o;              /* Expression: inf
                                        * Referenced by: '<S142>/NoLimit'
                                        */
  real_T safedivide_UpperSat_f;        /* Expression: 1e6
                                        * Referenced by: '<S142>/safedivide'
                                        */
  real_T safedivide_LowerSat_a;        /* Expression: eps
                                        * Referenced by: '<S142>/safedivide'
                                        */
  real_T Constant3_Value_g;            /* Expression: 0
                                        * Referenced by: '<S142>/Constant3'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 0
                                        * Referenced by: '<S142>/Switch1'
                                        */
  real_T Percentagetofraction_Gain;    /* Expression: 0.01
                                        * Referenced by: '<S128>/Percentage to fraction'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S128>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S128>/Saturation1'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S128>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S128>/Saturation3'
                                        */
  real_T safedivide_UpperSat_h;        /* Expression: 1e6
                                        * Referenced by: '<S128>/safedivide'
                                        */
  real_T safedivide_LowerSat_e;        /* Expression: eps
                                        * Referenced by: '<S128>/safedivide'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S142>/Constant2'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S142>/Switch'
                                        */
  real_T Percentagetofraction_Gain_n;  /* Expression: 0.01
                                        * Referenced by: '<S127>/Percentage to fraction'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real_T Saturation1_UpperSat_f;       /* Expression: 1
                                        * Referenced by: '<S138>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_a;       /* Expression: 0
                                        * Referenced by: '<S138>/Saturation1'
                                        */
  real_T Constant_Value_m;             /* Expression: CDMaxMotorPower
                                        * Referenced by: '<S138>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: CDMaxMotorTorque
                                        * Referenced by: '<S138>/Constant1'
                                        */
  real_T Saturation3_UpperSat_f;       /* Expression: 1
                                        * Referenced by: '<S138>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_d;       /* Expression: 0
                                        * Referenced by: '<S138>/Saturation3'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 1
                                        * Referenced by: '<S133>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_e;       /* Expression: 0
                                        * Referenced by: '<S133>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S133>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: 0
                                        * Referenced by: '<S133>/Saturation3'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S126>/Switch'
                                        */
  real_T Constant_Value_jf;            /* Expression: 0
                                        * Referenced by: '<S130>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S112>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S113>/Constant'
                                        */
  real_T safedivide1_UpperSat;         /* Expression: 1e6
                                        * Referenced by: '<S109>/safedivide1'
                                        */
  real_T safedivide1_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S109>/safedivide1'
                                        */
  real_T PerformanceFactor_Value;      /* Expression: 1
                                        * Referenced by: '<S111>/PerformanceFactor'
                                        */
  real_T RateLimiter_RisingLim;     /* Computed Parameter: RateLimiter_RisingLim
                                     * Referenced by: '<S111>/Rate Limiter'
                                     */
  real_T RateLimiter_FallingLim;   /* Computed Parameter: RateLimiter_FallingLim
                                    * Referenced by: '<S111>/Rate Limiter'
                                    */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S111>/Rate Limiter'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S110>/Switch2'
                                        */
  real_T PerformanceFactor_Value_h;    /* Expression: 1
                                        * Referenced by: '<S107>/PerformanceFactor'
                                        */
  real_T RateLimiter_RisingLim_g; /* Computed Parameter: RateLimiter_RisingLim_g
                                   * Referenced by: '<S107>/Rate Limiter'
                                   */
  real_T RateLimiter_FallingLim_h;
                                 /* Computed Parameter: RateLimiter_FallingLim_h
                                  * Referenced by: '<S107>/Rate Limiter'
                                  */
  real_T RateLimiter_IC_p;             /* Expression: 0
                                        * Referenced by: '<S107>/Rate Limiter'
                                        */
  real_T Constant_Value_az;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant1'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S104>/Constant4'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S104>/Constant5'
                                        */
};

/* Parameters for system: '<S28>/BogieTractionConverterSystem (Per Bogie)' */
struct P_CoreSubsys_TractionSystem_gmy0og_T_ {
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S100>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S100>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.25
                                        * Referenced by: '<S100>/Gain1'
                                        */
  P_CoreSubsys_TractionSystem_c_T CoreSubsys_h;/* '<S101>/TractionMotor' */
  P_CoreSubsys_TractionSystem_gmy0ogc_T CoreSubsys;/* '<S102>/MotorVehicle' */
};

/* Parameters for system: '<Root>/Traction (Per Vehicle)' */
struct P_CoreSubsys_TractionSystem_g_T_ {
  boolean_T AKState1_initial_condition;
                                   /* Mask Parameter: AKState1_initial_condition
                                    * Referenced by: '<S98>/Memory'
                                    */
  boolean_T AKState_initial_condition;
                                    /* Mask Parameter: AKState_initial_condition
                                     * Referenced by: '<S97>/Memory'
                                     */
  BD_TractionSystem_Out_Vehicle TractionSystemOut_Y0;
                                     /* Computed Parameter: TractionSystemOut_Y0
                                      * Referenced by: '<S25>/TractionSystemOut'
                                      */
  BD_TractionSystem_Out_Vehicle Constant1_Value;/* Computed Parameter: Constant1_Value
                                                 * Referenced by: '<S26>/Constant1'
                                                 */
  BD_TractionSystem_Out_Vehicle_TCU Constant1_Value_i;/* Computed Parameter: Constant1_Value_i
                                                       * Referenced by: '<S33>/Constant1'
                                                       */
  BD_TractionSystem_Out_Vehicle_TCMS Constant4_Value;/* Computed Parameter: Constant4_Value
                                                      * Referenced by: '<S39>/Constant4'
                                                      */
  BD_TractionSystem_Int_BogieOutputs UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S25>/Unit Delay'
                                */
  BD_TractionSystem_Out_Vehicle_BCU Constant2_Value;/* Computed Parameter: Constant2_Value
                                                     * Referenced by: '<S37>/Constant2'
                                                     */
  BD_TractionSystem_Out_Vehicle_ElectricalSystem Constant2_Value_m;/* Computed Parameter: Constant2_Value_m
                                                                    * Referenced by: '<S38>/Constant2'
                                                                    */
  BD_TractionSystem_Out_Vehicle_Audio Constant2_Value_i;/* Computed Parameter: Constant2_Value_i
                                                         * Referenced by: '<S29>/Constant2'
                                                         */
  real_T RC_AK_Value;                  /* Expression: 9*0.0242
                                        * Referenced by: '<S36>/RC_AK'
                                        */
  real_T RC_K_Value;                   /* Expression: eps
                                        * Referenced by: '<S36>/RC_K'
                                        */
  real_T Link_NominalVoltage_Value;    /* Expression: 1800
                                        * Referenced by: '<S36>/Link_NominalVoltage'
                                        */
  real_T Link_UnderVoltage_Value;      /* Expression: 1500
                                        * Referenced by: '<S36>/Link_UnderVoltage'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S36>/Switch1'
                                        */
  real_T Link_OverVoltage_Value;       /* Expression: 2200
                                        * Referenced by: '<S36>/Link_OverVoltage'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S36>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S36>/Discrete-Time Integrator'
                                        */
  real_T Multiply1_Gain;               /* Expression: -1
                                        * Referenced by: '<S36>/Multiply1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S36>/Switch'
                                        */
  real_T Multiply_Gain;                /* Expression: 0.638
                                        * Referenced by: '<S36>/Multiply'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Constant_Value[6];            /* Expression: zeros(1,MaxAxles)
                                        * Referenced by: '<S30>/Constant'
                                        */
  boolean_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S36>/Unit Delay'
                              */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S98>/Logic'
                                        */
  boolean_T Logic_table_f[16];         /* Computed Parameter: Logic_table_f
                                        * Referenced by: '<S97>/Logic'
                                        */
  P_CoreSubsys_TractionSystem_gmy0og_T CoreSubsys_pnae;
                          /* '<S28>/BogieTractionConverterSystem (Per Bogie)' */
  P_CoreSubsys_TractionSystem_gmy0o_T CoreSubsys_pna;/* '<S27>/TractionControl (Per Bogie)' */
};

/* Parameters (default storage) */
struct P_TractionSystem_T_ {
  BD_CommonTrain_Cfg_Vehicle CommonVehicleConfig_Y0;
                                   /* Computed Parameter: CommonVehicleConfig_Y0
                                    * Referenced by: '<S3>/CommonVehicleConfig'
                                    */
  BD_TractionSystem_Cfg_Vehicle TractionSystemVehicleConfig_Y0;
                           /* Computed Parameter: TractionSystemVehicleConfig_Y0
                            * Referenced by: '<S3>/TractionSystemVehicleConfig'
                            */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  P_CoreSubsys_TractionSystem_g_T CoreSubsys_p;/* '<Root>/Traction (Per Vehicle)' */
  P_CoreSubsys_TractionSystem_T CoreSubsys;/* '<S3>/ConfigCheck' */
};

/* Real-time Model Data Structure */
struct tag_RTM_TractionSystem_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[279];
    int32_T* vardimsAddress[279];
    RTWLoggingFcnPtr loggingPtrs[279];
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    int_T mdlref_GlobalTID[1];
  } Timing;
};

typedef struct {
  B_TractionSystem_c_T rtb;
  DW_TractionSystem_f_T rtdw;
  RT_MODEL_TractionSystem_T rtm;
} MdlrefDW_TractionSystem_T;

/* Model reference registration function */
extern void TractionSystem_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_TractionSystem_T *
  const TractionSystem_M, B_TractionSystem_c_T *localB, DW_TractionSystem_f_T
  *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath,
  int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  TractionSystem_GetCAPIStaticMap(void);
extern void TractionSystem_TimerOnDelayNoInit_Init
  (DW_TimerOnDelayNoInit_TractionSystem_T *localDW,
   P_TimerOnDelayNoInit_TractionSystem_T *localP);
extern void TractionSystem_TimerOnDelayNoInit_Start
  (B_TimerOnDelayNoInit_TractionSystem_T *localB,
   DW_TimerOnDelayNoInit_TractionSystem_T *localDW);
extern void TractionSystem_TimerOnDelayNoInit(boolean_T rtu_In,
  B_TimerOnDelayNoInit_TractionSystem_T *localB,
  DW_TimerOnDelayNoInit_TractionSystem_T *localDW,
  P_TimerOnDelayNoInit_TractionSystem_T *localP, real_T rtp_UpperSaturationLimit);
extern void TractionSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_TractionSystem_T *localDW);
extern void TractionSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_TractionSystem_T *localB,
   DW_TimerOffDelayNoInit_TractionSystem_T *localDW);
extern void TractionSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_TractionSystem_T *localB,
  DW_TimerOffDelayNoInit_TractionSystem_T *localDW,
  P_TimerOffDelayNoInit_TractionSystem_T *localP);
extern void TractionSystem_ReplaceZeros_Start(B_ReplaceZeros_TractionSystem_T
  *localB);
extern void TractionSystem_ReplaceZeros(real_T rtu_u,
  B_ReplaceZeros_TractionSystem_T *localB);
extern void TractionSystem_Init(B_TractionSystem_c_T *localB,
  DW_TractionSystem_f_T *localDW);
extern void TractionSystem_Start(B_TractionSystem_c_T *localB,
  DW_TractionSystem_f_T *localDW);
extern void TractionSystem(RT_MODEL_TractionSystem_T * const TractionSystem_M,
  const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8], const
  BD_TractionSystem_Cfg_Vehicle rtu_TractionSystemVehicleConfig[8], const
  BD_TractionSystem_In_Vehicle rtu_TractionSystemVehicleInputs[8], const
  BD_TractionSystem_In_Overrides rtu_Overrides[8], const
  BD_TractionSystem_In_Faults rtu_Faults[8], BD_TractionSystem_Out_Vehicle
  rty_TractionSystemOut[8], B_TractionSystem_c_T *localB, DW_TractionSystem_f_T *
  localDW, const BD_TractionSystem_Prm *rtp_Prm_TractionSystem);

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
 * '<Root>' : 'TractionSystem'
 * '<S1>'   : 'TractionSystem/Configuration'
 * '<S2>'   : 'TractionSystem/Traction (Per Vehicle)'
 * '<S3>'   : 'TractionSystem/Configuration/ConfigProcessing'
 * '<S4>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck'
 * '<S5>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gearing Ratio'
 * '<S6>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gross1'
 * '<S7>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Height1'
 * '<S8>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Length1'
 * '<S9>'   : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles3'
 * '<S10>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles4'
 * '<S11>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles5'
 * '<S12>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Tare1'
 * '<S13>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default WheelDiameter'
 * '<S14>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Width1'
 * '<S15>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gearing Ratio/Min Value'
 * '<S16>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Gross1/Min Value'
 * '<S17>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Height1/Min Value'
 * '<S18>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Length1/Min Value'
 * '<S19>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles3/Min Value'
 * '<S20>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles4/Min Value'
 * '<S21>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default NumberOfAxles5/Min Value'
 * '<S22>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Tare1/Min Value'
 * '<S23>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default WheelDiameter/Min Value'
 * '<S24>'  : 'TractionSystem/Configuration/ConfigProcessing/ConfigCheck/Default Width1/Min Value'
 * '<S25>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle'
 * '<S26>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter'
 * '<S27>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit'
 * '<S28>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem'
 * '<S29>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/AudioOutputsRepack'
 * '<S30>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/DynamicsOutputsRepack'
 * '<S31>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/AudioOutputsRepack/ForEachBogie'
 * '<S32>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/OutputAdapter/DynamicsOutputsRepack/For Each Subsystem'
 * '<S33>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter'
 * '<S34>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/Subsystem'
 * '<S35>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)'
 * '<S36>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits'
 * '<S37>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/BCUOutputsRepack'
 * '<S38>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/ElectricalOutputsRepack'
 * '<S39>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/OutputAdapter/TCMSOutputsRepack'
 * '<S40>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem'
 * '<S41>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUOFFLogic'
 * '<S42>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic'
 * '<S43>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Compare To Constant'
 * '<S44>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/Detect Decrease'
 * '<S45>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/Subsystem/SR Latch - Reset Priority'
 * '<S46>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/BogieTractionBrakingAvailable'
 * '<S47>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/DirectionControl'
 * '<S48>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUControlsAssign'
 * '<S49>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign'
 * '<S50>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl'
 * '<S51>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingInterlocks'
 * '<S52>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/BCUOutCompile'
 * '<S53>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/BogieElectricalOutCompile'
 * '<S54>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TCUOutputsAssign/TCMSOutCompile'
 * '<S55>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/MotorBrakingEffortComputation'
 * '<S56>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/MotorTractionEffortComputation'
 * '<S57>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/SpeedRatio'
 * '<S58>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidBrakingDemandPct'
 * '<S59>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidTractionDemandPct'
 * '<S60>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl'
 * '<S61>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl'
 * '<S62>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/ValidTractionDemandPct/Compare To Zero'
 * '<S63>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Compare To Constant'
 * '<S64>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Compare To Constant1'
 * '<S65>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/SR Latch - Reset Priority'
 * '<S66>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/Stop'
 * '<S67>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit'
 * '<S68>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl'
 * '<S69>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/TimerOnDelay NoInit/Compare To Zero'
 * '<S70>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Rate Limiter Dynamic'
 * '<S71>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort'
 * '<S72>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S73>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Compare To Zero1'
 * '<S74>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Decrease'
 * '<S75>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Increase'
 * '<S76>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/SR Latch - Reset Priority1'
 * '<S77>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/Sample and Hold'
 * '<S78>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit'
 * '<S79>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlideControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Count to 0'
 * '<S80>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Compare To Constant1'
 * '<S81>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Compare To Constant2'
 * '<S82>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/SR Latch - Reset Priority'
 * '<S83>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/Stop'
 * '<S84>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit'
 * '<S85>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl'
 * '<S86>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/TimerOnDelay NoInit/Compare To Zero'
 * '<S87>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Rate Limiter Dynamic'
 * '<S88>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort'
 * '<S89>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S90>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Compare To Zero1'
 * '<S91>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Decrease'
 * '<S92>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Detect Increase'
 * '<S93>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/SR Latch - Reset Priority1'
 * '<S94>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/Sample and Hold'
 * '<S95>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit'
 * '<S96>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionControl (Per Bogie)/TCUONLogic/TractionBrakingDemandControl/WheelSlipControl/WSControl/WSDetectedWhileReapplyingEffort/TimerOffDelay NoInit/Count to 0'
 * '<S97>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState'
 * '<S98>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionControlUnit/TractionConverterCircuits/AKState1'
 * '<S99>'  : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)'
 * '<S100>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem'
 * '<S101>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter'
 * '<S102>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible'
 * '<S103>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor'
 * '<S104>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorDisabled'
 * '<S105>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled'
 * '<S106>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable'
 * '<S107>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque'
 * '<S108>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection'
 * '<S109>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/SpeedRatio'
 * '<S110>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionAvailable'
 * '<S111>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque'
 * '<S112>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable/Compare To Zero'
 * '<S113>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingAvailable/Compare To Zero1'
 * '<S114>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData'
 * '<S115>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveData'
 * '<S116>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations'
 * '<S117>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveInputType'
 * '<S118>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/NoData'
 * '<S119>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/Percentage Variation'
 * '<S120>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/ContourData/Contour Interpolation 2D y'
 * '<S121>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveData/Subset Interpolation 1D'
 * '<S122>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/LimitationCurves'
 * '<S123>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/BrakingTorque/CurveEquations/RampUpCurve'
 * '<S124>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection/Orientation Inversion'
 * '<S125>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/DemandDirectionCorrection/Orientation Inversion/Compare To Constant'
 * '<S126>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData'
 * '<S127>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData'
 * '<S128>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations'
 * '<S129>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveInputType'
 * '<S130>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/NoData'
 * '<S131>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/Percentage Variation'
 * '<S132>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Contour Interpolation 2D y'
 * '<S133>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters'
 * '<S134>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxPowerLookup'
 * '<S135>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/MaxTorqueLookup'
 * '<S136>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/SafeDivide'
 * '<S137>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/ContourData/Limiters/SafeDivide/Replace Zeros'
 * '<S138>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters'
 * '<S139>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Subset Interpolation 1D'
 * '<S140>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/SafeDivide'
 * '<S141>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveData/Limiters/SafeDivide/Replace Zeros'
 * '<S142>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverter/TractionMotor/TractionMotorEnabled/TractionTorque/CurveEquations/LimitationCurves'
 * '<S143>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle'
 * '<S144>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle'
 * '<S145>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/NoMotorAxle'
 * '<S146>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumBraking'
 * '<S147>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumTraction'
 * '<S148>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/SpeedRatio'
 * '<S149>' : 'TractionSystem/Traction (Per Vehicle)/MotorVehicle/VehicleTractionConvertersSystem/BogieTractionConverterSystem (Per Bogie)/TractionConverterSystem/TractionConverterMaxEffortPossible/MotorVehicle/MotorAxle/MaximumBraking/RampUpCurve'
 */
#endif                                 /* RTW_HEADER_TractionSystem_h_ */
