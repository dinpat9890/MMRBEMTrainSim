/*
 * Code generation for system system '<S3147>/RightDoor4DCUCB-MCB'
 * For more details, see corresponding source file MCBControl.c
 *
 */

#ifndef RTW_HEADER_MCBControl_h_
#define RTW_HEADER_MCBControl_h_
#ifndef IOControls_COMMON_INCLUDES_
# define IOControls_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IOControls_COMMON_INCLUDES_ */

#include "IOControls_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "ToggleControl.h"

/* Block signals for system '<S3147>/RightDoor4DCUCB-MCB' */
typedef struct {
  real_T DataTypeConversion;           /* '<S3556>/Data Type Conversion' */
  B_ToggleControl_T Toggle;            /* '<S3554>/Toggle' */
} B_MCBControl_T;

/* Block states (default storage) for system '<S3147>/RightDoor4DCUCB-MCB' */
typedef struct {
  real_T Timer_DSTATE;                 /* '<S3561>/Timer' */
  boolean_T UnitDelay_DSTATE;          /* '<S3556>/Unit Delay' */
  int8_T Timer_PrevResetState;         /* '<S3561>/Timer' */
  boolean_T Memory_PreviousInput;      /* '<S3560>/Memory' */
  boolean_T MCBTrip_MODE;              /* '<S3554>/MCB Trip' */
  DW_ToggleControl_T Toggle;           /* '<S3554>/Toggle' */
} DW_MCBControl_T;

/* Parameters for system: '<S3147>/RightDoor4DCUCB-MCB' */
struct P_MCBControl_T_ {
  real_T TimerOnDelayNoInit_UpperSaturationLimit;
                      /* Mask Parameter: TimerOnDelayNoInit_UpperSaturationLimit
                       * Referenced by: '<S3561>/Timer'
                       */
  real_T IsON_const;                   /* Mask Parameter: IsON_const
                                        * Referenced by: '<S3559>/Constant'
                                        */
  real_T IsOFF_const;                  /* Mask Parameter: IsOFF_const
                                        * Referenced by: '<S3558>/Constant'
                                        */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S3560>/Memory'
                                  */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3562>/Constant'
                                        */
  real_T Timer_gainval;                /* Computed Parameter: Timer_gainval
                                        * Referenced by: '<S3561>/Timer'
                                        */
  real_T Timer_IC;                     /* Expression: 0
                                        * Referenced by: '<S3561>/Timer'
                                        */
  real_T Timer_LowerSat;               /* Expression: 0
                                        * Referenced by: '<S3561>/Timer'
                                        */
  real_T TripOut_Y0;                   /* Computed Parameter: TripOut_Y0
                                        * Referenced by: '<S3556>/TripOut'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S3555>/Constant'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3556>/Unit Delay'
                                */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S3560>/Logic'
                                        */
  P_ToggleControl_T Toggle;            /* '<S3554>/Toggle' */
};

extern void MCBControl_Init(B_MCBControl_T *localB, DW_MCBControl_T *localDW,
  P_MCBControl_T *localP);
extern void MCBControl_Reset(DW_MCBControl_T *localDW, P_MCBControl_T *localP);
extern void MCBControl_Start(B_MCBControl_T *localB, DW_MCBControl_T *localDW);
extern void MCBControl_Disable(DW_MCBControl_T *localDW);
extern void MCBControl(real_T rtu_InVal, real_T rtu_InMode, real_T rtu_InitVal,
  real_T rtu_InitTrigger, real_T rtu_IRQ, real_T rtu_Inhibit, real_T rtu_TripIn,
  B_MCBControl_T *localB, DW_MCBControl_T *localDW, P_MCBControl_T *localP,
  real_T rtp_OffStateValue, real_T rtp_OnStateValue, real_T rtp_InitState);

#endif                                 /* RTW_HEADER_MCBControl_h_ */
