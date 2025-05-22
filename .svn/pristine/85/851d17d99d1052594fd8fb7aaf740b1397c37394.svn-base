/*
 * Code generation for system system '<S21>/ModeSelector-Increment'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "IOControls_IncrementControl_h.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"
#include "look1_ts8Dd_binlcapw.h"

/* System initialize for atomic system: '<S21>/ModeSelector-Increment' */
void IOControls_IncrementControl_a_Init(DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S57>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S58>/Delay Input1' */
  localDW->DelayInput1_DSTATE_m = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/* System reset for atomic system: '<S21>/ModeSelector-Increment' */
void IOControls_IncrementControl_h_Reset(DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S57>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S58>/Delay Input1' */
  localDW->DelayInput1_DSTATE_m = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/* Start for atomic system: '<S21>/ModeSelector-Increment' */
void IOControls_IncrementControl_m_Start(B_IncrementControl_h_T *localB,
  DW_IncrementControl_n_T *localDW)
{
  localDW->DelayInput1_DSTATE = 0.0;
  localDW->DelayInput1_DSTATE_m = 0.0;
  localDW->UnitDelay_DSTATE = 0.0;
  localB->ModeSwitch = 0.0;
}

/* Output and update for atomic system: '<S21>/ModeSelector-Increment' */
void IOControls_IncrementControl_h(real_T rtu_InVal, real_T rtu_InMode, real_T
  rtu_InitVal, real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
  B_IncrementControl_h_T *localB, DW_IncrementControl_n_T *localDW,
  P_IncrementControl_l_T *localP, const real_T rtp_ControlStates[6], real_T
  rtp_InitState)
{
  real_T maxV;
  int32_T sigIdx;
  real_T rtb_IncDecRq;
  real_T u1;

  /* Switch: '<S51>/ModeSwitch' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S59>/Constant'
   *  RelationalOperator: '<S52>/Compare'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S57>/FixPt Relational Operator'
   *  RelationalOperator: '<S58>/FixPt Relational Operator'
   *  RelationalOperator: '<S59>/Compare'
   *  Switch: '<S51>/InitSwitch'
   *  Switch: '<S55>/IRQSwitch'
   *  Switch: '<S55>/InValSwitch'
   *  Switch: '<S55>/InhibitSwitch'
   *  UnitDelay: '<S57>/Delay Input1'
   *  UnitDelay: '<S58>/Delay Input1'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S53>/InitialiastionSwitch' incorporates:
     *  Constant: '<S53>/InitSource'
     *  Constant: '<S53>/InternalInitialValue'
     *  Switch: '<S51>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      rtb_IncDecRq = rtp_InitState;
    } else {
      rtb_IncDecRq = rtu_InitVal;
    }

    /* End of Switch: '<S53>/InitialiastionSwitch' */

    /* MinMax: '<S53>/MinMax' incorporates:
     *  Constant: '<S53>/Constant2'
     *  Switch: '<S51>/InitSwitch'
     */
    maxV = rtp_ControlStates[0];
    for (sigIdx = 0; sigIdx < 5; sigIdx++) {
      u1 = rtp_ControlStates[sigIdx + 1];
      if ((!(maxV > u1)) && (!rtIsNaN(u1))) {
        maxV = u1;
      }
    }

    /* Switch: '<S56>/Switch2' incorporates:
     *  MinMax: '<S53>/MinMax'
     *  RelationalOperator: '<S56>/LowerRelop1'
     *  Switch: '<S51>/InitSwitch'
     */
    if (rtb_IncDecRq > maxV) {
      localB->ModeSwitch = maxV;
    } else {
      /* MinMax: '<S53>/MinMax1' incorporates:
       *  Constant: '<S53>/Constant2'
       */
      maxV = rtp_ControlStates[0];
      for (sigIdx = 0; sigIdx < 5; sigIdx++) {
        u1 = rtp_ControlStates[sigIdx + 1];
        if ((!(maxV < u1)) && (!rtIsNaN(u1))) {
          maxV = u1;
        }
      }

      /* Switch: '<S56>/Switch' incorporates:
       *  MinMax: '<S53>/MinMax1'
       *  RelationalOperator: '<S56>/UpperRelop'
       */
      if (rtb_IncDecRq < maxV) {
        localB->ModeSwitch = maxV;
      } else {
        localB->ModeSwitch = rtb_IncDecRq;
      }

      /* End of Switch: '<S56>/Switch' */
    }

    /* End of Switch: '<S56>/Switch2' */
  } else {
    if (rtu_Inhibit == localP->InhibitCheck_const) {
      /* Switch: '<S55>/InhibitSwitch' incorporates:
       *  Constant: '<S55>/Constant2'
       *  Switch: '<S51>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant2_Value;
    } else if (rtu_IRQ != localDW->DelayInput1_DSTATE) {
      /* Switch: '<S55>/IRQSwitch' incorporates:
       *  Switch: '<S51>/InitSwitch'
       *  Switch: '<S55>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_IRQ;
    } else if (rtu_InVal != localDW->DelayInput1_DSTATE_m) {
      /* Switch: '<S55>/InValSwitch' incorporates:
       *  Switch: '<S51>/InitSwitch'
       *  Switch: '<S55>/IRQSwitch'
       *  Switch: '<S55>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_InVal;
    } else {
      /* Switch: '<S55>/InhibitSwitch' incorporates:
       *  Constant: '<S55>/Constant3'
       *  Switch: '<S51>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant3_Value;
    }

    /* LookupNDDirect: '<S55>/Direct Lookup Table (n-D)1' incorporates:
     *  Lookup_n-D: '<S55>/n-D Lookup Table'
     *  RelationalOperator: '<S57>/FixPt Relational Operator'
     *  RelationalOperator: '<S58>/FixPt Relational Operator'
     *  Saturate: '<S55>/Saturation'
     *  Sum: '<S55>/Sum'
     *  Switch: '<S51>/InitSwitch'
     *  Switch: '<S55>/IRQSwitch'
     *  Switch: '<S55>/InValSwitch'
     *  Switch: '<S55>/InhibitSwitch'
     *  UnitDelay: '<S51>/Unit Delay'
     *  UnitDelay: '<S57>/Delay Input1'
     *  UnitDelay: '<S58>/Delay Input1'
     *
     * About '<S55>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_IncDecRq += static_cast<real_T>(look1_ts8Dd_binlcapw
      (localDW->UnitDelay_DSTATE, rtp_ControlStates,
       localP->nDLookupTable_tableData, 5U));
    if (rtb_IncDecRq > localP->Saturation_UpperSat) {
      rtb_IncDecRq = localP->Saturation_UpperSat;
    } else {
      if (rtb_IncDecRq < localP->Saturation_LowerSat) {
        rtb_IncDecRq = localP->Saturation_LowerSat;
      }
    }

    if (rtb_IncDecRq > 5.0) {
      rtb_IncDecRq = 5.0;
    } else {
      if (rtb_IncDecRq < 0.0) {
        rtb_IncDecRq = 0.0;
      }
    }

    /* Switch: '<S51>/InitSwitch' incorporates:
     *  LookupNDDirect: '<S55>/Direct Lookup Table (n-D)1'
     *
     * About '<S55>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    localB->ModeSwitch = rtp_ControlStates[static_cast<int32_T>(rtb_IncDecRq)];
  }

  /* End of Switch: '<S51>/ModeSwitch' */

  /* Update for UnitDelay: '<S57>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_IRQ;

  /* Update for UnitDelay: '<S58>/Delay Input1' */
  localDW->DelayInput1_DSTATE_m = rtu_InVal;

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->ModeSwitch;
}
