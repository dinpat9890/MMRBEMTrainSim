/*
 * Code generation for system model 'PantographSystem'
 * For more details, see corresponding source file PantographSystem.c
 *
 */

#ifndef RTW_HEADER_PantographSystem_h_
#define RTW_HEADER_PantographSystem_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef PantographSystem_COMMON_INCLUDES_
# define PantographSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PantographSystem_COMMON_INCLUDES_ */

#include "PantographSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<Root>/PantographSystemPerVehicle' */
typedef struct {
  BD_PantographSystem_Out_Vehicle BusAssignment;/* '<S4>/Bus Assignment' */
} B_CoreSubsys_PantographSystem_T;

/* Block states (default storage) for system '<Root>/PantographSystemPerVehicle' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S8>/Delay Input1' */
  real_T UnitDelay1_DSTATE;            /* '<S9>/Unit Delay1' */
  real_T DelayInput1_DSTATE_p;         /* '<S17>/Delay Input1' */
  real_T DelayInput1_DSTATE_l;         /* '<S16>/Delay Input1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S2>/Unit Delay3' */
  boolean_T UnitDelay2_DSTATE;         /* '<S2>/Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S2>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE;          /* '<S2>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S5>/Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S12>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S27>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S25>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S9>/IC' */
  boolean_T Memory_PreviousInput_p;    /* '<S26>/Memory' */
} DW_CoreSubsys_PantographSystem_T;

/* Block signals for model 'PantographSystem' */
typedef struct {
  B_CoreSubsys_PantographSystem_T CoreSubsys[8];/* '<Root>/PantographSystemPerVehicle' */
} B_PantographSystem_c_T;

/* Block states (default storage) for model 'PantographSystem' */
typedef struct {
  DW_CoreSubsys_PantographSystem_T CoreSubsys[8];/* '<Root>/PantographSystemPerVehicle' */
} DW_PantographSystem_f_T;

/* Parameters for system: '<S18>/DOWN' */
struct P_DOWN_PantographSystem_T_ {
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S22>/Constant'
                                        */
};

/* Parameters for system: '<Root>/PantographSystemPerVehicle' */
struct P_CoreSubsys_PantographSystem_T_ {
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S14>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S15>/Constant'
                                      */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S8>/Delay Input1'
                                        */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S17>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_a;       /* Mask Parameter: DetectDecrease_vinit_a
                                        * Referenced by: '<S16>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority_initial_condition;
                       /* Mask Parameter: SRLatchResetPriority_initial_condition
                        * Referenced by: '<S12>/Memory'
                        */
  boolean_T SRLatchResetPriority_initial_condition_h;
                     /* Mask Parameter: SRLatchResetPriority_initial_condition_h
                      * Referenced by: '<S27>/Memory'
                      */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S25>/Memory'
                       */
  boolean_T SRLatchResetPriority2_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority2_initial_condition
                       * Referenced by: '<S26>/Memory'
                       */
  BD_PantographSystem_Out_Vehicle PantographSystemVehicleOutputs_Y0;
                        /* Computed Parameter: PantographSystemVehicleOutputs_Y0
                         * Referenced by: '<S2>/PantographSystemVehicleOutputs'
                         */
  BD_PantographSystem_Out_Vehicle Constant3_Value;/* Computed Parameter: Constant3_Value
                                                   * Referenced by: '<S4>/Constant3'
                                                   */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T OnlyGoesDOWN_Gain;            /* Expression: -1
                                        * Referenced by: '<S10>/OnlyGoesDOWN'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Speed_Threshold;              /* Expression: 0
                                        * Referenced by: '<S10>/Speed'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S9>/Weighted Sample Time'
                                   */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T Constant3_Value_e;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay1'
                                        */
  boolean_T Constant_Value_o;          /* Expression: false
                                        * Referenced by: '<S29>/Constant'
                                        */
  boolean_T UnitDelay3_InitialCondition;
                              /* Computed Parameter: UnitDelay3_InitialCondition
                               * Referenced by: '<S2>/Unit Delay3'
                               */
  boolean_T UnitDelay2_InitialCondition;
                              /* Computed Parameter: UnitDelay2_InitialCondition
                               * Referenced by: '<S2>/Unit Delay2'
                               */
  boolean_T UnitDelay1_InitialCondition_e;
                            /* Computed Parameter: UnitDelay1_InitialCondition_e
                             * Referenced by: '<S2>/Unit Delay1'
                             */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S2>/Unit Delay'
                                */
  boolean_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S5>/Unit Delay'
                              */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S9>/IC'
                                        */
  boolean_T Constant_Value_e;          /* Expression: true
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Dummy_Gain;                  /* Computed Parameter: Dummy_Gain
                                        * Referenced by: '<S3>/Dummy'
                                        */
  uint8_T Dummy1_Gain;                 /* Computed Parameter: Dummy1_Gain
                                        * Referenced by: '<S3>/Dummy1'
                                        */
  uint8_T Dummy2_Gain;                 /* Computed Parameter: Dummy2_Gain
                                        * Referenced by: '<S3>/Dummy2'
                                        */
  P_DOWN_PantographSystem_T NoPantoCommand;/* '<S18>/NoPantoCommand' */
  P_DOWN_PantographSystem_T UP;        /* '<S18>/UP' */
  P_DOWN_PantographSystem_T DOWN;      /* '<S18>/DOWN' */
};

/* Parameters (default storage) */
struct P_PantographSystem_T_ {
  P_CoreSubsys_PantographSystem_T CoreSubsys;/* '<Root>/PantographSystemPerVehicle' */
};

/* Real-time Model Data Structure */
struct tag_RTM_PantographSystem_T {
  const char_T **errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[37];
    int32_T* vardimsAddress[37];
    RTWLoggingFcnPtr loggingPtrs[37];
  } DataMapInfo;
};

typedef struct {
  B_PantographSystem_c_T rtb;
  DW_PantographSystem_f_T rtdw;
  RT_MODEL_PantographSystem_T rtm;
} MdlrefDW_PantographSystem_T;

/* Model reference registration function */
extern void PantographSystem_initialize(const char_T **rt_errorStatus,
  RT_MODEL_PantographSystem_T *const PantographSystem_M, B_PantographSystem_c_T *
  localB, DW_PantographSystem_f_T *localDW, rtwCAPI_ModelMappingInfo
  *rt_ParentMMI, const char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T
  rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  PantographSystem_GetCAPIStaticMap(void);
extern void PantographSystem_DOWN(real_T *rty_PantoCommand,
  P_DOWN_PantographSystem_T *localP);
extern void PantographSystem_Init(B_PantographSystem_c_T *localB,
  DW_PantographSystem_f_T *localDW);
extern void PantographSystem_Start(B_PantographSystem_c_T *localB,
  DW_PantographSystem_f_T *localDW);
extern void PantographSystem(const BD_CommonTrain_Cfg_Vehicle
  rtu_CommonVehicleConfig[8], const BD_PantographSystem_Cfg_Vehicle
  rtu_PantographSystemVehicleConfig[8], const BD_PantographSystem_In_Vehicle
  rtu_PantographSystemVehicleInputs[8], const
  BD_PantographSystem_In_Vehicle_Overrides rtu_Overrides[8],
  BD_PantographSystem_Out_Vehicle rty_PantographSystemVehicleOutputs[8],
  B_PantographSystem_c_T *localB, DW_PantographSystem_f_T *localDW, const
  BD_PantographSystem_Prm *rtp_Prm_PantographSystem);

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
 * '<Root>' : 'PantographSystem'
 * '<S1>'   : 'PantographSystem/PantographSystemPerVehicle'
 * '<S2>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle'
 * '<S3>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/FaultProcessingandVoltageDetection'
 * '<S4>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/OutputsPacking'
 * '<S5>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches'
 * '<S6>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit'
 * '<S7>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoSystemSupply'
 * '<S8>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Detect Decrease'
 * '<S9>'   : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Discrete Dynamic Limited Integrator1'
 * '<S10>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoActuation'
 * '<S11>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches'
 * '<S12>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/SR Latch - Reset Priority'
 * '<S13>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Discrete Dynamic Limited Integrator1/Saturation Dynamic'
 * '<S14>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Compare To Constant1'
 * '<S15>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Compare To Constant2'
 * '<S16>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Detect Decrease'
 * '<S17>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Detect Increase'
 * '<S18>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic'
 * '<S19>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoDOWNCommand'
 * '<S20>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoEMERCommand'
 * '<S21>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoUPCommand'
 * '<S22>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/DOWN'
 * '<S23>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/NoPantoCommand'
 * '<S24>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/UP'
 * '<S25>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoDOWNCommand/SR Latch - Reset Priority1'
 * '<S26>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoEMERCommand/SR Latch - Reset Priority2'
 * '<S27>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoUPCommand/SR Latch - Reset Priority'
 * '<S28>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoSystemSupply/ElectricSupply'
 * '<S29>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoSystemSupply/NoPantoSupply'
 * '<S30>'  : 'PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoSystemSupply/PneumaticSupply'
 */
#endif                                 /* RTW_HEADER_PantographSystem_h_ */
