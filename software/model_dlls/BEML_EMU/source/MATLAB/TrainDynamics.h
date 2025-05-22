/*
 * Code generation for system model 'TrainDynamics'
 * For more details, see corresponding source file TrainDynamics.c
 *
 */

#ifndef RTW_HEADER_TrainDynamics_h_
#define RTW_HEADER_TrainDynamics_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef TrainDynamics_COMMON_INCLUDES_
# define TrainDynamics_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* TrainDynamics_COMMON_INCLUDES_ */

#include "TrainDynamics_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_assert.h"
#include "rtGetInf.h"

/* Block signals for system '<S142>/Braking Force Per Axle' */
typedef struct {
  real_T ForcePerAxle[6];              /* '<S142>/Braking Force Per Axle' */
} B_BrakingForcePerAxle_TrainDynamics_T;

/* Block signals for system '<S144>/AxleModel' */
typedef struct {
  BD_TrainDynamics_Out_Vehicle_Wheel BusCreator;/* '<S152>/Bus Creator' */
  real_T v;                            /* '<S155>/Product' */
  real_T DataTypeConversion2;          /* '<S151>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<S151>/Data Type Conversion3' */
  real_T Switch5;                      /* '<S151>/Switch5' */
  real_T WheelSpeed;                   /* '<S151>/VehicleSpeedandDelta' */
} B_CoreSubsys_TrainDynamics_k_T;

/* Block states (default storage) for system '<S144>/AxleModel' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S151>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S156>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_k;       /* '<S151>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S155>/Unit Delay1' */
  boolean_T IC_FirstOutputTime;        /* '<S156>/IC' */
  boolean_T AxleModelEnabled_MODE;     /* '<S148>/AxleModelEnabled' */
} DW_CoreSubsys_TrainDynamics_b_T;

/* Block signals for system '<S161>/Dynamic Track Adhesion Variation' */
typedef struct {
  real_T Output;                 /* '<S161>/Dynamic Track Adhesion Variation' */
} B_DynamicTrackAdhesionVariation_TrainDynamics_T;

/* Block signals for system '<S161>/Sanding Dynamic Track Adhesion Variation' */
typedef struct {
  real_T Output;         /* '<S161>/Sanding Dynamic Track Adhesion Variation' */
} B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T;

/* Block signals for system '<S13>/UpdateMimicPerCoupler' */
typedef struct {
  BD_CouplerMimic_InterfaceData BusAssignment;/* '<S121>/Bus Assignment' */
} B_CoreSubsys_TrainDynamics_ks_T;

/* Block states (default storage) for system '<S13>/UpdateMimicPerCoupler' */
typedef struct {
  real_T TappedDelay_X[10];            /* '<S122>/Tapped Delay' */
  boolean_T UpdateMimicOutputs_MODE;   /* '<S119>/UpdateMimicOutputs' */
} DW_CoreSubsys_TrainDynamics_bk_T;

/* Block signals for system '<S55>/MimicModelPerCoupler' */
typedef struct {
  BD_CouplerMimic_Out_Dynamics BusCreator;/* '<S90>/Bus Creator' */
  boolean_T External1;                 /* '<S89>/External1' */
} B_CoreSubsys_TrainDynamics_ks3_T;

/* Block states (default storage) for system '<S55>/MimicModelPerCoupler' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S117>/Delay Input1' */
  real_T UnitDelay_DSTATE;             /* '<S118>/Unit Delay' */
  real_T PreviousVelocity_DSTATE;      /* '<S93>/PreviousVelocity' */
  real_T IntegratedVelocity_DSTATE;    /* '<S97>/IntegratedVelocity' */
  real_T UnitDelay_DSTATE_f;           /* '<S106>/Unit Delay' */
  real_T IntegratedPosition_DSTATE;    /* '<S96>/IntegratedPosition' */
  real_T Timer_DSTATE;                 /* '<S104>/Timer' */
  int8_T IntegratedVelocity_PrevResetState;/* '<S97>/IntegratedVelocity' */
  int8_T IntegratedPosition_PrevResetState;/* '<S96>/IntegratedPosition' */
  int8_T Timer_PrevResetState;         /* '<S104>/Timer' */
  uint8_T IntegratedVelocity_IC_LOADING;/* '<S97>/IntegratedVelocity' */
  uint8_T IntegratedVelocity_SYSTEM_ENABLE;/* '<S97>/IntegratedVelocity' */
  uint8_T IntegratedPosition_IC_LOADING;/* '<S96>/IntegratedPosition' */
  uint8_T IntegratedPosition_SYSTEM_ENABLE;/* '<S96>/IntegratedPosition' */
  boolean_T MimicModelEnabled_MODE;    /* '<S88>/MimicModelEnabled' */
} DW_CoreSubsys_TrainDynamics_bkw_T;

/* Zero-crossing (trigger) state for system '<S55>/MimicModelPerCoupler' */
typedef struct {
  ZCSigState ExternalCouplingLogic_Trig_ZCE;/* '<S88>/ExternalCouplingLogic' */
} ZCE_CoreSubsys_TrainDynamics_f00w_T;

/* Block signals for system '<S57>/CouplerForcesPerCoupler' */
typedef struct {
  real_T Gain;                         /* '<S67>/Gain' */
  real_T Gain1;                        /* '<S63>/Gain1' */
  real_T Limit;                        /* '<S60>/Limit' */
  real_T Merge;                        /* '<S66>/Merge' */
  real_T DataTypeConversion1;          /* '<S62>/Data Type Conversion1' */
  real_T Saturation;                   /* '<S64>/Saturation' */
  real_T Saturation1;                  /* '<S64>/Saturation1' */
} B_CoreSubsys_TrainDynamics_ks3z_T;

/* Block states (default storage) for system '<S57>/CouplerForcesPerCoupler' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S79>/Discrete-Time Integrator' */
  boolean_T DelayInput1_DSTATE;        /* '<S76>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S79>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S79>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput;      /* '<S70>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S79>/IC' */
  boolean_T CouplerForces_MODE;        /* '<S58>/CouplerForces' */
} DW_CoreSubsys_TrainDynamics_bkw1_T;

/* Block signals for system '<Root>/Train Dynamics' */
typedef struct {
  BD_TrainDynamics_Cfg_Vehicle BusCreator1;/* '<S15>/Bus Creator1' */
  BD_TrainDynamics_Out_Coupler UnitDelay1[2];/* '<S11>/Unit Delay1' */
  BD_TrainDynamics_Out_Coupler
    TmpSignalConversionAtUpdateMimicPerCouplerInport5[2];
  BD_TrainDynamics_Out_Coupler ImpAsg_InsertedFor_Coupler_Out_at_inport_0[2];/* '<S58>/Bus Creator' */
  BD_TrainDynamics_Out_Vehicle_Wheel ImpAsg_InsertedFor_Wheel_Out_at_inport_0[6];/* '<S148>/PackWheelOutputs' */
  BD_CouplerMimic_Out_Dynamics
    ImpAsg_InsertedFor_MimicModelDynamicsOut_at_inport_0[2];/* '<S88>/MimicModelEnabled' */
  real_T Integrator;                   /* '<S125>/Integrator' */
  real_T CouplerSeparation[2];         /* '<S54>/CouplerSeparation' */
  real_T CouplerSeparationRate[2];     /* '<S54>/CouplerSeparationRate' */
  real_T FrontVehicleMass[2];          /* '<S54>/FrontVehicleMass' */
  real_T BackVehicleMass[2];           /* '<S54>/BackVehicleMass' */
  real_T FrontMovingForce[2];          /* '<S54>/FrontMovingForce' */
  real_T BackMovingForce[2];           /* '<S54>/BackMovingForce' */
  real_T VectorConcatenate[5];         /* '<S129>/Vector Concatenate' */
  real_T Position;                     /* '<S135>/PositionIntegrator' */
  real_T VectorConcatenate_k[2];       /* '<S13>/Vector Concatenate' */
  real_T ImpAsg_InsertedFor_MechanicallyCoupled_at_inport_0[2];
  real_T Merge[2];                     /* '<S83>/Merge' */
  real_T DataTypeConversion[6];        /* '<S141>/Data Type Conversion' */
  real_T BrakingForce[6];              /* '<S143>/BrakingForce' */
  real_T DrivingForce[6];              /* '<S142>/Add' */
  real_T BrakePower[6];                /* '<S143>/BrakePower' */
  real_T Add[6];                       /* '<S144>/Add' */
  real_T Assignment[6];                /* '<S150>/Assignment' */
  real_T ForcePerAxle[6];         /* '<S142>/Lateral Friction Force Per Axle' */
  boolean_T EnableCouplerForceCalc[2]; /* '<S59>/EnableCouplerForceCalc' */
  boolean_T ImpAsg_InsertedFor_ExternalCoupling_at_inport_0[2];/* '<S88>/ExternalCouplingLogic' */
  B_CoreSubsys_TrainDynamics_ks3z_T CoreSubsys_ixb[2];/* '<S57>/CouplerForcesPerCoupler' */
  B_CoreSubsys_TrainDynamics_ks3_T CoreSubsys_ix[2];/* '<S55>/MimicModelPerCoupler' */
  B_CoreSubsys_TrainDynamics_ks_T CoreSubsys_i[2];/* '<S13>/UpdateMimicPerCoupler' */
  B_DynamicTrackAdhesionVariation_TrainDynamics_T
    sf_StaticTrackAdhesionVariation_j;
                                  /* '<S162>/Static Track Adhesion Variation' */
  B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T
    sf_SandingStaticTrackAdhesionVariation_m;
                          /* '<S162>/Sanding Static Track Adhesion Variation' */
  B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T
    sf_SandingDynamicTrackAdhesionVariation_c;
                         /* '<S162>/Sanding Dynamic Track Adhesion Variation' */
  B_DynamicTrackAdhesionVariation_TrainDynamics_T
    sf_DynamicTrackAdhesionVariation_p;
                                 /* '<S162>/Dynamic Track Adhesion Variation' */
  B_DynamicTrackAdhesionVariation_TrainDynamics_T
    sf_StaticTrackAdhesionVariation;
                                  /* '<S161>/Static Track Adhesion Variation' */
  B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T
    sf_SandingStaticTrackAdhesionVariation;
                          /* '<S161>/Sanding Static Track Adhesion Variation' */
  B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T
    sf_SandingDynamicTrackAdhesionVariation;
                         /* '<S161>/Sanding Dynamic Track Adhesion Variation' */
  B_DynamicTrackAdhesionVariation_TrainDynamics_T
    sf_DynamicTrackAdhesionVariation;
                                 /* '<S161>/Dynamic Track Adhesion Variation' */
  B_CoreSubsys_TrainDynamics_k_T CoreSubsys[6];/* '<S144>/AxleModel' */
  B_BrakingForcePerAxle_TrainDynamics_T sf_ReactionForcePerAxle;/* '<S142>/Reaction Force Per Axle' */
  B_BrakingForcePerAxle_TrainDynamics_T sf_BrakingForcePerAxle;/* '<S142>/Braking Force Per Axle' */
} B_CoreSubsys_TrainDynamics_c_T;

/* Block states (default storage) for system '<Root>/Train Dynamics' */
typedef struct {
  BD_TrainDynamics_Out_Coupler UnitDelay1_DSTATE[2];/* '<S11>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S14>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S125>/Integrator' */
  real_T UD_DSTATE;                    /* '<S172>/UD' */
  real_T VelocityIntegrator_DSTATE;    /* '<S136>/VelocityIntegrator' */
  real_T PositionIntegrator_DSTATE;    /* '<S135>/PositionIntegrator' */
  real_T UD_DSTATE_l;                  /* '<S137>/UD' */
  void* Assertion_slioAccessor;        /* '<S34>/Assertion' */
  int8_T PositionIntegrator_PrevResetState;/* '<S135>/PositionIntegrator' */
  uint8_T VelocityIntegrator_IC_LOADING;/* '<S136>/VelocityIntegrator' */
  uint8_T PositionIntegrator_IC_LOADING;/* '<S135>/PositionIntegrator' */
  uint8_T PositionIntegrator_SYSTEM_ENABLE;/* '<S135>/PositionIntegrator' */
  boolean_T CouplerForcesEnabledCar_MODE;/* '<S56>/CouplerForcesEnabledCar' */
  boolean_T LongitudinalWheelForce_MODE;/* '<S14>/Longitudinal Wheel Force' */
  DW_CoreSubsys_TrainDynamics_bkw1_T CoreSubsys_ixb[2];/* '<S57>/CouplerForcesPerCoupler' */
  DW_CoreSubsys_TrainDynamics_bkw_T CoreSubsys_ix[2];/* '<S55>/MimicModelPerCoupler' */
  DW_CoreSubsys_TrainDynamics_bk_T CoreSubsys_i[2];/* '<S13>/UpdateMimicPerCoupler' */
  DW_CoreSubsys_TrainDynamics_b_T CoreSubsys[6];/* '<S144>/AxleModel' */
} DW_CoreSubsys_TrainDynamics_f_T;

/* Zero-crossing (trigger) state for system '<Root>/Train Dynamics' */
typedef struct {
  ZCE_CoreSubsys_TrainDynamics_f00w_T CoreSubsys_ix[2];/* '<S55>/MimicModelPerCoupler' */
} ZCE_CoreSubsys_TrainDynamics_f_T;

/* Block signals for model 'TrainDynamics' */
typedef struct {
  BD_TrainDynamics_VehicleCouplingData UnitDelay[8];/* '<Root>/Unit Delay' */
  real_T RunInit;                      /* '<S2>/Data Type Conversion' */
  real_T y[8];                         /* '<S6>/Initial Positions' */
  int32_T ForEach;                     /* '<S4>/For Each' */
  B_CoreSubsys_TrainDynamics_c_T CoreSubsys_p[8];/* '<Root>/Train Dynamics' */
} B_TrainDynamics_c_T;

/* Block states (default storage) for model 'TrainDynamics' */
typedef struct {
  BD_TrainDynamics_VehicleCouplingData UnitDelay_DSTATE[8];/* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  DW_CoreSubsys_TrainDynamics_f_T CoreSubsys_p[8];/* '<Root>/Train Dynamics' */
} DW_TrainDynamics_f_T;

/* Zero-crossing (trigger) state for model 'TrainDynamics' */
typedef struct {
  ZCE_CoreSubsys_TrainDynamics_f_T CoreSubsys_p[8];/* '<Root>/Train Dynamics' */
} ZCE_TrainDynamics_T;

/* Parameters for system: '<S144>/AxleModel' */
struct P_CoreSubsys_TrainDynamics_f_T_ {
  real_T SnapToZero_threshold;         /* Mask Parameter: SnapToZero_threshold
                                        * Referenced by: '<S157>/Switch2'
                                        */
  BD_TrainDynamics_Out_Vehicle_Wheel Wheel_Out_Y0;/* Computed Parameter: Wheel_Out_Y0
                                                   * Referenced by: '<S152>/Wheel_Out'
                                                   */
  real_T FrictionForce1_Value;         /* Expression: 0
                                        * Referenced by: '<S153>/Friction Force1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S151>/Gain'
                                        */
  real_T NoAdditionalForce_Value;      /* Expression: 0
                                        * Referenced by: '<S155>/No AdditionalForce'
                                        */
  real_T MomentOfInertia_Value;        /* Expression: 2000
                                        * Referenced by: '<S155>/MomentOfInertia'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S156>/Weighted Sample Time'
                                   */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S159>/Gain4'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S159>/Switch2'
                                        */
  real_T AxleLongitudinalForce_Y0;
                                 /* Computed Parameter: AxleLongitudinalForce_Y0
                                  * Referenced by: '<S151>/Axle Longitudinal Force'
                                  */
  real_T AxleSpeed_Y0;                 /* Computed Parameter: AxleSpeed_Y0
                                        * Referenced by: '<S151>/Axle Speed'
                                        */
  real_T AxleSpeedDelta_Y0;            /* Computed Parameter: AxleSpeedDelta_Y0
                                        * Referenced by: '<S151>/Axle Speed Delta'
                                        */
  real_T AxleSlipping_Y0;              /* Computed Parameter: AxleSlipping_Y0
                                        * Referenced by: '<S151>/Axle Slipping'
                                        */
  real_T AxleSkidding_Y0;              /* Computed Parameter: AxleSkidding_Y0
                                        * Referenced by: '<S151>/Axle Skidding'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S158>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: inf
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: Inf
                                        * Referenced by: '<S155>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.01
                                        * Referenced by: '<S155>/Saturation'
                                        */
  real_T BrakingDeltaLimit_Gain;       /* Expression: -1
                                        * Referenced by: '<S159>/BrakingDeltaLimit'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S159>/Switch3'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S156>/IC'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S151>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S156>/Unit Delay1'
                                        */
  boolean_T UnitDelay1_InitialCondition_a;
                            /* Computed Parameter: UnitDelay1_InitialCondition_a
                             * Referenced by: '<S151>/Unit Delay1'
                             */
  boolean_T UnitDelay1_InitialCondition_f;
                            /* Computed Parameter: UnitDelay1_InitialCondition_f
                             * Referenced by: '<S155>/Unit Delay1'
                             */
};

/* Parameters for system: '<S13>/UpdateMimicPerCoupler' */
struct P_CoreSubsys_TrainDynamics_fx_T_ {
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S122>/Tapped Delay'
                                        */
  real_T WMAV10_weights[10];           /* Mask Parameter: WMAV10_weights
                                        * Referenced by: '<S122>/Constant'
                                        */
  BD_CouplerMimic_InterfaceData MimicModelOut_Y0;/* Computed Parameter: MimicModelOut_Y0
                                                  * Referenced by: '<S121>/MimicModelOut'
                                                  */
  BD_CouplerMimic_InterfaceData Mimic_Value;/* Computed Parameter: Mimic_Value
                                             * Referenced by: '<S121>/Mimic'
                                             */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S123>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1.0
                                        * Referenced by: '<S123>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T TimeAtOutput_WtEt;            /* Computed Parameter: TimeAtOutput_WtEt
                                        * Referenced by: '<S121>/TimeAtOutput'
                                        */
};

/* Parameters for system: '<S55>/MimicModelPerCoupler' */
struct P_CoreSubsys_TrainDynamics_fxp_T_ {
  real_T LatchDT_InitialCondition;   /* Mask Parameter: LatchDT_InitialCondition
                                      * Referenced by: '<S118>/Unit Delay'
                                      */
  real_T LatchMovement_InitialCondition;
                               /* Mask Parameter: LatchMovement_InitialCondition
                                * Referenced by: '<S106>/Unit Delay'
                                */
  real_T UpdateTimeout_UpperSaturationLimit;
                           /* Mask Parameter: UpdateTimeout_UpperSaturationLimit
                            * Referenced by: '<S104>/Timer'
                            */
  real_T OursIs12_const;               /* Mask Parameter: OursIs12_const
                                        * Referenced by: '<S112>/Constant'
                                        */
  real_T OursIs1_const;                /* Mask Parameter: OursIs1_const
                                        * Referenced by: '<S111>/Constant'
                                        */
  real_T TheirsIs1_const;              /* Mask Parameter: TheirsIs1_const
                                        * Referenced by: '<S113>/Constant'
                                        */
  real_T TheirsIs12_const;             /* Mask Parameter: TheirsIs12_const
                                        * Referenced by: '<S114>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S117>/Delay Input1'
                                        */
  BD_CouplerMimic_Out_Dynamics MimicModelDynamicsOut_Y0;
                                 /* Computed Parameter: MimicModelDynamicsOut_Y0
                                  * Referenced by: '<S90>/MimicModelDynamicsOut'
                                  */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S92>/Gain'
                                        */
  real_T ZeroAcceleration_Value;       /* Expression: 0
                                        * Referenced by: '<S95>/ZeroAcceleration'
                                        */
  real_T ZeroVelocity_Value;           /* Expression: 0
                                        * Referenced by: '<S97>/ZeroVelocity'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S105>/Constant'
                                        */
  real_T Timer_gainval;                /* Computed Parameter: Timer_gainval
                                        * Referenced by: '<S104>/Timer'
                                        */
  real_T Timer_IC;                     /* Expression: 0
                                        * Referenced by: '<S104>/Timer'
                                        */
  real_T Timer_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S104>/Timer'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S110>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Limit_Threshold;              /* Expression: 1
                                        * Referenced by: '<S116>/Limit'
                                        */
  real_T MimicModelDebugOut_Y0;        /* Expression: 0
                                        * Referenced by: '<S90>/MimicModelDebugOut'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S100>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S102>/Constant'
                                        */
  real_T UseMimic_Value;               /* Expression: 1
                                        * Referenced by: '<S90>/UseMimic'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S110>/Constant'
                                        */
  real_T Drag_Coefs[3];                /* Expression: [ 0.4225, 31.33, 580.81]
                                        * Referenced by: '<S92>/Drag'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S92>/Switch'
                                        */
  real_T AccGravity_Gain;              /* Expression: -9.81
                                        * Referenced by: '<S92>/AccGravity'
                                        */
  real_T MassLimit_UpperSat;           /* Expression: 1e06
                                        * Referenced by: '<S94>/MassLimit'
                                        */
  real_T MassLimit_LowerSat;           /* Expression: 1e04
                                        * Referenced by: '<S94>/MassLimit'
                                        */
  real_T Constant_Value_m4;            /* Expression: 1
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T PreviousVelocity_InitialCondition;/* Expression: 0
                                            * Referenced by: '<S93>/PreviousVelocity'
                                            */
  real_T SafeDivide_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S95>/SafeDivide'
                                        */
  real_T SafeDivide_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S95>/SafeDivide'
                                        */
  real_T SanityLimit_UpperSat;         /* Expression: 100
                                        * Referenced by: '<S95>/SanityLimit'
                                        */
  real_T SanityLimit_LowerSat;         /* Expression: -100
                                        * Referenced by: '<S95>/SanityLimit'
                                        */
  real_T VelocityChange_WtEt;         /* Computed Parameter: VelocityChange_WtEt
                                       * Referenced by: '<S98>/VelocityChange'
                                       */
  real_T IntegratedVelocity_gainval;
                               /* Computed Parameter: IntegratedVelocity_gainval
                                * Referenced by: '<S97>/IntegratedVelocity'
                                */
  real_T Latch_Threshold;              /* Expression: 0
                                        * Referenced by: '<S106>/Latch'
                                        */
  real_T IntegratedPosition_gainval;
                               /* Computed Parameter: IntegratedPosition_gainval
                                * Referenced by: '<S96>/IntegratedPosition'
                                */
  boolean_T ExternalCoupling_Y0;      /* Computed Parameter: ExternalCoupling_Y0
                                       * Referenced by: '<S89>/ExternalCoupling'
                                       */
};

/* Parameters for system: '<S57>/CouplerForcesPerCoupler' */
struct P_CoreSubsys_TrainDynamics_fxp4_T_ {
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S70>/Memory'
                                  */
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S76>/Delay Input1'
                                      */
  BD_CouplerMimic_InterfaceData Mimic_Value;/* Computed Parameter: Mimic_Value
                                             * Referenced by: '<S58>/Mimic'
                                             */
  real_T uto1_UpperSat;                /* Expression: 1
                                        * Referenced by: '<S72>/0 to 1'
                                        */
  real_T uto1_LowerSat;                /* Expression: 0
                                        * Referenced by: '<S72>/0 to 1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S65>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S78>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S78>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -inf
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T SafeDivide2_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S78>/SafeDivide2'
                                        */
  real_T SafeDivide2_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S78>/SafeDivide2'
                                        */
  real_T SafeDivide1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S78>/SafeDivide1'
                                        */
  real_T SafeDivide1_LowerSat;         /* Expression: eps
                                        * Referenced by: '<S78>/SafeDivide1'
                                        */
  real_T SafeDivide_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S78>/SafeDivide'
                                        */
  real_T SafeDivide_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S78>/SafeDivide'
                                        */
  real_T SignCheck_Threshold;          /* Expression: 0
                                        * Referenced by: '<S78>/SignCheck'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S79>/OffTime'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S79>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S79>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S79>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S79>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S79>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S79>/Discrete-Time Integrator'
                                          */
  real_T CouplerForce_N_Y0;            /* Computed Parameter: CouplerForce_N_Y0
                                        * Referenced by: '<S60>/CouplerForce_N'
                                        */
  real_T SpringForce_N_Y0;             /* Computed Parameter: SpringForce_N_Y0
                                        * Referenced by: '<S60>/SpringForce_N'
                                        */
  real_T DampingForce_N_Y0;            /* Computed Parameter: DampingForce_N_Y0
                                        * Referenced by: '<S60>/DampingForce_N'
                                        */
  real_T BuffForce_N_Y0;               /* Computed Parameter: BuffForce_N_Y0
                                        * Referenced by: '<S60>/BuffForce_N'
                                        */
  real_T DraftForce_N_Y0;              /* Computed Parameter: DraftForce_N_Y0
                                        * Referenced by: '<S60>/DraftForce_N'
                                        */
  real_T CouplerBreakage_Y0;           /* Computed Parameter: CouplerBreakage_Y0
                                        * Referenced by: '<S60>/CouplerBreakage'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S61>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * Referenced by: '<S65>/Gain'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S67>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: -1
                                        * Referenced by: '<S63>/Gain1'
                                        */
  real_T Limit_UpperSat;               /* Expression: 1e8
                                        * Referenced by: '<S60>/Limit'
                                        */
  real_T Limit_LowerSat;               /* Expression: -1e8
                                        * Referenced by: '<S60>/Limit'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S66>/Merge'
                                       */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S64>/Gain'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1e8
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 0
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 1e8
                                        * Referenced by: '<S64>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: 0
                                        * Referenced by: '<S64>/Saturation1'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S70>/Logic'
                                        */
};

/* Parameters for system: '<Root>/Train Dynamics' */
struct P_CoreSubsys_TrainDynamics_g_T_ {
  real_T DiscreteDerivative_ICPrevScaledInput;
                         /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                          * Referenced by: '<S172>/UD'
                          */
  real_T DiscreteDerivative_ICPrevScaledInput_a;
                       /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput_a
                        * Referenced by: '<S137>/UD'
                        */
  real_T MinValue_const;               /* Mask Parameter: MinValue_const
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T MinValue_const_n;             /* Mask Parameter: MinValue_const_n
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T MinValue_const_b;             /* Mask Parameter: MinValue_const_b
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T MinValue_const_o;             /* Mask Parameter: MinValue_const_o
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T MinValue_const_d;             /* Mask Parameter: MinValue_const_d
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T MinValue_const_h;             /* Mask Parameter: MinValue_const_h
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T MinValue_const_c;             /* Mask Parameter: MinValue_const_c
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T MinValue_const_a;             /* Mask Parameter: MinValue_const_a
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T MinValue_const_i;             /* Mask Parameter: MinValue_const_i
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T MinValue_const_nv;            /* Mask Parameter: MinValue_const_nv
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T MinValue_const_l;             /* Mask Parameter: MinValue_const_l
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T MinValue_const_aa;            /* Mask Parameter: MinValue_const_aa
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T MinValue_const_bl;            /* Mask Parameter: MinValue_const_bl
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T MinValue_const_aae;           /* Mask Parameter: MinValue_const_aae
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T MaxValue_const;               /* Mask Parameter: MaxValue_const
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T MaxValue_const_l;             /* Mask Parameter: MaxValue_const_l
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T MaxValue_const_g;             /* Mask Parameter: MaxValue_const_g
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T MaxValue_const_l1;            /* Mask Parameter: MaxValue_const_l1
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T PositiveMovement_const;       /* Mask Parameter: PositiveMovement_const
                                        * Referenced by: '<S184>/Constant'
                                        */
  real_T NegativeMovement_const;       /* Mask Parameter: NegativeMovement_const
                                        * Referenced by: '<S183>/Constant'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S140>/Constant'
                                      */
  boolean_T CompareToConstant_const;  /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S185>/Constant'
                                       */
  BD_TrainDynamics_Cfg_Vehicle DynamicsVehicleConfig_Y0;
                                 /* Computed Parameter: DynamicsVehicleConfig_Y0
                                  * Referenced by: '<S10>/DynamicsVehicleConfig'
                                  */
  BD_TrainDynamics_Out_Coupler Coupler_Out_Y0;/* Computed Parameter: Coupler_Out_Y0
                                               * Referenced by: '<S57>/Coupler_Out'
                                               */
  BD_TrainDynamics_Out_Coupler UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S11>/Unit Delay1'
                               */
  BD_TrainDynamics_Out_Vehicle_Wheel Wheel_Out_Y0;/* Computed Parameter: Wheel_Out_Y0
                                                   * Referenced by: '<S128>/Wheel_Out'
                                                   */
  BD_TrainDynamics_VehicleCouplingData Constant_Value;/* Computed Parameter: Constant_Value
                                                       * Referenced by: '<S120>/Constant'
                                                       */
  BD_TrainDynamics_Out_Vehicle_Drag Constant_Value_g;/* Computed Parameter: Constant_Value_g
                                                      * Referenced by: '<S175>/Constant'
                                                      */
  BD_TrainDynamics_Out_Vehicle_Drag Constant_Value_gl;/* Computed Parameter: Constant_Value_gl
                                                       * Referenced by: '<S176>/Constant'
                                                       */
  BD_TrainDynamics_Out_Vehicle_Drag Constant_Value_f;/* Computed Parameter: Constant_Value_f
                                                      * Referenced by: '<S178>/Constant'
                                                      */
  BD_TrainDynamics_Out_Vehicle_Drag Constant_Value_e;/* Computed Parameter: Constant_Value_e
                                                      * Referenced by: '<S174>/Constant'
                                                      */
  real_T NoLateralDrag_Value;          /* Expression: 0
                                        * Referenced by: '<S180>/NoLateralDrag'
                                        */
  real_T NoBearingDrag_Value;          /* Expression: 0
                                        * Referenced by: '<S180>/NoBearingDrag'
                                        */
  real_T Saturation_UpperSat;          /* Expression: Inf
                                        * Referenced by: '<S175>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S175>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: Inf
                                        * Referenced by: '<S175>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S175>/Saturation1'
                                        */
  real_T AirDensitykgm3_Value;         /* Expression: 1.2252
                                        * Referenced by: '<S178>/Air Density kg//m3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S178>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S173>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: -75
                                        * Referenced by: '<S161>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S161>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S161>/Switch1'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S162>/Constant11'
                                        */
  real_T Constant9_Value;              /* Expression: .5
                                        * Referenced by: '<S162>/Constant9'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S162>/Constant6'
                                        */
  real_T Constant1_Value_i;            /* Expression: .5
                                        * Referenced by: '<S162>/Constant1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S162>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S162>/Switch3'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S162>/Switch'
                                        */
  real_T Switch1_Threshold_h;          /* Expression: 0
                                        * Referenced by: '<S162>/Switch1'
                                        */
  real_T TotalForceTransmitted_Y0;
                                 /* Computed Parameter: TotalForceTransmitted_Y0
                                  * Referenced by: '<S128>/TotalForceTransmitted'
                                  */
  real_T MaxAxles2_Value[6];           /* Expression: 1:MaxAxles
                                        * Referenced by: '<S141>/Max Axles2'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 1
                                        * Referenced by: '<S141>/Saturation'
                                        */
  real_T MaxAxles1_Value[6];           /* Expression: zeros(6,1)
                                        * Referenced by: '<S150>/Max Axles1'
                                        */
  real_T LockedAxleIndex_Value;        /* Expression: 2
                                        * Referenced by: '<S150>/Locked Axle Index'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 0.5
                                        * Referenced by: '<S144>/Gain'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S139>/Constant'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: Inf
                                        * Referenced by: '<S133>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: 500
                                        * Referenced by: '<S133>/Saturation'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S133>/Constant'
                                        */
  real_T Constant_Value_bx;            /* Expression: 1e6
                                        * Referenced by: '<S86>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1e6
                                        * Referenced by: '<S86>/Constant1'
                                        */
  real_T Constant_Value_op[2];         /* Expression: [1 1]
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T MechanicallyCoupled_Y0;   /* Computed Parameter: MechanicallyCoupled_Y0
                                    * Referenced by: '<S57>/MechanicallyCoupled'
                                    */
  real_T HeadANDTailEnabled_Value[2];  /* Expression: [1,1]
                                        * Referenced by: '<S59>/HeadANDTailEnabled'
                                        */
  real_T Default_Value;                /* Expression: 0
                                        * Referenced by: '<S16>/Default'
                                        */
  real_T Default_Value_f;              /* Expression: 1.5*0.005
                                        * Referenced by: '<S17>/Default'
                                        */
  real_T Default_Value_o;              /* Expression: 0.4
                                        * Referenced by: '<S18>/Default'
                                        */
  real_T Default_Value_f1;             /* Expression: 0.1
                                        * Referenced by: '<S19>/Default'
                                        */
  real_T Default_Value_a;              /* Expression: 0
                                        * Referenced by: '<S20>/Default'
                                        */
  real_T Default_Value_c;              /* Expression: 5e6
                                        * Referenced by: '<S21>/Default'
                                        */
  real_T Default_Value_cj;             /* Expression: 0.05
                                        * Referenced by: '<S22>/Default'
                                        */
  real_T Default_Value_k;              /* Expression: 0.24
                                        * Referenced by: '<S23>/Default'
                                        */
  real_T Default_Value_b;              /* Expression: 0.4
                                        * Referenced by: '<S24>/Default'
                                        */
  real_T Default_Value_l;              /* Expression: 0.6
                                        * Referenced by: '<S25>/Default'
                                        */
  real_T Default_Value_n;              /* Expression: 0.41
                                        * Referenced by: '<S26>/Default'
                                        */
  real_T Default_Value_h;              /* Expression: 5e4
                                        * Referenced by: '<S27>/Default'
                                        */
  real_T Default_Value_g;              /* Expression: 0
                                        * Referenced by: '<S28>/Default'
                                        */
  real_T Default_Value_p;              /* Expression: 0
                                        * Referenced by: '<S29>/Default'
                                        */
  real_T Default_Value_a2;             /* Expression: 5e7
                                        * Referenced by: '<S30>/Default'
                                        */
  real_T Default_Value_pa;             /* Expression: 5e4
                                        * Referenced by: '<S31>/Default'
                                        */
  real_T Default_Value_gb;             /* Expression: .2
                                        * Referenced by: '<S32>/Default'
                                        */
  real_T Default_Value_o1;             /* Expression: .2
                                        * Referenced by: '<S33>/Default'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S186>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S14>/Unit Delay'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: 30
                                        * Referenced by: '<S125>/Proportional Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Saturation1_UpperSat_h;       /* Expression: 1
                                        * Referenced by: '<S125>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: -1
                                        * Referenced by: '<S125>/Saturation1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S125>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 0.01
                                        * Referenced by: '<S132>/Gain'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 1e6
                                        * Referenced by: '<S132>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_o;       /* Expression: 0
                                        * Referenced by: '<S132>/Saturation1'
                                        */
  real_T g_Value;                      /* Expression: 9.81
                                        * Referenced by: '<S130>/g'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S130>/Gain'
                                        */
  real_T simcoordinates_Gain;          /* Expression: -1
                                        * Referenced by: '<S130>/sim coordinates'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S172>/TSamp'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * Referenced by: '<S171>/Gain'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1e9
                                        * Referenced by: '<S171>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: 1
                                        * Referenced by: '<S171>/Saturation'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0
                                        * Referenced by: '<S133>/Switch'
                                        */
  real_T VelocityIntegrator_gainval;
                               /* Computed Parameter: VelocityIntegrator_gainval
                                * Referenced by: '<S136>/VelocityIntegrator'
                                */
  real_T PositionIntegrator_gainval;
                               /* Computed Parameter: PositionIntegrator_gainval
                                * Referenced by: '<S135>/PositionIntegrator'
                                */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S137>/TSamp'
                                        */
  real_T IntegralGain_Gain;            /* Expression: 300
                                        * Referenced by: '<S125>/Integral Gain'
                                        */
  P_CoreSubsys_TrainDynamics_fxp4_T CoreSubsys_ixb;/* '<S57>/CouplerForcesPerCoupler' */
  P_CoreSubsys_TrainDynamics_fxp_T CoreSubsys_ix;/* '<S55>/MimicModelPerCoupler' */
  P_CoreSubsys_TrainDynamics_fx_T CoreSubsys_i;/* '<S13>/UpdateMimicPerCoupler' */
  P_CoreSubsys_TrainDynamics_f_T CoreSubsys;/* '<S144>/AxleModel' */
};

/* Parameters (default storage) */
struct P_TrainDynamics_T_ {
  BD_TrainDynamics_Prm PRM_TrainDynamics;/* Variable: PRM_TrainDynamics
                                          * Referenced by: '<S138>/Constant'
                                          */
  real_T MaxAxles;                     /* Variable: MaxAxles
                                        * Referenced by: '<S141>/Saturation'
                                        */
  BD_TrainDynamics_VehicleCouplingData UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<Root>/Unit Delay'
                                */
  real_T InitialPosition_Y0;           /* Computed Parameter: InitialPosition_Y0
                                        * Referenced by: '<S6>/InitialPosition'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S2>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S2>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -inf
                                          * Referenced by: '<S2>/Discrete-Time Integrator'
                                          */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  P_CoreSubsys_TrainDynamics_g_T CoreSubsys_p;/* '<Root>/Train Dynamics' */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrainDynamics_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[345];
    int32_T* vardimsAddress[345];
    RTWLoggingFcnPtr loggingPtrs[345];
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    int_T mdlref_GlobalTID[2];
  } Timing;
};

typedef struct {
  B_TrainDynamics_c_T rtb;
  DW_TrainDynamics_f_T rtdw;
  RT_MODEL_TrainDynamics_T rtm;
  ZCE_TrainDynamics_T rtzce;
} MdlrefDW_TrainDynamics_T;

/* Model reference registration function */
extern void TrainDynamics_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
  RT_MODEL_TrainDynamics_T *const TrainDynamics_M, B_TrainDynamics_c_T *localB,
  DW_TrainDynamics_f_T *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const
  char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  TrainDynamics_GetCAPIStaticMap(void);
extern void TrainDynamics_BrakingForcePerAxle_Start
  (B_BrakingForcePerAxle_TrainDynamics_T *localB);
extern void TrainDynamics_BrakingForcePerAxle(const real_T rtu_AxleConfig[6],
  real_T rtu_TotalForce, B_BrakingForcePerAxle_TrainDynamics_T *localB);
extern void TrainDynamics_DynamicTrackAdhesionVariation_Start
  (B_DynamicTrackAdhesionVariation_TrainDynamics_T *localB);
extern void TrainDynamics_DynamicTrackAdhesionVariation(real_T rtu_Input, real_T
  rtu_Variation, B_DynamicTrackAdhesionVariation_TrainDynamics_T *localB);
extern void TrainDynamics_SandingDynamicTrackAdhesionVariation_Start
  (B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T *localB);
extern void TrainDynamics_SandingDynamicTrackAdhesionVariation(real_T rtu_Input,
  real_T rtu_Variation, B_SandingDynamicTrackAdhesionVariation_TrainDynamics_T
  *localB);
extern void TrainDynamics_Init(B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T
  *localDW);
extern void TrainDynamics_Reset(DW_TrainDynamics_f_T *localDW);
extern void TrainDynamics_Enable(DW_TrainDynamics_f_T *localDW);
extern void TrainDynamics_Start(B_TrainDynamics_c_T *localB,
  DW_TrainDynamics_f_T *localDW, ZCE_TrainDynamics_T *localZCE);
extern void TrainDynamics_Disable(B_TrainDynamics_c_T *localB,
  DW_TrainDynamics_f_T *localDW);
extern void TrainDynamics(RT_MODEL_TrainDynamics_T * const TrainDynamics_M,
  const BD_CommonTrain_SimulatorData *rtu_SimData, const
  BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8], const
  BD_TrainDynamics_Cfg_Vehicle rtu_DynamicsVehicleConfig[8], const
  BD_TrainDynamics_In_Vehicle rtu_DynamicsInVehicle[8], const
  BD_TrainDynamics_In_Vehicle_Overrides rtu_Overrides[8], const
  BD_TrainDynamics_In_Vehicle_Faults rtu_Faults[8], BD_TrainDynamics_Out_Vehicle
  rty_DynamicsVehicleOut[8], B_TrainDynamics_c_T *localB, DW_TrainDynamics_f_T
  *localDW, ZCE_TrainDynamics_T *localZCE);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TrainDynamics'
 * '<S1>'   : 'TrainDynamics/Configuration'
 * '<S2>'   : 'TrainDynamics/Initialize'
 * '<S3>'   : 'TrainDynamics/Model Info'
 * '<S4>'   : 'TrainDynamics/Train Dynamics'
 * '<S5>'   : 'TrainDynamics/Configuration/AtomicConfigProcessing'
 * '<S6>'   : 'TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing'
 * '<S7>'   : 'TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing/ConfigCheck'
 * '<S8>'   : 'TrainDynamics/Configuration/AtomicConfigProcessing/ConfigProcessing/Initial Positions'
 * '<S9>'   : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel'
 * '<S10>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing'
 * '<S11>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models'
 * '<S12>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Pack Outputs'
 * '<S13>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo'
 * '<S14>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics '
 * '<S15>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck'
 * '<S16>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingDynamicFriction'
 * '<S17>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingFriction'
 * '<S18>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Front'
 * '<S19>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Trail'
 * '<S20>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingLeadIn'
 * '<S21>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingRate'
 * '<S22>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default LateralFriction'
 * '<S23>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailDynamicFrictionCoeff'
 * '<S24>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedDynamicFrictionCoeff'
 * '<S25>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedStaticFrictionCoeff'
 * '<S26>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailStaticFrictionCoeff'
 * '<S27>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackDampingRate'
 * '<S28>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackLength'
 * '<S29>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackSpringRate'
 * '<S30>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SpringRate'
 * '<S31>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/DefaultDampingAdjustmentMass'
 * '<S32>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandDynamicFrictionReduction'
 * '<S33>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandStaticFrictionReduction'
 * '<S34>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Validation'
 * '<S35>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingDynamicFriction/Min Value'
 * '<S36>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default BearingFriction/Min Value'
 * '<S37>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Front/Min Value'
 * '<S38>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default Cd_Trail/Min Value'
 * '<S39>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingLeadIn/Max Value'
 * '<S40>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default DampingRate/Min Value'
 * '<S41>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default LateralFriction/Min Value'
 * '<S42>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailDynamicFrictionCoeff/Min Value'
 * '<S43>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedDynamicFrictionCoeff/Min Value'
 * '<S44>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailSandedStaticFrictionCoeff/Min Value'
 * '<S45>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default RailStaticFrictionCoeff/Min Value'
 * '<S46>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackDampingRate/Min Value'
 * '<S47>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackLength/Max Value'
 * '<S48>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SlackSpringRate/Min Value'
 * '<S49>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/Default SpringRate/Min Value'
 * '<S50>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/DefaultDampingAdjustmentMass/Min Value'
 * '<S51>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandDynamicFrictionReduction/Max Value'
 * '<S52>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/ConfigProcessing/ConfigCheck/SandStaticFrictionReduction/Max Value'
 * '<S53>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics'
 * '<S54>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection'
 * '<S55>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle'
 * '<S56>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car'
 * '<S57>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar'
 * '<S58>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler'
 * '<S59>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/HeadANDTailEnable'
 * '<S60>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces'
 * '<S61>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CoupledExtension'
 * '<S62>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage'
 * '<S63>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force'
 * '<S64>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/DraftandBuff'
 * '<S65>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/ExtensionPastSlack'
 * '<S66>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force'
 * '<S67>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Spring Force'
 * '<S68>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CoupledExtension/Compression'
 * '<S69>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/Compare To Zero'
 * '<S70>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/CouplerDamage/S-R Flip-Flop'
 * '<S71>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/DampingRate'
 * '<S72>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/DampingRate/Damping Rate with lead in'
 * '<S73>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Damping Force/DampingRate/Simple Damping'
 * '<S74>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/ExtensionPastSlack/ExtensionPastSlackDeadZone'
 * '<S75>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Compare To Zero'
 * '<S76>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Detect Rise Positive'
 * '<S77>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/NotShocking'
 * '<S78>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Shocking'
 * '<S79>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit'
 * '<S80>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/Detect Rise Positive/Positive'
 * '<S81>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerDynamics/Coupler Models Per Car/CouplerForcesEnabledCar/CouplerForcesPerCoupler/CouplerForces/Instantaneous Impact Force/TimerOffDelay NoInit/Count to 0'
 * '<S82>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/CouplerSelection'
 * '<S83>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor'
 * '<S84>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/ExtractMimic'
 * '<S85>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/If Action Subsystem1'
 * '<S86>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Subsystem'
 * '<S87>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/CouplerModelSelection/DampingFactor/Subsystem/MassFactor1'
 * '<S88>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler'
 * '<S89>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/ExternalCouplingLogic'
 * '<S90>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled'
 * '<S91>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/ExternalCouplingLogic/IsInternalVehicle'
 * '<S92>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicForceSimulation'
 * '<S93>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation'
 * '<S94>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation'
 * '<S95>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation'
 * '<S96>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/PositionCalculation'
 * '<S97>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation'
 * '<S98>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/PredictStop'
 * '<S99>'  : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/Sample and Hold'
 * '<S100>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/AccelerationCalculation/PredictStop/StoppedOrSignChange'
 * '<S101>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/PositionCalculation/Sample and Hold'
 * '<S102>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/NoUpdate'
 * '<S103>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/Sample and Hold'
 * '<S104>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout'
 * '<S105>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInertiaSimulation/VelocityCalculation/UpdateTimeout/Compare To Zero'
 * '<S106>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/Latch Movement'
 * '<S107>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms'
 * '<S108>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate'
 * '<S109>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/CouplerSeparationTransform'
 * '<S110>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/MimicDirectionTransform'
 * '<S111>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Ours Is 1'
 * '<S112>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Ours Is 1:2'
 * '<S113>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Theirs Is 1'
 * '<S114>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicFrameTransforms/Theirs Is 1:2'
 * '<S115>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/MimicInertiaUpdate'
 * '<S116>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference'
 * '<S117>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Detect Change'
 * '<S118>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Coupler Models/MimicModelPerVehicle/MimicModelPerCoupler/MimicModelEnabled/MimicInputTransformation/MimicInertiaUpdate/UpdateTimeDifference/Latch DT'
 * '<S119>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler'
 * '<S120>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/VehicleCouplingDataSelection'
 * '<S121>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs'
 * '<S122>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10'
 * '<S123>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Weighted Average'
 * '<S124>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/UpdateCouplerInfo/UpdateMimicPerCoupler/UpdateMimicOutputs/WMAV10/Weighted Average/Compare To Zero'
 * '<S125>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Braking Gain'
 * '<S126>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Compare To Zero'
 * '<S127>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force'
 * '<S128>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force'
 * '<S129>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Net Force'
 * '<S130>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force'
 * '<S131>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag'
 * '<S132>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /VehicleMass'
 * '<S133>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration'
 * '<S134>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/OscillationOverride'
 * '<S135>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Position'
 * '<S136>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity'
 * '<S137>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Acceleration/Discrete Derivative'
 * '<S138>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/OscillationOverride/Threshold'
 * '<S139>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity/SetVelocity'
 * '<S140>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Inertia Force/Velocity/SetVelocity/Compare To Constant1'
 * '<S141>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/AxleEnabled'
 * '<S142>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle'
 * '<S143>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Stopping Force'
 * '<S144>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact'
 * '<S145>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Braking Force Per Axle'
 * '<S146>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Lateral Friction Force Per Axle'
 * '<S147>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/PerAxle/Reaction Force Per Axle'
 * '<S148>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel'
 * '<S149>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients'
 * '<S150>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/LockedAxle'
 * '<S151>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled'
 * '<S152>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/PackWheelOutputs'
 * '<S153>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/FrictionForce'
 * '<S154>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/Variable Limiter'
 * '<S155>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta'
 * '<S156>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/DifferentialWheelSpeed'
 * '<S157>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/SnapToZero'
 * '<S158>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/SomeSlip'
 * '<S159>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/WheelSpeedLimits'
 * '<S160>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/AxleModel/AxleModelEnabled/WheelSpeedDelta/DifferentialWheelSpeed/Saturation Dynamic'
 * '<S161>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding'
 * '<S162>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding'
 * '<S163>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Dynamic Track Adhesion Variation'
 * '<S164>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Sanding Dynamic Track Adhesion Variation'
 * '<S165>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Sanding Static Track Adhesion Variation'
 * '<S166>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Constant Friction While Sanding/Static Track Adhesion Variation'
 * '<S167>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Dynamic Track Adhesion Variation'
 * '<S168>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Sanding Dynamic Track Adhesion Variation'
 * '<S169>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Sanding Static Track Adhesion Variation'
 * '<S170>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Longitudinal Wheel Force/Wheel Rail Contact/Friction Coefficients/Variant Friction While Sanding/Static Track Adhesion Variation'
 * '<S171>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Derailment Coefficient'
 * '<S172>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/Discrete Derivative'
 * '<S173>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Track Geometry Force/DivSafe'
 * '<S174>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/ApplyBrakingGain'
 * '<S175>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Custom Drag'
 * '<S176>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Davis Drag'
 * '<S177>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/DetermineLeadCar'
 * '<S178>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag'
 * '<S179>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Lateral Friction'
 * '<S180>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Wheel Related Drag Force Axle Check'
 * '<S181>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/ApplyBrakingGain/Percentage Variation'
 * '<S182>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/ApplyBrakingGain/Percentage Variation1'
 * '<S183>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/DetermineLeadCar/NegativeMovement'
 * '<S184>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/DetermineLeadCar/PositiveMovement'
 * '<S185>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Fundamental Drag/Compare To Constant'
 * '<S186>' : 'TrainDynamics/Train Dynamics/VehicleDynamicsModel/Vehicle Dynamics /Vehicle Drag/Wheel Related Drag Force Axle Check/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_TrainDynamics_h_ */
