/*
 * Code generation for system system '<S20>/MasterControllerHandle-Increment'
 * For more details, see corresponding source file IOControls_IncrementControl_a.c
 *
 */

#ifndef RTW_HEADER_IOControls_IncrementControl_a_h_
#define RTW_HEADER_IOControls_IncrementControl_a_h_
#ifndef IOControls_COMMON_INCLUDES_
# define IOControls_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IOControls_COMMON_INCLUDES_ */

#include "IOControls_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S20>/MasterControllerHandle-Increment' */
typedef struct {
  real_T ModeSwitch;                   /* '<S42>/ModeSwitch' */
} B_IncrementControl_f_T;

/* Block states (default storage) for system '<S20>/MasterControllerHandle-Increment' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S48>/Delay Input1' */
  real_T DelayInput1_DSTATE_f;         /* '<S49>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S42>/Unit Delay' */
} DW_IncrementControl_j_T;

/* Parameters for system: '<S20>/MasterControllerHandle-Increment' */
struct P_IncrementControl_k_T_ {
  real_T InitCheck_const;              /* Mask Parameter: InitCheck_const
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T ModeCheck_const;              /* Mask Parameter: ModeCheck_const
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S48>/Delay Input1'
                                        */
  real_T DetectChange1_vinit;          /* Mask Parameter: DetectChange1_vinit
                                        * Referenced by: '<S49>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: (length(ControlStates)-1)
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S44>/InitSource'
                                        */
  int8_T nDLookupTable_tableData[22];
                                  /* Computed Parameter: nDLookupTable_tableData
                                   * Referenced by: '<S46>/n-D Lookup Table'
                                   */
};

extern void IOControls_IncrementControl_n_Init(DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_n_Reset(DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_a_Start(B_IncrementControl_f_T *localB,
  DW_IncrementControl_j_T *localDW);
extern void IOControls_IncrementControl_a(real_T rtu_InVal, real_T rtu_InMode,
  real_T rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_f_T *localB, DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, const real_T rtp_ControlStates[22], real_T
  rtp_InitState);

#endif                         /* RTW_HEADER_IOControls_IncrementControl_a_h_ */
