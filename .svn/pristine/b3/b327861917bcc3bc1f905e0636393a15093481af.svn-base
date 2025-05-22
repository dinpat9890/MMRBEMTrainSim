/*
 * Code generation for system model 'CouplingSystem'
 * For more details, see corresponding source file CouplingSystem.c
 *
 */

#ifndef RTW_HEADER_CouplingSystem_h_
#define RTW_HEADER_CouplingSystem_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef CouplingSystem_COMMON_INCLUDES_
# define CouplingSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* CouplingSystem_COMMON_INCLUDES_ */

#include "CouplingSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Block signals for system '<S25>/TimerOffDelay NoInit' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S30>/Logical Operator1' */
} B_TimerOffDelayNoInit_CouplingSystem_T;

/* Block states (default storage) for system '<S25>/TimerOffDelay NoInit' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S30>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S30>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S30>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S30>/IC' */
} DW_TimerOffDelayNoInit_CouplingSystem_T;

/* Block states (default storage) for system '<S4>/PerEachHeadAndTailCouperGeneralCoupling' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S46>/Delay Input1' */
  real_T Timer_DSTATE;                 /* '<S38>/Timer' */
  int8_T Timer_PrevResetState;         /* '<S38>/Timer' */
  boolean_T Memory_PreviousInput;      /* '<S52>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S45>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S39>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S56>/Memory' */
} DW_CoreSubsys_CouplingSystem_f_T;

/* Block signals for system '<Root>/CouplingSystemPerCar' */
typedef struct {
  BD_CouplingSystem_Out_Vehicle BusAssignment;/* '<S5>/Bus Assignment' */
  real_T OverrideifDMS[2];             /* '<S10>/Override if DMS' */
  real_T OverrideifDMS_h[2];           /* '<S11>/Override if DMS' */
  real_T OverrideifDMS_o[2];           /* '<S12>/Override if DMS' */
  real_T OverrideifDMS_l[2];           /* '<S14>/Override if DMS' */
  B_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit_f;/* '<S28>/TimerOffDelay NoInit' */
  B_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit;/* '<S25>/TimerOffDelay NoInit' */
} B_CoreSubsys_CouplingSystem_T;

/* Block states (default storage) for system '<Root>/CouplingSystemPerCar' */
typedef struct {
  BD_CouplingSystem_Out_Vehicle_SingleCoupler UnitDelay_DSTATE[2];/* '<S4>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S32>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S29>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S24>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S23>/Memory' */
  DW_CoreSubsys_CouplingSystem_f_T CoreSubsys[2];
                            /* '<S4>/PerEachHeadAndTailCouperGeneralCoupling' */
  DW_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit_f;/* '<S28>/TimerOffDelay NoInit' */
  DW_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit;/* '<S25>/TimerOffDelay NoInit' */
} DW_CoreSubsys_CouplingSystem_T;

/* Block signals for model 'CouplingSystem' */
typedef struct {
  boolean_T NOT[16];                   /* '<Root>/NOT' */
  boolean_T VectorConcatenate2[10];    /* '<S2>/Vector Concatenate2' */
  boolean_T VectorConcatenate2_h[10];  /* '<S61>/Vector Concatenate2' */
  boolean_T ImpAsg_InsertedFor_ElectricallyCoupledVehicle_at_inport_0[16];/* '<S63>/ForEachCoupler' */
  boolean_T ImpAsg_InsertedFor_HasCab_at_inport_0[8];
  B_CoreSubsys_CouplingSystem_T CoreSubsys[8];/* '<Root>/CouplingSystemPerCar' */
} B_CouplingSystem_c_T;

/* Block states (default storage) for model 'CouplingSystem' */
typedef struct {
  DW_CoreSubsys_CouplingSystem_T CoreSubsys[8];/* '<Root>/CouplingSystemPerCar' */
} DW_CouplingSystem_f_T;

/* Parameters for system: '<S25>/TimerOffDelay NoInit' */
struct P_TimerOffDelayNoInit_CouplingSystem_T_ {
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S30>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S30>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S30>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S30>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S30>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S30>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S4>/PerEachHeadAndTailCouperGeneralCoupling' */
struct P_CoreSubsys_CouplingSystem_g_T_ {
  real_T TriggerOtherCoupling_UpperSaturationLimit;
                    /* Mask Parameter: TriggerOtherCoupling_UpperSaturationLimit
                     * Referenced by: '<S38>/Timer'
                     */
  real_T CloseRange_const;             /* Mask Parameter: CloseRange_const
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T WithinRange_const;            /* Mask Parameter: WithinRange_const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T WithinRange1_const;           /* Mask Parameter: WithinRange1_const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T MovedAway_const;              /* Mask Parameter: MovedAway_const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S52>/Memory'
                        */
  boolean_T CoupledState_initial_condition;
                               /* Mask Parameter: CoupledState_initial_condition
                                * Referenced by: '<S45>/Memory'
                                */
  boolean_T Head_initial_condition;    /* Mask Parameter: Head_initial_condition
                                        * Referenced by: '<S39>/Memory'
                                        */
  boolean_T SRR_initial_condition;     /* Mask Parameter: SRR_initial_condition
                                        * Referenced by: '<S56>/Memory'
                                        */
  BD_CouplingSystem_Out_Vehicle_Debug_PerCoupler Constant_Value;/* Computed Parameter: Constant_Value
                                                                 * Referenced by: '<S50>/Constant'
                                                                 */
  BD_CouplerSystem_InterfaceData Constant_Value_k;/* Computed Parameter: Constant_Value_k
                                                   * Referenced by: '<S9>/Constant'
                                                   */
  BD_CouplingSystem_Out_Vehicle_Coupler_PhysicalSignals Constant1_Value;/* Computed Parameter: Constant1_Value
                                                                      * Referenced by: '<S9>/Constant1'
                                                                      */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Timer_gainval;                /* Computed Parameter: Timer_gainval
                                        * Referenced by: '<S38>/Timer'
                                        */
  real_T Timer_IC;                     /* Expression: 0
                                        * Referenced by: '<S38>/Timer'
                                        */
  real_T Timer_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S38>/Timer'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T MinAutoCouplingSpeed_Value;   /* Expression: 0.6/3.6
                                        * Referenced by: '<S37>/MinAutoCouplingSpeed'
                                        */
  real_T ApproachSpeed_Gain;           /* Expression: -1
                                        * Referenced by: '<S43>/ApproachSpeed'
                                        */
  real_T MaxAutoCouplingSpeed_Value;   /* Expression: 5/3.6
                                        * Referenced by: '<S37>/MaxAutoCouplingSpeed'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S37>/Switch'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S35>/Switch2'
                                        */
};

/* Parameters for system: '<Root>/CouplingSystemPerCar' */
struct P_CoreSubsys_CouplingSystem_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S17>/Constant'
                                       */
  real_T CompareToConstant_const_j; /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S18>/Constant'
                                     */
  real_T CompareToConstant_const_a; /* Mask Parameter: CompareToConstant_const_a
                                     * Referenced by: '<S19>/Constant'
                                     */
  real_T CompareToConstant_const_d; /* Mask Parameter: CompareToConstant_const_d
                                     * Referenced by: '<S20>/Constant'
                                     */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S21>/Constant'
                                     */
  real_T CompareToConstant_const_dg;
                                   /* Mask Parameter: CompareToConstant_const_dg
                                    * Referenced by: '<S22>/Constant'
                                    */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S29>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S32>/Delay Input1'
                                        */
  boolean_T SRLatchSetPriority2_initial_condition;
                        /* Mask Parameter: SRLatchSetPriority2_initial_condition
                         * Referenced by: '<S24>/Memory'
                         */
  boolean_T SRLatchSetPriority1_initial_condition;
                        /* Mask Parameter: SRLatchSetPriority1_initial_condition
                         * Referenced by: '<S23>/Memory'
                         */
  BD_CouplingSystem_Out_Vehicle CouplerSystemOut_Y0;
                                      /* Computed Parameter: CouplerSystemOut_Y0
                                       * Referenced by: '<S3>/CouplerSystemOut'
                                       */
  BD_CouplingSystem_Out_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                                * Referenced by: '<S5>/Constant'
                                                */
  BD_CouplingSystem_Out_Vehicle_Debug Constant1_Value;/* Computed Parameter: Constant1_Value
                                                       * Referenced by: '<S60>/Constant1'
                                                       */
  BD_CouplingSystem_Out_Vehicle_SingleCoupler UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S4>/Unit Delay'
                                */
  real_T Constant1_Value_f;            /* Expression: 2
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: 2
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 2
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 2
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant_Value_kt;            /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 2
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 2
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant1_Value_jn[2];        /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Temporary_ReadyToCouple_Value;/* Expression: 1
                                        * Referenced by: '<S6>/Temporary_ReadyToCouple'
                                        */
  real_T Constant2_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant4_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Constant6_Value[2];           /* Expression: [2 2]
                                        * Referenced by: '<S6>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant7'
                                        */
  real_T Constant12_Value[2];          /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant12'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant5_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant5'
                                        */
  real_T Constant11_Value[2];          /* Expression: [0 0]
                                        * Referenced by: '<S6>/Constant11'
                                        */
  real_T Switch2_Threshold;            /* Expression: 2
                                        * Referenced by: '<S8>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S26>/Switch3'
                                        */
  real_T Switch3_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S27>/Switch3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 2
                                        * Referenced by: '<S8>/Switch1'
                                        */
  P_CoreSubsys_CouplingSystem_g_T CoreSubsys;
                            /* '<S4>/PerEachHeadAndTailCouperGeneralCoupling' */
  P_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit_f;/* '<S28>/TimerOffDelay NoInit' */
  P_TimerOffDelayNoInit_CouplingSystem_T TimerOffDelayNoInit;/* '<S25>/TimerOffDelay NoInit' */
};

/* Parameters (default storage) */
struct P_CouplingSystem_T_ {
  real_T Step_Time;                    /* Expression: 5
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  boolean_T ForUnitConnection_Value;   /* Expression: true
                                        * Referenced by: '<S2>/ForUnitConnection'
                                        */
  boolean_T ForTrainConnection_Value;  /* Expression: false
                                        * Referenced by: '<S61>/ForTrainConnection'
                                        */
  P_CoreSubsys_CouplingSystem_T CoreSubsys;/* '<Root>/CouplingSystemPerCar' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CouplingSystem_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[108];
    int32_T* vardimsAddress[108];
    RTWLoggingFcnPtr loggingPtrs[108];
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
  B_CouplingSystem_c_T rtb;
  DW_CouplingSystem_f_T rtdw;
  RT_MODEL_CouplingSystem_T rtm;
} MdlrefDW_CouplingSystem_T;

/* Model reference registration function */
extern void CouplingSystem_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_CouplingSystem_T *
  const CouplingSystem_M, B_CouplingSystem_c_T *localB, DW_CouplingSystem_f_T
  *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath,
  int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  CouplingSystem_GetCAPIStaticMap(void);
extern void CouplingSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_CouplingSystem_T *localDW);
extern void CouplingSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_CouplingSystem_T *localB,
   DW_TimerOffDelayNoInit_CouplingSystem_T *localDW);
extern void CouplingSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_CouplingSystem_T *localB,
  DW_TimerOffDelayNoInit_CouplingSystem_T *localDW,
  P_TimerOffDelayNoInit_CouplingSystem_T *localP);
extern void CouplingSystem_Init(B_CouplingSystem_c_T *localB,
  DW_CouplingSystem_f_T *localDW);
extern void CouplingSystem_Start(B_CouplingSystem_c_T *localB,
  DW_CouplingSystem_f_T *localDW);
extern void CouplingSystem(RT_MODEL_CouplingSystem_T * const CouplingSystem_M,
  const BD_CouplingSystem_Cfg_Vehicle rtu_CouplingVehicleConfig[8], const
  BD_CouplingSystem_In_Vehicle rtu_CouplingInput[8],
  BD_CouplingSystem_Out_Vehicle rty_CouplingOutput[8], B_CouplingSystem_c_T
  *localB, DW_CouplingSystem_f_T *localDW);

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
 * '<Root>' : 'CouplingSystem'
 * '<S1>'   : 'CouplingSystem/CouplingSystemPerCar'
 * '<S2>'   : 'CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection'
 * '<S3>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem'
 * '<S4>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic'
 * '<S5>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/OutputsPacking'
 * '<S6>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling'
 * '<S7>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/CouplingConnectionsFromMVP'
 * '<S8>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle'
 * '<S9>'   : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling'
 * '<S10>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers'
 * '<S11>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1'
 * '<S12>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2'
 * '<S13>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers3'
 * '<S14>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4'
 * '<S15>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers5'
 * '<S16>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics'
 * '<S17>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers/Compare To Constant'
 * '<S18>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers1/Compare To Constant'
 * '<S19>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers2/Compare To Constant'
 * '<S20>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers3/Compare To Constant'
 * '<S21>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers4/Compare To Constant'
 * '<S22>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/AssignValueToCouplers5/Compare To Constant'
 * '<S23>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/SR Latch - Set Priority1'
 * '<S24>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/AcrossUnitCoupling/ElectricHeadPneumatics/SR Latch - Set Priority2'
 * '<S25>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse'
 * '<S26>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/MaskInitalisation'
 * '<S27>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/MaskInitalisation1'
 * '<S28>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse'
 * '<S29>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/Detect Increase'
 * '<S30>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit'
 * '<S31>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/LeadingEdgePulse/TimerOffDelay NoInit/Count to 0'
 * '<S32>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/Detect Decrease'
 * '<S33>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit'
 * '<S34>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/Output Control State and Audio Per Vehicle/TrailingEdgePulse/TimerOffDelay NoInit/Count to 0'
 * '<S35>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled'
 * '<S36>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled1'
 * '<S37>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler'
 * '<S38>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling'
 * '<S39>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled/Head'
 * '<S40>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled/NotInterfacing'
 * '<S41>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled1/Head'
 * '<S42>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/DetermineIfSystemCoupled1/NotInterfacing'
 * '<S43>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/AutocoupleEvent'
 * '<S44>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Close Range'
 * '<S45>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/CoupledState'
 * '<S46>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Detect Decrease'
 * '<S47>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/DoCouplersMatch'
 * '<S48>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/NotInterfacing'
 * '<S49>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1'
 * '<S50>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/Subsystem'
 * '<S51>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/AutocoupleEvent/CouplingSpeedOK'
 * '<S52>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/AutocoupleEvent/SR Latch - Reset Priority'
 * '<S53>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/DoCouplersMatch/Compare To Zero'
 * '<S54>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/DoCouplersMatch/Compare To Zero1'
 * '<S55>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/MovedAway'
 * '<S56>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/SRR'
 * '<S57>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/Within Range'
 * '<S58>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/GeneralMechanicalCouplingPerCoupler/RescueCondition1/Within Range1'
 * '<S59>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/CouplingLogic/PerEachHeadAndTailCouperGeneralCoupling/TriggerOtherCoupling/Compare To Zero'
 * '<S60>'  : 'CouplingSystem/CouplingSystemPerCar/CouplerSystem/OutputsPacking/Subsystem'
 * '<S61>'  : 'CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/SelectVehicleUp1'
 * '<S62>'  : 'CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/Subsystem'
 * '<S63>'  : 'CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/VehicleCouplingSystem'
 * '<S64>'  : 'CouplingSystem/MVP capability for generation of TrainConnection and UnitConnection/VehicleCouplingSystem/ForEachCoupler'
 */
#endif                                 /* RTW_HEADER_CouplingSystem_h_ */
