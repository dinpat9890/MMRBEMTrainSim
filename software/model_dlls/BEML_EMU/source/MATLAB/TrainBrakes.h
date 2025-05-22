/*
 * Code generation for system model 'TrainBrakes'
 * For more details, see corresponding source file TrainBrakes.c
 *
 */

#ifndef RTW_HEADER_TrainBrakes_h_
#define RTW_HEADER_TrainBrakes_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef TrainBrakes_COMMON_INCLUDES_
# define TrainBrakes_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* TrainBrakes_COMMON_INCLUDES_ */

#include "TrainBrakes_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals for system '<S4>/AxleBrakes' */
typedef struct {
  real_T Product;                      /* '<S17>/Product' */
  real_T BrakeFadePercentage;          /* '<S14>/Gain' */
  real_T Saturation;                   /* '<S32>/Saturation' */
  real_T Sum1;                         /* '<S12>/Sum1' */
  real_T BrakeTemperature;             /* '<S26>/Add' */
  real_T Max;                          /* '<S13>/Max' */
} B_CoreSubsys_TrainBrakes_g_T;

/* Block states (default storage) for system '<S4>/AxleBrakes' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S17>/Unit Delay' */
  real_T UnitDelay_DSTATE_n;           /* '<S26>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S30>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S31>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S31>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S31>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;/* '<S31>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S31>/IC' */
  boolean_T BrakingForce_MODE;         /* '<S5>/BrakingForce' */
  boolean_T BrakeThermalModel_MODE;    /* '<S17>/BrakeThermalModel' */
} DW_CoreSubsys_TrainBrakes_o_T;

/* Block signals for system '<Root>/VehicleBrakes' */
typedef struct {
  BD_TrainBrakes_Out_Vehicle TrainBrakesOut;/* '<S10>/Bus Assignment' */
  BD_TrainBrakes_Cfg_Vehicle BusCreator1;/* '<S33>/Bus Creator1' */
  real_T Selector[6];                  /* '<S6>/Selector' */
  real_T Selector1[6];                 /* '<S6>/Selector1' */
  boolean_T Compare[6];                /* '<S7>/Compare' */
  boolean_T Compare_a[6];              /* '<S8>/Compare' */
  B_CoreSubsys_TrainBrakes_g_T CoreSubsys[6];/* '<S4>/AxleBrakes' */
} B_CoreSubsys_TrainBrakes_T;

/* Block states (default storage) for system '<Root>/VehicleBrakes' */
typedef struct {
  void* Assertion_slioAccessor;        /* '<S34>/Assertion' */
  boolean_T VehicleEnabledBrakes_MODE; /* '<S2>/VehicleEnabledBrakes' */
  DW_CoreSubsys_TrainBrakes_o_T CoreSubsys[6];/* '<S4>/AxleBrakes' */
} DW_CoreSubsys_TrainBrakes_T;

/* Block signals for model 'TrainBrakes' */
typedef struct {
  B_CoreSubsys_TrainBrakes_T CoreSubsys[8];/* '<Root>/VehicleBrakes' */
} B_TrainBrakes_c_T;

/* Block states (default storage) for model 'TrainBrakes' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  DW_CoreSubsys_TrainBrakes_T CoreSubsys[8];/* '<Root>/VehicleBrakes' */
} DW_TrainBrakes_f_T;

/* Parameters for system: '<S4>/AxleBrakes' */
struct P_CoreSubsys_TrainBrakes_l_T_ {
  real_T BrakeThermalFade_AirDensity;
                                  /* Mask Parameter: BrakeThermalFade_AirDensity
                                   * Referenced by: '<S28>/AirRho'
                                   */
  real_T BrakeThermalFade_AirDynamicViscosity;
                         /* Mask Parameter: BrakeThermalFade_AirDynamicViscosity
                          * Referenced by: '<S28>/AirMuv'
                          */
  real_T BrakeThermalFade_AirSpecificHeat;
                             /* Mask Parameter: BrakeThermalFade_AirSpecificHeat
                              * Referenced by: '<S28>/AirCp'
                              */
  real_T BrakeThermalFade_AirThermalConductivity;
                      /* Mask Parameter: BrakeThermalFade_AirThermalConductivity
                       * Referenced by: '<S28>/AirK'
                       */
  real_T BrakeThermalFade_AmbientTemperature;
                          /* Mask Parameter: BrakeThermalFade_AmbientTemperature
                           * Referenced by: '<S26>/AmbientAirTemp'
                           */
  real_T BrakeThermalFade_ConvectiveArea;
                              /* Mask Parameter: BrakeThermalFade_ConvectiveArea
                               * Referenced by: '<S26>/ConvectiveArea'
                               */
  real_T DiscreteIntegratorWithReset_InitValue;
                        /* Mask Parameter: DiscreteIntegratorWithReset_InitValue
                         * Referenced by: '<S31>/InitValue'
                         */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S30>/Delay Input1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T ParkBrakePistonForce_Y0; /* Computed Parameter: ParkBrakePistonForce_Y0
                                   * Referenced by: '<S13>/ParkBrakePistonForce'
                                   */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: 1
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T OvertemperatureEnergy_Value;  /* Expression: 1e8
                                        * Referenced by: '<S29>/OvertemperatureEnergy'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0
                                        * Referenced by: '<S29>/Switch'
                                        */
  real_T BrakeTemperature_Y0;         /* Computed Parameter: BrakeTemperature_Y0
                                       * Referenced by: '<S26>/BrakeTemperature'
                                       */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S26>/Unit Delay'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: inf
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T StefanBoltzmannSigma_Value;   /* Expression: 5.67e-8
                                        * Referenced by: '<S26>/StefanBoltzmannSigma'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S31>/Discrete-Time Integrator'
                            */
  real_T Constant_Value_n;             /* Expression: eps
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T BrakingForceAxle_N_Y0;     /* Computed Parameter: BrakingForceAxle_N_Y0
                                     * Referenced by: '<S12>/BrakingForceAxle_N'
                                     */
  real_T BrakeShoeForceAxle_N_Y0; /* Computed Parameter: BrakeShoeForceAxle_N_Y0
                                   * Referenced by: '<S12>/BrakeShoeForceAxle_N'
                                   */
  real_T BrakeShoeEfficiency_Y0;   /* Computed Parameter: BrakeShoeEfficiency_Y0
                                    * Referenced by: '<S12>/BrakeShoeEfficiency'
                                    */
  real_T DiscBrakeForceAxle_N_Y0; /* Computed Parameter: DiscBrakeForceAxle_N_Y0
                                   * Referenced by: '<S12>/DiscBrakeForceAxle_N'
                                   */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T Multiply_Gain;                /* Expression: 0.5
                                        * Referenced by: '<S14>/Multiply'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S27>/Switch2'
                                        */
  real_T Saturation_UpperSat_fq;       /* Expression: 1
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation_LowerSat_ar;       /* Expression: 0
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Constant4_Value;              /* Expression: 100
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: inf
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: 0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S31>/IC'
                                        */
};

/* Parameters for system: '<Root>/VehicleBrakes' */
struct P_CoreSubsys_TrainBrakes_T_ {
  real_T InvalidZeroOrNegativeFriction_const;
                          /* Mask Parameter: InvalidZeroOrNegativeFriction_const
                           * Referenced by: '<S35>/Constant'
                           */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S39>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S40>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S37>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S38>/Constant'
                                      */
  BD_TrainBrakes_Out_Vehicle TrainBrakesOut_Y0;/* Computed Parameter: TrainBrakesOut_Y0
                                                * Referenced by: '<S3>/TrainBrakesOut'
                                                */
  BD_TrainBrakes_Out_Vehicle Constant_Value;/* Computed Parameter: Constant_Value
                                             * Referenced by: '<S10>/Constant'
                                             */
  BD_TrainBrakes_Out_Vehicle_States Constant_Value_i;/* Computed Parameter: Constant_Value_i
                                                      * Referenced by: '<S36>/Constant'
                                                      */
  BD_TrainBrakes_Cfg_Vehicle BrakesVehicleConfig_Y0;
                                   /* Computed Parameter: BrakesVehicleConfig_Y0
                                    * Referenced by: '<S9>/BrakesVehicleConfig'
                                    */
  real_T Constant_Value_iu;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_iw;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant3'
                                        */
  P_CoreSubsys_TrainBrakes_l_T CoreSubsys;/* '<S4>/AxleBrakes' */
};

/* Parameters (default storage) */
struct P_TrainBrakes_T_ {
  real_T pAtm;                         /* Variable: pAtm
                                        * Referenced by: '<S11>/PAtm'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S1>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S1>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -inf
                                          * Referenced by: '<S1>/Discrete-Time Integrator'
                                          */
  P_CoreSubsys_TrainBrakes_T CoreSubsys;/* '<Root>/VehicleBrakes' */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrainBrakes_T {
  const char_T **errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[84];
    int32_T* vardimsAddress[84];
    RTWLoggingFcnPtr loggingPtrs[84];
  } DataMapInfo;
};

typedef struct {
  B_TrainBrakes_c_T rtb;
  DW_TrainBrakes_f_T rtdw;
  RT_MODEL_TrainBrakes_T rtm;
} MdlrefDW_TrainBrakes_T;

/* Model reference registration function */
extern void TrainBrakes_initialize(const char_T **rt_errorStatus,
  RT_MODEL_TrainBrakes_T *const TrainBrakes_M, B_TrainBrakes_c_T *localB,
  DW_TrainBrakes_f_T *localDW, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const
  char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  TrainBrakes_GetCAPIStaticMap(void);
extern void TrainBrakes_Init(B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T
  *localDW);
extern void TrainBrakes_Reset(DW_TrainBrakes_f_T *localDW);
extern void TrainBrakes_Start(B_TrainBrakes_c_T *localB, DW_TrainBrakes_f_T
  *localDW);
extern void TrainBrakes_Disable(DW_TrainBrakes_f_T *localDW);
extern void TrainBrakes(const BD_CommonTrain_Cfg_Vehicle
  rtu_CommonVehicleConfig[8], const BD_TrainBrakes_Cfg_Vehicle
  rtu_BrakeVehicleConfig[8], const BD_TrainBrakes_In_Vehicle
  rtu_BrakesVehicleIn[8], const BD_TrainBrakes_In_Vehicle_Overrides
  rtu_Overrides[8], const BD_TrainBrakes_In_Vehicle_Faults rtu_Faults[8],
  BD_TrainBrakes_Out_Vehicle rty_BrakesVehicleOut[8], B_TrainBrakes_c_T *localB,
  DW_TrainBrakes_f_T *localDW, const BD_TrainBrakes_Prm_Vehicle
  *rtp_PRM_TrainBrakes_Vehicles);

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
 * '<Root>' : 'TrainBrakes'
 * '<S1>'   : 'TrainBrakes/Initialize'
 * '<S2>'   : 'TrainBrakes/VehicleBrakes'
 * '<S3>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes'
 * '<S4>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes'
 * '<S5>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes'
 * '<S6>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxlePressureDistribution'
 * '<S7>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero'
 * '<S8>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/Compare To Zero1'
 * '<S9>'   : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing'
 * '<S10>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile'
 * '<S11>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakeCylinderPistonForce'
 * '<S12>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce'
 * '<S13>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/ParkBrakePistonForce'
 * '<S14>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce'
 * '<S15>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionDiscBrake'
 * '<S16>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient'
 * '<S17>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade'
 * '<S18>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/Percentage Variation'
 * '<S19>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Constant'
 * '<S20>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom'
 * '<S21>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Default'
 * '<S22>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient'
 * '<S23>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/MATLAB Function'
 * '<S24>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/Mean of Non-Zero Elements'
 * '<S25>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeShoeFrictionCoefficient/Custom/CustomBrakeShoeCoefficient/Mean of Non-Zero Elements/Compare To Zero'
 * '<S26>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel'
 * '<S27>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/TemperatureBrakeFade'
 * '<S28>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/ConvectiveCoefficient'
 * '<S29>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator'
 * '<S30>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/Detect Change'
 * '<S31>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionBrakeForce/BrakeThermalFade/BrakeThermalModel/EnergyAccumluator/DiscreteIntegratorWithReset'
 * '<S32>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/AxleBrakes/BrakingForce/FrictionDiscBrake/DiscBrakeNormalForce'
 * '<S33>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/ConfigCheck'
 * '<S34>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/ConfigCheck/BrakeShoeFrictionAssert'
 * '<S35>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/ConfigProcessing/ConfigCheck/BrakeShoeFrictionAssert/InvalidZeroOrNegativeFriction'
 * '<S36>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping'
 * '<S37>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant2'
 * '<S38>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant3'
 * '<S39>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant5'
 * '<S40>'  : 'TrainBrakes/VehicleBrakes/VehicleEnabledBrakes/VehicleBrakes/TrainBrakesOutCompile/StatesMapping/Compare To Constant6'
 */
#endif                                 /* RTW_HEADER_TrainBrakes_h_ */
