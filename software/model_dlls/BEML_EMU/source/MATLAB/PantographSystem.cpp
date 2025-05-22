/*
 * Code generation for system model 'PantographSystem'
 *
 * Model                      : PantographSystem
 * Model version              : 1.936
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PantographSystem_capi.h"
#include "PantographSystem.h"
#include "PantographSystem_private.h"

P_PantographSystem_T PantographSystem_P = {
  /* Start of '<S1>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S14>/Constant'
     */
    1.0,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S15>/Constant'
     */
    0.0,

    /* Mask Parameter: DetectDecrease_vinit
     * Referenced by: '<S8>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectIncrease_vinit
     * Referenced by: '<S17>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease_vinit_a
     * Referenced by: '<S16>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: SRLatchResetPriority_initial_condition
     * Referenced by: '<S12>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority_initial_condition_h
     * Referenced by: '<S27>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority1_initial_condition
     * Referenced by: '<S25>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority2_initial_condition
     * Referenced by: '<S26>/Memory'
     */
    0,

    /* Computed Parameter: PantographSystemVehicleOutputs_Y0
     * Referenced by: '<S2>/PantographSystemVehicleOutputs'
     */
    {
      0.0,                             /* PantographPosition */
      false,                           /* PantoUpStatus */
      false,                           /* PantoDownStatus */
      false,                           /* PantoIsolatedStatus */
      false,                           /* PantoRising */
      false,                           /* PantoLowering */
      0.0,                             /* DetectedLineVoltage */
      false,                           /* NoOverheadLineDetected */
      false,                           /* PantographFault */

      {
        {
          false,                       /* PantoADDFaultMessage */
          false,                       /* PantoORDFaultMessage */
          false                        /* PantoRaiseFailureMessage */
        }                              /* Messages */
      }                                /* TCMS */
    },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S4>/Constant3'
     */
    {
      0.0,                             /* PantographPosition */
      false,                           /* PantoUpStatus */
      false,                           /* PantoDownStatus */
      false,                           /* PantoIsolatedStatus */
      false,                           /* PantoRising */
      false,                           /* PantoLowering */
      0.0,                             /* DetectedLineVoltage */
      false,                           /* NoOverheadLineDetected */
      false,                           /* PantographFault */

      {
        {
          false,                       /* PantoADDFaultMessage */
          false,                       /* PantoORDFaultMessage */
          false                        /* PantoRaiseFailureMessage */
        }                              /* Messages */
      }                                /* TCMS */
    },

    /* Expression: 0
     * Referenced by: '<S3>/Constant'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S10>/OnlyGoesDOWN'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S10>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S10>/Speed'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt
     * Referenced by: '<S9>/Weighted Sample Time'
     */
    0.05,

    /* Expression: 0
     * Referenced by: '<S5>/Constant2'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S5>/Constant5'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S5>/Constant3'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S5>/Constant1'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay1'
     */
    0.0,

    /* Expression: false
     * Referenced by: '<S29>/Constant'
     */
    0,

    /* Computed Parameter: UnitDelay3_InitialCondition
     * Referenced by: '<S2>/Unit Delay3'
     */
    0,

    /* Computed Parameter: UnitDelay2_InitialCondition
     * Referenced by: '<S2>/Unit Delay2'
     */
    0,

    /* Computed Parameter: UnitDelay1_InitialCondition_e
     * Referenced by: '<S2>/Unit Delay1'
     */
    0,

    /* Computed Parameter: UnitDelay_InitialCondition
     * Referenced by: '<S2>/Unit Delay'
     */
    0,

    /* Computed Parameter: UnitDelay_InitialCondition_e
     * Referenced by: '<S5>/Unit Delay'
     */
    0,

    /* Computed Parameter: IC_Value
     * Referenced by: '<S9>/IC'
     */
    1,

    /* Expression: true
     * Referenced by: '<S5>/Constant'
     */
    1,

    /* Computed Parameter: Dummy_Gain
     * Referenced by: '<S3>/Dummy'
     */
    128U,

    /* Computed Parameter: Dummy1_Gain
     * Referenced by: '<S3>/Dummy1'
     */
    128U,

    /* Computed Parameter: Dummy2_Gain
     * Referenced by: '<S3>/Dummy2'
     */
    128U,

    /* Start of '<S18>/NoPantoCommand' */
    {
      /* Expression: 0
       * Referenced by: '<S23>/Constant'
       */
      0.0
    }
    ,

    /* End of '<S18>/NoPantoCommand' */

    /* Start of '<S18>/UP' */
    {
      /* Expression: 1
       * Referenced by: '<S24>/Constant'
       */
      1.0
    }
    ,

    /* End of '<S18>/UP' */

    /* Start of '<S18>/DOWN' */
    {
      /* Expression: -1
       * Referenced by: '<S22>/Constant'
       */
      -1.0
    }
    /* End of '<S18>/DOWN' */
  }
  /* End of '<S1>/CoreSubsys' */
};

/*
 * Output and update for action system:
 *    '<S18>/DOWN'
 *    '<S18>/UP'
 *    '<S18>/NoPantoCommand'
 */
void PantographSystem_DOWN(real_T *rty_PantoCommand, P_DOWN_PantographSystem_T
  *localP)
{
  /* SignalConversion generated from: '<S22>/PantoCommand' incorporates:
   *  Constant: '<S22>/Constant'
   */
  *rty_PantoCommand = localP->Constant_Value;
}

/* System initialize for referenced model: 'PantographSystem' */
void PantographSystem_Init(B_PantographSystem_c_T *localB,
  DW_PantographSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* SystemInitialize for Iterator SubSystem: '<Root>/PantographSystemPerVehicle' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* SystemInitialize for Enabled SubSystem: '<S1>/EnabledPantoVehicle' */
    /* InitializeConditions for Memory: '<S12>/Memory' */
    localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput =
      PantographSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay3_DSTATE =
      PantographSystem_P.CoreSubsys.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay2_DSTATE =
      PantographSystem_P.CoreSubsys.UnitDelay2_InitialCondition;

    /* InitializeConditions for Memory: '<S27>/Memory' */
    localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_m =
      PantographSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition_h;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE_e =
      PantographSystem_P.CoreSubsys.UnitDelay1_InitialCondition_e;

    /* InitializeConditions for Memory: '<S25>/Memory' */
    localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_e =
      PantographSystem_P.CoreSubsys.SRLatchResetPriority1_initial_condition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay_DSTATE =
      PantographSystem_P.CoreSubsys.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE =
      PantographSystem_P.CoreSubsys.DetectDecrease_vinit;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay_DSTATE_o =
      PantographSystem_P.CoreSubsys.UnitDelay_InitialCondition_e;

    /* InitializeConditions for Memory: '<S26>/Memory' */
    localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_p =
      PantographSystem_P.CoreSubsys.SRLatchResetPriority2_initial_condition;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
    localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE =
      PantographSystem_P.CoreSubsys.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S17>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_p =
      PantographSystem_P.CoreSubsys.DetectIncrease_vinit;

    /* InitializeConditions for UnitDelay: '<S16>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_l =
      PantographSystem_P.CoreSubsys.DetectDecrease_vinit_a;

    /* SystemInitialize for Outport: '<S2>/PantographSystemVehicleOutputs' */
    localB->CoreSubsys[ForEach_itr].BusAssignment =
      PantographSystem_P.CoreSubsys.PantographSystemVehicleOutputs_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/EnabledPantoVehicle' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/PantographSystemPerVehicle' */
}

/* Start for referenced model: 'PantographSystem' */
void PantographSystem_Start(B_PantographSystem_c_T *localB,
  DW_PantographSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  static const BD_PantographSystem_Out_Vehicle tmp = { 0.0,/* PantographPosition */
    false,                             /* PantoUpStatus */
    false,                             /* PantoDownStatus */
    false,                             /* PantoIsolatedStatus */
    false,                             /* PantoRising */
    false,                             /* PantoLowering */
    0.0,                               /* DetectedLineVoltage */
    false,                             /* NoOverheadLineDetected */
    false,                             /* PantographFault */
    { { false,                         /* PantoADDFaultMessage */
        false,                         /* PantoORDFaultMessage */
        false                          /* PantoRaiseFailureMessage */
      }                                /* Messages */
    }                                  /* TCMS */
  };

  /* Start for Iterator SubSystem: '<Root>/PantographSystemPerVehicle' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Start for Enabled SubSystem: '<S1>/EnabledPantoVehicle' */
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE = 0.0;
    localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE = 0.0;
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_p = 0.0;
    localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_l = 0.0;
    localB->CoreSubsys[ForEach_itr].BusAssignment = tmp;

    /* Start for InitialCondition: '<S9>/IC' */
    localDW->CoreSubsys[ForEach_itr].IC_FirstOutputTime = true;

    /* End of Start for SubSystem: '<S1>/EnabledPantoVehicle' */
  }

  /* End of Start for SubSystem: '<Root>/PantographSystemPerVehicle' */
}

/* Output and update for referenced model: 'PantographSystem' */
void PantographSystem(const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8],
                      const BD_PantographSystem_Cfg_Vehicle
                      rtu_PantographSystemVehicleConfig[8], const
                      BD_PantographSystem_In_Vehicle
                      rtu_PantographSystemVehicleInputs[8], const
                      BD_PantographSystem_In_Vehicle_Overrides rtu_Overrides[8],
                      BD_PantographSystem_Out_Vehicle
                      rty_PantographSystemVehicleOutputs[8],
                      B_PantographSystem_c_T *localB, DW_PantographSystem_f_T
                      *localDW, const BD_PantographSystem_Prm
                      *rtp_Prm_PantographSystem)
{
  /* local block i/o variables */
  real_T rtb_Merge;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_AND1;
  boolean_T rtb_AND_l;
  boolean_T rtb_AND2_k;
  boolean_T rtb_PantographFaultStatus;
  boolean_T rtb_LogicalOperator40_m;
  boolean_T rtb_LogicalOperator40_n;
  boolean_T rtb_Compare_p;
  real_T rtb_PantoMode;
  boolean_T rtb_LogicalOperator40_b_tmp;

  /* Outputs for Iterator SubSystem: '<Root>/PantographSystemPerVehicle' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Outputs for Enabled SubSystem: '<S1>/EnabledPantoVehicle' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    /* Logic: '<S1>/AND' incorporates:
     *  ForEachSliceSelector generated from: '<S1>/CommonVehicleConfig'
     *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleConfig'
     */
    if (rtu_CommonVehicleConfig[ForEach_itr].Enabled &&
        rtu_PantographSystemVehicleConfig[ForEach_itr].HasPanto) {
      /* Logic: '<S20>/OR1' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S20>/NOT'
       *  Logic: '<S20>/NOT1'
       *  UnitDelay: '<S2>/Unit Delay2'
       *  UnitDelay: '<S2>/Unit Delay3'
       */
      rtb_AND1 = (rtu_PantographSystemVehicleInputs[ForEach_itr].
                  Control.PantoEmergencyDownCommand ||
                  rtu_PantographSystemVehicleInputs[ForEach_itr].
                  Control.PantoIsolationCommand ||
                  (!rtu_PantographSystemVehicleInputs[ForEach_itr].
                   Electrical.PantoControlPower) || (!localDW->
        CoreSubsys[ForEach_itr].UnitDelay3_DSTATE) || localDW->
                  CoreSubsys[ForEach_itr].UnitDelay2_DSTATE);

      /* Logic: '<S21>/OR2' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       */
      rtb_AND2_k = (rtu_PantographSystemVehicleInputs[ForEach_itr].
                    Control.PantoDownCommand || rtb_AND1);

      /* Logic: '<S21>/AND1' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S21>/NOT'
       */
      rtb_AND_l = (rtu_PantographSystemVehicleInputs[ForEach_itr].
                   Electrical.PantoControlPower &&
                   rtu_PantographSystemVehicleInputs[ForEach_itr].
                   Control.PantoUpCommand && (!rtb_AND2_k));

      /* Logic: '<S21>/OR3' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/Overrides'
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  UnitDelay: '<S2>/Unit Delay1'
       */
      rtb_AND2_k = (rtb_AND2_k || localDW->CoreSubsys[ForEach_itr].
                    UnitDelay1_DSTATE_e || rtu_Overrides[ForEach_itr].
                    PantoUPOverride ||
                    rtu_PantographSystemVehicleInputs[ForEach_itr].
                    Electrical.PantoRaiseFailure);

      /* Logic: '<S27>/Logical Operator40' incorporates:
       *  Logic: '<S27>/Logical Operator39'
       *  Logic: '<S27>/Logical Operator41'
       *  Memory: '<S27>/Memory'
       */
      rtb_AND2_k = ((rtb_AND_l || localDW->CoreSubsys[ForEach_itr].
                     Memory_PreviousInput_m) && (!rtb_AND2_k));

      /* Logic: '<S19>/NOT1' incorporates:
       *  Logic: '<S19>/OR4'
       */
      rtb_AND_l = !rtb_AND1;

      /* UnitDelay: '<S2>/Unit Delay' */
      rtb_Compare_p = !localDW->CoreSubsys[ForEach_itr].UnitDelay_DSTATE;

      /* ForEachSliceSelector generated from: '<S1>/Overrides' */
      rtb_LogicalOperator40_b_tmp = !rtu_Overrides[ForEach_itr].PantoUPOverride;

      /* Logic: '<S25>/Logical Operator40' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/Overrides'
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S19>/AND2'
       *  Logic: '<S19>/NOT1'
       *  Logic: '<S19>/OR4'
       *  Logic: '<S25>/Logical Operator39'
       *  Logic: '<S25>/Logical Operator41'
       *  Memory: '<S25>/Memory'
       *  UnitDelay: '<S2>/Unit Delay'
       */
      rtb_LogicalOperator40_m = (((rtu_PantographSystemVehicleInputs[ForEach_itr]
        .Electrical.PantoControlPower &&
        rtu_PantographSystemVehicleInputs[ForEach_itr].Control.PantoDownCommand &&
        rtb_AND_l) || localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_e) &&
        (rtb_AND_l && rtb_Compare_p && rtb_LogicalOperator40_b_tmp));

      /* If: '<S18>/If' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S18>/Logical Operator5'
       *  Logic: '<S18>/Logical Operator7'
       */
      if (rtu_PantographSystemVehicleInputs[ForEach_itr].
          Electrical.PantoControlPower && rtb_LogicalOperator40_m) {
        /* Outputs for IfAction SubSystem: '<S18>/DOWN' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        PantographSystem_DOWN(&rtb_Merge, &PantographSystem_P.CoreSubsys.DOWN);

        /* End of Outputs for SubSystem: '<S18>/DOWN' */
      } else if (rtu_PantographSystemVehicleInputs[ForEach_itr].
                 Electrical.PantoControlPower && rtb_AND2_k) {
        /* Outputs for IfAction SubSystem: '<S18>/UP' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        PantographSystem_DOWN(&rtb_Merge, &PantographSystem_P.CoreSubsys.UP);

        /* End of Outputs for SubSystem: '<S18>/UP' */
      } else {
        /* Outputs for IfAction SubSystem: '<S18>/NoPantoCommand' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        PantographSystem_DOWN(&rtb_Merge,
                              &PantographSystem_P.CoreSubsys.NoPantoCommand);

        /* End of Outputs for SubSystem: '<S18>/NoPantoCommand' */
      }

      /* End of If: '<S18>/If' */

      /* Logic: '<S12>/Logical Operator40' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/Overrides'
       *  Logic: '<S12>/Logical Operator39'
       *  Logic: '<S12>/Logical Operator41'
       *  Memory: '<S12>/Memory'
       *  RelationalOperator: '<S8>/FixPt Relational Operator'
       *  UnitDelay: '<S8>/Delay Input1'
       */
      rtb_LogicalOperator40_n = ((rtu_Overrides[ForEach_itr].PantoUPOverride ||
        localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput) && (!(rtb_Merge <
        localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE)));

      /* Switch: '<S5>/Switch2' incorporates:
       *  Logic: '<S5>/Logical Operator1'
       *  UnitDelay: '<S5>/Unit Delay'
       */
      if (rtb_LogicalOperator40_n) {
        rtb_PantographFaultStatus = true;
      } else {
        rtb_PantographFaultStatus = !localDW->CoreSubsys[ForEach_itr].
          UnitDelay_DSTATE_o;
      }

      /* End of Switch: '<S5>/Switch2' */

      /* InitialCondition: '<S9>/IC' */
      if (localDW->CoreSubsys[ForEach_itr].IC_FirstOutputTime) {
        localDW->CoreSubsys[ForEach_itr].IC_FirstOutputTime = false;
        rtb_PantographFaultStatus = PantographSystem_P.CoreSubsys.IC_Value;
      }

      /* End of InitialCondition: '<S9>/IC' */

      /* Logic: '<S7>/NOT' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       */
      rtb_AND_l = !rtu_PantographSystemVehicleInputs[ForEach_itr].
        Control.PantoIsolationCommand;

      /* Logic: '<S7>/Logical Operator5' */
      rtb_LogicalOperator5 = (rtb_AND_l &&
        rtu_PantographSystemVehicleConfig[ForEach_itr].PneumaticsPoweredPanto);

      /* Logic: '<S7>/Logical Operator7' */
      rtb_AND_l = (rtb_AND_l && rtu_PantographSystemVehicleConfig[ForEach_itr].
                   ElectricPoweredPanto);

      /* If: '<S7>/If' */
      if (rtb_LogicalOperator5) {
        /* Outputs for IfAction SubSystem: '<S7>/PneumaticSupply' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* SignalConversion generated from: '<S30>/Bus Selector' incorporates:
         *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
         */
        rtb_AND_l = rtu_PantographSystemVehicleInputs[ForEach_itr].
          Pneumatics.PantoPneumaticSupply;

        /* End of Outputs for SubSystem: '<S7>/PneumaticSupply' */
      } else if (rtb_AND_l) {
        /* Outputs for IfAction SubSystem: '<S7>/ElectricSupply' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* SignalConversion generated from: '<S28>/Bus Selector' incorporates:
         *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
         */
        rtb_AND_l = rtu_PantographSystemVehicleInputs[ForEach_itr].
          Electrical.PantoMotorPower;

        /* End of Outputs for SubSystem: '<S7>/ElectricSupply' */
      } else {
        /* Outputs for IfAction SubSystem: '<S7>/NoPantoSupply' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* SignalConversion generated from: '<S29>/PantoSupply' incorporates:
         *  Constant: '<S29>/Constant'
         */
        rtb_AND_l = PantographSystem_P.CoreSubsys.Constant_Value_o;

        /* End of Outputs for SubSystem: '<S7>/NoPantoSupply' */
      }

      /* End of If: '<S7>/If' */

      /* Logic: '<S26>/Logical Operator40' incorporates:
       *  Logic: '<S20>/OR'
       *  Logic: '<S26>/Logical Operator39'
       *  Logic: '<S26>/Logical Operator41'
       *  Memory: '<S26>/Memory'
       */
      rtb_AND1 = ((rtb_AND1 || localDW->CoreSubsys[ForEach_itr].
                   Memory_PreviousInput_p) && (rtb_Compare_p &&
        rtb_LogicalOperator40_b_tmp));

      /* Switch: '<S9>/SelReset' incorporates:
       *  Logic: '<S10>/AND'
       *  Logic: '<S10>/NOT1'
       *  SampleTimeMath: '<S9>/Weighted Sample Time'
       *  Sum: '<S9>/Sum1'
       *  Switch: '<S10>/PantoMode'
       *  UnitDelay: '<S9>/Unit Delay1'
       *
       * About '<S9>/Weighted Sample Time':
       *  y = u * K where K = ( w * Ts )
       */
      if (rtb_PantographFaultStatus) {
        /* Switch: '<S5>/Switch1' incorporates:
         *  Constant: '<S5>/Constant2'
         *  Constant: '<S5>/Constant5'
         */
        if (rtb_LogicalOperator40_n) {
          rtb_PantoMode = PantographSystem_P.CoreSubsys.Constant5_Value;
        } else {
          rtb_PantoMode = PantographSystem_P.CoreSubsys.Constant2_Value;
        }

        /* End of Switch: '<S5>/Switch1' */
      } else {
        if (rtb_AND_l && (!rtb_AND1)) {
          /* Switch: '<S10>/Speed' incorporates:
           *  Constant: '<S10>/Constant5'
           *  Constant: '<S10>/Constant6'
           *  Switch: '<S10>/PantoMode'
           *  Switch: '<S10>/Switch'
           */
          if (rtb_Merge > PantographSystem_P.CoreSubsys.Speed_Threshold) {
            rtb_PantoMode = 1.0 / rtp_Prm_PantographSystem->PantoRaiseTime;
          } else {
            rtb_PantoMode = 1.0 / rtp_Prm_PantographSystem->PantoLowerTime;
          }

          /* End of Switch: '<S10>/Speed' */

          /* Switch: '<S10>/PantoMode' incorporates:
           *  Product: '<S10>/Product'
           *  Switch: '<S10>/Switch'
           */
          rtb_PantoMode *= rtb_Merge;
        } else {
          /* Switch: '<S10>/PantoMode' incorporates:
           *  Constant: '<S10>/Constant1'
           *  Gain: '<S10>/OnlyGoesDOWN'
           */
          rtb_PantoMode = 1.0 /
            rtp_Prm_PantographSystem->PantoEmergencyLowerTime *
            PantographSystem_P.CoreSubsys.OnlyGoesDOWN_Gain;
        }

        rtb_PantoMode = rtb_PantoMode *
          PantographSystem_P.CoreSubsys.WeightedSampleTime_WtEt +
          localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE;
      }

      /* End of Switch: '<S9>/SelReset' */

      /* Switch: '<S13>/Switch2' incorporates:
       *  Constant: '<S5>/Constant1'
       *  Constant: '<S5>/Constant3'
       *  RelationalOperator: '<S13>/LowerRelop1'
       *  RelationalOperator: '<S13>/UpperRelop'
       *  Switch: '<S13>/Switch'
       */
      if (rtb_PantoMode > PantographSystem_P.CoreSubsys.Constant1_Value) {
        rtb_PantoMode = PantographSystem_P.CoreSubsys.Constant1_Value;
      } else {
        if (rtb_PantoMode < PantographSystem_P.CoreSubsys.Constant3_Value_e) {
          /* Switch: '<S13>/Switch' incorporates:
           *  Constant: '<S5>/Constant3'
           */
          rtb_PantoMode = PantographSystem_P.CoreSubsys.Constant3_Value_e;
        }
      }

      /* End of Switch: '<S13>/Switch2' */

      /* RelationalOperator: '<S14>/Compare' incorporates:
       *  Constant: '<S14>/Constant'
       */
      rtb_PantographFaultStatus = (rtb_PantoMode ==
        PantographSystem_P.CoreSubsys.CompareToConstant1_const);

      /* Logic: '<S3>/AND2' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S3>/NOT'
       */
      rtb_LogicalOperator5 = ((!(rtu_PantographSystemVehicleInputs[ForEach_itr].
        Environment.OverheadLinePresent != 0.0)) && rtb_PantographFaultStatus);

      /* RelationalOperator: '<S15>/Compare' incorporates:
       *  Constant: '<S15>/Constant'
       */
      rtb_Compare_p = (rtb_PantoMode ==
                       PantographSystem_P.CoreSubsys.CompareToConstant2_const);

      /* BusAssignment: '<S4>/Bus Assignment' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S11>/AND2'
       *  Logic: '<S5>/AND'
       *  Logic: '<S5>/Logical Operator2'
       */
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantographPosition =
        rtb_PantoMode;
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantoUpStatus =
        rtb_PantographFaultStatus;
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantoDownStatus =
        rtb_Compare_p;
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantoIsolatedStatus =
        (rtb_Compare_p && ((!rtb_AND_l) &&
                           rtu_PantographSystemVehicleInputs[ForEach_itr].
                           Control.PantoIsolationCommand));

      /* Logic: '<S11>/NOR' incorporates:
       *  Logic: '<S11>/NOR1'
       */
      rtb_LogicalOperator40_b_tmp = ((!rtb_PantographFaultStatus) &&
        (!rtb_Compare_p));

      /* BusAssignment: '<S4>/Bus Assignment' incorporates:
       *  Logic: '<S11>/AND'
       *  Logic: '<S11>/AND1'
       *  Logic: '<S11>/NOR'
       *  RelationalOperator: '<S16>/FixPt Relational Operator'
       *  RelationalOperator: '<S17>/FixPt Relational Operator'
       *  UnitDelay: '<S16>/Delay Input1'
       *  UnitDelay: '<S17>/Delay Input1'
       */
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantoRising =
        (rtb_LogicalOperator40_b_tmp && (rtb_PantoMode > localDW->
          CoreSubsys[ForEach_itr].DelayInput1_DSTATE_p));
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantoLowering =
        (rtb_LogicalOperator40_b_tmp && (rtb_PantoMode < localDW->
          CoreSubsys[ForEach_itr].DelayInput1_DSTATE_l));

      /* Switch: '<S3>/Switch' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Logic: '<S3>/AND'
       *  Logic: '<S3>/AND1'
       *  Logic: '<S3>/NOT1'
       */
      if ((!(rtu_PantographSystemVehicleInputs[ForEach_itr].
             Environment.NeutralSection != 0.0)) &&
          ((rtu_PantographSystemVehicleInputs[ForEach_itr].
            Environment.OverheadLinePresent != 0.0) && rtb_PantographFaultStatus))
      {
        /* BusAssignment: '<S4>/Bus Assignment' */
        localB->CoreSubsys[ForEach_itr].BusAssignment.DetectedLineVoltage =
          rtu_PantographSystemVehicleInputs[ForEach_itr].Environment.LineVoltage;
      } else {
        /* BusAssignment: '<S4>/Bus Assignment' incorporates:
         *  Constant: '<S3>/Constant'
         */
        localB->CoreSubsys[ForEach_itr].BusAssignment.DetectedLineVoltage =
          PantographSystem_P.CoreSubsys.Constant_Value;
      }

      /* End of Switch: '<S3>/Switch' */

      /* BusAssignment: '<S4>/Bus Assignment' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/PantographSystemVehicleInputs'
       *  Gain: '<S3>/Dummy'
       *  Gain: '<S3>/Dummy1'
       *  Gain: '<S3>/Dummy2'
       *  Logic: '<S3>/OR1'
       */
      localB->CoreSubsys[ForEach_itr].BusAssignment.NoOverheadLineDetected =
        rtb_LogicalOperator5;
      localB->CoreSubsys[ForEach_itr].BusAssignment.PantographFault =
        (rtu_PantographSystemVehicleInputs[ForEach_itr].Electrical.PantoADDFault
         || rtu_PantographSystemVehicleInputs[ForEach_itr].
         Electrical.PantoORDFault ||
         rtu_PantographSystemVehicleInputs[ForEach_itr].
         Electrical.PantoRaiseFailure ||
         rtu_PantographSystemVehicleInputs[ForEach_itr].
         Electrical.PantoLoweringFailure);
      localB->CoreSubsys[ForEach_itr].
        BusAssignment.TCMS.Messages.PantoADDFaultMessage =
        ((PantographSystem_P.CoreSubsys.Dummy_Gain != 0) &&
         rtu_PantographSystemVehicleInputs[ForEach_itr].Electrical.PantoADDFault);
      localB->CoreSubsys[ForEach_itr].
        BusAssignment.TCMS.Messages.PantoORDFaultMessage =
        ((PantographSystem_P.CoreSubsys.Dummy1_Gain != 0) &&
         rtu_PantographSystemVehicleInputs[ForEach_itr].Electrical.PantoORDFault);
      localB->CoreSubsys[ForEach_itr].
        BusAssignment.TCMS.Messages.PantoRaiseFailureMessage =
        ((PantographSystem_P.CoreSubsys.Dummy2_Gain != 0) &&
         rtu_PantographSystemVehicleInputs[ForEach_itr].
         Electrical.PantoRaiseFailure);

      /* Update for Memory: '<S12>/Memory' */
      localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput =
        rtb_LogicalOperator40_n;

      /* Update for UnitDelay: '<S2>/Unit Delay3' */
      localDW->CoreSubsys[ForEach_itr].UnitDelay3_DSTATE = rtb_AND_l;

      /* Update for UnitDelay: '<S2>/Unit Delay2' */
      localDW->CoreSubsys[ForEach_itr].UnitDelay2_DSTATE = rtb_LogicalOperator5;

      /* Update for Memory: '<S27>/Memory' */
      localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_m = rtb_AND2_k;

      /* Update for UnitDelay: '<S2>/Unit Delay1' */
      localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE_e =
        rtb_PantographFaultStatus;

      /* Update for Memory: '<S25>/Memory' */
      localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_e =
        rtb_LogicalOperator40_m;

      /* Update for UnitDelay: '<S2>/Unit Delay' */
      localDW->CoreSubsys[ForEach_itr].UnitDelay_DSTATE = rtb_Compare_p;

      /* Update for UnitDelay: '<S8>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE = rtb_Merge;

      /* Update for UnitDelay: '<S5>/Unit Delay' incorporates:
       *  Constant: '<S5>/Constant'
       */
      localDW->CoreSubsys[ForEach_itr].UnitDelay_DSTATE_o =
        PantographSystem_P.CoreSubsys.Constant_Value_e;

      /* Update for Memory: '<S26>/Memory' */
      localDW->CoreSubsys[ForEach_itr].Memory_PreviousInput_p = rtb_AND1;

      /* Update for UnitDelay: '<S9>/Unit Delay1' */
      localDW->CoreSubsys[ForEach_itr].UnitDelay1_DSTATE = rtb_PantoMode;

      /* Update for UnitDelay: '<S17>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_p = rtb_PantoMode;

      /* Update for UnitDelay: '<S16>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr].DelayInput1_DSTATE_l = rtb_PantoMode;
    }

    /* End of Logic: '<S1>/AND' */
    /* End of Outputs for SubSystem: '<S1>/EnabledPantoVehicle' */

    /* ForEachSliceAssignment generated from: '<S1>/PantographSystemVehicleOutputs' */
    rty_PantographSystemVehicleOutputs[ForEach_itr] = localB->
      CoreSubsys[ForEach_itr].BusAssignment;
  }

  /* End of Outputs for SubSystem: '<Root>/PantographSystemPerVehicle' */
}

/* Model initialize function */
void PantographSystem_initialize(const char_T **rt_errorStatus,
  RT_MODEL_PantographSystem_T *const PantographSystem_M, B_PantographSystem_c_T *
  localB, DW_PantographSystem_f_T *localDW, rtwCAPI_ModelMappingInfo
  *rt_ParentMMI, const char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T
  rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(PantographSystem_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_PantographSystem_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_PantographSystem_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    PantographSystem_InitializeDataMapInfo(PantographSystem_M, localB);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(PantographSystem_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(PantographSystem_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(PantographSystem_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
