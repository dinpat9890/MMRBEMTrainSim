/*
 * Code generation for system model 'PneumaticsSystem'
 * For more details, see corresponding source file PneumaticsSystem.c
 *
 */

#ifndef RTW_HEADER_PneumaticsSystem_h_
#define RTW_HEADER_PneumaticsSystem_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef PneumaticsSystem_COMMON_INCLUDES_
# define PneumaticsSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PneumaticsSystem_COMMON_INCLUDES_ */

#include "PneumaticsSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals for system '<S26>/BSR Vent IC' */
typedef struct {
  real_T FlowNoflow;                   /* '<S31>/FlowNoflow' */
} B_BSRVentIC_PneumaticsSystem_T;

/* Block signals for system '<S26>/BSR Vent Drain' */
typedef struct {
  real_T FlowNoflow;                   /* '<S30>/FlowNoflow' */
} B_BSRVentDrain_PneumaticsSystem_T;

/* Block signals for system '<S11>/TimerOffDelay NoInit' */
typedef struct {
  boolean_T LogicalOperator1;          /* '<S38>/Logical Operator1' */
} B_TimerOffDelayNoInit_PneumaticsSystem_T;

/* Block states (default storage) for system '<S11>/TimerOffDelay NoInit' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S38>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S38>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S38>/Discrete-Time Integrator' */
  boolean_T IC_FirstOutputTime;        /* '<S38>/IC' */
} DW_TimerOffDelayNoInit_PneumaticsSystem_T;

/* Block signals for system '<S127>/AS Charge' */
typedef struct {
  real_T FlowNoflow;                   /* '<S133>/FlowNoflow' */
} B_ASCharge_PneumaticsSystem_T;

/* Block signals for system '<S127>/AS Vent' */
typedef struct {
  real_T FlowNoflow;                   /* '<S134>/FlowNoflow' */
} B_ASVent_PneumaticsSystem_T;

/* Block signals for system '<S118>/AirSuspensionPerBogie' */
typedef struct {
  real_T VectorConcatenate1[2];        /* '<S145>/Vector Concatenate1' */
  real_T VectorConcatenate[2];         /* '<S145>/Vector Concatenate' */
  B_BSRVentDrain_PneumaticsSystem_T ASVentDrain;/* '<S127>/AS Vent Drain' */
  B_BSRVentIC_PneumaticsSystem_T ASVentIC;/* '<S127>/AS Vent IC' */
  B_ASVent_PneumaticsSystem_T ASVent;  /* '<S127>/AS Vent' */
  B_ASCharge_PneumaticsSystem_T ASCharge;/* '<S127>/AS Charge' */
} B_CoreSubsys_PneumaticsSystem_cau_T;

/* Block states (default storage) for system '<S118>/AirSuspensionPerBogie' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S123>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S130>/Unit Delay1' */
  real_T DiscreteTransferFcn_states;   /* '<S145>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp;      /* '<S145>/Discrete Transfer Fcn' */
  boolean_T UnitDelay1_DSTATE_g;       /* '<S123>/Unit Delay1' */
  boolean_T IC_FirstOutputTime;        /* '<S130>/IC' */
  boolean_T Initialise_FirstOutputTime;/* '<S132>/Initialise' */
  boolean_T PressureSwitch_Mode;       /* '<S126>/PressureSwitch' */
} DW_CoreSubsys_PneumaticsSystem_fwu_T;

/* Block signals for system '<S148>/BrakeCylinderSystemPerAxle' */
typedef struct {
  real_T P;                            /* '<S194>/ConvertToPressure' */
  B_ASCharge_PneumaticsSystem_T BCCharge;/* '<S195>/BC Charge' */
  B_BSRVentDrain_PneumaticsSystem_T BCIsolate;/* '<S195>/BC Isolate' */
  B_ASVent_PneumaticsSystem_T BCVent;  /* '<S195>/BC Vent' */
} B_CoreSubsys_PneumaticsSystem_cauaohu_T;

/* Block states (default storage) for system '<S148>/BrakeCylinderSystemPerAxle' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S192>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S196>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_k;       /* '<S192>/Unit Delay1' */
  boolean_T IC_FirstOutputTime;        /* '<S196>/IC' */
} DW_CoreSubsys_PneumaticsSystem_fwu4slj_T;

/* Block signals for system '<S153>/If Action Subsystem5' */
typedef struct {
  real_T In1;                          /* '<S173>/In1' */
} B_IfActionSubsystem5_PneumaticsSystem_T;

/* Block signals for system '<S121>/BrakingSystemPerBogie' */
typedef struct {
  real_T VectorConcatenate1[2];        /* '<S156>/Vector Concatenate1' */
  real_T VectorConcatenate[2];         /* '<S156>/Vector Concatenate' */
  real_T VectorConcatenate1_c[2];      /* '<S187>/Vector Concatenate1' */
  real_T VectorConcatenate_l[2];       /* '<S187>/Vector Concatenate' */
  real_T VectorConcatenate1_d[2];      /* '<S208>/Vector Concatenate1' */
  real_T VectorConcatenate_k[2];       /* '<S208>/Vector Concatenate' */
  real_T OutportBufferForOut2;         /* '<S170>/Rate Limiter Dynamic2' */
  B_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem6;/* '<S153>/If Action Subsystem6' */
  B_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem4;/* '<S153>/If Action Subsystem4' */
  B_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem5;/* '<S153>/If Action Subsystem5' */
  B_CoreSubsys_PneumaticsSystem_cauaohu_T CoreSubsys[2];/* '<S148>/BrakeCylinderSystemPerAxle' */
} B_CoreSubsys_PneumaticsSystem_cauaoh_T;

/* Block states (default storage) for system '<S121>/BrakingSystemPerBogie' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<S156>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_i; /* '<S187>/Discrete Transfer Fcn' */
  real_T DelayInput1_DSTATE;           /* '<S163>/Delay Input1' */
  real_T DelayInput1_DSTATE_b;         /* '<S164>/Delay Input1' */
  real_T DelayInput1_DSTATE_e;         /* '<S165>/Delay Input1' */
  real_T DelayInput1_DSTATE_a;         /* '<S166>/Delay Input1' */
  real_T DelayInput1_DSTATE_f;         /* '<S169>/Delay Input1' */
  real_T DiscreteTransferFcn_states_l; /* '<S208>/Discrete Transfer Fcn' */
  real_T DelayInput2_DSTATE;           /* '<S181>/Delay Input2' */
  real_T DiscreteTransferFcn_tmp;      /* '<S156>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S187>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_h;    /* '<S208>/Discrete Transfer Fcn' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S168>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S167>/Delay Input1' */
  int8_T If_ActiveSubsystem;           /* '<S153>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S153>/If1' */
  boolean_T Initialise_FirstOutputTime;/* '<S190>/Initialise' */
  boolean_T PressureSwitch_Mode;       /* '<S185>/PressureSwitch' */
  boolean_T Memory_PreviousInput;      /* '<S175>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S176>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S177>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S178>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S179>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S180>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S209>/Memory' */
  boolean_T Initialise_FirstOutputTime_g;/* '<S210>/Initialise' */
  boolean_T PressureSwitch_Mode_b;     /* '<S207>/PressureSwitch' */
  DW_CoreSubsys_PneumaticsSystem_fwu4slj_T CoreSubsys[2];/* '<S148>/BrakeCylinderSystemPerAxle' */
} DW_CoreSubsys_PneumaticsSystem_fwu4sl_T;

/* Block states (default storage) for system '<S122>/SandingSystemPerBogie' */
typedef struct {
  boolean_T Initialise_FirstOutputTime;/* '<S213>/Initialise' */
  boolean_T PressureSwitch_Mode;       /* '<S212>/PressureSwitch' */
} DW_CoreSubsys_PneumaticsSystem_fwu4sljn_T;

/* Block signals for system '<S231>/MR Pipe Two Way Valve' */
typedef struct {
  real_T Add;                          /* '<S237>/Add' */
  B_BSRVentDrain_PneumaticsSystem_T Reverse;/* '<S237>/Reverse' */
  B_BSRVentDrain_PneumaticsSystem_T Forward;/* '<S237>/Forward' */
} B_MRPipeTwoWayValve_PneumaticsSystem_T;

/* Block signals for system '<Root>/PneumaticsPerVehicle' */
typedef struct {
  BD_PneumaticsSystem_Out_Vehicle BusCreator;/* '<S18>/Bus Creator' */
  BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie
    ImpAsg_InsertedFor_BCUPressureTransducers_at_inport_0[2];/* '<S148>/BrakeControlUnit' */
  BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie
    ImpAsg_InsertedFor_FaultMessages_at_inport_0[2];/* '<S148>/BrakeControlUnit' */
  BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie
    ImpAsg_InsertedFor_BrakeSystemPressureGauges_at_inport_0[2];/* '<S148>/Bus Creator2' */
  real_T P;                            /* '<S233>/ConvertToPressure' */
  real_T PressureSwitch;               /* '<S232>/PressureSwitch' */
  real_T P_a;                          /* '<S216>/ConvertToPressure' */
  real_T Bias;                         /* '<S214>/Bias' */
  real_T PressureSwitch_g;             /* '<S215>/PressureSwitch' */
  real_T ImpAsg_InsertedFor_SandingPressure_at_inport_0[2];/* '<S211>/Divide' */
  real_T ImpAsg_InsertedFor_SandingPressureSwitch_at_inport_0[2];/* '<S211>/Divide1' */
  real_T VectorConcatenate1[2];        /* '<S121>/Vector Concatenate1' */
  real_T SumofElements;                /* '<S121>/Sum of Elements' */
  real_T ImpAsg_InsertedFor_ParkBrakePressure_at_inport_0[2];/* '<S148>/ParkBrakes' */
  real_T ImpAsg_InsertedFor_ParkBrakePressureSwitch_at_inport_0[2];/* '<S148>/ParkBrakes' */
  real_T ImpAsg_InsertedFor_ControlPressure_at_inport_0[2];/* '<S148>/BrakeControlUnit' */
  real_T ImpAsg_InsertedFor_BrakeCylinderPressure_at_inport_0[4];/* '<S148>/BrakeCylinderSystemPerAxle' */
  real_T ImpAsg_InsertedFor_BCPressureSwitch_at_inport_0[2];/* '<S148>/BrakeCylinderSupplyLine' */
  real_T VectorConcatenate2[2];        /* '<S118>/Vector Concatenate2' */
  real_T VectorConcatenate1_k[2];      /* '<S118>/Vector Concatenate1' */
  real_T Sum;                          /* '<S118>/Sum' */
  real_T ImpAsg_InsertedFor_AirSuspensionPressure_at_inport_0[2];/* '<S123>/Subsystem' */
  real_T ImpAsg_InsertedFor_AirSuspensionPressureSwitch_at_inport_0[2];/* '<S123>/B27-L11-1//2' */
  real_T ImpAsg_InsertedFor_AirSuspPressureVariation_at_inport_0[2];/* '<S123>/Subsystem' */
  real_T HornLowPressureSwitch;        /* '<S59>/Data Type Conversion' */
  real_T HornHighPressureSwitch;       /* '<S59>/Data Type Conversion1' */
  real_T HornLow;                      /* '<S59>/Gain' */
  real_T HornHigh;                     /* '<S59>/Gain1' */
  real_T P_d;                          /* '<S64>/ConvertToPressure' */
  real_T PressureSwitch_e;             /* '<S63>/PressureSwitch' */
  real_T P_e;                          /* '<S82>/ConvertToPressure' */
  real_T PressureSwitch_d;             /* '<S79>/PressureSwitch' */
  real_T PressureSwitch_l;             /* '<S80>/PressureSwitch' */
  real_T P_o;                          /* '<S103>/ConvertToPressure' */
  real_T PressureSwitch_j;             /* '<S104>/PressureSwitch' */
  boolean_T VectorConcatenate[2];      /* '<S121>/Vector Concatenate' */
  boolean_T VectorConcatenate2_c[2];   /* '<S121>/Vector Concatenate2' */
  B_MRPipeTwoWayValve_PneumaticsSystem_T MRPtoDownstreamConnection;
                                     /* '<S255>/MRP to Downstream Connection' */
  B_MRPipeTwoWayValve_PneumaticsSystem_T MRPtoUpstreamConnection;/* '<S255>/MRP to Upstream Connection' */
  B_BSRVentDrain_PneumaticsSystem_T MRVentDrain;/* '<S231>/MR Vent Drain' */
  B_BSRVentDrain_PneumaticsSystem_T MRBlowoff;/* '<S231>/MR Blowoff' */
  B_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit_d;/* '<S231>/TimerOffDelay NoInit' */
  B_MRPipeTwoWayValve_PneumaticsSystem_T MRPipeTwoWayValve;/* '<S231>/MR Pipe Two Way Valve' */
  B_BSRVentDrain_PneumaticsSystem_T BSRCharge_b;/* '<S217>/BSR Charge' */
  B_BSRVentDrain_PneumaticsSystem_T BSRVentDrain_d;/* '<S217>/BSR Vent Drain' */
  B_BSRVentDrain_PneumaticsSystem_T BSRVentIC_c;/* '<S217>/BSR Vent IC' */
  B_CoreSubsys_PneumaticsSystem_cauaoh_T CoreSubsys_pna[2];/* '<S121>/BrakingSystemPerBogie' */
  B_CoreSubsys_PneumaticsSystem_cau_T CoreSubsys[2];/* '<S118>/AirSuspensionPerBogie' */
  B_BSRVentIC_PneumaticsSystem_T VCBIsolate;/* '<S102>/VCB Isolate' */
  B_BSRVentDrain_PneumaticsSystem_T VCBVent;/* '<S102>/VCB Vent' */
  B_BSRVentDrain_PneumaticsSystem_T VCBCharge;/* '<S102>/VCB Charge' */
  B_BSRVentIC_PneumaticsSystem_T PCVentIsol;/* '<S77>/PC Vent Isol' */
  B_BSRVentIC_PneumaticsSystem_T PCVentControl;/* '<S77>/PC Vent Control' */
  B_BSRVentDrain_PneumaticsSystem_T PCVentEmer;/* '<S77>/PC Vent Emer' */
  B_BSRVentDrain_PneumaticsSystem_T ARCharge;/* '<S77>/AR Charge' */
  B_BSRVentDrain_PneumaticsSystem_T ARChargefromMRP;/* '<S65>/AR Charge from MRP' */
  B_BSRVentDrain_PneumaticsSystem_T ARVentDrain;/* '<S65>/AR Vent Drain' */
  B_BSRVentDrain_PneumaticsSystem_T ARBlowoff;/* '<S65>/AR Blowoff' */
  B_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit1;/* '<S11>/TimerOffDelay NoInit1' */
  B_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit;/* '<S11>/TimerOffDelay NoInit' */
  B_BSRVentDrain_PneumaticsSystem_T BSRCharge;/* '<S26>/BSR Charge' */
  B_BSRVentDrain_PneumaticsSystem_T BSRVentDrain;/* '<S26>/BSR Vent Drain' */
  B_BSRVentIC_PneumaticsSystem_T BSRVentIC;/* '<S26>/BSR Vent IC' */
} B_CoreSubsys_PneumaticsSystem_ca_T;

/* Block states (default storage) for system '<Root>/PneumaticsPerVehicle' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S230>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S9>/Unit Delay' */
  real_T UnitDelay_DSTATE_k;           /* '<S17>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S9>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S9>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_a;          /* '<S273>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S24>/Unit Delay' */
  real_T UnitDelay5_DSTATE;            /* '<S9>/Unit Delay5' */
  real_T UnitDelay1_DSTATE_e;          /* '<S27>/Unit Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S40>/Delay Input1' */
  real_T DelayInput1_DSTATE_d;         /* '<S46>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S41>/Delay Input1' */
  real_T DelayInput1_DSTATE_a;         /* '<S48>/Delay Input1' */
  real_T DelayInput1_DSTATE_dh;        /* '<S49>/Delay Input1' */
  real_T DelayInput1_DSTATE_g;         /* '<S50>/Delay Input1' */
  real_T DelayInput1_DSTATE_c;         /* '<S51>/Delay Input1' */
  real_T DelayInput1_DSTATE_b;         /* '<S52>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;         /* '<S53>/Delay Input1' */
  real_T DelayInput1_DSTATE_nm;        /* '<S54>/Delay Input1' */
  real_T DelayInput1_DSTATE_b2;        /* '<S55>/Delay Input1' */
  real_T DelayInput1_DSTATE_da;        /* '<S42>/Delay Input1' */
  real_T DelayInput1_DSTATE_c4;        /* '<S43>/Delay Input1' */
  real_T DelayInput1_DSTATE_p;         /* '<S44>/Delay Input1' */
  real_T DelayInput1_DSTATE_f;         /* '<S45>/Delay Input1' */
  real_T DelayInput1_DSTATE_fx;        /* '<S47>/Delay Input1' */
  real_T DelayInput1_DSTATE_ia;        /* '<S36>/Delay Input1' */
  real_T UnitDelay4_DSTATE;            /* '<S9>/Unit Delay4' */
  real_T UnitDelay_DSTATE_d;           /* '<S229>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S251>/Unit Delay1' */
  real_T UnitDelay_DSTATE_h;           /* '<S214>/Unit Delay' */
  real_T UnitDelay1_DSTATE_es;         /* '<S219>/Unit Delay1' */
  real_T UnitDelay_DSTATE_f;           /* '<S58>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S58>/Unit Delay1' */
  real_T UnitDelay_DSTATE_e;           /* '<S60>/Unit Delay' */
  real_T UnitDelay1_DSTATE_m;          /* '<S67>/Unit Delay1' */
  real_T DelayInput1_DSTATE_ii;        /* '<S76>/Delay Input1' */
  real_T UnitDelay_DSTATE_eb;          /* '<S61>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ks;         /* '<S61>/Unit Delay1' */
  real_T DelayInput1_DSTATE_m;         /* '<S98>/Delay Input1' */
  real_T UnitDelay1_DSTATE_g;          /* '<S85>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_mr;         /* '<S100>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_kw;         /* '<S62>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d;          /* '<S111>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE_pn;     /* '<S235>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_j;       /* '<S83>/Unit Delay1' */
  boolean_T IC_FirstOutputTime;        /* '<S27>/IC' */
  boolean_T IC_FirstOutputTime_k;      /* '<S273>/IC' */
  boolean_T Initialise_FirstOutputTime;/* '<S257>/Initialise' */
  boolean_T PressureSwitch_Mode;       /* '<S253>/PressureSwitch' */
  boolean_T Initialise_FirstOutputTime_d;/* '<S258>/Initialise' */
  boolean_T PressureSwitch_Mode_e;     /* '<S254>/PressureSwitch' */
  boolean_T IC_FirstOutputTime_c;      /* '<S251>/IC' */
  boolean_T Overpressure_Mode;         /* '<S231>/Overpressure' */
  boolean_T Initialise_FirstOutputTime_l;/* '<S250>/Initialise' */
  boolean_T PressureSwitch_Mode_k;     /* '<S232>/PressureSwitch' */
  boolean_T Initialise_FirstOutputTime_e;/* '<S218>/Initialise' */
  boolean_T IC_FirstOutputTime_b;      /* '<S219>/IC' */
  boolean_T PressureSwitch_Mode_m;     /* '<S215>/PressureSwitch' */
  boolean_T Initialise_FirstOutputTime_a;/* '<S66>/Initialise' */
  boolean_T IC_FirstOutputTime_a;      /* '<S67>/IC' */
  boolean_T Overpressure_Mode_c;       /* '<S65>/Overpressure' */
  boolean_T PressureSwitch_Mode_c;     /* '<S63>/PressureSwitch' */
  boolean_T IC_FirstOutputTime_ax;     /* '<S85>/IC' */
  boolean_T Memory_PreviousInput;      /* '<S99>/Memory' */
  boolean_T IC_FirstOutputTime_ak;     /* '<S100>/IC' */
  boolean_T Initialise_FirstOutputTime_g;/* '<S96>/Initialise' */
  boolean_T PressureSwitch_Mode_b;     /* '<S79>/PressureSwitch' */
  boolean_T Initialise_FirstOutputTime_f;/* '<S97>/Initialise' */
  boolean_T PressureSwitch_Mode_f;     /* '<S80>/PressureSwitch' */
  boolean_T IC_FirstOutputTime_o;      /* '<S111>/IC' */
  boolean_T Initialise_FirstOutputTime_n;/* '<S113>/Initialise' */
  boolean_T PressureSwitch_Mode_d;     /* '<S104>/PressureSwitch' */
  boolean_T PneumaticsSystem_MODE;     /* '<S3>/PneumaticsSystem' */
  boolean_T BrakingSystem_MODE;        /* '<S14>/BrakingSystem' */
  DW_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit_d;/* '<S231>/TimerOffDelay NoInit' */
  DW_CoreSubsys_PneumaticsSystem_fwu4sljn_T CoreSubsys_pnae[2];/* '<S122>/SandingSystemPerBogie' */
  DW_CoreSubsys_PneumaticsSystem_fwu4sl_T CoreSubsys_pna[2];/* '<S121>/BrakingSystemPerBogie' */
  DW_CoreSubsys_PneumaticsSystem_fwu_T CoreSubsys[2];/* '<S118>/AirSuspensionPerBogie' */
  DW_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit1;/* '<S11>/TimerOffDelay NoInit1' */
  DW_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit;/* '<S11>/TimerOffDelay NoInit' */
} DW_CoreSubsys_PneumaticsSystem_fw_T;

/* Block signals for model 'PneumaticsSystem' */
typedef struct {
  real_T yUp[8];                       /* '<S2>/UpDnSel' */
  real_T yDn[8];                       /* '<S2>/UpDnSel' */
  real_T frontState[8];                /* '<S2>/PipeConnections' */
  real_T rearState[8];                 /* '<S2>/PipeConnections' */
  B_CoreSubsys_PneumaticsSystem_ca_T CoreSubsys_pn[8];/* '<Root>/PneumaticsPerVehicle' */
} B_PneumaticsSystem_c_T;

/* Block states (default storage) for model 'PneumaticsSystem' */
typedef struct {
  real_T UnitDelay_DSTATE[8];          /* '<Root>/Unit Delay' */
  DW_CoreSubsys_PneumaticsSystem_fw_T CoreSubsys_pn[8];/* '<Root>/PneumaticsPerVehicle' */
} DW_PneumaticsSystem_f_T;

/* Invariant block signals for system '<S121>/BrakingSystemPerBogie' */
typedef const struct tag_ConstB_CoreSubsys_PneumaticsSystem_co24gd_T {
  real_T Width;                        /* '<S157>/Width' */
  real_T Width_o;                      /* '<S188>/Width' */
} ConstB_CoreSubsys_PneumaticsSystem_hb4tis_T;

/* Invariant block signals for system '<Root>/PneumaticsPerVehicle' */
typedef const struct tag_ConstB_CoreSubsys_PneumaticsSystem_co_T {
  ConstB_CoreSubsys_PneumaticsSystem_hb4tis_T CoreSubsys_pna;/* '<S121>/BrakingSystemPerBogie' */
} ConstB_CoreSubsys_PneumaticsSystem_hb_T;

/* Invariant block signals for model 'PneumaticsSystem' */
typedef const struct tag_ConstB_PneumaticsSystem_c_T {
  ConstB_CoreSubsys_PneumaticsSystem_hb_T CoreSubsys_pn;/* '<Root>/PneumaticsPerVehicle' */
} ConstB_PneumaticsSystem_h_T;

/* Parameters for system: '<S26>/BSR Vent IC' */
struct P_BSRVentIC_PneumaticsSystem_T_ {
  real_T PuPd_Value;                   /* Expression: 1.89
                                        * Referenced by: '<S31>/PuPd'
                                        */
  real_T piRsqrd_Value;                /* Expression: pi*(d/2)^2
                                        * Referenced by: '<S31>/piRsqrd'
                                        */
  real_T Zero_Value;                   /* Expression: 0.0
                                        * Referenced by: '<S31>/Zero'
                                        */
  real_T C1_Value;                     /* Expression: 2.13e-5
                                        * Referenced by: '<S31>/C1'
                                        */
  real_T Cd_Value;                     /* Expression: 0.75
                                        * Referenced by: '<S31>/Cd'
                                        */
  real_T Zero1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S31>/Zero1'
                                        */
};

/* Parameters for system: '<S26>/BSR Vent Drain' */
struct P_BSRVentDrain_PneumaticsSystem_T_ {
  real_T PuPd_Value;                   /* Expression: 1.89
                                        * Referenced by: '<S30>/PuPd'
                                        */
  real_T piRsqrd_Value;                /* Expression: pi*(d/2)^2
                                        * Referenced by: '<S30>/piRsqrd'
                                        */
  real_T Zero_Value;                   /* Expression: 0.0
                                        * Referenced by: '<S30>/Zero'
                                        */
  real_T C1_Value;                     /* Expression: 2.13e-5
                                        * Referenced by: '<S30>/C1'
                                        */
  real_T Cd_Value;                     /* Expression: 0.75
                                        * Referenced by: '<S30>/Cd'
                                        */
  real_T Zero1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S30>/Zero1'
                                        */
};

/* Parameters for system: '<S11>/TimerOffDelay NoInit' */
struct P_TimerOffDelayNoInit_PneumaticsSystem_T_ {
  real_T OffTime_Value;                /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S38>/OffTime'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Initialise_Value;             /* Expression: 0
                                        * Referenced by: '<S38>/Initialise'
                                        */
  real_T IC_Value;                     /* Expression: 1
                                        * Referenced by: '<S38>/IC'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S38>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperSaturationLimit
                                          * Referenced by: '<S38>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S38>/Discrete-Time Integrator'
                                          */
};

/* Parameters for system: '<S127>/AS Charge' */
struct P_ASCharge_PneumaticsSystem_T_ {
  real_T PuPd_Value;                   /* Expression: 1.89
                                        * Referenced by: '<S133>/PuPd'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1.0
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S133>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi
                                        * Referenced by: '<S133>/Gain1'
                                        */
  real_T Zero_Value;                   /* Expression: 0.0
                                        * Referenced by: '<S133>/Zero'
                                        */
  real_T C1_Value;                     /* Expression: 2.13e-5
                                        * Referenced by: '<S133>/C1'
                                        */
  real_T Cd_Value;                     /* Expression: 0.75
                                        * Referenced by: '<S133>/Cd'
                                        */
  real_T Zero1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S133>/Zero1'
                                        */
};

/* Parameters for system: '<S127>/AS Vent' */
struct P_ASVent_PneumaticsSystem_T_ {
  real_T PuPd_Value;                   /* Expression: 1.89
                                        * Referenced by: '<S134>/PuPd'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1.0
                                        * Referenced by: '<S140>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S140>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi
                                        * Referenced by: '<S134>/Gain1'
                                        */
  real_T Zero_Value;                   /* Expression: 0.0
                                        * Referenced by: '<S134>/Zero'
                                        */
  real_T C1_Value;                     /* Expression: 2.13e-5
                                        * Referenced by: '<S134>/C1'
                                        */
  real_T Cd_Value;                     /* Expression: 0.75
                                        * Referenced by: '<S134>/Cd'
                                        */
  real_T Zero1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S134>/Zero1'
                                        */
};

/* Parameters for system: '<S118>/AirSuspensionPerBogie' */
struct P_CoreSubsys_PneumaticsSystem_gmy_T_ {
  real_T ChargeChoke_DiffGain;         /* Mask Parameter: ChargeChoke_DiffGain
                                        * Referenced by: '<S137>/Constant'
                                        */
  real_T ReleaseChoke_DiffGain;        /* Mask Parameter: ReleaseChoke_DiffGain
                                        * Referenced by: '<S140>/Constant'
                                        */
  real_T ChargeChoke_FullDiam;         /* Mask Parameter: ChargeChoke_FullDiam
                                        * Referenced by: '<S137>/Constant1'
                                        */
  real_T ReleaseChoke_FullDiam;        /* Mask Parameter: ReleaseChoke_FullDiam
                                        * Referenced by: '<S140>/Constant1'
                                        */
  real_T B27L1112_OffOutputValue;     /* Mask Parameter: B27L1112_OffOutputValue
                                       * Referenced by: '<S126>/PressureSwitch'
                                       */
  real_T B27L1112_OnOutputValue;       /* Mask Parameter: B27L1112_OnOutputValue
                                        * Referenced by: '<S126>/PressureSwitch'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S129>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S139>/Constant'
                                      */
  real_T CompareToConstant_const_l; /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S138>/Constant'
                                     */
  real_T ASVentDrain_p_deadband;       /* Mask Parameter: ASVentDrain_p_deadband
                                        * Referenced by: '<S127>/AS Vent Drain'
                                        */
  real_T ASVentIC_p_deadband;          /* Mask Parameter: ASVentIC_p_deadband
                                        * Referenced by: '<S127>/AS Vent IC'
                                        */
  real_T ASVent_p_deadband;            /* Mask Parameter: ASVent_p_deadband
                                        * Referenced by: '<S127>/AS Vent'
                                        */
  real_T ASCharge_p_deadband;          /* Mask Parameter: ASCharge_p_deadband
                                        * Referenced by: '<S127>/AS Charge'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.7
                                        * Referenced by: '<S128>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S128>/Gain1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S128>/Switch1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S128>/Constant'
                                        */
  real_T ExternalIC_Threshold;         /* Expression: 0
                                        * Referenced by: '<S132>/ExternalIC'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S130>/Weighted Sample Time'
                                   */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S123>/Unit Delay'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S130>/Unit Delay1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S128>/Switch2'
                                        */
  real_T WeightedSampleTime_WtEt_b;
                                /* Computed Parameter: WeightedSampleTime_WtEt_b
                                 * Referenced by: '<S145>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value;    /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S145>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: inf
                                        * Referenced by: '<S145>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S145>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S145>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S145>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates;/* Expression: 0
                                            * Referenced by: '<S145>/Discrete Transfer Fcn'
                                            */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<S128>/Gain2'
                                        */
  real_T OnlyIC_Value;                 /* Expression: 0
                                        * Referenced by: '<S132>/OnlyIC'
                                        */
  real_T Initialise_Value;             /* Expression: 1
                                        * Referenced by: '<S132>/Initialise'
                                        */
  real_T Constant_Value_d;             /* Expression: InitOn
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T Initialise_Threshold;         /* Expression: 0
                                        * Referenced by: '<S126>/Initialise'
                                        */
  boolean_T UnitDelay1_InitialCondition_m;
                            /* Computed Parameter: UnitDelay1_InitialCondition_m
                             * Referenced by: '<S123>/Unit Delay1'
                             */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S130>/IC'
                                        */
  boolean_T Constant1_Value_c;         /* Expression: true
                                        * Referenced by: '<S123>/Constant1'
                                        */
  P_BSRVentDrain_PneumaticsSystem_T ASVentDrain;/* '<S127>/AS Vent Drain' */
  P_BSRVentIC_PneumaticsSystem_T ASVentIC;/* '<S127>/AS Vent IC' */
  P_ASVent_PneumaticsSystem_T ASVent;  /* '<S127>/AS Vent' */
  P_ASCharge_PneumaticsSystem_T ASCharge;/* '<S127>/AS Charge' */
};

/* Parameters for system: '<S14>/BogiePressureMapping' */
struct P_CoreSubsys_PneumaticsSystem_gmy0_T_ {
  BD_PneumaticsSystem_Out_Vehicle_Debug_Bogie Constant_Value;/* Computed Parameter: Constant_Value
                                                              * Referenced by: '<S119>/Constant'
                                                              */
};

/* Parameters for system: '<S14>/BogiePressureSwitchesMapping' */
struct P_CoreSubsys_PneumaticsSystem_gmy0o_T_ {
  BD_PneumaticsSystem_Out_Vehicle_Switches_Bogie Constant_Value;/* Computed Parameter: Constant_Value
                                                                 * Referenced by: '<S120>/Constant'
                                                                 */
};

/* Parameters for system: '<S148>/BrakeCylinderSystemPerAxle' */
struct P_CoreSubsys_PneumaticsSystem_gmy0ogc_T_ {
  real_T ChargeChoke_DiffGain;         /* Mask Parameter: ChargeChoke_DiffGain
                                        * Referenced by: '<S201>/Constant'
                                        */
  real_T ReleaseChoke_DiffGain;        /* Mask Parameter: ReleaseChoke_DiffGain
                                        * Referenced by: '<S203>/Constant'
                                        */
  real_T ChargeChoke_FullDiam;         /* Mask Parameter: ChargeChoke_FullDiam
                                        * Referenced by: '<S201>/Constant1'
                                        */
  real_T ReleaseChoke_FullDiam;        /* Mask Parameter: ReleaseChoke_FullDiam
                                        * Referenced by: '<S203>/Constant1'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S202>/Constant'
                                       */
  real_T BCIsolate_p_deadband;         /* Mask Parameter: BCIsolate_p_deadband
                                        * Referenced by: '<S195>/BC Isolate'
                                        */
  real_T BCVent_p_deadband;            /* Mask Parameter: BCVent_p_deadband
                                        * Referenced by: '<S195>/BC Vent'
                                        */
  real_T BCCharge_p_deadband;          /* Mask Parameter: BCCharge_p_deadband
                                        * Referenced by: '<S195>/BC Charge'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S196>/Weighted Sample Time'
                                   */
  real_T BCPressure_Y0;                /* Computed Parameter: BCPressure_Y0
                                        * Referenced by: '<S192>/BCPressure'
                                        */
  real_T BSRtoBCFlow_Y0;               /* Computed Parameter: BSRtoBCFlow_Y0
                                        * Referenced by: '<S192>/BSRtoBCFlow'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S194>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S194>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S192>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S196>/Unit Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S193>/Constant'
                                        */
  boolean_T UnitDelay1_InitialCondition_o;
                            /* Computed Parameter: UnitDelay1_InitialCondition_o
                             * Referenced by: '<S192>/Unit Delay1'
                             */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S196>/IC'
                                        */
  boolean_T Constant1_Value;           /* Expression: true
                                        * Referenced by: '<S192>/Constant1'
                                        */
  P_ASCharge_PneumaticsSystem_T BCCharge;/* '<S195>/BC Charge' */
  P_BSRVentDrain_PneumaticsSystem_T BCIsolate;/* '<S195>/BC Isolate' */
  P_ASVent_PneumaticsSystem_T BCVent;  /* '<S195>/BC Vent' */
};

/* Parameters for system: '<S153>/If Action Subsystem5' */
struct P_IfActionSubsystem5_PneumaticsSystem_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S173>/Out1'
                                        */
};

/* Parameters for system: '<S121>/BrakingSystemPerBogie' */
struct P_CoreSubsys_PneumaticsSystem_gmy0og_T_ {
  real_T B2728B07_OffOutputValue;     /* Mask Parameter: B2728B07_OffOutputValue
                                       * Referenced by: '<S185>/PressureSwitch'
                                       */
  real_T B27B14_OffOutputValue;        /* Mask Parameter: B27B14_OffOutputValue
                                        * Referenced by: '<S207>/PressureSwitch'
                                        */
  real_T B2728B07_OnOutputValue;       /* Mask Parameter: B2728B07_OnOutputValue
                                        * Referenced by: '<S185>/PressureSwitch'
                                        */
  real_T B27B14_OnOutputValue;         /* Mask Parameter: B27B14_OnOutputValue
                                        * Referenced by: '<S207>/PressureSwitch'
                                        */
  real_T BrakeCylinderPressureCalc_bcArea;
                             /* Mask Parameter: BrakeCylinderPressureCalc_bcArea
                              * Referenced by: '<S154>/Constant1'
                              */
  real_T BrakeCylinderPressureCalc_bcPreload;
                          /* Mask Parameter: BrakeCylinderPressureCalc_bcPreload
                           * Referenced by: '<S154>/Constant5'
                           */
  real_T BrakeCylinderPressureCalc_brkBeamFactor;
                      /* Mask Parameter: BrakeCylinderPressureCalc_brkBeamFactor
                       * Referenced by: '<S154>/Constant2'
                       */
  real_T BrakeCylinderPressureCalc_brkEfficiency;
                      /* Mask Parameter: BrakeCylinderPressureCalc_brkEfficiency
                       * Referenced by: '<S154>/Constant3'
                       */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S155>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S159>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S161>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S160>/Constant'
                                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S158>/Constant'
                                      */
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S162>/Constant'
                                      */
  real_T BrakeCylinderPressureCalc_noBrakeCyl;
                         /* Mask Parameter: BrakeCylinderPressureCalc_noBrakeCyl
                          * Referenced by: '<S154>/Constant'
                          */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S163>/Delay Input1'
                                        */
  real_T DetectDecrease1_vinit;        /* Mask Parameter: DetectDecrease1_vinit
                                        * Referenced by: '<S164>/Delay Input1'
                                        */
  real_T DetectDecrease2_vinit;        /* Mask Parameter: DetectDecrease2_vinit
                                        * Referenced by: '<S165>/Delay Input1'
                                        */
  real_T DetectDecrease3_vinit;        /* Mask Parameter: DetectDecrease3_vinit
                                        * Referenced by: '<S166>/Delay Input1'
                                        */
  real_T DetectDecrease6_vinit;        /* Mask Parameter: DetectDecrease6_vinit
                                        * Referenced by: '<S169>/Delay Input1'
                                        */
  boolean_T SRLatchResetPriority1_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority1_initial_condition
                       * Referenced by: '<S175>/Memory'
                       */
  boolean_T SRLatchResetPriority2_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority2_initial_condition
                       * Referenced by: '<S176>/Memory'
                       */
  boolean_T SRLatchResetPriority3_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority3_initial_condition
                       * Referenced by: '<S177>/Memory'
                       */
  boolean_T SRLatchResetPriority4_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority4_initial_condition
                       * Referenced by: '<S178>/Memory'
                       */
  boolean_T SRLatchResetPriority5_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority5_initial_condition
                       * Referenced by: '<S179>/Memory'
                       */
  boolean_T SRLatchResetPriority6_initial_condition;
                      /* Mask Parameter: SRLatchResetPriority6_initial_condition
                       * Referenced by: '<S180>/Memory'
                       */
  boolean_T MagnetValve_B20_initial_condition;
                            /* Mask Parameter: MagnetValve_B20_initial_condition
                             * Referenced by: '<S209>/Memory'
                             */
  boolean_T DetectDecrease5_vinit;     /* Mask Parameter: DetectDecrease5_vinit
                                        * Referenced by: '<S168>/Delay Input1'
                                        */
  boolean_T DetectDecrease4_vinit;     /* Mask Parameter: DetectDecrease4_vinit
                                        * Referenced by: '<S167>/Delay Input1'
                                        */
  BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie Constant_Value;/* Computed Parameter: Constant_Value
                                                             * Referenced by: '<S153>/Constant'
                                                             */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S152>/Switch3'
                                        */
  real_T ExternalIC_Threshold;         /* Expression: 0
                                        * Referenced by: '<S210>/ExternalIC'
                                        */
  real_T ExternalIC_Threshold_b;       /* Expression: 0
                                        * Referenced by: '<S190>/ExternalIC'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S149>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S149>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S170>/Constant3'
                                        */
  real_T Out2_Y0;                      /* Expression: 0
                                        * Referenced by: '<S170>/Out2'
                                        */
  real_T Constant4_Value;              /* Expression: 1e6
                                        * Referenced by: '<S170>/Constant4'
                                        */
  real_T sampletime_WtEt;              /* Computed Parameter: sampletime_WtEt
                                        * Referenced by: '<S181>/sample time'
                                        */
  real_T DelayInput2_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S181>/Delay Input2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S171>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S186>/Constant'
                                        */
  real_T OnlyIC_Value;                 /* Expression: 0
                                        * Referenced by: '<S190>/OnlyIC'
                                        */
  real_T Initialise_Value;             /* Expression: 1
                                        * Referenced by: '<S190>/Initialise'
                                        */
  real_T Proportion_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S157>/Proportion'
                                        */
  real_T Proportion_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S157>/Proportion'
                                        */
  real_T Constant4_Value_j;            /* Expression: 100
                                        * Referenced by: '<S154>/Constant4'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S156>/Weighted Sample Time'
                                   */
  real_T FilterSpecification_Value;    /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S156>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S156>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S156>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates;/* Expression: 0
                                            * Referenced by: '<S156>/Discrete Transfer Fcn'
                                            */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S149>/Switch2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S149>/Switch1'
                                        */
  real_T RegulatingValve02_LowerSat;   /* Expression: 0
                                        * Referenced by: '<S149>/Regulating Valve 02'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: inf
                                        * Referenced by: '<S188>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 1
                                        * Referenced by: '<S188>/Saturation'
                                        */
  real_T WeightedSampleTime_WtEt_j;
                                /* Computed Parameter: WeightedSampleTime_WtEt_j
                                 * Referenced by: '<S187>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_m;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S187>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: inf
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S187>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S187>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_i;/* Expression: 0
                                              * Referenced by: '<S187>/Discrete Transfer Fcn'
                                              */
  real_T Constant_Value_ou;            /* Expression: InitOn
                                        * Referenced by: '<S185>/Constant'
                                        */
  real_T Initialise_Threshold;         /* Expression: 0
                                        * Referenced by: '<S185>/Initialise'
                                        */
  real_T Constant3_Value_p;            /* Expression: 1
                                        * Referenced by: '<S153>/Constant3'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S153>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S153>/Constant2'
                                        */
  real_T WeightedSampleTime_WtEt_b;
                                /* Computed Parameter: WeightedSampleTime_WtEt_b
                                 * Referenced by: '<S208>/Weighted Sample Time'
                                 */
  real_T FilterSpecification_Value_o;  /* Expression: FilterSpecificationValue
                                        * Referenced by: '<S208>/FilterSpecification'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: inf
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: 0
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S208>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S208>/Constant'
                                        */
  real_T DiscreteTransferFcn_InitialStates_o;/* Expression: 0
                                              * Referenced by: '<S208>/Discrete Transfer Fcn'
                                              */
  real_T OnlyIC_Value_p;               /* Expression: 0
                                        * Referenced by: '<S210>/OnlyIC'
                                        */
  real_T Initialise_Value_c;           /* Expression: 1
                                        * Referenced by: '<S210>/Initialise'
                                        */
  real_T Constant_Value_a;             /* Expression: InitOn
                                        * Referenced by: '<S207>/Constant'
                                        */
  real_T Initialise_Threshold_l;       /* Expression: 0
                                        * Referenced by: '<S207>/Initialise'
                                        */
  uint8_T Switch1_Threshold_o;        /* Computed Parameter: Switch1_Threshold_o
                                       * Referenced by: '<S150>/Switch1'
                                       */
  P_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem6;/* '<S153>/If Action Subsystem6' */
  P_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem4;/* '<S153>/If Action Subsystem4' */
  P_IfActionSubsystem5_PneumaticsSystem_T IfActionSubsystem5;/* '<S153>/If Action Subsystem5' */
  P_CoreSubsys_PneumaticsSystem_gmy0ogc_T CoreSubsys;/* '<S148>/BrakeCylinderSystemPerAxle' */
};

/* Parameters for system: '<S122>/SandingSystemPerBogie' */
struct P_CoreSubsys_PneumaticsSystem_gmy0ogcc_T_ {
  real_T SandingPressureSwitch10_OffOutputValue;
                       /* Mask Parameter: SandingPressureSwitch10_OffOutputValue
                        * Referenced by: '<S212>/PressureSwitch'
                        */
  real_T SandingPressureSwitch10_OnOutputValue;
                        /* Mask Parameter: SandingPressureSwitch10_OnOutputValue
                         * Referenced by: '<S212>/PressureSwitch'
                         */
  real_T ExternalIC_Threshold;         /* Expression: 0
                                        * Referenced by: '<S213>/ExternalIC'
                                        */
  real_T OnlyIC_Value;                 /* Expression: 0
                                        * Referenced by: '<S213>/OnlyIC'
                                        */
  real_T Initialise_Value;             /* Expression: 1
                                        * Referenced by: '<S213>/Initialise'
                                        */
  real_T Constant_Value;               /* Expression: InitOn
                                        * Referenced by: '<S212>/Constant'
                                        */
  real_T Initialise_Threshold;         /* Expression: 0
                                        * Referenced by: '<S212>/Initialise'
                                        */
};

/* Parameters for system: '<S16>/Subsystem' */
struct P_CoreSubsys_PneumaticsSystem_gmy0ogccz_T_ {
  BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie Constant1_Value;/* Computed Parameter: Constant1_Value
                                                                * Referenced by: '<S228>/Constant1'
                                                                */
};

/* Parameters for system: '<S231>/MR Pipe Two Way Valve' */
struct P_MRPipeTwoWayValve_PneumaticsSystem_T_ {
  P_BSRVentDrain_PneumaticsSystem_T Reverse;/* '<S237>/Reverse' */
  P_BSRVentDrain_PneumaticsSystem_T Forward;/* '<S237>/Forward' */
};

/* Parameters for system: '<Root>/PneumaticsPerVehicle' */
struct P_CoreSubsys_PneumaticsSystem_gm_T_ {
  real_T AirSuspensionReservoir_MaxPressure;
                           /* Mask Parameter: AirSuspensionReservoir_MaxPressure
                            * Referenced by: '<S24>/Constant'
                            */
  real_T ARPressureSwitch12_OffOutputValue;
                            /* Mask Parameter: ARPressureSwitch12_OffOutputValue
                             * Referenced by: '<S63>/PressureSwitch'
                             */
  real_T PS2_OffOutputValue;           /* Mask Parameter: PS2_OffOutputValue
                                        * Referenced by: '<S79>/PressureSwitch'
                                        */
  real_T PanPressureSwitch_OffOutputValue;
                             /* Mask Parameter: PanPressureSwitch_OffOutputValue
                              * Referenced by: '<S80>/PressureSwitch'
                              */
  real_T VCBPressureSwitch1_OffOutputValue;
                            /* Mask Parameter: VCBPressureSwitch1_OffOutputValue
                             * Referenced by: '<S104>/PressureSwitch'
                             */
  real_T BSRPressureSwitch05_OffOutputValue;
                           /* Mask Parameter: BSRPressureSwitch05_OffOutputValue
                            * Referenced by: '<S215>/PressureSwitch'
                            */
  real_T MRPressureSwitch06_OffOutputValue;
                            /* Mask Parameter: MRPressureSwitch06_OffOutputValue
                             * Referenced by: '<S232>/PressureSwitch'
                             */
  real_T A00A14_OffOutputValue;        /* Mask Parameter: A00A14_OffOutputValue
                                        * Referenced by: '<S253>/PressureSwitch'
                                        */
  real_T B27B22_OffOutputValue;        /* Mask Parameter: B27B22_OffOutputValue
                                        * Referenced by: '<S254>/PressureSwitch'
                                        */
  real_T B27B22_OffSwitchValue;        /* Mask Parameter: B27B22_OffSwitchValue
                                        * Referenced by: '<S254>/PressureSwitch'
                                        */
  real_T ARPressureSwitch12_OnOutputValue;
                             /* Mask Parameter: ARPressureSwitch12_OnOutputValue
                              * Referenced by: '<S63>/PressureSwitch'
                              */
  real_T PS2_OnOutputValue;            /* Mask Parameter: PS2_OnOutputValue
                                        * Referenced by: '<S79>/PressureSwitch'
                                        */
  real_T PanPressureSwitch_OnOutputValue;
                              /* Mask Parameter: PanPressureSwitch_OnOutputValue
                               * Referenced by: '<S80>/PressureSwitch'
                               */
  real_T VCBPressureSwitch1_OnOutputValue;
                             /* Mask Parameter: VCBPressureSwitch1_OnOutputValue
                              * Referenced by: '<S104>/PressureSwitch'
                              */
  real_T BSRPressureSwitch05_OnOutputValue;
                            /* Mask Parameter: BSRPressureSwitch05_OnOutputValue
                             * Referenced by: '<S215>/PressureSwitch'
                             */
  real_T MRPressureSwitch06_OnOutputValue;
                             /* Mask Parameter: MRPressureSwitch06_OnOutputValue
                              * Referenced by: '<S232>/PressureSwitch'
                              */
  real_T A00A14_OnOutputValue;         /* Mask Parameter: A00A14_OnOutputValue
                                        * Referenced by: '<S253>/PressureSwitch'
                                        */
  real_T B27B22_OnOutputValue;         /* Mask Parameter: B27B22_OnOutputValue
                                        * Referenced by: '<S254>/PressureSwitch'
                                        */
  real_T B27B22_OnSwitchValue;         /* Mask Parameter: B27B22_OnSwitchValue
                                        * Referenced by:
                                        *   '<S254>/InitialConditionValue'
                                        *   '<S254>/PressureSwitch'
                                        */
  real_T AirSuspensionReservoir_ResetPressure;
                         /* Mask Parameter: AirSuspensionReservoir_ResetPressure
                          * Referenced by: '<S25>/Constant1'
                          */
  real_T AirSuspensionReservoir_Volume;
                                /* Mask Parameter: AirSuspensionReservoir_Volume
                                 * Referenced by: '<S24>/pAtm2'
                                 */
  real_T HighHorn_const;               /* Mask Parameter: HighHorn_const
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T LowHorn_const;                /* Mask Parameter: LowHorn_const
                                        * Referenced by: '<S117>/Constant'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S224>/Constant'
                                       */
  real_T CompareToConstant_const_a; /* Mask Parameter: CompareToConstant_const_a
                                     * Referenced by: '<S32>/Constant'
                                     */
  real_T BSRVentDrain_p_deadband;     /* Mask Parameter: BSRVentDrain_p_deadband
                                       * Referenced by: '<S26>/BSR Vent Drain'
                                       */
  real_T BSRVentIC_p_deadband;         /* Mask Parameter: BSRVentIC_p_deadband
                                        * Referenced by: '<S26>/BSR Vent IC'
                                        */
  real_T ARVentDrain_p_deadband;       /* Mask Parameter: ARVentDrain_p_deadband
                                        * Referenced by: '<S65>/AR Vent Drain'
                                        */
  real_T ARBlowoff_p_deadband;         /* Mask Parameter: ARBlowoff_p_deadband
                                        * Referenced by: '<S65>/AR Blowoff'
                                        */
  real_T PCVentIsol_p_deadband;        /* Mask Parameter: PCVentIsol_p_deadband
                                        * Referenced by: '<S77>/PC Vent Isol'
                                        */
  real_T PCVentControl_p_deadband;   /* Mask Parameter: PCVentControl_p_deadband
                                      * Referenced by: '<S77>/PC Vent Control'
                                      */
  real_T VCBIsolate_p_deadband;        /* Mask Parameter: VCBIsolate_p_deadband
                                        * Referenced by: '<S102>/VCB Isolate'
                                        */
  real_T VCBVent_p_deadband;           /* Mask Parameter: VCBVent_p_deadband
                                        * Referenced by: '<S102>/VCB Vent'
                                        */
  real_T ARChargefromMRP_p_deadband;
                                   /* Mask Parameter: ARChargefromMRP_p_deadband
                                    * Referenced by: '<S65>/AR Charge from MRP'
                                    */
  real_T PCVentEmer_p_deadband;        /* Mask Parameter: PCVentEmer_p_deadband
                                        * Referenced by: '<S77>/PC Vent Emer'
                                        */
  real_T ARCharge_p_deadband;          /* Mask Parameter: ARCharge_p_deadband
                                        * Referenced by: '<S77>/AR Charge'
                                        */
  real_T VCBCharge_p_deadband;         /* Mask Parameter: VCBCharge_p_deadband
                                        * Referenced by: '<S102>/VCB Charge'
                                        */
  real_T BSRVentDrain_p_deadband_a; /* Mask Parameter: BSRVentDrain_p_deadband_a
                                     * Referenced by: '<S217>/BSR Vent Drain'
                                     */
  real_T BSRVentIC_p_deadband_e;       /* Mask Parameter: BSRVentIC_p_deadband_e
                                        * Referenced by: '<S217>/BSR Vent IC'
                                        */
  real_T BSRCharge_p_deadband;         /* Mask Parameter: BSRCharge_p_deadband
                                        * Referenced by: '<S217>/BSR Charge'
                                        */
  real_T CouplingExtraMRP_p_deadband;
                                  /* Mask Parameter: CouplingExtraMRP_p_deadband
                                   * Referenced by: '<S234>/Dead Zone'
                                   */
  real_T MRVentDrain_p_deadband;       /* Mask Parameter: MRVentDrain_p_deadband
                                        * Referenced by: '<S231>/MR Vent Drain'
                                        */
  real_T MRBlowoff_p_deadband;         /* Mask Parameter: MRBlowoff_p_deadband
                                        * Referenced by: '<S231>/MR Blowoff'
                                        */
  real_T MRPipeTwoWayValve_p_deadband;
                                 /* Mask Parameter: MRPipeTwoWayValve_p_deadband
                                  * Referenced by: '<S231>/MR Pipe Two Way Valve'
                                  */
  real_T MRPtoDownstreamConnection_p_deadband;
                         /* Mask Parameter: MRPtoDownstreamConnection_p_deadband
                          * Referenced by: '<S255>/MRP to Downstream Connection'
                          */
  real_T MRPtoUpstreamConnection_p_deadband;
                           /* Mask Parameter: MRPtoUpstreamConnection_p_deadband
                            * Referenced by: '<S255>/MRP to Upstream Connection'
                            */
  real_T BSRCharge_p_deadband_d;       /* Mask Parameter: BSRCharge_p_deadband_d
                                        * Referenced by: '<S26>/BSR Charge'
                                        */
  real_T DetectDecrease_vinit;         /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S76>/Delay Input1'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S98>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_j;       /* Mask Parameter: DetectDecrease_vinit_j
                                        * Referenced by: '<S40>/Delay Input1'
                                        */
  real_T DetectDecrease14_vinit;       /* Mask Parameter: DetectDecrease14_vinit
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  real_T DetectDecrease1_vinit;        /* Mask Parameter: DetectDecrease1_vinit
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  real_T DetectDecrease2_vinit;        /* Mask Parameter: DetectDecrease2_vinit
                                        * Referenced by: '<S48>/Delay Input1'
                                        */
  real_T DetectDecrease3_vinit;        /* Mask Parameter: DetectDecrease3_vinit
                                        * Referenced by: '<S49>/Delay Input1'
                                        */
  real_T DetectDecrease4_vinit;        /* Mask Parameter: DetectDecrease4_vinit
                                        * Referenced by: '<S50>/Delay Input1'
                                        */
  real_T DetectDecrease5_vinit;        /* Mask Parameter: DetectDecrease5_vinit
                                        * Referenced by: '<S51>/Delay Input1'
                                        */
  real_T DetectDecrease6_vinit;        /* Mask Parameter: DetectDecrease6_vinit
                                        * Referenced by: '<S52>/Delay Input1'
                                        */
  real_T DetectDecrease7_vinit;        /* Mask Parameter: DetectDecrease7_vinit
                                        * Referenced by: '<S53>/Delay Input1'
                                        */
  real_T DetectDecrease8_vinit;        /* Mask Parameter: DetectDecrease8_vinit
                                        * Referenced by: '<S54>/Delay Input1'
                                        */
  real_T DetectDecrease9_vinit;        /* Mask Parameter: DetectDecrease9_vinit
                                        * Referenced by: '<S55>/Delay Input1'
                                        */
  real_T DetectDecrease10_vinit;       /* Mask Parameter: DetectDecrease10_vinit
                                        * Referenced by: '<S42>/Delay Input1'
                                        */
  real_T DetectDecrease11_vinit;       /* Mask Parameter: DetectDecrease11_vinit
                                        * Referenced by: '<S43>/Delay Input1'
                                        */
  real_T DetectDecrease12_vinit;       /* Mask Parameter: DetectDecrease12_vinit
                                        * Referenced by: '<S44>/Delay Input1'
                                        */
  real_T DetectDecrease13_vinit;       /* Mask Parameter: DetectDecrease13_vinit
                                        * Referenced by: '<S45>/Delay Input1'
                                        */
  real_T DetectDecrease15_vinit;       /* Mask Parameter: DetectDecrease15_vinit
                                        * Referenced by: '<S47>/Delay Input1'
                                        */
  real_T DetectDecrease_vinit_c;       /* Mask Parameter: DetectDecrease_vinit_c
                                        * Referenced by: '<S36>/Delay Input1'
                                        */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S99>/Memory'
                                  */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S235>/Delay Input1'
                                        */
  BD_PneumaticsSystem_Out_Vehicle PenumaticsVehicleOut_Y0;
                                  /* Computed Parameter: PenumaticsVehicleOut_Y0
                                   * Referenced by: '<S9>/PenumaticsVehicleOut'
                                   */
  BD_PneumaticsSystem_Out_Vehicle_Debug Constant_Value;/* Computed Parameter: Constant_Value
                                                        * Referenced by: '<S19>/Constant'
                                                        */
  BD_PneumaticsSystem_Out_Vehicle_Switches Constant_Value_n;/* Computed Parameter: Constant_Value_n
                                                             * Referenced by: '<S21>/Constant'
                                                             */
  BD_PneumaticsSystem_Out_Vehicle_Gauges Constant_Value_p;/* Computed Parameter: Constant_Value_p
                                                           * Referenced by: '<S16>/Constant'
                                                           */
  BD_PneumaticsSystem_Out_Vehicle_Transducers_Bogie BCUPressureTransducers_Y0;
                                /* Computed Parameter: BCUPressureTransducers_Y0
                                 * Referenced by: '<S121>/BCUPressureTransducers'
                                 */
  struct_pstkrRYuTizE8LmMqadwGC PressureSwitches_Y0;
                                      /* Computed Parameter: PressureSwitches_Y0
                                       * Referenced by: '<S58>/PressureSwitches'
                                       */
  struct_ylqIrRqgnuacN7w5OmlN1C PantoSystemPressures_Y0;
                                  /* Computed Parameter: PantoSystemPressures_Y0
                                   * Referenced by: '<S58>/PantoSystemPressures'
                                   */
  BD_PneumaticsSystem_Out_Vehicle_Gauges_Bogie BrakeSystemGauges_Y0;
                                     /* Computed Parameter: BrakeSystemGauges_Y0
                                      * Referenced by: '<S121>/BrakeSystemGauges'
                                      */
  BD_PneumaticsSystem_Out_Vehicle_TCMS_Bogie FaultMessages_Y0;/* Computed Parameter: FaultMessages_Y0
                                                               * Referenced by: '<S121>/FaultMessages'
                                                               */
  struct_1YI8GwFFQsLNC6JiQRPuWE AudioOut_Y0;/* Computed Parameter: AudioOut_Y0
                                             * Referenced by: '<S59>/AudioOut'
                                             */
  struct_6zPdHGimiatdtWuKyP0SWB PressureSwitches_Y0_d;
                                    /* Computed Parameter: PressureSwitches_Y0_d
                                     * Referenced by: '<S59>/PressureSwitches'
                                     */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T WeightedSampleTime_WtEt; /* Computed Parameter: WeightedSampleTime_WtEt
                                   * Referenced by: '<S27>/Weighted Sample Time'
                                   */
  real_T ExternalIC_Threshold;         /* Expression: 0
                                        * Referenced by: '<S66>/ExternalIC'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S65>/Switch1'
                                        */
  real_T WeightedSampleTime_WtEt_o;
                                /* Computed Parameter: WeightedSampleTime_WtEt_o
                                 * Referenced by: '<S67>/Weighted Sample Time'
                                 */
  real_T WeightedSampleTime_WtEt_i;
                                /* Computed Parameter: WeightedSampleTime_WtEt_i
                                 * Referenced by: '<S85>/Weighted Sample Time'
                                 */
  real_T ExternalIC_Threshold_j;       /* Expression: 0
                                        * Referenced by: '<S96>/ExternalIC'
                                        */
  real_T ExternalIC_Threshold_i;       /* Expression: 0
                                        * Referenced by: '<S97>/ExternalIC'
                                        */
  real_T WeightedSampleTime_WtEt_c;
                                /* Computed Parameter: WeightedSampleTime_WtEt_c
                                 * Referenced by: '<S100>/Weighted Sample Time'
                                 */
  real_T WeightedSampleTime_WtEt_p;
                                /* Computed Parameter: WeightedSampleTime_WtEt_p
                                 * Referenced by: '<S111>/Weighted Sample Time'
                                 */
  real_T ExternalIC_Threshold_c;       /* Expression: 0
                                        * Referenced by: '<S113>/ExternalIC'
                                        */
  real_T MRPToAuxR_Y0;                 /* Computed Parameter: MRPToAuxR_Y0
                                        * Referenced by: '<S58>/MRPToAuxR'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S58>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S58>/Unit Delay1'
                                        */
  real_T Constant_Value_d;             /* Expression: InitOn
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T OnlyIC_Value;                 /* Expression: 0
                                        * Referenced by: '<S66>/OnlyIC'
                                        */
  real_T Initialise_Value;             /* Expression: 1
                                        * Referenced by: '<S66>/Initialise'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S60>/Unit Delay'
                                        */
  real_T Overpressure_YOn;             /* Expression: 1
                                        * Referenced by: '<S65>/Overpressure'
                                        */
  real_T Overpressure_YOff;            /* Expression: 0
                                        * Referenced by: '<S65>/Overpressure'
                                        */
  real_T UnitDelay1_InitialCondition_p;/* Expression: 0
                                        * Referenced by: '<S67>/Unit Delay1'
                                        */
  real_T Initialise_Threshold;         /* Expression: 0
                                        * Referenced by: '<S63>/Initialise'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: inf
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: eps
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition_kr;/* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay1'
                                        */
  real_T UnitDelay1_InitialCondition_a;/* Expression: 0
                                        * Referenced by: '<S85>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: inf
                                        * Referenced by: '<S82>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: eps
                                        * Referenced by: '<S82>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition_e3;/* Expression: 0
                                         * Referenced by: '<S100>/Unit Delay1'
                                         */
  real_T Constant_Value_h;             /* Expression: InitOn
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T OnlyIC_Value_f;               /* Expression: 0
                                        * Referenced by: '<S96>/OnlyIC'
                                        */
  real_T Initialise_Value_f;           /* Expression: 1
                                        * Referenced by: '<S96>/Initialise'
                                        */
  real_T Initialise_Threshold_l;       /* Expression: 0
                                        * Referenced by: '<S79>/Initialise'
                                        */
  real_T Constant_Value_nc;            /* Expression: InitOn
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T OnlyIC_Value_n;               /* Expression: 0
                                        * Referenced by: '<S97>/OnlyIC'
                                        */
  real_T Initialise_Value_g;           /* Expression: 1
                                        * Referenced by: '<S97>/Initialise'
                                        */
  real_T Initialise_Threshold_p;       /* Expression: 0
                                        * Referenced by: '<S80>/Initialise'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S103>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: eps
                                        * Referenced by: '<S103>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition_n;/* Expression: 0
                                        * Referenced by: '<S62>/Unit Delay1'
                                        */
  real_T UnitDelay1_InitialCondition_i;/* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay1'
                                        */
  real_T Constant_Value_c;             /* Expression: InitOn
                                        * Referenced by: '<S104>/Constant'
                                        */
  real_T OnlyIC_Value_nw;              /* Expression: 0
                                        * Referenced by: '<S113>/OnlyIC'
                                        */
  real_T Initialise_Value_k;           /* Expression: 1
                                        * Referenced by: '<S113>/Initialise'
                                        */
  real_T Initialise_Threshold_h;       /* Expression: 0
                                        * Referenced by: '<S104>/Initialise'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S59>/Gain1'
                                        */
  real_T AirSuspensionPressure_Y0;
                                 /* Computed Parameter: AirSuspensionPressure_Y0
                                  * Referenced by: '<S118>/AirSuspensionPressure'
                                  */
  real_T ASPressureSwitches_Y0;     /* Computed Parameter: ASPressureSwitches_Y0
                                     * Referenced by: '<S118>/ASPressureSwitches'
                                     */
  real_T AirSuspPressureVariation_Y0;
                              /* Computed Parameter: AirSuspPressureVariation_Y0
                               * Referenced by: '<S118>/AirSuspPressure%Variation'
                               */
  real_T ASRToAS_Y0;                   /* Computed Parameter: ASRToAS_Y0
                                        * Referenced by: '<S118>/ASRToAS'
                                        */
  real_T BSRtoVehicleBCFlow_Y0;     /* Computed Parameter: BSRtoVehicleBCFlow_Y0
                                     * Referenced by: '<S121>/BSRtoVehicleBCFlow'
                                     */
  real_T BrakeControlPressures_Y0;
                                 /* Computed Parameter: BrakeControlPressures_Y0
                                  * Referenced by: '<S121>/BrakeControlPressures'
                                  */
  real_T BrakeCylinderPressures_Y0;
                                /* Computed Parameter: BrakeCylinderPressures_Y0
                                 * Referenced by: '<S121>/BrakeCylinderPressures'
                                 */
  real_T ParkBrakePressures_Y0;     /* Computed Parameter: ParkBrakePressures_Y0
                                     * Referenced by: '<S121>/ParkBrakePressures'
                                     */
  real_T BrakeCylinderPressureSwitches_Y0;
                         /* Computed Parameter: BrakeCylinderPressureSwitches_Y0
                          * Referenced by: '<S121>/BrakeCylinderPressureSwitches'
                          */
  real_T ParkBrakePressureSwitches_Y0;
                             /* Computed Parameter: ParkBrakePressureSwitches_Y0
                              * Referenced by: '<S121>/ParkBrakePressureSwitches'
                              */
  real_T SandingPressures_Y0;         /* Computed Parameter: SandingPressures_Y0
                                       * Referenced by: '<S122>/SandingPressures'
                                       */
  real_T SandingPressureSwitches_Y0;
                               /* Computed Parameter: SandingPressureSwitches_Y0
                                * Referenced by: '<S122>/SandingPressureSwitches'
                                */
  real_T ExternalIC_Threshold_o;       /* Expression: 0
                                        * Referenced by: '<S218>/ExternalIC'
                                        */
  real_T WeightedSampleTime_WtEt_e;
                                /* Computed Parameter: WeightedSampleTime_WtEt_e
                                 * Referenced by: '<S219>/Weighted Sample Time'
                                 */
  real_T BSRPressure_Y0;               /* Computed Parameter: BSRPressure_Y0
                                        * Referenced by: '<S214>/BSRPressure'
                                        */
  real_T BSRPressureSwitch_Y0;       /* Computed Parameter: BSRPressureSwitch_Y0
                                      * Referenced by: '<S214>/BSRPressureSwitch'
                                      */
  real_T MRPToBSR_Y0;                  /* Computed Parameter: MRPToBSR_Y0
                                        * Referenced by: '<S214>/MRPToBSR'
                                        */
  real_T BSRPressureGauge_Y0;         /* Computed Parameter: BSRPressureGauge_Y0
                                       * Referenced by: '<S214>/BSRPressureGauge'
                                       */
  real_T Constant_Value_c1;            /* Expression: InitOn
                                        * Referenced by: '<S215>/Constant'
                                        */
  real_T OnlyIC_Value_k;               /* Expression: 0
                                        * Referenced by: '<S218>/OnlyIC'
                                        */
  real_T Initialise_Value_i;           /* Expression: 1
                                        * Referenced by: '<S218>/Initialise'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: inf
                                        * Referenced by: '<S216>/Saturation'
                                        */
  real_T Saturation_LowerSat_pf;       /* Expression: eps
                                        * Referenced by: '<S216>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S214>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_o;/* Expression: 0
                                        * Referenced by: '<S219>/Unit Delay1'
                                        */
  real_T Initialise_Threshold_i;       /* Expression: 0
                                        * Referenced by: '<S215>/Initialise'
                                        */
  real_T ExternalIC_Threshold_k;       /* Expression: 0
                                        * Referenced by: '<S250>/ExternalIC'
                                        */
  real_T PuPd_Value;                   /* Expression: 1.89
                                        * Referenced by: '<S234>/PuPd'
                                        */
  real_T piRsqrd_Value;                /* Expression: pi*(d/2)^2
                                        * Referenced by: '<S234>/piRsqrd'
                                        */
  real_T Zero_Value;                   /* Expression: 0.0
                                        * Referenced by: '<S234>/Zero'
                                        */
  real_T Constant1_Value;              /* Expression: 500000
                                        * Referenced by: '<S231>/Constant1'
                                        */
  real_T C1_Value;                     /* Expression: 2.13e-5
                                        * Referenced by: '<S234>/C1'
                                        */
  real_T Cd_Value;                     /* Expression: 0.75
                                        * Referenced by: '<S234>/Cd'
                                        */
  real_T Zero1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S234>/Zero1'
                                        */
  real_T Switch1_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S231>/Switch1'
                                        */
  real_T WeightedSampleTime_WtEt_j;
                                /* Computed Parameter: WeightedSampleTime_WtEt_j
                                 * Referenced by: '<S251>/Weighted Sample Time'
                                 */
  real_T MRPressure_Y0;                /* Computed Parameter: MRPressure_Y0
                                        * Referenced by: '<S229>/MRPressure'
                                        */
  real_T MRPressureSwitch_Y0;         /* Computed Parameter: MRPressureSwitch_Y0
                                       * Referenced by: '<S229>/MRPressureSwitch'
                                       */
  real_T MRPToMRFlow_Y0;               /* Computed Parameter: MRPToMRFlow_Y0
                                        * Referenced by: '<S229>/MRPToMRFlow'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S233>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: eps
                                        * Referenced by: '<S233>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S229>/Unit Delay'
                                        */
  real_T Overpressure_YOn_f;           /* Expression: 1
                                        * Referenced by: '<S231>/Overpressure'
                                        */
  real_T Overpressure_YOff_p;          /* Expression: 0
                                        * Referenced by: '<S231>/Overpressure'
                                        */
  real_T UnitDelay1_InitialCondition_d;/* Expression: 0
                                        * Referenced by: '<S251>/Unit Delay1'
                                        */
  real_T Constant_Value_de;            /* Expression: InitOn
                                        * Referenced by: '<S232>/Constant'
                                        */
  real_T OnlyIC_Value_a;               /* Expression: 0
                                        * Referenced by: '<S250>/OnlyIC'
                                        */
  real_T Initialise_Value_l;           /* Expression: 1
                                        * Referenced by: '<S250>/Initialise'
                                        */
  real_T Initialise_Threshold_ir;      /* Expression: 0
                                        * Referenced by: '<S232>/Initialise'
                                        */
  real_T ExternalIC_Threshold_kz;      /* Expression: 0
                                        * Referenced by: '<S257>/ExternalIC'
                                        */
  real_T ExternalIC_Threshold_i0;      /* Expression: 0
                                        * Referenced by: '<S258>/ExternalIC'
                                        */
  real_T WeightedSampleTime_WtEt_p0;
                               /* Computed Parameter: WeightedSampleTime_WtEt_p0
                                * Referenced by: '<S273>/Weighted Sample Time'
                                */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: eps
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T MRVolume_Value;               /* Expression: 75*0.001
                                        * Referenced by: '<S230>/MR Volume'
                                        */
  real_T Saturation_UpperSat_mq;       /* Expression: inf
                                        * Referenced by: '<S256>/Saturation'
                                        */
  real_T Saturation_LowerSat_ks;       /* Expression: eps
                                        * Referenced by: '<S256>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition_eb;/* Expression: 0
                                         * Referenced by: '<S230>/Unit Delay1'
                                         */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_pi;/* Expression: 0
                                         * Referenced by: '<S9>/Unit Delay1'
                                         */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay3'
                                        */
  real_T UnitDelay1_InitialCondition_m;/* Expression: 0
                                        * Referenced by: '<S273>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  real_T UnitDelay5_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay5'
                                        */
  real_T UnitDelay1_InitialCondition_ed;/* Expression: 0
                                         * Referenced by: '<S27>/Unit Delay1'
                                         */
  real_T BrakeSupplyReservoirPressureavailable_Value;/* Expression: 1
                                                      * Referenced by: '<S11>/Brake Supply Reservoir Pressure available'
                                                      */
  real_T AuxReservoirPressureavailable_Value;/* Expression: 1
                                              * Referenced by: '<S37>/Aux Reservoir Pressure available'
                                              */
  real_T BrakeSupplyReservoirPressureavailable_Value_i;/* Expression: 1
                                                        * Referenced by: '<S37>/Brake Supply Reservoir Pressure available'
                                                        */
  real_T MainReservoirPressureavailable_Value;/* Expression: 1
                                               * Referenced by: '<S37>/Main Reservoir Pressure available'
                                               */
  real_T Constant_Value_e[6];          /* Expression: zeros(1,MaxAxles)
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T UnitDelay4_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S9>/Unit Delay4'
                                        */
  real_T AddConstant_Bias;             /* Expression: -1
                                        * Referenced by: '<S20>/Add Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T Constant_Value_k;             /* Expression: InitOn
                                        * Referenced by: '<S253>/Constant'
                                        */
  real_T OnlyIC_Value_l;               /* Expression: 0
                                        * Referenced by: '<S257>/OnlyIC'
                                        */
  real_T Initialise_Value_e;           /* Expression: 1
                                        * Referenced by: '<S257>/Initialise'
                                        */
  real_T Initialise_Threshold_hk;      /* Expression: 0
                                        * Referenced by: '<S253>/Initialise'
                                        */
  real_T Constant_Value_p2;            /* Expression: InitOn
                                        * Referenced by: '<S254>/Constant'
                                        */
  real_T OnlyIC_Value_lu;              /* Expression: 0
                                        * Referenced by: '<S258>/OnlyIC'
                                        */
  real_T Initialise_Value_j;           /* Expression: 1
                                        * Referenced by: '<S258>/Initialise'
                                        */
  real_T Initialise_Threshold_b;       /* Expression: 0
                                        * Referenced by: '<S254>/Initialise'
                                        */
  boolean_T IC_Value;                  /* Computed Parameter: IC_Value
                                        * Referenced by: '<S67>/IC'
                                        */
  boolean_T Constant2_Value;           /* Expression: false
                                        * Referenced by: '<S75>/Constant2'
                                        */
  boolean_T IC_Value_l;                /* Computed Parameter: IC_Value_l
                                        * Referenced by: '<S85>/IC'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S99>/Logic'
                                        */
  boolean_T UnitDelay1_InitialCondition_nm;
                           /* Computed Parameter: UnitDelay1_InitialCondition_nm
                            * Referenced by: '<S83>/Unit Delay1'
                            */
  boolean_T IC_Value_g;                /* Computed Parameter: IC_Value_g
                                        * Referenced by: '<S100>/IC'
                                        */
  boolean_T Constant1_Value_d;         /* Expression: true
                                        * Referenced by: '<S83>/Constant1'
                                        */
  boolean_T IC_Value_li;               /* Computed Parameter: IC_Value_li
                                        * Referenced by: '<S111>/IC'
                                        */
  boolean_T IC_Value_b;                /* Computed Parameter: IC_Value_b
                                        * Referenced by: '<S219>/IC'
                                        */
  boolean_T IC_Value_i;                /* Computed Parameter: IC_Value_i
                                        * Referenced by: '<S251>/IC'
                                        */
  boolean_T IC_Value_k;                /* Computed Parameter: IC_Value_k
                                        * Referenced by: '<S27>/IC'
                                        */
  boolean_T IC_Value_c;                /* Computed Parameter: IC_Value_c
                                        * Referenced by: '<S273>/IC'
                                        */
  P_MRPipeTwoWayValve_PneumaticsSystem_T MRPtoDownstreamConnection;
                                     /* '<S255>/MRP to Downstream Connection' */
  P_MRPipeTwoWayValve_PneumaticsSystem_T MRPtoUpstreamConnection;/* '<S255>/MRP to Upstream Connection' */
  P_BSRVentDrain_PneumaticsSystem_T MRVentDrain;/* '<S231>/MR Vent Drain' */
  P_BSRVentDrain_PneumaticsSystem_T MRBlowoff;/* '<S231>/MR Blowoff' */
  P_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit_d;/* '<S231>/TimerOffDelay NoInit' */
  P_MRPipeTwoWayValve_PneumaticsSystem_T MRPipeTwoWayValve;/* '<S231>/MR Pipe Two Way Valve' */
  P_CoreSubsys_PneumaticsSystem_gmy0ogccz_T CoreSubsys_pnaev;/* '<S16>/Subsystem' */
  P_BSRVentDrain_PneumaticsSystem_T BSRCharge_b;/* '<S217>/BSR Charge' */
  P_BSRVentDrain_PneumaticsSystem_T BSRVentDrain_d;/* '<S217>/BSR Vent Drain' */
  P_BSRVentDrain_PneumaticsSystem_T BSRVentIC_c;/* '<S217>/BSR Vent IC' */
  P_CoreSubsys_PneumaticsSystem_gmy0ogcc_T CoreSubsys_pnae;/* '<S122>/SandingSystemPerBogie' */
  P_CoreSubsys_PneumaticsSystem_gmy0og_T CoreSubsys_pna;/* '<S121>/BrakingSystemPerBogie' */
  P_CoreSubsys_PneumaticsSystem_gmy0o_T CoreSubsys_pn;
                                      /* '<S14>/BogiePressureSwitchesMapping' */
  P_CoreSubsys_PneumaticsSystem_gmy0_T CoreSubsys_p;/* '<S14>/BogiePressureMapping' */
  P_CoreSubsys_PneumaticsSystem_gmy_T CoreSubsys;/* '<S118>/AirSuspensionPerBogie' */
  P_BSRVentIC_PneumaticsSystem_T VCBIsolate;/* '<S102>/VCB Isolate' */
  P_BSRVentDrain_PneumaticsSystem_T VCBVent;/* '<S102>/VCB Vent' */
  P_BSRVentDrain_PneumaticsSystem_T VCBCharge;/* '<S102>/VCB Charge' */
  P_BSRVentIC_PneumaticsSystem_T PCVentIsol;/* '<S77>/PC Vent Isol' */
  P_BSRVentIC_PneumaticsSystem_T PCVentControl;/* '<S77>/PC Vent Control' */
  P_BSRVentDrain_PneumaticsSystem_T PCVentEmer;/* '<S77>/PC Vent Emer' */
  P_BSRVentDrain_PneumaticsSystem_T ARCharge;/* '<S77>/AR Charge' */
  P_BSRVentDrain_PneumaticsSystem_T ARChargefromMRP;/* '<S65>/AR Charge from MRP' */
  P_BSRVentDrain_PneumaticsSystem_T ARVentDrain;/* '<S65>/AR Vent Drain' */
  P_BSRVentDrain_PneumaticsSystem_T ARBlowoff;/* '<S65>/AR Blowoff' */
  P_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit1;/* '<S11>/TimerOffDelay NoInit1' */
  P_TimerOffDelayNoInit_PneumaticsSystem_T TimerOffDelayNoInit;/* '<S11>/TimerOffDelay NoInit' */
  P_BSRVentDrain_PneumaticsSystem_T BSRCharge;/* '<S26>/BSR Charge' */
  P_BSRVentDrain_PneumaticsSystem_T BSRVentDrain;/* '<S26>/BSR Vent Drain' */
  P_BSRVentIC_PneumaticsSystem_T BSRVentIC;/* '<S26>/BSR Vent IC' */
};

/* Parameters (default storage) */
struct P_PneumaticsSystem_T_ {
  real_T PAtm;                         /* Variable: PAtm
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
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  P_CoreSubsys_PneumaticsSystem_gm_T CoreSubsys_pn;/* '<Root>/PneumaticsPerVehicle' */
};

/* Real-time Model Data Structure */
struct tag_RTM_PneumaticsSystem_T {
  const char_T **errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[784];
    int32_T* vardimsAddress[784];
    RTWLoggingFcnPtr loggingPtrs[784];
  } DataMapInfo;
};

typedef struct {
  B_PneumaticsSystem_c_T rtb;
  DW_PneumaticsSystem_f_T rtdw;
  RT_MODEL_PneumaticsSystem_T rtm;
} MdlrefDW_PneumaticsSystem_T;

/* Model reference registration function */
extern void PneumaticsSystem_initialize(const char_T **rt_errorStatus,
  RT_MODEL_PneumaticsSystem_T *const PneumaticsSystem_M, B_PneumaticsSystem_c_T *
  localB, DW_PneumaticsSystem_f_T *localDW, rtwCAPI_ModelMappingInfo
  *rt_ParentMMI, const char_T *rt_ChildPath, int_T rt_ChildMMIIdx, int_T
  rt_CSTATEIdx);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  PneumaticsSystem_GetCAPIStaticMap(void);
extern void PneumaticsSystem_BSRVentIC_Start(B_BSRVentIC_PneumaticsSystem_T
  *localB);
extern void PneumaticsSystem_BSRVentIC(real_T rtu_P1, real_T rtu_P2, real_T
  rtu_Isolate, B_BSRVentIC_PneumaticsSystem_T *localB,
  P_BSRVentIC_PneumaticsSystem_T *localP, real_T rtp_p_deadband);
extern void PneumaticsSystem_BSRVentDrain_Start
  (B_BSRVentDrain_PneumaticsSystem_T *localB);
extern void PneumaticsSystem_BSRVentDrain(real_T rtu_P1, real_T rtu_P2,
  boolean_T rtu_Isolate, B_BSRVentDrain_PneumaticsSystem_T *localB,
  P_BSRVentDrain_PneumaticsSystem_T *localP, real_T rtp_p_deadband);
extern void PneumaticsSystem_TimerOffDelayNoInit_Init
  (DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW);
extern void PneumaticsSystem_TimerOffDelayNoInit_Start
  (B_TimerOffDelayNoInit_PneumaticsSystem_T *localB,
   DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW);
extern void PneumaticsSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_PneumaticsSystem_T *localB,
  DW_TimerOffDelayNoInit_PneumaticsSystem_T *localDW,
  P_TimerOffDelayNoInit_PneumaticsSystem_T *localP);
extern void PneumaticsSystem_ASCharge_Start(B_ASCharge_PneumaticsSystem_T
  *localB);
extern void PneumaticsSystem_ASCharge(real_T rtu_P1, real_T rtu_P2, boolean_T
  rtu_Isolate, real_T rtu_3, real_T rtu_4, real_T rtu_5,
  B_ASCharge_PneumaticsSystem_T *localB, P_ASCharge_PneumaticsSystem_T *localP,
  real_T rtp_p_deadband);
extern void PneumaticsSystem_ASVent_Start(B_ASVent_PneumaticsSystem_T *localB);
extern void PneumaticsSystem_ASVent(real_T rtu_P1, real_T rtu_P2, boolean_T
  rtu_Isolate, real_T rtu_3, real_T rtu_4, real_T rtu_5,
  B_ASVent_PneumaticsSystem_T *localB, P_ASVent_PneumaticsSystem_T *localP,
  real_T rtp_p_deadband);
extern void PneumaticsSystem_IfActionSubsystem5_Init
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB,
   P_IfActionSubsystem5_PneumaticsSystem_T *localP);
extern void PneumaticsSystem_IfActionSubsystem5_Start
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB);
extern void PneumaticsSystem_IfActionSubsystem5_Disable
  (B_IfActionSubsystem5_PneumaticsSystem_T *localB,
   P_IfActionSubsystem5_PneumaticsSystem_T *localP);
extern void PneumaticsSystem_IfActionSubsystem5(real_T rtu_In1,
  B_IfActionSubsystem5_PneumaticsSystem_T *localB);
extern void PneumaticsSystem_MRPipeTwoWayValve_Start
  (B_MRPipeTwoWayValve_PneumaticsSystem_T *localB);
extern void PneumaticsSystem_MRPipeTwoWayValve(real_T rtu_P1, real_T rtu_P2,
  boolean_T rtu_Isolate, B_MRPipeTwoWayValve_PneumaticsSystem_T *localB,
  P_MRPipeTwoWayValve_PneumaticsSystem_T *localP, real_T rtp_p_deadband);
extern void PneumaticsSystem_Init(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW);
extern void PneumaticsSystem_Reset(DW_PneumaticsSystem_f_T *localDW);
extern void PneumaticsSystem_Start(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW);
extern void PneumaticsSystem_Disable(B_PneumaticsSystem_c_T *localB,
  DW_PneumaticsSystem_f_T *localDW);
extern void PneumaticsSystem(const BD_CommonTrain_Cfg_Vehicle
  rtu_CommonVehicleConfig[8], const BD_PneumaticsSystem_Cfg_Vehicle
  rtu_PneumaticsSystemVehicleConfig[8], const BD_PneumaticsSystem_In_Vehicle
  rtu_PneumaticsSystemVehicleInputs[8], const BD_PneumaticsSystem_In_Overrides
  rtu_Overrides[8], const BD_PneumaticsSystem_In_Vehicle_Faults rtu_Faults[8],
  BD_PneumaticsSystem_Out_Vehicle rty_PneumaticsSystemVehicleOut[8],
  B_PneumaticsSystem_c_T *localB, DW_PneumaticsSystem_f_T *localDW, const
  BD_PneumaticsSystem_Prm *rtp_Prm_PneumaticsSystem);

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
 * '<Root>' : 'PneumaticsSystem'
 * '<S1>'   : 'PneumaticsSystem/ExtractMRP'
 * '<S2>'   : 'PneumaticsSystem/MRPipeState'
 * '<S3>'   : 'PneumaticsSystem/PneumaticsPerVehicle'
 * '<S4>'   : 'PneumaticsSystem/MRPipeState/Extract'
 * '<S5>'   : 'PneumaticsSystem/MRPipeState/Orientation Swap'
 * '<S6>'   : 'PneumaticsSystem/MRPipeState/PipeConnections'
 * '<S7>'   : 'PneumaticsSystem/MRPipeState/UpDnSel'
 * '<S8>'   : 'PneumaticsSystem/MRPipeState/Orientation Swap/Orientation Swap'
 * '<S9>'   : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem'
 * '<S10>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir'
 * '<S11>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping'
 * '<S12>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems'
 * '<S13>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AxleMapping'
 * '<S14>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems'
 * '<S15>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem'
 * '<S16>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/GaugesMapping'
 * '<S17>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem'
 * '<S18>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/OutputMapping'
 * '<S19>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/PressuresMapping'
 * '<S20>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/Subsystem1'
 * '<S21>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/SwitchesMapping'
 * '<S22>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/TCMSMapping'
 * '<S23>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/TrandsducersMapping'
 * '<S24>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir'
 * '<S25>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/AirSuspensionReservoir'
 * '<S26>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc'
 * '<S27>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/AirSuspensionReservoir/Discrete Dyamic Limited Integrator1'
 * '<S28>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/AirSuspensionReservoir/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S29>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Charge'
 * '<S30>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Vent Drain'
 * '<S31>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Vent IC'
 * '<S32>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/Compare To Constant'
 * '<S33>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Charge/Compare To Zero'
 * '<S34>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Vent Drain/Compare To Zero'
 * '<S35>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/ASReservoir/Air SuspensionReservoir/FlowCalc/BSR Vent IC/Compare To Zero'
 * '<S36>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Detect Decrease'
 * '<S37>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem'
 * '<S38>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/TimerOffDelay NoInit'
 * '<S39>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/TimerOffDelay NoInit1'
 * '<S40>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease'
 * '<S41>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease1'
 * '<S42>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease10'
 * '<S43>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease11'
 * '<S44>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease12'
 * '<S45>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease13'
 * '<S46>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease14'
 * '<S47>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease15'
 * '<S48>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease2'
 * '<S49>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease3'
 * '<S50>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease4'
 * '<S51>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease5'
 * '<S52>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease6'
 * '<S53>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease7'
 * '<S54>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease8'
 * '<S55>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/Subsystem/Detect Decrease9'
 * '<S56>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/TimerOffDelay NoInit/Count to 0'
 * '<S57>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AudioMapping/TimerOffDelay NoInit1/Count to 0'
 * '<S58>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem'
 * '<S59>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/Horn'
 * '<S60>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir'
 * '<S61>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph'
 * '<S62>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB'
 * '<S63>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/ARPressureSwitch.12'
 * '<S64>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/AuxReservoir'
 * '<S65>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc'
 * '<S66>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/ARPressureSwitch.12/External IC'
 * '<S67>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/AuxReservoir/Discrete Dyamic Limited Integrator1'
 * '<S68>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/AuxReservoir/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S69>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Blowoff'
 * '<S70>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Charge from MRP'
 * '<S71>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Vent Drain'
 * '<S72>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Blowoff/Compare To Zero'
 * '<S73>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Charge from MRP/Compare To Zero'
 * '<S74>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/AuxReservoir/FlowCalc/AR Vent Drain/Compare To Zero'
 * '<S75>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/BellowCylinder'
 * '<S76>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/Detect Decrease'
 * '<S77>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc'
 * '<S78>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PS1.'
 * '<S79>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PS2.'
 * '<S80>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PanPressureSwitch'
 * '<S81>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantoValves'
 * '<S82>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantographCylinder'
 * '<S83>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/StartupStateOverrideElectric'
 * '<S84>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/BellowCylinder/AirBellowPressureSafegaurd'
 * '<S85>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/BellowCylinder/AirBellowPressureSafegaurd/Discrete Dyamic Limited Integrator1'
 * '<S86>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/BellowCylinder/AirBellowPressureSafegaurd/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S87>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/AR Charge'
 * '<S88>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Control'
 * '<S89>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Emer'
 * '<S90>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Isol'
 * '<S91>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/AR Charge/Compare To Zero'
 * '<S92>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Control/Compare To Zero'
 * '<S93>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Emer/Compare To Zero'
 * '<S94>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/FlowCalc/PC Vent Isol/Compare To Zero'
 * '<S95>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PS1./External IC'
 * '<S96>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PS2./External IC'
 * '<S97>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PanPressureSwitch/External IC'
 * '<S98>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantoValves/Detect Change'
 * '<S99>'  : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantoValves/S-R Flip-Flop'
 * '<S100>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantographCylinder/Discrete Dyamic Limited Integrator1'
 * '<S101>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/Pantograph/PantographCylinder/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S102>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem'
 * '<S103>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/VCBCylinder'
 * '<S104>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/VCBPressureSwitch1'
 * '<S105>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Charge'
 * '<S106>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Isolate'
 * '<S107>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Vent'
 * '<S108>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Charge/Compare To Zero'
 * '<S109>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Isolate/Compare To Zero'
 * '<S110>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/Subsystem/VCB Vent/Compare To Zero'
 * '<S111>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/VCBCylinder/Discrete Dyamic Limited Integrator1'
 * '<S112>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/VCBCylinder/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S113>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/AuxSystem/VCB/VCBPressureSwitch1/External IC'
 * '<S114>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/Horn/Enough Air'
 * '<S115>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/Horn/Enough Air1'
 * '<S116>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/Horn/High Horn'
 * '<S117>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/AuxiliarySystems/Horn/Low Horn'
 * '<S118>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem'
 * '<S119>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BogiePressureMapping'
 * '<S120>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BogiePressureSwitchesMapping'
 * '<S121>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem'
 * '<S122>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/SandingSystem'
 * '<S123>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie'
 * '<S124>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/AirLevelingValve'
 * '<S125>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/AirSuspensionReservoir'
 * '<S126>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/B27-L11-1//2'
 * '<S127>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc'
 * '<S128>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/Subsystem'
 * '<S129>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/AirLevelingValve/Compare To Constant'
 * '<S130>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/AirSuspensionReservoir/Discrete Dyamic Limited Integrator1'
 * '<S131>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/AirSuspensionReservoir/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S132>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/B27-L11-1//2/External IC'
 * '<S133>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Charge'
 * '<S134>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent'
 * '<S135>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent Drain'
 * '<S136>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent IC'
 * '<S137>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/Charge Choke'
 * '<S138>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/Compare To Constant'
 * '<S139>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/Compare To Constant1'
 * '<S140>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/Release Choke'
 * '<S141>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Charge/Compare To Zero'
 * '<S142>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent/Compare To Zero'
 * '<S143>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent Drain/Compare To Zero'
 * '<S144>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/FlowCalc/AS Vent IC/Compare To Zero'
 * '<S145>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/Subsystem/First Order Low Pass Filter'
 * '<S146>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/Subsystem/SafeDivide'
 * '<S147>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/AirSuspensionSystem/AirSuspensionPerBogie/Subsystem/SafeDivide/Replace Zeros'
 * '<S148>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie'
 * '<S149>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit'
 * '<S150>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine'
 * '<S151>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle'
 * '<S152>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/ParkBrakes'
 * '<S153>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS'
 * '<S154>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BrakeCylinderPressureCalc'
 * '<S155>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/Compare To Constant2'
 * '<S156>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/LPF'
 * '<S157>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/LoadCompensation'
 * '<S158>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Compare To Constant1'
 * '<S159>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Compare To Constant3'
 * '<S160>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Compare To Constant4'
 * '<S161>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Compare To Constant5'
 * '<S162>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Compare To Constant7'
 * '<S163>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease'
 * '<S164>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease1'
 * '<S165>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease2'
 * '<S166>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease3'
 * '<S167>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease4'
 * '<S168>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease5'
 * '<S169>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/Detect Decrease6'
 * '<S170>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem'
 * '<S171>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem1'
 * '<S172>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem4'
 * '<S173>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem5'
 * '<S174>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem6'
 * '<S175>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority1'
 * '<S176>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority2'
 * '<S177>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority3'
 * '<S178>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority4'
 * '<S179>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority5'
 * '<S180>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/SR Latch - Reset Priority6'
 * '<S181>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem/Rate Limiter Dynamic2'
 * '<S182>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/BECUFaultToTCMS/If Action Subsystem/Rate Limiter Dynamic2/Saturation Dynamic'
 * '<S183>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/LoadCompensation/LoadCompensatedEB'
 * '<S184>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeControlUnit/LoadCompensation/Regulating Valve'
 * '<S185>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/B27//28-B07'
 * '<S186>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/HasBC'
 * '<S187>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/LPF'
 * '<S188>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/Mean of Elements'
 * '<S189>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/SafeDivide'
 * '<S190>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/B27//28-B07/External IC'
 * '<S191>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSupplyLine/SafeDivide/Replace Zeros'
 * '<S192>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder'
 * '<S193>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/Compare To Zero'
 * '<S194>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/BrakeCylinder'
 * '<S195>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc'
 * '<S196>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/BrakeCylinder/Discrete Dyamic Limited Integrator1'
 * '<S197>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/BrakeCylinder/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S198>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Charge'
 * '<S199>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Isolate'
 * '<S200>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Vent'
 * '<S201>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/Charge Choke'
 * '<S202>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/Compare To Constant'
 * '<S203>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/Release Choke'
 * '<S204>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Charge/Compare To Zero'
 * '<S205>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Isolate/Compare To Zero'
 * '<S206>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/BrakeCylinderSystemPerAxle/AxleBrakeCylinder/FlowCalc/BC Vent/Compare To Zero'
 * '<S207>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/ParkBrakes/B27-B14'
 * '<S208>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/ParkBrakes/LPF'
 * '<S209>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/ParkBrakes/MagnetValve_B20'
 * '<S210>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/BrakingSystem/BrakingSystemPerBogie/ParkBrakes/B27-B14/External IC'
 * '<S211>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/SandingSystem/SandingSystemPerBogie'
 * '<S212>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/SandingSystem/SandingSystemPerBogie/SandingPressureSwitch.10'
 * '<S213>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BogiePneumaticSystems/SandingSystem/SandingSystemPerBogie/SandingPressureSwitch.10/External IC'
 * '<S214>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir'
 * '<S215>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/BSRPressureSwitch.05'
 * '<S216>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/BrakeSupplyReservoir'
 * '<S217>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc'
 * '<S218>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/BSRPressureSwitch.05/External IC'
 * '<S219>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/BrakeSupplyReservoir/Discrete Dyamic Limited Integrator1'
 * '<S220>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/BrakeSupplyReservoir/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S221>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Charge'
 * '<S222>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Vent Drain'
 * '<S223>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Vent IC'
 * '<S224>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/Compare To Constant'
 * '<S225>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Charge/Compare To Zero'
 * '<S226>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Vent Drain/Compare To Zero'
 * '<S227>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/BrakeReservoirSystem/BrakeSupplyReservoir/FlowCalc/BSR Vent IC/Compare To Zero'
 * '<S228>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/GaugesMapping/Subsystem'
 * '<S229>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir'
 * '<S230>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe'
 * '<S231>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc'
 * '<S232>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/MRPressureSwitch.06'
 * '<S233>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/MainReservoir'
 * '<S234>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/Coupling-ExtraMRP'
 * '<S235>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/Detect Increase'
 * '<S236>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Blowoff'
 * '<S237>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve'
 * '<S238>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Vent Drain'
 * '<S239>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/TimerOffDelay NoInit'
 * '<S240>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/Coupling-ExtraMRP/Compare To Zero'
 * '<S241>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Blowoff/Compare To Zero'
 * '<S242>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Compare To Zero'
 * '<S243>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Compare To Zero1'
 * '<S244>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Forward'
 * '<S245>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Reverse'
 * '<S246>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Forward/Compare To Zero'
 * '<S247>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Pipe Two Way Valve/Reverse/Compare To Zero'
 * '<S248>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/MR Vent Drain/Compare To Zero'
 * '<S249>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/FlowCalc/TimerOffDelay NoInit/Count to 0'
 * '<S250>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/MRPressureSwitch.06/External IC'
 * '<S251>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/MainReservoir/Discrete Dyamic Limited Integrator1'
 * '<S252>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoir/MainReservoir/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 * '<S253>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/A00-A14'
 * '<S254>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/B27-B22'
 * '<S255>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc'
 * '<S256>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/MainReservoirPipe'
 * '<S257>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/A00-A14/External IC'
 * '<S258>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/B27-B22/External IC'
 * '<S259>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection'
 * '<S260>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection'
 * '<S261>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Compare To Zero'
 * '<S262>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Compare To Zero1'
 * '<S263>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Forward'
 * '<S264>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Reverse'
 * '<S265>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Forward/Compare To Zero'
 * '<S266>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Downstream Connection/Reverse/Compare To Zero'
 * '<S267>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Compare To Zero'
 * '<S268>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Compare To Zero1'
 * '<S269>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Forward'
 * '<S270>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Reverse'
 * '<S271>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Forward/Compare To Zero'
 * '<S272>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/FlowCalc/MRP to Upstream Connection/Reverse/Compare To Zero'
 * '<S273>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/MainReservoirPipe/Discrete Dyamic Limited Integrator1'
 * '<S274>' : 'PneumaticsSystem/PneumaticsPerVehicle/PneumaticsSystem/MainReservoirSystem/MainReservoirPipe/MainReservoirPipe/Discrete Dyamic Limited Integrator1/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_PneumaticsSystem_h_ */
