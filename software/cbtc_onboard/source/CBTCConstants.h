///
/// @file       CBTCConstants.h
///
///             Constants that are common to the different CBTC On Board System Modules.
///
/// @author     Adam Zielinski
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "project_comms_structure/ProjectObjectConstants.h"

#include "Protobuf/CBTCOnboard.pb.h"

#include <utility>
#include <vector>

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Speed Profile data  as (train path location, speed limit)
        using SpeedProfilePoint  = std::pair<double, double>;
        using SpeedProfilePoints = std::vector<SpeedProfilePoint>;

        /// Gradient Profile data  as (train path location, gradient)
        using GradientProfilePoint  = std::pair<double, double>;
        using GradientProfilePoints = std::vector<GradientProfilePoint>;

        const double MPS_TO_KPH                   = 3.6;
        const double ACCELELERATION_GRAVITY       = 9.81;
        const double DELTA                        = 0.1;
        const double UNDEFINED_DISTANCE           = 0.0;
        const double INVALID_DISTANCE             = -1.0;
        const double MAX_DISTANCE                 = std::numeric_limits<double>::max();
        const double INVALID_SPEED                = -1.0;
        const double MIN_ZERO_SPEED               = 0.1;
        const double INVALID_TIME                 = -1.0;
        const double UNDEFINED_TIME_STAMP         = -1.0;
        const double PULSE_SIGNAL_DURATION        = 0.25;
        const int    UNDEFINED_TEXT_ID            = 0; // Text Message ID's
        const double END_OF_PROFILE               = -1;
        const double MAX_ALLOWED_OVERSHOOT_IN_ATO = 0.5;
        const int    SERVICE_BRAKE                = 1;
        const int    EMERGENCY_BRAKE              = 2;

        /// Common definitions for data that are used by multiple modules
        namespace TypeValue
        {
            enum StartupTestStage
            {
                INIT_TEST_NOT_ACTIVE = 0,
                INIT_TEST_STARTED    = 1,
                INIT_TEST_SUCCESS    = 2
            };

            enum PulseSignalState
            {
                PULSE_INACTIVE = 0,
                PULSE_ACTIVE   = 1
            };

            enum class EmergencyBrakeTrigger
            {
                NO_EB_REQUIRED            = 0,
                EB_TRAIN_DELOCALISED      = 1,
                EB_OVERSPEED_INTERVENTION = 2,
                ROLLWAY                   = 3,
                MAX_REVERSE_EXCEEDED      = 4,
                EB_MODE_CHANGE_ON_RUN     = 5,
                EB_TRAIN_DOOR_UNLOCKED    = 6,
                EB_SIGNAL_OVERRUN         = 7,
                EB_COMMS_LOST             = 8,
                EB_TRAIN_HOLD             = 10,
                EB_FATAL_FAULT            = 11, // Triggerring condition currently not implemented
                EB_NO_IMMOBILISATION      = 12, // Triggerring condition currently not implemented
                EB_PSD_UNLOCKED           = 13, // Triggerring condition currently not implemented
                EB_REQUESTED_BY_ATS       = 14, // Triggerring condition currently not implemented
                EB_PEC_REQUEST            = 15,
            };

            enum class NVEBReleaseCondition
            {
                STANDSTILL        = 0,
                UNDER_SPEED_LIMIT = 1
            };

            enum class MonitoringMode
            {
                CSM = 0, // Ceiling Speed Monitoring
                PIM = 1, // Pre-indication Speed Monitoring
                TSM = 2  // Target Speed Monitoring
            };

            enum class SpeedStatus
            {
                NORMAL       = 1,
                OVER_SPEED   = 2,
                WARNING      = 3,
                INDICATION   = 4,
                INTERVENTION = 5
            };
        }

        // Types associated wth the train model interface
        namespace TrainTypeValues
        {
            //////////////////////////////////////////////////////////
            // Types associated with the SCC interface
            //////////////////////////////////////////////////////////
            enum AutoPowerOn
            {
                CLEARED       = 0,
                AUTO_POWER_ON = 1
            };

            enum SelectedDrivingMode
            {
                OFF = 0,
                ATP = 1,
                ROS = 2,
                RMR = 3,
                RMF = 4,
                ATB = 5,
                ATO = 6,
                UTO = 7,
            };

            enum CommsStatus
            {
                COMMS_OK   = 0,
                COMMS_LOST = 1
            };

            enum RearCabStatus
            {
                CAB_NOT_ACTIVE = 0,
                CAB_ACTIVE     = 1
            };

            enum LocalisationState
            {
                MEMORISED_LOCATION = 0,
                LOCALISED          = 1,
                DELOCALISED        = 2
            };

            enum ATOPositionError
            {
                ACCURATE_DOCKING = 0,
                UNDERSHOOT       = 1,
                OVERSHOOT        = 2
            };
        }

        /// TBD - Need to update for CBTC speed and distance monitoring module to calculate braking curves
        namespace FixedValues
        {
            /// Maximum possible rotating mass as a percentage of the total weight of the train (%)
            const double m_rotating_max = 15;

            /// Minimum possible rotating mass as a percentage of the total weight of the train (%)
            const double m_rotating_min = 2;
        }
    }
}