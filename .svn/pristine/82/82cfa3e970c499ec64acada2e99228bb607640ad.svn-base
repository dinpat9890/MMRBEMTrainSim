/*
 * Code generation for system system '<S20>/MasterControllerHandle-Increment'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "IOControls_IncrementControl_a.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"
#include "look1_ts8Dd_binlcapw.h"

/* System initialize for atomic system: '<S20>/MasterControllerHandle-Increment' */
void IOControls_IncrementControl_n_Init(DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S48>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S49>/Delay Input1' */
  localDW->DelayInput1_DSTATE_f = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S42>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/* System reset for atomic system: '<S20>/MasterControllerHandle-Increment' */
void IOControls_IncrementControl_n_Reset(DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S48>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S49>/Delay Input1' */
  localDW->DelayInput1_DSTATE_f = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S42>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/* Start for atomic system: '<S20>/MasterControllerHandle-Increment' */
void IOControls_IncrementControl_a_Start(B_IncrementControl_f_T *localB,
  DW_IncrementControl_j_T *localDW)
{
  localDW->DelayInput1_DSTATE = 0.0;
  localDW->DelayInput1_DSTATE_f = 0.0;
  localDW->UnitDelay_DSTATE = 0.0;
  localB->ModeSwitch = 0.0;
}

/* Output and update for atomic system: '<S20>/MasterControllerHandle-Increment' */
void IOControls_IncrementControl_a(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_f_T *localB, DW_IncrementControl_j_T *localDW,
  P_IncrementControl_k_T *localP, const real_T rtp_ControlStates[22], real_T
  rtp_InitState)
{
  real_T maxV;
  int32_T sigIdx;
  real_T rtb_IncDecRq;
  real_T u1;

  /* Switch: '<S42>/ModeSwitch' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S50>/Constant'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S48>/FixPt Relational Operator'
   *  RelationalOperator: '<S49>/FixPt Relational Operator'
   *  RelationalOperator: '<S50>/Compare'
   *  Switch: '<S42>/InitSwitch'
   *  Switch: '<S46>/IRQSwitch'
   *  Switch: '<S46>/InValSwitch'
   *  Switch: '<S46>/InhibitSwitch'
   *  UnitDelay: '<S48>/Delay Input1'
   *  UnitDelay: '<S49>/Delay Input1'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S44>/InitialiastionSwitch' incorporates:
     *  Constant: '<S44>/InitSource'
     *  Constant: '<S44>/InternalInitialValue'
     *  Switch: '<S42>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      rtb_IncDecRq = rtp_InitState;
    } else {
      rtb_IncDecRq = rtu_InitVal;
    }

    /* End of Switch: '<S44>/InitialiastionSwitch' */

    /* MinMax: '<S44>/MinMax' incorporates:
     *  Constant: '<S44>/Constant2'
     *  Switch: '<S42>/InitSwitch'
     */
    maxV = rtp_ControlStates[0];
    for (sigIdx = 0; sigIdx < 21; sigIdx++) {
      u1 = rtp_ControlStates[sigIdx + 1];
      if ((!(maxV > u1)) && (!rtIsNaN(u1))) {
        maxV = u1;
      }
    }

    /* Switch: '<S47>/Switch2' incorporates:
     *  MinMax: '<S44>/MinMax'
     *  RelationalOperator: '<S47>/LowerRelop1'
     *  Switch: '<S42>/InitSwitch'
     */
    if (rtb_IncDecRq > maxV) {
      localB->ModeSwitch = maxV;
    } else {
      /* MinMax: '<S44>/MinMax1' incorporates:
       *  Constant: '<S44>/Constant2'
       */
      maxV = rtp_ControlStates[0];
      for (sigIdx = 0; sigIdx < 21; sigIdx++) {
        u1 = rtp_ControlStates[sigIdx + 1];
        if ((!(maxV < u1)) && (!rtIsNaN(u1))) {
          maxV = u1;
        }
      }

      /* Switch: '<S47>/Switch' incorporates:
       *  MinMax: '<S44>/MinMax1'
       *  RelationalOperator: '<S47>/UpperRelop'
       */
      if (rtb_IncDecRq < maxV) {
        localB->ModeSwitch = maxV;
      } else {
        localB->ModeSwitch = rtb_IncDecRq;
      }

      /* End of Switch: '<S47>/Switch' */
    }

    /* End of Switch: '<S47>/Switch2' */
  } else {
    if (rtu_Inhibit == localP->InhibitCheck_const) {
      /* Switch: '<S46>/InhibitSwitch' incorporates:
       *  Constant: '<S46>/Constant2'
       *  Switch: '<S42>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant2_Value;
    } else if (rtu_IRQ != localDW->DelayInput1_DSTATE) {
      /* Switch: '<S46>/IRQSwitch' incorporates:
       *  Switch: '<S42>/InitSwitch'
       *  Switch: '<S46>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_IRQ;
    } else if (rtu_InVal != localDW->DelayInput1_DSTATE_f) {
      /* Switch: '<S46>/InValSwitch' incorporates:
       *  Switch: '<S42>/InitSwitch'
       *  Switch: '<S46>/IRQSwitch'
       *  Switch: '<S46>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_InVal;
    } else {
      /* Switch: '<S46>/InhibitSwitch' incorporates:
       *  Constant: '<S46>/Constant3'
       *  Switch: '<S42>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant3_Value;
    }

    /* LookupNDDirect: '<S46>/Direct Lookup Table (n-D)1' incorporates:
     *  Lookup_n-D: '<S46>/n-D Lookup Table'
     *  RelationalOperator: '<S48>/FixPt Relational Operator'
     *  RelationalOperator: '<S49>/FixPt Relational Operator'
     *  Saturate: '<S46>/Saturation'
     *  Sum: '<S46>/Sum'
     *  Switch: '<S42>/InitSwitch'
     *  Switch: '<S46>/IRQSwitch'
     *  Switch: '<S46>/InValSwitch'
     *  Switch: '<S46>/InhibitSwitch'
     *  UnitDelay: '<S42>/Unit Delay'
     *  UnitDelay: '<S48>/Delay Input1'
     *  UnitDelay: '<S49>/Delay Input1'
     *
     * About '<S46>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_IncDecRq += static_cast<real_T>(look1_ts8Dd_binlcapw
      (localDW->UnitDelay_DSTATE, rtp_ControlStates,
       localP->nDLookupTable_tableData, 21U));
    if (rtb_IncDecRq > localP->Saturation_UpperSat) {
      rtb_IncDecRq = localP->Saturation_UpperSat;
    } else {
      if (rtb_IncDecRq < localP->Saturation_LowerSat) {
        rtb_IncDecRq = localP->Saturation_LowerSat;
      }
    }

    if (rtb_IncDecRq > 21.0) {
      rtb_IncDecRq = 21.0;
    } else {
      if (rtb_IncDecRq < 0.0) {
        rtb_IncDecRq = 0.0;
      }
    }

    /* Switch: '<S42>/InitSwitch' incorporates:
     *  LookupNDDirect: '<S46>/Direct Lookup Table (n-D)1'
     *
     * About '<S46>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    localB->ModeSwitch = rtp_ControlStates[static_cast<int32_T>(rtb_IncDecRq)];
  }

  /* End of Switch: '<S42>/ModeSwitch' */

  /* Update for UnitDelay: '<S48>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_IRQ;

  /* Update for UnitDelay: '<S49>/Delay Input1' */
  localDW->DelayInput1_DSTATE_f = rtu_InVal;

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->ModeSwitch;
}
