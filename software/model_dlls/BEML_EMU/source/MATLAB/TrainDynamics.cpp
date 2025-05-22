/*
 * Code generation for system model 'TrainDynamics'
 *
 * Model                      : TrainDynamics
 * Model version              : 1.788
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "TrainDynamics_capi.h"
#include "TrainDynamics.h"
#include "TrainDynamics_private.h"

P_TrainDynamics_T TrainDynamics_P = {
  /* Variable: PRM_TrainDynamics
   * Referenced by: '<S138>/Constant'
   */
  {
    1.0e-5
  },

  /* Variable: MaxAxles
   * Referenced by: '<S141>/Saturation'
   */
  6.0,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<Root>/Unit Delay'
   */
  {
    false,                             /* Enabled */
    0U,                                /* VehicleID */
    0.0,                               /* HeadPosition */
    0.0,                               /* TailPosition */
    0.0,                               /* Velocity */
    0.0,                               /* Mass */
    0.0,                               /* MovingForce */
    0.0,                               /* HeadCouplerForce */
    0.0                                /* TailCouplerForce */
  },

  /* Computed Parameter: InitialPosition_Y0
   * Referenced by: '<S6>/InitialPosition'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: -inf
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Start of '<S4>/CoreSubsys' */
  {
    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
     * Referenced by: '<S172>/UD'
     */
    0.0,

    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput_a
     * Referenced by: '<S137>/UD'
     */
    0.0,

    /* Mask Parameter: MinValue_const
     * Referenced by: '<S37>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_n
     * Referenced by: '<S38>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_b
     * Referenced by: '<S36>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_o
     * Referenced by: '<S35>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_d
     * Referenced by: '<S41>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_h
     * Referenced by: '<S45>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_c
     * Referenced by: '<S42>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_a
     * Referenced by: '<S44>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_i
     * Referenced by: '<S43>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_nv
     * Referenced by: '<S49>/Constant'
     */
    1.0E+7,

    /* Mask Parameter: MinValue_const_l
     * Referenced by: '<S48>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_aa
     * Referenced by: '<S40>/Constant'
     */
    500000.0,

    /* Mask Parameter: MinValue_const_bl
     * Referenced by: '<S46>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_aae
     * Referenced by: '<S50>/Constant'
     */
    0.0,

    /* Mask Parameter: MaxValue_const
     * Referenced by: '<S47>/Constant'
     */
    0.0,

    /* Mask Parameter: MaxValue_const_l
     * Referenced by: '<S39>/Constant'
     */
    0.5,

    /* Mask Parameter: MaxValue_const_g
     * Referenced by: '<S52>/Constant'
     */
    0.0,

    /* Mask Parameter: MaxValue_const_l1
     * Referenced by: '<S51>/Constant'
     */
    0.0,

    /* Mask Parameter: PositiveMovement_const
     * Referenced by: '<S184>/Constant'
     */
    0.1,

    /* Mask Parameter: NegativeMovement_const
     * Referenced by: '<S183>/Constant'
     */
    -0.1,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S140>/Constant'
     */
    0.0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S185>/Constant'
     */
    0,

    /* Computed Parameter: DynamicsVehicleConfig_Y0
     * Referenced by: '<S10>/DynamicsVehicleConfig'
     */
    {
      0.0,                             /* AerodynamicDragCoeff_Front */
      0.0,                             /* AerodynamicDragCoeff_Trail */
      0.0,                             /* BearingFrictionCoeff */
      0.0,                             /* BearingDynamicFrictionCoeff */
      0.0,                             /* LateralFrictionCoeff */
      0.0,                             /* RailStaticFrictionCoeff */
      0.0,                             /* RailDynamicFrictionCoeff */
      0.0,                             /* RailSandedStaticFrictionCoeff */
      0.0,                             /* RailSandedDynamicFrictionCoeff */
      0.0,                             /* SpringRate */
      0.0,                             /* SlackSpringRate */
      0.0,                             /* DampingRate */
      0.0,                             /* SlackDampingRate */
      false,                           /* EnableDampingAdjustmentByMass */
      0.0,                             /* DampingAdjustmentDesignMass */
      0.0,                             /* SlackLength */
      0.0,                             /* DampingLeadIn */
      0.0,                             /* CouplerShockTime */
      DragCalculationMethod_Fundamental,/* DragCalculationMethod */

      {
        0.0,                           /* DavisCoeffA1 */
        0.0,                           /* DavisCoeffA2 */
        0.0,                           /* DavisCoeffB1 */
        0.0,                           /* DavisCoeffB2 */
        0.0,                           /* DavisCoeffLeadCarC */
        0.0                            /* DavisCoeffTailCarC */
      },                               /* DavisCoefficients */
      0.0,                             /* UseSandFrictionCoeffs */
      0.0,                             /* SandStaticFrictionFactor */
      0.0,                             /* SandDynamicFrictionFactor */
      0.0                              /* InitialVelocity */
    },

    /* Computed Parameter: Coupler_Out_Y0
     * Referenced by: '<S57>/Coupler_Out'
     */
    {
      0.0,                             /* Force */
      0.0,                             /* SpringForce */
      0.0,                             /* DampingForce */
      0.0,                             /* BuffForce */
      0.0,                             /* DraftForce */
      0.0,                             /* ImpactForce */
      0.0,                             /* Breakage */
      0.0,                             /* Extension */
      0.0,                             /* ExtensionRate */
      0.0,                             /* ExternalCoupling */

      {
        0.0,                           /* Mass */
        0.0,                           /* Time */
        0.0,                           /* Position */
        0.0,                           /* Velocity */
        0.0,                           /* Acceleration */
        0.0,                           /* Gradient */
        0.0,                           /* Radius */
        0.0,                           /* TractiveForce */
        0.0,                           /* BrakingForce */
        0.0,                           /* OtherCouplerForce */
        0.0                            /* OtherCouplerForceRate */
      }                                /* Mimic */
    },

    /* Computed Parameter: UnitDelay1_InitialCondition
     * Referenced by: '<S11>/Unit Delay1'
     */
    {
      0.0,                             /* Force */
      0.0,                             /* SpringForce */
      0.0,                             /* DampingForce */
      0.0,                             /* BuffForce */
      0.0,                             /* DraftForce */
      0.0,                             /* ImpactForce */
      0.0,                             /* Breakage */
      0.0,                             /* Extension */
      0.0,                             /* ExtensionRate */
      0.0,                             /* ExternalCoupling */

      {
        0.0,                           /* Mass */
        0.0,                           /* Time */
        0.0,                           /* Position */
        0.0,                           /* Velocity */
        0.0,                           /* Acceleration */
        0.0,                           /* Gradient */
        0.0,                           /* Radius */
        0.0,                           /* TractiveForce */
        0.0,                           /* BrakingForce */
        0.0,                           /* OtherCouplerForce */
        0.0                            /* OtherCouplerForceRate */
      }                                /* Mimic */
    },

    /* Computed Parameter: Wheel_Out_Y0
     * Referenced by: '<S128>/Wheel_Out'
     */
    {
      0.0,                             /* ForceTransmitted */
      0.0,                             /* Speed */
      0.0,                             /* SpeedDelta */
      0.0,                             /* Spin */
      0.0,                             /* Skid */
      0.0,                             /* DrivingForce */
      0.0,                             /* LateralFrictionForce */
      0.0,                             /* BrakingForce */
      0.0                              /* BrakePower */
    },

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S120>/Constant'
     */
    {
      false,                           /* Enabled */
      0U,                              /* VehicleID */
      0.0,                             /* HeadPosition */
      0.0,                             /* TailPosition */
      0.0,                             /* Velocity */
      0.0,                             /* Mass */
      0.0,                             /* MovingForce */
      0.0,                             /* HeadCouplerForce */
      0.0                              /* TailCouplerForce */
    },

    /* Computed Parameter: Constant_Value_g
     * Referenced by: '<S175>/Constant'
     */
    {
      0.0,                             /* AerodynamicDragForce */
      0.0,                             /* BearingDragForce */
      0.0,                             /* LateralDragForce */
      0.0                              /* AdditionalNonWheelDragForce */
    },

    /* Computed Parameter: Constant_Value_gl
     * Referenced by: '<S176>/Constant'
     */
    {
      0.0,                             /* AerodynamicDragForce */
      0.0,                             /* BearingDragForce */
      0.0,                             /* LateralDragForce */
      0.0                              /* AdditionalNonWheelDragForce */
    },

    /* Computed Parameter: Constant_Value_f
     * Referenced by: '<S178>/Constant'
     */
    {
      0.0,                             /* AerodynamicDragForce */
      0.0,                             /* BearingDragForce */
      0.0,                             /* LateralDragForce */
      0.0                              /* AdditionalNonWheelDragForce */
    },

    /* Computed Parameter: Constant_Value_e
     * Referenced by: '<S174>/Constant'
     */
    {
      0.0,                             /* AerodynamicDragForce */
      0.0,                             /* BearingDragForce */
      0.0,                             /* LateralDragForce */
      0.0                              /* AdditionalNonWheelDragForce */
    },

    /* Expression: 0
     * Referenced by: '<S180>/NoLateralDrag'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S180>/NoBearingDrag'
     */
    0.0,

    /* Expression: Inf
     * Referenced by: '<S175>/Saturation'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S175>/Saturation'
     */
    0.0,

    /* Expression: Inf
     * Referenced by: '<S175>/Saturation1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S175>/Saturation1'
     */
    0.0,

    /* Expression: 1.2252
     * Referenced by: '<S178>/Air Density kg//m3'
     */
    1.2252,

    /* Expression: 0.5
     * Referenced by: '<S178>/Gain'
     */
    0.5,

    /* Expression: 0
     * Referenced by: '<S173>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S173>/Constant1'
     */
    1.0,

    /* Expression: -75
     * Referenced by: '<S161>/Constant'
     */
    -75.0,

    /* Expression: 0
     * Referenced by: '<S161>/Switch'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S161>/Switch1'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S162>/Constant11'
     */
    1.0,

    /* Expression: .5
     * Referenced by: '<S162>/Constant9'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S162>/Constant6'
     */
    1.0,

    /* Expression: .5
     * Referenced by: '<S162>/Constant1'
     */
    0.5,

    /* Expression: 0
     * Referenced by: '<S162>/Switch2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S162>/Switch3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S162>/Switch'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S162>/Switch1'
     */
    0.0,

    /* Computed Parameter: TotalForceTransmitted_Y0
     * Referenced by: '<S128>/TotalForceTransmitted'
     */
    0.0,

    /* Expression: 1:MaxAxles
     * Referenced by: '<S141>/Max Axles2'
     */
    { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 },

    /* Expression: 1
     * Referenced by: '<S141>/Saturation'
     */
    1.0,

    /* Expression: zeros(6,1)
     * Referenced by: '<S150>/Max Axles1'
     */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    /* Expression: 2
     * Referenced by: '<S150>/Locked Axle Index'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S144>/Gain'
     */
    0.5,

    /* Expression: 0
     * Referenced by: '<S139>/Constant'
     */
    0.0,

    /* Expression: Inf
     * Referenced by: '<S133>/Saturation'
     */
    0.0,

    /* Expression: 500
     * Referenced by: '<S133>/Saturation'
     */
    500.0,

    /* Expression: 0
     * Referenced by: '<S133>/Constant'
     */
    0.0,

    /* Expression: 1e6
     * Referenced by: '<S86>/Constant'
     */
    1.0E+6,

    /* Expression: 1e6
     * Referenced by: '<S86>/Constant1'
     */
    1.0E+6,

    /* Expression: [1 1]
     * Referenced by: '<S85>/Constant'
     */
    { 1.0, 1.0 },

    /* Computed Parameter: MechanicallyCoupled_Y0
     * Referenced by: '<S57>/MechanicallyCoupled'
     */
    0.0,

    /* Expression: [1,1]
     * Referenced by: '<S59>/HeadANDTailEnabled'
     */
    { 1.0, 1.0 },

    /* Expression: 0
     * Referenced by: '<S16>/Default'
     */
    0.0,

    /* Expression: 1.5*0.005
     * Referenced by: '<S17>/Default'
     */
    0.0075,

    /* Expression: 0.4
     * Referenced by: '<S18>/Default'
     */
    0.4,

    /* Expression: 0.1
     * Referenced by: '<S19>/Default'
     */
    0.1,

    /* Expression: 0
     * Referenced by: '<S20>/Default'
     */
    0.0,

    /* Expression: 5e6
     * Referenced by: '<S21>/Default'
     */
    5.0E+6,

    /* Expression: 0.05
     * Referenced by: '<S22>/Default'
     */
    0.05,

    /* Expression: 0.24
     * Referenced by: '<S23>/Default'
     */
    0.24,

    /* Expression: 0.4
     * Referenced by: '<S24>/Default'
     */
    0.4,

    /* Expression: 0.6
     * Referenced by: '<S25>/Default'
     */
    0.6,

    /* Expression: 0.41
     * Referenced by: '<S26>/Default'
     */
    0.41,

    /* Expression: 5e4
     * Referenced by: '<S27>/Default'
     */
    50000.0,

    /* Expression: 0
     * Referenced by: '<S28>/Default'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S29>/Default'
     */
    0.0,

    /* Expression: 5e7
     * Referenced by: '<S30>/Default'
     */
    5.0E+7,

    /* Expression: 5e4
     * Referenced by: '<S31>/Default'
     */
    50000.0,

    /* Expression: .2
     * Referenced by: '<S32>/Default'
     */
    0.2,

    /* Expression: .2
     * Referenced by: '<S33>/Default'
     */
    0.2,

    /* Expression: 0
     * Referenced by: '<S126>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S186>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S14>/Unit Delay'
     */
    0.0,

    /* Expression: 30
     * Referenced by: '<S125>/Proportional Gain'
     */
    30.0,

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S125>/Integrator'
     */
    0.001,

    /* Expression: 0
     * Referenced by: '<S125>/Integrator'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S125>/Integrator'
     */
    1.0,

    /* Expression: -1
     * Referenced by: '<S125>/Integrator'
     */
    -1.0,

    /* Expression: 1
     * Referenced by: '<S125>/Saturation1'
     */
    1.0,

    /* Expression: -1
     * Referenced by: '<S125>/Saturation1'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S125>/Gain'
     */
    -1.0,

    /* Expression: 0.01
     * Referenced by: '<S132>/Gain'
     */
    0.01,

    /* Expression: 1e6
     * Referenced by: '<S132>/Saturation1'
     */
    1.0E+6,

    /* Expression: 0
     * Referenced by: '<S132>/Saturation1'
     */
    0.0,

    /* Expression: 9.81
     * Referenced by: '<S130>/g'
     */
    9.81,

    /* Expression: -1
     * Referenced by: '<S130>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S130>/sim coordinates'
     */
    -1.0,

    /* Computed Parameter: TSamp_WtEt
     * Referenced by: '<S172>/TSamp'
     */
    1000.0,

    /* Expression: 0.5
     * Referenced by: '<S171>/Gain'
     */
    0.5,

    /* Expression: 1e9
     * Referenced by: '<S171>/Saturation'
     */
    1.0E+9,

    /* Expression: 1
     * Referenced by: '<S171>/Saturation'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S133>/Switch'
     */
    0.0,

    /* Computed Parameter: VelocityIntegrator_gainval
     * Referenced by: '<S136>/VelocityIntegrator'
     */
    0.0005,

    /* Computed Parameter: PositionIntegrator_gainval
     * Referenced by: '<S135>/PositionIntegrator'
     */
    0.0005,

    /* Computed Parameter: TSamp_WtEt_h
     * Referenced by: '<S137>/TSamp'
     */
    1000.0,

    /* Expression: 300
     * Referenced by: '<S125>/Integral Gain'
     */
    300.0,

    /* Start of '<S58>/CoreSubsys' */
    {
      /* Mask Parameter: SRFlipFlop_initial_condition
       * Referenced by: '<S70>/Memory'
       */
      0,

      /* Mask Parameter: DetectRisePositive_vinit
       * Referenced by: '<S76>/Delay Input1'
       */
      0,

      /* Computed Parameter: Mimic_Value
       * Referenced by: '<S58>/Mimic'
       */
      {
        0.0,                           /* Mass */
        0.0,                           /* Time */
        0.0,                           /* Position */
        0.0,                           /* Velocity */
        0.0,                           /* Acceleration */
        0.0,                           /* Gradient */
        0.0,                           /* Radius */
        0.0,                           /* TractiveForce */
        0.0,                           /* BrakingForce */
        0.0,                           /* OtherCouplerForce */
        0.0                            /* OtherCouplerForceRate */
      },

      /* Expression: 1
       * Referenced by: '<S72>/0 to 1'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S72>/0 to 1'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S65>/Gain1'
       */
      -1.0,

      /* Expression: inf
       * Referenced by: '<S78>/Saturation1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S78>/Saturation1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S78>/Saturation'
       */
      0.0,

      /* Expression: -inf
       * Referenced by: '<S78>/Saturation'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S78>/SafeDivide2'
       */
      0.0,

      /* Expression: eps
       * Referenced by: '<S78>/SafeDivide2'
       */
      2.2204460492503131E-16,

      /* Expression: inf
       * Referenced by: '<S78>/SafeDivide1'
       */
      0.0,

      /* Expression: eps
       * Referenced by: '<S78>/SafeDivide1'
       */
      2.2204460492503131E-16,

      /* Expression: inf
       * Referenced by: '<S78>/SafeDivide'
       */
      0.0,

      /* Expression: eps
       * Referenced by: '<S78>/SafeDivide'
       */
      2.2204460492503131E-16,

      /* Expression: 0
       * Referenced by: '<S78>/SignCheck'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S77>/Constant'
       */
      0.0,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S79>/OffTime'
       */
      0.1,

      /* Expression: 0
       * Referenced by: '<S81>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S79>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S79>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S79>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S79>/Discrete-Time Integrator'
       */
      0.001,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S79>/Discrete-Time Integrator'
       */
      0.1,

      /* Expression: 0
       * Referenced by: '<S79>/Discrete-Time Integrator'
       */
      0.0,

      /* Computed Parameter: CouplerForce_N_Y0
       * Referenced by: '<S60>/CouplerForce_N'
       */
      0.0,

      /* Computed Parameter: SpringForce_N_Y0
       * Referenced by: '<S60>/SpringForce_N'
       */
      0.0,

      /* Computed Parameter: DampingForce_N_Y0
       * Referenced by: '<S60>/DampingForce_N'
       */
      0.0,

      /* Computed Parameter: BuffForce_N_Y0
       * Referenced by: '<S60>/BuffForce_N'
       */
      0.0,

      /* Computed Parameter: DraftForce_N_Y0
       * Referenced by: '<S60>/DraftForce_N'
       */
      0.0,

      /* Computed Parameter: CouplerBreakage_Y0
       * Referenced by: '<S60>/CouplerBreakage'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S68>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S69>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S75>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S80>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S61>/Constant1'
       */
      0.0,

      /* Expression: 0.5
       * Referenced by: '<S65>/Gain'
       */
      0.5,

      /* Expression: -1
       * Referenced by: '<S67>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S63>/Gain1'
       */
      -1.0,

      /* Expression: 1e8
       * Referenced by: '<S60>/Limit'
       */
      1.0E+8,

      /* Expression: -1e8
       * Referenced by: '<S60>/Limit'
       */
      -1.0E+8,

      /* Computed Parameter: Merge_InitialOutput
       * Referenced by: '<S66>/Merge'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S64>/Gain'
       */
      -1.0,

      /* Expression: 1e8
       * Referenced by: '<S64>/Saturation'
       */
      1.0E+8,

      /* Expression: 0
       * Referenced by: '<S64>/Saturation'
       */
      0.0,

      /* Expression: 1e8
       * Referenced by: '<S64>/Saturation1'
       */
      1.0E+8,

      /* Expression: 0
       * Referenced by: '<S64>/Saturation1'
       */
      0.0,

      /* Computed Parameter: Logic_table
       * Referenced by: '<S70>/Logic'
       */
      { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
    }
    ,

    /* End of '<S58>/CoreSubsys' */

    /* Start of '<S88>/CoreSubsys' */
    {
      /* Mask Parameter: LatchDT_InitialCondition
       * Referenced by: '<S118>/Unit Delay'
       */
      0.0,

      /* Mask Parameter: LatchMovement_InitialCondition
       * Referenced by: '<S106>/Unit Delay'
       */
      0.0,

      /* Mask Parameter: UpdateTimeout_UpperSaturationLimit
       * Referenced by: '<S104>/Timer'
       */
      1.0,

      /* Mask Parameter: OursIs12_const
       * Referenced by: '<S112>/Constant'
       */
      1.0,

      /* Mask Parameter: OursIs1_const
       * Referenced by: '<S111>/Constant'
       */
      1.0,

      /* Mask Parameter: TheirsIs1_const
       * Referenced by: '<S113>/Constant'
       */
      1.0,

      /* Mask Parameter: TheirsIs12_const
       * Referenced by: '<S114>/Constant'
       */
      1.0,

      /* Mask Parameter: DetectChange_vinit
       * Referenced by: '<S117>/Delay Input1'
       */
      0.0,

      /* Computed Parameter: MimicModelDynamicsOut_Y0
       * Referenced by: '<S90>/MimicModelDynamicsOut'
       */
      {
        0.0,                           /* UseMimic */
        0.0,                           /* MimicPosition */
        0.0,                           /* MimicVelocity */
        0.0,                           /* MimicMass */
        0.0,                           /* MimicMovingForce */
        0.0                            /* MimicCouplerForce */
      },

      /* Expression: -1
       * Referenced by: '<S92>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S95>/ZeroAcceleration'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S97>/ZeroVelocity'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S105>/Constant'
       */
      0.0,

      /* Computed Parameter: Timer_gainval
       * Referenced by: '<S104>/Timer'
       */
      0.001,

      /* Expression: 0
       * Referenced by: '<S104>/Timer'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S104>/Timer'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S109>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S110>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S116>/Constant'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S116>/Limit'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S90>/MimicModelDebugOut'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S100>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S102>/Constant'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S90>/UseMimic'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S110>/Constant'
       */
      1.0,

      /* Expression: [ 0.4225, 31.33, 580.81]
       * Referenced by: '<S92>/Drag'
       */
      { 0.4225, 31.33, 580.81 },

      /* Expression: 0
       * Referenced by: '<S92>/Switch'
       */
      0.0,

      /* Expression: -9.81
       * Referenced by: '<S92>/AccGravity'
       */
      -9.81,

      /* Expression: 1e06
       * Referenced by: '<S94>/MassLimit'
       */
      1.0E+6,

      /* Expression: 1e04
       * Referenced by: '<S94>/MassLimit'
       */
      10000.0,

      /* Expression: 1
       * Referenced by: '<S109>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S93>/PreviousVelocity'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S95>/SafeDivide'
       */
      0.0,

      /* Expression: eps
       * Referenced by: '<S95>/SafeDivide'
       */
      2.2204460492503131E-16,

      /* Expression: 100
       * Referenced by: '<S95>/SanityLimit'
       */
      100.0,

      /* Expression: -100
       * Referenced by: '<S95>/SanityLimit'
       */
      -100.0,

      /* Computed Parameter: VelocityChange_WtEt
       * Referenced by: '<S98>/VelocityChange'
       */
      0.001,

      /* Computed Parameter: IntegratedVelocity_gainval
       * Referenced by: '<S97>/IntegratedVelocity'
       */
      0.001,

      /* Expression: 0
       * Referenced by: '<S106>/Latch'
       */
      0.0,

      /* Computed Parameter: IntegratedPosition_gainval
       * Referenced by: '<S96>/IntegratedPosition'
       */
      0.001,

      /* Computed Parameter: ExternalCoupling_Y0
       * Referenced by: '<S89>/ExternalCoupling'
       */
      0
    }
    ,

    /* End of '<S88>/CoreSubsys' */

    /* Start of '<S119>/CoreSubsys' */
    {
      /* Mask Parameter: TappedDelay_vinit
       * Referenced by: '<S122>/Tapped Delay'
       */
      0.0,

      /* Mask Parameter: WMAV10_weights
       * Referenced by: '<S122>/Constant'
       */
      { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

      /* Computed Parameter: MimicModelOut_Y0
       * Referenced by: '<S121>/MimicModelOut'
       */
      {
        0.0,                           /* Mass */
        0.0,                           /* Time */
        0.0,                           /* Position */
        0.0,                           /* Velocity */
        0.0,                           /* Acceleration */
        0.0,                           /* Gradient */
        0.0,                           /* Radius */
        0.0,                           /* TractiveForce */
        0.0,                           /* BrakingForce */
        0.0,                           /* OtherCouplerForce */
        0.0                            /* OtherCouplerForceRate */
      },

      /* Computed Parameter: Mimic_Value
       * Referenced by: '<S121>/Mimic'
       */
      {
        0.0,                           /* Mass */
        0.0,                           /* Time */
        0.0,                           /* Position */
        0.0,                           /* Velocity */
        0.0,                           /* Acceleration */
        0.0,                           /* Gradient */
        0.0,                           /* Radius */
        0.0,                           /* TractiveForce */
        0.0,                           /* BrakingForce */
        0.0,                           /* OtherCouplerForce */
        0.0                            /* OtherCouplerForceRate */
      },

      /* Expression: 0
       * Referenced by: '<S123>/Constant1'
       */
      0.0,

      /* Expression: 1.0
       * Referenced by: '<S123>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S124>/Constant'
       */
      0.0,

      /* Computed Parameter: TimeAtOutput_WtEt
       * Referenced by: '<S121>/TimeAtOutput'
       */
      0.001
    }
    ,

    /* End of '<S119>/CoreSubsys' */

    /* Start of '<S148>/CoreSubsys' */
    {
      /* Mask Parameter: SnapToZero_threshold
       * Referenced by: '<S157>/Switch2'
       */
      0.001,

      /* Computed Parameter: Wheel_Out_Y0
       * Referenced by: '<S152>/Wheel_Out'
       */
      {
        0.0,                           /* ForceTransmitted */
        0.0,                           /* Speed */
        0.0,                           /* SpeedDelta */
        0.0,                           /* Spin */
        0.0,                           /* Skid */
        0.0,                           /* DrivingForce */
        0.0,                           /* LateralFrictionForce */
        0.0,                           /* BrakingForce */
        0.0                            /* BrakePower */
      },

      /* Expression: 0
       * Referenced by: '<S153>/Friction Force1'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S151>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S155>/No AdditionalForce'
       */
      0.0,

      /* Expression: 2000
       * Referenced by: '<S155>/MomentOfInertia'
       */
      2000.0,

      /* Computed Parameter: WeightedSampleTime_WtEt
       * Referenced by: '<S156>/Weighted Sample Time'
       */
      0.001,

      /* Expression: -1
       * Referenced by: '<S159>/Gain4'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S159>/Switch2'
       */
      0.0,

      /* Computed Parameter: AxleLongitudinalForce_Y0
       * Referenced by: '<S151>/Axle Longitudinal Force'
       */
      0.0,

      /* Computed Parameter: AxleSpeed_Y0
       * Referenced by: '<S151>/Axle Speed'
       */
      0.0,

      /* Computed Parameter: AxleSpeedDelta_Y0
       * Referenced by: '<S151>/Axle Speed Delta'
       */
      0.0,

      /* Computed Parameter: AxleSlipping_Y0
       * Referenced by: '<S151>/Axle Slipping'
       */
      0.0,

      /* Computed Parameter: AxleSkidding_Y0
       * Referenced by: '<S151>/Axle Skidding'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S158>/Constant'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S159>/Constant'
       */
      0.0,

      /* Expression: Inf
       * Referenced by: '<S155>/Saturation'
       */
      0.0,

      /* Expression: 0.01
       * Referenced by: '<S155>/Saturation'
       */
      0.01,

      /* Expression: -1
       * Referenced by: '<S159>/BrakingDeltaLimit'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S159>/Switch3'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S156>/IC'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S151>/Unit Delay'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S156>/Unit Delay1'
       */
      0.0,

      /* Computed Parameter: UnitDelay1_InitialCondition_a
       * Referenced by: '<S151>/Unit Delay1'
       */
      0,

      /* Computed Parameter: UnitDelay1_InitialCondition_f
       * Referenced by: '<S155>/Unit Delay1'
       */
      0
    }
    /* End of '<S148>/CoreSubsys' */
  }
  /* End of '<S4>/CoreSubsys' */
};

/*
 * Start for atomic system:
 *    '<S142>/Braking Force Per Axle'
 *    '<S142>/Reaction Force Per Axle'
 */
void TrainDynamics_BrakingForcePerAxle_Start
  (B_BrakingForcePerAxle_TrainDynamics_T *localB)
{
  int32_T i;
  for (i = 0; i < 6; i++) {
    localB->ForcePerAxle[i] = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S142>/Braking Force Per Axle'
 *    '<S142>/Reaction Force Per Axle'
 */
void TrainDynamics_BrakingForcePerAxle(const real_T rtu_AxleConfig[6], real_T
  rtu_TotalForce, B_BrakingForcePerAxle_TrainDynamics_T *localB)
{
  real_T AxleForce;
  boolean_T x[6];
  int32_T k;
  int32_T i;
  for (i = 0; i < 6; i++) {
    localB->ForcePerAxle[i] = 0.0;
    x[i] = (rtu_AxleConfig[i] > 0.0);
  }

  i = x[0];
  for (k = 0; k < 5; k++) {
    i += x[k + 1];
  }

  if (i > 0) {
    AxleForce = rtu_TotalForce / static_cast<real_T>(i);
    for (i = 0; i < 6; i++) {
      if (rtu_AxleConfig[i] > 0.0) {
        localB->ForcePerAxle[i] = AxleForce;
      }
    }
  }
}

/*
 * Start for atomic system:
 *    '<S161>/Dynamic Track Adhesion Variation'
 *    '<S161>/Static Track Adhesion Variation'
 *    '<S162>/Dynamic Track Adhesion Variation'
 *    '<S162>/Static Track Adhesion Variation'
 */
void TrainDynamics_DynamicTrackAdhesionVariation_Start
  (B_DynamicTrackAdhesionVariation_TrainDynamics_T *localB)
{
  localB->Output = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S161>/Dynamic Track Adhesion Variation'
 *    '<S161>/Static Track Adhesion Variation'
 *    '<S162>/Dynamic Track Adhesion Variation'
 *    '<S162>/Static Track Adhesion Variation'
 */
void TrainDynamics_DynamicTrackAdhesionVariation(real_T rtu_Input, real_T
  rtu_Variation, B_DynamicTrackAdhesionVariation_TrainDynamics_T *localB)
{
  localB->Output = (rtu_Variation / 100.0 + 1.0) * rtu_Input;
}

/*
 * Start for atomic system:
 *    '<S161>/Sanding Dynamic Track Adhesion Variation'
 *    '<S161>/Sanding Static Track Adhesion Variation'
 *    '<S162>/Sanding Dynamic Track Adhesion Variation'
 *    '<S162>/Sanding Static Track Adhesion Variation'
 */
void TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
  (B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T *localB)
{
  localB->Output = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S161>/Sanding Dynamic Track Adhesion Variation'
 *    '<S161>/Sanding Static Track Adhesion Variation'
 *    '<S162>/Sanding Dynamic Track Adhesion Variation'
 *    '<S162>/Sanding Static Track Adhesion Variation'
 */
void TrainDynamics_SandingDynamicTrackAdhesionVariation(real_T rtu_Input, real_T
  rtu_Variation, B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T *localB)
{
  localB->Output = (rtu_Variation / 100.0 + 1.0) * rtu_Input;
}

/* System initialize for referenced model: 'TrainDynamics' */
void TrainDynamics_Init(B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T
  *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_n;
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE =
    TrainDynamics_P.DiscreteTimeIntegrator_IC;

  /* SystemInitialize for Atomic SubSystem: '<S1>/AtomicConfigProcessing' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/ConfigProcessing' */
  for (i = 0; i < 8; i++) {
    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    localDW->UnitDelay_DSTATE[i] = TrainDynamics_P.UnitDelay_InitialCondition;

    /* SystemInitialize for Outport: '<S6>/InitialPosition' */
    localB->y[i] = TrainDynamics_P.InitialPosition_Y0;
  }

  /* End of SystemInitialize for SubSystem: '<S5>/ConfigProcessing' */
  /* End of SystemInitialize for SubSystem: '<S1>/AtomicConfigProcessing' */

  /* SystemInitialize for Iterator SubSystem: '<Root>/Train Dynamics' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE =
      TrainDynamics_P.CoreSubsys_p.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator' */
    localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE =
      TrainDynamics_P.CoreSubsys_p.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[0] =
      TrainDynamics_P.CoreSubsys_p.UnitDelay1_InitialCondition;
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[1] =
      TrainDynamics_P.CoreSubsys_p.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S172>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE =
      TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for DiscreteIntegrator: '<S136>/VelocityIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S135>/PositionIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_IC_LOADING = 1U;
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = 0;

    /* InitializeConditions for UnitDelay: '<S137>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE_l =
      TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput_a;

    /* SystemInitialize for Enabled SubSystem: '<S9>/ConfigProcessing' */
    /* SystemInitialize for Outport: '<S10>/DynamicsVehicleConfig' */
    localB->CoreSubsys_p[ForEach_itr].BusCreator1 =
      TrainDynamics_P.CoreSubsys_p.DynamicsVehicleConfig_Y0;

    /* End of SystemInitialize for SubSystem: '<S9>/ConfigProcessing' */

    /* SystemInitialize for Iterator SubSystem: '<S55>/MimicModelPerCoupler' */
    for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
      /* SystemInitialize for Triggered SubSystem: '<S88>/ExternalCouplingLogic' */
      /* SystemInitialize for Outport: '<S89>/ExternalCoupling' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].External1 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ExternalCoupling_Y0;

      /* End of SystemInitialize for SubSystem: '<S88>/ExternalCouplingLogic' */

      /* SystemInitialize for Enabled SubSystem: '<S88>/MimicModelEnabled' */
      /* InitializeConditions for UnitDelay: '<S117>/Delay Input1' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        DelayInput1_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.DetectChange_vinit;

      /* InitializeConditions for UnitDelay: '<S118>/Unit Delay' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        UnitDelay_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchDT_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S93>/PreviousVelocity' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        PreviousVelocity_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.PreviousVelocity_InitialCondition;

      /* InitializeConditions for DiscreteIntegrator: '<S97>/IntegratedVelocity' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedVelocity_IC_LOADING = 1U;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedVelocity_PrevResetState = 2;

      /* InitializeConditions for UnitDelay: '<S106>/Unit Delay' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        UnitDelay_DSTATE_f =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchMovement_InitialCondition;

      /* InitializeConditions for DiscreteIntegrator: '<S96>/IntegratedPosition' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedPosition_IC_LOADING = 1U;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedPosition_PrevResetState = 2;

      /* SystemInitialize for Atomic SubSystem: '<S97>/UpdateTimeout' */
      /* InitializeConditions for DiscreteIntegrator: '<S104>/Timer' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        Timer_DSTATE = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_IC;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        Timer_PrevResetState = 0;

      /* End of SystemInitialize for SubSystem: '<S97>/UpdateTimeout' */

      /* SystemInitialize for Outport: '<S90>/MimicModelDynamicsOut' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].BusCreator =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MimicModelDynamicsOut_Y0;

      /* End of SystemInitialize for SubSystem: '<S88>/MimicModelEnabled' */
    }

    /* End of SystemInitialize for SubSystem: '<S55>/MimicModelPerCoupler' */

    /* SystemInitialize for Enabled SubSystem: '<S56>/CouplerForcesEnabledCar' */
    /* SystemInitialize for Iterator SubSystem: '<S57>/CouplerForcesPerCoupler' */
    for (ForEach_itr_h = 0; ForEach_itr_h < 2; ForEach_itr_h++) {
      /* SystemInitialize for Enabled SubSystem: '<S58>/CouplerForces' */
      /* InitializeConditions for UnitDelay: '<S76>/Delay Input1' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DelayInput1_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DetectRisePositive_vinit;

      /* InitializeConditions for Memory: '<S70>/Memory' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        Memory_PreviousInput =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SRFlipFlop_initial_condition;

      /* SystemInitialize for Atomic SubSystem: '<S66>/TimerOffDelay NoInit' */
      /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DiscreteTimeIntegrator_IC_LOADING = 1U;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DiscreteTimeIntegrator_PrevResetState = 0;

      /* End of SystemInitialize for SubSystem: '<S66>/TimerOffDelay NoInit' */

      /* SystemInitialize for Merge: '<S66>/Merge' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Merge =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Merge_InitialOutput;

      /* SystemInitialize for Outport: '<S60>/CouplerForce_N' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Limit =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.CouplerForce_N_Y0;

      /* SystemInitialize for Outport: '<S60>/SpringForce_N' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SpringForce_N_Y0;

      /* SystemInitialize for Outport: '<S60>/DampingForce_N' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain1 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DampingForce_N_Y0;

      /* SystemInitialize for Outport: '<S60>/BuffForce_N' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Saturation
        = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.BuffForce_N_Y0;

      /* SystemInitialize for Outport: '<S60>/DraftForce_N' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        Saturation1 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DraftForce_N_Y0;

      /* SystemInitialize for Outport: '<S60>/CouplerBreakage' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DataTypeConversion1 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.CouplerBreakage_Y0;

      /* End of SystemInitialize for SubSystem: '<S58>/CouplerForces' */
    }

    /* End of SystemInitialize for SubSystem: '<S57>/CouplerForcesPerCoupler' */

    /* SystemInitialize for Outport: '<S57>/Coupler_Out' */
    localB->CoreSubsys_p[ForEach_itr]
      .ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0] =
      TrainDynamics_P.CoreSubsys_p.Coupler_Out_Y0;

    /* SystemInitialize for Outport: '<S57>/MechanicallyCoupled' */
    localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[0] =
      TrainDynamics_P.CoreSubsys_p.MechanicallyCoupled_Y0;

    /* SystemInitialize for Outport: '<S57>/Coupler_Out' */
    localB->CoreSubsys_p[ForEach_itr]
      .ImpAsg_InsertedFor_Coupler_Out_at_inport_0[1] =
      TrainDynamics_P.CoreSubsys_p.Coupler_Out_Y0;

    /* SystemInitialize for Outport: '<S57>/MechanicallyCoupled' */
    localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[1] =
      TrainDynamics_P.CoreSubsys_p.MechanicallyCoupled_Y0;

    /* End of SystemInitialize for SubSystem: '<S56>/CouplerForcesEnabledCar' */

    /* SystemInitialize for Enabled SubSystem: '<S14>/Longitudinal Wheel Force' */
    /* SystemInitialize for Iterator SubSystem: '<S144>/AxleModel' */
    for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
      /* SystemInitialize for Enabled SubSystem: '<S148>/AxleModelEnabled' */
      /* InitializeConditions for UnitDelay: '<S151>/Unit Delay1' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay1_DSTATE_k =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_a;

      /* InitializeConditions for UnitDelay: '<S155>/Unit Delay1' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay1_DSTATE_n =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_f;

      /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S156>/Unit Delay1' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay1_DSTATE =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition;

      /* SystemInitialize for Outport: '<S151>/Axle Longitudinal Force' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].Switch5 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleLongitudinalForce_Y0;

      /* SystemInitialize for Outport: '<S151>/Axle Speed' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].WheelSpeed =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSpeed_Y0;

      /* SystemInitialize for Outport: '<S151>/Axle Speed Delta' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].v =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSpeedDelta_Y0;

      /* SystemInitialize for Outport: '<S151>/Axle Slipping' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        DataTypeConversion2 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSlipping_Y0;

      /* SystemInitialize for Outport: '<S151>/Axle Skidding' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        DataTypeConversion3 =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.AxleSkidding_Y0;

      /* End of SystemInitialize for SubSystem: '<S148>/AxleModelEnabled' */

      /* SystemInitialize for Enabled SubSystem: '<S148>/PackWheelOutputs' */
      /* SystemInitialize for Outport: '<S152>/Wheel_Out' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].BusCreator =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys.Wheel_Out_Y0;

      /* End of SystemInitialize for SubSystem: '<S148>/PackWheelOutputs' */
    }

    /* End of SystemInitialize for SubSystem: '<S144>/AxleModel' */

    /* SystemInitialize for Outport: '<S128>/TotalForceTransmitted' */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[4] =
      TrainDynamics_P.CoreSubsys_p.TotalForceTransmitted_Y0;

    /* SystemInitialize for Outport: '<S128>/Wheel_Out' */
    for (i = 0; i < 6; i++) {
      localB->CoreSubsys_p[ForEach_itr]
        .ImpAsg_InsertedFor_Wheel_Out_at_inport_0[i] =
        TrainDynamics_P.CoreSubsys_p.Wheel_Out_Y0;
    }

    /* End of SystemInitialize for Outport: '<S128>/Wheel_Out' */
    /* End of SystemInitialize for SubSystem: '<S14>/Longitudinal Wheel Force' */

    /* SystemInitialize for Iterator SubSystem: '<S13>/UpdateMimicPerCoupler' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 2; ForEach_itr_d++) {
      /* SystemInitialize for Enabled SubSystem: '<S119>/UpdateMimicOutputs' */
      /* InitializeConditions for S-Function (sfix_udelay): '<S122>/Tapped Delay' */
      for (i = 0; i < 10; i++) {
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          TappedDelay_X[i] =
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.TappedDelay_vinit;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S122>/Tapped Delay' */

      /* SystemInitialize for Outport: '<S121>/MimicModelOut' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
        BusAssignment =
        TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.MimicModelOut_Y0;

      /* End of SystemInitialize for SubSystem: '<S119>/UpdateMimicOutputs' */
    }

    /* End of SystemInitialize for SubSystem: '<S13>/UpdateMimicPerCoupler' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/Train Dynamics' */
}

/* System reset for referenced model: 'TrainDynamics' */
void TrainDynamics_Reset(DW_TrainDynamics_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE =
    TrainDynamics_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] = TrainDynamics_P.UnitDelay_InitialCondition;
  }

  /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

  /* SystemReset for Iterator SubSystem: '<Root>/Train Dynamics' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE =
      TrainDynamics_P.CoreSubsys_p.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator' */
    localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE =
      TrainDynamics_P.CoreSubsys_p.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[0] =
      TrainDynamics_P.CoreSubsys_p.UnitDelay1_InitialCondition;
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[1] =
      TrainDynamics_P.CoreSubsys_p.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S172>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE =
      TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for DiscreteIntegrator: '<S136>/VelocityIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S135>/PositionIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_IC_LOADING = 1U;
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = 0;

    /* InitializeConditions for UnitDelay: '<S137>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE_l =
      TrainDynamics_P.CoreSubsys_p.DiscreteDerivative_ICPrevScaledInput_a;
  }

  /* End of SystemReset for SubSystem: '<Root>/Train Dynamics' */
}

/* Enable for referenced model: 'TrainDynamics' */
void TrainDynamics_Enable(DW_TrainDynamics_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Enable for Iterator SubSystem: '<Root>/Train Dynamics' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Enable for DiscreteIntegrator: '<S135>/PositionIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_SYSTEM_ENABLE = 1U;
  }

  /* End of Enable for SubSystem: '<Root>/Train Dynamics' */
}

/* Disable for referenced model: 'TrainDynamics' */
void TrainDynamics_Disable(B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T
  *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_n;

  /* Disable for Iterator SubSystem: '<Root>/Train Dynamics' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* Disable for DiscreteIntegrator: '<S125>/Integrator' */
    localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE = localB->
      CoreSubsys_p[ForEach_itr].Integrator;

    /* Disable for Iterator SubSystem: '<S55>/MimicModelPerCoupler' */
    for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
      /* Disable for Enabled SubSystem: '<S88>/MimicModelEnabled' */
      if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          MimicModelEnabled_MODE) {
        /* Disable for Outport: '<S90>/MimicModelDynamicsOut' */
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator =
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MimicModelDynamicsOut_Y0;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          MimicModelEnabled_MODE = false;
      }

      /* End of Disable for SubSystem: '<S88>/MimicModelEnabled' */
    }

    /* End of Disable for SubSystem: '<S55>/MimicModelPerCoupler' */

    /* Disable for Enabled SubSystem: '<S56>/CouplerForcesEnabledCar' */
    if (localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE) {
      /* Disable for Iterator SubSystem: '<S57>/CouplerForcesPerCoupler' */
      for (ForEach_itr_h = 0; ForEach_itr_h < 2; ForEach_itr_h++) {
        /* Disable for Enabled SubSystem: '<S58>/CouplerForces' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
          CouplerForces_MODE = false;

        /* End of Disable for SubSystem: '<S58>/CouplerForces' */
      }

      /* End of Disable for SubSystem: '<S57>/CouplerForcesPerCoupler' */
      localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE = false;
    }

    /* End of Disable for SubSystem: '<S56>/CouplerForcesEnabledCar' */

    /* Disable for Enabled SubSystem: '<S14>/Longitudinal Wheel Force' */
    if (localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE) {
      /* Disable for Iterator SubSystem: '<S144>/AxleModel' */
      for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
        /* Disable for Enabled SubSystem: '<S148>/AxleModelEnabled' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
          AxleModelEnabled_MODE = false;

        /* End of Disable for SubSystem: '<S148>/AxleModelEnabled' */
      }

      /* End of Disable for SubSystem: '<S144>/AxleModel' */
      localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE = false;
    }

    /* End of Disable for SubSystem: '<S14>/Longitudinal Wheel Force' */

    /* Disable for DiscreteIntegrator: '<S135>/PositionIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE =
      localB->CoreSubsys_p[ForEach_itr].Position;

    /* Disable for Iterator SubSystem: '<S13>/UpdateMimicPerCoupler' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 2; ForEach_itr_d++) {
      /* Disable for Enabled SubSystem: '<S119>/UpdateMimicOutputs' */
      if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          UpdateMimicOutputs_MODE) {
        /* Disable for Outport: '<S121>/MimicModelOut' */
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment =
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.MimicModelOut_Y0;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          UpdateMimicOutputs_MODE = false;
      }

      /* End of Disable for SubSystem: '<S119>/UpdateMimicOutputs' */
    }

    /* End of Disable for SubSystem: '<S13>/UpdateMimicPerCoupler' */
  }

  /* End of Disable for SubSystem: '<Root>/Train Dynamics' */
}

/* Start for referenced model: 'TrainDynamics' */
void TrainDynamics_Start(B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T
  *localDW, ZCE_TrainDynamics_T *localZCE)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_n;
  int32_T i;
  static const BD_TrainDynamics_Out_Coupler tmp = { 0.0,/* Force */
    0.0,                               /* SpringForce */
    0.0,                               /* DampingForce */
    0.0,                               /* BuffForce */
    0.0,                               /* DraftForce */
    0.0,                               /* ImpactForce */
    0.0,                               /* Breakage */
    0.0,                               /* Extension */
    0.0,                               /* ExtensionRate */
    0.0,                               /* ExternalCoupling */
    { 0.0,                             /* Mass */
      0.0,                             /* Time */
      0.0,                             /* Position */
      0.0,                             /* Velocity */
      0.0,                             /* Acceleration */
      0.0,                             /* Gradient */
      0.0,                             /* Radius */
      0.0,                             /* TractiveForce */
      0.0,                             /* BrakingForce */
      0.0,                             /* OtherCouplerForce */
      0.0                              /* OtherCouplerForceRate */
    }                                  /* Mimic */
  };

  static const BD_TrainDynamics_Cfg_Vehicle tmp_0 = { 0.0,/* AerodynamicDragCoeff_Front */
    0.0,                               /* AerodynamicDragCoeff_Trail */
    0.0,                               /* BearingFrictionCoeff */
    0.0,                               /* BearingDynamicFrictionCoeff */
    0.0,                               /* LateralFrictionCoeff */
    0.0,                               /* RailStaticFrictionCoeff */
    0.0,                               /* RailDynamicFrictionCoeff */
    0.0,                               /* RailSandedStaticFrictionCoeff */
    0.0,                               /* RailSandedDynamicFrictionCoeff */
    0.0,                               /* SpringRate */
    0.0,                               /* SlackSpringRate */
    0.0,                               /* DampingRate */
    0.0,                               /* SlackDampingRate */
    false,                             /* EnableDampingAdjustmentByMass */
    0.0,                               /* DampingAdjustmentDesignMass */
    0.0,                               /* SlackLength */
    0.0,                               /* DampingLeadIn */
    0.0,                               /* CouplerShockTime */
    DragCalculationMethod_Fundamental, /* DragCalculationMethod */
    { 0.0,                             /* DavisCoeffA1 */
      0.0,                             /* DavisCoeffA2 */
      0.0,                             /* DavisCoeffB1 */
      0.0,                             /* DavisCoeffB2 */
      0.0,                             /* DavisCoeffLeadCarC */
      0.0                              /* DavisCoeffTailCarC */
    },                                 /* DavisCoefficients */
    0.0,                               /* UseSandFrictionCoeffs */
    0.0,                               /* SandStaticFrictionFactor */
    0.0,                               /* SandDynamicFrictionFactor */
    0.0                                /* InitialVelocity */
  };

  static const BD_CouplerMimic_Out_Dynamics tmp_1 = { 0.0,/* UseMimic */
    0.0,                               /* MimicPosition */
    0.0,                               /* MimicVelocity */
    0.0,                               /* MimicMass */
    0.0,                               /* MimicMovingForce */
    0.0                                /* MimicCouplerForce */
  };

  static const BD_CouplerMimic_InterfaceData tmp_2 = { 0.0,/* Mass */
    0.0,                               /* Time */
    0.0,                               /* Position */
    0.0,                               /* Velocity */
    0.0,                               /* Acceleration */
    0.0,                               /* Gradient */
    0.0,                               /* Radius */
    0.0,                               /* TractiveForce */
    0.0,                               /* BrakingForce */
    0.0,                               /* OtherCouplerForce */
    0.0                                /* OtherCouplerForceRate */
  };

  static const BD_TrainDynamics_Out_Vehicle_Wheel tmp_3 = { 0.0,/* ForceTransmitted */
    0.0,                               /* Speed */
    0.0,                               /* SpeedDelta */
    0.0,                               /* Spin */
    0.0,                               /* Skid */
    0.0,                               /* DrivingForce */
    0.0,                               /* LateralFrictionForce */
    0.0,                               /* BrakingForce */
    0.0                                /* BrakePower */
  };

  /* Start for Iterator SubSystem: '<Root>/Train Dynamics' */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE = 0.0;
    localB->CoreSubsys_p[ForEach_itr].Integrator = 0.0;
    localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE = 0.0;
    localB->CoreSubsys_p[ForEach_itr].UnitDelay1[0] = tmp;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackMovingForce[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].UnitDelay1[1] = tmp;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] = 0.0;
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE = 0.0;
    for (i = 0; i < 5; i++) {
      localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[i] = 0.0;
    }

    localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_DSTATE = 0.0;
    localB->CoreSubsys_p[ForEach_itr].Position = 0.0;
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE = 0.0;
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE_l = 0.0;
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate_k[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].
      TmpSignalConversionAtUpdateMimicPerCouplerInport5[0] = tmp;
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate_k[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].
      TmpSignalConversionAtUpdateMimicPerCouplerInport5[1] = tmp;

    /* Start for Enabled SubSystem: '<S9>/ConfigProcessing' */
    localB->CoreSubsys_p[ForEach_itr].BusCreator1 = tmp_0;

    /* End of Start for SubSystem: '<S9>/ConfigProcessing' */

    /* Start for Iterator SubSystem: '<S55>/MimicModelPerCoupler' */
    for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
      /* Start for Triggered SubSystem: '<S88>/ExternalCouplingLogic' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].External1 =
        false;

      /* End of Start for SubSystem: '<S88>/ExternalCouplingLogic' */

      /* Start for Enabled SubSystem: '<S88>/MimicModelEnabled' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        DelayInput1_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        UnitDelay_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        PreviousVelocity_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedVelocity_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        UnitDelay_DSTATE_f = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        IntegratedPosition_DSTATE = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].BusCreator =
        tmp_1;

      /* Start for Atomic SubSystem: '<S97>/UpdateTimeout' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        Timer_DSTATE = 0.0;

      /* End of Start for SubSystem: '<S97>/UpdateTimeout' */
      /* End of Start for SubSystem: '<S88>/MimicModelEnabled' */
      localZCE->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        ExternalCouplingLogic_Trig_ZCE = UNINITIALIZED_ZCSIG;
    }

    /* End of Start for SubSystem: '<S55>/MimicModelPerCoupler' */

    /* Start for Atomic SubSystem: '<S54>/DampingFactor' */
    /* Start for IfAction SubSystem: '<S83>/If Action Subsystem1' */
    localB->CoreSubsys_p[ForEach_itr].Merge[0] = 0.0;

    /* End of Start for SubSystem: '<S83>/If Action Subsystem1' */
    /* End of Start for SubSystem: '<S54>/DampingFactor' */

    /* Start for Enabled SubSystem: '<S56>/CouplerForcesEnabledCar' */
    localB->CoreSubsys_p[ForEach_itr].EnableCouplerForceCalc[0] = false;

    /* End of Start for SubSystem: '<S56>/CouplerForcesEnabledCar' */

    /* Start for Atomic SubSystem: '<S54>/DampingFactor' */
    /* Start for IfAction SubSystem: '<S83>/If Action Subsystem1' */
    localB->CoreSubsys_p[ForEach_itr].Merge[1] = 0.0;

    /* End of Start for SubSystem: '<S83>/If Action Subsystem1' */
    /* End of Start for SubSystem: '<S54>/DampingFactor' */

    /* Start for Enabled SubSystem: '<S56>/CouplerForcesEnabledCar' */
    localB->CoreSubsys_p[ForEach_itr].EnableCouplerForceCalc[1] = false;

    /* Start for Iterator SubSystem: '<S57>/CouplerForcesPerCoupler' */
    for (ForEach_itr_h = 0; ForEach_itr_h < 2; ForEach_itr_h++) {
      /* Start for Enabled SubSystem: '<S58>/CouplerForces' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain1 =
        0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Limit =
        0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DataTypeConversion1 = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Saturation
        = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        Saturation1 = 0.0;

      /* Start for Atomic SubSystem: '<S66>/TimerOffDelay NoInit' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        DiscreteTimeIntegrator_DSTATE = 0.0;

      /* Start for InitialCondition: '<S79>/IC' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
        IC_FirstOutputTime = true;

      /* End of Start for SubSystem: '<S66>/TimerOffDelay NoInit' */

      /* Start for IfAction SubSystem: '<S66>/NotShocking' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Merge =
        0.0;

      /* End of Start for SubSystem: '<S66>/NotShocking' */
      /* End of Start for SubSystem: '<S58>/CouplerForces' */
    }

    /* End of Start for SubSystem: '<S57>/CouplerForcesPerCoupler' */
    /* End of Start for SubSystem: '<S56>/CouplerForcesEnabledCar' */

    /* Start for Enabled SubSystem: '<S14>/Longitudinal Wheel Force' */
    for (i = 0; i < 6; i++) {
      localB->CoreSubsys_p[ForEach_itr].DataTypeConversion[i] = 0.0;
      localB->CoreSubsys_p[ForEach_itr].BrakingForce[i] = 0.0;
      localB->CoreSubsys_p[ForEach_itr].DrivingForce[i] = 0.0;
      localB->CoreSubsys_p[ForEach_itr].BrakePower[i] = 0.0;
      localB->CoreSubsys_p[ForEach_itr].Add[i] = 0.0;
      localB->CoreSubsys_p[ForEach_itr].Assignment[i] = 0.0;
    }

    /* Start for MATLAB Function: '<S142>/Braking Force Per Axle' */
    TrainDynamics_BrakingForcePerAxle_Start(&localB->CoreSubsys_p[ForEach_itr].
      sf_BrakingForcePerAxle);

    /* Start for MATLAB Function: '<S142>/Lateral Friction Force Per Axle' */
    for (i = 0; i < 6; i++) {
      localB->CoreSubsys_p[ForEach_itr].ForcePerAxle[i] = 0.0;
    }

    /* End of Start for MATLAB Function: '<S142>/Lateral Friction Force Per Axle' */

    /* Start for MATLAB Function: '<S142>/Reaction Force Per Axle' */
    TrainDynamics_BrakingForcePerAxle_Start(&localB->CoreSubsys_p[ForEach_itr].
      sf_ReactionForcePerAxle);

    /* Start for IfAction SubSystem: '<S149>/Constant Friction While Sanding' */
    /* Start for MATLAB Function: '<S161>/Dynamic Track Adhesion Variation' */
    TrainDynamics_DynamicTrackAdhesionVariation_Start(&localB->
      CoreSubsys_p[ForEach_itr].sf_DynamicTrackAdhesionVariation);

    /* Start for MATLAB Function: '<S161>/Sanding Dynamic Track Adhesion Variation' */
    TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
      (&localB->CoreSubsys_p[ForEach_itr].
       sf_SandingDynamicTrackAdhesionVariation);

    /* Start for MATLAB Function: '<S161>/Sanding Static Track Adhesion Variation' */
    TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
      (&localB->CoreSubsys_p[ForEach_itr].sf_SandingStaticTrackAdhesionVariation);

    /* Start for MATLAB Function: '<S161>/Static Track Adhesion Variation' */
    TrainDynamics_DynamicTrackAdhesionVariation_Start(&localB->
      CoreSubsys_p[ForEach_itr].sf_StaticTrackAdhesionVariation);

    /* End of Start for SubSystem: '<S149>/Constant Friction While Sanding' */

    /* Start for IfAction SubSystem: '<S149>/Variant Friction While Sanding' */
    /* Start for MATLAB Function: '<S162>/Dynamic Track Adhesion Variation' */
    TrainDynamics_DynamicTrackAdhesionVariation_Start(&localB->
      CoreSubsys_p[ForEach_itr].sf_DynamicTrackAdhesionVariation_p);

    /* Start for MATLAB Function: '<S162>/Sanding Dynamic Track Adhesion Variation' */
    TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
      (&localB->CoreSubsys_p[ForEach_itr].
       sf_SandingDynamicTrackAdhesionVariation_c);

    /* Start for MATLAB Function: '<S162>/Sanding Static Track Adhesion Variation' */
    TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
      (&localB->CoreSubsys_p[ForEach_itr].
       sf_SandingStaticTrackAdhesionVariation_m);

    /* Start for MATLAB Function: '<S162>/Static Track Adhesion Variation' */
    TrainDynamics_DynamicTrackAdhesionVariation_Start(&localB->
      CoreSubsys_p[ForEach_itr].sf_StaticTrackAdhesionVariation_j);

    /* End of Start for SubSystem: '<S149>/Variant Friction While Sanding' */

    /* Start for Iterator SubSystem: '<S144>/AxleModel' */
    for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
      /* Start for Enabled SubSystem: '<S148>/AxleModelEnabled' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        UnitDelay1_DSTATE = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].v = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        DataTypeConversion2 = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        DataTypeConversion3 = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].Switch5 = 0.0;
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].WheelSpeed =
        0.0;

      /* Start for InitialCondition: '<S156>/IC' */
      localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
        IC_FirstOutputTime = true;

      /* End of Start for SubSystem: '<S148>/AxleModelEnabled' */

      /* Start for Enabled SubSystem: '<S148>/PackWheelOutputs' */
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].BusCreator =
        tmp_3;

      /* End of Start for SubSystem: '<S148>/PackWheelOutputs' */
    }

    /* End of Start for SubSystem: '<S144>/AxleModel' */
    /* End of Start for SubSystem: '<S14>/Longitudinal Wheel Force' */

    /* Start for Iterator SubSystem: '<S13>/UpdateMimicPerCoupler' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 2; ForEach_itr_d++) {
      /* Start for Enabled SubSystem: '<S119>/UpdateMimicOutputs' */
      memset(&localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
             TappedDelay_X[0], 0, 10U * sizeof(real_T));
      localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
        BusAssignment = tmp_2;

      /* End of Start for SubSystem: '<S119>/UpdateMimicOutputs' */
    }

    /* End of Start for SubSystem: '<S13>/UpdateMimicPerCoupler' */
  }

  /* End of Start for SubSystem: '<Root>/Train Dynamics' */
}

/* Output and update for referenced model: 'TrainDynamics' */
void TrainDynamics(RT_MODEL_TrainDynamics_T * const TrainDynamics_M, const
                   BD_CommonTrain_SimulatorData *rtu_SimData, const
                   BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8], const
                   BD_TrainDynamics_Cfg_Vehicle rtu_DynamicsVehicleConfig[8],
                   const BD_TrainDynamics_In_Vehicle rtu_DynamicsInVehicle[8],
                   const BD_TrainDynamics_In_Vehicle_Overrides rtu_Overrides[8],
                   const BD_TrainDynamics_In_Vehicle_Faults rtu_Faults[8],
                   BD_TrainDynamics_Out_Vehicle rty_DynamicsVehicleOut[8],
                   B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T *localDW,
                   ZCE_TrainDynamics_T *localZCE)
{
  /* local block i/o variables */
  BD_TrainDynamics_In_Vehicle_Overrides
    rtb_ImpSel_InsertedFor_Overrides_at_outport_0;
  BD_TrainDynamics_Out_Vehicle_TrackGeometry rtb_BusCreator_g;
  BD_TrainDynamics_Out_Vehicle_Drag rtb_BusAssignment1;
  real_T rtb_Acceleration;
  real_T rtb_Switch;
  real_T rtb_DataTypeConversion;
  real_T rtb_Divide1;
  real_T rtb_Divide2;
  real_T rtb_Product_n;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_ResetVelocity;
  boolean_T rtb_LogicalOperator_k;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_f;
  boolean_T x[6];
  int32_T nz;
  real_T this_mass_factor;
  real_T head_mass_factor;
  real_T tail_mass_factor;
  real_T rtb_InitFlag;
  boolean_T rtb_Compare_b;
  BD_TrainDynamics_VehicleCouplingData
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[8];
  real_T rtb_gcost;
  real_T rtb_sint;
  real_T rtb_Switch1_l;
  real_T rtb_cosa;
  real_T rtb_RailReactionForce;
  real_T rtb_PositionRear;
  BD_TrainDynamics_Out_Coupler rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_Length_at_inport_0[8];
  real_T rtb_TotalTraction;
  real_T rtb_Add1_o[6];
  real_T rtb_Gain_e;
  real_T rtb_ImpAsg_InsertedFor_AxleLongitudinalForce_at_inport_0[6];
  ZCEventType zcEvent;
  real_T rtb_Merge1;
  boolean_T rtb_Compare_h;
  real_T rtb_SumInWt;
  int32_T Vehicle_Index;
  boolean_T exitg1;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      TrainDynamics_P.DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainDynamics_P.DiscreteTimeIntegrator_UpperSat;
    rtb_InitFlag = 1.0;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE <=
             TrainDynamics_P.DiscreteTimeIntegrator_LowerSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainDynamics_P.DiscreteTimeIntegrator_LowerSat;
    rtb_InitFlag = -1.0;
  } else {
    rtb_InitFlag = 0.0;
  }

  /* End of DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Logic: '<S2>/Logical Operator'
   */
  localB->RunInit = !(rtb_InitFlag != 0.0);

  /* Outputs for Atomic SubSystem: '<S1>/AtomicConfigProcessing' */
  /* Outputs for Enabled SubSystem: '<S5>/ConfigProcessing' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* SignalConversion generated from: '<S6>/Enable' */
  if (rtmIsSampleHit(TrainDynamics_M, 1, 0) && (localB->RunInit > 0.0)) {
    /* Outputs for Iterator SubSystem: '<S6>/ConfigCheck' incorporates:
     *  ForEach: '<S7>/For Each'
     */
    for (ForEach_itr_f = 0; ForEach_itr_f < 8; ForEach_itr_f++) {
      /* ForEachSliceAssignment generated from: '<S7>/Length' incorporates:
       *  ForEachSliceSelector generated from: '<S7>/CommonVehicleConfig'
       */
      rtb_ImpAsg_InsertedFor_Length_at_inport_0[ForEach_itr_f] =
        rtu_CommonVehicleConfig[ForEach_itr_f].Length;
    }

    /* End of Outputs for SubSystem: '<S6>/ConfigCheck' */

    /* MATLAB Function: '<S6>/Initial Positions' */
    localB->y[0] = -0.0;
    for (Vehicle_Index = 0; Vehicle_Index < 7; Vehicle_Index++) {
      localB->y[Vehicle_Index + 1] =
        -rtb_ImpAsg_InsertedFor_Length_at_inport_0[Vehicle_Index];
      localB->y[Vehicle_Index + 1] += localB->y[Vehicle_Index];
    }

    /* End of MATLAB Function: '<S6>/Initial Positions' */
  }

  /* End of SignalConversion generated from: '<S6>/Enable' */
  /* End of Outputs for SubSystem: '<S5>/ConfigProcessing' */
  /* End of Outputs for SubSystem: '<S1>/AtomicConfigProcessing' */

  /* UnitDelay: '<Root>/Unit Delay' */
  memcpy(&localB->UnitDelay[0], &localDW->UnitDelay_DSTATE[0], sizeof
         (BD_TrainDynamics_VehicleCouplingData) << 3U);

  /* Outputs for Iterator SubSystem: '<Root>/Train Dynamics' incorporates:
   *  ForEach: '<S4>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    localB->ForEach = ForEach_itr;

    /* ForEachSliceSelector generated from: '<S4>/Overrides' */
    rtb_ImpSel_InsertedFor_Overrides_at_outport_0 = rtu_Overrides[ForEach_itr];

    /* DiscreteIntegrator: '<S125>/Integrator' */
    localB->CoreSubsys_p[ForEach_itr].Integrator = localDW->
      CoreSubsys_p[ForEach_itr].Integrator_DSTATE;

    /* Sum: '<S125>/Sum' incorporates:
     *  Gain: '<S125>/Proportional Gain'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    head_mass_factor = TrainDynamics_P.CoreSubsys_p.ProportionalGain_Gain *
      localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE + localB->
      CoreSubsys_p[ForEach_itr].Integrator;

    /* Saturate: '<S125>/Saturation1' */
    if (head_mass_factor > TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_h)
    {
      head_mass_factor = TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_h;
    } else {
      if (head_mass_factor < TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_d)
      {
        head_mass_factor = TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_d;
      }
    }

    /* End of Saturate: '<S125>/Saturation1' */

    /* Gain: '<S125>/Gain' */
    rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Gain_Gain_c * head_mass_factor;

    /* Outputs for Enabled SubSystem: '<S9>/ConfigProcessing' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    if (localB->RunInit > 0.0) {
      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S37>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S37>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].AerodynamicDragCoeff_Front >
          TrainDynamics_P.CoreSubsys_p.MinValue_const) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.AerodynamicDragCoeff_Front
          = rtu_DynamicsVehicleConfig[ForEach_itr].AerodynamicDragCoeff_Front;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S18>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.AerodynamicDragCoeff_Front
          = TrainDynamics_P.CoreSubsys_p.Default_Value_o;
      }

      /* End of Switch: '<S18>/Switch' */

      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S38>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S38>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].AerodynamicDragCoeff_Trail >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_n) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.AerodynamicDragCoeff_Trail
          = rtu_DynamicsVehicleConfig[ForEach_itr].AerodynamicDragCoeff_Trail;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S19>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.AerodynamicDragCoeff_Trail
          = TrainDynamics_P.CoreSubsys_p.Default_Value_f1;
      }

      /* End of Switch: '<S19>/Switch' */

      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S36>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S36>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].BearingFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_b) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.BearingFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].BearingFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S17>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.BearingFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_f;
      }

      /* End of Switch: '<S17>/Switch' */

      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S35>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S35>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].BearingDynamicFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_o) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.BearingDynamicFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].BearingDynamicFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S16>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.BearingDynamicFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value;
      }

      /* End of Switch: '<S16>/Switch' */

      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S41>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S41>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].LateralFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_d) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.LateralFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].LateralFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S22>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.LateralFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_cj;
      }

      /* End of Switch: '<S22>/Switch' */

      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S45>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S45>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].RailStaticFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_h) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.RailStaticFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].RailStaticFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S26>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.RailStaticFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_n;
      }

      /* End of Switch: '<S26>/Switch' */

      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S42>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S42>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].RailDynamicFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_c) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.RailDynamicFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].RailDynamicFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S23>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.RailDynamicFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_k;
      }

      /* End of Switch: '<S23>/Switch' */

      /* Switch: '<S25>/Switch' incorporates:
       *  Constant: '<S44>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S44>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].RailSandedStaticFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_a) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.RailSandedStaticFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].RailSandedStaticFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S25>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.RailSandedStaticFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_l;
      }

      /* End of Switch: '<S25>/Switch' */

      /* Switch: '<S24>/Switch' incorporates:
       *  Constant: '<S43>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S43>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].RailSandedDynamicFrictionCoeff >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_i) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.RailSandedDynamicFrictionCoeff =
          rtu_DynamicsVehicleConfig[ForEach_itr].RailSandedDynamicFrictionCoeff;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S24>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.RailSandedDynamicFrictionCoeff =
          TrainDynamics_P.CoreSubsys_p.Default_Value_b;
      }

      /* End of Switch: '<S24>/Switch' */

      /* Switch: '<S30>/Switch' incorporates:
       *  Constant: '<S49>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S49>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SpringRate >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_nv) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SpringRate =
          rtu_DynamicsVehicleConfig[ForEach_itr].SpringRate;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S30>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SpringRate =
          TrainDynamics_P.CoreSubsys_p.Default_Value_a2;
      }

      /* End of Switch: '<S30>/Switch' */

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S48>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S48>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SlackSpringRate >=
          TrainDynamics_P.CoreSubsys_p.MinValue_const_l) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackSpringRate =
          rtu_DynamicsVehicleConfig[ForEach_itr].SlackSpringRate;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S29>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackSpringRate =
          TrainDynamics_P.CoreSubsys_p.Default_Value_p;
      }

      /* End of Switch: '<S29>/Switch' */

      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S40>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S40>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].DampingRate >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_aa) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingRate =
          rtu_DynamicsVehicleConfig[ForEach_itr].DampingRate;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S21>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingRate =
          TrainDynamics_P.CoreSubsys_p.Default_Value_c;
      }

      /* End of Switch: '<S21>/Switch' */

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S46>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S46>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SlackDampingRate >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_bl) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackDampingRate =
          rtu_DynamicsVehicleConfig[ForEach_itr].SlackDampingRate;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S27>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackDampingRate =
          TrainDynamics_P.CoreSubsys_p.Default_Value_h;
      }

      /* End of Switch: '<S27>/Switch' */

      /* BusCreator: '<S15>/Bus Creator1' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       */
      localB->CoreSubsys_p[ForEach_itr].
        BusCreator1.EnableDampingAdjustmentByMass =
        rtu_DynamicsVehicleConfig[ForEach_itr].EnableDampingAdjustmentByMass;

      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S50>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S50>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].DampingAdjustmentDesignMass >
          TrainDynamics_P.CoreSubsys_p.MinValue_const_aae) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.DampingAdjustmentDesignMass =
          rtu_DynamicsVehicleConfig[ForEach_itr].DampingAdjustmentDesignMass;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S31>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.DampingAdjustmentDesignMass =
          TrainDynamics_P.CoreSubsys_p.Default_Value_pa;
      }

      /* End of Switch: '<S31>/Switch' */

      /* Switch: '<S28>/Switch' incorporates:
       *  Constant: '<S47>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S47>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SlackLength >=
          TrainDynamics_P.CoreSubsys_p.MaxValue_const) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackLength =
          rtu_DynamicsVehicleConfig[ForEach_itr].SlackLength;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S28>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackLength =
          TrainDynamics_P.CoreSubsys_p.Default_Value_g;
      }

      /* End of Switch: '<S28>/Switch' */

      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S39>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S39>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].DampingLeadIn <
          TrainDynamics_P.CoreSubsys_p.MaxValue_const_l) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingLeadIn =
          rtu_DynamicsVehicleConfig[ForEach_itr].DampingLeadIn;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S20>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingLeadIn =
          TrainDynamics_P.CoreSubsys_p.Default_Value_a;
      }

      /* End of Switch: '<S20>/Switch' */

      /* BusCreator: '<S15>/Bus Creator1' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       */
      localB->CoreSubsys_p[ForEach_itr].BusCreator1.CouplerShockTime =
        rtu_DynamicsVehicleConfig[ForEach_itr].CouplerShockTime;
      localB->CoreSubsys_p[ForEach_itr].BusCreator1.DragCalculationMethod =
        rtu_DynamicsVehicleConfig[ForEach_itr].DragCalculationMethod;
      localB->CoreSubsys_p[ForEach_itr].BusCreator1.DavisCoefficients =
        rtu_DynamicsVehicleConfig[ForEach_itr].DavisCoefficients;
      localB->CoreSubsys_p[ForEach_itr].BusCreator1.UseSandFrictionCoeffs =
        rtu_DynamicsVehicleConfig[ForEach_itr].UseSandFrictionCoeffs;

      /* Switch: '<S33>/Switch' incorporates:
       *  Constant: '<S52>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S52>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SandStaticFrictionFactor >
          TrainDynamics_P.CoreSubsys_p.MaxValue_const_g) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SandStaticFrictionFactor =
          rtu_DynamicsVehicleConfig[ForEach_itr].SandStaticFrictionFactor;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S33>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SandStaticFrictionFactor =
          TrainDynamics_P.CoreSubsys_p.Default_Value_o1;
      }

      /* End of Switch: '<S33>/Switch' */

      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S51>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       *  RelationalOperator: '<S51>/Compare'
       */
      if (rtu_DynamicsVehicleConfig[ForEach_itr].SandDynamicFrictionFactor >
          TrainDynamics_P.CoreSubsys_p.MaxValue_const_l1) {
        /* BusCreator: '<S15>/Bus Creator1' */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SandDynamicFrictionFactor =
          rtu_DynamicsVehicleConfig[ForEach_itr].SandDynamicFrictionFactor;
      } else {
        /* BusCreator: '<S15>/Bus Creator1' incorporates:
         *  Constant: '<S32>/Default'
         */
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.SandDynamicFrictionFactor =
          TrainDynamics_P.CoreSubsys_p.Default_Value_gb;
      }

      /* End of Switch: '<S32>/Switch' */

      /* BusCreator: '<S15>/Bus Creator1' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsVehicleConfig'
       */
      localB->CoreSubsys_p[ForEach_itr].BusCreator1.InitialVelocity =
        rtu_DynamicsVehicleConfig[ForEach_itr].InitialVelocity;

      /* Assertion: '<S34>/Assertion' incorporates:
       *  RelationalOperator: '<S34>/Relational Operator'
       */
      utAssert(localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackLength >=
               localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingLeadIn);
    }

    /* End of Outputs for SubSystem: '<S9>/ConfigProcessing' */

    /* UnitDelay: '<S11>/Unit Delay1' */
    memcpy(&localB->CoreSubsys_p[ForEach_itr].UnitDelay1[0],
           &localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[0], sizeof
           (BD_TrainDynamics_Out_Coupler) << 1U);

    /* Outputs for Iterator SubSystem: '<S55>/MimicModelPerCoupler' incorporates:
     *  ForEach: '<S88>/For Each'
     */
    for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
      /* Outputs for Triggered SubSystem: '<S88>/ExternalCouplingLogic' incorporates:
       *  TriggerPort: '<S89>/Trigger'
       */
      /* ForEachSliceSelector generated from: '<S88>/CouplerIn' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       */
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&localZCE->CoreSubsys_p[ForEach_itr].
                         CoreSubsys_ix[ForEach_itr_e].
                         ExternalCouplingLogic_Trig_ZCE,
                         (rtu_DynamicsInVehicle[ForEach_itr]
                          .Couplers[ForEach_itr_e].OtherVehicleID));
      if (zcEvent != NO_ZCEVENT) {
        /* MATLAB Function: '<S89>/IsInternalVehicle' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         */
        rtb_Compare_b = false;
        if (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
            OtherVehicleID > 0.0) {
          Vehicle_Index = 0;
          exitg1 = false;
          while ((!exitg1) && (Vehicle_Index < 8)) {
            if (localB->UnitDelay[Vehicle_Index].VehicleID ==
                rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
                OtherVehicleID) {
              rtb_Compare_b = true;
              exitg1 = true;
            } else {
              Vehicle_Index++;
            }
          }
        }

        /* End of MATLAB Function: '<S89>/IsInternalVehicle' */

        /* Logic: '<S89>/External1' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  Logic: '<S89>/External'
         */
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].External1
          = ((!rtb_Compare_b) && (rtu_DynamicsInVehicle[ForEach_itr]
              .Couplers[ForEach_itr_e].Available != 0.0));
      }

      /* End of Outputs for SubSystem: '<S88>/ExternalCouplingLogic' */

      /* Outputs for Enabled SubSystem: '<S88>/MimicModelEnabled' incorporates:
       *  EnablePort: '<S90>/Enable'
       */
      if (localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          External1) {
        if (!localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            MimicModelEnabled_MODE) {
          /* InitializeConditions for UnitDelay: '<S117>/Delay Input1' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            DelayInput1_DSTATE =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.DetectChange_vinit;

          /* InitializeConditions for UnitDelay: '<S118>/Unit Delay' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            UnitDelay_DSTATE =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchDT_InitialCondition;

          /* InitializeConditions for UnitDelay: '<S93>/PreviousVelocity' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            PreviousVelocity_DSTATE =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.PreviousVelocity_InitialCondition;

          /* InitializeConditions for DiscreteIntegrator: '<S97>/IntegratedVelocity' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedVelocity_IC_LOADING = 1U;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedVelocity_PrevResetState = 2;

          /* InitializeConditions for UnitDelay: '<S106>/Unit Delay' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            UnitDelay_DSTATE_f =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.LatchMovement_InitialCondition;

          /* InitializeConditions for DiscreteIntegrator: '<S96>/IntegratedPosition' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_IC_LOADING = 1U;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_PrevResetState = 2;

          /* SystemReset for Atomic SubSystem: '<S97>/UpdateTimeout' */
          /* InitializeConditions for DiscreteIntegrator: '<S104>/Timer' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            Timer_DSTATE = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_IC;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            Timer_PrevResetState = 0;

          /* End of SystemReset for SubSystem: '<S97>/UpdateTimeout' */

          /* Enable for DiscreteIntegrator: '<S97>/IntegratedVelocity' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedVelocity_SYSTEM_ENABLE = 1U;

          /* Enable for DiscreteIntegrator: '<S96>/IntegratedPosition' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_SYSTEM_ENABLE = 1U;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            MimicModelEnabled_MODE = true;
        }

        /* RelationalOperator: '<S117>/FixPt Relational Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  UnitDelay: '<S117>/Delay Input1'
         */
        rtb_Compare_h = (rtu_DynamicsInVehicle[ForEach_itr]
                         .Couplers[ForEach_itr_e].Mimic.Time !=
                         localDW->CoreSubsys_p[ForEach_itr]
                         .CoreSubsys_ix[ForEach_itr_e].DelayInput1_DSTATE);

        /* Switch: '<S118>/Latch' incorporates:
         *  UnitDelay: '<S118>/Unit Delay'
         */
        if (rtb_Compare_h) {
          /* Sum: '<S116>/Subtract' incorporates:
           *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
           *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
           */
          rtb_TotalTraction = rtu_SimData->SimulationTime -
            rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
            Mimic.Time;

          /* Switch: '<S116>/Limit' incorporates:
           *  Abs: '<S116>/Abs'
           *  Constant: '<S116>/Constant'
           */
          if (fabs(rtb_TotalTraction) >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Limit_Threshold) {
            this_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_m;
          } else {
            this_mass_factor = rtb_TotalTraction;
          }

          /* End of Switch: '<S116>/Limit' */
        } else {
          this_mass_factor = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].UnitDelay_DSTATE;
        }

        /* End of Switch: '<S118>/Latch' */

        /* Logic: '<S107>/Logical Operator2' incorporates:
         *  Constant: '<S111>/Constant'
         *  Constant: '<S112>/Constant'
         *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  RelationalOperator: '<S111>/Compare'
         *  RelationalOperator: '<S112>/Compare'
         */
        rtb_Compare_b = (rtu_CommonVehicleConfig[ForEach_itr].Orientation ==
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.OursIs12_const)
          ^ (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].End ==
             TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.OursIs1_const);

        /* Switch: '<S110>/Switch' incorporates:
         *  Constant: '<S110>/Constant'
         *  Constant: '<S113>/Constant'
         *  Constant: '<S114>/Constant'
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  Gain: '<S110>/Gain'
         *  Logic: '<S107>/Logical Operator1'
         *  Logic: '<S107>/Logical Operator3'
         *  RelationalOperator: '<S113>/Compare'
         *  RelationalOperator: '<S114>/Compare'
         */
        if (static_cast<boolean_T>((static_cast<boolean_T>
              (((rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
                 OtherVehicleEnd ==
                 TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.TheirsIs1_const) ^
                (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
                 OtherVehicleOrientation ==
                 TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.TheirsIs12_const))) ^
              rtb_Compare_b))) {
          rtb_PositionRear =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_h;
        } else {
          rtb_PositionRear =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain_e *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_h;
        }

        /* End of Switch: '<S110>/Switch' */

        /* Product: '<S94>/Product2' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  MATLAB Function: '<S108>/MimicInertiaUpdate'
         */
        rtb_TotalTraction = (rtu_DynamicsInVehicle[ForEach_itr]
                             .Couplers[ForEach_itr_e].Mimic.Acceleration *
                             this_mass_factor +
                             rtu_DynamicsInVehicle[ForEach_itr]
                             .Couplers[ForEach_itr_e].Mimic.Velocity) *
          rtb_PositionRear;

        /* Abs: '<S92>/Abs' */
        head_mass_factor = fabs(rtb_TotalTraction);

        /* Switch: '<S92>/Switch' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  Gain: '<S92>/Gain'
         *  Polyval: '<S92>/Drag'
         *  Sum: '<S92>/StoppingForce'
         */
        if (rtb_TotalTraction >=
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Switch_Threshold) {
          rtb_cosa = (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
                      .Mimic.BrakingForce +
                      ((TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[0]
                        * head_mass_factor +
                        TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[1])
                       * head_mass_factor +
                       TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[2]))
            * TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain;
        } else {
          rtb_cosa = rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
            Mimic.BrakingForce +
            ((TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[0] *
              head_mass_factor +
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[1]) *
             head_mass_factor +
             TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Drag_Coefs[2]);
        }

        /* End of Switch: '<S92>/Switch' */

        /* Saturate: '<S94>/MassLimit' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         */
        if (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
            Mimic.Mass >
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_UpperSat) {
          head_mass_factor =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_UpperSat;
        } else if (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
                   Mimic.Mass <
                   TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_LowerSat)
        {
          head_mass_factor =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MassLimit_LowerSat;
        } else {
          head_mass_factor = rtu_DynamicsInVehicle[ForEach_itr]
            .Couplers[ForEach_itr_e].Mimic.Mass;
        }

        /* End of Saturate: '<S94>/MassLimit' */

        /* Switch: '<S109>/Switch' incorporates:
         *  Constant: '<S109>/Constant'
         *  Gain: '<S109>/Gain'
         *  Logic: '<S107>/Logical Operator4'
         */
        if (!rtb_Compare_b) {
          rtb_Gain_e =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_m4;
        } else {
          rtb_Gain_e = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Gain_Gain_j *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_m4;
        }

        /* End of Switch: '<S109>/Switch' */

        /* Product: '<S92>/Product1' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/DynamicsCouplerOut'
         *  Sum: '<S92>/CouplerForces'
         */
        tail_mass_factor = (localB->CoreSubsys_p[ForEach_itr]
                            .UnitDelay1[ForEach_itr_e].Force -
                            rtu_DynamicsInVehicle[ForEach_itr]
                            .Couplers[ForEach_itr_e].Mimic.OtherCouplerForce) *
          rtb_Gain_e;

        /* Sum: '<S92>/MotiveForces' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  Gain: '<S92>/AccGravity'
         *  Product: '<S92>/Product'
         *  Product: '<S94>/Product4'
         *  Product: '<S94>/Product6'
         */
        rtb_Merge1 = (rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
                      .Mimic.Gradient * rtb_PositionRear *
                      TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.AccGravity_Gain
                      * head_mass_factor + tail_mass_factor) +
          rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
          Mimic.TractiveForce * rtb_PositionRear;

        /* RelationalOperator: '<S98>/Braking' incorporates:
         *  Abs: '<S98>/Abs'
         *  Abs: '<S98>/Abs1'
         */
        rtb_Compare_b = (fabs(rtb_cosa) > fabs(rtb_Merge1));

        /* Sum: '<S92>/MimicForces' */
        rtb_cosa += rtb_Merge1;

        /* Saturate: '<S95>/SafeDivide' */
        if (head_mass_factor >
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_UpperSat) {
          rtb_gcost =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_UpperSat;
        } else if (head_mass_factor <
                   TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_LowerSat)
        {
          rtb_gcost =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_LowerSat;
        } else {
          rtb_gcost = head_mass_factor;
        }

        /* End of Saturate: '<S95>/SafeDivide' */

        /* Product: '<S95>/Divide' */
        rtb_Merge1 = rtb_cosa / rtb_gcost;

        /* Saturate: '<S95>/SanityLimit' */
        if (rtb_Merge1 >
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_UpperSat) {
          rtb_Merge1 =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_UpperSat;
        } else {
          if (rtb_Merge1 <
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_LowerSat) {
            rtb_Merge1 =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SanityLimit_LowerSat;
          }
        }

        /* End of Saturate: '<S95>/SanityLimit' */

        /* Logic: '<S98>/Stop' incorporates:
         *  Constant: '<S100>/Constant'
         *  Product: '<S98>/Product'
         *  RelationalOperator: '<S100>/Compare'
         *  SampleTimeMath: '<S98>/VelocityChange'
         *  Sum: '<S98>/ProjectedVelocity'
         *  UnitDelay: '<S93>/PreviousVelocity'
         *
         * About '<S98>/VelocityChange':
         *  y = u * K where K = ( w * Ts )
         */
        rtb_Compare_b = (rtb_Compare_b && ((rtb_Merge1 *
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.VelocityChange_WtEt +
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          PreviousVelocity_DSTATE) * localDW->CoreSubsys_p[ForEach_itr].
          CoreSubsys_ix[ForEach_itr_e].PreviousVelocity_DSTATE <=
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_i));

        /* Switch: '<S95>/Switch1' incorporates:
         *  Constant: '<S95>/ZeroAcceleration'
         */
        if (rtb_Compare_b) {
          rtb_sint =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ZeroAcceleration_Value;
        } else {
          rtb_sint = rtb_Merge1;
        }

        /* End of Switch: '<S95>/Switch1' */

        /* DataTypeConversion: '<S116>/Data Type Conversion' */
        rtb_DataTypeConversion = rtb_Compare_h;

        /* RelationalOperator: '<S102>/Compare' incorporates:
         *  Constant: '<S102>/Constant'
         */
        rtb_Compare_h = (rtb_DataTypeConversion ==
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value_g);

        /* Outputs for Atomic SubSystem: '<S97>/UpdateTimeout' */
        /* Logic: '<S104>/Logical Operator' */
        rtb_LogicalOperator_k = !rtb_Compare_h;

        /* DiscreteIntegrator: '<S104>/Timer' incorporates:
         *  DataTypeConversion: '<S104>/Data Type Conversion'
         */
        if (rtb_LogicalOperator_k || (localDW->CoreSubsys_p[ForEach_itr].
             CoreSubsys_ix[ForEach_itr_e].Timer_PrevResetState != 0)) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            Timer_DSTATE = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_IC;
        }

        rtb_gcost = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_gainval *
          static_cast<real_T>(rtb_Compare_h) + localDW->CoreSubsys_p[ForEach_itr]
          .CoreSubsys_ix[ForEach_itr_e].Timer_DSTATE;
        if (rtb_gcost >=
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.UpdateTimeout_UpperSaturationLimit)
        {
          rtb_gcost =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.UpdateTimeout_UpperSaturationLimit;
          rtb_Merge1 = 1.0;
        } else if (rtb_gcost <=
                   TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_LowerSat) {
          rtb_gcost = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Timer_LowerSat;
          rtb_Merge1 = -1.0;
        } else {
          rtb_Merge1 = 0.0;
        }

        /* End of DiscreteIntegrator: '<S104>/Timer' */

        /* Update for DiscreteIntegrator: '<S104>/Timer' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          Timer_DSTATE = rtb_gcost;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          Timer_PrevResetState = static_cast<int8_T>(rtb_LogicalOperator_k);

        /* Logic: '<S97>/ResetToZero' incorporates:
         *  Constant: '<S105>/Constant'
         *  RelationalOperator: '<S105>/Compare'
         */
        rtb_Compare_b = ((rtb_Merge1 >
                          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Constant_Value)
                         || rtb_Compare_b);

        /* End of Outputs for SubSystem: '<S97>/UpdateTimeout' */

        /* Logic: '<S97>/ResetVelocity' */
        rtb_ResetVelocity = ((rtb_DataTypeConversion != 0.0) || rtb_Compare_b);

        /* Switch: '<S97>/Switch1' incorporates:
         *  Constant: '<S97>/ZeroVelocity'
         */
        if (rtb_Compare_b) {
          rtb_Merge1 =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.ZeroVelocity_Value;
        } else {
          rtb_Merge1 = rtb_TotalTraction;
        }

        /* End of Switch: '<S97>/Switch1' */

        /* DiscreteIntegrator: '<S97>/IntegratedVelocity' */
        if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedVelocity_SYSTEM_ENABLE != 0) {
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
              IntegratedVelocity_IC_LOADING != 0) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
              IntegratedVelocity_DSTATE = rtb_Merge1;
          }

          rtb_Merge1 = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedVelocity_DSTATE;
        } else if (rtb_ResetVelocity && (localDW->CoreSubsys_p[ForEach_itr].
                    CoreSubsys_ix[ForEach_itr_e].
                    IntegratedVelocity_PrevResetState <= 0)) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedVelocity_DSTATE = rtb_Merge1;
          rtb_Merge1 = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedVelocity_DSTATE;
        } else {
          rtb_Merge1 =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.IntegratedVelocity_gainval
            * rtb_sint + localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedVelocity_DSTATE;
        }

        /* End of DiscreteIntegrator: '<S97>/IntegratedVelocity' */

        /* Product: '<S94>/Product' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         */
        rtb_Gain_e *= rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
          .CouplingSeparation;

        /* Sum: '<S94>/Add' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         */
        rtb_Gain_e += rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
          .OurCouplingPosition;

        /* Switch: '<S106>/Latch' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         *  MATLAB Function: '<S108>/MimicInertiaUpdate'
         *  Sum: '<S94>/Add2'
         *  UnitDelay: '<S106>/Unit Delay'
         */
        if (rtb_DataTypeConversion >
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.Latch_Threshold) {
          rtb_sint = ((rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
                       .Mimic.Velocity * this_mass_factor +
                       rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
                       .Mimic.Position) + 0.5 *
                      rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e]
                      .Mimic.Acceleration * (this_mass_factor * this_mass_factor))
            - rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_e].
            OtherCouplingPosition;
        } else {
          rtb_sint = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].UnitDelay_DSTATE_f;
        }

        /* End of Switch: '<S106>/Latch' */

        /* Sum: '<S94>/Add1' incorporates:
         *  Product: '<S94>/Product1'
         */
        rtb_PositionRear = rtb_sint * rtb_PositionRear + rtb_Gain_e;

        /* DiscreteIntegrator: '<S96>/IntegratedPosition' */
        if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_SYSTEM_ENABLE != 0) {
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
              IntegratedPosition_IC_LOADING != 0) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
              IntegratedPosition_DSTATE = rtb_PositionRear;
          }

          rtb_PositionRear = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedPosition_DSTATE;
        } else if ((rtb_DataTypeConversion > 0.0) && (localDW->
                    CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
                    IntegratedPosition_PrevResetState <= 0)) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_DSTATE = rtb_PositionRear;
          rtb_PositionRear = localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedPosition_DSTATE;
        } else {
          rtb_PositionRear =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.IntegratedPosition_gainval
            * rtb_Merge1 + localDW->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ix[ForEach_itr_e].IntegratedPosition_DSTATE;
        }

        /* End of DiscreteIntegrator: '<S96>/IntegratedPosition' */

        /* BusCreator: '<S90>/Bus Creator' incorporates:
         *  Constant: '<S90>/UseMimic'
         */
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.UseMimic =
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.UseMimic_Value;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.MimicPosition = rtb_PositionRear;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.MimicVelocity = rtb_Merge1;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.MimicMass = head_mass_factor;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.MimicMovingForce = rtb_cosa;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          BusCreator.MimicCouplerForce = tail_mass_factor;

        /* Update for UnitDelay: '<S117>/Delay Input1' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  ForEachSliceSelector generated from: '<S88>/CouplerIn'
         */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          DelayInput1_DSTATE = rtu_DynamicsInVehicle[ForEach_itr]
          .Couplers[ForEach_itr_e].Mimic.Time;

        /* Update for UnitDelay: '<S118>/Unit Delay' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          UnitDelay_DSTATE = this_mass_factor;

        /* Update for UnitDelay: '<S93>/PreviousVelocity' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          PreviousVelocity_DSTATE = rtb_Merge1;

        /* Update for DiscreteIntegrator: '<S97>/IntegratedVelocity' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedVelocity_SYSTEM_ENABLE = 0U;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedVelocity_IC_LOADING = 0U;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedVelocity_DSTATE = rtb_Merge1;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedVelocity_PrevResetState = static_cast<int8_T>
          (rtb_ResetVelocity);

        /* Update for UnitDelay: '<S106>/Unit Delay' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          UnitDelay_DSTATE_f = rtb_sint;

        /* Update for DiscreteIntegrator: '<S96>/IntegratedPosition' */
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedPosition_SYSTEM_ENABLE = 0U;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedPosition_IC_LOADING = 0U;
        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
          IntegratedPosition_DSTATE = rtb_PositionRear;
        if (rtb_DataTypeConversion > 0.0) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_PrevResetState = 1;
        } else if (rtb_DataTypeConversion < 0.0) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_PrevResetState = -1;
        } else if (rtb_DataTypeConversion == 0.0) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_PrevResetState = 0;
        } else {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            IntegratedPosition_PrevResetState = 2;
        }

        /* End of Update for DiscreteIntegrator: '<S96>/IntegratedPosition' */
      } else {
        if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            MimicModelEnabled_MODE) {
          /* Disable for Outport: '<S90>/MimicModelDynamicsOut' */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            BusCreator =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.MimicModelDynamicsOut_Y0;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
            MimicModelEnabled_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S88>/MimicModelEnabled' */

      /* ForEachSliceAssignment generated from: '<S88>/MimicModelDynamicsOut' */
      localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[ForEach_itr_e] =
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].
        BusCreator;

      /* ForEachSliceAssignment generated from: '<S88>/ExternalCoupling' */
      localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[ForEach_itr_e] =
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ix[ForEach_itr_e].External1;
    }

    /* End of Outputs for SubSystem: '<S55>/MimicModelPerCoupler' */

    /* MATLAB Function: '<S54>/CouplerSelection' */
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[1] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackMovingForce[0] = 0.0;
    localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] = 0.0;
    if (localB->ForEach > 2147483646) {
      Vehicle_Index = MAX_int32_T;
    } else {
      Vehicle_Index = localB->ForEach + 1;
    }

    Vehicle_Index--;
    if (localB->UnitDelay[Vehicle_Index].Enabled) {
      localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[0] = localB->
        UnitDelay[Vehicle_Index].Mass;
      localB->CoreSubsys_p[ForEach_itr].BackMovingForce[0] = localB->
        UnitDelay[Vehicle_Index].MovingForce + localB->UnitDelay[Vehicle_Index].
        HeadCouplerForce;
      if (localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].UseMimic > 0.0)
      {
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[0] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].MimicPosition
          - localB->UnitDelay[Vehicle_Index].HeadPosition;
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[0] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].MimicVelocity
          - localB->UnitDelay[Vehicle_Index].Velocity;
        localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[0] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].MimicMass;
        localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[0] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].
          MimicMovingForce - localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].
          MimicCouplerForce;
      } else if (Vehicle_Index + 1 == 1) {
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[0] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[0] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[0] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[0] = 0.0;
      } else {
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[0] =
          localB->UnitDelay[Vehicle_Index - 1].TailPosition - localB->
          UnitDelay[Vehicle_Index].HeadPosition;
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[0] =
          localB->UnitDelay[Vehicle_Index - 1].Velocity - localB->
          UnitDelay[Vehicle_Index].Velocity;
        localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[0] =
          localB->UnitDelay[Vehicle_Index - 1].Mass;
        localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[0] =
          localB->UnitDelay[Vehicle_Index - 1].MovingForce - localB->
          UnitDelay[Vehicle_Index - 1].TailCouplerForce;
      }

      localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[1] = localB->
        UnitDelay[Vehicle_Index].Mass;
      localB->CoreSubsys_p[ForEach_itr].FrontMovingForce[1] = localB->
        UnitDelay[Vehicle_Index].MovingForce - localB->UnitDelay[Vehicle_Index].
        TailCouplerForce;
      if (localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].UseMimic > 0.0)
      {
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] =
          localB->UnitDelay[Vehicle_Index].TailPosition - localB->
          CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].MimicPosition;
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] =
          localB->UnitDelay[Vehicle_Index].Velocity - localB->
          CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].MimicVelocity;
        localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].MimicMass;
        localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] =
          localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].
          MimicMovingForce - localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].
          MimicCouplerForce;
      } else if (Vehicle_Index + 1 == 8) {
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] = 0.0;
        localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] = 0.0;
      } else {
        nz = Vehicle_Index + 1;
        if (nz > 2147483646) {
          nz = MAX_int32_T;
        } else {
          nz++;
        }

        if (!localB->UnitDelay[nz - 1].Enabled) {
          localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] = 0.0;
          localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] = 0.0;
          localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] = 0.0;
          localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] = 0.0;
        } else {
          nz = Vehicle_Index + 1;
          if (nz > 2147483646) {
            nz = MAX_int32_T;
          } else {
            nz++;
          }

          localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[1] =
            localB->UnitDelay[Vehicle_Index].TailPosition - localB->UnitDelay[nz
            - 1].HeadPosition;
          nz = Vehicle_Index + 1;
          if (nz > 2147483646) {
            nz = MAX_int32_T;
          } else {
            nz++;
          }

          localB->CoreSubsys_p[ForEach_itr].CouplerSeparationRate[1] =
            localB->UnitDelay[Vehicle_Index].Velocity - localB->UnitDelay[nz - 1]
            .Velocity;
          nz = Vehicle_Index + 1;
          if (nz > 2147483646) {
            nz = MAX_int32_T;
          } else {
            nz++;
          }

          localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[1] =
            localB->UnitDelay[nz - 1].Mass;
          nz = Vehicle_Index + 1;
          Vehicle_Index++;
          if (nz > 2147483646) {
            nz = MAX_int32_T;
          } else {
            nz++;
          }

          if (Vehicle_Index > 2147483646) {
            Vehicle_Index = MAX_int32_T;
          } else {
            Vehicle_Index++;
          }

          localB->CoreSubsys_p[ForEach_itr].BackMovingForce[1] =
            localB->UnitDelay[nz - 1].MovingForce + localB->
            UnitDelay[Vehicle_Index - 1].HeadCouplerForce;
        }
      }
    }

    /* End of MATLAB Function: '<S54>/CouplerSelection' */
    if (rtmIsSampleHit(TrainDynamics_M, 1, 0)) {
      /* Outputs for Atomic SubSystem: '<S54>/DampingFactor' */
      /* If: '<S83>/If' */
      if (localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.EnableDampingAdjustmentByMass) {
        /* Outputs for IfAction SubSystem: '<S83>/Subsystem' incorporates:
         *  ActionPort: '<S86>/Action Port'
         */
        /* SignalConversion generated from: '<S86>/Out1' incorporates:
         *  MATLAB Function: '<S86>/MassFactor1'
         */
        localB->CoreSubsys_p[ForEach_itr].Merge[0] = 1.0;
        localB->CoreSubsys_p[ForEach_itr].Merge[1] = 1.0;

        /* MATLAB Function: '<S86>/MassFactor1' incorporates:
         *  Constant: '<S86>/Constant'
         *  Constant: '<S86>/Constant1'
         *  SignalConversion generated from: '<S86>/Out1'
         */
        if (localB->ForEach > 2147483646) {
          Vehicle_Index = MAX_int32_T;
        } else {
          Vehicle_Index = localB->ForEach + 1;
        }

        if (localB->UnitDelay[Vehicle_Index - 1].Enabled) {
          this_mass_factor = localB->UnitDelay[Vehicle_Index - 1].Mass /
            localB->CoreSubsys_p[ForEach_itr].
            BusCreator1.DampingAdjustmentDesignMass;
          if (!(this_mass_factor > 0.05)) {
            this_mass_factor = 0.05;
          }

          if (!(this_mass_factor < 1.0)) {
            this_mass_factor = 1.0;
          }

          if (localB->CoreSubsys_p[ForEach_itr].
              ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[0].UseMimic >
              0.0) {
            head_mass_factor = TrainDynamics_P.CoreSubsys_p.Constant_Value_bx /
              localB->CoreSubsys_p[ForEach_itr].
              BusCreator1.DampingAdjustmentDesignMass;
            if (!(head_mass_factor > 0.05)) {
              head_mass_factor = 0.05;
            }

            if (!(head_mass_factor < 1.0)) {
              head_mass_factor = 1.0;
            }
          } else if (Vehicle_Index == 1) {
            head_mass_factor = 1.0;
          } else {
            head_mass_factor = localB->UnitDelay[Vehicle_Index - 2].Mass /
              localB->CoreSubsys_p[ForEach_itr].
              BusCreator1.DampingAdjustmentDesignMass;
            if (!(head_mass_factor > 0.05)) {
              head_mass_factor = 0.05;
            }

            if (!(head_mass_factor < 1.0)) {
              head_mass_factor = 1.0;
            }
          }

          if (localB->CoreSubsys_p[ForEach_itr].
              ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[1].UseMimic >
              0.0) {
            tail_mass_factor = TrainDynamics_P.CoreSubsys_p.Constant1_Value_k /
              localB->CoreSubsys_p[ForEach_itr].
              BusCreator1.DampingAdjustmentDesignMass;
            if (!(tail_mass_factor > 0.05)) {
              tail_mass_factor = 0.05;
            }

            if (!(tail_mass_factor < 1.0)) {
              tail_mass_factor = 1.0;
            }
          } else if (Vehicle_Index == 8) {
            tail_mass_factor = 1.0;
          } else {
            if (Vehicle_Index > 2147483646) {
              nz = MAX_int32_T;
            } else {
              nz = Vehicle_Index + 1;
            }

            if (!localB->UnitDelay[nz - 1].Enabled) {
              tail_mass_factor = 1.0;
            } else {
              if (Vehicle_Index > 2147483646) {
                Vehicle_Index = MAX_int32_T;
              } else {
                Vehicle_Index++;
              }

              tail_mass_factor = localB->UnitDelay[Vehicle_Index - 1].Mass /
                localB->CoreSubsys_p[ForEach_itr].
                BusCreator1.DampingAdjustmentDesignMass;
              if (!(tail_mass_factor > 0.05)) {
                tail_mass_factor = 0.05;
              }

              if (!(tail_mass_factor < 1.0)) {
                tail_mass_factor = 1.0;
              }
            }
          }

          if ((this_mass_factor < head_mass_factor) || rtIsNaN(head_mass_factor))
          {
            localB->CoreSubsys_p[ForEach_itr].Merge[0] = this_mass_factor;
          } else {
            localB->CoreSubsys_p[ForEach_itr].Merge[0] = head_mass_factor;
          }

          if ((this_mass_factor < tail_mass_factor) || rtIsNaN(tail_mass_factor))
          {
            localB->CoreSubsys_p[ForEach_itr].Merge[1] = this_mass_factor;
          } else {
            localB->CoreSubsys_p[ForEach_itr].Merge[1] = tail_mass_factor;
          }
        }

        /* End of Outputs for SubSystem: '<S83>/Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S83>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        /* SignalConversion generated from: '<S85>/Out1' incorporates:
         *  Constant: '<S85>/Constant'
         */
        localB->CoreSubsys_p[ForEach_itr].Merge[0] =
          TrainDynamics_P.CoreSubsys_p.Constant_Value_op[0];
        localB->CoreSubsys_p[ForEach_itr].Merge[1] =
          TrainDynamics_P.CoreSubsys_p.Constant_Value_op[1];

        /* End of Outputs for SubSystem: '<S83>/If Action Subsystem1' */
      }

      /* End of If: '<S83>/If' */
      /* End of Outputs for SubSystem: '<S54>/DampingFactor' */
    }

    /* Outputs for Enabled SubSystem: '<S56>/CouplerForcesEnabledCar' incorporates:
     *  EnablePort: '<S57>/Enable'
     */
    /* ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig ' incorporates:
     *  ForEachSliceSelector generated from: '<S58>/CouplerEnabled'
     */
    if (rtu_CommonVehicleConfig[ForEach_itr].Enabled) {
      if (!localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE) {
        localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE = true;
      }

      /* Logic: '<S59>/EnableCouplerForceCalc' incorporates:
       *  Constant: '<S59>/HeadANDTailEnabled'
       */
      localB->CoreSubsys_p[ForEach_itr].EnableCouplerForceCalc[0] =
        (localB->CoreSubsys_p[ForEach_itr].
         ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[0] ||
         (TrainDynamics_P.CoreSubsys_p.HeadANDTailEnabled_Value[0] != 0.0));
      localB->CoreSubsys_p[ForEach_itr].EnableCouplerForceCalc[1] =
        (localB->CoreSubsys_p[ForEach_itr].
         ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[1] ||
         (TrainDynamics_P.CoreSubsys_p.HeadANDTailEnabled_Value[1] != 0.0));

      /* Outputs for Iterator SubSystem: '<S57>/CouplerForcesPerCoupler' incorporates:
       *  ForEach: '<S58>/For Each'
       */
      for (ForEach_itr_h = 0; ForEach_itr_h < 2; ForEach_itr_h++) {
        /* Outputs for Enabled SubSystem: '<S58>/CouplerForces' incorporates:
         *  EnablePort: '<S60>/Enable'
         */
        if (localB->CoreSubsys_p[ForEach_itr]
            .EnableCouplerForceCalc[ForEach_itr_h]) {
          if (!localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              CouplerForces_MODE) {
            /* InitializeConditions for UnitDelay: '<S76>/Delay Input1' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DelayInput1_DSTATE =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DetectRisePositive_vinit;

            /* InitializeConditions for Memory: '<S70>/Memory' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Memory_PreviousInput =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SRFlipFlop_initial_condition;

            /* SystemReset for Atomic SubSystem: '<S66>/TimerOffDelay NoInit' */
            /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DiscreteTimeIntegrator_IC_LOADING = 1U;
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DiscreteTimeIntegrator_PrevResetState = 0;

            /* End of SystemReset for SubSystem: '<S66>/TimerOffDelay NoInit' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              CouplerForces_MODE = true;
          }

          /* Logic: '<S61>/Engaged' incorporates:
           *  Constant: '<S68>/Constant'
           *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
           *  RelationalOperator: '<S68>/Compare'
           */
          rtb_Compare_h = ((rtu_DynamicsInVehicle[ForEach_itr]
                            .Couplers[ForEach_itr_h].MechanicallyCoupled != 0.0)
                           || (localB->CoreSubsys_p[ForEach_itr].
                               CouplerSeparation[ForEach_itr_h] <
                               TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_b));

          /* Switch: '<S61>/Switch' incorporates:
           *  Constant: '<S61>/Constant1'
           */
          if (rtb_Compare_h) {
            this_mass_factor = localB->CoreSubsys_p[ForEach_itr].
              CouplerSeparation[ForEach_itr_h];
          } else {
            this_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant1_Value;
          }

          /* End of Switch: '<S61>/Switch' */

          /* Product: '<S67>/Slack Spring Force' */
          rtb_TotalTraction = this_mass_factor * localB->
            CoreSubsys_p[ForEach_itr].BusCreator1.SlackSpringRate;

          /* Gain: '<S65>/Gain' */
          rtb_cosa = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_f *
            localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackLength;

          /* Switch: '<S74>/Switch' incorporates:
           *  RelationalOperator: '<S74>/u_GTE_up'
           */
          if (!(this_mass_factor >= rtb_cosa)) {
            /* Gain: '<S65>/Gain1' */
            rtb_cosa *= TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain1_Gain;

            /* Switch: '<S74>/Switch1' incorporates:
             *  RelationalOperator: '<S74>/u_GT_lo'
             */
            if (this_mass_factor > rtb_cosa) {
              rtb_cosa = this_mass_factor;
            }

            /* End of Switch: '<S74>/Switch1' */
          }

          /* End of Switch: '<S74>/Switch' */

          /* Sum: '<S74>/Diff' */
          this_mass_factor -= rtb_cosa;

          /* Gain: '<S67>/Gain' incorporates:
           *  Product: '<S67>/Spring Force'
           *  Sum: '<S67>/Sum1'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain =
            (localB->CoreSubsys_p[ForEach_itr].BusCreator1.SpringRate *
             this_mass_factor + rtb_TotalTraction) *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_a;

          /* If: '<S71>/If' */
          if ((localB->CoreSubsys_p[ForEach_itr].BusCreator1.SlackLength > 0.0) &&
              (localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingLeadIn > 0.0))
          {
            /* Outputs for IfAction SubSystem: '<S71>/Damping Rate with lead in' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* Product: '<S72>/LeadIn' incorporates:
             *  Abs: '<S72>/Abs'
             */
            head_mass_factor = fabs(this_mass_factor) / localB->
              CoreSubsys_p[ForEach_itr].BusCreator1.DampingLeadIn;

            /* Saturate: '<S72>/0 to 1' */
            if (head_mass_factor >
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_UpperSat) {
              head_mass_factor =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_UpperSat;
            } else {
              if (head_mass_factor <
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_LowerSat) {
                head_mass_factor =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.uto1_LowerSat;
              }
            }

            /* End of Saturate: '<S72>/0 to 1' */

            /* Fcn: '<S72>/Fcn' */
            head_mass_factor = (1.0 - head_mass_factor) * localB->
              CoreSubsys_p[ForEach_itr].BusCreator1.SlackDampingRate +
              localB->CoreSubsys_p[ForEach_itr].BusCreator1.DampingRate *
              head_mass_factor;

            /* End of Outputs for SubSystem: '<S71>/Damping Rate with lead in' */
          } else {
            /* Outputs for IfAction SubSystem: '<S71>/Simple Damping' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* DataTypeConversion: '<S73>/Data Type Conversion' */
            head_mass_factor = localB->CoreSubsys_p[ForEach_itr].
              BusCreator1.DampingRate;

            /* End of Outputs for SubSystem: '<S71>/Simple Damping' */
          }

          /* End of If: '<S71>/If' */

          /* Switch: '<S61>/Switch1' incorporates:
           *  Constant: '<S61>/Constant1'
           */
          if (rtb_Compare_h) {
            tail_mass_factor = localB->CoreSubsys_p[ForEach_itr].
              CouplerSeparationRate[ForEach_itr_h];
          } else {
            tail_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant1_Value;
          }

          /* End of Switch: '<S61>/Switch1' */

          /* Gain: '<S63>/Gain1' incorporates:
           *  Product: '<S63>/Damping'
           *  Product: '<S71>/LeadIn1'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain1 =
            head_mass_factor * localB->CoreSubsys_p[ForEach_itr]
            .Merge[ForEach_itr_h] * tail_mass_factor *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain1_Gain_i;

          /* Sum: '<S60>/Sum3' */
          head_mass_factor = localB->CoreSubsys_p[ForEach_itr]
            .CoreSubsys_ixb[ForEach_itr_h].Gain + localB->
            CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain1;

          /* Saturate: '<S60>/Limit' */
          if (head_mass_factor >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_UpperSat) {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Limit = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_UpperSat;
          } else if (head_mass_factor <
                     TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_LowerSat)
          {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Limit = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Limit_LowerSat;
          } else {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Limit = head_mass_factor;
          }

          /* End of Saturate: '<S60>/Limit' */

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Abs: '<S66>/Abs'
           *  Constant: '<S80>/Constant'
           */
          rtb_Compare_h = (fabs(this_mass_factor) >
                           TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_o);

          /* RelationalOperator: '<S76>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S76>/Delay Input1'
           */
          rtb_FixPtRelationalOperator = (static_cast<int32_T>(rtb_Compare_h) >
            static_cast<int32_T>(localDW->CoreSubsys_p[ForEach_itr].
            CoreSubsys_ixb[ForEach_itr_h].DelayInput1_DSTATE));

          /* Outputs for Atomic SubSystem: '<S66>/TimerOffDelay NoInit' */
          /* InitialCondition: '<S79>/IC' incorporates:
           *  Constant: '<S79>/Initialise'
           */
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              IC_FirstOutputTime) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              IC_FirstOutputTime = false;
            rtb_PositionRear =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.IC_Value;
          } else {
            rtb_PositionRear =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Initialise_Value;
          }

          /* End of InitialCondition: '<S79>/IC' */

          /* Switch: '<S79>/Switch2' incorporates:
           *  Constant: '<S79>/Initialise'
           *  Constant: '<S79>/OffTime'
           */
          if (rtb_PositionRear != 0.0) {
            head_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Initialise_Value;
          } else {
            head_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.OffTime_Value;
          }

          /* End of Switch: '<S79>/Switch2' */

          /* DiscreteIntegrator: '<S79>/Discrete-Time Integrator' incorporates:
           *  DataTypeConversion: '<S79>/Data Type Conversion'
           *  Gain: '<S79>/Gain'
           *  Logic: '<S79>/Logical Operator'
           */
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DiscreteTimeIntegrator_IC_LOADING != 0) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DiscreteTimeIntegrator_DSTATE = head_mass_factor;
            if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h]
                .DiscreteTimeIntegrator_DSTATE >=
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat)
            {
              localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                DiscreteTimeIntegrator_DSTATE =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat;
            } else {
              if (localDW->CoreSubsys_p[ForEach_itr]
                  .CoreSubsys_ixb[ForEach_itr_h].DiscreteTimeIntegrator_DSTATE <=
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat)
              {
                localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h]
                  .DiscreteTimeIntegrator_DSTATE =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat;
              }
            }
          }

          if (rtb_FixPtRelationalOperator || (localDW->CoreSubsys_p[ForEach_itr]
               .CoreSubsys_ixb[ForEach_itr_h].
               DiscreteTimeIntegrator_PrevResetState != 0)) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              DiscreteTimeIntegrator_DSTATE = head_mass_factor;
            if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h]
                .DiscreteTimeIntegrator_DSTATE >=
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat)
            {
              localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                DiscreteTimeIntegrator_DSTATE =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat;
            } else {
              if (localDW->CoreSubsys_p[ForEach_itr]
                  .CoreSubsys_ixb[ForEach_itr_h].DiscreteTimeIntegrator_DSTATE <=
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat)
              {
                localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h]
                  .DiscreteTimeIntegrator_DSTATE =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat;
              }
            }
          }

          head_mass_factor =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain *
            static_cast<real_T>(!rtb_FixPtRelationalOperator) *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_gainval
            + localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DiscreteTimeIntegrator_DSTATE;
          if (head_mass_factor >=
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat)
          {
            head_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_UpperSat;
            rtb_PositionRear = 1.0;
          } else if (head_mass_factor <=
                     TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat)
          {
            head_mass_factor =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.DiscreteTimeIntegrator_LowerSat;
            rtb_PositionRear = -1.0;
          } else {
            rtb_PositionRear = 0.0;
          }

          /* End of DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DiscreteTimeIntegrator_IC_LOADING = 0U;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DiscreteTimeIntegrator_DSTATE = head_mass_factor;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
            (rtb_FixPtRelationalOperator);

          /* SwitchCase: '<S66>/Switch Case' incorporates:
           *  Constant: '<S75>/Constant'
           *  Constant: '<S77>/Constant'
           *  Constant: '<S81>/Constant'
           *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
           *  Logic: '<S66>/AND'
           *  Logic: '<S79>/Logical Operator1'
           *  RelationalOperator: '<S75>/Compare'
           *  RelationalOperator: '<S81>/Compare'
           */
          if ((rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_h].
               MechanicallyCoupled != 0.0) && ((rtb_PositionRear >=
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_h) ||
               rtb_FixPtRelationalOperator) && (localB->CoreSubsys_p[ForEach_itr]
               .BusCreator1.CouplerShockTime >
               TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_p)) {
            /* Outputs for IfAction SubSystem: '<S66>/Shocking' incorporates:
             *  ActionPort: '<S78>/Action Port'
             */
            /* Saturate: '<S78>/SafeDivide2' */
            if (localB->CoreSubsys_p[ForEach_itr].FrontVehicleMass[ForEach_itr_h]
                >
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_UpperSat)
            {
              head_mass_factor =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_UpperSat;
            } else if (localB->CoreSubsys_p[ForEach_itr]
                       .FrontVehicleMass[ForEach_itr_h] <
                       TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_LowerSat)
            {
              head_mass_factor =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_LowerSat;
            } else {
              head_mass_factor = localB->CoreSubsys_p[ForEach_itr].
                FrontVehicleMass[ForEach_itr_h];
            }

            /* End of Saturate: '<S78>/SafeDivide2' */

            /* Saturate: '<S78>/SafeDivide1' */
            if (localB->CoreSubsys_p[ForEach_itr].BackVehicleMass[ForEach_itr_h]
                >
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_UpperSat)
            {
              tail_mass_factor =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_UpperSat;
            } else if (localB->CoreSubsys_p[ForEach_itr]
                       .BackVehicleMass[ForEach_itr_h] <
                       TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_LowerSat)
            {
              tail_mass_factor =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_LowerSat;
            } else {
              tail_mass_factor = localB->CoreSubsys_p[ForEach_itr].
                BackVehicleMass[ForEach_itr_h];
            }

            /* End of Saturate: '<S78>/SafeDivide1' */

            /* Switch: '<S78>/SignCheck' incorporates:
             *  Saturate: '<S78>/SafeDivide'
             */
            if (this_mass_factor >
                TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SignCheck_Threshold)
            {
              /* Saturate: '<S78>/SafeDivide' */
              if (localB->CoreSubsys_p[ForEach_itr].BusCreator1.CouplerShockTime
                  >
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat)
              {
                rtb_TotalTraction =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat;
              } else if (localB->CoreSubsys_p[ForEach_itr].
                         BusCreator1.CouplerShockTime <
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_LowerSat)
              {
                rtb_TotalTraction =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_LowerSat;
              } else {
                rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
                  BusCreator1.CouplerShockTime;
              }

              /* Sum: '<S78>/Sum' incorporates:
               *  Fcn: '<S78>/(vf-vb)//Dt*mf*mb//(mf+mb)'
               *  Fcn: '<S78>/Fb*mf//(mf+mb)'
               *  Fcn: '<S78>/Ff*mb//(mf+mb)'
               */
              head_mass_factor = (localB->CoreSubsys_p[ForEach_itr].
                                  BackMovingForce[ForEach_itr_h] *
                                  head_mass_factor / (head_mass_factor +
                tail_mass_factor) - localB->CoreSubsys_p[ForEach_itr].
                                  FrontMovingForce[ForEach_itr_h] *
                                  tail_mass_factor / (head_mass_factor +
                tail_mass_factor)) - localB->CoreSubsys_p[ForEach_itr].
                CouplerSeparationRate[ForEach_itr_h] / rtb_TotalTraction *
                head_mass_factor * tail_mass_factor / (head_mass_factor +
                tail_mass_factor);

              /* Saturate: '<S78>/Saturation' */
              if (head_mass_factor >
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat)
              {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat;
              } else if (head_mass_factor <
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat)
              {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat;
              } else {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge = head_mass_factor;
              }

              /* End of Saturate: '<S78>/Saturation' */
            } else {
              if (localB->CoreSubsys_p[ForEach_itr].BusCreator1.CouplerShockTime
                  >
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat)
              {
                /* Saturate: '<S78>/SafeDivide' */
                rtb_TotalTraction =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat;
              } else if (localB->CoreSubsys_p[ForEach_itr].
                         BusCreator1.CouplerShockTime <
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_LowerSat)
              {
                /* Saturate: '<S78>/SafeDivide' */
                rtb_TotalTraction =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_LowerSat;
              } else {
                /* Saturate: '<S78>/SafeDivide' */
                rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
                  BusCreator1.CouplerShockTime;
              }

              /* Fcn: '<S78>/Fb*mf//(mf+mb)' incorporates:
               *  Fcn: '<S78>/(vf-vb)//Dt*mf*mb//(mf+mb)'
               *  Fcn: '<S78>/Ff*mb//(mf+mb)'
               *  Saturate: '<S78>/SafeDivide'
               */
              this_mass_factor = head_mass_factor + tail_mass_factor;

              /* Sum: '<S78>/Sum' incorporates:
               *  Fcn: '<S78>/(vf-vb)//Dt*mf*mb//(mf+mb)'
               *  Fcn: '<S78>/Fb*mf//(mf+mb)'
               *  Fcn: '<S78>/Ff*mb//(mf+mb)'
               */
              head_mass_factor = (localB->CoreSubsys_p[ForEach_itr].
                                  BackMovingForce[ForEach_itr_h] *
                                  head_mass_factor / this_mass_factor -
                                  localB->CoreSubsys_p[ForEach_itr].
                                  FrontMovingForce[ForEach_itr_h] *
                                  tail_mass_factor / this_mass_factor) -
                localB->CoreSubsys_p[ForEach_itr]
                .CouplerSeparationRate[ForEach_itr_h] / rtb_TotalTraction *
                head_mass_factor * tail_mass_factor / this_mass_factor;

              /* Saturate: '<S78>/Saturation1' */
              if (head_mass_factor >
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat)
              {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat;
              } else if (head_mass_factor <
                         TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat)
              {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge =
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat;
              } else {
                localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
                  Merge = head_mass_factor;
              }

              /* End of Saturate: '<S78>/Saturation1' */
            }

            /* End of Switch: '<S78>/SignCheck' */
            /* End of Outputs for SubSystem: '<S66>/Shocking' */
          } else {
            /* Outputs for IfAction SubSystem: '<S66>/NotShocking' incorporates:
             *  ActionPort: '<S77>/Action Port'
             */
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Merge = TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value;

            /* End of Outputs for SubSystem: '<S66>/NotShocking' */
          }

          /* End of SwitchCase: '<S66>/Switch Case' */
          /* End of Outputs for SubSystem: '<S66>/TimerOffDelay NoInit' */

          /* CombinatorialLogic: '<S70>/Logic' incorporates:
           *  Abs: '<S62>/Abs'
           *  Abs: '<S62>/Abs1'
           *  Constant: '<S69>/Constant'
           *  Logic: '<S62>/Logical Operator'
           *  Memory: '<S70>/Memory'
           *  RelationalOperator: '<S62>/Relational Operator'
           *  RelationalOperator: '<S69>/Compare'
           *  Sum: '<S62>/Sum'
           */
          Vehicle_Index = static_cast<int32_T>(((((static_cast<uint32_T>(((fabs
            (localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
             Limit) + fabs(localB->CoreSubsys_p[ForEach_itr]
                           .CoreSubsys_ixb[ForEach_itr_h].Merge) >
            rtb_ImpSel_InsertedFor_Overrides_at_outport_0.CouplerBreakageLimit) &&
            (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.CouplerBreakageLimit >
             TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Constant_Value_j))) <<
            1) + false) << 1) + localDW->CoreSubsys_p[ForEach_itr].
            CoreSubsys_ixb[ForEach_itr_h].Memory_PreviousInput));

          /* DataTypeConversion: '<S62>/Data Type Conversion1' incorporates:
           *  CombinatorialLogic: '<S70>/Logic'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DataTypeConversion1 =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Logic_table
            [static_cast<uint32_T>(Vehicle_Index)];

          /* Saturate: '<S64>/Saturation' */
          if (localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Limit >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat_i)
          {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_UpperSat_i;
          } else if (localB->CoreSubsys_p[ForEach_itr]
                     .CoreSubsys_ixb[ForEach_itr_h].Limit <
                     TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat_g)
          {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat_g;
          } else {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation = localB->CoreSubsys_p[ForEach_itr]
              .CoreSubsys_ixb[ForEach_itr_h].Limit;
          }

          /* End of Saturate: '<S64>/Saturation' */

          /* Gain: '<S64>/Gain' */
          head_mass_factor =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Gain_Gain_l *
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            Limit;

          /* Saturate: '<S64>/Saturation1' */
          if (head_mass_factor >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat_n)
          {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation1 =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat_n;
          } else if (head_mass_factor <
                     TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat_g)
          {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation1 =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_LowerSat_g;
          } else {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
              Saturation1 = head_mass_factor;
          }

          /* End of Saturate: '<S64>/Saturation1' */

          /* Update for UnitDelay: '<S76>/Delay Input1' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            DelayInput1_DSTATE = rtb_Compare_h;

          /* Update for Memory: '<S70>/Memory' incorporates:
           *  CombinatorialLogic: '<S70>/Logic'
           */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            Memory_PreviousInput =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Logic_table
            [static_cast<uint32_T>(Vehicle_Index)];
        } else {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            CouplerForces_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S58>/CouplerForces' */

        /* ForEachSliceAssignment generated from: '<S58>/MechanicallyCoupled' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         */
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[ForEach_itr_h] =
          rtu_DynamicsInVehicle[ForEach_itr].Couplers[ForEach_itr_h].
          MechanicallyCoupled;

        /* ForEachSliceAssignment generated from: '<S58>/Coupler_Out' incorporates:
         *  BusCreator: '<S58>/Bus Creator'
         *  Constant: '<S58>/Mimic'
         *  DataTypeConversion: '<S58>/Data Type Conversion'
         */
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].Force =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Limit;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].SpringForce =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Gain;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].DampingForce
          = localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
          Gain1;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].BuffForce =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
          Saturation;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].DraftForce =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
          Saturation1;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].ImpactForce =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].Merge;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].Breakage =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
          DataTypeConversion1;
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].Extension =
          localB->CoreSubsys_p[ForEach_itr].CouplerSeparation[ForEach_itr_h];
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].
          ExtensionRate = localB->CoreSubsys_p[ForEach_itr].
          CouplerSeparationRate[ForEach_itr_h];
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].
          ExternalCoupling = localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[ForEach_itr_h];
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_h].Mimic =
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Mimic_Value;
      }

      /* End of Outputs for SubSystem: '<S57>/CouplerForcesPerCoupler' */
    } else {
      if (localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE) {
        /* Disable for Iterator SubSystem: '<S57>/CouplerForcesPerCoupler' */
        for (ForEach_itr_h = 0; ForEach_itr_h < 2; ForEach_itr_h++) {
          /* Disable for Enabled SubSystem: '<S58>/CouplerForces' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_ixb[ForEach_itr_h].
            CouplerForces_MODE = false;

          /* End of Disable for SubSystem: '<S58>/CouplerForces' */
        }

        /* End of Disable for SubSystem: '<S57>/CouplerForcesPerCoupler' */
        localDW->CoreSubsys_p[ForEach_itr].CouplerForcesEnabledCar_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S56>/CouplerForcesEnabledCar' */

    /* SwitchCase: '<S131>/Switch Case' */
    switch (localB->CoreSubsys_p[ForEach_itr].BusCreator1.DragCalculationMethod)
    {
     case DragCalculationMethod_Custom:
      /* Outputs for IfAction SubSystem: '<S131>/Custom Drag' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      /* Saturate: '<S175>/Saturation' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       */
      if (rtu_DynamicsInVehicle[ForEach_itr].
          CustomDragForces.AerodynamicDragForce >
          TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat) {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Gain_e = TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat;
      } else if (rtu_DynamicsInVehicle[ForEach_itr].
                 CustomDragForces.AerodynamicDragForce <
                 TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat) {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Gain_e = TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat;
      } else {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Gain_e = rtu_DynamicsInVehicle[ForEach_itr].
          CustomDragForces.AerodynamicDragForce;
      }

      /* End of Saturate: '<S175>/Saturation' */

      /* Saturate: '<S175>/Saturation1' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       */
      if (rtu_DynamicsInVehicle[ForEach_itr].CustomDragForces.BearingDragForce >
          TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat) {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Merge1 = TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat;
      } else if (rtu_DynamicsInVehicle[ForEach_itr].
                 CustomDragForces.BearingDragForce <
                 TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat) {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Merge1 = TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat;
      } else {
        /* BusAssignment: '<S175>/Bus Assignment' */
        rtb_Merge1 = rtu_DynamicsInVehicle[ForEach_itr].
          CustomDragForces.BearingDragForce;
      }

      /* End of Saturate: '<S175>/Saturation1' */
      /* End of Outputs for SubSystem: '<S131>/Custom Drag' */
      break;

     case DragCalculationMethod_Davis:
      /* Outputs for IfAction SubSystem: '<S131>/Davis Drag' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Abs: '<S176>/Abs1' incorporates:
       *  UnitDelay: '<S14>/Unit Delay'
       */
      this_mass_factor = fabs(localDW->CoreSubsys_p[ForEach_itr].
        UnitDelay_DSTATE);

      /* BusAssignment: '<S176>/Bus Assignment' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       *  Product: '<S176>/A*Mass'
       *  Product: '<S176>/B1*Mass*Vel'
       *  Product: '<S176>/B2*Vel'
       *  Sum: '<S176>/Add'
       */
      rtb_Merge1 = ((localB->CoreSubsys_p[ForEach_itr].
                     BusCreator1.DavisCoefficients.DavisCoeffA1 *
                     rtu_DynamicsInVehicle[ForEach_itr].BogieSupportedMass +
                     localB->CoreSubsys_p[ForEach_itr].
                     BusCreator1.DavisCoefficients.DavisCoeffA2) +
                    localB->CoreSubsys_p[ForEach_itr].
                    BusCreator1.DavisCoefficients.DavisCoeffB1 *
                    rtu_DynamicsInVehicle[ForEach_itr].BogieSupportedMass *
                    this_mass_factor) + localB->CoreSubsys_p[ForEach_itr].
        BusCreator1.DavisCoefficients.DavisCoeffB2 * this_mass_factor;

      /* Switch: '<S176>/Switch' incorporates:
       *  Constant: '<S183>/Constant'
       *  Constant: '<S184>/Constant'
       *  Logic: '<S177>/Logical Operator'
       *  Logic: '<S177>/Logical Operator1'
       *  Logic: '<S177>/Logical Operator2'
       *  Logic: '<S177>/Logical Operator3'
       *  Logic: '<S177>/Logical Operator4'
       *  RelationalOperator: '<S183>/Compare'
       *  RelationalOperator: '<S184>/Compare'
       *  UnitDelay: '<S14>/Unit Delay'
       */
      if (((localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE >
            TrainDynamics_P.CoreSubsys_p.PositiveMovement_const) &&
           (!(localB->CoreSubsys_p[ForEach_itr].
              ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[0] != 0.0))) ||
          ((localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE <
            TrainDynamics_P.CoreSubsys_p.NegativeMovement_const) &&
           (!(localB->CoreSubsys_p[ForEach_itr].
              ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[1] != 0.0)))) {
        rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.DavisCoefficients.DavisCoeffLeadCarC;
      } else {
        rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.DavisCoefficients.DavisCoeffTailCarC;
      }

      /* End of Switch: '<S176>/Switch' */

      /* BusAssignment: '<S176>/Bus Assignment' incorporates:
       *  Math: '<S176>/Math Function'
       *  Product: '<S176>/C*Vel^2'
       */
      rtb_Gain_e = this_mass_factor * this_mass_factor * rtb_TotalTraction;

      /* End of Outputs for SubSystem: '<S131>/Davis Drag' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S131>/Fundamental Drag' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* Switch: '<S178>/Frontal Drag' incorporates:
       *  Constant: '<S183>/Constant'
       *  Constant: '<S184>/Constant'
       *  Constant: '<S185>/Constant'
       *  Logic: '<S177>/Logical Operator'
       *  Logic: '<S177>/Logical Operator1'
       *  Logic: '<S177>/Logical Operator2'
       *  Logic: '<S177>/Logical Operator3'
       *  Logic: '<S177>/Logical Operator4'
       *  RelationalOperator: '<S183>/Compare'
       *  RelationalOperator: '<S184>/Compare'
       *  RelationalOperator: '<S185>/Compare'
       *  UnitDelay: '<S14>/Unit Delay'
       */
      if (static_cast<int32_T>((((localDW->CoreSubsys_p[ForEach_itr].
              UnitDelay_DSTATE >
              TrainDynamics_P.CoreSubsys_p.PositiveMovement_const) &&
             (!(localB->CoreSubsys_p[ForEach_itr].
                ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[0] != 0.0))) ||
            ((localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE <
              TrainDynamics_P.CoreSubsys_p.NegativeMovement_const) &&
             (!(localB->CoreSubsys_p[ForEach_itr].
                ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[1] != 0.0)))))
          > static_cast<int32_T>
          (TrainDynamics_P.CoreSubsys_p.CompareToConstant_const)) {
        rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.AerodynamicDragCoeff_Front;
      } else {
        rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.AerodynamicDragCoeff_Trail;
      }

      /* End of Switch: '<S178>/Frontal Drag' */

      /* BusAssignment: '<S178>/Bus Assignment' incorporates:
       *  Abs: '<S178>/Abs'
       *  Constant: '<S178>/Air Density kg//m3'
       *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       *  Gain: '<S178>/Gain'
       *  Math: '<S178>/Math Function'
       *  Product: '<S178>/A'
       *  Product: '<S178>/Aero Drag'
       *  Product: '<S178>/Constant Bearing Friction (N)'
       *  Product: '<S178>/Dynamic Bearing Friction(N)'
       *  Sum: '<S178>/Add'
       *  UnitDelay: '<S14>/Unit Delay'
       */
      rtb_Gain_e = localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE *
        localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE *
        TrainDynamics_P.CoreSubsys_p.AirDensitykgm3_Value * rtb_TotalTraction *
        (rtu_CommonVehicleConfig[ForEach_itr].Height *
         rtu_CommonVehicleConfig[ForEach_itr].Width) *
        TrainDynamics_P.CoreSubsys_p.Gain_Gain;
      rtb_Merge1 = localB->CoreSubsys_p[ForEach_itr].
        BusCreator1.BearingDynamicFrictionCoeff *
        rtu_DynamicsInVehicle[ForEach_itr].BogieSupportedMass * fabs
        (localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE) +
        localB->CoreSubsys_p[ForEach_itr].BusCreator1.BearingFrictionCoeff *
        rtu_DynamicsInVehicle[ForEach_itr].BogieSupportedMass;

      /* End of Outputs for SubSystem: '<S131>/Fundamental Drag' */
      break;
    }

    /* End of SwitchCase: '<S131>/Switch Case' */

    /* RelationalOperator: '<S186>/Compare' incorporates:
     *  Constant: '<S186>/Constant'
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     */
    rtb_Compare_b = (rtu_CommonVehicleConfig[ForEach_itr].NumberOfAxles >
                     TrainDynamics_P.CoreSubsys_p.Constant_Value_k);

    /* Switch: '<S180>/Switch' */
    if (!rtb_Compare_b) {
      /* BusAssignment: '<S180>/Bus Assignment' incorporates:
       *  Constant: '<S180>/NoBearingDrag'
       */
      rtb_Merge1 = TrainDynamics_P.CoreSubsys_p.NoBearingDrag_Value;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Sum: '<S132>/Add2' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     *  Gain: '<S132>/Gain'
     *  Product: '<S132>/Product'
     *  Sum: '<S132>/Add'
     */
    this_mass_factor = (rtu_CommonVehicleConfig[ForEach_itr].GrossMass -
                        rtu_CommonVehicleConfig[ForEach_itr].TareMass) *
      (TrainDynamics_P.CoreSubsys_p.Gain_Gain_p *
       rtb_ImpSel_InsertedFor_Overrides_at_outport_0.LoadingVariation) +
      rtu_CommonVehicleConfig[ForEach_itr].LoadingMass;

    /* Saturate: '<S132>/Saturation1' */
    if (this_mass_factor > TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_n)
    {
      this_mass_factor = TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat_n;
    } else {
      if (this_mass_factor < TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_o)
      {
        this_mass_factor = TrainDynamics_P.CoreSubsys_p.Saturation1_LowerSat_o;
      }
    }

    /* End of Saturate: '<S132>/Saturation1' */

    /* Sum: '<S132>/Add1' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     */
    head_mass_factor = rtu_CommonVehicleConfig[ForEach_itr].TareMass +
      this_mass_factor;

    /* Trigonometry: '<S130>/theta' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     */
    rtb_gcost = atan(rtu_DynamicsInVehicle[ForEach_itr].TrackData.Gradient);

    /* Trigonometry: '<S130>/Trigonometric Function1' */
    rtb_sint = sin(rtb_gcost);

    /* Gain: '<S130>/sim coordinates' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     */
    tail_mass_factor = TrainDynamics_P.CoreSubsys_p.simcoordinates_Gain *
      rtu_DynamicsInVehicle[ForEach_itr].TrackData.Radius;

    /* Switch: '<S173>/Switch1' incorporates:
     *  Constant: '<S173>/Constant'
     *  Math: '<S130>/v_squared'
     *  Product: '<S173>/Divide'
     *  UnitDelay: '<S14>/Unit Delay'
     */
    if (tail_mass_factor != 0.0) {
      /* Switch: '<S173>/Switch2' incorporates:
       *  Constant: '<S173>/Constant1'
       */
      if (!(tail_mass_factor != 0.0)) {
        tail_mass_factor = TrainDynamics_P.CoreSubsys_p.Constant1_Value;
      }

      /* End of Switch: '<S173>/Switch2' */
      rtb_Switch1_l = localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE *
        localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE / tail_mass_factor;
    } else {
      rtb_Switch1_l = TrainDynamics_P.CoreSubsys_p.Constant_Value_b;
    }

    /* End of Switch: '<S173>/Switch1' */

    /* Trigonometry: '<S130>/Trigonometric Function4' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     */
    rtb_cosa = cos(rtu_DynamicsInVehicle[ForEach_itr].TrackData.Superelevation);

    /* Product: '<S130>/Product1' incorporates:
     *  Constant: '<S130>/g'
     *  Trigonometry: '<S130>/Trigonometric Function2'
     */
    rtb_gcost = TrainDynamics_P.CoreSubsys_p.g_Value * cos(rtb_gcost);

    /* Trigonometry: '<S130>/Trigonometric Function3' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     */
    rtb_RailReactionForce = sin(rtu_DynamicsInVehicle[ForEach_itr].
      TrackData.Superelevation);

    /* Sum: '<S130>/Add' incorporates:
     *  Product: '<S130>/Product4'
     *  Product: '<S130>/Product5'
     */
    rtb_PositionRear = rtb_Switch1_l * rtb_cosa + rtb_gcost *
      rtb_RailReactionForce;

    /* SampleTimeMath: '<S172>/TSamp'
     *
     * About '<S172>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    tail_mass_factor = rtb_PositionRear *
      TrainDynamics_P.CoreSubsys_p.TSamp_WtEt;

    /* Sum: '<S130>/Add1' incorporates:
     *  Product: '<S130>/Product7'
     *  Product: '<S130>/Product8'
     */
    rtb_gcost = rtb_Switch1_l * rtb_RailReactionForce + rtb_gcost * rtb_cosa;

    /* BusCreator: '<S130>/Bus Creator' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     *  Product: '<S130>/Product3'
     */
    rtb_BusCreator_g.RailReactionForce = rtu_DynamicsInVehicle[ForEach_itr].
      BogieSupportedMass * rtb_gcost;

    /* Gain: '<S171>/Gain' */
    rtb_gcost *= TrainDynamics_P.CoreSubsys_p.Gain_Gain_f;

    /* Saturate: '<S171>/Saturation' */
    if (rtb_gcost > TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_d) {
      rtb_gcost = TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_d;
    } else {
      if (rtb_gcost < TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_b) {
        rtb_gcost = TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_b;
      }
    }

    /* End of Saturate: '<S171>/Saturation' */

    /* Product: '<S171>/Product9' */
    rtb_gcost = rtb_PositionRear / rtb_gcost;

    /* BusCreator: '<S130>/Bus Creator' incorporates:
     *  Abs: '<S171>/Abs'
     *  Constant: '<S130>/g'
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     *  Gain: '<S130>/Gain'
     *  Product: '<S130>/Product'
     *  Product: '<S130>/Product2'
     *  Product: '<S130>/Product6'
     *  Sum: '<S172>/Diff'
     *  UnitDelay: '<S172>/UD'
     */
    rtb_BusCreator_g.DerailmentCoefficient = fabs(rtb_gcost);
    rtb_BusCreator_g.GravitationalForce = TrainDynamics_P.CoreSubsys_p.g_Value *
      rtb_sint * TrainDynamics_P.CoreSubsys_p.Gain_Gain_o * head_mass_factor;
    rtb_BusCreator_g.LateralForce = rtu_DynamicsInVehicle[ForEach_itr].
      BogieSupportedMass * rtb_PositionRear;
    rtb_BusCreator_g.LateralAcceleration = rtb_PositionRear;
    rtb_BusCreator_g.LateralAccelerationRate = tail_mass_factor -
      localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE;

    /* BusAssignment: '<S174>/Bus Assignment1' incorporates:
     *  Fcn: '<S181>/Fcn'
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     *  Product: '<S174>/Product'
     *  Product: '<S174>/Product1'
     *  Product: '<S174>/Product3'
     *  Product: '<S181>/Product'
     */
    rtb_BusAssignment1.AdditionalNonWheelDragForce =
      rtu_DynamicsInVehicle[ForEach_itr].NonWheelStoppingForce * rtb_InitFlag;
    rtb_BusAssignment1.AerodynamicDragForce = rtb_Gain_e * rtb_InitFlag;
    rtb_BusAssignment1.BearingDragForce =
      (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.BearingFrictionVariation /
       100.0 + 1.0) * (rtb_Merge1 * rtb_InitFlag);

    /* Switch: '<S180>/Switch1' incorporates:
     *  Abs: '<S179>/Abs'
     *  Constant: '<S180>/NoLateralDrag'
     *  Product: '<S179>/Product'
     */
    if (rtb_Compare_b) {
      rtb_Gain_e = fabs(rtb_BusCreator_g.LateralForce) * localB->
        CoreSubsys_p[ForEach_itr].BusCreator1.LateralFrictionCoeff;
    } else {
      rtb_Gain_e = TrainDynamics_P.CoreSubsys_p.NoLateralDrag_Value;
    }

    /* End of Switch: '<S180>/Switch1' */

    /* BusAssignment: '<S174>/Bus Assignment1' incorporates:
     *  Fcn: '<S182>/Fcn'
     *  Product: '<S174>/Product2'
     *  Product: '<S182>/Product'
     */
    rtb_BusAssignment1.LateralDragForce =
      (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.LateralFrictionVariation /
       100.0 + 1.0) * (rtb_Gain_e * rtb_InitFlag);

    /* Sum: '<S129>/Sum1' incorporates:
     *  Selector: '<S9>/Head'
     *  Selector: '<S9>/Tail'
     */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[0] =
      localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[1].Force - localB->
      CoreSubsys_p[ForEach_itr].ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0].
      Force;

    /* SignalConversion generated from: '<S129>/Vector Concatenate' */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[1] =
      rtb_BusAssignment1.AerodynamicDragForce;

    /* SignalConversion generated from: '<S129>/Vector Concatenate' */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[2] =
      rtb_BusAssignment1.AdditionalNonWheelDragForce;

    /* SignalConversion generated from: '<S129>/Vector Concatenate' */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[3] =
      rtb_BusCreator_g.GravitationalForce;

    /* Outputs for Enabled SubSystem: '<S14>/Longitudinal Wheel Force' incorporates:
     *  EnablePort: '<S128>/Enable'
     */
    /* RelationalOperator: '<S126>/Compare' incorporates:
     *  Constant: '<S126>/Constant'
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     */
    if (rtu_CommonVehicleConfig[ForEach_itr].NumberOfAxles >
        TrainDynamics_P.CoreSubsys_p.Constant_Value_j) {
      if (!localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE) {
        localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE = true;
      }

      /* Saturate: '<S141>/Saturation' */
      if (rtu_CommonVehicleConfig[ForEach_itr].NumberOfAxles >
          TrainDynamics_P.MaxAxles) {
        rtb_PositionRear = TrainDynamics_P.MaxAxles;
      } else if (rtu_CommonVehicleConfig[ForEach_itr].NumberOfAxles <
                 TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_h) {
        rtb_PositionRear = TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_h;
      } else {
        rtb_PositionRear = rtu_CommonVehicleConfig[ForEach_itr].NumberOfAxles;
      }

      /* End of Saturate: '<S141>/Saturation' */
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        /* DataTypeConversion: '<S141>/Data Type Conversion' incorporates:
         *  Constant: '<S141>/Max Axles2'
         *  RelationalOperator: '<S141>/Relational Operator'
         */
        localB->CoreSubsys_p[ForEach_itr].DataTypeConversion[Vehicle_Index] =
          (TrainDynamics_P.CoreSubsys_p.MaxAxles2_Value[Vehicle_Index] <=
           rtb_PositionRear);

        /* Product: '<S143>/BrakingForce' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         */
        localB->CoreSubsys_p[ForEach_itr].BrakingForce[Vehicle_Index] =
          rtu_DynamicsInVehicle[ForEach_itr].BrakingForce[Vehicle_Index] *
          rtb_InitFlag;
      }

      /* MATLAB Function: '<S142>/Braking Force Per Axle' */
      TrainDynamics_BrakingForcePerAxle(localB->CoreSubsys_p[ForEach_itr].
        DataTypeConversion, rtb_BusAssignment1.BearingDragForce,
        &localB->CoreSubsys_p[ForEach_itr].sf_BrakingForcePerAxle);

      /* MATLAB Function: '<S142>/Lateral Friction Force Per Axle' */
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        localB->CoreSubsys_p[ForEach_itr].ForcePerAxle[Vehicle_Index] = 0.0;
        x[Vehicle_Index] = (localB->CoreSubsys_p[ForEach_itr]
                            .DataTypeConversion[Vehicle_Index] > 0.0);
      }

      nz = x[0];
      for (Vehicle_Index = 0; Vehicle_Index < 5; Vehicle_Index++) {
        nz += x[Vehicle_Index + 1];
      }

      if (nz > 0) {
        rtb_InitFlag = rtb_BusAssignment1.LateralDragForce / static_cast<real_T>
          (nz);
        for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
          if (localB->CoreSubsys_p[ForEach_itr].DataTypeConversion[Vehicle_Index]
              > 0.0) {
            localB->CoreSubsys_p[ForEach_itr].ForcePerAxle[Vehicle_Index] =
              rtb_InitFlag;
          }
        }
      }

      /* End of MATLAB Function: '<S142>/Lateral Friction Force Per Axle' */

      /* Sum: '<S142>/Add1' */
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        rtb_Add1_o[Vehicle_Index] = (localB->CoreSubsys_p[ForEach_itr].
          BrakingForce[Vehicle_Index] + localB->CoreSubsys_p[ForEach_itr].
          sf_BrakingForcePerAxle.ForcePerAxle[Vehicle_Index]) +
          localB->CoreSubsys_p[ForEach_itr].ForcePerAxle[Vehicle_Index];
      }

      /* End of Sum: '<S142>/Add1' */

      /* Sum: '<S142>/Add' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
       */
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        localB->CoreSubsys_p[ForEach_itr].DrivingForce[Vehicle_Index] =
          rtu_DynamicsInVehicle[ForEach_itr].TractionForce[Vehicle_Index] +
          rtb_Add1_o[Vehicle_Index];
      }

      /* End of Sum: '<S142>/Add' */

      /* MATLAB Function: '<S142>/Reaction Force Per Axle' */
      TrainDynamics_BrakingForcePerAxle(localB->CoreSubsys_p[ForEach_itr].
        DataTypeConversion, rtb_BusCreator_g.RailReactionForce,
        &localB->CoreSubsys_p[ForEach_itr].sf_ReactionForcePerAxle);
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        /* Product: '<S143>/BrakePower' incorporates:
         *  UnitDelay: '<S14>/Unit Delay'
         */
        localB->CoreSubsys_p[ForEach_itr].BrakePower[Vehicle_Index] =
          localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE *
          localB->CoreSubsys_p[ForEach_itr].BrakingForce[Vehicle_Index];

        /* Sum: '<S144>/Add' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         */
        localB->CoreSubsys_p[ForEach_itr].Add[Vehicle_Index] =
          rtu_DynamicsInVehicle[ForEach_itr].TractionForce[Vehicle_Index] +
          rtb_Add1_o[Vehicle_Index];
      }

      /* If: '<S149>/If' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/Faults'
       *  Switch: '<S162>/Switch2'
       */
      if (localB->CoreSubsys_p[ForEach_itr].BusCreator1.UseSandFrictionCoeffs >
          0.0) {
        /* Outputs for IfAction SubSystem: '<S149>/Constant Friction While Sanding' incorporates:
         *  ActionPort: '<S161>/Action Port'
         */
        /* MATLAB Function: '<S161>/Dynamic Track Adhesion Variation' */
        TrainDynamics_DynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailDynamicFrictionCoeff,
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation,
          &localB->CoreSubsys_p[ForEach_itr].sf_DynamicTrackAdhesionVariation);

        /* MinMax: '<S161>/MinMax' incorporates:
         *  Constant: '<S161>/Constant'
         */
        if ((rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation
             < TrainDynamics_P.CoreSubsys_p.Constant_Value_o) || rtIsNaN
            (TrainDynamics_P.CoreSubsys_p.Constant_Value_o)) {
          rtb_TotalTraction =
            rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation;
        } else {
          rtb_TotalTraction = TrainDynamics_P.CoreSubsys_p.Constant_Value_o;
        }

        /* End of MinMax: '<S161>/MinMax' */

        /* Product: '<S161>/Product' incorporates:
         *  ForEachSliceSelector generated from: '<S4>/Faults'
         */
        rtb_Product_n = rtb_TotalTraction * rtu_Faults[ForEach_itr].PoorSanding;

        /* MATLAB Function: '<S161>/Sanding Dynamic Track Adhesion Variation' */
        TrainDynamics_SandingDynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailSandedDynamicFrictionCoeff,
          rtb_Product_n, &localB->CoreSubsys_p[ForEach_itr].
          sf_SandingDynamicTrackAdhesionVariation);

        /* MATLAB Function: '<S161>/Sanding Static Track Adhesion Variation' */
        TrainDynamics_SandingDynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailSandedStaticFrictionCoeff,
          rtb_Product_n, &localB->CoreSubsys_p[ForEach_itr].
          sf_SandingStaticTrackAdhesionVariation);

        /* MATLAB Function: '<S161>/Static Track Adhesion Variation' */
        TrainDynamics_DynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailStaticFrictionCoeff,
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation,
          &localB->CoreSubsys_p[ForEach_itr].sf_StaticTrackAdhesionVariation);

        /* Switch: '<S161>/Switch' */
        if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.SandingApplied >
            TrainDynamics_P.CoreSubsys_p.Switch_Threshold) {
          rtb_InitFlag = localB->CoreSubsys_p[ForEach_itr].
            sf_SandingStaticTrackAdhesionVariation.Output;
        } else {
          rtb_InitFlag = localB->CoreSubsys_p[ForEach_itr].
            sf_StaticTrackAdhesionVariation.Output;
        }

        /* End of Switch: '<S161>/Switch' */

        /* Switch: '<S161>/Switch1' */
        if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.SandingApplied >
            TrainDynamics_P.CoreSubsys_p.Switch1_Threshold) {
          rtb_Merge1 = localB->CoreSubsys_p[ForEach_itr].
            sf_SandingDynamicTrackAdhesionVariation.Output;
        } else {
          rtb_Merge1 = localB->CoreSubsys_p[ForEach_itr].
            sf_DynamicTrackAdhesionVariation.Output;
        }

        /* End of Switch: '<S161>/Switch1' */
        /* End of Outputs for SubSystem: '<S149>/Constant Friction While Sanding' */
      } else {
        /* Outputs for IfAction SubSystem: '<S149>/Variant Friction While Sanding' incorporates:
         *  ActionPort: '<S162>/Action Port'
         */
        if (rtu_Faults[ForEach_itr].PoorSanding >
            TrainDynamics_P.CoreSubsys_p.Switch2_Threshold) {
          /* Switch: '<S162>/Switch2' incorporates:
           *  Constant: '<S162>/Constant1'
           */
          rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Constant1_Value_i;
        } else {
          /* Switch: '<S162>/Switch2' incorporates:
           *  Constant: '<S162>/Constant6'
           */
          rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Constant6_Value;
        }

        /* Product: '<S162>/Divide1' */
        rtb_Divide1 =
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation *
          localB->CoreSubsys_p[ForEach_itr].BusCreator1.SandStaticFrictionFactor
          / rtb_InitFlag;

        /* Switch: '<S162>/Switch3' incorporates:
         *  Constant: '<S162>/Constant11'
         *  Constant: '<S162>/Constant9'
         *  ForEachSliceSelector generated from: '<S4>/Faults'
         */
        if (rtu_Faults[ForEach_itr].PoorSanding >
            TrainDynamics_P.CoreSubsys_p.Switch3_Threshold) {
          rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Constant9_Value;
        } else {
          rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Constant11_Value;
        }

        /* End of Switch: '<S162>/Switch3' */

        /* Product: '<S162>/Divide2' */
        rtb_Divide2 =
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation *
          localB->CoreSubsys_p[ForEach_itr].
          BusCreator1.SandDynamicFrictionFactor / rtb_InitFlag;

        /* MATLAB Function: '<S162>/Dynamic Track Adhesion Variation' */
        TrainDynamics_DynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailDynamicFrictionCoeff,
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation,
          &localB->CoreSubsys_p[ForEach_itr].sf_DynamicTrackAdhesionVariation_p);

        /* MATLAB Function: '<S162>/Sanding Dynamic Track Adhesion Variation' */
        TrainDynamics_SandingDynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailDynamicFrictionCoeff,
          rtb_Divide2, &localB->CoreSubsys_p[ForEach_itr].
          sf_SandingDynamicTrackAdhesionVariation_c);

        /* MATLAB Function: '<S162>/Sanding Static Track Adhesion Variation' */
        TrainDynamics_SandingDynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailStaticFrictionCoeff,
          rtb_Divide1, &localB->CoreSubsys_p[ForEach_itr].
          sf_SandingStaticTrackAdhesionVariation_m);

        /* MATLAB Function: '<S162>/Static Track Adhesion Variation' */
        TrainDynamics_DynamicTrackAdhesionVariation(localB->
          CoreSubsys_p[ForEach_itr].BusCreator1.RailStaticFrictionCoeff,
          rtb_ImpSel_InsertedFor_Overrides_at_outport_0.TrackAdhesionVariation,
          &localB->CoreSubsys_p[ForEach_itr].sf_StaticTrackAdhesionVariation_j);

        /* Switch: '<S162>/Switch' */
        if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.SandingApplied >
            TrainDynamics_P.CoreSubsys_p.Switch_Threshold_a) {
          rtb_InitFlag = localB->CoreSubsys_p[ForEach_itr].
            sf_SandingStaticTrackAdhesionVariation_m.Output;
        } else {
          rtb_InitFlag = localB->CoreSubsys_p[ForEach_itr].
            sf_StaticTrackAdhesionVariation_j.Output;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Switch: '<S162>/Switch1' */
        if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.SandingApplied >
            TrainDynamics_P.CoreSubsys_p.Switch1_Threshold_h) {
          rtb_Merge1 = localB->CoreSubsys_p[ForEach_itr].
            sf_SandingDynamicTrackAdhesionVariation_c.Output;
        } else {
          rtb_Merge1 = localB->CoreSubsys_p[ForEach_itr].
            sf_DynamicTrackAdhesionVariation_p.Output;
        }

        /* End of Switch: '<S162>/Switch1' */
        /* End of Outputs for SubSystem: '<S149>/Variant Friction While Sanding' */
      }

      /* End of If: '<S149>/If' */

      /* Assignment: '<S150>/Assignment' incorporates:
       *  Constant: '<S150>/Locked Axle Index'
       *  Constant: '<S150>/Max Axles1'
       *  ForEachSliceSelector generated from: '<S4>/Faults'
       */
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        localB->CoreSubsys_p[ForEach_itr].Assignment[Vehicle_Index] =
          TrainDynamics_P.CoreSubsys_p.MaxAxles1_Value[Vehicle_Index];
      }

      localB->CoreSubsys_p[ForEach_itr].Assignment[static_cast<int32_T>
        (TrainDynamics_P.CoreSubsys_p.LockedAxleIndex_Value) - 1] =
        rtu_Faults[ForEach_itr].LockedAxle;

      /* End of Assignment: '<S150>/Assignment' */

      /* Gain: '<S144>/Gain' */
      rtb_Gain_e = TrainDynamics_P.CoreSubsys_p.Gain_Gain_a *
        rtu_CommonVehicleConfig[ForEach_itr].WheelDiameter;

      /* Outputs for Iterator SubSystem: '<S144>/AxleModel' incorporates:
       *  ForEach: '<S148>/For Each'
       */
      for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
        /* Outputs for Enabled SubSystem: '<S148>/AxleModelEnabled' incorporates:
         *  EnablePort: '<S151>/Enable'
         */
        if (localB->CoreSubsys_p[ForEach_itr].DataTypeConversion[ForEach_itr_n] >
            0.0) {
          if (!localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              AxleModelEnabled_MODE) {
            /* InitializeConditions for UnitDelay: '<S151>/Unit Delay1' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE_k =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_a;

            /* InitializeConditions for UnitDelay: '<S155>/Unit Delay1' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE_n =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition_f;

            /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay_DSTATE =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay_InitialCondition;

            /* InitializeConditions for UnitDelay: '<S156>/Unit Delay1' */
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.UnitDelay1_InitialCondition;
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              AxleModelEnabled_MODE = true;
          }

          /* Signum: '<S151>/Forwards' incorporates:
           *  UnitDelay: '<S14>/Unit Delay'
           */
          if (localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE < 0.0) {
            rtb_sint = -1.0;
          } else if (localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE > 0.0)
          {
            rtb_sint = 1.0;
          } else if (localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE == 0.0)
          {
            rtb_sint = 0.0;
          } else {
            rtb_sint = (rtNaN);
          }

          /* End of Signum: '<S151>/Forwards' */

          /* Saturate: '<S155>/Saturation' */
          if (rtb_Gain_e >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_UpperSat) {
            rtb_gcost =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_UpperSat;
          } else if (rtb_Gain_e <
                     TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_LowerSat)
          {
            rtb_gcost =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_LowerSat;
          } else {
            rtb_gcost = rtb_Gain_e;
          }

          /* End of Saturate: '<S155>/Saturation' */

          /* Gain: '<S159>/BrakingDeltaLimit' incorporates:
           *  Product: '<S155>/Divide2'
           *  UnitDelay: '<S14>/Unit Delay'
           */
          rtb_Switch1_l = localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE /
            rtb_gcost *
            TrainDynamics_P.CoreSubsys_p.CoreSubsys.BrakingDeltaLimit_Gain;

          /* Switch: '<S159>/Switch3' incorporates:
           *  Constant: '<S159>/Constant'
           */
          if (rtb_sint >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.Switch3_Threshold) {
            rtb_PositionRear =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value_m;
          } else {
            rtb_PositionRear = rtb_Switch1_l;
          }

          /* End of Switch: '<S159>/Switch3' */

          /* InitialCondition: '<S156>/IC' */
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              IC_FirstOutputTime) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              IC_FirstOutputTime = false;
            rtb_TotalTraction = TrainDynamics_P.CoreSubsys_p.CoreSubsys.IC_Value;
          } else {
            rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr]
              .Assignment[ForEach_itr_n];
          }

          /* End of InitialCondition: '<S156>/IC' */

          /* Switch: '<S153>/Switch2' incorporates:
           *  Product: '<S151>/Dynamic Friction Limit'
           *  Product: '<S151>/Static Friction Limit'
           *  UnitDelay: '<S151>/Unit Delay1'
           */
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE_k) {
            rtb_RailReactionForce = localB->CoreSubsys_p[ForEach_itr].
              sf_ReactionForcePerAxle.ForcePerAxle[ForEach_itr_n] * rtb_Merge1;
          } else {
            rtb_RailReactionForce = localB->CoreSubsys_p[ForEach_itr].
              sf_ReactionForcePerAxle.ForcePerAxle[ForEach_itr_n] * rtb_InitFlag;
          }

          /* End of Switch: '<S153>/Switch2' */

          /* Switch: '<S154>/Switch1' incorporates:
           *  RelationalOperator: '<S154>/Greater Than  Upper Limit'
           */
          if (localB->CoreSubsys_p[ForEach_itr].Add[ForEach_itr_n] >
              rtb_RailReactionForce) {
            rtb_cosa = rtb_RailReactionForce;
          } else {
            /* Gain: '<S151>/Gain' */
            rtb_cosa = TrainDynamics_P.CoreSubsys_p.CoreSubsys.Gain_Gain *
              rtb_RailReactionForce;

            /* Switch: '<S154>/Switch2' incorporates:
             *  RelationalOperator: '<S154>/Less Than Lower Limit'
             */
            if (!(localB->CoreSubsys_p[ForEach_itr].Add[ForEach_itr_n] <
                  rtb_cosa)) {
              rtb_cosa = localB->CoreSubsys_p[ForEach_itr].Add[ForEach_itr_n];
            }

            /* End of Switch: '<S154>/Switch2' */
          }

          /* End of Switch: '<S154>/Switch1' */

          /* Switch: '<S153>/Switch1' incorporates:
           *  Constant: '<S153>/Friction Force1'
           *  Product: '<S153>/Product1'
           *  UnitDelay: '<S151>/Unit Delay'
           *  UnitDelay: '<S151>/Unit Delay1'
           */
          if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE_k) {
            rtb_RailReactionForce *= localDW->CoreSubsys_p[ForEach_itr].
              CoreSubsys[ForEach_itr_n].UnitDelay_DSTATE;
          } else {
            rtb_RailReactionForce =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.FrictionForce1_Value;
          }

          /* End of Switch: '<S153>/Switch1' */

          /* Switch: '<S156>/SelReset' incorporates:
           *  Abs: '<S155>/Abs1'
           *  Constant: '<S155>/MomentOfInertia'
           *  Logic: '<S155>/Spin1'
           *  Product: '<S155>/Divide'
           *  Product: '<S155>/Divide1'
           *  SampleTimeMath: '<S156>/Weighted Sample Time'
           *  Sum: '<S155>/Subtract1'
           *  Sum: '<S155>/Subtract2'
           *  Sum: '<S156>/Sum1'
           *  Switch: '<S155>/Switch4'
           *  UnitDelay: '<S155>/Unit Delay1'
           *  UnitDelay: '<S156>/Unit Delay1'
           *
           * About '<S156>/Weighted Sample Time':
           *  y = u * K where K = ( w * Ts )
           */
          if (rtb_TotalTraction != 0.0) {
            rtb_TotalTraction = rtb_Switch1_l;
          } else {
            if ((fabs(localB->CoreSubsys_p[ForEach_itr].Add[ForEach_itr_n] -
                      rtb_cosa) != 0.0) || localDW->CoreSubsys_p[ForEach_itr].
                CoreSubsys[ForEach_itr_n].UnitDelay1_DSTATE_n) {
              /* Switch: '<S155>/Switch4' */
              rtb_TotalTraction = localB->CoreSubsys_p[ForEach_itr]
                .Add[ForEach_itr_n];
            } else {
              /* Switch: '<S155>/Switch4' incorporates:
               *  Constant: '<S155>/No AdditionalForce'
               */
              rtb_TotalTraction =
                TrainDynamics_P.CoreSubsys_p.CoreSubsys.NoAdditionalForce_Value;
            }

            rtb_TotalTraction = (rtb_TotalTraction - rtb_RailReactionForce) /
              rtb_gcost /
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.MomentOfInertia_Value *
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.WeightedSampleTime_WtEt +
              localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
              UnitDelay1_DSTATE;
          }

          /* End of Switch: '<S156>/SelReset' */

          /* Switch: '<S160>/Switch2' incorporates:
           *  RelationalOperator: '<S160>/LowerRelop1'
           */
          if (!(rtb_TotalTraction > rtb_PositionRear)) {
            /* Switch: '<S159>/Switch2' incorporates:
             *  Constant: '<S159>/Constant'
             *  Gain: '<S159>/Gain4'
             */
            if (!(rtb_sint >
                  TrainDynamics_P.CoreSubsys_p.CoreSubsys.Switch2_Threshold)) {
              rtb_Switch1_l = TrainDynamics_P.CoreSubsys_p.CoreSubsys.Gain4_Gain
                * TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value_m;
            }

            /* End of Switch: '<S159>/Switch2' */

            /* Switch: '<S160>/Switch' incorporates:
             *  RelationalOperator: '<S160>/UpperRelop'
             */
            if (rtb_TotalTraction < rtb_Switch1_l) {
              rtb_PositionRear = rtb_Switch1_l;
            } else {
              rtb_PositionRear = rtb_TotalTraction;
            }

            /* End of Switch: '<S160>/Switch' */
          }

          /* End of Switch: '<S160>/Switch2' */

          /* Switch: '<S157>/Switch2' incorporates:
           *  Abs: '<S157>/Abs'
           */
          if (fabs(rtb_PositionRear) >
              TrainDynamics_P.CoreSubsys_p.CoreSubsys.SnapToZero_threshold) {
            rtb_TotalTraction = rtb_PositionRear;
          } else {
            rtb_TotalTraction = 0.0;
          }

          /* End of Switch: '<S157>/Switch2' */

          /* Product: '<S155>/Product' */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].v =
            rtb_TotalTraction * rtb_gcost;

          /* Signum: '<S155>/Sign2' */
          if (localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].v <
              0.0) {
            rtb_gcost = -1.0;
          } else if (localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n]
                     .v > 0.0) {
            rtb_gcost = 1.0;
          } else if (localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n]
                     .v == 0.0) {
            rtb_gcost = 0.0;
          } else {
            rtb_gcost = (rtNaN);
          }

          /* End of Signum: '<S155>/Sign2' */

          /* RelationalOperator: '<S158>/Compare' incorporates:
           *  Constant: '<S158>/Constant'
           */
          rtb_Compare_h = (rtb_gcost !=
                           TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value);

          /* RelationalOperator: '<S151>/RelativeSlipPositive' */
          rtb_Compare_b = (rtb_sint == rtb_gcost);

          /* DataTypeConversion: '<S151>/Data Type Conversion2' incorporates:
           *  Logic: '<S151>/Spin'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            DataTypeConversion2 = (rtb_Compare_h && rtb_Compare_b);

          /* DataTypeConversion: '<S151>/Data Type Conversion3' incorporates:
           *  Logic: '<S151>/RelativeSlipNegative'
           *  Logic: '<S151>/Skid'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            DataTypeConversion3 = (rtb_Compare_h && (!rtb_Compare_b));

          /* Switch: '<S151>/Switch5' */
          if (rtb_Compare_h) {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].Switch5 =
              rtb_RailReactionForce;
          } else {
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].Switch5 =
              rtb_cosa;
          }

          /* End of Switch: '<S151>/Switch5' */

          /* Sum: '<S151>/VehicleSpeedandDelta' incorporates:
           *  UnitDelay: '<S14>/Unit Delay'
           */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].WheelSpeed
            = localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE +
            localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].v;

          /* Update for UnitDelay: '<S151>/Unit Delay1' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            UnitDelay1_DSTATE_k = rtb_Compare_h;

          /* Update for UnitDelay: '<S155>/Unit Delay1' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            UnitDelay1_DSTATE_n = rtb_Compare_h;

          /* Update for UnitDelay: '<S151>/Unit Delay' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            UnitDelay_DSTATE = rtb_gcost;

          /* Update for UnitDelay: '<S156>/Unit Delay1' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            UnitDelay1_DSTATE = rtb_PositionRear;
        } else {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            AxleModelEnabled_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S148>/AxleModelEnabled' */

        /* Outputs for Enabled SubSystem: '<S148>/PackWheelOutputs' incorporates:
         *  EnablePort: '<S152>/Enable'
         */
        if (localB->CoreSubsys_p[ForEach_itr].DataTypeConversion[ForEach_itr_n] >
            0.0) {
          /* BusCreator: '<S152>/Bus Creator' */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.ForceTransmitted = localB->CoreSubsys_p[ForEach_itr].
            CoreSubsys[ForEach_itr_n].Switch5;
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.Speed = localB->CoreSubsys_p[ForEach_itr]
            .CoreSubsys[ForEach_itr_n].WheelSpeed;
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.SpeedDelta = localB->CoreSubsys_p[ForEach_itr]
            .CoreSubsys[ForEach_itr_n].v;
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.Spin = localB->CoreSubsys_p[ForEach_itr]
            .CoreSubsys[ForEach_itr_n].DataTypeConversion2;
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.Skid = localB->CoreSubsys_p[ForEach_itr]
            .CoreSubsys[ForEach_itr_n].DataTypeConversion3;
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.DrivingForce = localB->CoreSubsys_p[ForEach_itr].
            DrivingForce[ForEach_itr_n];
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.LateralFrictionForce = localB->CoreSubsys_p[ForEach_itr].
            ForcePerAxle[ForEach_itr_n];
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.BrakingForce = localB->CoreSubsys_p[ForEach_itr].
            BrakingForce[ForEach_itr_n];
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            BusCreator.BrakePower = localB->CoreSubsys_p[ForEach_itr]
            .BrakePower[ForEach_itr_n];
        }

        /* End of Outputs for SubSystem: '<S148>/PackWheelOutputs' */

        /* ForEachSliceAssignment generated from: '<S148>/Wheel_Out' */
        localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_Wheel_Out_at_inport_0[ForEach_itr_n] =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].BusCreator;

        /* ForEachSliceAssignment generated from: '<S148>/Axle Longitudinal Force' */
        rtb_ImpAsg_InsertedFor_AxleLongitudinalForce_at_inport_0[ForEach_itr_n] =
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].Switch5;
      }

      /* End of Outputs for SubSystem: '<S144>/AxleModel' */

      /* Sum: '<S144>/Sum of Elements1' incorporates:
       *  ForEachSliceSelector generated from: '<S148>/AxleEnabled'
       */
      rtb_InitFlag = -0.0;
      for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
        rtb_InitFlag +=
          rtb_ImpAsg_InsertedFor_AxleLongitudinalForce_at_inport_0[Vehicle_Index];
      }

      localB->CoreSubsys_p[ForEach_itr].VectorConcatenate[4] = rtb_InitFlag;

      /* End of Sum: '<S144>/Sum of Elements1' */
    } else {
      if (localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE) {
        /* Disable for Iterator SubSystem: '<S144>/AxleModel' */
        for (ForEach_itr_n = 0; ForEach_itr_n < 6; ForEach_itr_n++) {
          /* Disable for Enabled SubSystem: '<S148>/AxleModelEnabled' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys[ForEach_itr_n].
            AxleModelEnabled_MODE = false;

          /* End of Disable for SubSystem: '<S148>/AxleModelEnabled' */
        }

        /* End of Disable for SubSystem: '<S144>/AxleModel' */
        localDW->CoreSubsys_p[ForEach_itr].LongitudinalWheelForce_MODE = false;
      }
    }

    /* End of RelationalOperator: '<S126>/Compare' */
    /* End of Outputs for SubSystem: '<S14>/Longitudinal Wheel Force' */

    /* Sum: '<S129>/Sum of Elements' */
    rtb_Switch1_l = -0.0;
    for (Vehicle_Index = 0; Vehicle_Index < 5; Vehicle_Index++) {
      rtb_Switch1_l += localB->CoreSubsys_p[ForEach_itr]
        .VectorConcatenate[Vehicle_Index];
    }

    /* End of Sum: '<S129>/Sum of Elements' */

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S133>/Constant'
     *  Product: '<S133>/Divide'
     *  Saturate: '<S133>/Saturation'
     */
    if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.FreezeDynamics >
        TrainDynamics_P.CoreSubsys_p.Switch_Threshold_o) {
      rtb_Acceleration = TrainDynamics_P.CoreSubsys_p.Constant_Value_d;
    } else {
      if (head_mass_factor > TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_i)
      {
        /* Saturate: '<S133>/Saturation' */
        rtb_gcost = TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_i;
      } else if (head_mass_factor <
                 TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_f) {
        /* Saturate: '<S133>/Saturation' */
        rtb_gcost = TrainDynamics_P.CoreSubsys_p.Saturation_LowerSat_f;
      } else {
        /* Saturate: '<S133>/Saturation' */
        rtb_gcost = head_mass_factor;
      }

      rtb_Acceleration = rtb_Switch1_l / rtb_gcost;
    }

    /* End of Switch: '<S133>/Switch' */

    /* RelationalOperator: '<S140>/Compare' incorporates:
     *  Constant: '<S140>/Constant'
     */
    rtb_Compare_b =
      (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.FreezeDynamics >
       TrainDynamics_P.CoreSubsys_p.CompareToConstant1_const);

    /* Switch: '<S139>/Freeze' incorporates:
     *  Constant: '<S139>/Constant'
     *  Switch: '<S139>/SetValue1'
     */
    if (rtb_Compare_b) {
      rtb_InitFlag = TrainDynamics_P.CoreSubsys_p.Constant_Value_n;
    } else if (localB->RunInit != 0.0) {
      /* Switch: '<S139>/SetValue1' */
      rtb_InitFlag = localB->CoreSubsys_p[ForEach_itr].
        BusCreator1.InitialVelocity;
    } else {
      rtb_InitFlag =
        rtb_ImpSel_InsertedFor_Overrides_at_outport_0.VelocitySetValue;
    }

    /* End of Switch: '<S139>/Freeze' */

    /* DiscreteIntegrator: '<S136>/VelocityIntegrator' incorporates:
     *  Logic: '<S139>/Set'
     */
    if (localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_IC_LOADING != 0) {
      localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_DSTATE =
        rtb_InitFlag;
    }

    if (rtb_ImpSel_InsertedFor_Overrides_at_outport_0.VelocitySetFlag ||
        (localB->RunInit != 0.0) || rtb_Compare_b) {
      localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_DSTATE =
        rtb_InitFlag;
    }

    rtb_RailReactionForce =
      TrainDynamics_P.CoreSubsys_p.VelocityIntegrator_gainval * rtb_Acceleration;
    rtb_InitFlag = rtb_RailReactionForce + localDW->CoreSubsys_p[ForEach_itr].
      VelocityIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S136>/VelocityIntegrator' */

    /* RelationalOperator: '<S138>/Compare' incorporates:
     *  Abs: '<S134>/Abs'
     *  Constant: '<S138>/Constant'
     */
    rtb_Compare_b = (fabs(rtb_InitFlag) >
                     TrainDynamics_P.PRM_TrainDynamics.SnapToZeroVelocity);

    /* Switch: '<S134>/Switch' incorporates:
     *  Switch: '<S134>/Switch1'
     */
    if (rtb_Compare_b) {
      rtb_Switch = rtb_InitFlag;
      rtb_gcost = rtb_Acceleration;
    } else {
      rtb_Switch = 0.0;
      rtb_gcost = 0.0;
    }

    /* End of Switch: '<S134>/Switch' */

    /* DiscreteIntegrator: '<S135>/PositionIntegrator' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/InitialPosition'
     */
    if (localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_SYSTEM_ENABLE != 0)
    {
      if (localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_IC_LOADING != 0)
      {
        localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE = localB->
          y[ForEach_itr];
      }

      localB->CoreSubsys_p[ForEach_itr].Position = localDW->
        CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE;
    } else if ((localB->RunInit != 0.0) || (localDW->CoreSubsys_p[ForEach_itr].
                PositionIntegrator_PrevResetState != 0)) {
      localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE = localB->
        y[ForEach_itr];
      localB->CoreSubsys_p[ForEach_itr].Position = localDW->
        CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE;
    } else {
      localB->CoreSubsys_p[ForEach_itr].Position =
        TrainDynamics_P.CoreSubsys_p.PositionIntegrator_gainval * rtb_Switch +
        localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S135>/PositionIntegrator' */

    /* SampleTimeMath: '<S137>/TSamp'
     *
     * About '<S137>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Gain_e = rtb_Acceleration * TrainDynamics_P.CoreSubsys_p.TSamp_WtEt_h;

    /* Switch: '<S134>/Switch2' incorporates:
     *  Sum: '<S137>/Diff'
     *  UnitDelay: '<S137>/UD'
     */
    if (rtb_Compare_b) {
      rtb_sint = rtb_Gain_e - localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE_l;
    } else {
      rtb_sint = 0.0;
    }

    /* End of Switch: '<S134>/Switch2' */

    /* Sum: '<S127>/Sum' incorporates:
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     */
    rtb_PositionRear = localB->CoreSubsys_p[ForEach_itr].Position -
      rtu_CommonVehicleConfig[ForEach_itr].Length;

    /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
     *  BusCreator: '<S127>/Bus Creator'
     */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate_k[0] =
      localB->CoreSubsys_p[ForEach_itr].Position;

    /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
     *  BusCreator: '<S127>/Bus Creator'
     */
    localB->CoreSubsys_p[ForEach_itr].VectorConcatenate_k[1] = rtb_PositionRear;

    /* SignalConversion generated from: '<S13>/UpdateMimicPerCoupler' */
    localB->CoreSubsys_p[ForEach_itr].
      TmpSignalConversionAtUpdateMimicPerCouplerInport5[0] =
      localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[1];
    localB->CoreSubsys_p[ForEach_itr].
      TmpSignalConversionAtUpdateMimicPerCouplerInport5[1] =
      localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0];

    /* Outputs for Iterator SubSystem: '<S13>/UpdateMimicPerCoupler' incorporates:
     *  ForEach: '<S119>/For Each'
     */
    for (ForEach_itr_d = 0; ForEach_itr_d < 2; ForEach_itr_d++) {
      /* Outputs for Enabled SubSystem: '<S119>/UpdateMimicOutputs' incorporates:
       *  EnablePort: '<S121>/Enable'
       */
      /* ForEachSliceSelector generated from: '<S119>/ExternalCoupling' */
      if (localB->CoreSubsys_p[ForEach_itr].
          ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[ForEach_itr_d]) {
        if (!localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            UpdateMimicOutputs_MODE) {
          /* InitializeConditions for S-Function (sfix_udelay): '<S122>/Tapped Delay' */
          for (Vehicle_Index = 0; Vehicle_Index < 10; Vehicle_Index++) {
            localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
              TappedDelay_X[Vehicle_Index] =
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.TappedDelay_vinit;
          }

          /* End of InitializeConditions for S-Function (sfix_udelay): '<S122>/Tapped Delay' */
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            UpdateMimicOutputs_MODE = true;
        }

        /* Sum: '<S121>/Total Traction' */
        rtb_TotalTraction = -0.0;

        /* Sum: '<S121>/TotalBraking' */
        rtb_cosa = -0.0;
        for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
          /* Sum: '<S121>/Total Traction' incorporates:
           *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
           */
          rtb_TotalTraction += rtu_DynamicsInVehicle[ForEach_itr]
            .TractionForce[Vehicle_Index];

          /* Sum: '<S121>/TotalBraking' incorporates:
           *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
           */
          rtb_cosa += rtu_DynamicsInVehicle[ForEach_itr]
            .BrakingForce[Vehicle_Index];
        }

        /* Sum: '<S123>/SumWt' incorporates:
         *  Constant: '<S122>/Constant'
         */
        rtb_Merge1 = -0.0;
        for (Vehicle_Index = 0; Vehicle_Index < 10; Vehicle_Index++) {
          rtb_Merge1 +=
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.WMAV10_weights[Vehicle_Index];
        }

        /* End of Sum: '<S123>/SumWt' */

        /* Switch: '<S123>/Switch1' incorporates:
         *  Constant: '<S123>/Constant1'
         *  Constant: '<S124>/Constant'
         *  Product: '<S123>/WtAvgCalc'
         *  RelationalOperator: '<S124>/Compare'
         *  Switch: '<S123>/Switch'
         */
        if (rtb_Merge1 !=
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Constant_Value_m) {
          /* Sum: '<S123>/SumInWt' */
          rtb_SumInWt = -0.0;
          for (Vehicle_Index = 0; Vehicle_Index < 10; Vehicle_Index++) {
            /* Sum: '<S123>/SumInWt' incorporates:
             *  Constant: '<S122>/Constant'
             *  Product: '<S123>/InWt'
             *  S-Function (sfix_udelay): '<S122>/Tapped Delay'
             */
            rtb_SumInWt += localDW->CoreSubsys_p[ForEach_itr]
              .CoreSubsys_i[ForEach_itr_d].TappedDelay_X[Vehicle_Index] *
              TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.WMAV10_weights[Vehicle_Index];
          }

          rtb_Merge1 = rtb_SumInWt / rtb_Merge1;
        } else {
          rtb_Merge1 = TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.Constant1_Value;
        }

        /* End of Switch: '<S123>/Switch1' */

        /* BusAssignment: '<S121>/Bus Assignment' incorporates:
         *  BusCreator: '<S127>/Bus Creator'
         *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
         *  SampleTimeMath: '<S121>/TimeAtOutput'
         *
         * About '<S121>/TimeAtOutput':
         *  y = u + K where K = ( w * Ts )
         */
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Mass = head_mass_factor;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Time = rtu_SimData->SimulationTime +
          TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.TimeAtOutput_WtEt;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Position = localB->CoreSubsys_p[ForEach_itr].
          VectorConcatenate_k[ForEach_itr_d];
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Velocity = rtb_Switch;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Acceleration = rtb_gcost;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Gradient = rtu_DynamicsInVehicle[ForEach_itr].
          TrackData.Gradient;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.Radius = rtu_DynamicsInVehicle[ForEach_itr].
          TrackData.Radius;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.TractiveForce = rtb_TotalTraction;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.BrakingForce = rtb_cosa;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.OtherCouplerForce = rtb_Merge1;
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          BusAssignment.OtherCouplerForceRate = 0.0;

        /* Update for S-Function (sfix_udelay): '<S122>/Tapped Delay' */
        for (Vehicle_Index = 0; Vehicle_Index < 9; Vehicle_Index++) {
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            TappedDelay_X[Vehicle_Index] = localDW->CoreSubsys_p[ForEach_itr].
            CoreSubsys_i[ForEach_itr_d].TappedDelay_X[Vehicle_Index + 1];
        }

        localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
          TappedDelay_X[9] = localB->CoreSubsys_p[ForEach_itr].
          TmpSignalConversionAtUpdateMimicPerCouplerInport5[ForEach_itr_d].Force;

        /* End of Update for S-Function (sfix_udelay): '<S122>/Tapped Delay' */
      } else {
        if (localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            UpdateMimicOutputs_MODE) {
          /* Disable for Outport: '<S121>/MimicModelOut' */
          localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            BusAssignment =
            TrainDynamics_P.CoreSubsys_p.CoreSubsys_i.MimicModelOut_Y0;
          localDW->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
            UpdateMimicOutputs_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S119>/UpdateMimicOutputs' */

      /* ForEachSliceAssignment generated from: '<S119>/CouplerOut' incorporates:
       *  BusAssignment: '<S119>/MimicOutAssignment'
       */
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].Force =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].Force;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].SpringForce =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].SpringForce;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].DampingForce =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].DampingForce;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].BuffForce =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].BuffForce;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].DraftForce =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].DraftForce;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].ImpactForce =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].ImpactForce;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].Breakage =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].Breakage;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].Extension =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].Extension;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].ExtensionRate
        = localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].ExtensionRate;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].
        ExternalCoupling = localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Coupler_Out_at_inport_0[ForEach_itr_d].
        ExternalCoupling;
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[ForEach_itr_d].Mimic =
        localB->CoreSubsys_p[ForEach_itr].CoreSubsys_i[ForEach_itr_d].
        BusAssignment;
    }

    /* End of Outputs for SubSystem: '<S13>/UpdateMimicPerCoupler' */

    /* Gain: '<S125>/Integral Gain' incorporates:
     *  UnitDelay: '<S14>/Unit Delay'
     */
    rtb_Merge1 = TrainDynamics_P.CoreSubsys_p.IntegralGain_Gain *
      localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE;

    /* Update for UnitDelay: '<S14>/Unit Delay' incorporates:
     *  BusCreator: '<S127>/Bus Creator'
     */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay_DSTATE = rtb_Switch;

    /* Update for DiscreteIntegrator: '<S125>/Integrator' */
    localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE +=
      TrainDynamics_P.CoreSubsys_p.Integrator_gainval * rtb_Merge1;
    if (localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE >=
        TrainDynamics_P.CoreSubsys_p.Integrator_UpperSat) {
      localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE =
        TrainDynamics_P.CoreSubsys_p.Integrator_UpperSat;
    } else {
      if (localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE <=
          TrainDynamics_P.CoreSubsys_p.Integrator_LowerSat) {
        localDW->CoreSubsys_p[ForEach_itr].Integrator_DSTATE =
          TrainDynamics_P.CoreSubsys_p.Integrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S125>/Integrator' */

    /* Update for UnitDelay: '<S172>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE = tail_mass_factor;

    /* Update for DiscreteIntegrator: '<S136>/VelocityIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_IC_LOADING = 0U;
    localDW->CoreSubsys_p[ForEach_itr].VelocityIntegrator_DSTATE =
      rtb_RailReactionForce + rtb_InitFlag;

    /* Update for DiscreteIntegrator: '<S135>/PositionIntegrator' */
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_SYSTEM_ENABLE = 0U;
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_IC_LOADING = 0U;
    localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_DSTATE =
      TrainDynamics_P.CoreSubsys_p.PositionIntegrator_gainval * rtb_Switch +
      localB->CoreSubsys_p[ForEach_itr].Position;
    if (localB->RunInit > 0.0) {
      localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = 1;
    } else if (localB->RunInit < 0.0) {
      localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = -1;
    } else if (localB->RunInit == 0.0) {
      localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = 0;
    } else {
      localDW->CoreSubsys_p[ForEach_itr].PositionIntegrator_PrevResetState = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S135>/PositionIntegrator' */

    /* Update for UnitDelay: '<S137>/UD' */
    localDW->CoreSubsys_p[ForEach_itr].UD_DSTATE_l = rtb_Gain_e;

    /* ForEachSliceAssignment generated from: '<S4>/VehicleCouplingData' incorporates:
     *  BusCreator: '<S127>/Bus Creator'
     *  ForEachSliceSelector generated from: '<S4>/CommonVehicleConfig '
     *  Selector: '<S120>/Head'
     *  Selector: '<S120>/Tail'
     */
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].Enabled =
      rtu_CommonVehicleConfig[ForEach_itr].Enabled;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      VehicleID = rtu_CommonVehicleConfig[ForEach_itr].VehicleID;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      HeadPosition = localB->CoreSubsys_p[ForEach_itr].Position;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      TailPosition = rtb_PositionRear;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].Velocity
      = rtb_Switch;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].Mass =
      head_mass_factor;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      MovingForce = rtb_Switch1_l;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      HeadCouplerForce = localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0].Force;
    rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[ForEach_itr].
      TailCouplerForce = localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[1].Force;

    /* ForEachSliceAssignment generated from: '<S4>/DynamicsOut' incorporates:
     *  BusCreator: '<S12>/Bus Creator'
     */
    rty_DynamicsVehicleOut[ForEach_itr].Drag = rtb_BusAssignment1;

    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[0] =
      localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[0];

    /* ForEachSliceAssignment generated from: '<S4>/DynamicsOut' incorporates:
     *  BusCreator: '<S12>/Bus Creator'
     */
    rty_DynamicsVehicleOut[ForEach_itr].Couplers[0] =
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[0];

    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    localDW->CoreSubsys_p[ForEach_itr].UnitDelay1_DSTATE[1] =
      localB->CoreSubsys_p[ForEach_itr].
      ImpAsg_InsertedFor_Coupler_Out_at_inport_0[1];

    /* ForEachSliceAssignment generated from: '<S4>/DynamicsOut' incorporates:
     *  BusCreator: '<S127>/Bus Creator'
     *  BusCreator: '<S12>/Bus Creator'
     *  ForEachSliceSelector generated from: '<S4>/DynamicsIn'
     */
    rty_DynamicsVehicleOut[ForEach_itr].Couplers[1] =
      rtb_ImpAsg_InsertedFor_CouplerOut_at_inport_0[1];
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.Position = localB->
      CoreSubsys_p[ForEach_itr].Position;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.Velocity = rtb_Switch;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.Acceleration = rtb_gcost;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.Jerk = rtb_sint;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.PositionRear = rtb_PositionRear;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.MovingForce = rtb_Switch1_l;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.Mass = head_mass_factor;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.LoadingMass = this_mass_factor;
    rty_DynamicsVehicleOut[ForEach_itr].Inertia.BogieSupportedMass =
      rtu_DynamicsInVehicle[ForEach_itr].BogieSupportedMass;
    rty_DynamicsVehicleOut[ForEach_itr].TrackGeometry = rtb_BusCreator_g;
    for (Vehicle_Index = 0; Vehicle_Index < 6; Vehicle_Index++) {
      rty_DynamicsVehicleOut[ForEach_itr].Wheel[Vehicle_Index] =
        localB->CoreSubsys_p[ForEach_itr].
        ImpAsg_InsertedFor_Wheel_Out_at_inport_0[Vehicle_Index];
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Train Dynamics' */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  localDW->DiscreteTimeIntegrator_DSTATE +=
    TrainDynamics_P.DiscreteTimeIntegrator_gainval *
    TrainDynamics_P.Constant_Value;
  if (localDW->DiscreteTimeIntegrator_DSTATE >=
      TrainDynamics_P.DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE =
      TrainDynamics_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE <=
        TrainDynamics_P.DiscreteTimeIntegrator_LowerSat) {
      localDW->DiscreteTimeIntegrator_DSTATE =
        TrainDynamics_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0],
         &rtb_ImpAsg_InsertedFor_VehicleCouplingData_at_inport_0[0], sizeof
         (BD_TrainDynamics_VehicleCouplingData) << 3U);
}

/* Model initialize function */
void TrainDynamics_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
  RT_MODEL_TrainDynamics_T *const TrainDynamics_M, B_TrainDynamics_c_T *localB,
  DW_TrainDynamics_f_T *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const
  char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  TrainDynamics_P.DiscreteTimeIntegrator_LowerSat = rtMinusInf;
  TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.Saturation1_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.Saturation_UpperSat_i = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation1_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.Saturation_LowerSat = rtMinusInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide2_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide1_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ixb.SafeDivide_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys_ix.SafeDivide_UpperSat = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys.Constant_Value_m = rtInf;
  TrainDynamics_P.CoreSubsys_p.CoreSubsys.Saturation_UpperSat = rtInf;

  /* setup the global timing engine */
  TrainDynamics_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
  TrainDynamics_M->Timing.mdlref_GlobalTID[1] = mdlref_TID1;
  TrainDynamics_M->timingBridge = (timingBridge);

  /* initialize error status */
  rtmSetErrorStatusPointer(TrainDynamics_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_TrainDynamics_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_TrainDynamics_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    TrainDynamics_InitializeDataMapInfo(TrainDynamics_M, localB, localDW);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(TrainDynamics_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(TrainDynamics_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(TrainDynamics_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
