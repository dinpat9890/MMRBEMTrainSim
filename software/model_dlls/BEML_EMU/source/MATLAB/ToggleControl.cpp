/*
 * Code generation for system system '<S3645>/UncouplingCock-Toggle'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "ToggleControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"

/*
 * System initialize for atomic system:
 *    '<S3645>/UncouplingCock-Toggle'
 *    '<S3644>/SR-Toggle'
 *    '<S3643>/ParkingBrakeManualReleaseBogie2Handle2-Toggle'
 *    '<S3642>/ParkingBrakeManualReleaseBogie2Handle1-Toggle'
 *    '<S3641>/ParkingBrakeManualReleaseBogie1Handle2-Toggle'
 *    '<S3640>/ParkingBrakeManualReleaseBogie1Handle1-Toggle'
 *    '<S3639>/ParkBrakeIsolationCockBogie2-Toggle'
 *    '<S3638>/ParkBrakeIsolationCockBogie1-Toggle'
 *    '<S3637>/MRIsolationCock-Toggle'
 *    '<S3636>/MREPIsolationCockEnd2-Toggle'
 *    ...
 */
void ToggleControl_Init(DW_ToggleControl_T *localDW, P_ToggleControl_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S3846>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S3846>/Software Mode' */
  /* InitializeConditions for UnitDelay: '<S3851>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S3852>/Delay Input1' */
  localDW->DelayInput1_DSTATE_m = localP->DetectRisePositive1_vinit;

  /* End of SystemInitialize for SubSystem: '<S3846>/Software Mode' */
}

/*
 * System reset for atomic system:
 *    '<S3645>/UncouplingCock-Toggle'
 *    '<S3644>/SR-Toggle'
 *    '<S3643>/ParkingBrakeManualReleaseBogie2Handle2-Toggle'
 *    '<S3642>/ParkingBrakeManualReleaseBogie2Handle1-Toggle'
 *    '<S3641>/ParkingBrakeManualReleaseBogie1Handle2-Toggle'
 *    '<S3640>/ParkingBrakeManualReleaseBogie1Handle1-Toggle'
 *    '<S3639>/ParkBrakeIsolationCockBogie2-Toggle'
 *    '<S3638>/ParkBrakeIsolationCockBogie1-Toggle'
 *    '<S3637>/MRIsolationCock-Toggle'
 *    '<S3636>/MREPIsolationCockEnd2-Toggle'
 *    ...
 */
void ToggleControl_Reset(DW_ToggleControl_T *localDW, P_ToggleControl_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S3846>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;
}

/*
 * Start for atomic system:
 *    '<S3645>/UncouplingCock-Toggle'
 *    '<S3644>/SR-Toggle'
 *    '<S3643>/ParkingBrakeManualReleaseBogie2Handle2-Toggle'
 *    '<S3642>/ParkingBrakeManualReleaseBogie2Handle1-Toggle'
 *    '<S3641>/ParkingBrakeManualReleaseBogie1Handle2-Toggle'
 *    '<S3640>/ParkingBrakeManualReleaseBogie1Handle1-Toggle'
 *    '<S3639>/ParkBrakeIsolationCockBogie2-Toggle'
 *    '<S3638>/ParkBrakeIsolationCockBogie1-Toggle'
 *    '<S3637>/MRIsolationCock-Toggle'
 *    '<S3636>/MREPIsolationCockEnd2-Toggle'
 *    ...
 */
void ToggleControl_Start(B_ToggleControl_T *localB, DW_ToggleControl_T *localDW)
{
  localDW->UnitDelay_DSTATE = 0.0;
  localB->Merge = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S3645>/UncouplingCock-Toggle'
 *    '<S3644>/SR-Toggle'
 *    '<S3643>/ParkingBrakeManualReleaseBogie2Handle2-Toggle'
 *    '<S3642>/ParkingBrakeManualReleaseBogie2Handle1-Toggle'
 *    '<S3641>/ParkingBrakeManualReleaseBogie1Handle2-Toggle'
 *    '<S3640>/ParkingBrakeManualReleaseBogie1Handle1-Toggle'
 *    '<S3639>/ParkBrakeIsolationCockBogie2-Toggle'
 *    '<S3638>/ParkBrakeIsolationCockBogie1-Toggle'
 *    '<S3637>/MRIsolationCock-Toggle'
 *    '<S3636>/MREPIsolationCockEnd2-Toggle'
 *    ...
 */
void ToggleControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal,
                   real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit,
                   B_ToggleControl_T *localB, DW_ToggleControl_T *localDW,
                   P_ToggleControl_T *localP, real_T rtp_OffStateValue, real_T
                   rtp_OnStateValue, real_T rtp_InitState)
{
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_lw;
  real_T tmp;

  /* If: '<S3846>/If' incorporates:
   *  Inport: '<S3847>/InValue'
   */
  if (rtu_InMode == 0.0) {
    /* Outputs for IfAction SubSystem: '<S3846>/Hardware Mode' incorporates:
     *  ActionPort: '<S3847>/Action Port'
     */
    localB->Merge = rtu_InVal;

    /* End of Outputs for SubSystem: '<S3846>/Hardware Mode' */
  } else if (rtu_InitTrigger > 0.0) {
    /* Outputs for IfAction SubSystem: '<S3846>/Initialise' incorporates:
     *  ActionPort: '<S3848>/Action Port'
     */
    /* Switch: '<S3848>/InitSourceSwitch' incorporates:
     *  Constant: '<S3848>/InitSource'
     *  Constant: '<S3848>/InternalInitialValue'
     */
    if (localP->InitSource_Value != 0.0) {
      tmp = rtp_InitState;
    } else {
      tmp = rtu_InitVal;
    }

    /* End of Switch: '<S3848>/InitSourceSwitch' */

    /* Switch: '<S3848>/MapOutput' incorporates:
     *  Constant: '<S3848>/OffValue'
     *  Constant: '<S3848>/OnValue'
     */
    if (tmp != 0.0) {
      localB->Merge = rtp_OnStateValue;
    } else {
      localB->Merge = rtp_OffStateValue;
    }

    /* End of Switch: '<S3848>/MapOutput' */
    /* End of Outputs for SubSystem: '<S3846>/Initialise' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3846>/Software Mode' incorporates:
     *  ActionPort: '<S3849>/Action Port'
     */
    /* RelationalOperator: '<S3854>/Compare' incorporates:
     *  Constant: '<S3854>/Constant'
     */
    rtb_Compare = (rtu_IRQ > localP->Constant_Value);

    /* RelationalOperator: '<S3855>/Compare' incorporates:
     *  Constant: '<S3855>/Constant'
     */
    rtb_Compare_lw = (rtu_InVal > localP->Constant_Value_k);

    /* Switch: '<S3849>/MapOutput' incorporates:
     *  Constant: '<S3849>/OffValue'
     *  Constant: '<S3849>/OnValue'
     *  Constant: '<S3850>/Constant'
     *  Constant: '<S3853>/Constant'
     *  Logic: '<S3849>/CombineRq'
     *  Logic: '<S3849>/NextState'
     *  Logic: '<S3849>/Toggle'
     *  RelationalOperator: '<S3850>/Compare'
     *  RelationalOperator: '<S3851>/FixPt Relational Operator'
     *  RelationalOperator: '<S3852>/FixPt Relational Operator'
     *  RelationalOperator: '<S3853>/Compare'
     *  UnitDelay: '<S3846>/Unit Delay'
     *  UnitDelay: '<S3851>/Delay Input1'
     *  UnitDelay: '<S3852>/Delay Input1'
     */
    if (static_cast<boolean_T>(((((static_cast<int32_T>(rtb_Compare) >
             static_cast<int32_T>(localDW->DelayInput1_DSTATE)) ||
            (static_cast<int32_T>(rtb_Compare_lw) > static_cast<int32_T>
             (localDW->DelayInput1_DSTATE_m))) && (rtu_Inhibit !=
            localP->InhibitCheck_const)) ^ (localDW->UnitDelay_DSTATE ==
           rtp_OnStateValue)))) {
      localB->Merge = rtp_OnStateValue;
    } else {
      localB->Merge = rtp_OffStateValue;
    }

    /* End of Switch: '<S3849>/MapOutput' */

    /* Update for UnitDelay: '<S3851>/Delay Input1' */
    localDW->DelayInput1_DSTATE = rtb_Compare;

    /* Update for UnitDelay: '<S3852>/Delay Input1' */
    localDW->DelayInput1_DSTATE_m = rtb_Compare_lw;

    /* End of Outputs for SubSystem: '<S3846>/Software Mode' */
  }

  /* End of If: '<S3846>/If' */

  /* Update for UnitDelay: '<S3846>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Merge;
}
