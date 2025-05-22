/*
 * Code generation for system system '<S342>/HoldDoorCloseBypassSS-Increment'
 * For more details, see corresponding source file IOControls_IncrementControl.c
 *
 */

#ifndef RTW_HEADER_IOControls_IncrementControl_h_
#define RTW_HEADER_IOControls_IncrementControl_h_
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

/* Block signals for system '<S342>/HoldDoorCloseBypassSS-Increment' */
typedef struct {
  real_T ModeSwitch;                   /* '<S415>/ModeSwitch' */
} B_IncrementControl_c_T;

/* Block states (default storage) for system '<S342>/HoldDoorCloseBypassSS-Increment' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S421>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S422>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S415>/Unit Delay' */
} DW_IncrementControl_k_T;

/* Parameters for system: '<S342>/HoldDoorCloseBypassSS-Increment' */
struct P_IncrementControl_f_T_ {
  real_T InitCheck_const;              /* Mask Parameter: InitCheck_const
                                        * Referenced by: '<S416>/Constant'
                                        */
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S423>/Constant'
                                        */
  real_T ModeCheck_const;              /* Mask Parameter: ModeCheck_const
                                        * Referenced by: '<S418>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S421>/Delay Input1'
                                        */
  real_T DetectChange1_vinit;          /* Mask Parameter: DetectChange1_vinit
                                        * Referenced by: '<S422>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S419>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S419>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: (length(ControlStates)-1)
                                        * Referenced by: '<S419>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S419>/Saturation'
                                        */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S417>/InitSource'
                                        */
  int8_T nDLookupTable_tableData[3];
                                  /* Computed Parameter: nDLookupTable_tableData
                                   * Referenced by: '<S419>/n-D Lookup Table'
                                   */
};

extern void IOControls_IncrementControl_Init(DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_Reset(DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_Start(B_IncrementControl_c_T *localB,
  DW_IncrementControl_k_T *localDW);
extern void IOControls_IncrementControl(real_T rtu_InVal, real_T rtu_InMode,
  real_T rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_c_T *localB, DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, const real_T rtp_ControlStates[3], real_T
  rtp_InitState);

#endif                           /* RTW_HEADER_IOControls_IncrementControl_h_ */
