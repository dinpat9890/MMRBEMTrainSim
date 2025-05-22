/*
 * Code generation for system system '<S349>/WiperControlSwitch-Increment'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "IncrementControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"
#include "look1_ts8Dd_binlcapw.h"

/*
 * System initialize for atomic system:
 *    '<S349>/WiperControlSwitch-Increment'
 *    '<S202>/WiperSelectionSwitch-Increment'
 *    '<S195>/PantoSelector-Increment'
 */
void IncrementControl_Init(DW_IncrementControl_T *localDW, P_IncrementControl_T *
  localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S474>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S475>/Delay Input1' */
  localDW->DelayInput1_DSTATE_a = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S468>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * System reset for atomic system:
 *    '<S349>/WiperControlSwitch-Increment'
 *    '<S202>/WiperSelectionSwitch-Increment'
 *    '<S195>/PantoSelector-Increment'
 */
void IncrementControl_Reset(DW_IncrementControl_T *localDW, P_IncrementControl_T
  *localP, real_T rtp_InitState)
{
  /* InitializeConditions for UnitDelay: '<S474>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectChange_vinit;

  /* InitializeConditions for UnitDelay: '<S475>/Delay Input1' */
  localDW->DelayInput1_DSTATE_a = localP->DetectChange1_vinit;

  /* InitializeConditions for UnitDelay: '<S468>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_InitState;
}

/*
 * Start for atomic system:
 *    '<S349>/WiperControlSwitch-Increment'
 *    '<S202>/WiperSelectionSwitch-Increment'
 *    '<S195>/PantoSelector-Increment'
 */
void IncrementControl_Start(B_IncrementControl_T *localB, DW_IncrementControl_T *
  localDW)
{
  localDW->DelayInput1_DSTATE = 0.0;
  localDW->DelayInput1_DSTATE_a = 0.0;
  localDW->UnitDelay_DSTATE = 0.0;
  localB->ModeSwitch = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S349>/WiperControlSwitch-Increment'
 *    '<S202>/WiperSelectionSwitch-Increment'
 *    '<S195>/PantoSelector-Increment'
 */
void IncrementControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal,
                      real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
                      B_IncrementControl_T *localB, DW_IncrementControl_T
                      *localDW, P_IncrementControl_T *localP, const real_T
                      rtp_ControlStates[4], real_T rtp_InitState)
{
  real_T maxV;
  real_T rtb_IncDecRq;
  boolean_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;

  /* Switch: '<S468>/ModeSwitch' incorporates:
   *  Constant: '<S469>/Constant'
   *  Constant: '<S471>/Constant'
   *  Constant: '<S476>/Constant'
   *  RelationalOperator: '<S469>/Compare'
   *  RelationalOperator: '<S471>/Compare'
   *  RelationalOperator: '<S474>/FixPt Relational Operator'
   *  RelationalOperator: '<S475>/FixPt Relational Operator'
   *  RelationalOperator: '<S476>/Compare'
   *  Switch: '<S468>/InitSwitch'
   *  Switch: '<S472>/IRQSwitch'
   *  Switch: '<S472>/InValSwitch'
   *  Switch: '<S472>/InhibitSwitch'
   *  UnitDelay: '<S474>/Delay Input1'
   *  UnitDelay: '<S475>/Delay Input1'
   */
  if (rtu_InMode == localP->ModeCheck_const) {
    localB->ModeSwitch = rtu_InVal;
  } else if (rtu_InitTrigger == localP->InitCheck_const) {
    /* Switch: '<S470>/InitialiastionSwitch' incorporates:
     *  Constant: '<S470>/InitSource'
     *  Constant: '<S470>/InternalInitialValue'
     *  Switch: '<S468>/InitSwitch'
     */
    if (localP->InitSource_Value != 0.0) {
      rtb_IncDecRq = rtp_InitState;
    } else {
      rtb_IncDecRq = rtu_InitVal;
    }

    /* End of Switch: '<S470>/InitialiastionSwitch' */

    /* MinMax: '<S470>/MinMax' incorporates:
     *  Constant: '<S470>/Constant2'
     *  MinMax: '<S470>/MinMax1'
     *  Switch: '<S468>/InitSwitch'
     *  Switch: '<S473>/Switch2'
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

    tmp_1 = rtIsNaN(rtp_ControlStates[3]);
    if ((!(maxV > rtp_ControlStates[3])) && (!tmp_1)) {
      maxV = rtp_ControlStates[3];
    }

    /* Switch: '<S473>/Switch2' incorporates:
     *  Constant: '<S470>/Constant2'
     *  MinMax: '<S470>/MinMax'
     *  MinMax: '<S470>/MinMax1'
     *  RelationalOperator: '<S473>/LowerRelop1'
     *  Switch: '<S468>/InitSwitch'
     */
    if (rtb_IncDecRq > maxV) {
      localB->ModeSwitch = maxV;
    } else {
      if ((rtp_ControlStates[0] < rtp_ControlStates[1]) || tmp) {
        /* MinMax: '<S470>/MinMax1' incorporates:
         *  Constant: '<S470>/Constant2'
         */
        maxV = rtp_ControlStates[0];
      } else {
        /* MinMax: '<S470>/MinMax1' incorporates:
         *  Constant: '<S470>/Constant2'
         */
        maxV = rtp_ControlStates[1];
      }

      /* MinMax: '<S470>/MinMax1' incorporates:
       *  Constant: '<S470>/Constant2'
       */
      if ((!(maxV < rtp_ControlStates[2])) && (!tmp_0)) {
        maxV = rtp_ControlStates[2];
      }

      if ((!(maxV < rtp_ControlStates[3])) && (!tmp_1)) {
        maxV = rtp_ControlStates[3];
      }

      /* Switch: '<S473>/Switch' incorporates:
       *  MinMax: '<S470>/MinMax1'
       *  RelationalOperator: '<S473>/UpperRelop'
       */
      if (rtb_IncDecRq < maxV) {
        localB->ModeSwitch = maxV;
      } else {
        localB->ModeSwitch = rtb_IncDecRq;
      }

      /* End of Switch: '<S473>/Switch' */
    }
  } else {
    if (rtu_Inhibit == localP->InhibitCheck_const) {
      /* Switch: '<S472>/InhibitSwitch' incorporates:
       *  Constant: '<S472>/Constant2'
       *  Switch: '<S468>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant2_Value;
    } else if (rtu_IRQ != localDW->DelayInput1_DSTATE) {
      /* Switch: '<S472>/IRQSwitch' incorporates:
       *  Switch: '<S468>/InitSwitch'
       *  Switch: '<S472>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_IRQ;
    } else if (rtu_InVal != localDW->DelayInput1_DSTATE_a) {
      /* Switch: '<S472>/InValSwitch' incorporates:
       *  Switch: '<S468>/InitSwitch'
       *  Switch: '<S472>/IRQSwitch'
       *  Switch: '<S472>/InhibitSwitch'
       */
      rtb_IncDecRq = rtu_InVal;
    } else {
      /* Switch: '<S472>/InhibitSwitch' incorporates:
       *  Constant: '<S472>/Constant3'
       *  Switch: '<S468>/InitSwitch'
       */
      rtb_IncDecRq = localP->Constant3_Value;
    }

    /* LookupNDDirect: '<S472>/Direct Lookup Table (n-D)1' incorporates:
     *  Lookup_n-D: '<S472>/n-D Lookup Table'
     *  RelationalOperator: '<S474>/FixPt Relational Operator'
     *  RelationalOperator: '<S475>/FixPt Relational Operator'
     *  Saturate: '<S472>/Saturation'
     *  Sum: '<S472>/Sum'
     *  Switch: '<S468>/InitSwitch'
     *  Switch: '<S472>/IRQSwitch'
     *  Switch: '<S472>/InValSwitch'
     *  Switch: '<S472>/InhibitSwitch'
     *  UnitDelay: '<S468>/Unit Delay'
     *  UnitDelay: '<S474>/Delay Input1'
     *  UnitDelay: '<S475>/Delay Input1'
     *
     * About '<S472>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_IncDecRq += static_cast<real_T>(look1_ts8Dd_binlcapw
      (localDW->UnitDelay_DSTATE, rtp_ControlStates,
       localP->nDLookupTable_tableData, 3U));
    if (rtb_IncDecRq > localP->Saturation_UpperSat) {
      rtb_IncDecRq = localP->Saturation_UpperSat;
    } else {
      if (rtb_IncDecRq < localP->Saturation_LowerSat) {
        rtb_IncDecRq = localP->Saturation_LowerSat;
      }
    }

    if (rtb_IncDecRq > 3.0) {
      rtb_IncDecRq = 3.0;
    } else {
      if (rtb_IncDecRq < 0.0) {
        rtb_IncDecRq = 0.0;
      }
    }

    /* Switch: '<S468>/InitSwitch' incorporates:
     *  LookupNDDirect: '<S472>/Direct Lookup Table (n-D)1'
     *
     * About '<S472>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    localB->ModeSwitch = rtp_ControlStates[static_cast<int32_T>(rtb_IncDecRq)];
  }

  /* End of Switch: '<S468>/ModeSwitch' */

  /* Update for UnitDelay: '<S474>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_IRQ;

  /* Update for UnitDelay: '<S475>/Delay Input1' */
  localDW->DelayInput1_DSTATE_a = rtu_InVal;

  /* Update for UnitDelay: '<S468>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->ModeSwitch;
}
