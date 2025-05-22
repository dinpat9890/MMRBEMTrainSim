/*
 * Code generation for system system '<S3602>/PECUPushButton-Momentary'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "MomentaryControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"

/*
 * Start for atomic system:
 *    '<S3602>/PECUPushButton-Momentary'
 *    '<S3601>/Microphone-Momentary'
 *    '<S3151>/RightDoor4ManualOpen-Momentary'
 *    '<S3150>/RightDoor4ManualClose-Momentary'
 *    '<S3148>/RightDoor4EED-Momentary'
 *    '<S3145>/RightDoor3ManualOpen-Momentary'
 *    '<S3144>/RightDoor3ManualClose-Momentary'
 *    '<S3142>/RightDoor3EED-Momentary'
 *    '<S3139>/RightDoor2ManualOpen-Momentary'
 *    '<S3138>/RightDoor2ManualClose-Momentary'
 *    ...
 */
void MomentaryControl_Start(B_MomentaryControl_T *localB)
{
  localB->ModeSwitch = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S3602>/PECUPushButton-Momentary'
 *    '<S3601>/Microphone-Momentary'
 *    '<S3151>/RightDoor4ManualOpen-Momentary'
 *    '<S3150>/RightDoor4ManualClose-Momentary'
 *    '<S3148>/RightDoor4EED-Momentary'
 *    '<S3145>/RightDoor3ManualOpen-Momentary'
 *    '<S3144>/RightDoor3ManualClose-Momentary'
 *    '<S3142>/RightDoor3EED-Momentary'
 *    '<S3139>/RightDoor2ManualOpen-Momentary'
 *    '<S3138>/RightDoor2ManualClose-Momentary'
 *    ...
 */
void MomentaryControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal,
                      real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
                      B_MomentaryControl_T *localB, P_MomentaryControl_T *localP,
                      real_T rtp_InitState)
{
  /* Switch: '<S3619>/ModeSwitch' incorporates:
   *  Constant: '<S3620>/Constant'
   *  Constant: '<S3622>/Constant'
   *  Constant: '<S3624>/Constant'
   *  RelationalOperator: '<S3620>/Compare'
   *  RelationalOperator: '<S3622>/Compare'
   *  RelationalOperator: '<S3624>/Compare'
   *  Switch: '<S3619>/InitSwitch'
   *  Switch: '<S3623>/IRQSwitch'
   *  Switch: '<S3623>/InValSwitch'
   *  Switch: '<S3623>/InhibitSwitch'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S3621>/InitialiastionSwitch' incorporates:
     *  Constant: '<S3621>/InitSource'
     *  Constant: '<S3621>/InternalInitialValue'
     *  Switch: '<S3619>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      localB->ModeSwitch = rtp_InitState;
    } else {
      localB->ModeSwitch = rtu_InitVal;
    }

    /* End of Switch: '<S3621>/InitialiastionSwitch' */
  } else if (rtu_Inhibit == localP->InhibitCheck_const) {
    /* Switch: '<S3623>/InhibitSwitch' incorporates:
     *  Constant: '<S3623>/Constant1'
     *  Switch: '<S3619>/InitSwitch'
     */
    localB->ModeSwitch = localP->Constant1_Value;
  } else if (rtu_IRQ != 0.0) {
    /* Switch: '<S3623>/IRQSwitch' incorporates:
     *  Switch: '<S3619>/InitSwitch'
     *  Switch: '<S3623>/InhibitSwitch'
     */
    localB->ModeSwitch = rtu_IRQ;
  } else if (rtu_InVal != 0.0) {
    /* Switch: '<S3623>/InValSwitch' incorporates:
     *  Switch: '<S3619>/InitSwitch'
     *  Switch: '<S3623>/IRQSwitch'
     *  Switch: '<S3623>/InhibitSwitch'
     */
    localB->ModeSwitch = rtu_InVal;
  } else {
    /* Switch: '<S3623>/InhibitSwitch' incorporates:
     *  Constant: '<S3623>/Constant2'
     *  Switch: '<S3619>/InitSwitch'
     *  Switch: '<S3623>/IRQSwitch'
     */
    localB->ModeSwitch = localP->Constant2_Value;
  }

  /* End of Switch: '<S3619>/ModeSwitch' */
}
