/*
 * Code generation for system system '<S342>/HoldDoorCloseBypassSS-Increment'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "IOControls_IncrementControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"
#include "look1_ts8Dd_binlcapw.h"

/*
 * System initialize for atomic system:
 *    '<S342>/HoldDoorCloseBypassSS-Increment'
 *    '<S336>/CabBoosterFanSS-Increment'
 *    '<S189>/HeadLightSwitch-Increment'
 */
void IOControls_IncrementControl_Init(DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S421>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S422>/Delay Input1' */
  localDW->DelayInput1_DSTATE_e = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S415>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * System reset for atomic system:
 *    '<S342>/HoldDoorCloseBypassSS-Increment'
 *    '<S336>/CabBoosterFanSS-Increment'
 *    '<S189>/HeadLightSwitch-Increment'
 */
void IOControls_IncrementControl_Reset(DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S421>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S422>/Delay Input1' */
  localDW->DelayInput1_DSTATE_e = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S415>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * Start for atomic system:
 *    '<S342>/HoldDoorCloseBypassSS-Increment'
 *    '<S336>/CabBoosterFanSS-Increment'
 *    '<S189>/HeadLightSwitch-Increment'
 */
void IOControls_IncrementControl_Start(B_IncrementControl_c_T *localB,
  DW_IncrementControl_k_T *localDW)
{
  localDW->DelayInput1_DSTATE = 0.0;
  localDW->DelayInput1_DSTATE_e = 0.0;
  localDW->UnitDelay_DSTATE = 0.0;
  localB->ModeSwitch = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S342>/HoldDoorCloseBypassSS-Increment'
 *    '<S336>/CabBoosterFanSS-Increment'
 *    '<S189>/HeadLightSwitch-Increment'
 */
void IOControls_IncrementControl(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_c_T *localB, DW_IncrementControl_k_T *localDW,
  P_IncrementControl_f_T *localP, const real_T rtp_ControlStates[3], real_T
  rtp_InitState)
{
  real_T maxV;
  real_T rtb_IncDecRq;
  boolean_T tmp;
  boolean_T tmp_0;

  /* Switch: '<S415>/ModeSwitch' incorporates:
   *  Constant: '<S416>/Constant'
   *  Constant: '<S418>/Constant'
   *  Constant: '<S423>/Constant'
   *  RelationalOperator: '<S416>/Compare'
   *  RelationalOperator: '<S418>/Compare'
   *  RelationalOperator: '<S421>/FixPt Relational Operator'
   *  RelationalOperator: '<S422>/FixPt Relational Operator'
   *  RelationalOperator: '<S423>/Compare'
   *  Switch: '<S415>/InitSwitch'
   *  Switch: '<S419>/IRQSwitch'
   *  Switch: '<S419>/InValSwitch'
   *  Switch: '<S419>/InhibitSwitch'
   *  UnitDelay: '<S421>/Delay Input1'
   *  UnitDelay: '<S422>/Delay Input1'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S417>/InitialiastionSwitch' incorporates:
     *  Constant: '<S417>/InitSource'
     *  Constant: '<S417>/InternalInitialValue'
     *  Switch: '<S415>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      rtb_IncDecRq = rtp_InitState;
    } else {
      rtb_IncDecRq = rtu_InitVal;
    }

    /* End of Switch: '<S417>/InitialiastionSwitch' */

    /* MinMax: '<S417>/MinMax' incorporates:
     *  Constant: '<S417>/Constant2'
     *  MinMax: '<S417>/MinMax1'
     *  Switch: '<S415>/InitSwitch'
     *  Switch: '<S420>/Switch2'
     */
    tmp = rtIsNaN(rtp_ControlStates[1]);
    if ((rtp_ControlStates[0] > rtp_ControlStates[1]) || tmp) {
      maxV = rtp_ControlStates[0];
    } else {
      maxV = rtp_ControlStates[1];
    }

    tmp_0 = rtIsNaN(rtp_ControlStates[2]);
    if ((!(maxV > rtp_ControlStates[2])) && (!tmp_0)) {
      maxV = rtp_ControlStates[2];
    }

    /* Switch: '<S420>/Switch2' incorporates:
     *  Constant: '<S417>/Constant2'
     *  MinMax: '<S417>/MinMax'
     *  MinMax: '<S417>/MinMax1'
     *  RelationalOperator: '<S420>/LowerRelop1'
     *  Switch: '<S415>/InitSwitch'
     */
    if (rtb_IncDecRq > maxV) {
      localB->ModeSwitch = maxV;
    } else {
      if ((rtp_ControlStates[0] < rtp_ControlStates[1]) || tmp) {
        /* MinMax: '<S417>/MinMax1' incorporates:
         *  Constant: '<S417>/Constant2'
         */
        maxV = rtp_ControlStates[0];
      } else {
        /* MinMax: '<S417>/MinMax1' incorporates:
         *  Constant: '<S417>/Constant2'
         */
        maxV = rtp_ControlStates[1];
      }

      /* MinMax: '<S417>/MinMax1' incorporates:
       *  Constant: '<S417>/Constant2'
       */
      if ((!(maxV < rtp_ControlStates[2])) && (!tmp_0)) {
        maxV = rtp_ControlStates[2];
      }

      /* Switch: '<S420>/Switch' incorporates:
       *  MinMax: '<S417>/MinMax1'
       *  RelationalOperator: '<S420>/UpperRelop'
       */
      if (rtb_IncDecRq < maxV) {
        localB->ModeSwitch = maxV;
      } else {
        localB->ModeSwitch = rtb_IncDecRq;
      }

      /* End of Switch: '<S420>/Switch' */
    }
  } else {
    if (rtu_Inhibit == localP->InhibitCheck_const) {
      /* Switch: '<S419>/InhibitSwitch' incorporates:
       *  Constant: '<S419>/Constant2'
       *  Switch: '<S415>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant2_Value;
    } else if (rtu_IRQ != localDW->DelayInput1_DSTATE) {
      /* Switch: '<S419>/IRQSwitch' incorporates:
       *  Switch: '<S415>/InitSwitch'
       *  Switch: '<S419>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_IRQ;
    } else if (rtu_InVal != localDW->DelayInput1_DSTATE_e) {
      /* Switch: '<S419>/InValSwitch' incorporates:
       *  Switch: '<S415>/InitSwitch'
       *  Switch: '<S419>/IRQSwitch'
       *  Switch: '<S419>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_InVal;
    } else {
      /* Switch: '<S419>/InhibitSwitch' incorporates:
       *  Constant: '<S419>/Constant3'
       *  Switch: '<S415>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant3_Value;
    }

    /* LookupNDDirect: '<S419>/Direct Lookup Table (n-D)1' incorporates:
     *  Lookup_n-D: '<S419>/n-D Lookup Table'
     *  RelationalOperator: '<S421>/FixPt Relational Operator'
     *  RelationalOperator: '<S422>/FixPt Relational Operator'
     *  Saturate: '<S419>/Saturation'
     *  Sum: '<S419>/Sum'
     *  Switch: '<S415>/InitSwitch'
     *  Switch: '<S419>/IRQSwitch'
     *  Switch: '<S419>/InValSwitch'
     *  Switch: '<S419>/InhibitSwitch'
     *  UnitDelay: '<S415>/Unit Delay'
     *  UnitDelay: '<S421>/Delay Input1'
     *  UnitDelay: '<S422>/Delay Input1'
     *
     * About '<S419>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_IncDecRq += static_cast<real_T>(look1_ts8Dd_binlcapw
      (localDW->UnitDelay_DSTATE, rtp_ControlStates,
       localP->nDLookupTable_tableData, 2U));
    if (rtb_IncDecRq > localP->Saturation_UpperSat) {
      rtb_IncDecRq = localP->Saturation_UpperSat;
    } else {
      if (rtb_IncDecRq < localP->Saturation_LowerSat) {
        rtb_IncDecRq = localP->Saturation_LowerSat;
      }
    }

    if (rtb_IncDecRq > 2.0) {
      rtb_IncDecRq = 2.0;
    } else {
      if (rtb_IncDecRq < 0.0) {
        rtb_IncDecRq = 0.0;
      }
    }

    /* Switch: '<S415>/InitSwitch' incorporates:
     *  LookupNDDirect: '<S419>/Direct Lookup Table (n-D)1'
     *
     * About '<S419>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    localB->ModeSwitch = rtp_ControlStates[static_cast<int32_T>(rtb_IncDecRq)];
  }

  /* End of Switch: '<S415>/ModeSwitch' */

  /* Update for UnitDelay: '<S421>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_IRQ;

  /* Update for UnitDelay: '<S422>/Delay Input1' */
  localDW->DelayInput1_DSTATE_e = rtu_InVal;

  /* Update for UnitDelay: '<S415>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->ModeSwitch;
}
