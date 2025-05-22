/*
 * Code generation for system system '<S493>/RampWinder-Rotary'
 * For more details, see corresponding source file RotaryControl.c
 *
 */

#ifndef RTW_HEADER_RotaryControl_h_
#define RTW_HEADER_RotaryControl_h_
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

/* Block signals for system '<S493>/RampWinder-Rotary' */
typedef struct {
  real_T ModeSwitch;                   /* '<S586>/ModeSwitch' */
} B_RotaryControl_T;

/* Block states (default storage) for system '<S493>/RampWinder-Rotary' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S592>/Delay Input1' */
  real_T DelayInput1_DSTATE_h;         /* '<S593>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S586>/Unit Delay' */
} DW_RotaryControl_T;

/* Parameters for system: '<S493>/RampWinder-Rotary' */
struct P_RotaryControl_T_ {
  real_T InitCheck_const;              /* Mask Parameter: InitCheck_const
                                        * Referenced by: '<S587>/Constant'
                                        */
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S594>/Constant'
                                        */
  real_T ModeCheck_const;              /* Mask Parameter: ModeCheck_const
                                        * Referenced by: '<S589>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S592>/Delay Input1'
                                        */
  real_T DetectChange1_vinit;          /* Mask Parameter: DetectChange1_vinit
                                        * Referenced by: '<S593>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S590>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S590>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: length(ControlStates)
                                        * Referenced by: '<S590>/Constant'
                                        */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S588>/InitSource'
                                        */
  int8_T nDLookupTable_tableData[13];
                                  /* Computed Parameter: nDLookupTable_tableData
                                   * Referenced by: '<S590>/n-D Lookup Table'
                                   */
};

extern void RotaryControl_Init(DW_RotaryControl_T *localDW, P_RotaryControl_T
  *localP, real_T rtp_InitState);
extern void RotaryControl_Reset(DW_RotaryControl_T *localDW, P_RotaryControl_T
  *localP, real_T rtp_InitState);
extern void RotaryControl_Start(B_RotaryControl_T *localB, DW_RotaryControl_T
  *localDW);
extern void RotaryControl(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_RotaryControl_T *localB, DW_RotaryControl_T *localDW, P_RotaryControl_T
  *localP, const real_T rtp_ControlStates[13], real_T rtp_InitState);

#endif                                 /* RTW_HEADER_RotaryControl_h_ */
