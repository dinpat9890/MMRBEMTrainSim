/*
 * Code generation for system model 'PneumaticsSystem'
 *
 * Model                      : PneumaticsSystem
 * Model version              : 1.664
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PneumaticsSystem_capi.h"
#include "PneumaticsSystem.h"
#include "PneumaticsSystem_private.h"
#include "LookUp_real_T_real_T.h"

P_PneumaticsSystem_T PneumaticsSystem_P = {
  /* Variable: PAtm
   * Referenced by:
   *   '<S24>/Constant'
   *   '<S24>/pAtm'
   *   '<S59>/Bias'
   *   '<S214>/Bias'
   *   '<S214>/Constant'
   *   '<S214>/pAtm'
   *   '<S229>/Bias'
   *   '<S229>/Constant'
   *   '<S229>/pAtm'
   *   '<S230>/Bias'
   *   '<S230>/Constant'
   *   '<S230>/pAtm'
   *   '<S25>/Constant1'
   *   '<S26>/Constant'
   *   '<S60>/Bias'
   *   '<S60>/Constant'
   *   '<S60>/pAtm'
   *   '<S61>/Bias'
   *   '<S61>/Bias1'
   *   '<S61>/Constant'
   *   '<S61>/pAtm'
   *   '<S62>/Bias'
   *   '<S62>/Constant'
   *   '<S62>/pAtm'
   *   '<S123>/Bias'
   *   '<S123>/Constant'
   *   '<S123>/pAtm'
   *   '<S211>/Bias'
   *   '<S216>/Constant1'
   *   '<S217>/Constant'
   *   '<S231>/Constant'
   *   '<S231>/Overpressure'
   *   '<S233>/Constant1'
   *   '<S256>/Constant1'
   *   '<S64>/Constant1'
   *   '<S65>/Constant'
   *   '<S65>/Overpressure'
   *   '<S75>/Constant1'
   *   '<S75>/pAtm1'
   *   '<S77>/Constant'
   *   '<S82>/Constant1'
   *   '<S102>/pAtm'
   *   '<S103>/Constant1'
   *   '<S124>/Bias'
   *   '<S124>/limiter1'
   *   '<S125>/Constant1'
   *   '<S127>/Constant'
   *   '<S149>/Bias'
   *   '<S149>/Bias1'
   *   '<S149>/Bias2'
   *   '<S149>/Bias3'
   *   '<S149>/pAtm'
   *   '<S150>/Bias'
   *   '<S150>/Atmospheric'
   *   '<S152>/Bias'
   *   '<S152>/Bias1'
   *   '<S152>/Constant'
   *   '<S152>/Constant1'
   *   '<S84>/Constant1'
   *   '<S157>/CrushRevertingPistonValve 02'
   *   '<S192>/Constant'
   *   '<S192>/pAtm'
   *   '<S194>/Constant1'
   *   '<S195>/Constant'
   */
  101300.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Start of '<S3>/CoreSubsys' */
  {
    /* Mask Parameter: AirSuspensionReservoir_MaxPressure
     * Referenced by: '<S24>/Constant'
     */
    1.0E+6,

    /* Mask Parameter: ARPressureSwitch12_OffOutputValue
     * Referenced by: '<S63>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: PS2_OffOutputValue
     * Referenced by: '<S79>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: PanPressureSwitch_OffOutputValue
     * Referenced by: '<S80>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: VCBPressureSwitch1_OffOutputValue
     * Referenced by: '<S104>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: BSRPressureSwitch05_OffOutputValue
     * Referenced by: '<S215>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: MRPressureSwitch06_OffOutputValue
     * Referenced by: '<S232>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: A00A14_OffOutputValue
     * Referenced by: '<S253>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: B27B22_OffOutputValue
     * Referenced by: '<S254>/PressureSwitch'
     */
    0.0,

    /* Mask Parameter: B27B22_OffSwitchValue
     * Referenced by: '<S254>/PressureSwitch'
     */
    600000.0,

    /* Mask Parameter: ARPressureSwitch12_OnOutputValue
     * Referenced by: '<S63>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: PS2_OnOutputValue
     * Referenced by: '<S79>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: PanPressureSwitch_OnOutputValue
     * Referenced by: '<S80>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: VCBPressureSwitch1_OnOutputValue
     * Referenced by: '<S104>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: BSRPressureSwitch05_OnOutputValue
     * Referenced by: '<S215>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: MRPressureSwitch06_OnOutputValue
     * Referenced by: '<S232>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: A00A14_OnOutputValue
     * Referenced by: '<S253>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: B27B22_OnOutputValue
     * Referenced by: '<S254>/PressureSwitch'
     */
    1.0,

    /* Mask Parameter: B27B22_OnSwitchValue
     * Referenced by:
     *   '<S254>/InitialConditionValue'
     *   '<S254>/PressureSwitch'
     */
    700000.0,

    /* Mask Parameter: AirSuspensionReservoir_ResetPressure
     * Referenced by: '<S25>/Constant1'
     */
    900000.0,

    /* Mask Parameter: AirSuspensionReservoir_Volume
     * Referenced by: '<S24>/pAtm2'
     */
    0.05,

    /* Mask Parameter: HighHorn_const
     * Referenced by: '<S116>/Constant'
     */
    1.0,

    /* Mask Parameter: LowHorn_const
     * Referenced by: '<S117>/Constant'
     */
    1.0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S224>/Constant'
     */
    880000.0,

    /* Mask Parameter: CompareToConstant_const_a
     * Referenced by: '<S32>/Constant'
     */
    780000.0,

    /* Mask Parameter: BSRVentDrain_p_deadband
     * Referenced by: '<S26>/BSR Vent Drain'
     */
    1000.0,

    /* Mask Parameter: BSRVentIC_p_deadband
     * Referenced by: '<S26>/BSR Vent IC'
     */
    1000.0,

    /* Mask Parameter: ARVentDrain_p_deadband
     * Referenced by: '<S65>/AR Vent Drain'
     */
    1000.0,

    /* Mask Parameter: ARBlowoff_p_deadband
     * Referenced by: '<S65>/AR Blowoff'
     */
    1000.0,

    /* Mask Parameter: PCVentIsol_p_deadband
     * Referenced by: '<S77>/PC Vent Isol'
     */
    500.0,

    /* Mask Parameter: PCVentControl_p_deadband
     * Referenced by: '<S77>/PC Vent Control'
     */
    1000.0,

    /* Mask Parameter: VCBIsolate_p_deadband
     * Referenced by: '<S102>/VCB Isolate'
     */
    1000.0,

    /* Mask Parameter: VCBVent_p_deadband
     * Referenced by: '<S102>/VCB Vent'
     */
    1000.0,

    /* Mask Parameter: ARChargefromMRP_p_deadband
     * Referenced by: '<S65>/AR Charge from MRP'
     */
    1000.0,

    /* Mask Parameter: PCVentEmer_p_deadband
     * Referenced by: '<S77>/PC Vent Emer'
     */
    500.0,

    /* Mask Parameter: ARCharge_p_deadband
     * Referenced by: '<S77>/AR Charge'
     */
    1000.0,

    /* Mask Parameter: VCBCharge_p_deadband
     * Referenced by: '<S102>/VCB Charge'
     */
    1000.0,

    /* Mask Parameter: BSRVentDrain_p_deadband_a
     * Referenced by: '<S217>/BSR Vent Drain'
     */
    1000.0,

    /* Mask Parameter: BSRVentIC_p_deadband_e
     * Referenced by: '<S217>/BSR Vent IC'
     */
    1000.0,

    /* Mask Parameter: BSRCharge_p_deadband
     * Referenced by: '<S217>/BSR Charge'
     */
    1000.0,

    /* Mask Parameter: CouplingExtraMRP_p_deadband
     * Referenced by: '<S234>/Dead Zone'
     */
    1000.0,

    /* Mask Parameter: MRVentDrain_p_deadband
     * Referenced by: '<S231>/MR Vent Drain'
     */
    1000.0,

    /* Mask Parameter: MRBlowoff_p_deadband
     * Referenced by: '<S231>/MR Blowoff'
     */
    1000.0,

    /* Mask Parameter: MRPipeTwoWayValve_p_deadband
     * Referenced by: '<S231>/MR Pipe Two Way Valve'
     */
    1000.0,

    /* Mask Parameter: MRPtoDownstreamConnection_p_deadband
     * Referenced by: '<S255>/MRP to Downstream Connection'
     */
    200.0,

    /* Mask Parameter: MRPtoUpstreamConnection_p_deadband
     * Referenced by: '<S255>/MRP to Upstream Connection'
     */
    200.0,

    /* Mask Parameter: BSRCharge_p_deadband_d
     * Referenced by: '<S26>/BSR Charge'
     */
    1000.0,

    /* Mask Parameter: DetectDecrease_vinit
     * Referenced by: '<S76>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectChange_vinit
     * Referenced by: '<S98>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease_vinit_j
     * Referenced by: '<S40>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease14_vinit
     * Referenced by: '<S46>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease1_vinit
     * Referenced by: '<S41>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease2_vinit
     * Referenced by: '<S48>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease3_vinit
     * Referenced by: '<S49>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease4_vinit
     * Referenced by: '<S50>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease5_vinit
     * Referenced by: '<S51>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease6_vinit
     * Referenced by: '<S52>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease7_vinit
     * Referenced by: '<S53>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease8_vinit
     * Referenced by: '<S54>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease9_vinit
     * Referenced by: '<S55>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease10_vinit
     * Referenced by: '<S42>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease11_vinit
     * Referenced by: '<S43>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease12_vinit
     * Referenced by: '<S44>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease13_vinit
     * Referenced by: '<S45>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease15_vinit
     * Referenced by: '<S47>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease_vinit_c
     * Referenced by: '<S36>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: SRFlipFlop_initial_condition
     * Referenced by: '<S99>/Memory'
     */
    0,

    /* Mask Parameter: DetectIncrease_vinit
     * Referenced by: '<S235>/Delay Input1'
     */
    0,

    /* Computed Parameter: PenumaticsVehicleOut_Y0
     * Referenced by: '<S9>/PenumaticsVehicleOut'
     */
    {
      {
        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        ,                              /* BrakeCylinderPressures */

        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        /* ParkBrakePressures */
      },                               /* AxleBrakes */

      {
        0.0,                           /* HornLow */
        0.0,                           /* HornHigh */
        0.0,                           /* PneumaticPressureRelease */
        false                          /* EmergencyBrakeActive */
      },                               /* Audio */

      {
        0.0,                           /* BrakeReservoirPressure */
        0.0,                           /* MainReservoirPressure */
        0.0,                           /* MainReservoirPipePressure */
        0.0,                           /* AuxiliaryReservoirPressure */
        0.0,                           /* PantographCylinderPressure */
        0.0,                           /* VCBCylinderPressure */

        {
          {
            0.0,                       /* BrakeCylinderControlPressure */

            {
              0.0, 0.0 }
            ,                          /* BrakeCylinderPressure */
            0.0,                       /* ParkBrakePressure */
            0.0,                       /* SandingSystemPressure */
            0.0,                       /* AirSuspensionPressure */
            0.0                        /* AirSuspPressureDiff */
          }, {
            0.0,                       /* BrakeCylinderControlPressure */

            {
              0.0, 0.0 }
            ,                          /* BrakeCylinderPressure */
            0.0,                       /* ParkBrakePressure */
            0.0,                       /* SandingSystemPressure */
            0.0,                       /* AirSuspensionPressure */
            0.0                        /* AirSuspPressureDiff */
          } }
        /* Bogie */
      },                               /* Debug */

      {
        0.0,                           /* MainReservoirPressureGauge */
        0.0,                           /* SRPressureGauge */

        {
          {
            0.0,                       /* BrakeCylinderPressureGauge */
            0.0                        /* ParkBrakePressureGauge */
          }, {
            0.0,                       /* BrakeCylinderPressureGauge */
            0.0                        /* ParkBrakePressureGauge */
          } }
        /* Bogie */
      },                               /* PressureGauges */

      {
        0.0,                           /* BrakeReservoirPressureSwitch */
        0.0,                           /* HornHighPressureSwitch */
        0.0,                           /* HornLowPressureSwitch */
        0.0,                           /* MainReservoirPressureSwitch */
        0.0,                           /* AuxiliaryReservoirPressureSwitch */
        0.0,                           /* MainReservoirPipePressureSwitch */
        0.0,                           /* MRPS_TractionCutout */
        0.0,                           /* PS3 */
        0.0,                           /* PS2 */
        0.0,                           /* VCBPressureSwitch */

        {
          {
            0.0,                       /* BrakeCylinderPressureSwitch */
            0.0,                       /* ParkBrakePressureSwitch */
            0.0,                       /* AirSuspensionPressureSwitch */
            0.0                        /* SandingSystemPressureSwitch */
          }, {
            0.0,                       /* BrakeCylinderPressureSwitch */
            0.0,                       /* ParkBrakePressureSwitch */
            0.0,                       /* AirSuspensionPressureSwitch */
            0.0                        /* SandingSystemPressureSwitch */
          } }
        /* Bogie */
      },                               /* PressureSwitches */

      {
        {
          {
            0.0,                       /* BrakeCylinderControlPressure */
            0.0,                       /* BrakeCylinderControlVolumePressure */
            0.0,                       /* BrakeReservoirPressure */
            0.0                        /* AirSuspensionLoadPressure */
          }, {
            0.0,                       /* BrakeCylinderControlPressure */
            0.0,                       /* BrakeCylinderControlVolumePressure */
            0.0,                       /* BrakeReservoirPressure */
            0.0                        /* AirSuspensionLoadPressure */
          } }
        /* Bogie */
      },                               /* PressureTransducers */

      {
        {
          {
            false,                     /* BECU1EmergencyBrakeFailure */
            false,                     /* BECU2EmergencyBrakeFailure */
            false,                     /* BECU1ServiceBrakeFailure */
            false,                     /* BECU1BrakeNotApplied */
            false,                     /* BECU1BrakeNotReleased */
            false,                     /* BECU1CarLoadPressureLow */
            false,                     /* BECU2CarLoadPressureLow */
            false,                     /* BECULowRPressure */
            false,                     /* AirSuspensionBogie1Deflated */
            false                      /* BECU1LoadPressureLow */
          }, {
            false,                     /* BECU1EmergencyBrakeFailure */
            false,                     /* BECU2EmergencyBrakeFailure */
            false,                     /* BECU1ServiceBrakeFailure */
            false,                     /* BECU1BrakeNotApplied */
            false,                     /* BECU1BrakeNotReleased */
            false,                     /* BECU1CarLoadPressureLow */
            false,                     /* BECU2CarLoadPressureLow */
            false,                     /* BECULowRPressure */
            false,                     /* AirSuspensionBogie1Deflated */
            false                      /* BECU1LoadPressureLow */
          } }
        /* Bogie */
      }                                /* TCMS */
    },

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S19>/Constant'
     */
    {
      0.0,                             /* BrakeReservoirPressure */
      0.0,                             /* MainReservoirPressure */
      0.0,                             /* MainReservoirPipePressure */
      0.0,                             /* AuxiliaryReservoirPressure */
      0.0,                             /* PantographCylinderPressure */
      0.0,                             /* VCBCylinderPressure */

      {
        {
          0.0,                         /* BrakeCylinderControlPressure */

          {
            0.0, 0.0 }
          ,                            /* BrakeCylinderPressure */
          0.0,                         /* ParkBrakePressure */
          0.0,                         /* SandingSystemPressure */
          0.0,                         /* AirSuspensionPressure */
          0.0                          /* AirSuspPressureDiff */
        }, {
          0.0,                         /* BrakeCylinderControlPressure */

          {
            0.0, 0.0 }
          ,                            /* BrakeCylinderPressure */
          0.0,                         /* ParkBrakePressure */
          0.0,                         /* SandingSystemPressure */
          0.0,                         /* AirSuspensionPressure */
          0.0                          /* AirSuspPressureDiff */
        } }
      /* Bogie */
    },

    /* Computed Parameter: Constant_Value_n
     * Referenced by: '<S21>/Constant'
     */
    {
      0.0,                             /* BrakeReservoirPressureSwitch */
      0.0,                             /* HornHighPressureSwitch */
      0.0,                             /* HornLowPressureSwitch */
      0.0,                             /* MainReservoirPressureSwitch */
      0.0,                             /* AuxiliaryReservoirPressureSwitch */
      0.0,                             /* MainReservoirPipePressureSwitch */
      0.0,                             /* MRPS_TractionCutout */
      0.0,                             /* PS3 */
      0.0,                             /* PS2 */
      0.0,                             /* VCBPressureSwitch */

      {
        {
          0.0,                         /* BrakeCylinderPressureSwitch */
          0.0,                         /* ParkBrakePressureSwitch */
          0.0,                         /* AirSuspensionPressureSwitch */
          0.0                          /* SandingSystemPressureSwitch */
        }, {
          0.0,                         /* BrakeCylinderPressureSwitch */
          0.0,                         /* ParkBrakePressureSwitch */
          0.0,                         /* AirSuspensionPressureSwitch */
          0.0                          /* SandingSystemPressureSwitch */
        } }
      /* Bogie */
    },

    /* Computed Parameter: Constant_Value_p
     * Referenced by: '<S16>/Constant'
     */
    {
      0.0,                             /* MainReservoirPressureGauge */
      0.0,                             /* SRPressureGauge */

      {
        {
          0.0,                         /* BrakeCylinderPressureGauge */
          0.0                          /* ParkBrakePressureGauge */
        }, {
          0.0,                         /* BrakeCylinderPressureGauge */
          0.0                          /* ParkBrakePressureGauge */
        } }
      /* Bogie */
    },

    /* Computed Parameter: BCUPressureTransducers_Y0
     * Referenced by: '<S121>/BCUPressureTransducers'
     */
    {
      0.0,                             /* BrakeCylinderControlPressure */
      0.0,                             /* BrakeCylinderControlVolumePressure */
      0.0,                             /* BrakeReservoirPressure */
      0.0                              /* AirSuspensionLoadPressure */
    },

    /* Computed Parameter: PressureSwitches_Y0
     * Referenced by: '<S58>/PressureSwitches'
     */
    {
      0.0,                             /* AuxiliaryReservoirPressureSwitch */
      0.0,                             /* PS3 */
      0.0,                             /* VCBPressureSwitch */
      0.0                              /* ORDPressureSwitch */
    },

    /* Computed Parameter: PantoSystemPressures_Y0
     * Referenced by: '<S58>/PantoSystemPressures'
     */
    {
      0.0,                             /* AuxiliaryReservoirPressure */
      0.0,                             /* PantographCylinderPressure */
      0.0                              /* VCBCylinderPressure */
    },

    /* Computed Parameter: BrakeSystemGauges_Y0
     * Referenced by: '<S121>/BrakeSystemGauges'
     */
    {
      0.0,                             /* BrakeCylinderPressureGauge */
      0.0                              /* ParkBrakePressureGauge */
    },

    /* Computed Parameter: FaultMessages_Y0
     * Referenced by: '<S121>/FaultMessages'
     */
    {
      false,                           /* BECU1EmergencyBrakeFailure */
      false,                           /* BECU2EmergencyBrakeFailure */
      false,                           /* BECU1ServiceBrakeFailure */
      false,                           /* BECU1BrakeNotApplied */
      false,                           /* BECU1BrakeNotReleased */
      false,                           /* BECU1CarLoadPressureLow */
      false,                           /* BECU2CarLoadPressureLow */
      false,                           /* BECULowRPressure */
      false,                           /* AirSuspensionBogie1Deflated */
      false                            /* BECU1LoadPressureLow */
    },

    /* Computed Parameter: AudioOut_Y0
     * Referenced by: '<S59>/AudioOut'
     */
    {
      0.0,                             /* HornLow */
      0.0                              /* HornHigh */
    },

    /* Computed Parameter: PressureSwitches_Y0_d
     * Referenced by: '<S59>/PressureSwitches'
     */
    {
      0.0,                             /* HornLowPressureSwitch */
      0.0                              /* HornHighPressureSwitch */
    },

    /* Expression: 0
     * Referenced by: '<S10>/Constant'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt
     * Referenced by: '<S27>/Weighted Sample Time'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S66>/ExternalIC'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S65>/Switch1'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt_o
     * Referenced by: '<S67>/Weighted Sample Time'
     */
    0.01,

    /* Computed Parameter: WeightedSampleTime_WtEt_i
     * Referenced by: '<S85>/Weighted Sample Time'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S96>/ExternalIC'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S97>/ExternalIC'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt_c
     * Referenced by: '<S100>/Weighted Sample Time'
     */
    0.01,

    /* Computed Parameter: WeightedSampleTime_WtEt_p
     * Referenced by: '<S111>/Weighted Sample Time'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S113>/ExternalIC'
     */
    0.0,

    /* Computed Parameter: MRPToAuxR_Y0
     * Referenced by: '<S58>/MRPToAuxR'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S58>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S58>/Unit Delay1'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S63>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S66>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S66>/Initialise'
     */
    1.0,

    /* Expression: inf
     * Referenced by: '<S64>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S64>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S60>/Unit Delay'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S65>/Overpressure'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S65>/Overpressure'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S67>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S63>/Initialise'
     */
    0.0,

    /* Expression: inf
     * Referenced by: '<S84>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S84>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S61>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S61>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S85>/Unit Delay1'
     */
    0.0,

    /* Expression: inf
     * Referenced by: '<S82>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S82>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S100>/Unit Delay1'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S79>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S96>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S96>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S79>/Initialise'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S80>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S97>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S97>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S80>/Initialise'
     */
    0.0,

    /* Expression: inf
     * Referenced by: '<S103>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S103>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S62>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S111>/Unit Delay1'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S104>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S113>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S113>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S104>/Initialise'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S59>/Gain'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S59>/Gain1'
     */
    1.0,

    /* Computed Parameter: AirSuspensionPressure_Y0
     * Referenced by: '<S118>/AirSuspensionPressure'
     */
    0.0,

    /* Computed Parameter: ASPressureSwitches_Y0
     * Referenced by: '<S118>/ASPressureSwitches'
     */
    0.0,

    /* Computed Parameter: AirSuspPressureVariation_Y0
     * Referenced by: '<S118>/AirSuspPressure%Variation'
     */
    0.0,

    /* Computed Parameter: ASRToAS_Y0
     * Referenced by: '<S118>/ASRToAS'
     */
    0.0,

    /* Computed Parameter: BSRtoVehicleBCFlow_Y0
     * Referenced by: '<S121>/BSRtoVehicleBCFlow'
     */
    0.0,

    /* Computed Parameter: BrakeControlPressures_Y0
     * Referenced by: '<S121>/BrakeControlPressures'
     */
    0.0,

    /* Computed Parameter: BrakeCylinderPressures_Y0
     * Referenced by: '<S121>/BrakeCylinderPressures'
     */
    0.0,

    /* Computed Parameter: ParkBrakePressures_Y0
     * Referenced by: '<S121>/ParkBrakePressures'
     */
    0.0,

    /* Computed Parameter: BrakeCylinderPressureSwitches_Y0
     * Referenced by: '<S121>/BrakeCylinderPressureSwitches'
     */
    0.0,

    /* Computed Parameter: ParkBrakePressureSwitches_Y0
     * Referenced by: '<S121>/ParkBrakePressureSwitches'
     */
    0.0,

    /* Computed Parameter: SandingPressures_Y0
     * Referenced by: '<S122>/SandingPressures'
     */
    0.0,

    /* Computed Parameter: SandingPressureSwitches_Y0
     * Referenced by: '<S122>/SandingPressureSwitches'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S218>/ExternalIC'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt_e
     * Referenced by: '<S219>/Weighted Sample Time'
     */
    0.01,

    /* Computed Parameter: BSRPressure_Y0
     * Referenced by: '<S214>/BSRPressure'
     */
    0.0,

    /* Computed Parameter: BSRPressureSwitch_Y0
     * Referenced by: '<S214>/BSRPressureSwitch'
     */
    0.0,

    /* Computed Parameter: MRPToBSR_Y0
     * Referenced by: '<S214>/MRPToBSR'
     */
    0.0,

    /* Computed Parameter: BSRPressureGauge_Y0
     * Referenced by: '<S214>/BSRPressureGauge'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S215>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S218>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S218>/Initialise'
     */
    1.0,

    /* Expression: inf
     * Referenced by: '<S216>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S216>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S214>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S219>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S215>/Initialise'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S250>/ExternalIC'
     */
    0.0,

    /* Expression: 1.89
     * Referenced by: '<S234>/PuPd'
     */
    1.89,

    /* Expression: pi*(d/2)^2
     * Referenced by: '<S234>/piRsqrd'
     */
    7.8539816339744827E-5,

    /* Expression: 0.0
     * Referenced by: '<S234>/Zero'
     */
    0.0,

    /* Expression: 500000
     * Referenced by: '<S231>/Constant1'
     */
    500000.0,

    /* Expression: 2.13e-5
     * Referenced by: '<S234>/C1'
     */
    2.13E-5,

    /* Expression: 0.75
     * Referenced by: '<S234>/Cd'
     */
    0.75,

    /* Expression: 0.0
     * Referenced by: '<S234>/Zero1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S231>/Switch1'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt_j
     * Referenced by: '<S251>/Weighted Sample Time'
     */
    0.01,

    /* Computed Parameter: MRPressure_Y0
     * Referenced by: '<S229>/MRPressure'
     */
    0.0,

    /* Computed Parameter: MRPressureSwitch_Y0
     * Referenced by: '<S229>/MRPressureSwitch'
     */
    0.0,

    /* Computed Parameter: MRPToMRFlow_Y0
     * Referenced by: '<S229>/MRPToMRFlow'
     */
    0.0,

    /* Expression: inf
     * Referenced by: '<S233>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S233>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S229>/Unit Delay'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S231>/Overpressure'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S231>/Overpressure'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S251>/Unit Delay1'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S232>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S250>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S250>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S232>/Initialise'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S257>/ExternalIC'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S258>/ExternalIC'
     */
    0.0,

    /* Computed Parameter: WeightedSampleTime_WtEt_p0
     * Referenced by: '<S273>/Weighted Sample Time'
     */
    0.01,

    /* Expression: inf
     * Referenced by: '<S25>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S25>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 75*0.001
     * Referenced by: '<S230>/MR Volume'
     */
    0.075,

    /* Expression: inf
     * Referenced by: '<S256>/Saturation'
     */
    0.0,

    /* Expression: eps
     * Referenced by: '<S256>/Saturation'
     */
    2.2204460492503131E-16,

    /* Expression: 0
     * Referenced by: '<S230>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S17>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S273>/Unit Delay1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S24>/Unit Delay'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay5'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S27>/Unit Delay1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S11>/Brake Supply Reservoir Pressure available'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S37>/Aux Reservoir Pressure available'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S37>/Brake Supply Reservoir Pressure available'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S37>/Main Reservoir Pressure available'
     */
    1.0,

    /* Expression: zeros(1,MaxAxles)
     * Referenced by: '<S13>/Constant'
     */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    /* Expression: 0
     * Referenced by: '<S9>/Unit Delay4'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S20>/Add Constant'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S20>/Switch'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S253>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S257>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S257>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S253>/Initialise'
     */
    0.0,

    /* Expression: InitOn
     * Referenced by: '<S254>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S258>/OnlyIC'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S258>/Initialise'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S254>/Initialise'
     */
    0.0,

    /* Computed Parameter: IC_Value
     * Referenced by: '<S67>/IC'
     */
    1,

    /* Expression: false
     * Referenced by: '<S75>/Constant2'
     */
    0,

    /* Computed Parameter: IC_Value_l
     * Referenced by: '<S85>/IC'
     */
    1,

    /* Computed Parameter: Logic_table
     * Referenced by: '<S99>/Logic'
     */
    { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

    /* Computed Parameter: UnitDelay1_InitialCondition_nm
     * Referenced by: '<S83>/Unit Delay1'
     */
    0,

    /* Computed Parameter: IC_Value_g
     * Referenced by: '<S100>/IC'
     */
    1,

    /* Expression: true
     * Referenced by: '<S83>/Constant1'
     */
    1,

    /* Computed Parameter: IC_Value_li
     * Referenced by: '<S111>/IC'
     */
    1,

    /* Computed Parameter: IC_Value_b
     * Referenced by: '<S219>/IC'
     */
    1,

    /* Computed Parameter: IC_Value_i
     * Referenced by: '<S251>/IC'
     */
    1,

    /* Computed Parameter: IC_Value_k
     * Referenced by: '<S27>/IC'
     */
    1,

    /* Computed Parameter: IC_Value_c
     * Referenced by: '<S273>/IC'
     */
    1,

    /* Start of '<S255>/MRP to Downstream Connection' */
    {
      /* Start of '<S237>/Reverse' */
      {
        /* Expression: 1.89
         * Referenced by: '<S264>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S264>/piRsqrd'
         */
        0.00017087318792415732,

        /* Expression: 0.0
         * Referenced by: '<S264>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S264>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S264>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S264>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S237>/Reverse' */

      /* Start of '<S237>/Forward' */
      {
        /* Expression: 1.89
         * Referenced by: '<S263>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S263>/piRsqrd'
         */
        0.00017087318792415732,

        /* Expression: 0.0
         * Referenced by: '<S263>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S263>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S263>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S263>/Zero1'
         */
        0.0
      }
      /* End of '<S237>/Forward' */
    }
    ,

    /* End of '<S255>/MRP to Downstream Connection' */

    /* Start of '<S255>/MRP to Upstream Connection' */
    {
      /* Start of '<S237>/Reverse' */
      {
        /* Expression: 1.89
         * Referenced by: '<S270>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S270>/piRsqrd'
         */
        0.00017087318792415732,

        /* Expression: 0.0
         * Referenced by: '<S270>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S270>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S270>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S270>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S237>/Reverse' */

      /* Start of '<S237>/Forward' */
      {
        /* Expression: 1.89
         * Referenced by: '<S269>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S269>/piRsqrd'
         */
        0.00017087318792415732,

        /* Expression: 0.0
         * Referenced by: '<S269>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S269>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S269>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S269>/Zero1'
         */
        0.0
      }
      /* End of '<S237>/Forward' */
    }
    ,

    /* End of '<S255>/MRP to Upstream Connection' */

    /* Start of '<S231>/MR Vent Drain' */
    {
      /* Expression: 1.89
       * Referenced by: '<S238>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S238>/piRsqrd'
       */
      7.8539816339744827E-5,

      /* Expression: 0.0
       * Referenced by: '<S238>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S238>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S238>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S238>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S231>/MR Vent Drain' */

    /* Start of '<S231>/MR Blowoff' */
    {
      /* Expression: 1.89
       * Referenced by: '<S236>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S236>/piRsqrd'
       */
      7.8539816339744827E-5,

      /* Expression: 0.0
       * Referenced by: '<S236>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S236>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S236>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S236>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S231>/MR Blowoff' */

    /* Start of '<S231>/TimerOffDelay NoInit' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S239>/OffTime'
       */
      12.0,

      /* Expression: 0
       * Referenced by: '<S249>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S239>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S239>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S239>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S239>/Discrete-Time Integrator'
       */
      0.01,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S239>/Discrete-Time Integrator'
       */
      12.0,

      /* Expression: 0
       * Referenced by: '<S239>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S231>/TimerOffDelay NoInit' */

    /* Start of '<S231>/MR Pipe Two Way Valve' */
    {
      /* Start of '<S237>/Reverse' */
      {
        /* Expression: 1.89
         * Referenced by: '<S245>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S245>/piRsqrd'
         */
        7.8539816339744827E-5,

        /* Expression: 0.0
         * Referenced by: '<S245>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S245>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S245>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S245>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S237>/Reverse' */

      /* Start of '<S237>/Forward' */
      {
        /* Expression: 1.89
         * Referenced by: '<S244>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S244>/piRsqrd'
         */
        7.8539816339744827E-5,

        /* Expression: 0.0
         * Referenced by: '<S244>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S244>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S244>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S244>/Zero1'
         */
        0.0
      }
      /* End of '<S237>/Forward' */
    }
    ,

    /* End of '<S231>/MR Pipe Two Way Valve' */

    /* Start of '<S228>/CoreSubsys' */
    {
      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S228>/Constant1'
       */
      {
        0.0,                           /* BrakeCylinderPressureGauge */
        0.0                            /* ParkBrakePressureGauge */
      }
    }
    ,

    /* End of '<S228>/CoreSubsys' */

    /* Start of '<S217>/BSR Charge' */
    {
      /* Expression: 1.89
       * Referenced by: '<S221>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S221>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S221>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S221>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S221>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S221>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S217>/BSR Charge' */

    /* Start of '<S217>/BSR Vent Drain' */
    {
      /* Expression: 1.89
       * Referenced by: '<S222>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S222>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S222>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S222>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S222>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S222>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S217>/BSR Vent Drain' */

    /* Start of '<S217>/BSR Vent IC' */
    {
      /* Expression: 1.89
       * Referenced by: '<S223>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S223>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S223>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S223>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S223>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S223>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S217>/BSR Vent IC' */

    /* Start of '<S211>/CoreSubsys' */
    {
      /* Mask Parameter: SandingPressureSwitch10_OffOutputValue
       * Referenced by: '<S212>/PressureSwitch'
       */
      0.0,

      /* Mask Parameter: SandingPressureSwitch10_OnOutputValue
       * Referenced by: '<S212>/PressureSwitch'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S213>/ExternalIC'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S213>/OnlyIC'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S213>/Initialise'
       */
      1.0,

      /* Expression: InitOn
       * Referenced by: '<S212>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S212>/Initialise'
       */
      0.0
    }
    ,

    /* End of '<S211>/CoreSubsys' */

    /* Start of '<S148>/CoreSubsys' */
    {
      /* Mask Parameter: B2728B07_OffOutputValue
       * Referenced by: '<S185>/PressureSwitch'
       */
      0.0,

      /* Mask Parameter: B27B14_OffOutputValue
       * Referenced by: '<S207>/PressureSwitch'
       */
      1.0,

      /* Mask Parameter: B2728B07_OnOutputValue
       * Referenced by: '<S185>/PressureSwitch'
       */
      1.0,

      /* Mask Parameter: B27B14_OnOutputValue
       * Referenced by: '<S207>/PressureSwitch'
       */
      0.0,

      /* Mask Parameter: BrakeCylinderPressureCalc_bcArea
       * Referenced by: '<S154>/Constant1'
       */
      0.024,

      /* Mask Parameter: BrakeCylinderPressureCalc_bcPreload
       * Referenced by: '<S154>/Constant5'
       */
      5000.0,

      /* Mask Parameter: BrakeCylinderPressureCalc_brkBeamFactor
       * Referenced by: '<S154>/Constant2'
       */
      1.0,

      /* Mask Parameter: BrakeCylinderPressureCalc_brkEfficiency
       * Referenced by: '<S154>/Constant3'
       */
      95.0,

      /* Mask Parameter: CompareToConstant2_const
       * Referenced by: '<S155>/Constant'
       */
      70.0,

      /* Mask Parameter: CompareToConstant3_const
       * Referenced by: '<S159>/Constant'
       */
      280000.0,

      /* Mask Parameter: CompareToConstant5_const
       * Referenced by: '<S161>/Constant'
       */
      4500.0,

      /* Mask Parameter: CompareToConstant4_const
       * Referenced by: '<S160>/Constant'
       */
      0.0,

      /* Mask Parameter: CompareToConstant1_const
       * Referenced by: '<S158>/Constant'
       */
      180000.0,

      /* Mask Parameter: CompareToConstant7_const
       * Referenced by: '<S162>/Constant'
       */
      880000.0,

      /* Mask Parameter: BrakeCylinderPressureCalc_noBrakeCyl
       * Referenced by: '<S154>/Constant'
       */
      4.0,

      /* Mask Parameter: DetectDecrease_vinit
       * Referenced by: '<S163>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease1_vinit
       * Referenced by: '<S164>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease2_vinit
       * Referenced by: '<S165>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease3_vinit
       * Referenced by: '<S166>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease6_vinit
       * Referenced by: '<S169>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: SRLatchResetPriority1_initial_condition
       * Referenced by: '<S175>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority2_initial_condition
       * Referenced by: '<S176>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority3_initial_condition
       * Referenced by: '<S177>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority4_initial_condition
       * Referenced by: '<S178>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority5_initial_condition
       * Referenced by: '<S179>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority6_initial_condition
       * Referenced by: '<S180>/Memory'
       */
      0,

      /* Mask Parameter: MagnetValve_B20_initial_condition
       * Referenced by: '<S209>/Memory'
       */
      0,

      /* Mask Parameter: DetectDecrease5_vinit
       * Referenced by: '<S168>/Delay Input1'
       */
      0,

      /* Mask Parameter: DetectDecrease4_vinit
       * Referenced by: '<S167>/Delay Input1'
       */
      0,

      /* Computed Parameter: Constant_Value
       * Referenced by: '<S153>/Constant'
       */
      {
        false,                         /* BECU1EmergencyBrakeFailure */
        false,                         /* BECU2EmergencyBrakeFailure */
        false,                         /* BECU1ServiceBrakeFailure */
        false,                         /* BECU1BrakeNotApplied */
        false,                         /* BECU1BrakeNotReleased */
        false,                         /* BECU1CarLoadPressureLow */
        false,                         /* BECU2CarLoadPressureLow */
        false,                         /* BECULowRPressure */
        false,                         /* AirSuspensionBogie1Deflated */
        false                          /* BECU1LoadPressureLow */
      },

      /* Expression: 0
       * Referenced by: '<S152>/Switch3'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S210>/ExternalIC'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S190>/ExternalIC'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S149>/Constant2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S149>/Constant1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S170>/Constant3'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S170>/Out2'
       */
      0.0,

      /* Expression: 1e6
       * Referenced by: '<S170>/Constant4'
       */
      1.0E+6,

      /* Computed Parameter: sampletime_WtEt
       * Referenced by: '<S181>/sample time'
       */
      0.01,

      /* Expression: 0
       * Referenced by: '<S181>/Delay Input2'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S171>/Gain'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S186>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S190>/OnlyIC'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S190>/Initialise'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S157>/Proportion'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S157>/Proportion'
       */
      0.0,

      /* Expression: 100
       * Referenced by: '<S154>/Constant4'
       */
      100.0,

      /* Computed Parameter: WeightedSampleTime_WtEt
       * Referenced by: '<S156>/Weighted Sample Time'
       */
      0.01,

      /* Expression: FilterSpecificationValue
       * Referenced by: '<S156>/FilterSpecification'
       */
      0.1,

      /* Expression: inf
       * Referenced by: '<S156>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S156>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S156>/Constant1'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S156>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S156>/Discrete Transfer Fcn'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S149>/Switch2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S149>/Switch1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S149>/Regulating Valve 02'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S188>/Saturation'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S188>/Saturation'
       */
      1.0,

      /* Computed Parameter: WeightedSampleTime_WtEt_j
       * Referenced by: '<S187>/Weighted Sample Time'
       */
      0.01,

      /* Expression: FilterSpecificationValue
       * Referenced by: '<S187>/FilterSpecification'
       */
      0.01,

      /* Expression: inf
       * Referenced by: '<S187>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S187>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S187>/Constant1'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S187>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S187>/Discrete Transfer Fcn'
       */
      0.0,

      /* Expression: InitOn
       * Referenced by: '<S185>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S185>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S153>/Constant3'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S153>/Constant1'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S153>/Constant2'
       */
      1.0,

      /* Computed Parameter: WeightedSampleTime_WtEt_b
       * Referenced by: '<S208>/Weighted Sample Time'
       */
      0.01,

      /* Expression: FilterSpecificationValue
       * Referenced by: '<S208>/FilterSpecification'
       */
      0.01,

      /* Expression: inf
       * Referenced by: '<S208>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S208>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S208>/Constant1'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S208>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S208>/Discrete Transfer Fcn'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S210>/OnlyIC'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S210>/Initialise'
       */
      1.0,

      /* Expression: InitOn
       * Referenced by: '<S207>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S207>/Initialise'
       */
      0.0,

      /* Computed Parameter: Switch1_Threshold_o
       * Referenced by: '<S150>/Switch1'
       */
      0U,

      /* Start of '<S153>/If Action Subsystem6' */
      {
        /* Expression: 0
         * Referenced by: '<S174>/Out1'
         */
        0.0
      }
      ,

      /* End of '<S153>/If Action Subsystem6' */

      /* Start of '<S153>/If Action Subsystem4' */
      {
        /* Expression: 0
         * Referenced by: '<S172>/Out1'
         */
        0.0
      }
      ,

      /* End of '<S153>/If Action Subsystem4' */

      /* Start of '<S153>/If Action Subsystem5' */
      {
        /* Expression: 0
         * Referenced by: '<S173>/Out1'
         */
        0.0
      }
      ,

      /* End of '<S153>/If Action Subsystem5' */

      /* Start of '<S151>/CoreSubsys' */
      {
        /* Mask Parameter: ChargeChoke_DiffGain
         * Referenced by: '<S201>/Constant'
         */
        0.0001,

        /* Mask Parameter: ReleaseChoke_DiffGain
         * Referenced by: '<S203>/Constant'
         */
        0.0002,

        /* Mask Parameter: ChargeChoke_FullDiam
         * Referenced by: '<S201>/Constant1'
         */
        0.0032,

        /* Mask Parameter: ReleaseChoke_FullDiam
         * Referenced by: '<S203>/Constant1'
         */
        0.008,

        /* Mask Parameter: CompareToConstant_const
         * Referenced by: '<S202>/Constant'
         */
        1000.0,

        /* Mask Parameter: BCIsolate_p_deadband
         * Referenced by: '<S195>/BC Isolate'
         */
        1000.0,

        /* Mask Parameter: BCVent_p_deadband
         * Referenced by: '<S195>/BC Vent'
         */
        500.0,

        /* Mask Parameter: BCCharge_p_deadband
         * Referenced by: '<S195>/BC Charge'
         */
        1000.0,

        /* Computed Parameter: WeightedSampleTime_WtEt
         * Referenced by: '<S196>/Weighted Sample Time'
         */
        0.01,

        /* Computed Parameter: BCPressure_Y0
         * Referenced by: '<S192>/BCPressure'
         */
        0.0,

        /* Computed Parameter: BSRtoBCFlow_Y0
         * Referenced by: '<S192>/BSRtoBCFlow'
         */
        0.0,

        /* Expression: inf
         * Referenced by: '<S194>/Saturation'
         */
        0.0,

        /* Expression: eps
         * Referenced by: '<S194>/Saturation'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S192>/Unit Delay'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S196>/Unit Delay1'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S193>/Constant'
         */
        0.0,

        /* Computed Parameter: UnitDelay1_InitialCondition_o
         * Referenced by: '<S192>/Unit Delay1'
         */
        0,

        /* Computed Parameter: IC_Value
         * Referenced by: '<S196>/IC'
         */
        1,

        /* Expression: true
         * Referenced by: '<S192>/Constant1'
         */
        1,

        /* Start of '<S195>/BC Charge' */
        {
          /* Expression: 1.89
           * Referenced by: '<S198>/PuPd'
           */
          1.89,

          /* Expression: 1.0
           * Referenced by: '<S201>/Saturation'
           */
          1.0,

          /* Expression: 0
           * Referenced by: '<S201>/Saturation'
           */
          0.0,

          /* Expression: 0.5
           * Referenced by: '<S198>/Gain'
           */
          0.5,

          /* Expression: pi
           * Referenced by: '<S198>/Gain1'
           */
          3.1415926535897931,

          /* Expression: 0.0
           * Referenced by: '<S198>/Zero'
           */
          0.0,

          /* Expression: 2.13e-5
           * Referenced by: '<S198>/C1'
           */
          2.13E-5,

          /* Expression: 0.75
           * Referenced by: '<S198>/Cd'
           */
          0.75,

          /* Expression: 0.0
           * Referenced by: '<S198>/Zero1'
           */
          0.0
        }
        ,

        /* End of '<S195>/BC Charge' */

        /* Start of '<S195>/BC Isolate' */
        {
          /* Expression: 1.89
           * Referenced by: '<S199>/PuPd'
           */
          1.89,

          /* Expression: pi*(d/2)^2
           * Referenced by: '<S199>/piRsqrd'
           */
          0.00017671458676442585,

          /* Expression: 0.0
           * Referenced by: '<S199>/Zero'
           */
          0.0,

          /* Expression: 2.13e-5
           * Referenced by: '<S199>/C1'
           */
          2.13E-5,

          /* Expression: 0.75
           * Referenced by: '<S199>/Cd'
           */
          0.75,

          /* Expression: 0.0
           * Referenced by: '<S199>/Zero1'
           */
          0.0
        }
        ,

        /* End of '<S195>/BC Isolate' */

        /* Start of '<S195>/BC Vent' */
        {
          /* Expression: 1.89
           * Referenced by: '<S200>/PuPd'
           */
          1.89,

          /* Expression: 1.0
           * Referenced by: '<S203>/Saturation'
           */
          1.0,

          /* Expression: 0
           * Referenced by: '<S203>/Saturation'
           */
          0.0,

          /* Expression: 0.5
           * Referenced by: '<S200>/Gain'
           */
          0.5,

          /* Expression: pi
           * Referenced by: '<S200>/Gain1'
           */
          3.1415926535897931,

          /* Expression: 0.0
           * Referenced by: '<S200>/Zero'
           */
          0.0,

          /* Expression: 2.13e-5
           * Referenced by: '<S200>/C1'
           */
          2.13E-5,

          /* Expression: 0.75
           * Referenced by: '<S200>/Cd'
           */
          0.75,

          /* Expression: 0.0
           * Referenced by: '<S200>/Zero1'
           */
          0.0
        }
        /* End of '<S195>/BC Vent' */
      }
      /* End of '<S151>/CoreSubsys' */
    }
    ,

    /* End of '<S148>/CoreSubsys' */

    /* Start of '<S120>/CoreSubsys' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S120>/Constant'
       */
      {
        0.0,                           /* BrakeCylinderPressureSwitch */
        0.0,                           /* ParkBrakePressureSwitch */
        0.0,                           /* AirSuspensionPressureSwitch */
        0.0                            /* SandingSystemPressureSwitch */
      }
    }
    ,

    /* End of '<S120>/CoreSubsys' */

    /* Start of '<S119>/CoreSubsys' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S119>/Constant'
       */
      {
        0.0,                           /* BrakeCylinderControlPressure */

        {
          0.0, 0.0 }
        ,                              /* BrakeCylinderPressure */
        0.0,                           /* ParkBrakePressure */
        0.0,                           /* SandingSystemPressure */
        0.0,                           /* AirSuspensionPressure */
        0.0                            /* AirSuspPressureDiff */
      }
    }
    ,

    /* End of '<S119>/CoreSubsys' */

    /* Start of '<S123>/CoreSubsys' */
    {
      /* Mask Parameter: ChargeChoke_DiffGain
       * Referenced by: '<S137>/Constant'
       */
      0.0015,

      /* Mask Parameter: ReleaseChoke_DiffGain
       * Referenced by: '<S140>/Constant'
       */
      0.0015,

      /* Mask Parameter: ChargeChoke_FullDiam
       * Referenced by: '<S137>/Constant1'
       */
      0.005,

      /* Mask Parameter: ReleaseChoke_FullDiam
       * Referenced by: '<S140>/Constant1'
       */
      0.007,

      /* Mask Parameter: B27L1112_OffOutputValue
       * Referenced by: '<S126>/PressureSwitch'
       */
      0.0,

      /* Mask Parameter: B27L1112_OnOutputValue
       * Referenced by: '<S126>/PressureSwitch'
       */
      1.0,

      /* Mask Parameter: CompareToConstant_const
       * Referenced by: '<S129>/Constant'
       */
      2500.0,

      /* Mask Parameter: CompareToConstant1_const
       * Referenced by: '<S139>/Constant'
       */
      1.0,

      /* Mask Parameter: CompareToConstant_const_l
       * Referenced by: '<S138>/Constant'
       */
      -1.0,

      /* Mask Parameter: ASVentDrain_p_deadband
       * Referenced by: '<S127>/AS Vent Drain'
       */
      1000.0,

      /* Mask Parameter: ASVentIC_p_deadband
       * Referenced by: '<S127>/AS Vent IC'
       */
      1000.0,

      /* Mask Parameter: ASVent_p_deadband
       * Referenced by: '<S127>/AS Vent'
       */
      1.0,

      /* Mask Parameter: ASCharge_p_deadband
       * Referenced by: '<S127>/AS Charge'
       */
      1.0,

      /* Expression: 0.7
       * Referenced by: '<S128>/Gain'
       */
      0.7,

      /* Expression: 0.5
       * Referenced by: '<S128>/Gain1'
       */
      0.5,

      /* Expression: 0
       * Referenced by: '<S128>/Switch1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S128>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S132>/ExternalIC'
       */
      0.0,

      /* Computed Parameter: WeightedSampleTime_WtEt
       * Referenced by: '<S130>/Weighted Sample Time'
       */
      0.01,

      /* Expression: 0
       * Referenced by: '<S123>/Unit Delay'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S125>/Saturation'
       */
      0.0,

      /* Expression: eps
       * Referenced by: '<S125>/Saturation'
       */
      2.2204460492503131E-16,

      /* Expression: 0
       * Referenced by: '<S130>/Unit Delay1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S128>/Switch2'
       */
      0.0,

      /* Computed Parameter: WeightedSampleTime_WtEt_b
       * Referenced by: '<S145>/Weighted Sample Time'
       */
      0.01,

      /* Expression: FilterSpecificationValue
       * Referenced by: '<S145>/FilterSpecification'
       */
      0.1,

      /* Expression: inf
       * Referenced by: '<S145>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S145>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S145>/Constant1'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S145>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S145>/Discrete Transfer Fcn'
       */
      0.0,

      /* Expression: 100
       * Referenced by: '<S128>/Gain2'
       */
      100.0,

      /* Expression: 0
       * Referenced by: '<S132>/OnlyIC'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S132>/Initialise'
       */
      1.0,

      /* Expression: InitOn
       * Referenced by: '<S126>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S126>/Initialise'
       */
      0.0,

      /* Computed Parameter: UnitDelay1_InitialCondition_m
       * Referenced by: '<S123>/Unit Delay1'
       */
      0,

      /* Computed Parameter: IC_Value
       * Referenced by: '<S130>/IC'
       */
      1,

      /* Expression: true
       * Referenced by: '<S123>/Constant1'
       */
      1,

      /* Start of '<S127>/AS Vent Drain' */
      {
        /* Expression: 1.89
         * Referenced by: '<S135>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S135>/piRsqrd'
         */
        0.00017671458676442585,

        /* Expression: 0.0
         * Referenced by: '<S135>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S135>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S135>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S135>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S127>/AS Vent Drain' */

      /* Start of '<S127>/AS Vent IC' */
      {
        /* Expression: 1.89
         * Referenced by: '<S136>/PuPd'
         */
        1.89,

        /* Expression: pi*(d/2)^2
         * Referenced by: '<S136>/piRsqrd'
         */
        0.00017671458676442585,

        /* Expression: 0.0
         * Referenced by: '<S136>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S136>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S136>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S136>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S127>/AS Vent IC' */

      /* Start of '<S127>/AS Vent' */
      {
        /* Expression: 1.89
         * Referenced by: '<S134>/PuPd'
         */
        1.89,

        /* Expression: 1.0
         * Referenced by: '<S140>/Saturation'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S140>/Saturation'
         */
        0.0,

        /* Expression: 0.5
         * Referenced by: '<S134>/Gain'
         */
        0.5,

        /* Expression: pi
         * Referenced by: '<S134>/Gain1'
         */
        3.1415926535897931,

        /* Expression: 0.0
         * Referenced by: '<S134>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S134>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S134>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S134>/Zero1'
         */
        0.0
      }
      ,

      /* End of '<S127>/AS Vent' */

      /* Start of '<S127>/AS Charge' */
      {
        /* Expression: 1.89
         * Referenced by: '<S133>/PuPd'
         */
        1.89,

        /* Expression: 1.0
         * Referenced by: '<S137>/Saturation'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S137>/Saturation'
         */
        0.0,

        /* Expression: 0.5
         * Referenced by: '<S133>/Gain'
         */
        0.5,

        /* Expression: pi
         * Referenced by: '<S133>/Gain1'
         */
        3.1415926535897931,

        /* Expression: 0.0
         * Referenced by: '<S133>/Zero'
         */
        0.0,

        /* Expression: 2.13e-5
         * Referenced by: '<S133>/C1'
         */
        2.13E-5,

        /* Expression: 0.75
         * Referenced by: '<S133>/Cd'
         */
        0.75,

        /* Expression: 0.0
         * Referenced by: '<S133>/Zero1'
         */
        0.0
      }
      /* End of '<S127>/AS Charge' */
    }
    ,

    /* End of '<S123>/CoreSubsys' */

    /* Start of '<S102>/VCB Isolate' */
    {
      /* Expression: 1.89
       * Referenced by: '<S106>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S106>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S106>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S106>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S106>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S106>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S102>/VCB Isolate' */

    /* Start of '<S102>/VCB Vent' */
    {
      /* Expression: 1.89
       * Referenced by: '<S107>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S107>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S107>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S107>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S107>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S107>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S102>/VCB Vent' */

    /* Start of '<S102>/VCB Charge' */
    {
      /* Expression: 1.89
       * Referenced by: '<S105>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S105>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S105>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S105>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S105>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S105>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S102>/VCB Charge' */

    /* Start of '<S77>/PC Vent Isol' */
    {
      /* Expression: 1.89
       * Referenced by: '<S90>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S90>/piRsqrd'
       */
      1.2566370614359172E-5,

      /* Expression: 0.0
       * Referenced by: '<S90>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S90>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S90>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S90>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S77>/PC Vent Isol' */

    /* Start of '<S77>/PC Vent Control' */
    {
      /* Expression: 1.89
       * Referenced by: '<S88>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S88>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S88>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S88>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S88>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S88>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S77>/PC Vent Control' */

    /* Start of '<S77>/PC Vent Emer' */
    {
      /* Expression: 1.89
       * Referenced by: '<S89>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S89>/piRsqrd'
       */
      1.2566370614359172E-5,

      /* Expression: 0.0
       * Referenced by: '<S89>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S89>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S89>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S89>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S77>/PC Vent Emer' */

    /* Start of '<S77>/AR Charge' */
    {
      /* Expression: 1.89
       * Referenced by: '<S87>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S87>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S87>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S87>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S87>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S87>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S77>/AR Charge' */

    /* Start of '<S65>/AR Charge from MRP' */
    {
      /* Expression: 1.89
       * Referenced by: '<S70>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S70>/piRsqrd'
       */
      4.9087385212340517E-6,

      /* Expression: 0.0
       * Referenced by: '<S70>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S70>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S70>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S70>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S65>/AR Charge from MRP' */

    /* Start of '<S65>/AR Vent Drain' */
    {
      /* Expression: 1.89
       * Referenced by: '<S71>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S71>/piRsqrd'
       */
      1.9634954084936207E-5,

      /* Expression: 0.0
       * Referenced by: '<S71>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S71>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S71>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S71>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S65>/AR Vent Drain' */

    /* Start of '<S65>/AR Blowoff' */
    {
      /* Expression: 1.89
       * Referenced by: '<S69>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S69>/piRsqrd'
       */
      7.8539816339744823E-7,

      /* Expression: 0.0
       * Referenced by: '<S69>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S69>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S69>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S69>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S65>/AR Blowoff' */

    /* Start of '<S11>/TimerOffDelay NoInit1' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S39>/OffTime'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S57>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S39>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S39>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S39>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S39>/Discrete-Time Integrator'
       */
      0.01,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S39>/Discrete-Time Integrator'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S39>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S11>/TimerOffDelay NoInit1' */

    /* Start of '<S11>/TimerOffDelay NoInit' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S38>/OffTime'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S56>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S38>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S38>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S38>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S38>/Discrete-Time Integrator'
       */
      0.01,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S38>/Discrete-Time Integrator'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S38>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S11>/TimerOffDelay NoInit' */

    /* Start of '<S26>/BSR Charge' */
    {
      /* Expression: 1.89
       * Referenced by: '<S29>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S29>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S29>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S29>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S29>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S29>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S26>/BSR Charge' */

    /* Start of '<S26>/BSR Vent Drain' */
    {
      /* Expression: 1.89
       * Referenced by: '<S30>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S30>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S30>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S30>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S30>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S30>/Zero1'
       */
      0.0
    }
    ,

    /* End of '<S26>/BSR Vent Drain' */

    /* Start of '<S26>/BSR Vent IC' */
    {
      /* Expression: 1.89
       * Referenced by: '<S31>/PuPd'
       */
      1.89,

      /* Expression: pi*(d/2)^2
       * Referenced by: '<S31>/piRsqrd'
       */
      0.00017671458676442585,

      /* Expression: 0.0
       * Referenced by: '<S31>/Zero'
       */
      0.0,

      /* Expression: 2.13e-5
       * Referenced by: '<S31>/C1'
       */
      2.13E-5,

      /* Expression: 0.75
       * Referenced by: '<S31>/Cd'
       */
      0.75,

      /* Expression: 0.0
       * Referenced by: '<S31>/Zero1'
       */
      0.0
    }
    /* End of '<S26>/BSR Vent IC' */
  }
  /* End of '<S3>/CoreSubsys' */
};

/*
 * Start for atomic system:
 *    '<S26>/BSR Vent IC'
 *    '<S77>/PC Vent Control'
 *    '<S77>/PC Vent Isol'
 *    '<S102>/VCB Isolate'
 *    '<S127>/AS Vent IC'
 */
void PneumaticsSystem_BSRVentIC_Start(B_BSRVentIC_PneumaticsSystem_T *localB)
{
  localB->FlowNoflow = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S26>/BSR Vent IC'
 *    '<S77>/PC Vent Control'
 *    '<S77>/PC Vent Isol'
 *    '<S102>/VCB Isolate'
 *    '<S127>/AS Vent IC'
 */
void PneumaticsSystem_BSRVentIC(real_T rtu_P1, real_T rtu_P2, real_T rtu_Isolate,
  B_BSRVentIC_PneumaticsSystem_T *localB, P_BSRVentIC_PneumaticsSystem_T *localP,
  real_T rtp_p_deadband)
{
  real_T rtb_Sqrt_d;
  real_T rtb_P2C_g;

  /* Switch: '<S31>/FlowNoflow' incorporates:
   *  Constant: '<S31>/Cd'
   *  Constant: '<S31>/PuPd'
   *  Constant: '<S31>/Zero1'
   *  Constant: '<S31>/piRsqrd'
   *  Product: '<S31>/Product'
   *  Product: '<S31>/Product4'
   *  Product: '<S31>/Product5'
   *  RelationalOperator: '<S31>/ChkSonic'
   *  Sqrt: '<S31>/Sqrt'
   *  Switch: '<S31>/P2C'
   */
  if (rtu_Isolate != 0.0) {
    localB->FlowNoflow = localP->Zero1_Value;
  } else {
    if (rtu_P1 > localP->PuPd_Value * rtu_P2) {
      /* Switch: '<S31>/P2C' incorporates:
       *  Constant: '<S31>/PuPd'
       *  Product: '<S31>/Product1'
       */
      rtb_P2C_g = rtu_P1 / localP->PuPd_Value;
    } else {
      /* Switch: '<S31>/P2C' */
      rtb_P2C_g = rtu_P2;
    }

    /* Sum: '<S31>/Sum' */
    rtb_Sqrt_d = rtu_P1 - rtb_P2C_g;

    /* DeadZone: '<S31>/Dead Zone' */
    if (rtb_Sqrt_d > rtp_p_deadband) {
      rtb_Sqrt_d -= rtp_p_deadband;
    } else if (rtb_Sqrt_d >= -rtp_p_deadband) {
      rtb_Sqrt_d = 0.0;
    } else {
      rtb_Sqrt_d -= -rtp_p_deadband;
    }

    /* End of DeadZone: '<S31>/Dead Zone' */

    /* Product: '<S31>/Product3' incorporates:
     *  Constant: '<S31>/C1'
     *  Product: '<S31>/Product2'
     */
    rtb_P2C_g = rtb_Sqrt_d * rtb_P2C_g * localP->C1_Value;

    /* MinMax: '<S31>/MinMax' incorporates:
     *  Constant: '<S31>/Zero'
     */
    if ((!(rtb_P2C_g > localP->Zero_Value)) && (!rtIsNaN(localP->Zero_Value))) {
      rtb_P2C_g = localP->Zero_Value;
    }

    /* End of MinMax: '<S31>/MinMax' */
    localB->FlowNoflow = sqrt(rtb_P2C_g) * localP->piRsqrd_Value *
      localP->Cd_Value;
  }

  /* End of Switch: '<S31>/FlowNoflow' */
}

/*
 * Start for atomic system:
 *    '<S26>/BSR Vent Drain'
 *    '<S26>/BSR Charge'
 *    '<S65>/AR Blowoff'
 *    '<S65>/AR Vent Drain'
 *    '<S65>/AR Charge from MRP'
 *    '<S77>/AR Charge'
 *    '<S77>/PC Vent Emer'
 *    '<S102>/VCB Charge'
 *    '<S102>/VCB Vent'
 *    '<S127>/AS Vent Drain'
 *    ...
 */
void PneumaticsSystem_BSRVentDrain_Start(B_BSRVentDrain_PneumaticsSystem_T
  *localB)
{
  localB->FlowNoflow = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S26>/BSR Vent Drain'
 *    '<S26>/BSR Charge'
 *    '<S65>/AR Blowoff'
 *    '<S65>/AR Vent Drain'
 *    '<S65>/AR Charge from MRP'
 *    '<S77>/AR Charge'
 *    '<S77>/PC Vent Emer'
 *    '<S102>/VCB Charge'
 *    '<S102>/VCB Vent'
 *    '<S127>/AS Vent Drain'
 *    ...
 */
void PneumaticsSystem_BSRVentDrain(real_T rtu_P1, real_T rtu_P2, boolean_T
  rtu_Isolate, B_BSRVentDrain_PneumaticsSystem_T *localB,
  P_BSRVentDrain_PneumaticsSystem_T *localP, real_T rtp_p_deadband)
{
  real_T rtb_Sqrt_c;
  real_T rtb_P2C_e;

  /* Switch: '<S30>/FlowNoflow' incorporates:
   *  Constant: '<S30>/Cd'
   *  Constant: '<S30>/PuPd'
   *  Constant: '<S30>/Zero1'
   *  Constant: '<S30>/piRsqrd'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product4'
   *  Product: '<S30>/Product5'
   *  RelationalOperator: '<S30>/ChkSonic'
   *  Sqrt: '<S30>/Sqrt'
   *  Switch: '<S30>/P2C'
   */
  if (rtu_Isolate) {
    localB->FlowNoflow = localP->Zero1_Value;
  } else {
    if (rtu_P1 > localP->PuPd_Value * rtu_P2) {
      /* Switch: '<S30>/P2C' incorporates:
       *  Constant: '<S30>/PuPd'
       *  Product: '<S30>/Product1'
       */
      rtb_P2C_e = rtu_P1 / localP->PuPd_Value;
    } else {
      /* Switch: '<S30>/P2C' */
      rtb_P2C_e = rtu_P2;
    }

    /* Sum: '<S30>/Sum' */
    rtb_Sqrt_c = rtu_P1 - rtb_P2C_e;

    /* DeadZone: '<S30>/Dead Zone' */
    if (rtb_Sqrt_c > rtp_p_deadband) {
      rtb_Sqrt_c -= rtp_p_deadband;
    } else if (rtb_Sqrt_c >= -rtp_p_deadband) {
      rtb_Sqrt_c = 0.0;
    } else {
      rtb_Sqrt_c -= -rtp_p_deadband;
    }

    /* End of DeadZone: '<S30>/Dead Zone' */

    /* Product: '<S30>/Product3' incorporates:
     *  Constant: '<S30>/C1'
     *  Product: '<S30>/Product2'
     */
    rtb_P2C_e = rtb_Sqrt_c * rtb_P2C_e * localP->C1_Value;

    /* MinMax: '<S30>/MinMax' incorporates:
     *  Constant: '<S30>/Zero'
     */
    if ((!(rtb_P2C_e > localP->Zero_Value)) && (!rtIsNaN(localP->Zero_Value))) {
      rtb_P2C_e = localP->Zero_Value;
    }

    /* End of MinMax: '<S30>/MinMax' */
    localB->FlowNoflow = sqrt(rtb_P2C_e) * localP->piRsqrd_Value *
      localP->Cd_Value;
  }

  /* End of Switch: '<S30>/FlowNoflow' */
}

/*
 * System initialize for atomic system:
 *    '<S11>/TimerOffDelay NoInit'
 *    '<S11>/TimerOffDelay NoInit1'
 *    '<S231>/TimerOffDelay NoInit'
 */
void PneumaticsSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 1U;
  localDW->DiscreteTimeIntegrator_PrevResetState = 0;
}

/*
 * Start for atomic system:
 *    '<S11>/TimerOffDelay NoInit'
 *    '<S11>/TimerOffDelay NoInit1'
 *    '<S231>/TimerOffDelay NoInit'
 */
void PneumaticsSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_PneumaticsSystem_T *localB,
   DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW)
{
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  localB->LogicalOperator1 = false;

  /* Start for InitialCondition: '<S38>/IC' */
  localDW->IC_FirstOutputTime = true;
}

/*
 * Output and update for atomic system:
 *    '<S11>/TimerOffDelay NoInit'
 *    '<S11>/TimerOffDelay NoInit1'
 *    '<S231>/TimerOffDelay NoInit'
 */
void PneumaticsSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_PneumaticsSystem_T *localB,
  DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW,
  P_TimerOffDelayNoInit_PneumaticsSystem_T *localP)
{
  real_T rtb_DiscreteTimeIntegrator_o2;
  real_T DiscreteTimeIntegrator_o1;

  /* InitialCondition: '<S38>/IC' incorporates:
   *  Constant: '<S38>/Initialise'
   */
  if (localDW->IC_FirstOutputTime) {
    localDW->IC_FirstOutputTime = false;
    rtb_DiscreteTimeIntegrator_o2 = localP->IC_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  }

  /* End of InitialCondition: '<S38>/IC' */

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S38>/Initialise'
   *  Constant: '<S38>/OffTime'
   */
  if (rtb_DiscreteTimeIntegrator_o2 != 0.0) {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->OffTime_Value;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   *  Gain: '<S38>/Gain'
   *  Logic: '<S38>/Logical Operator'
   */
  if (localDW->DiscreteTimeIntegrator_IC_LOADING != 0) {
    localDW->DiscreteTimeIntegrator_DSTATE = rtb_DiscreteTimeIntegrator_o2;
    if (localDW->DiscreteTimeIntegrator_DSTATE >=
        localP->DiscreteTimeIntegrator_UpperSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_UpperSat;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }
  }

  if (rtu_In || (localDW->DiscreteTimeIntegrator_PrevResetState != 0)) {
    localDW->DiscreteTimeIntegrator_DSTATE = rtb_DiscreteTimeIntegrator_o2;
    if (localDW->DiscreteTimeIntegrator_DSTATE >=
        localP->DiscreteTimeIntegrator_UpperSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        localP->DiscreteTimeIntegrator_UpperSat;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }
  }

  DiscreteTimeIntegrator_o1 = localP->Gain_Gain * static_cast<real_T>(!rtu_In) *
    localP->DiscreteTimeIntegrator_gainval +
    localDW->DiscreteTimeIntegrator_DSTATE;
  if (DiscreteTimeIntegrator_o1 >= localP->DiscreteTimeIntegrator_UpperSat) {
    DiscreteTimeIntegrator_o1 = localP->DiscreteTimeIntegrator_UpperSat;
    rtb_DiscreteTimeIntegrator_o2 = 1.0;
  } else if (DiscreteTimeIntegrator_o1 <=
             localP->DiscreteTimeIntegrator_LowerSat) {
    DiscreteTimeIntegrator_o1 = localP->DiscreteTimeIntegrator_LowerSat;
    rtb_DiscreteTimeIntegrator_o2 = -1.0;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = 0.0;
  }

  /* End of DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */

  /* Logic: '<S38>/Logical Operator1' incorporates:
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S56>/Compare'
   */
  localB->LogicalOperator1 = ((rtb_DiscreteTimeIntegrator_o2 >=
    localP->Constant_Value) || rtu_In);

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 0U;
  localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator_o1;
  localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>(rtu_In);
}

/*
 * Start for atomic system:
 *    '<S127>/AS Charge'
 *    '<S195>/BC Charge'
 */
void PneumaticsSystem_ASCharge_Start(B_ASCharge_PneumaticsSystem_T *localB)
{
  localB->FlowNoflow = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S127>/AS Charge'
 *    '<S195>/BC Charge'
 */
void PneumaticsSystem_ASCharge(real_T rtu_P1, real_T rtu_P2, boolean_T
  rtu_Isolate, real_T rtu_3, real_T rtu_4, real_T rtu_5,
  B_ASCharge_PneumaticsSystem_T *localB, P_ASCharge_PneumaticsSystem_T *localP,
  real_T rtp_p_deadband)
{
  real_T rtb_P2C_e;
  real_T rtb_Sqrt_d;
  real_T rtb_MathFunction;

  /* Switch: '<S133>/FlowNoflow' incorporates:
   *  Constant: '<S133>/Cd'
   *  Constant: '<S133>/Zero1'
   *  Gain: '<S133>/Gain1'
   *  Product: '<S133>/Product4'
   *  Product: '<S133>/Product5'
   *  Sqrt: '<S133>/Sqrt'
   */
  if (rtu_Isolate) {
    localB->FlowNoflow = localP->Zero1_Value;
  } else {
    /* Product: '<S137>/Product' incorporates:
     *  Sum: '<S137>/Sum'
     */
    rtb_P2C_e = (rtu_3 - rtu_P2) * rtu_4;

    /* Saturate: '<S137>/Saturation' */
    if (rtb_P2C_e > localP->Saturation_UpperSat) {
      rtb_P2C_e = localP->Saturation_UpperSat;
    } else {
      if (rtb_P2C_e < localP->Saturation_LowerSat) {
        rtb_P2C_e = localP->Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S137>/Saturation' */

    /* Gain: '<S133>/Gain' incorporates:
     *  Product: '<S137>/Product1'
     */
    rtb_P2C_e = rtb_P2C_e * rtu_5 * localP->Gain_Gain;

    /* Math: '<S133>/Math Function' */
    rtb_MathFunction = rtb_P2C_e * rtb_P2C_e;

    /* Switch: '<S133>/P2C' incorporates:
     *  Constant: '<S133>/PuPd'
     *  Product: '<S133>/Product'
     *  Product: '<S133>/Product1'
     *  RelationalOperator: '<S133>/ChkSonic'
     */
    if (rtu_P1 > localP->PuPd_Value * rtu_P2) {
      rtb_P2C_e = rtu_P1 / localP->PuPd_Value;
    } else {
      rtb_P2C_e = rtu_P2;
    }

    /* End of Switch: '<S133>/P2C' */

    /* Sum: '<S133>/Sum' */
    rtb_Sqrt_d = rtu_P1 - rtb_P2C_e;

    /* DeadZone: '<S133>/Dead Zone' */
    if (rtb_Sqrt_d > rtp_p_deadband) {
      rtb_Sqrt_d -= rtp_p_deadband;
    } else if (rtb_Sqrt_d >= -rtp_p_deadband) {
      rtb_Sqrt_d = 0.0;
    } else {
      rtb_Sqrt_d -= -rtp_p_deadband;
    }

    /* End of DeadZone: '<S133>/Dead Zone' */

    /* Product: '<S133>/Product3' incorporates:
     *  Constant: '<S133>/C1'
     *  Product: '<S133>/Product2'
     */
    rtb_P2C_e = rtb_Sqrt_d * rtb_P2C_e * localP->C1_Value;

    /* MinMax: '<S133>/MinMax' incorporates:
     *  Constant: '<S133>/Zero'
     */
    if ((!(rtb_P2C_e > localP->Zero_Value)) && (!rtIsNaN(localP->Zero_Value))) {
      rtb_P2C_e = localP->Zero_Value;
    }

    /* End of MinMax: '<S133>/MinMax' */
    localB->FlowNoflow = localP->Gain1_Gain * rtb_MathFunction * sqrt(rtb_P2C_e)
      * localP->Cd_Value;
  }

  /* End of Switch: '<S133>/FlowNoflow' */
}

/*
 * Start for atomic system:
 *    '<S127>/AS Vent'
 *    '<S195>/BC Vent'
 */
void PneumaticsSystem_ASVent_Start(B_ASVent_PneumaticsSystem_T *localB)
{
  localB->FlowNoflow = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S127>/AS Vent'
 *    '<S195>/BC Vent'
 */
void PneumaticsSystem_ASVent(real_T rtu_P1, real_T rtu_P2, boolean_T rtu_Isolate,
  real_T rtu_3, real_T rtu_4, real_T rtu_5, B_ASVent_PneumaticsSystem_T *localB,
  P_ASVent_PneumaticsSystem_T *localP, real_T rtp_p_deadband)
{
  real_T rtb_P2C_f;
  real_T rtb_Sqrt_l;
  real_T rtb_MathFunction;

  /* Switch: '<S134>/FlowNoflow' incorporates:
   *  Constant: '<S134>/Cd'
   *  Constant: '<S134>/Zero1'
   *  Gain: '<S134>/Gain1'
   *  Product: '<S134>/Product4'
   *  Product: '<S134>/Product5'
   *  Sqrt: '<S134>/Sqrt'
   */
  if (rtu_Isolate) {
    localB->FlowNoflow = localP->Zero1_Value;
  } else {
    /* Product: '<S140>/Product' incorporates:
     *  Sum: '<S140>/Sum'
     */
    rtb_P2C_f = (rtu_P1 - rtu_3) * rtu_4;

    /* Saturate: '<S140>/Saturation' */
    if (rtb_P2C_f > localP->Saturation_UpperSat) {
      rtb_P2C_f = localP->Saturation_UpperSat;
    } else {
      if (rtb_P2C_f < localP->Saturation_LowerSat) {
        rtb_P2C_f = localP->Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S140>/Saturation' */

    /* Gain: '<S134>/Gain' incorporates:
     *  Product: '<S140>/Product1'
     */
    rtb_P2C_f = rtb_P2C_f * rtu_5 * localP->Gain_Gain;

    /* Math: '<S134>/Math Function' */
    rtb_MathFunction = rtb_P2C_f * rtb_P2C_f;

    /* Switch: '<S134>/P2C' incorporates:
     *  Constant: '<S134>/PuPd'
     *  Product: '<S134>/Product'
     *  Product: '<S134>/Product1'
     *  RelationalOperator: '<S134>/ChkSonic'
     */
    if (rtu_P1 > localP->PuPd_Value * rtu_P2) {
      rtb_P2C_f = rtu_P1 / localP->PuPd_Value;
    } else {
      rtb_P2C_f = rtu_P2;
    }

    /* End of Switch: '<S134>/P2C' */

    /* Sum: '<S134>/Sum' */
    rtb_Sqrt_l = rtu_P1 - rtb_P2C_f;

    /* DeadZone: '<S134>/Dead Zone' */
    if (rtb_Sqrt_l > rtp_p_deadband) {
      rtb_Sqrt_l -= rtp_p_deadband;
    } else if (rtb_Sqrt_l >= -rtp_p_deadband) {
      rtb_Sqrt_l = 0.0;
    } else {
      rtb_Sqrt_l -= -rtp_p_deadband;
    }

    /* End of DeadZone: '<S134>/Dead Zone' */

    /* Product: '<S134>/Product3' incorporates:
     *  Constant: '<S134>/C1'
     *  Product: '<S134>/Product2'
     */
    rtb_P2C_f = rtb_Sqrt_l * rtb_P2C_f * localP->C1_Value;

    /* MinMax: '<S134>/MinMax' incorporates:
     *  Constant: '<S134>/Zero'
     */
    if ((!(rtb_P2C_f > localP->Zero_Value)) && (!rtIsNaN(localP->Zero_Value))) {
      rtb_P2C_f = localP->Zero_Value;
    }

    /* End of MinMax: '<S134>/MinMax' */
    localB->FlowNoflow = localP->Gain1_Gain * rtb_MathFunction * sqrt(rtb_P2C_f)
      * localP->Cd_Value;
  }

  /* End of Switch: '<S134>/FlowNoflow' */
}

/*
 * System initialize for action system:
 *    '<S153>/If Action Subsystem5'
 *    '<S153>/If Action Subsystem4'
 *    '<S153>/If Action Subsystem6'
 */
void PneumaticsSystem_IfActionSubsystem5_Init
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB,
   P_IfActionSubsystem5_PneumaticsSystem_T *localP)
{
  /* SystemInitialize for Outport: '<S173>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for action system:
 *    '<S153>/If Action Subsystem5'
 *    '<S153>/If Action Subsystem4'
 *    '<S153>/If Action Subsystem6'
 */
void PneumaticsSystem_IfActionSubsystem5_Disable
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB,
   P_IfActionSubsystem5_PneumaticsSystem_T *localP)
{
  /* Disable for Outport: '<S173>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Start for action system:
 *    '<S153>/If Action Subsystem5'
 *    '<S153>/If Action Subsystem4'
 *    '<S153>/If Action Subsystem6'
 */
void PneumaticsSystem_IfActionSubsystem5_Start
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB)
{
  localB->In1 = 0.0;
}

/*
 * Output and update for action system:
 *    '<S153>/If Action Subsystem5'
 *    '<S153>/If Action Subsystem4'
 *    '<S153>/If Action Subsystem6'
 */
void PneumaticsSystem_IfActionSubsystem5(real_T rtu_In1,
  B_IfActionSubsystem5_PneumaticsSystem_T *localB)
{
  /* Inport: '<S173>/In1' */
  localB->In1 = rtu_In1;
}

/*
 * Start for atomic system:
 *    '<S231>/MR Pipe Two Way Valve'
 *    '<S255>/MRP to Upstream Connection'
 *    '<S255>/MRP to Downstream Connection'
 */
void PneumaticsSystem_MRPipeTwoWayValve_Start
  (B_MRPipeTwoWayValve_PneumaticsSystem_T *localB)
{
  localB->Add = 0.0;

  /* Start for Atomic SubSystem: '<S237>/Forward' */
  PneumaticsSystem_BSRVentDrain_Start(&localB->Forward);

  /* End of Start for SubSystem: '<S237>/Forward' */

  /* Start for Atomic SubSystem: '<S237>/Reverse' */
  PneumaticsSystem_BSRVentDrain_Start(&localB->Reverse);

  /* End of Start for SubSystem: '<S237>/Reverse' */
}

/*
 * Output and update for atomic system:
 *    '<S231>/MR Pipe Two Way Valve'
 *    '<S255>/MRP to Upstream Connection'
 *    '<S255>/MRP to Downstream Connection'
 */
void PneumaticsSystem_MRPipeTwoWayValve(real_T rtu_P1, real_T rtu_P2, boolean_T
  rtu_Isolate, B_MRPipeTwoWayValve_PneumaticsSystem_T *localB,
  P_MRPipeTwoWayValve_PneumaticsSystem_T *localP, real_T rtp_p_deadband)
{
  /* Outputs for Atomic SubSystem: '<S237>/Forward' */
  PneumaticsSystem_BSRVentDrain(rtu_P1, rtu_P2, rtu_Isolate, &localB->Forward,
    &localP->Forward, rtp_p_deadband);

  /* End of Outputs for SubSystem: '<S237>/Forward' */

  /* Outputs for Atomic SubSystem: '<S237>/Reverse' */
  PneumaticsSystem_BSRVentDrain(rtu_P2, rtu_P1, rtu_Isolate, &localB->Reverse,
    &localP->Reverse, rtp_p_deadband);

  /* End of Outputs for SubSystem: '<S237>/Reverse' */

  /* Sum: '<S237>/Add' */
  localB->Add = localB->Forward.FlowNoflow - localB->Reverse.FlowNoflow;
}

/* System initialize for referenced model: 'PneumaticsSystem' */
void PneumaticsSystem_Init(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_au;
  int32_T ForEach_itr_cq;
  int32_T ForEach_itr_fz;
  int32_T i;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] = PneumaticsSystem_P.UnitDelay_InitialCondition;
  }

  /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

  /* SystemInitialize for Iterator SubSystem: '<Root>/PneumaticsPerVehicle' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* SystemInitialize for Enabled SubSystem: '<S3>/PneumaticsSystem' */
    /* InitializeConditions for UnitDelay: '<S230>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_eb;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_h;

    /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_k =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_k =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_pi;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay3' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay3_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S273>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_a =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_g =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay5' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay5_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay5_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S27>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_e =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_ed;

    /* InitializeConditions for UnitDelay: '<S40>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease_vinit_j;

    /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_d =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease14_vinit;

    /* InitializeConditions for UnitDelay: '<S41>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_n =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease1_vinit;

    /* InitializeConditions for UnitDelay: '<S48>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_a =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease2_vinit;

    /* InitializeConditions for UnitDelay: '<S49>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_dh =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease3_vinit;

    /* InitializeConditions for UnitDelay: '<S50>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_g =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease4_vinit;

    /* InitializeConditions for UnitDelay: '<S51>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease5_vinit;

    /* InitializeConditions for UnitDelay: '<S52>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease6_vinit;

    /* InitializeConditions for UnitDelay: '<S53>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_i =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease7_vinit;

    /* InitializeConditions for UnitDelay: '<S54>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_nm =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease8_vinit;

    /* InitializeConditions for UnitDelay: '<S55>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b2 =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease9_vinit;

    /* InitializeConditions for UnitDelay: '<S42>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_da =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease10_vinit;

    /* InitializeConditions for UnitDelay: '<S43>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c4 =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease11_vinit;

    /* InitializeConditions for UnitDelay: '<S44>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_p =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease12_vinit;

    /* InitializeConditions for UnitDelay: '<S45>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_f =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease13_vinit;

    /* InitializeConditions for UnitDelay: '<S47>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_fx =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease15_vinit;

    /* InitializeConditions for UnitDelay: '<S36>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ia =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease_vinit_c;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay4' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay4_DSTATE =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay4_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S11>/TimerOffDelay NoInit1' */
    PneumaticsSystem_TimerOffDelayNoInit_Init(&localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1);

    /* End of SystemInitialize for SubSystem: '<S11>/TimerOffDelay NoInit1' */

    /* SystemInitialize for Atomic SubSystem: '<S11>/TimerOffDelay NoInit' */
    PneumaticsSystem_TimerOffDelayNoInit_Init(&localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit);

    /* End of SystemInitialize for SubSystem: '<S11>/TimerOffDelay NoInit' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/AuxSystem' */
    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_f =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_c =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S60>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_e =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S67>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_m =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S76>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ii =
      PneumaticsSystem_P.CoreSubsys_pn.DetectDecrease_vinit;

    /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_eb =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_kr;

    /* InitializeConditions for UnitDelay: '<S61>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_ks =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S98>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_m =
      PneumaticsSystem_P.CoreSubsys_pn.DetectChange_vinit;

    /* InitializeConditions for Memory: '<S99>/Memory' */
    localDW->CoreSubsys_pn[ForEach_itr].Memory_PreviousInput =
      PneumaticsSystem_P.CoreSubsys_pn.SRFlipFlop_initial_condition;

    /* InitializeConditions for UnitDelay: '<S85>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_g =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S83>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_j =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_nm;

    /* InitializeConditions for UnitDelay: '<S100>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_mr =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_e3;

    /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_kw =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S111>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_d =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_i;

    /* SystemInitialize for Outport: '<S58>/PantoSystemPressures' */
    localB->CoreSubsys_pn[ForEach_itr].P_d =
      PneumaticsSystem_P.CoreSubsys_pn.PantoSystemPressures_Y0.AuxiliaryReservoirPressure;
    localB->CoreSubsys_pn[ForEach_itr].P_e =
      PneumaticsSystem_P.CoreSubsys_pn.PantoSystemPressures_Y0.PantographCylinderPressure;
    localB->CoreSubsys_pn[ForEach_itr].P_o =
      PneumaticsSystem_P.CoreSubsys_pn.PantoSystemPressures_Y0.VCBCylinderPressure;

    /* SystemInitialize for Outport: '<S58>/PressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_e =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0.AuxiliaryReservoirPressureSwitch;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0.PS3;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_j =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0.VCBPressureSwitch;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_d =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0.ORDPressureSwitch;

    /* SystemInitialize for Outport: '<S58>/MRPToAuxR' */
    localB->CoreSubsys_pn[ForEach_itr].ARChargefromMRP.FlowNoflow =
      PneumaticsSystem_P.CoreSubsys_pn.MRPToAuxR_Y0;

    /* End of SystemInitialize for SubSystem: '<S12>/AuxSystem' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/Horn' */
    /* SystemInitialize for Outport: '<S59>/PressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].HornLowPressureSwitch =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0_d.HornLowPressureSwitch;
    localB->CoreSubsys_pn[ForEach_itr].HornHighPressureSwitch =
      PneumaticsSystem_P.CoreSubsys_pn.PressureSwitches_Y0_d.HornHighPressureSwitch;

    /* SystemInitialize for Outport: '<S59>/AudioOut' */
    localB->CoreSubsys_pn[ForEach_itr].HornLow =
      PneumaticsSystem_P.CoreSubsys_pn.AudioOut_Y0.HornLow;
    localB->CoreSubsys_pn[ForEach_itr].HornHigh =
      PneumaticsSystem_P.CoreSubsys_pn.AudioOut_Y0.HornHigh;

    /* End of SystemInitialize for SubSystem: '<S12>/Horn' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/BrakeSupplyReservoir' */
    /* InitializeConditions for UnitDelay: '<S214>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_h =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S219>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_es =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_o;

    /* SystemInitialize for Outport: '<S214>/BSRPressure' */
    localB->CoreSubsys_pn[ForEach_itr].P_a =
      PneumaticsSystem_P.CoreSubsys_pn.BSRPressure_Y0;

    /* SystemInitialize for Outport: '<S214>/BSRPressureSwitch' */
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_g =
      PneumaticsSystem_P.CoreSubsys_pn.BSRPressureSwitch_Y0;

    /* SystemInitialize for Outport: '<S214>/MRPToBSR' */
    localB->CoreSubsys_pn[ForEach_itr].BSRCharge_b.FlowNoflow =
      PneumaticsSystem_P.CoreSubsys_pn.MRPToBSR_Y0;

    /* SystemInitialize for Outport: '<S214>/BSRPressureGauge' */
    localB->CoreSubsys_pn[ForEach_itr].Bias =
      PneumaticsSystem_P.CoreSubsys_pn.BSRPressureGauge_Y0;

    /* End of SystemInitialize for SubSystem: '<S15>/BrakeSupplyReservoir' */

    /* SystemInitialize for Enabled SubSystem: '<S14>/AirSuspensionSystem' */
    /* SystemInitialize for Iterator SubSystem: '<S118>/AirSuspensionPerBogie' */
    for (ForEach_itr_fz = 0; ForEach_itr_fz < 2; ForEach_itr_fz++) {
      /* InitializeConditions for UnitDelay: '<S123>/Unit Delay' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        UnitDelay_DSTATE =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S123>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        UnitDelay1_DSTATE_g =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.UnitDelay1_InitialCondition_m;

      /* InitializeConditions for UnitDelay: '<S130>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        UnitDelay1_DSTATE =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.UnitDelay1_InitialCondition;

      /* InitializeConditions for DiscreteTransferFcn: '<S145>/Discrete Transfer Fcn' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        DiscreteTransferFcn_states =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.DiscreteTransferFcn_InitialStates;
    }

    /* End of SystemInitialize for SubSystem: '<S118>/AirSuspensionPerBogie' */

    /* SystemInitialize for Outport: '<S118>/AirSuspensionPressure' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionPressure_Y0;

    /* SystemInitialize for Outport: '<S118>/ASPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.ASPressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S118>/AirSuspPressure%Variation' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.AirSuspPressureVariation_Y0;

    /* SystemInitialize for Outport: '<S118>/AirSuspensionPressure' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionPressure_Y0;

    /* SystemInitialize for Outport: '<S118>/ASPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.ASPressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S118>/AirSuspPressure%Variation' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.AirSuspPressureVariation_Y0;

    /* SystemInitialize for Outport: '<S118>/ASRToAS' */
    localB->CoreSubsys_pn[ForEach_itr].Sum =
      PneumaticsSystem_P.CoreSubsys_pn.ASRToAS_Y0;

    /* End of SystemInitialize for SubSystem: '<S14>/AirSuspensionSystem' */

    /* SystemInitialize for Enabled SubSystem: '<S14>/BrakingSystem' */
    /* SystemInitialize for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' */
    for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
      /* InitializeConditions for DiscreteTransferFcn: '<S156>/Discrete Transfer Fcn' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DiscreteTransferFcn_InitialStates;

      /* InitializeConditions for DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states_i =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DiscreteTransferFcn_InitialStates_i;

      /* InitializeConditions for UnitDelay: '<S168>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_h =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease5_vinit;

      /* InitializeConditions for Memory: '<S175>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority1_initial_condition;

      /* InitializeConditions for UnitDelay: '<S163>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease_vinit;

      /* InitializeConditions for Memory: '<S176>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_j =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority2_initial_condition;

      /* InitializeConditions for UnitDelay: '<S164>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_b =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease1_vinit;

      /* InitializeConditions for Memory: '<S177>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_l =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority3_initial_condition;

      /* InitializeConditions for UnitDelay: '<S165>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_e =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease2_vinit;

      /* InitializeConditions for Memory: '<S178>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_d =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority4_initial_condition;

      /* InitializeConditions for UnitDelay: '<S166>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_a =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease3_vinit;

      /* InitializeConditions for Memory: '<S179>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_f =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority5_initial_condition;

      /* InitializeConditions for UnitDelay: '<S167>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_j =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease4_vinit;

      /* InitializeConditions for Memory: '<S180>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_g =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.SRLatchResetPriority6_initial_condition;

      /* InitializeConditions for UnitDelay: '<S169>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_f =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DetectDecrease6_vinit;

      /* InitializeConditions for Memory: '<S209>/Memory' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Memory_PreviousInput_p =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.MagnetValve_B20_initial_condition;

      /* InitializeConditions for DiscreteTransferFcn: '<S208>/Discrete Transfer Fcn' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states_l =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DiscreteTransferFcn_InitialStates_o;

      /* SystemInitialize for IfAction SubSystem: '<S153>/If Action Subsystem' */
      /* InitializeConditions for UnitDelay: '<S181>/Delay Input2' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput2_DSTATE =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.DelayInput2_InitialCondition;

      /* SystemInitialize for Outport: '<S170>/Out2' */
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        OutportBufferForOut2 =
        PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Out2_Y0;

      /* End of SystemInitialize for SubSystem: '<S153>/If Action Subsystem' */

      /* SystemInitialize for Iterator SubSystem: '<S148>/BrakeCylinderSystemPerAxle' */
      for (ForEach_itr_cq = 0; ForEach_itr_cq < 2; ForEach_itr_cq++) {
        /* SystemInitialize for Enabled SubSystem: '<S151>/AxleBrakeCylinder' */
        /* InitializeConditions for UnitDelay: '<S192>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].UnitDelay1_DSTATE_k =
          PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.UnitDelay1_InitialCondition_o;

        /* InitializeConditions for UnitDelay: '<S192>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].UnitDelay_DSTATE =
          PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S196>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].UnitDelay1_DSTATE =
          PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.UnitDelay1_InitialCondition;

        /* SystemInitialize for Outport: '<S192>/BCPressure' */
        localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].P =
          PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCPressure_Y0;

        /* SystemInitialize for Outport: '<S192>/BSRtoBCFlow' */
        localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].BCCharge.FlowNoflow =
          PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BSRtoBCFlow_Y0;

        /* End of SystemInitialize for SubSystem: '<S151>/AxleBrakeCylinder' */
      }

      /* End of SystemInitialize for SubSystem: '<S148>/BrakeCylinderSystemPerAxle' */

      /* SystemInitialize for IfAction SubSystem: '<S153>/If Action Subsystem5' */
      PneumaticsSystem_IfActionSubsystem5_Init(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem5,
        &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem5);

      /* End of SystemInitialize for SubSystem: '<S153>/If Action Subsystem5' */

      /* SystemInitialize for IfAction SubSystem: '<S153>/If Action Subsystem4' */
      PneumaticsSystem_IfActionSubsystem5_Init(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem4,
        &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem4);

      /* End of SystemInitialize for SubSystem: '<S153>/If Action Subsystem4' */

      /* SystemInitialize for IfAction SubSystem: '<S153>/If Action Subsystem6' */
      PneumaticsSystem_IfActionSubsystem5_Init(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem6,
        &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem6);

      /* End of SystemInitialize for SubSystem: '<S153>/If Action Subsystem6' */
    }

    /* End of SystemInitialize for SubSystem: '<S121>/BrakingSystemPerBogie' */

    /* SystemInitialize for Outport: '<S121>/BSRtoVehicleBCFlow' */
    localB->CoreSubsys_pn[ForEach_itr].SumofElements =
      PneumaticsSystem_P.CoreSubsys_pn.BSRtoVehicleBCFlow_Y0;

    /* SystemInitialize for Outport: '<S121>/BCUPressureTransducers' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.BCUPressureTransducers_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeSystemGauges' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeSystemGauges_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeControlPressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ControlPressure_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeControlPressures_Y0;

    /* SystemInitialize for Outport: '<S121>/BCUPressureTransducers' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.BCUPressureTransducers_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeSystemGauges' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeSystemGauges_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeControlPressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ControlPressure_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeControlPressures_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeCylinderPressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressures_Y0;
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressures_Y0;
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[2] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressures_Y0;
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[3] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressures_Y0;

    /* SystemInitialize for Outport: '<S121>/ParkBrakePressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ParkBrakePressure_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.ParkBrakePressures_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeCylinderPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S121>/ParkBrakePressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.ParkBrakePressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S121>/FaultMessages' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_FaultMessages_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.FaultMessages_Y0;

    /* SystemInitialize for Outport: '<S121>/ParkBrakePressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ParkBrakePressure_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.ParkBrakePressures_Y0;

    /* SystemInitialize for Outport: '<S121>/BrakeCylinderPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.BrakeCylinderPressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S121>/ParkBrakePressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.ParkBrakePressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S121>/FaultMessages' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_FaultMessages_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.FaultMessages_Y0;

    /* End of SystemInitialize for SubSystem: '<S14>/BrakingSystem' */

    /* SystemInitialize for Enabled SubSystem: '<S14>/SandingSystem' */
    /* SystemInitialize for Outport: '<S122>/SandingPressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_SandingPressure_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.SandingPressures_Y0;

    /* SystemInitialize for Outport: '<S122>/SandingPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_SandingPressureSwitch_at_inport_0[0] =
      PneumaticsSystem_P.CoreSubsys_pn.SandingPressureSwitches_Y0;

    /* SystemInitialize for Outport: '<S122>/SandingPressures' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_SandingPressure_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.SandingPressures_Y0;

    /* SystemInitialize for Outport: '<S122>/SandingPressureSwitches' */
    localB->CoreSubsys_pn[ForEach_itr].
      ImpAsg_InsertedFor_SandingPressureSwitch_at_inport_0[1] =
      PneumaticsSystem_P.CoreSubsys_pn.SandingPressureSwitches_Y0;

    /* End of SystemInitialize for SubSystem: '<S14>/SandingSystem' */

    /* SystemInitialize for Enabled SubSystem: '<S17>/MainReservoir' */
    /* InitializeConditions for UnitDelay: '<S229>/Unit Delay' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_d =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S235>/Delay Input1' */
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_pn =
      PneumaticsSystem_P.CoreSubsys_pn.DetectIncrease_vinit;

    /* InitializeConditions for UnitDelay: '<S251>/Unit Delay1' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_f =
      PneumaticsSystem_P.CoreSubsys_pn.UnitDelay1_InitialCondition_d;

    /* SystemInitialize for Atomic SubSystem: '<S231>/TimerOffDelay NoInit' */
    PneumaticsSystem_TimerOffDelayNoInit_Init(&localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit_d);

    /* End of SystemInitialize for SubSystem: '<S231>/TimerOffDelay NoInit' */

    /* SystemInitialize for Outport: '<S229>/MRPressure' */
    localB->CoreSubsys_pn[ForEach_itr].P =
      PneumaticsSystem_P.CoreSubsys_pn.MRPressure_Y0;

    /* SystemInitialize for Outport: '<S229>/MRPressureSwitch' */
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch =
      PneumaticsSystem_P.CoreSubsys_pn.MRPressureSwitch_Y0;

    /* SystemInitialize for Outport: '<S229>/MRPToMRFlow' */
    localB->CoreSubsys_pn[ForEach_itr].MRPipeTwoWayValve.Add =
      PneumaticsSystem_P.CoreSubsys_pn.MRPToMRFlow_Y0;

    /* End of SystemInitialize for SubSystem: '<S17>/MainReservoir' */

    /* SystemInitialize for Outport: '<S9>/PenumaticsVehicleOut' */
    localB->CoreSubsys_pn[ForEach_itr].BusCreator =
      PneumaticsSystem_P.CoreSubsys_pn.PenumaticsVehicleOut_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/PneumaticsSystem' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/PneumaticsPerVehicle' */
}

/* System reset for referenced model: 'PneumaticsSystem' */
void PneumaticsSystem_Reset(DW_PneumaticsSystem_f_T *localDW)
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] = PneumaticsSystem_P.UnitDelay_InitialCondition;
  }

  /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
}

/* Disable for referenced model: 'PneumaticsSystem' */
void PneumaticsSystem_Disable(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_au;

  /* Disable for Iterator SubSystem: '<Root>/PneumaticsPerVehicle' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Disable for Enabled SubSystem: '<S3>/PneumaticsSystem' */
    if (localDW->CoreSubsys_pn[ForEach_itr].PneumaticsSystem_MODE) {
      /* Disable for Enabled SubSystem: '<S14>/BrakingSystem' */
      if (localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE) {
        /* Disable for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' */
        for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
          /* Disable for If: '<S153>/If' */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .If_ActiveSubsystem == 0) {
            /* Disable for Outport: '<S170>/Out2' */
            localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              OutportBufferForOut2 =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Out2_Y0;
          }

          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            If_ActiveSubsystem = -1;

          /* End of Disable for If: '<S153>/If' */

          /* Disable for If: '<S153>/If1' */
          switch (localDW->CoreSubsys_pn[ForEach_itr]
                  .CoreSubsys_pna[ForEach_itr_au].If1_ActiveSubsystem) {
           case 0:
            PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
              CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              IfActionSubsystem5,
              &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem5);
            break;

           case 1:
            PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
              CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              IfActionSubsystem4,
              &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem4);
            break;

           case 2:
            PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
              CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              IfActionSubsystem6,
              &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem6);
            break;
          }

          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            If1_ActiveSubsystem = -1;

          /* End of Disable for If: '<S153>/If1' */
        }

        /* End of Disable for SubSystem: '<S121>/BrakingSystemPerBogie' */
        localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE = false;
      }

      /* End of Disable for SubSystem: '<S14>/BrakingSystem' */
      localDW->CoreSubsys_pn[ForEach_itr].PneumaticsSystem_MODE = false;
    }

    /* End of Disable for SubSystem: '<S3>/PneumaticsSystem' */
  }

  /* End of Disable for SubSystem: '<Root>/PneumaticsPerVehicle' */
}

/* Start for referenced model: 'PneumaticsSystem' */
void PneumaticsSystem_Start(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_a;
  int32_T ForEach_itr_au;
  int32_T ForEach_itr_cq;
  int32_T ForEach_itr_fz;
  static const BD_PneumaticsSystem_Out_Vehicle tmp = { { { 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0 },                    /* BrakeCylinderPressures */
      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } /* ParkBrakePressures */
    },                                 /* AxleBrakes */
    { 0.0,                             /* HornLow */
      0.0,                             /* HornHigh */
      0.0,                             /* PneumaticPressureRelease */
      false                            /* EmergencyBrakeActive */
    },                                 /* Audio */
    { 0.0,                             /* BrakeReservoirPressure */
      0.0,                             /* MainReservoirPressure */
      0.0,                             /* MainReservoirPipePressure */
      0.0,                             /* AuxiliaryReservoirPressure */
      0.0,                             /* PantographCylinderPressure */
      0.0,                             /* VCBCylinderPressure */
      { { 0.0,                         /* BrakeCylinderControlPressure */
          { 0.0, 0.0 },                /* BrakeCylinderPressure */
          0.0,                         /* ParkBrakePressure */
          0.0,                         /* SandingSystemPressure */
          0.0,                         /* AirSuspensionPressure */
          0.0                          /* AirSuspPressureDiff */
        }, { 0.0,                      /* BrakeCylinderControlPressure */
          { 0.0, 0.0 },                /* BrakeCylinderPressure */
          0.0,                         /* ParkBrakePressure */
          0.0,                         /* SandingSystemPressure */
          0.0,                         /* AirSuspensionPressure */
          0.0                          /* AirSuspPressureDiff */
        } }                            /* Bogie */
    },                                 /* Debug */
    { 0.0,                             /* MainReservoirPressureGauge */
      0.0,                             /* SRPressureGauge */
      { { 0.0,                         /* BrakeCylinderPressureGauge */
          0.0                          /* ParkBrakePressureGauge */
        }, { 0.0,                      /* BrakeCylinderPressureGauge */
          0.0                          /* ParkBrakePressureGauge */
        } }                            /* Bogie */
    },                                 /* PressureGauges */
    { 0.0,                             /* BrakeReservoirPressureSwitch */
      0.0,                             /* HornHighPressureSwitch */
      0.0,                             /* HornLowPressureSwitch */
      0.0,                             /* MainReservoirPressureSwitch */
      0.0,                             /* AuxiliaryReservoirPressureSwitch */
      0.0,                             /* MainReservoirPipePressureSwitch */
      0.0,                             /* MRPS_TractionCutout */
      0.0,                             /* PS3 */
      0.0,                             /* PS2 */
      0.0,                             /* VCBPressureSwitch */
      { { 0.0,                         /* BrakeCylinderPressureSwitch */
          0.0,                         /* ParkBrakePressureSwitch */
          0.0,                         /* AirSuspensionPressureSwitch */
          0.0                          /* SandingSystemPressureSwitch */
        }, { 0.0,                      /* BrakeCylinderPressureSwitch */
          0.0,                         /* ParkBrakePressureSwitch */
          0.0,                         /* AirSuspensionPressureSwitch */
          0.0                          /* SandingSystemPressureSwitch */
        } }                            /* Bogie */
    },                                 /* PressureSwitches */
    { { { 0.0,                         /* BrakeCylinderControlPressure */
          0.0,                         /* BrakeCylinderControlVolumePressure */
          0.0,                         /* BrakeReservoirPressure */
          0.0                          /* AirSuspensionLoadPressure */
        }, { 0.0,                      /* BrakeCylinderControlPressure */
          0.0,                         /* BrakeCylinderControlVolumePressure */
          0.0,                         /* BrakeReservoirPressure */
          0.0                          /* AirSuspensionLoadPressure */
        } }                            /* Bogie */
    },                                 /* PressureTransducers */
    { { { false,                       /* BECU1EmergencyBrakeFailure */
          false,                       /* BECU2EmergencyBrakeFailure */
          false,                       /* BECU1ServiceBrakeFailure */
          false,                       /* BECU1BrakeNotApplied */
          false,                       /* BECU1BrakeNotReleased */
          false,                       /* BECU1CarLoadPressureLow */
          false,                       /* BECU2CarLoadPressureLow */
          false,                       /* BECULowRPressure */
          false,                       /* AirSuspensionBogie1Deflated */
          false                        /* BECU1LoadPressureLow */
        }, { false,                    /* BECU1EmergencyBrakeFailure */
          false,                       /* BECU2EmergencyBrakeFailure */
          false,                       /* BECU1ServiceBrakeFailure */
          false,                       /* BECU1BrakeNotApplied */
          false,                       /* BECU1BrakeNotReleased */
          false,                       /* BECU1CarLoadPressureLow */
          false,                       /* BECU2CarLoadPressureLow */
          false,                       /* BECULowRPressure */
          false,                       /* AirSuspensionBogie1Deflated */
          false                        /* BECU1LoadPressureLow */
        } }                            /* Bogie */
    }                                  /* TCMS */
  };

  /* Start for Iterator SubSystem: '<Root>/PneumaticsPerVehicle' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Start for Enabled SubSystem: '<S3>/PneumaticsSystem' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_k = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_k = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay3_DSTATE = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_a = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_g = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay5_DSTATE = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_e = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_d = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_n = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_a = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_dh = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_g = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_i = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_nm = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b2 = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_da = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c4 = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_p = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_f = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_fx = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ia = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay4_DSTATE = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].BusCreator = tmp;

    /* Start for InitialCondition: '<S27>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S273>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_k = true;

    /* Start for Atomic SubSystem: '<S255>/MRP to Downstream Connection' */
    PneumaticsSystem_MRPipeTwoWayValve_Start(&localB->CoreSubsys_pn[ForEach_itr]
      .MRPtoDownstreamConnection);

    /* End of Start for SubSystem: '<S255>/MRP to Downstream Connection' */

    /* Start for Atomic SubSystem: '<S255>/MRP to Upstream Connection' */
    PneumaticsSystem_MRPipeTwoWayValve_Start(&localB->CoreSubsys_pn[ForEach_itr]
      .MRPtoUpstreamConnection);

    /* End of Start for SubSystem: '<S255>/MRP to Upstream Connection' */

    /* Start for Atomic SubSystem: '<S26>/BSR Charge' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRCharge);

    /* End of Start for SubSystem: '<S26>/BSR Charge' */

    /* Start for Atomic SubSystem: '<S26>/BSR Vent Drain' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRVentDrain);

    /* End of Start for SubSystem: '<S26>/BSR Vent Drain' */

    /* Start for Atomic SubSystem: '<S26>/BSR Vent IC' */
    PneumaticsSystem_BSRVentIC_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRVentIC);

    /* End of Start for SubSystem: '<S26>/BSR Vent IC' */

    /* Start for Atomic SubSystem: '<S11>/TimerOffDelay NoInit1' */
    PneumaticsSystem_TimerOffDelayNoInit_Start(&localB->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1, &localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1);

    /* End of Start for SubSystem: '<S11>/TimerOffDelay NoInit1' */

    /* Start for Atomic SubSystem: '<S11>/TimerOffDelay NoInit' */
    PneumaticsSystem_TimerOffDelayNoInit_Start(&localB->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit, &localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit);

    /* End of Start for SubSystem: '<S11>/TimerOffDelay NoInit' */

    /* Start for Enabled SubSystem: '<S12>/AuxSystem' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_f = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_c = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_e = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_m = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].P_d = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_e = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ii = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_eb = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_ks = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_m = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_g = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_mr = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].P_e = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_d = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_kw = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_d = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].P_o = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_j = 0.0;

    /* Start for InitialCondition: '<S66>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_a = true;

    /* Start for InitialCondition: '<S67>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_a = true;

    /* Start for Atomic SubSystem: '<S65>/AR Charge from MRP' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      ARChargefromMRP);

    /* End of Start for SubSystem: '<S65>/AR Charge from MRP' */

    /* Start for Atomic SubSystem: '<S65>/AR Vent Drain' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      ARVentDrain);

    /* End of Start for SubSystem: '<S65>/AR Vent Drain' */

    /* Start for Atomic SubSystem: '<S65>/AR Blowoff' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      ARBlowoff);

    /* End of Start for SubSystem: '<S65>/AR Blowoff' */

    /* Start for InitialCondition: '<S85>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ax = true;

    /* Start for Atomic SubSystem: '<S77>/PC Vent Emer' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      PCVentEmer);

    /* End of Start for SubSystem: '<S77>/PC Vent Emer' */

    /* Start for InitialCondition: '<S100>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ak = true;

    /* Start for Atomic SubSystem: '<S77>/AR Charge' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      ARCharge);

    /* End of Start for SubSystem: '<S77>/AR Charge' */

    /* Start for Atomic SubSystem: '<S77>/PC Vent Isol' */
    PneumaticsSystem_BSRVentIC_Start(&localB->CoreSubsys_pn[ForEach_itr].
      PCVentIsol);

    /* End of Start for SubSystem: '<S77>/PC Vent Isol' */

    /* Start for Atomic SubSystem: '<S77>/PC Vent Control' */
    PneumaticsSystem_BSRVentIC_Start(&localB->CoreSubsys_pn[ForEach_itr].
      PCVentControl);

    /* End of Start for SubSystem: '<S77>/PC Vent Control' */

    /* Start for InitialCondition: '<S96>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_g = true;

    /* Start for InitialCondition: '<S97>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_f = true;

    /* Start for InitialCondition: '<S111>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_o = true;

    /* Start for Atomic SubSystem: '<S102>/VCB Charge' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      VCBCharge);

    /* End of Start for SubSystem: '<S102>/VCB Charge' */

    /* Start for Atomic SubSystem: '<S102>/VCB Isolate' */
    PneumaticsSystem_BSRVentIC_Start(&localB->CoreSubsys_pn[ForEach_itr].
      VCBIsolate);

    /* End of Start for SubSystem: '<S102>/VCB Isolate' */

    /* Start for Atomic SubSystem: '<S102>/VCB Vent' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      VCBVent);

    /* End of Start for SubSystem: '<S102>/VCB Vent' */

    /* Start for InitialCondition: '<S113>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_n = true;

    /* End of Start for SubSystem: '<S12>/AuxSystem' */

    /* Start for Enabled SubSystem: '<S12>/Horn' */
    localB->CoreSubsys_pn[ForEach_itr].HornLowPressureSwitch = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].HornHighPressureSwitch = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].HornLow = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].HornHigh = 0.0;

    /* End of Start for SubSystem: '<S12>/Horn' */

    /* Start for Enabled SubSystem: '<S15>/BrakeSupplyReservoir' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_h = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_es = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].P_a = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].Bias = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_g = 0.0;

    /* Start for InitialCondition: '<S218>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_e = true;

    /* Start for InitialCondition: '<S219>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_b = true;

    /* Start for Atomic SubSystem: '<S217>/BSR Charge' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRCharge_b);

    /* End of Start for SubSystem: '<S217>/BSR Charge' */

    /* Start for Atomic SubSystem: '<S217>/BSR Vent Drain' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRVentDrain_d);

    /* End of Start for SubSystem: '<S217>/BSR Vent Drain' */

    /* Start for Atomic SubSystem: '<S217>/BSR Vent IC' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      BSRVentIC_c);

    /* End of Start for SubSystem: '<S217>/BSR Vent IC' */
    /* End of Start for SubSystem: '<S15>/BrakeSupplyReservoir' */

    /* Start for Enabled SubSystem: '<S14>/AirSuspensionSystem' */
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2[0] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1_k[0] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2[1] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1_k[1] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].Sum = 0.0;

    /* Start for Iterator SubSystem: '<S118>/AirSuspensionPerBogie' */
    for (ForEach_itr_fz = 0; ForEach_itr_fz < 2; ForEach_itr_fz++) {
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        UnitDelay_DSTATE = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        UnitDelay1_DSTATE = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        VectorConcatenate1[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        VectorConcatenate[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        VectorConcatenate1[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        VectorConcatenate[1] = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        DiscreteTransferFcn_states = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        DiscreteTransferFcn_tmp = 0.0;

      /* Start for InitialCondition: '<S130>/IC' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        IC_FirstOutputTime = true;

      /* Start for Atomic SubSystem: '<S127>/AS Charge' */
      PneumaticsSystem_ASCharge_Start(&localB->CoreSubsys_pn[ForEach_itr].
        CoreSubsys[ForEach_itr_fz].ASCharge);

      /* End of Start for SubSystem: '<S127>/AS Charge' */

      /* Start for Atomic SubSystem: '<S127>/AS Vent Drain' */
      PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
        CoreSubsys[ForEach_itr_fz].ASVentDrain);

      /* End of Start for SubSystem: '<S127>/AS Vent Drain' */

      /* Start for Atomic SubSystem: '<S127>/AS Vent IC' */
      PneumaticsSystem_BSRVentIC_Start(&localB->CoreSubsys_pn[ForEach_itr].
        CoreSubsys[ForEach_itr_fz].ASVentIC);

      /* End of Start for SubSystem: '<S127>/AS Vent IC' */

      /* Start for Atomic SubSystem: '<S127>/AS Vent' */
      PneumaticsSystem_ASVent_Start(&localB->CoreSubsys_pn[ForEach_itr].
        CoreSubsys[ForEach_itr_fz].ASVent);

      /* End of Start for SubSystem: '<S127>/AS Vent' */

      /* Start for InitialCondition: '<S132>/Initialise' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
        Initialise_FirstOutputTime = true;
    }

    /* End of Start for SubSystem: '<S118>/AirSuspensionPerBogie' */
    /* End of Start for SubSystem: '<S14>/AirSuspensionSystem' */

    /* Start for Enabled SubSystem: '<S14>/BrakingSystem' */
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate[0] = false;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1[0] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2_c[0] = false;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate[1] = false;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1[1] = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2_c[1] = false;
    localB->CoreSubsys_pn[ForEach_itr].SumofElements = 0.0;

    /* Start for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' */
    for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_tmp = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states_i = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_tmp_d = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_b = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_e = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_a = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput1_DSTATE_f = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1_c[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate_l[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1_d[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate_k[0] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1_c[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate_l[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate1_d[1] = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        VectorConcatenate_k[1] = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_states_l = 0.0;
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DiscreteTransferFcn_tmp_h = 0.0;

      /* Start for InitialCondition: '<S190>/Initialise' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Initialise_FirstOutputTime = true;

      /* Start for If: '<S153>/If' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        If_ActiveSubsystem = -1;

      /* Start for IfAction SubSystem: '<S153>/If Action Subsystem' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        DelayInput2_DSTATE = 0.0;
      localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        OutportBufferForOut2 = 0.0;

      /* End of Start for SubSystem: '<S153>/If Action Subsystem' */

      /* Start for Iterator SubSystem: '<S148>/BrakeCylinderSystemPerAxle' */
      for (ForEach_itr_cq = 0; ForEach_itr_cq < 2; ForEach_itr_cq++) {
        /* Start for Enabled SubSystem: '<S151>/AxleBrakeCylinder' */
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].UnitDelay_DSTATE = 0.0;
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].UnitDelay1_DSTATE = 0.0;
        localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].P = 0.0;

        /* Start for InitialCondition: '<S196>/IC' */
        localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
          CoreSubsys[ForEach_itr_cq].IC_FirstOutputTime = true;

        /* Start for Atomic SubSystem: '<S195>/BC Charge' */
        PneumaticsSystem_ASCharge_Start(&localB->CoreSubsys_pn[ForEach_itr].
          CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].BCCharge);

        /* End of Start for SubSystem: '<S195>/BC Charge' */

        /* Start for Atomic SubSystem: '<S195>/BC Isolate' */
        PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
          CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].BCIsolate);

        /* End of Start for SubSystem: '<S195>/BC Isolate' */

        /* Start for Atomic SubSystem: '<S195>/BC Vent' */
        PneumaticsSystem_ASVent_Start(&localB->CoreSubsys_pn[ForEach_itr].
          CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].BCVent);

        /* End of Start for SubSystem: '<S195>/BC Vent' */
        /* End of Start for SubSystem: '<S151>/AxleBrakeCylinder' */
      }

      /* End of Start for SubSystem: '<S148>/BrakeCylinderSystemPerAxle' */

      /* Start for If: '<S153>/If1' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        If1_ActiveSubsystem = -1;

      /* Start for IfAction SubSystem: '<S153>/If Action Subsystem5' */
      PneumaticsSystem_IfActionSubsystem5_Start(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem5);

      /* End of Start for SubSystem: '<S153>/If Action Subsystem5' */

      /* Start for IfAction SubSystem: '<S153>/If Action Subsystem4' */
      PneumaticsSystem_IfActionSubsystem5_Start(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem4);

      /* End of Start for SubSystem: '<S153>/If Action Subsystem4' */

      /* Start for IfAction SubSystem: '<S153>/If Action Subsystem6' */
      PneumaticsSystem_IfActionSubsystem5_Start(&localB->
        CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        IfActionSubsystem6);

      /* End of Start for SubSystem: '<S153>/If Action Subsystem6' */

      /* Start for InitialCondition: '<S210>/Initialise' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
        Initialise_FirstOutputTime_g = true;
    }

    /* End of Start for SubSystem: '<S121>/BrakingSystemPerBogie' */
    /* End of Start for SubSystem: '<S14>/BrakingSystem' */

    /* Start for Enabled SubSystem: '<S14>/SandingSystem' */
    /* Start for Iterator SubSystem: '<S122>/SandingSystemPerBogie' */
    for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
      /* Start for InitialCondition: '<S213>/Initialise' */
      localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a].
        Initialise_FirstOutputTime = true;
    }

    /* End of Start for SubSystem: '<S122>/SandingSystemPerBogie' */
    /* End of Start for SubSystem: '<S14>/SandingSystem' */

    /* Start for Enabled SubSystem: '<S17>/MainReservoir' */
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_d = 0.0;
    localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_f = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].P = 0.0;
    localB->CoreSubsys_pn[ForEach_itr].PressureSwitch = 0.0;

    /* Start for InitialCondition: '<S251>/IC' */
    localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_c = true;

    /* Start for Atomic SubSystem: '<S231>/MR Pipe Two Way Valve' */
    PneumaticsSystem_MRPipeTwoWayValve_Start(&localB->CoreSubsys_pn[ForEach_itr]
      .MRPipeTwoWayValve);

    /* End of Start for SubSystem: '<S231>/MR Pipe Two Way Valve' */

    /* Start for Atomic SubSystem: '<S231>/TimerOffDelay NoInit' */
    PneumaticsSystem_TimerOffDelayNoInit_Start(&localB->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit_d, &localDW->
      CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit_d);

    /* End of Start for SubSystem: '<S231>/TimerOffDelay NoInit' */

    /* Start for Atomic SubSystem: '<S231>/MR Vent Drain' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      MRVentDrain);

    /* End of Start for SubSystem: '<S231>/MR Vent Drain' */

    /* Start for Atomic SubSystem: '<S231>/MR Blowoff' */
    PneumaticsSystem_BSRVentDrain_Start(&localB->CoreSubsys_pn[ForEach_itr].
      MRBlowoff);

    /* End of Start for SubSystem: '<S231>/MR Blowoff' */

    /* Start for InitialCondition: '<S250>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_l = true;

    /* End of Start for SubSystem: '<S17>/MainReservoir' */

    /* Start for InitialCondition: '<S257>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime = true;

    /* Start for InitialCondition: '<S258>/Initialise' */
    localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_d = true;

    /* End of Start for SubSystem: '<S3>/PneumaticsSystem' */
  }

  /* End of Start for SubSystem: '<Root>/PneumaticsPerVehicle' */
}

/* Output and update for referenced model: 'PneumaticsSystem' */
void PneumaticsSystem(const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8],
                      const BD_PneumaticsSystem_Cfg_Vehicle
                      rtu_PneumaticsSystemVehicleConfig[8], const
                      BD_PneumaticsSystem_In_Vehicle
                      rtu_PneumaticsSystemVehicleInputs[8], const
                      BD_PneumaticsSystem_In_Overrides rtu_Overrides[8], const
                      BD_PneumaticsSystem_In_Vehicle_Faults rtu_Faults[8],
                      BD_PneumaticsSystem_Out_Vehicle
                      rty_PneumaticsSystemVehicleOut[8], B_PneumaticsSystem_c_T *
                      localB, DW_PneumaticsSystem_f_T *localDW, const
                      BD_PneumaticsSystem_Prm *rtp_Prm_PneumaticsSystem)
{
  /* local block i/o variables */
  BD_PneumaticsSystem_In_Vehicle
    rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0;
  real_T rtb_UnitDelay1;
  real_T rtb_P;
  real_T rtb_UnitDelay_i;
  real_T rtb_P_e;
  real_T rtb_UnitDelay_a;
  real_T rtb_UnitDelay_l;
  real_T rtb_BrakeCylinderControlPressure;
  real_T rtb_UnitDelay_g;
  real_T rtb_ImpSel_InsertedFor_BogieSupportedMass_at_outport_0;
  real_T rtb_ImpSel_InsertedFor_AirSuspensionIsolCock_at_outport_0;
  real_T rtb_Bias_p;
  real_T rtb_UnitDelay_lp;
  real_T rtb_UnitDelay_o;
  real_T rtb_UnitDelay_h;
  real_T rtb_UnitDelay1_oz;
  real_T rtb_PressureSwitch;
  real_T rtb_PressureSwitch_e;
  real_T rtb_Initialise_b;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator1_o;
  boolean_T rtb_LogicalOperator_n;
  boolean_T rtb_LogicalOperator1_a;
  boolean_T rtb_LogicalOperator5_k;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_LogicalOperator1_f;
  boolean_T rtb_LogicalOperator2_a;
  boolean_T rtb_LogicalOperator1_d;
  boolean_T rtb_LogicalOperator3_i;
  boolean_T rtb_LogicalOperator2_c;
  boolean_T rtb_LogicalOperator2_i;
  boolean_T rtb_LogicalOperator5_l;
  boolean_T rtb_Compare_np;
  boolean_T rtb_LogicalOperator2_m;
  boolean_T rtb_LogicalOperator3_by;
  boolean_T rtb_LogicalOperator6_e;
  boolean_T rtb_LogicalOperator5_p;
  boolean_T rtb_LogicalOperator3_b3;
  boolean_T rtb_LogicalOperator1_id;
  boolean_T rtb_LogicalOperator2_p;
  boolean_T rtb_LogicalOperator2_ce;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_a;
  int32_T ForEach_itr_au;
  int32_T ForEach_itr_cq;
  int32_T ForEach_itr_f;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_fz;
  int32_T ForEach_itr_j;
  int32_T ForEach_itr_e0;
  boolean_T rtb_ImpAsg_InsertedFor_Enabled_at_inport_0[8];
  real_T rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[8];
  real_T rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[8];
  real_T rtb_ImpAsg_InsertedFor_Orientation_at_inport_0[8];
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1CarLoadPressureLow;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2CarLoadPressureLow;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECULowRPressure;
  real_T rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1LoadPressureLow;
  real_T rtb_ImpAsg_InsertedFor_MRP_at_inport_0[8];
  real_T rtb_w1[8];
  real_T rtb_w2[8];
  real_T rtb_RTV;
  real_T rtb_RTV_ai;
  real_T rtb_PneumaticPressureRelease;
  boolean_T rtb_AND9;
  boolean_T rtb_IC;
  real_T rtb_SelReset;
  real_T rtb_MainReservoirPipePressureGauge;
  BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie
    rtb_ImpAsg_InsertedFor_Bogie_at_inport_0[2];
  BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie
    rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[2];
  BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie
    rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[2];
  real_T rtb_RTV_h;
  boolean_T rtb_FixPtRelationalOperator_d;
  boolean_T rtb_AND3;
  boolean_T rtb_AND5;
  real_T rtb_ImpAsg_InsertedFor_ASRToAS_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_BSRtoBogieBCFlow_at_inport_0[2];
  real_T rtb_SandingSystemIsolationCock[2];
  real_T rtb_RTV_f;
  real_T rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[2];
  real_T rtb_Divide;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_ImpAsg_InsertedFor_BSRtoBCFlow_at_inport_0[2];
  boolean_T rtb_AND6;
  boolean_T rtb_LogicalOperator40;
  boolean_T rtb_LogicalOperator40_j;
  boolean_T rtb_LogicalOperator40_e;
  boolean_T rtb_LogicalOperator40_l;
  boolean_T rtb_LogicalOperator40_o;
  real_T rtb_MinMass_jc;
  real_T rtb_DiscreteTransferFcn;
  real_T rtb_MinMass_os;
  real_T rtb_SelReset_n;
  real_T rtb_Sqrt;
  real_T rtb_P2C;
  real_T rtb_MinMass_f;
  boolean_T rtb_ImpAsg_InsertedFor_PneumaticCouplingState_at_inport_0[16];
  int32_T i;
  uint8_T b_idx_0;

  /* MATLAB Function: '<S2>/UpDnSel' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  localB->yUp[0] = 0.0;
  for (i = 0; i < 7; i++) {
    localB->yUp[i + 1] = localDW->UnitDelay_DSTATE[i];
    localB->yDn[i] = localDW->UnitDelay_DSTATE[i + 1];
  }

  localB->yDn[7] = 0.0;

  /* End of MATLAB Function: '<S2>/UpDnSel' */

  /* Outputs for Iterator SubSystem: '<S2>/Extract' incorporates:
   *  ForEach: '<S4>/For Each'
   */
  for (ForEach_itr_j = 0; ForEach_itr_j < 8; ForEach_itr_j++) {
    /* ForEachSliceAssignment generated from: '<S4>/PneumaticCouplingState' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/PneumaticsSystemVehicleInputs'
     *  Logic: '<S4>/Logical Operator'
     */
    rtb_ImpAsg_InsertedFor_PneumaticCouplingState_at_inport_0[ForEach_itr_j] =
      ((rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
        PhysicalSignals.PneumaticallyCoupled[0] != 0.0) &&
       (rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
        InputControlStates.UncouplingIsolationCock != 0.0));
    rtb_ImpAsg_InsertedFor_PneumaticCouplingState_at_inport_0[ForEach_itr_j + 8]
      = ((rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
          PhysicalSignals.PneumaticallyCoupled[1] != 0.0) &&
         (rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
          InputControlStates.UncouplingIsolationCock != 0.0));

    /* ForEachSliceAssignment generated from: '<S4>/End2Cock' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/PneumaticsSystemVehicleInputs'
     */
    rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[ForEach_itr_j] =
      rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
      InputControlStates.InterCarIsolationCockEnd2;

    /* ForEachSliceAssignment generated from: '<S4>/End1Cock' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/PneumaticsSystemVehicleInputs'
     */
    rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[ForEach_itr_j] =
      rtu_PneumaticsSystemVehicleInputs[ForEach_itr_j].
      InputControlStates.InterCarIsolationCockEnd1;

    /* ForEachSliceAssignment generated from: '<S4>/Orientation' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/CommonConfig'
     */
    rtb_ImpAsg_InsertedFor_Orientation_at_inport_0[ForEach_itr_j] =
      rtu_CommonVehicleConfig[ForEach_itr_j].Orientation;

    /* ForEachSliceAssignment generated from: '<S4>/Enabled' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/CommonConfig'
     */
    rtb_ImpAsg_InsertedFor_Enabled_at_inport_0[ForEach_itr_j] =
      rtu_CommonVehicleConfig[ForEach_itr_j].Enabled;
  }

  /* End of Outputs for SubSystem: '<S2>/Extract' */
  for (i = 0; i < 8; i++) {
    /* Product: '<S2>/Product' */
    rtb_MainReservoirPipePressureGauge = static_cast<real_T>
      (rtb_ImpAsg_InsertedFor_Enabled_at_inport_0[i]) *
      rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[i];

    /* Product: '<S2>/Product1' incorporates:
     *  Product: '<S2>/Product'
     */
    rtb_RTV_f = static_cast<real_T>(rtb_ImpAsg_InsertedFor_Enabled_at_inport_0[i])
      * rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[i];

    /* MATLAB Function: '<S5>/Orientation Swap' */
    if (rtb_ImpAsg_InsertedFor_Orientation_at_inport_0[i] > 1.5) {
      rtb_w1[i] = rtb_RTV_f;
      rtb_w2[i] = rtb_MainReservoirPipePressureGauge;
    } else {
      rtb_w1[i] = rtb_MainReservoirPipePressureGauge;
      rtb_w2[i] = rtb_RTV_f;
    }

    /* End of MATLAB Function: '<S5>/Orientation Swap' */

    /* Product: '<S2>/Product' */
    rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[i] =
      rtb_MainReservoirPipePressureGauge;

    /* Product: '<S2>/Product1' */
    rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[i] = rtb_RTV_f;
  }

  /* MATLAB Function: '<S2>/PipeConnections' incorporates:
   *  Selector: '<S2>/Head'
   *  Selector: '<S2>/Tail'
   */
  rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[0] = 0.0;
  for (i = 0; i < 7; i++) {
    rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[i + 1] = rtb_w2[i];
    rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[i] = rtb_w1[i + 1];
  }

  rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[7] = 0.0;
  for (i = 0; i < 8; i++) {
    localB->frontState[i] = 0.0;
    localB->rearState[i] = 0.0;
    if ((rtb_w1[i] == 1.0) &&
        rtb_ImpAsg_InsertedFor_PneumaticCouplingState_at_inport_0[i]) {
      if (rtb_ImpAsg_InsertedFor_End1Cock_at_inport_0[i] == 1.0) {
        localB->frontState[i] = 1.0;
      } else {
        localB->frontState[i] = 2.0;
      }
    }

    if ((rtb_w2[i] == 1.0) &&
        rtb_ImpAsg_InsertedFor_PneumaticCouplingState_at_inport_0[i + 8]) {
      if (rtb_ImpAsg_InsertedFor_End2Cock_at_inport_0[i] == 1.0) {
        localB->rearState[i] = 1.0;
      } else {
        localB->rearState[i] = 2.0;
      }
    }
  }

  /* End of MATLAB Function: '<S2>/PipeConnections' */

  /* Outputs for Iterator SubSystem: '<Root>/PneumaticsPerVehicle' incorporates:
   *  ForEach: '<S3>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S3>/PneumaticsInputs' */
    rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0 =
      rtu_PneumaticsSystemVehicleInputs[ForEach_itr];

    /* ForEachSliceSelector generated from: '<S3>/Overrides' */
    rtb_MainReservoirPipePressureGauge = rtu_Overrides[ForEach_itr].Reset;

    /* ForEachSliceSelector generated from: '<S3>/Faults' */
    rtb_RTV_f = rtu_Faults[ForEach_itr].BECU1ServiceBrakeFailure;
    rtb_P2C = rtu_Faults[ForEach_itr].BECU1EmergencyBrakeFailure;
    rtb_Sqrt = rtu_Faults[ForEach_itr].AirSuspensionBogie1Deflated;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure =
      rtu_Faults[ForEach_itr].BECU2EmergencyBrakeFailure;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied =
      rtu_Faults[ForEach_itr].BECU1BrakeNotApplied;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1CarLoadPressureLow =
      rtu_Faults[ForEach_itr].BECU1CarLoadPressureLow;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2CarLoadPressureLow =
      rtu_Faults[ForEach_itr].BECU2CarLoadPressureLow;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECULowRPressure =
      rtu_Faults[ForEach_itr].BECULowRPressure;
    rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1LoadPressureLow =
      rtu_Faults[ForEach_itr].BECU1LoadPressureLow;

    /* Outputs for Enabled SubSystem: '<S3>/PneumaticsSystem' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* ForEachSliceSelector generated from: '<S3>/CommonConfig' incorporates:
     *  Constant: '<S77>/Constant'
     *  ForEachSliceSelector generated from: '<S3>/PneumaticsConfig'
     */
    if (rtu_CommonVehicleConfig[ForEach_itr].Enabled) {
      localDW->CoreSubsys_pn[ForEach_itr].PneumaticsSystem_MODE = true;

      /* Saturate: '<S25>/Saturation' incorporates:
       *  Constant: '<S24>/pAtm2'
       */
      if (PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionReservoir_Volume >
          PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_e) {
        rtb_PressureSwitch_e =
          PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_e;
      } else if (PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionReservoir_Volume <
                 PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_k) {
        rtb_PressureSwitch_e =
          PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_k;
      } else {
        rtb_PressureSwitch_e =
          PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionReservoir_Volume;
      }

      /* End of Saturate: '<S25>/Saturation' */

      /* Fcn: '<S25>/RT // V' */
      rtb_RTV = 84102.72 / rtb_PressureSwitch_e;

      /* Product: '<S25>/MaxMass' incorporates:
       *  Constant: '<S24>/Constant'
       */
      rtb_PressureSwitch_e = (PneumaticsSystem_P.PAtm +
        PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionReservoir_MaxPressure) /
        rtb_RTV;

      /* Logic: '<S25>/Logical Operator' incorporates:
       *  ForEachSliceSelector generated from: '<S3>/Overrides'
       */
      rtb_AND9 = (rtu_Overrides[ForEach_itr].Reset != 0.0);

      /* InitialCondition: '<S27>/IC' */
      if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime) {
        localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime = false;
        rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_k;
      }

      /* End of InitialCondition: '<S27>/IC' */

      /* Saturate: '<S256>/Saturation' incorporates:
       *  Constant: '<S230>/MR Volume'
       */
      if (PneumaticsSystem_P.CoreSubsys_pn.MRVolume_Value >
          PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_mq) {
        rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_mq;
      } else if (PneumaticsSystem_P.CoreSubsys_pn.MRVolume_Value <
                 PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_ks) {
        rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_ks;
      } else {
        rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.MRVolume_Value;
      }

      /* End of Saturate: '<S256>/Saturation' */

      /* Fcn: '<S256>/RT // V' */
      rtb_RTV_ai = 84102.72 / rtb_MinMass_os;

      /* Product: '<S256>/MaxMass' incorporates:
       *  Constant: '<S230>/Constant'
       */
      rtb_PneumaticPressureRelease = (PneumaticsSystem_P.PAtm + 1.05E+6) /
        rtb_RTV_ai;

      /* Logic: '<S256>/Logical Operator' incorporates:
       *  ForEachSliceSelector generated from: '<S3>/Overrides'
       */
      rtb_IC = (rtu_Overrides[ForEach_itr].Reset != 0.0);

      /* InitialCondition: '<S273>/IC' */
      if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_k) {
        localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_k = false;
        rtb_IC = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_c;
      }

      /* End of InitialCondition: '<S273>/IC' */

      /* UnitDelay: '<S230>/Unit Delay1' */
      rtb_UnitDelay1 = localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE;

      /* Switch: '<S273>/SelReset' incorporates:
       *  Constant: '<S256>/Constant1'
       *  ForEachSliceSelector generated from: '<S3>/MRPDownPressure'
       *  ForEachSliceSelector generated from: '<S3>/MRPUpPressure'
       *  Product: '<S256>/ResetMass'
       *  SampleTimeMath: '<S273>/Weighted Sample Time'
       *  Sum: '<S255>/Add'
       *  Sum: '<S273>/Sum1'
       *  Switch: '<S256>/SelReset'
       *  UnitDelay: '<S17>/Unit Delay'
       *  UnitDelay: '<S273>/Unit Delay1'
       *  UnitDelay: '<S9>/Unit Delay'
       *  UnitDelay: '<S9>/Unit Delay1'
       *  UnitDelay: '<S9>/Unit Delay3'
       *
       * About '<S273>/Weighted Sample Time':
       *  y = u * K where K = ( w * Ts )
       */
      if (rtb_IC) {
        rtb_SelReset =
          (rtp_Prm_PneumaticsSystem->MainReservoirPipe.ResetPressure +
           PneumaticsSystem_P.PAtm) / rtb_RTV_ai;
      } else {
        /* Logic: '<S255>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/MRPUpConnection'
         */
        rtb_LogicalOperator_n = !(localB->frontState[ForEach_itr] != 0.0);

        /* Logic: '<S255>/Logical Operator1' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/MRPDownConnection'
         */
        rtb_LogicalOperator1_a = !(localB->rearState[ForEach_itr] != 0.0);

        /* Outputs for Atomic SubSystem: '<S255>/MRP to Downstream Connection' */
        PneumaticsSystem_MRPipeTwoWayValve(rtb_UnitDelay1, localB->
          yDn[ForEach_itr], rtb_LogicalOperator1_a, &localB->
          CoreSubsys_pn[ForEach_itr].MRPtoDownstreamConnection,
          &PneumaticsSystem_P.CoreSubsys_pn.MRPtoDownstreamConnection,
          PneumaticsSystem_P.CoreSubsys_pn.MRPtoDownstreamConnection_p_deadband);

        /* End of Outputs for SubSystem: '<S255>/MRP to Downstream Connection' */

        /* Outputs for Atomic SubSystem: '<S255>/MRP to Upstream Connection' */
        PneumaticsSystem_MRPipeTwoWayValve(rtb_UnitDelay1, localB->
          yUp[ForEach_itr], rtb_LogicalOperator_n, &localB->
          CoreSubsys_pn[ForEach_itr].MRPtoUpstreamConnection,
          &PneumaticsSystem_P.CoreSubsys_pn.MRPtoUpstreamConnection,
          PneumaticsSystem_P.CoreSubsys_pn.MRPtoUpstreamConnection_p_deadband);

        /* End of Outputs for SubSystem: '<S255>/MRP to Upstream Connection' */
        rtb_SelReset = ((((((0.0 - localB->CoreSubsys_pn[ForEach_itr].
                             MRPtoUpstreamConnection.Add) -
                            localB->CoreSubsys_pn[ForEach_itr].
                            MRPtoDownstreamConnection.Add) -
                           localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE)
                          - localDW->CoreSubsys_pn[ForEach_itr].
                          UnitDelay_DSTATE_k) - localDW->
                         CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_k) -
                        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay3_DSTATE) *
          PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_p0 +
          localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_a;
      }

      /* End of Switch: '<S273>/SelReset' */

      /* Switch: '<S274>/Switch2' incorporates:
       *  RelationalOperator: '<S274>/LowerRelop1'
       */
      if (!(rtb_SelReset > rtb_PneumaticPressureRelease)) {
        /* Product: '<S256>/MinMass' incorporates:
         *  Constant: '<S230>/pAtm'
         */
        rtb_PneumaticPressureRelease = PneumaticsSystem_P.PAtm / rtb_RTV_ai;

        /* Switch: '<S274>/Switch' incorporates:
         *  RelationalOperator: '<S274>/UpperRelop'
         */
        if (!(rtb_SelReset < rtb_PneumaticPressureRelease)) {
          rtb_PneumaticPressureRelease = rtb_SelReset;
        }

        /* End of Switch: '<S274>/Switch' */
      }

      /* End of Switch: '<S274>/Switch2' */

      /* Product: '<S256>/ConvertToPressure' */
      rtb_P = rtb_PneumaticPressureRelease * rtb_RTV_ai;

      /* UnitDelay: '<S24>/Unit Delay' */
      rtb_UnitDelay_i = localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_g;

      /* Logic: '<S26>/Logical Operator3' incorporates:
       *  Constant: '<S32>/Constant'
       *  Logic: '<S26>/Logical Operator1'
       *  RelationalOperator: '<S32>/Compare'
       */
      rtb_LogicalOperator3 =
        ((!(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionReservoirIsolationCock
            != 0.0)) || (rtb_UnitDelay_i >=
                         PneumaticsSystem_P.CoreSubsys_pn.CompareToConstant_const_a));

      /* Outputs for Atomic SubSystem: '<S26>/BSR Charge' */
      PneumaticsSystem_BSRVentDrain(rtb_P, rtb_UnitDelay_i, rtb_LogicalOperator3,
        &localB->CoreSubsys_pn[ForEach_itr].BSRCharge,
        &PneumaticsSystem_P.CoreSubsys_pn.BSRCharge,
        PneumaticsSystem_P.CoreSubsys_pn.BSRCharge_p_deadband_d);

      /* End of Outputs for SubSystem: '<S26>/BSR Charge' */

      /* Switch: '<S27>/SelReset' incorporates:
       *  Constant: '<S25>/Constant1'
       *  Constant: '<S26>/Constant'
       *  Product: '<S25>/ResetMass'
       *  SampleTimeMath: '<S27>/Weighted Sample Time'
       *  Sum: '<S26>/Add'
       *  Sum: '<S27>/Sum1'
       *  Switch: '<S25>/SelReset'
       *  UnitDelay: '<S27>/Unit Delay1'
       *  UnitDelay: '<S9>/Unit Delay5'
       *
       * About '<S27>/Weighted Sample Time':
       *  y = u * K where K = ( w * Ts )
       */
      if (rtb_AND9) {
        rtb_RTV_ai =
          (PneumaticsSystem_P.CoreSubsys_pn.AirSuspensionReservoir_ResetPressure
           + PneumaticsSystem_P.PAtm) / rtb_RTV;
      } else {
        /* Logic: '<S26>/Logical Operator2' incorporates:
         *  Constant: '<S10>/Constant'
         */
        rtb_LogicalOperator2_ce =
          !(PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_o != 0.0);

        /* Outputs for Atomic SubSystem: '<S26>/BSR Vent Drain' */
        PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_i, PneumaticsSystem_P.PAtm,
          rtb_LogicalOperator2_ce, &localB->CoreSubsys_pn[ForEach_itr].
          BSRVentDrain, &PneumaticsSystem_P.CoreSubsys_pn.BSRVentDrain,
          PneumaticsSystem_P.CoreSubsys_pn.BSRVentDrain_p_deadband);

        /* End of Outputs for SubSystem: '<S26>/BSR Vent Drain' */

        /* Outputs for Atomic SubSystem: '<S26>/BSR Vent IC' */
        PneumaticsSystem_BSRVentIC(rtb_UnitDelay_i, PneumaticsSystem_P.PAtm,
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionReservoirIsolationCock,
          &localB->CoreSubsys_pn[ForEach_itr].BSRVentIC,
          &PneumaticsSystem_P.CoreSubsys_pn.BSRVentIC,
          PneumaticsSystem_P.CoreSubsys_pn.BSRVentIC_p_deadband);

        /* End of Outputs for SubSystem: '<S26>/BSR Vent IC' */
        rtb_RTV_ai = (((localB->CoreSubsys_pn[ForEach_itr].BSRCharge.FlowNoflow
                        - localB->CoreSubsys_pn[ForEach_itr].
                        BSRVentIC.FlowNoflow) - localB->
                       CoreSubsys_pn[ForEach_itr].BSRVentDrain.FlowNoflow) -
                      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay5_DSTATE) *
          PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt +
          localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_e;
      }

      /* End of Switch: '<S27>/SelReset' */

      /* Switch: '<S28>/Switch2' incorporates:
       *  RelationalOperator: '<S28>/LowerRelop1'
       */
      if (rtb_RTV_ai > rtb_PressureSwitch_e) {
        rtb_RTV_ai = rtb_PressureSwitch_e;
      } else {
        /* Product: '<S25>/MinMass' incorporates:
         *  Constant: '<S24>/pAtm'
         */
        rtb_SelReset = PneumaticsSystem_P.PAtm / rtb_RTV;

        /* Switch: '<S28>/Switch' incorporates:
         *  RelationalOperator: '<S28>/UpperRelop'
         */
        if (rtb_RTV_ai < rtb_SelReset) {
          rtb_RTV_ai = rtb_SelReset;
        }

        /* End of Switch: '<S28>/Switch' */
      }

      /* End of Switch: '<S28>/Switch2' */

      /* Product: '<S25>/ConvertToPressure' */
      rtb_P_e = rtb_RTV_ai * rtb_RTV;

      /* Logic: '<S37>/Logical Operator' incorporates:
       *  Constant: '<S37>/Aux Reservoir Pressure available'
       *  Constant: '<S37>/Brake Supply Reservoir Pressure available'
       *  Constant: '<S37>/Main Reservoir Pressure available'
       *  Logic: '<S37>/Logical Operator1'
       *  Logic: '<S37>/Logical Operator10'
       *  Logic: '<S37>/Logical Operator11'
       *  Logic: '<S37>/Logical Operator12'
       *  Logic: '<S37>/Logical Operator13'
       *  Logic: '<S37>/Logical Operator14'
       *  Logic: '<S37>/Logical Operator15'
       *  Logic: '<S37>/Logical Operator16'
       *  Logic: '<S37>/Logical Operator2'
       *  Logic: '<S37>/Logical Operator3'
       *  Logic: '<S37>/Logical Operator4'
       *  Logic: '<S37>/Logical Operator5'
       *  Logic: '<S37>/Logical Operator6'
       *  Logic: '<S37>/Logical Operator7'
       *  Logic: '<S37>/Logical Operator8'
       *  Logic: '<S37>/Logical Operator9'
       *  RelationalOperator: '<S40>/FixPt Relational Operator'
       *  RelationalOperator: '<S41>/FixPt Relational Operator'
       *  RelationalOperator: '<S42>/FixPt Relational Operator'
       *  RelationalOperator: '<S43>/FixPt Relational Operator'
       *  RelationalOperator: '<S44>/FixPt Relational Operator'
       *  RelationalOperator: '<S45>/FixPt Relational Operator'
       *  RelationalOperator: '<S46>/FixPt Relational Operator'
       *  RelationalOperator: '<S47>/FixPt Relational Operator'
       *  RelationalOperator: '<S48>/FixPt Relational Operator'
       *  RelationalOperator: '<S49>/FixPt Relational Operator'
       *  RelationalOperator: '<S50>/FixPt Relational Operator'
       *  RelationalOperator: '<S51>/FixPt Relational Operator'
       *  RelationalOperator: '<S52>/FixPt Relational Operator'
       *  RelationalOperator: '<S53>/FixPt Relational Operator'
       *  RelationalOperator: '<S54>/FixPt Relational Operator'
       *  RelationalOperator: '<S55>/FixPt Relational Operator'
       *  UnitDelay: '<S40>/Delay Input1'
       *  UnitDelay: '<S41>/Delay Input1'
       *  UnitDelay: '<S42>/Delay Input1'
       *  UnitDelay: '<S43>/Delay Input1'
       *  UnitDelay: '<S44>/Delay Input1'
       *  UnitDelay: '<S45>/Delay Input1'
       *  UnitDelay: '<S46>/Delay Input1'
       *  UnitDelay: '<S47>/Delay Input1'
       *  UnitDelay: '<S48>/Delay Input1'
       *  UnitDelay: '<S49>/Delay Input1'
       *  UnitDelay: '<S50>/Delay Input1'
       *  UnitDelay: '<S51>/Delay Input1'
       *  UnitDelay: '<S52>/Delay Input1'
       *  UnitDelay: '<S53>/Delay Input1'
       *  UnitDelay: '<S54>/Delay Input1'
       *  UnitDelay: '<S55>/Delay Input1'
       */
      rtb_LogicalOperator =
        (((PneumaticsSystem_P.CoreSubsys_pn.AuxReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornLowIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.AuxReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornHighIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_d)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeSupplyReservoirIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_n)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainReservoirIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_a)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie1
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_dh)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie2
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_g)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie1
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie2
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie1
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_i)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie2
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_nm)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainAirSupplyIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b2)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.InterCarIsolationCockEnd1
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_da)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.InterCarIsolationCockEnd2
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c4)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.UncouplingIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_p)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value_i
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.EPIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_f)) ||
         ((PneumaticsSystem_P.CoreSubsys_pn.MainReservoirPressureavailable_Value
           != 0.0) &&
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionReservoirIsolationCock
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_fx)));

      /* Outputs for Atomic SubSystem: '<S11>/TimerOffDelay NoInit1' */
      PneumaticsSystem_TimerOffDelayNoInit(rtb_LogicalOperator,
        &localB->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1,
        &localDW->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1,
        &PneumaticsSystem_P.CoreSubsys_pn.TimerOffDelayNoInit1);

      /* End of Outputs for SubSystem: '<S11>/TimerOffDelay NoInit1' */

      /* UnitDelay: '<S36>/Delay Input1' */
      rtb_PressureSwitch_e = localDW->CoreSubsys_pn[ForEach_itr].
        DelayInput1_DSTATE_ia;

      /* Logic: '<S11>/Logical Operator1' incorporates:
       *  Constant: '<S11>/Brake Supply Reservoir Pressure available'
       *  RelationalOperator: '<S36>/FixPt Relational Operator'
       */
      rtb_LogicalOperator1_o =
        ((PneumaticsSystem_P.CoreSubsys_pn.BrakeSupplyReservoirPressureavailable_Value
          != 0.0) &&
         (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.NoEmergencyBrakeValve
          < rtb_PressureSwitch_e));

      /* Outputs for Atomic SubSystem: '<S11>/TimerOffDelay NoInit' */
      PneumaticsSystem_TimerOffDelayNoInit(rtb_LogicalOperator1_o,
        &localB->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit,
        &localDW->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit,
        &PneumaticsSystem_P.CoreSubsys_pn.TimerOffDelayNoInit);

      /* End of Outputs for SubSystem: '<S11>/TimerOffDelay NoInit' */

      /* Outputs for Enabled SubSystem: '<S12>/AuxSystem' incorporates:
       *  EnablePort: '<S58>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].Equipment.HasPantograph
          > 0.0) {
        /* InitialCondition: '<S66>/Initialise' incorporates:
         *  Constant: '<S66>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_a) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_a =
            false;
          rtb_SelReset = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value;
        } else {
          rtb_SelReset = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value;
        }

        /* End of InitialCondition: '<S66>/Initialise' */

        /* Saturate: '<S64>/Saturation' incorporates:
         *  Constant: '<S60>/pAtm2'
         */
        if (rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat;
        } else if (rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat;
        } else {
          rtb_Initialise_b = rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.Volume;
        }

        /* End of Saturate: '<S64>/Saturation' */

        /* Fcn: '<S64>/RT // V' */
        rtb_DiscreteTransferFcn = 84102.72 / rtb_Initialise_b;

        /* Product: '<S64>/MaxMass' incorporates:
         *  Constant: '<S60>/Constant'
         */
        rtb_Initialise_b = (PneumaticsSystem_P.PAtm +
                            rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.MaxPressure)
          / rtb_DiscreteTransferFcn;

        /* Logic: '<S64>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Overrides'
         */
        rtb_AND9 = (rtu_Overrides[ForEach_itr].Reset != 0.0);

        /* InitialCondition: '<S67>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_a) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_a = false;
          rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.IC_Value;
        }

        /* End of InitialCondition: '<S67>/IC' */

        /* UnitDelay: '<S60>/Unit Delay' */
        rtb_UnitDelay_o = localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_e;

        /* Logic: '<S65>/Logical Operator3' */
        rtb_LogicalOperator3_by =
          !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AuxiliaryReservoirIsolationCock
            != 0.0);

        /* Outputs for Atomic SubSystem: '<S65>/AR Charge from MRP' */
        PneumaticsSystem_BSRVentDrain(rtb_P, rtb_UnitDelay_o,
          rtb_LogicalOperator3_by, &localB->CoreSubsys_pn[ForEach_itr].
          ARChargefromMRP, &PneumaticsSystem_P.CoreSubsys_pn.ARChargefromMRP,
          PneumaticsSystem_P.CoreSubsys_pn.ARChargefromMRP_p_deadband);

        /* End of Outputs for SubSystem: '<S65>/AR Charge from MRP' */

        /* Relay: '<S65>/Overpressure' */
        localDW->CoreSubsys_pn[ForEach_itr].Overpressure_Mode_c =
          ((rtb_UnitDelay_o >=
            rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.BlowOffONPressure +
            PneumaticsSystem_P.PAtm) || ((!(rtb_UnitDelay_o <=
              rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.BlowOffOFFPressure +
              PneumaticsSystem_P.PAtm)) && localDW->CoreSubsys_pn[ForEach_itr].
            Overpressure_Mode_c));

        /* Switch: '<S67>/SelReset' incorporates:
         *  Constant: '<S64>/Constant1'
         *  Constant: '<S65>/Constant'
         *  Product: '<S64>/ResetMass'
         *  Relay: '<S65>/Overpressure'
         *  SampleTimeMath: '<S67>/Weighted Sample Time'
         *  Sum: '<S58>/Add'
         *  Sum: '<S65>/Add'
         *  Sum: '<S67>/Sum1'
         *  Switch: '<S64>/SelReset'
         *  UnitDelay: '<S58>/Unit Delay'
         *  UnitDelay: '<S58>/Unit Delay1'
         *  UnitDelay: '<S67>/Unit Delay1'
         *
         * About '<S67>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_AND9) {
          rtb_RTV = (rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.ResetPressure
                     + PneumaticsSystem_P.PAtm) / rtb_DiscreteTransferFcn;
        } else {
          if (localDW->CoreSubsys_pn[ForEach_itr].Overpressure_Mode_c) {
            /* Relay: '<S65>/Overpressure' */
            rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.Overpressure_YOn;
          } else {
            /* Relay: '<S65>/Overpressure' */
            rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.Overpressure_YOff;
          }

          /* Logic: '<S65>/Logical Operator1' */
          rtb_LogicalOperator1_id = !(rtb_MinMass_os != 0.0);

          /* Logic: '<S65>/Logical Operator2' */
          rtb_LogicalOperator2_p =
            !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AuxiliaryReservoirDrainCock
              != 0.0);

          /* Outputs for Atomic SubSystem: '<S65>/AR Vent Drain' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_o, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator2_p, &localB->CoreSubsys_pn[ForEach_itr].
            ARVentDrain, &PneumaticsSystem_P.CoreSubsys_pn.ARVentDrain,
            PneumaticsSystem_P.CoreSubsys_pn.ARVentDrain_p_deadband);

          /* End of Outputs for SubSystem: '<S65>/AR Vent Drain' */

          /* Outputs for Atomic SubSystem: '<S65>/AR Blowoff' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_o, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator1_id, &localB->CoreSubsys_pn[ForEach_itr].
            ARBlowoff, &PneumaticsSystem_P.CoreSubsys_pn.ARBlowoff,
            PneumaticsSystem_P.CoreSubsys_pn.ARBlowoff_p_deadband);

          /* End of Outputs for SubSystem: '<S65>/AR Blowoff' */

          /* Switch: '<S65>/Switch1' incorporates:
           *  Constant: '<S65>/Aux Compressor Flow Rate'
           *  Constant: '<S65>/Constant'
           *  Product: '<S65>/Product'
           */
          if (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AuxiliaryCompressorIsolationCock
              > PneumaticsSystem_P.CoreSubsys_pn.Switch1_Threshold) {
            rtb_MinMass_os =
              rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.CompressorMassFlowRate
              * rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.AuxiliaryCompressorOn;
          } else {
            rtb_MinMass_os = 0.0;
          }

          /* End of Switch: '<S65>/Switch1' */
          rtb_RTV = ((((rtb_MinMass_os + localB->CoreSubsys_pn[ForEach_itr].
                        ARChargefromMRP.FlowNoflow) - localB->
                       CoreSubsys_pn[ForEach_itr].ARBlowoff.FlowNoflow) -
                      localB->CoreSubsys_pn[ForEach_itr].ARVentDrain.FlowNoflow)
                     - (localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_f +
                        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_c))
            * PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_o +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_m;
        }

        /* End of Switch: '<S67>/SelReset' */

        /* Switch: '<S68>/Switch2' incorporates:
         *  RelationalOperator: '<S68>/LowerRelop1'
         */
        if (rtb_RTV > rtb_Initialise_b) {
          rtb_RTV = rtb_Initialise_b;
        } else {
          /* Product: '<S64>/MinMass' incorporates:
           *  Constant: '<S60>/pAtm'
           */
          rtb_MinMass_jc = PneumaticsSystem_P.PAtm / rtb_DiscreteTransferFcn;

          /* Switch: '<S68>/Switch' incorporates:
           *  RelationalOperator: '<S68>/UpperRelop'
           */
          if (rtb_RTV < rtb_MinMass_jc) {
            rtb_RTV = rtb_MinMass_jc;
          }

          /* End of Switch: '<S68>/Switch' */
        }

        /* End of Switch: '<S68>/Switch2' */

        /* Product: '<S64>/ConvertToPressure' */
        localB->CoreSubsys_pn[ForEach_itr].P_d = rtb_RTV *
          rtb_DiscreteTransferFcn;

        /* Switch: '<S63>/Initialise' incorporates:
         *  Bias: '<S60>/Bias'
         *  Constant: '<S63>/Constant'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_d >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold) {
          /* Switch: '<S66>/ExternalIC' incorporates:
           *  Bias: '<S60>/Bias'
           *  Constant: '<S63>/InitialConditionValue'
           */
          if (rtb_SelReset >
              PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold) {
            rtb_Initialise_b =
              rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.SwitchONPressure;
          } else {
            rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_d +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S66>/ExternalIC' */
        } else {
          rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_d +
            -PneumaticsSystem_P.PAtm;
        }

        /* End of Switch: '<S63>/Initialise' */

        /* Relay: '<S63>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_c =
          ((rtb_Initialise_b >=
            rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.SwitchONPressure) || ((
             !(rtb_Initialise_b <=
               rtp_Prm_PneumaticsSystem->AuxiliaryReservoir.SwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_c));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_c) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_e =
            PneumaticsSystem_P.CoreSubsys_pn.ARPressureSwitch12_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_e =
            PneumaticsSystem_P.CoreSubsys_pn.ARPressureSwitch12_OffOutputValue;
        }

        /* End of Relay: '<S63>/PressureSwitch' */

        /* Saturate: '<S84>/Saturation' incorporates:
         *  Constant: '<S75>/pAtm3'
         */
        if (rtp_Prm_PneumaticsSystem->Pantograph.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_a) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_a;
        } else if (rtp_Prm_PneumaticsSystem->Pantograph.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_p) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_p;
        } else {
          rtb_Initialise_b = rtp_Prm_PneumaticsSystem->Pantograph.Volume;
        }

        /* End of Saturate: '<S84>/Saturation' */

        /* Fcn: '<S84>/RT // V' */
        rtb_MinMass_jc = 84102.72 / rtb_Initialise_b;

        /* Product: '<S84>/MaxMass' incorporates:
         *  Constant: '<S61>/Constant'
         *  Constant: '<S75>/Constant1'
         *  Product: '<S82>/MaxMass'
         */
        rtb_Divide = PneumaticsSystem_P.PAtm +
          rtp_Prm_PneumaticsSystem->Pantograph.MaxPressure;
        rtb_Initialise_b = rtb_Divide / rtb_MinMass_jc;

        /* RelationalOperator: '<S76>/FixPt Relational Operator' incorporates:
         *  UnitDelay: '<S76>/Delay Input1'
         */
        rtb_FixPtRelationalOperator_d =
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ORDPlunger
           < localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ii);

        /* Logic: '<S84>/Logical Operator' incorporates:
         *  Constant: '<S75>/Constant2'
         */
        rtb_AND9 = (PneumaticsSystem_P.CoreSubsys_pn.Constant2_Value ||
                    rtb_FixPtRelationalOperator_d);

        /* InitialCondition: '<S85>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ax) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ax = false;
          rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_l;
        }

        /* End of InitialCondition: '<S85>/IC' */

        /* UnitDelay: '<S61>/Unit Delay' */
        rtb_UnitDelay_h = localDW->CoreSubsys_pn[ForEach_itr].
          UnitDelay_DSTATE_eb;

        /* CombinatorialLogic: '<S99>/Logic' incorporates:
         *  Logic: '<S81>/Logical Operator'
         *  Memory: '<S99>/Memory'
         *  RelationalOperator: '<S98>/FixPt Relational Operator'
         *  UnitDelay: '<S61>/Unit Delay1'
         *  UnitDelay: '<S98>/Delay Input1'
         */
        i = static_cast<int32_T>(((((static_cast<uint32_T>
          (((localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_ks != 0.0) &&
            (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographEmergencyValve
             != 0.0))) << 1) +
          (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographRaiseValve
           != localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_m)) << 1) +
          localDW->CoreSubsys_pn[ForEach_itr].Memory_PreviousInput));

        /* Logic: '<S77>/Logical Operator6' incorporates:
         *  CombinatorialLogic: '<S99>/Logic'
         *  ForEachSliceSelector generated from: '<S3>/Faults'
         *  Logic: '<S77>/Logical Operator'
         */
        rtb_LogicalOperator6_e =
          ((!PneumaticsSystem_P.CoreSubsys_pn.Logic_table[static_cast<uint32_T>
            (i)]) && (!(rtu_Faults[ForEach_itr].PantographPipeLowPressure != 0.0))
           && (!(rtu_Faults[ForEach_itr].ORDIntervention != 0.0)));

        /* Outputs for Atomic SubSystem: '<S77>/PC Vent Emer' */
        PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_h, PneumaticsSystem_P.PAtm,
          rtb_LogicalOperator6_e, &localB->CoreSubsys_pn[ForEach_itr].PCVentEmer,
          &PneumaticsSystem_P.CoreSubsys_pn.PCVentEmer,
          PneumaticsSystem_P.CoreSubsys_pn.PCVentEmer_p_deadband);

        /* End of Outputs for SubSystem: '<S77>/PC Vent Emer' */

        /* Switch: '<S85>/SelReset' incorporates:
         *  Constant: '<S77>/Constant'
         *  ForEachSliceSelector generated from: '<S3>/Faults'
         *  Product: '<S77>/Product'
         *  Product: '<S84>/ResetMass'
         *  SampleTimeMath: '<S85>/Weighted Sample Time'
         *  Sum: '<S85>/Sum1'
         *  UnitDelay: '<S85>/Unit Delay1'
         *
         * About '<S85>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_AND9) {
          /* Switch: '<S84>/SelReset' incorporates:
           *  Constant: '<S75>/Constant2'
           *  Constant: '<S75>/pAtm1'
           *  Constant: '<S84>/Constant1'
           *  Logic: '<S84>/Logical Operator1'
           *  Logic: '<S84>/Logical Operator2'
           */
          if (rtb_FixPtRelationalOperator_d &&
              (!PneumaticsSystem_P.CoreSubsys_pn.Constant2_Value)) {
            rtb_DiscreteTransferFcn = PneumaticsSystem_P.PAtm;
          } else {
            rtb_DiscreteTransferFcn = PneumaticsSystem_P.PAtm +
              rtp_Prm_PneumaticsSystem->Pantograph.ResetPressure;
          }

          /* End of Switch: '<S84>/SelReset' */
          rtb_SelReset = rtb_DiscreteTransferFcn / rtb_MinMass_jc;
        } else {
          rtb_SelReset = localB->CoreSubsys_pn[ForEach_itr].
            PCVentEmer.FlowNoflow * rtu_Faults[ForEach_itr].ORDIntervention *
            PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_i +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_g;
        }

        /* End of Switch: '<S85>/SelReset' */

        /* Switch: '<S86>/Switch2' incorporates:
         *  RelationalOperator: '<S86>/LowerRelop1'
         */
        if (rtb_SelReset > rtb_Initialise_b) {
          rtb_SelReset = rtb_Initialise_b;
        } else {
          /* Product: '<S84>/MinMass' incorporates:
           *  Constant: '<S75>/pAtm1'
           */
          rtb_DiscreteTransferFcn = PneumaticsSystem_P.PAtm / rtb_MinMass_jc;

          /* Switch: '<S86>/Switch' incorporates:
           *  RelationalOperator: '<S86>/UpperRelop'
           */
          if (rtb_SelReset < rtb_DiscreteTransferFcn) {
            rtb_SelReset = rtb_DiscreteTransferFcn;
          }

          /* End of Switch: '<S86>/Switch' */
        }

        /* End of Switch: '<S86>/Switch2' */

        /* Saturate: '<S82>/Saturation' incorporates:
         *  Constant: '<S61>/pAtm2'
         */
        if (rtp_Prm_PneumaticsSystem->Pantograph.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_b) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_b;
        } else if (rtp_Prm_PneumaticsSystem->Pantograph.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_n) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_n;
        } else {
          rtb_Initialise_b = rtp_Prm_PneumaticsSystem->Pantograph.Volume;
        }

        /* End of Saturate: '<S82>/Saturation' */

        /* Fcn: '<S82>/RT // V' */
        rtb_RTV_h = 84102.72 / rtb_Initialise_b;

        /* Product: '<S82>/MaxMass' */
        rtb_Initialise_b = rtb_Divide / rtb_RTV_h;

        /* Logic: '<S83>/Logical Operator33' incorporates:
         *  Logic: '<S83>/NOT'
         *  UnitDelay: '<S83>/Unit Delay1'
         */
        rtb_FixPtRelationalOperator_d =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographRaiseValve
            != 0.0) && (!localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_j));

        /* Logic: '<S82>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Overrides'
         */
        rtb_AND9 = ((rtu_Overrides[ForEach_itr].Reset != 0.0) ||
                    rtb_FixPtRelationalOperator_d);

        /* InitialCondition: '<S100>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ak) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_ak = false;
          rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_g;
        }

        /* End of InitialCondition: '<S100>/IC' */

        /* Logic: '<S77>/Logical Operator5' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Faults'
         *  Logic: '<S77>/Logical Operator1'
         */
        rtb_LogicalOperator5_p =
          ((!(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.PantographAirSupplyIsolationCock
              != 0.0)) ||
           (!(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographRaiseValve
              != 0.0)) || (rtu_Faults[ForEach_itr].ORDIntervention != 0.0));

        /* Outputs for Atomic SubSystem: '<S77>/AR Charge' */
        PneumaticsSystem_BSRVentDrain(localB->CoreSubsys_pn[ForEach_itr].P_d,
          rtb_UnitDelay_h, rtb_LogicalOperator5_p, &localB->
          CoreSubsys_pn[ForEach_itr].ARCharge,
          &PneumaticsSystem_P.CoreSubsys_pn.ARCharge,
          PneumaticsSystem_P.CoreSubsys_pn.ARCharge_p_deadband);

        /* End of Outputs for SubSystem: '<S77>/AR Charge' */

        /* Switch: '<S100>/SelReset' incorporates:
         *  Constant: '<S77>/Constant'
         *  Product: '<S82>/ResetMass'
         *  SampleTimeMath: '<S100>/Weighted Sample Time'
         *  Sum: '<S100>/Sum1'
         *  Sum: '<S77>/Add'
         *  UnitDelay: '<S100>/Unit Delay1'
         *
         * About '<S100>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_AND9) {
          /* Switch: '<S82>/SelReset' incorporates:
           *  Constant: '<S82>/Constant1'
           *  ForEachSliceSelector generated from: '<S3>/Overrides'
           *  Logic: '<S82>/Logical Operator1'
           *  Logic: '<S82>/Logical Operator2'
           *  Switch: '<S83>/Switch'
           */
          if (rtb_FixPtRelationalOperator_d && (!(rtu_Overrides[ForEach_itr].
                Reset != 0.0))) {
            rtb_DiscreteTransferFcn = localB->CoreSubsys_pn[ForEach_itr].P_d;
          } else {
            rtb_DiscreteTransferFcn = PneumaticsSystem_P.PAtm +
              rtp_Prm_PneumaticsSystem->Pantograph.ResetPressure;
          }

          /* End of Switch: '<S82>/SelReset' */
          rtb_DiscreteTransferFcn /= rtb_RTV_h;
        } else {
          /* Outputs for Atomic SubSystem: '<S77>/PC Vent Isol' */
          PneumaticsSystem_BSRVentIC(rtb_UnitDelay_h, PneumaticsSystem_P.PAtm,
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.PantographAirSupplyIsolationCock,
            &localB->CoreSubsys_pn[ForEach_itr].PCVentIsol,
            &PneumaticsSystem_P.CoreSubsys_pn.PCVentIsol,
            PneumaticsSystem_P.CoreSubsys_pn.PCVentIsol_p_deadband);

          /* End of Outputs for SubSystem: '<S77>/PC Vent Isol' */

          /* Outputs for Atomic SubSystem: '<S77>/PC Vent Control' */
          PneumaticsSystem_BSRVentIC(rtb_UnitDelay_h, PneumaticsSystem_P.PAtm,
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographRaiseValve,
            &localB->CoreSubsys_pn[ForEach_itr].PCVentControl,
            &PneumaticsSystem_P.CoreSubsys_pn.PCVentControl,
            PneumaticsSystem_P.CoreSubsys_pn.PCVentControl_p_deadband);

          /* End of Outputs for SubSystem: '<S77>/PC Vent Control' */
          rtb_DiscreteTransferFcn = (((localB->CoreSubsys_pn[ForEach_itr].
            ARCharge.FlowNoflow - localB->CoreSubsys_pn[ForEach_itr].
            PCVentControl.FlowNoflow) - localB->CoreSubsys_pn[ForEach_itr].
            PCVentEmer.FlowNoflow) - localB->CoreSubsys_pn[ForEach_itr].
            PCVentIsol.FlowNoflow) *
            PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_c +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_mr;
        }

        /* End of Switch: '<S100>/SelReset' */

        /* Switch: '<S101>/Switch2' incorporates:
         *  RelationalOperator: '<S101>/LowerRelop1'
         */
        if (rtb_DiscreteTransferFcn > rtb_Initialise_b) {
          rtb_DiscreteTransferFcn = rtb_Initialise_b;
        } else {
          /* Product: '<S82>/MinMass' incorporates:
           *  Constant: '<S61>/pAtm'
           */
          rtb_MinMass_os = PneumaticsSystem_P.PAtm / rtb_RTV_h;

          /* Switch: '<S101>/Switch' incorporates:
           *  RelationalOperator: '<S101>/UpperRelop'
           */
          if (rtb_DiscreteTransferFcn < rtb_MinMass_os) {
            rtb_DiscreteTransferFcn = rtb_MinMass_os;
          }

          /* End of Switch: '<S101>/Switch' */
        }

        /* End of Switch: '<S101>/Switch2' */

        /* Product: '<S82>/ConvertToPressure' */
        localB->CoreSubsys_pn[ForEach_itr].P_e = rtb_DiscreteTransferFcn *
          rtb_RTV_h;

        /* InitialCondition: '<S96>/Initialise' incorporates:
         *  Constant: '<S96>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_g) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_g =
            false;
          rtb_RTV_h = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_f;
        } else {
          rtb_RTV_h = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_f;
        }

        /* End of InitialCondition: '<S96>/Initialise' */

        /* Switch: '<S79>/Initialise' incorporates:
         *  Bias: '<S61>/Bias1'
         *  Constant: '<S79>/Constant'
         *  Product: '<S84>/ConvertToPressure'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_h >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_l) {
          /* Switch: '<S96>/ExternalIC' incorporates:
           *  Bias: '<S61>/Bias1'
           *  Constant: '<S79>/InitialConditionValue'
           *  Product: '<S84>/ConvertToPressure'
           */
          if (rtb_RTV_h >
              PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_j) {
            rtb_Initialise_b =
              rtp_Prm_PneumaticsSystem->Pantograph.ORDSwitchONPressure;
          } else {
            rtb_Initialise_b = rtb_SelReset * rtb_MinMass_jc +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S96>/ExternalIC' */
        } else {
          rtb_Initialise_b = rtb_SelReset * rtb_MinMass_jc +
            -PneumaticsSystem_P.PAtm;
        }

        /* End of Switch: '<S79>/Initialise' */

        /* Relay: '<S79>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_b =
          ((rtb_Initialise_b >=
            rtp_Prm_PneumaticsSystem->Pantograph.ORDSwitchONPressure) ||
           ((!(rtb_Initialise_b <=
               rtp_Prm_PneumaticsSystem->Pantograph.ORDSwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_b));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_b) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_d =
            PneumaticsSystem_P.CoreSubsys_pn.PS2_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_d =
            PneumaticsSystem_P.CoreSubsys_pn.PS2_OffOutputValue;
        }

        /* End of Relay: '<S79>/PressureSwitch' */

        /* InitialCondition: '<S97>/Initialise' incorporates:
         *  Constant: '<S97>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_f) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_f =
            false;
          rtb_MinMass_jc = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_g;
        } else {
          rtb_MinMass_jc = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_n;
        }

        /* End of InitialCondition: '<S97>/Initialise' */

        /* Switch: '<S80>/Initialise' incorporates:
         *  Bias: '<S61>/Bias'
         *  Constant: '<S80>/Constant'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_nc >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_p) {
          /* Switch: '<S97>/ExternalIC' incorporates:
           *  Bias: '<S61>/Bias'
           *  Constant: '<S80>/InitialConditionValue'
           */
          if (rtb_MinMass_jc >
              PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_i) {
            rtb_Initialise_b =
              rtp_Prm_PneumaticsSystem->Pantograph.SwitchONPressure;
          } else {
            rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_e +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S97>/ExternalIC' */
        } else {
          rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_e +
            -PneumaticsSystem_P.PAtm;
        }

        /* End of Switch: '<S80>/Initialise' */

        /* Relay: '<S80>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_f =
          ((rtb_Initialise_b >=
            rtp_Prm_PneumaticsSystem->Pantograph.SwitchONPressure) ||
           ((!(rtb_Initialise_b <=
               rtp_Prm_PneumaticsSystem->Pantograph.SwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_f));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_f) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l =
            PneumaticsSystem_P.CoreSubsys_pn.PanPressureSwitch_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l =
            PneumaticsSystem_P.CoreSubsys_pn.PanPressureSwitch_OffOutputValue;
        }

        /* End of Relay: '<S80>/PressureSwitch' */

        /* Saturate: '<S103>/Saturation' incorporates:
         *  Constant: '<S62>/pAtm2'
         */
        if (rtp_Prm_PneumaticsSystem->VCB.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_d) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_d;
        } else if (rtp_Prm_PneumaticsSystem->VCB.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_c) {
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_c;
        } else {
          rtb_Initialise_b = rtp_Prm_PneumaticsSystem->VCB.Volume;
        }

        /* End of Saturate: '<S103>/Saturation' */

        /* Fcn: '<S103>/RT // V' */
        rtb_MinMass_jc = 84102.72 / rtb_Initialise_b;

        /* Product: '<S103>/MaxMass' incorporates:
         *  Constant: '<S62>/Constant'
         */
        rtb_Initialise_b = (PneumaticsSystem_P.PAtm +
                            rtp_Prm_PneumaticsSystem->VCB.MaxPressure) /
          rtb_MinMass_jc;

        /* Logic: '<S103>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Overrides'
         */
        rtb_AND9 = (rtu_Overrides[ForEach_itr].Reset != 0.0);

        /* InitialCondition: '<S111>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_o) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_o = false;
          rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_li;
        }

        /* End of InitialCondition: '<S111>/IC' */

        /* UnitDelay: '<S62>/Unit Delay1' */
        rtb_UnitDelay1_oz = localDW->CoreSubsys_pn[ForEach_itr].
          UnitDelay1_DSTATE_kw;

        /* Logic: '<S102>/Logical Operator3' */
        rtb_LogicalOperator3_b3 =
          ((!rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.VCBCloseCmd)
           ||
           (!(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.VCBIsolationCock
              != 0.0)));

        /* Outputs for Atomic SubSystem: '<S102>/VCB Charge' */
        PneumaticsSystem_BSRVentDrain(localB->CoreSubsys_pn[ForEach_itr].P_d,
          rtb_UnitDelay1_oz, rtb_LogicalOperator3_b3, &localB->
          CoreSubsys_pn[ForEach_itr].VCBCharge,
          &PneumaticsSystem_P.CoreSubsys_pn.VCBCharge,
          PneumaticsSystem_P.CoreSubsys_pn.VCBCharge_p_deadband);

        /* End of Outputs for SubSystem: '<S102>/VCB Charge' */

        /* Switch: '<S111>/SelReset' incorporates:
         *  Constant: '<S102>/pAtm'
         *  Constant: '<S103>/Constant1'
         *  Product: '<S103>/ResetMass'
         *  SampleTimeMath: '<S111>/Weighted Sample Time'
         *  Sum: '<S102>/Sum'
         *  Sum: '<S111>/Sum1'
         *  Switch: '<S103>/SelReset'
         *  UnitDelay: '<S111>/Unit Delay1'
         *
         * About '<S111>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_AND9) {
          rtb_RTV_h = (PneumaticsSystem_P.PAtm +
                       rtp_Prm_PneumaticsSystem->VCB.ResetPressure) /
            rtb_MinMass_jc;
        } else {
          /* Outputs for Atomic SubSystem: '<S102>/VCB Isolate' */
          PneumaticsSystem_BSRVentIC(rtb_UnitDelay1_oz, PneumaticsSystem_P.PAtm,
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.VCBIsolationCock,
            &localB->CoreSubsys_pn[ForEach_itr].VCBIsolate,
            &PneumaticsSystem_P.CoreSubsys_pn.VCBIsolate,
            PneumaticsSystem_P.CoreSubsys_pn.VCBIsolate_p_deadband);

          /* End of Outputs for SubSystem: '<S102>/VCB Isolate' */

          /* Outputs for Atomic SubSystem: '<S102>/VCB Vent' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay1_oz,
            PneumaticsSystem_P.PAtm,
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.VCBCloseCmd,
            &localB->CoreSubsys_pn[ForEach_itr].VCBVent,
            &PneumaticsSystem_P.CoreSubsys_pn.VCBVent,
            PneumaticsSystem_P.CoreSubsys_pn.VCBVent_p_deadband);

          /* End of Outputs for SubSystem: '<S102>/VCB Vent' */
          rtb_RTV_h = ((localB->CoreSubsys_pn[ForEach_itr].VCBCharge.FlowNoflow
                        - localB->CoreSubsys_pn[ForEach_itr].VCBVent.FlowNoflow)
                       - localB->CoreSubsys_pn[ForEach_itr].
                       VCBIsolate.FlowNoflow) *
            PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_p +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_d;
        }

        /* End of Switch: '<S111>/SelReset' */

        /* Switch: '<S112>/Switch2' incorporates:
         *  RelationalOperator: '<S112>/LowerRelop1'
         */
        if (rtb_RTV_h > rtb_Initialise_b) {
          rtb_RTV_h = rtb_Initialise_b;
        } else {
          /* Product: '<S103>/MinMass' incorporates:
           *  Constant: '<S62>/pAtm'
           */
          rtb_MinMass_os = PneumaticsSystem_P.PAtm / rtb_MinMass_jc;

          /* Switch: '<S112>/Switch' incorporates:
           *  RelationalOperator: '<S112>/UpperRelop'
           */
          if (rtb_RTV_h < rtb_MinMass_os) {
            rtb_RTV_h = rtb_MinMass_os;
          }

          /* End of Switch: '<S112>/Switch' */
        }

        /* End of Switch: '<S112>/Switch2' */

        /* Product: '<S103>/ConvertToPressure' */
        localB->CoreSubsys_pn[ForEach_itr].P_o = rtb_RTV_h * rtb_MinMass_jc;

        /* InitialCondition: '<S113>/Initialise' incorporates:
         *  Constant: '<S113>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_n) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_n =
            false;
          rtb_MinMass_jc = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_k;
        } else {
          rtb_MinMass_jc = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_nw;
        }

        /* End of InitialCondition: '<S113>/Initialise' */

        /* Switch: '<S104>/Initialise' incorporates:
         *  Bias: '<S62>/Bias'
         *  Constant: '<S104>/Constant'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_c >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_h) {
          /* Switch: '<S113>/ExternalIC' incorporates:
           *  Bias: '<S62>/Bias'
           *  Constant: '<S104>/InitialConditionValue'
           */
          if (rtb_MinMass_jc >
              PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_c) {
            rtb_Initialise_b = rtp_Prm_PneumaticsSystem->VCB.SwitchONPressure;
          } else {
            rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_o +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S113>/ExternalIC' */
        } else {
          rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr].P_o +
            -PneumaticsSystem_P.PAtm;
        }

        /* End of Switch: '<S104>/Initialise' */

        /* Relay: '<S104>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_d =
          ((rtb_Initialise_b >= rtp_Prm_PneumaticsSystem->VCB.SwitchONPressure) ||
           ((!(rtb_Initialise_b <=
               rtp_Prm_PneumaticsSystem->VCB.SwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_d));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_d) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_j =
            PneumaticsSystem_P.CoreSubsys_pn.VCBPressureSwitch1_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_j =
            PneumaticsSystem_P.CoreSubsys_pn.VCBPressureSwitch1_OffOutputValue;
        }

        /* End of Relay: '<S104>/PressureSwitch' */

        /* Update for UnitDelay: '<S58>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_f =
          localB->CoreSubsys_pn[ForEach_itr].ARCharge.FlowNoflow;

        /* Update for UnitDelay: '<S58>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_c =
          localB->CoreSubsys_pn[ForEach_itr].VCBCharge.FlowNoflow;

        /* Update for UnitDelay: '<S60>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_e =
          localB->CoreSubsys_pn[ForEach_itr].P_d;

        /* Update for UnitDelay: '<S67>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_m = rtb_RTV;

        /* Update for UnitDelay: '<S76>/Delay Input1' */
        localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ii =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ORDPlunger;

        /* Update for UnitDelay: '<S61>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_eb =
          localB->CoreSubsys_pn[ForEach_itr].P_e;

        /* Update for UnitDelay: '<S61>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_ks =
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l;

        /* Update for UnitDelay: '<S98>/Delay Input1' */
        localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_m =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.PantographRaiseValve;

        /* Update for Memory: '<S99>/Memory' incorporates:
         *  CombinatorialLogic: '<S99>/Logic'
         */
        localDW->CoreSubsys_pn[ForEach_itr].Memory_PreviousInput =
          PneumaticsSystem_P.CoreSubsys_pn.Logic_table[static_cast<uint32_T>(i)];

        /* Update for UnitDelay: '<S85>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_g = rtb_SelReset;

        /* Update for UnitDelay: '<S83>/Unit Delay1' incorporates:
         *  Constant: '<S83>/Constant1'
         */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_j =
          PneumaticsSystem_P.CoreSubsys_pn.Constant1_Value_d;

        /* Update for UnitDelay: '<S100>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_mr =
          rtb_DiscreteTransferFcn;

        /* Update for UnitDelay: '<S62>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_kw =
          localB->CoreSubsys_pn[ForEach_itr].P_o;

        /* Update for UnitDelay: '<S111>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_d = rtb_RTV_h;
      }

      /* End of Outputs for SubSystem: '<S12>/AuxSystem' */

      /* Outputs for Enabled SubSystem: '<S12>/Horn' incorporates:
       *  EnablePort: '<S59>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].Equipment.HasDriverCab >
          0.0) {
        /* Bias: '<S59>/Bias' */
        rtb_Initialise_b = rtb_P + -PneumaticsSystem_P.PAtm;

        /* Logic: '<S59>/NOT' */
        rtb_AND3 =
          !rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.RemoteHornIsolate;

        /* DataTypeConversion: '<S59>/Data Type Conversion' incorporates:
         *  Constant: '<S115>/Constant'
         *  Constant: '<S116>/Constant'
         *  Logic: '<S59>/Logical Operator'
         *  Product: '<S59>/Product1'
         *  RelationalOperator: '<S115>/Compare'
         *  RelationalOperator: '<S116>/Compare'
         */
        localB->CoreSubsys_pn[ForEach_itr].HornLowPressureSwitch =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.HornLowControl
            == PneumaticsSystem_P.CoreSubsys_pn.HighHorn_const) &&
           (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornLowIsolationCock
            * rtb_Initialise_b > rtp_Prm_PneumaticsSystem->Horn.SwitchONPressure)
           && rtb_AND3);

        /* Product: '<S59>/Product' */
        rtb_Initialise_b *=
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornHighIsolationCock;

        /* DataTypeConversion: '<S59>/Data Type Conversion1' incorporates:
         *  Constant: '<S114>/Constant'
         *  Constant: '<S117>/Constant'
         *  Logic: '<S59>/Logical Operator1'
         *  RelationalOperator: '<S114>/Compare'
         *  RelationalOperator: '<S117>/Compare'
         */
        localB->CoreSubsys_pn[ForEach_itr].HornHighPressureSwitch =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.HornHighControl
            == PneumaticsSystem_P.CoreSubsys_pn.LowHorn_const) &&
           (rtb_Initialise_b > rtp_Prm_PneumaticsSystem->Horn.SwitchONPressure) &&
           rtb_AND3);

        /* Gain: '<S59>/Gain' */
        localB->CoreSubsys_pn[ForEach_itr].HornLow =
          PneumaticsSystem_P.CoreSubsys_pn.Gain_Gain * localB->
          CoreSubsys_pn[ForEach_itr].HornLowPressureSwitch;

        /* Gain: '<S59>/Gain1' */
        localB->CoreSubsys_pn[ForEach_itr].HornHigh =
          PneumaticsSystem_P.CoreSubsys_pn.Gain1_Gain * localB->
          CoreSubsys_pn[ForEach_itr].HornHighPressureSwitch;
      }

      /* End of Outputs for SubSystem: '<S12>/Horn' */

      /* Outputs for Enabled SubSystem: '<S15>/BrakeSupplyReservoir' incorporates:
       *  EnablePort: '<S214>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].
          Equipment.HasBrakeSystem > 0.0) {
        /* InitialCondition: '<S218>/Initialise' incorporates:
         *  Constant: '<S218>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_e) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_e =
            false;
          rtb_RTV = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_i;
        } else {
          rtb_RTV = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_k;
        }

        /* End of InitialCondition: '<S218>/Initialise' */

        /* Saturate: '<S216>/Saturation' incorporates:
         *  Constant: '<S214>/pAtm2'
         */
        if (rtp_Prm_PneumaticsSystem->BrakeReservoir.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_m) {
          rtb_PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_m;
        } else if (rtp_Prm_PneumaticsSystem->BrakeReservoir.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_pf) {
          rtb_PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_pf;
        } else {
          rtb_PressureSwitch = rtp_Prm_PneumaticsSystem->BrakeReservoir.Volume;
        }

        /* End of Saturate: '<S216>/Saturation' */

        /* Fcn: '<S216>/RT // V' */
        rtb_SelReset = 84102.72 / rtb_PressureSwitch;

        /* Product: '<S216>/MaxMass' incorporates:
         *  Constant: '<S214>/Constant'
         */
        rtb_PressureSwitch = (PneumaticsSystem_P.PAtm +
                              rtp_Prm_PneumaticsSystem->BrakeReservoir.MaxPressure)
          / rtb_SelReset;

        /* Logic: '<S216>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Overrides'
         */
        rtb_IC = (rtu_Overrides[ForEach_itr].Reset != 0.0);

        /* InitialCondition: '<S219>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_b) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_b = false;
          rtb_IC = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_b;
        }

        /* End of InitialCondition: '<S219>/IC' */

        /* UnitDelay: '<S214>/Unit Delay' */
        rtb_UnitDelay_l = localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_h;

        /* Logic: '<S217>/Logical Operator1' */
        rtb_LogicalOperator1_d =
          !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeSupplyReservoirIsolationCock
            != 0.0);

        /* Outputs for Atomic SubSystem: '<S217>/BSR Charge' */
        PneumaticsSystem_BSRVentDrain(rtb_P, rtb_UnitDelay_l,
          rtb_LogicalOperator1_d, &localB->CoreSubsys_pn[ForEach_itr].
          BSRCharge_b, &PneumaticsSystem_P.CoreSubsys_pn.BSRCharge_b,
          PneumaticsSystem_P.CoreSubsys_pn.BSRCharge_p_deadband);

        /* End of Outputs for SubSystem: '<S217>/BSR Charge' */

        /* Switch: '<S219>/SelReset' incorporates:
         *  Constant: '<S216>/Constant1'
         *  Constant: '<S217>/Constant'
         *  Product: '<S216>/ResetMass'
         *  SampleTimeMath: '<S219>/Weighted Sample Time'
         *  Sum: '<S217>/Add'
         *  Sum: '<S219>/Sum1'
         *  Switch: '<S216>/SelReset'
         *  UnitDelay: '<S219>/Unit Delay1'
         *  UnitDelay: '<S9>/Unit Delay4'
         *
         * About '<S219>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_IC) {
          rtb_DiscreteTransferFcn =
            (rtp_Prm_PneumaticsSystem->BrakeReservoir.ResetPressure +
             PneumaticsSystem_P.PAtm) / rtb_SelReset;
        } else {
          /* Logic: '<S217>/Logical Operator3' incorporates:
           *  Constant: '<S224>/Constant'
           *  ForEachSliceSelector generated from: '<S3>/Faults'
           *  Logic: '<S217>/Logical Operator4'
           *  RelationalOperator: '<S224>/Compare'
           */
          rtb_LogicalOperator3_i = ((!(rtu_Faults[ForEach_itr].BECULowRPressure
            != 0.0)) || (!(rtb_UnitDelay_l >
                           PneumaticsSystem_P.CoreSubsys_pn.CompareToConstant_const)));

          /* Logic: '<S217>/Logical Operator2' */
          rtb_LogicalOperator2_c =
            !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeSupplyReservoirDrainCock
              != 0.0);

          /* Outputs for Atomic SubSystem: '<S217>/BSR Vent Drain' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_l, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator2_c, &localB->CoreSubsys_pn[ForEach_itr].
            BSRVentDrain_d, &PneumaticsSystem_P.CoreSubsys_pn.BSRVentDrain_d,
            PneumaticsSystem_P.CoreSubsys_pn.BSRVentDrain_p_deadband_a);

          /* End of Outputs for SubSystem: '<S217>/BSR Vent Drain' */

          /* Outputs for Atomic SubSystem: '<S217>/BSR Vent IC' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_l, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator3_i, &localB->CoreSubsys_pn[ForEach_itr].
            BSRVentIC_c, &PneumaticsSystem_P.CoreSubsys_pn.BSRVentIC_c,
            PneumaticsSystem_P.CoreSubsys_pn.BSRVentIC_p_deadband_e);

          /* End of Outputs for SubSystem: '<S217>/BSR Vent IC' */
          rtb_DiscreteTransferFcn = (((localB->CoreSubsys_pn[ForEach_itr].
            BSRCharge_b.FlowNoflow - localB->CoreSubsys_pn[ForEach_itr].
            BSRVentIC_c.FlowNoflow) - localB->CoreSubsys_pn[ForEach_itr].
            BSRVentDrain_d.FlowNoflow) - localDW->CoreSubsys_pn[ForEach_itr].
            UnitDelay4_DSTATE) *
            PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_e +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_es;
        }

        /* End of Switch: '<S219>/SelReset' */

        /* Switch: '<S220>/Switch2' incorporates:
         *  RelationalOperator: '<S220>/LowerRelop1'
         */
        if (rtb_DiscreteTransferFcn > rtb_PressureSwitch) {
          rtb_DiscreteTransferFcn = rtb_PressureSwitch;
        } else {
          /* Product: '<S216>/MinMass' incorporates:
           *  Constant: '<S214>/pAtm'
           */
          rtb_MinMass_jc = PneumaticsSystem_P.PAtm / rtb_SelReset;

          /* Switch: '<S220>/Switch' incorporates:
           *  RelationalOperator: '<S220>/UpperRelop'
           */
          if (rtb_DiscreteTransferFcn < rtb_MinMass_jc) {
            rtb_DiscreteTransferFcn = rtb_MinMass_jc;
          }

          /* End of Switch: '<S220>/Switch' */
        }

        /* End of Switch: '<S220>/Switch2' */

        /* Product: '<S216>/ConvertToPressure' */
        localB->CoreSubsys_pn[ForEach_itr].P_a = rtb_DiscreteTransferFcn *
          rtb_SelReset;

        /* Bias: '<S214>/Bias' */
        localB->CoreSubsys_pn[ForEach_itr].Bias = localB->
          CoreSubsys_pn[ForEach_itr].P_a + -PneumaticsSystem_P.PAtm;

        /* Switch: '<S215>/Initialise' incorporates:
         *  Constant: '<S215>/Constant'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_c1 >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_i) {
          /* Switch: '<S218>/ExternalIC' incorporates:
           *  Constant: '<S215>/InitialConditionValue'
           */
          if (rtb_RTV > PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_o)
          {
            rtb_PressureSwitch =
              rtp_Prm_PneumaticsSystem->BrakeReservoir.SwitchONPressure;
          } else {
            rtb_PressureSwitch = localB->CoreSubsys_pn[ForEach_itr].Bias;
          }

          /* End of Switch: '<S218>/ExternalIC' */
        } else {
          rtb_PressureSwitch = localB->CoreSubsys_pn[ForEach_itr].Bias;
        }

        /* End of Switch: '<S215>/Initialise' */

        /* Relay: '<S215>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_m =
          ((rtb_PressureSwitch >=
            rtp_Prm_PneumaticsSystem->BrakeReservoir.SwitchONPressure) ||
           ((!(rtb_PressureSwitch <=
               rtp_Prm_PneumaticsSystem->BrakeReservoir.SwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_m));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_m) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_g =
            PneumaticsSystem_P.CoreSubsys_pn.BSRPressureSwitch05_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_g =
            PneumaticsSystem_P.CoreSubsys_pn.BSRPressureSwitch05_OffOutputValue;
        }

        /* End of Relay: '<S215>/PressureSwitch' */

        /* Update for UnitDelay: '<S214>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_h =
          localB->CoreSubsys_pn[ForEach_itr].P_a;

        /* Update for UnitDelay: '<S219>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_es =
          rtb_DiscreteTransferFcn;
      }

      /* End of Outputs for SubSystem: '<S15>/BrakeSupplyReservoir' */

      /* Outputs for Enabled SubSystem: '<S14>/AirSuspensionSystem' incorporates:
       *  EnablePort: '<S118>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].Equipment.HasBogie >
          0.0) {
        /* SignalConversion generated from: '<S118>/Vector Concatenate2' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2[0] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie1;

        /* SignalConversion generated from: '<S118>/Vector Concatenate2' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2[1] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie2;

        /* SignalConversion generated from: '<S118>/Vector Concatenate1' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1_k[0] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemDrainCockBogie1;

        /* SignalConversion generated from: '<S118>/Vector Concatenate1' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1_k[1] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemDrainCockBogie2;

        /* Outputs for Iterator SubSystem: '<S118>/AirSuspensionPerBogie' incorporates:
         *  ForEach: '<S123>/For Each'
         */
        for (ForEach_itr_fz = 0; ForEach_itr_fz < 2; ForEach_itr_fz++) {
          /* ForEachSliceSelector generated from: '<S123>/BogieSupportedMass' */
          rtb_ImpSel_InsertedFor_BogieSupportedMass_at_outport_0 =
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.PhysicalSignals.BogieSupportedMasses
            [ForEach_itr_fz];

          /* ForEachSliceSelector generated from: '<S123>/AirSuspensionIsolCock' */
          rtb_ImpSel_InsertedFor_AirSuspensionIsolCock_at_outport_0 =
            localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2[ForEach_itr_fz];

          /* S-Function (sfix_look1_dyn): '<S124>/Lookup Table Dynamic1' incorporates:
           *  Constant: '<S124>/Constant'
           *  Constant: '<S124>/Constant1'
           */
          /* Dynamic Look-Up Table Block: '<S124>/Lookup Table Dynamic1'
           * Input0  Data Type:  Floating Point real_T
           * Input1  Data Type:  Floating Point real_T
           * Input2  Data Type:  Floating Point real_T
           * Output0 Data Type:  Floating Point real_T
           * Lookup Method: Linear_Endpoint
           *
           */
          LookUp_real_T_real_T( &(rtb_Initialise_b),
                               &rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                               [0],
                               rtb_ImpSel_InsertedFor_BogieSupportedMass_at_outport_0,
                               &rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationMasses
                               [0], 1U);

          /* Saturate: '<S124>/limiter1' incorporates:
           *  Constant: '<S123>/Constant'
           *  Product: '<S125>/MaxMass'
           */
          rtb_MinMass_jc = rtp_Prm_PneumaticsSystem->AirSuspension.MaxPressure +
            PneumaticsSystem_P.PAtm;
          if (rtb_Initialise_b > rtb_MinMass_jc) {
            rtb_Initialise_b = rtb_MinMass_jc;
          } else {
            if (rtb_Initialise_b < PneumaticsSystem_P.PAtm) {
              rtb_Initialise_b = PneumaticsSystem_P.PAtm;
            }
          }

          /* End of Saturate: '<S124>/limiter1' */

          /* Bias: '<S124>/Bias' */
          rtb_Bias_p = rtb_Initialise_b + PneumaticsSystem_P.PAtm;

          /* UnitDelay: '<S123>/Unit Delay' */
          rtb_UnitDelay_lp = localDW->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys[ForEach_itr_fz].UnitDelay_DSTATE;

          /* Sum: '<S124>/Subtract' */
          rtb_Initialise_b = rtb_Bias_p - rtb_UnitDelay_lp;

          /* Abs: '<S124>/Abs' */
          rtb_DiscreteTransferFcn = fabs(rtb_Initialise_b);

          /* Logic: '<S123>/OR1' */
          rtb_FixPtRelationalOperator_d =
            ((rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1CarLoadPressureLow
              != 0.0) ||
             (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2CarLoadPressureLow
              != 0.0));

          /* Signum: '<S124>/Sign' */
          if (rtb_Initialise_b < 0.0) {
            rtb_Initialise_b = -1.0;
          } else if (rtb_Initialise_b > 0.0) {
            rtb_Initialise_b = 1.0;
          } else if (rtb_Initialise_b == 0.0) {
            rtb_Initialise_b = 0.0;
          } else {
            rtb_Initialise_b = (rtNaN);
          }

          /* End of Signum: '<S124>/Sign' */

          /* Product: '<S124>/Product' incorporates:
           *  Constant: '<S129>/Constant'
           *  Logic: '<S123>/OR2'
           *  Logic: '<S124>/NOT'
           *  RelationalOperator: '<S129>/Compare'
           */
          rtb_SelReset = static_cast<real_T>(((!rtb_FixPtRelationalOperator_d) &&
            (!(rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1LoadPressureLow
               != 0.0)) && (!(rtb_Sqrt != 0.0)))) * (static_cast<real_T>
            ((rtb_DiscreteTransferFcn >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.CompareToConstant_const))
            * rtb_Initialise_b);

          /* Saturate: '<S125>/Saturation' incorporates:
           *  Constant: '<S123>/Volume'
           */
          if (rtp_Prm_PneumaticsSystem->AirSuspension.Volume >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat) {
            rtb_Initialise_b =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat;
          } else if (rtp_Prm_PneumaticsSystem->AirSuspension.Volume <
                     PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_LowerSat)
          {
            rtb_Initialise_b =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_LowerSat;
          } else {
            rtb_Initialise_b = rtp_Prm_PneumaticsSystem->AirSuspension.Volume;
          }

          /* End of Saturate: '<S125>/Saturation' */

          /* Fcn: '<S125>/RT // V' */
          rtb_RTV = 84102.72 / rtb_Initialise_b;

          /* Product: '<S125>/MaxMass' */
          rtb_Initialise_b = rtb_MinMass_jc / rtb_RTV;

          /* Logic: '<S123>/NOT' incorporates:
           *  UnitDelay: '<S123>/Unit Delay1'
           */
          rtb_AND3 = !localDW->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys[ForEach_itr_fz].UnitDelay1_DSTATE_g;

          /* Logic: '<S125>/Logical Operator' */
          rtb_AND9 = ((rtb_MainReservoirPipePressureGauge != 0.0) || rtb_AND3);

          /* InitialCondition: '<S130>/IC' */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              IC_FirstOutputTime) {
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              IC_FirstOutputTime = false;
            rtb_AND9 = PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.IC_Value;
          }

          /* End of InitialCondition: '<S130>/IC' */

          /* Logic: '<S127>/Logical Operator5' incorporates:
           *  Constant: '<S139>/Constant'
           *  Logic: '<S127>/Logical Operator4'
           *  RelationalOperator: '<S139>/Compare'
           */
          rtb_LogicalOperator5_l =
            ((!(rtb_ImpSel_InsertedFor_AirSuspensionIsolCock_at_outport_0 != 0.0))
             || (rtb_SelReset !=
                 PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.CompareToConstant1_const));

          /* Outputs for Atomic SubSystem: '<S127>/AS Charge' */
          PneumaticsSystem_ASCharge(rtb_P_e, rtb_UnitDelay_lp,
            rtb_LogicalOperator5_l, rtb_Bias_p,
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ChargeChoke_DiffGain,
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ChargeChoke_FullDiam,
            &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            ASCharge, &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASCharge,
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASCharge_p_deadband);

          /* End of Outputs for SubSystem: '<S127>/AS Charge' */

          /* Switch: '<S130>/SelReset' incorporates:
           *  Constant: '<S127>/Constant'
           *  Constant: '<S137>/Constant'
           *  Constant: '<S137>/Constant1'
           *  Constant: '<S140>/Constant'
           *  Constant: '<S140>/Constant1'
           *  Product: '<S125>/ResetMass'
           *  SampleTimeMath: '<S130>/Weighted Sample Time'
           *  Sum: '<S127>/Add'
           *  Sum: '<S130>/Sum1'
           *  UnitDelay: '<S130>/Unit Delay1'
           *
           * About '<S130>/Weighted Sample Time':
           *  y = u * K where K = ( w * Ts )
           */
          if (rtb_AND9) {
            /* Switch: '<S125>/SelReset' incorporates:
             *  Constant: '<S125>/Constant1'
             *  Logic: '<S125>/Logical Operator1'
             *  Logic: '<S125>/Logical Operator2'
             */
            if (rtb_AND3 && (!(rtb_MainReservoirPipePressureGauge != 0.0))) {
              rtb_SelReset = rtb_Bias_p;
            } else {
              rtb_SelReset = PneumaticsSystem_P.PAtm + 450000.0;
            }

            /* End of Switch: '<S125>/SelReset' */
            rtb_SelReset /= rtb_RTV;
          } else {
            /* RelationalOperator: '<S138>/Compare' incorporates:
             *  Constant: '<S138>/Constant'
             */
            rtb_Compare_np = (rtb_SelReset !=
                              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.CompareToConstant_const_l);

            /* Logic: '<S127>/Logical Operator2' incorporates:
             *  ForEachSliceSelector generated from: '<S123>/AirSuspensionDrainCock'
             */
            rtb_LogicalOperator2_m = !(localB->CoreSubsys_pn[ForEach_itr].
              VectorConcatenate1_k[ForEach_itr_fz] != 0.0);

            /* Outputs for Atomic SubSystem: '<S127>/AS Vent Drain' */
            PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_lp,
              PneumaticsSystem_P.PAtm, rtb_LogicalOperator2_m,
              &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              ASVentDrain,
              &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVentDrain,
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVentDrain_p_deadband);

            /* End of Outputs for SubSystem: '<S127>/AS Vent Drain' */

            /* Outputs for Atomic SubSystem: '<S127>/AS Vent IC' */
            PneumaticsSystem_BSRVentIC(rtb_UnitDelay_lp, PneumaticsSystem_P.PAtm,
              rtb_ImpSel_InsertedFor_AirSuspensionIsolCock_at_outport_0,
              &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              ASVentIC, &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVentIC,
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVentIC_p_deadband);

            /* End of Outputs for SubSystem: '<S127>/AS Vent IC' */

            /* Outputs for Atomic SubSystem: '<S127>/AS Vent' */
            PneumaticsSystem_ASVent(rtb_UnitDelay_lp, PneumaticsSystem_P.PAtm,
              rtb_Compare_np, rtb_Bias_p,
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ReleaseChoke_DiffGain,
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ReleaseChoke_FullDiam,
              &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              ASVent, &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVent,
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ASVent_p_deadband);

            /* End of Outputs for SubSystem: '<S127>/AS Vent' */
            rtb_SelReset = (((localB->CoreSubsys_pn[ForEach_itr]
                              .CoreSubsys[ForEach_itr_fz].ASCharge.FlowNoflow -
                              localB->CoreSubsys_pn[ForEach_itr]
                              .CoreSubsys[ForEach_itr_fz].ASVent.FlowNoflow) -
                             localB->CoreSubsys_pn[ForEach_itr]
                             .CoreSubsys[ForEach_itr_fz].ASVentIC.FlowNoflow) -
                            localB->CoreSubsys_pn[ForEach_itr]
                            .CoreSubsys[ForEach_itr_fz].ASVentDrain.FlowNoflow) *
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.WeightedSampleTime_WtEt
              + localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              UnitDelay1_DSTATE;
          }

          /* End of Switch: '<S130>/SelReset' */

          /* Switch: '<S131>/Switch2' incorporates:
           *  RelationalOperator: '<S131>/LowerRelop1'
           */
          if (rtb_SelReset > rtb_Initialise_b) {
            rtb_SelReset = rtb_Initialise_b;
          } else {
            /* Product: '<S125>/MinMass' incorporates:
             *  Constant: '<S123>/pAtm'
             */
            rtb_DiscreteTransferFcn = PneumaticsSystem_P.PAtm / rtb_RTV;

            /* Switch: '<S131>/Switch' incorporates:
             *  RelationalOperator: '<S131>/UpperRelop'
             */
            if (rtb_SelReset < rtb_DiscreteTransferFcn) {
              rtb_SelReset = rtb_DiscreteTransferFcn;
            }

            /* End of Switch: '<S131>/Switch' */
          }

          /* End of Switch: '<S131>/Switch2' */

          /* Product: '<S125>/ConvertToPressure' */
          rtb_RTV *= rtb_SelReset;

          /* Switch: '<S128>/Switch2' incorporates:
           *  Constant: '<S128>/Constant'
           *  Switch: '<S128>/Switch'
           *  Switch: '<S128>/Switch1'
           */
          if (rtb_Sqrt >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Switch2_Threshold) {
            rtb_RTV = PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant_Value;
          } else if
              (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1LoadPressureLow >
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Switch1_Threshold) {
            /* Switch: '<S128>/Switch1' incorporates:
             *  Gain: '<S128>/Gain1'
             */
            rtb_RTV *= PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Gain1_Gain;
          } else {
            if (rtb_FixPtRelationalOperator_d) {
              /* Switch: '<S128>/Switch' incorporates:
               *  Gain: '<S128>/Gain'
               *  Switch: '<S128>/Switch1'
               */
              rtb_RTV *= PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Gain_Gain;
            }
          }

          /* End of Switch: '<S128>/Switch2' */

          /* SampleTimeMath: '<S145>/Weighted Sample Time'
           *
           * About '<S145>/Weighted Sample Time':
           *  y = K where K = ( w * Ts )
           */
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.WeightedSampleTime_WtEt_b;

          /* Saturate: '<S145>/Saturation' incorporates:
           *  Constant: '<S145>/FilterSpecification'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.FilterSpecification_Value
              >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat_m)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat_m;
          } else if
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.FilterSpecification_Value
               <
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_LowerSat_l)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_LowerSat_l;
          } else {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.FilterSpecification_Value;
          }

          /* End of Saturate: '<S145>/Saturation' */

          /* Product: '<S145>/Divide' incorporates:
           *  Sum: '<S145>/Den'
           */
          rtb_Initialise_b /= rtb_Initialise_b + rtb_MinMass_os;

          /* SignalConversion generated from: '<S145>/Vector Concatenate1' */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            VectorConcatenate1[0] = rtb_Initialise_b;
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            VectorConcatenate1[1] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant1_Value;

          /* SignalConversion generated from: '<S145>/Vector Concatenate' incorporates:
           *  Constant: '<S145>/Constant'
           *  Constant: '<S145>/Constant1'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            VectorConcatenate[0] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant_Value_c;

          /* Sum: '<S145>/Subtract' incorporates:
           *  Constant: '<S145>/Constant'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            VectorConcatenate[1] = rtb_Initialise_b -
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant_Value_c;

          /* DiscreteTransferFcn: '<S145>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            DiscreteTransferFcn_tmp = rtb_RTV - localB->
            CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            VectorConcatenate[1] * localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys[ForEach_itr_fz].DiscreteTransferFcn_states;
          rtb_MinMass_jc = localB->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys[ForEach_itr_fz].VectorConcatenate1[0] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            DiscreteTransferFcn_tmp + localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys[ForEach_itr_fz].VectorConcatenate1[1] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            DiscreteTransferFcn_states;

          /* MATLAB Function: '<S146>/Replace Zeros' */
          rtb_RTV = rtb_Bias_p;
          if (rtb_Bias_p == 0.0) {
            rtb_RTV = 4.94065645841247E-324;
          }

          /* Gain: '<S128>/Gain2' incorporates:
           *  MATLAB Function: '<S146>/Replace Zeros'
           *  Product: '<S146>/Divide'
           *  Sum: '<S128>/Subtract'
           */
          rtb_Initialise_b = (rtb_Bias_p - rtb_MinMass_jc) / rtb_RTV *
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Gain2_Gain;

          /* ForEachSliceAssignment generated from: '<S123>/AirSuspPressure%Variation' incorporates:
           *  Abs: '<S128>/Abs'
           */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[ForEach_itr_fz]
            = fabs(rtb_Initialise_b);

          /* InitialCondition: '<S132>/Initialise' incorporates:
           *  Constant: '<S132>/OnlyIC'
           */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              Initialise_FirstOutputTime) {
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              Initialise_FirstOutputTime = false;
            rtb_RTV =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Initialise_Value;
          } else {
            rtb_RTV = PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.OnlyIC_Value;
          }

          /* End of InitialCondition: '<S132>/Initialise' */

          /* Switch: '<S126>/Initialise' incorporates:
           *  Bias: '<S123>/Bias'
           *  Constant: '<S126>/Constant'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant_Value_d >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Initialise_Threshold)
          {
            /* Switch: '<S132>/ExternalIC' incorporates:
             *  Bias: '<S123>/Bias'
             *  Constant: '<S126>/InitialConditionValue'
             */
            if (rtb_RTV >
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.ExternalIC_Threshold)
            {
              rtb_Initialise_b =
                rtp_Prm_PneumaticsSystem->AirSuspension.SwitchONPressure;
            } else {
              rtb_Initialise_b = rtb_MinMass_jc + -PneumaticsSystem_P.PAtm;
            }

            /* End of Switch: '<S132>/ExternalIC' */
          } else {
            rtb_Initialise_b = rtb_MinMass_jc + -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S126>/Initialise' */

          /* Relay: '<S126>/PressureSwitch' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            PressureSwitch_Mode = ((rtb_Initialise_b >=
            rtp_Prm_PneumaticsSystem->AirSuspension.SwitchONPressure) ||
            ((!(rtb_Initialise_b <=
                rtp_Prm_PneumaticsSystem->AirSuspension.SwitchOFFPressure)) &&
             localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
             PressureSwitch_Mode));

          /* Update for UnitDelay: '<S123>/Unit Delay' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            UnitDelay_DSTATE = rtb_MinMass_jc;

          /* Update for UnitDelay: '<S123>/Unit Delay1' incorporates:
           *  Constant: '<S123>/Constant1'
           */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            UnitDelay1_DSTATE_g =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Constant1_Value_c;

          /* Update for UnitDelay: '<S130>/Unit Delay1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            UnitDelay1_DSTATE = rtb_SelReset;

          /* Update for DiscreteTransferFcn: '<S145>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            DiscreteTransferFcn_states = localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys[ForEach_itr_fz].DiscreteTransferFcn_tmp;

          /* ForEachSliceAssignment generated from: '<S123>/AirSuspensionPressure' */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0[ForEach_itr_fz]
            = rtb_MinMass_jc;

          /* Relay: '<S126>/PressureSwitch' */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
              PressureSwitch_Mode) {
            /* ForEachSliceAssignment generated from: '<S123>/AirSuspensionPressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[ForEach_itr_fz]
              =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.B27L1112_OnOutputValue;
          } else {
            /* ForEachSliceAssignment generated from: '<S123>/AirSuspensionPressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[ForEach_itr_fz]
              =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.B27L1112_OffOutputValue;
          }

          /* ForEachSliceAssignment generated from: '<S123>/ASRToAS' */
          rtb_ImpAsg_InsertedFor_ASRToAS_at_inport_0[ForEach_itr_fz] =
            localB->CoreSubsys_pn[ForEach_itr].CoreSubsys[ForEach_itr_fz].
            ASCharge.FlowNoflow;
        }

        /* End of Outputs for SubSystem: '<S118>/AirSuspensionPerBogie' */

        /* Sum: '<S118>/Sum' incorporates:
         *  Constant: '<S137>/Constant'
         *  Constant: '<S137>/Constant1'
         *  Constant: '<S145>/Constant1'
         */
        localB->CoreSubsys_pn[ForEach_itr].Sum =
          rtb_ImpAsg_InsertedFor_ASRToAS_at_inport_0[0] +
          rtb_ImpAsg_InsertedFor_ASRToAS_at_inport_0[1];
      }

      /* End of Outputs for SubSystem: '<S14>/AirSuspensionSystem' */

      /* Outputs for Enabled SubSystem: '<S14>/BrakingSystem' incorporates:
       *  EnablePort: '<S121>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].Equipment.HasBogie >
          0.0) {
        localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE = true;

        /* Logic: '<S121>/OR2' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Faults'
         *  Logic: '<S121>/NOT2'
         */
        rtb_FixPtRelationalOperator_d =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.ParkingBrakeApplyCmd
            != 0.0) && (!(rtu_Faults[ForEach_itr].ParkingBrakeApplicationFailure
                          != 0.0)));

        /* Logic: '<S121>/OR3' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Faults'
         *  Logic: '<S121>/NOT3'
         */
        rtb_AND3 =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.ParkingBrakeReleaseCmd
            != 0.0) && (!(rtu_Faults[ForEach_itr].ParkingBrakeReleaseFailure !=
                          0.0)));

        /* Logic: '<S121>/OR' incorporates:
         *  Logic: '<S121>/NOT'
         */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate[0] =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie1
            != 0.0) &&
           (!rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.RemoteMagnetValve1));

        /* Logic: '<S121>/OR1' incorporates:
         *  Logic: '<S121>/NOT1'
         */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate[1] =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie2
            != 0.0) &&
           (!rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.RemoteMagnetValve2));

        /* SignalConversion generated from: '<S121>/Vector Concatenate1' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1[0] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie1;

        /* SignalConversion generated from: '<S121>/Vector Concatenate1' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate1[1] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie2;

        /* Logic: '<S121>/Logical Operator' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2_c[0] =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeManualReleaseBogie1Handle2
            != 0.0) &&
           (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeManualReleaseBogie1Handle1
            != 0.0));

        /* Logic: '<S121>/Logical Operator1' */
        localB->CoreSubsys_pn[ForEach_itr].VectorConcatenate2_c[1] =
          ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeManualReleaseBogie2Handle1
            != 0.0) &&
           (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeManualReleaseBogie2Handle2
            != 0.0));

        /* Outputs for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' incorporates:
         *  ForEach: '<S148>/For Each'
         */
        for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
          /* InitialCondition: '<S190>/Initialise' incorporates:
           *  Constant: '<S190>/OnlyIC'
           */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .Initialise_FirstOutputTime) {
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              Initialise_FirstOutputTime = false;
            rtb_RTV =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Initialise_Value;
          } else {
            rtb_RTV =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.OnlyIC_Value;
          }

          /* End of InitialCondition: '<S190>/Initialise' */

          /* Logic: '<S153>/Logical Operator' incorporates:
           *  ForEachSliceSelector generated from: '<S148>/BrakeCylinderIsolationCock'
           *  ForEachSliceSelector generated from: '<S3>/Faults'
           */
          rtb_AND5 = ((rtu_Faults[ForEach_itr].BECU1BrakeNotReleased != 0.0) &&
                      localB->CoreSubsys_pn[ForEach_itr]
                      .VectorConcatenate[ForEach_itr_au]);

          /* Product: '<S157>/Divide' incorporates:
           *  Bias: '<S149>/Bias2'
           *  ForEachSliceSelector generated from: '<S148>/AirSuspensionPressures '
           */
          rtb_PressureSwitch = (localB->CoreSubsys_pn[ForEach_itr].
                                ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0
                                [ForEach_itr_au] + -PneumaticsSystem_P.PAtm) /
            PneumaticsSystem_ConstB.CoreSubsys_pn.CoreSubsys_pna.Width;

          /* Switch: '<S157>/CrushRevertingPistonValve 02' */
          if (!(rtb_PressureSwitch >= PneumaticsSystem_P.PAtm)) {
            /* Bias: '<S149>/Bias3' */
            rtb_SelReset = rtb_P + -PneumaticsSystem_P.PAtm;

            /* MinMax: '<S157>/Max' incorporates:
             *  Constant: '<S157>/Constant1'
             */
            if ((rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                 [0] >
                 rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                 [1]) || rtIsNaN
                (rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                 [1])) {
              rtb_DiscreteTransferFcn =
                rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                [0];
            } else {
              rtb_DiscreteTransferFcn =
                rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                [1];
            }

            /* Switch: '<S184>/Switch2' incorporates:
             *  MinMax: '<S157>/Max'
             *  RelationalOperator: '<S184>/LowerRelop1'
             *  RelationalOperator: '<S184>/UpperRelop'
             *  Switch: '<S184>/Switch'
             */
            if (rtb_SelReset > rtb_DiscreteTransferFcn) {
              rtb_PressureSwitch = rtb_DiscreteTransferFcn;
            } else if (rtb_SelReset < 0.0) {
              /* Switch: '<S184>/Switch' */
              rtb_PressureSwitch = 0.0;
            } else {
              rtb_PressureSwitch = rtb_SelReset;
            }

            /* End of Switch: '<S184>/Switch2' */
          }

          /* End of Switch: '<S157>/CrushRevertingPistonValve 02' */

          /* S-Function (sfix_look1_dyn): '<S157>/Lookup Table Dynamic1' incorporates:
           *  Constant: '<S157>/Constant'
           *  Constant: '<S157>/Constant1'
           */
          /* Dynamic Look-Up Table Block: '<S157>/Lookup Table Dynamic1'
           * Input0  Data Type:  Floating Point real_T
           * Input1  Data Type:  Floating Point real_T
           * Input2  Data Type:  Floating Point real_T
           * Output0 Data Type:  Floating Point real_T
           * Lookup Method: Linear_Endpoint
           *
           */
          LookUp_real_T_real_T( &(rtb_PressureSwitch_e),
                               &rtp_Prm_PneumaticsSystem->BrakeControl.LoadCompensationGains
                               [0], rtb_PressureSwitch,
                               &rtp_Prm_PneumaticsSystem->AirSuspension.LoadCompensationPressures
                               [0], 1U);

          /* Saturate: '<S157>/Proportion' */
          if (rtb_PressureSwitch_e >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Proportion_UpperSat)
          {
            rtb_PressureSwitch_e =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Proportion_UpperSat;
          } else {
            if (rtb_PressureSwitch_e <
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Proportion_LowerSat)
            {
              rtb_PressureSwitch_e =
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Proportion_LowerSat;
            }
          }

          /* End of Saturate: '<S157>/Proportion' */

          /* Gain: '<S157>/Gain' */
          rtb_PressureSwitch_e *=
            rtp_Prm_PneumaticsSystem->BrakeControl.MaxPressure;

          /* RelationalOperator: '<S155>/Compare' incorporates:
           *  Constant: '<S155>/Constant'
           */
          rtb_IC =
            (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.TCMSBrakingDemand
             >
             PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant2_const);

          /* Saturate: '<S156>/Saturation' incorporates:
           *  Constant: '<S156>/FilterSpecification'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value
              >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat;
          } else if
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value
               <
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat;
          } else {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value;
          }

          /* End of Saturate: '<S156>/Saturation' */

          /* Product: '<S156>/Divide' incorporates:
           *  SampleTimeMath: '<S156>/Weighted Sample Time'
           *  Sum: '<S156>/Den'
           *
           * About '<S156>/Weighted Sample Time':
           *  y = K where K = ( w * Ts )
           */
          rtb_MinMass_jc =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.WeightedSampleTime_WtEt
            /
            (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.WeightedSampleTime_WtEt
             + rtb_MinMass_os);

          /* SignalConversion generated from: '<S156>/Vector Concatenate1' */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1[0] = rtb_MinMass_jc;
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1[1] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant1_Value_c;

          /* SignalConversion generated from: '<S156>/Vector Concatenate' incorporates:
           *  Constant: '<S156>/Constant'
           *  Constant: '<S156>/Constant1'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate[0] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_n;

          /* Sum: '<S156>/Subtract' incorporates:
           *  Constant: '<S156>/Constant'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate[1] = rtb_MinMass_jc -
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_n;

          /* Switch: '<S149>/Switch' incorporates:
           *  Constant: '<S149>/Constant1'
           *  ForEachSliceSelector generated from: '<S148>/BogieControl'
           *  Logic: '<S149>/AND'
           */
          if (rtb_IC && (rtb_RTV_f != 0.0)) {
            rtb_SelReset =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant1_Value;
          } else {
            rtb_SelReset =
              rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.BogieControl
              [ForEach_itr_au].EPBrakingDemand;
          }

          /* End of Switch: '<S149>/Switch' */

          /* DiscreteTransferFcn: '<S156>/Discrete Transfer Fcn' incorporates:
           *  Constant: '<S154>/Constant'
           *  Constant: '<S154>/Constant1'
           *  Constant: '<S154>/Constant2'
           *  Constant: '<S154>/Constant3'
           *  Constant: '<S154>/Constant4'
           *  Constant: '<S154>/Constant5'
           *  Product: '<S154>/Product1'
           *  Product: '<S154>/Product2'
           *  Product: '<S154>/Product3'
           *  Product: '<S154>/Product4'
           *  Product: '<S154>/Product5'
           *  Sum: '<S154>/Sum'
           */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp = (rtb_SelReset /
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.BrakeCylinderPressureCalc_noBrakeCyl
            /
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.BrakeCylinderPressureCalc_bcArea
            /
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.BrakeCylinderPressureCalc_brkBeamFactor
            /
            (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.BrakeCylinderPressureCalc_brkEfficiency
             / PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant4_Value_j)
            + PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.BrakeCylinderPressureCalc_bcPreload)
            - localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate[1] * localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_states;
          rtb_DiscreteTransferFcn = localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1[0] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp + localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1[1] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states;

          /* Switch: '<S149>/Switch2' incorporates:
           *  Constant: '<S149>/pAtm'
           */
          if (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.EPIsolationCock
              >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Switch2_Threshold)
          {
            rtb_MinMass_os = localB->CoreSubsys_pn[ForEach_itr].P_a;
          } else {
            rtb_MinMass_os = PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S149>/Switch2' */

          /* Bias: '<S149>/Bias1' */
          rtb_SelReset = rtb_MinMass_os + -PneumaticsSystem_P.PAtm;

          /* Switch: '<S149>/Switch1' incorporates:
           *  Constant: '<S149>/Constant2'
           *  Logic: '<S149>/OR'
           *  Switch: '<S149>/EM Magnet Valve 03'
           */
          if (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Switch1_Threshold)
          {
            rtb_DiscreteTransferFcn =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant2_Value;
          } else if
              ((rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.NoEmergencyBrakeValve
                != 0.0) || (rtb_P2C != 0.0) ||
               (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure
                != 0.0)) {
            /* MinMax: '<S149>/MinMax' incorporates:
             *  Switch: '<S149>/EM Magnet Valve 03'
             */
            if ((!(rtb_DiscreteTransferFcn < rtb_SelReset)) && (!rtIsNaN
                 (rtb_SelReset))) {
              rtb_DiscreteTransferFcn = rtb_SelReset;
            }

            /* End of MinMax: '<S149>/MinMax' */
          } else {
            /* Switch: '<S149>/EM Magnet Valve 03' */
            rtb_DiscreteTransferFcn = rtb_SelReset;
          }

          /* End of Switch: '<S149>/Switch1' */

          /* Saturate: '<S149>/Regulating Valve 02' */
          if (rtb_DiscreteTransferFcn >
              rtp_Prm_PneumaticsSystem->BrakeControl.MaxPressure) {
            rtb_RTV_h = rtp_Prm_PneumaticsSystem->BrakeControl.MaxPressure;
          } else if (rtb_DiscreteTransferFcn <
                     PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.RegulatingValve02_LowerSat)
          {
            rtb_RTV_h =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.RegulatingValve02_LowerSat;
          } else {
            rtb_RTV_h = rtb_DiscreteTransferFcn;
          }

          /* End of Saturate: '<S149>/Regulating Valve 02' */

          /* Switch: '<S183>/Switch2' incorporates:
           *  RelationalOperator: '<S183>/LowerRelop1'
           *  RelationalOperator: '<S183>/UpperRelop'
           *  Switch: '<S183>/Switch'
           */
          if (rtb_RTV_h > rtb_PressureSwitch_e) {
            rtb_RTV_h = rtb_PressureSwitch_e;
          } else {
            if (rtb_RTV_h < 0.0) {
              /* Switch: '<S183>/Switch' */
              rtb_RTV_h = 0.0;
            }
          }

          /* End of Switch: '<S183>/Switch2' */

          /* If: '<S153>/If' */
          rtPrevAction = localDW->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys_pna[ForEach_itr_au].If_ActiveSubsystem;
          rtAction = static_cast<int8_T>(!rtb_AND5);
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            If_ActiveSubsystem = rtAction;
          if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
            /* Disable for Outport: '<S170>/Out2' */
            localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              OutportBufferForOut2 =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Out2_Y0;
          }

          if (rtAction == 0) {
            /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem' incorporates:
             *  ActionPort: '<S170>/Action Port'
             */
            /* Product: '<S181>/delta rise limit' incorporates:
             *  Constant: '<S170>/Constant4'
             *  SampleTimeMath: '<S181>/sample time'
             *
             * About '<S181>/sample time':
             *  y = K where K = ( w * Ts )
             */
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant4_Value *
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.sampletime_WtEt;

            /* Sum: '<S181>/Difference Inputs1' incorporates:
             *  UnitDelay: '<S181>/Delay Input2'
             */
            rtb_MinMass_jc = rtb_RTV_h - localDW->CoreSubsys_pn[ForEach_itr].
              CoreSubsys_pna[ForEach_itr_au].DelayInput2_DSTATE;

            /* Switch: '<S182>/Switch2' incorporates:
             *  RelationalOperator: '<S182>/LowerRelop1'
             */
            if (!(rtb_MinMass_jc > rtb_MinMass_os)) {
              /* Product: '<S181>/delta fall limit' incorporates:
               *  Constant: '<S170>/Constant3'
               *  SampleTimeMath: '<S181>/sample time'
               *
               * About '<S181>/sample time':
               *  y = K where K = ( w * Ts )
               */
              rtb_MinMass_os =
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant3_Value *
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.sampletime_WtEt;

              /* Switch: '<S182>/Switch' incorporates:
               *  RelationalOperator: '<S182>/UpperRelop'
               */
              if (!(rtb_MinMass_jc < rtb_MinMass_os)) {
                rtb_MinMass_os = rtb_MinMass_jc;
              }

              /* End of Switch: '<S182>/Switch' */
            }

            /* End of Switch: '<S182>/Switch2' */

            /* Sum: '<S181>/Difference Inputs2' incorporates:
             *  UnitDelay: '<S181>/Delay Input2'
             */
            rtb_MinMass_jc = rtb_MinMass_os + localDW->CoreSubsys_pn[ForEach_itr]
              .CoreSubsys_pna[ForEach_itr_au].DelayInput2_DSTATE;

            /* SignalConversion generated from: '<S170>/Out2' */
            localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              OutportBufferForOut2 = rtb_MinMass_jc;

            /* Update for UnitDelay: '<S181>/Delay Input2' */
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              DelayInput2_DSTATE = rtb_MinMass_jc;

            /* End of Outputs for SubSystem: '<S153>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S171>/Action Port'
             */
            /* Gain: '<S171>/Gain' */
            rtb_MinMass_jc =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Gain_Gain *
              rtb_RTV_h;

            /* End of Outputs for SubSystem: '<S153>/If Action Subsystem1' */
          }

          /* End of If: '<S153>/If' */

          /* Bias: '<S149>/Bias' */
          rtb_BrakeCylinderControlPressure = rtb_MinMass_jc +
            PneumaticsSystem_P.PAtm;

          /* Switch: '<S150>/Switch' incorporates:
           *  Constant: '<S150>/Atmospheric'
           *  ForEachSliceSelector generated from: '<S148>/BrakeCylinderIsolationCock'
           */
          if (localB->CoreSubsys_pn[ForEach_itr]
              .VectorConcatenate[ForEach_itr_au]) {
            rtb_MinMass_os = rtb_BrakeCylinderControlPressure;
          } else {
            rtb_MinMass_os = PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S150>/Switch' */

          /* Outputs for Iterator SubSystem: '<S148>/BrakeCylinderSystemPerAxle' incorporates:
           *  ForEach: '<S151>/For Each'
           */
          for (ForEach_itr_cq = 0; ForEach_itr_cq < 2; ForEach_itr_cq++) {
            /* Outputs for Enabled SubSystem: '<S151>/AxleBrakeCylinder' incorporates:
             *  EnablePort: '<S192>/Enable'
             */
            if (rtp_Prm_PneumaticsSystem->BrakeCylinder.BrakeCylindersPerBogieAxle
                [ForEach_itr_cq] >
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Constant_Value)
            {
              /* Saturate: '<S194>/Saturation' incorporates:
               *  Constant: '<S192>/pAtm2'
               */
              if (rtp_Prm_PneumaticsSystem->BrakeCylinder.Volume >
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Saturation_UpperSat)
              {
                rtb_Initialise_b =
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Saturation_UpperSat;
              } else if (rtp_Prm_PneumaticsSystem->BrakeCylinder.Volume <
                         PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Saturation_LowerSat)
              {
                rtb_Initialise_b =
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Saturation_LowerSat;
              } else {
                rtb_Initialise_b =
                  rtp_Prm_PneumaticsSystem->BrakeCylinder.Volume;
              }

              /* End of Saturate: '<S194>/Saturation' */

              /* Fcn: '<S194>/RT // V' */
              rtb_Divide = 84102.72 / rtb_Initialise_b;

              /* Product: '<S194>/MaxMass' incorporates:
               *  Constant: '<S192>/Constant'
               */
              rtb_Initialise_b = (PneumaticsSystem_P.PAtm +
                                  rtp_Prm_PneumaticsSystem->BrakeCylinder.MaxPressure)
                / rtb_Divide;

              /* Logic: '<S192>/NOT' incorporates:
               *  UnitDelay: '<S192>/Unit Delay1'
               */
              rtb_LogicalOperator40 = !localDW->CoreSubsys_pn[ForEach_itr].
                CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                UnitDelay1_DSTATE_k;

              /* Logic: '<S194>/Logical Operator' */
              rtb_AND9 = ((rtb_MainReservoirPipePressureGauge != 0.0) ||
                          rtb_LogicalOperator40);

              /* InitialCondition: '<S196>/IC' */
              if (localDW->CoreSubsys_pn[ForEach_itr]
                  .CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                  IC_FirstOutputTime) {
                localDW->CoreSubsys_pn[ForEach_itr]
                  .CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                  IC_FirstOutputTime = false;
                rtb_AND9 =
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.IC_Value;
              }

              /* End of InitialCondition: '<S196>/IC' */

              /* UnitDelay: '<S192>/Unit Delay' */
              rtb_UnitDelay_g = localDW->CoreSubsys_pn[ForEach_itr].
                CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                UnitDelay_DSTATE;

              /* Sum: '<S195>/Subtract' */
              rtb_PressureSwitch_e = rtb_UnitDelay_g -
                rtb_BrakeCylinderControlPressure;

              /* Abs: '<S195>/Abs' */
              rtb_PressureSwitch_e = fabs(rtb_PressureSwitch_e);

              /* Logic: '<S195>/Logical Operator2' incorporates:
               *  Constant: '<S202>/Constant'
               *  ForEachSliceSelector generated from: '<S148>/BrakeCylinderIsolationCock'
               *  Logic: '<S195>/Logical Operator1'
               *  RelationalOperator: '<S202>/Compare'
               */
              rtb_LogicalOperator2_i = ((rtb_PressureSwitch_e <=
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.CompareToConstant_const)
                || (!localB->CoreSubsys_pn[ForEach_itr]
                    .VectorConcatenate[ForEach_itr_au]));

              /* Outputs for Atomic SubSystem: '<S195>/BC Charge' */
              PneumaticsSystem_ASCharge(localB->CoreSubsys_pn[ForEach_itr].P_a,
                rtb_UnitDelay_g, rtb_LogicalOperator2_i,
                rtb_BrakeCylinderControlPressure,
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.ChargeChoke_DiffGain,
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.ChargeChoke_FullDiam,
                &localB->CoreSubsys_pn[ForEach_itr]
                .CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                BCCharge,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCCharge,
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCCharge_p_deadband);

              /* End of Outputs for SubSystem: '<S195>/BC Charge' */

              /* Switch: '<S196>/SelReset' incorporates:
               *  Constant: '<S195>/Constant'
               *  Constant: '<S201>/Constant'
               *  Constant: '<S201>/Constant1'
               *  Constant: '<S203>/Constant'
               *  Constant: '<S203>/Constant1'
               *  ForEachSliceSelector generated from: '<S148>/BrakeCylinderIsolationCock'
               *  Product: '<S194>/ResetMass'
               *  SampleTimeMath: '<S196>/Weighted Sample Time'
               *  Sum: '<S195>/Add'
               *  Sum: '<S196>/Sum1'
               *  UnitDelay: '<S196>/Unit Delay1'
               *
               * About '<S196>/Weighted Sample Time':
               *  y = u * K where K = ( w * Ts )
               */
              if (rtb_AND9) {
                /* Switch: '<S194>/SelReset' incorporates:
                 *  Constant: '<S194>/Constant1'
                 *  Logic: '<S194>/Logical Operator1'
                 *  Logic: '<S194>/Logical Operator2'
                 */
                if (rtb_LogicalOperator40 &&
                    (!(rtb_MainReservoirPipePressureGauge != 0.0))) {
                  rtb_SelReset_n = rtb_BrakeCylinderControlPressure;
                } else {
                  rtb_SelReset_n = PneumaticsSystem_P.PAtm +
                    rtp_Prm_PneumaticsSystem->BrakeCylinder.ResetPressure;
                }

                /* End of Switch: '<S194>/SelReset' */
                rtb_SelReset_n /= rtb_Divide;
              } else {
                /* Outputs for Atomic SubSystem: '<S195>/BC Isolate' */
                PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_g,
                  PneumaticsSystem_P.PAtm, localB->CoreSubsys_pn[ForEach_itr].
                  VectorConcatenate[ForEach_itr_au], &localB->
                  CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                  CoreSubsys[ForEach_itr_cq].BCIsolate,
                  &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCIsolate,
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCIsolate_p_deadband);

                /* End of Outputs for SubSystem: '<S195>/BC Isolate' */

                /* Outputs for Atomic SubSystem: '<S195>/BC Vent' */
                PneumaticsSystem_ASVent(rtb_UnitDelay_g, PneumaticsSystem_P.PAtm,
                  rtb_LogicalOperator2_i, rtb_BrakeCylinderControlPressure,
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.ReleaseChoke_DiffGain,
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.ReleaseChoke_FullDiam,
                  &localB->CoreSubsys_pn[ForEach_itr]
                  .CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                  BCVent,
                  &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCVent,
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.BCVent_p_deadband);

                /* End of Outputs for SubSystem: '<S195>/BC Vent' */
                rtb_SelReset_n = ((localB->CoreSubsys_pn[ForEach_itr].
                                   CoreSubsys_pna[ForEach_itr_au]
                                   .CoreSubsys[ForEach_itr_cq].
                                   BCCharge.FlowNoflow - localB->
                                   CoreSubsys_pn[ForEach_itr]
                                   .CoreSubsys_pna[ForEach_itr_au]
                                   .CoreSubsys[ForEach_itr_cq].BCVent.FlowNoflow)
                                  - localB->CoreSubsys_pn[ForEach_itr].
                                  CoreSubsys_pna[ForEach_itr_au]
                                  .CoreSubsys[ForEach_itr_cq].
                                  BCIsolate.FlowNoflow) *
                  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.WeightedSampleTime_WtEt
                  + localDW->CoreSubsys_pn[ForEach_itr]
                  .CoreSubsys_pna[ForEach_itr_au].CoreSubsys[ForEach_itr_cq].
                  UnitDelay1_DSTATE;
              }

              /* End of Switch: '<S196>/SelReset' */

              /* Switch: '<S197>/Switch2' incorporates:
               *  RelationalOperator: '<S197>/LowerRelop1'
               */
              if (rtb_SelReset_n > rtb_Initialise_b) {
                rtb_SelReset_n = rtb_Initialise_b;
              } else {
                /* Product: '<S194>/MinMass' incorporates:
                 *  Constant: '<S192>/pAtm'
                 */
                rtb_MinMass_f = PneumaticsSystem_P.PAtm / rtb_Divide;

                /* Switch: '<S197>/Switch' incorporates:
                 *  RelationalOperator: '<S197>/UpperRelop'
                 */
                if (rtb_SelReset_n < rtb_MinMass_f) {
                  rtb_SelReset_n = rtb_MinMass_f;
                }

                /* End of Switch: '<S197>/Switch' */
              }

              /* End of Switch: '<S197>/Switch2' */

              /* Product: '<S194>/ConvertToPressure' */
              localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                CoreSubsys[ForEach_itr_cq].P = rtb_SelReset_n * rtb_Divide;

              /* Update for UnitDelay: '<S192>/Unit Delay1' incorporates:
               *  Constant: '<S192>/Constant1'
               */
              localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
                .CoreSubsys[ForEach_itr_cq].UnitDelay1_DSTATE_k =
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Constant1_Value;

              /* Update for UnitDelay: '<S192>/Unit Delay' */
              localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
                .CoreSubsys[ForEach_itr_cq].UnitDelay_DSTATE =
                localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
                .CoreSubsys[ForEach_itr_cq].P;

              /* Update for UnitDelay: '<S196>/Unit Delay1' */
              localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
                .CoreSubsys[ForEach_itr_cq].UnitDelay1_DSTATE = rtb_SelReset_n;
            }

            /* End of Outputs for SubSystem: '<S151>/AxleBrakeCylinder' */

            /* ForEachSliceAssignment generated from: '<S151>/BrakeCylinderPressure' incorporates:
             *  Constant: '<S148>/Constant'
             *  Constant: '<S193>/Constant'
             *  Constant: '<S201>/Constant'
             *  Constant: '<S201>/Constant1'
             *  ForEachSliceSelector generated from: '<S151>/BrakeCylindersPerAxle'
             *  RelationalOperator: '<S193>/Compare'
             */
            rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[ForEach_itr_cq]
              = localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .CoreSubsys[ForEach_itr_cq].P;

            /* ForEachSliceAssignment generated from: '<S151>/BSRtoBCFlow' */
            rtb_ImpAsg_InsertedFor_BSRtoBCFlow_at_inport_0[ForEach_itr_cq] =
              localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              CoreSubsys[ForEach_itr_cq].BCCharge.FlowNoflow;
          }

          /* End of Outputs for SubSystem: '<S148>/BrakeCylinderSystemPerAxle' */

          /* Sum: '<S150>/Sum of Elements1' incorporates:
           *  Constant: '<S148>/Constant'
           *  Constant: '<S186>/Constant'
           *  Constant: '<S193>/Constant'
           *  Constant: '<S201>/Constant'
           *  Constant: '<S201>/Constant1'
           *  ForEachSliceSelector generated from: '<S151>/BrakeCylindersPerAxle'
           *  RelationalOperator: '<S186>/Compare'
           *  RelationalOperator: '<S193>/Compare'
           */
          i = static_cast<int32_T>((static_cast<uint32_T>
            ((rtp_Prm_PneumaticsSystem->
              BrakeCylinder.BrakeCylindersPerBogieAxle[0] >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_o))
            + (rtp_Prm_PneumaticsSystem->BrakeCylinder.BrakeCylindersPerBogieAxle
               [1] >
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_o)));

          /* MATLAB Function: '<S189>/Replace Zeros' incorporates:
           *  Sum: '<S150>/Sum of Elements1'
           */
          b_idx_0 = static_cast<uint8_T>(i);
          if (static_cast<uint8_T>(i) == 0) {
            b_idx_0 = 0U;
          }

          /* Switch: '<S150>/Switch1' incorporates:
           *  Sum: '<S150>/Sum of Elements1'
           */
          if (static_cast<uint8_T>(i) >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Switch1_Threshold_o)
          {
            /* Product: '<S189>/Divide' incorporates:
             *  MATLAB Function: '<S189>/Replace Zeros'
             *  Sum: '<S150>/Sum of Elements'
             */
            rtb_SandingSystemIsolationCock[1] =
              (rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[0] +
               rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[1]) /
              static_cast<real_T>(b_idx_0);

            /* SignalConversion generated from: '<S150>/Vector Concatenate' */
            rtb_SandingSystemIsolationCock[0] = rtb_MinMass_os;
          } else {
            /* SignalConversion generated from: '<S150>/Vector Concatenate1' */
            rtb_SandingSystemIsolationCock[1] = rtb_MinMass_os;

            /* SignalConversion generated from: '<S150>/Vector Concatenate1' */
            rtb_SandingSystemIsolationCock[0] = rtb_MinMass_os;
          }

          /* End of Switch: '<S150>/Switch1' */

          /* Saturate: '<S188>/Saturation' */
          if (PneumaticsSystem_ConstB.CoreSubsys_pn.CoreSubsys_pna.Width_o >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_n)
          {
            rtb_PressureSwitch_e =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_n;
          } else if
              (PneumaticsSystem_ConstB.CoreSubsys_pn.CoreSubsys_pna.Width_o <
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_j)
          {
            rtb_PressureSwitch_e =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_j;
          } else {
            rtb_PressureSwitch_e =
              PneumaticsSystem_ConstB.CoreSubsys_pn.CoreSubsys_pna.Width_o;
          }

          /* End of Saturate: '<S188>/Saturation' */

          /* Product: '<S188>/Divide' incorporates:
           *  Sum: '<S188>/Sum of Elements'
           */
          rtb_Divide = (rtb_SandingSystemIsolationCock[0] +
                        rtb_SandingSystemIsolationCock[1]) /
            rtb_PressureSwitch_e;

          /* SampleTimeMath: '<S187>/Weighted Sample Time'
           *
           * About '<S187>/Weighted Sample Time':
           *  y = K where K = ( w * Ts )
           */
          rtb_PressureSwitch_e =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.WeightedSampleTime_WtEt_j;

          /* Saturate: '<S187>/Saturation' incorporates:
           *  Constant: '<S187>/FilterSpecification'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_m
              >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_h)
          {
            rtb_Initialise_b =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_h;
          } else if
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_m
               <
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_c)
          {
            rtb_Initialise_b =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_c;
          } else {
            rtb_Initialise_b =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_m;
          }

          /* End of Saturate: '<S187>/Saturation' */

          /* Product: '<S187>/Divide' incorporates:
           *  Fcn: '<S187>/SpecificationTypeConversion'
           *  Sum: '<S187>/Den'
           */
          rtb_PressureSwitch_e /= rtb_PressureSwitch_e + rtb_Initialise_b;

          /* SignalConversion generated from: '<S187>/Vector Concatenate1' */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1_c[0] = rtb_PressureSwitch_e;
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1_c[1] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant1_Value_p;

          /* SignalConversion generated from: '<S187>/Vector Concatenate' incorporates:
           *  Constant: '<S187>/Constant'
           *  Constant: '<S187>/Constant1'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_l[0] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_d;

          /* Sum: '<S187>/Subtract' incorporates:
           *  Constant: '<S187>/Constant'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_l[1] = rtb_PressureSwitch_e -
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_d;

          /* DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp_d = rtb_Divide - localB->
            CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_l[1] * localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_states_i;
          rtb_Initialise_b = localB->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1_c[0] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp_d + localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1_c[1] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states_i;

          /* Bias: '<S150>/Bias' */
          rtb_Divide = rtb_Initialise_b + -PneumaticsSystem_P.PAtm;

          /* Switch: '<S185>/Initialise' incorporates:
           *  Constant: '<S185>/Constant'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_ou >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Initialise_Threshold)
          {
            /* Switch: '<S190>/ExternalIC' incorporates:
             *  Constant: '<S185>/InitialConditionValue'
             */
            if (rtb_RTV >
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.ExternalIC_Threshold_b)
            {
              rtb_PressureSwitch_e =
                rtp_Prm_PneumaticsSystem->BrakeCylinder.SwitchONPressure;
            } else {
              rtb_PressureSwitch_e = rtb_Divide;
            }

            /* End of Switch: '<S190>/ExternalIC' */
          } else {
            rtb_PressureSwitch_e = rtb_Divide;
          }

          /* End of Switch: '<S185>/Initialise' */

          /* Relay: '<S185>/PressureSwitch' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            PressureSwitch_Mode = ((rtb_PressureSwitch_e >=
            rtp_Prm_PneumaticsSystem->BrakeCylinder.SwitchONPressure) ||
            ((!(rtb_PressureSwitch_e <=
                rtp_Prm_PneumaticsSystem->BrakeCylinder.SwitchOFFPressure)) &&
             localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
             PressureSwitch_Mode));

          /* Logic: '<S153>/Logical Operator1' */
          rtb_AND9 =
            !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.NoEmergencyBrakeValve
              != 0.0);

          /* Logic: '<S153>/AND' incorporates:
           *  Constant: '<S159>/Constant'
           *  RelationalOperator: '<S159>/Compare'
           */
          rtb_AND6 = (rtb_AND9 && (rtb_RTV_h <
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant3_const));

          /* If: '<S153>/If1' incorporates:
           *  Constant: '<S153>/Constant1'
           *  Constant: '<S153>/Constant2'
           *  Constant: '<S153>/Constant3'
           *  ForEachSliceSelector generated from: '<S148>/AirSuspPressure%Var'
           */
          rtPrevAction = localDW->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys_pna[ForEach_itr_au].If1_ActiveSubsystem;
          rtAction = -1;
          if (localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[ForEach_itr_au]
              > 80.0) {
            rtAction = 0;
          } else if (localB->CoreSubsys_pn[ForEach_itr].
                     ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[ForEach_itr_au]
                     < 40.0) {
            rtAction = 1;
          } else {
            if ((localB->CoreSubsys_pn[ForEach_itr].
                 ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[ForEach_itr_au]
                 > 40.0) && (localB->CoreSubsys_pn[ForEach_itr].
                             ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0
                             [ForEach_itr_au] < 80.0)) {
              rtAction = 2;
            }
          }

          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            If1_ActiveSubsystem = rtAction;
          if (rtPrevAction != rtAction) {
            switch (rtPrevAction) {
             case 0:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem5,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem5);
              break;

             case 1:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem4,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem4);
              break;

             case 2:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem6,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem6);
              break;
            }
          }

          switch (rtAction) {
           case 0:
            /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem5' incorporates:
             *  ActionPort: '<S173>/Action Port'
             */
            PneumaticsSystem_IfActionSubsystem5
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant1_Value_a,
               &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
               .IfActionSubsystem5);

            /* End of Outputs for SubSystem: '<S153>/If Action Subsystem5' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem4' incorporates:
             *  ActionPort: '<S172>/Action Port'
             */
            PneumaticsSystem_IfActionSubsystem5
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant2_Value_a,
               &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
               .IfActionSubsystem4);

            /* End of Outputs for SubSystem: '<S153>/If Action Subsystem4' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem6' incorporates:
             *  ActionPort: '<S174>/Action Port'
             */
            PneumaticsSystem_IfActionSubsystem5
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant3_Value_p,
               &localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
               .IfActionSubsystem6);

            /* End of Outputs for SubSystem: '<S153>/If Action Subsystem6' */
            break;
          }

          /* End of If: '<S153>/If1' */

          /* Logic: '<S153>/Logical Operator2' */
          rtb_AND9 = (rtb_AND9 || rtb_IC);

          /* Logic: '<S175>/Logical Operator40' incorporates:
           *  Logic: '<S153>/AND1'
           *  Logic: '<S175>/Logical Operator39'
           *  Logic: '<S175>/Logical Operator41'
           *  Memory: '<S175>/Memory'
           *  RelationalOperator: '<S163>/FixPt Relational Operator'
           *  UnitDelay: '<S163>/Delay Input1'
           */
          rtb_LogicalOperator40 = (((rtb_AND6 && (rtb_P2C != 0.0)) ||
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput) && (!(rtb_P2C < localDW->
            CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE)));

          /* Logic: '<S176>/Logical Operator40' incorporates:
           *  Logic: '<S153>/AND5'
           *  Logic: '<S176>/Logical Operator39'
           *  Logic: '<S176>/Logical Operator41'
           *  Memory: '<S176>/Memory'
           *  RelationalOperator: '<S164>/FixPt Relational Operator'
           *  UnitDelay: '<S164>/Delay Input1'
           */
          rtb_AND6 = (((rtb_AND6 &&
                        (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure
                         != 0.0)) || localDW->CoreSubsys_pn[ForEach_itr].
                       CoreSubsys_pna[ForEach_itr_au].Memory_PreviousInput_j) &&
                      (!(rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure
                         < localDW->CoreSubsys_pn[ForEach_itr]
                         .CoreSubsys_pna[ForEach_itr_au].DelayInput1_DSTATE_b)));

          /* Logic: '<S177>/Logical Operator40' incorporates:
           *  Logic: '<S153>/AND2'
           *  Logic: '<S177>/Logical Operator39'
           *  Logic: '<S177>/Logical Operator41'
           *  Memory: '<S177>/Memory'
           *  RelationalOperator: '<S165>/FixPt Relational Operator'
           *  UnitDelay: '<S165>/Delay Input1'
           */
          rtb_IC = (((rtb_IC && (rtb_RTV_f != 0.0)) || localDW->
                     CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                     Memory_PreviousInput_l) && (!(rtb_RTV_f <
                      localDW->CoreSubsys_pn[ForEach_itr]
                      .CoreSubsys_pna[ForEach_itr_au].DelayInput1_DSTATE_e)));

          /* Logic: '<S178>/Logical Operator40' incorporates:
           *  Constant: '<S160>/Constant'
           *  Constant: '<S161>/Constant'
           *  ForEachSliceSelector generated from: '<S148>/BogieControl'
           *  Logic: '<S153>/AND3'
           *  Logic: '<S178>/Logical Operator39'
           *  Logic: '<S178>/Logical Operator41'
           *  Memory: '<S178>/Memory'
           *  RelationalOperator: '<S160>/Compare'
           *  RelationalOperator: '<S161>/Compare'
           *  RelationalOperator: '<S166>/FixPt Relational Operator'
           *  UnitDelay: '<S166>/Delay Input1'
           */
          rtb_LogicalOperator40_j = ((((rtb_RTV_h <
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant5_const)
            &&
            (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.BogieControl
             [ForEach_itr_au].EPBrakingDemand >
             PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant4_const)
            && (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied
                != 0.0)) || localDW->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys_pna[ForEach_itr_au].Memory_PreviousInput_d) &&
            (!(rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied <
               localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
               .DelayInput1_DSTATE_a)));

          /* Logic: '<S179>/Logical Operator40' incorporates:
           *  Constant: '<S158>/Constant'
           *  Logic: '<S153>/AND4'
           *  Logic: '<S179>/Logical Operator39'
           *  Logic: '<S179>/Logical Operator41'
           *  Memory: '<S179>/Memory'
           *  RelationalOperator: '<S158>/Compare'
           *  RelationalOperator: '<S167>/FixPt Relational Operator'
           *  RelationalOperator: '<S168>/FixPt Relational Operator'
           *  UnitDelay: '<S167>/Delay Input1'
           *  UnitDelay: '<S168>/Delay Input1'
           */
          rtb_LogicalOperator40_e = ((((static_cast<int32_T>(rtb_AND9) <
            static_cast<int32_T>(localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DelayInput1_DSTATE_h)) &&
            (localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
             OutportBufferForOut2 >
             PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant1_const))
            || localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
            .Memory_PreviousInput_f) && (static_cast<int32_T>(rtb_AND5) >=
            static_cast<int32_T>(localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DelayInput1_DSTATE_j)));

          /* Logic: '<S180>/Logical Operator40' incorporates:
           *  Constant: '<S162>/Constant'
           *  Logic: '<S153>/AND6'
           *  Logic: '<S180>/Logical Operator39'
           *  Logic: '<S180>/Logical Operator41'
           *  Memory: '<S180>/Memory'
           *  RelationalOperator: '<S162>/Compare'
           *  RelationalOperator: '<S169>/FixPt Relational Operator'
           *  UnitDelay: '<S169>/Delay Input1'
           */
          rtb_LogicalOperator40_l =
            ((((rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECULowRPressure !=
                0.0) && (localB->CoreSubsys_pn[ForEach_itr].P_a <=
                         PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CompareToConstant7_const))
              || localDW->CoreSubsys_pn[ForEach_itr]
              .CoreSubsys_pna[ForEach_itr_au].Memory_PreviousInput_g) &&
             (!(rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECULowRPressure <
                localDW->CoreSubsys_pn[ForEach_itr]
                .CoreSubsys_pna[ForEach_itr_au].DelayInput1_DSTATE_f)));

          /* Logic: '<S209>/Logical Operator40' incorporates:
           *  Logic: '<S209>/Logical Operator39'
           *  Logic: '<S209>/Logical Operator41'
           *  Memory: '<S209>/Memory'
           */
          rtb_LogicalOperator40_o = ((rtb_FixPtRelationalOperator_d ||
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_p) && (!rtb_AND3));

          /* Switch: '<S152>/Switch1' incorporates:
           *  Constant: '<S152>/Constant1'
           */
          if (rtb_LogicalOperator40_o) {
            rtb_RTV = PneumaticsSystem_P.PAtm;
          } else {
            rtb_RTV = rtb_P;
          }

          /* End of Switch: '<S152>/Switch1' */

          /* MinMax: '<S152>/DoubleCheckValve' */
          if ((!(rtb_RTV > rtb_Initialise_b)) && (!rtIsNaN(rtb_Initialise_b))) {
            rtb_RTV = rtb_Initialise_b;
          }

          /* End of MinMax: '<S152>/DoubleCheckValve' */

          /* Switch: '<S152>/Switch2' incorporates:
           *  Constant: '<S152>/Constant'
           *  ForEachSliceSelector generated from: '<S148>/ParkBrakesIsolationCock'
           *  ForEachSliceSelector generated from: '<S148>/ParkBrakesManualRelease'
           *  Logic: '<S152>/AND'
           *  Logic: '<S152>/NOT'
           *  Switch: '<S152>/Switch3'
           */
          if ((!(localB->CoreSubsys_pn[ForEach_itr]
                 .VectorConcatenate1[ForEach_itr_au] != 0.0)) &&
              localB->CoreSubsys_pn[ForEach_itr]
              .VectorConcatenate2_c[ForEach_itr_au]) {
            /* MinMax: '<S152>/Max' incorporates:
             *  Constant: '<S152>/PBPressures'
             */
            if ((rtp_Prm_PneumaticsSystem->ParkBrakes.ParkBrakePressures[0] >
                 rtp_Prm_PneumaticsSystem->ParkBrakes.ParkBrakePressures[1]) ||
                rtIsNaN(rtp_Prm_PneumaticsSystem->ParkBrakes.ParkBrakePressures
                        [1])) {
              rtb_RTV_h =
                rtp_Prm_PneumaticsSystem->ParkBrakes.ParkBrakePressures[0];
            } else {
              rtb_RTV_h =
                rtp_Prm_PneumaticsSystem->ParkBrakes.ParkBrakePressures[1];
            }

            /* End of MinMax: '<S152>/Max' */
          } else if (localB->CoreSubsys_pn[ForEach_itr]
                     .VectorConcatenate1[ForEach_itr_au] >
                     PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Switch3_Threshold)
          {
            /* Switch: '<S152>/Switch3' */
            rtb_RTV_h = rtb_RTV;
          } else {
            rtb_RTV_h = PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S152>/Switch2' */

          /* SampleTimeMath: '<S208>/Weighted Sample Time'
           *
           * About '<S208>/Weighted Sample Time':
           *  y = K where K = ( w * Ts )
           */
          rtb_Initialise_b =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.WeightedSampleTime_WtEt_b;

          /* Saturate: '<S208>/Saturation' incorporates:
           *  Constant: '<S208>/FilterSpecification'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_o
              >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_p)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_p;
          } else if
              (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_o
               <
               PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_l)
          {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_LowerSat_l;
          } else {
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.FilterSpecification_Value_o;
          }

          /* End of Saturate: '<S208>/Saturation' */

          /* Product: '<S208>/Divide' incorporates:
           *  Sum: '<S208>/Den'
           */
          rtb_Initialise_b /= rtb_Initialise_b + rtb_MinMass_os;

          /* SignalConversion generated from: '<S208>/Vector Concatenate1' */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1_d[0] = rtb_Initialise_b;
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate1_d[1] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant1_Value_l;

          /* SignalConversion generated from: '<S208>/Vector Concatenate' incorporates:
           *  Constant: '<S208>/Constant'
           *  Constant: '<S208>/Constant1'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_k[0] =
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_g;

          /* Sum: '<S208>/Subtract' incorporates:
           *  Constant: '<S208>/Constant'
           */
          localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_k[1] = rtb_Initialise_b -
            PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_g;

          /* DiscreteTransferFcn: '<S208>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp_h = rtb_RTV_h - localB->
            CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            VectorConcatenate_k[1] * localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_states_l;
          rtb_MinMass_os = localB->CoreSubsys_pn[ForEach_itr]
            .CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1_d[0] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_tmp_h + localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].VectorConcatenate1_d[1] *
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states_l;

          /* InitialCondition: '<S210>/Initialise' incorporates:
           *  Constant: '<S210>/OnlyIC'
           */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .Initialise_FirstOutputTime_g) {
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              Initialise_FirstOutputTime_g = false;
            rtb_RTV_h =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Initialise_Value_c;
          } else {
            rtb_RTV_h =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.OnlyIC_Value_p;
          }

          /* End of InitialCondition: '<S210>/Initialise' */

          /* Switch: '<S207>/Initialise' incorporates:
           *  Bias: '<S152>/Bias1'
           *  Constant: '<S207>/Constant'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Constant_Value_a >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Initialise_Threshold_l)
          {
            /* Switch: '<S210>/ExternalIC' incorporates:
             *  Bias: '<S152>/Bias1'
             *  Constant: '<S207>/InitialConditionValue'
             */
            if (rtb_RTV_h >
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.ExternalIC_Threshold)
            {
              rtb_Initialise_b =
                rtp_Prm_PneumaticsSystem->ParkBrakes.SwitchONPressure;
            } else {
              rtb_Initialise_b = rtb_RTV + -PneumaticsSystem_P.PAtm;
            }

            /* End of Switch: '<S210>/ExternalIC' */
          } else {
            rtb_Initialise_b = rtb_RTV + -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S207>/Initialise' */

          /* Relay: '<S207>/PressureSwitch' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            PressureSwitch_Mode_b = ((rtb_Initialise_b >=
            rtp_Prm_PneumaticsSystem->ParkBrakes.SwitchONPressure) ||
            ((!(rtb_Initialise_b <=
                rtp_Prm_PneumaticsSystem->ParkBrakes.SwitchOFFPressure)) &&
             localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
             PressureSwitch_Mode_b));

          /* Update for DiscreteTransferFcn: '<S156>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states = localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_tmp;

          /* Update for DiscreteTransferFcn: '<S187>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states_i = localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_tmp_d;

          /* Update for UnitDelay: '<S168>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_h = rtb_AND9;

          /* Update for Memory: '<S175>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput = rtb_LogicalOperator40;

          /* Update for UnitDelay: '<S163>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE = rtb_P2C;

          /* Update for Memory: '<S176>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_j = rtb_AND6;

          /* Update for UnitDelay: '<S164>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_b =
            rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2EmergencyBrakeFailure;

          /* Update for Memory: '<S177>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_l = rtb_IC;

          /* Update for UnitDelay: '<S165>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_e = rtb_RTV_f;

          /* Update for Memory: '<S178>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_d = rtb_LogicalOperator40_j;

          /* Update for UnitDelay: '<S166>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_a =
            rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1BrakeNotApplied;

          /* Update for Memory: '<S179>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_f = rtb_LogicalOperator40_e;

          /* Update for UnitDelay: '<S167>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_j = rtb_AND5;

          /* Update for Memory: '<S180>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_g = rtb_LogicalOperator40_l;

          /* Update for UnitDelay: '<S169>/Delay Input1' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DelayInput1_DSTATE_f =
            rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECULowRPressure;

          /* Update for Memory: '<S209>/Memory' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            Memory_PreviousInput_p = rtb_LogicalOperator40_o;

          /* Update for DiscreteTransferFcn: '<S208>/Discrete Transfer Fcn' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
            DiscreteTransferFcn_states_l = localDW->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].DiscreteTransferFcn_tmp_h;

          /* ForEachSliceAssignment generated from: '<S148>/ParkBrakePressure' */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_ParkBrakePressure_at_inport_0[ForEach_itr_au] =
            rtb_MinMass_os;

          /* Relay: '<S207>/PressureSwitch' */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .PressureSwitch_Mode_b) {
            /* ForEachSliceAssignment generated from: '<S148>/ParkBrakePressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[ForEach_itr_au]
              =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.B27B14_OnOutputValue;
          } else {
            /* ForEachSliceAssignment generated from: '<S148>/ParkBrakePressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[ForEach_itr_au]
              =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.B27B14_OffOutputValue;
          }

          /* ForEachSliceAssignment generated from: '<S148>/FaultMessages' incorporates:
           *  BusAssignment: '<S153>/Bus Assignment'
           *  Logic: '<S153>/AND10'
           *  Logic: '<S153>/AND7'
           *  Logic: '<S153>/AND8'
           *  Logic: '<S153>/AND9'
           */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1EmergencyBrakeFailure = rtb_LogicalOperator40;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU2EmergencyBrakeFailure = rtb_AND6;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1ServiceBrakeFailure = rtb_IC;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1BrakeNotApplied = rtb_LogicalOperator40_j;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1BrakeNotReleased = rtb_LogicalOperator40_e;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1CarLoadPressureLow =
            ((rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1CarLoadPressureLow
              != 0.0) && (localB->CoreSubsys_pn[ForEach_itr]
                          .CoreSubsys_pna[ForEach_itr_au].IfActionSubsystem4.In1
                          != 0.0));
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU2CarLoadPressureLow = ((localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].IfActionSubsystem4.In1 != 0.0) &&
            (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU2CarLoadPressureLow
             != 0.0));
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECULowRPressure = rtb_LogicalOperator40_l;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            AirSuspensionBogie1Deflated = ((rtb_Sqrt != 0.0) &&
            (localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
             IfActionSubsystem5.In1 != 0.0));
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_FaultMessages_at_inport_0[ForEach_itr_au].
            BECU1LoadPressureLow = ((localB->CoreSubsys_pn[ForEach_itr].
            CoreSubsys_pna[ForEach_itr_au].IfActionSubsystem6.In1 != 0.0) &&
            (rtb_ImpSel_InsertedFor_Faults_at_outport_0_BECU1LoadPressureLow !=
             0.0));

          /* ForEachSliceAssignment generated from: '<S148>/ControlPressure' */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_ControlPressure_at_inport_0[ForEach_itr_au] =
            rtb_BrakeCylinderControlPressure;

          /* ForEachSliceAssignment generated from: '<S148>/BrakeSystemPressureGauges' incorporates:
           *  Bias: '<S152>/Bias'
           *  ForEachSliceSelector generated from: '<S3>/Faults'
           *  Logic: '<S148>/NOT'
           *  Product: '<S148>/Product'
           */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[ForEach_itr_au]
            .BrakeCylinderPressureGauge = static_cast<real_T>
            (!(rtu_Faults[ForEach_itr].PressureGuageNotWorking != 0.0)) *
            rtb_Divide;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[ForEach_itr_au]
            .ParkBrakePressureGauge = rtb_MinMass_os + -PneumaticsSystem_P.PAtm;

          /* ForEachSliceAssignment generated from: '<S148>/BrakeCylinderPressure' */
          i = ForEach_itr_au << 1;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[i] =
            rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[0];
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[i + 1] =
            rtb_ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[1];

          /* ForEachSliceAssignment generated from: '<S148>/BSRtoBogieBCFlow' incorporates:
           *  Sum: '<S148>/Sum of Elements'
           */
          rtb_ImpAsg_InsertedFor_BSRtoBogieBCFlow_at_inport_0[ForEach_itr_au] =
            rtb_ImpAsg_InsertedFor_BSRtoBCFlow_at_inport_0[0] +
            rtb_ImpAsg_InsertedFor_BSRtoBCFlow_at_inport_0[1];

          /* ForEachSliceAssignment generated from: '<S148>/BCUPressureTransducers' incorporates:
           *  BusCreator: '<S149>/Bus Creator'
           */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[ForEach_itr_au]
            .BrakeCylinderControlPressure = rtb_MinMass_jc;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[ForEach_itr_au]
            .BrakeCylinderControlVolumePressure = rtb_DiscreteTransferFcn;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[ForEach_itr_au]
            .BrakeReservoirPressure = rtb_SelReset;
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[ForEach_itr_au]
            .AirSuspensionLoadPressure = rtb_PressureSwitch;

          /* Relay: '<S185>/PressureSwitch' */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au]
              .PressureSwitch_Mode) {
            /* ForEachSliceAssignment generated from: '<S148>/BCPressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[ForEach_itr_au] =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.B2728B07_OnOutputValue;
          } else {
            /* ForEachSliceAssignment generated from: '<S148>/BCPressureSwitch' */
            localB->CoreSubsys_pn[ForEach_itr].
              ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[ForEach_itr_au] =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.B2728B07_OffOutputValue;
          }
        }

        /* End of Outputs for SubSystem: '<S121>/BrakingSystemPerBogie' */

        /* Sum: '<S121>/Sum of Elements' incorporates:
         *  Constant: '<S156>/Constant1'
         *  Constant: '<S187>/Constant1'
         *  Constant: '<S208>/Constant1'
         */
        localB->CoreSubsys_pn[ForEach_itr].SumofElements =
          rtb_ImpAsg_InsertedFor_BSRtoBogieBCFlow_at_inport_0[0] +
          rtb_ImpAsg_InsertedFor_BSRtoBogieBCFlow_at_inport_0[1];
      } else {
        if (localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE) {
          /* Disable for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' */
          for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
            /* Disable for If: '<S153>/If' */
            if (localDW->CoreSubsys_pn[ForEach_itr]
                .CoreSubsys_pna[ForEach_itr_au].If_ActiveSubsystem == 0) {
              /* Disable for Outport: '<S170>/Out2' */
              localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                OutportBufferForOut2 =
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Out2_Y0;
            }

            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              If_ActiveSubsystem = -1;

            /* Disable for If: '<S153>/If1' */
            switch (localDW->CoreSubsys_pn[ForEach_itr]
                    .CoreSubsys_pna[ForEach_itr_au].If1_ActiveSubsystem) {
             case 0:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem5,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem5);
              break;

             case 1:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem4,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem4);
              break;

             case 2:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem6,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem6);
              break;
            }

            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              If1_ActiveSubsystem = -1;
          }

          /* End of Disable for SubSystem: '<S121>/BrakingSystemPerBogie' */
          localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S14>/BrakingSystem' */

      /* Outputs for Enabled SubSystem: '<S14>/SandingSystem' incorporates:
       *  EnablePort: '<S122>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].Equipment.HasBogie >
          0.0) {
        /* SignalConversion generated from: '<S122>/Vector Concatenate' */
        rtb_SandingSystemIsolationCock[0] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.SandingSystemIsolationCockBogie1;

        /* SignalConversion generated from: '<S122>/Vector Concatenate' */
        rtb_SandingSystemIsolationCock[1] =
          rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.SandingSystemIsolationCockBogie2;

        /* Outputs for Iterator SubSystem: '<S122>/SandingSystemPerBogie' incorporates:
         *  ForEach: '<S211>/For Each'
         */
        for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
          /* Product: '<S211>/Divide' incorporates:
           *  ForEachSliceSelector generated from: '<S211>/SandingSystemIsolationCock'
           */
          rtb_MainReservoirPipePressureGauge =
            rtb_SandingSystemIsolationCock[ForEach_itr_a] * rtb_P;

          /* InitialCondition: '<S213>/Initialise' incorporates:
           *  Constant: '<S213>/OnlyIC'
           */
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a]
              .Initialise_FirstOutputTime) {
            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a].
              Initialise_FirstOutputTime = false;
            rtb_RTV_f =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.Initialise_Value;
          } else {
            rtb_RTV_f =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.OnlyIC_Value;
          }

          /* End of InitialCondition: '<S213>/Initialise' */

          /* Switch: '<S212>/Initialise' incorporates:
           *  Bias: '<S211>/Bias'
           *  Constant: '<S212>/Constant'
           */
          if (PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.Constant_Value >
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.Initialise_Threshold)
          {
            /* Switch: '<S213>/ExternalIC' incorporates:
             *  Bias: '<S211>/Bias'
             *  Constant: '<S212>/InitialConditionValue'
             */
            if (rtb_RTV_f >
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.ExternalIC_Threshold)
            {
              rtb_PressureSwitch =
                rtp_Prm_PneumaticsSystem->Sanding.SwitchONPressure;
            } else {
              rtb_PressureSwitch = rtb_MainReservoirPipePressureGauge +
                -PneumaticsSystem_P.PAtm;
            }

            /* End of Switch: '<S213>/ExternalIC' */
          } else {
            rtb_PressureSwitch = rtb_MainReservoirPipePressureGauge +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S212>/Initialise' */

          /* Relay: '<S212>/PressureSwitch' */
          localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a].
            PressureSwitch_Mode = ((rtb_PressureSwitch >=
            rtp_Prm_PneumaticsSystem->Sanding.SwitchONPressure) ||
            ((!(rtb_PressureSwitch <=
                rtp_Prm_PneumaticsSystem->Sanding.SwitchOFFPressure)) &&
             localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a].
             PressureSwitch_Mode));
          if (localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pnae[ForEach_itr_a]
              .PressureSwitch_Mode) {
            rtb_PressureSwitch =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.SandingPressureSwitch10_OnOutputValue;
          } else {
            rtb_PressureSwitch =
              PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pnae.SandingPressureSwitch10_OffOutputValue;
          }

          /* End of Relay: '<S212>/PressureSwitch' */

          /* ForEachSliceAssignment generated from: '<S211>/SandingPressure' */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_SandingPressure_at_inport_0[ForEach_itr_a] =
            rtb_MainReservoirPipePressureGauge;

          /* ForEachSliceAssignment generated from: '<S211>/SandingPressureSwitch' incorporates:
           *  Product: '<S211>/Divide1'
           */
          localB->CoreSubsys_pn[ForEach_itr].
            ImpAsg_InsertedFor_SandingPressureSwitch_at_inport_0[ForEach_itr_a] =
            rtb_PressureSwitch *
            rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.SandingValve;
        }

        /* End of Outputs for SubSystem: '<S122>/SandingSystemPerBogie' */
      }

      /* End of Outputs for SubSystem: '<S14>/SandingSystem' */

      /* Outputs for Iterator SubSystem: '<S14>/BogiePressureMapping' incorporates:
       *  ForEach: '<S119>/For Each'
       */
      for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
        /* ForEachSliceAssignment generated from: '<S119>/BogiePressures' incorporates:
         *  ForEachSliceSelector generated from: '<S119>/BrakeControlPressures'
         */
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          BrakeCylinderControlPressure = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_ControlPressure_at_inport_0[ForEach_itr_e];

        /* ForEachSliceSelector generated from: '<S119>/BrakeCylinderPressures' */
        i = ForEach_itr_e << 1;

        /* ForEachSliceAssignment generated from: '<S119>/BogiePressures' incorporates:
         *  ForEachSliceSelector generated from: '<S119>/AirSuspPressure%Variation'
         *  ForEachSliceSelector generated from: '<S119>/AirSuspensionPressures'
         *  ForEachSliceSelector generated from: '<S119>/BrakeCylinderPressures'
         *  ForEachSliceSelector generated from: '<S119>/ParkBrakePressures'
         *  ForEachSliceSelector generated from: '<S119>/SandingPressures'
         */
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          BrakeCylinderPressure[0] = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[i];
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          BrakeCylinderPressure[1] = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[i + 1];
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          ParkBrakePressure = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_ParkBrakePressure_at_inport_0[ForEach_itr_e];
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          SandingSystemPressure = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_SandingPressure_at_inport_0[ForEach_itr_e];
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          AirSuspensionPressure = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0[ForEach_itr_e];
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[ForEach_itr_e].
          AirSuspPressureDiff = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[ForEach_itr_e];
      }

      /* End of Outputs for SubSystem: '<S14>/BogiePressureMapping' */
      for (i = 0; i < 6; i++) {
        /* BusCreator: '<S18>/Bus Creator' incorporates:
         *  Assignment: '<S13>/Assignment'
         *  Assignment: '<S13>/Assignment2'
         *  Constant: '<S13>/Constant'
         */
        localB->CoreSubsys_pn[ForEach_itr].
          BusCreator.AxleBrakes.BrakeCylinderPressures[i] =
          PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_e[i];
        localB->CoreSubsys_pn[ForEach_itr].
          BusCreator.AxleBrakes.ParkBrakePressures[i] =
          PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_e[i];
      }

      /* Assignment: '<S13>/Assignment' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       *  Constant: '<S77>/Constant'
       *  ForEachSliceSelector generated from: '<S3>/PneumaticsConfig'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.BrakeCylinderPressures[0] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[0].
        BrakeCylinderPressure[0];

      /* Assignment: '<S13>/Assignment1' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.BrakeCylinderPressures[2] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[1].
        BrakeCylinderPressure[0];

      /* Assignment: '<S13>/Assignment' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.BrakeCylinderPressures[1] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[0].
        BrakeCylinderPressure[1];

      /* Assignment: '<S13>/Assignment1' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.BrakeCylinderPressures[3] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[1].
        BrakeCylinderPressure[1];

      /* Assignment: '<S13>/Assignment2' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.ParkBrakePressures[0] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[0].ParkBrakePressure;

      /* Assignment: '<S13>/Assignment3' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.ParkBrakePressures[2] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[1].ParkBrakePressure;

      /* Assignment: '<S13>/Assignment2' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.ParkBrakePressures[1] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[0].ParkBrakePressure;

      /* Assignment: '<S13>/Assignment3' incorporates:
       *  BusCreator: '<S18>/Bus Creator'
       */
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.AxleBrakes.ParkBrakePressures[3] =
        rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[1].ParkBrakePressure;

      /* Outputs for Iterator SubSystem: '<S14>/BogiePressureSwitchesMapping' incorporates:
       *  ForEach: '<S120>/For Each'
       */
      for (ForEach_itr_f = 0; ForEach_itr_f < 2; ForEach_itr_f++) {
        /* ForEachSliceAssignment generated from: '<S120>/BogiePressureSwitches' incorporates:
         *  ForEachSliceSelector generated from: '<S120>/AirSuspensionPressureSwitches'
         *  ForEachSliceSelector generated from: '<S120>/BrakeCylinderPressureSwitches'
         *  ForEachSliceSelector generated from: '<S120>/ParkBrakePressureSwitches'
         *  ForEachSliceSelector generated from: '<S120>/SandingPressureSwitches'
         */
        rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[ForEach_itr_f].
          BrakeCylinderPressureSwitch = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[ForEach_itr_f];
        rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[ForEach_itr_f].
          ParkBrakePressureSwitch = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[ForEach_itr_f];
        rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[ForEach_itr_f].
          AirSuspensionPressureSwitch = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[ForEach_itr_f];
        rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[ForEach_itr_f].
          SandingSystemPressureSwitch = localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_SandingPressureSwitch_at_inport_0[ForEach_itr_f];
      }

      /* End of Outputs for SubSystem: '<S14>/BogiePressureSwitchesMapping' */

      /* Bias: '<S230>/Bias' */
      rtb_MainReservoirPipePressureGauge = rtb_P + -PneumaticsSystem_P.PAtm;

      /* Outputs for Iterator SubSystem: '<S16>/Subsystem' incorporates:
       *  ForEach: '<S228>/For Each'
       */
      for (ForEach_itr_c = 0; ForEach_itr_c < 2; ForEach_itr_c++) {
        /* ForEachSliceAssignment generated from: '<S228>/Bogie' incorporates:
         *  ForEachSliceSelector generated from: '<S228>/BCPressure'
         */
        rtb_ImpAsg_InsertedFor_Bogie_at_inport_0[ForEach_itr_c] =
          localB->CoreSubsys_pn[ForEach_itr].
          ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[ForEach_itr_c];
      }

      /* End of Outputs for SubSystem: '<S16>/Subsystem' */

      /* Bias: '<S20>/Add Constant' */
      rtb_PressureSwitch_e = rtu_CommonVehicleConfig[ForEach_itr].Orientation +
        PneumaticsSystem_P.CoreSubsys_pn.AddConstant_Bias;

      /* Switch: '<S20>/Switch' incorporates:
       *  ForEachSliceSelector generated from: '<S3>/PneumaticsConfig'
       *  Logic: '<S20>/Logical Operator1'
       */
      if (rtb_PressureSwitch_e >
          PneumaticsSystem_P.CoreSubsys_pn.Switch_Threshold) {
        rtb_FixPtRelationalOperator_d =
          ((rtu_PneumaticsSystemVehicleConfig[ForEach_itr].
            Equipment.HasDriverCab != 0.0) &&
           (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.PhysicalSignals.PneumaticallyCoupled
            [1] != 0.0));
      } else {
        rtb_FixPtRelationalOperator_d =
          ((rtu_PneumaticsSystemVehicleConfig[ForEach_itr].
            Equipment.HasDriverCab != 0.0) &&
           (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.PhysicalSignals.PneumaticallyCoupled
            [0] != 0.0));
      }

      /* End of Switch: '<S20>/Switch' */

      /* Outputs for Enabled SubSystem: '<S17>/MainReservoir' incorporates:
       *  EnablePort: '<S229>/Enable'
       */
      if (rtu_PneumaticsSystemVehicleConfig[ForEach_itr].
          Equipment.HasMainReservoir > 0.0) {
        /* Saturate: '<S233>/Saturation' incorporates:
         *  Constant: '<S229>/Vol'
         */
        if (rtp_Prm_PneumaticsSystem->MainReservoir.Volume >
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_f) {
          rtb_PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_f;
        } else if (rtp_Prm_PneumaticsSystem->MainReservoir.Volume <
                   PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_h) {
          rtb_PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.Saturation_LowerSat_h;
        } else {
          rtb_PressureSwitch = rtp_Prm_PneumaticsSystem->MainReservoir.Volume;
        }

        /* End of Saturate: '<S233>/Saturation' */

        /* Fcn: '<S233>/RT // V' */
        rtb_RTV_f = 84102.72 / rtb_PressureSwitch;

        /* Product: '<S233>/MaxMass' incorporates:
         *  Constant: '<S229>/Constant'
         */
        rtb_PressureSwitch = (PneumaticsSystem_P.PAtm +
                              rtp_Prm_PneumaticsSystem->MainReservoir.MaxPressure)
          / rtb_RTV_f;

        /* Logic: '<S233>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S3>/Overrides'
         */
        rtb_IC = (rtu_Overrides[ForEach_itr].Reset != 0.0);

        /* InitialCondition: '<S251>/IC' */
        if (localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_c) {
          localDW->CoreSubsys_pn[ForEach_itr].IC_FirstOutputTime_c = false;
          rtb_IC = PneumaticsSystem_P.CoreSubsys_pn.IC_Value_i;
        }

        /* End of InitialCondition: '<S251>/IC' */

        /* UnitDelay: '<S229>/Unit Delay' */
        rtb_UnitDelay_a = localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_d;

        /* Logic: '<S231>/Logical Operator5' */
        rtb_LogicalOperator5_k =
          !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainReservoirIsolationCock
            != 0.0);

        /* Outputs for Atomic SubSystem: '<S231>/MR Pipe Two Way Valve' */
        PneumaticsSystem_MRPipeTwoWayValve(rtb_P, rtb_UnitDelay_a,
          rtb_LogicalOperator5_k, &localB->CoreSubsys_pn[ForEach_itr].
          MRPipeTwoWayValve, &PneumaticsSystem_P.CoreSubsys_pn.MRPipeTwoWayValve,
          PneumaticsSystem_P.CoreSubsys_pn.MRPipeTwoWayValve_p_deadband);

        /* End of Outputs for SubSystem: '<S231>/MR Pipe Two Way Valve' */

        /* Relay: '<S231>/Overpressure' */
        localDW->CoreSubsys_pn[ForEach_itr].Overpressure_Mode =
          ((rtb_UnitDelay_a >=
            rtp_Prm_PneumaticsSystem->MainReservoir.BlowOffONPressure +
            PneumaticsSystem_P.PAtm) || ((!(rtb_UnitDelay_a <=
              rtp_Prm_PneumaticsSystem->MainReservoir.BlowOffOFFPressure +
              PneumaticsSystem_P.PAtm)) && localDW->CoreSubsys_pn[ForEach_itr].
            Overpressure_Mode));

        /* RelationalOperator: '<S235>/FixPt Relational Operator' incorporates:
         *  UnitDelay: '<S235>/Delay Input1'
         */
        rtb_FixPtRelationalOperator = (static_cast<int32_T>
          (rtb_FixPtRelationalOperator_d) > static_cast<int32_T>
          (localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_pn));

        /* Outputs for Atomic SubSystem: '<S231>/TimerOffDelay NoInit' */
        PneumaticsSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator,
          &localB->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit_d,
          &localDW->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit_d,
          &PneumaticsSystem_P.CoreSubsys_pn.TimerOffDelayNoInit_d);

        /* End of Outputs for SubSystem: '<S231>/TimerOffDelay NoInit' */

        /* Switch: '<S251>/SelReset' incorporates:
         *  Constant: '<S231>/Constant'
         *  Constant: '<S233>/Constant1'
         *  Product: '<S233>/ResetMass'
         *  Relay: '<S231>/Overpressure'
         *  SampleTimeMath: '<S251>/Weighted Sample Time'
         *  Sum: '<S231>/Add'
         *  Sum: '<S251>/Sum1'
         *  Switch: '<S233>/SelReset'
         *  UnitDelay: '<S251>/Unit Delay1'
         *
         * About '<S251>/Weighted Sample Time':
         *  y = u * K where K = ( w * Ts )
         */
        if (rtb_IC) {
          rtb_P2C = (rtp_Prm_PneumaticsSystem->MainReservoir.ResetPressure +
                     PneumaticsSystem_P.PAtm) / rtb_RTV_f;
        } else {
          if (localDW->CoreSubsys_pn[ForEach_itr].Overpressure_Mode) {
            /* Relay: '<S231>/Overpressure' */
            rtb_MinMass_os = PneumaticsSystem_P.CoreSubsys_pn.Overpressure_YOn_f;
          } else {
            /* Relay: '<S231>/Overpressure' */
            rtb_MinMass_os =
              PneumaticsSystem_P.CoreSubsys_pn.Overpressure_YOff_p;
          }

          /* Logic: '<S231>/Logical Operator1' */
          rtb_LogicalOperator1_f = !(rtb_MinMass_os != 0.0);

          /* Logic: '<S231>/Logical Operator2' */
          rtb_LogicalOperator2_a =
            !(rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainReservoirDrainCock
              != 0.0);

          /* Outputs for Atomic SubSystem: '<S231>/Coupling-ExtraMRP' */
          /* Switch: '<S234>/FlowNoflow' incorporates:
           *  Constant: '<S231>/Constant1'
           *  Constant: '<S234>/Cd'
           *  Constant: '<S234>/PuPd'
           *  Constant: '<S234>/Zero1'
           *  Constant: '<S234>/piRsqrd'
           *  Logic: '<S231>/Logical Operator4'
           *  Product: '<S234>/Product'
           *  Product: '<S234>/Product4'
           *  Product: '<S234>/Product5'
           *  RelationalOperator: '<S234>/ChkSonic'
           *  Sqrt: '<S234>/Sqrt'
           *  Switch: '<S234>/P2C'
           */
          if (!localB->CoreSubsys_pn[ForEach_itr].
              TimerOffDelayNoInit_d.LogicalOperator1) {
            rtb_P2C = PneumaticsSystem_P.CoreSubsys_pn.Zero1_Value;
          } else {
            if (rtb_UnitDelay_a > PneumaticsSystem_P.CoreSubsys_pn.PuPd_Value *
                PneumaticsSystem_P.CoreSubsys_pn.Constant1_Value) {
              /* Switch: '<S234>/P2C' incorporates:
               *  Constant: '<S234>/PuPd'
               *  Product: '<S234>/Product1'
               */
              rtb_P2C = rtb_UnitDelay_a /
                PneumaticsSystem_P.CoreSubsys_pn.PuPd_Value;
            } else {
              /* Switch: '<S234>/P2C' incorporates:
               *  Constant: '<S231>/Constant1'
               */
              rtb_P2C = PneumaticsSystem_P.CoreSubsys_pn.Constant1_Value;
            }

            /* Sum: '<S234>/Sum' */
            rtb_Sqrt = rtb_UnitDelay_a - rtb_P2C;

            /* DeadZone: '<S234>/Dead Zone' */
            if (rtb_Sqrt >
                PneumaticsSystem_P.CoreSubsys_pn.CouplingExtraMRP_p_deadband) {
              rtb_Sqrt -=
                PneumaticsSystem_P.CoreSubsys_pn.CouplingExtraMRP_p_deadband;
            } else if (rtb_Sqrt >=
                       -PneumaticsSystem_P.CoreSubsys_pn.CouplingExtraMRP_p_deadband)
            {
              rtb_Sqrt = 0.0;
            } else {
              rtb_Sqrt -=
                -PneumaticsSystem_P.CoreSubsys_pn.CouplingExtraMRP_p_deadband;
            }

            /* End of DeadZone: '<S234>/Dead Zone' */

            /* Product: '<S234>/Product3' incorporates:
             *  Constant: '<S234>/C1'
             *  Product: '<S234>/Product2'
             */
            rtb_P2C = rtb_Sqrt * rtb_P2C *
              PneumaticsSystem_P.CoreSubsys_pn.C1_Value;

            /* MinMax: '<S234>/MinMax' incorporates:
             *  Constant: '<S234>/Zero'
             */
            if ((!(rtb_P2C > PneumaticsSystem_P.CoreSubsys_pn.Zero_Value)) &&
                (!rtIsNaN(PneumaticsSystem_P.CoreSubsys_pn.Zero_Value))) {
              rtb_P2C = PneumaticsSystem_P.CoreSubsys_pn.Zero_Value;
            }

            /* End of MinMax: '<S234>/MinMax' */
            rtb_P2C = sqrt(rtb_P2C) *
              PneumaticsSystem_P.CoreSubsys_pn.piRsqrd_Value *
              PneumaticsSystem_P.CoreSubsys_pn.Cd_Value;
          }

          /* End of Switch: '<S234>/FlowNoflow' */
          /* End of Outputs for SubSystem: '<S231>/Coupling-ExtraMRP' */

          /* Outputs for Atomic SubSystem: '<S231>/MR Vent Drain' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_a, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator2_a, &localB->CoreSubsys_pn[ForEach_itr].
            MRVentDrain, &PneumaticsSystem_P.CoreSubsys_pn.MRVentDrain,
            PneumaticsSystem_P.CoreSubsys_pn.MRVentDrain_p_deadband);

          /* End of Outputs for SubSystem: '<S231>/MR Vent Drain' */

          /* Outputs for Atomic SubSystem: '<S231>/MR Blowoff' */
          PneumaticsSystem_BSRVentDrain(rtb_UnitDelay_a, PneumaticsSystem_P.PAtm,
            rtb_LogicalOperator1_f, &localB->CoreSubsys_pn[ForEach_itr].
            MRBlowoff, &PneumaticsSystem_P.CoreSubsys_pn.MRBlowoff,
            PneumaticsSystem_P.CoreSubsys_pn.MRBlowoff_p_deadband);

          /* End of Outputs for SubSystem: '<S231>/MR Blowoff' */

          /* Switch: '<S231>/Switch1' incorporates:
           *  Constant: '<S231>/Compressor Flow Rate'
           *  Constant: '<S231>/Constant'
           *  Product: '<S231>/Product'
           */
          if (rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainAirSupplyIsolationCock
              > PneumaticsSystem_P.CoreSubsys_pn.Switch1_Threshold_j) {
            rtb_MinMass_os =
              rtp_Prm_PneumaticsSystem->MainReservoir.CompressorMassFlowRate *
              rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.MainCompressorOn;
          } else {
            rtb_MinMass_os = 0.0;
          }

          /* End of Switch: '<S231>/Switch1' */
          rtb_P2C = ((((rtb_MinMass_os + localB->CoreSubsys_pn[ForEach_itr].
                        MRPipeTwoWayValve.Add) - localB->
                       CoreSubsys_pn[ForEach_itr].MRBlowoff.FlowNoflow) -
                      localB->CoreSubsys_pn[ForEach_itr].MRVentDrain.FlowNoflow)
                     - rtb_P2C) *
            PneumaticsSystem_P.CoreSubsys_pn.WeightedSampleTime_WtEt_j +
            localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_f;
        }

        /* End of Switch: '<S251>/SelReset' */

        /* Switch: '<S252>/Switch2' incorporates:
         *  RelationalOperator: '<S252>/LowerRelop1'
         */
        if (rtb_P2C > rtb_PressureSwitch) {
          rtb_P2C = rtb_PressureSwitch;
        } else {
          /* Product: '<S233>/MinMass' incorporates:
           *  Constant: '<S229>/pAtm'
           */
          rtb_Sqrt = PneumaticsSystem_P.PAtm / rtb_RTV_f;

          /* Switch: '<S252>/Switch' incorporates:
           *  RelationalOperator: '<S252>/UpperRelop'
           */
          if (rtb_P2C < rtb_Sqrt) {
            rtb_P2C = rtb_Sqrt;
          }

          /* End of Switch: '<S252>/Switch' */
        }

        /* End of Switch: '<S252>/Switch2' */

        /* Product: '<S233>/ConvertToPressure' */
        localB->CoreSubsys_pn[ForEach_itr].P = rtb_P2C * rtb_RTV_f;

        /* InitialCondition: '<S250>/Initialise' incorporates:
         *  Constant: '<S250>/OnlyIC'
         */
        if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_l) {
          localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_l =
            false;
          rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_l;
        } else {
          rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_a;
        }

        /* End of InitialCondition: '<S250>/Initialise' */

        /* Switch: '<S232>/Initialise' incorporates:
         *  Bias: '<S229>/Bias'
         *  Constant: '<S232>/Constant'
         */
        if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_de >
            PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_ir) {
          /* Switch: '<S250>/ExternalIC' incorporates:
           *  Bias: '<S229>/Bias'
           *  Constant: '<S232>/InitialConditionValue'
           */
          if (rtb_RTV_f >
              PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_k) {
            rtb_PressureSwitch =
              rtp_Prm_PneumaticsSystem->MainReservoir.SwitchONPressure;
          } else {
            rtb_PressureSwitch = localB->CoreSubsys_pn[ForEach_itr].P +
              -PneumaticsSystem_P.PAtm;
          }

          /* End of Switch: '<S250>/ExternalIC' */
        } else {
          rtb_PressureSwitch = localB->CoreSubsys_pn[ForEach_itr].P +
            -PneumaticsSystem_P.PAtm;
        }

        /* End of Switch: '<S232>/Initialise' */

        /* Relay: '<S232>/PressureSwitch' */
        localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_k =
          ((rtb_PressureSwitch >=
            rtp_Prm_PneumaticsSystem->MainReservoir.SwitchONPressure) ||
           ((!(rtb_PressureSwitch <=
               rtp_Prm_PneumaticsSystem->MainReservoir.SwitchOFFPressure)) &&
            localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_k));
        if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_k) {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.MRPressureSwitch06_OnOutputValue;
        } else {
          localB->CoreSubsys_pn[ForEach_itr].PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.MRPressureSwitch06_OffOutputValue;
        }

        /* End of Relay: '<S232>/PressureSwitch' */

        /* Update for UnitDelay: '<S229>/Unit Delay' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_d =
          localB->CoreSubsys_pn[ForEach_itr].P;

        /* Update for UnitDelay: '<S235>/Delay Input1' */
        localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_pn =
          rtb_FixPtRelationalOperator_d;

        /* Update for UnitDelay: '<S251>/Unit Delay1' */
        localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_f = rtb_P2C;
      }

      /* End of Outputs for SubSystem: '<S17>/MainReservoir' */

      /* InitialCondition: '<S257>/Initialise' incorporates:
       *  Constant: '<S257>/OnlyIC'
       *  ForEachSliceSelector generated from: '<S3>/PneumaticsConfig'
       */
      if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime) {
        localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime = false;
        rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_e;
      } else {
        rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_l;
      }

      /* End of InitialCondition: '<S257>/Initialise' */

      /* Switch: '<S253>/Initialise' incorporates:
       *  Constant: '<S253>/Constant'
       */
      if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_k >
          PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_hk) {
        /* Switch: '<S257>/ExternalIC' incorporates:
         *  Constant: '<S253>/InitialConditionValue'
         */
        if (rtb_RTV_f > PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_kz)
        {
          rtb_PressureSwitch_e =
            rtp_Prm_PneumaticsSystem->MainReservoirPipe.SwitchONPressure;
        } else {
          rtb_PressureSwitch_e = rtb_MainReservoirPipePressureGauge;
        }

        /* End of Switch: '<S257>/ExternalIC' */
      } else {
        rtb_PressureSwitch_e = rtb_MainReservoirPipePressureGauge;
      }

      /* End of Switch: '<S253>/Initialise' */

      /* Relay: '<S253>/PressureSwitch' */
      localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode =
        ((rtb_PressureSwitch_e >=
          rtp_Prm_PneumaticsSystem->MainReservoirPipe.SwitchONPressure) ||
         ((!(rtb_PressureSwitch_e <=
             rtp_Prm_PneumaticsSystem->MainReservoirPipe.SwitchOFFPressure)) &&
          localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode));
      if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode) {
        rtb_PressureSwitch_e =
          PneumaticsSystem_P.CoreSubsys_pn.A00A14_OnOutputValue;
      } else {
        rtb_PressureSwitch_e =
          PneumaticsSystem_P.CoreSubsys_pn.A00A14_OffOutputValue;
      }

      /* End of Relay: '<S253>/PressureSwitch' */

      /* InitialCondition: '<S258>/Initialise' incorporates:
       *  Constant: '<S258>/OnlyIC'
       */
      if (localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_d) {
        localDW->CoreSubsys_pn[ForEach_itr].Initialise_FirstOutputTime_d = false;
        rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.Initialise_Value_j;
      } else {
        rtb_RTV_f = PneumaticsSystem_P.CoreSubsys_pn.OnlyIC_Value_lu;
      }

      /* End of InitialCondition: '<S258>/Initialise' */

      /* Switch: '<S254>/Initialise' incorporates:
       *  Constant: '<S254>/Constant'
       */
      if (PneumaticsSystem_P.CoreSubsys_pn.Constant_Value_p2 >
          PneumaticsSystem_P.CoreSubsys_pn.Initialise_Threshold_b) {
        /* Switch: '<S258>/ExternalIC' incorporates:
         *  Constant: '<S254>/InitialConditionValue'
         */
        if (rtb_RTV_f > PneumaticsSystem_P.CoreSubsys_pn.ExternalIC_Threshold_i0)
        {
          rtb_PressureSwitch =
            PneumaticsSystem_P.CoreSubsys_pn.B27B22_OnSwitchValue;
        } else {
          rtb_PressureSwitch = rtb_MainReservoirPipePressureGauge;
        }

        /* End of Switch: '<S258>/ExternalIC' */
      } else {
        rtb_PressureSwitch = rtb_MainReservoirPipePressureGauge;
      }

      /* End of Switch: '<S254>/Initialise' */

      /* Relay: '<S254>/PressureSwitch' */
      localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_e =
        ((rtb_PressureSwitch >=
          PneumaticsSystem_P.CoreSubsys_pn.B27B22_OnSwitchValue) ||
         ((!(rtb_PressureSwitch <=
             PneumaticsSystem_P.CoreSubsys_pn.B27B22_OffSwitchValue)) &&
          localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_e));
      if (localDW->CoreSubsys_pn[ForEach_itr].PressureSwitch_Mode_e) {
        rtb_PressureSwitch =
          PneumaticsSystem_P.CoreSubsys_pn.B27B22_OnOutputValue;
      } else {
        rtb_PressureSwitch =
          PneumaticsSystem_P.CoreSubsys_pn.B27B22_OffOutputValue;
      }

      /* End of Relay: '<S254>/PressureSwitch' */

      /* BusCreator: '<S18>/Bus Creator' incorporates:
       *  BusAssignment: '<S16>/Bus Assignment'
       *  BusAssignment: '<S19>/Bus Assignment'
       *  BusAssignment: '<S21>/Bus Assignment'
       *  BusCreator: '<S22>/Bus Creator5'
       *  BusCreator: '<S23>/Bus Creator5'
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       */
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Audio.HornLow =
        localB->CoreSubsys_pn[ForEach_itr].HornLow;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Audio.HornHigh =
        localB->CoreSubsys_pn[ForEach_itr].HornHigh;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.Audio.PneumaticPressureRelease = localB->
        CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit1.LogicalOperator1;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Audio.EmergencyBrakeActive =
        localB->CoreSubsys_pn[ForEach_itr].TimerOffDelayNoInit.LogicalOperator1;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Debug.BrakeReservoirPressure
        = localB->CoreSubsys_pn[ForEach_itr].P_a;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Debug.MainReservoirPressure =
        localB->CoreSubsys_pn[ForEach_itr].P;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.Debug.MainReservoirPipePressure = rtb_P;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.Debug.AuxiliaryReservoirPressure = localB->
        CoreSubsys_pn[ForEach_itr].P_d;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.Debug.PantographCylinderPressure = localB->
        CoreSubsys_pn[ForEach_itr].P_e;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.Debug.VCBCylinderPressure =
        localB->CoreSubsys_pn[ForEach_itr].P_o;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureGauges.MainReservoirPressureGauge =
        rtb_MainReservoirPipePressureGauge;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureGauges.SRPressureGauge = localB->
        CoreSubsys_pn[ForEach_itr].Bias;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.BrakeReservoirPressureSwitch =
        localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_g;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.HornHighPressureSwitch =
        localB->CoreSubsys_pn[ForEach_itr].HornLowPressureSwitch;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.HornLowPressureSwitch =
        localB->CoreSubsys_pn[ForEach_itr].HornHighPressureSwitch;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.MainReservoirPressureSwitch =
        localB->CoreSubsys_pn[ForEach_itr].PressureSwitch;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.AuxiliaryReservoirPressureSwitch =
        localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_e;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.MainReservoirPipePressureSwitch =
        rtb_PressureSwitch_e;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.MRPS_TractionCutout = rtb_PressureSwitch;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.PressureSwitches.PS3 =
        localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_l;
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.PressureSwitches.PS2 =
        localB->CoreSubsys_pn[ForEach_itr].PressureSwitch_d;
      localB->CoreSubsys_pn[ForEach_itr].
        BusCreator.PressureSwitches.VCBPressureSwitch = localB->
        CoreSubsys_pn[ForEach_itr].PressureSwitch_j;
      memcpy(&localB->CoreSubsys_pn[ForEach_itr].BusCreator.Debug.Bogie[0],
             &rtb_ImpAsg_InsertedFor_BogiePressures_at_inport_0[0], sizeof
             (BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie) << 1U);
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.PressureGauges.Bogie[0] =
        rtb_ImpAsg_InsertedFor_Bogie_at_inport_0[0];
      memcpy(&localB->CoreSubsys_pn[ForEach_itr].
             BusCreator.PressureSwitches.Bogie[0],
             &rtb_ImpAsg_InsertedFor_BogiePressureSwitches_at_inport_0[0],
             sizeof(BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie) << 1U);
      memcpy(&localB->CoreSubsys_pn[ForEach_itr].
             BusCreator.PressureTransducers.Bogie[0], &localB->
             CoreSubsys_pn[ForEach_itr].
             ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[0], sizeof
             (BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie) << 1U);
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.TCMS.Bogie[0] =
        localB->CoreSubsys_pn[ForEach_itr].
        ImpAsg_InsertedFor_FaultMessages_at_inport_0[0];
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.PressureGauges.Bogie[1] =
        rtb_ImpAsg_InsertedFor_Bogie_at_inport_0[1];
      localB->CoreSubsys_pn[ForEach_itr].BusCreator.TCMS.Bogie[1] =
        localB->CoreSubsys_pn[ForEach_itr].
        ImpAsg_InsertedFor_FaultMessages_at_inport_0[1];

      /* Update for UnitDelay: '<S230>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE = rtb_P;

      /* Update for UnitDelay: '<S9>/Unit Delay' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE =
        localB->CoreSubsys_pn[ForEach_itr].BSRCharge_b.FlowNoflow;

      /* Update for UnitDelay: '<S17>/Unit Delay' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_k =
        localB->CoreSubsys_pn[ForEach_itr].MRPipeTwoWayValve.Add;

      /* Update for UnitDelay: '<S9>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_k =
        localB->CoreSubsys_pn[ForEach_itr].BSRCharge.FlowNoflow;

      /* Update for UnitDelay: '<S9>/Unit Delay3' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay3_DSTATE =
        localB->CoreSubsys_pn[ForEach_itr].ARChargefromMRP.FlowNoflow;

      /* Update for UnitDelay: '<S273>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_a =
        rtb_PneumaticPressureRelease;

      /* Update for UnitDelay: '<S24>/Unit Delay' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay_DSTATE_g = rtb_P_e;

      /* Update for UnitDelay: '<S9>/Unit Delay5' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay5_DSTATE =
        localB->CoreSubsys_pn[ForEach_itr].Sum;

      /* Update for UnitDelay: '<S27>/Unit Delay1' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay1_DSTATE_e = rtb_RTV_ai;

      /* Update for UnitDelay: '<S40>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornLowIsolationCock;

      /* Update for UnitDelay: '<S46>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_d =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.HornHighIsolationCock;

      /* Update for UnitDelay: '<S41>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_n =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeSupplyReservoirIsolationCock;

      /* Update for UnitDelay: '<S48>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_a =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainReservoirIsolationCock;

      /* Update for UnitDelay: '<S49>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_dh =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie1;

      /* Update for UnitDelay: '<S50>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_g =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionSystemIsolationCockBogie2;

      /* Update for UnitDelay: '<S51>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie1;

      /* Update for UnitDelay: '<S52>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.BrakeCylinderIsolationCockBogie2;

      /* Update for UnitDelay: '<S53>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_i =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie1;

      /* Update for UnitDelay: '<S54>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_nm =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.ParkingBrakeIsolationCockBogie2;

      /* Update for UnitDelay: '<S55>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_b2 =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.MainAirSupplyIsolationCock;

      /* Update for UnitDelay: '<S42>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_da =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.InterCarIsolationCockEnd1;

      /* Update for UnitDelay: '<S43>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_c4 =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.InterCarIsolationCockEnd2;

      /* Update for UnitDelay: '<S44>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_p =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.UncouplingIsolationCock;

      /* Update for UnitDelay: '<S45>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_f =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.EPIsolationCock;

      /* Update for UnitDelay: '<S47>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_fx =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.InputControlStates.AirSuspensionReservoirIsolationCock;

      /* Update for UnitDelay: '<S36>/Delay Input1' */
      localDW->CoreSubsys_pn[ForEach_itr].DelayInput1_DSTATE_ia =
        rtb_ImpSel_InsertedFor_PneumaticsInputs_at_outport_0.ElectricalSignals.NoEmergencyBrakeValve;

      /* Update for UnitDelay: '<S9>/Unit Delay4' */
      localDW->CoreSubsys_pn[ForEach_itr].UnitDelay4_DSTATE =
        localB->CoreSubsys_pn[ForEach_itr].SumofElements;
    } else {
      if (localDW->CoreSubsys_pn[ForEach_itr].PneumaticsSystem_MODE) {
        /* Disable for Enabled SubSystem: '<S14>/BrakingSystem' */
        if (localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE) {
          /* Disable for Iterator SubSystem: '<S121>/BrakingSystemPerBogie' */
          for (ForEach_itr_au = 0; ForEach_itr_au < 2; ForEach_itr_au++) {
            /* Disable for If: '<S153>/If' */
            if (localDW->CoreSubsys_pn[ForEach_itr]
                .CoreSubsys_pna[ForEach_itr_au].If_ActiveSubsystem == 0) {
              /* Disable for Outport: '<S170>/Out2' */
              localB->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                OutportBufferForOut2 =
                PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Out2_Y0;
            }

            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              If_ActiveSubsystem = -1;

            /* Disable for If: '<S153>/If1' */
            switch (localDW->CoreSubsys_pn[ForEach_itr]
                    .CoreSubsys_pna[ForEach_itr_au].If1_ActiveSubsystem) {
             case 0:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem5,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem5);
              break;

             case 1:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem4,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem4);
              break;

             case 2:
              PneumaticsSystem_IfActionSubsystem5_Disable(&localB->
                CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
                IfActionSubsystem6,
                &PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.IfActionSubsystem6);
              break;
            }

            localDW->CoreSubsys_pn[ForEach_itr].CoreSubsys_pna[ForEach_itr_au].
              If1_ActiveSubsystem = -1;
          }

          /* End of Disable for SubSystem: '<S121>/BrakingSystemPerBogie' */
          localDW->CoreSubsys_pn[ForEach_itr].BrakingSystem_MODE = false;
        }

        /* End of Disable for SubSystem: '<S14>/BrakingSystem' */
        localDW->CoreSubsys_pn[ForEach_itr].PneumaticsSystem_MODE = false;
      }
    }

    /* End of ForEachSliceSelector generated from: '<S3>/CommonConfig' */
    /* End of Outputs for SubSystem: '<S3>/PneumaticsSystem' */

    /* ForEachSliceAssignment generated from: '<S3>/PenumaticsVehicleOut' */
    rty_PneumaticsSystemVehicleOut[ForEach_itr] = localB->
      CoreSubsys_pn[ForEach_itr].BusCreator;
  }

  /* End of Outputs for SubSystem: '<Root>/PneumaticsPerVehicle' */

  /* Outputs for Iterator SubSystem: '<Root>/ExtractMRP' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  for (ForEach_itr_e0 = 0; ForEach_itr_e0 < 8; ForEach_itr_e0++) {
    /* ForEachSliceAssignment generated from: '<S1>/MRP' incorporates:
     *  ForEachSliceSelector generated from: '<S1>/In1'
     */
    rtb_ImpAsg_InsertedFor_MRP_at_inport_0[ForEach_itr_e0] =
      rty_PneumaticsSystemVehicleOut[ForEach_itr_e0].
      Debug.MainReservoirPipePressure;
  }

  /* End of Outputs for SubSystem: '<Root>/ExtractMRP' */

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0], &rtb_ImpAsg_InsertedFor_MRP_at_inport_0
         [0], sizeof(real_T) << 3U);
}

/* Model initialize function */
void PneumaticsSystem_initialize(const char_T **rt_errorStatus,
  RT_MODEL_PneumaticsSystem_T *const PneumaticsSystem_M, B_PneumaticsSystem_c_T *
  localB, DW_PneumaticsSystem_f_T *localDW, rtwCAPI_ModelMappingInfo
  *rt_ParentMMI, const char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T
  rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_a = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_b = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_d = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_m = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_f = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_e = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.Saturation_UpperSat_mq = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_n = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_h = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.Saturation_UpperSat_p = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys_pna.CoreSubsys.Saturation_UpperSat
    = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat = rtInf;
  PneumaticsSystem_P.CoreSubsys_pn.CoreSubsys.Saturation_UpperSat_m = rtInf;

  /* initialize error status */
  rtmSetErrorStatusPointer(PneumaticsSystem_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_PneumaticsSystem_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_PneumaticsSystem_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    PneumaticsSystem_InitializeDataMapInfo(PneumaticsSystem_M, localB, localDW);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(PneumaticsSystem_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(PneumaticsSystem_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(PneumaticsSystem_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
