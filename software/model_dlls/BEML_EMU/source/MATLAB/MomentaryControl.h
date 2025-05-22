/*
 * Code generation for system system '<S3602>/PECUPushButton-Momentary'
 * For more details, see corresponding source file MomentaryControl.c
 *
 */

#ifndef RTW_HEADER_MomentaryControl_h_
#define RTW_HEADER_MomentaryControl_h_
#ifndef IOControls_COMMON_INCLUDES_
# define IOControls_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IOControls_COMMON_INCLUDES_ */

#include "IOControls_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<S3602>/PECUPushButton-Momentary' */
typedef struct {
  real_T ModeSwitch;                   /* '<S3619>/ModeSwitch' */
} B_MomentaryControl_T;

/* Parameters for system: '<S3602>/PECUPushButton-Momentary' */
struct P_MomentaryControl_T_ {
  real_T InitCheck_const;              /* Mask Parameter: InitCheck_const
                                        * Referenced by: '<S3620>/Constant'
                                        */
  real_T InhibitCheck_const;           /* Mask Parameter: InhibitCheck_const
                                        * Referenced by: '<S3624>/Constant'
                                        */
  real_T ModeCheck_const;              /* Mask Parameter: ModeCheck_const
                                        * Referenced by: '<S3622>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S3623>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S3623>/Constant1'
                                        */
  real_T InitSource_Value;             /* Expression: 1
                                        * Referenced by: '<S3621>/InitSource'
                                        */
};

extern void MomentaryControl_Start(B_MomentaryControl_T *localB);
extern void MomentaryControl(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_MomentaryControl_T *localB, P_MomentaryControl_T *localP, real_T
  rtp_InitState);

#endif                                 /* RTW_HEADER_MomentaryControl_h_ */
