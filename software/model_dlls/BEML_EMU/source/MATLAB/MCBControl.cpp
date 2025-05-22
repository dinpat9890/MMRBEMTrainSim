/*
 * Code generation for system system '<S3147>/RightDoor4DCUCB-MCB'
 *
 * Model                      : IOControls
 * Model version              : 1.62
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "MCBControl.h"

/* Include model header file for global data */
#include "IOControls.h"
#include "IOControls_private.h"

/*
 * System initialize for atomic system:
 *    '<S3147>/RightDoor4DCUCB-MCB'
 *    '<S3141>/RightDoor3DCUCB-MCB'
 *    '<S3135>/RightDoor2DCUCB-MCB'
 *    '<S3129>/RightDoor1DCUCB-MCB'
 *    '<S3123>/LeftDoor4DCUCB-MCB'
 *    '<S3117>/LeftDoor3DCUCB-MCB'
 *    '<S3111>/LeftDoor2DCUCB-MCB'
 *    '<S3105>/LeftDoor1DCUCB-MCB'
 *    '<S766>/ZVBACB-MCB'
 *    '<S765>/WWCB-MCB'
 *    ...
 */
void MCBControl_Init(B_MCBControl_T *localB, DW_MCBControl_T *localDW,
                     P_MCBControl_T *localP)
{
  /* SystemInitialize for Atomic SubSystem: '<S3554>/Toggle' */
  ToggleControl_Init(&localDW->Toggle, &localP->Toggle);

  /* End of SystemInitialize for SubSystem: '<S3554>/Toggle' */

  /* SystemInitialize for Enabled SubSystem: '<S3554>/MCB Trip' */
  /* InitializeConditions for UnitDelay: '<S3556>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for Memory: '<S3560>/Memory' */
  localDW->Memory_PreviousInput = localP->SRFlipFlop_initial_condition;

  /* SystemInitialize for Atomic SubSystem: '<S3556>/TimerOnDelay NoInit' */
  /* InitializeConditions for DiscreteIntegrator: '<S3561>/Timer' */
  localDW->Timer_DSTATE = localP->Timer_IC;
  localDW->Timer_PrevResetState = 0;

  /* End of SystemInitialize for SubSystem: '<S3556>/TimerOnDelay NoInit' */

  /* SystemInitialize for Outport: '<S3556>/TripOut' */
  localB->DataTypeConversion = localP->TripOut_Y0;

  /* End of SystemInitialize for SubSystem: '<S3554>/MCB Trip' */
}

/*
 * System reset for atomic system:
 *    '<S3147>/RightDoor4DCUCB-MCB'
 *    '<S3141>/RightDoor3DCUCB-MCB'
 *    '<S3135>/RightDoor2DCUCB-MCB'
 *    '<S3129>/RightDoor1DCUCB-MCB'
 *    '<S3123>/LeftDoor4DCUCB-MCB'
 *    '<S3117>/LeftDoor3DCUCB-MCB'
 *    '<S3111>/LeftDoor2DCUCB-MCB'
 *    '<S3105>/LeftDoor1DCUCB-MCB'
 *    '<S766>/ZVBACB-MCB'
 *    '<S765>/WWCB-MCB'
 *    ...
 */
void MCBControl_Reset(DW_MCBControl_T *localDW, P_MCBControl_T *localP)
{
  /* SystemReset for Atomic SubSystem: '<S3554>/Toggle' */
  ToggleControl_Reset(&localDW->Toggle, &localP->Toggle);

  /* End of SystemReset for SubSystem: '<S3554>/Toggle' */
}

/*
 * Disable for atomic system:
 *    '<S3147>/RightDoor4DCUCB-MCB'
 *    '<S3141>/RightDoor3DCUCB-MCB'
 *    '<S3135>/RightDoor2DCUCB-MCB'
 *    '<S3129>/RightDoor1DCUCB-MCB'
 *    '<S3123>/LeftDoor4DCUCB-MCB'
 *    '<S3117>/LeftDoor3DCUCB-MCB'
 *    '<S3111>/LeftDoor2DCUCB-MCB'
 *    '<S3105>/LeftDoor1DCUCB-MCB'
 *    '<S766>/ZVBACB-MCB'
 *    '<S765>/WWCB-MCB'
 *    ...
 */
void MCBControl_Disable(DW_MCBControl_T *localDW)
{
  /* Disable for Enabled SubSystem: '<S3554>/MCB Trip' */
  localDW->MCBTrip_MODE = false;

  /* End of Disable for SubSystem: '<S3554>/MCB Trip' */
}

/*
 * Start for atomic system:
 *    '<S3147>/RightDoor4DCUCB-MCB'
 *    '<S3141>/RightDoor3DCUCB-MCB'
 *    '<S3135>/RightDoor2DCUCB-MCB'
 *    '<S3129>/RightDoor1DCUCB-MCB'
 *    '<S3123>/LeftDoor4DCUCB-MCB'
 *    '<S3117>/LeftDoor3DCUCB-MCB'
 *    '<S3111>/LeftDoor2DCUCB-MCB'
 *    '<S3105>/LeftDoor1DCUCB-MCB'
 *    '<S766>/ZVBACB-MCB'
 *    '<S765>/WWCB-MCB'
 *    ...
 */
void MCBControl_Start(B_MCBControl_T *localB, DW_MCBControl_T *localDW)
{
  /* Start for Atomic SubSystem: '<S3554>/Toggle' */
  ToggleControl_Start(&localB->Toggle, &localDW->Toggle);

  /* End of Start for SubSystem: '<S3554>/Toggle' */

  /* Start for Enabled SubSystem: '<S3554>/MCB Trip' */
  localB->DataTypeConversion = 0.0;

  /* Start for Atomic SubSystem: '<S3556>/TimerOnDelay NoInit' */
  localDW->Timer_DSTATE = 0.0;

  /* End of Start for SubSystem: '<S3556>/TimerOnDelay NoInit' */
  /* End of Start for SubSystem: '<S3554>/MCB Trip' */
}

/*
 * Output and update for atomic system:
 *    '<S3147>/RightDoor4DCUCB-MCB'
 *    '<S3141>/RightDoor3DCUCB-MCB'
 *    '<S3135>/RightDoor2DCUCB-MCB'
 *    '<S3129>/RightDoor1DCUCB-MCB'
 *    '<S3123>/LeftDoor4DCUCB-MCB'
 *    '<S3117>/LeftDoor3DCUCB-MCB'
 *    '<S3111>/LeftDoor2DCUCB-MCB'
 *    '<S3105>/LeftDoor1DCUCB-MCB'
 *    '<S766>/ZVBACB-MCB'
 *    '<S765>/WWCB-MCB'
 *    ...
 */
void MCBControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal, real_T
                rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit, real_T
                rtu_TripIn, B_MCBControl_T *localB, DW_MCBControl_T *localDW,
                P_MCBControl_T *localP, real_T rtp_OffStateValue, real_T
                rtp_OnStateValue, real_T rtp_InitState)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator_l;
  boolean_T rtb_UnTripRq;
  int32_T rtb_Timer_o2;
  real_T Timer_o1;

  /* Outputs for Atomic SubSystem: '<S3554>/Toggle' */
  ToggleControl(rtu_InVal, rtu_InMode, rtu_InitVal, rtu_InitTrigger, rtu_IRQ,
                rtu_Inhibit, &localB->Toggle, &localDW->Toggle, &localP->Toggle,
                rtp_OffStateValue, rtp_OnStateValue, rtp_InitState);

  /* End of Outputs for SubSystem: '<S3554>/Toggle' */

  /* Outputs for Enabled SubSystem: '<S3554>/MCB Trip' incorporates:
   *  EnablePort: '<S3556>/Enable'
   */
  /* RelationalOperator: '<S3555>/Compare' incorporates:
   *  Constant: '<S3555>/Constant'
   */
  if (rtu_InMode == localP->Constant_Value_m) {
    if (!localDW->MCBTrip_MODE) {
      /* InitializeConditions for UnitDelay: '<S3556>/Unit Delay' */
      localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

      /* InitializeConditions for Memory: '<S3560>/Memory' */
      localDW->Memory_PreviousInput = localP->SRFlipFlop_initial_condition;

      /* SystemReset for Atomic SubSystem: '<S3556>/TimerOnDelay NoInit' */
      /* InitializeConditions for DiscreteIntegrator: '<S3561>/Timer' */
      localDW->Timer_DSTATE = localP->Timer_IC;
      localDW->Timer_PrevResetState = 0;

      /* End of SystemReset for SubSystem: '<S3556>/TimerOnDelay NoInit' */
      localDW->MCBTrip_MODE = true;
    }

    /* RelationalOperator: '<S3559>/Compare' incorporates:
     *  Constant: '<S3559>/Constant'
     */
    rtb_UnTripRq = (localB->Toggle.Merge > localP->IsON_const);

    /* Outputs for Atomic SubSystem: '<S3556>/TimerOnDelay NoInit' */
    /* Logic: '<S3561>/Logical Operator' incorporates:
     *  UnitDelay: '<S3556>/Unit Delay'
     */
    rtb_LogicalOperator_l = !localDW->UnitDelay_DSTATE;

    /* DiscreteIntegrator: '<S3561>/Timer' incorporates:
     *  DataTypeConversion: '<S3561>/Data Type Conversion'
     *  UnitDelay: '<S3556>/Unit Delay'
     */
    if (rtb_LogicalOperator_l || (localDW->Timer_PrevResetState != 0)) {
      localDW->Timer_DSTATE = localP->Timer_IC;
    }

    Timer_o1 = localP->Timer_gainval * static_cast<real_T>
      (localDW->UnitDelay_DSTATE) + localDW->Timer_DSTATE;
    if (Timer_o1 >= localP->TimerOnDelayNoInit_UpperSaturationLimit) {
      Timer_o1 = localP->TimerOnDelayNoInit_UpperSaturationLimit;
      rtb_Timer_o2 = 1;
    } else if (Timer_o1 <= localP->Timer_LowerSat) {
      Timer_o1 = localP->Timer_LowerSat;
      rtb_Timer_o2 = -1;
    } else {
      rtb_Timer_o2 = 0;
    }

    /* End of DiscreteIntegrator: '<S3561>/Timer' */

    /* Update for DiscreteIntegrator: '<S3561>/Timer' */
    localDW->Timer_DSTATE = Timer_o1;
    localDW->Timer_PrevResetState = static_cast<int8_T>(rtb_LogicalOperator_l);

    /* CombinatorialLogic: '<S3560>/Logic' incorporates:
     *  Constant: '<S3558>/Constant'
     *  Constant: '<S3562>/Constant'
     *  Logic: '<S3556>/Logical Operator1'
     *  Logic: '<S3556>/Logical Operator2'
     *  Logic: '<S3556>/TripRq'
     *  Logic: '<S3556>/UnTripRq'
     *  Memory: '<S3560>/Memory'
     *  RelationalOperator: '<S3558>/Compare'
     *  RelationalOperator: '<S3562>/Compare'
     */
    rtb_Timer_o2 = static_cast<int32_T>(((((static_cast<uint32_T>((((rtu_TripIn
      != 0.0) && rtb_UnTripRq) || ((rtu_IRQ != 0.0) && rtb_UnTripRq))) << 1) +
      ((localB->Toggle.Merge <= localP->IsOFF_const) || (rtb_Timer_o2 >
      localP->Constant_Value))) << 1) + localDW->Memory_PreviousInput));

    /* End of Outputs for SubSystem: '<S3556>/TimerOnDelay NoInit' */

    /* DataTypeConversion: '<S3556>/Data Type Conversion' incorporates:
     *  CombinatorialLogic: '<S3560>/Logic'
     */
    localB->DataTypeConversion = localP->Logic_table[static_cast<uint32_T>
      (rtb_Timer_o2)];

    /* Update for UnitDelay: '<S3556>/Unit Delay' incorporates:
     *  CombinatorialLogic: '<S3560>/Logic'
     */
    localDW->UnitDelay_DSTATE = localP->Logic_table[static_cast<uint32_T>
      (rtb_Timer_o2)];

    /* Update for Memory: '<S3560>/Memory' incorporates:
     *  CombinatorialLogic: '<S3560>/Logic'
     */
    localDW->Memory_PreviousInput = localP->Logic_table[static_cast<uint32_T>
      (rtb_Timer_o2)];
  } else {
    localDW->MCBTrip_MODE = false;
  }

  /* End of RelationalOperator: '<S3555>/Compare' */
  /* End of Outputs for SubSystem: '<S3554>/MCB Trip' */
}
