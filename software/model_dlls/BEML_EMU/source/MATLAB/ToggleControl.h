/*
 * Code generation for system system '<S3645>/UncouplingCock-Toggle'
 * For more details, see corresponding source file ToggleControl.c
 *
 */

#ifndef RTW_HEADER_ToggleControl_h_
#define RTW_HEADER_ToggleControl_h_
#ifndef IOControls_COMMON_INCLUDES_
# define IOControls_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IOControls_COMMON_INCLUDES_ */

#include "IOControls_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<S3645>/UncouplingCock-Toggle' */
typedef struct {
  real_T Merge;                        /* '<S3846>/Merge' */
} B_ToggleControl_T;

/* Block states (default storage) for system '<S3645>/UncouplingCock-Toggle' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S3846>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S3851>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S3852>/Delay Input1' */
} DW_ToggleControl_T;

/* Parameters for system: '<S3645>/UncouplingCock-Toggle' */
struct P_ToggleControl_T_ {
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S3853>/Constant'
                                        */
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S3851>/Delay Input1'
                                      */
  boolean_T DetectRisePositive1_vinit;
                                    /* Mask Parameter: DetectRisePositive1_vinit
                                     * Referenced by: '<S3852>/Delay Input1'
                                     */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S3848>/InitSource'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3854>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S3855>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S3846>/Unit Delay'
                                        */
};

extern void ToggleControl_Init(DW_ToggleControl_T *localDW, P_ToggleControl_T
  *localP);
extern void ToggleControl_Reset(DW_ToggleControl_T *localDW, P_ToggleControl_T
  *localP);
extern void ToggleControl_Start(B_ToggleControl_T *localB, DW_ToggleControl_T
  *localDW);
extern void ToggleControl(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_ToggleControl_T *localB, DW_ToggleControl_T *localDW, P_ToggleControl_T
  *localP, real_T rtp_OffStateValue, real_T rtp_OnStateValue, real_T
  rtp_InitState);

#endif                                 /* RTW_HEADER_ToggleControl_h_ */
