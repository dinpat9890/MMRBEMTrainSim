/*
 * Code generation for system system '<S493>/RampWinder-Rotary'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "RotaryControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"
#include "look1_ts8Dd_binlcapw.h"
#include "rt_modd_snf.h"

/*
 * System initialize for atomic system:
 *    '<S493>/RampWinder-Rotary'
 *    '<S484>/DoorWinder-Rotary'
 */
void RotaryControl_Init(DW_RotaryControl_T *localDW, P_RotaryControl_T *localP,
  real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S592>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S593>/Delay Input1' */
  localDW->DelayInput1_DSTATE_h = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S586>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * System reset for atomic system:
 *    '<S493>/RampWinder-Rotary'
 *    '<S484>/DoorWinder-Rotary'
 */
void RotaryControl_Reset(DW_RotaryControl_T *localDW, P_RotaryControl_T *localP,
  real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S592>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S593>/Delay Input1' */
  localDW->DelayInput1_DSTATE_h = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S586>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * Start for atomic system:
 *    '<S493>/RampWinder-Rotary'
 *    '<S484>/DoorWinder-Rotary'
 */
void RotaryControl_Start(B_RotaryControl_T *localB, DW_RotaryControl_T *localDW)
{
  localDW->DelayInput1_DSTATE = 0.0;
  localDW->DelayInput1_DSTATE_h = 0.0;
  localDW->UnitDelay_DSTATE = 0.0;
  localB->ModeSwitch = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S493>/RampWinder-Rotary'
 *    '<S484>/DoorWinder-Rotary'
 */
void RotaryControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal,
                   real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
                   B_RotaryControl_T *localB, DW_RotaryControl_T *localDW,
                   P_RotaryControl_T *localP, const real_T rtp_ControlStates[13],
                   real_T rtp_InitState)
{
  real_T maxV;
  int32_T sigIdx;
  real_T rtb_IncDecRq;
  real_T u1;

  /* Switch: '<S586>/ModeSwitch' incorporates:
   *  Constant: '<S587>/Constant'
   *  Constant: '<S589>/Constant'
   *  Constant: '<S594>/Constant'
   *  RelationalOperator: '<S587>/Compare'
   *  RelationalOperator: '<S589>/Compare'
   *  RelationalOperator: '<S592>/FixPt Relational Operator'
   *  RelationalOperator: '<S593>/FixPt Relational Operator'
   *  RelationalOperator: '<S594>/Compare'
   *  Switch: '<S586>/InitSwitch'
   *  Switch: '<S590>/IRQSwitch'
   *  Switch: '<S590>/InValSwitch'
   *  Switch: '<S590>/InhibitSwitch'
   *  UnitDelay: '<S592>/Delay Input1'
   *  UnitDelay: '<S593>/Delay Input1'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S588>/InitialiastionSwitch' incorporates:
     *  Constant: '<S588>/InitSource'
     *  Constant: '<S588>/InternalInitialValue'
     *  Switch: '<S586>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      rtb_IncDecRq = rtp_InitState;
    } else {
      rtb_IncDecRq = rtu_InitVal;
    }

    /* End of Switch: '<S588>/InitialiastionSwitch' */

    /* MinMax: '<S588>/MinMax' incorporates:
     *  Constant: '<S588>/Constant2'
     *  Switch: '<S586>/InitSwitch'
     */
    maxV = rtp_ControlStates[0];
    for (sigIdx = 0; sigIdx < 12; sigIdx++) {
      u1 = rtp_ControlStates[sigIdx + 1];
      if ((!(maxV > u1)) && (!rtIsNaN(u1))) {
        maxV = u1;
      }
    }

    /* Switch: '<S591>/Switch2' incorporates:
     *  MinMax: '<S588>/MinMax'
     *  RelationalOperator: '<S591>/LowerRelop1'
     *  Switch: '<S586>/InitSwitch'
     */
    if (rtb_IncDecRq > maxV) {
      localB->ModeSwitch = maxV;
    } else {
      /* MinMax: '<S588>/MinMax1' incorporates:
       *  Constant: '<S588>/Constant2'
       */
      maxV = rtp_ControlStates[0];
      for (sigIdx = 0; sigIdx < 12; sigIdx++) {
        u1 = rtp_ControlStates[sigIdx + 1];
        if ((!(maxV < u1)) && (!rtIsNaN(u1))) {
          maxV = u1;
        }
      }

      /* Switch: '<S591>/Switch' incorporates:
       *  MinMax: '<S588>/MinMax1'
       *  RelationalOperator: '<S591>/UpperRelop'
       */
      if (rtb_IncDecRq < maxV) {
        localB->ModeSwitch = maxV;
      } else {
        localB->ModeSwitch = rtb_IncDecRq;
      }

      /* End of Switch: '<S591>/Switch' */
    }

    /* End of Switch: '<S591>/Switch2' */
  } else {
    if (rtu_Inhibit == localP->InhibitCheck_const) {
      /* Switch: '<S590>/InhibitSwitch' incorporates:
       *  Constant: '<S590>/Constant2'
       *  Switch: '<S586>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant2_Value;
    } else if (rtu_IRQ != localDW->DelayInput1_DSTATE) {
      /* Switch: '<S590>/IRQSwitch' incorporates:
       *  Switch: '<S586>/InitSwitch'
       *  Switch: '<S590>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_IRQ;
    } else if (rtu_InVal != localDW->DelayInput1_DSTATE_h) {
      /* Switch: '<S590>/InValSwitch' incorporates:
       *  Switch: '<S586>/InitSwitch'
       *  Switch: '<S590>/IRQSwitch'
       *  Switch: '<S590>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_InVal;
    } else {
      /* Switch: '<S590>/InhibitSwitch' incorporates:
       *  Constant: '<S590>/Constant3'
       *  Switch: '<S586>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant3_Value;
    }

    /* LookupNDDirect: '<S590>/Direct Lookup Table (n-D)1' incorporates:
     *  Constant: '<S590>/Constant'
     *  Lookup_n-D: '<S590>/n-D Lookup Table'
     *  Math: '<S590>/Math Function'
     *  RelationalOperator: '<S592>/FixPt Relational Operator'
     *  RelationalOperator: '<S593>/FixPt Relational Operator'
     *  Sum: '<S590>/Sum'
     *  Switch: '<S586>/InitSwitch'
     *  Switch: '<S590>/IRQSwitch'
     *  Switch: '<S590>/InValSwitch'
     *  Switch: '<S590>/InhibitSwitch'
     *  UnitDelay: '<S586>/Unit Delay'
     *  UnitDelay: '<S592>/Delay Input1'
     *  UnitDelay: '<S593>/Delay Input1'
     *
     * About '<S590>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_IncDecRq = rt_modd_snf(rtb_IncDecRq + static_cast<real_T>
      (look1_ts8Dd_binlcapw(localDW->UnitDelay_DSTATE, rtp_ControlStates,
      localP->nDLookupTable_tableData, 12U)), localP->Constant_Value);
    if (rtb_IncDecRq > 12.0) {
      rtb_IncDecRq = 12.0;
    } else {
      if (rtb_IncDecRq < 0.0) {
        rtb_IncDecRq = 0.0;
      }
    }

    /* Switch: '<S586>/InitSwitch' incorporates:
     *  LookupNDDirect: '<S590>/Direct Lookup Table (n-D)1'
     *
     * About '<S590>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    localB->ModeSwitch = rtp_ControlStates[static_cast<int32_T>(rtb_IncDecRq)];
  }

  /* End of Switch: '<S586>/ModeSwitch' */

  /* Update for UnitDelay: '<S592>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_IRQ;

  /* Update for UnitDelay: '<S593>/Delay Input1' */
  localDW->DelayInput1_DSTATE_h = rtu_InVal;

  /* Update for UnitDelay: '<S586>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->ModeSwitch;
}
