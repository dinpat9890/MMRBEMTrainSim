/*
 * Code generation for system model 'TrainBrakes'
 *
 * Model                      : TrainBrakes
 * Model version              : 1.18
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "TrainBrakes_capi.h"
#include "TrainBrakes.h"
#include "TrainBrakes_private.h"
#include "LookUp_real_T_real_T.h"
#include "rt_powd_snf.h"

P_TrainBrakes_T TrainBrakes_P = {
  /* Variable: pAtm
   * Referenced by: '<S11>/PAtm'
   */
  101300.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: -inf
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Start of '<S2>/CoreSubsys' */
  {
    /* Mask Parameter: InvalidZeroOrNegativeFriction_const
     * Referenced by: '<S35>/Constant'
     */
    0.0,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S39>/Constant'
     */
    10000.0,

    /* Mask Parameter: CompareToConstant6_const
     * Referenced by: '<S40>/Constant'
     */
    10000.0,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S37>/Constant'
     */
    3000.0,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S38>/Constant'
     */
    3000.0,

    /* Computed Parameter: TrainBrakesOut_Y0
     * Referenced by: '<S3>/TrainBrakesOut'
     */
    {
      {
        {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        } }
      ,                                /* Axle */

      {
        0.0,                           /* BCPEngaged */
        0.0,                           /* BCPEngagedBogie1 */
        0.0,                           /* BCPEngagedBogie2 */
        0.0,                           /* WheelBrakeBlocks */
        0.0,                           /* WheelBrakeBlocksBogie1 */
        0.0                            /* WheelBrakeBlocksBogie2 */
      }                                /* States */
    },

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S10>/Constant'
     */
    {
      {
        {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        }, {
          0.0,                         /* BrakingPower */
          0.0,                         /* BrakingForce */
          0.0,                         /* BrakeShoeForce */
          0.0,                         /* BrakeShoeTemperature */
          0.0,                         /* BrakeShoeEfficiency */
          0.0,                         /* BrakeDiscForce */
          0.0                          /* NormalBrakePistonForce */
        } }
      ,                                /* Axle */

      {
        0.0,                           /* BCPEngaged */
        0.0,                           /* BCPEngagedBogie1 */
        0.0,                           /* BCPEngagedBogie2 */
        0.0,                           /* WheelBrakeBlocks */
        0.0,                           /* WheelBrakeBlocksBogie1 */
        0.0                            /* WheelBrakeBlocksBogie2 */
      }                                /* States */
    },

    /* Computed Parameter: Constant_Value_i
     * Referenced by: '<S36>/Constant'
     */
    {
      0.0,                             /* BCPEngaged */
      0.0,                             /* BCPEngagedBogie1 */
      0.0,                             /* BCPEngagedBogie2 */
      0.0,                             /* WheelBrakeBlocks */
      0.0,                             /* WheelBrakeBlocksBogie1 */
      0.0                              /* WheelBrakeBlocksBogie2 */
    },

    /* Computed Parameter: BrakesVehicleConfig_Y0
     * Referenced by: '<S9>/BrakesVehicleConfig'
     */
    {
      BrakeShoeCoefficientCalculationMethod_ConstantBSC,
                                     /* BrakeShoeCoefficientCalculationMethod */
      0.0,                             /* BrakeShoeFrictionCoeff */
      0.0,                             /* BrakeFadeEnable */
      0.0                              /* BrakeTemperatureEnable */
    },

    /* Expression: 0
     * Referenced by: '<S7>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S8>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S6>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S6>/Constant3'
     */
    0.0,

    /* Start of '<S5>/CoreSubsys' */
    {
      /* Mask Parameter: BrakeThermalFade_AirDensity
       * Referenced by: '<S28>/AirRho'
       */
      1.184,

      /* Mask Parameter: BrakeThermalFade_AirDynamicViscosity
       * Referenced by: '<S28>/AirMuv'
       */
      1.849E-5,

      /* Mask Parameter: BrakeThermalFade_AirSpecificHeat
       * Referenced by: '<S28>/AirCp'
       */
      1007.0,

      /* Mask Parameter: BrakeThermalFade_AirThermalConductivity
       * Referenced by: '<S28>/AirK'
       */
      0.02551,

      /* Mask Parameter: BrakeThermalFade_AmbientTemperature
       * Referenced by: '<S26>/AmbientAirTemp'
       */
      298.0,

      /* Mask Parameter: BrakeThermalFade_ConvectiveArea
       * Referenced by: '<S26>/ConvectiveArea'
       */
      0.8,

      /* Mask Parameter: DiscreteIntegratorWithReset_InitValue
       * Referenced by: '<S31>/InitValue'
       */
      0.0,

      /* Mask Parameter: DetectChange_vinit
       * Referenced by: '<S30>/Delay Input1'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S13>/Saturation'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S13>/Saturation'
       */
      0.0,

      /* Computed Parameter: ParkBrakePistonForce_Y0
       * Referenced by: '<S13>/ParkBrakePistonForce'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S13>/Switch'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S25>/Constant'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S24>/Saturation'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S24>/Saturation'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S21>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S29>/Constant'
       */
      0.0,

      /* Expression: 1e8
       * Referenced by: '<S29>/OvertemperatureEnergy'
       */
      1.0E+8,

      /* Expression: 0
       * Referenced by: '<S29>/Switch'
       */
      0.0,

      /* Computed Parameter: BrakeTemperature_Y0
       * Referenced by: '<S26>/BrakeTemperature'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S26>/Unit Delay'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S26>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S26>/Saturation'
       */
      0.0,

      /* Expression: 5.67e-8
       * Referenced by: '<S26>/StefanBoltzmannSigma'
       */
      5.67E-8,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S31>/Discrete-Time Integrator'
       */
      0.01,

      /* Expression: eps
       * Referenced by: '<S26>/Constant'
       */
      2.2204460492503131E-16,

      /* Expression: 1
       * Referenced by: '<S27>/Constant1'
       */
      1.0,

      /* Computed Parameter: BrakingForceAxle_N_Y0
       * Referenced by: '<S12>/BrakingForceAxle_N'
       */
      0.0,

      /* Computed Parameter: BrakeShoeForceAxle_N_Y0
       * Referenced by: '<S12>/BrakeShoeForceAxle_N'
       */
      0.0,

      /* Computed Parameter: BrakeShoeEfficiency_Y0
       * Referenced by: '<S12>/BrakeShoeEfficiency'
       */
      0.0,

      /* Computed Parameter: DiscBrakeForceAxle_N_Y0
       * Referenced by: '<S12>/DiscBrakeForceAxle_N'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S17>/Unit Delay'
       */
      0.0,

      /* Expression: 0.5
       * Referenced by: '<S14>/Multiply'
       */
      0.5,

      /* Expression: 0
       * Referenced by: '<S27>/Switch2'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S27>/Saturation'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S27>/Saturation'
       */
      0.0,

      /* Expression: 100
       * Referenced by: '<S14>/Gain'
       */
      100.0,

      /* Expression: inf
       * Referenced by: '<S32>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S32>/Saturation'
       */
      0.0,

      /* Expression: 100
       * Referenced by: '<S11>/Constant4'
       */
      100.0,

      /* Expression: inf
       * Referenced by: '<S11>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S11>/Saturation'
       */
      0.0,

      /* Computed Parameter: IC_Value
       * Referenced by: '<S31>/IC'
       */
      1
    }
    /* End of '<S5>/CoreSubsys' */
  }
  /* End of '<S2>/CoreSubsys' */
};

/* System initialize for referenced model: 'TrainBrakes' */
void TrainBrakes_Init(B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE =
    TrainBrakes_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for Iterator SubSystem: '<Root>/VehicleBrakes' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* SystemInitialize for Enabled SubSystem: '<S2>/VehicleEnabledBrakes' */
    /* SystemInitialize for Enabled SubSystem: '<S4>/ConfigProcessing' */
    /* SystemInitialize for Outport: '<S9>/BrakesVehicleConfig' */
    localB->CoreSubsys[ForEach_itr].BusCreator1 =
      TrainBrakes_P.CoreSubsys.BrakesVehicleConfig_Y0;

    /* End of SystemInitialize for SubSystem: '<S4>/ConfigProcessing' */

    /* SystemInitialize for Iterator SubSystem: '<S4>/AxleBrakes' */
    for (ForEach_itr_c = 0; ForEach_itr_c < 6; ForEach_itr_c++) {
      /* SystemInitialize for Enabled SubSystem: '<S5>/ParkBrakePistonForce' */
      /* SystemInitialize for Outport: '<S13>/ParkBrakePistonForce' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Max =
        TrainBrakes_P.CoreSubsys.CoreSubsys.ParkBrakePistonForce_Y0;

      /* End of SystemInitialize for SubSystem: '<S5>/ParkBrakePistonForce' */

      /* SystemInitialize for Enabled SubSystem: '<S5>/BrakingForce' */
      /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        UnitDelay_DSTATE =
        TrainBrakes_P.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition_c;

      /* SystemInitialize for Enabled SubSystem: '<S17>/BrakeThermalModel' */
      /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        UnitDelay_DSTATE_n =
        TrainBrakes_P.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S30>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        DelayInput1_DSTATE =
        TrainBrakes_P.CoreSubsys.CoreSubsys.DetectChange_vinit;

      /* InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        DiscreteTimeIntegrator_IC_LOADING = 1U;
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        DiscreteTimeIntegrator_PrevResetState = 0;

      /* SystemInitialize for Outport: '<S26>/BrakeTemperature' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].BrakeTemperature
        = TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeTemperature_Y0;

      /* End of SystemInitialize for SubSystem: '<S17>/BrakeThermalModel' */

      /* SystemInitialize for Outport: '<S12>/BrakingForceAxle_N' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product =
        TrainBrakes_P.CoreSubsys.CoreSubsys.BrakingForceAxle_N_Y0;

      /* SystemInitialize for Outport: '<S12>/BrakeShoeForceAxle_N' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Sum1 =
        TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeShoeForceAxle_N_Y0;

      /* SystemInitialize for Outport: '<S12>/BrakeShoeEfficiency' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        BrakeFadePercentage =
        TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeShoeEfficiency_Y0;

      /* SystemInitialize for Outport: '<S12>/DiscBrakeForceAxle_N' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation =
        TrainBrakes_P.CoreSubsys.CoreSubsys.DiscBrakeForceAxle_N_Y0;

      /* End of SystemInitialize for SubSystem: '<S5>/BrakingForce' */
    }

    /* End of SystemInitialize for SubSystem: '<S4>/AxleBrakes' */

    /* SystemInitialize for Outport: '<S3>/TrainBrakesOut' */
    localB->CoreSubsys[ForEach_itr].TrainBrakesOut =
      TrainBrakes_P.CoreSubsys.TrainBrakesOut_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/VehicleEnabledBrakes' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/VehicleBrakes' */
}

/* System reset for referenced model: 'TrainBrakes' */
void TrainBrakes_Reset(DW_TrainBrakes_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE =
    TrainBrakes_P.DiscreteTimeIntegrator_IC;
}

/* Disable for referenced model: 'TrainBrakes' */
void TrainBrakes_Disable(DW_TrainBrakes_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;

  /* Disable for Iterator SubSystem: '<Root>/VehicleBrakes' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Disable for Enabled SubSystem: '<S2>/VehicleEnabledBrakes' */
    if (localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE) {
      /* Disable for Iterator SubSystem: '<S4>/AxleBrakes' */
      for (ForEach_itr_c = 0; ForEach_itr_c < 6; ForEach_itr_c++) {
        /* Disable for Enabled SubSystem: '<S5>/BrakingForce' */
        if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            BrakingForce_MODE) {
          /* Disable for Enabled SubSystem: '<S17>/BrakeThermalModel' */
          localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            BrakeThermalModel_MODE = false;

          /* End of Disable for SubSystem: '<S17>/BrakeThermalModel' */
          localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            BrakingForce_MODE = false;
        }

        /* End of Disable for SubSystem: '<S5>/BrakingForce' */
      }

      /* End of Disable for SubSystem: '<S4>/AxleBrakes' */
      localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE = false;
    }

    /* End of Disable for SubSystem: '<S2>/VehicleEnabledBrakes' */
  }

  /* End of Disable for SubSystem: '<Root>/VehicleBrakes' */
}

/* Start for referenced model: 'TrainBrakes' */
void TrainBrakes_Start(B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T i;
  static const BD_TrainBrakes_Out_Vehicle tmp = { { { 0.0,/* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      }, { 0.0,                        /* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      }, { 0.0,                        /* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      }, { 0.0,                        /* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      }, { 0.0,                        /* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      }, { 0.0,                        /* BrakingPower */
        0.0,                           /* BrakingForce */
        0.0,                           /* BrakeShoeForce */
        0.0,                           /* BrakeShoeTemperature */
        0.0,                           /* BrakeShoeEfficiency */
        0.0,                           /* BrakeDiscForce */
        0.0                            /* NormalBrakePistonForce */
      } },                             /* Axle */
    { 0.0,                             /* BCPEngaged */
      0.0,                             /* BCPEngagedBogie1 */
      0.0,                             /* BCPEngagedBogie2 */
      0.0,                             /* WheelBrakeBlocks */
      0.0,                             /* WheelBrakeBlocksBogie1 */
      0.0                              /* WheelBrakeBlocksBogie2 */
    }                                  /* States */
  };

  static const BD_TrainBrakes_Cfg_Vehicle tmp_0 = {
    BrakeShoeCoefficientCalculationMethod_ConstantBSC,
                                     /* BrakeShoeCoefficientCalculationMethod */
    0.0,                               /* BrakeShoeFrictionCoeff */
    0.0,                               /* BrakeFadeEnable */
    0.0                                /* BrakeTemperatureEnable */
  };

  /* Start for Iterator SubSystem: '<Root>/VehicleBrakes' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Start for Enabled SubSystem: '<S2>/VehicleEnabledBrakes' */
    for (i = 0; i < 6; i++) {
      localB->CoreSubsys[ForEach_itr].Compare[i] = false;
      localB->CoreSubsys[ForEach_itr].Compare_a[i] = false;
      localB->CoreSubsys[ForEach_itr].Selector[i] = 0.0;
      localB->CoreSubsys[ForEach_itr].Selector1[i] = 0.0;
    }

    localB->CoreSubsys[ForEach_itr].TrainBrakesOut = tmp;

    /* Start for Enabled SubSystem: '<S4>/ConfigProcessing' */
    localB->CoreSubsys[ForEach_itr].BusCreator1 = tmp_0;

    /* End of Start for SubSystem: '<S4>/ConfigProcessing' */

    /* Start for Iterator SubSystem: '<S4>/AxleBrakes' */
    for (ForEach_itr_c = 0; ForEach_itr_c < 6; ForEach_itr_c++) {
      /* Start for Enabled SubSystem: '<S5>/ParkBrakePistonForce' */
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Max = 0.0;

      /* End of Start for SubSystem: '<S5>/ParkBrakePistonForce' */

      /* Start for Enabled SubSystem: '<S5>/BrakingForce' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        UnitDelay_DSTATE = 0.0;
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product = 0.0;
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        BrakeFadePercentage = 0.0;
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation = 0.0;
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Sum1 = 0.0;

      /* Start for Enabled SubSystem: '<S17>/BrakeThermalModel' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        UnitDelay_DSTATE_n = 0.0;
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        DelayInput1_DSTATE = 0.0;
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        DiscreteTimeIntegrator_DSTATE = 0.0;
      localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].BrakeTemperature
        = 0.0;

      /* Start for InitialCondition: '<S31>/IC' */
      localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
        IC_FirstOutputTime = true;

      /* End of Start for SubSystem: '<S17>/BrakeThermalModel' */
      /* End of Start for SubSystem: '<S5>/BrakingForce' */
    }

    /* End of Start for SubSystem: '<S4>/AxleBrakes' */
    /* End of Start for SubSystem: '<S2>/VehicleEnabledBrakes' */
  }

  /* End of Start for SubSystem: '<Root>/VehicleBrakes' */
}

/* Output and update for referenced model: 'TrainBrakes' */
void TrainBrakes(const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8],
                 const BD_TrainBrakes_Cfg_Vehicle rtu_BrakeVehicleConfig[8],
                 const BD_TrainBrakes_In_Vehicle rtu_BrakesVehicleIn[8], const
                 BD_TrainBrakes_In_Vehicle_Overrides rtu_Overrides[8], const
                 BD_TrainBrakes_In_Vehicle_Faults rtu_Faults[8],
                 BD_TrainBrakes_Out_Vehicle rty_BrakesVehicleOut[8],
                 B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T *localDW, const
                 BD_TrainBrakes_Prm_Vehicle *rtp_PRM_TrainBrakes_Vehicles)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_ParkBrakePressure_at_outport_0;
  real_T rtb_LookupTableDynamic;
  real_T rtb_DataTypeConversion2;
  boolean_T rtb_IC;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T rtb_InitFlag;
  boolean_T rtb_OR2;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BrakeShoeOverheatFault;
  real_T rtb_VectorConcatenate[7];
  real_T rtb_VectorConcatenate1_k[7];
  real_T rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[6];
  boolean_T rtb_OR4;
  boolean_T rtb_OR1;
  real_T rtb_DataTypeConversion3;
  real_T rtb_DataTypeConversion4;
  real_T rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[6];
  real_T rtb_DataTypeConversion1;
  BD_TrainBrakes_Out_Vehicle_Axle
    rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[6];
  real_T rtb_Gain;
  real_T rtb_Abs;
  real_T rtb_SelReset;
  int32_T i;
  real_T rtb_VectorConcatenate1_idx_0;
  real_T tmp;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      TrainBrakes_P.DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainBrakes_P.DiscreteTimeIntegrator_UpperSat;
    rtb_InitFlag = 1;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE <=
             TrainBrakes_P.DiscreteTimeIntegrator_LowerSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainBrakes_P.DiscreteTimeIntegrator_LowerSat;
    rtb_InitFlag = -1;
  } else {
    rtb_InitFlag = 0;
  }

  /* End of DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Logic: '<S1>/Logical Operator'
   */
  rtb_InitFlag = (rtb_InitFlag == 0);

  /* Outputs for Iterator SubSystem: '<Root>/VehicleBrakes' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S2>/TrainBrakesIn' */
    rtb_DataTypeConversion3 = rtu_BrakesVehicleIn[ForEach_itr].VehicleVelocity;

    /* ForEachSliceSelector generated from: '<S2>/Overrides' */
    rtb_DataTypeConversion4 = rtu_Overrides[ForEach_itr].ParkBrakeOverride;

    /* ForEachSliceSelector generated from: '<S2>/Faults' */
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BrakeShoeOverheatFault =
      rtu_Faults[ForEach_itr].BrakeShoeOverheatFault;

    /* Outputs for Enabled SubSystem: '<S2>/VehicleEnabledBrakes' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    /* ForEachSliceSelector generated from: '<S2>/CommonVehicleConfig' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant3'
     */
    if (rtu_CommonVehicleConfig[ForEach_itr].Enabled) {
      if (!localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE) {
        localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE = true;
      }

      for (i = 0; i < 6; i++) {
        /* RelationalOperator: '<S7>/Compare' incorporates:
         *  Constant: '<S4>/Constant'
         *  Constant: '<S7>/Constant'
         */
        localB->CoreSubsys[ForEach_itr].Compare[i] =
          (rtp_PRM_TrainBrakes_Vehicles->Equipment.AxleBrakeConfig[i] >
           TrainBrakes_P.CoreSubsys.Constant_Value_iu);

        /* RelationalOperator: '<S8>/Compare' incorporates:
         *  Constant: '<S4>/Constant1'
         *  Constant: '<S8>/Constant'
         */
        localB->CoreSubsys[ForEach_itr].Compare_a[i] =
          (rtp_PRM_TrainBrakes_Vehicles->Equipment.AxleParkBrakeConfig[i] >
           TrainBrakes_P.CoreSubsys.Constant_Value_iw);
      }

      /* Outputs for Enabled SubSystem: '<S4>/ConfigProcessing' incorporates:
       *  EnablePort: '<S9>/Enable'
       */
      if (rtb_InitFlag > 0) {
        /* Assertion: '<S34>/Assertion' incorporates:
         *  Constant: '<S35>/Constant'
         *  ForEachSliceSelector generated from: '<S2>/BrakesVehicleConfig'
         *  RelationalOperator: '<S35>/Compare'
         */
        utAssert(rtu_BrakeVehicleConfig[ForEach_itr].BrakeShoeFrictionCoeff >
                 TrainBrakes_P.CoreSubsys.InvalidZeroOrNegativeFriction_const);

        /* BusCreator: '<S33>/Bus Creator1' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/BrakesVehicleConfig'
         */
        localB->CoreSubsys[ForEach_itr].BusCreator1 =
          rtu_BrakeVehicleConfig[ForEach_itr];
      }

      /* End of Outputs for SubSystem: '<S4>/ConfigProcessing' */
      rtb_VectorConcatenate[0] = TrainBrakes_P.CoreSubsys.Constant1_Value;

      /* SignalConversion generated from: '<S6>/Vector Concatenate' incorporates:
       *  Constant: '<S6>/Constant1'
       *  ForEachSliceSelector generated from: '<S2>/TrainBrakesIn'
       */
      for (i = 0; i < 6; i++) {
        rtb_VectorConcatenate[i + 1] = rtu_BrakesVehicleIn[ForEach_itr].
          BrakeCylinderPressure[i];
      }

      rtb_VectorConcatenate1_k[0] = TrainBrakes_P.CoreSubsys.Constant3_Value;
      for (i = 0; i < 6; i++) {
        /* Selector: '<S6>/Selector' incorporates:
         *  Constant: '<S6>/Constant'
         */
        localB->CoreSubsys[ForEach_itr].Selector[i] = rtb_VectorConcatenate[
          static_cast<int32_T>
          (rtp_PRM_TrainBrakes_Vehicles->Equipment.AxleBrakeConfig[i])];

        /* SignalConversion generated from: '<S6>/Vector Concatenate1' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TrainBrakesIn'
         */
        rtb_VectorConcatenate1_k[i + 1] = rtu_BrakesVehicleIn[ForEach_itr].
          ParkBrakePressure[i];
      }

      /* Selector: '<S6>/Selector1' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant3'
       */
      for (i = 0; i < 6; i++) {
        localB->CoreSubsys[ForEach_itr].Selector1[i] = rtb_VectorConcatenate1_k[
          static_cast<int32_T>
          (rtp_PRM_TrainBrakes_Vehicles->Equipment.AxleParkBrakeConfig[i])];
      }

      /* End of Selector: '<S6>/Selector1' */

      /* Outputs for Iterator SubSystem: '<S4>/AxleBrakes' incorporates:
       *  ForEach: '<S5>/For Each'
       */
      for (ForEach_itr_c = 0; ForEach_itr_c < 6; ForEach_itr_c++) {
        /* ForEachSliceSelector generated from: '<S5>/ParkBrakePressure' */
        rtb_ImpSel_InsertedFor_ParkBrakePressure_at_outport_0 =
          localB->CoreSubsys[ForEach_itr].Selector1[ForEach_itr_c];

        /* Outputs for Enabled SubSystem: '<S5>/ParkBrakePistonForce' incorporates:
         *  EnablePort: '<S13>/Enable'
         */
        if (localB->CoreSubsys[ForEach_itr].Compare_a[ForEach_itr_c]) {
          /* S-Function (sfix_look1_dyn): '<S13>/Lookup Table Dynamic' incorporates:
           *  Constant: '<S13>/Constant1'
           *  Constant: '<S13>/Constant2'
           */
          /* Dynamic Look-Up Table Block: '<S13>/Lookup Table Dynamic'
           * Input0  Data Type:  Floating Point real_T
           * Input1  Data Type:  Floating Point real_T
           * Input2  Data Type:  Floating Point real_T
           * Output0 Data Type:  Floating Point real_T
           * Lookup Method: Linear_Endpoint
           *
           */
          LookUp_real_T_real_T( &(rtb_DataTypeConversion2),
                               &rtp_PRM_TrainBrakes_Vehicles->ParkBrakes.AxleParkBrakePistonForces
                               [0],
                               rtb_ImpSel_InsertedFor_ParkBrakePressure_at_outport_0,
                               &rtp_PRM_TrainBrakes_Vehicles->ParkBrakes.ParkBrakePressures
                               [0], 1U);

          /* Switch: '<S13>/Switch' incorporates:
           *  Abs: '<S13>/Abs'
           *  DataTypeConversion: '<S13>/Data Type Conversion'
           *  ForEachSliceSelector generated from: '<S2>/TrainBrakesIn'
           *  Logic: '<S13>/OR'
           */
          if (fabs(rtb_DataTypeConversion4) >
              TrainBrakes_P.CoreSubsys.CoreSubsys.Switch_Threshold) {
            /* Saturate: '<S13>/Saturation' */
            if (rtb_DataTypeConversion4 >
                TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat) {
              rtb_DataTypeConversion1 =
                TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat;
            } else if (rtb_DataTypeConversion4 <
                       TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat)
            {
              rtb_DataTypeConversion1 =
                TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat;
            } else {
              rtb_DataTypeConversion1 = rtb_DataTypeConversion4;
            }

            /* End of Saturate: '<S13>/Saturation' */
          } else {
            rtb_DataTypeConversion1 = ((rtu_BrakesVehicleIn[ForEach_itr].
              ManualHandBrakeApplication != 0.0) ||
              (rtu_BrakesVehicleIn[ForEach_itr].ElectricParkBrakeApplication !=
               0.0));
          }

          /* End of Switch: '<S13>/Switch' */

          /* MinMax: '<S13>/Max1' incorporates:
           *  Constant: '<S13>/Constant1'
           */
          if ((rtp_PRM_TrainBrakes_Vehicles->ParkBrakes.AxleParkBrakePistonForces
               [0] >
               rtp_PRM_TrainBrakes_Vehicles->ParkBrakes.AxleParkBrakePistonForces
               [1]) || rtIsNaN
              (rtp_PRM_TrainBrakes_Vehicles->ParkBrakes.AxleParkBrakePistonForces
               [1])) {
            tmp =
              rtp_PRM_TrainBrakes_Vehicles->
              ParkBrakes.AxleParkBrakePistonForces[0];
          } else {
            tmp =
              rtp_PRM_TrainBrakes_Vehicles->
              ParkBrakes.AxleParkBrakePistonForces[1];
          }

          /* End of MinMax: '<S13>/Max1' */

          /* Product: '<S13>/Product1' */
          rtb_DataTypeConversion1 *= tmp;

          /* MinMax: '<S13>/Max' */
          if ((rtb_DataTypeConversion1 > rtb_DataTypeConversion2) || rtIsNaN
              (rtb_DataTypeConversion2)) {
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Max =
              rtb_DataTypeConversion1;
          } else {
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Max =
              rtb_DataTypeConversion2;
          }

          /* End of MinMax: '<S13>/Max' */
        }

        /* End of Outputs for SubSystem: '<S5>/ParkBrakePistonForce' */

        /* Product: '<S11>/Product3' incorporates:
         *  Constant: '<S11>/Constant'
         *  Constant: '<S11>/Constant1'
         *  Constant: '<S11>/Constant2'
         *  Constant: '<S11>/Constant3'
         *  Constant: '<S11>/Constant4'
         *  Constant: '<S11>/Constant5'
         *  Constant: '<S11>/PAtm'
         *  ForEachSliceSelector generated from: '<S5>/ParkBrakeAxleEnabled'
         *  Product: '<S11>/Product'
         *  Product: '<S11>/Product1'
         *  Product: '<S11>/Product2'
         *  Product: '<S11>/Product4'
         *  Sum: '<S11>/Sum'
         */
        rtb_DataTypeConversion1 = ((localB->CoreSubsys[ForEach_itr]
          .Selector[ForEach_itr_c] - TrainBrakes_P.pAtm) -
          rtp_PRM_TrainBrakes_Vehicles->BrakeCylinder.BrakeCylinderPreload) *
          rtp_PRM_TrainBrakes_Vehicles->Equipment.NumberOfBrakeCylindersPerAxle *
          rtp_PRM_TrainBrakes_Vehicles->BrakeCylinder.BrakeCylinderArea *
          rtp_PRM_TrainBrakes_Vehicles->BrakeCylinder.BrakeBeamFactor *
          (rtp_PRM_TrainBrakes_Vehicles->BrakeCylinder.BrakeEfficiency /
           TrainBrakes_P.CoreSubsys.CoreSubsys.Constant4_Value);

        /* Saturate: '<S11>/Saturation' */
        if (rtb_DataTypeConversion1 >
            TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_i) {
          rtb_DataTypeConversion1 =
            TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_i;
        } else {
          if (rtb_DataTypeConversion1 <
              TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_o) {
            rtb_DataTypeConversion1 =
              TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_o;
          }
        }

        /* End of Saturate: '<S11>/Saturation' */

        /* MinMax: '<S5>/Max' */
        if ((!(rtb_DataTypeConversion1 > localB->CoreSubsys[ForEach_itr].
               CoreSubsys[ForEach_itr_c].Max)) && (!rtIsNaN(localB->
              CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Max))) {
          rtb_DataTypeConversion1 = localB->CoreSubsys[ForEach_itr]
            .CoreSubsys[ForEach_itr_c].Max;
        }

        /* End of MinMax: '<S5>/Max' */

        /* Outputs for Enabled SubSystem: '<S5>/BrakingForce' incorporates:
         *  EnablePort: '<S12>/Enable'
         */
        if (localB->CoreSubsys[ForEach_itr].Compare[ForEach_itr_c]) {
          localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            BrakingForce_MODE = true;

          /* Abs: '<S16>/Abs' */
          rtb_Abs = fabs(rtb_DataTypeConversion3);

          /* SwitchCase: '<S16>/Switch Case' incorporates:
           *  Inport: '<S19>/ConstantCoefficient'
           */
          if (localB->CoreSubsys[ForEach_itr].
              BusCreator1.BrakeShoeCoefficientCalculationMethod ==
              BrakeShoeCoefficientCalculationMethod_ConstantBSC) {
            /* Outputs for IfAction SubSystem: '<S16>/Constant' incorporates:
             *  ActionPort: '<S19>/Action Port'
             */
            rtb_Gain = localB->CoreSubsys[ForEach_itr].
              BusCreator1.BrakeShoeFrictionCoeff;

            /* End of Outputs for SubSystem: '<S16>/Constant' */
          } else {
            /* Outputs for IfAction SubSystem: '<S16>/Custom' incorporates:
             *  ActionPort: '<S20>/Action Port'
             */
            /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
             *  Constant: '<S22>/Constant'
             *  Product: '<S24>/Divide'
             *  Sum: '<S24>/Sum of Elements'
             */
            switch (rtp_PRM_TrainBrakes_Vehicles->Equipment.BrakeShoeType) {
             case BrakeShoeType_Composition:
              rtb_Gain = (rtb_Abs + 19.223) * 0.21 / (rtb_Abs + 9.388);
              break;

             case BrakeShoeType_CastIron:
              /* DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
               *  Constant: '<S25>/Constant'
               *  RelationalOperator: '<S25>/Compare'
               */
              rtb_SelReset = (rtb_DataTypeConversion1 >
                              TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value);

              /* Saturate: '<S24>/Saturation' */
              if (rtb_SelReset >
                  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_f) {
                rtb_SelReset =
                  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_f;
              } else {
                if (rtb_SelReset <
                    TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_b) {
                  rtb_SelReset =
                    TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_b;
                }
              }

              /* End of Saturate: '<S24>/Saturation' */
              rtb_Gain = ((rtb_Abs * rtb_Abs + 224.2) + rtb_DataTypeConversion1 /
                          rtb_SelReset * 0.0089) * 0.00313 / (rtb_Abs + 7.153);
              break;

             case BrakeShoeType_HT45:
              rtb_Gain = (rtb_Abs + 10.729) * 0.294 / (rtb_Abs + 6.259);
              break;

             case BrakeShoeType_LT22:
              rtb_Gain = (rtb_Abs + 10.729) * 0.13 / (rtb_Abs + 4.023);
              break;

             case BrakeShoeType_LT14:
              rtb_Gain = (rtb_Abs + 14.752) * 0.197 / (rtb_Abs + 5.812);
              break;

             default:
              rtb_Gain = (rtb_Abs + 32.187) * 0.323 / (rtb_Abs + 25.034);
              break;
            }

            /* End of MATLAB Function: '<S22>/MATLAB Function' */
            /* End of Outputs for SubSystem: '<S16>/Custom' */
          }

          /* End of SwitchCase: '<S16>/Switch Case' */

          /* Product: '<S14>/BrakeFrictionForce' */
          rtb_Abs = rtb_DataTypeConversion1 * rtb_Gain;

          /* Gain: '<S14>/Multiply' */
          rtb_VectorConcatenate1_idx_0 =
            TrainBrakes_P.CoreSubsys.CoreSubsys.Multiply_Gain *
            rtu_CommonVehicleConfig[ForEach_itr].WheelDiameter;

          /* Outputs for Enabled SubSystem: '<S17>/BrakeThermalModel' incorporates:
           *  EnablePort: '<S26>/Enable'
           */
          if (localB->CoreSubsys[ForEach_itr].BusCreator1.BrakeTemperatureEnable
              > 0.0) {
            if (!localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                BrakeThermalModel_MODE) {
              /* Enable for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
              localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;
              localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                BrakeThermalModel_MODE = true;
            }

            /* Fcn: '<S28>/( 2*rho_a*R*v // mu_va )0.8' incorporates:
             *  Constant: '<S28>/AirMuv'
             *  Constant: '<S28>/AirRho'
             *  SignalConversion generated from: '<S28>/Vector Concatenate1'
             */
            rtb_Gain = 2.0 *
              TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirDensity *
              rtb_VectorConcatenate1_idx_0 * rtb_DataTypeConversion3 /
              TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirDynamicViscosity;

            /* Fcn: '<S28>/( Cp_a * mu_va // k_a )0.33' incorporates:
             *  Constant: '<S28>/AirCp'
             *  Constant: '<S28>/AirK'
             *  Constant: '<S28>/AirMuv'
             */
            tmp =
              TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirSpecificHeat
              * TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirDynamicViscosity
              /
              TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirThermalConductivity;

            /* Logic: '<S29>/OR' incorporates:
             *  RelationalOperator: '<S30>/FixPt Relational Operator'
             *  UnitDelay: '<S30>/Delay Input1'
             */
            rtb_OR4 = ((localB->CoreSubsys[ForEach_itr].
                        BusCreator1.BrakeTemperatureEnable !=
                        localDW->CoreSubsys[ForEach_itr]
                        .CoreSubsys[ForEach_itr_c].DelayInput1_DSTATE) ||
                       (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BrakeShoeOverheatFault
                        != 0.0));

            /* InitialCondition: '<S31>/IC' */
            if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                IC_FirstOutputTime) {
              localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                IC_FirstOutputTime = false;
              rtb_IC = TrainBrakes_P.CoreSubsys.CoreSubsys.IC_Value;
            } else {
              rtb_IC = rtb_OR4;
            }

            /* End of InitialCondition: '<S31>/IC' */

            /* Switch: '<S31>/SelReset' incorporates:
             *  Constant: '<S31>/InitValue'
             */
            if (rtb_OR4) {
              /* Switch: '<S29>/Switch' incorporates:
               *  Constant: '<S29>/Constant'
               *  Constant: '<S29>/OvertemperatureEnergy'
               */
              if (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BrakeShoeOverheatFault
                  > TrainBrakes_P.CoreSubsys.CoreSubsys.Switch_Threshold_l) {
                rtb_SelReset =
                  TrainBrakes_P.CoreSubsys.CoreSubsys.OvertemperatureEnergy_Value;
              } else {
                rtb_SelReset =
                  TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_a;
              }

              /* End of Switch: '<S29>/Switch' */
            } else {
              rtb_SelReset =
                TrainBrakes_P.CoreSubsys.CoreSubsys.DiscreteIntegratorWithReset_InitValue;
            }

            /* End of Switch: '<S31>/SelReset' */

            /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
             *  Abs: '<S26>/Abs'
             *  Constant: '<S26>/AmbientAirTemp'
             *  Constant: '<S26>/BrakeEpsilon'
             *  Constant: '<S26>/ConvectiveArea'
             *  Constant: '<S26>/StefanBoltzmannSigma'
             *  Constant: '<S28>/AirK'
             *  Fcn: '<S26>/T4 - Ta4'
             *  Fcn: '<S28>/0.037*k_a // (2*R)'
             *  ForEachSliceSelector generated from: '<S2>/TrainBrakesIn'
             *  Product: '<S26>/Product2'
             *  Product: '<S26>/Product4'
             *  Product: '<S26>/Product5'
             *  Product: '<S26>/Product6'
             *  Product: '<S28>/Product4'
             *  SignalConversion generated from: '<S26>/Vector Concatenate'
             *  Sum: '<S26>/Subtract'
             *  UnitDelay: '<S17>/Unit Delay'
             *  UnitDelay: '<S26>/Unit Delay'
             */
            if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                DiscreteTimeIntegrator_SYSTEM_ENABLE != 0) {
              if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                  DiscreteTimeIntegrator_IC_LOADING != 0) {
                localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                  DiscreteTimeIntegrator_DSTATE = rtb_SelReset;
              }

              rtb_Gain = localDW->CoreSubsys[ForEach_itr]
                .CoreSubsys[ForEach_itr_c].DiscreteTimeIntegrator_DSTATE;
            } else if (rtb_IC || (localDW->CoreSubsys[ForEach_itr]
                                  .CoreSubsys[ForEach_itr_c].
                                  DiscreteTimeIntegrator_PrevResetState != 0)) {
              localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                DiscreteTimeIntegrator_DSTATE = rtb_SelReset;
              rtb_Gain = localDW->CoreSubsys[ForEach_itr]
                .CoreSubsys[ForEach_itr_c].DiscreteTimeIntegrator_DSTATE;
            } else {
              /* Sum: '<S26>/Subtract1' incorporates:
               *  Constant: '<S26>/AmbientAirTemp'
               *  UnitDelay: '<S26>/Unit Delay'
               */
              rtb_SelReset = localDW->CoreSubsys[ForEach_itr]
                .CoreSubsys[ForEach_itr_c].UnitDelay_DSTATE_n -
                TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AmbientTemperature;

              /* Fcn: '<S28>/( 2*rho_a*R*v // mu_va )0.8' */
              if (rtb_Gain < 0.0) {
                rtb_Gain = -rt_powd_snf(-rtb_Gain, 0.8);
              } else {
                rtb_Gain = rt_powd_snf(rtb_Gain, 0.8);
              }

              /* Fcn: '<S28>/( Cp_a * mu_va // k_a )0.33' */
              if (tmp < 0.0) {
                tmp = -rt_powd_snf(-tmp, 0.33);
              } else {
                tmp = rt_powd_snf(tmp, 0.33);
              }

              /* Saturate: '<S26>/Saturation' */
              if (rtb_SelReset >
                  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_m) {
                rtb_SelReset =
                  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_m;
              } else {
                if (rtb_SelReset <
                    TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_a) {
                  rtb_SelReset =
                    TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_a;
                }
              }

              /* End of Saturate: '<S26>/Saturation' */
              rtb_Gain = ((fabs(localDW->CoreSubsys[ForEach_itr]
                                .CoreSubsys[ForEach_itr_c].UnitDelay_DSTATE *
                                rtu_BrakesVehicleIn[ForEach_itr]
                                .WheelSpeed[ForEach_itr_c]) - 0.037 *
                           TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AirThermalConductivity
                           / (2.0 * rtb_VectorConcatenate1_idx_0) * rtb_Gain *
                           tmp *
                           TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_ConvectiveArea
                           * rtb_SelReset) - (rt_powd_snf(localDW->
                CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                UnitDelay_DSTATE_n, 4.0) - rt_powd_snf
                (TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_AmbientTemperature,
                 4.0)) * TrainBrakes_P.CoreSubsys.CoreSubsys.BrakeThermalFade_ConvectiveArea
                          * (rtp_PRM_TrainBrakes_Vehicles->ThermalModel.BrakeEmissivity
                             * TrainBrakes_P.CoreSubsys.CoreSubsys.StefanBoltzmannSigma_Value))
                * TrainBrakes_P.CoreSubsys.CoreSubsys.DiscreteTimeIntegrator_gainval
                + localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
                DiscreteTimeIntegrator_DSTATE;
            }

            /* End of DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */

            /* Product: '<S26>/Product3' incorporates:
             *  Constant: '<S26>/BrakeCp'
             *  Constant: '<S26>/BrakeThermalMass'
             */
            rtb_SelReset =
              rtp_PRM_TrainBrakes_Vehicles->ThermalModel.BrakeThermalMass *
              rtp_PRM_TrainBrakes_Vehicles->ThermalModel.BrakeSpecificHeat;

            /* MinMax: '<S26>/SafeDivide' incorporates:
             *  Constant: '<S26>/Constant'
             */
            if ((!(rtb_SelReset >
                   TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_n)) &&
                (!rtIsNaN(TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_n)))
            {
              rtb_SelReset =
                TrainBrakes_P.CoreSubsys.CoreSubsys.Constant_Value_n;
            }

            /* End of MinMax: '<S26>/SafeDivide' */

            /* Sum: '<S26>/Add' incorporates:
             *  Constant: '<S26>/BrakesInitialTemp'
             *  Product: '<S26>/Divide'
             */
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakeTemperature = rtb_Gain / rtb_SelReset +
              rtp_PRM_TrainBrakes_Vehicles->ThermalModel.BrakeInitialTemperature;

            /* Update for UnitDelay: '<S26>/Unit Delay' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              UnitDelay_DSTATE_n = localB->CoreSubsys[ForEach_itr]
              .CoreSubsys[ForEach_itr_c].BrakeTemperature;

            /* Update for UnitDelay: '<S30>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              DelayInput1_DSTATE = localB->CoreSubsys[ForEach_itr].
              BusCreator1.BrakeTemperatureEnable;

            /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              DiscreteTimeIntegrator_IC_LOADING = 0U;
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              DiscreteTimeIntegrator_DSTATE = rtb_Gain;
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>(rtb_IC);
          } else {
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakeThermalModel_MODE = false;
          }

          /* End of Outputs for SubSystem: '<S17>/BrakeThermalModel' */

          /* Switch: '<S27>/Switch2' incorporates:
           *  Constant: '<S27>/Constant1'
           */
          if (localB->CoreSubsys[ForEach_itr].BusCreator1.BrakeFadeEnable >
              TrainBrakes_P.CoreSubsys.CoreSubsys.Switch2_Threshold) {
            /* S-Function (sfix_look1_dyn): '<S27>/Lookup Table Dynamic' incorporates:
             *  Constant: '<S27>/XBrakeTemperatures'
             *  Constant: '<S27>/YBrakeShoeFactors'
             */
            /* Dynamic Look-Up Table Block: '<S27>/Lookup Table Dynamic'
             * Input0  Data Type:  Floating Point real_T
             * Input1  Data Type:  Floating Point real_T
             * Input2  Data Type:  Floating Point real_T
             * Output0 Data Type:  Floating Point real_T
             * Lookup Method: Linear_Endpoint
             *
             */
            LookUp_real_T_real_T( &(rtb_LookupTableDynamic),
                                 &rtp_PRM_TrainBrakes_Vehicles->BrakeFade.BrakeEfficiencies
                                 [0], localB->CoreSubsys[ForEach_itr]
                                 .CoreSubsys[ForEach_itr_c].BrakeTemperature,
                                 &rtp_PRM_TrainBrakes_Vehicles->BrakeFade.BrakeTemperatures
                                 [0], 9U);
            rtb_Gain = rtb_LookupTableDynamic;
          } else {
            rtb_Gain = TrainBrakes_P.CoreSubsys.CoreSubsys.Constant1_Value;
          }

          /* End of Switch: '<S27>/Switch2' */

          /* Saturate: '<S27>/Saturation' */
          if (rtb_Gain >
              TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_fq) {
            rtb_Gain =
              TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_fq;
          } else {
            if (rtb_Gain <
                TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_j) {
              rtb_Gain =
                TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_j;
            }
          }

          /* End of Saturate: '<S27>/Saturation' */

          /* Product: '<S17>/Product' incorporates:
           *  Fcn: '<S18>/Fcn'
           *  ForEachSliceSelector generated from: '<S2>/Overrides'
           *  Product: '<S18>/Product'
           */
          localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product =
            (rtu_Overrides[ForEach_itr].FrictionBrakeForceVariation / 100.0 +
             1.0) * rtb_Abs * rtb_Gain;

          /* Gain: '<S14>/Gain' */
          localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            BrakeFadePercentage = TrainBrakes_P.CoreSubsys.CoreSubsys.Gain_Gain *
            rtb_Gain;

          /* Gain: '<S32>/Gain' */
          rtb_SelReset = (1.0 -
                          rtp_PRM_TrainBrakes_Vehicles->BrakeDisc.DiscBrakeRatio)
            * rtp_PRM_TrainBrakes_Vehicles->BrakeDisc.DiscBrakeRatio *
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product;

          /* Saturate: '<S32>/Saturation' */
          if (rtb_SelReset >
              TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_e) {
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation
              = TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_e;
          } else if (rtb_SelReset <
                     TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_ar)
          {
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation
              = TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_LowerSat_ar;
          } else {
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation
              = rtb_SelReset;
          }

          /* End of Saturate: '<S32>/Saturation' */

          /* Sum: '<S12>/Sum1' */
          localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Sum1 =
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product -
            localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Saturation;

          /* Update for UnitDelay: '<S17>/Unit Delay' */
          localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
            UnitDelay_DSTATE = localB->CoreSubsys[ForEach_itr]
            .CoreSubsys[ForEach_itr_c].Product;
        } else {
          if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakingForce_MODE) {
            /* Disable for Enabled SubSystem: '<S17>/BrakeThermalModel' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakeThermalModel_MODE = false;

            /* End of Disable for SubSystem: '<S17>/BrakeThermalModel' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakingForce_MODE = false;
          }
        }

        /* End of Outputs for SubSystem: '<S5>/BrakingForce' */

        /* ForEachSliceAssignment generated from: '<S5>/BrakeShoeForce' */
        rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[ForEach_itr_c] =
          localB->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Sum1;

        /* ForEachSliceAssignment generated from: '<S5>/BrakePistonForce' */
        rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[ForEach_itr_c] =
          rtb_DataTypeConversion1;

        /* ForEachSliceAssignment generated from: '<S5>/AxleBrakeOut' incorporates:
         *  BusCreator: '<S5>/Bus Creator'
         *  Product: '<S5>/BrakePower'
         */
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakingPower = rtb_DataTypeConversion3 * localB->
          CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].Product;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakingForce = localB->CoreSubsys[ForEach_itr]
          .CoreSubsys[ForEach_itr_c].Product;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakeShoeForce = localB->CoreSubsys[ForEach_itr]
          .CoreSubsys[ForEach_itr_c].Sum1;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakeShoeTemperature = localB->CoreSubsys[ForEach_itr]
          .CoreSubsys[ForEach_itr_c].BrakeTemperature;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakeShoeEfficiency = localB->CoreSubsys[ForEach_itr]
          .CoreSubsys[ForEach_itr_c].BrakeFadePercentage;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          BrakeDiscForce = localB->CoreSubsys[ForEach_itr]
          .CoreSubsys[ForEach_itr_c].Saturation;
        rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[ForEach_itr_c].
          NormalBrakePistonForce = rtb_DataTypeConversion1;
      }

      /* End of Outputs for SubSystem: '<S4>/AxleBrakes' */

      /* Logic: '<S36>/OR5' incorporates:
       *  Constant: '<S39>/Constant'
       *  ForEachSliceSelector generated from: '<S5>/ParkBrakeAxleEnabled'
       *  RelationalOperator: '<S39>/Compare'
       */
      rtb_OR2 = ((rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[0] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant5_const) ||
                 (rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[1] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant5_const));

      /* Logic: '<S36>/OR6' incorporates:
       *  Constant: '<S40>/Constant'
       *  RelationalOperator: '<S40>/Compare'
       */
      rtb_OR4 = ((rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[2] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant6_const) ||
                 (rtb_ImpAsg_InsertedFor_BrakePistonForce_at_inport_0[3] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant6_const));

      /* DataTypeConversion: '<S36>/Data Type Conversion3' incorporates:
       *  Logic: '<S36>/OR3'
       */
      rtb_DataTypeConversion3 = (rtb_OR2 || rtb_OR4);

      /* DataTypeConversion: '<S36>/Data Type Conversion4' */
      rtb_DataTypeConversion4 = rtb_OR4;

      /* Logic: '<S36>/OR1' incorporates:
       *  Constant: '<S37>/Constant'
       *  RelationalOperator: '<S37>/Compare'
       */
      rtb_OR1 = ((rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[0] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant2_const) ||
                 (rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[1] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant2_const));

      /* Logic: '<S36>/OR4' incorporates:
       *  Constant: '<S38>/Constant'
       *  RelationalOperator: '<S38>/Compare'
       */
      rtb_OR4 = ((rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[2] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant3_const) ||
                 (rtb_ImpAsg_InsertedFor_BrakeShoeForce_at_inport_0[3] >=
                  TrainBrakes_P.CoreSubsys.CompareToConstant3_const));

      /* DataTypeConversion: '<S36>/Data Type Conversion2' incorporates:
       *  Logic: '<S36>/OR2'
       */
      rtb_DataTypeConversion2 = (rtb_OR1 || rtb_OR4);

      /* BusAssignment: '<S10>/Bus Assignment' incorporates:
       *  BusAssignment: '<S36>/Bus Assignment'
       *  Constant: '<S10>/Constant'
       *  DataTypeConversion: '<S36>/Data Type Conversion'
       *  DataTypeConversion: '<S36>/Data Type Conversion1'
       *  DataTypeConversion: '<S36>/Data Type Conversion5'
       */
      localB->CoreSubsys[ForEach_itr].TrainBrakesOut =
        TrainBrakes_P.CoreSubsys.Constant_Value;
      memcpy(&localB->CoreSubsys[ForEach_itr].TrainBrakesOut.Axle[0],
             &rtb_ImpAsg_InsertedFor_AxleBrakeOut_at_inport_0[0], 6U * sizeof
             (BD_TrainBrakes_Out_Vehicle_Axle));
      localB->CoreSubsys[ForEach_itr].TrainBrakesOut.States.BCPEngaged =
        rtb_DataTypeConversion3;
      localB->CoreSubsys[ForEach_itr].TrainBrakesOut.States.BCPEngagedBogie1 =
        rtb_OR2;
      localB->CoreSubsys[ForEach_itr].TrainBrakesOut.States.BCPEngagedBogie2 =
        rtb_DataTypeConversion4;
      localB->CoreSubsys[ForEach_itr].TrainBrakesOut.States.WheelBrakeBlocks =
        rtb_DataTypeConversion2;
      localB->CoreSubsys[ForEach_itr].
        TrainBrakesOut.States.WheelBrakeBlocksBogie1 = rtb_OR1;
      localB->CoreSubsys[ForEach_itr].
        TrainBrakesOut.States.WheelBrakeBlocksBogie2 = rtb_OR4;
    } else {
      if (localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE) {
        /* Disable for Iterator SubSystem: '<S4>/AxleBrakes' */
        for (ForEach_itr_c = 0; ForEach_itr_c < 6; ForEach_itr_c++) {
          /* Disable for Enabled SubSystem: '<S5>/BrakingForce' */
          if (localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakingForce_MODE) {
            /* Disable for Enabled SubSystem: '<S17>/BrakeThermalModel' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakeThermalModel_MODE = false;

            /* End of Disable for SubSystem: '<S17>/BrakeThermalModel' */
            localDW->CoreSubsys[ForEach_itr].CoreSubsys[ForEach_itr_c].
              BrakingForce_MODE = false;
          }

          /* End of Disable for SubSystem: '<S5>/BrakingForce' */
        }

        /* End of Disable for SubSystem: '<S4>/AxleBrakes' */
        localDW->CoreSubsys[ForEach_itr].VehicleEnabledBrakes_MODE = false;
      }
    }

    /* End of ForEachSliceSelector generated from: '<S2>/CommonVehicleConfig' */
    /* End of Outputs for SubSystem: '<S2>/VehicleEnabledBrakes' */

    /* ForEachSliceAssignment generated from: '<S2>/TrainBrakesOut' */
    rty_BrakesVehicleOut[ForEach_itr] = localB->CoreSubsys[ForEach_itr].
      TrainBrakesOut;
  }

  /* End of Outputs for SubSystem: '<Root>/VehicleBrakes' */

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  localDW->DiscreteTimeIntegrator_DSTATE +=
    TrainBrakes_P.DiscreteTimeIntegrator_gainval * TrainBrakes_P.Constant_Value;
  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      TrainBrakes_P.DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainBrakes_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <=
        TrainBrakes_P.DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        TrainBrakes_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
}

/* Model initialize function */
void TrainBrakes_initialize(const char_T **rt_errorStatus,
  RT_MODEL_TrainBrakes_T *const TrainBrakes_M, B_TrainBrakes_c_T *localB,
  DW_TrainBrakes_f_T *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const
  char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  TrainBrakes_P.DiscreteTimeIntegrator_LowerSat = rtMinusInf;
  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_f = rtInf;
  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_m = rtInf;
  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_e = rtInf;
  TrainBrakes_P.CoreSubsys.CoreSubsys.Saturation_UpperSat_i = rtInf;

  /* initialize error status */
  rtmSetErrorStatusPointer(TrainBrakes_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_TrainBrakes_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_TrainBrakes_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    TrainBrakes_InitializeDataMapInfo(TrainBrakes_M, localB, localDW);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(TrainBrakes_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(TrainBrakes_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(TrainBrakes_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
