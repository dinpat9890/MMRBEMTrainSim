/*
 * Code generation for system system '<S21>/ModeSelector-Increment'
 * For more details, see corresponding source file IOControls_IncrementControl_h.c
 *
 */

#ifndef RTW_HEADER_IOControls_IncrementControl_h_h_
#define RTW_HEADER_IOControls_IncrementControl_h_h_
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

/* Block signals for system '<S21>/ModeSelector-Increment' */
typedef struct {
  real_T ModeSwitch;                   /* '<S51>/ModeSwitch' */
} B_IncrementControl_h_T;

/* Block states (default storage) for system '<S21>/ModeSelector-Increment' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S57>/Delay Input1' */
  real_T DelayInput1_DSTATE_m;         /* '<S58>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S51>/Unit Delay' */
} DW_IncrementControl_n_T;

/* Parameters for system: '<S21>/ModeSelector-Increment' */
struct P_IncrementControl_l_T_ {
  real_T InitCheck_const;              /* Mask Parameter: InitCheck_const
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T ModeCheck_const;              /* Mask Parameter: ModeCheck_const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S57>/Delay Input1'
                                        */
  real_T DetectChange1_vinit;          /* Mask Parameter: DetectChange1_vinit
                                        * Referenced by: '<S58>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S55>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S55>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: (length(ControlStates)-1)
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S53>/InitSource'
                                        */
  int8_T nDLookupTable_tableData[6];
                                  /* Computed Parameter: nDLookupTable_tableData
                                   * Referenced by: '<S55>/n-D Lookup Table'
                                   */
};

extern void IOControls_IncrementControl_a_Init(DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_h_Reset(DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, real_T rtp_InitState);
extern void IOControls_IncrementControl_m_Start(B_IncrementControl_h_T *localB,
  DW_IncrementControl_n_T *localDW);
extern void IOControls_IncrementControl_h(real_T rtu_InVal, real_T rtu_InMode,
  real_T rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_h_T *localB, DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, const real_T rtp_ControlStates[6], real_T
  rtp_InitState);

#endif                         /* RTW_HEADER_IOControls_IncrementControl_h_h_ */
