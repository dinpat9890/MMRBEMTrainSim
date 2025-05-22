///
/// @file       SpeedAndDistanceMonitoringModule.cpp
///
///             Implements the SpeedAndDistanceMonitoringModule class.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "SpeedAndDistanceMonitoringModule.h"

#include "common/StandardLogging.h"

#include <algorithm>
#include <limits>
#include <math.h>

using namespace Project::CBTCOnBoard;

namespace
{
    const bool   DEBUG                = false;
    const bool   DEBUG_BRAKING_CURVES = false;
    const bool   TEST                 = false;
    const double SPEED_DELTA          = 0.1;
    const double SSP_DELTA            = 1.8;
    const double WARNING_FSB_DELTA    = 0.83333;//  3 kmph
    const double WARNING_RM_LIMIT     = 0.56;
    double ADVISORY_DISTANCE          = 250.0;
    const double MAX_WARNING_SPEED    = 23.06;  // 83 kmph
    const double PSD_BYPASSED_MAX_SPEED_ALLOWED = 1.944; // 7kmph
    const double DOCKING_DISTANCE_FOR_PSD_BYPASSED = 3.0;
    /// Convert Km/Hr to m/sec
    ///
    /// Note that a profile point may be used to mark the end of a profile by setting
    /// the velocity to have value "END_OF_PROFILE".
    ///
    double KmPerHrToMPerSec(double speed)
    {
        if (speed != END_OF_PROFILE)
            return (speed / MPS_TO_KPH);
        else
            return END_OF_PROFILE;
    }

    /// Of the two speed status values given, returns the value of the speed status that is triggered at the higher
    /// speed
    ///
    Project::CBTCOnBoard::TypeValue::SpeedStatus GetHighestSpeedSpeedStatus(Project::CBTCOnBoard::TypeValue::SpeedStatus status_one,
                                                                            Project::CBTCOnBoard::TypeValue::SpeedStatus status_two)
    {
        if ((status_one == Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION) ||
            (status_two == Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION))
            return Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION;
        else if ((status_one == Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING) ||
                 (status_two == Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING))
            return Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING;
        else if ((status_one == Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED) ||
                 (status_two == Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED))
            return Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED;
        else if ((status_one == Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION) ||
                 (status_two == Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION))
            return Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION;

        return Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;
    }

    /// Get the change in velocity value that is used when calculating the speed profile curves
    ///
    double GetDVEBI(double target_velocity, double v_ebi_min, double v_ebi_max, double dv_ebi_min, double dv_ebi_max)
    {
        auto c = 0.0;
        if (v_ebi_max != v_ebi_min)
            c = (dv_ebi_max - dv_ebi_min) / (v_ebi_max - v_ebi_min);

        double dv_ebi = dv_ebi_min;
        if (target_velocity > dv_ebi_min)
            dv_ebi = std::min((dv_ebi_min + c * (target_velocity - v_ebi_min)), dv_ebi_max);

        return dv_ebi;
    }
}

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data to be used by the module
///
SpeedAndDistanceMonitoringModule::SpeedAndDistanceMonitoringModule(const Initialisation& init)
  : CBTCModule<SpeedAndDistanceMonitoringModule, SpeedAndDistanceMonitoringModuleIO>(init)
  , m_door_authorization_distance_limit(5.0)
{
    // Record all fixed data values whose units need to be converted
    v_ebi_min      = KmPerHrToMPerSec(K().v_ebi_min);
    v_ebi_max      = KmPerHrToMPerSec(K().v_ebi_max);
    dv_ebi_min     = KmPerHrToMPerSec(K().dv_ebi_min);
    dv_ebi_max     = KmPerHrToMPerSec(K().dv_ebi_max);
    v_sbi_min      = KmPerHrToMPerSec(K().v_sbi_min);
    v_sbi_max      = KmPerHrToMPerSec(K().v_sbi_max);
    dv_sbi_min     = KmPerHrToMPerSec(K().dv_sbi_min);
    dv_sbi_max     = KmPerHrToMPerSec(K().dv_sbi_max);
    v_warning_min  = KmPerHrToMPerSec(K().v_warning_min);
    v_warning_max  = KmPerHrToMPerSec(K().v_warning_max);
    dv_warning_min = KmPerHrToMPerSec(K().dv_warning_min);
    dv_warning_max = KmPerHrToMPerSec(K().dv_warning_max);

    // Record speed limit values whose units need to be converted
    auto_region_speed_limit            = KmPerHrToMPerSec(K().auto_region_speed_limit);
    rmf_speed_limit                    = KmPerHrToMPerSec(K().rmf_speed_limit);
    rmr_speed_limit                    = KmPerHrToMPerSec(K().rmr_speed_limit);
    ros_speed_limit                    = KmPerHrToMPerSec(K().ros_speed_limit);
    auto_skip_speed_limit              = KmPerHrToMPerSec(K().auto_skip_speed_limit);
    memorised_localisation_speed_limit = KmPerHrToMPerSec(K().memorised_localisation_speed_limit);

    // Set the time offsets for our curve calculations
    sbi_time_offset           = K().t_service_brake;
    warning_time_offset       = sbi_time_offset + K().t_warning;
    permitted_time_offset     = sbi_time_offset + K().t_driver;
    indication_time_offset    = permitted_time_offset + K().t_indication;
    preindication_time_offset = indication_time_offset + K().t_preindiction;

    // Initialise state data, if required
    X().max_train_speed = auto_region_speed_limit;
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step The amount of time to since the module was last run
void SpeedAndDistanceMonitoringModule::Step(double time_step)
{
    // Determine max train speed for given region

    X().max_train_speed = GetCeilingSpeedLimit(auto_region_speed_limit);

    /// Use the gradient profile to generate the profile that captures the accelleration due to gradient used in
    /// the braking curve calculations
    GenerateAGProfile();

    // Is train at standstill
    PerformZeroSpeedDetection();

    // Determine the advisory speed, if any, to report to the driver
    Y().advisory_speed = GetAdvisorySpeed();

    // Determine the warning speed, if any, to report to the driver
    Y().warning_speed = GetWarningSpeed();

    // Perform speed and distance monitoring for those modes that require it
    MonitoredSpeedData csm_profile_data;
    csm_profile_data.is_valid = false;
    MonitoredSpeedData tsm_profile_data;
    tsm_profile_data.is_valid = false;

    // Update distance travelled backwards if the train is in RMR mode
    // or a train that has previously reversed while in RMF mode starts moving forwards
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR) || (X().distance_travelled_backwards < 0.0))
    {
        X().distance_travelled_backwards += (U().current_train_position - X().previous_train_position);

        if (X().distance_travelled_backwards > 0.0 || static_cast<bool>(U().atc_sb_reset_button) == true)
            X().distance_travelled_backwards = 0.0;
    }

    // Speed and distance monitoring in ATP and ATO modes
    if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP ||
        U().mode_selector_position == Project::TypeValue::ModeSelector::ATO || U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)
    {
        csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(U().speed_profile_speed_limit));

        // In ATO mode, if the stopping point distance is less than the EOA distance then
        // we use this as the end of authority for ATO driving
        if (U().ato_active && ((U().stopping_point_distance - MAX_ALLOWED_OVERSHOOT_IN_ATO) < U().eoa_distance))
            tsm_profile_data = GetTSMProfile(U().stopping_point_distance, U().stopping_point_distance);
        else
            tsm_profile_data = GetTSMProfile(U().eoa_distance, U().svl_distance);
    }
    // Speed monitoring in RMF Mode
    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF)
    {
        csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(X().max_train_speed));

        // In RMF mode all speed curves are fixed at the RMF ceiling speed limit
        csm_profile_data.ebi_velocity     = csm_profile_data.permitted_velocity;
        csm_profile_data.warning_velocity = csm_profile_data.permitted_velocity - WARNING_RM_LIMIT;
    }

    // Speed and Distance monitoring performed in RMR mode
    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR)
    {
        csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(X().max_train_speed));

        // In RMR mode all speed curves are fixed at the RMR ceiling speed limit
        csm_profile_data.ebi_velocity     = csm_profile_data.permitted_velocity;
        csm_profile_data.sbi_velocity     = csm_profile_data.permitted_velocity;
        csm_profile_data.warning_velocity = csm_profile_data.permitted_velocity;
    }

    // Speed and Distance monitoring performed in ROS mode
    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ROS)
    {
        csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(X().max_train_speed));

        // In ROS mode all speed curves are fixed at the ROS ceiling speed limit
        csm_profile_data.ebi_velocity     = csm_profile_data.permitted_velocity;
        csm_profile_data.warning_velocity = csm_profile_data.permitted_velocity - WARNING_RM_LIMIT;
    }
    // Trace out our speed monitoring data in Debug mode
    if (DEBUG)
    {
        LogSpeedProfile();
        if (csm_profile_data.is_valid)
            Trace::GetLogger().STAMP(Trace::INFO) << "CSMProfile - " << csm_profile_data.ToString() << Trace::EndLog();

        if (tsm_profile_data.is_valid)
            Trace::GetLogger().STAMP(Trace::INFO) << "TSMProfile - " << GetCeilingSpeedLimit(U().speed_profile_speed_limit)
                                                  << " - " << tsm_profile_data.ToString() << Trace::EndLog();
    }

    // Perform target and mode management which will update the speed and distance monitoring outputs
    TargetAndModeManagement(csm_profile_data, tsm_profile_data);

    // Maximum reverse distance since train is allowed to reverse.
    auto max_reverse_distance = K().max_reverse_distance;

    // Max reverse distance exceeded is reported when the distance travelled exceeds
    // the maximum allowed reverse movement distance.
    if (std::abs(X().distance_travelled_backwards) > max_reverse_distance)
        Y().max_reverse_distance_exceeded = true;
    else
        Y().max_reverse_distance_exceeded = false;

    // Report if the train's End of Authority has been exceeded while in a mode that performs distance monitoring
    // Note that EOA is assumed to be where the train should be stopping and SVL is considered as the point of
    // protection that the train should not pass.
    Y().movement_authority_exceeded = false;
    if (((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO || U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) &&
         ((U().svl_distance - DELTA) <= -SSP_DELTA)) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP && ((U().svl_distance - DELTA) <= 0.0)) && (!U().ma_shortened))
    {
        Y().movement_authority_exceeded = true;
    }

    // Update any remaining state data that has not already been updated
    X().previous_train_position = U().current_train_position;
    X().previous_cbtc_mode      = U().cbtc_current_mode;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Generate the profile that provides the locations where the accelleration due to gradient changes
///
/// The Trackside gradient profile needs to be converted into an onboard profile
/// where the gradient at a given track location is given by the worst case
/// gradient under the train. Refer Subset-026, section 3.13.4.1, figure 35
///
/// Formula for calculating acceleration due to gradient given in Subset-026, section 3.13.4.3.2
///
void SpeedAndDistanceMonitoringModule::GenerateAGProfile()
{
    if (U().path_gradient_profile.empty())
        return;

    // Define and insert the first element into the onboard gradient profile
    std::vector<std::pair<double, double>> onboard_gradient_profile;
    onboard_gradient_profile.push_back(
      std::pair<double, double>(U().path_gradient_profile.begin()->first, U().path_gradient_profile.begin()->second));

    // Identifies gradient profile point to be compared against the next gradient point being processed from the
    // profile
    std::pair<double, double> previous_gradient = onboard_gradient_profile.back();

    // Identifies the last gradient change point that the train detected
    std::pair<double, double> last_gradient;

    bool rear_gradient_less_than_front = false;

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << "\nOnboard gradient (Ref pos = " << U().path_gradient_profile.front().first << ")"
                                             << "\n--------------------------------------------------------";

    // First we need to generate the onboard gradient profile. In this profile the gradient
    // at a given track location is given by the worst case gradient under the train.
    // Refer Subset-026, section 3.13.4.1, figure 35.
    for (auto next_gradient : U().path_gradient_profile)
    {
        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::ERR) << "\nNext Gradient : "
                                                 << "  (" << next_gradient.first << " " << next_gradient.second << ")";

        if (next_gradient.first == U().path_gradient_profile.begin()->first)
            continue;

        // If the gradient at the rear of the train is less than the gradient at the front, the
        // rear of the train must leave this lower gradient region before the higher gradient
        // profile point is inserted into the onboard gradient profile
        if (rear_gradient_less_than_front && (next_gradient.first > (previous_gradient.first + K().train_length)))
        {
            // Insert the gradient profile point for the higher gradient region of track that the rear of the
            // train has just entered
            onboard_gradient_profile.push_back(
              std::pair<double, double>((previous_gradient.first + K().train_length), previous_gradient.second));

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR)
                  << "\n-  insert new            " << previous_gradient.first << " + " << K().train_length << "  ("
                  << onboard_gradient_profile.back().first << " " << onboard_gradient_profile.back().second << ")";

            // If the next gradient value is greater than the last detected gradient profile value
            // and the location of the next gradient change happens before the rear of the train
            // passes over this last detected gradient change, then the value of the previous gradient
            // to be used in this iteration of the loop should be updated to be the gradient detected in
            // the previous iteration of this loop
            if ((next_gradient.second > last_gradient.second) && (next_gradient.first < (last_gradient.first + K().train_length)))
            {
                previous_gradient = last_gradient;

                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::ERR)
                      << "\n-  rear_gradient_less_than_front           "
                      << "  (" << previous_gradient.first << " " << previous_gradient.second << ")";
            }
            else
                rear_gradient_less_than_front = false;
        }

        // If the train is moving into an area where the gradient is lower than the area it was previously in,
        // the gradient is immediately added into the onboard gradient profile and the previous gradient value
        // to be used in the next iteration is updated to the newly detected gradient value
        if (next_gradient.second < previous_gradient.second)
        {
            onboard_gradient_profile.push_back(next_gradient);
            rear_gradient_less_than_front = false;
            previous_gradient             = next_gradient;

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << "\n-   insert existing      "
                                                     << "  (" << onboard_gradient_profile.back().first << " "
                                                     << onboard_gradient_profile.back().second << ")";
        }

        // If the train is moving into an area where the gradient is higher than the area it was previously in
        else
        {
            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << "\n  skip       ";

            // Set the flag that indicates the train is moving into an area where the gradient is higher than the
            // area it is leaving and record the detected gradient as the previous gradient that is to be used in
            // the next iteration
            if (!rear_gradient_less_than_front)
            {
                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::ERR) << "\n-  rear_gradient_less_than_front       "
                                                         << "  (" << next_gradient.first << " " << next_gradient.second << ")";

                rear_gradient_less_than_front = true;
                previous_gradient             = next_gradient;
            }
        }

        // Record the last gradient that the train moved past
        last_gradient = next_gradient;
    }

    if (DEBUG_BRAKING_CURVES)
        Trace::GetLogger().STAMP(Trace::ERR) << "\n\nAccelleration due to gradient  " << U().current_train_position
                                             << "\n--------------------------------------------------------";

    // Generate the "acceleration due to gradient" profile points for the Onboard gradient profile
    // Uses path position to identify the location at which the acceleration due to gradient changes
    // Expected test result (based on Subset-026, section 3.13.4.1, figure 35) is
    // -> (0.0, 0.0), (10 -0.0865), (100 -0.1729), (350 -0.0769), (400 0.05965), (450 0.0)
    X().ag_profile.clear();
    for (auto next_gradient_profile : onboard_gradient_profile)
    {
        double accelleration_gradient;
        if (next_gradient_profile.second < 0.0)
            accelleration_gradient = (next_gradient_profile.second * ACCELELERATION_GRAVITY) /
                                     (1000.0 + (10 * FixedValues::m_rotating_min));
        else
            accelleration_gradient = (next_gradient_profile.second * ACCELELERATION_GRAVITY) /
                                     (1000.0 + (10 * FixedValues::m_rotating_max));

        X().ag_profile.push_back(std::pair<double, double>(next_gradient_profile.first, accelleration_gradient));

        if (DEBUG_BRAKING_CURVES)
            Trace::GetLogger().STAMP(Trace::ERR)
              << "\n---------------->         "
              << "  (" << X().ag_profile.back().first << ", " << next_gradient_profile.second
              << ") -> AG = " << X().ag_profile.back().second << ")";
    }

    if (DEBUG_BRAKING_CURVES)
        Trace::GetLogger().STAMP(Trace::ERR) << "\n--------------------------------------------------------" << Trace::EndLog();
}

/// Determine the maximum allowed speed the train can travel at it's current location
///
/// @param speed_profile_limit Currrent speed limit provided by the target speed profile or max speed when no
/// profile present
///
double SpeedAndDistanceMonitoringModule::GetCeilingSpeedLimit(double speed_profile_limit)
{

    // Default ceiling speed limit to the speed given in the speed profile
    double ceiling_speed_limit = speed_profile_limit;

    // TBD - Look to delete this and only have in speed profile created by trackside data module
    // Region related speed restriction including skip station speed restriction
    if (auto_region_speed_limit < ceiling_speed_limit)
        ceiling_speed_limit = auto_region_speed_limit;

    // Set Skip station speed limit when train running in AM mode is near a platform that is being skipped
    if ((U().mode_selector_position == Project::TypeValue::ModeSelector::ATO || U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) &&
        (U().next_driver_event_skip_station == Project::TypeValue::DriverEventStatus::ACTIVE) && U().train_front_in_platform)
        ceiling_speed_limit = auto_skip_speed_limit;

    // RMF mode related speed restriction
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF) && ((rmf_speed_limit < ceiling_speed_limit)))
        ceiling_speed_limit = rmf_speed_limit;

    // RMR mode related speed restriction
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR) && ((rmr_speed_limit < ceiling_speed_limit)))
        ceiling_speed_limit = rmr_speed_limit;

    // ROS mode related speed restriction
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ROS) && ((ros_speed_limit < ceiling_speed_limit)))
        ceiling_speed_limit = ros_speed_limit;

    // Memorised location related speed restriction applies when driving with memorised location in ATO/ATP mode
    else if (((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
              (U().mode_selector_position == Project::TypeValue::ModeSelector::ATO) ||
              (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)) &&
             (U().current_localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
             (memorised_localisation_speed_limit < ceiling_speed_limit))
        ceiling_speed_limit = memorised_localisation_speed_limit;

    return ceiling_speed_limit;
}

/// Calculates the CSM Speed Profile data
///
/// @param speed_limit ceiling speed limit that needs to be met
///
SpeedAndDistanceMonitoringModule::MonitoredSpeedData SpeedAndDistanceMonitoringModule::GetCSMProfile(double speed_limit)
{
    SpeedAndDistanceMonitoringModule::MonitoredSpeedData data;
    data.is_valid = true;

    if (speed_limit < 0.0)
    {
        data.ato_velocity            = INVALID_SPEED;
        data.ebi_velocity            = INVALID_SPEED;
        data.sbi_velocity            = INVALID_SPEED;
        data.warning_velocity        = INVALID_SPEED;
        data.permitted_velocity      = INVALID_SPEED;
        data.indication_velocity     = INVALID_SPEED;
        data.pre_indication_velocity = INVALID_SPEED;
        data.pre_indication_distance = INVALID_DISTANCE;
        data.indication_distance     = INVALID_SPEED;
        data.target_distance         = INVALID_DISTANCE;
        data.target_velocity         = INVALID_SPEED;
        data.is_eoa_target           = false;

        return data;
    }

    // Determine the EBI ceiling speed limit
    auto c_ebi = 0.0;
    if (v_ebi_max != v_ebi_min)
        c_ebi = (dv_ebi_max - dv_ebi_min) / (v_ebi_max - v_ebi_min);

    if (speed_limit > v_ebi_min)
        data.ebi_velocity = std::min((dv_ebi_min + c_ebi * (speed_limit - v_ebi_min)), dv_ebi_max) + speed_limit;
    else
        data.ebi_velocity = dv_ebi_min + speed_limit;

    // Determine the SBI ceiling speed limit
    auto c_sbi = 0.0;
    if (v_sbi_max != v_sbi_min)
        c_sbi = (dv_sbi_max - dv_sbi_min) / (v_sbi_max - v_sbi_min);

    if (speed_limit > v_sbi_min)
        data.sbi_velocity = std::min((dv_sbi_min + c_sbi * (speed_limit - v_sbi_min)), dv_sbi_max) + speed_limit;
    else
        data.sbi_velocity = dv_sbi_min + speed_limit;

    // Determine the Warning ceiling speed limit
    auto c_warning = 0.0;
    if (v_warning_max != v_warning_min)
        c_warning = (dv_warning_max - dv_warning_min) / (v_warning_max - v_warning_min);

    if (speed_limit > v_warning_min)
        data.warning_velocity = std::min((dv_warning_min + c_warning * (speed_limit - v_warning_min)), dv_warning_max) + speed_limit;
    else
        data.warning_velocity = dv_warning_min + speed_limit;

    // Set the permitted, preindication, target velocities to the speed limit
    data.ato_velocity            = speed_limit;
    data.permitted_velocity      = speed_limit;
    data.indication_velocity     = speed_limit;
    data.pre_indication_velocity = speed_limit;
    data.target_velocity         = speed_limit;
    data.target_distance         = INVALID_DISTANCE;
    data.pre_indication_distance = INVALID_DISTANCE;
    data.indication_distance     = INVALID_DISTANCE;
    data.is_eoa_target           = false;

    return data;
}

/// Calculates the TSM speed profile for each target speed
///
/// Note that the target speed monitoring curves end at the point where they meet the
/// ceiling speed monitoring curves associated with the target speed being monitored
///
/// @param remaining_eoa_distance distance to the end of movement authority
/// @param remaining_svl_distance distance to the SvL
///
/// @returns the Speed monitoring data to be used when in TSM mode
///
SpeedAndDistanceMonitoringModule::MonitoredSpeedData
SpeedAndDistanceMonitoringModule::GetTSMProfile(double remaining_eoa_distance, double remaining_svl_distance)
{
    SpeedAndDistanceMonitoringModule::MonitoredSpeedData data;
    data.is_valid = true;

    // Determine TSM data for each speed profile point
    auto speed_profile_velocity_at_eoa = GetCeilingSpeedLimit(U().speed_profile_speed_limit);
    auto previous_target_speed         = GetCeilingSpeedLimit(U().speed_profile_speed_limit);
    std::vector<SpeedAndDistanceMonitoringModule::MonitoredSpeedData> tsm_data;
    for (auto& speed_profile : U().speed_data_profile)
    {
        auto target_distance      = speed_profile.first - U().current_train_position;
        auto next_target_velocity = speed_profile.second;

        // Target distance is the distance from the front of the train to the speed profile point
        // We only need to calculate TSM speed data for targets that appear before our EOA location
        if ((target_distance > remaining_eoa_distance) || (next_target_velocity == 0))
            break;

        // Only calculate a target speed monitoring profile when the previous target speed is greater than the next
        // one.
        if (previous_target_speed > next_target_velocity)
        {
            // Get the Target speed monitoring and ceiling speed monitoring curves for the next target.
            // We want to get the max value of these two speeds since the TSM monitoring curves end at
            // the point where they intersect the CSM monitoring curve for the given target speed
            auto next_target_tsm = CalculateTSMTarget(GetCeilingSpeedLimit(previous_target_speed), target_distance, next_target_velocity);
            auto next_target_csm = GetCSMProfile(GetCeilingSpeedLimit(next_target_velocity));

            if (DEBUG && (next_target_tsm.target_distance < 0.0))
                Trace::GetLogger().STAMP(Trace::ERR) << "\n---------------------------------------------  : "
                                                     << "  (" << previous_target_speed << " " << next_target_velocity
                                                     << " ->    " << target_distance << "}\n"
                                                     << Trace::EndLog();

            SpeedAndDistanceMonitoringModule::MonitoredSpeedData next_tsm;
            next_tsm.is_valid         = true;
            next_tsm.ato_velocity     = std::max(next_target_tsm.ato_velocity, next_target_csm.ato_velocity);
            next_tsm.ebi_velocity     = std::max(next_target_tsm.ebi_velocity, next_target_csm.ebi_velocity);
            next_tsm.sbi_velocity     = std::max(next_target_tsm.sbi_velocity, next_target_csm.sbi_velocity);
            next_tsm.warning_velocity = std::max(next_target_tsm.warning_velocity, next_target_csm.warning_velocity);
            next_tsm.permitted_velocity = std::max(next_target_tsm.permitted_velocity, next_target_csm.permitted_velocity);
            next_tsm.indication_velocity = std::max(next_target_tsm.indication_velocity, next_target_csm.indication_velocity);
            next_tsm.pre_indication_velocity = std::max(next_target_tsm.pre_indication_velocity, next_target_csm.pre_indication_velocity);
            next_tsm.target_distance         = next_target_tsm.target_distance;
            next_tsm.target_velocity         = next_target_tsm.target_velocity;
            next_tsm.pre_indication_distance = next_target_tsm.pre_indication_distance;
            next_tsm.indication_distance     = next_target_tsm.indication_distance;
            next_tsm.is_eoa_target           = false;

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << "NEXT TSM  - " << next_target_tsm.ToString() << "\n\n  "
                                                     << target_distance << " " << remaining_svl_distance << Trace::EndLog();

            tsm_data.push_back(next_tsm);
        }

        speed_profile_velocity_at_eoa = next_target_velocity;
        previous_target_speed         = next_target_velocity;
    }

    // Determine TSM for the end of the movement authority
    tsm_data.push_back(CalculateEOATarget(speed_profile_velocity_at_eoa, remaining_eoa_distance, remaining_svl_distance));

    // At this point we have a Target speed monitoring profile for each target decrease
    // so we just want to find the most retrictive profile
    data = tsm_data[0];
    for (size_t i = 1; i < tsm_data.size(); i++)
    {
        // TSM profile selected identifies the next profile that will trigger TSM
        if (data.permitted_velocity > tsm_data[i].permitted_velocity)
        {
            data.ato_velocity            = tsm_data[i].ato_velocity;
            data.ebi_velocity            = tsm_data[i].ebi_velocity;
            data.sbi_velocity            = tsm_data[i].sbi_velocity;
            data.warning_velocity        = tsm_data[i].warning_velocity;
            data.permitted_velocity      = tsm_data[i].permitted_velocity;
            data.indication_velocity     = tsm_data[i].indication_velocity;
            data.target_distance         = tsm_data[i].target_distance;
            data.target_velocity         = tsm_data[i].target_velocity;
            data.is_eoa_target           = tsm_data[i].is_eoa_target;
            data.pre_indication_distance = tsm_data[i].pre_indication_distance;
            data.indication_distance     = tsm_data[i].indication_distance;
            data.pre_indication_velocity = tsm_data[i].pre_indication_velocity;
        }
    }

    return data;
}

/// Returns the braking curve for the given target distance and velocity.
///
/// This braking curve is made up of a number of segments where each segment corresponds to a region in which a
/// different decelleration rate is being applied. Each point on the curve identifies
/// - path position to which the decelleration curve point applies,
/// - target velocity at this path position in order for train to reach the target velocity at the target distance
/// - braking decelleration that applies between this and the next braking curve point
///
/// * Important Note : The first element in the vector is the brake curve segment closest to the target
///                    The last element in the vector is the brake curve segment closest to the train
///
/// @param target_distance      Distance of travel between the current position and position of the target velocity
/// @param target_velocity      Velocity train must be traveling when it reaches the position given by the target
/// distance
/// @param brake_type           Brake type which identifies the brake curve equation and deceleration rate
/// @param add_csm_ebi_offset   Flag that indicates the given target velocity should be increased by dV_EBI
///
/// @returns Vector of points that identify the target speed required at different points on the path as the train
///          approaches the target speed located at the target distance (path position, target velocity,
///          decelleration)
///
std::vector<std::tuple<double, double, double>> SpeedAndDistanceMonitoringModule::GetBrakeDecellerationCurve(double target_distance,
                                                                                                             double target_velocity,
                                                                                                             double brake_type,
                                                                                                             bool add_csm_ebi_offset,
                                                                                                             bool debug_curve)
{
    // Following records the end points of the segments (path position, target velocity, decelleration rate) which
    // make up the braking curve that terminates at point (target distance, target velocity)
    std::vector<std::tuple<double, double, double>> braking_curve_change_points;

    double decelleration_rate = 0;
    if (brake_type == SERVICE_BRAKE)
    {
        if (U().ato_active)
            decelleration_rate = K().ato_brake_demand_rate;
        else
            decelleration_rate = K().sbd_rate;
    }
    else if (brake_type == EMERGENCY_BRAKE)
        decelleration_rate = K().ebd_rate;

    auto   braking_rate                 = decelleration_rate;
    double next_braking_target_velocity = target_velocity;

    // Find the location at which the gradient segment, on which the target velocity is located, first starts to
    // apply to the track
    auto next_target_position    = U().current_train_position + target_distance;
    auto gradient_at_target_iter = std::find_if(X().ag_profile.rbegin(),
                                                X().ag_profile.rend(),
                                                [next_target_position](const std::pair<double, double>& ag_profile_point)
                                                { return ag_profile_point.first < next_target_position; });

    // If we found a gradient then we want to determine the segments that make up the braking curve
    if (gradient_at_target_iter != X().ag_profile.rend())
    {
        if (debug_curve)
            Trace::GetLogger().STAMP(Trace::ERR)
              << "\n======================== Braking Curve Data =====================\n"
                 " -> "
              << U().current_train_position << ": " << target_distance << ", " << target_velocity << "\n"
              << gradient_at_target_iter->first << " " << gradient_at_target_iter->second << "\n\n";

        // Calculate the braking deceleration rate that applies at the final target location and record the final
        // target point into the vector of braking curve segments
        braking_rate = decelleration_rate + gradient_at_target_iter->second;
        braking_curve_change_points.push_back(std::tuple<double, double, double>(next_target_position, target_velocity, braking_rate));
        auto previous_target_position = next_target_position;

        if (debug_curve)
            Trace::GetLogger().STAMP(Trace::ERR)
              << "         ------------> (" << std::get<0>(braking_curve_change_points.back()) << ", "
              << std::get<1>(braking_curve_change_points.back()) << ", "
              << std::get<2>(braking_curve_change_points.back()) << ")\n";

        // Loop back through all of the different gradient regions between the target and the train
        // and calculate the braking curve velocity at the start of each of these gradient segements
        while ((gradient_at_target_iter != X().ag_profile.rend()) && (next_target_position > U().current_train_position))
        {
            // Final target position will be located at the front of the train
            next_target_position = gradient_at_target_iter->first;
            if (next_target_position < U().current_train_position)
                next_target_position = U().current_train_position;

            auto next_target_distance = previous_target_position - next_target_position;
            braking_rate              = decelleration_rate + gradient_at_target_iter->second;

            if (debug_curve)
                Trace::GetLogger().STAMP(Trace::ERR) << "( " << next_target_distance << ", " << target_velocity << ")    ------------> ";

            // Calculate the braking curve point and add it to our vector of braking curve segments
            if (brake_type == EMERGENCY_BRAKE)
            {
                next_braking_target_velocity = GetEBIVelocity(
                  next_target_distance, next_braking_target_velocity, braking_rate, add_csm_ebi_offset);
                if (add_csm_ebi_offset)
                    next_braking_target_velocity -= K().dbec;
            }
            else if (brake_type == SERVICE_BRAKE)
                next_braking_target_velocity = GetSBDMonitoredSpeedVelocity(
                  next_target_distance, next_braking_target_velocity, braking_rate, 0.0);

            braking_curve_change_points.push_back(
              std::tuple<double, double, double>(next_target_position, next_braking_target_velocity, braking_rate));

            if (debug_curve)
                Trace::GetLogger().STAMP(Trace::ERR) << "( " << std::get<0>(braking_curve_change_points.back()) << ", "
                                                     << std::get<1>(braking_curve_change_points.back()) << ", "
                                                     << std::get<2>(braking_curve_change_points.back()) << "\n";

            previous_target_position = next_target_position;
            gradient_at_target_iter++;
        }
    }

    // If we failed to find a gradient then we just calculate a single braking curve that uses the base
    // decelleration rate.
    else
        braking_curve_change_points.push_back(std::tuple<double, double, double>(
          U().current_train_position + target_distance, target_velocity, decelleration_rate));
    return braking_curve_change_points;
}

/// Calculate the monitored speed data for the given target located at the given distance ahead of the train
///
/// @param previous_target_speed Target speed of the previous speed change location
/// @param target_distance       Distance to the speed change location
/// @param target_velocity       Velocity to be reached at the speed change location
///
/// @returns the Target Speed Monitoring data for the given speed profile point
///
SpeedAndDistanceMonitoringModule::MonitoredSpeedData
SpeedAndDistanceMonitoringModule::CalculateTSMTarget(double previous_target_speed, double target_distance, double target_velocity)
{
    SpeedAndDistanceMonitoringModule::MonitoredSpeedData tsm_target;
    tsm_target.is_valid = true;

    // Following records the end points of the segments (start location, start velocity, SBD rate) that make up
    // the SBD curve that terminates at point (eoa distance, zero velocity)
    std::vector<std::tuple<double, double, double>> sbd_curve_change_points = GetBrakeDecellerationCurve(
      target_distance, target_velocity, SERVICE_BRAKE, true);

    // Get the information about the service brake curve segment that is closest to the train and use this to
    // calculate target velocities. Note that
    // - std::get<0> : returns path position where first brake decelleration curve segment ends
    // - std::get<1> : returns target velocity located at the end of the first brake decelleration curve segment
    // - std::get<2> : returns braking rate used to calculate the first brake decelleration curve segment
    auto segment_length = std::get<0>(sbd_curve_change_points.back()) - U().current_train_position;
    auto velocity       = std::get<1>(sbd_curve_change_points.back());
    auto braking_rate   = std::get<2>(sbd_curve_change_points.back());

    tsm_target.ato_velocity = velocity;

    // Following records the end points of the segments (start location, start velocity, EBD rate) that make up
    // the EBD curve that terminates at point (target distance, target velocity)
    std::vector<std::tuple<double, double, double>> ebd_curve_change_points = GetBrakeDecellerationCurve(
      target_distance, target_velocity, EMERGENCY_BRAKE, true);

    // Get the information about the brake curve segment that is closest to the train and use this to calculate
    // target velocities. Note that
    // - std::get<0> : returns path position where first brake decelleration curve segment ends
    // - std::get<1> : returns target velocity located at the end of the first brake decelleration curve segment
    // - std::get<2> : returns braking rate used to calculate the first brake decelleration curve segment
    segment_length = std::get<0>(ebd_curve_change_points.back()) - U().current_train_position;
    velocity       = std::get<1>(ebd_curve_change_points.back());
    braking_rate   = std::get<2>(ebd_curve_change_points.back());

    tsm_target.ebi_velocity = GetEBIVelocity(segment_length, velocity, braking_rate, true);
    tsm_target.sbi_velocity = GetEBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, sbi_time_offset, true);
    tsm_target.warning_velocity = GetEBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, warning_time_offset, true);
    tsm_target.permitted_velocity = GetEBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, permitted_time_offset, true);
    tsm_target.pre_indication_velocity = GetEBDMonitoredSpeedVelocity(
      segment_length, velocity, braking_rate, preindication_time_offset, true);
    tsm_target.indication_velocity = GetEBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, indication_time_offset, true);

    if (DEBUG_BRAKING_CURVES)
        Trace::GetLogger().STAMP(Trace::ERR) << "\n---------------------------------------------  : "
                                             << "  (" << tsm_target.pre_indication_velocity << " " << segment_length
                                             << "  " << velocity << "} " << braking_rate << "\n";

    if (DEBUG_BRAKING_CURVES)
    {
        auto tsm_target_velocity = GetEBDMonitoredSpeedVelocity(
          target_distance, target_velocity, K().ebd_rate, preindication_time_offset, true);
        Trace::GetLogger().STAMP(Trace::ERR) << "\n---------------------------------------------  : "
                                             << "  (" << tsm_target_velocity << "  "
                                             << "} " << K().ebd_rate << "\n";
    }

    // In order determine the distance to the location where TSM mode begins, first we need to get
    // the EBD curve gradient change velocity point that is nearest to the target speed that appears
    // before the target speed of interest
    auto nearest_ebd_target_speed = std::find_if(ebd_curve_change_points.begin(),
                                                 ebd_curve_change_points.end(),
                                                 [previous_target_speed](const std::tuple<double, double, double>& ebd_curve_change_point)
                                                 { return std::get<1>(ebd_curve_change_point) < previous_target_speed; });

    if (DEBUG_BRAKING_CURVES)
    {
        Trace::GetLogger().STAMP(Trace::ERR)
          << "Closest EBD curve point (" << std::get<0>(*nearest_ebd_target_speed) << ", "
          << std::get<1>(*nearest_ebd_target_speed) << ", " << std::get<2>(*nearest_ebd_target_speed) << ")  <  "
          << previous_target_speed << " \n";

        tsm_target.pre_indication_distance = GetEBDMonitoredSpeedDistance(
          previous_target_speed, target_velocity, target_distance, K().ebd_rate, preindication_time_offset, true);
        Trace::GetLogger().STAMP(Trace::ERR)
          << "TD Preindication Single segment gradient  --->  " << tsm_target.pre_indication_distance << "\n";
    }

    // Find the pre-indication distance
    if (nearest_ebd_target_speed != ebd_curve_change_points.end())
        tsm_target.pre_indication_distance = GetEBDMonitoredSpeedDistance(previous_target_speed,
                                                                          std::get<1>(*nearest_ebd_target_speed),
                                                                          target_distance,
                                                                          std::get<2>(*nearest_ebd_target_speed),
                                                                          preindication_time_offset,
                                                                          true);
    else
        tsm_target.pre_indication_distance = MAX_DISTANCE;

    if (DEBUG_BRAKING_CURVES)
    {
        Trace::GetLogger().STAMP(Trace::ERR)
          << "TD Preindication Multi segment gradient   --->  " << tsm_target.pre_indication_distance << "\n";
        Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
    }

    // Find the indication distance
    if (nearest_ebd_target_speed != ebd_curve_change_points.end())
        tsm_target.indication_distance = GetEBDMonitoredSpeedDistance(previous_target_speed,
                                                                      std::get<1>(*nearest_ebd_target_speed),
                                                                      target_distance,
                                                                      std::get<2>(*nearest_ebd_target_speed),
                                                                      indication_time_offset,
                                                                      true);
    else
        tsm_target.indication_distance = MAX_DISTANCE;

    // Set the remain TSM target data fields

    tsm_target.target_velocity = target_velocity;
    {
        // Distance travelled by the train when the train follows the permitted speed braking curve. This is
        // - the distance taken to decellerate from the current target speed to the new target speed
        // - plus the difference between the permitted speed offset associated with the current target speed
        //   and the one associated with the new target speed
        auto permitted_curve_braking_distance =
          (((std::pow(previous_target_speed, 2) - std::pow(target_velocity, 2)) / (2 * braking_rate))) +
          (((previous_target_speed * permitted_time_offset)) - ((tsm_target.target_velocity * permitted_time_offset)));

        // Distance between the trains current position and the location where the permitted braking curve intersects
        // with the previous target speed.
        auto distance_from_start_permitted_brake = (GetEBIDistance(previous_target_speed, target_velocity, target_distance, braking_rate, true) -
                                                    (previous_target_speed * permitted_time_offset));

        // Target distance should be zero at the point where the permitted speed curve reduces the train speed to the
        // new target speed.
        tsm_target.target_distance = std::max(distance_from_start_permitted_brake + permitted_curve_braking_distance, 0.0);

        // Want to set the target distance to -1 when target distance 0m is reported so that the target distance bar
        // is removed from the DMI once target speed is reached
        if (tsm_target.target_distance == 0.0)
            tsm_target.target_distance = -1.0;
    }
    tsm_target.is_eoa_target = false;

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << "TSMProfile - " << tsm_target.ToString() << Trace::EndLog();

    return tsm_target;
}

/// Calculate the monitored speed data for the end of the movement authority
///
// @param speed_profile_velocity_at_eoa Speed profile speed at the EOA location
/// @param eoa_distance Distance to the end of authority
/// @param svl_distance Distance to the supervised location
///
/// @returns the Target Speed Monitoring data for the end of movement authority
///
SpeedAndDistanceMonitoringModule::MonitoredSpeedData
SpeedAndDistanceMonitoringModule::CalculateEOATarget(double speed_profile_velocity_at_eoa, double eoa_distance, double svl_distance)
{
    // distances cannot be less than zero
    eoa_distance = std::max(eoa_distance, 0.0);
    svl_distance = std::max(svl_distance, 0.0);

    SpeedAndDistanceMonitoringModule::MonitoredSpeedData tsm_target;
    tsm_target.is_valid = true;

    // Following records the end points of the segments (start location, start velocity, EBD rate) that make up
    // the EBD curve that terminates at point (SvL distance, zero velocity)
    std::vector<std::tuple<double, double, double>> ebd_curve_change_points = GetBrakeDecellerationCurve(
      svl_distance, 0.0, EMERGENCY_BRAKE, false);

    // Get the information about the emergency brake curve segment that is closest to the train and use this to
    // calculate target velocities. Note that
    // - std::get<0> : returns path position where first brake decelleration curve segment ends
    // - std::get<1> : returns target velocity located at the end of the first brake decelleration curve segment
    // - std::get<2> : returns braking rate used to calculate the first brake decelleration curve segment
    auto segment_length = std::get<0>(ebd_curve_change_points.back()) - U().current_train_position;
    auto velocity       = std::get<1>(ebd_curve_change_points.back());
    auto braking_rate   = std::get<2>(ebd_curve_change_points.back());

    // Using gradient based EBD rate
    tsm_target.ebi_velocity = GetEBIVelocity(segment_length, velocity, braking_rate, false);

    // Following records the end points of the segments (start location, start velocity, SBD rate) that make up
    // the SBD curve that terminates at point (eoa distance, zero velocity)
    std::vector<std::tuple<double, double, double>> sbd_curve_change_points = GetBrakeDecellerationCurve(
      eoa_distance, 0, SERVICE_BRAKE, false);

    // Get the information about the service brake curve segment that is closest to the train and use this to
    // calculate target velocities. Note that
    // - std::get<0> : returns path position where first brake decelleration curve segment ends
    // - std::get<1> : returns target velocity located at the end of the first brake decelleration curve segment
    // - std::get<2> : returns braking rate used to calculate the first brake decelleration curve segment
    segment_length = std::get<0>(sbd_curve_change_points.back()) - U().current_train_position;
    velocity       = std::get<1>(sbd_curve_change_points.back());
    braking_rate   = std::get<2>(sbd_curve_change_points.back());

    // Using gradient based SBD rate
    tsm_target.ato_velocity     = velocity;
    tsm_target.sbi_velocity     = GetSBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, sbi_time_offset);
    tsm_target.warning_velocity = GetSBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, warning_time_offset);
    tsm_target.permitted_velocity = GetSBDMonitoredSpeedVelocity(segment_length, velocity, braking_rate, permitted_time_offset);
    tsm_target.pre_indication_velocity = GetSBDMonitoredSpeedVelocity(segment_length, velocity, K().sbd_rate, preindication_time_offset);
    tsm_target.indication_velocity = GetSBDMonitoredSpeedVelocity(segment_length, velocity, K().sbd_rate, indication_time_offset);

    // Get the EBD curve gradient change velocity point that is nearest to the target speed that appears before
    // the target speed of interest
    auto nearest_sbd_target_speed = std::find_if(
      sbd_curve_change_points.begin(),
      sbd_curve_change_points.end(),
      [speed_profile_velocity_at_eoa](const std::tuple<double, double, double>& sbd_curve_change_point)
      { return std::get<1>(sbd_curve_change_point) < speed_profile_velocity_at_eoa; });

    // Find the pre-indication and indication distance
    tsm_target.indication_distance     = MAX_DISTANCE;
    tsm_target.pre_indication_distance = MAX_DISTANCE;
    if (nearest_sbd_target_speed != sbd_curve_change_points.end())
    {
        tsm_target.indication_distance = GetSBDMonitoredSpeedDistance(speed_profile_velocity_at_eoa,
                                                                      std::get<1>(*nearest_sbd_target_speed),
                                                                      eoa_distance,
                                                                      std::get<2>(*nearest_sbd_target_speed),
                                                                      indication_time_offset);

        tsm_target.pre_indication_distance = GetSBDMonitoredSpeedDistance(speed_profile_velocity_at_eoa,
                                                                          std::get<1>(*nearest_sbd_target_speed),
                                                                          eoa_distance,
                                                                          std::get<2>(*nearest_sbd_target_speed),
                                                                          preindication_time_offset);
    }

    // Set the remain TSM target data fields
    tsm_target.target_distance = eoa_distance;
    //tsm_target.target_velocity = 0;
    {
        //MMRBEM-4169 : DMI curve in ATO should be same as ATP mode.
        //Get CSM profile traget & permitted speed & use in ATO mode.
        MonitoredSpeedData csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(U().speed_profile_speed_limit));
        tsm_target.target_velocity = csm_profile_data.target_velocity;

        //If end of service, then send target speed as 0.0 to show YELLOW curve
        if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATB && U().dmi_driver_event_change_ends == Project::TypeValue::ActiveInactive::ACTIVE)
            tsm_target.target_velocity = 0.0;        
    }
    tsm_target.is_eoa_target   = true;

    // Want to set the target distance to -1 when target distance 0m is reported so that the target distance bar
    // is removed from the DMI once target speed is reached
    if (tsm_target.target_distance == 0.0)
        tsm_target.target_distance = -1.0;

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO) << "EOA TSMProfile - " << tsm_target.ToString() << Trace::EndLog();

    return tsm_target;
}

/// Returns the velocity that the train would need to be traveling in order for Emergency Brake Intervention to be
/// triggered when it is located target_distance meters away from the location at which the target velocity must be
/// reached
///
/// In the case where the target speed being supplied ends at the target velocity provided by the MRSP or LOA,
/// the target velocity to be reached when the train reaches the location of the target velocity is given by the CSM
/// EBI curve of the target speed. This offfset is included in the calculations via the dv_ebi value
/// - Refer section 3.13.8.3.1, fihure 40 in the ETCS standard SUBSET-026-3 which show the EBI reference
//
/// @param target_distance      Distance of travel between the current position and position where target velocity
/// must be reached
/// @param target_velocity      Velocity train must be traveling when it reaches the position given by the target
/// distance
/// @param decelleration_rate   Brake Deceleration rate used to determine how quickly the train's speed reduces
/// @param add_csm_ebi_offset   Flag that indicates the given target velocity should be increased by dV_EBI
///
/// @returns EBI curve velocity at the current position. Train speed greater than this value to trigger EBI.
///
/// Note that a fixed Dbec value has been used to define the distance between the EBD to EBI curve
///
double SpeedAndDistanceMonitoringModule::GetEBIVelocity(double target_distance, double target_velocity, double decelleration_rate, bool add_csm_ebi_offset)
{
    double start_braking_velocity;

    // When calculating the curve that ends at the MRSP target speed an offset needs to be applied to the target
    // velocity
    // - Refer Figure 55 in the ETCS standard SUBSET-026-3 which shows the EBI curve being generated here
    if (add_csm_ebi_offset)
    {
        double dv_ebi = GetDVEBI(target_velocity, v_ebi_min, v_ebi_max, dv_ebi_min, dv_ebi_max);

        start_braking_velocity = sqrt(
          std::max((2 * decelleration_rate * (target_distance - K().dbec)) + std::pow((target_velocity + dv_ebi), 2), 0.0));
    }
    else
        start_braking_velocity = sqrt(2 * decelleration_rate * std::max((target_distance - K().dbec), 0.0) +
                                      std::pow((target_velocity), 2));

    return start_braking_velocity;
}

/// Returns the velocity that the train would need to be traveling in order for the given curve to be exceeded when
/// the train is located target_distance meters away from the location at which the target velocity must be reached.
///
/// In the case where the target speed being supplied ends at the target velocity provided by the MRSP or LOA,
/// the target velocity to be reached when the train reaches the location of the target velocity is given by the CSM
/// EBI curve of the target speed. This offset is included in the calculations via the dv_ebi value
/// - Refer section 3.13.8.3.1, figure 40 in the ETCS standard SUBSET-026-3 which show the EBI reference
///
/// This function can be used to calculate the max velocity given by the Warning, Permitted Speed, Indication
/// and preindication curves that are generated in reference to the EBD curve.
/// - Refer Figure 45 in the ETCS standard SUBSET-026-3 which show the required curves
///
/// The curve for which the velocity is being reported is determined by the supplied time_offset
/// This offset is multiplied by the train speed and thus determines how far away from the EBI curve that is to be
/// calculated is located.
///
/// @param target_distance      Distance of travel between the current position and position of the target velocity
/// @param target_velocity      Velocity train must be traveling when it reaches the position given by the target
/// distance
/// @param decelleration_rate   Brake Deceleration rate used to determine how quickly the train's speed reduces
/// @param time_offset          Offset that is multiplied by the train speed to determine the distance between the
/// curve to
///                             be calculated and the EBI curve.
/// @param add_csm_ebi_offset   Flag that indicates the given target velocity should be increased by dV_EBI
///
/// @returns Velocity returned for the calculated curve at the location which is target distance before the location
/// at
///          which the target velocity is to be reached
///
double SpeedAndDistanceMonitoringModule::GetEBDMonitoredSpeedVelocity(double target_distance,
                                                                      double target_velocity,
                                                                      double decelleration_rate,
                                                                      double time_offset,
                                                                      bool   add_csm_ebi_offset)
{
    double start_braking_velocity;

    if (add_csm_ebi_offset)
    {
        double dv_ebi = GetDVEBI(target_velocity, v_ebi_min, v_ebi_max, dv_ebi_min, dv_ebi_max);

        start_braking_velocity = decelleration_rate *
                                 (-time_offset + sqrt(std::pow(time_offset, 2) +
                                                      (4.0 / (2.0 * decelleration_rate)) *
                                                        (std::max((target_distance - K().dbec), 0.0) +
                                                         std::pow((target_velocity + dv_ebi), 2) / (2.0 * decelleration_rate))));
    }
    else
        start_braking_velocity = decelleration_rate *
                                 (-time_offset + sqrt(std::pow(time_offset, 2) +
                                                      (4.0 / (2.0 * decelleration_rate)) *
                                                        (std::max((target_distance - K().dbec), 0.0) +
                                                         std::pow(target_velocity, 2) / (2.0 * decelleration_rate))));

    return start_braking_velocity;
}

/// Returns the velocity that the train would need to be traveling in order for the given curve to be exceeded when
/// the train is located target_distance meters away from the location at which the target velocity must be reached.
///
/// This function can be used to calculate the max velocity given by the SBI1, Warning, Permitted Speed, Indication
/// and preindication curves that are generated in reference to the SBD curve.
/// - Refer Figure 46 in the ETCS standard SUBSET-026-3 which show the required curves
///
/// The curve for which the velocity is being reported is determined by the supplied time_offset
/// This offset is multiplied by the train speed and thus determines how far away from the SBD curve that the curve
/// be to be calculated is located.
///
/// @param target_distance      Distance of travel between the current position and position of the target velocity
/// @param target_velocity      Velocity train must be traveling when it reaches the position given by the target
/// distance
/// @param decelleration_rate   Brake Deceleration rate used to determine how quickly the train's speed reduces
/// @param time_offset          Offset that is multiplied by the train speed to determine the distance between the
/// curve to
///                             be calculated and the SBD curve.
///
/// @returns Velocity returned for the calculated curve at the location which is target distance before the location
/// at
///          which the target velocity is to be reached
///
double SpeedAndDistanceMonitoringModule::GetSBDMonitoredSpeedVelocity(double target_distance,
                                                                      double target_velocity,
                                                                      double decelleration_rate,
                                                                      double time_offset)
{
    double start_braking_velocity;

    start_braking_velocity = decelleration_rate *
                             (-time_offset + sqrt(std::pow(time_offset, 2) +
                                                  (4 / (2 * decelleration_rate)) *
                                                    (std::max(target_distance, 0.0) +
                                                     (std::pow(target_velocity, 2) / (2 * decelleration_rate)))));

    return start_braking_velocity;
}

/// Returns the distance the train must travel before it reaches the location where the EBI curve reports the
/// identified target velocity
///
///  @param start_velocity     Velocity the calculated EBI curve will start at
///  @param target_velocity    Velocity the calculated EBI curve will end at
///  @param target_distance    distance from trains current position to target_velocity position
///  @param decelleration_rate EBD rate with gradient corrections applied
///  @param add_csm_ebi_offset Flag that indicates the given target velocity should be increased by dV_EBI
///
/// @returns distance train must travel before reaching the start of the calculated EBI decelleration curve
///
double SpeedAndDistanceMonitoringModule::GetEBIDistance(double start_velocity,
                                                        double target_velocity,
                                                        double target_distance,
                                                        double decelleration_rate,
                                                        bool   add_csm_ebi_offset)
{
    double decelleration_distance;

    // Get the distance the train must travel in order to decellerate from the start speed to the target speed using
    // the emergency brake
    if (add_csm_ebi_offset)
    {
        double dv_ebi = GetDVEBI(target_velocity, v_ebi_min, v_ebi_max, dv_ebi_min, dv_ebi_max);

        decelleration_distance = abs((std::pow(start_velocity, 2) - std::pow((target_velocity + dv_ebi), 2)) / (2 * decelleration_rate));
    }
    else
        decelleration_distance = abs((std::pow(start_velocity, 2) - std::pow(target_velocity, 2)) / (2 * decelleration_rate));

    // Return the distance from the trains current position to the start of the EBI decelleration curve
    return target_distance - decelleration_distance - K().dbec;
}

/// Returns the distance the train must travel before it reaches the location where the curve reports the identified
/// target velocity
///
/// In this case the location of the curve being looked for is offset from the EBI curve
///
///  @param start_velocity     Velocity the calculated curve will start at
///  @param target_velocity    Velocity the calculated curve will end at
///  @param target_distance    distance to target_velocity location
///  @param decelleration_rate SBD rate with gradient corrections applied
///  @param time_offset        time offset that is specific to the curve being calculated
///  @param add_csm_ebi_offset Flag that indicates the given target velocity should be increased by dV_EBI
///
/// @returns distance train must travel before reaching the start of the calculated decelleration curve
///
double SpeedAndDistanceMonitoringModule::GetEBDMonitoredSpeedDistance(double start_velocity,
                                                                      double target_velocity,
                                                                      double target_distance,
                                                                      double decelleration_rate,
                                                                      double time_offset,
                                                                      bool   add_csm_ebi_offset)
{
    // Get the distance the train must travel before it reaches the start of the EBI decelleration curve
    auto distance_to_ebi = GetEBIDistance(start_velocity, target_velocity, target_distance, decelleration_rate, add_csm_ebi_offset);

    // Return the distance from the trains current position to the start of the decelleration curve of interest
    return std::max((distance_to_ebi - (start_velocity * time_offset)), 0.0);
}

/// Returns the distance the train must travel before it reaches the location where the curve reports the identified
/// target velocity
///
/// In this case the location of the curve being looked for is offset from the SBD curve
///
///  @param start_velocity     Velocity the calculated curve will start at
///  @param target_velocity    Velocity the calculated curve will end at
///  @param target_distance    distance to target_velocity location
///  @param decelleration_rate SBD rate with gradient corrections applied
///  @param time_offset        time offset that is specific to the curve being calculated
///
/// @returns distance train must travel before reaching the start of the calculated decelleration curve
///
double SpeedAndDistanceMonitoringModule::GetSBDMonitoredSpeedDistance(double start_velocity,
                                                                      double target_velocity,
                                                                      double target_distance,
                                                                      double decelleration_rate,
                                                                      double time_offset)
{
    // Get the distance the train must travel in order to decellerate from the start speed to the target speed using
    // the service brake
    double decelleration_distance = abs((std::pow(start_velocity, 2) - std::pow(target_velocity, 2)) / (2 * decelleration_rate));

    return std::max(target_distance - (decelleration_distance + (start_velocity * time_offset)), 0.0);
}

/// Responsible for setting the outputs of this module
///
/// @param csm_data Ceiling  Speed monitoring speed data
/// @param tsm_data Target   Speed monitoring speed data
///
void SpeedAndDistanceMonitoringModule::TargetAndModeManagement(SpeedAndDistanceMonitoringModule::MonitoredSpeedData csm_data,
                                                               SpeedAndDistanceMonitoringModule::MonitoredSpeedData tsm_data)
{
    // Return immediately if we are not in a speed and distance monitoring mode
    if (!((U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR) ||
          (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF) || (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
          (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) || (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATB) ||
          (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
          (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ROS)))
    {
        Y().ato_permitted_speed      = INVALID_SPEED;
        Y().eb_intervention_velocity = INVALID_SPEED;
        Y().sb_intervention_velocity = INVALID_SPEED;
        Y().warning_velocity         = INVALID_SPEED;
        Y().cbtc_permitted_speed     = INVALID_SPEED;
        Y().indication_speed         = INVALID_SPEED;
        Y().target_distance          = INVALID_SPEED;
        Y().cbtc_target_speed        = INVALID_SPEED;
        X().reported_speed_status    = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;
        Y().speed_status             = X().reported_speed_status;
        Y().monitoring_mode          = Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM;
        Y().speed_monitoring_active  = false;
        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::INFO)
              << "No speed and distance monitoring data is undefined for current mode: " << U().cbtc_current_mode
              << Trace::EndLog();

        return;
    }

    SpeedAndDistanceMonitoringModule::MonitoredSpeedData data;
    data.is_valid = true;

    // Set all of the different threshold velocities that are being monitored
    data.ato_velocity            = csm_data.permitted_velocity;
    data.ebi_velocity            = csm_data.ebi_velocity;
    data.sbi_velocity            = csm_data.sbi_velocity;
    data.warning_velocity        = csm_data.warning_velocity;
    data.permitted_velocity      = csm_data.permitted_velocity;
    data.indication_velocity     = csm_data.indication_velocity;
    data.pre_indication_velocity = csm_data.pre_indication_velocity;
    data.is_eoa_target           = false;

    // If there is TSM data for the next target speed, set the speed monitoring
    // speeds to be the minimum of the CSM and TSM speed monitoring values
    if (tsm_data.is_valid)
    {
        data.ato_velocity            = std::min(tsm_data.ato_velocity, csm_data.ato_velocity);
        data.ebi_velocity            = std::min(tsm_data.ebi_velocity, csm_data.ebi_velocity);
        data.sbi_velocity            = std::min(tsm_data.sbi_velocity, csm_data.sbi_velocity);
        data.warning_velocity        = std::min(tsm_data.warning_velocity, csm_data.warning_velocity);
        data.permitted_velocity      = std::min(tsm_data.permitted_velocity, csm_data.permitted_velocity);
        data.indication_velocity     = std::min(tsm_data.indication_velocity, csm_data.indication_velocity);
        data.pre_indication_velocity = std::min(tsm_data.pre_indication_velocity, csm_data.pre_indication_velocity);
        data.is_eoa_target           = tsm_data.is_eoa_target;
    }

    // Determine the monitoring mode
    Project::CBTCOnBoard::TypeValue::MonitoringMode monitoring_mode = Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM;
    if (tsm_data.is_valid && (tsm_data.target_velocity <= csm_data.target_velocity))
    {
        monitoring_mode = GetSpeedMonitoringMode(
          tsm_data.indication_distance, tsm_data.pre_indication_distance, tsm_data.target_velocity, csm_data.target_velocity);
    }

    // Based on the monitoring mode set the target speed and distance
    if ((monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::PIM) ||
        (monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::TSM))
    {
        data.pre_indication_distance = tsm_data.pre_indication_distance;
        data.indication_distance     = tsm_data.indication_distance;
        data.target_distance         = tsm_data.target_distance;
        data.target_velocity         = tsm_data.target_velocity;
    }
    else
    {
        data.pre_indication_distance = csm_data.pre_indication_distance;
        data.indication_distance     = csm_data.indication_distance;
        data.target_distance         = csm_data.target_distance;
        data.target_velocity         = csm_data.target_velocity;
    }

    // Determine the speed status that is to be reported
    X().reported_speed_status = DetermineSpeedStatus(monitoring_mode, data);

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO)
          << "Speed Monitoring Data\n--------------------- " << data.ToString()
          << "\nMonitoring Mode: " << static_cast<int>(monitoring_mode) << Trace::EndLog();

    // Set the outputs
    Y().eb_intervention_velocity = data.ebi_velocity;
    Y().sb_intervention_velocity = data.sbi_velocity;
    Y().warning_velocity         = data.warning_velocity;
    Y().cbtc_permitted_speed     = data.permitted_velocity;
    Y().indication_speed         = data.indication_velocity;
    Y().target_distance          = data.target_distance;
    Y().cbtc_target_speed        = data.target_velocity;
    Y().speed_status             = X().reported_speed_status;
    Y().monitoring_mode          = monitoring_mode;

    // In AM mode we need to calculate the permitted speed in order to feed it to the
    // train model which handles automatic driving but the onboard itself does not handle
    // the speed supervision
    if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO || U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)
        Y().speed_monitoring_active = false;
    else if (!U().ma_shortened)
        Y().speed_monitoring_active = true;

    if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP && U().psd_door_status == Project::TypeValue::PSDDoorStatus::UNKNOWN)
    {
        Y().cbtc_target_speed = INVALID_SPEED;
    }
    // Report the distance and speed info to be used for ATO driving
    // When ATO is not enabled the data being reported to it is not valid
    if (U().ato_active)
    {
        Y().ato_permitted_distance = U().stopping_point_distance;
        Y().ato_permitted_speed    = data.ato_velocity;
    }
    else
    {
        Y().ato_permitted_distance = 0.0;
        Y().ato_permitted_speed    = 0.0;
    }

    if (U().psd_door_status == Project::TypeValue::PSDDoorStatus::UNKNOWN &&
        U().train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION &&
        (Y().target_distance > DOCKING_DISTANCE_FOR_PSD_BYPASSED || Y().target_distance < 0.0))
    {
        Y().ato_permitted_speed  = PSD_BYPASSED_MAX_SPEED_ALLOWED;
        Y().cbtc_permitted_speed = PSD_BYPASSED_MAX_SPEED_ALLOWED;
        Y().cbtc_target_speed    = PSD_BYPASSED_MAX_SPEED_ALLOWED;
    }
}

/// Returns the current speed monitoring mode
///
/// @param tsm_indication_distance     TSM indication distance used to detect entry to TSM
/// @param tsm_preindication_distance  TSM preindication distance used to detect entry to PIM
///
/// @returns speed monitoring mode
///
Project::CBTCOnBoard::TypeValue::MonitoringMode
SpeedAndDistanceMonitoringModule::GetSpeedMonitoringMode(double tsm_indication_distance,
                                                         double tsm_preindication_distance,
                                                         double tsm_target_velocity,
                                                         double csm_target_velocity)
{
    if ((tsm_indication_distance <= 0) && ((tsm_target_velocity + DELTA) < csm_target_velocity))
        return Project::CBTCOnBoard::TypeValue::MonitoringMode::TSM;
    else if ((tsm_preindication_distance <= 0) && ((tsm_target_velocity + DELTA) < csm_target_velocity))
        return Project::CBTCOnBoard::TypeValue::MonitoringMode::PIM;
    else
        return Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM;
}

/// Returns the current speed supervision status
///
/// @param monitoring_mode      Current speed monitoring mode that module is in
/// @param monitoring_mode_data Current speed monitoring data
///
/// @returns current speed status
///
Project::CBTCOnBoard::TypeValue::SpeedStatus
SpeedAndDistanceMonitoringModule::DetermineSpeedStatus(Project::CBTCOnBoard::TypeValue::MonitoringMode monitoring_mode,
                                                       MonitoredSpeedData monitoring_mode_data)
{
    Project::CBTCOnBoard::TypeValue::SpeedStatus speed_status_to_report = X().reported_speed_status;

    // Initially assume that the train is travelling below the permitted speed
    Project::CBTCOnBoard::TypeValue::SpeedStatus current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;

    // Determine if the train is traveling faster than the permitted speed in Ceiling Speed Mode
    if ((monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM) ||
        (monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::PIM))
    {
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION ||
            U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_MODE_CHANGE_ON_RUN)
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.warning_velocity) ||
                 (U().service_brake_request == Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.indication_velocity))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.permitted_velocity))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED;

        // If speed status level has risen, update the reported speed status level the the new speed status level
        speed_status_to_report = GetHighestSpeedSpeedStatus(current_speed_status, X().reported_speed_status);

        // Only return the speed status back to normal or indication if the speed drops back down beneath the
        // permitted speed Note that the EB and SB status occur when the associated speed limit is exceeded and are
        // not cleared until the brake is released
        if (current_speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL)
            speed_status_to_report = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;
    }

    // Determine speed status in Target Speed Mode
    else if (monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::TSM)
    {
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION ||
            U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_MODE_CHANGE_ON_RUN)
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.warning_velocity) ||
                 (U().service_brake_request == Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.permitted_velocity))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED;
        else if (IsSpeedThresholdExceeded(monitoring_mode_data.indication_velocity))
            current_speed_status = Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION;

        // If speed status level has risen, update the reported speed status level the the new speed status level
        speed_status_to_report = GetHighestSpeedSpeedStatus(current_speed_status, X().reported_speed_status);

        // Only return the speed status back to normal or indication if the speed drops back down beneath the
        // permitted speed Note that the EBI and SBI brake states occur when the associated speed limit is exceeded
        // and are not cleared until the brake is released
        if (current_speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL)
            speed_status_to_report = Project::CBTCOnBoard::TypeValue::SpeedStatus::NORMAL;
        else if (current_speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION)
            speed_status_to_report = Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION;
    }

    return speed_status_to_report;
}

/// Return a string with the speed monitoring data
///
///
std::string SpeedAndDistanceMonitoringModule::MonitoredSpeedData::ToString() const
{
    std::stringstream output;

    output << "\nis_valid                 : " << is_valid << "\nebi_velocity             : " << ebi_velocity
           << "\nsbi_velocity             : " << sbi_velocity << "\nwarning_velocity         : " << warning_velocity
           << "\npermitted_velocity       : " << permitted_velocity << "\nindication_velocity      : " << indication_velocity
           << "\npre_indication_velocity  : " << pre_indication_velocity << "\npre_indication_distance  : " << pre_indication_distance
           << "\nindication_distance      : " << indication_distance << "\ntarget_distance          : " << target_distance
           << "\ntarget_velocity          : " << target_velocity << "\nis_eoa_target            : " << is_eoa_target;

    return output.str();
}

/// Returns the advisory speed that is to be reported to the driver
///
/// Advisory speed is calculated in CM driving mode where “advisory speed” is the minimum between :
/// - “Max functional speed authorized”, provided by Traffic Controller (Not Simulated)
/// - “skip speed” if train is skipping the station
/// - “regulation speed” calculated in function of Train Movement (Not Simulated)
///
/// If “advisory speed” is lower than the “speed order”, then the System shall be able to display
/// the “advisory speed” in the driver TDD.
///
/// @returns advisory speed, INVALID_SPEED returned if no advisory speed is being reported
///
double SpeedAndDistanceMonitoringModule::GetAdvisorySpeed()
{
    auto advisory_speed = INVALID_SPEED;
    // If skipping station in ATP mode, set Advisory Speed to the skip station speed limit
    // Default advisory is 375 meters
    
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) &&
        U().stopping_point_distance <= ADVISORY_DISTANCE && U().stopping_point_distance > DELTA)
    {
        if (U().next_driver_event_skip_station == Project::TypeValue::DriverEventStatus::ACTIVE && U().train_front_in_platform)
            advisory_speed = auto_skip_speed_limit;
        else
        {
            MonitoredSpeedData csm_profile_data;
            csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(U().speed_profile_speed_limit));
            MonitoredSpeedData tsm_profile_data;
            tsm_profile_data = GetTSMProfile(U().stopping_point_distance, U().stopping_point_distance);
            advisory_speed = std::min(csm_profile_data.indication_velocity, tsm_profile_data.sbi_velocity); // 10
                                                                                               // speed in platform
            // advisory_speed -= SSP_DELTA; // overshooting distance for ato is around 2.0
        }
    }

    // Report advisory speed is invalid if the speed is greater that the current speed limit
    if ((advisory_speed + DELTA) >= GetCeilingSpeedLimit(U().speed_profile_speed_limit) && U().stopping_point_distance >= ADVISORY_DISTANCE)
        advisory_speed = INVALID_SPEED;

    // Report advisory speed is invalid if train is docked and door authorization is available
    if (U().stopping_point_distance <= m_door_authorization_distance_limit && U().current_train_speed < MIN_ZERO_SPEED)
        advisory_speed = INVALID_SPEED;

    return advisory_speed;
}
/// Returns the warning speed that is to be reported to the driver
/// In ATP mode warning speed will be Advisory speed + 3

double SpeedAndDistanceMonitoringModule::GetWarningSpeed()
{
    auto   warning_speed  = INVALID_SPEED;
    double advisory_speed = GetAdvisorySpeed();

    MonitoredSpeedData csm_profile_data;
    csm_profile_data = GetCSMProfile(GetCeilingSpeedLimit(22.23));
    MonitoredSpeedData tsm_profile_data;
    tsm_profile_data = GetTSMProfile(U().stopping_point_distance, U().stopping_point_distance);

    auto min_tsm_csm_spd = std::min(csm_profile_data.indication_velocity, tsm_profile_data.sbi_velocity);
    
    // Uncomment below if condition if advisory distance is changed to greater than 350.0 meters
    // TSM and CSM profiles modifies the velocities when stopping point distance is less than 350.0 meters,so from 375.0 to 350.0 distance, we have to set warning speed to 83 km/h (23.06 m/s)
    /*if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP && advisory_speed > 0 && U().stopping_point_distance > 350.0 && U().stopping_point_distance < ADVISORY_DISTANCE)
        warning_speed = MAX_WARNING_SPEED;*/

    if((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) && advisory_speed > 0 && min_tsm_csm_spd >= advisory_speed + WARNING_FSB_DELTA)
        warning_speed = min_tsm_csm_spd;
    else if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) && advisory_speed > 0)
        warning_speed = advisory_speed + WARNING_FSB_DELTA;

    return warning_speed;
}

/// Determines when the train has zero speed
///
void SpeedAndDistanceMonitoringModule::PerformZeroSpeedDetection()
{
    if (U().current_train_speed < MIN_ZERO_SPEED)
        Y().zero_speed = Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN;
    else
        Y().zero_speed = Project::TypeValue::ZeroSpeedState::SPEED_ABOVE_MIN;
}

bool Project::CBTCOnBoard::SpeedAndDistanceMonitoringModule::IsSpeedThresholdExceeded(double threshold_speed) const
{
    return (std::abs(GetInputs().current_train_speed) > (threshold_speed + SPEED_DELTA));
}

void SpeedAndDistanceMonitoringModule::LogSpeedProfile()
{
    Trace::GetLogger().STAMP(Trace::ERR) << "LogSpeedProfile (" << U().current_train_position << ") "
                                         << U().speed_profile_speed_limit << "\n--------------------- ";

    for (auto speed_data : U().speed_data_profile)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "(" << speed_data.first << " " << speed_data.second << "), ";
    }

    Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
}
