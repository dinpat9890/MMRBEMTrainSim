/*
 * Code generation for system model 'DoorSystem'
 *
 * Model                      : DoorSystem
 * Model version              : 1.2208
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "DoorSystem_capi.h"
#include "DoorSystem.h"
#include "DoorSystem_private.h"

/* Named constants for Chart: '<S33>/Chart' */
const uint8_T DoorSystem_IN_Active = 1U;
const uint8_T DoorSystem_IN_Active1 = 2U;
const uint8_T DoorSystem_IN_Closing = 1U;
const uint8_T DoorSystem_IN_Complete = 2U;
const uint8_T DoorSystem_IN_Complete_h = 1U;
const uint8_T DoorSystem_IN_Hold1 = 3U;
const uint8_T DoorSystem_IN_Hold1_n = 2U;
const uint8_T DoorSystem_IN_Hold2 = 4U;
const uint8_T DoorSystem_IN_Hold2_m = 3U;
const uint8_T DoorSystem_IN_Inactive = 3U;
const uint8_T DoorSystem_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T DoorSystem_IN_Opening = 5U;
P_DoorSystem_T DoorSystem_P = {
  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<Root>/Unit Delay'
   */
  {
    false,                             /* TrainDoorInterlockOk */
    false,                             /* TrainLeftDoorInterlockOk */
    false                              /* TrainRightDoorInterlockOk */
  },

  /* Start of '<S138>/CoreSubsys' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S138>/Constant'
     */
    {
      false,                           /* TrainDoorInterlockOk */
      false,                           /* TrainLeftDoorInterlockOk */
      false                            /* TrainRightDoorInterlockOk */
    }
  }
  ,

  /* End of '<S138>/CoreSubsys' */

  /* Start of '<S1>/CoreSubsys' */
  {
    /* Mask Parameter: TimerOnDelayNoInit2_UpperSaturationLimit
     * Referenced by: '<S108>/TimerOnDelay NoInit2'
     */
    1.0,

    /* Mask Parameter: TimerOnDelayNoInit1_UpperSaturationLimit
     * Referenced by: '<S108>/TimerOnDelay NoInit1'
     */
    1.0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S109>/Constant'
     */
    1.0,

    /* Mask Parameter: DetectIncrease1_vinit
     * Referenced by: '<S124>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectDecrease_vinit
     * Referenced by: '<S123>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: DetectIncrease2_vinit
     * Referenced by: '<S125>/Delay Input1'
     */
    0.0,

    /* Mask Parameter: SRLatchResetPriority_initial_condition
     * Referenced by: '<S117>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority1_initial_condition
     * Referenced by: '<S118>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority2_initial_condition
     * Referenced by: '<S119>/Memory'
     */
    0,

    /* Mask Parameter: SRLatchResetPriority3_initial_condition
     * Referenced by: '<S120>/Memory'
     */
    0,

    /* Mask Parameter: DetectIncrease_vinit
     * Referenced by: '<S110>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease3_vinit
     * Referenced by: '<S126>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease1_vinit_n
     * Referenced by: '<S111>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease2_vinit_a
     * Referenced by: '<S112>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease4_vinit
     * Referenced by: '<S114>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease3_vinit_d
     * Referenced by: '<S113>/Delay Input1'
     */
    0,

    /* Mask Parameter: DetectIncrease5_vinit
     * Referenced by: '<S115>/Delay Input1'
     */
    0,

    /* Computed Parameter: DoorSystemVehicleOut_Y0
     * Referenced by: '<S3>/DoorSystemVehicleOut'
     */
    {
      {
        false,                         /* TrainDoorInterlockOk */
        false,                         /* VehicleDoorInterlockOk */
        false,                         /* TrainLeftDoorInterlockOk */
        false,                         /* TrainRightDoorInterlockOk */
        false,                         /* VehicleLeftDoorInterlockOk */
        false                          /* VehicleRightDoorInterlockOk */
      },                               /* VehicleElectrical */

      {
        {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        }, {
          {
            false,                     /* DoorCloseInterlock */
            false                      /* DoorClosed */
          },                           /* ElectricalSignals */

          {
            0.0,                       /* DoorPosition */
            0.0,                       /* DoorOutsideLamp */
            0.0                        /* DoorInsideLamp */
          },                           /* OutputControlStates */

          {
            0.0,                       /* DoorOpeningAuthorised */
            0.0,                       /* DoorOpeningAlarm */
            0.0,                       /* DoorClosingAlarm */
            0.0,                       /* DoorEmergencyReleased */
            0.0,                       /* DoorIsolated */
            0.0,                       /* DoorClosing */
            0.0                        /* DoorOpening */
          },                           /* Audio */

          {
            false,                     /* DoorClosedStatus */
            false,                     /* DoorOpenStatus */
            false,                     /* DoorReleasedAuthorisedToOpenStatus */
            false,                     /* DoorEmergencyReleasedStatus */
            false,                     /* DoorIsolatedStatus */
            false,                     /* DoorFaultStatus */
            false,                     /* DoorObstacleDetected */
            false,                     /* DoorObstacleUnableToClose */
            false,                     /* DoorLockedStatus */
            false,                     /* DoorOpenPBLight */
            false,                     /* DoorClosedPBLight */

            {
              false,                   /* DoorOpenObstacleDetected */
              false,                   /* DoorCloseObstacleDetected */
              false,                   /* DoorFailedToLock */
              false,                   /* DoorFailedToUnlock */
              false,                   /* DoorMotorFailure */
              false,                   /* DoorMajorFault */
              false,                   /* DCSRFailure */
              false,                   /* DCSLFailure */
              false,                   /* DLSRFailure */
              false,                   /* DLSLFailure */
              false,                   /* DCUFailure */
              false,                   /* DoorUnexpectedUnlocking */
              false,                   /* DoorIsolatedWire */
              false,                   /* DoorEmergencyHandleWire */
              false                    /* UnexpectedDoorOpeningDetectedByCC */
            }                          /* Messages */
          }                            /* TCMS */
        } }
      ,                                /* Doors */

      {
        0.0,                           /* Ramp */
        0.0,                           /* EmergencyDoorOpen */
        false,                         /* EmergencyDoorLocked */
        0.0,                           /* GasSpringLocked */
        0.0,                           /* RampSupportDown */
        0.0,                           /* LockingLeverUnlockAuth */
        false                          /* EmerDoorOpenFaultMessage */
      }                                /* EmergencyDoor */
    },

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S6>/Constant1'
     */
    {
      0.0,                             /* Ramp */
      0.0,                             /* EmergencyDoorOpen */
      false,                           /* EmergencyDoorLocked */
      0.0,                             /* GasSpringLocked */
      0.0,                             /* RampSupportDown */
      0.0,                             /* LockingLeverUnlockAuth */
      false                            /* EmerDoorOpenFaultMessage */
    },

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S6>/Constant'
     */
    {
      false,                           /* TrainDoorInterlockOk */
      false,                           /* VehicleDoorInterlockOk */
      false,                           /* TrainLeftDoorInterlockOk */
      false,                           /* TrainRightDoorInterlockOk */
      false,                           /* VehicleLeftDoorInterlockOk */
      false                            /* VehicleRightDoorInterlockOk */
    },

    /* Expression: 0
     * Referenced by: '<S116>/Constant7'
     */
    0.0,

    /* Expression: -0.5
     * Referenced by: '<S116>/Constant6'
     */
    -0.5,

    /* Expression: 0.5
     * Referenced by: '<S116>/Constant5'
     */
    0.5,

    /* Computed Parameter: WeightedSampleTime_WtEt
     * Referenced by: '<S127>/Weighted Sample Time'
     */
    0.05,

    /* Expression: 0
     * Referenced by: '<S116>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S116>/Constant4'
     */
    0.0,

    /* Expression: 1:MaxDoors
     * Referenced by: '<S4>/Constant'
     */
    { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

    /* Expression: 1
     * Referenced by: '<S116>/Constant1'
     */
    1.0,

    /* Expression: 12
     * Referenced by: '<S108>/Constant1'
     */
    12.0,

    /* Expression: 0
     * Referenced by: '<S127>/Unit Delay1'
     */
    0.0,

    /* Expression: 12
     * Referenced by: '<S108>/Constant'
     */
    12.0,

    /* Computed Parameter: UnitDelay_InitialCondition
     * Referenced by: '<S116>/Unit Delay'
     */
    0,

    /* Computed Parameter: IC_Value
     * Referenced by: '<S127>/IC'
     */
    1,

    /* Computed Parameter: UnitDelay1_InitialCondition_i
     * Referenced by: '<S108>/Unit Delay1'
     */
    0,

    /* Computed Parameter: UnitDelay_InitialCondition_e
     * Referenced by: '<S108>/Unit Delay'
     */
    0,

    /* Expression: true
     * Referenced by: '<S116>/Constant'
     */
    1,

    /* Start of '<S108>/TimerOnDelay NoInit2' */
    {
      /* Expression: 0
       * Referenced by: '<S136>/Constant'
       */
      0.0,

      /* Computed Parameter: Timer_gainval
       * Referenced by: '<S122>/Timer'
       */
      0.05,

      /* Expression: 0
       * Referenced by: '<S122>/Timer'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S122>/Timer'
       */
      0.0
    }
    ,

    /* End of '<S108>/TimerOnDelay NoInit2' */

    /* Start of '<S108>/TimerOnDelay NoInit1' */
    {
      /* Expression: 0
       * Referenced by: '<S135>/Constant'
       */
      0.0,

      /* Computed Parameter: Timer_gainval
       * Referenced by: '<S121>/Timer'
       */
      0.05,

      /* Expression: 0
       * Referenced by: '<S121>/Timer'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S121>/Timer'
       */
      0.0
    }
    ,

    /* End of '<S108>/TimerOnDelay NoInit1' */

    /* Start of '<S116>/TimerOffDelay NoInit2' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S130>/OffTime'
       */
      0.1,

      /* Expression: 0
       * Referenced by: '<S134>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S130>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S130>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S130>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S130>/Discrete-Time Integrator'
       */
      0.05,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S130>/Discrete-Time Integrator'
       */
      0.1,

      /* Expression: 0
       * Referenced by: '<S130>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S116>/TimerOffDelay NoInit2' */

    /* Start of '<S116>/TimerOffDelay NoInit1' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S129>/OffTime'
       */
      5.0,

      /* Expression: 0
       * Referenced by: '<S133>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S129>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S129>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S129>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S129>/Discrete-Time Integrator'
       */
      0.05,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S129>/Discrete-Time Integrator'
       */
      5.0,

      /* Expression: 0
       * Referenced by: '<S129>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S116>/TimerOffDelay NoInit1' */

    /* Start of '<S116>/TimerOffDelay NoInit' */
    {
      /* Expression: UpperSaturationLimit
       * Referenced by: '<S128>/OffTime'
       */
      5.0,

      /* Expression: 0
       * Referenced by: '<S132>/Constant'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S128>/Gain'
       */
      -1.0,

      /* Expression: 0
       * Referenced by: '<S128>/Initialise'
       */
      0.0,

      /* Expression: 1
       * Referenced by: '<S128>/IC'
       */
      1.0,

      /* Computed Parameter: DiscreteTimeIntegrator_gainval
       * Referenced by: '<S128>/Discrete-Time Integrator'
       */
      0.05,

      /* Expression: UpperSaturationLimit
       * Referenced by: '<S128>/Discrete-Time Integrator'
       */
      5.0,

      /* Expression: 0
       * Referenced by: '<S128>/Discrete-Time Integrator'
       */
      0.0
    }
    ,

    /* End of '<S116>/TimerOffDelay NoInit' */

    /* Start of '<S96>/CoreSubsys' */
    {
      /* Mask Parameter: DetectDecrease_vinit
       * Referenced by: '<S104>/Delay Input1'
       */
      0,

      /* Mask Parameter: DetectIncrease_vinit
       * Referenced by: '<S101>/Delay Input1'
       */
      0,

      /* Expression: 0
       * Referenced by: '<S96>/Switch'
       */
      0.0,

      /* Start of '<S99>/TimerOffDelay NoInit' */
      {
        /* Expression: UpperSaturationLimit
         * Referenced by: '<S102>/OffTime'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S103>/Constant'
         */
        0.0,

        /* Expression: -1
         * Referenced by: '<S102>/Gain'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S102>/Initialise'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S102>/IC'
         */
        1.0,

        /* Computed Parameter: DiscreteTimeIntegrator_gainval
         * Referenced by: '<S102>/Discrete-Time Integrator'
         */
        0.05,

        /* Expression: UpperSaturationLimit
         * Referenced by: '<S102>/Discrete-Time Integrator'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S102>/Discrete-Time Integrator'
         */
        0.0
      }
      ,

      /* End of '<S99>/TimerOffDelay NoInit' */

      /* Start of '<S100>/TimerOffDelay NoInit' */
      {
        /* Expression: UpperSaturationLimit
         * Referenced by: '<S105>/OffTime'
         */
        0.5,

        /* Expression: 0
         * Referenced by: '<S106>/Constant'
         */
        0.0,

        /* Expression: -1
         * Referenced by: '<S105>/Gain'
         */
        -1.0,

        /* Expression: 0
         * Referenced by: '<S105>/Initialise'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S105>/IC'
         */
        1.0,

        /* Computed Parameter: DiscreteTimeIntegrator_gainval
         * Referenced by: '<S105>/Discrete-Time Integrator'
         */
        0.05,

        /* Expression: UpperSaturationLimit
         * Referenced by: '<S105>/Discrete-Time Integrator'
         */
        0.5,

        /* Expression: 0
         * Referenced by: '<S105>/Discrete-Time Integrator'
         */
        0.0
      }
      /* End of '<S100>/TimerOffDelay NoInit' */
    }
    ,

    /* End of '<S96>/CoreSubsys' */

    /* Start of '<S7>/CoreSubsys' */
    {
      /* Computed Parameter: DoorOut_Y0
       * Referenced by: '<S9>/DoorOut'
       */
      {
        {
          false,                       /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */

        {
          0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */

        {
          0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */

        {
          false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */

          {
            false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      },

      /* Computed Parameter: Interlock_Y0
       * Referenced by: '<S9>/Interlock'
       */
      0,

      /* Start of '<S10>/CoreSubsys' */
      {
        /* Mask Parameter: ObstacleDetectionFunctionality_MoveAwayFromObstacle
         * Referenced by: '<S33>/Chart'
         */
        0.05,

        /* Mask Parameter: ObstacleDetectionFunctionality_NumOfClosingAttempts
         * Referenced by: '<S33>/Chart'
         */
        3.0,

        /* Mask Parameter: ObstacleDetectionFunctionality_NumOfOpeningAttempts
         * Referenced by: '<S33>/Chart'
         */
        3.0,

        /* Mask Parameter: ObstacleDetectionFunctionality_PauseBeforeClosingAttempt
         * Referenced by: '<S33>/Chart'
         */
        2.0,

        /* Mask Parameter: ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt
         * Referenced by: '<S33>/Chart'
         */
        2.0,

        /* Mask Parameter: CompareToConstant2_const
         * Referenced by: '<S11>/Constant'
         */
        0.0,

        /* Mask Parameter: CompareToConstant3_const
         * Referenced by: '<S12>/Constant'
         */
        1.0,

        /* Mask Parameter: CompareToConstant4_const
         * Referenced by: '<S80>/Constant'
         */
        0.5,

        /* Mask Parameter: CompareToConstant1_const
         * Referenced by: '<S79>/Constant'
         */
        0.3,

        /* Mask Parameter: CompareToConstant1_const_k
         * Referenced by: '<S23>/Constant'
         */
        1.0,

        /* Mask Parameter: CompareToConstant2_const_i
         * Referenced by: '<S24>/Constant'
         */
        0.0,

        /* Mask Parameter: DetectIncrease_vinit
         * Referenced by: '<S16>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectDecrease_vinit
         * Referenced by: '<S81>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectIncrease_vinit_p
         * Referenced by: '<S83>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectIncrease1_vinit
         * Referenced by: '<S84>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectDecrease1_vinit
         * Referenced by: '<S82>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectDecrease_vinit_i
         * Referenced by: '<S93>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: DetectIncrease_vinit_o
         * Referenced by: '<S94>/Delay Input1'
         */
        0.0,

        /* Mask Parameter: SRLatchResetPriority_initial_condition
         * Referenced by: '<S51>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchResetPriority1_initial_condition
         * Referenced by: '<S52>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchResetPriority2_initial_condition
         * Referenced by: '<S53>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchResetPriority_initial_condition_m
         * Referenced by: '<S62>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchResetPriority_initial_condition_k
         * Referenced by: '<S64>/Memory'
         */
        0,

        /* Mask Parameter: MotorOpenLatch_initial_condition
         * Referenced by: '<S76>/Memory'
         */
        0,

        /* Mask Parameter: MotorCloseLatch_initial_condition
         * Referenced by: '<S75>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchSetPriority2_initial_condition
         * Referenced by: '<S86>/Memory'
         */
        0,

        /* Mask Parameter: SRLatchSetPriority1_initial_condition
         * Referenced by: '<S85>/Memory'
         */
        0,

        /* Mask Parameter: DetectDecrease_vinit_f
         * Referenced by: '<S47>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease_vinit_d
         * Referenced by: '<S48>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease1_vinit_i
         * Referenced by: '<S49>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease1_vinit_m
         * Referenced by: '<S17>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease_vinit_g
         * Referenced by: '<S60>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease1_vinit_i5
         * Referenced by: '<S61>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectDecrease_vinit_b
         * Referenced by: '<S73>/Delay Input1'
         */
        0,

        /* Mask Parameter: DetectIncrease_vinit_dn
         * Referenced by: '<S74>/Delay Input1'
         */
        0,

        /* Computed Parameter: Constant_Value
         * Referenced by: '<S44>/Constant'
         */
        {
          0.0,                         /* DoorOutsideLamp */
          0.0,                         /* DoorInsideLamp */
          0.0,                         /* DoorOpenPBLight */
          0.0,                         /* DoorClosePBLight */
          false,                       /* DoorsFaulty */

          {
            false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* DCUTCMSMessages */
        },

        /* Computed Parameter: Constant_Value_c
         * Referenced by: '<S87>/Constant'
         */
        {
          0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },

        /* Computed Parameter: Constant_Value_m
         * Referenced by: '<S34>/Constant'
         */
        {
          0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0                          /* DoorIsolated */
        },

        /* Computed Parameter: Constant_Value_ca
         * Referenced by: '<S90>/Constant'
         */
        {
          false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */

          {
            false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        },

        /* Computed Parameter: Constant_Value_d
         * Referenced by: '<S89>/Constant'
         */
        {
          0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },

        /* Computed Parameter: Messages_Value
         * Referenced by: '<S45>/Messages'
         */
        {
          false,                       /* DoorOpenObstacleDetected */
          false,                       /* DoorCloseObstacleDetected */
          false,                       /* DoorFailedToLock */
          false,                       /* DoorFailedToUnlock */
          false,                       /* DoorMotorFailure */
          false,                       /* DoorMajorFault */
          false,                       /* DCSRFailure */
          false,                       /* DCSLFailure */
          false,                       /* DLSRFailure */
          false,                       /* DLSLFailure */
          false,                       /* DCUFailure */
          false,                       /* DoorUnexpectedUnlocking */
          false,                       /* DoorIsolatedWire */
          false,                       /* DoorEmergencyHandleWire */
          false                        /* UnexpectedDoorOpeningDetectedByCC */
        },

        /* Computed Parameter: Constant_Value_co
         * Referenced by: '<S88>/Constant'
         */
        {
          false,                       /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },

        /* Expression: 3
         * Referenced by: '<S45>/YellowON'
         */
        3.0,

        /* Expression: 2
         * Referenced by: '<S45>/YellowFlashing'
         */
        2.0,

        /* Expression: 1
         * Referenced by: '<S45>/RedON'
         */
        1.0,

        /* Expression: 1
         * Referenced by: '<S54>/Constant'
         */
        1.0,

        /* Expression: 2
         * Referenced by: '<S54>/Constant1'
         */
        2.0,

        /* Expression: 0
         * Referenced by: '<S25>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S21>/Constant7'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S25>/Constant1'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S20>/Constant7'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S20>/Speed'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S21>/Speed'
         */
        0.0,

        /* Computed Parameter: WeightedSampleTime_WtEt
         * Referenced by: '<S18>/Weighted Sample Time'
         */
        0.05,

        /* Expression: 0
         * Referenced by: '<S13>/Constant2'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S13>/Constant4'
         */
        0.0,

        /* Expression: 0.05
         * Referenced by: '<S13>/Constant3'
         */
        0.05,

        /* Expression: 0.25
         * Referenced by: '<S13>/Constant5'
         */
        0.25,

        /* Expression: 0
         * Referenced by: '<S59>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S63>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S91>/Constant'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S92>/Constant'
         */
        0.0,

        /* Expression: 1
         * Referenced by: '<S13>/Constant1'
         */
        1.0,

        /* Expression: 0
         * Referenced by: '<S10>/Unit Delay2'
         */
        0.0,

        /* Expression: 0
         * Referenced by: '<S18>/Unit Delay1'
         */
        0.0,

        /* Computed Parameter: Constant_Value_e
         * Referenced by: '<S46>/Constant'
         */
        0,

        /* Expression: true
         * Referenced by: '<S13>/Constant'
         */
        1,

        /* Computed Parameter: UnitDelay1_InitialCondition_f
         * Referenced by: '<S10>/Unit Delay1'
         */
        1,

        /* Computed Parameter: UnitDelay_InitialCondition
         * Referenced by: '<S13>/Unit Delay'
         */
        0,

        /* Computed Parameter: IC_Value
         * Referenced by: '<S18>/IC'
         */
        1,

        /* Computed Parameter: UnitDelay_InitialCondition_k
         * Referenced by: '<S10>/Unit Delay'
         */
        0,

        /* Computed Parameter: UnitDelay3_InitialCondition
         * Referenced by: '<S10>/Unit Delay3'
         */
        0,

        /* Computed Parameter: Gain1_Gain
         * Referenced by: '<S70>/Gain1'
         */
        -128,

        /* Start of '<S35>/LeadingEdgePulseTunable1' */
        {
          /* Mask Parameter: DetectIncrease_vinit
           * Referenced by: '<S41>/Delay Input1'
           */
          0,

          /* Expression: 0
           * Referenced by: '<S43>/Constant'
           */
          0.0,

          /* Expression: -1
           * Referenced by: '<S42>/Gain'
           */
          -1.0,

          /* Expression: 0
           * Referenced by: '<S42>/Initialise'
           */
          0.0,

          /* Expression: 1
           * Referenced by: '<S42>/IC'
           */
          1.0,

          /* Computed Parameter: DiscreteTimeIntegrator_gainval
           * Referenced by: '<S42>/Discrete-Time Integrator'
           */
          0.05,

          /* Expression: 0
           * Referenced by: '<S42>/Discrete-Time Integrator'
           */
          0.0
        }
        ,

        /* End of '<S35>/LeadingEdgePulseTunable1' */

        /* Start of '<S35>/LeadingEdgePulseTunable' */
        {
          /* Mask Parameter: DetectIncrease_vinit
           * Referenced by: '<S38>/Delay Input1'
           */
          0,

          /* Expression: 0
           * Referenced by: '<S40>/Constant'
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
          0.05,

          /* Expression: 0
           * Referenced by: '<S39>/Discrete-Time Integrator'
           */
          0.0
        }
        ,

        /* End of '<S35>/LeadingEdgePulseTunable' */

        /* Start of '<S50>/If Action Subsystem4' */
        {
          /* Expression: 0
           * Referenced by: '<S58>/Constant'
           */
          0.0,

          /* Expression: 0
           * Referenced by: '<S58>/Constant1'
           */
          0.0
        }
        ,

        /* End of '<S50>/If Action Subsystem4' */

        /* Start of '<S50>/If Action Subsystem3' */
        {
          /* Expression: 0
           * Referenced by: '<S57>/Constant'
           */
          0.0,

          /* Expression: 1
           * Referenced by: '<S57>/Constant1'
           */
          1.0
        }
        ,

        /* End of '<S50>/If Action Subsystem3' */

        /* Start of '<S50>/If Action Subsystem2' */
        {
          /* Expression: 1
           * Referenced by: '<S56>/Constant'
           */
          1.0,

          /* Expression: 0
           * Referenced by: '<S56>/Constant1'
           */
          0.0
        }
        ,

        /* End of '<S50>/If Action Subsystem2' */

        /* Start of '<S50>/If Action Subsystem1' */
        {
          /* Expression: 1
           * Referenced by: '<S55>/Constant'
           */
          1.0,

          /* Expression: 2
           * Referenced by: '<S55>/Constant1'
           */
          2.0
        }
        ,

        /* End of '<S50>/If Action Subsystem1' */

        /* Start of '<S31>/DoorCloseDelay' */
        {
          /* Expression: 0
           * Referenced by: '<S71>/Constant'
           */
          0.0,

          /* Computed Parameter: Timer_gainval
           * Referenced by: '<S66>/Timer'
           */
          0.05,

          /* Expression: 0
           * Referenced by: '<S66>/Timer'
           */
          0.0,

          /* Expression: 0
           * Referenced by: '<S66>/Timer'
           */
          0.0
        }
        ,

        /* End of '<S31>/DoorCloseDelay' */

        /* Start of '<S31>/DoorOpenDelay' */
        {
          /* Expression: 0
           * Referenced by: '<S72>/Constant'
           */
          0.0,

          /* Computed Parameter: Timer_gainval
           * Referenced by: '<S68>/Timer'
           */
          0.05,

          /* Expression: 0
           * Referenced by: '<S68>/Timer'
           */
          0.0,

          /* Expression: 0
           * Referenced by: '<S68>/Timer'
           */
          0.0
        }
        ,

        /* End of '<S31>/DoorOpenDelay' */

        /* Start of '<S31>/NoMotorCommand' */
        {
          /* Expression: 0
           * Referenced by: '<S69>/Constant'
           */
          0.0
        }
        ,

        /* End of '<S31>/NoMotorCommand' */

        /* Start of '<S31>/DoorOpen' */
        {
          /* Expression: 1
           * Referenced by: '<S67>/Constant'
           */
          1.0
        }
        ,

        /* End of '<S31>/DoorOpen' */

        /* Start of '<S31>/DoorClose' */
        {
          /* Expression: -1
           * Referenced by: '<S65>/Constant'
           */
          -1.0
        }
        /* End of '<S31>/DoorClose' */
      }
      /* End of '<S10>/CoreSubsys' */
    }
    /* End of '<S7>/CoreSubsys' */
  }
  /* End of '<S1>/CoreSubsys' */
};

/*
 * Output and update for action system:
 *    '<S31>/DoorClose'
 *    '<S31>/DoorOpen'
 *    '<S31>/NoMotorCommand'
 */
void DoorSystem_DoorClose(real_T *rty_MotorCommand, P_DoorClose_DoorSystem_T
  *localP)
{
  /* SignalConversion generated from: '<S65>/MotorCommand' incorporates:
   *  Constant: '<S65>/Constant'
   */
  *rty_MotorCommand = localP->Constant_Value;
}

/*
 * System initialize for atomic system:
 *    '<S31>/DoorOpenDelay'
 *    '<S31>/DoorCloseDelay'
 *    '<S108>/TimerOnDelay NoInit1'
 *    '<S108>/TimerOnDelay NoInit2'
 */
void DoorSystem_DoorOpenDelay_Init(DW_DoorOpenDelay_DoorSystem_T *localDW,
  P_DoorOpenDelay_DoorSystem_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S68>/Timer' */
  localDW->Timer_DSTATE = localP->Timer_IC;
  localDW->Timer_PrevResetState = 0;
}

/*
 * Start for atomic system:
 *    '<S31>/DoorOpenDelay'
 *    '<S31>/DoorCloseDelay'
 *    '<S108>/TimerOnDelay NoInit1'
 *    '<S108>/TimerOnDelay NoInit2'
 */
void DoorSystem_DoorOpenDelay_Start(B_DoorOpenDelay_DoorSystem_T *localB,
  DW_DoorOpenDelay_DoorSystem_T *localDW)
{
  localDW->Timer_DSTATE = 0.0;
  localB->Compare = false;
}

/*
 * Output and update for atomic system:
 *    '<S31>/DoorOpenDelay'
 *    '<S31>/DoorCloseDelay'
 *    '<S108>/TimerOnDelay NoInit1'
 *    '<S108>/TimerOnDelay NoInit2'
 */
void DoorSystem_DoorOpenDelay(boolean_T rtu_In, B_DoorOpenDelay_DoorSystem_T
  *localB, DW_DoorOpenDelay_DoorSystem_T *localDW, P_DoorOpenDelay_DoorSystem_T *
  localP, real_T rtp_UpperSaturationLimit)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator_j;
  int32_T rtb_Timer_o2;
  real_T Timer_o1;

  /* Logic: '<S68>/Logical Operator' */
  rtb_LogicalOperator_j = !rtu_In;

  /* DiscreteIntegrator: '<S68>/Timer' incorporates:
   *  DataTypeConversion: '<S68>/Data Type Conversion'
   */
  if (rtb_LogicalOperator_j || (localDW->Timer_PrevResetState != 0)) {
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

  /* End of DiscreteIntegrator: '<S68>/Timer' */

  /* RelationalOperator: '<S72>/Compare' incorporates:
   *  Constant: '<S72>/Constant'
   */
  localB->Compare = (rtb_Timer_o2 > localP->Constant_Value);

  /* Update for DiscreteIntegrator: '<S68>/Timer' */
  localDW->Timer_DSTATE = Timer_o1;
  localDW->Timer_PrevResetState = static_cast<int8_T>(rtb_LogicalOperator_j);
}

/*
 * Output and update for action system:
 *    '<S50>/If Action Subsystem1'
 *    '<S50>/If Action Subsystem2'
 *    '<S50>/If Action Subsystem3'
 *    '<S50>/If Action Subsystem4'
 */
void DoorSystem_IfActionSubsystem1(real_T rty_Out2[2],
  P_IfActionSubsystem1_DoorSystem_T *localP)
{
  /* SignalConversion generated from: '<S55>/Out2' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S55>/Constant1'
   */
  rty_Out2[0] = localP->Constant_Value;
  rty_Out2[1] = localP->Constant1_Value;
}

/*
 * System initialize for atomic system:
 *    '<S35>/LeadingEdgePulseTunable'
 *    '<S35>/LeadingEdgePulseTunable1'
 */
void DoorSystem_LeadingEdgePulseTunable_Init
  (DW_LeadingEdgePulseTunable_DoorSystem_T *localDW,
   P_LeadingEdgePulseTunable_DoorSystem_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DetectIncrease_vinit;

  /* SystemInitialize for Atomic SubSystem: '<S36>/TimerOffDelay NoInitTunable' */
  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 1U;
  localDW->DiscreteTimeIntegrator_PrevResetState = 0;

  /* End of SystemInitialize for SubSystem: '<S36>/TimerOffDelay NoInitTunable' */
}

/*
 * Start for atomic system:
 *    '<S35>/LeadingEdgePulseTunable'
 *    '<S35>/LeadingEdgePulseTunable1'
 */
void DoorSystem_LeadingEdgePulseTunable_Start
  (B_LeadingEdgePulseTunable_DoorSystem_T *localB,
   DW_LeadingEdgePulseTunable_DoorSystem_T *localDW)
{
  /* Start for Atomic SubSystem: '<S36>/TimerOffDelay NoInitTunable' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  localB->LogicalOperator1 = false;

  /* Start for InitialCondition: '<S39>/IC' */
  localDW->IC_FirstOutputTime = true;

  /* End of Start for SubSystem: '<S36>/TimerOffDelay NoInitTunable' */
}

/*
 * Output and update for atomic system:
 *    '<S35>/LeadingEdgePulseTunable'
 *    '<S35>/LeadingEdgePulseTunable1'
 */
void DoorSystem_LeadingEdgePulseTunable(boolean_T rtu_In,
  B_LeadingEdgePulseTunable_DoorSystem_T *localB,
  DW_LeadingEdgePulseTunable_DoorSystem_T *localDW,
  P_LeadingEdgePulseTunable_DoorSystem_T *localP, real_T rtp_DoorOpenAlarmTime)
{
  /* local block i/o variables */
  boolean_T rtb_FixPtRelationalOperator_c;
  real_T rtb_DiscreteTimeIntegrator_o2_d;
  real_T DiscreteTimeIntegrator_o1;

  /* RelationalOperator: '<S38>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S38>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_c = (static_cast<int32_T>(rtu_In) >
    static_cast<int32_T>(localDW->DelayInput1_DSTATE));

  /* Outputs for Atomic SubSystem: '<S36>/TimerOffDelay NoInitTunable' */
  /* InitialCondition: '<S39>/IC' incorporates:
   *  Constant: '<S39>/Initialise'
   */
  if (localDW->IC_FirstOutputTime) {
    localDW->IC_FirstOutputTime = false;
    rtb_DiscreteTimeIntegrator_o2_d = localP->IC_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2_d = localP->Initialise_Value;
  }

  /* End of InitialCondition: '<S39>/IC' */

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S39>/Initialise'
   *  Constant: '<S39>/OffTime'
   */
  if (rtb_DiscreteTimeIntegrator_o2_d != 0.0) {
    rtb_DiscreteTimeIntegrator_o2_d = localP->Initialise_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2_d = rtp_DoorOpenAlarmTime;
  }

  /* End of Switch: '<S39>/Switch2' */

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S39>/Data Type Conversion'
   *  Gain: '<S39>/Gain'
   *  Logic: '<S39>/Logical Operator'
   */
  if (localDW->DiscreteTimeIntegrator_IC_LOADING != 0) {
    localDW->DiscreteTimeIntegrator_DSTATE = rtb_DiscreteTimeIntegrator_o2_d;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= rtp_DoorOpenAlarmTime) {
      localDW->DiscreteTimeIntegrator_DSTATE = rtp_DoorOpenAlarmTime;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }
  }

  if (rtb_FixPtRelationalOperator_c ||
      (localDW->DiscreteTimeIntegrator_PrevResetState != 0)) {
    localDW->DiscreteTimeIntegrator_DSTATE = rtb_DiscreteTimeIntegrator_o2_d;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= rtp_DoorOpenAlarmTime) {
      localDW->DiscreteTimeIntegrator_DSTATE = rtp_DoorOpenAlarmTime;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }
  }

  DiscreteTimeIntegrator_o1 = localP->Gain_Gain * static_cast<real_T>
    (!rtb_FixPtRelationalOperator_c) * localP->DiscreteTimeIntegrator_gainval +
    localDW->DiscreteTimeIntegrator_DSTATE;
  if (DiscreteTimeIntegrator_o1 >= rtp_DoorOpenAlarmTime) {
    DiscreteTimeIntegrator_o1 = rtp_DoorOpenAlarmTime;
    rtb_DiscreteTimeIntegrator_o2_d = 1.0;
  } else if (DiscreteTimeIntegrator_o1 <=
             localP->DiscreteTimeIntegrator_LowerSat) {
    DiscreteTimeIntegrator_o1 = localP->DiscreteTimeIntegrator_LowerSat;
    rtb_DiscreteTimeIntegrator_o2_d = -1.0;
  } else {
    rtb_DiscreteTimeIntegrator_o2_d = 0.0;
  }

  /* End of DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */

  /* Logic: '<S39>/Logical Operator1' incorporates:
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S40>/Compare'
   */
  localB->LogicalOperator1 = ((rtb_DiscreteTimeIntegrator_o2_d >=
    localP->Constant_Value) || rtb_FixPtRelationalOperator_c);

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 0U;
  localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator_o1;
  localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
    (rtb_FixPtRelationalOperator_c);

  /* End of Outputs for SubSystem: '<S36>/TimerOffDelay NoInitTunable' */

  /* Update for UnitDelay: '<S38>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_In;
}

/*
 * System initialize for atomic system:
 *    '<S100>/TimerOffDelay NoInit'
 *    '<S99>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit1'
 *    '<S116>/TimerOffDelay NoInit2'
 */
void DoorSystem_TimerOffDelayNoInit_Init(DW_TimerOffDelayNoInit_DoorSystem_T
  *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 1U;
  localDW->DiscreteTimeIntegrator_PrevResetState = 0;
}

/*
 * Start for atomic system:
 *    '<S100>/TimerOffDelay NoInit'
 *    '<S99>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit1'
 *    '<S116>/TimerOffDelay NoInit2'
 */
void DoorSystem_TimerOffDelayNoInit_Start(B_TimerOffDelayNoInit_DoorSystem_T
  *localB, DW_TimerOffDelayNoInit_DoorSystem_T *localDW)
{
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  localB->LogicalOperator1 = false;

  /* Start for InitialCondition: '<S105>/IC' */
  localDW->IC_FirstOutputTime = true;
}

/*
 * Output and update for atomic system:
 *    '<S100>/TimerOffDelay NoInit'
 *    '<S99>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit'
 *    '<S116>/TimerOffDelay NoInit1'
 *    '<S116>/TimerOffDelay NoInit2'
 */
void DoorSystem_TimerOffDelayNoInit(boolean_T rtu_In,
  B_TimerOffDelayNoInit_DoorSystem_T *localB,
  DW_TimerOffDelayNoInit_DoorSystem_T *localDW,
  P_TimerOffDelayNoInit_DoorSystem_T *localP)
{
  real_T rtb_DiscreteTimeIntegrator_o2;
  real_T DiscreteTimeIntegrator_o1;

  /* InitialCondition: '<S105>/IC' incorporates:
   *  Constant: '<S105>/Initialise'
   */
  if (localDW->IC_FirstOutputTime) {
    localDW->IC_FirstOutputTime = false;
    rtb_DiscreteTimeIntegrator_o2 = localP->IC_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  }

  /* End of InitialCondition: '<S105>/IC' */

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S105>/Initialise'
   *  Constant: '<S105>/OffTime'
   */
  if (rtb_DiscreteTimeIntegrator_o2 != 0.0) {
    rtb_DiscreteTimeIntegrator_o2 = localP->Initialise_Value;
  } else {
    rtb_DiscreteTimeIntegrator_o2 = localP->OffTime_Value;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S105>/Data Type Conversion'
   *  Gain: '<S105>/Gain'
   *  Logic: '<S105>/Logical Operator'
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

  /* End of DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */

  /* Logic: '<S105>/Logical Operator1' incorporates:
   *  Constant: '<S106>/Constant'
   *  RelationalOperator: '<S106>/Compare'
   */
  localB->LogicalOperator1 = ((rtb_DiscreteTimeIntegrator_o2 >=
    localP->Constant_Value) || rtu_In);

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_IC_LOADING = 0U;
  localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator_o1;
  localDW->DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>(rtu_In);
}

/* System initialize for referenced model: 'DoorSystem' */
void DoorSystem_Init(B_DoorSystem_c_T *localB, DW_DoorSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_o;
  int32_T ForEach_itr_dr;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_k;
  int32_T i;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] = DoorSystem_P.UnitDelay_InitialCondition;
  }

  /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

  /* SystemInitialize for Iterator SubSystem: '<Root>/DoorSystemPerCar' */
  for (ForEach_itr_o = 0; ForEach_itr_o < 8; ForEach_itr_o++) {
    /* SystemInitialize for Enabled SubSystem: '<S1>/EnabledVehicles' */
    /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
    localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE =
      DoorSystem_P.CoreSubsys.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S110>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_n =
      DoorSystem_P.CoreSubsys.DetectIncrease_vinit;

    /* InitializeConditions for Memory: '<S117>/Memory' */
    localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput =
      DoorSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition;

    /* InitializeConditions for UnitDelay: '<S108>/Unit Delay1' */
    localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE_e =
      DoorSystem_P.CoreSubsys.UnitDelay1_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S124>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE =
      DoorSystem_P.CoreSubsys.DetectIncrease1_vinit;

    /* InitializeConditions for UnitDelay: '<S123>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_j =
      DoorSystem_P.CoreSubsys.DetectDecrease_vinit;

    /* InitializeConditions for UnitDelay: '<S126>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h3 =
      DoorSystem_P.CoreSubsys.DetectIncrease3_vinit;

    /* InitializeConditions for UnitDelay: '<S125>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h =
      DoorSystem_P.CoreSubsys.DetectIncrease2_vinit;

    /* InitializeConditions for UnitDelay: '<S127>/Unit Delay1' */
    localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE =
      DoorSystem_P.CoreSubsys.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
    localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE_e =
      DoorSystem_P.CoreSubsys.UnitDelay_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S111>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_e =
      DoorSystem_P.CoreSubsys.DetectIncrease1_vinit_n;

    /* InitializeConditions for Memory: '<S118>/Memory' */
    localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_k =
      DoorSystem_P.CoreSubsys.SRLatchResetPriority1_initial_condition;

    /* InitializeConditions for UnitDelay: '<S112>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_ej =
      DoorSystem_P.CoreSubsys.DetectIncrease2_vinit_a;

    /* InitializeConditions for Memory: '<S119>/Memory' */
    localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_h =
      DoorSystem_P.CoreSubsys.SRLatchResetPriority2_initial_condition;

    /* InitializeConditions for UnitDelay: '<S114>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_ni =
      DoorSystem_P.CoreSubsys.DetectIncrease4_vinit;

    /* InitializeConditions for UnitDelay: '<S113>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_a =
      DoorSystem_P.CoreSubsys.DetectIncrease3_vinit_d;

    /* InitializeConditions for Memory: '<S120>/Memory' */
    localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_l =
      DoorSystem_P.CoreSubsys.SRLatchResetPriority3_initial_condition;

    /* InitializeConditions for UnitDelay: '<S115>/Delay Input1' */
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_hl =
      DoorSystem_P.CoreSubsys.DetectIncrease5_vinit;

    /* SystemInitialize for Iterator SubSystem: '<S5>/For Each Subsystem' */
    for (ForEach_itr_dr = 0; ForEach_itr_dr < 8; ForEach_itr_dr++) {
      /* SystemInitialize for Atomic SubSystem: '<S98>/LeadingEdgePulse' */
      /* InitializeConditions for UnitDelay: '<S101>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
        DelayInput1_DSTATE =
        DoorSystem_P.CoreSubsys.CoreSubsys_pn.DetectIncrease_vinit;

      /* SystemInitialize for Atomic SubSystem: '<S99>/TimerOffDelay NoInit' */
      DoorSystem_TimerOffDelayNoInit_Init(&localDW->CoreSubsys[ForEach_itr_o].
        CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit_n);

      /* End of SystemInitialize for SubSystem: '<S99>/TimerOffDelay NoInit' */
      /* End of SystemInitialize for SubSystem: '<S98>/LeadingEdgePulse' */

      /* SystemInitialize for Atomic SubSystem: '<S98>/TrailingEdgePulse' */
      /* InitializeConditions for UnitDelay: '<S104>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
        DelayInput1_DSTATE_n =
        DoorSystem_P.CoreSubsys.CoreSubsys_pn.DetectDecrease_vinit;

      /* SystemInitialize for Atomic SubSystem: '<S100>/TimerOffDelay NoInit' */
      DoorSystem_TimerOffDelayNoInit_Init(&localDW->CoreSubsys[ForEach_itr_o].
        CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit);

      /* End of SystemInitialize for SubSystem: '<S100>/TimerOffDelay NoInit' */
      /* End of SystemInitialize for SubSystem: '<S98>/TrailingEdgePulse' */
    }

    /* End of SystemInitialize for SubSystem: '<S5>/For Each Subsystem' */

    /* SystemInitialize for Iterator SubSystem: '<S4>/ForEachDoor' */
    for (ForEach_itr_e = 0; ForEach_itr_e < 8; ForEach_itr_e++) {
      /* SystemInitialize for Enabled SubSystem: '<S7>/DoorLogic' */
      /* SystemInitialize for Iterator SubSystem: '<S9>/DoorSystem' */
      for (ForEach_itr_k = 0; ForEach_itr_k < 2; ForEach_itr_k++) {
        /* InitializeConditions for UnitDelay: '<S16>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit;

        /* InitializeConditions for UnitDelay: '<S17>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_j =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_m;

        /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_lq =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_g;

        /* InitializeConditions for Memory: '<S62>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition_m;

        /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay1_InitialCondition_f;

        /* InitializeConditions for UnitDelay: '<S10>/Unit Delay2' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay2_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_p =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_i5;

        /* InitializeConditions for Memory: '<S64>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_o =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition_k;

        /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay_DSTATE =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition;

        /* InitializeConditions for Memory: '<S76>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_p =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.MotorOpenLatch_initial_condition;

        /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay_DSTATE_h =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition_k;

        /* InitializeConditions for UnitDelay: '<S73>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_jd =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_b;

        /* InitializeConditions for Memory: '<S75>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.MotorCloseLatch_initial_condition;

        /* InitializeConditions for UnitDelay: '<S81>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_l =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit;

        /* InitializeConditions for Memory: '<S86>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_bz =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchSetPriority2_initial_condition;

        /* InitializeConditions for UnitDelay: '<S83>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_o =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_p;

        /* InitializeConditions for UnitDelay: '<S84>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_g =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit;

        /* InitializeConditions for Memory: '<S85>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_f =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchSetPriority1_initial_condition;

        /* InitializeConditions for UnitDelay: '<S82>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_e =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease1_vinit;

        /* InitializeConditions for UnitDelay: '<S74>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_a =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_dn;

        /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay1_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S10>/Unit Delay3' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay3_DSTATE =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay3_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S93>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_c =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_i;

        /* InitializeConditions for UnitDelay: '<S94>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_ly =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_o;

        /* SystemInitialize for Atomic SubSystem: '<S31>/DoorOpenDelay' */
        DoorSystem_DoorOpenDelay_Init(&localDW->CoreSubsys[ForEach_itr_o].
          CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].DoorOpenDelay,
          &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay);

        /* End of SystemInitialize for SubSystem: '<S31>/DoorOpenDelay' */

        /* SystemInitialize for Chart: '<S33>/Chart' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].is_Active = DoorSystem_IN_NO_ACTIVE_CHILD;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].is_Active1 = DoorSystem_IN_NO_ACTIVE_CHILD;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].temporalCounter_i1 = 0U;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].is_active_c1_DoorSystem = 0U;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
          DoorSystem_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for Atomic SubSystem: '<S31>/DoorCloseDelay' */
        DoorSystem_DoorOpenDelay_Init(&localDW->CoreSubsys[ForEach_itr_o].
          CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].DoorCloseDelay,
          &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay);

        /* End of SystemInitialize for SubSystem: '<S31>/DoorCloseDelay' */

        /* SystemInitialize for IfAction SubSystem: '<S26>/DCUOnAudio' */
        /* SystemInitialize for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable' */
        DoorSystem_LeadingEdgePulseTunable_Init(&localDW->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable,
          &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable);

        /* End of SystemInitialize for SubSystem: '<S35>/LeadingEdgePulseTunable' */

        /* SystemInitialize for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable1' */
        DoorSystem_LeadingEdgePulseTunable_Init(&localDW->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable1,
          &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1);

        /* End of SystemInitialize for SubSystem: '<S35>/LeadingEdgePulseTunable1' */
        /* End of SystemInitialize for SubSystem: '<S26>/DCUOnAudio' */

        /* SystemInitialize for IfAction SubSystem: '<S27>/DCUOnIndicators1' */
        /* InitializeConditions for UnitDelay: '<S47>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_m =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_f;

        /* InitializeConditions for Memory: '<S51>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_j =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition;

        /* InitializeConditions for UnitDelay: '<S48>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_md =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_d;

        /* InitializeConditions for Memory: '<S52>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_l =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority1_initial_condition;

        /* InitializeConditions for UnitDelay: '<S49>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_n =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_i;

        /* InitializeConditions for Memory: '<S53>/Memory' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b2 =
          DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority2_initial_condition;

        /* End of SystemInitialize for SubSystem: '<S27>/DCUOnIndicators1' */
      }

      /* End of SystemInitialize for SubSystem: '<S9>/DoorSystem' */

      /* SystemInitialize for Outport: '<S9>/DoorOut' */
      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
        ImpAsg_InsertedFor_DoorOut_at_inport_0[0] =
        DoorSystem_P.CoreSubsys.CoreSubsys.DoorOut_Y0;
      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
        ImpAsg_InsertedFor_DoorOut_at_inport_0[1] =
        DoorSystem_P.CoreSubsys.CoreSubsys.DoorOut_Y0;

      /* SystemInitialize for Outport: '<S9>/Interlock' */
      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].AND =
        DoorSystem_P.CoreSubsys.CoreSubsys.Interlock_Y0;

      /* End of SystemInitialize for SubSystem: '<S7>/DoorLogic' */
    }

    /* End of SystemInitialize for SubSystem: '<S4>/ForEachDoor' */

    /* SystemInitialize for Atomic SubSystem: '<S108>/TimerOnDelay NoInit2' */
    DoorSystem_DoorOpenDelay_Init(&localDW->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit2, &DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2);

    /* End of SystemInitialize for SubSystem: '<S108>/TimerOnDelay NoInit2' */

    /* SystemInitialize for Atomic SubSystem: '<S116>/TimerOffDelay NoInit' */
    DoorSystem_TimerOffDelayNoInit_Init(&localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit);

    /* End of SystemInitialize for SubSystem: '<S116>/TimerOffDelay NoInit' */

    /* SystemInitialize for Atomic SubSystem: '<S116>/TimerOffDelay NoInit1' */
    DoorSystem_TimerOffDelayNoInit_Init(&localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit1);

    /* End of SystemInitialize for SubSystem: '<S116>/TimerOffDelay NoInit1' */

    /* SystemInitialize for Atomic SubSystem: '<S116>/TimerOffDelay NoInit2' */
    DoorSystem_TimerOffDelayNoInit_Init(&localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit2);

    /* End of SystemInitialize for SubSystem: '<S116>/TimerOffDelay NoInit2' */

    /* SystemInitialize for Atomic SubSystem: '<S108>/TimerOnDelay NoInit1' */
    DoorSystem_DoorOpenDelay_Init(&localDW->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit1, &DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1);

    /* End of SystemInitialize for SubSystem: '<S108>/TimerOnDelay NoInit1' */

    /* SystemInitialize for Outport: '<S3>/DoorSystemVehicleOut' */
    localB->CoreSubsys[ForEach_itr_o].BusCreator1 =
      DoorSystem_P.CoreSubsys.DoorSystemVehicleOut_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/EnabledVehicles' */
  }

  /* End of SystemInitialize for SubSystem: '<Root>/DoorSystemPerCar' */
}

/* System reset for referenced model: 'DoorSystem' */
void DoorSystem_Reset(DW_DoorSystem_f_T *localDW)
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] = DoorSystem_P.UnitDelay_InitialCondition;
  }

  /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
}

/* Disable for referenced model: 'DoorSystem' */
void DoorSystem_Disable(DW_DoorSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_o;
  int32_T ForEach_itr_e;

  /* Disable for Iterator SubSystem: '<Root>/DoorSystemPerCar' */
  for (ForEach_itr_o = 0; ForEach_itr_o < 8; ForEach_itr_o++) {
    /* Disable for Enabled SubSystem: '<S1>/EnabledVehicles' */
    if (localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE) {
      /* Disable for Iterator SubSystem: '<S4>/ForEachDoor' */
      for (ForEach_itr_e = 0; ForEach_itr_e < 8; ForEach_itr_e++) {
        /* Disable for Enabled SubSystem: '<S7>/DoorLogic' */
        if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
            DoorLogic_MODE) {
          localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
            DoorLogic_MODE = false;
        }

        /* End of Disable for SubSystem: '<S7>/DoorLogic' */
      }

      /* End of Disable for SubSystem: '<S4>/ForEachDoor' */
      localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE = false;
    }

    /* End of Disable for SubSystem: '<S1>/EnabledVehicles' */
  }

  /* End of Disable for SubSystem: '<Root>/DoorSystemPerCar' */
}

/* Start for referenced model: 'DoorSystem' */
void DoorSystem_Start(B_DoorSystem_c_T *localB, DW_DoorSystem_f_T *localDW)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_o;
  int32_T ForEach_itr_dr;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_k;
  static const BD_DoorSystem_In_Vehicle tmp = { { { { 0.0,/* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      }, { { 0.0,                      /* isLeft */
          0.0                          /* NumberOfDoors */
        },                             /* Config */
        { 0.0,                         /* LocalDoorOpenPB */
          0.0,                         /* OpenCloseWidget */
          0.0,                         /* EmergencyAccessDevice */
          0.0,                         /* EmergencyEgressDevice */
          0.0                          /* LocalDoorIsolationLock */
        },                             /* InputControlStates */
        { false,                       /* DoorControlPower */
          false,                       /* DoorMotorPower */
          false,                       /* DoorEnable */
          false,                       /* DoorRelease */
          false,                       /* DoorOpen */
          false,                       /* DoorClose */
          false,                       /* DoorEmergencyRelease */
          false                        /* DoorIsolation */
        },                             /* ElectricalSignals */
        { 0.0,                         /* ObjectObstructingDoorWhileClosing */
          0.0,                         /* ObjectObstructingDoorWhileOpening */
          0.0,                         /* DoorFailToClose */
          0.0,                         /* DoorFailToOpen */
          0.0,                         /* DoorMotorCircuitFailure */
          0.0,                         /* DoorFailedToLock */
          0.0,                         /* DoorFailedToUnlock */
          0.0,                         /* DoorUnexpectedUnlocking */
          0.0,                         /* DoorDCUFailure */
          0.0,                         /* DCSRFailure */
          0.0,                         /* DCSLFailure */
          0.0,                         /* DLSRFailure */
          0.0,                         /* DLSLFailure */
          0.0,                         /* DoorMajorFault */
          0.0,                         /* DoorUnauthorisedOpen */
          0.0,                         /* UnexpectedDoorOpeningDetectedByCC */
          0.0,                         /* EmergencyDoorMechanicalUnlocked */
          0.0                          /* DoorEmergencyHandleActivation */
        }                              /* Faults */
      } }                              /* Doors */
  };

  static const BD_DoorSystem_Out_Vehicle tmp_0 = { { false,/* TrainDoorInterlockOk */
      false,                           /* VehicleDoorInterlockOk */
      false,                           /* TrainLeftDoorInterlockOk */
      false,                           /* TrainRightDoorInterlockOk */
      false,                           /* VehicleLeftDoorInterlockOk */
      false                            /* VehicleRightDoorInterlockOk */
    },                                 /* VehicleElectrical */
    { { { false,                       /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      }, { { false,                    /* DoorCloseInterlock */
          false                        /* DoorClosed */
        },                             /* ElectricalSignals */
        { 0.0,                         /* DoorPosition */
          0.0,                         /* DoorOutsideLamp */
          0.0                          /* DoorInsideLamp */
        },                             /* OutputControlStates */
        { 0.0,                         /* DoorOpeningAuthorised */
          0.0,                         /* DoorOpeningAlarm */
          0.0,                         /* DoorClosingAlarm */
          0.0,                         /* DoorEmergencyReleased */
          0.0,                         /* DoorIsolated */
          0.0,                         /* DoorClosing */
          0.0                          /* DoorOpening */
        },                             /* Audio */
        { false,                       /* DoorClosedStatus */
          false,                       /* DoorOpenStatus */
          false,                       /* DoorReleasedAuthorisedToOpenStatus */
          false,                       /* DoorEmergencyReleasedStatus */
          false,                       /* DoorIsolatedStatus */
          false,                       /* DoorFaultStatus */
          false,                       /* DoorObstacleDetected */
          false,                       /* DoorObstacleUnableToClose */
          false,                       /* DoorLockedStatus */
          false,                       /* DoorOpenPBLight */
          false,                       /* DoorClosedPBLight */
          { false,                     /* DoorOpenObstacleDetected */
            false,                     /* DoorCloseObstacleDetected */
            false,                     /* DoorFailedToLock */
            false,                     /* DoorFailedToUnlock */
            false,                     /* DoorMotorFailure */
            false,                     /* DoorMajorFault */
            false,                     /* DCSRFailure */
            false,                     /* DCSLFailure */
            false,                     /* DLSRFailure */
            false,                     /* DLSLFailure */
            false,                     /* DCUFailure */
            false,                     /* DoorUnexpectedUnlocking */
            false,                     /* DoorIsolatedWire */
            false,                     /* DoorEmergencyHandleWire */
            false                      /* UnexpectedDoorOpeningDetectedByCC */
          }                            /* Messages */
        }                              /* TCMS */
      } },                             /* Doors */
    { 0.0,                             /* Ramp */
      0.0,                             /* EmergencyDoorOpen */
      false,                           /* EmergencyDoorLocked */
      0.0,                             /* GasSpringLocked */
      0.0,                             /* RampSupportDown */
      0.0,                             /* LockingLeverUnlockAuth */
      false                            /* EmerDoorOpenFaultMessage */
    }                                  /* EmergencyDoor */
  };

  /* Start for Iterator SubSystem: '<Root>/DoorSystemPerCar' */
  for (ForEach_itr_o = 0; ForEach_itr_o < 8; ForEach_itr_o++) {
    /* Start for Enabled SubSystem: '<S1>/EnabledVehicles' */
    localB->CoreSubsys[ForEach_itr_o].BusAssignment = tmp;
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE = 0.0;
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_j = 0.0;
    localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h = 0.0;
    localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE = 0.0;
    localB->CoreSubsys[ForEach_itr_o].BusCreator1 = tmp_0;

    /* End of Start for SubSystem: '<S1>/EnabledVehicles' */
    /* Start for Enabled SubSystem: '<S1>/EnabledVehicles' */
    /* Start for Iterator SubSystem: '<S5>/For Each Subsystem' */
    for (ForEach_itr_dr = 0; ForEach_itr_dr < 8; ForEach_itr_dr++) {
      /* Start for Enabled SubSystem: '<S1>/EnabledVehicles' */
      /* Start for Iterator SubSystem: '<S5>/For Each Subsystem' */
      /* Start for Atomic SubSystem: '<S98>/LeadingEdgePulse' */
      /* Start for Atomic SubSystem: '<S99>/TimerOffDelay NoInit' */
      DoorSystem_TimerOffDelayNoInit_Start(&localB->CoreSubsys[ForEach_itr_o].
        CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit_n,
        &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
        TimerOffDelayNoInit_n);

      /* End of Start for SubSystem: '<S99>/TimerOffDelay NoInit' */
      /* End of Start for SubSystem: '<S98>/LeadingEdgePulse' */

      /* Start for Atomic SubSystem: '<S98>/TrailingEdgePulse' */
      /* Start for Atomic SubSystem: '<S100>/TimerOffDelay NoInit' */
      DoorSystem_TimerOffDelayNoInit_Start(&localB->CoreSubsys[ForEach_itr_o].
        CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit, &localDW->
        CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
        TimerOffDelayNoInit);

      /* End of Start for SubSystem: '<S100>/TimerOffDelay NoInit' */
      /* End of Start for SubSystem: '<S98>/TrailingEdgePulse' */
      /* End of Start for SubSystem: '<S5>/For Each Subsystem' */
      /* End of Start for SubSystem: '<S1>/EnabledVehicles' */
    }

    /* End of Start for SubSystem: '<S5>/For Each Subsystem' */
    /* End of Start for SubSystem: '<S1>/EnabledVehicles' */
    /* Start for Enabled SubSystem: '<S1>/EnabledVehicles' */
    /* Start for Iterator SubSystem: '<S4>/ForEachDoor' */
    for (ForEach_itr_e = 0; ForEach_itr_e < 8; ForEach_itr_e++) {
      /* Start for Enabled SubSystem: '<S7>/DoorLogic' */
      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].AND = false;

      /* Start for Iterator SubSystem: '<S9>/DoorSystem' */
      for (ForEach_itr_k = 0; ForEach_itr_k < 2; ForEach_itr_k++) {
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_l = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_o = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_g = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_e = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_c = 0.0;
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_ly = 0.0;

        /* Start for InitialCondition: '<S18>/IC' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].IC_FirstOutputTime = true;

        /* Start for Atomic SubSystem: '<S31>/DoorOpenDelay' */
        DoorSystem_DoorOpenDelay_Start(&localB->CoreSubsys[ForEach_itr_o].
          CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].DoorOpenDelay,
          &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          CoreSubsys[ForEach_itr_k].DoorOpenDelay);

        /* End of Start for SubSystem: '<S31>/DoorOpenDelay' */

        /* Start for Chart: '<S33>/Chart' */
        localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].OpenCMD = false;
        localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].CloseCMD = false;
        localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].ResetOtherCommands = false;
        localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].MaxOpenAttempts = false;
        localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].MaxCloseAttempts = false;

        /* Start for Atomic SubSystem: '<S31>/DoorCloseDelay' */
        DoorSystem_DoorOpenDelay_Start(&localB->CoreSubsys[ForEach_itr_o].
          CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].DoorCloseDelay,
          &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          CoreSubsys[ForEach_itr_k].DoorCloseDelay);

        /* End of Start for SubSystem: '<S31>/DoorCloseDelay' */

        /* Start for IfAction SubSystem: '<S26>/DCUOnAudio' */
        /* Start for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable' */
        DoorSystem_LeadingEdgePulseTunable_Start(&localB->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable,
          &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable);

        /* End of Start for SubSystem: '<S35>/LeadingEdgePulseTunable' */

        /* Start for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable1' */
        DoorSystem_LeadingEdgePulseTunable_Start(&localB->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
          .CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable1,
          &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable1);

        /* End of Start for SubSystem: '<S35>/LeadingEdgePulseTunable1' */
        /* End of Start for SubSystem: '<S26>/DCUOnAudio' */
      }

      /* End of Start for SubSystem: '<S9>/DoorSystem' */
      /* End of Start for SubSystem: '<S7>/DoorLogic' */
    }

    /* End of Start for SubSystem: '<S4>/ForEachDoor' */

    /* Start for InitialCondition: '<S127>/IC' */
    localDW->CoreSubsys[ForEach_itr_o].IC_FirstOutputTime = true;

    /* Start for Atomic SubSystem: '<S108>/TimerOnDelay NoInit2' */
    DoorSystem_DoorOpenDelay_Start(&localB->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit2, &localDW->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit2);

    /* End of Start for SubSystem: '<S108>/TimerOnDelay NoInit2' */

    /* Start for Atomic SubSystem: '<S116>/TimerOffDelay NoInit' */
    DoorSystem_TimerOffDelayNoInit_Start(&localB->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit, &localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit);

    /* End of Start for SubSystem: '<S116>/TimerOffDelay NoInit' */

    /* Start for Atomic SubSystem: '<S116>/TimerOffDelay NoInit1' */
    DoorSystem_TimerOffDelayNoInit_Start(&localB->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit1, &localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit1);

    /* End of Start for SubSystem: '<S116>/TimerOffDelay NoInit1' */

    /* Start for Atomic SubSystem: '<S116>/TimerOffDelay NoInit2' */
    DoorSystem_TimerOffDelayNoInit_Start(&localB->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit2, &localDW->CoreSubsys[ForEach_itr_o].
      TimerOffDelayNoInit2);

    /* End of Start for SubSystem: '<S116>/TimerOffDelay NoInit2' */

    /* Start for Atomic SubSystem: '<S108>/TimerOnDelay NoInit1' */
    DoorSystem_DoorOpenDelay_Start(&localB->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit1, &localDW->CoreSubsys[ForEach_itr_o].
      TimerOnDelayNoInit1);

    /* End of Start for SubSystem: '<S108>/TimerOnDelay NoInit1' */
    /* End of Start for SubSystem: '<S1>/EnabledVehicles' */
  }

  /* End of Start for SubSystem: '<Root>/DoorSystemPerCar' */
}

/* Output and update for referenced model: 'DoorSystem' */
void DoorSystem(const BD_CommonTrain_Cfg_Vehicle rtu_CommonVehicleConfig[8],
                const BD_DoorSystem_In_Vehicle rtu_DoorSystemVehicleInputs[8],
                const BD_DoorSystem_In_Overrides rtu_Overrides[8], const
                BD_DoorSystem_In_Emergency_Door rtu_EmergencyDoorInputs[8],
                BD_DoorSystem_Out_Vehicle rty_DoorSystemVehicleOut[8],
                B_DoorSystem_c_T *localB, DW_DoorSystem_f_T *localDW, const
                BD_DoorSystem_Prm *rtp_PRM_DoorSystem)
{
  /* local block i/o variables */
  real_T rtb_Merge_f;
  real_T rtb_Merge_i[2];
  boolean_T rtb_OR;
  boolean_T rtb_FixPtRelationalOperator_b;
  boolean_T rtb_OR_o;
  boolean_T rtb_FixPtRelationalOperator_ot;
  boolean_T rtb_AND1;
  boolean_T rtb_FixPtRelationalOperator_l;
  boolean_T rtb_FixPtRelationalOperator_of;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_LogicalOperator7;
  boolean_T rtb_LogicalOperator1_c;
  boolean_T rtb_LogicalOperator4;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_o;
  int32_T ForEach_itr_dr;
  int32_T ForEach_itr_c;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_k;
  real_T rtb_ValveDirection1;
  boolean_T rtb_LogicalOperator39_p;
  real_T rtb_UnitDelay2;
  boolean_T rtb_LogicalOperator39_cj;
  real_T
    rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToLock;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToUnlock;
  real_T
    rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnexpectedUnlocking;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorDCUFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSRFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSLFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSRFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSLFailure;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMajorFault;
  real_T rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnauthorisedOpen;
  real_T
    rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_UnexpectedDoorOpeningDetectedByCC;
  boolean_T rtb_OR_e;
  real_T rtb_Switch2_p;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Compare_f;
  boolean_T rtb_ObstacleDetectActive;
  boolean_T rtb_LogicalOperator40_k0;
  boolean_T rtb_DoorsFaulty;
  real_T rtb_DataTypeConversion1;
  boolean_T rtb_IC;
  boolean_T rtb_LogicalOperator6_k;
  boolean_T rtb_LogicalOperator40_a;
  boolean_T rtb_Memory;
  boolean_T rtb_OR4_a;
  boolean_T rtb_EmerDoorLocked;
  boolean_T rtb_NoPower;
  boolean_T rtb_AND2;
  boolean_T rtb_RaiseFaultafterDoorOpensBeyond300mm;
  int8_T rtb_ImpAsg_InsertedFor_Interlock_at_inport_0[2];
  real_T rtb_w2;
  real_T rtb_w1;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator40_ga;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_RelationalOperator1;
  real_T rtb_ImpAsg_InsertedFor_IsLeft_at_inport_0[8];
  boolean_T rtb_ImpAsg_InsertedFor_DoorEnabled_at_inport_0[8];
  boolean_T rtb_ImpAsg_InsertedFor_DoorInterlock_at_inport_0[8];
  BD_DoorSystem_Out_Door rtb_ImpAsg_InsertedFor_DoorOut_at_inport_0[16];
  BD_DoorSystem_In_Door rtb_ImpAsg_InsertedFor_Out1_at_inport_0[8];
  boolean_T rtb_LogicalOperator40_i;
  boolean_T rtb_LogicalOperator40_h;
  boolean_T rtb_LogicalOperator40;
  uint16_T rtb_SumofElements3;
  uint8_T rtb_SumofElements1;
  uint32_T tmp;
  int8_T rtb_Product_e[8];
  boolean_T rtb_ImpAsg_InsertedFor_VehicleRightDoorInterlock_at_inport_0[8];
  boolean_T rtb_ImpAsg_InsertedFor_VehicleLeftDoorInterlock_at_inport_0[8];
  boolean_T rtb_LogicalOperator1[8];
  BD_DoorSystem_In_Vehicle_TrainWires
    rtb_ImpAsg_InsertedFor_TrainWires_at_inport_0[8];
  int32_T i;
  boolean_T rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp;
  boolean_T rtb_AND3_o_tmp;

  /* UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localB->UnitDelay[i] = localDW->UnitDelay_DSTATE[i];
  }

  /* End of UnitDelay: '<Root>/Unit Delay' */

  /* Outputs for Iterator SubSystem: '<Root>/DoorSystemPerCar' incorporates:
   *  ForEach: '<S1>/For Each'
   */
  for (ForEach_itr_o = 0; ForEach_itr_o < 8; ForEach_itr_o++) {
    /* Outputs for Enabled SubSystem: '<S1>/EnabledVehicles' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    /* ForEachSliceSelector generated from: '<S1>/CommonConfig' */
    if (rtu_CommonVehicleConfig[ForEach_itr_o].Enabled) {
      if (!localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE) {
        localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE = true;
      }

      /* MATLAB Function: '<S97>/Orientation Swap' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/Overrides'
       */
      if (rtu_CommonVehicleConfig[ForEach_itr_o].Orientation > 1.5) {
        rtb_w1 = rtu_Overrides[ForEach_itr_o].AllDoorsRightOpen;
        rtb_w2 = rtu_Overrides[ForEach_itr_o].AllDoorsLeftOpen;
      } else {
        rtb_w1 = rtu_Overrides[ForEach_itr_o].AllDoorsLeftOpen;
        rtb_w2 = rtu_Overrides[ForEach_itr_o].AllDoorsRightOpen;
      }

      /* End of MATLAB Function: '<S97>/Orientation Swap' */

      /* Outputs for Iterator SubSystem: '<S5>/For Each Subsystem' incorporates:
       *  ForEach: '<S96>/For Each'
       */
      for (ForEach_itr_dr = 0; ForEach_itr_dr < 8; ForEach_itr_dr++) {
        /* Switch: '<S96>/Switch' incorporates:
         *  ForEachSliceSelector generated from: '<S1>/DoorSystemVehicleInputs'
         *  ForEachSliceSelector generated from: '<S96>/In1'
         */
        if (rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
            Config.isLeft >
            DoorSystem_P.CoreSubsys.CoreSubsys_pn.Switch_Threshold) {
          rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
            = rtb_w1;
        } else {
          rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
            = rtb_w2;
        }

        /* End of Switch: '<S96>/Switch' */

        /* Logic: '<S98>/Logical Operator' incorporates:
         *  ForEachSliceSelector generated from: '<S1>/DoorSystemVehicleInputs'
         *  ForEachSliceSelector generated from: '<S96>/In1'
         */
        rtb_OR4_a = (rtu_DoorSystemVehicleInputs[ForEach_itr_o]
                     .Doors[ForEach_itr_dr].ElectricalSignals.DoorEnable &&
                     (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
                      != 0.0));

        /* Outputs for Atomic SubSystem: '<S98>/LeadingEdgePulse' */
        /* RelationalOperator: '<S101>/FixPt Relational Operator' incorporates:
         *  UnitDelay: '<S101>/Delay Input1'
         */
        rtb_FixPtRelationalOperator_l = (static_cast<int32_T>(rtb_OR4_a) >
          static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o]
          .CoreSubsys_pn[ForEach_itr_dr].DelayInput1_DSTATE));

        /* Outputs for Atomic SubSystem: '<S99>/TimerOffDelay NoInit' */
        DoorSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator_l,
          &localB->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
          TimerOffDelayNoInit_n, &localDW->CoreSubsys[ForEach_itr_o].
          CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit_n,
          &DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n);

        /* End of Outputs for SubSystem: '<S99>/TimerOffDelay NoInit' */

        /* Update for UnitDelay: '<S101>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
          DelayInput1_DSTATE = rtb_OR4_a;

        /* End of Outputs for SubSystem: '<S98>/LeadingEdgePulse' */

        /* Outputs for Atomic SubSystem: '<S98>/TrailingEdgePulse' */
        /* RelationalOperator: '<S104>/FixPt Relational Operator' incorporates:
         *  UnitDelay: '<S104>/Delay Input1'
         */
        rtb_FixPtRelationalOperator_of = (static_cast<int32_T>
          (localB->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
           TimerOffDelayNoInit_n.LogicalOperator1) < static_cast<int32_T>
          (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
           DelayInput1_DSTATE_n));

        /* Outputs for Atomic SubSystem: '<S100>/TimerOffDelay NoInit' */
        DoorSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator_of,
          &localB->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
          TimerOffDelayNoInit, &localDW->CoreSubsys[ForEach_itr_o]
          .CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit,
          &DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit);

        /* End of Outputs for SubSystem: '<S100>/TimerOffDelay NoInit' */

        /* Update for UnitDelay: '<S104>/Delay Input1' */
        localDW->CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
          DelayInput1_DSTATE_n = localB->CoreSubsys[ForEach_itr_o]
          .CoreSubsys_pn[ForEach_itr_dr].TimerOffDelayNoInit_n.LogicalOperator1;

        /* End of Outputs for SubSystem: '<S98>/TrailingEdgePulse' */

        /* ForEachSliceAssignment generated from: '<S96>/Out1' incorporates:
         *  DataTypeConversion: '<S98>/Data Type Conversion'
         *  ForEachSliceSelector generated from: '<S1>/DoorSystemVehicleInputs'
         *  ForEachSliceSelector generated from: '<S96>/In1'
         *  Logic: '<S98>/Logical Operator1'
         */
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].Config =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          Config;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          InputControlStates.LocalDoorOpenPB =
          ((rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
            InputControlStates.LocalDoorOpenPB != 0.0) || localB->
           CoreSubsys[ForEach_itr_o].CoreSubsys_pn[ForEach_itr_dr].
           TimerOffDelayNoInit.LogicalOperator1);
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          InputControlStates.OpenCloseWidget =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          InputControlStates.OpenCloseWidget;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          InputControlStates.EmergencyAccessDevice =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          InputControlStates.EmergencyAccessDevice;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          InputControlStates.EmergencyEgressDevice =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          InputControlStates.EmergencyEgressDevice;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          InputControlStates.LocalDoorIsolationLock =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          InputControlStates.LocalDoorIsolationLock;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].
          ElectricalSignals = rtu_DoorSystemVehicleInputs[ForEach_itr_o]
          .Doors[ForEach_itr_dr].ElectricalSignals;
        rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_dr].Faults =
          rtu_DoorSystemVehicleInputs[ForEach_itr_o].Doors[ForEach_itr_dr].
          Faults;
      }

      /* End of Outputs for SubSystem: '<S5>/For Each Subsystem' */

      /* BusAssignment: '<S5>/Bus Assignment' */
      memcpy(&localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[0],
             &rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0], sizeof
             (BD_DoorSystem_In_Door) << 3U);

      /* Outputs for Iterator SubSystem: '<S4>/ForEachDoor' incorporates:
       *  ForEach: '<S7>/For Each'
       */
      for (ForEach_itr_e = 0; ForEach_itr_e < 8; ForEach_itr_e++) {
        /* ForEachSliceSelector generated from: '<S7>/In1' */
        rtb_OR4_a = localB->CoreSubsys[ForEach_itr_o]
          .BusAssignment.Doors[ForEach_itr_e].ElectricalSignals.DoorMotorPower;
        rtb_RelationalOperator1 = localB->CoreSubsys[ForEach_itr_o].
          BusAssignment.Doors[ForEach_itr_e].ElectricalSignals.DoorRelease;
        rtb_w1 = localB->CoreSubsys[ForEach_itr_o]
          .BusAssignment.Doors[ForEach_itr_e].
          Faults.ObjectObstructingDoorWhileClosing;
        rtb_w2 = localB->CoreSubsys[ForEach_itr_o]
          .BusAssignment.Doors[ForEach_itr_e].
          Faults.ObjectObstructingDoorWhileOpening;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
          = localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e]
          .Faults.DoorMotorCircuitFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToLock =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DoorFailedToLock;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToUnlock =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DoorFailedToUnlock;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnexpectedUnlocking
          = localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e]
          .Faults.DoorUnexpectedUnlocking;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorDCUFailure =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DoorDCUFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSRFailure =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DCSRFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSLFailure =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DCSLFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSRFailure =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DLSRFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSLFailure =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DLSLFailure;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMajorFault =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DoorMajorFault;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnauthorisedOpen =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
          Faults.DoorUnauthorisedOpen;
        rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_UnexpectedDoorOpeningDetectedByCC
          = localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e]
          .Faults.UnexpectedDoorOpeningDetectedByCC;

        /* RelationalOperator: '<S7>/Relational Operator' incorporates:
         *  Constant: '<S4>/Constant'
         *  ForEachSliceSelector generated from: '<S7>/DoorIndex'
         *  ForEachSliceSelector generated from: '<S7>/In1'
         */
        rtb_LogicalOperator40 =
          (DoorSystem_P.CoreSubsys.Constant_Value_o[ForEach_itr_e] <=
           localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
           Config.NumberOfDoors);

        /* Outputs for Enabled SubSystem: '<S7>/DoorLogic' incorporates:
         *  EnablePort: '<S9>/Enable'
         */
        if (rtb_LogicalOperator40) {
          if (!localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE) {
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE = true;
          }

          /* Outputs for Iterator SubSystem: '<S9>/DoorSystem' incorporates:
           *  ForEach: '<S10>/For Each'
           */
          for (ForEach_itr_k = 0; ForEach_itr_k < 2; ForEach_itr_k++) {
            /* RelationalOperator: '<S11>/Compare' incorporates:
             *  Constant: '<S11>/Constant'
             */
            rtb_Compare_n = (ForEach_itr_k ==
                             DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant2_const);

            /* RelationalOperator: '<S12>/Compare' incorporates:
             *  Constant: '<S12>/Constant'
             */
            rtb_Compare_f = (ForEach_itr_k ==
                             DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant3_const);

            /* Logic: '<S14>/AND' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S14>/Logical Operator8'
             *  Logic: '<S14>/OR'
             */
            rtb_Memory = (localB->CoreSubsys[ForEach_itr_o]
                          .BusAssignment.Doors[ForEach_itr_e].
                          ElectricalSignals.DoorControlPower &&
                          ((!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorDCUFailure
                              != 0.0)) &&
                           (!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMajorFault
                              != 0.0))));

            /* Logic: '<S28>/OR1' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             */
            rtb_EmerDoorLocked = ((localB->CoreSubsys[ForEach_itr_o].
              BusAssignment.Doors[ForEach_itr_e].
              InputControlStates.EmergencyAccessDevice != 0.0) ||
                                  (localB->CoreSubsys[ForEach_itr_o].
              BusAssignment.Doors[ForEach_itr_e].
              InputControlStates.EmergencyEgressDevice != 0.0));

            /* UnitDelay: '<S10>/Unit Delay2' */
            rtb_UnitDelay2 = localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE;

            /* Logic: '<S28>/OR' incorporates:
             *  Constant: '<S59>/Constant'
             *  RelationalOperator: '<S59>/Compare'
             *  UnitDelay: '<S10>/Unit Delay1'
             *  UnitDelay: '<S10>/Unit Delay2'
             */
            rtb_LogicalOperator40_ga = (localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay1_DSTATE_n || (localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE ==
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_b));

            /* Logic: '<S62>/Logical Operator40' incorporates:
             *  Logic: '<S62>/Logical Operator39'
             *  Logic: '<S62>/Logical Operator41'
             *  Memory: '<S62>/Memory'
             *  RelationalOperator: '<S60>/FixPt Relational Operator'
             *  RelationalOperator: '<S61>/FixPt Relational Operator'
             *  UnitDelay: '<S60>/Delay Input1'
             *  UnitDelay: '<S61>/Delay Input1'
             */
            rtb_LogicalOperator2 = (((static_cast<int32_T>(rtb_EmerDoorLocked) >
              static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              DelayInput1_DSTATE_lq)) || localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              Memory_PreviousInput) && (static_cast<int32_T>
              (rtb_LogicalOperator40_ga) <= static_cast<int32_T>
              (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
               CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_p)));

            /* Logic: '<S29>/Logical Operator10' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S29>/AND5'
             */
            rtb_RaiseFaultafterDoorOpensBeyond300mm = ((rtb_Memory &&
              localB->CoreSubsys[ForEach_itr_o]
              .BusAssignment.Doors[ForEach_itr_e].
              ElectricalSignals.DoorIsolation) || (localB->
              CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
              InputControlStates.LocalDoorIsolationLock != 0.0));

            /* Logic: '<S64>/Logical Operator40' incorporates:
             *  Constant: '<S63>/Constant'
             *  Logic: '<S29>/AND1'
             *  Logic: '<S29>/NOT'
             *  Logic: '<S64>/Logical Operator39'
             *  Memory: '<S64>/Memory'
             *  RelationalOperator: '<S63>/Compare'
             *  UnitDelay: '<S10>/Unit Delay2'
             */
            rtb_LogicalOperator40_h = ((((localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE ==
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_l) &&
              rtb_RaiseFaultafterDoorOpensBeyond300mm) || localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_o) &&
              rtb_RaiseFaultafterDoorOpensBeyond300mm);

            /* Logic: '<S28>/NOT' incorporates:
             *  Logic: '<S32>/Logical Operator12'
             */
            rtb_LogicalOperator40_i = !rtb_LogicalOperator40_h;

            /* Logic: '<S28>/AND1' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S28>/AND4'
             *  Logic: '<S28>/Logical Operator9'
             *  Logic: '<S28>/NOT'
             */
            rtb_LogicalOperator3 = (((rtb_Memory && localB->
              CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_e].
              ElectricalSignals.DoorEmergencyRelease) || rtb_LogicalOperator2) &&
              rtb_LogicalOperator40_i);

            /* Logic: '<S13>/Logical Operator1' incorporates:
             *  UnitDelay: '<S13>/Unit Delay'
             */
            rtb_IC = !localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay_DSTATE;

            /* InitialCondition: '<S18>/IC' */
            if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].IC_FirstOutputTime) {
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].IC_FirstOutputTime = false;
              rtb_IC = DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IC_Value;
            }

            /* End of InitialCondition: '<S18>/IC' */

            /* Logic: '<S32>/Logical Operator11' incorporates:
             *  Logic: '<S32>/Logical Operator12'
             */
            rtb_RaiseFaultafterDoorOpensBeyond300mm = (rtb_LogicalOperator40_i &&
              (!rtb_LogicalOperator3));

            /* Logic: '<S32>/AND6' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             */
            rtb_LogicalOperator40_i = (localB->CoreSubsys[ForEach_itr_o].
              BusAssignment.Doors[ForEach_itr_e].ElectricalSignals.DoorEnable &&
              rtb_RelationalOperator1 && rtb_RaiseFaultafterDoorOpensBeyond300mm);

            /* Logic: '<S32>/AND2' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S14>/OR1'
             *  Logic: '<S32>/Logical Operator1'
             */
            rtb_AND2 = (rtb_LogicalOperator40_i && rtb_Memory &&
                        (localB->CoreSubsys[ForEach_itr_o]
                         .BusAssignment.Doors[ForEach_itr_e].
                         ElectricalSignals.DoorOpen ||
                         (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_UnexpectedDoorOpeningDetectedByCC
                          != 0.0) || (localB->CoreSubsys[ForEach_itr_o].
              BusAssignment.Doors[ForEach_itr_e].
              InputControlStates.LocalDoorOpenPB != 0.0)));

            /* Logic: '<S32>/AND3' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S32>/Logical Operator6'
             *  RelationalOperator: '<S73>/FixPt Relational Operator'
             *  UnitDelay: '<S73>/Delay Input1'
             */
            rtb_RaiseFaultafterDoorOpensBeyond300mm =
              (rtb_RaiseFaultafterDoorOpensBeyond300mm && rtb_Memory && ((
                 static_cast<int32_T>(rtb_RelationalOperator1) <
                 static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
                  CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                  DelayInput1_DSTATE_jd)) || localB->CoreSubsys[ForEach_itr_o].
                BusAssignment.Doors[ForEach_itr_e].ElectricalSignals.DoorClose));

            /* Logic: '<S76>/Logical Operator40' incorporates:
             *  Logic: '<S32>/Logical Operator'
             *  Logic: '<S32>/Logical Operator4'
             *  Logic: '<S76>/Logical Operator39'
             *  Logic: '<S76>/Logical Operator41'
             *  Memory: '<S76>/Memory'
             *  UnitDelay: '<S10>/Unit Delay'
             */
            rtb_LogicalOperator40_a = ((rtb_AND2 || localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_p) && (rtb_Memory &&
              (!localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
               CoreSubsys[ForEach_itr_k].UnitDelay_DSTATE_h) &&
              (!rtb_RaiseFaultafterDoorOpensBeyond300mm)));

            /* Logic: '<S31>/Logical Operator5' */
            rtb_LogicalOperator5 = (rtb_OR4_a && rtb_LogicalOperator40_a);

            /* Outputs for Atomic SubSystem: '<S31>/DoorOpenDelay' */
            DoorSystem_DoorOpenDelay(rtb_LogicalOperator5, &localB->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].DoorOpenDelay, &localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].DoorOpenDelay,
              &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay,
              rtp_PRM_DoorSystem->DoorOpenDelay);

            /* End of Outputs for SubSystem: '<S31>/DoorOpenDelay' */

            /* Logic: '<S86>/Logical Operator39' incorporates:
             *  Constant: '<S80>/Constant'
             *  Logic: '<S78>/LO1'
             *  Logic: '<S78>/LO23'
             *  Logic: '<S78>/Logical Operator'
             *  Logic: '<S86>/Logical Operator40'
             *  Logic: '<S86>/Logical Operator41'
             *  Memory: '<S86>/Memory'
             *  RelationalOperator: '<S80>/Compare'
             *  RelationalOperator: '<S81>/FixPt Relational Operator'
             *  RelationalOperator: '<S83>/FixPt Relational Operator'
             *  UnitDelay: '<S10>/Unit Delay2'
             *  UnitDelay: '<S81>/Delay Input1'
             *  UnitDelay: '<S83>/Delay Input1'
             */
            rtb_LogicalOperator39_cj = (((localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE < localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              DelayInput1_DSTATE_l) && (localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE <=
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant4_const)
              && (rtb_w1 != 0.0)) || (localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              Memory_PreviousInput_bz && ((!(localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE > localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              DelayInput1_DSTATE_o)) && (rtb_w1 != 0.0))));

            /* Logic: '<S85>/Logical Operator39' incorporates:
             *  Constant: '<S79>/Constant'
             *  Logic: '<S78>/LO2'
             *  Logic: '<S78>/LO3'
             *  Logic: '<S78>/Logical Operator1'
             *  Logic: '<S85>/Logical Operator40'
             *  Logic: '<S85>/Logical Operator41'
             *  Memory: '<S85>/Memory'
             *  RelationalOperator: '<S79>/Compare'
             *  RelationalOperator: '<S82>/FixPt Relational Operator'
             *  RelationalOperator: '<S84>/FixPt Relational Operator'
             *  UnitDelay: '<S10>/Unit Delay2'
             *  UnitDelay: '<S82>/Delay Input1'
             *  UnitDelay: '<S84>/Delay Input1'
             */
            rtb_LogicalOperator39_p = (((localDW->CoreSubsys[ForEach_itr_o].
              CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              UnitDelay2_DSTATE > localDW->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              DelayInput1_DSTATE_g) && (rtb_w2 != 0.0) && (localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE >=
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant1_const))
              || (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                  CoreSubsys[ForEach_itr_k].Memory_PreviousInput_f &&
                  ((!(localDW->CoreSubsys[ForEach_itr_o]
                      .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                      UnitDelay2_DSTATE < localDW->CoreSubsys[ForEach_itr_o].
                      CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                      DelayInput1_DSTATE_e)) && (rtb_w2 != 0.0))));

            /* Chart: '<S33>/Chart' incorporates:
             *  UnitDelay: '<S10>/Unit Delay2'
             */
            if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].temporalCounter_i1 < MAX_uint32_T) {
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].temporalCounter_i1++;
            }

            if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].is_active_c1_DoorSystem == 0U) {
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].is_active_c1_DoorSystem = 1U;
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
                DoorSystem_IN_Inactive;
              rtb_ObstacleDetectActive = false;
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].ObstaclePosition = 0.0;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].ResetOtherCommands = false;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].MaxOpenAttempts = false;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].MaxCloseAttempts = false;
            } else {
              switch (localDW->CoreSubsys[ForEach_itr_o]
                      .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                      is_c1_DoorSystem) {
               case DoorSystem_IN_Active:
                rtb_ObstacleDetectActive = true;
                if ((localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                     .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE <=
                     localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                     .CoreSubsys[ForEach_itr_k].ObstaclePosition) &&
                    (!rtb_LogicalOperator39_cj)) {
                  switch (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          is_Active) {
                   case DoorSystem_IN_Closing:
                    localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                      CoreSubsys[ForEach_itr_k].CloseCMD = false;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].is_Active =
                      DoorSystem_IN_NO_ACTIVE_CHILD;
                    break;

                   case DoorSystem_IN_Opening:
                    localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                      CoreSubsys[ForEach_itr_k].OpenCMD = false;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].is_Active =
                      DoorSystem_IN_NO_ACTIVE_CHILD;
                    break;

                   default:
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].is_Active =
                      DoorSystem_IN_NO_ACTIVE_CHILD;
                    break;
                  }

                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
                    DoorSystem_IN_Inactive;
                  rtb_ObstacleDetectActive = false;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].ObstaclePosition = 0.0;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].ResetOtherCommands = false;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].MaxOpenAttempts = false;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].MaxCloseAttempts = false;
                } else {
                  switch (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          is_Active) {
                   case DoorSystem_IN_Closing:
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        UnitDelay2_DSTATE <= localDW->CoreSubsys[ForEach_itr_o].
                        CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        ObstaclePosition) {
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].CloseCMD = false;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active = DoorSystem_IN_Hold1;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        temporalCounter_i1 = 0U;
                      i = localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        CloseAttempt + 1;
                      if (i > 127) {
                        i = 127;
                      }

                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        CloseAttempt = static_cast<int8_T>(i);
                    }
                    break;

                   case DoorSystem_IN_Complete:
                    localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                      CoreSubsys[ForEach_itr_k].ResetOtherCommands = true;
                    break;

                   case DoorSystem_IN_Hold1:
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        CloseAttempt >=
                        DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_NumOfClosingAttempts)
                    {
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].MaxCloseAttempts = true;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active = DoorSystem_IN_Complete;
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].ResetOtherCommands = true;
                    } else {
                      if (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          temporalCounter_i1 >= static_cast<uint32_T>(ceil
                           (DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt
                            * 20.0))) {
                        localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          is_Active = DoorSystem_IN_Opening;
                        localB->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          OpenCMD = true;
                      }
                    }
                    break;

                   case DoorSystem_IN_Hold2:
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        temporalCounter_i1 >= static_cast<uint32_T>(ceil
                         (DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_PauseBeforeClosingAttempt
                          * 20.0))) {
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active = DoorSystem_IN_Closing;
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].CloseCMD = true;
                    }
                    break;

                   default:
                    /* case IN_Opening: */
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        UnitDelay2_DSTATE > localDW->CoreSubsys[ForEach_itr_o].
                        CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        ObstaclePosition +
                        DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_MoveAwayFromObstacle)
                    {
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].OpenCMD = false;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active = DoorSystem_IN_Hold2;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        temporalCounter_i1 = 0U;
                    }
                    break;
                  }
                }
                break;

               case DoorSystem_IN_Active1:
                rtb_ObstacleDetectActive = true;
                if ((localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                     .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE <=
                     localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                     .CoreSubsys[ForEach_itr_k].ObstaclePosition) &&
                    (!rtb_LogicalOperator39_p)) {
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].is_Active1 =
                    DoorSystem_IN_NO_ACTIVE_CHILD;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
                    DoorSystem_IN_Inactive;
                  rtb_ObstacleDetectActive = false;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].ObstaclePosition = 0.0;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].ResetOtherCommands = false;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].MaxOpenAttempts = false;
                  localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].MaxCloseAttempts = false;
                } else {
                  switch (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          is_Active1) {
                   case DoorSystem_IN_Complete_h:
                    localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                      CoreSubsys[ForEach_itr_k].ResetOtherCommands = true;
                    break;

                   case DoorSystem_IN_Hold1_n:
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        OpenAttempt ==
                        DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_NumOfOpeningAttempts)
                    {
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].MaxOpenAttempts = true;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active1 = DoorSystem_IN_Complete_h;
                      localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                        .CoreSubsys[ForEach_itr_k].ResetOtherCommands = true;
                    } else {
                      if (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          temporalCounter_i1 >= static_cast<uint32_T>(ceil
                           (DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt
                            * 20.0))) {
                        localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          is_Active1 = DoorSystem_IN_Hold2_m;
                      }
                    }
                    break;

                   default:
                    /* case IN_Hold2: */
                    if (localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        UnitDelay2_DSTATE == localDW->CoreSubsys[ForEach_itr_o].
                        CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        ObstaclePosition) {
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        is_Active1 = DoorSystem_IN_Hold1_n;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        temporalCounter_i1 = 0U;
                      localDW->CoreSubsys[ForEach_itr_o]
                        .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                        OpenAttempt++;
                    }
                    break;
                  }
                }
                break;

               default:
                /* case IN_Inactive: */
                rtb_ObstacleDetectActive = false;
                localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                  CoreSubsys[ForEach_itr_k].ResetOtherCommands = false;
                if (rtb_LogicalOperator39_cj) {
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
                    DoorSystem_IN_Active;
                  rtb_ObstacleDetectActive = true;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].CloseAttempt = 0;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].ObstaclePosition =
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                    .CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].is_Active = DoorSystem_IN_Hold1;
                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].temporalCounter_i1 = 0U;
                  i = localDW->CoreSubsys[ForEach_itr_o]
                    .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                    CloseAttempt + 1;
                  if (i > 127) {
                    i = 127;
                  }

                  localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                    CoreSubsys[ForEach_itr_k].CloseAttempt = static_cast<int8_T>
                    (i);
                } else {
                  if (rtb_LogicalOperator39_p) {
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].is_c1_DoorSystem =
                      DoorSystem_IN_Active1;
                    rtb_ObstacleDetectActive = true;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].OpenAttempt = 0.0;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].ObstaclePosition =
                      localDW->CoreSubsys[ForEach_itr_o]
                      .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                      UnitDelay2_DSTATE;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].is_Active1 =
                      DoorSystem_IN_Hold1_n;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].temporalCounter_i1 = 0U;
                    localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                      .CoreSubsys[ForEach_itr_k].OpenAttempt++;
                  }
                }
                break;
              }
            }

            /* End of Chart: '<S33>/Chart' */

            /* Outputs for IfAction SubSystem: '<S27>/DCUOnIndicators1' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            /* If: '<S27>/If' incorporates:
             *  Logic: '<S45>/NOT'
             *  Logic: '<S50>/NOT'
             *  UnitDelay: '<S10>/Unit Delay1'
             */
            rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp = !localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n;

            /* End of Outputs for SubSystem: '<S27>/DCUOnIndicators1' */

            /* Logic: '<S75>/Logical Operator40' incorporates:
             *  Logic: '<S32>/Logical Operator4'
             *  Logic: '<S32>/Logical Operator5'
             *  Logic: '<S75>/Logical Operator39'
             *  Logic: '<S75>/Logical Operator41'
             *  Memory: '<S75>/Memory'
             *  RelationalOperator: '<S74>/FixPt Relational Operator'
             *  UnitDelay: '<S10>/Unit Delay1'
             *  UnitDelay: '<S74>/Delay Input1'
             */
            rtb_RaiseFaultafterDoorOpensBeyond300mm =
              ((rtb_RaiseFaultafterDoorOpensBeyond300mm || localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b) &&
               ((!rtb_AND2) && rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp &&
                rtb_Memory && (static_cast<int32_T>(localB->
                  CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                  .CoreSubsys[ForEach_itr_k].ResetOtherCommands) <=
                               static_cast<int32_T>(localDW->
                  CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                  .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_a))));

            /* Logic: '<S31>/Logical Operator7' */
            rtb_LogicalOperator7 = (rtb_OR4_a &&
              rtb_RaiseFaultafterDoorOpensBeyond300mm);

            /* Outputs for Atomic SubSystem: '<S31>/DoorCloseDelay' */
            DoorSystem_DoorOpenDelay(rtb_LogicalOperator7, &localB->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].DoorCloseDelay, &localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].DoorCloseDelay,
              &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay,
              rtp_PRM_DoorSystem->DoorCloseDelay);

            /* End of Outputs for SubSystem: '<S31>/DoorCloseDelay' */

            /* If: '<S31>/If' incorporates:
             *  Logic: '<S31>/Logical Operator2'
             *  Logic: '<S31>/Logical Operator3'
             */
            if (rtb_ObstacleDetectActive) {
              /* Outputs for IfAction SubSystem: '<S31>/Obstruction' incorporates:
               *  ActionPort: '<S70>/Action Port'
               */
              /* Switch: '<S70>/Switch1' incorporates:
               *  Gain: '<S70>/Gain1'
               */
              if (localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                  CoreSubsys[ForEach_itr_k].OpenCMD) {
                rtb_Merge_f = localB->CoreSubsys[ForEach_itr_o]
                  .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].OpenCMD;
              } else {
                rtb_Merge_f = static_cast<real_T>((localB->
                  CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                  .CoreSubsys[ForEach_itr_k].CloseCMD ? static_cast<int32_T>
                  (DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Gain1_Gain) : 0))
                  * 0.0078125;
              }

              /* End of Switch: '<S70>/Switch1' */
              /* End of Outputs for SubSystem: '<S31>/Obstruction' */
            } else if (localB->CoreSubsys[ForEach_itr_o]
                       .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                       DoorCloseDelay.Compare) {
              /* Outputs for IfAction SubSystem: '<S31>/DoorClose' incorporates:
               *  ActionPort: '<S65>/Action Port'
               */
              DoorSystem_DoorClose(&rtb_Merge_f,
                                   &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorClose);

              /* End of Outputs for SubSystem: '<S31>/DoorClose' */
            } else if (localB->CoreSubsys[ForEach_itr_o]
                       .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                       DoorOpenDelay.Compare) {
              /* Outputs for IfAction SubSystem: '<S31>/DoorOpen' incorporates:
               *  ActionPort: '<S67>/Action Port'
               */
              DoorSystem_DoorClose(&rtb_Merge_f,
                                   &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpen);

              /* End of Outputs for SubSystem: '<S31>/DoorOpen' */
            } else {
              /* Outputs for IfAction SubSystem: '<S31>/NoMotorCommand' incorporates:
               *  ActionPort: '<S69>/Action Port'
               */
              DoorSystem_DoorClose(&rtb_Merge_f,
                                   &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.NoMotorCommand);

              /* End of Outputs for SubSystem: '<S31>/NoMotorCommand' */
            }

            /* End of If: '<S31>/If' */

            /* Logic: '<S10>/OR2' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             *  Logic: '<S10>/AND1'
             *  Logic: '<S10>/AND2'
             */
            rtb_NoPower =
              (((rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSLFailure !=
                 0.0) && rtb_Compare_n) || (rtb_Compare_f &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSRFailure !=
                 0.0)) || (localB->CoreSubsys[ForEach_itr_o]
                           .BusAssignment.Doors[ForEach_itr_e].
                           Faults.DoorFailToClose != 0.0));

            /* Switch: '<S25>/ValveDirection1' */
            if (rtb_NoPower) {
              /* MinMax: '<S25>/Prevent  closing' incorporates:
               *  Constant: '<S25>/Constant'
               */
              if ((DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_j
                   > rtb_Merge_f) || rtIsNaN(rtb_Merge_f)) {
                rtb_ValveDirection1 =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_j;
              } else {
                rtb_ValveDirection1 = rtb_Merge_f;
              }

              /* End of MinMax: '<S25>/Prevent  closing' */
            } else {
              rtb_ValveDirection1 = rtb_Merge_f;
            }

            /* End of Switch: '<S25>/ValveDirection1' */

            /* Logic: '<S10>/OR' incorporates:
             *  ForEachSliceSelector generated from: '<S7>/In1'
             */
            rtb_OR_e = ((localB->CoreSubsys[ForEach_itr_o]
                         .BusAssignment.Doors[ForEach_itr_e].
                         Faults.DoorFailToOpen != 0.0) ||
                        (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToUnlock
                         != 0.0));

            /* Switch: '<S30>/Switch' incorporates:
             *  Logic: '<S14>/AND1'
             *  Logic: '<S14>/AND2'
             *  Logic: '<S14>/OR2'
             *  Logic: '<S30>/AND'
             *  Logic: '<S30>/AND1'
             *  Logic: '<S30>/Logical Operator8'
             *  Logic: '<S30>/OR'
             *  Logic: '<S30>/OR1'
             *  UnitDelay: '<S10>/Unit Delay1'
             */
            if (rtb_LogicalOperator40_h) {
              rtb_Compare_n = localDW->CoreSubsys[ForEach_itr_o]
                .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                UnitDelay1_DSTATE_n;
            } else {
              rtb_Compare_n = ((localDW->CoreSubsys[ForEach_itr_o]
                                .CoreSubsys[ForEach_itr_e]
                                .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n &&
                                (((!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSLFailure
                != 0.0)) || (!rtb_Compare_n)) && ((!rtb_Compare_f) ||
                (!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSRFailure
                   != 0.0))) && (!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToLock
                                   != 0.0)) &&
                                 (!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnexpectedUnlocking
                                    != 0.0)))) || (localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToUnlock
                 != 0.0)));
            }

            /* End of Switch: '<S30>/Switch' */

            /* Switch: '<S18>/SelReset' incorporates:
             *  Constant: '<S13>/Constant2'
             *  SampleTimeMath: '<S18>/Weighted Sample Time'
             *  Sum: '<S18>/Sum1'
             *  UnitDelay: '<S18>/Unit Delay1'
             *
             * About '<S18>/Weighted Sample Time':
             *  y = u * K where K = ( w * Ts )
             */
            if (rtb_IC) {
              rtb_ValveDirection1 =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant2_Value;
            } else {
              /* Logic: '<S13>/Logical Operator4' incorporates:
               *  Logic: '<S13>/Logical Operator3'
               */
              rtb_IC = (rtb_OR4_a &&
                        (!(rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
                           != 0.0)));

              /* Switch: '<S21>/MotorControl' incorporates:
               *  Constant: '<S21>/Constant7'
               */
              if (rtb_IC) {
                /* MinMax: '<S25>/Prevent  opening' incorporates:
                 *  Constant: '<S25>/Constant1'
                 *  Switch: '<S25>/ValveDirection2'
                 */
                if (rtb_OR_e &&
                    ((DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_b
                      < rtb_ValveDirection1) || rtIsNaN(rtb_ValveDirection1))) {
                  rtb_ValveDirection1 =
                    DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_b;
                }

                /* End of MinMax: '<S25>/Prevent  opening' */
              } else {
                rtb_ValveDirection1 =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant7_Value;
              }

              /* End of Switch: '<S21>/MotorControl' */

              /* Switch: '<S21>/Speed' incorporates:
               *  Constant: '<S21>/Constant5'
               *  Constant: '<S21>/Constant6'
               */
              if (rtb_ValveDirection1 >=
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Speed_Threshold_h)
              {
                rtb_Switch2_p = 1.0 / rtp_PRM_DoorSystem->DoorOpenTime;
              } else {
                rtb_Switch2_p = 1.0 / rtp_PRM_DoorSystem->DoorCloseTime;
              }

              /* End of Switch: '<S21>/Speed' */

              /* Product: '<S21>/Product' */
              rtb_ValveDirection1 *= rtb_Switch2_p;

              /* Switch: '<S13>/Switch' incorporates:
               *  Product: '<S20>/Product'
               */
              if (!(rtb_ValveDirection1 != 0.0)) {
                /* Switch: '<S20>/MotorControl' incorporates:
                 *  Constant: '<S20>/Constant7'
                 *  ForEachSliceSelector generated from: '<S7>/In1'
                 *  Logic: '<S13>/Logical Operator2'
                 *  Logic: '<S20>/Logical Operator1'
                 *  Logic: '<S20>/Logical Operator2'
                 *  Logic: '<S20>/Logical Operator4'
                 *  Logic: '<S20>/Logical Operator6'
                 */
                if (((!rtb_IC) || rtb_LogicalOperator3) && ((!rtb_Compare_n) &&
                     (!rtb_LogicalOperator40_h))) {
                  rtb_ValveDirection1 = localB->CoreSubsys[ForEach_itr_o].
                    BusAssignment.Doors[ForEach_itr_e].
                    InputControlStates.OpenCloseWidget;
                } else {
                  rtb_ValveDirection1 =
                    DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant7_Value_d;
                }

                /* End of Switch: '<S20>/MotorControl' */

                /* Switch: '<S20>/Speed' incorporates:
                 *  Constant: '<S20>/Constant5'
                 *  Constant: '<S20>/Constant6'
                 */
                if (rtb_ValveDirection1 >=
                    DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Speed_Threshold)
                {
                  rtb_Switch2_p = 1.0 / rtp_PRM_DoorSystem->DoorOpenTime;
                } else {
                  rtb_Switch2_p = 1.0 / rtp_PRM_DoorSystem->DoorCloseTime;
                }

                /* End of Switch: '<S20>/Speed' */
                rtb_ValveDirection1 *= rtb_Switch2_p;
              }

              /* End of Switch: '<S13>/Switch' */
              rtb_ValveDirection1 = rtb_ValveDirection1 *
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.WeightedSampleTime_WtEt
                + localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE;
            }

            /* End of Switch: '<S18>/SelReset' */

            /* Switch: '<S22>/Switch2' incorporates:
             *  Constant: '<S13>/Constant1'
             *  RelationalOperator: '<S16>/FixPt Relational Operator'
             *  RelationalOperator: '<S17>/FixPt Relational Operator'
             *  RelationalOperator: '<S22>/LowerRelop1'
             *  Switch: '<S13>/Switch1'
             *  Switch: '<S13>/Switch2'
             *  UnitDelay: '<S16>/Delay Input1'
             *  UnitDelay: '<S17>/Delay Input1'
             */
            if (rtb_ValveDirection1 >
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_h)
            {
              rtb_ValveDirection1 =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_h;
            } else {
              if (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnauthorisedOpen
                  > localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                  .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE) {
                /* Switch: '<S13>/Switch2' incorporates:
                 *  Constant: '<S13>/Constant5'
                 */
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant5_Value;
              } else if (static_cast<int32_T>(rtb_LogicalOperator3) >
                         static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          DelayInput1_DSTATE_j)) {
                /* Switch: '<S13>/Switch1' incorporates:
                 *  Constant: '<S13>/Constant3'
                 *  Switch: '<S13>/Switch2'
                 */
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant3_Value;
              } else {
                /* Switch: '<S13>/Switch2' incorporates:
                 *  Constant: '<S13>/Constant4'
                 */
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant4_Value;
              }

              /* Switch: '<S22>/Switch' incorporates:
               *  RelationalOperator: '<S17>/FixPt Relational Operator'
               *  RelationalOperator: '<S22>/UpperRelop'
               *  Switch: '<S13>/Switch1'
               *  Switch: '<S13>/Switch2'
               *  UnitDelay: '<S17>/Delay Input1'
               */
              if (rtb_ValveDirection1 < rtb_Switch2_p) {
                rtb_ValveDirection1 = rtb_Switch2_p;
              }

              /* End of Switch: '<S22>/Switch' */
            }

            /* End of Switch: '<S22>/Switch2' */

            /* Logic: '<S19>/AND' incorporates:
             *  Constant: '<S23>/Constant'
             *  Logic: '<S19>/NOT1'
             *  RelationalOperator: '<S23>/Compare'
             */
            rtb_IC = ((rtb_ValveDirection1 ==
                       DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant1_const_k)
                      && (!rtb_OR_e));

            /* Logic: '<S19>/AND1' incorporates:
             *  Constant: '<S24>/Constant'
             *  Logic: '<S19>/NOT'
             *  RelationalOperator: '<S24>/Compare'
             */
            rtb_Compare_f = ((rtb_ValveDirection1 ==
                              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant2_const_i)
                             && (!rtb_NoPower));

            /* Logic: '<S31>/Logical Operator1' */
            rtb_LogicalOperator1_c = rtb_LogicalOperator7;

            /* Logic: '<S31>/Logical Operator4' */
            rtb_LogicalOperator4 = rtb_LogicalOperator5;

            /* If: '<S26>/If' incorporates:
             *  DataTypeConversion: '<S26>/Data Type Conversion'
             *  If: '<S27>/If'
             */
            if (rtb_Memory) {
              /* Outputs for IfAction SubSystem: '<S26>/DCUOnAudio' incorporates:
               *  ActionPort: '<S35>/Action Port'
               */
              /* Outputs for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable' */
              DoorSystem_LeadingEdgePulseTunable(rtb_LogicalOperator4,
                &localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable,
                &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable,
                &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable,
                rtp_PRM_DoorSystem->DoorOpenAlarmTime);

              /* End of Outputs for SubSystem: '<S35>/LeadingEdgePulseTunable' */

              /* Outputs for Atomic SubSystem: '<S35>/LeadingEdgePulseTunable1' */
              DoorSystem_LeadingEdgePulseTunable(rtb_LogicalOperator1_c,
                &localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable1,
                &localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].LeadingEdgePulseTunable1,
                &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1,
                rtp_PRM_DoorSystem->DoorOpenAlarmTime);

              /* End of Outputs for SubSystem: '<S35>/LeadingEdgePulseTunable1' */

              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  BusCreator: '<S35>/Bus Creator'
               *  DataTypeConversion: '<S35>/Data Type Conversion1'
               *  DataTypeConversion: '<S35>/Data Type Conversion2'
               *  DataTypeConversion: '<S35>/Data Type Conversion3'
               *  DataTypeConversion: '<S35>/Data Type Conversion4'
               *  DataTypeConversion: '<S35>/Data Type Conversion5'
               */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorOpeningAuthorised = rtb_LogicalOperator40_i;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorOpeningAlarm = localB->CoreSubsys[ForEach_itr_o].
                CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                LeadingEdgePulseTunable.LogicalOperator1;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorClosingAlarm = localB->CoreSubsys[ForEach_itr_o].
                CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                LeadingEdgePulseTunable1.LogicalOperator1;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorEmergencyReleased = rtb_LogicalOperator3;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorIsolated = rtb_LogicalOperator40_h;

              /* End of Outputs for SubSystem: '<S26>/DCUOnAudio' */

              /* Outputs for IfAction SubSystem: '<S27>/DCUOnIndicators1' incorporates:
               *  ActionPort: '<S45>/Action Port'
               */
              /* Logic: '<S51>/Logical Operator40' incorporates:
               *  Logic: '<S51>/Logical Operator39'
               *  Logic: '<S51>/Logical Operator41'
               *  Memory: '<S51>/Memory'
               *  RelationalOperator: '<S47>/FixPt Relational Operator'
               *  UnitDelay: '<S10>/Unit Delay3'
               *  UnitDelay: '<S47>/Delay Input1'
               */
              rtb_Memory = (((static_cast<int32_T>(rtb_LogicalOperator1_c) <
                              static_cast<int32_T>(localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_m)) ||
                             localDW->CoreSubsys[ForEach_itr_o]
                             .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k]
                             .Memory_PreviousInput_j) && (!localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].UnitDelay3_DSTATE));

              /* RelationalOperator: '<S46>/Compare' incorporates:
               *  Constant: '<S46>/Constant'
               *  UnitDelay: '<S10>/Unit Delay3'
               */
              rtb_LogicalOperator6_k = (localDW->CoreSubsys[ForEach_itr_o].
                CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                UnitDelay3_DSTATE ==
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_e);

              /* Logic: '<S45>/AND1' incorporates:
               *  UnitDelay: '<S10>/Unit Delay1'
               */
              rtb_AND2 = (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          UnitDelay1_DSTATE_n && rtb_Memory &&
                          (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToLock
                           != 0.0) && rtb_LogicalOperator6_k);

              /* Logic: '<S52>/Logical Operator40' incorporates:
               *  Logic: '<S52>/Logical Operator39'
               *  Logic: '<S52>/Logical Operator41'
               *  Memory: '<S52>/Memory'
               *  RelationalOperator: '<S48>/FixPt Relational Operator'
               *  UnitDelay: '<S48>/Delay Input1'
               */
              rtb_NoPower = (((static_cast<int32_T>(rtb_LogicalOperator4) >
                               static_cast<int32_T>(localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_md)) ||
                              localDW->CoreSubsys[ForEach_itr_o]
                              .CoreSubsys[ForEach_itr_e]
                              .CoreSubsys[ForEach_itr_k].Memory_PreviousInput_l)
                             && (!rtb_LogicalOperator6_k));

              /* Logic: '<S45>/AND2' incorporates:
               *  UnitDelay: '<S10>/Unit Delay1'
               *  UnitDelay: '<S10>/Unit Delay3'
               */
              rtb_OR_e = (localDW->CoreSubsys[ForEach_itr_o]
                          .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                          UnitDelay1_DSTATE_n &&
                          (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorFailedToUnlock
                           != 0.0) && rtb_NoPower && localDW->
                          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                          CoreSubsys[ForEach_itr_k].UnitDelay3_DSTATE);

              /* Logic: '<S53>/Logical Operator40' incorporates:
               *  Logic: '<S45>/OR4'
               *  Logic: '<S53>/Logical Operator39'
               *  Logic: '<S53>/Logical Operator41'
               *  Memory: '<S53>/Memory'
               *  RelationalOperator: '<S49>/FixPt Relational Operator'
               *  UnitDelay: '<S49>/Delay Input1'
               */
              rtb_LogicalOperator40_k0 = (((static_cast<int32_T>
                (rtb_LogicalOperator1_c) > static_cast<int32_T>
                (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                 CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_n)) ||
                localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b2) &&
                (rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp &&
                 (!rtb_LogicalOperator40_h)));

              /* Logic: '<S45>/AND9' incorporates:
               *  Logic: '<S45>/NOT1'
               */
              rtb_DoorsFaulty =
                ((rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMotorCircuitFailure
                  != 0.0) && (!rtb_LogicalOperator40_h));

              /* Switch: '<S45>/Switch' incorporates:
               *  Constant: '<S45>/RedON'
               *  Logic: '<S45>/OR'
               *  Logic: '<S45>/OR1'
               *  Logic: '<S45>/OR2'
               *  Switch: '<S45>/Switch1'
               *  Switch: '<S45>/Switch2'
               *  UnitDelay: '<S10>/Unit Delay'
               */
              if (rtb_LogicalOperator3 || rtb_LogicalOperator40_h) {
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.RedON_Value;
              } else if (rtb_LogicalOperator4 || rtb_LogicalOperator1_c) {
                /* Switch: '<S45>/Switch1' incorporates:
                 *  Constant: '<S45>/YellowFlashing'
                 */
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.YellowFlashing_Value;
              } else if (localDW->CoreSubsys[ForEach_itr_o]
                         .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                         UnitDelay_DSTATE_h || localB->CoreSubsys[ForEach_itr_o]
                         .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                         MaxOpenAttempts || localB->CoreSubsys[ForEach_itr_o].
                         CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                         MaxCloseAttempts) {
                /* Switch: '<S45>/Switch2' incorporates:
                 *  Constant: '<S45>/YellowON'
                 *  Switch: '<S45>/Switch1'
                 */
                rtb_Switch2_p =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.YellowON_Value;
              } else {
                /* Switch: '<S45>/Switch1' incorporates:
                 *  Switch: '<S45>/Switch2'
                 */
                rtb_Switch2_p = rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp;
              }

              /* End of Switch: '<S45>/Switch' */

              /* Logic: '<S50>/NOT2' incorporates:
               *  Logic: '<S50>/NOT1'
               */
              rtb_AND3_o_tmp = !rtb_LogicalOperator40_i;

              /* If: '<S50>/If' incorporates:
               *  Logic: '<S50>/AND'
               *  Logic: '<S50>/AND1'
               *  Logic: '<S50>/AND2'
               *  Logic: '<S50>/AND3'
               *  Logic: '<S50>/NOT2'
               *  UnitDelay: '<S10>/Unit Delay1'
               */
              if (rtb_LogicalOperator40_i && localDW->CoreSubsys[ForEach_itr_o].
                  CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                  UnitDelay1_DSTATE_n) {
                /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem' incorporates:
                 *  ActionPort: '<S54>/Action Port'
                 */
                /* SignalConversion generated from: '<S54>/Out1' incorporates:
                 *  Constant: '<S54>/Constant'
                 *  Constant: '<S54>/Constant1'
                 */
                rtb_Merge_i[0] =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value;
                rtb_Merge_i[1] =
                  DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_g;

                /* End of Outputs for SubSystem: '<S50>/If Action Subsystem' */
              } else if (rtb_LogicalOperator40_i &&
                         rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp) {
                /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
                 *  ActionPort: '<S55>/Action Port'
                 */
                DoorSystem_IfActionSubsystem1(rtb_Merge_i,
                  &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem1);

                /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
              } else if (rtb_AND3_o_tmp && localDW->CoreSubsys[ForEach_itr_o].
                         CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
                         UnitDelay1_DSTATE_n) {
                /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem2' incorporates:
                 *  ActionPort: '<S56>/Action Port'
                 */
                DoorSystem_IfActionSubsystem1(rtb_Merge_i,
                  &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem2);

                /* End of Outputs for SubSystem: '<S50>/If Action Subsystem2' */
              } else if (rtb_AND3_o_tmp &&
                         rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp) {
                /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem3' incorporates:
                 *  ActionPort: '<S57>/Action Port'
                 */
                DoorSystem_IfActionSubsystem1(rtb_Merge_i,
                  &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem3);

                /* End of Outputs for SubSystem: '<S50>/If Action Subsystem3' */
              } else {
                /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem4' incorporates:
                 *  ActionPort: '<S58>/Action Port'
                 */
                DoorSystem_IfActionSubsystem1(rtb_Merge_i,
                  &DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem4);

                /* End of Outputs for SubSystem: '<S50>/If Action Subsystem4' */
              }

              /* End of If: '<S50>/If' */

              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  BusCreator: '<S45>/Bus Creator'
               */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                OutputControlStates.DoorOutsideLamp = rtb_Switch2_p;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                OutputControlStates.DoorInsideLamp = rtb_Switch2_p;

              /* BusCreator: '<S45>/Bus Creator' */
              rtb_Switch2_p = rtb_Merge_i[0];
              rtb_DataTypeConversion1 = rtb_Merge_i[1];

              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  BusAssignment: '<S45>/Bus Assignment'
               *  BusCreator: '<S45>/Bus Creator'
               *  Constant: '<S45>/Messages'
               *  Logic: '<S45>/AND3'
               *  Logic: '<S45>/AND4'
               *  Logic: '<S45>/AND5'
               *  Logic: '<S45>/AND6'
               *  Logic: '<S45>/AND7'
               *  Logic: '<S45>/AND8'
               *  Logic: '<S45>/OR3'
               *  SignalConversion generated from: '<S45>/Vector Concatenate'
               *  UnitDelay: '<S10>/Unit Delay1'
               * */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.DoorFaultStatus = (rtb_OR_e || rtb_DoorsFaulty || rtb_AND2);
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorOpenObstacleDetected = localB->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].MaxOpenAttempts;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorCloseObstacleDetected = localB->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].MaxCloseAttempts;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorFailedToLock = rtb_AND2;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorFailedToUnlock = rtb_OR_e;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorMotorFailure = rtb_DoorsFaulty;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorMajorFault =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Messages_Value.DoorMajorFault;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCSRFailure = (rtb_LogicalOperator40_k0 &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSRFailure !=
                 0.0));
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCSLFailure = (rtb_LogicalOperator40_k0 &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DCSLFailure !=
                 0.0));
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DLSRFailure = (rtb_Memory &&
                rtb_LogicalOperator6_k &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSRFailure !=
                 0.0));
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DLSLFailure = (rtb_LogicalOperator6_k &&
                rtb_Memory &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DLSLFailure !=
                 0.0));
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCUFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Messages_Value.DCUFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorUnexpectedUnlocking = (localDW->
                CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
                .CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n &&
                (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnexpectedUnlocking
                 != 0.0) && rtb_LogicalOperator6_k);
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorIsolatedWire = false;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorEmergencyHandleWire = false;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.UnexpectedDoorOpeningDetectedByCC =
                ((rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_UnexpectedDoorOpeningDetectedByCC
                  != 0.0) && rtb_RaiseFaultafterDoorOpensBeyond300mm_tmp);

              /* Update for UnitDelay: '<S47>/Delay Input1' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_m =
                rtb_LogicalOperator1_c;

              /* Update for Memory: '<S51>/Memory' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].Memory_PreviousInput_j = rtb_Memory;

              /* Update for UnitDelay: '<S48>/Delay Input1' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_md =
                rtb_LogicalOperator4;

              /* Update for Memory: '<S52>/Memory' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].Memory_PreviousInput_l = rtb_NoPower;

              /* Update for UnitDelay: '<S49>/Delay Input1' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_n =
                rtb_LogicalOperator1_c;

              /* Update for Memory: '<S53>/Memory' */
              localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b2 =
                rtb_LogicalOperator40_k0;

              /* End of Outputs for SubSystem: '<S27>/DCUOnIndicators1' */
            } else {
              /* Outputs for IfAction SubSystem: '<S26>/DCUOffAudio' incorporates:
               *  ActionPort: '<S34>/Action Port'
               */
              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  Constant: '<S34>/Constant'
               *  SignalConversion generated from: '<S34>/NoDCUAudio'
               */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorOpeningAuthorised =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m.DoorOpeningAuthorised;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorOpeningAlarm =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m.DoorOpeningAlarm;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorClosingAlarm =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m.DoorClosingAlarm;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorEmergencyReleased =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m.DoorEmergencyReleased;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                Audio.DoorIsolated =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m.DoorIsolated;

              /* End of Outputs for SubSystem: '<S26>/DCUOffAudio' */

              /* Outputs for IfAction SubSystem: '<S27>/DCUOffIndicators' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* Logic: '<S44>/NOT' */
              rtb_LogicalOperator6_k = !rtb_LogicalOperator40_h;

              /* Logic: '<S44>/AND' incorporates:
               *  DataTypeConversion: '<S44>/Data Type Conversion8'
               */
              rtb_Memory = (rtb_LogicalOperator6_k &&
                            (rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorMajorFault
                             != 0.0));

              /* Logic: '<S44>/AND1' incorporates:
               *  DataTypeConversion: '<S44>/Data Type Conversion1'
               */
              rtb_LogicalOperator6_k =
                ((rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorDCUFailure
                  != 0.0) && rtb_LogicalOperator6_k);

              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  BusAssignment: '<S44>/Bus Assignment'
               *  Constant: '<S44>/Constant'
               */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                OutputControlStates.DoorOutsideLamp =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DoorOutsideLamp;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                OutputControlStates.DoorInsideLamp =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DoorInsideLamp;

              /* BusAssignment: '<S44>/Bus Assignment' incorporates:
               *  Constant: '<S44>/Constant'
               */
              rtb_Switch2_p =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DoorOpenPBLight;
              rtb_DataTypeConversion1 =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DoorClosePBLight;

              /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
               *  BusAssignment: '<S44>/Bus Assignment'
               *  Constant: '<S44>/Constant'
               *  Logic: '<S44>/Logical Operator'
               */
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorOpenObstacleDetected =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorOpenObstacleDetected;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorCloseObstacleDetected =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorCloseObstacleDetected;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorFailedToLock =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorFailedToLock;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorFailedToUnlock =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorFailedToUnlock;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorMotorFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorMotorFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCSRFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DCSRFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCSLFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DCSLFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DLSRFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DLSRFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DLSLFailure =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DLSLFailure;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorUnexpectedUnlocking =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorUnexpectedUnlocking;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorIsolatedWire =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorIsolatedWire;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorEmergencyHandleWire =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.DoorEmergencyHandleWire;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.UnexpectedDoorOpeningDetectedByCC =
                DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value.DCUTCMSMessages.UnexpectedDoorOpeningDetectedByCC;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.DoorFaultStatus = (rtb_Memory || rtb_LogicalOperator6_k);
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DoorMajorFault = rtb_Memory;
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
                TCMS.Messages.DCUFailure = rtb_LogicalOperator6_k;

              /* End of Outputs for SubSystem: '<S27>/DCUOffIndicators' */
            }

            /* End of If: '<S26>/If' */

            /* RelationalOperator: '<S93>/FixPt Relational Operator' incorporates:
             *  UnitDelay: '<S93>/Delay Input1'
             */
            rtb_Memory = (rtb_ValveDirection1 < localDW->
                          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
                          CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_c);

            /* RelationalOperator: '<S94>/FixPt Relational Operator' incorporates:
             *  UnitDelay: '<S94>/Delay Input1'
             */
            rtb_LogicalOperator6_k = (rtb_ValveDirection1 > localDW->
              CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e]
              .CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_ly);

            /* Update for UnitDelay: '<S16>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE =
              rtb_ImpSel_InsertedFor_In1_at_outport_0_o_Faults_DoorUnauthorisedOpen;

            /* Update for UnitDelay: '<S17>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_j =
              rtb_LogicalOperator3;

            /* Update for UnitDelay: '<S60>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_lq =
              rtb_EmerDoorLocked;

            /* Update for Memory: '<S62>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput =
              rtb_LogicalOperator2;

            /* Update for UnitDelay: '<S10>/Unit Delay1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE_n = rtb_Compare_f;

            /* Update for UnitDelay: '<S10>/Unit Delay2' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay2_DSTATE = rtb_ValveDirection1;

            /* Update for UnitDelay: '<S61>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_p =
              rtb_LogicalOperator40_ga;

            /* Update for Memory: '<S64>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput_o =
              rtb_LogicalOperator40_h;

            /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
             *  Constant: '<S13>/Constant'
             */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay_DSTATE =
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_i4;

            /* Update for Memory: '<S76>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput_p =
              rtb_LogicalOperator40_a;

            /* Update for UnitDelay: '<S10>/Unit Delay' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay_DSTATE_h = rtb_IC;

            /* Update for UnitDelay: '<S73>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_jd =
              rtb_RelationalOperator1;

            /* Update for Memory: '<S75>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput_b =
              rtb_RaiseFaultafterDoorOpensBeyond300mm;

            /* Update for UnitDelay: '<S81>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_l = rtb_UnitDelay2;

            /* Update for Memory: '<S86>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput_bz =
              rtb_LogicalOperator39_cj;

            /* Update for UnitDelay: '<S83>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_o = rtb_UnitDelay2;

            /* Update for UnitDelay: '<S84>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_g = rtb_UnitDelay2;

            /* Update for Memory: '<S85>/Memory' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].Memory_PreviousInput_f =
              rtb_LogicalOperator39_p;

            /* Update for UnitDelay: '<S82>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_e = rtb_UnitDelay2;

            /* Update for UnitDelay: '<S74>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_a =
              localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].ResetOtherCommands;

            /* Update for UnitDelay: '<S18>/Unit Delay1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay1_DSTATE = rtb_ValveDirection1;

            /* Update for UnitDelay: '<S10>/Unit Delay3' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].UnitDelay3_DSTATE = rtb_Compare_n;

            /* Update for UnitDelay: '<S93>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_c =
              rtb_ValveDirection1;

            /* Update for UnitDelay: '<S94>/Delay Input1' */
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              CoreSubsys[ForEach_itr_k].DelayInput1_DSTATE_ly =
              rtb_ValveDirection1;

            /* ForEachSliceAssignment generated from: '<S10>/Interlock' incorporates:
             *  DataTypeConversion: '<S15>/Data Type Conversion4'
             */
            rtb_ImpAsg_InsertedFor_Interlock_at_inport_0[ForEach_itr_k] =
              static_cast<int8_T>(rtb_Compare_n);

            /* ForEachSliceAssignment generated from: '<S10>/DoorOut' incorporates:
             *  BusAssignment: '<S88>/Bus Assignment'
             *  BusAssignment: '<S89>/Bus Assignment'
             *  BusAssignment: '<S90>/Bus Assignment'
             *  Constant: '<S91>/Constant'
             *  Constant: '<S92>/Constant'
             *  DataTypeConversion: '<S87>/Data Type Conversion7'
             *  DataTypeConversion: '<S87>/Data Type Conversion8'
             *  DataTypeConversion: '<S90>/Data Type Conversion'
             *  DataTypeConversion: '<S90>/Data Type Conversion1'
             *  Logic: '<S87>/AND1'
             *  Logic: '<S87>/AND2'
             *  RelationalOperator: '<S91>/Compare'
             *  RelationalOperator: '<S92>/Compare'
             */
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              ElectricalSignals.DoorCloseInterlock = rtb_Compare_n;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              ElectricalSignals.DoorClosed = rtb_Compare_f;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              OutputControlStates.DoorPosition = rtb_ValveDirection1;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              Audio.DoorClosing = ((rtb_Merge_f <
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_a) &&
              rtb_Memory);
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              Audio.DoorOpening = ((rtb_Merge_f >
              DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_i) &&
              rtb_LogicalOperator6_k);
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorClosedStatus = rtb_Compare_f;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorOpenStatus = rtb_IC;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorReleasedAuthorisedToOpenStatus = rtb_LogicalOperator40_i;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorEmergencyReleasedStatus = rtb_LogicalOperator3;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorIsolatedStatus = rtb_LogicalOperator40_h;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorObstacleDetected = rtb_ObstacleDetectActive;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorObstacleUnableToClose = localB->CoreSubsys[ForEach_itr_o]
              .CoreSubsys[ForEach_itr_e].CoreSubsys[ForEach_itr_k].
              ResetOtherCommands;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorLockedStatus = rtb_Compare_n;
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorOpenPBLight = (rtb_Switch2_p != 0.0);
            localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              ImpAsg_InsertedFor_DoorOut_at_inport_0[ForEach_itr_k].
              TCMS.DoorClosedPBLight = (rtb_DataTypeConversion1 != 0.0);
          }

          /* End of Outputs for SubSystem: '<S9>/DoorSystem' */

          /* Logic: '<S9>/AND' */
          localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].AND =
            ((rtb_ImpAsg_InsertedFor_Interlock_at_inport_0[0] != 0) &&
             (rtb_ImpAsg_InsertedFor_Interlock_at_inport_0[1] != 0));
        } else {
          if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE) {
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE = false;
          }
        }

        /* End of Outputs for SubSystem: '<S7>/DoorLogic' */

        /* ForEachSliceAssignment generated from: '<S7>/DoorOut' */
        i = ForEach_itr_e << 1;
        rtb_ImpAsg_InsertedFor_DoorOut_at_inport_0[i] = localB->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          ImpAsg_InsertedFor_DoorOut_at_inport_0[0];
        rtb_ImpAsg_InsertedFor_DoorOut_at_inport_0[i + 1] = localB->
          CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
          ImpAsg_InsertedFor_DoorOut_at_inport_0[1];

        /* ForEachSliceAssignment generated from: '<S7>/DoorInterlock' */
        rtb_ImpAsg_InsertedFor_DoorInterlock_at_inport_0[ForEach_itr_e] =
          localB->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].AND;

        /* ForEachSliceAssignment generated from: '<S7>/DoorEnabled' */
        rtb_ImpAsg_InsertedFor_DoorEnabled_at_inport_0[ForEach_itr_e] =
          rtb_LogicalOperator40;
      }

      /* End of Outputs for SubSystem: '<S4>/ForEachDoor' */

      /* Outputs for Iterator SubSystem: '<S8>/For Each Subsystem' incorporates:
       *  ForEach: '<S95>/For Each'
       */
      for (ForEach_itr_c = 0; ForEach_itr_c < 8; ForEach_itr_c++) {
        /* ForEachSliceAssignment generated from: '<S95>/IsLeft' incorporates:
         *  ForEachSliceSelector generated from: '<S95>/DoorConfig'
         */
        rtb_ImpAsg_InsertedFor_IsLeft_at_inport_0[ForEach_itr_c] =
          localB->CoreSubsys[ForEach_itr_o].BusAssignment.Doors[ForEach_itr_c].
          Config.isLeft;
      }

      /* End of Outputs for SubSystem: '<S8>/For Each Subsystem' */

      /* Sum: '<S8>/Sum of Elements' */
      tmp = 0U;
      for (i = 0; i < 8; i++) {
        /* Logic: '<S8>/Logical Operator3' */
        rtb_Memory = ((rtb_ImpAsg_InsertedFor_IsLeft_at_inport_0[i] != 0.0) &&
                      rtb_ImpAsg_InsertedFor_DoorEnabled_at_inport_0[i]);

        /* Sum: '<S8>/Sum of Elements' */
        tmp += rtb_Memory;

        /* Product: '<S8>/Product' */
        rtb_Product_e[i] = static_cast<int8_T>((rtb_Memory ? static_cast<int32_T>
          (rtb_ImpAsg_InsertedFor_DoorInterlock_at_inport_0[i]) : 0));
      }

      /* Sum: '<S8>/Sum of Elements' */
      rtb_SumofElements1 = static_cast<uint8_T>(tmp);

      /* Sum: '<S8>/Sum of Elements2' incorporates:
       *  Logic: '<S8>/Logical Operator2'
       *  Product: '<S8>/Product1'
       */
      tmp = 0U;
      for (i = 0; i < 8; i++) {
        tmp += rtb_Product_e[i];

        /* Logic: '<S8>/Logical Operator2' incorporates:
         *  Logic: '<S8>/Logical Operator'
         */
        rtb_Memory = (rtb_ImpAsg_InsertedFor_DoorEnabled_at_inport_0[i] &&
                      (!(rtb_ImpAsg_InsertedFor_IsLeft_at_inport_0[i] != 0.0)));
        rtb_Product_e[i] = static_cast<int8_T>
          ((rtb_ImpAsg_InsertedFor_DoorInterlock_at_inport_0[i] ?
            static_cast<int32_T>(rtb_Memory) : 0));
        rtb_LogicalOperator1[i] = rtb_Memory;
      }

      /* RelationalOperator: '<S8>/Relational Operator' incorporates:
       *  Sum: '<S8>/Sum of Elements2'
       */
      rtb_Memory = (rtb_SumofElements1 == static_cast<uint16_T>(tmp));

      /* Sum: '<S8>/Sum of Elements3' */
      tmp = 0U;
      for (i = 0; i < 8; i++) {
        tmp += rtb_Product_e[i];
      }

      rtb_SumofElements3 = static_cast<uint16_T>(tmp);

      /* End of Sum: '<S8>/Sum of Elements3' */

      /* Sum: '<S8>/Sum of Elements1' */
      tmp = 0U;
      for (i = 0; i < 8; i++) {
        tmp += rtb_LogicalOperator1[i];
      }

      /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
       *  Sum: '<S8>/Sum of Elements1'
       */
      rtb_OR4_a = (rtb_SumofElements3 == static_cast<uint8_T>(tmp));

      /* Logic: '<S116>/Logical Operator1' incorporates:
       *  UnitDelay: '<S116>/Unit Delay'
       */
      rtb_EmerDoorLocked = !localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE;

      /* InitialCondition: '<S127>/IC' */
      if (localDW->CoreSubsys[ForEach_itr_o].IC_FirstOutputTime) {
        localDW->CoreSubsys[ForEach_itr_o].IC_FirstOutputTime = false;
        rtb_EmerDoorLocked = DoorSystem_P.CoreSubsys.IC_Value;
      }

      /* End of InitialCondition: '<S127>/IC' */

      /* Logic: '<S108>/OR' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  Logic: '<S108>/Logical Operator'
       *  Logic: '<S108>/OR1'
       */
      rtb_OR = (((rtu_EmergencyDoorInputs[ForEach_itr_o].
                  EmergencyDoorMechanicalUnlocked != 0.0) ||
                 (!rtu_EmergencyDoorInputs[ForEach_itr_o].EmerDoorLatched)) &&
                rtu_EmergencyDoorInputs[ForEach_itr_o].EmergencyDoorHandle);

      /* Outputs for Atomic SubSystem: '<S108>/TimerOnDelay NoInit2' */
      DoorSystem_DoorOpenDelay(rtb_OR, &localB->CoreSubsys[ForEach_itr_o].
        TimerOnDelayNoInit2, &localDW->CoreSubsys[ForEach_itr_o].
        TimerOnDelayNoInit2, &DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2,
        DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2_UpperSaturationLimit);

      /* End of Outputs for SubSystem: '<S108>/TimerOnDelay NoInit2' */

      /* RelationalOperator: '<S108>/Relational Operator1' incorporates:
       *  Constant: '<S108>/Constant1'
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       */
      rtb_RelationalOperator1 = (rtu_EmergencyDoorInputs[ForEach_itr_o].
        DoorWinder == DoorSystem_P.CoreSubsys.Constant1_Value_nk);

      /* Logic: '<S117>/Logical Operator40' incorporates:
       *  Logic: '<S108>/AND'
       *  Logic: '<S117>/Logical Operator39'
       *  Logic: '<S117>/Logical Operator41'
       *  Memory: '<S117>/Memory'
       *  RelationalOperator: '<S110>/FixPt Relational Operator'
       *  UnitDelay: '<S108>/Unit Delay1'
       *  UnitDelay: '<S110>/Delay Input1'
       */
      rtb_LogicalOperator40 = (((static_cast<int32_T>(localB->
        CoreSubsys[ForEach_itr_o].TimerOnDelayNoInit2.Compare) >
        static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_n)) || localDW->CoreSubsys[ForEach_itr_o].
        Memory_PreviousInput) && ((!rtb_RelationalOperator1) ||
        localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE_e));

      /* RelationalOperator: '<S124>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion4'
       *  UnitDelay: '<S124>/Delay Input1'
       */
      rtb_FixPtRelationalOperator_b = (static_cast<real_T>(rtb_LogicalOperator40)
        > localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE);

      /* Outputs for Atomic SubSystem: '<S116>/TimerOffDelay NoInit' */
      DoorSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator_b,
        &localB->CoreSubsys[ForEach_itr_o].TimerOffDelayNoInit,
        &localDW->CoreSubsys[ForEach_itr_o].TimerOffDelayNoInit,
        &DoorSystem_P.CoreSubsys.TimerOffDelayNoInit);

      /* End of Outputs for SubSystem: '<S116>/TimerOffDelay NoInit' */

      /* Logic: '<S116>/OR' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion4'
       *  RelationalOperator: '<S123>/FixPt Relational Operator'
       *  RelationalOperator: '<S126>/FixPt Relational Operator'
       *  UnitDelay: '<S123>/Delay Input1'
       *  UnitDelay: '<S126>/Delay Input1'
       */
      rtb_OR_o = ((static_cast<real_T>(rtb_LogicalOperator40) <
                   localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_j) || (
        static_cast<int32_T>(rtb_RelationalOperator1) > static_cast<int32_T>
        (localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h3)));

      /* Outputs for Atomic SubSystem: '<S116>/TimerOffDelay NoInit1' */
      DoorSystem_TimerOffDelayNoInit(rtb_OR_o, &localB->CoreSubsys[ForEach_itr_o]
        .TimerOffDelayNoInit1, &localDW->CoreSubsys[ForEach_itr_o].
        TimerOffDelayNoInit1, &DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1);

      /* End of Outputs for SubSystem: '<S116>/TimerOffDelay NoInit1' */

      /* RelationalOperator: '<S125>/FixPt Relational Operator' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  UnitDelay: '<S125>/Delay Input1'
       */
      rtb_FixPtRelationalOperator_ot = (rtu_EmergencyDoorInputs[ForEach_itr_o].
        RampCoverLockingLever > localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_h);

      /* Outputs for Atomic SubSystem: '<S116>/TimerOffDelay NoInit2' */
      DoorSystem_TimerOffDelayNoInit(rtb_FixPtRelationalOperator_ot,
        &localB->CoreSubsys[ForEach_itr_o].TimerOffDelayNoInit2,
        &localDW->CoreSubsys[ForEach_itr_o].TimerOffDelayNoInit2,
        &DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2);

      /* End of Outputs for SubSystem: '<S116>/TimerOffDelay NoInit2' */

      /* Switch: '<S127>/SelReset' incorporates:
       *  Constant: '<S116>/Constant2'
       *  SampleTimeMath: '<S127>/Weighted Sample Time'
       *  Sum: '<S127>/Sum1'
       *  Switch: '<S116>/Switch'
       *  Switch: '<S116>/Switch1'
       *  Switch: '<S116>/Switch2'
       *  UnitDelay: '<S127>/Unit Delay1'
       *
       * About '<S127>/Weighted Sample Time':
       *  y = u * K where K = ( w * Ts )
       */
      if (rtb_EmerDoorLocked) {
        rtb_w1 = DoorSystem_P.CoreSubsys.Constant2_Value;
      } else {
        if (localB->CoreSubsys[ForEach_itr_o].
            TimerOffDelayNoInit.LogicalOperator1) {
          /* Switch: '<S116>/Switch' incorporates:
           *  Constant: '<S116>/Constant5'
           */
          rtb_w1 = DoorSystem_P.CoreSubsys.Constant5_Value;
        } else if (localB->CoreSubsys[ForEach_itr_o].
                   TimerOffDelayNoInit1.LogicalOperator1) {
          /* Switch: '<S116>/Switch1' incorporates:
           *  Constant: '<S116>/Constant6'
           *  Switch: '<S116>/Switch'
           */
          rtb_w1 = DoorSystem_P.CoreSubsys.Constant6_Value;
        } else if (rtb_FixPtRelationalOperator_ot) {
          /* Switch: '<S116>/Switch2' incorporates:
           *  Switch: '<S116>/Switch'
           *  Switch: '<S116>/Switch1'
           */
          rtb_w1 = localB->CoreSubsys[ForEach_itr_o].
            TimerOffDelayNoInit2.LogicalOperator1;
        } else {
          /* Switch: '<S116>/Switch' incorporates:
           *  Constant: '<S116>/Constant7'
           */
          rtb_w1 = DoorSystem_P.CoreSubsys.Constant7_Value;
        }

        rtb_w1 = rtb_w1 * DoorSystem_P.CoreSubsys.WeightedSampleTime_WtEt +
          localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE;
      }

      /* End of Switch: '<S127>/SelReset' */

      /* Switch: '<S131>/Switch2' incorporates:
       *  Constant: '<S116>/Constant1'
       *  Constant: '<S116>/Constant4'
       *  RelationalOperator: '<S131>/LowerRelop1'
       *  RelationalOperator: '<S131>/UpperRelop'
       *  Switch: '<S131>/Switch'
       */
      if (rtb_w1 > DoorSystem_P.CoreSubsys.Constant1_Value_n) {
        rtb_w1 = DoorSystem_P.CoreSubsys.Constant1_Value_n;
      } else {
        if (rtb_w1 < DoorSystem_P.CoreSubsys.Constant4_Value) {
          /* Switch: '<S131>/Switch' incorporates:
           *  Constant: '<S116>/Constant4'
           */
          rtb_w1 = DoorSystem_P.CoreSubsys.Constant4_Value;
        }
      }

      /* End of Switch: '<S131>/Switch2' */

      /* RelationalOperator: '<S109>/Compare' incorporates:
       *  Constant: '<S109>/Constant'
       */
      rtb_EmerDoorLocked = (rtb_w1 ==
                            DoorSystem_P.CoreSubsys.CompareToConstant_const);

      /* Logic: '<S108>/AND1' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  UnitDelay: '<S108>/Unit Delay'
       */
      rtb_AND1 = (localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE_e &&
                  rtu_EmergencyDoorInputs[ForEach_itr_o].RampHandle);

      /* Outputs for Atomic SubSystem: '<S108>/TimerOnDelay NoInit1' */
      DoorSystem_DoorOpenDelay(rtb_AND1, &localB->CoreSubsys[ForEach_itr_o].
        TimerOnDelayNoInit1, &localDW->CoreSubsys[ForEach_itr_o].
        TimerOnDelayNoInit1, &DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1,
        DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1_UpperSaturationLimit);

      /* End of Outputs for SubSystem: '<S108>/TimerOnDelay NoInit1' */

      /* Logic: '<S118>/Logical Operator40' incorporates:
       *  Constant: '<S108>/Constant'
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  Logic: '<S118>/Logical Operator39'
       *  Logic: '<S118>/Logical Operator41'
       *  Memory: '<S118>/Memory'
       *  RelationalOperator: '<S108>/Relational Operator'
       *  RelationalOperator: '<S111>/FixPt Relational Operator'
       *  UnitDelay: '<S111>/Delay Input1'
       */
      rtb_LogicalOperator40_ga = (((static_cast<int32_T>(localB->
        CoreSubsys[ForEach_itr_o].TimerOnDelayNoInit1.Compare) >
        static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_e)) || localDW->CoreSubsys[ForEach_itr_o].
        Memory_PreviousInput_k) && (!(rtu_EmergencyDoorInputs[ForEach_itr_o].
        RampWinder == DoorSystem_P.CoreSubsys.Constant_Value_g)));

      /* Logic: '<S108>/Logical Operator2' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       */
      rtb_LogicalOperator2 = !rtu_EmergencyDoorInputs[ForEach_itr_o].
        EmergencyDoorGasSpring;

      /* Logic: '<S119>/Logical Operator40' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  Logic: '<S108>/OR3'
       *  Logic: '<S119>/Logical Operator39'
       *  Logic: '<S119>/Logical Operator41'
       *  Memory: '<S119>/Memory'
       *  RelationalOperator: '<S112>/FixPt Relational Operator'
       *  RelationalOperator: '<S114>/FixPt Relational Operator'
       *  UnitDelay: '<S112>/Delay Input1'
       *  UnitDelay: '<S114>/Delay Input1'
       */
      rtb_LogicalOperator40_h = (((static_cast<int32_T>(rtb_EmerDoorLocked) >
        static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_ej)) || rtu_EmergencyDoorInputs[ForEach_itr_o].
        EmergencyDoorGasSpring || localDW->CoreSubsys[ForEach_itr_o].
        Memory_PreviousInput_h) && (static_cast<int32_T>(rtb_LogicalOperator2) <=
        static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_ni)));

      /* Logic: '<S108>/Logical Operator3' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       */
      rtb_LogicalOperator3 = !rtu_EmergencyDoorInputs[ForEach_itr_o].
        RampMiddleSupport;

      /* Logic: '<S120>/Logical Operator40' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  Logic: '<S108>/OR4'
       *  Logic: '<S120>/Logical Operator39'
       *  Logic: '<S120>/Logical Operator41'
       *  Memory: '<S120>/Memory'
       *  RelationalOperator: '<S113>/FixPt Relational Operator'
       *  RelationalOperator: '<S115>/FixPt Relational Operator'
       *  UnitDelay: '<S113>/Delay Input1'
       *  UnitDelay: '<S115>/Delay Input1'
       */
      rtb_LogicalOperator40_i = (((static_cast<int32_T>(rtb_LogicalOperator40_ga)
        > static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_a)) || rtu_EmergencyDoorInputs[ForEach_itr_o].
        RampMiddleSupport || localDW->CoreSubsys[ForEach_itr_o].
        Memory_PreviousInput_l) && (static_cast<int32_T>(rtb_LogicalOperator3) <=
        static_cast<int32_T>(localDW->CoreSubsys[ForEach_itr_o].
        DelayInput1_DSTATE_hl)));

      /* BusCreator: '<S6>/Bus Creator1' incorporates:
       *  BusAssignment: '<S6>/Bus Assignment'
       *  DataTypeConversion: '<S108>/Data Type Conversion2'
       *  DataTypeConversion: '<S108>/Data Type Conversion3'
       *  DataTypeConversion: '<S6>/Data Type Conversion4'
       *  DataTypeConversion: '<S6>/Data Type Conversion5'
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       *  ForEachSliceSelector generated from: '<S1>/TrainWireInputs'
       *  Logic: '<S108>/Logical Operator1'
       *  Logic: '<S108>/Logical Operator4'
       *  Logic: '<S108>/OR2'
       *  Logic: '<S8>/Logical Operator1'
       */
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.TrainDoorInterlockOk = localB->
        UnitDelay[ForEach_itr_o].TrainDoorInterlockOk;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.VehicleDoorInterlockOk = (rtb_Memory &&
        rtb_OR4_a);
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.TrainLeftDoorInterlockOk =
        localB->UnitDelay[ForEach_itr_o].TrainLeftDoorInterlockOk;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.TrainRightDoorInterlockOk =
        localB->UnitDelay[ForEach_itr_o].TrainRightDoorInterlockOk;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.VehicleLeftDoorInterlockOk = rtb_Memory;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.VehicleElectrical.VehicleRightDoorInterlockOk = rtb_OR4_a;
      memcpy(&localB->CoreSubsys[ForEach_itr_o].BusCreator1.Doors[0],
             &rtb_ImpAsg_InsertedFor_DoorOut_at_inport_0[0], sizeof
             (BD_DoorSystem_Out_Door) << 4U);
      localB->CoreSubsys[ForEach_itr_o].BusCreator1.EmergencyDoor.Ramp =
        rtb_LogicalOperator40_ga;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.EmergencyDoorOpen = rtb_EmerDoorLocked;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.EmergencyDoorLocked =
        ((!(rtu_EmergencyDoorInputs[ForEach_itr_o].
            EmergencyDoorMechanicalUnlocked != 0.0)) &&
         (!(rtu_EmergencyDoorInputs[ForEach_itr_o].RampCoverLockingLever != 0.0)));
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.GasSpringLocked = rtb_LogicalOperator40_h;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.RampSupportDown = rtb_LogicalOperator40_i;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.LockingLeverUnlockAuth =
        rtu_EmergencyDoorInputs[ForEach_itr_o].RampCoverLockingLever;
      localB->CoreSubsys[ForEach_itr_o].
        BusCreator1.EmergencyDoor.EmerDoorOpenFaultMessage =
        rtu_EmergencyDoorInputs[ForEach_itr_o].EmerDoorOpenFault;

      /* Update for UnitDelay: '<S116>/Unit Delay' incorporates:
       *  Constant: '<S116>/Constant'
       */
      localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE =
        DoorSystem_P.CoreSubsys.Constant_Value_c;

      /* Update for UnitDelay: '<S110>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_n =
        localB->CoreSubsys[ForEach_itr_o].TimerOnDelayNoInit2.Compare;

      /* Update for Memory: '<S117>/Memory' */
      localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput =
        rtb_LogicalOperator40;

      /* Update for UnitDelay: '<S108>/Unit Delay1' */
      localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE_e =
        rtb_LogicalOperator40_ga;

      /* Update for UnitDelay: '<S124>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion4'
       */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE =
        rtb_LogicalOperator40;

      /* Update for UnitDelay: '<S123>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion4'
       */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_j =
        rtb_LogicalOperator40;

      /* Update for UnitDelay: '<S126>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h3 =
        rtb_RelationalOperator1;

      /* Update for UnitDelay: '<S125>/Delay Input1' incorporates:
       *  ForEachSliceSelector generated from: '<S1>/EmergencyDoorInputs'
       */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_h =
        rtu_EmergencyDoorInputs[ForEach_itr_o].RampCoverLockingLever;

      /* Update for UnitDelay: '<S127>/Unit Delay1' */
      localDW->CoreSubsys[ForEach_itr_o].UnitDelay1_DSTATE = rtb_w1;

      /* Update for UnitDelay: '<S108>/Unit Delay' */
      localDW->CoreSubsys[ForEach_itr_o].UnitDelay_DSTATE_e = rtb_EmerDoorLocked;

      /* Update for UnitDelay: '<S111>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_e =
        localB->CoreSubsys[ForEach_itr_o].TimerOnDelayNoInit1.Compare;

      /* Update for Memory: '<S118>/Memory' */
      localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_k =
        rtb_LogicalOperator40_ga;

      /* Update for UnitDelay: '<S112>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_ej =
        rtb_EmerDoorLocked;

      /* Update for Memory: '<S119>/Memory' */
      localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_h =
        rtb_LogicalOperator40_h;

      /* Update for UnitDelay: '<S114>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_ni =
        rtb_LogicalOperator2;

      /* Update for UnitDelay: '<S113>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_a =
        rtb_LogicalOperator40_ga;

      /* Update for Memory: '<S120>/Memory' */
      localDW->CoreSubsys[ForEach_itr_o].Memory_PreviousInput_l =
        rtb_LogicalOperator40_i;

      /* Update for UnitDelay: '<S115>/Delay Input1' */
      localDW->CoreSubsys[ForEach_itr_o].DelayInput1_DSTATE_hl =
        rtb_LogicalOperator3;
    } else {
      if (localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE) {
        /* Disable for Iterator SubSystem: '<S4>/ForEachDoor' */
        for (ForEach_itr_e = 0; ForEach_itr_e < 8; ForEach_itr_e++) {
          /* Disable for Enabled SubSystem: '<S7>/DoorLogic' */
          if (localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE) {
            localDW->CoreSubsys[ForEach_itr_o].CoreSubsys[ForEach_itr_e].
              DoorLogic_MODE = false;
          }

          /* End of Disable for SubSystem: '<S7>/DoorLogic' */
        }

        /* End of Disable for SubSystem: '<S4>/ForEachDoor' */
        localDW->CoreSubsys[ForEach_itr_o].EnabledVehicles_MODE = false;
      }
    }

    /* End of ForEachSliceSelector generated from: '<S1>/CommonConfig' */
    /* End of Outputs for SubSystem: '<S1>/EnabledVehicles' */

    /* ForEachSliceAssignment generated from: '<S1>/DoorSystemVehicleOut' */
    rty_DoorSystemVehicleOut[ForEach_itr_o] = localB->CoreSubsys[ForEach_itr_o].
      BusCreator1;
  }

  /* End of Outputs for SubSystem: '<Root>/DoorSystemPerCar' */

  /* Outputs for Iterator SubSystem: '<S2>/CreateBusOfVectorsConfig' incorporates:
   *  ForEach: '<S137>/For Each'
   */
  for (ForEach_itr_d = 0; ForEach_itr_d < 8; ForEach_itr_d++) {
    /* ForEachSliceAssignment generated from: '<S137>/VehicleRightDoorInterlock' incorporates:
     *  ForEachSliceSelector generated from: '<S137>/DoorSystemVehicleOut'
     */
    rtb_ImpAsg_InsertedFor_VehicleRightDoorInterlock_at_inport_0[ForEach_itr_d] =
      rty_DoorSystemVehicleOut[ForEach_itr_d].
      VehicleElectrical.VehicleRightDoorInterlockOk;

    /* ForEachSliceAssignment generated from: '<S137>/VehicleLeftDoorInterlock' incorporates:
     *  ForEachSliceSelector generated from: '<S137>/DoorSystemVehicleOut'
     */
    rtb_ImpAsg_InsertedFor_VehicleLeftDoorInterlock_at_inport_0[ForEach_itr_d] =
      rty_DoorSystemVehicleOut[ForEach_itr_d].
      VehicleElectrical.VehicleLeftDoorInterlockOk;
  }

  /* End of Outputs for SubSystem: '<S2>/CreateBusOfVectorsConfig' */

  /* Logic: '<S139>/Logical Operator1' */
  for (i = 0; i < 8; i++) {
    rtb_LogicalOperator1[i] =
      (rtb_ImpAsg_InsertedFor_VehicleLeftDoorInterlock_at_inport_0[i] &&
       rtb_ImpAsg_InsertedFor_VehicleRightDoorInterlock_at_inport_0[i]);
  }

  /* End of Logic: '<S139>/Logical Operator1' */

  /* Outputs for Iterator SubSystem: '<S2>/MakeArrayOfBuses' incorporates:
   *  ForEach: '<S138>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 8; ForEach_itr++) {
    /* ForEachSliceAssignment generated from: '<S138>/TrainWires' incorporates:
     *  BusAssignment: '<S138>/Bus Assignment'
     *  ForEachSliceSelector generated from: '<S138>/TrainDoorInterlockOk'
     *  ForEachSliceSelector generated from: '<S138>/TrainLeftDoorInterlockOk'
     *  ForEachSliceSelector generated from: '<S138>/TrainRightDoorInterlockOk'
     */
    rtb_ImpAsg_InsertedFor_TrainWires_at_inport_0[ForEach_itr].
      TrainDoorInterlockOk = rtb_LogicalOperator1[ForEach_itr];
    rtb_ImpAsg_InsertedFor_TrainWires_at_inport_0[ForEach_itr].
      TrainLeftDoorInterlockOk =
      rtb_ImpAsg_InsertedFor_VehicleLeftDoorInterlock_at_inport_0[ForEach_itr];
    rtb_ImpAsg_InsertedFor_TrainWires_at_inport_0[ForEach_itr].
      TrainRightDoorInterlockOk =
      rtb_ImpAsg_InsertedFor_VehicleRightDoorInterlock_at_inport_0[ForEach_itr];
  }

  /* End of Outputs for SubSystem: '<S2>/MakeArrayOfBuses' */

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  for (i = 0; i < 8; i++) {
    localDW->UnitDelay_DSTATE[i] =
      rtb_ImpAsg_InsertedFor_TrainWires_at_inport_0[i];
  }

  /* End of Update for UnitDelay: '<Root>/Unit Delay' */
}

/* Model initialize function */
void DoorSystem_initialize(const char_T **rt_errorStatus, RT_MODEL_DoorSystem_T *
  const DoorSystem_M, B_DoorSystem_c_T *localB, DW_DoorSystem_f_T *localDW,
  rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath, int_T
  rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(DoorSystem_M, rt_errorStatus);

  /* block I/O */
  (void) memset((static_cast<void *>(localB)), 0,
                sizeof(B_DoorSystem_c_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(localDW), 0,
                sizeof(DW_DoorSystem_f_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  {
    DoorSystem_InitializeDataMapInfo(DoorSystem_M, localB);
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(DoorSystem_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(DoorSystem_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(DoorSystem_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}
