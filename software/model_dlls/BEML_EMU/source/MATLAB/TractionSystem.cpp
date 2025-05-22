/*
 * Code generation for system model 'TractionSystem'
 *
 * Model                      : TractionSystem
 * Model version              : 1.676
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "TractionSystem_capi.h"
#include "TractionSystem.h"
#include "TractionSystem_private.h"
#include "LookUp_real_T_real_T.h"

P_TractionSystem_T TractionSystem_P = {
  /* Computed Parameter: CommonVehicleConfig_Y0
   * Referenced by: '<S3>/CommonVehicleConfig'
   */
  {
    false,                             /* Enabled */
    0U,                                /* VehicleID */
    VehicleType_NoVehicleType,         /* Type */
    0.0,                               /* Class */
    0.0,                               /* Orientation */
    0.0,                               /* Length */
    0.0,                               /* Height */
    0.0,                               /* Width */
    0.0,                               /* TareMass */
    0.0,                               /* GrossMass */
    0.0,                               /* LoadingMass */
    0.0,                               /* NumberOfAxles */
    0.0,                               /* NumberOfDrivenAxles */
    0.0,                               /* NumberOfBrakedAxles */
    0.0                                /* WheelDiameter */
  },

  /* Computed Parameter: TractionSystemVehicleConfig_Y0
   * Referenced by: '<S3>/TractionSystemVehicleConfig'
   */
  {
    false                              /* HasMotors */
  },

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Start of '<S2>/CoreSubsys' */
  {
    /* Mask Parameter: AKState1_initial_condition
     * Referenced by: '<S98>/Memory'
     */
    0,

    /* Mask Parameter: AKState_initial_condition
     * Referenced by: '<S97>/Memory'
     */
    0,

    /* Computed Parameter: TractionSystemOut_Y0
     * Referenced by: '<S25>/TractionSystemOut'
     */
    {
      {
        {
          0.0,                         /* TractionContactorStatus */

          {
            {
              false,                   /* Forward */
              false,                   /* Reverse */
              false                    /* BogieNotIsolated */
            }, {
              false,                   /* Forward */
              false,                   /* Reverse */
              false                    /* BogieNotIsolated */
            } }
          /* Bogie */
        },                             /* ElectricalSystem */

        {
          {
            {
              false,                   /* TCUStatus */
              false,                   /* BogieFaulty */
              false,                   /* TractionNotIsolated */
              false,                   /* EDBrakeNotIsolated */
              false,                   /* TCUSlideDetected */
              false,                   /* TCUSlipDetected */
              0.0,                     /* TractiveEffortAchieved */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0,                     /* TractiveEffortPossible */
              0.0,                     /* EDBrakingEffortPossible */
              0.0,                     /* TractionPower */
              0.0,                     /* EDBrakingPower */
              0.0,                     /* TractivePowerPossible */
              0.0,                     /* EDBrakingPowerPossible */

              {
                0.0, 0.0 }
              ,                        /* MotorSpeeds */
              false,                   /* WSPTractionCutout */
              0.0                      /* SpeedSensorFault */
            }, {
              false,                   /* TCUStatus */
              false,                   /* BogieFaulty */
              false,                   /* TractionNotIsolated */
              false,                   /* EDBrakeNotIsolated */
              false,                   /* TCUSlideDetected */
              false,                   /* TCUSlipDetected */
              0.0,                     /* TractiveEffortAchieved */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0,                     /* TractiveEffortPossible */
              0.0,                     /* EDBrakingEffortPossible */
              0.0,                     /* TractionPower */
              0.0,                     /* EDBrakingPower */
              0.0,                     /* TractivePowerPossible */
              0.0,                     /* EDBrakingPowerPossible */

              {
                0.0, 0.0 }
              ,                        /* MotorSpeeds */
              false,                   /* WSPTractionCutout */
              0.0                      /* SpeedSensorFault */
            } }
          ,                            /* Bogie */

          {
            0.0,                       /* TCU_KStatus */
            0.0,                       /* TCU_AKStatus */
            0.0                        /* FilterVoltage */
          },                           /* Trafo_TCU */
          0.0,                         /* VehicleDerailed */
          0.0                          /* VehicleBogieDerailed */
        },                             /* TCMS */

        {
          {
            {
              false,                   /* TCUWheelSlideControlActive */
              false,                   /* EDBrakeStatus */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0                      /* EDBrakingEffortPossible */
            }, {
              false,                   /* TCUWheelSlideControlActive */
              false,                   /* EDBrakeStatus */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0                      /* EDBrakingEffortPossible */
            } }
          /* Bogie */
        }                              /* BCU */
      },                               /* TractionControl */

      {
        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        ,                              /* TractionBrakingForce */

        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        ,                              /* TractionForce */

        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        /* BrakingForce */
      },                               /* Dynamics */

      {
        0.0,                           /* TractionEDPower */
        0.0                            /* WheelAngularVelocity */
      }                                /* Audio */
    },

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S26>/Constant1'
     */
    {
      {
        {
          0.0,                         /* TractionContactorStatus */

          {
            {
              false,                   /* Forward */
              false,                   /* Reverse */
              false                    /* BogieNotIsolated */
            }, {
              false,                   /* Forward */
              false,                   /* Reverse */
              false                    /* BogieNotIsolated */
            } }
          /* Bogie */
        },                             /* ElectricalSystem */

        {
          {
            {
              false,                   /* TCUStatus */
              false,                   /* BogieFaulty */
              false,                   /* TractionNotIsolated */
              false,                   /* EDBrakeNotIsolated */
              false,                   /* TCUSlideDetected */
              false,                   /* TCUSlipDetected */
              0.0,                     /* TractiveEffortAchieved */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0,                     /* TractiveEffortPossible */
              0.0,                     /* EDBrakingEffortPossible */
              0.0,                     /* TractionPower */
              0.0,                     /* EDBrakingPower */
              0.0,                     /* TractivePowerPossible */
              0.0,                     /* EDBrakingPowerPossible */

              {
                0.0, 0.0 }
              ,                        /* MotorSpeeds */
              false,                   /* WSPTractionCutout */
              0.0                      /* SpeedSensorFault */
            }, {
              false,                   /* TCUStatus */
              false,                   /* BogieFaulty */
              false,                   /* TractionNotIsolated */
              false,                   /* EDBrakeNotIsolated */
              false,                   /* TCUSlideDetected */
              false,                   /* TCUSlipDetected */
              0.0,                     /* TractiveEffortAchieved */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0,                     /* TractiveEffortPossible */
              0.0,                     /* EDBrakingEffortPossible */
              0.0,                     /* TractionPower */
              0.0,                     /* EDBrakingPower */
              0.0,                     /* TractivePowerPossible */
              0.0,                     /* EDBrakingPowerPossible */

              {
                0.0, 0.0 }
              ,                        /* MotorSpeeds */
              false,                   /* WSPTractionCutout */
              0.0                      /* SpeedSensorFault */
            } }
          ,                            /* Bogie */

          {
            0.0,                       /* TCU_KStatus */
            0.0,                       /* TCU_AKStatus */
            0.0                        /* FilterVoltage */
          },                           /* Trafo_TCU */
          0.0,                         /* VehicleDerailed */
          0.0                          /* VehicleBogieDerailed */
        },                             /* TCMS */

        {
          {
            {
              false,                   /* TCUWheelSlideControlActive */
              false,                   /* EDBrakeStatus */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0                      /* EDBrakingEffortPossible */
            }, {
              false,                   /* TCUWheelSlideControlActive */
              false,                   /* EDBrakeStatus */
              0.0,                     /* EDBrakingEffortAchieved */
              0.0                      /* EDBrakingEffortPossible */
            } }
          /* Bogie */
        }                              /* BCU */
      },                               /* TractionControl */

      {
        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        ,                              /* TractionBrakingForce */

        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        ,                              /* TractionForce */

        {
          0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
        /* BrakingForce */
      },                               /* Dynamics */

      {
        0.0,                           /* TractionEDPower */
        0.0                            /* WheelAngularVelocity */
      }                                /* Audio */
    },

    /* Computed Parameter: Constant1_Value_i
     * Referenced by: '<S33>/Constant1'
     */
    {
      {
        0.0,                           /* TractionContactorStatus */

        {
          {
            false,                     /* Forward */
            false,                     /* Reverse */
            false                      /* BogieNotIsolated */
          }, {
            false,                     /* Forward */
            false,                     /* Reverse */
            false                      /* BogieNotIsolated */
          } }
        /* Bogie */
      },                               /* ElectricalSystem */

      {
        {
          {
            false,                     /* TCUStatus */
            false,                     /* BogieFaulty */
            false,                     /* TractionNotIsolated */
            false,                     /* EDBrakeNotIsolated */
            false,                     /* TCUSlideDetected */
            false,                     /* TCUSlipDetected */
            0.0,                       /* TractiveEffortAchieved */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0,                       /* TractiveEffortPossible */
            0.0,                       /* EDBrakingEffortPossible */
            0.0,                       /* TractionPower */
            0.0,                       /* EDBrakingPower */
            0.0,                       /* TractivePowerPossible */
            0.0,                       /* EDBrakingPowerPossible */

            {
              0.0, 0.0 }
            ,                          /* MotorSpeeds */
            false,                     /* WSPTractionCutout */
            0.0                        /* SpeedSensorFault */
          }, {
            false,                     /* TCUStatus */
            false,                     /* BogieFaulty */
            false,                     /* TractionNotIsolated */
            false,                     /* EDBrakeNotIsolated */
            false,                     /* TCUSlideDetected */
            false,                     /* TCUSlipDetected */
            0.0,                       /* TractiveEffortAchieved */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0,                       /* TractiveEffortPossible */
            0.0,                       /* EDBrakingEffortPossible */
            0.0,                       /* TractionPower */
            0.0,                       /* EDBrakingPower */
            0.0,                       /* TractivePowerPossible */
            0.0,                       /* EDBrakingPowerPossible */

            {
              0.0, 0.0 }
            ,                          /* MotorSpeeds */
            false,                     /* WSPTractionCutout */
            0.0                        /* SpeedSensorFault */
          } }
        ,                              /* Bogie */

        {
          0.0,                         /* TCU_KStatus */
          0.0,                         /* TCU_AKStatus */
          0.0                          /* FilterVoltage */
        },                             /* Trafo_TCU */
        0.0,                           /* VehicleDerailed */
        0.0                            /* VehicleBogieDerailed */
      },                               /* TCMS */

      {
        {
          {
            false,                     /* TCUWheelSlideControlActive */
            false,                     /* EDBrakeStatus */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0                        /* EDBrakingEffortPossible */
          }, {
            false,                     /* TCUWheelSlideControlActive */
            false,                     /* EDBrakeStatus */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0                        /* EDBrakingEffortPossible */
          } }
        /* Bogie */
      }                                /* BCU */
    },

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S39>/Constant4'
     */
    {
      {
        {
          false,                       /* TCUStatus */
          false,                       /* BogieFaulty */
          false,                       /* TractionNotIsolated */
          false,                       /* EDBrakeNotIsolated */
          false,                       /* TCUSlideDetected */
          false,                       /* TCUSlipDetected */
          0.0,                         /* TractiveEffortAchieved */
          0.0,                         /* EDBrakingEffortAchieved */
          0.0,                         /* TractiveEffortPossible */
          0.0,                         /* EDBrakingEffortPossible */
          0.0,                         /* TractionPower */
          0.0,                         /* EDBrakingPower */
          0.0,                         /* TractivePowerPossible */
          0.0,                         /* EDBrakingPowerPossible */

          {
            0.0, 0.0 }
          ,                            /* MotorSpeeds */
          false,                       /* WSPTractionCutout */
          0.0                          /* SpeedSensorFault */
        }, {
          false,                       /* TCUStatus */
          false,                       /* BogieFaulty */
          false,                       /* TractionNotIsolated */
          false,                       /* EDBrakeNotIsolated */
          false,                       /* TCUSlideDetected */
          false,                       /* TCUSlipDetected */
          0.0,                         /* TractiveEffortAchieved */
          0.0,                         /* EDBrakingEffortAchieved */
          0.0,                         /* TractiveEffortPossible */
          0.0,                         /* EDBrakingEffortPossible */
          0.0,                         /* TractionPower */
          0.0,                         /* EDBrakingPower */
          0.0,                         /* TractivePowerPossible */
          0.0,                         /* EDBrakingPowerPossible */

          {
            0.0, 0.0 }
          ,                            /* MotorSpeeds */
          false,                       /* WSPTractionCutout */
          0.0                          /* SpeedSensorFault */
        } }
      ,                                /* Bogie */

      {
        0.0,                           /* TCU_KStatus */
        0.0,                           /* TCU_AKStatus */
        0.0                            /* FilterVoltage */
      },                               /* Trafo_TCU */
      0.0,                             /* VehicleDerailed */
      0.0                              /* VehicleBogieDerailed */
    },

    /* Computed Parameter: UnitDelay_InitialCondition
     * Referenced by: '<S25>/Unit Delay'
     */
    {
      0.0,                             /* BogieTractiveEffort */
      0.0,                             /* BogieDynamicBrakingEffort */
      0.0,                             /* BogieMaxTractionEffortPossible */
      0.0,                             /* BogieMaxBrakingEffortPossible */
      0.0,                             /* BogieTractivePower */
      0.0,                             /* BogieDynamicBrakingPower */
      0.0,                             /* BogieMaxTractionPowerPossible */
      0.0,                             /* BogieMaxBrakingPowerPossible */

      {
        0.0, 0.0 }
      /* BogieMotorSpeeds */
    },

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S37>/Constant2'
     */
    {
      {
        {
          false,                       /* TCUWheelSlideControlActive */
          false,                       /* EDBrakeStatus */
          0.0,                         /* EDBrakingEffortAchieved */
          0.0                          /* EDBrakingEffortPossible */
        }, {
          false,                       /* TCUWheelSlideControlActive */
          false,                       /* EDBrakeStatus */
          0.0,                         /* EDBrakingEffortAchieved */
          0.0                          /* EDBrakingEffortPossible */
        } }
      /* Bogie */
    },

    /* Computed Parameter: Constant2_Value_m
     * Referenced by: '<S38>/Constant2'
     */
    {
      0.0,                             /* TractionContactorStatus */

      {
        {
          false,                       /* Forward */
          false,                       /* Reverse */
          false                        /* BogieNotIsolated */
        }, {
          false,                       /* Forward */
          false,                       /* Reverse */
          false                        /* BogieNotIsolated */
        } }
      /* Bogie */
    },

    /* Computed Parameter: Constant2_Value_i
     * Referenced by: '<S29>/Constant2'
     */
    {
      0.0,                             /* TractionEDPower */
      0.0                              /* WheelAngularVelocity */
    },

    /* Expression: 9*0.0242
     * Referenced by: '<S36>/RC_AK'
     */
    0.2178,

    /* Expression: eps
     * Referenced by: '<S36>/RC_K'
     */
    2.2204460492503131E-16,

    /* Expression: 1800
     * Referenced by: '<S36>/Link_NominalVoltage'
     */
    1800.0,

    /* Expression: 1500
     * Referenced by: '<S36>/Link_UnderVoltage'
     */
    1500.0,

    /* Expression: 0
     * Referenced by: '<S36>/Switch1'
     */
    0.0,

    /* Expression: 2200
     * Referenced by: '<S36>/Link_OverVoltage'
     */
    2200.0,

    /* Expression: 1
     * Referenced by: '<S36>/Constant1'
     */
    1.0,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S36>/Discrete-Time Integrator'
     */
    0.01,

    /* Expression: 0
     * Referenced by: '<S36>/Discrete-Time Integrator'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S36>/Multiply1'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S36>/Switch'
     */
    0.0,

    /* Expression: 0.638
     * Referenced by: '<S36>/Multiply'
     */
    0.638,

    /* Expression: 0.5
     * Referenced by: '<S29>/Gain'
     */
    0.5,

    /* Expression: zeros(1,MaxAxles)
     * Referenced by: '<S30>/Constant'
     */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    /* Computed Parameter: UnitDelay_InitialCondition_e
     * Referenced by: '<S36>/Unit Delay'
     */
    0,

    /* Computed Parameter: Logic_table
     * Referenced by: '<S98>/Logic'
     */
    { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

    /* Computed Parameter: Logic_table_f
     * Referenced by: '<S97>/Logic'
     */
    { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

    /* Start of '<S99>/CoreSubsys' */
    {
      /* Expression: 1
       * Referenced by: '<S100>/Constant3'
       */
      1.0,

      /* Expression: 0.5
       * Referenced by: '<S100>/Gain'
       */
      0.5,

      /* Expression: 0.25
       * Referenced by: '<S100>/Gain1'
       */
      0.25,

      /* Start of '<S103>/CoreSubsys' */
      {
        /* Mask Parameter: CompareToConstant_const
         * Referenced by: '<S125>/Constant'
         */
        1.5,

        /* Mask Parameter: ContourInterpolation2Dy_contour_size
         * Referenced by: '<S114>/Contour Interpolation 2D y'
         */
        { 4.0, 4.0, 3.0, 5.0, 0.0 },

        /* Mask Parameter: ContourInterpolation2Dy_contour_size_a
         * Referenced by: '<S126>/Contour Interpolation 2D y'
         */
        { 4.0, 4.0, 3.0, 5.0, 0.0 },

        /* Mask Parameter: ContourInterpolation2Dy_contour_xy_data
         * Referenced by: '<S114>/Contour Interpolation 2D y'
         */
        { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.5, 0.0, 1.0, 1.0, 2.0, 1.0,
          0.0, 1.0, 2.0, 4.0, 4.0, 0.0, 2.0, 2.5, 4.0, 2.0, 0.0, 2.0, 3.0, 8.0,
          5.0, 0.0, 3.0, 5.0, 0.0, 3.0, 0.0, 3.0, 4.5, 0.0, 9.0, 0.0, 0.0, 0.0,
          0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 15.0, 0.0 },

        /* Mask Parameter: ContourInterpolation2Dy_contour_xy_data_d
         * Referenced by: '<S126>/Contour Interpolation 2D y'
         */
        { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.5, 0.0, 1.0, 1.0, 2.0, 1.0,
          0.0, 1.0, 2.0, 4.0, 4.0, 0.0, 2.0, 2.5, 4.0, 2.0, 0.0, 2.0, 3.0, 8.0,
          5.0, 0.0, 3.0, 5.0, 0.0, 3.0, 0.0, 3.0, 4.5, 0.0, 9.0, 0.0, 0.0, 0.0,
          0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 15.0, 0.0 },

        /* Mask Parameter: ContourInterpolation2Dy_contour_z_data
         * Referenced by: '<S114>/Contour Interpolation 2D y'
         */
        { 1.0, 2.0, 3.0, 4.0, 0.0 },

        /* Mask Parameter: ContourInterpolation2Dy_contour_z_data_i
         * Referenced by: '<S126>/Contour Interpolation 2D y'
         */
        { 1.0, 2.0, 3.0, 4.0, 0.0 },

        /* Mask Parameter: SubsetInterpolation1D_subset_size
         * Referenced by: '<S115>/Subset Interpolation 1D'
         */
        2.0,

        /* Mask Parameter: SubsetInterpolation1D_subset_size_b
         * Referenced by: '<S127>/Subset Interpolation 1D'
         */
        2.0,

        /* Mask Parameter: MaxPowerLookup_subset_size
         * Referenced by: '<S133>/MaxPowerLookup'
         */
        4.0,

        /* Mask Parameter: MaxTorqueLookup_subset_size
         * Referenced by: '<S133>/MaxTorqueLookup'
         */
        4.0,

        /* Mask Parameter: SubsetInterpolation1D_x_data
         * Referenced by: '<S115>/Subset Interpolation 1D'
         */
        { 0.0, 1.0 },

        /* Mask Parameter: SubsetInterpolation1D_x_data_j
         * Referenced by: '<S127>/Subset Interpolation 1D'
         */
        { 0.0, 1.0 },

        /* Mask Parameter: MaxPowerLookup_x_data
         * Referenced by: '<S133>/MaxPowerLookup'
         */
        { 1.0, 2.0, 3.0, 4.0, 0.0 },

        /* Mask Parameter: MaxTorqueLookup_x_data
         * Referenced by: '<S133>/MaxTorqueLookup'
         */
        { 1.0, 2.0, 3.0, 4.0, 0.0 },

        /* Mask Parameter: SubsetInterpolation1D_y_data
         * Referenced by: '<S115>/Subset Interpolation 1D'
         */
        { 20500.0, 20500.0 },

        /* Mask Parameter: SubsetInterpolation1D_y_data_o
         * Referenced by: '<S127>/Subset Interpolation 1D'
         */
        { 13940.0, 13940.0 },

        /* Mask Parameter: MaxPowerLookup_y_data
         * Referenced by: '<S133>/MaxPowerLookup'
         */
        { 9.0, 22.5, 32.0, 75.0, 0.0 },

        /* Mask Parameter: MaxTorqueLookup_y_data
         * Referenced by: '<S133>/MaxTorqueLookup'
         */
        { 3.0, 4.5, 8.0, 15.0, 0.0 },

        /* Mask Parameter: CurveInputType_Value
         * Referenced by: '<S129>/Constant'
         */
        TractionCurveSpecificationType_CurveEquationStatic,

        /* Mask Parameter: CurveInputType_Value_f
         * Referenced by: '<S117>/Constant'
         */
        TractionCurveSpecificationType_CurveEquationStatic,

        /* Expression: -1
         * Referenced by: '<S105>/apply opposite to direction of movement'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S106>/No Braking'
         */
        0.0,

        /* Expression: inf
         * Referenced by: '<S122>/NoLimit'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S122>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S122>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S122>/Constant3'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S122>/Switch1'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S122>/Constant2'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S116>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S116>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S122>/Switch'
         */
        0.0,

        /* Expression: [0,1]
         * Referenced by: '<S123>/Constant'
         */
        { 0.0, 1.0 },

        /* Expression: 0
         * Referenced by: '<S114>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S114>/Switch'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S118>/Constant'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S124>/Constant1'
         */
        1.0,

        /* Expression: -1
         * Referenced by: '<S124>/Constant'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S110>/No Power'
         */
        0.0,

        /* Expression: inf
         * Referenced by: '<S142>/NoLimit'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S142>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S142>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S142>/Constant3'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S142>/Switch1'
         */
        0.0,

        /* Expression: 0.01
         * Referenced by: '<S128>/Percentage to fraction'
         */
        0.01,

        /* Expression: 1
         * Referenced by: '<S128>/Saturation'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S128>/Saturation'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S128>/Saturation1'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S128>/Saturation1'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S128>/Saturation3'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S128>/Saturation3'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S128>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S128>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S142>/Constant2'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S142>/Switch'
         */
        0.0,

        /* Expression: 0.01
         * Referenced by: '<S127>/Percentage to fraction'
         */
        0.01,

        /* Expression: 1
         * Referenced by: '<S127>/Saturation'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S127>/Saturation'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S138>/Saturation1'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S138>/Saturation1'
         */
        0.0,

        /* Expression: CDMaxMotorPower
         * Referenced by: '<S138>/Constant'
         */
        210120.0,

        /* Expression: CDMaxMotorTorque
         * Referenced by: '<S138>/Constant1'
         */
        1091.0,

        /* Expression: 1
         * Referenced by: '<S138>/Saturation3'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S138>/Saturation3'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S126>/Constant'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S133>/Saturation1'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S133>/Saturation1'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S133>/Saturation3'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S133>/Saturation3'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S126>/Switch'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S130>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S112>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S113>/Constant'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S109>/safedivide1'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S109>/safedivide1'
         */
        2.2204460492503131E-16,

        /* Expression: 1
         * Referenced by: '<S111>/PerformanceFactor'
         */
        1.0,

        /* Computed Parameter: RateLimiter_RisingLim
         * Referenced by: '<S111>/Rate Limiter'
         */
        20.0,

        /* Computed Parameter: RateLimiter_FallingLim
         * Referenced by: '<S111>/Rate Limiter'
         */
        -50.0,

        /* Expression: 0
         * Referenced by: '<S111>/Rate Limiter'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S110>/Switch2'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S107>/PerformanceFactor'
         */
        1.0,

        /* Computed Parameter: RateLimiter_RisingLim_g
         * Referenced by: '<S107>/Rate Limiter'
         */
        50.0,

        /* Computed Parameter: RateLimiter_FallingLim_h
         * Referenced by: '<S107>/Rate Limiter'
         */
        -50.0,

        /* Expression: 0
         * Referenced by: '<S107>/Rate Limiter'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant1'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant2'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant4'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant3'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S104>/Constant5'
         */
        0.0
      }
      ,

      /* End of '<S103>/CoreSubsys' */

      /* Start of '<S143>/CoreSubsys' */
      {
        /* Expression: 1
         * Referenced by: '<S147>/Saturation1'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S147>/Saturation1'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S147>/Saturation3'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S147>/Saturation3'
         */
        0.0,

        /* Expression: 1e6
         * Referenced by: '<S148>/safedivide1'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S148>/safedivide1'
         */
        2.2204460492503131E-16,

        /* Expression: 1e6
         * Referenced by: '<S147>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S147>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: [0,1]
         * Referenced by: '<S149>/Constant'
         */
        { 0.0, 1.0 },

        /* Expression: 1e6
         * Referenced by: '<S146>/safedivide'
         */
        1.0E+6,

        /* Expression: eps
         * Referenced by: '<S146>/safedivide'
         */
        2.2204460492503131E-16,

        /* Expression: 0
         * Referenced by: '<S145>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S145>/Constant1'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S145>/Constant2'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S145>/Constant3'
         */
        0.0
      }
      /* End of '<S143>/CoreSubsys' */
    }
    ,

    /* End of '<S99>/CoreSubsys' */

    /* Start of '<S35>/CoreSubsys' */
    {
      /* Mask Parameter: SampleandHold_InitialCondition
       * Referenced by: '<S77>/Unit Delay'
       */
      0.0,

      /* Mask Parameter: SampleandHold_InitialCondition_m
       * Referenced by: '<S94>/Unit Delay'
       */
      0.0,

      /* Mask Parameter: CompareToConstant1_const
       * Referenced by: '<S80>/Constant'
       */
      1.0,

      /* Mask Parameter: CompareToConstant2_const
       * Referenced by: '<S81>/Constant'
       */
      1.0,

      /* Mask Parameter: Stop_const
       * Referenced by: '<S83>/Constant'
       */
      0.05,

      /* Mask Parameter: CompareToConstant1_const_j
       * Referenced by: '<S64>/Constant'
       */
      1.0,

      /* Mask Parameter: CompareToConstant_const
       * Referenced by: '<S63>/Constant'
       */
      1.4,

      /* Mask Parameter: Stop_const_o
       * Referenced by: '<S66>/Constant'
       */
      0.05,

      /* Mask Parameter: CompareToConstant_const_c
       * Referenced by: '<S43>/Constant'
       */
      0.1,

      /* Mask Parameter: DetectDecrease_vinit
       * Referenced by: '<S74>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectIncrease_vinit
       * Referenced by: '<S75>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease_vinit_i
       * Referenced by: '<S91>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectIncrease_vinit_d
       * Referenced by: '<S92>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: DetectDecrease_vinit_j
       * Referenced by: '<S44>/Delay Input1'
       */
      0.0,

      /* Mask Parameter: SRLatchResetPriority_initial_condition
       * Referenced by: '<S82>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority_initial_condition_e
       * Referenced by: '<S65>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority1_initial_condition
       * Referenced by: '<S76>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority1_initial_condition_f
       * Referenced by: '<S93>/Memory'
       */
      0,

      /* Mask Parameter: SRLatchResetPriority_initial_condition_m
       * Referenced by: '<S45>/Memory'
       */
      0,

      /* Computed Parameter: Constant4_Value
       * Referenced by: '<S54>/Constant4'
       */
      {
        false,                         /* TCUStatus */
        false,                         /* BogieFaulty */
        false,                         /* TractionNotIsolated */
        false,                         /* EDBrakeNotIsolated */
        false,                         /* TCUSlideDetected */
        false,                         /* TCUSlipDetected */
        0.0,                           /* TractiveEffortAchieved */
        0.0,                           /* EDBrakingEffortAchieved */
        0.0,                           /* TractiveEffortPossible */
        0.0,                           /* EDBrakingEffortPossible */
        0.0,                           /* TractionPower */
        0.0,                           /* EDBrakingPower */
        0.0,                           /* TractivePowerPossible */
        0.0,                           /* EDBrakingPowerPossible */

        {
          0.0, 0.0 }
        ,                              /* MotorSpeeds */
        false,                         /* WSPTractionCutout */
        0.0                            /* SpeedSensorFault */
      },

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S41>/Constant1'
       */
      {
        false,                         /* TCUStatus */
        false,                         /* BogieFaulty */
        false,                         /* TractionNotIsolated */
        false,                         /* EDBrakeNotIsolated */
        false,                         /* TCUSlideDetected */
        false,                         /* TCUSlipDetected */
        0.0,                           /* TractiveEffortAchieved */
        0.0,                           /* EDBrakingEffortAchieved */
        0.0,                           /* TractiveEffortPossible */
        0.0,                           /* EDBrakingEffortPossible */
        0.0,                           /* TractionPower */
        0.0,                           /* EDBrakingPower */
        0.0,                           /* TractivePowerPossible */
        0.0,                           /* EDBrakingPowerPossible */

        {
          0.0, 0.0 }
        ,                              /* MotorSpeeds */
        false,                         /* WSPTractionCutout */
        0.0                            /* SpeedSensorFault */
      },

      /* Computed Parameter: Constant3_Value
       * Referenced by: '<S41>/Constant3'
       */
      {
        0.0,                           /* TractionDemandPct */
        0.0,                           /* DynamicBrakeTorqueDemand */
        0.0,                           /* Powering */
        0.0,                           /* Braking */
        0.0,                           /* Forward */
        0.0,                           /* Reverse */

        {
          0.0, 0.0 }
        ,                              /* MotorNotAvailable */
        0.0,                           /* TractionTorqueAvailable */
        0.0                            /* DynamicBrakeAvailable */
      },

      /* Computed Parameter: Constant1_Value_d
       * Referenced by: '<S52>/Constant1'
       */
      {
        false,                         /* TCUWheelSlideControlActive */
        false,                         /* EDBrakeStatus */
        0.0,                           /* EDBrakingEffortAchieved */
        0.0                            /* EDBrakingEffortPossible */
      },

      /* Computed Parameter: Constant2_Value
       * Referenced by: '<S41>/Constant2'
       */
      {
        false,                         /* TCUWheelSlideControlActive */
        false,                         /* EDBrakeStatus */
        0.0,                           /* EDBrakingEffortAchieved */
        0.0                            /* EDBrakingEffortPossible */
      },

      /* Computed Parameter: Constant4_Value_k
       * Referenced by: '<S53>/Constant4'
       */
      {
        false,                         /* Forward */
        false,                         /* Reverse */
        false                          /* BogieNotIsolated */
      },

      /* Computed Parameter: Constant4_Value_ko
       * Referenced by: '<S41>/Constant4'
       */
      {
        false,                         /* Forward */
        false,                         /* Reverse */
        false                          /* BogieNotIsolated */
      },

      /* Expression: 0
       * Referenced by: '<S40>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S58>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S59>/Constant'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S68>/min0'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S68>/min0'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S60>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S68>/Constant2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S68>/Constant1'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S85>/min0'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S85>/min0'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S61>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S85>/Constant2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S85>/Constant1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S62>/Constant'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S51>/Switch'
       */
      0.0,

      /* Expression: 0.01
       * Referenced by: '<S56>/Multiply'
       */
      0.01,

      /* Expression: 0.0
       * Referenced by: '<S85>/Delay'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S61>/Switch1'
       */
      0.0,

      /* Expression: 1e8
       * Referenced by: '<S50>/safedivide2'
       */
      1.0E+8,

      /* Expression: eps
       * Referenced by: '<S50>/safedivide2'
       */
      2.2204460492503131E-16,

      /* Expression: 100
       * Referenced by: '<S50>/Multiply1'
       */
      100.0,

      /* Expression: 100
       * Referenced by: '<S50>/Saturation1'
       */
      100.0,

      /* Expression: 0
       * Referenced by: '<S50>/Saturation1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S58>/Switch'
       */
      0.0,

      /* Expression: 0.01
       * Referenced by: '<S55>/Multiply'
       */
      0.01,

      /* Expression: 0.0
       * Referenced by: '<S68>/Delay'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S60>/Switch1'
       */
      0.0,

      /* Expression: inf
       * Referenced by: '<S50>/Saturation'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S50>/Saturation'
       */
      0.0,

      /* Expression: 0.5
       * Referenced by: '<S57>/Multiply1'
       */
      0.5,

      /* Expression: 1e6
       * Referenced by: '<S57>/safedivide1'
       */
      1.0E+6,

      /* Expression: eps
       * Referenced by: '<S57>/safedivide1'
       */
      2.2204460492503131E-16,

      /* Expression: 1e6
       * Referenced by: '<S57>/safedivide2'
       */
      1.0E+6,

      /* Expression: eps
       * Referenced by: '<S57>/safedivide2'
       */
      2.2204460492503131E-16,

      /* Expression: 0
       * Referenced by: '<S70>/Delay Input2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S68>/Unit Delay1'
       */
      0.0,

      /* Computed Parameter: sampletime_WtEt
       * Referenced by: '<S70>/sample time'
       */
      0.01,

      /* Expression: 0.5
       * Referenced by: '<S71>/Gain'
       */
      0.5,

      /* Expression: 0
       * Referenced by: '<S87>/Delay Input2'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S85>/Unit Delay1'
       */
      0.0,

      /* Computed Parameter: sampletime_WtEt_h
       * Referenced by: '<S87>/sample time'
       */
      0.01,

      /* Expression: 0.5
       * Referenced by: '<S88>/Gain'
       */
      0.5,

      /* Expression: 0
       * Referenced by: '<S40>/Switch'
       */
      0.0,

      /* Expression: true
       * Referenced by: '<S51>/Constant'
       */
      1,

      /* Computed Parameter: Constant_Value_e
       * Referenced by: '<S73>/Constant'
       */
      0,

      /* Computed Parameter: Constant_Value_cd
       * Referenced by: '<S90>/Constant'
       */
      0,

      /* Computed Parameter: UnitDelay_InitialCondition
       * Referenced by: '<S61>/Unit Delay'
       */
      0,

      /* Computed Parameter: UnitDelay_InitialCondition_a
       * Referenced by: '<S60>/Unit Delay'
       */
      0,

      /* Computed Parameter: UnitDelay_InitialCondition_h
       * Referenced by: '<S68>/Unit Delay'
       */
      0,

      /* Computed Parameter: UnitDelay_InitialCondition_i
       * Referenced by: '<S85>/Unit Delay'
       */
      0,

      /* Start of '<S88>/TimerOffDelay NoInit' */
      {
        /* Expression: UpperSaturationLimit
         * Referenced by: '<S95>/OffTime'
         */
        0.1,

        /* Expression: 0
         * Referenced by: '<S96>/Constant'
         */
        0.0,

        /* Expression: -1
         * Referenced by: '<S95>/Gain'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S95>/Initialise'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S95>/IC'
         */
        1.0,

        /* Computed Parameter: DiscreteTimeIntegrator_gainval
         * Referenced by: '<S95>/Discrete-Time Integrator'
         */
        0.01,

        /* Expression: UpperSaturationLimit
         * Referenced by: '<S95>/Discrete-Time Integrator'
         */
        0.1,

        /* Expression: 0
         * Referenced by: '<S95>/Discrete-Time Integrator'
         */
        0.0
      }
      ,

      /* End of '<S88>/TimerOffDelay NoInit' */

      /* Start of '<S61>/TimerOnDelay NoInit' */
      {
        /* Expression: 0
         * Referenced by: '<S86>/Constant'
         */
        0.0,

        /* Computed Parameter: Timer_gainval
         * Referenced by: '<S84>/Timer'
         */
        0.01,

        /* Expression: 0
         * Referenced by: '<S84>/Timer'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S84>/Timer'
         */
        0.0
      }
      ,

      /* End of '<S61>/TimerOnDelay NoInit' */

      /* Start of '<S71>/TimerOffDelay NoInit' */
      {
        /* Expression: UpperSaturationLimit
         * Referenced by: '<S78>/OffTime'
         */
        0.1,

        /* Expression: 0
         * Referenced by: '<S79>/Constant'
         */
        0.0,

        /* Expression: -1
         * Referenced by: '<S78>/Gain'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S78>/Initialise'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S78>/IC'
         */
        1.0,

        /* Computed Parameter: DiscreteTimeIntegrator_gainval
         * Referenced by: '<S78>/Discrete-Time Integrator'
         */
        0.01,

        /* Expression: UpperSaturationLimit
         * Referenced by: '<S78>/Discrete-Time Integrator'
         */
        0.1,

        /* Expression: 0
         * Referenced by: '<S78>/Discrete-Time Integrator'
         */
        0.0
      }
      ,

      /* End of '<S71>/TimerOffDelay NoInit' */

      /* Start of '<S60>/TimerOnDelay NoInit' */
      {
        /* Expression: 0
         * Referenced by: '<S69>/Constant'
         */
        0.0,

        /* Computed Parameter: Timer_gainval
         * Referenced by: '<S67>/Timer'
         */
        0.01,

        /* Expression: 0
         * Referenced by: '<S67>/Timer'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S67>/Timer'
         */
        0.0
      }
      /* End of '<S60>/TimerOnDelay NoInit' */
    }
    /* End of '<S35>/CoreSubsys' */
  }
  ,

  /* End of '<S2>/CoreSubsys' */

  /* Start of '<S4>/CoreSubsys' */
  {
    /* Mask Parameter: MinValue_const
     * Referenced by: '<S18>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_o
     * Referenced by: '<S17>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_b
     * Referenced by: '<S24>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_p
     * Referenced by: '<S22>/Constant'
     */
    16000.0,

    /* Mask Parameter: MinValue_const_h
     * Referenced by: '<S16>/Constant'
     */
    16000.0,

    /* Mask Parameter: MinValue_const_i
     * Referenced by: '<S19>/Constant'
     */
    1.0,

    /* Mask Parameter: MinValue_const_m
     * Referenced by: '<S20>/Constant'
     */
    1.0,

    /* Mask Parameter: MinValue_const_n
     * Referenced by: '<S21>/Constant'
     */
    1.0,

    /* Mask Parameter: MinValue_const_d
     * Referenced by: '<S23>/Constant'
     */
    0.0,

    /* Mask Parameter: MinValue_const_g
     * Referenced by: '<S15>/Constant'
     */
    0,

    /* Expression: 3
     * Referenced by: '<S14>/Default'
     */
    3.0,

    /* Expression: 0.580
     * Referenced by: '<S13>/Default'
     */
    0.58,

    /* Expression: 16000
     * Referenced by: '<S12>/Default'
     */
    16000.0,

    /* Expression: 2
     * Referenced by: '<S11>/Default'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S10>/Default'
     */
    2.0,

    /* Expression: 6
     * Referenced by: '<S9>/Default'
     */
    6.0,

    /* Expression: 20
     * Referenced by: '<S8>/Default'
     */
    20.0,

    /* Expression: 3
     * Referenced by: '<S7>/Default'
     */
    3.0,

    /* Expression: 16000
     * Referenced by: '<S6>/Default'
     */
    16000.0,

    /* Expression: 0
     * Referenced by: '<S5>/Default'
     */
    0.0
  }
  /* End of '<S4>/CoreSubsys' */
};

/*
 * System initialize for atomic system:
 *    '<S60>/TimerOnDelay NoInit'
 *    '<S61>/TimerOnDelay NoInit'
 */
void TractionSystem_TimerOnDelayNoInit_Init
  (DW_TimerOnDelayNoInit_TractionSystem_T *localDW,
   P_TimerOnDelayNoInit_TractionSystem_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S67>/Timer' */
  localDW->Timer_DSTATE = localP->Timer_IC;
  localDW->Timer_PrevResetState = 0;
}

/*
 * Start for atomic system:
 *    '<S60>/TimerOnDelay NoInit'
 *    '<S61>/TimerOnDelay NoInit'
 */
void TractionSystem_TimerOnDelayNoInit_Start
  (B_TimerOnDelayNoInit_TractionSystem_T *localB,
   DW_TimerOnDelayNoInit_TractionSystem_T *localDW)
{
  localDW->Timer_DSTATE = 0.0;
  localB->Compare = false;
}

/*
 * Output and update for atomic system:
 *    '<S60>/TimerOnDelay NoInit'
 *    '<S61>/TimerOnDelay NoInit'
 */
void TractionSystem_TimerOnDelayNoInit(boolean_T rtu_In,
  B_TimerOnDelayNoInit_TractionSystem_T *localB,
  DW_TimerOnDelayNoInit_TractionSystem_T *localDW,
  P_TimerOnDelayNoInit_TractionSystem_T *localP, real_T rtp_UpperSaturationLimit)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator_k;
  int32_T rtb_Timer_o2;
  real_T Timer_o1;

  /* Logic: '<S67>/Logical Operator' */
  rtb_LogicalOperator_k = !rtu_In;

  /* DiscreteIntegrator: '<S67>/Timer' incorporates:
   *  DataTypeConversion: '<S67>/Data Type Conversion'
   */
  if (rtb_LogicalOperator_k || (localDW->Timer_PrevResetState != 0)) {
    localDW->Timer_DSTATE = localP->Timer_IC;
  }

  Timer_o1 = localP->Timer_gainval * static_cast<real_T>(rtu_In) +
    localDW->Timer_DSTATE;
  if (Timer_o1 >= rtp_UpperSaturationLimit) {
    Timer_o1 = rtp_UpperSaturationLimit;
    rtb_Timer_o2 = 1;
  } else if (Timer_o1 <= localP->Timer_LowerSat) {
    Timer_o1 = localP->Timer_LowerSat;
    rtb_Timer_o2 = -1;
  } else {
    rtb_Timer_o2 = 0;
  }

  /* End of DiscreteIntegrator: '<S67>/Timer' */

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S69>/Constant'
   */
  localB->Compare = (rtb_Timer_o2 > localP->Constant_Value);

  /* Update for DiscreteIntegrator: '<S67>/Timer' */
  localDW->Timer_DSTATE = Timer_o1;
  localDW->Timer_PrevResetState = static_cast<int8_T>(rtb_LogicalOperator_k);
}

/*
 * System initialize for atomic system:
 *    '<S71>/TimerOffDelay NoInit'
 *    '<S88>/TimerOffDelay NoInit'
 */
void TractionSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_TractionSystem_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 1U;
  localDW->DiscreteTimeIntegrator_PrevResetState = 0;
}

/*
 * Start for atomic system:
 *    '<S71>/TimerOffDelay NoInit'
 *    '<S88>/TimerOffDelay NoInit'
 */
void TractionSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_TractionSystem_T *localB,
   DW_TimerOffDelayNoInit_TractionSystem_T *localDW)
{
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  localB->LogicalOperator1 = false;

  /* Start for InitialCondition: '<S78>/IC' */
  localDW->IC_FirstOutputTime = true;
}

/*
 * Output and update for atomic system:
 *    '<S71>/TimerOffDelay NoInit'
 *    '<S88>/TimerOffDelay NoInit'
 */
void TractionSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_TractionSystem_T *localB,
  DW_TimerOffDelayNoInit_TractionSystem_T *localDW,
  P_TimerOffDelayNoInit_TractionSystem_T *localP)
{
  real_T rtb_DiscreteTimeIntegrator_o2;
  real_T DiscreteTimeIntegrator_o1;

  /* InitialCondition: '<S78>/IC' incorporates:
   *  Constant: '<S78>/Initialise'
   */
  if (localDW->IC_FirstOutputTime) {
    localDW->IC_FirstOutputTime = false;
    rtb_DiscreteTimeIntegrator_o2 = localP->IC_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  }

  /* End of InitialCondition: '<S78>/IC' */

  /* Switch: '<S78>/Switch2' incorporates:
   *  Constant: '<S78>/Initialise'
   *  Constant: '<S78>/OffTime'
   */
  if (rtb_DiscreteTimeIntegrator_o2 != 0.0) {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->OffTime_Value;
  }

  /* End of Switch: '<S78>/Switch2' */

  /* DiscreteIntegrator: '<S78>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S78>/Data Type Conversion'
   *  Gain: '<S78>/Gain'
   *  Logic: '<S78>/Logical Operator'
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

  /* End of DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */

  /* Logic: '<S78>/Logical Operator1' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S79>/Compare'
   */
  localB->LogicalOperator1 = ((rtb_DiscreteTimeIntegrator_o2 >=
    localP->Constant_Value) || rtu_In);

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 0U;
  localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator_o1;
  localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>(rtu_In);
}

/*
 * Start for atomic system:
 *    '<S140>/Replace Zeros'
 *    '<S136>/Replace Zeros'
 */
void TractionSystem_ReplaceZeros_Start(B_ReplaceZeros_TractionSystem_T *localB)
{
  localB->y = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S140>/Replace Zeros'
 *    '<S136>/Replace Zeros'
 */
void TractionSystem_ReplaceZeros(real_T rtu_u, B_ReplaceZeros_TractionSystem_T
  *localB)
{
  localB->y = rtu_u;
  if (rtu_u == 0.0) {
    localB->y = 4.94065645841247E-324;
  }
}

/* System initialize for referenced model: 'TractionSystem' */
void TractionSystem_Init(B_TractionSystem_c_T *localB, DW_TractionSystem_f_T
  *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEachVehicle_itr;
  int32_T ForEachBogie_itr;
  int32_T ForEach_itr;
  int32_T ForEachBogie_itr_b;
  int32_T i;

  /* SystemInitialize for Enabled SubSystem: '<S1>/ConfigProcessing' */
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Outport: '<S3>/CommonVehicleConfig' */
    localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[i] =
      TractionSystem_P.CommonVehicleConfig_Y0;

    /* SystemInitialize for Outport: '<S3>/TractionSystemVehicleConfig' */
    localB->ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[i] =
      TractionSystem_P.TractionSystemVehicleConfig_Y0;
  }

  /* End of SystemInitialize for SubSystem: '<S1>/ConfigProcessing' */

  /* SystemInitialize for Iterator SubSystem: '<Root>/Traction (Per Vehicle)' */
  for (ForEachVehicle_itr = 0; ForEachVehicle_itr < 8; ForEachVehicle_itr++) {
    /* SystemInitialize for Enabled SubSystem: '<S2>/MotorVehicle' */
    /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].DiscreteTimeIntegrator_DSTATE =
      TractionSystem_P.CoreSubsys_p.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S36>/Unit Delay' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE_p =
      TractionSystem_P.CoreSubsys_p.UnitDelay_InitialCondition_e;

    /* InitializeConditions for Memory: '<S98>/Memory' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput =
      TractionSystem_P.CoreSubsys_p.AKState1_initial_condition;

    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE[0] =
      TractionSystem_P.CoreSubsys_p.UnitDelay_InitialCondition;
    localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE[1] =
      TractionSystem_P.CoreSubsys_p.UnitDelay_InitialCondition;

    /* InitializeConditions for Memory: '<S97>/Memory' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput_o =
      TractionSystem_P.CoreSubsys_p.AKState_initial_condition;

    /* SystemInitialize for Iterator SubSystem: '<S27>/TractionControl (Per Bogie)' */
    for (ForEachBogie_itr_b = 0; ForEachBogie_itr_b < 2; ForEachBogie_itr_b++) {
      /* InitializeConditions for Memory: '<S45>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition_m;

      /* InitializeConditions for UnitDelay: '<S44>/Delay Input1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit_j;

      /* SystemInitialize for IfAction SubSystem: '<S35>/TCUONLogic' */
      /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_d =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition;

      /* InitializeConditions for Memory: '<S82>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_o =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition;

      /* InitializeConditions for UnitDelay: '<S60>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_b =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_a;

      /* InitializeConditions for Memory: '<S65>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_h =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority_initial_condition_e;

      /* InitializeConditions for Delay: '<S85>/Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[0] =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition;

      /* InitializeConditions for Delay: '<S68>/Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[0] =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition_l;

      /* InitializeConditions for Delay: '<S85>/Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[1] =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition;

      /* InitializeConditions for Delay: '<S68>/Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[1] =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Delay_InitialCondition_l;

      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_k =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_h;

      /* InitializeConditions for UnitDelay: '<S70>/Delay Input2' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DelayInput2_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay1_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S74>/Delay Input1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_n =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit;

      /* InitializeConditions for UnitDelay: '<S75>/Delay Input1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_o =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectIncrease_vinit;

      /* InitializeConditions for Memory: '<S76>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_l =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority1_initial_condition;

      /* InitializeConditions for UnitDelay: '<S77>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SampleandHold_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S85>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_j =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay_InitialCondition_i;

      /* InitializeConditions for UnitDelay: '<S87>/Delay Input2' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE_e =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DelayInput2_InitialCondition_f;

      /* InitializeConditions for UnitDelay: '<S85>/Unit Delay1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE_p =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.UnitDelay1_InitialCondition_k;

      /* InitializeConditions for UnitDelay: '<S91>/Delay Input1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_c =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectDecrease_vinit_i;

      /* InitializeConditions for UnitDelay: '<S92>/Delay Input1' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_e =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.DetectIncrease_vinit_d;

      /* InitializeConditions for Memory: '<S93>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_g =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SRLatchResetPriority1_initial_condition_f;

      /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_p =
        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.SampleandHold_InitialCondition_m;

      /* SystemInitialize for Atomic SubSystem: '<S61>/TimerOnDelay NoInit' */
      TractionSystem_TimerOnDelayNoInit_Init(&localDW->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOnDelayNoInit_h,
        &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h);

      /* End of SystemInitialize for SubSystem: '<S61>/TimerOnDelay NoInit' */

      /* SystemInitialize for Atomic SubSystem: '<S60>/TimerOnDelay NoInit' */
      TractionSystem_TimerOnDelayNoInit_Init(&localDW->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOnDelayNoInit,
        &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit);

      /* End of SystemInitialize for SubSystem: '<S60>/TimerOnDelay NoInit' */

      /* SystemInitialize for Atomic SubSystem: '<S71>/TimerOffDelay NoInit' */
      TractionSystem_TimerOffDelayNoInit_Init(&localDW->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOffDelayNoInit);

      /* End of SystemInitialize for SubSystem: '<S71>/TimerOffDelay NoInit' */

      /* SystemInitialize for Atomic SubSystem: '<S88>/TimerOffDelay NoInit' */
      TractionSystem_TimerOffDelayNoInit_Init(&localDW->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOffDelayNoInit_h);

      /* End of SystemInitialize for SubSystem: '<S88>/TimerOffDelay NoInit' */
      /* End of SystemInitialize for SubSystem: '<S35>/TCUONLogic' */
    }

    /* End of SystemInitialize for SubSystem: '<S27>/TractionControl (Per Bogie)' */

    /* SystemInitialize for Iterator SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' */
    for (ForEachBogie_itr = 0; ForEachBogie_itr < 2; ForEachBogie_itr++) {
      /* SystemInitialize for Iterator SubSystem: '<S101>/TractionMotor' */
      for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
        /* SystemInitialize for IfAction SubSystem: '<S103>/TractionMotorEnabled' */
        /* InitializeConditions for RateLimiter: '<S111>/Rate Limiter' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].PrevY =
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_IC;

        /* InitializeConditions for RateLimiter: '<S107>/Rate Limiter' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].PrevY_j =
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_IC_p;

        /* SystemInitialize for IfAction SubSystem: '<S111>/ContourData' */
        /* SystemInitialize for MATLAB Function: '<S126>/Contour Interpolation 2D y' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          n_countours_not_empty = false;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_index = 1.0;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_x_index_c1 = 1.0;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_x_index_c2 = 1.0;

        /* End of SystemInitialize for SubSystem: '<S111>/ContourData' */

        /* SystemInitialize for IfAction SubSystem: '<S107>/ContourData' */
        /* SystemInitialize for MATLAB Function: '<S114>/Contour Interpolation 2D y' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          n_countours_not_empty_m = false;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_index_n = 1.0;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_x_index_c1_b = 1.0;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
          previous_contour_x_index_c2_i = 1.0;

        /* End of SystemInitialize for SubSystem: '<S107>/ContourData' */
        /* End of SystemInitialize for SubSystem: '<S103>/TractionMotorEnabled' */
      }

      /* End of SystemInitialize for SubSystem: '<S101>/TractionMotor' */
    }

    /* End of SystemInitialize for SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' */

    /* SystemInitialize for Outport: '<S25>/TractionSystemOut' */
    localB->CoreSubsys_p[ForEachVehicle_itr].BusAssignment =
      TractionSystem_P.CoreSubsys_p.TractionSystemOut_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/MotorVehicle' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/Traction (Per Vehicle)' */
}

/* Start for referenced model: 'TractionSystem' */
void TractionSystem_Start(B_TractionSystem_c_T *localB, DW_TractionSystem_f_T
  *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEachVehicle_itr;
  int32_T ForEachBogie_itr;
  int32_T ForEach_itr;
  int32_T ForEachBogie_itr_b;
  static const BD_TractionSystem_Int_BogieOutputs tmp = { 0.0,/* BogieTractiveEffort */
    0.0,                               /* BogieDynamicBrakingEffort */
    0.0,                               /* BogieMaxTractionEffortPossible */
    0.0,                               /* BogieMaxBrakingEffortPossible */
    0.0,                               /* BogieTractivePower */
    0.0,                               /* BogieDynamicBrakingPower */
    0.0,                               /* BogieMaxTractionPowerPossible */
    0.0,                               /* BogieMaxBrakingPowerPossible */
    { 0.0, 0.0 }                       /* BogieMotorSpeeds */
  };

  static const BD_TractionSystem_Out_Vehicle tmp_0 = { { { 0.0,/* TractionContactorStatus */
        { { false,                     /* Forward */
            false,                     /* Reverse */
            false                      /* BogieNotIsolated */
          }, { false,                  /* Forward */
            false,                     /* Reverse */
            false                      /* BogieNotIsolated */
          } }                          /* Bogie */
      },                               /* ElectricalSystem */
      { { { false,                     /* TCUStatus */
            false,                     /* BogieFaulty */
            false,                     /* TractionNotIsolated */
            false,                     /* EDBrakeNotIsolated */
            false,                     /* TCUSlideDetected */
            false,                     /* TCUSlipDetected */
            0.0,                       /* TractiveEffortAchieved */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0,                       /* TractiveEffortPossible */
            0.0,                       /* EDBrakingEffortPossible */
            0.0,                       /* TractionPower */
            0.0,                       /* EDBrakingPower */
            0.0,                       /* TractivePowerPossible */
            0.0,                       /* EDBrakingPowerPossible */
            { 0.0, 0.0 },              /* MotorSpeeds */
            false,                     /* WSPTractionCutout */
            0.0                        /* SpeedSensorFault */
          }, { false,                  /* TCUStatus */
            false,                     /* BogieFaulty */
            false,                     /* TractionNotIsolated */
            false,                     /* EDBrakeNotIsolated */
            false,                     /* TCUSlideDetected */
            false,                     /* TCUSlipDetected */
            0.0,                       /* TractiveEffortAchieved */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0,                       /* TractiveEffortPossible */
            0.0,                       /* EDBrakingEffortPossible */
            0.0,                       /* TractionPower */
            0.0,                       /* EDBrakingPower */
            0.0,                       /* TractivePowerPossible */
            0.0,                       /* EDBrakingPowerPossible */
            { 0.0, 0.0 },              /* MotorSpeeds */
            false,                     /* WSPTractionCutout */
            0.0                        /* SpeedSensorFault */
          } },                         /* Bogie */
        { 0.0,                         /* TCU_KStatus */
          0.0,                         /* TCU_AKStatus */
          0.0                          /* FilterVoltage */
        },                             /* Trafo_TCU */
        0.0,                           /* VehicleDerailed */
        0.0                            /* VehicleBogieDerailed */
      },                               /* TCMS */
      { { { false,                     /* TCUWheelSlideControlActive */
            false,                     /* EDBrakeStatus */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0                        /* EDBrakingEffortPossible */
          }, { false,                  /* TCUWheelSlideControlActive */
            false,                     /* EDBrakeStatus */
            0.0,                       /* EDBrakingEffortAchieved */
            0.0                        /* EDBrakingEffortPossible */
          } }                          /* Bogie */
      }                                /* BCU */
    },                                 /* TractionControl */
    { { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* TractionBrakingForce */
      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* TractionForce */
      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } /* BrakingForce */
    },                                 /* Dynamics */
    { 0.0,                             /* TractionEDPower */
      0.0                              /* WheelAngularVelocity */
    }                                  /* Audio */
  };

  /* Start for Iterator SubSystem: '<Root>/Traction (Per Vehicle)' */
  for (ForEachVehicle_itr = 0; ForEachVehicle_itr < 8; ForEachVehicle_itr++) {
    /* Start for Enabled SubSystem: '<S2>/MotorVehicle' */
    localDW->CoreSubsys_p[ForEachVehicle_itr].DiscreteTimeIntegrator_DSTATE =
      0.0;
    localB->CoreSubsys_p[ForEachVehicle_itr].UnitDelay[0] = tmp;
    localB->CoreSubsys_p[ForEachVehicle_itr].UnitDelay[1] = tmp;
    localB->CoreSubsys_p[ForEachVehicle_itr].BusAssignment = tmp_0;

    /* Start for Iterator SubSystem: '<S27>/TractionControl (Per Bogie)' */
    for (ForEachBogie_itr_b = 0; ForEachBogie_itr_b < 2; ForEachBogie_itr_b++) {
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE = 0.0;

      /* Start for IfAction SubSystem: '<S35>/TCUONLogic' */
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[0] = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[0] = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[1] = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[1] = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_n = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_o = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE_e = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE_p = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_c = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_e = 0.0;
      localDW->CoreSubsys_p[ForEachVehicle_itr]
        .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_p = 0.0;

      /* Start for Atomic SubSystem: '<S61>/TimerOnDelay NoInit' */
      TractionSystem_TimerOnDelayNoInit_Start(&localB->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOnDelayNoInit_h, &localDW->CoreSubsys_p[ForEachVehicle_itr].
        CoreSubsys_pna[ForEachBogie_itr_b].TimerOnDelayNoInit_h);

      /* End of Start for SubSystem: '<S61>/TimerOnDelay NoInit' */

      /* Start for Atomic SubSystem: '<S60>/TimerOnDelay NoInit' */
      TractionSystem_TimerOnDelayNoInit_Start(&localB->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOnDelayNoInit, &localDW->CoreSubsys_p[ForEachVehicle_itr].
        CoreSubsys_pna[ForEachBogie_itr_b].TimerOnDelayNoInit);

      /* End of Start for SubSystem: '<S60>/TimerOnDelay NoInit' */

      /* Start for Atomic SubSystem: '<S71>/TimerOffDelay NoInit' */
      TractionSystem_TimerOffDelayNoInit_Start(&localB->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOffDelayNoInit, &localDW->CoreSubsys_p[ForEachVehicle_itr].
        CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit);

      /* End of Start for SubSystem: '<S71>/TimerOffDelay NoInit' */

      /* Start for Atomic SubSystem: '<S88>/TimerOffDelay NoInit' */
      TractionSystem_TimerOffDelayNoInit_Start(&localB->
        CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
        TimerOffDelayNoInit_h, &localDW->CoreSubsys_p[ForEachVehicle_itr].
        CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit_h);

      /* End of Start for SubSystem: '<S88>/TimerOffDelay NoInit' */
      /* End of Start for SubSystem: '<S35>/TCUONLogic' */
    }

    /* End of Start for SubSystem: '<S27>/TractionControl (Per Bogie)' */

    /* Start for Iterator SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' */
    for (ForEachBogie_itr = 0; ForEachBogie_itr < 2; ForEachBogie_itr++) {
      /* Start for Iterator SubSystem: '<S101>/TractionMotor' */
      for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
        /* Start for IfAction SubSystem: '<S103>/TractionMotorEnabled' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].PrevY =
          0.0;
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].PrevY_j =
          0.0;

        /* Start for IfAction SubSystem: '<S111>/CurveData' */
        /* Start for MATLAB Function: '<S140>/Replace Zeros' */
        TractionSystem_ReplaceZeros_Start(&localB->
          CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pnae[ForEachBogie_itr].
          CoreSubsys_h[ForEach_itr].sf_ReplaceZeros);

        /* End of Start for SubSystem: '<S111>/CurveData' */

        /* Start for IfAction SubSystem: '<S111>/ContourData' */
        /* Start for MATLAB Function: '<S136>/Replace Zeros' */
        TractionSystem_ReplaceZeros_Start(&localB->
          CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pnae[ForEachBogie_itr].
          CoreSubsys_h[ForEach_itr].sf_ReplaceZeros_k);

        /* End of Start for SubSystem: '<S111>/ContourData' */
        /* End of Start for SubSystem: '<S103>/TractionMotorEnabled' */
      }

      /* End of Start for SubSystem: '<S101>/TractionMotor' */
    }

    /* End of Start for SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' */
    /* End of Start for SubSystem: '<S2>/MotorVehicle' */
  }

  /* End of Start for SubSystem: '<Root>/Traction (Per Vehicle)' */
}

/* Output and update for referenced model: 'TractionSystem' */
void TractionSystem(RT_MODEL_TractionSystem_T * const TractionSystem_M, const
                    BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8], const
                    BD_TractionSystem_Cfg_Vehicle
                    rtu_TractionSystemVehicleConfig[8], const
                    BD_TractionSystem_In_Vehicle
                    rtu_TractionSystemVehicleInputs[8], const
                    BD_TractionSystem_In_Overrides rtu_Overrides[8], const
                    BD_TractionSystem_In_Faults rtu_Faults[8],
                    BD_TractionSystem_Out_Vehicle rty_TractionSystemOut[8],
                    B_TractionSystem_c_T *localB, DW_TractionSystem_f_T *localDW,
                    const BD_TractionSystem_Prm *rtp_Prm_TractionSystem)
{
  /* local block i/o variables */
  real_T rtb_Abs;
  real_T rtb_Product_m;
  real_T rtb_Abs2;
  real_T rtb_MinMax_i;
  real_T rtb_ConstantPower_k;
  real_T rtb_TorqueScaling_o;
  boolean_T rtb_TCUSlip;
  boolean_T rtb_TCUSlide;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_FixPtRelationalOperator_f;

  /* local scratch DWork variables */
  int32_T ForEachVehicle_itr;
  int32_T ForEachBogie_itr;
  int32_T ForEach_itr;
  int32_T ForEach_itr_e;
  int32_T ForEachBogie_itr_b;
  int32_T ForEach_itr_f;
  int32_T ForEach_itr_b;
  int32_T ForEach_itr_f5;
  real_T contour_fraction;
  real_T contour_x_index_c1;
  real_T x_fraction_c1;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  boolean_T
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_ReverseTW;
  boolean_T
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_NoEmergencyBrakeActiveTW;
  real_T rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
  real_T
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd;
  boolean_T rtb_LogicalOperator3;
  real_T rtb_FilterVoltage;
  real_T rtb_DataTypeConversion5;
  boolean_T rtb_Memory;
  boolean_T rtb_AND_m;
  real_T rtb_ImpAsg_InsertedFor_BogieTractionBrakingPower_at_inport_0[2];
  BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie
    rtb_ImpAsg_InsertedFor_TCUtoElectricalOutputs_at_inport_0[2];
  BD_TractionSystem_Out_Vehicle_TCMS_Bogie
    rtb_ImpAsg_InsertedFor_TCUtoTCMSOutputs_at_inport_0[2];
  BD_TractionSystem_Out_Vehicle_BCU_Bogie
    rtb_ImpAsg_InsertedFor_TCUToBCUOutputs_at_inport_0[2];
  real_T rtb_TractionBrakingForce[6];
  real_T rtb_TractionForce[6];
  real_T rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[4];
  real_T rtb_BrakingForce[6];
  real_T rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[4];
  BD_TractionSystem_Int_BogieControl rtb_Merge4;
  BD_TractionSystem_Out_Vehicle_TCMS_Bogie rtb_Merge1;
  BD_TractionSystem_Out_Vehicle_ElectricalSystem_Bogie rtb_Merge3_h;
  BD_TractionSystem_Out_Vehicle_BCU_Bogie rtb_Merge2;
  BD_TractionSystem_Int_BogieOutputs
    rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[2];
  BD_TractionSystem_Int_Vehicle_Dynamics
    rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[2];
  real_T rtb_Gain_f;
  real_T rtb_ImpAsg_InsertedFor_MotorSpeed_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_TractivePower_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_TractiveEffort_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_TractiveBrakingEffort_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_DynamicBrakingPower_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_BrakingEffort_at_inport_0[2];
  boolean_T rtb_AND2;
  boolean_T rtb_AND_j;
  boolean_T rtb_and1;
  boolean_T rtb_AND1_i;
  boolean_T rtb_AND1;
  boolean_T rtb_AND_i;
  boolean_T rtb_LogicalOperator40_d;
  boolean_T rtb_and;
  real_T rtb_ImpAsg_InsertedFor_MaximumTractionEffortPossible_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_MaxTractionPowerPossible_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_MaxBrakingPowerPossible_at_inport_0[2];
  real_T rtb_ImpAsg_InsertedFor_MaxBrakingEffortPossible_at_inport_0[2];
  real_T rtb_MaximumBrakingEffortPossible_p;
  real_T rtb_MaximumTractionEffortPossible_k;
  int32_T i;
  boolean_T rtb_Logic_idx_0;
  real_T rtb_Product_c_idx_0;
  real_T rtb_Product_c_idx_1;
  real_T rtb_Product3_f_idx_2;
  real_T rtb_Product3_f_idx_6;
  real_T rtb_Product3_f_idx_7;
  int32_T exitg1;

  /* Step: '<S1>/Step' */
  if ((( rtmGetClockTick0(TractionSystem_M) + rtmGetClockTickH0(TractionSystem_M)*
        4294967296.0 ) * 0.01) < TractionSystem_P.Step_Time) {
    contour_fraction = TractionSystem_P.Step_Y0;
  } else {
    contour_fraction = TractionSystem_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Outputs for Enabled SubSystem: '<S1>/ConfigProcessing' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (contour_fraction > 0.0) {
    /* Outputs for Iterator SubSystem: '<S3>/ConfigCheck' incorporates:
     *  ForEach: '<S4>/For Each'
     */
    for (ForEach_itr_f5 = 0; ForEach_itr_f5 < 8; ForEach_itr_f5++) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S5>/Default'
       *  ForEachSliceSelector generated from: '<S4>/In2'
       *  RelationalOperator: '<S15>/Compare'
       */
      if (static_cast<int32_T>(rtu_TractionSystemVehicleConfig[ForEach_itr_f5].
           HasMotors) > static_cast<int32_T>
          (TractionSystem_P.CoreSubsys.MinValue_const_g)) {
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
          rtu_TractionSystemVehicleConfig[ForEach_itr_f5].HasMotors;
      } else {
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
          TractionSystem_P.CoreSubsys.Default_Value_mh;
      }

      /* End of Switch: '<S5>/Switch' */

      /* ForEachSliceAssignment generated from: '<S4>/TractionSystemVehicleConfig' incorporates:
       *  DataTypeConversion: '<S4>/Data Type Conversion'
       */
      localB->
        ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[ForEach_itr_f5]
        .HasMotors =
        (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity !=
         0.0);

      /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/In1'
       */
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .Enabled = rtu_CommonVehicleConfig[ForEach_itr_f5].Enabled;
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .VehicleID = rtu_CommonVehicleConfig[ForEach_itr_f5].VehicleID;
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .Type = rtu_CommonVehicleConfig[ForEach_itr_f5].Type;
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .Class = rtu_CommonVehicleConfig[ForEach_itr_f5].Class;
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .Orientation = rtu_CommonVehicleConfig[ForEach_itr_f5].Orientation;

      /* Switch: '<S8>/Switch' incorporates:
       *  Constant: '<S18>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S18>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].Length >
          TractionSystem_P.CoreSubsys.MinValue_const) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Length = rtu_CommonVehicleConfig[ForEach_itr_f5].Length;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S8>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Length = TractionSystem_P.CoreSubsys.Default_Value_h;
      }

      /* End of Switch: '<S8>/Switch' */

      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S17>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S17>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].Height >
          TractionSystem_P.CoreSubsys.MinValue_const_o) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Height = rtu_CommonVehicleConfig[ForEach_itr_f5].Height;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S7>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Height = TractionSystem_P.CoreSubsys.Default_Value_de;
      }

      /* End of Switch: '<S7>/Switch' */

      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S24>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S24>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].Width >
          TractionSystem_P.CoreSubsys.MinValue_const_b) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Width = rtu_CommonVehicleConfig[ForEach_itr_f5].Width;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S14>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          Width = TractionSystem_P.CoreSubsys.Default_Value;
      }

      /* End of Switch: '<S14>/Switch' */

      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S22>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S22>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].TareMass >
          TractionSystem_P.CoreSubsys.MinValue_const_p) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          TareMass = rtu_CommonVehicleConfig[ForEach_itr_f5].TareMass;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S12>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          TareMass = TractionSystem_P.CoreSubsys.Default_Value_a;
      }

      /* End of Switch: '<S12>/Switch' */

      /* Switch: '<S6>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S16>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].GrossMass >
          TractionSystem_P.CoreSubsys.MinValue_const_h) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          GrossMass = rtu_CommonVehicleConfig[ForEach_itr_f5].GrossMass;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S6>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          GrossMass = TractionSystem_P.CoreSubsys.Default_Value_m;
      }

      /* End of Switch: '<S6>/Switch' */

      /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
       *  ForEachSliceSelector generated from: '<S4>/In1'
       */
      localB->ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5]
        .LoadingMass = rtu_CommonVehicleConfig[ForEach_itr_f5].LoadingMass;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S19>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S19>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].NumberOfAxles >=
          TractionSystem_P.CoreSubsys.MinValue_const_i) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfAxles = rtu_CommonVehicleConfig[ForEach_itr_f5].NumberOfAxles;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S9>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfAxles = TractionSystem_P.CoreSubsys.Default_Value_e;
      }

      /* End of Switch: '<S9>/Switch' */

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S20>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].NumberOfDrivenAxles >=
          TractionSystem_P.CoreSubsys.MinValue_const_m) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfDrivenAxles = rtu_CommonVehicleConfig[ForEach_itr_f5].
          NumberOfDrivenAxles;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S10>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfDrivenAxles = TractionSystem_P.CoreSubsys.Default_Value_f;
      }

      /* End of Switch: '<S10>/Switch' */

      /* Switch: '<S11>/Switch' incorporates:
       *  Constant: '<S21>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S21>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].NumberOfBrakedAxles >=
          TractionSystem_P.CoreSubsys.MinValue_const_n) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfBrakedAxles = rtu_CommonVehicleConfig[ForEach_itr_f5].
          NumberOfBrakedAxles;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S11>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          NumberOfBrakedAxles = TractionSystem_P.CoreSubsys.Default_Value_n;
      }

      /* End of Switch: '<S11>/Switch' */

      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S23>/Constant'
       *  ForEachSliceSelector generated from: '<S4>/In1'
       *  RelationalOperator: '<S23>/Compare'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_f5].WheelDiameter >
          TractionSystem_P.CoreSubsys.MinValue_const_d) {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          WheelDiameter = rtu_CommonVehicleConfig[ForEach_itr_f5].WheelDiameter;
      } else {
        /* ForEachSliceAssignment generated from: '<S4>/CommonVehicleConfig' incorporates:
         *  Constant: '<S13>/Default'
         */
        localB->
          ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEach_itr_f5].
          WheelDiameter = TractionSystem_P.CoreSubsys.Default_Value_d;
      }

      /* End of Switch: '<S13>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S3>/ConfigCheck' */
  }

  /* End of Outputs for SubSystem: '<S1>/ConfigProcessing' */

  /* Outputs for Iterator SubSystem: '<Root>/Traction (Per Vehicle)' incorporates:
   *  ForEach: '<S2>/ForEachVehicle'
   */
  for (ForEachVehicle_itr = 0; ForEachVehicle_itr < 8; ForEachVehicle_itr++) {
    /* ForEachSliceSelector generated from: '<S2>/TractionInputs' */
    rtb_LogicalOperator3 = rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
      ElectricalSystem.ForwardTW;
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_ReverseTW
      = rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
      ElectricalSystem.ReverseTW;
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_NoEmergencyBrakeActiveTW
      = rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
      ElectricalSystem.NoEmergencyBrakeActiveTW;
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
      rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].Dynamics.Velocity;
    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd =
      rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].TCMS.TCMSEDBrakingCmd;

    /* ForEachSliceSelector generated from: '<S2>/Faults' */
    rtb_Gain_f = rtu_Faults[ForEachVehicle_itr].BECU1FailureAllSpeedSensors;

    /* Outputs for Enabled SubSystem: '<S2>/MotorVehicle' incorporates:
     *  EnablePort: '<S25>/MotorVehicleEnable'
     */
    /* Logic: '<S2>/AND' incorporates:
     *  ForEachSliceSelector generated from: '<S2>/CommonConfig'
     *  ForEachSliceSelector generated from: '<S2>/TractionSystemConfig'
     */
    if (localB->
        ImpAsg_InsertedFor_TractionSystemVehicleConfig_at_inport_0[ForEachVehicle_itr]
        .HasMotors && localB->
        ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEachVehicle_itr].
        Enabled) {
      /* Switch: '<S36>/Switch' incorporates:
       *  Constant: '<S36>/Link_NominalVoltage'
       *  Constant: '<S36>/Link_OverVoltage'
       *  ForEachSliceSelector generated from: '<S2>/Faults'
       *  Switch: '<S36>/Switch1'
       */
      if (rtu_Faults[ForEachVehicle_itr].DCLinkOverVoltageLevel1 >
          TractionSystem_P.CoreSubsys_p.Switch_Threshold) {
        rtb_DataTypeConversion5 =
          TractionSystem_P.CoreSubsys_p.Link_OverVoltage_Value;
      } else if (rtu_Faults[ForEachVehicle_itr].DCLinkLowVoltageLevel1 >
                 TractionSystem_P.CoreSubsys_p.Switch1_Threshold) {
        /* Switch: '<S36>/Switch1' incorporates:
         *  Constant: '<S36>/Link_UnderVoltage'
         */
        rtb_DataTypeConversion5 =
          TractionSystem_P.CoreSubsys_p.Link_UnderVoltage_Value;
      } else {
        rtb_DataTypeConversion5 =
          TractionSystem_P.CoreSubsys_p.Link_NominalVoltage_Value;
      }

      /* End of Switch: '<S36>/Switch' */

      /* Switch: '<S36>/Switch2' incorporates:
       *  Constant: '<S36>/RC_AK'
       *  Constant: '<S36>/RC_K'
       *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
       *  Logic: '<S36>/Logical Operator7'
       *  UnitDelay: '<S36>/Unit Delay'
       */
      if (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          ElectricalSystem.VCBState && localDW->CoreSubsys_p[ForEachVehicle_itr]
          .UnitDelay_DSTATE_p) {
        rtb_FilterVoltage = TractionSystem_P.CoreSubsys_p.RC_K_Value;
      } else {
        rtb_FilterVoltage = TractionSystem_P.CoreSubsys_p.RC_AK_Value;
      }

      /* End of Switch: '<S36>/Switch2' */

      /* Product: '<S36>/Product1' incorporates:
       *  Constant: '<S36>/Constant1'
       *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
       *  Gain: '<S36>/Multiply1'
       *  Math: '<S36>/Exp'
       *  Product: '<S36>/Product'
       *  Sum: '<S36>/Add'
       *
       * About '<S36>/Exp':
       *  Operator: exp
       */
      rtb_FilterVoltage = (TractionSystem_P.CoreSubsys_p.Constant1_Value_f - exp
                           (localDW->CoreSubsys_p[ForEachVehicle_itr].
                            DiscreteTimeIntegrator_DSTATE / rtb_FilterVoltage *
                            TractionSystem_P.CoreSubsys_p.Multiply1_Gain)) *
        rtb_DataTypeConversion5;

      /* CombinatorialLogic: '<S98>/Logic' incorporates:
       *  ForEachSliceSelector generated from: '<S2>/Faults'
       *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
       *  Gain: '<S36>/Multiply'
       *  Logic: '<S36>/AND1'
       *  Logic: '<S36>/Logical Operator'
       *  Logic: '<S36>/Logical Operator2'
       *  Logic: '<S36>/Logical Operator5'
       *  Memory: '<S98>/Memory'
       *  RelationalOperator: '<S36>/Relational Operator'
       */
      rtb_Logic_idx_0 = TractionSystem_P.CoreSubsys_p.Logic_table[(((
        static_cast<uint32_T>((rtb_FilterVoltage >=
        TractionSystem_P.CoreSubsys_p.Multiply_Gain * rtb_DataTypeConversion5)) <<
        1) + (((!rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                ElectricalSystem.VCBState) ||
               rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
               ElectricalSystem.ContactorsFailure) &&
              (!(rtu_Faults[ForEachVehicle_itr].CIKOpenFailure != 0.0)))) << 1)
        + localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput];

      /* UnitDelay: '<S25>/Unit Delay' */
      memcpy(&localB->CoreSubsys_p[ForEachVehicle_itr].UnitDelay[0],
             &localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE[0],
             sizeof(BD_TractionSystem_Int_BogieOutputs) << 1U);

      /* Outputs for Iterator SubSystem: '<S27>/TractionControl (Per Bogie)' incorporates:
       *  ForEach: '<S35>/ForEachBogie'
       */
      for (ForEachBogie_itr_b = 0; ForEachBogie_itr_b < 2; ForEachBogie_itr_b++)
      {
        /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/Faults'
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S35>/BogieDynamics'
         *  Logic: '<S35>/OR'
         */
        rtb_Product_c_idx_0 =
          ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
            .Dynamics.Bogie[ForEachBogie_itr_b].WheelSlip[0] != 0.0) ||
           (rtu_Faults[ForEachVehicle_itr].HeavyWheelSlip != 0.0));

        /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/Faults'
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S35>/BogieDynamics'
         *  Logic: '<S35>/OR1'
         */
        high_i = ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                   Dynamics.Bogie[ForEachBogie_itr_b].WheelSlide[0] != 0.0) ||
                  (rtu_Faults[ForEachVehicle_itr].HeavyWheelSlide != 0.0));

        /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/Faults'
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S35>/BogieDynamics'
         *  Logic: '<S35>/OR'
         */
        rtb_Product_c_idx_1 =
          ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
            .Dynamics.Bogie[ForEachBogie_itr_b].WheelSlip[1] != 0.0) ||
           (rtu_Faults[ForEachVehicle_itr].HeavyWheelSlip != 0.0));

        /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/Faults'
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S35>/BogieDynamics'
         *  Logic: '<S35>/OR1'
         */
        i = ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
              .Dynamics.Bogie[ForEachBogie_itr_b].WheelSlide[1] != 0.0) ||
             (rtu_Faults[ForEachVehicle_itr].HeavyWheelSlide != 0.0));

        /* Logic: '<S45>/Logical Operator40' incorporates:
         *  Abs: '<S40>/Abs'
         *  Constant: '<S43>/Constant'
         *  Logic: '<S40>/AND'
         *  Logic: '<S45>/Logical Operator39'
         *  Logic: '<S45>/Logical Operator41'
         *  Memory: '<S45>/Memory'
         *  RelationalOperator: '<S43>/Compare'
         *  RelationalOperator: '<S44>/FixPt Relational Operator'
         *  UnitDelay: '<S44>/Delay Input1'
         */
        rtb_AND_m = ((((fabs
                        (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity)
                        >
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant_const_c)
                       && (rtb_Gain_f != 0.0)) || localDW->
                      CoreSubsys_p[ForEachVehicle_itr]
                      .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput) &&
                     (!(rtb_Gain_f < localDW->CoreSubsys_p[ForEachVehicle_itr].
                        CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE)));

        /* If: '<S35>/If' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S35>/BogieElectrical'
         */
        if (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
            ElectricalSystem.Bogie[ForEachBogie_itr_b].TCUPower) {
          /* Outputs for IfAction SubSystem: '<S35>/TCUONLogic' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* Logic: '<S46>/AND2' incorporates:
           *  DataTypeConversion: '<S36>/Data Type Conversion3'
           */
          rtb_AND2 = (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                      ElectricalSystem.Bogie[ForEachBogie_itr_b].TCUPower &&
                      rtb_Logic_idx_0);

          /* End of Outputs for SubSystem: '<S35>/TCUONLogic' */

          /* Switch: '<S40>/Switch' incorporates:
           *  Constant: '<S40>/Constant'
           */
          if (rtb_Gain_f >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold_f) {
            rtb_MaximumTractionEffortPossible_k =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value;
          } else {
            rtb_MaximumTractionEffortPossible_k =
              rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
          }

          /* End of Switch: '<S40>/Switch' */

          /* Outputs for IfAction SubSystem: '<S35>/TCUONLogic' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* Abs: '<S61>/Abs' incorporates:
           *  Abs: '<S60>/Abs'
           */
          rtb_Product3_f_idx_2 = fabs(rtb_MaximumTractionEffortPossible_k);

          /* MinMax: '<S61>/Max' */
          if (rtb_Product_c_idx_0 > rtb_Product_c_idx_1) {
            rtb_Product_c_idx_1 = rtb_Product_c_idx_0;
          }

          /* End of MinMax: '<S61>/Max' */

          /* Logic: '<S61>/AND' incorporates:
           *  Abs: '<S61>/Abs'
           *  Constant: '<S80>/Constant'
           *  Constant: '<S81>/Constant'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S61>/NOT'
           *  Logic: '<S61>/NOT1'
           *  RelationalOperator: '<S80>/Compare'
           *  RelationalOperator: '<S81>/Compare'
           *  UnitDelay: '<S61>/Unit Delay'
           */
          rtb_TCUSlip = ((rtb_Product_c_idx_1 >=
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant1_const)
                         && (!localDW->CoreSubsys_p[ForEachVehicle_itr].
                             CoreSubsys_pna[ForEachBogie_itr_b].
                             UnitDelay_DSTATE_d) && (rtb_Product3_f_idx_2 >=
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant2_const)
                         &&
                         (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                            TCMS.Bogie[ForEachBogie_itr_b].BogieIsolationStatus
                            != 0.0)));

          /* Outputs for Atomic SubSystem: '<S61>/TimerOnDelay NoInit' */
          TractionSystem_TimerOnDelayNoInit(rtb_TCUSlip, &localB->
            CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
            TimerOnDelayNoInit_h, &localDW->CoreSubsys_p[ForEachVehicle_itr].
            CoreSubsys_pna[ForEachBogie_itr_b].TimerOnDelayNoInit_h,
            &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit_h,
            rtp_Prm_TractionSystem->MaxContinuousSlipBeforeTractionCutout);

          /* End of Outputs for SubSystem: '<S61>/TimerOnDelay NoInit' */

          /* Logic: '<S82>/Logical Operator40' incorporates:
           *  Abs: '<S61>/Abs'
           *  Constant: '<S83>/Constant'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S61>/AND1'
           *  Logic: '<S82>/Logical Operator39'
           *  Logic: '<S82>/Logical Operator41'
           *  Memory: '<S82>/Memory'
           *  RelationalOperator: '<S83>/Compare'
           */
          rtb_Memory = ((localB->CoreSubsys_p[ForEachVehicle_itr]
                         .CoreSubsys_pna[ForEachBogie_itr_b].
                         TimerOnDelayNoInit_h.Compare || localDW->
                         CoreSubsys_p[ForEachVehicle_itr]
                         .CoreSubsys_pna[ForEachBogie_itr_b].
                         Memory_PreviousInput_o) && ((!(rtb_Product3_f_idx_2 <
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Stop_const)) &&
            (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
               .TCMS.Bogie[ForEachBogie_itr_b].BogieIsolationStatus != 0.0))));

          /* Logic: '<S46>/NOT6' incorporates:
           *  ForEachSliceSelector generated from: '<S2>/Faults'
           *  ForEachSliceSelector generated from: '<S35>/BogieFaults'
           */
          rtb_AND1 = !(rtu_Faults[ForEachVehicle_itr].Bogie[ForEachBogie_itr_b].
                       TractionBogieFaulty != 0.0);

          /* Logic: '<S46>/AND' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S46>/NOT'
           *  Logic: '<S46>/NOT1'
           *  Logic: '<S46>/NOT4'
           */
          rtb_AND_j = (rtb_AND2 &&
                       (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                          ElectricalSystem.Bogie[ForEachBogie_itr_b].
                          TractionCutoff != 0.0)) &&
                       (!rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                        TCMS.Bogie[ForEachBogie_itr_b].TCMSTractionInhibit) && (
            !rtb_Memory) && rtb_AND1);

          /* MinMax: '<S60>/Max' */
          if (static_cast<real_T>(high_i) > i) {
            rtb_DataTypeConversion5 = high_i;
          } else {
            rtb_DataTypeConversion5 = i;
          }

          /* End of MinMax: '<S60>/Max' */

          /* Logic: '<S60>/AND' incorporates:
           *  Constant: '<S63>/Constant'
           *  Constant: '<S64>/Constant'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S60>/NOT'
           *  Logic: '<S60>/NOT1'
           *  RelationalOperator: '<S63>/Compare'
           *  RelationalOperator: '<S64>/Compare'
           *  UnitDelay: '<S60>/Unit Delay'
           */
          rtb_TCUSlide = ((rtb_DataTypeConversion5 >=
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant1_const_j)
                          && (rtb_Product3_f_idx_2 >=
                              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.CompareToConstant_const)
                          && (!localDW->CoreSubsys_p[ForEachVehicle_itr].
                              CoreSubsys_pna[ForEachBogie_itr_b].
                              UnitDelay_DSTATE_b) &&
                          (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
                             .TCMS.Bogie[ForEachBogie_itr_b].
                             BogieIsolationStatus != 0.0)));

          /* Outputs for Atomic SubSystem: '<S60>/TimerOnDelay NoInit' */
          TractionSystem_TimerOnDelayNoInit(rtb_TCUSlide, &localB->
            CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
            TimerOnDelayNoInit, &localDW->CoreSubsys_p[ForEachVehicle_itr].
            CoreSubsys_pna[ForEachBogie_itr_b].TimerOnDelayNoInit,
            &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOnDelayNoInit,
            rtp_Prm_TractionSystem->MaxContinuousSlideBeforeBrakeCutout);

          /* End of Outputs for SubSystem: '<S60>/TimerOnDelay NoInit' */

          /* Logic: '<S65>/Logical Operator40' incorporates:
           *  Constant: '<S66>/Constant'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S60>/AND1'
           *  Logic: '<S65>/Logical Operator39'
           *  Logic: '<S65>/Logical Operator41'
           *  Memory: '<S65>/Memory'
           *  RelationalOperator: '<S66>/Compare'
           */
          rtb_LogicalOperator40_d = ((localB->CoreSubsys_p[ForEachVehicle_itr].
            CoreSubsys_pna[ForEachBogie_itr_b].TimerOnDelayNoInit.Compare ||
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_h) &&
            ((!(rtb_Product3_f_idx_2 <
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Stop_const_o)) && (
            !(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
              .TCMS.Bogie[ForEachBogie_itr_b].BogieIsolationStatus != 0.0))));

          /* Logic: '<S46>/AND1' incorporates:
           *  ForEachSliceSelector generated from: '<S2>/Faults'
           *  ForEachSliceSelector generated from: '<S35>/BogieFaults'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Logic: '<S46>/NOT2'
           *  Logic: '<S46>/NOT3'
           *  Logic: '<S46>/NOT5'
           *  Logic: '<S46>/NOT7'
           */
          rtb_AND1 = (rtb_AND2 && rtb_AND1 &&
                      (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                         ElectricalSystem.Bogie[ForEachBogie_itr_b].
                         DynamicBrakingCutoff != 0.0)) &&
                      (!(rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                         TCMS.Bogie[ForEachBogie_itr_b].
                         TCMSDynamicBrakingInhibit != 0.0)) &&
                      (!rtb_LogicalOperator40_d) &&
                      (!(rtu_Faults[ForEachVehicle_itr].Bogie[ForEachBogie_itr_b]
                         .DynamicBrakeNotAvailable != 0.0)));

          /* Logic: '<S47>/AND' incorporates:
           *  Logic: '<S47>/NOT'
           */
          rtb_AND_i = ((!rtb_LogicalOperator3) &&
                       rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_ReverseTW);

          /* Logic: '<S47>/AND1' incorporates:
           *  Logic: '<S47>/NOT1'
           */
          rtb_AND1_i = (rtb_LogicalOperator3 &&
                        (!rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_ReverseTW));

          /* Switch: '<S51>/Switch' incorporates:
           *  Constant: '<S51>/Constant'
           *  Constant: '<S51>/Constant1'
           */
          if (rtp_Prm_TractionSystem->EmergencyBrakeDeactivatesDynamicBrake >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold) {
            rtb_and1 =
              rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_NoEmergencyBrakeActiveTW;
          } else {
            rtb_and1 =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_i4;
          }

          /* End of Switch: '<S51>/Switch' */

          /* Logic: '<S51>/and1' incorporates:
           *  Logic: '<S51>/OR1'
           */
          rtb_and1 = ((rtb_AND1_i || rtb_AND_i) && rtb_and1);

          /* Logic: '<S51>/and' incorporates:
           *  Logic: '<S51>/and5'
           *  SignalConversion generated from: '<S51>/Vector Concatenate'
           */
          rtb_and = (rtb_and1 &&
                     (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_ElectricalSystem_NoEmergencyBrakeActiveTW
                      && rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                      ElectricalSystem.TractionActiveTW &&
                      rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
                      ElectricalSystem.Bogie[ForEachBogie_itr_b].
                      TractionAuthorisation));

          /* Switch: '<S59>/Switch' incorporates:
           *  Constant: '<S59>/Constant'
           *  Constant: '<S62>/Constant'
           *  Logic: '<S59>/NOT'
           *  Logic: '<S59>/OR'
           *  RelationalOperator: '<S62>/Compare'
           */
          if ((!(rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd
                 > TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_a))
              || rtb_and) {
            x_fraction_c1 = rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
              TCMS.TCMSTractionCmd;
          } else {
            x_fraction_c1 =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_c;
          }

          /* End of Switch: '<S59>/Switch' */

          /* Product: '<S56>/Product4' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           *  Gain: '<S56>/Multiply'
           */
          rtb_DataTypeConversion5 =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply_Gain *
            x_fraction_c1 * localB->CoreSubsys_p[ForEachVehicle_itr]
            .UnitDelay[ForEachBogie_itr_b].BogieMaxTractionEffortPossible;

          /* Switch: '<S61>/Switch1' incorporates:
           *  Constant: '<S61>/Constant1'
           */
          if (rtp_Prm_TractionSystem->WheelSlipProtectionEnable >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch1_Threshold) {
            /* Switch: '<S61>/Switch' incorporates:
             *  Constant: '<S61>/Constant'
             */
            if (rtb_Memory) {
              rtb_Product3_f_idx_2 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_m;
            } else {
              /* Sum: '<S85>/Sum' incorporates:
               *  Delay: '<S85>/Delay'
               */
              rtb_Product3_f_idx_2 = rtb_DataTypeConversion5 -
                localDW->CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[0];

              /* Saturate: '<S85>/min0' */
              if (rtb_Product3_f_idx_2 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat_f)
              {
                rtb_Product3_f_idx_2 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat_f;
              } else {
                if (rtb_Product3_f_idx_2 <
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat_j)
                {
                  rtb_Product3_f_idx_2 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat_j;
                }
              }

              /* End of Saturate: '<S85>/min0' */

              /* MinMax: '<S85>/Min' */
              if ((rtb_DataTypeConversion5 < rtb_Product3_f_idx_2) || rtIsNaN
                  (rtb_Product3_f_idx_2)) {
                rtb_Product3_f_idx_2 = rtb_DataTypeConversion5;
              }

              /* End of MinMax: '<S85>/Min' */
            }

            /* End of Switch: '<S61>/Switch' */
          } else {
            rtb_Product3_f_idx_2 = rtb_DataTypeConversion5;
          }

          /* End of Switch: '<S61>/Switch1' */

          /* Switch: '<S58>/Switch' incorporates:
           *  Constant: '<S58>/Constant'
           *  DataTypeConversion: '<S51>/Data Type Conversion4'
           */
          if (static_cast<real_T>(rtb_and1) >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch_Threshold_a) {
            rtb_MaximumTractionEffortPossible_k =
              rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd;
          } else {
            rtb_MaximumTractionEffortPossible_k =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_d;
          }

          /* End of Switch: '<S58>/Switch' */

          /* Product: '<S55>/Product' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           *  Gain: '<S55>/Multiply'
           */
          rtb_MaximumTractionEffortPossible_k =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply_Gain_b *
            rtb_MaximumTractionEffortPossible_k * localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieMaxBrakingEffortPossible;

          /* Switch: '<S60>/Switch1' incorporates:
           *  Constant: '<S60>/Constant1'
           */
          if (rtp_Prm_TractionSystem->WheelSlideProtectionEnable >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Switch1_Threshold_k)
          {
            /* Switch: '<S60>/Switch' incorporates:
             *  Constant: '<S60>/Constant'
             */
            if (rtb_LogicalOperator40_d) {
              rtb_MaximumBrakingEffortPossible_p =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_i;
            } else {
              /* Sum: '<S68>/Sum' incorporates:
               *  Delay: '<S68>/Delay'
               */
              rtb_MaximumBrakingEffortPossible_p =
                rtb_MaximumTractionEffortPossible_k - localDW->
                CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[0];

              /* Saturate: '<S68>/min0' */
              if (rtb_MaximumBrakingEffortPossible_p >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat) {
                rtb_MaximumBrakingEffortPossible_p =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat;
              } else {
                if (rtb_MaximumBrakingEffortPossible_p <
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat)
                {
                  rtb_MaximumBrakingEffortPossible_p =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_LowerSat;
                }
              }

              /* End of Saturate: '<S68>/min0' */

              /* MinMax: '<S68>/Min' */
              if ((rtb_MaximumTractionEffortPossible_k <
                   rtb_MaximumBrakingEffortPossible_p) || rtIsNaN
                  (rtb_MaximumBrakingEffortPossible_p)) {
                rtb_MaximumBrakingEffortPossible_p =
                  rtb_MaximumTractionEffortPossible_k;
              }

              /* End of MinMax: '<S68>/Min' */
            }

            /* End of Switch: '<S60>/Switch' */
          } else {
            rtb_MaximumBrakingEffortPossible_p =
              rtb_MaximumTractionEffortPossible_k;
          }

          /* End of Switch: '<S60>/Switch1' */

          /* Saturate: '<S50>/Saturation' */
          if (rtb_MaximumBrakingEffortPossible_p >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_UpperSat)
          {
            rtb_MaximumBrakingEffortPossible_p =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_UpperSat;
          } else {
            if (rtb_MaximumBrakingEffortPossible_p <
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_LowerSat)
            {
              rtb_MaximumBrakingEffortPossible_p =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_LowerSat;
            }
          }

          /* End of Saturate: '<S50>/Saturation' */

          /* Saturate: '<S50>/safedivide2' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           */
          if (localB->CoreSubsys_p[ForEachVehicle_itr]
              .UnitDelay[ForEachBogie_itr_b].BogieMaxTractionEffortPossible >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat)
          {
            contour_fraction =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat;
          } else if (localB->CoreSubsys_p[ForEachVehicle_itr]
                     .UnitDelay[ForEachBogie_itr_b].
                     BogieMaxTractionEffortPossible <
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat)
          {
            contour_fraction =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat;
          } else {
            contour_fraction = localB->CoreSubsys_p[ForEachVehicle_itr].
              UnitDelay[ForEachBogie_itr_b].BogieMaxTractionEffortPossible;
          }

          /* End of Saturate: '<S50>/safedivide2' */

          /* Gain: '<S50>/Multiply1' incorporates:
           *  Product: '<S50>/Product8'
           */
          contour_fraction = rtb_Product3_f_idx_2 / contour_fraction *
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply1_Gain;

          /* Saturate: '<S50>/Saturation1' */
          if (contour_fraction >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_UpperSat)
          {
            /* BusCreator: '<S48>/Bus Creator' */
            rtb_Merge4.TractionDemandPct =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_UpperSat;
          } else if (contour_fraction <
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_LowerSat)
          {
            /* BusCreator: '<S48>/Bus Creator' */
            rtb_Merge4.TractionDemandPct =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation1_LowerSat;
          } else {
            /* BusCreator: '<S48>/Bus Creator' */
            rtb_Merge4.TractionDemandPct = contour_fraction;
          }

          /* End of Saturate: '<S50>/Saturation1' */

          /* Gain: '<S57>/Multiply1' incorporates:
           *  Constant: '<S57>/Constant2'
           */
          contour_fraction =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Multiply1_Gain_k *
            rtp_Prm_TractionSystem->DesignWheelDiameter;

          /* Saturate: '<S57>/safedivide1' */
          if (contour_fraction >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_UpperSat)
          {
            contour_fraction =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_UpperSat;
          } else {
            if (contour_fraction <
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_LowerSat)
            {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide1_LowerSat;
            }
          }

          /* End of Saturate: '<S57>/safedivide1' */

          /* Product: '<S57>/Pmax//v1' incorporates:
           *  Constant: '<S57>/Constant1'
           */
          contour_fraction = rtp_Prm_TractionSystem->DesignGearingRatio /
            contour_fraction;

          /* Saturate: '<S57>/safedivide2' */
          if (contour_fraction >
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat_a)
          {
            contour_fraction =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_UpperSat_a;
          } else {
            if (contour_fraction <
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat_e)
            {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.safedivide2_LowerSat_e;
            }
          }

          /* End of Saturate: '<S57>/safedivide2' */

          /* BusCreator: '<S48>/Bus Creator' incorporates:
           *  DataTypeConversion: '<S48>/Data Type Conversion2'
           *  DataTypeConversion: '<S48>/Data Type Conversion3'
           *  DataTypeConversion: '<S48>/Data Type Conversion4'
           *  DataTypeConversion: '<S48>/Data Type Conversion6'
           *  DataTypeConversion: '<S48>/Data Type Conversion8'
           *  DataTypeConversion: '<S51>/Data Type Conversion4'
           *  Gain: '<S50>/Multiply2'
           *  Product: '<S50>/Product6'
           */
          rtb_Merge4.DynamicBrakeTorqueDemand = 1.0 /
            rtp_Prm_TractionSystem->DesignBogieMotorCount *
            (rtb_MaximumBrakingEffortPossible_p / contour_fraction);
          rtb_Merge4.Powering = rtb_and;
          rtb_Merge4.Braking = rtb_and1;
          rtb_Merge4.Forward = rtb_AND1_i;
          rtb_Merge4.Reverse = rtb_AND_i;
          rtb_Merge4.TractionTorqueAvailable = rtb_AND_j;
          rtb_Merge4.DynamicBrakeAvailable = rtb_AND1;

          /* Abs: '<S49>/Abs' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           */
          rtb_MaximumBrakingEffortPossible_p = fabs(localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieDynamicBrakingEffort);

          /* Abs: '<S49>/Abs1' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           */
          rtb_Product3_f_idx_2 = fabs(localB->CoreSubsys_p[ForEachVehicle_itr].
            UnitDelay[ForEachBogie_itr_b].BogieMaxBrakingEffortPossible);

          /* BusAssignment: '<S52>/Bus Assignment1' */
          rtb_Merge2.TCUWheelSlideControlActive = rtb_TCUSlide;
          rtb_Merge2.EDBrakeStatus = rtb_AND1;
          rtb_Merge2.EDBrakingEffortAchieved =
            rtb_MaximumBrakingEffortPossible_p;
          rtb_Merge2.EDBrakingEffortPossible = rtb_Product3_f_idx_2;

          /* BusAssignment: '<S53>/Bus Assignment1' */
          rtb_Merge3_h.Forward = rtb_AND1_i;
          rtb_Merge3_h.Reverse = rtb_AND_i;
          rtb_Merge3_h.BogieNotIsolated = rtb_AND_j;

          /* BusAssignment: '<S54>/Bus Assignment1' incorporates:
           *  ForEachSliceSelector generated from: '<S2>/Faults'
           *  ForEachSliceSelector generated from: '<S35>/BogieFaults'
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           *  Logic: '<S46>/OR'
           */
          rtb_Merge1.TCUStatus = rtb_AND2;
          rtb_Merge1.BogieFaulty = ((rtu_Faults[ForEachVehicle_itr]
            .Bogie[ForEachBogie_itr_b].TractionBogieFaulty != 0.0) ||
            (rtu_Faults[ForEachVehicle_itr].Bogie[ForEachBogie_itr_b].
             DynamicBrakeNotAvailable != 0.0));
          rtb_Merge1.TractionNotIsolated = rtb_AND_j;
          rtb_Merge1.EDBrakeNotIsolated = rtb_AND1;
          rtb_Merge1.TCUSlideDetected = rtb_TCUSlide;
          rtb_Merge1.TCUSlipDetected = rtb_TCUSlip;
          rtb_Merge1.TractiveEffortAchieved = localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieTractiveEffort;
          rtb_Merge1.EDBrakingEffortAchieved =
            rtb_MaximumBrakingEffortPossible_p;
          rtb_Merge1.TractiveEffortPossible = localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieMaxTractionEffortPossible;
          rtb_Merge1.EDBrakingEffortPossible = rtb_Product3_f_idx_2;
          rtb_Merge1.TractionPower = localB->CoreSubsys_p[ForEachVehicle_itr].
            UnitDelay[ForEachBogie_itr_b].BogieTractivePower;
          rtb_Merge1.EDBrakingPower = localB->CoreSubsys_p[ForEachVehicle_itr].
            UnitDelay[ForEachBogie_itr_b].BogieDynamicBrakingPower;
          rtb_Merge1.TractivePowerPossible = localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieMaxTractionPowerPossible;
          rtb_Merge1.EDBrakingPowerPossible = localB->
            CoreSubsys_p[ForEachVehicle_itr].UnitDelay[ForEachBogie_itr_b].
            BogieMaxBrakingPowerPossible;

          /* BusCreator: '<S48>/Bus Creator' incorporates:
           *  Constant: '<S48>/Constant1'
           *  DataTypeConversion: '<S48>/Data Type Conversion10'
           *  DataTypeConversion: '<S48>/Data Type Conversion5'
           *  Logic: '<S48>/NOT1'
           *  Product: '<S48>/Product'
           */
          rtb_Merge4.MotorNotAvailable[0] =
            !(rtp_Prm_TractionSystem->AxleHasMotor[0] * static_cast<real_T>
              (rtb_AND_j) != 0.0);

          /* BusAssignment: '<S54>/Bus Assignment1' incorporates:
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           */
          rtb_Merge1.MotorSpeeds[0] = localB->CoreSubsys_p[ForEachVehicle_itr].
            UnitDelay[ForEachBogie_itr_b].BogieMotorSpeeds[0];

          /* BusCreator: '<S48>/Bus Creator' incorporates:
           *  Constant: '<S48>/Constant1'
           *  DataTypeConversion: '<S48>/Data Type Conversion10'
           *  DataTypeConversion: '<S48>/Data Type Conversion5'
           *  Logic: '<S48>/NOT1'
           *  Product: '<S48>/Product'
           */
          rtb_Merge4.MotorNotAvailable[1] =
            !(rtp_Prm_TractionSystem->AxleHasMotor[1] * static_cast<real_T>
              (rtb_AND_j) != 0.0);

          /* BusAssignment: '<S54>/Bus Assignment1' incorporates:
           *  DataTypeConversion: '<S40>/Data Type Conversion'
           *  ForEachSliceSelector generated from: '<S35>/TractionConvertersFB'
           */
          rtb_Merge1.MotorSpeeds[1] = localB->CoreSubsys_p[ForEachVehicle_itr].
            UnitDelay[ForEachBogie_itr_b].BogieMotorSpeeds[1];
          rtb_Merge1.WSPTractionCutout = rtb_Memory;
          rtb_Merge1.SpeedSensorFault = rtb_AND_m;

          /* Logic: '<S68>/NOT' incorporates:
           *  UnitDelay: '<S68>/Unit Delay'
           */
          rtb_AND2 = !localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_k;

          /* Switch: '<S68>/Switch' incorporates:
           *  Logic: '<S68>/AND'
           */
          if ((!rtb_TCUSlide) || (!rtb_AND2)) {
            /* Switch: '<S68>/Switch3' incorporates:
             *  Constant: '<S68>/Constant1'
             *  UnitDelay: '<S68>/Unit Delay1'
             */
            if (rtb_AND2) {
              rtb_MaximumTractionEffortPossible_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value_dh;
            } else {
              rtb_MaximumTractionEffortPossible_k = localDW->
                CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE;
            }

            /* End of Switch: '<S68>/Switch3' */
          }

          /* End of Switch: '<S68>/Switch' */

          /* Sum: '<S70>/Difference Inputs1' incorporates:
           *  UnitDelay: '<S70>/Delay Input2'
           */
          rtb_MaximumTractionEffortPossible_k -= localDW->
            CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
            DelayInput2_DSTATE;

          /* Switch: '<S68>/Switch2' incorporates:
           *  Constant: '<S68>/Constant2'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Gain: '<S68>/2xjerklim'
           */
          if (rtb_AND2) {
            rtb_Product3_f_idx_2 = 2.0 * rtp_Prm_TractionSystem->JerkLimit *
              rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
              .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
          } else {
            rtb_Product3_f_idx_2 =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value_l;
          }

          /* End of Switch: '<S68>/Switch2' */

          /* Product: '<S70>/delta rise limit' incorporates:
           *  SampleTimeMath: '<S70>/sample time'
           *
           * About '<S70>/sample time':
           *  y = K where K = ( w * Ts )
           */
          rtb_Product3_f_idx_2 *=
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt;

          /* Switch: '<S72>/Switch2' incorporates:
           *  RelationalOperator: '<S72>/LowerRelop1'
           */
          if (!(rtb_MaximumTractionEffortPossible_k > rtb_Product3_f_idx_2)) {
            /* Switch: '<S68>/Switch1' incorporates:
             *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
             *  Gain: '<S68>/05xjerklim'
             *  Gain: '<S68>/1xjerklim'
             */
            if (rtb_AND2) {
              rtb_Product3_f_idx_2 = -0.5 * rtp_Prm_TractionSystem->JerkLimit *
                rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
                .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
            } else {
              rtb_Product3_f_idx_2 = -0.02 * rtp_Prm_TractionSystem->JerkLimit *
                rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
                .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
            }

            /* End of Switch: '<S68>/Switch1' */

            /* Product: '<S70>/delta fall limit' incorporates:
             *  SampleTimeMath: '<S70>/sample time'
             *
             * About '<S70>/sample time':
             *  y = K where K = ( w * Ts )
             */
            rtb_Product3_f_idx_2 *=
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt;

            /* Switch: '<S72>/Switch' incorporates:
             *  RelationalOperator: '<S72>/UpperRelop'
             */
            if (!(rtb_MaximumTractionEffortPossible_k < rtb_Product3_f_idx_2)) {
              rtb_Product3_f_idx_2 = rtb_MaximumTractionEffortPossible_k;
            }

            /* End of Switch: '<S72>/Switch' */
          }

          /* End of Switch: '<S72>/Switch2' */

          /* Sum: '<S70>/Difference Inputs2' incorporates:
           *  UnitDelay: '<S70>/Delay Input2'
           */
          rtb_MaximumTractionEffortPossible_k = rtb_Product3_f_idx_2 +
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE;

          /* RelationalOperator: '<S74>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S74>/Delay Input1'
           */
          rtb_FixPtRelationalOperator = (rtb_MaximumTractionEffortPossible_k <
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_n);

          /* Outputs for Atomic SubSystem: '<S71>/TimerOffDelay NoInit' */
          TractionSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator,
            &localB->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit,
            &localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit,
            &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit);

          /* End of Outputs for SubSystem: '<S71>/TimerOffDelay NoInit' */

          /* Logic: '<S76>/Logical Operator40' incorporates:
           *  Constant: '<S73>/Constant'
           *  Logic: '<S71>/AND'
           *  Logic: '<S76>/Logical Operator39'
           *  Logic: '<S76>/Logical Operator41'
           *  Memory: '<S76>/Memory'
           *  RelationalOperator: '<S73>/Compare'
           *  RelationalOperator: '<S75>/FixPt Relational Operator'
           *  UnitDelay: '<S75>/Delay Input1'
           */
          rtb_AND2 = (((localB->CoreSubsys_p[ForEachVehicle_itr]
                        .CoreSubsys_pna[ForEachBogie_itr_b].
                        TimerOffDelayNoInit.LogicalOperator1 &&
                        (rtb_MaximumTractionEffortPossible_k >
                         localDW->CoreSubsys_p[ForEachVehicle_itr].
                         CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_o))
                       || localDW->CoreSubsys_p[ForEachVehicle_itr].
                       CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_l)
                      && (static_cast<int32_T>(rtb_TCUSlide) >
                          static_cast<int32_T>
                          (TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_e)));

          /* Switch: '<S77>/Latch' incorporates:
           *  Logic: '<S71>/NOT'
           *  UnitDelay: '<S77>/Unit Delay'
           */
          if (!rtb_AND2) {
            rtb_MaximumBrakingEffortPossible_p =
              rtb_MaximumTractionEffortPossible_k;
          } else {
            rtb_MaximumBrakingEffortPossible_p = localDW->
              CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b]
              .UnitDelay_DSTATE;
          }

          /* End of Switch: '<S77>/Latch' */

          /* Logic: '<S85>/NOT' incorporates:
           *  UnitDelay: '<S85>/Unit Delay'
           */
          rtb_AND1 = !localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_j;

          /* Switch: '<S85>/Switch' incorporates:
           *  Logic: '<S85>/AND'
           */
          if ((!rtb_TCUSlip) || (!rtb_AND1)) {
            /* Switch: '<S85>/Switch3' incorporates:
             *  Constant: '<S85>/Constant1'
             *  UnitDelay: '<S85>/Unit Delay1'
             */
            if (rtb_AND1) {
              rtb_DataTypeConversion5 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value_i;
            } else {
              rtb_DataTypeConversion5 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE_p;
            }

            /* End of Switch: '<S85>/Switch3' */
          }

          /* End of Switch: '<S85>/Switch' */

          /* Sum: '<S87>/Difference Inputs1' incorporates:
           *  UnitDelay: '<S87>/Delay Input2'
           */
          rtb_DataTypeConversion5 -= localDW->CoreSubsys_p[ForEachVehicle_itr].
            CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE_e;

          /* Switch: '<S85>/Switch2' incorporates:
           *  Constant: '<S85>/Constant2'
           *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
           *  Gain: '<S85>/2xjerklim'
           */
          if (rtb_AND1) {
            rtb_Product3_f_idx_2 = 2.0 * rtp_Prm_TractionSystem->JerkLimit *
              rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
              .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
          } else {
            rtb_Product3_f_idx_2 =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value_o;
          }

          /* End of Switch: '<S85>/Switch2' */

          /* Product: '<S87>/delta rise limit' incorporates:
           *  SampleTimeMath: '<S87>/sample time'
           *
           * About '<S87>/sample time':
           *  y = K where K = ( w * Ts )
           */
          rtb_Product3_f_idx_2 *=
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt_h;

          /* Switch: '<S89>/Switch2' incorporates:
           *  RelationalOperator: '<S89>/LowerRelop1'
           */
          if (!(rtb_DataTypeConversion5 > rtb_Product3_f_idx_2)) {
            /* Switch: '<S85>/Switch1' incorporates:
             *  ForEachSliceSelector generated from: '<S35>/TCMSBogie'
             *  Gain: '<S85>/05xjerklim'
             *  Gain: '<S85>/1xjerklim'
             */
            if (rtb_AND1) {
              rtb_Product3_f_idx_2 = -0.5 * rtp_Prm_TractionSystem->JerkLimit *
                rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
                .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
            } else {
              rtb_Product3_f_idx_2 = -0.02 * rtp_Prm_TractionSystem->JerkLimit *
                rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
                .TCMS.Bogie[ForEachBogie_itr_b].BogieSupportedMass;
            }

            /* End of Switch: '<S85>/Switch1' */

            /* Product: '<S87>/delta fall limit' incorporates:
             *  SampleTimeMath: '<S87>/sample time'
             *
             * About '<S87>/sample time':
             *  y = K where K = ( w * Ts )
             */
            rtb_Product3_f_idx_2 *=
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.sampletime_WtEt_h;

            /* Switch: '<S89>/Switch' incorporates:
             *  RelationalOperator: '<S89>/UpperRelop'
             */
            if (!(rtb_DataTypeConversion5 < rtb_Product3_f_idx_2)) {
              rtb_Product3_f_idx_2 = rtb_DataTypeConversion5;
            }

            /* End of Switch: '<S89>/Switch' */
          }

          /* End of Switch: '<S89>/Switch2' */

          /* Sum: '<S87>/Difference Inputs2' incorporates:
           *  UnitDelay: '<S87>/Delay Input2'
           */
          rtb_DataTypeConversion5 = rtb_Product3_f_idx_2 + localDW->
            CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pna[ForEachBogie_itr_b].
            DelayInput2_DSTATE_e;

          /* RelationalOperator: '<S91>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S91>/Delay Input1'
           */
          rtb_FixPtRelationalOperator_f = (rtb_DataTypeConversion5 <
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_c);

          /* Outputs for Atomic SubSystem: '<S88>/TimerOffDelay NoInit' */
          TractionSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator_f,
            &localB->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit_h,
            &localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].TimerOffDelayNoInit_h,
            &TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.TimerOffDelayNoInit_h);

          /* End of Outputs for SubSystem: '<S88>/TimerOffDelay NoInit' */

          /* Logic: '<S93>/Logical Operator40' incorporates:
           *  Constant: '<S90>/Constant'
           *  Logic: '<S88>/AND'
           *  Logic: '<S93>/Logical Operator39'
           *  Logic: '<S93>/Logical Operator41'
           *  Memory: '<S93>/Memory'
           *  RelationalOperator: '<S90>/Compare'
           *  RelationalOperator: '<S92>/FixPt Relational Operator'
           *  UnitDelay: '<S92>/Delay Input1'
           */
          rtb_AND1 = (((localB->CoreSubsys_p[ForEachVehicle_itr]
                        .CoreSubsys_pna[ForEachBogie_itr_b].
                        TimerOffDelayNoInit_h.LogicalOperator1 &&
                        (rtb_DataTypeConversion5 > localDW->
                         CoreSubsys_p[ForEachVehicle_itr]
                         .CoreSubsys_pna[ForEachBogie_itr_b].
                         DelayInput1_DSTATE_e)) || localDW->
                       CoreSubsys_p[ForEachVehicle_itr]
                       .CoreSubsys_pna[ForEachBogie_itr_b].
                       Memory_PreviousInput_g) && (static_cast<int32_T>
            (rtb_TCUSlip) > static_cast<int32_T>
            (TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant_Value_cd)));

          /* Switch: '<S94>/Latch' incorporates:
           *  Logic: '<S88>/NOT'
           *  UnitDelay: '<S94>/Unit Delay'
           */
          if (!rtb_AND1) {
            rtb_Product3_f_idx_2 = rtb_DataTypeConversion5;
          } else {
            rtb_Product3_f_idx_2 = localDW->CoreSubsys_p[ForEachVehicle_itr].
              CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_p;
          }

          /* End of Switch: '<S94>/Latch' */

          /* Update for UnitDelay: '<S61>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_d = rtb_Memory;

          /* Update for Memory: '<S82>/Memory' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_o =
            rtb_Memory;

          /* Update for UnitDelay: '<S60>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_b =
            rtb_LogicalOperator40_d;

          /* Update for Memory: '<S65>/Memory' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_h =
            rtb_LogicalOperator40_d;

          /* Update for Delay: '<S85>/Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[0] =
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[1];
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE[1] =
            rtb_DataTypeConversion5;

          /* Update for Delay: '<S68>/Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[0] =
            localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[1];
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Delay_DSTATE_b[1] =
            rtb_MaximumTractionEffortPossible_k;

          /* Update for UnitDelay: '<S68>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_k = rtb_AND2;

          /* Update for UnitDelay: '<S70>/Delay Input2' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE =
            rtb_MaximumTractionEffortPossible_k;

          /* Update for UnitDelay: '<S68>/Unit Delay1' incorporates:
           *  Gain: '<S71>/Gain'
           */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Gain_Gain *
            rtb_MaximumBrakingEffortPossible_p;

          /* Update for UnitDelay: '<S74>/Delay Input1' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_n =
            rtb_MaximumTractionEffortPossible_k;

          /* Update for UnitDelay: '<S75>/Delay Input1' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_o =
            rtb_MaximumTractionEffortPossible_k;

          /* Update for Memory: '<S76>/Memory' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_l =
            rtb_AND2;

          /* Update for UnitDelay: '<S77>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE =
            rtb_MaximumBrakingEffortPossible_p;

          /* Update for UnitDelay: '<S85>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_j = rtb_AND1;

          /* Update for UnitDelay: '<S87>/Delay Input2' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput2_DSTATE_e =
            rtb_DataTypeConversion5;

          /* Update for UnitDelay: '<S85>/Unit Delay1' incorporates:
           *  Gain: '<S88>/Gain'
           */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay1_DSTATE_p =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Gain_Gain_o *
            rtb_Product3_f_idx_2;

          /* Update for UnitDelay: '<S91>/Delay Input1' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_c =
            rtb_DataTypeConversion5;

          /* Update for UnitDelay: '<S92>/Delay Input1' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE_e =
            rtb_DataTypeConversion5;

          /* Update for Memory: '<S93>/Memory' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput_g =
            rtb_AND1;

          /* Update for UnitDelay: '<S94>/Unit Delay' */
          localDW->CoreSubsys_p[ForEachVehicle_itr]
            .CoreSubsys_pna[ForEachBogie_itr_b].UnitDelay_DSTATE_p =
            rtb_Product3_f_idx_2;

          /* End of Outputs for SubSystem: '<S35>/TCUONLogic' */
        } else {
          /* Outputs for IfAction SubSystem: '<S35>/TCUOFFLogic' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* SignalConversion generated from: '<S41>/TractionConverterControlOut' incorporates:
           *  Constant: '<S41>/Constant3'
           */
          rtb_Merge4 =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant3_Value;

          /* SignalConversion generated from: '<S41>/TCUtoElectricalOut' incorporates:
           *  Constant: '<S41>/Constant4'
           */
          rtb_Merge3_h =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant4_Value_ko;

          /* SignalConversion generated from: '<S41>/TCUtoTCMSOut' incorporates:
           *  Constant: '<S41>/Constant1'
           */
          rtb_Merge1 =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant1_Value;

          /* SignalConversion generated from: '<S41>/TCUToBCUOut' incorporates:
           *  Constant: '<S41>/Constant2'
           */
          rtb_Merge2 =
            TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Constant2_Value;

          /* End of Outputs for SubSystem: '<S35>/TCUOFFLogic' */
        }

        /* End of If: '<S35>/If' */

        /* Update for Memory: '<S45>/Memory' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pna[ForEachBogie_itr_b].Memory_PreviousInput = rtb_AND_m;

        /* Update for UnitDelay: '<S44>/Delay Input1' */
        localDW->CoreSubsys_p[ForEachVehicle_itr]
          .CoreSubsys_pna[ForEachBogie_itr_b].DelayInput1_DSTATE = rtb_Gain_f;

        /* ForEachSliceAssignment generated from: '<S35>/TractionConverterControl' */
        localB->CoreSubsys_p[ForEachVehicle_itr].
          ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr_b]
          = rtb_Merge4;

        /* ForEachSliceAssignment generated from: '<S35>/TCUtoTCMSOutputs' */
        rtb_ImpAsg_InsertedFor_TCUtoTCMSOutputs_at_inport_0[ForEachBogie_itr_b] =
          rtb_Merge1;

        /* ForEachSliceAssignment generated from: '<S35>/TCUtoElectricalOutputs' */
        rtb_ImpAsg_InsertedFor_TCUtoElectricalOutputs_at_inport_0[ForEachBogie_itr_b]
          = rtb_Merge3_h;

        /* ForEachSliceAssignment generated from: '<S35>/TCUToBCUOutputs' */
        rtb_ImpAsg_InsertedFor_TCUToBCUOutputs_at_inport_0[ForEachBogie_itr_b] =
          rtb_Merge2;
      }

      /* End of Outputs for SubSystem: '<S27>/TractionControl (Per Bogie)' */

      /* Outputs for Iterator SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' incorporates:
       *  ForEach: '<S99>/ForEachBogie'
       */
      for (ForEachBogie_itr = 0; ForEachBogie_itr < 2; ForEachBogie_itr++) {
        /* ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn' */
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
          localB->CoreSubsys_p[ForEachVehicle_itr].
          ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
          .TractionTorqueAvailable;
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd
          = localB->CoreSubsys_p[ForEachVehicle_itr].
          ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
          .DynamicBrakeAvailable;

        /* Gain: '<S100>/Gain' incorporates:
         *  Constant: '<S100>/Constant'
         */
        rtb_Gain_f = TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Gain_Gain *
          rtp_Prm_TractionSystem->DesignWheelDiameter;

        /* DataTypeConversion: '<S99>/Data Type Conversion' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         */
        rtb_DataTypeConversion5 =
          rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          ElectricalSystem.PowerAvailable;

        /* Outputs for Iterator SubSystem: '<S101>/TractionMotor' incorporates:
         *  ForEach: '<S103>/For Each'
         */
        for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
          /* If: '<S103>/If' incorporates:
           *  Constant: '<S101>/Constant'
           *  Constant: '<S104>/Constant'
           *  Constant: '<S104>/Constant1'
           *  Constant: '<S104>/Constant2'
           *  Constant: '<S104>/Constant3'
           *  Constant: '<S104>/Constant4'
           *  Constant: '<S104>/Constant5'
           *  ForEachSliceSelector generated from: '<S103>/AxleHasMotor'
           */
          if (rtp_Prm_TractionSystem->AxleHasMotor[ForEach_itr] != 0.0) {
            /* Outputs for IfAction SubSystem: '<S103>/TractionMotorEnabled' incorporates:
             *  ActionPort: '<S105>/Action Port'
             */
            /* Saturate: '<S109>/safedivide1' */
            if (rtb_Gain_f >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_UpperSat)
            {
              rtb_MaximumTractionEffortPossible_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_UpperSat;
            } else if (rtb_Gain_f <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_LowerSat)
            {
              rtb_MaximumTractionEffortPossible_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide1_LowerSat;
            } else {
              rtb_MaximumTractionEffortPossible_k = rtb_Gain_f;
            }

            /* End of Saturate: '<S109>/safedivide1' */

            /* Product: '<S109>/Pmax//v1' incorporates:
             *  Constant: '<S109>/Constant'
             */
            rtb_Product3_f_idx_2 = rtp_Prm_TractionSystem->DesignGearingRatio /
              rtb_MaximumTractionEffortPossible_k;

            /* Product: '<S105>/Product1' incorporates:
             *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
             *  ForEachSliceSelector generated from: '<S99>/BogieDynamics'
             */
            rtb_MaximumTractionEffortPossible_k =
              rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
              .Dynamics.Bogie[ForEachBogie_itr].WheelSpeed[ForEach_itr] *
              rtb_Product3_f_idx_2;

            /* Abs: '<S105>/Abs' */
            rtb_Abs = fabs(rtb_MaximumTractionEffortPossible_k);

            /* Abs: '<S105>/Abs1' incorporates:
             *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
             *  ForEachSliceSelector generated from: '<S99>/BogieDynamics'
             */
            rtb_MaximumBrakingEffortPossible_p = fabs
              (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
               Dynamics.Bogie[ForEachBogie_itr].WheelSpeed[ForEach_itr]);

            /* Product: '<S105>/Product2' incorporates:
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             */
            rtb_Product3_f_idx_6 = localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .TractionDemandPct * localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .Powering;

            /* Switch: '<S124>/Switch' incorporates:
             *  Constant: '<S124>/Constant'
             *  Constant: '<S124>/Constant1'
             *  Constant: '<S125>/Constant'
             *  RelationalOperator: '<S125>/Compare'
             */
            if (localB->
                ImpAsg_InsertedFor_CommonVehicleConfig_at_inport_0[ForEachVehicle_itr]
                .Orientation >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CompareToConstant_const)
            {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_j;
            } else {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value;
            }

            /* End of Switch: '<S124>/Switch' */

            /* Product: '<S108>/Product1' incorporates:
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             *  Sum: '<S108>/Add'
             */
            rtb_Product_c_idx_0 = (localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .Forward - localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .Reverse) * contour_fraction;

            /* Product: '<S105>/Product' */
            rtb_Product_m = rtb_Product_c_idx_0 *
              rtb_MaximumTractionEffortPossible_k;

            /* SwitchCase: '<S111>/Switch Case1' incorporates:
             *  Constant: '<S129>/Constant'
             */
            switch
              (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CurveInputType_Value)
            {
             case TractionCurveSpecificationType_CurveEquationStatic:
              /* Outputs for IfAction SubSystem: '<S111>/CurveEquations' incorporates:
               *  ActionPort: '<S128>/Action Port'
               */
              /* Saturate: '<S128>/safedivide' */
              if (rtb_Product_m >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_h)
              {
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_h;
              } else if (rtb_Product_m <
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_e)
              {
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_e;
              } else {
                rtb_Product3_f_idx_7 = rtb_Product_m;
              }

              /* End of Saturate: '<S128>/safedivide' */

              /* Switch: '<S142>/Switch' incorporates:
               *  Constant: '<S142>/Constant2'
               *  Constant: '<S142>/NoLimit'
               */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value_c
                  >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_m)
              {
                /* Switch: '<S142>/Switch1' incorporates:
                 *  Constant: '<S142>/Constant3'
                 *  Fcn: '<S142>/Inverse'
                 *  Fcn: '<S142>/Linear'
                 *  Saturate: '<S142>/safedivide'
                 */
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value_g
                    >
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch1_Threshold_e)
                {
                  rtb_Product_c_idx_1 = rtb_Product3_f_idx_7 + 2.0;
                } else {
                  if (rtb_Product3_f_idx_7 >
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_f)
                  {
                    /* Saturate: '<S142>/safedivide' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_f;
                  } else if (rtb_Product3_f_idx_7 <
                             TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_a)
                  {
                    /* Saturate: '<S142>/safedivide' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_a;
                  } else {
                    /* Saturate: '<S142>/safedivide' */
                    x_fraction_c1 = rtb_Product3_f_idx_7;
                  }

                  rtb_Product_c_idx_1 = 1.0 / x_fraction_c1 + 2.0;
                }

                /* End of Switch: '<S142>/Switch1' */
              } else {
                rtb_Product_c_idx_1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value_o;
              }

              /* End of Switch: '<S142>/Switch' */

              /* Gain: '<S128>/Percentage to fraction' */
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Percentagetofraction_Gain
                * rtb_Product3_f_idx_6;

              /* Saturate: '<S128>/Saturation1' */
              if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                  >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat;
              } else if
                  (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                   <
                   TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat;
              } else {
                x_fraction_c1 =
                  rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
              }

              /* End of Saturate: '<S128>/Saturation1' */

              /* Product: '<S128>/TorqueAvailable' incorporates:
               *  Constant: '<S128>/Constant'
               */
              rtb_Product3_f_idx_6 =
                rtp_Prm_TractionSystem->DesignMaxTractionTorque * x_fraction_c1;

              /* Saturate: '<S128>/Saturation3' */
              if (rtb_DataTypeConversion5 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat;
              } else if (rtb_DataTypeConversion5 <
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat;
              } else {
                x_fraction_c1 = rtb_DataTypeConversion5;
              }

              /* End of Saturate: '<S128>/Saturation3' */

              /* Product: '<S128>/Pmax//v' incorporates:
               *  Constant: '<S128>/Constant1'
               *  Product: '<S128>/PowerAvailble'
               */
              x_fraction_c1 = rtp_Prm_TractionSystem->DesignMaxTractionPower *
                x_fraction_c1 / rtb_Product3_f_idx_7;

              /* MinMax: '<S128>/MinMax' */
              if ((rtb_Product3_f_idx_6 < x_fraction_c1) || rtIsNaN
                  (x_fraction_c1)) {
                x_fraction_c1 = rtb_Product3_f_idx_6;
              }

              /* Saturate: '<S128>/Saturation' */
              if (contour_fraction >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat)
              {
                contour_fraction =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat;
              } else {
                if (contour_fraction <
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat)
                {
                  contour_fraction =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat;
                }
              }

              /* End of Saturate: '<S128>/Saturation' */

              /* MinMax: '<S128>/MinMax' */
              if ((x_fraction_c1 < rtb_Product_c_idx_1) || rtIsNaN
                  (rtb_Product_c_idx_1)) {
                rtb_Product_c_idx_1 = x_fraction_c1;
              }

              /* Product: '<S128>/Demand Scaling' */
              rtb_Product3_f_idx_6 = contour_fraction * rtb_Product_c_idx_1;

              /* End of Outputs for SubSystem: '<S111>/CurveEquations' */
              break;

             case TractionCurveSpecificationType_CurveData:
              /* Outputs for IfAction SubSystem: '<S111>/CurveData' incorporates:
               *  ActionPort: '<S127>/Action Port'
               */
              /* Gain: '<S127>/Percentage to fraction' */
              rtb_Product3_f_idx_6 *=
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Percentagetofraction_Gain_n;

              /* MATLAB Function: '<S127>/Subset Interpolation 1D' */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size_b
                  > 0.0) {
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size_b
                    < 2.0) {
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size_b;
                } else {
                  rtb_Product_c_idx_1 = 2.0;
                }

                if (rtb_Product_m <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                    [0]) {
                  rtb_Product3_f_idx_7 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                    [0];
                } else {
                  high_i = static_cast<int32_T>(rtb_Product_c_idx_1) - 1;
                  if (rtb_Product_m >=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                      [high_i]) {
                    rtb_Product3_f_idx_7 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                      [high_i];
                  } else {
                    rtb_Product3_f_idx_7 = (rtNaN);
                    if ((rtb_Product_m >=
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                         [0]) && (rtb_Product_m <=
                                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                                  [high_i])) {
                      rtb_Product_c_idx_1 = (rtb_Product_m -
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                        [0]) /
                        (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                         [1] -
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data_j
                         [0]);
                      if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                          [0] ==
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                          [1]) {
                        rtb_Product3_f_idx_7 =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                          [0];
                      } else {
                        rtb_Product3_f_idx_7 = (1.0 - rtb_Product_c_idx_1) *
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                          [0] + rtb_Product_c_idx_1 *
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data_o
                          [1];
                      }
                    }
                  }
                }
              } else {
                rtb_Product3_f_idx_7 = 0.0;
              }

              /* End of MATLAB Function: '<S127>/Subset Interpolation 1D' */

              /* Saturate: '<S127>/Saturation' */
              if (rtb_Product3_f_idx_6 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat_o)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_UpperSat_o;
              } else if (rtb_Product3_f_idx_6 <
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat_j)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation_LowerSat_j;
              } else {
                x_fraction_c1 = rtb_Product3_f_idx_6;
              }

              /* End of Saturate: '<S127>/Saturation' */

              /* Product: '<S127>/Torque Scaling2' */
              rtb_Product3_f_idx_7 *= x_fraction_c1;

              /* Saturate: '<S138>/Saturation1' */
              if (rtb_DataTypeConversion5 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_f)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_f;
              } else if (rtb_DataTypeConversion5 <
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_a)
              {
                x_fraction_c1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_a;
              } else {
                x_fraction_c1 = rtb_DataTypeConversion5;
              }

              /* End of Saturate: '<S138>/Saturation1' */

              /* Product: '<S138>/Product' incorporates:
               *  Constant: '<S138>/Constant'
               *  Product: '<S138>/Product3'
               */
              rtb_Product_c_idx_1 = rtb_Product3_f_idx_6 *
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_m
                * x_fraction_c1;

              /* MATLAB Function: '<S140>/Replace Zeros' */
              TractionSystem_ReplaceZeros(rtb_Product_m, &localB->
                CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                sf_ReplaceZeros);

              /* Switch: '<S138>/Switch' incorporates:
               *  Abs: '<S138>/Abs'
               *  Abs: '<S138>/Abs1'
               *  Product: '<S138>/Product1'
               *  RelationalOperator: '<S138>/Relational Operator'
               *  Saturate: '<S138>/Saturation3'
               */
              if (fabs(rtb_Product3_f_idx_7 * rtb_Product_m) > fabs
                  (rtb_Product_c_idx_1)) {
                /* Saturate: '<S138>/Saturation3' */
                if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                    >
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_f)
                {
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_f;
                } else if
                    (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                     <
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_d)
                {
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_d;
                } else {
                  x_fraction_c1 =
                    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
                }

                /* Product: '<S138>/Product2' incorporates:
                 *  Constant: '<S138>/Constant1'
                 *  Product: '<S138>/Product4'
                 */
                rtb_Product3_f_idx_6 = rtb_Product3_f_idx_6 *
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value_e
                  * x_fraction_c1;

                /* MinMax: '<S138>/MinMax' */
                if ((rtb_Product3_f_idx_7 < rtb_Product3_f_idx_6) || rtIsNaN
                    (rtb_Product3_f_idx_6)) {
                  rtb_Product3_f_idx_6 = rtb_Product3_f_idx_7;
                }

                /* Product: '<S140>/Divide' */
                contour_fraction = rtb_Product_c_idx_1 / localB->
                  CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  sf_ReplaceZeros.y;

                /* MinMax: '<S138>/MinMax1' */
                if ((contour_fraction < rtb_Product3_f_idx_6) || rtIsNaN
                    (rtb_Product3_f_idx_6)) {
                  rtb_Product3_f_idx_6 = contour_fraction;
                }

                /* End of MinMax: '<S138>/MinMax1' */
              } else {
                if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                    >
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_f)
                {
                  /* Saturate: '<S138>/Saturation3' */
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_f;
                } else if
                    (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                     <
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_d)
                {
                  /* Saturate: '<S138>/Saturation3' */
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_d;
                } else {
                  /* Saturate: '<S138>/Saturation3' */
                  x_fraction_c1 =
                    rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
                }

                /* Product: '<S138>/Product2' incorporates:
                 *  Constant: '<S138>/Constant1'
                 *  Product: '<S138>/Product4'
                 *  Saturate: '<S138>/Saturation3'
                 */
                rtb_Product3_f_idx_6 = rtb_Product3_f_idx_6 *
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value_e
                  * x_fraction_c1;

                /* MinMax: '<S138>/MinMax' */
                if ((rtb_Product3_f_idx_7 < rtb_Product3_f_idx_6) || rtIsNaN
                    (rtb_Product3_f_idx_6)) {
                  rtb_Product3_f_idx_6 = rtb_Product3_f_idx_7;
                }
              }

              /* End of Switch: '<S138>/Switch' */
              /* End of Outputs for SubSystem: '<S111>/CurveData' */
              break;

             case TractionCurveSpecificationType_ContourData:
              /* Outputs for IfAction SubSystem: '<S111>/ContourData' incorporates:
               *  ActionPort: '<S126>/Action Port'
               */
              /* MATLAB Function: '<S126>/Contour Interpolation 2D y' */
              if (!localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_not_empty) {
                localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours = 0.0;
                localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_not_empty = true;
                i = 0;
                while ((i < 5) &&
                       (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                        [i] > 0.0)) {
                  localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours = static_cast<real_T>(i) + 1.0;
                  i++;
                }
              }

              if (localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours > 0.0) {
                rtb_Product_c_idx_1 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                  CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  previous_contour_index;
                contour_fraction = 0.0;
                if (rtb_Product3_f_idx_6 <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                    [0]) {
                  rtb_Product_c_idx_1 = 1.0;
                } else if (rtb_Product3_f_idx_6 <
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                           [static_cast<int32_T>(localDW->
                            CoreSubsys_p[ForEachVehicle_itr]
                            .CoreSubsys_pnae[ForEachBogie_itr]
                            .CoreSubsys_h[ForEach_itr].n_countours) - 1]) {
                  i = static_cast<int32_T>(((1.0 - localDW->
                    CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .previous_contour_index) + localDW->
                    CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours));
                  low_ip1 = 0;
                  while ((low_ip1 <= i - 1) && (rtb_Product3_f_idx_6 <
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                          [static_cast<int32_T>((localDW->
                            CoreSubsys_p[ForEachVehicle_itr]
                            .CoreSubsys_pnae[ForEachBogie_itr]
                            .CoreSubsys_h[ForEach_itr].previous_contour_index +
                            static_cast<real_T>(low_ip1))) - 1])) {
                    rtb_Product_c_idx_1--;
                    low_ip1++;
                  }

                  do {
                    exitg1 = 0;
                    high_i = static_cast<int32_T>((rtb_Product_c_idx_1 + 1.0)) -
                      1;
                    if (rtb_Product3_f_idx_6 >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                        [high_i]) {
                      rtb_Product_c_idx_1++;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  i = static_cast<int32_T>(rtb_Product_c_idx_1) - 1;
                  contour_fraction = (rtb_Product3_f_idx_6 -
                                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                                      [i]) /
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                     [high_i] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data_i
                     [i]);
                } else {
                  rtb_Product_c_idx_1 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours;
                }

                contour_x_index_c1 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                  CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  previous_contour_x_index_c1;
                x_fraction_c1 = 0.0;
                high_i = static_cast<int32_T>(rtb_Product_c_idx_1);
                i = high_i - 1;
                if (rtb_Product_m <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                    [i]) {
                  contour_x_index_c1 = 1.0;
                } else if (rtb_Product_m <
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                           [((static_cast<int32_T>
                              (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                               [i]) - 1) * 10 + high_i) - 1]) {
                  i = static_cast<int32_T>
                    ((TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                      [i] + (1.0 - localDW->CoreSubsys_p[ForEachVehicle_itr].
                             CoreSubsys_pnae[ForEachBogie_itr]
                             .CoreSubsys_h[ForEach_itr].
                             previous_contour_x_index_c1)));
                  low_ip1 = 0;
                  while ((low_ip1 <= i - 1) && (rtb_Product_m <
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                          [((static_cast<int32_T>((localDW->
                              CoreSubsys_p[ForEachVehicle_itr]
                              .CoreSubsys_pnae[ForEachBogie_itr]
                              .CoreSubsys_h[ForEach_itr].
                              previous_contour_x_index_c1 + static_cast<real_T>
                              (low_ip1))) - 1) * 10 + high_i) - 1])) {
                    contour_x_index_c1--;
                    low_ip1++;
                  }

                  do {
                    exitg1 = 0;
                    i = ((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                         10 + high_i) - 1;
                    if (rtb_Product_m >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                        [i]) {
                      contour_x_index_c1++;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  low_ip1 = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10
                             + high_i) - 1;
                  x_fraction_c1 = (rtb_Product_m -
                                   TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                                   [low_ip1]) /
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                     [i] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                     [low_ip1]);
                } else {
                  contour_x_index_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                    [i];
                }

                i = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10 +
                     high_i) + 4;
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                  [i];
                if (x_fraction_c1 > 0.0) {
                  rtb_Product3_f_idx_7 =
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                     [((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                       10 + high_i) + 4] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                     [i]) * x_fraction_c1 +
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                    [i];
                }

                if (contour_fraction > 0.0) {
                  contour_x_index_c1 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .previous_contour_x_index_c2;
                  x_fraction_c1 = 0.0;
                  high_i = static_cast<int32_T>((rtb_Product_c_idx_1 + 1.0));
                  i = high_i - 1;
                  if (rtb_Product_m <=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                      [i]) {
                    contour_x_index_c1 = 1.0;
                  } else if (rtb_Product_m <
                             TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                             [((static_cast<int32_T>
                                (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                                 [i]) - 1) * 10 + high_i) - 1]) {
                    i = static_cast<int32_T>
                      ((TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                        [i] + (1.0 - localDW->CoreSubsys_p[ForEachVehicle_itr].
                               CoreSubsys_pnae[ForEachBogie_itr]
                               .CoreSubsys_h[ForEach_itr].
                               previous_contour_x_index_c2)));
                    low_ip1 = 0;
                    while ((low_ip1 <= i - 1) && (rtb_Product_m <
                            TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                            [((static_cast<int32_T>((localDW->
                                CoreSubsys_p[ForEachVehicle_itr]
                                .CoreSubsys_pnae[ForEachBogie_itr]
                                .CoreSubsys_h[ForEach_itr].
                                previous_contour_x_index_c2 + static_cast<real_T>
                                (low_ip1))) - 1) * 10 + high_i) - 1])) {
                      contour_x_index_c1--;
                      low_ip1++;
                    }

                    do {
                      exitg1 = 0;
                      i = ((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1)
                           * 10 + high_i) - 1;
                      if (rtb_Product_m >=
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                          [i]) {
                        contour_x_index_c1++;
                      } else {
                        exitg1 = 1;
                      }
                    } while (exitg1 == 0);

                    low_ip1 = ((static_cast<int32_T>(contour_x_index_c1) - 1) *
                               10 + high_i) - 1;
                    x_fraction_c1 = (rtb_Product_m -
                                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                                     [low_ip1]) /
                      (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                       [i] -
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                       [low_ip1]);
                  } else {
                    contour_x_index_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size_a
                      [i];
                  }

                  i = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10 +
                       high_i) + 4;
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                    [i];
                  if (x_fraction_c1 > 0.0) {
                    rtb_Product_c_idx_1 =
                      (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                       [((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                         10 + high_i) + 4] -
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                       [i]) * x_fraction_c1 +
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data_d
                      [i];
                  }

                  rtb_Product3_f_idx_7 += (rtb_Product_c_idx_1 -
                    rtb_Product3_f_idx_7) * contour_fraction;
                }
              } else {
                rtb_Product3_f_idx_7 = 0.0;
              }

              /* MATLAB Function: '<S133>/MaxPowerLookup' */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_subset_size
                  > 0.0) {
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_subset_size
                    < 5.0) {
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_subset_size;
                } else {
                  rtb_Product_c_idx_1 = 5.0;
                }

                if (rtb_Product3_f_idx_6 <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                    [0]) {
                  contour_fraction =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
                    [0];
                } else {
                  high_i = static_cast<int32_T>(rtb_Product_c_idx_1);
                  i = high_i - 1;
                  if (rtb_Product3_f_idx_6 >=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                      [i]) {
                    contour_fraction =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
                      [i];
                  } else {
                    contour_fraction = (rtNaN);
                    if (rtb_Product3_f_idx_6 >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                        [0]) {
                      high_i = static_cast<int8_T>(high_i);
                      if (rtb_Product3_f_idx_6 <=
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                          [high_i - 1]) {
                        i = 1;
                        low_ip1 = 2;
                        while (high_i > low_ip1) {
                          mid_i = (i >> 1) + (high_i >> 1);
                          if (((i & 1) == 1) && ((high_i & 1) == 1)) {
                            mid_i++;
                          }

                          if (rtb_Product3_f_idx_6 >=
                              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                              [mid_i - 1]) {
                            i = mid_i;
                            low_ip1 = mid_i + 1;
                          } else {
                            high_i = mid_i;
                          }
                        }

                        x_fraction_c1 =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                          [i - 1];
                        rtb_Product_c_idx_1 = (rtb_Product3_f_idx_6 -
                          x_fraction_c1) /
                          (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_x_data
                           [i] - x_fraction_c1);
                        contour_fraction =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
                          [i - 1];
                        if (!(contour_fraction ==
                              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
                              [i])) {
                          contour_fraction = (1.0 - rtb_Product_c_idx_1) *
                            contour_fraction + rtb_Product_c_idx_1 *
                            TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxPowerLookup_y_data
                            [i];
                        }
                      }
                    }
                  }
                }
              } else {
                contour_fraction = 0.0;
              }

              /* End of MATLAB Function: '<S133>/MaxPowerLookup' */

              /* Abs: '<S133>/Abs2' */
              rtb_Abs2 = fabs(rtb_Product_m);

              /* MATLAB Function: '<S133>/MaxTorqueLookup' */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_subset_size
                  > 0.0) {
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_subset_size
                    < 5.0) {
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_subset_size;
                } else {
                  rtb_Product_c_idx_1 = 5.0;
                }

                if (rtb_Product3_f_idx_6 <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                    [0]) {
                  contour_x_index_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
                    [0];
                } else {
                  high_i = static_cast<int32_T>(rtb_Product_c_idx_1);
                  i = high_i - 1;
                  if (rtb_Product3_f_idx_6 >=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                      [i]) {
                    contour_x_index_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
                      [i];
                  } else {
                    contour_x_index_c1 = (rtNaN);
                    if (rtb_Product3_f_idx_6 >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                        [0]) {
                      high_i = static_cast<int8_T>(high_i);
                      if (rtb_Product3_f_idx_6 <=
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                          [high_i - 1]) {
                        i = 1;
                        low_ip1 = 2;
                        while (high_i > low_ip1) {
                          mid_i = (i >> 1) + (high_i >> 1);
                          if (((i & 1) == 1) && ((high_i & 1) == 1)) {
                            mid_i++;
                          }

                          if (rtb_Product3_f_idx_6 >=
                              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                              [mid_i - 1]) {
                            i = mid_i;
                            low_ip1 = mid_i + 1;
                          } else {
                            high_i = mid_i;
                          }
                        }

                        x_fraction_c1 =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                          [i - 1];
                        rtb_Product_c_idx_1 = (rtb_Product3_f_idx_6 -
                          x_fraction_c1) /
                          (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_x_data
                           [i] - x_fraction_c1);
                        contour_x_index_c1 =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
                          [i - 1];
                        if (!(contour_x_index_c1 ==
                              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
                              [i])) {
                          contour_x_index_c1 = (1.0 - rtb_Product_c_idx_1) *
                            contour_x_index_c1 + rtb_Product_c_idx_1 *
                            TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.MaxTorqueLookup_y_data
                            [i];
                        }
                      }
                    }
                  }
                }
              } else {
                contour_x_index_c1 = 0.0;
              }

              /* End of MATLAB Function: '<S133>/MaxTorqueLookup' */

              /* MATLAB Function: '<S136>/Replace Zeros' */
              TractionSystem_ReplaceZeros(rtb_Abs2, &localB->
                CoreSubsys_p[ForEachVehicle_itr]
                .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                sf_ReplaceZeros_k);

              /* Switch: '<S126>/Switch' incorporates:
               *  Constant: '<S126>/Constant'
               */
              if (rtb_Product3_f_idx_6 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_c)
              {
                /* Saturate: '<S133>/Saturation1' */
                if (rtb_DataTypeConversion5 >
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_j)
                {
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_UpperSat_j;
                } else if (rtb_DataTypeConversion5 <
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_e)
                {
                  x_fraction_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation1_LowerSat_e;
                } else {
                  x_fraction_c1 = rtb_DataTypeConversion5;
                }

                /* End of Saturate: '<S133>/Saturation1' */

                /* Product: '<S133>/Product' */
                rtb_Product3_f_idx_6 = x_fraction_c1 * contour_fraction;

                /* Switch: '<S133>/Switch' incorporates:
                 *  Abs: '<S133>/Abs'
                 *  Abs: '<S133>/Abs1'
                 *  MATLAB Function: '<S126>/Contour Interpolation 2D y'
                 *  Product: '<S133>/Product1'
                 *  RelationalOperator: '<S133>/Relational Operator'
                 *  Saturate: '<S133>/Saturation3'
                 */
                if (fabs(rtb_Product3_f_idx_7 * rtb_Product_m) > fabs
                    (rtb_Product3_f_idx_6)) {
                  /* Saturate: '<S133>/Saturation3' */
                  if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                      >
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_k)
                  {
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_k;
                  } else if
                      (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                       <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_c)
                  {
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_c;
                  } else {
                    x_fraction_c1 =
                      rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
                  }

                  /* Product: '<S133>/Product2' */
                  x_fraction_c1 *= contour_x_index_c1;

                  /* MinMax: '<S133>/MinMax' */
                  if ((rtb_Product3_f_idx_7 < x_fraction_c1) || rtIsNaN
                      (x_fraction_c1)) {
                    x_fraction_c1 = rtb_Product3_f_idx_7;
                  }

                  /* Product: '<S136>/Divide' */
                  rtb_Product3_f_idx_6 /= localB->
                    CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .sf_ReplaceZeros_k.y;

                  /* MinMax: '<S133>/MinMax1' */
                  if ((!(rtb_Product3_f_idx_6 < x_fraction_c1)) && (!rtIsNaN
                       (x_fraction_c1))) {
                    rtb_Product3_f_idx_6 = x_fraction_c1;
                  }

                  /* End of MinMax: '<S133>/MinMax1' */
                } else {
                  if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                      >
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_k)
                  {
                    /* Saturate: '<S133>/Saturation3' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_UpperSat_k;
                  } else if
                      (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                       <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_c)
                  {
                    /* Saturate: '<S133>/Saturation3' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Saturation3_LowerSat_c;
                  } else {
                    /* Saturate: '<S133>/Saturation3' */
                    x_fraction_c1 =
                      rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
                  }

                  /* Product: '<S133>/Product2' incorporates:
                   *  Saturate: '<S133>/Saturation3'
                   */
                  rtb_Product3_f_idx_6 = x_fraction_c1 * contour_x_index_c1;

                  /* MinMax: '<S133>/MinMax' */
                  if ((rtb_Product3_f_idx_7 < rtb_Product3_f_idx_6) || rtIsNaN
                      (rtb_Product3_f_idx_6)) {
                    rtb_Product3_f_idx_6 = rtb_Product3_f_idx_7;
                  }
                }

                /* End of Switch: '<S133>/Switch' */
              } else {
                rtb_Product3_f_idx_6 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_a;
              }

              /* End of Switch: '<S126>/Switch' */
              /* End of Outputs for SubSystem: '<S111>/ContourData' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S111>/NoData' incorporates:
               *  ActionPort: '<S130>/Action Port'
               */
              /* SignalConversion generated from: '<S130>/TractionTorque' incorporates:
               *  Constant: '<S130>/Constant'
               */
              rtb_Product3_f_idx_6 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_jf;

              /* End of Outputs for SubSystem: '<S111>/NoData' */
              break;
            }

            /* End of SwitchCase: '<S111>/Switch Case1' */

            /* Product: '<S131>/Product' incorporates:
             *  Constant: '<S111>/PerformanceFactor'
             *  Fcn: '<S131>/Fcn'
             *  ForEachSliceSelector generated from: '<S2>/Overrides'
             *  Product: '<S111>/Torque Scaling'
             */
            rtb_Product3_f_idx_6 = (rtu_Overrides[ForEachVehicle_itr].
              TractionForceVariation / 100.0 + 1.0) * (rtb_Product3_f_idx_6 *
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.PerformanceFactor_Value);

            /* RateLimiter: '<S111>/Rate Limiter' */
            rtb_Product3_f_idx_7 = rtb_Product3_f_idx_6 - localDW->
              CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pnae[ForEachBogie_itr]
              .CoreSubsys_h[ForEach_itr].PrevY;
            if (rtb_Product3_f_idx_7 >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim)
            {
              rtb_Product3_f_idx_6 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                PrevY +
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim;
            } else {
              if (rtb_Product3_f_idx_7 <
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim)
              {
                rtb_Product3_f_idx_6 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  PrevY +
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim;
              }
            }

            localDW->CoreSubsys_p[ForEachVehicle_itr]
              .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].PrevY
              = rtb_Product3_f_idx_6;

            /* End of RateLimiter: '<S111>/Rate Limiter' */

            /* Switch: '<S110>/Switch2' incorporates:
             *  Constant: '<S110>/No Power'
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             *  Product: '<S105>/Force'
             */
            if (localB->CoreSubsys_p[ForEachVehicle_itr].
                ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
                .MotorNotAvailable[ForEach_itr] >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch2_Threshold)
            {
              rtb_Product3_f_idx_6 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoPower_Value;
            } else {
              rtb_Product3_f_idx_6 = rtb_Product3_f_idx_6 * rtb_Product3_f_idx_2
                * rtb_Product_c_idx_0;
            }

            /* End of Switch: '<S110>/Switch2' */

            /* Product: '<S105>/Product3' incorporates:
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             */
            rtb_Product_c_idx_0 = localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .DynamicBrakeTorqueDemand * localB->
              CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .Braking;

            /* SwitchCase: '<S107>/Switch Case1' incorporates:
             *  Constant: '<S117>/Constant'
             */
            switch
              (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.CurveInputType_Value_f)
            {
             case TractionCurveSpecificationType_CurveEquationStatic:
              /* Outputs for IfAction SubSystem: '<S107>/CurveEquations' incorporates:
               *  ActionPort: '<S116>/Action Port'
               */
              /* Saturate: '<S116>/safedivide' */
              if (rtb_Abs >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_j)
              {
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat_j;
              } else if (rtb_Abs <
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_d)
              {
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat_d;
              } else {
                rtb_Product3_f_idx_7 = rtb_Abs;
              }

              /* End of Saturate: '<S116>/safedivide' */

              /* Switch: '<S122>/Switch' incorporates:
               *  Constant: '<S122>/Constant2'
               *  Constant: '<S122>/NoLimit'
               */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value
                  >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold)
              {
                /* Switch: '<S122>/Switch1' incorporates:
                 *  Constant: '<S122>/Constant3'
                 *  Fcn: '<S122>/Inverse'
                 *  Fcn: '<S122>/Linear'
                 *  Saturate: '<S122>/safedivide'
                 */
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value
                    >
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch1_Threshold)
                {
                  rtb_Product_c_idx_1 = rtb_Product3_f_idx_7 + 2.0;
                } else {
                  if (rtb_Product3_f_idx_7 >
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat)
                  {
                    /* Saturate: '<S122>/safedivide' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_UpperSat;
                  } else if (rtb_Product3_f_idx_7 <
                             TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat)
                  {
                    /* Saturate: '<S122>/safedivide' */
                    x_fraction_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.safedivide_LowerSat;
                  } else {
                    /* Saturate: '<S122>/safedivide' */
                    x_fraction_c1 = rtb_Product3_f_idx_7;
                  }

                  rtb_Product_c_idx_1 = 1.0 / x_fraction_c1 + 2.0;
                }

                /* End of Switch: '<S122>/Switch1' */
              } else {
                rtb_Product_c_idx_1 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value;
              }

              /* End of Switch: '<S122>/Switch' */

              /* S-Function (sfix_look1_dyn): '<S123>/Lookup Table Dynamic' incorporates:
               *  Constant: '<S123>/Constant'
               *  Constant: '<S123>/Constant1'
               */
              /* Dynamic Look-Up Table Block: '<S123>/Lookup Table Dynamic'
               * Input0  Data Type:  Floating Point real_T
               * Input1  Data Type:  Floating Point real_T
               * Input2  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * Lookup Method: Linear_Endpoint
               *
               */
              LookUp_real_T_real_T( &(rtb_MinMax_i),
                                   &TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value
                                   [0], rtb_Abs,
                                   &rtp_Prm_TractionSystem->BrakeFadeRampDownSpeeds
                                   [0], 1U);

              /* Product: '<S123>/Torque Scaling' incorporates:
               *  Constant: '<S116>/Constant'
               */
              rtb_MinMax_i *= rtp_Prm_TractionSystem->DesignMaxBrakingTorque;

              /* Product: '<S116>/Pmax//v' incorporates:
               *  Constant: '<S116>/Constant1'
               */
              x_fraction_c1 = rtp_Prm_TractionSystem->DesignMaxBrakingPower /
                rtb_Product3_f_idx_7;

              /* MinMax: '<S116>/MinMax' */
              if ((rtb_MinMax_i < x_fraction_c1) || rtIsNaN(x_fraction_c1)) {
                x_fraction_c1 = rtb_MinMax_i;
              }

              if ((x_fraction_c1 < rtb_Product_c_idx_1) || rtIsNaN
                  (rtb_Product_c_idx_1)) {
                rtb_MinMax_i = x_fraction_c1;
              } else {
                rtb_MinMax_i = rtb_Product_c_idx_1;
              }

              /* End of MinMax: '<S116>/MinMax' */

              /* MinMax: '<S116>/MinMax1' */
              if ((!(rtb_Product_c_idx_0 < rtb_MinMax_i)) && (!rtIsNaN
                   (rtb_MinMax_i))) {
                rtb_Product_c_idx_0 = rtb_MinMax_i;
              }

              /* End of MinMax: '<S116>/MinMax1' */
              /* End of Outputs for SubSystem: '<S107>/CurveEquations' */
              break;

             case TractionCurveSpecificationType_CurveData:
              /* Outputs for IfAction SubSystem: '<S107>/CurveData' incorporates:
               *  ActionPort: '<S115>/Action Port'
               */
              /* MATLAB Function: '<S115>/Subset Interpolation 1D' */
              if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size
                  > 0.0) {
                if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size
                    < 2.0) {
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_subset_size;
                } else {
                  rtb_Product_c_idx_1 = 2.0;
                }

                if (rtb_Abs <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                    [0]) {
                  rtb_Product3_f_idx_7 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                    [0];
                } else {
                  high_i = static_cast<int32_T>(rtb_Product_c_idx_1) - 1;
                  if (rtb_Abs >=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                      [high_i]) {
                    rtb_Product3_f_idx_7 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                      [high_i];
                  } else {
                    rtb_Product3_f_idx_7 = (rtNaN);
                    if ((rtb_Abs >=
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                         [0]) && (rtb_Abs <=
                                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                                  [high_i])) {
                      rtb_Product_c_idx_1 = (rtb_Abs -
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                        [0]) /
                        (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                         [1] -
                         TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_x_data
                         [0]);
                      if (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                          [0] ==
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                          [1]) {
                        rtb_Product3_f_idx_7 =
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                          [0];
                      } else {
                        rtb_Product3_f_idx_7 = (1.0 - rtb_Product_c_idx_1) *
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                          [0] + rtb_Product_c_idx_1 *
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.SubsetInterpolation1D_y_data
                          [1];
                      }
                    }
                  }
                }
              } else {
                rtb_Product3_f_idx_7 = 0.0;
              }

              /* End of MATLAB Function: '<S115>/Subset Interpolation 1D' */

              /* MinMax: '<S115>/MinMax2' */
              if ((!(rtb_Product_c_idx_0 < rtb_Product3_f_idx_7)) && (!rtIsNaN
                   (rtb_Product3_f_idx_7))) {
                rtb_Product_c_idx_0 = rtb_Product3_f_idx_7;
              }

              /* End of MinMax: '<S115>/MinMax2' */
              /* End of Outputs for SubSystem: '<S107>/CurveData' */
              break;

             case TractionCurveSpecificationType_ContourData:
              /* Outputs for IfAction SubSystem: '<S107>/ContourData' incorporates:
               *  ActionPort: '<S114>/Action Port'
               */
              /* MATLAB Function: '<S114>/Contour Interpolation 2D y' */
              if (!localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_not_empty_m) {
                localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_c = 0.0;
                localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_not_empty_m = true;
                i = 0;
                while ((i < 5) &&
                       (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                        [i] > 0.0)) {
                  localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours_c = static_cast<real_T>(i) + 1.0;
                  i++;
                }
              }

              if (localDW->CoreSubsys_p[ForEachVehicle_itr]
                  .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  n_countours_c > 0.0) {
                rtb_Product_c_idx_1 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                  CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  previous_contour_index_n;
                contour_fraction = 0.0;
                if (rtb_Product_c_idx_0 <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                    [0]) {
                  rtb_Product_c_idx_1 = 1.0;
                } else if (rtb_Product_c_idx_0 <
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                           [static_cast<int32_T>(localDW->
                            CoreSubsys_p[ForEachVehicle_itr]
                            .CoreSubsys_pnae[ForEachBogie_itr]
                            .CoreSubsys_h[ForEach_itr].n_countours_c) - 1]) {
                  i = static_cast<int32_T>(((1.0 - localDW->
                    CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .previous_contour_index_n) + localDW->
                    CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours_c));
                  low_ip1 = 0;
                  while ((low_ip1 <= i - 1) && (rtb_Product_c_idx_0 <
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                          [static_cast<int32_T>((localDW->
                            CoreSubsys_p[ForEachVehicle_itr]
                            .CoreSubsys_pnae[ForEachBogie_itr]
                            .CoreSubsys_h[ForEach_itr].previous_contour_index_n
                            + static_cast<real_T>(low_ip1))) - 1])) {
                    rtb_Product_c_idx_1--;
                    low_ip1++;
                  }

                  do {
                    exitg1 = 0;
                    high_i = static_cast<int32_T>((rtb_Product_c_idx_1 + 1.0)) -
                      1;
                    if (rtb_Product_c_idx_0 >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                        [high_i]) {
                      rtb_Product_c_idx_1++;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  i = static_cast<int32_T>(rtb_Product_c_idx_1) - 1;
                  contour_fraction = (rtb_Product_c_idx_0 -
                                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                                      [i]) /
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                     [high_i] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_z_data
                     [i]);
                } else {
                  rtb_Product_c_idx_1 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .n_countours_c;
                }

                contour_x_index_c1 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                  CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  previous_contour_x_index_c1_b;
                x_fraction_c1 = 0.0;
                high_i = static_cast<int32_T>(rtb_Product_c_idx_1);
                i = high_i - 1;
                if (rtb_Abs <=
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                    [i]) {
                  contour_x_index_c1 = 1.0;
                } else if (rtb_Abs <
                           TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                           [((static_cast<int32_T>
                              (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                               [i]) - 1) * 10 + high_i) - 1]) {
                  i = static_cast<int32_T>
                    ((TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                      [i] + (1.0 - localDW->CoreSubsys_p[ForEachVehicle_itr].
                             CoreSubsys_pnae[ForEachBogie_itr]
                             .CoreSubsys_h[ForEach_itr].
                             previous_contour_x_index_c1_b)));
                  low_ip1 = 0;
                  while ((low_ip1 <= i - 1) && (rtb_Abs <
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                          [((static_cast<int32_T>((localDW->
                              CoreSubsys_p[ForEachVehicle_itr]
                              .CoreSubsys_pnae[ForEachBogie_itr]
                              .CoreSubsys_h[ForEach_itr].
                              previous_contour_x_index_c1_b + static_cast<real_T>
                              (low_ip1))) - 1) * 10 + high_i) - 1])) {
                    contour_x_index_c1--;
                    low_ip1++;
                  }

                  do {
                    exitg1 = 0;
                    i = ((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                         10 + high_i) - 1;
                    if (rtb_Abs >=
                        TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                        [i]) {
                      contour_x_index_c1++;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);

                  low_ip1 = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10
                             + high_i) - 1;
                  x_fraction_c1 = (rtb_Abs -
                                   TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                                   [low_ip1]) /
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                     [i] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                     [low_ip1]);
                } else {
                  contour_x_index_c1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                    [i];
                }

                i = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10 +
                     high_i) + 4;
                rtb_Product3_f_idx_7 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                  [i];
                if (x_fraction_c1 > 0.0) {
                  rtb_Product3_f_idx_7 =
                    (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                     [((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                       10 + high_i) + 4] -
                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                     [i]) * x_fraction_c1 +
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                    [i];
                }

                if (contour_fraction > 0.0) {
                  contour_x_index_c1 = localDW->CoreSubsys_p[ForEachVehicle_itr]
                    .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr]
                    .previous_contour_x_index_c2_i;
                  x_fraction_c1 = 0.0;
                  high_i = static_cast<int32_T>((rtb_Product_c_idx_1 + 1.0));
                  i = high_i - 1;
                  if (rtb_Abs <=
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                      [i]) {
                    contour_x_index_c1 = 1.0;
                  } else if (rtb_Abs <
                             TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                             [((static_cast<int32_T>
                                (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                                 [i]) - 1) * 10 + high_i) - 1]) {
                    i = static_cast<int32_T>
                      ((TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                        [i] + (1.0 - localDW->CoreSubsys_p[ForEachVehicle_itr].
                               CoreSubsys_pnae[ForEachBogie_itr]
                               .CoreSubsys_h[ForEach_itr].
                               previous_contour_x_index_c2_i)));
                    low_ip1 = 0;
                    while ((low_ip1 <= i - 1) && (rtb_Abs <
                            TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                            [((static_cast<int32_T>((localDW->
                                CoreSubsys_p[ForEachVehicle_itr]
                                .CoreSubsys_pnae[ForEachBogie_itr]
                                .CoreSubsys_h[ForEach_itr].
                                previous_contour_x_index_c2_i +
                                static_cast<real_T>(low_ip1))) - 1) * 10 +
                              high_i) - 1])) {
                      contour_x_index_c1--;
                      low_ip1++;
                    }

                    do {
                      exitg1 = 0;
                      i = ((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1)
                           * 10 + high_i) - 1;
                      if (rtb_Abs >=
                          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                          [i]) {
                        contour_x_index_c1++;
                      } else {
                        exitg1 = 1;
                      }
                    } while (exitg1 == 0);

                    low_ip1 = ((static_cast<int32_T>(contour_x_index_c1) - 1) *
                               10 + high_i) - 1;
                    x_fraction_c1 = (rtb_Abs -
                                     TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                                     [low_ip1]) /
                      (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                       [i] -
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                       [low_ip1]);
                  } else {
                    contour_x_index_c1 =
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_size
                      [i];
                  }

                  i = ((static_cast<int32_T>(contour_x_index_c1) - 1) * 10 +
                       high_i) + 4;
                  rtb_Product_c_idx_1 =
                    TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                    [i];
                  if (x_fraction_c1 > 0.0) {
                    rtb_Product_c_idx_1 =
                      (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                       [((static_cast<int32_T>((contour_x_index_c1 + 1.0)) - 1) *
                         10 + high_i) + 4] -
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                       [i]) * x_fraction_c1 +
                      TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.ContourInterpolation2Dy_contour_xy_data
                      [i];
                  }

                  rtb_Product3_f_idx_7 += (rtb_Product_c_idx_1 -
                    rtb_Product3_f_idx_7) * contour_fraction;
                }
              } else {
                rtb_Product3_f_idx_7 = 0.0;
              }

              /* Switch: '<S114>/Switch' incorporates:
               *  Constant: '<S114>/Constant'
               *  MATLAB Function: '<S114>/Contour Interpolation 2D y'
               */
              if (rtb_Product_c_idx_0 >
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Switch_Threshold_a)
              {
                rtb_Product_c_idx_0 = rtb_Product3_f_idx_7;
              } else {
                rtb_Product_c_idx_0 =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_e;
              }

              /* End of Switch: '<S114>/Switch' */
              /* End of Outputs for SubSystem: '<S107>/ContourData' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S107>/NoData' incorporates:
               *  ActionPort: '<S118>/Action Port'
               */
              /* SignalConversion generated from: '<S118>/BrakingTorque' incorporates:
               *  Constant: '<S118>/Constant'
               */
              rtb_Product_c_idx_0 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_f;

              /* End of Outputs for SubSystem: '<S107>/NoData' */
              break;
            }

            /* End of SwitchCase: '<S107>/Switch Case1' */

            /* Product: '<S119>/Product' incorporates:
             *  Constant: '<S107>/PerformanceFactor'
             *  Fcn: '<S119>/Fcn'
             *  ForEachSliceSelector generated from: '<S2>/Overrides'
             *  Product: '<S107>/TorqueScaling'
             */
            rtb_Product_c_idx_0 = (rtu_Overrides[ForEachVehicle_itr].
              DynamicBrakeForceVariation / 100.0 + 1.0) * (rtb_Product_c_idx_0 *
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.PerformanceFactor_Value_h);

            /* RateLimiter: '<S107>/Rate Limiter' */
            rtb_Product3_f_idx_7 = rtb_Product_c_idx_0 - localDW->
              CoreSubsys_p[ForEachVehicle_itr].CoreSubsys_pnae[ForEachBogie_itr]
              .CoreSubsys_h[ForEach_itr].PrevY_j;
            if (rtb_Product3_f_idx_7 >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim_g)
            {
              rtb_Product_c_idx_0 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                PrevY_j +
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_RisingLim_g;
            } else {
              if (rtb_Product3_f_idx_7 <
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim_h)
              {
                rtb_Product_c_idx_0 = localDW->CoreSubsys_p[ForEachVehicle_itr].
                  CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
                  PrevY_j +
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.RateLimiter_FallingLim_h;
              }
            }

            localDW->CoreSubsys_p[ForEachVehicle_itr]
              .CoreSubsys_pnae[ForEachBogie_itr].CoreSubsys_h[ForEach_itr].
              PrevY_j = rtb_Product_c_idx_0;

            /* End of RateLimiter: '<S107>/Rate Limiter' */

            /* Switch: '<S106>/Switch2' incorporates:
             *  Constant: '<S106>/No Braking'
             *  Constant: '<S112>/Constant'
             *  Constant: '<S113>/Constant'
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             *  Gain: '<S105>/apply opposite to direction of movement'
             *  Logic: '<S106>/Logical Operator'
             *  Product: '<S105>/Force1'
             *  RelationalOperator: '<S112>/Compare'
             *  RelationalOperator: '<S113>/Compare'
             *  Signum: '<S105>/Sign'
             */
            if ((localB->CoreSubsys_p[ForEachVehicle_itr].
                 ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
                 .MotorNotAvailable[ForEach_itr] >
                 TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_p)
                ||
                (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd
                 ==
                 TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_g))
            {
              rtb_Product_c_idx_0 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoBraking_Value;
            } else {
              if (rtb_MaximumTractionEffortPossible_k < 0.0) {
                /* Signum: '<S105>/Sign' */
                rtb_Product3_f_idx_7 = -1.0;
              } else if (rtb_MaximumTractionEffortPossible_k > 0.0) {
                /* Signum: '<S105>/Sign' */
                rtb_Product3_f_idx_7 = 1.0;
              } else if (rtb_MaximumTractionEffortPossible_k == 0.0) {
                /* Signum: '<S105>/Sign' */
                rtb_Product3_f_idx_7 = 0.0;
              } else {
                /* Signum: '<S105>/Sign' */
                rtb_Product3_f_idx_7 = (rtNaN);
              }

              rtb_Product_c_idx_0 = rtb_Product_c_idx_0 * rtb_Product3_f_idx_2 *
                (TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.applyoppositetodirectionofmovement_Gain
                 * rtb_Product3_f_idx_7);
            }

            /* End of Switch: '<S106>/Switch2' */

            /* Sum: '<S105>/Add' */
            rtb_ImpAsg_InsertedFor_TractiveBrakingEffort_at_inport_0[ForEach_itr]
              = rtb_Product3_f_idx_6 + rtb_Product_c_idx_0;

            /* Product: '<S105>/Force2' */
            rtb_ImpAsg_InsertedFor_TractivePower_at_inport_0[ForEach_itr] =
              rtb_Product3_f_idx_6 * rtb_MaximumBrakingEffortPossible_p;

            /* Product: '<S105>/Force3' */
            rtb_ImpAsg_InsertedFor_DynamicBrakingPower_at_inport_0[ForEach_itr] =
              rtb_Product_c_idx_0 * rtb_MaximumBrakingEffortPossible_p;
            rtb_ImpAsg_InsertedFor_BrakingEffort_at_inport_0[ForEach_itr] =
              rtb_Product_c_idx_0;
            rtb_ImpAsg_InsertedFor_MotorSpeed_at_inport_0[ForEach_itr] =
              rtb_MaximumTractionEffortPossible_k;
            rtb_ImpAsg_InsertedFor_TractiveEffort_at_inport_0[ForEach_itr] =
              rtb_Product3_f_idx_6;

            /* End of Outputs for SubSystem: '<S103>/TractionMotorEnabled' */
          } else {
            /* Outputs for IfAction SubSystem: '<S103>/TractionMotorDisabled' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            rtb_ImpAsg_InsertedFor_TractiveBrakingEffort_at_inport_0[ForEach_itr]
              =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant_Value_az;
            rtb_ImpAsg_InsertedFor_TractiveEffort_at_inport_0[ForEach_itr] =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant1_Value_g;
            rtb_ImpAsg_InsertedFor_TractivePower_at_inport_0[ForEach_itr] =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant2_Value_l;
            rtb_ImpAsg_InsertedFor_BrakingEffort_at_inport_0[ForEach_itr] =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant4_Value;
            rtb_ImpAsg_InsertedFor_DynamicBrakingPower_at_inport_0[ForEach_itr] =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant3_Value_k;
            rtb_ImpAsg_InsertedFor_MotorSpeed_at_inport_0[ForEach_itr] =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.Constant5_Value;

            /* End of Outputs for SubSystem: '<S103>/TractionMotorDisabled' */
          }

          /* End of If: '<S103>/If' */
        }

        /* End of Outputs for SubSystem: '<S101>/TractionMotor' */

        /* Product: '<S100>/Product3' incorporates:
         *  Constant: '<S100>/Constant3'
         *  Gain: '<S100>/GearEfficiency'
         */
        rtb_Product3_f_idx_2 = rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractiveEffort_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_Product3_f_idx_6 = rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_BrakingEffort_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;

        /* Sum: '<S100>/Subtract' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  Gain: '<S100>/Gain1'
         *  Product: '<S100>/Product2'
         */
        rtb_Product_c_idx_0 = rtb_Product3_f_idx_2 -
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Gain1_Gain *
          rtb_Product3_f_idx_2 *
          rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          TCMS.TractiveLosses;

        /* Product: '<S100>/Product3' incorporates:
         *  Constant: '<S100>/Constant3'
         *  Gain: '<S100>/GearEfficiency'
         */
        rtb_Product3_f_idx_2 = rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractiveEffort_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_Product3_f_idx_7 = rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_BrakingEffort_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;

        /* Sum: '<S100>/Subtract' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  Gain: '<S100>/Gain1'
         *  Product: '<S100>/Product2'
         */
        rtb_Product_c_idx_1 = rtb_Product3_f_idx_2 -
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Gain1_Gain *
          rtb_Product3_f_idx_2 *
          rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          TCMS.TractiveLosses;

        /* Outputs for Iterator SubSystem: '<S102>/MotorVehicle' incorporates:
         *  ForEach: '<S143>/For Each'
         */
        for (ForEach_itr_e = 0; ForEach_itr_e < 2; ForEach_itr_e++) {
          /* If: '<S143>/If' incorporates:
           *  Constant: '<S102>/Constant'
           *  ForEachSliceSelector generated from: '<S143>/AxleHasMotor'
           */
          if (rtp_Prm_TractionSystem->AxleHasMotor[ForEach_itr_e] != 0.0) {
            /* Outputs for IfAction SubSystem: '<S143>/MotorAxle' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* Abs: '<S144>/Abs' incorporates:
             *  ForEachSliceSelector generated from: '<S143>/LinearWheelSpeed'
             *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
             *  ForEachSliceSelector generated from: '<S99>/BogieDynamics'
             */
            rtb_Product3_f_idx_2 = fabs
              (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
               Dynamics.Bogie[ForEachBogie_itr].WheelSpeed[ForEach_itr_e]);

            /* Logic: '<S144>/NOT' incorporates:
             *  ForEachSliceSelector generated from: '<S143>/MotorFailure'
             *  ForEachSliceSelector generated from: '<S99>/BogieTractionConverterControlIn'
             */
            rtb_LogicalOperator3 = !(localB->CoreSubsys_p[ForEachVehicle_itr].
              ImpAsg_InsertedFor_TractionConverterControl_at_inport_0[ForEachBogie_itr]
              .MotorNotAvailable[ForEach_itr_e] != 0.0);

            /* Saturate: '<S147>/Saturation1' */
            if (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_UpperSat)
            {
              rtb_TorqueScaling_o =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_UpperSat;
            } else if
                (rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity
                 <
                 TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_LowerSat)
            {
              rtb_TorqueScaling_o =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation1_LowerSat;
            } else {
              rtb_TorqueScaling_o =
                rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity;
            }

            /* End of Saturate: '<S147>/Saturation1' */

            /* Product: '<S147>/TorqueAvailable' incorporates:
             *  Constant: '<S147>/Constant1'
             */
            rtb_TorqueScaling_o *=
              rtp_Prm_TractionSystem->DesignMaxTractionTorque;

            /* Saturate: '<S148>/safedivide1' */
            if (rtb_Gain_f >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_UpperSat)
            {
              rtb_MaximumTractionEffortPossible_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_UpperSat;
            } else if (rtb_Gain_f <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_LowerSat)
            {
              rtb_MaximumTractionEffortPossible_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide1_LowerSat;
            } else {
              rtb_MaximumTractionEffortPossible_k = rtb_Gain_f;
            }

            /* End of Saturate: '<S148>/safedivide1' */

            /* Product: '<S148>/Pmax//v1' incorporates:
             *  Constant: '<S148>/Constant'
             */
            rtb_MaximumBrakingEffortPossible_p =
              rtp_Prm_TractionSystem->DesignGearingRatio /
              rtb_MaximumTractionEffortPossible_k;

            /* Product: '<S144>/Product1' */
            rtb_ConstantPower_k = rtb_Product3_f_idx_2 *
              rtb_MaximumBrakingEffortPossible_p;

            /* Saturate: '<S147>/Saturation3' */
            if (rtb_DataTypeConversion5 >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_UpperSat)
            {
              x_fraction_c1 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_UpperSat;
            } else if (rtb_DataTypeConversion5 <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_LowerSat)
            {
              x_fraction_c1 =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Saturation3_LowerSat;
            } else {
              x_fraction_c1 = rtb_DataTypeConversion5;
            }

            /* End of Saturate: '<S147>/Saturation3' */

            /* Saturate: '<S147>/safedivide' */
            if (rtb_ConstantPower_k >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat)
            {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat;
            } else if (rtb_ConstantPower_k <
                       TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat)
            {
              contour_fraction =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat;
            } else {
              contour_fraction = rtb_ConstantPower_k;
            }

            /* End of Saturate: '<S147>/safedivide' */

            /* Product: '<S147>/Pmax//v' incorporates:
             *  Constant: '<S147>/Constant2'
             *  Product: '<S147>/PowerAvailble'
             */
            x_fraction_c1 = rtp_Prm_TractionSystem->DesignMaxTractionPower *
              x_fraction_c1 / contour_fraction;

            /* MinMax: '<S147>/MinMax' */
            if ((rtb_TorqueScaling_o < x_fraction_c1) || rtIsNaN(x_fraction_c1))
            {
              x_fraction_c1 = rtb_TorqueScaling_o;
            }

            /* End of MinMax: '<S147>/MinMax' */

            /* Product: '<S144>/Product4' incorporates:
             *  DataTypeConversion: '<S144>/Data Type Conversion'
             *  Product: '<S144>/Product2'
             */
            rtb_MaximumTractionEffortPossible_k = x_fraction_c1 *
              rtb_MaximumBrakingEffortPossible_p * static_cast<real_T>
              (rtb_LogicalOperator3);

            /* ForEachSliceAssignment generated from: '<S143>/MaxTractionPowerPossible' incorporates:
             *  Product: '<S144>/Force2'
             */
            rtb_ImpAsg_InsertedFor_MaxTractionPowerPossible_at_inport_0[ForEach_itr_e]
              = rtb_MaximumTractionEffortPossible_k * rtb_Product3_f_idx_2;

            /* S-Function (sfix_look1_dyn): '<S149>/Lookup Table Dynamic' incorporates:
             *  Constant: '<S149>/Constant'
             *  Constant: '<S149>/Constant1'
             */
            /* Dynamic Look-Up Table Block: '<S149>/Lookup Table Dynamic'
             * Input0  Data Type:  Floating Point real_T
             * Input1  Data Type:  Floating Point real_T
             * Input2  Data Type:  Floating Point real_T
             * Output0 Data Type:  Floating Point real_T
             * Lookup Method: Linear_Endpoint
             *
             */
            LookUp_real_T_real_T( &(rtb_TorqueScaling_o),
                                 &TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant_Value
                                 [0], rtb_ConstantPower_k,
                                 &rtp_Prm_TractionSystem->BrakeFadeRampDownSpeeds
                                 [0], 1U);

            /* Product: '<S149>/Torque Scaling' incorporates:
             *  Constant: '<S146>/Constant1'
             */
            rtb_TorqueScaling_o *=
              rtp_Prm_TractionSystem->DesignMaxBrakingTorque;

            /* Saturate: '<S146>/safedivide' */
            if (rtb_ConstantPower_k >
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat_o)
            {
              rtb_ConstantPower_k =
                TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_UpperSat_o;
            } else {
              if (rtb_ConstantPower_k <
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat_d)
              {
                rtb_ConstantPower_k =
                  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.safedivide_LowerSat_d;
              }
            }

            /* End of Saturate: '<S146>/safedivide' */

            /* Product: '<S146>/Pmax//v' incorporates:
             *  Constant: '<S146>/Constant2'
             */
            rtb_ConstantPower_k = rtp_Prm_TractionSystem->DesignMaxBrakingPower /
              rtb_ConstantPower_k;

            /* MinMax: '<S146>/MinMax' */
            if ((rtb_TorqueScaling_o < rtb_ConstantPower_k) || rtIsNaN
                (rtb_ConstantPower_k)) {
              contour_fraction = rtb_TorqueScaling_o;
            } else {
              contour_fraction = rtb_ConstantPower_k;
            }

            /* End of MinMax: '<S146>/MinMax' */

            /* Product: '<S144>/Product3' */
            rtb_MaximumBrakingEffortPossible_p *= contour_fraction;

            /* Product: '<S144>/Product5' incorporates:
             *  DataTypeConversion: '<S144>/Data Type Conversion'
             */
            rtb_MaximumBrakingEffortPossible_p = static_cast<real_T>
              (rtb_LogicalOperator3) * rtb_MaximumBrakingEffortPossible_p *
              rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_TCMS_TCMSEDBrakingCmd;

            /* ForEachSliceAssignment generated from: '<S143>/MaxBrakingPowerPossible' incorporates:
             *  Product: '<S144>/Force3'
             */
            rtb_ImpAsg_InsertedFor_MaxBrakingPowerPossible_at_inport_0[ForEach_itr_e]
              = rtb_Product3_f_idx_2 * rtb_MaximumBrakingEffortPossible_p;

            /* ForEachSliceAssignment generated from: '<S143>/MaxBrakingEffortPossible' incorporates:
             *  SignalConversion generated from: '<S144>/MaximumBrakingEffortPossible'
             */
            rtb_ImpAsg_InsertedFor_MaxBrakingEffortPossible_at_inport_0[ForEach_itr_e]
              = rtb_MaximumBrakingEffortPossible_p;

            /* ForEachSliceAssignment generated from: '<S143>/MaximumTractionEffortPossible' incorporates:
             *  SignalConversion generated from: '<S144>/MaximumTractionEffortPossible'
             */
            rtb_ImpAsg_InsertedFor_MaximumTractionEffortPossible_at_inport_0[ForEach_itr_e]
              = rtb_MaximumTractionEffortPossible_k;

            /* End of Outputs for SubSystem: '<S143>/MotorAxle' */
          } else {
            /* Outputs for IfAction SubSystem: '<S143>/NoMotorAxle' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* ForEachSliceAssignment generated from: '<S143>/MaximumTractionEffortPossible' incorporates:
             *  Constant: '<S145>/Constant'
             *  SignalConversion generated from: '<S145>/MaximumTractionEffortPossible'
             */
            rtb_ImpAsg_InsertedFor_MaximumTractionEffortPossible_at_inport_0[ForEach_itr_e]
              =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant_Value_i;

            /* ForEachSliceAssignment generated from: '<S143>/MaxBrakingEffortPossible' incorporates:
             *  Constant: '<S145>/Constant1'
             *  SignalConversion generated from: '<S145>/MaximumBrakingEffortPossible'
             */
            rtb_ImpAsg_InsertedFor_MaxBrakingEffortPossible_at_inport_0[ForEach_itr_e]
              =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant1_Value;

            /* ForEachSliceAssignment generated from: '<S143>/MaxTractionPowerPossible' incorporates:
             *  Constant: '<S145>/Constant2'
             *  SignalConversion generated from: '<S145>/MaximumTractionPowerPossible'
             */
            rtb_ImpAsg_InsertedFor_MaxTractionPowerPossible_at_inport_0[ForEach_itr_e]
              =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant2_Value;

            /* ForEachSliceAssignment generated from: '<S143>/MaxBrakingPowerPossible' incorporates:
             *  Constant: '<S145>/Constant3'
             *  SignalConversion generated from: '<S145>/MaximumBrakingPowerPossible'
             */
            rtb_ImpAsg_InsertedFor_MaxBrakingPowerPossible_at_inport_0[ForEach_itr_e]
              =
              TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys.Constant3_Value;

            /* End of Outputs for SubSystem: '<S143>/NoMotorAxle' */
          }

          /* End of If: '<S143>/If' */
        }

        /* End of Outputs for SubSystem: '<S102>/MotorVehicle' */

        /* ForEachSliceAssignment generated from: '<S99>/BogieOutputs' incorporates:
         *  BusCreator: '<S99>/Bus Creator'
         */
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMotorSpeeds[0] = rtb_ImpAsg_InsertedFor_MotorSpeed_at_inport_0[0];

        /* ForEachSliceAssignment generated from: '<S99>/BogieForcesPerAxle' incorporates:
         *  BusCreator: '<S99>/Bus Creator1'
         *  Constant: '<S100>/Constant3'
         *  Gain: '<S100>/GearEfficiency'
         *  Product: '<S100>/Product3'
         */
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleTractionBrakingForce[0] =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractiveBrakingEffort_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleTractionForce[0] = rtb_Product_c_idx_0;
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleBrakingForce[0] = rtb_Product3_f_idx_6;

        /* ForEachSliceAssignment generated from: '<S99>/BogieOutputs' incorporates:
         *  BusCreator: '<S99>/Bus Creator'
         */
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMotorSpeeds[1] = rtb_ImpAsg_InsertedFor_MotorSpeed_at_inport_0[1];

        /* ForEachSliceAssignment generated from: '<S99>/BogieForcesPerAxle' incorporates:
         *  BusCreator: '<S99>/Bus Creator1'
         *  Constant: '<S100>/Constant3'
         *  Gain: '<S100>/GearEfficiency'
         *  Product: '<S100>/Product3'
         */
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleTractionBrakingForce[1] =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractiveBrakingEffort_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleTractionForce[1] = rtb_Product_c_idx_1;
        rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEachBogie_itr].
          AxleBrakingForce[1] = rtb_Product3_f_idx_7;

        /* ForEachSliceAssignment generated from: '<S99>/BogieOutputs' incorporates:
         *  Constant: '<S100>/Constant3'
         *  Gain: '<S100>/GearEfficiency'
         *  Gain: '<S100>/GearEfficiency1'
         *  Product: '<S100>/Product1'
         *  Product: '<S100>/Product3'
         *  Sum: '<S100>/Sum of Elements'
         *  Sum: '<S100>/Sum of Elements1'
         *  Sum: '<S100>/Sum of Elements2'
         *  Sum: '<S100>/Sum of Elements3'
         *  Sum: '<S100>/Sum of Elements4'
         *  Sum: '<S100>/Sum of Elements5'
         *  Sum: '<S100>/Sum of Elements6'
         *  Sum: '<S100>/Sum of Elements8'
         */
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieTractiveEffort = rtb_Product_c_idx_0 + rtb_Product_c_idx_1;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieDynamicBrakingEffort = rtb_Product3_f_idx_6 +
          rtb_Product3_f_idx_7;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMaxTractionEffortPossible =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaximumTractionEffortPossible_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaximumTractionEffortPossible_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMaxBrakingEffortPossible =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxBrakingEffortPossible_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxBrakingEffortPossible_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieTractivePower = rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractivePower_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_TractivePower_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieDynamicBrakingPower =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_DynamicBrakingPower_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_DynamicBrakingPower_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMaxTractionPowerPossible =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxTractionPowerPossible_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxTractionPowerPossible_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
        rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[ForEachBogie_itr].
          BogieMaxBrakingPowerPossible =
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxBrakingPowerPossible_at_inport_0[0] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value +
          rtp_Prm_TractionSystem->DesignGearingEfficiency *
          rtb_ImpAsg_InsertedFor_MaxBrakingPowerPossible_at_inport_0[1] *
          TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.Constant3_Value;
      }

      /* End of Outputs for SubSystem: '<S28>/BogieTractionConverterSystem (Per Bogie)' */

      /* Outputs for Iterator SubSystem: '<S29>/ForEachBogie' incorporates:
       *  ForEach: '<S31>/For Each'
       */
      for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
        /* MinMax: '<S31>/IfWheelSlipping' incorporates:
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S31>/BogieDynamics'
         */
        if ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
             .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[0] >
             rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
             .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[1]) || rtIsNaN
            (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
             .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[1])) {
          /* ForEachSliceAssignment generated from: '<S31>/BogieWheelSpeed' */
          rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[ForEach_itr_b] =
            rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
            .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[0];
        } else {
          /* ForEachSliceAssignment generated from: '<S31>/BogieWheelSpeed' */
          rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[ForEach_itr_b] =
            rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
            .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[1];
        }

        /* End of MinMax: '<S31>/IfWheelSlipping' */

        /* ForEachSliceAssignment generated from: '<S31>/BogieTractionBrakingPower' incorporates:
         *  Abs: '<S31>/Abs'
         *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
         *  ForEachSliceSelector generated from: '<S31>/BogieDynamics'
         *  ForEachSliceSelector generated from: '<S31>/BogieTraction'
         *  Product: '<S31>/Product'
         *  Sum: '<S31>/Sum of Elements'
         */
        rtb_ImpAsg_InsertedFor_BogieTractionBrakingPower_at_inport_0[ForEach_itr_b]
          = rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_b]
          .AxleTractionBrakingForce[0] * fabs
          (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
           .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[0]) +
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_b].
          AxleTractionBrakingForce[1] * fabs
          (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr]
           .Dynamics.Bogie[ForEach_itr_b].WheelSpeed[1]);
      }

      /* End of Outputs for SubSystem: '<S29>/ForEachBogie' */

      /* CombinatorialLogic: '<S97>/Logic' incorporates:
       *  ForEachSliceSelector generated from: '<S2>/Faults'
       *  ForEachSliceSelector generated from: '<S2>/TractionInputs'
       *  Logic: '<S36>/AND'
       *  Logic: '<S36>/AND2'
       *  Logic: '<S36>/Logical Operator1'
       *  Logic: '<S36>/Logical Operator4'
       *  Logic: '<S36>/Logical Operator6'
       *  Memory: '<S97>/Memory'
       *  UnitDelay: '<S36>/Unit Delay'
       */
      high_i = static_cast<int32_T>(((((static_cast<uint32_T>
        ((rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          ElectricalSystem.VCBState && (!localDW->
        CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE_p))) << 1) +
        ((!(rtu_Faults[ForEachVehicle_itr].CIAKOpenFailure != 0.0)) &&
         (rtu_TractionSystemVehicleInputs[ForEachVehicle_itr].
          ElectricalSystem.ContactorsFailure || localDW->
          CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE_p))) << 1) +
        localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput_o));

      /* SignalConversion generated from: '<S30>/Assignment' incorporates:
       *  Constant: '<S30>/Constant'
       */
      for (i = 0; i < 6; i++) {
        rtb_TractionBrakingForce[i] =
          TractionSystem_P.CoreSubsys_p.Constant_Value[i];
      }

      /* End of SignalConversion generated from: '<S30>/Assignment' */

      /* Outputs for Iterator SubSystem: '<S30>/For Each Subsystem' incorporates:
       *  ForEach: '<S32>/For Each'
       */
      for (ForEach_itr_f = 0; ForEach_itr_f < 2; ForEach_itr_f++) {
        /* ForEachSliceAssignment generated from: '<S32>/TractionForce' incorporates:
         *  ForEachSliceAssignment generated from: '<S32>/BrakingForce'
         *  ForEachSliceAssignment generated from: '<S32>/TractionBrakingForce'
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        i = ForEach_itr_f << 1;
        rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleTractionForce[0];

        /* ForEachSliceAssignment generated from: '<S32>/TractionBrakingForce' incorporates:
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        rtb_TractionBrakingForce[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleTractionBrakingForce[0];

        /* ForEachSliceAssignment generated from: '<S32>/BrakingForce' incorporates:
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleBrakingForce[0];

        /* ForEachSliceAssignment generated from: '<S32>/TractionForce' incorporates:
         *  ForEachSliceAssignment generated from: '<S32>/BrakingForce'
         *  ForEachSliceAssignment generated from: '<S32>/TractionBrakingForce'
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        i++;
        rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleTractionForce[1];

        /* ForEachSliceAssignment generated from: '<S32>/TractionBrakingForce' incorporates:
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        rtb_TractionBrakingForce[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleTractionBrakingForce[1];

        /* ForEachSliceAssignment generated from: '<S32>/BrakingForce' incorporates:
         *  ForEachSliceSelector generated from: '<S32>/In1'
         */
        rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[i] =
          rtb_ImpAsg_InsertedFor_BogieForcesPerAxle_at_inport_0[ForEach_itr_f].
          AxleBrakingForce[1];
      }

      /* End of Outputs for SubSystem: '<S30>/For Each Subsystem' */
      for (i = 0; i < 6; i++) {
        /* SignalConversion generated from: '<S30>/Assignment1' incorporates:
         *  Constant: '<S30>/Constant'
         */
        rtb_TractionForce[i] = TractionSystem_P.CoreSubsys_p.Constant_Value[i];

        /* SignalConversion generated from: '<S30>/Assignment2' incorporates:
         *  Constant: '<S30>/Constant'
         */
        rtb_BrakingForce[i] = TractionSystem_P.CoreSubsys_p.Constant_Value[i];
      }

      /* Assignment: '<S30>/Assignment1' */
      rtb_TractionForce[0] = rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[0];
      rtb_TractionForce[1] = rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[1];
      rtb_TractionForce[2] = rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[2];
      rtb_TractionForce[3] = rtb_ImpAsg_InsertedFor_TractionForce_at_inport_0[3];

      /* Assignment: '<S30>/Assignment2' */
      rtb_BrakingForce[0] = rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[0];
      rtb_BrakingForce[1] = rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[1];
      rtb_BrakingForce[2] = rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[2];
      rtb_BrakingForce[3] = rtb_ImpAsg_InsertedFor_BrakingForce_at_inport_0[3];

      /* BusAssignment: '<S26>/Bus Assignment' incorporates:
       *  BusAssignment: '<S37>/Bus Assignment2'
       *  BusAssignment: '<S38>/Bus Assignment2'
       *  BusAssignment: '<S39>/Bus Assignment1'
       *  BusCreator: '<S30>/Bus Creator'
       *  CombinatorialLogic: '<S97>/Logic'
       *  Constant: '<S26>/Constant1'
       *  DataTypeConversion: '<S36>/Data Type Conversion1'
       *  DataTypeConversion: '<S36>/Data Type Conversion3'
       *  DataTypeConversion: '<S36>/Data Type Conversion4'
       *  DataTypeConversion: '<S36>/Data Type Conversion5'
       *  ForEachSliceSelector generated from: '<S2>/Faults'
       *  Logic: '<S36>/Logical Operator3'
       *  Product: '<S36>/Product3'
       *  Sum: '<S29>/Sum of Elements'
       */
      localB->CoreSubsys_p[ForEachVehicle_itr].BusAssignment =
        TractionSystem_P.CoreSubsys_p.Constant1_Value;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.ElectricalSystem.TractionContactorStatus =
        rtb_Logic_idx_0;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.TCMS.Trafo_TCU.TCU_KStatus =
        rtb_Logic_idx_0;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.TCMS.Trafo_TCU.TCU_AKStatus =
        TractionSystem_P.CoreSubsys_p.Logic_table_f[static_cast<uint32_T>(high_i)];
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.TCMS.Trafo_TCU.FilterVoltage =
        static_cast<real_T>((TractionSystem_P.CoreSubsys_p.Logic_table_f[
        static_cast<uint32_T>(high_i)] || rtb_Logic_idx_0)) * rtb_FilterVoltage;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.TCMS.VehicleDerailed =
        rtu_Faults[ForEachVehicle_itr].DerailmentDetectedRightSide;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.TCMS.VehicleBogieDerailed =
        rtu_Faults[ForEachVehicle_itr].BogieDerailed;
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.ElectricalSystem.Bogie[0] =
        rtb_ImpAsg_InsertedFor_TCUtoElectricalOutputs_at_inport_0[0];
      memcpy(&localB->CoreSubsys_p[ForEachVehicle_itr].
             BusAssignment.TractionControl.TCMS.Bogie[0],
             &rtb_ImpAsg_InsertedFor_TCUtoTCMSOutputs_at_inport_0[0], sizeof
             (BD_TractionSystem_Out_Vehicle_TCMS_Bogie) << 1U);
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.BCU.Bogie[0] =
        rtb_ImpAsg_InsertedFor_TCUToBCUOutputs_at_inport_0[0];
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.ElectricalSystem.Bogie[1] =
        rtb_ImpAsg_InsertedFor_TCUtoElectricalOutputs_at_inport_0[1];
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.TractionControl.BCU.Bogie[1] =
        rtb_ImpAsg_InsertedFor_TCUToBCUOutputs_at_inport_0[1];
      for (i = 0; i < 6; i++) {
        localB->CoreSubsys_p[ForEachVehicle_itr].
          BusAssignment.Dynamics.TractionBrakingForce[i] =
          rtb_TractionBrakingForce[i];
        localB->CoreSubsys_p[ForEachVehicle_itr].
          BusAssignment.Dynamics.TractionForce[i] = rtb_TractionForce[i];
        localB->CoreSubsys_p[ForEachVehicle_itr].
          BusAssignment.Dynamics.BrakingForce[i] = rtb_BrakingForce[i];
      }

      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.Audio.TractionEDPower =
        rtb_ImpAsg_InsertedFor_BogieTractionBrakingPower_at_inport_0[0] +
        rtb_ImpAsg_InsertedFor_BogieTractionBrakingPower_at_inport_0[1];

      /* MinMax: '<S29>/IfWheelSlipping' */
      if ((rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[0] >
           rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[1]) || rtIsNaN
          (rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[1])) {
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
          rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[0];
      } else {
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity =
          rtb_ImpAsg_InsertedFor_BogieWheelSpeed_at_inport_0[1];
      }

      /* End of MinMax: '<S29>/IfWheelSlipping' */

      /* BusAssignment: '<S26>/Bus Assignment' incorporates:
       *  Constant: '<S29>/Constant'
       *  Gain: '<S29>/Gain'
       *  Product: '<S29>/Product'
       */
      localB->CoreSubsys_p[ForEachVehicle_itr].
        BusAssignment.Audio.WheelAngularVelocity =
        rtb_ImpSel_InsertedFor_TractionInputs_at_outport_0_Dynamics_Velocity /
        (TractionSystem_P.CoreSubsys_p.Gain_Gain *
         rtp_Prm_TractionSystem->DesignWheelDiameter);

      /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
       *  CombinatorialLogic: '<S97>/Logic'
       *  DataTypeConversion: '<S36>/Data Type Conversion1'
       */
      localDW->CoreSubsys_p[ForEachVehicle_itr].DiscreteTimeIntegrator_DSTATE +=
        TractionSystem_P.CoreSubsys_p.DiscreteTimeIntegrator_gainval *
        static_cast<real_T>(TractionSystem_P.CoreSubsys_p.Logic_table_f[
                            static_cast<uint32_T>(high_i)]);

      /* Update for UnitDelay: '<S36>/Unit Delay' */
      localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE_p =
        rtb_Logic_idx_0;

      /* Update for Memory: '<S98>/Memory' */
      localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput =
        rtb_Logic_idx_0;

      /* Update for UnitDelay: '<S25>/Unit Delay' */
      memcpy(&localDW->CoreSubsys_p[ForEachVehicle_itr].UnitDelay_DSTATE[0],
             &rtb_ImpAsg_InsertedFor_BogieOutputs_at_inport_0[0], sizeof
             (BD_TractionSystem_Int_BogieOutputs) << 1U);

      /* Update for Memory: '<S97>/Memory' incorporates:
       *  CombinatorialLogic: '<S97>/Logic'
       */
      localDW->CoreSubsys_p[ForEachVehicle_itr].Memory_PreviousInput_o =
        TractionSystem_P.CoreSubsys_p.Logic_table_f[static_cast<uint32_T>(high_i)];
    }

    /* End of Logic: '<S2>/AND' */
    /* End of Outputs for SubSystem: '<S2>/MotorVehicle' */

    /* ForEachSliceAssignment generated from: '<S2>/TractionSystemOut' */
    rty_TractionSystemOut[ForEachVehicle_itr] = localB->
      CoreSubsys_p[ForEachVehicle_itr].BusAssignment;
  }

  /* End of Outputs for SubSystem: '<Root>/Traction (Per Vehicle)' */
}

/* Model initialize function */
void TractionSystem_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_TractionSystem_T *
  const TractionSystem_M, B_TractionSystem_c_T *localB, DW_TractionSystem_f_T
  *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath,
  int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value =
    rtInf;
  TractionSystem_P.CoreSubsys_p.CoreSubsys_pnae.CoreSubsys_h.NoLimit_Value_o =
    rtInf;
  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat = rtInf;
  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.min0_UpperSat_f = rtInf;
  TractionSystem_P.CoreSubsys_p.CoreSubsys_pna.Saturation_UpperSat = rtInf;

  /* setup the global timing engine */
  TractionSystem_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
  TractionSystem_M->timingBridge = (timingBridge);

  /* initialize error status */
  rtmSetErrorStatusPointer(TractionSystem_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_TractionSystem_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_TractionSystem_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    TractionSystem_InitializeDataMapInfo(TractionSystem_M, localB);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(TractionSystem_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(TractionSystem_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(TractionSystem_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
