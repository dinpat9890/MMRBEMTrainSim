///
/// @file       SpeedAndDistanceMonitoringModule.h
///
///             Module that handles the functionality related to the Speed and Monitoring function of the CBTC OnBoard
///             System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

#include <list>
#include <map>
#include <vector>

namespace Project
{
    namespace CBTCOnBoard
    {
        // Points in the EBI/SBD curve where the decelleration rate being used changes
        // - first value is the distance to the point
        // - second value is the velocity at the point
        // - third value is the deceleration rate used by the EBI curve between the
        //   previous point and the point at the given distance
        using ChangePoint  = std::tuple<double, double, double>;
        using ChangePoints = std::vector<ChangePoint>;

        /// Defines the standard structures required of a Module
        struct SpeedAndDistanceMonitoringModuleIO
        {
            struct Initialisation
            {
                // CBTC Speed Limits
                double auto_region_speed_limit            = INVALID_SPEED;
                double rmf_speed_limit                    = INVALID_SPEED;
                double rmr_speed_limit                    = INVALID_SPEED;
                double ros_speed_limit                    = INVALID_SPEED;
                double auto_skip_speed_limit              = INVALID_SPEED;
                double memorised_localisation_speed_limit = INVALID_SPEED;

                // Maximum reversing distance
                double max_reverse_distance = INVALID_DISTANCE;

                // Train length
                double train_length = INVALID_DISTANCE;

                // Configuration data

                // Travel time to get from the SBI to the EBD curve (sec)
                double t_service_brake = INVALID_TIME;

                // From section 3.13.9.3.6.2 of the ETCS standard (sec)
                double t_indication = INVALID_TIME;

                // Emergency brake deceleration rate (m/s^2)
                double ebd_rate = 0;

                // Service brake deceleration rate (m/s^2)
                double sbd_rate = 0;

                // Brake deceleration rate (m/s^2) used for automatic train driving
                double ato_brake_demand_rate = 0;

                // Identifies the distance between the EBD and EBI curves in (m)
                double dbec = INVALID_DISTANCE;

                /// Speed difference between Permitted speed and Emergency Brake Intervention supervision limits,
                /// minimum value (km/h)
                double dv_ebi_min = INVALID_SPEED;

                /// Speed difference between Permitted speed and Emergency Brake Intervention supervision limits,
                /// maximum value (km/h)
                double dv_ebi_max = INVALID_SPEED;

                /// Value of MRSP where dV_ebi starts to increase to dV_ebi_max (km/h)
                double v_ebi_min = INVALID_SPEED;

                /// Value of MRSP where dV_ebi stops to increase to dV_ebi_max (km/h)
                double v_ebi_max = INVALID_SPEED;

                /// Speed difference between Permitted speed and Service Brake Intervention supervision limits, minimum
                /// value (km/h)
                double dv_sbi_min = INVALID_SPEED;

                /// Speed difference between Permitted speed and Service Brake Intervention supervision limits, maximum
                /// value (km/h)
                double dv_sbi_max = INVALID_SPEED;

                /// Value of MRSP where dV_sbi starts to increase to dV_sbi_max (km/h)
                double v_sbi_min = INVALID_SPEED;

                /// Value of MRSP where dV_sbi stops to increase to dV_sbi_max (km/h)
                double v_sbi_max = INVALID_SPEED;

                /// Speed difference between Permitted speed and Warning supervision limits, minimum value (km/h)
                double dv_warning_min = INVALID_SPEED;

                /// Speed difference between Permitted speed and Warning supervision limits, maximum value (km/h)
                double dv_warning_max = INVALID_SPEED;

                /// Value of MRSP where dV_warning starts to increase to dV_warning_max (km/h)
                double v_warning_min = INVALID_SPEED;

                /// Value of MRSP where dV_warning stops to increase to dV_warning_max (km/h)
                double v_warning_max = INVALID_SPEED;

                /// Time between Warning supervision limit and SBI (sec)
                double t_warning = INVALID_TIME;

                /// Driver reaction time between Permitted speed supervision limit and SBI (sec)
                double t_driver = INVALID_TIME;

                /// Time between the pre-indication location and the indication supervision limit valid for MRSP speed.
                /// (sec)
                double t_preindiction = INVALID_TIME;
            };

            struct Inputs
            {
                double atc_sb_reset_button = 0.0;
                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                double current_train_position = INVALID_DISTANCE;
                double current_train_speed    = INVALID_SPEED;

                //=========================================================================================
                // The following data is populated using outputs from the CBTCOnboardInputs
                //=========================================================================================

                /// Speed Profile data  as (incremental distance, speed limit) where first incremental distance is
                /// the distance between the front of the train and first speed sign and subsequenct incremental
                /// distance as the distance from the previous to current speed limit.
                SpeedProfilePoints speed_data_profile;

                // Identifies the speed limit that applies to the train at the start of the speed profile
                double speed_profile_speed_limit = INVALID_SPEED;

                // Gradient profile data as (train path location, gradient)
                GradientProfilePoints path_gradient_profile;

                /// Current region train is located in platform region
                double train_front_in_platform = false; // NB: Implicit conversion to double for compatibility w comms
                double train_near_platform;

                //=========================================================================================
                // The following data is populated using outputs from the Trackside Data Managemrnt
                //=========================================================================================

                // Movement Authority related data
                double eoa_distance            = INVALID_DISTANCE;
                double svl_distance            = INVALID_DISTANCE;
                double stopping_point_distance = INVALID_DISTANCE;
                bool   ma_shortened            = false;

                //=========================================================================================
                // The following data is populated using outputs from the BeaconManagementModule
                //=========================================================================================

                /// Current localisation state
                double current_localisation_state = Project::TypeValue::LocalisationStatus::UNAVAILABLE;

                //=========================================================================================
                // The following data is populated using outputs from the Mode Transition Modules
                //=========================================================================================

                // Identifies the current CBTC Mode
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;
                double dmi_driver_event_change_ends = Project::TypeValue::ActiveInactive::INACTIVE;
                /// Current docking info
                double train_docking_status   = Project::TypeValue::TrainDockingStatus::UNKNOWN;
                double mode_selector_position = Project::TypeValue::ModeSelector::OFF_UTO;
                double psd_door_status  = Project::TypeValue::PSDDoorStatus::UNAVAILABLE;
                //=========================================================================================
                // The following data is populated using outputs from the Automatic Train Protection Module
                //=========================================================================================

                /// Reports current state of the emergency brake. When EB applied this identifies the reason for the EB
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_condition =
                  Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;

                double service_brake_request = Project::TypeValue::ServiceBrakeOrder::NO_SB_DEMAND;

                // Reports when automatic train driving is enabled
                bool ato_active = Project::TypeValue::ATOState::NOT_IN_AM;

                //=========================================================================================
                // The following data is populated using outputs from the Trackside Data Module
                //=========================================================================================

                /// Reports when a driver skip station event is being approached
                double next_driver_event_skip_station = Project::TypeValue::DriverEventStatus::INACTIVE;
            };

            struct Outputs
            {
                //=========================================================================================
                // The following data is reported to the train model
                //=========================================================================================

                // Reports when the train has zero speed
                double zero_speed = Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN;

                // Data required by the train in order to perform automatic driving
                double ato_permitted_distance = INVALID_DISTANCE;
                double ato_permitted_speed    = INVALID_SPEED;

                //=========================================================================================
                // The following data is reported to the DMI
                //=========================================================================================

                /// Speed that driver is to target at the next speed change
                double cbtc_target_speed = INVALID_SPEED;

                /// distance until the next change of target speed is reached
                double target_distance = INVALID_SPEED;

                /// Identifies the current speed status (normal, overspeed, warning, indication, intervention)
                Project::CBTCOnBoard::TypeValue::SpeedStatus speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;

                // Speed at which driver is advised to travel at in ATP mode
                double advisory_speed = INVALID_SPEED;

                // Speed at which driver is warned with FSB in ATP mode
                double warning_speed = INVALID_SPEED;
                //=========================================================================================
                // The following data reported to DMI, Train Model and Automatic Train Protection module
                //=========================================================================================

                /// Speed driver is permitted to go based on MRSP
                double cbtc_permitted_speed = INVALID_SPEED;

                //=========================================================================================
                // The following data is reported to the DMI and/or Automatic Train Protection module
                //=========================================================================================

                /// Current speed monitoring mode that the train is in (CSM, PIM, TSM)
                Project::CBTCOnBoard::TypeValue::MonitoringMode monitoring_mode = Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM;

                /// Velocity for emergency brake intervention
                double eb_intervention_velocity = INVALID_SPEED;

                /// Velocity for service brake intervention
                double sb_intervention_velocity = INVALID_SPEED;

                /// Reports when EOA is exceeded
                bool movement_authority_exceeded = false;

                /// Indication speed limit
                double indication_speed = INVALID_SPEED;

                /// Velocity for traction cut off
                double warning_velocity = INVALID_SPEED;

                /// Set to true when the train moves more than the allowed distance in post trip mode
                bool max_reverse_distance_exceeded = false;

                /// Indicates that speed monitoring is active
                bool speed_monitoring_active = false;
            };

            struct State
            {
                /// Position the train was located at in the previous step
                double previous_train_position = 0;

                // Records the Maximum train speed for the train
                double max_train_speed = INVALID_SPEED;

                // Records the CBTC Mode from the previous step
                double previous_cbtc_mode = Project::TypeValue::CBTCMode::NO_MODE;

                /// Records the distance the train has moved backwards when in post trip mode
                double distance_travelled_backwards = 0;

                /// This is the reported speed supervision status
                Project::CBTCOnBoard::TypeValue::SpeedStatus reported_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;

                // List of speed limit restrictions to be merged with the static speed profile packet data
                std::map<double, SpeedProfilePoint> speed_limit_restrictions;

                // Records the gradient profile that identifies the worst gradient that appears
                // under the train at each of the locations on the track.
                GradientProfilePoints ag_profile;
            };
        };

        /// Module that handles the functionality related to the Speed and Monitoring function of the CBTC OnBoard
        /// System.
        ///
        class SpeedAndDistanceMonitoringModule : public CBTCModule<SpeedAndDistanceMonitoringModule, SpeedAndDistanceMonitoringModuleIO>
        {
        public:
            SpeedAndDistanceMonitoringModule(const Initialisation& init);

            void Step(double time_step);

        private:
            /// Structure that holds the data reported when CSM, TSM and RSM data is generated
            struct MonitoredSpeedData
            {
                bool   is_valid                = false;
                double ato_velocity            = INVALID_SPEED;
                double ebi_velocity            = INVALID_SPEED;
                double sbi_velocity            = INVALID_SPEED;
                double warning_velocity        = INVALID_SPEED;
                double permitted_velocity      = INVALID_SPEED;
                double indication_velocity     = INVALID_SPEED;
                double pre_indication_velocity = INVALID_SPEED;
                double pre_indication_distance = INVALID_DISTANCE;
                double indication_distance     = INVALID_DISTANCE;
                double target_velocity         = INVALID_SPEED;
                double target_distance         = INVALID_DISTANCE;
                bool   is_eoa_target           = false;

                // The following vector holds information about the points in the EBI curve
                // where the decelleration rate being used changes
                ChangePoints ebi_change_points;

                // Similar vector as the EBI Curve except for the SBD curve
                ChangePoints sbd_change_points;

                std::string ToString() const;
            };

            // Functions to process input data from trackside
            void GenerateAGProfile();

            // Calculate ceiling speed limit
            double GetCeilingSpeedLimit(double speed_profile_limit);

            // Distance from docking front and back from the perfect docking point(Overshoot Distance) where door authorization is available 
            double m_door_authorization_distance_limit;

            // Calculate the Speed profile curves for each of the speed monitoring modes
            MonitoredSpeedData GetCSMProfile(double speed_limit);
            MonitoredSpeedData GetTSMProfile(double remaining_eoa_distance, double remaining_svl_distance);

            // Helper functions to get TSM
            MonitoredSpeedData CalculateTSMTarget(double previous_target_speed, double target_distance, double target_velocity);
            MonitoredSpeedData CalculateEOATarget(double speed_profile_velocity_at_eoa, double eoa_distance, double svl_distance);

            // Helpers to get the EBD and SBD curves while taking into account the change in gradient
            std::vector<std::tuple<double, double, double>> GetBrakeDecellerationCurve(double target_distance,
                                                                                       double target_velocity,
                                                                                       double brake_type,
                                                                                       bool   add_csm_ebi_offset,
                                                                                       bool   debug_curve = false);

            // Helpers to calculate the velocity at the current location based on braking curves
            double GetEBIVelocity(double target_distance, double target_velocity, double decelleration_rate, bool add_csm_ebi_offset);
            double GetEBDMonitoredSpeedVelocity(double target_distance,
                                                double target_velocity,
                                                double decelleration_rate,
                                                double time_offset,
                                                bool   add_csm_ebi_offset);
            double GetSBDMonitoredSpeedVelocity(double target_distance, double target_velocity, double decelleration_rate, double time_offset);

            // Helpers to find the distance to a given braking curve given that the train is traveling at a given speed
            double GetEBIDistance(double start_velocity, double target_velocity, double target_distance, double decelleration_rate, bool add_csm_ebi_offset);
            double GetEBDMonitoredSpeedDistance(double start_velocity,
                                                double target_velocity,
                                                double target_distance,
                                                double decelleration_rate,
                                                double time_offset,
                                                bool   add_csm_ebi_offset);
            double GetSBDMonitoredSpeedDistance(double start_velocity,
                                                double target_velocity,
                                                double target_distance,
                                                double decelleration_rate,
                                                double time_offset);

            // Functions for determining and reporting data generated from performing speed supervision
            void TargetAndModeManagement(SpeedAndDistanceMonitoringModule::MonitoredSpeedData csm_data,
                                         SpeedAndDistanceMonitoringModule::MonitoredSpeedData tsm_data);
            Project::CBTCOnBoard::TypeValue::MonitoringMode GetSpeedMonitoringMode(double tsm_indication_distance,
                                                                                   double tsm_preindication_distance,
                                                                                   double tsm_target_velocity,
                                                                                   double csm_target_velocity);
            Project::CBTCOnBoard::TypeValue::SpeedStatus DetermineSpeedStatus(Project::CBTCOnBoard::TypeValue::MonitoringMode monitoring_mode,
                                                                              MonitoredSpeedData monitoring_mode_data);

            // Determine the advisory speed to report to the driver, if any
            double GetAdvisorySpeed();

            // Determine the warning speed to report to the driver, if any
            double GetWarningSpeed();

            // Determine if the train is at standstill
            void PerformZeroSpeedDetection();

            // Test current speed against threshold (including delta for train model fluctuations)
            bool IsSpeedThresholdExceeded(double threshold_speed) const;

            void LogSpeedProfile();

        private:
            // Fixed values converted from km/hr to m/sec
            double v_ebi_min      = INVALID_SPEED;
            double v_ebi_max      = INVALID_SPEED;
            double dv_ebi_min     = INVALID_SPEED;
            double dv_ebi_max     = INVALID_SPEED;
            double v_sbi_min      = INVALID_SPEED;
            double v_sbi_max      = INVALID_SPEED;
            double dv_sbi_min     = INVALID_SPEED;
            double dv_sbi_max     = INVALID_SPEED;
            double v_warning_min  = INVALID_SPEED;
            double v_warning_max  = INVALID_SPEED;
            double dv_warning_min = INVALID_SPEED;
            double dv_warning_max = INVALID_SPEED;

            // National values converted from km/hr to m/sec
            double auto_region_speed_limit            = INVALID_SPEED;
            double rmf_speed_limit                    = INVALID_SPEED;
            double rmr_speed_limit                    = INVALID_SPEED;
            double ros_speed_limit                    = INVALID_SPEED;
            double auto_skip_speed_limit              = INVALID_SPEED;
            double memorised_localisation_speed_limit = INVALID_SPEED;

            // Times that identify the distance between a curve and the EBI curve
            double sbi_time_offset           = INVALID_TIME;
            double warning_time_offset       = INVALID_TIME;
            double permitted_time_offset     = INVALID_TIME;
            double indication_time_offset    = INVALID_TIME;
            double preindication_time_offset = INVALID_TIME;
        };
    }
}
