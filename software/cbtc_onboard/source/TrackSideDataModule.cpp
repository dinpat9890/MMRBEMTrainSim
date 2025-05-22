///
/// @file       TrackSideDataModule.cpp
///
///             Implements the TrackSideDataModule class.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "TrackSideDataModule.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

namespace
{
    const bool DEBUG = false;
    const bool TEST  = false;

    // Currently start reporting Change of Ends and Work Zone events at a fixed distance prior to reaching the event
    // location TBD - Need to determine exact conditions for when these events to be reported
    const double REPORT_TRACK_EVENT_OFFSET       = 100.0;
    const double DELTA                           = 0.2;
    const double END_OF_PROFILE                  = -1;
    const double SKIP_STATION_LOOKAHEAD_DISTANCE = 300.0;

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

    bool IsEqual(double a, double b) { return (std::abs(a - b) <= 0.0000001); }
};

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data for the module
///
TrackSideDataModule::TrackSideDataModule(const Initialisation& init)
  : CBTCModule<TrackSideDataModule, TrackSideDataModuleIO>(init)
{

    // Record speed limit values whose units need to be converted
    X().auto_skip_speed_limit_kph = KmPerHrToMPerSec(K().auto_skip_speed_limit);

    // Initialise state data, if required
    X().skip_station_speed_profile_location = INVALID_DISTANCE;
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step The amount of time to since the module was last run
///
void TrackSideDataModule::Step(double time_step)
{
    // Perform actions associated with processing trackside data
    ProcessMovementAuthorityData();
    ProcessGradientProfileData();
    ProcessSpeedProfileData();
    ProcessTrackEventList();

    // Need to manage the reporting of track events
    ManageTrackEvents();

    // If we have an existing speed profile we need to update the profile so that we removed
    // profile points that appear behind the trains new position
    UpdateTracksideData();

    // If we are currently ignoring or skipping the next stopping point, report EOA distance
    // otherwise its the minimum of the EOA and Stopping Point distances
    if (IgnoreNextStoppingPoint())
        Y().stopping_distance = X().eoa_distance;
    else
        Y().stopping_distance = std::min(X().stopping_distance, X().eoa_distance);

    // Reduce the MA to the front of the train if the
    // - train doors are open and no interlock bypass while train at standstill
    // - train is being held
    // - Radio communications is lost
    Y().ma_shortened = false;
    if (((U().train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::NO_INTERLOCK) &&
         (U().no_door_enable_bypass == Project::TypeValue::NoDoorInterlockBypass::NO_BYPASS) &&
         (U().zero_speed == Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN)) ||
        (U().platform_status == Project::TypeValue::PlatformStatus::HOLD) ||
        (U().radio_communication_state == Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED))
    {
        X().eoa_distance = 0.0;
        X().svl_distance = 0.0;
        Y().ma_shortened = true;
    }

    // Set the trackside outputs
    Y().speed_data_profile    = X().speed_data_profile;
    Y().path_gradient_profile = X().path_gradient_profile;
    Y().eoa_distance          = X().eoa_distance;
    Y().svl_distance          = X().svl_distance;

    // Set State info for next loop
    X().previous_train_position = U().current_train_position;
}

/// Generates a gradient profile from the gradient profile packet data
///
void TrackSideDataModule::ProcessGradientProfileData()
{
    // Return immediately since nothing to do if data has not been updated
    if ((X().gradient_reference_position == U().gradient_profile_data.reference_train_position()) &&
        !X().path_gradient_profile.empty() && (X().previous_train_position != U().current_train_position))
        return;

    // Clear the old gradient profile
    X().path_gradient_profile.clear();

    // Now that existing data has been cleared there is nothing more to do if trackside data is invalid
    if (!U().gradient_profile_data.has_reference_train_position())
        return;

    /// TBD - return immediately if we loose radio communications.

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR)
          << "\nTrack defined gradient: " << U().speed_data_profile.reference_train_position() << "\n";

    /// Absolute path position where the gradient profile starts
    auto train_path_position = U().gradient_profile_data.reference_train_position();

    // Process the gradient profile packet if it is valid
    if (!U().gradient_profile_data.gradient_profile().empty())
    {
        // Process each of the gradient profile points
        for (const auto& gradient_profile : U().gradient_profile_data.gradient_profile())
        {
            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << "(" << train_path_position << ", " << gradient_profile.gradient() << ")   ";

            // Record the trackside gradient profile in terms of the absolute path
            X().path_gradient_profile.push_back(std::pair<double, double>(train_path_position, gradient_profile.gradient()));
            train_path_position += gradient_profile.distance();
        }
    }
    else
        // Insert a zero gradient if not gradient information is available
        X().path_gradient_profile.push_back(std::pair<double, double>(train_path_position, 0.0));

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();

    X().gradient_reference_position = U().gradient_profile_data.reference_train_position();

    // Following profile can be used for test purposes
    // Test data is based on Subset-026, section 3.13.4.1, figure 35
    if (TEST)
    {
        X().path_gradient_profile.clear();
        X().path_gradient_profile.push_back(std::pair<double, double>(0.0, 0.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(10.0, -9.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(100.0, -18.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(150.0, -8.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(160.0, -6.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(200.0, 7.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(370.0, 12.0));
        X().path_gradient_profile.push_back(std::pair<double, double>(450.0, 0.0));
    }
}

/// Generates a static speed profile from the static speed profile packet data
/// and insert any additional speed restrictions
///
void TrackSideDataModule::ProcessSpeedProfileData()
{
    // Speed profile data has not changed so no need to process it again
    if ((X().speed_reference_position == U().speed_data_profile.reference_train_position()) &&
        !X().speed_data_profile.empty() && (X().previous_train_position != U().current_train_position))
    {
        return;
    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR)
          << "\n ==================> " << (X().speed_reference_position == U().speed_data_profile.reference_train_position())
          << "  " << !X().speed_data_profile.empty() << "\n  "
          << "  " << (X().previous_train_position != U().current_train_position) << " : " << X().previous_train_position
          << "   " << U().current_train_position << "\n"
          << Trace::EndLog();

    // Clear the old speed profile data
    X().speed_data_profile.clear();

    // Now that existing data has been cleared there is nothing more to do if trackside data is invalid or
    // train is in the wrong mode
    if (!U().speed_data_profile.has_reference_train_position() ||
        ((U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATP) && (U().mode_selector_position != Project::TypeValue::ModeSelector::ATO) &&
         (U().cbtc_current_mode != Project::TypeValue::CBTCMode::UTO)))
    {
        Y().speed_profile_speed_limit = INVALID_SPEED;
        return;
    }

    /// TBD - return immediately if we loose radio communications.

    Y().speed_profile_speed_limit = U().speed_data_profile.current_speed_limit();

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR)
          << "\nTrack defined Speed Data (" << U().speed_data_profile.speed_limits().size()
          << "): " << U().speed_data_profile.reference_train_position() << " - " << Y().speed_profile_speed_limit << "\n ";

    // Convert the distances into absolute path distances
    if (U().speed_data_profile.speed_limits().size() > 0)
    {
        auto reference_position = U().speed_data_profile.reference_train_position();

        // Process each of the speed profile points
        for (auto& speed_profile : U().speed_data_profile.speed_limits())
        {
            // Create next trackside speed profile record
            auto                      speed         = speed_profile.speed();
            auto                      path_location = reference_position + speed_profile.distance();
            std::pair<double, double> next_profile(path_location, speed);

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR)
                  << "(" << path_location << ") - (" << speed_profile.distance() << ", " << speed << ")\n ";

            X().speed_data_profile.push_back(next_profile);
        }
    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();

    X().speed_reference_position            = U().speed_data_profile.reference_train_position();
    X().skip_station_speed_profile_location = INVALID_DISTANCE;
}

/// Generates a movement authority data from the movement authority packet data
///
void TrackSideDataModule::ProcessMovementAuthorityData()
{
    /// TBD - Report Invalid Data if we loose radio communications.

    // Nothing to do if data is not defined
    if (!U().movement_authority_data.has_reference_train_position())
    {
        X().eoa_distance      = Project::CBTCOnBoard::INVALID_DISTANCE;
        X().svl_distance      = Project::CBTCOnBoard::INVALID_DISTANCE;
        X().stopping_distance = Project::CBTCOnBoard::INVALID_DISTANCE;

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::WARN) << "Movement Authority Data - No reference train position" << Trace::EndLog();
        }

        return;
    }

    // Determine remaining EOA and SvL movement authority distances
    double eoa_distance = U().movement_authority_data.eoa_distance();
    X().eoa_distance    = 0.0;
    if (eoa_distance != 0.0)
        X().eoa_distance = eoa_distance - (U().current_train_position - U().movement_authority_data.reference_train_position());

    double svl_distance = U().movement_authority_data.svl_distance();
    X().svl_distance    = 0.0;
    if (svl_distance != 0.0)
        X().svl_distance = svl_distance - (U().current_train_position - U().movement_authority_data.reference_train_position());

    // Determine remaining distance to station stopping point
    double stopping_distance = U().movement_authority_data.stopping_distance();
    X().stopping_distance    = 0.0;
    if (stopping_distance != 0.0)
        X().stopping_distance = stopping_distance -
                                (U().current_train_position - U().movement_authority_data.reference_train_position());

    // Set the final stopping distance based on the state of ato position error
    if (U().ato_position_error == Project::CBTCOnBoard::TrainTypeValues::ATOPositionError::UNDERSHOOT)
        X().stopping_distance = X().stopping_distance - K().undershoot_distance;
    else if (U().ato_position_error == Project::CBTCOnBoard::TrainTypeValues::ATOPositionError::OVERSHOOT)
        X().stopping_distance = X().stopping_distance + K().overshoot_distance;
    else
        X().stopping_distance = X().stopping_distance;

    if (DEBUG)
    {
        static int count = 0;
        count++;
        if (count % 20 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "   (eoa, svl, sd) : " << X().eoa_distance << X().svl_distance
                                                 << " " << X().stopping_distance << Trace::EndLog();
    }
}

/// Reports whether or not the next stopping point is to be ignored
///
/// @returns true if the next stopping point is to be ignored
///
bool TrackSideDataModule::IgnoreNextStoppingPoint()
{
    // In ATO mode we need to determine if the next stopping point is to be ignored
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO || U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
        U().ato_is_available)
    {
        // We want to start ignoring the next stopping point if ATO was disabled due to the train stopping
        // at or beyond a stopping point or if a stopping point is being skipped
        // - Train is located at or has overshot stopping point.
        // - ATO is not currently active
        // OR
        // - skipping the station
        // Important note : a negative distance will be reported when the train overshoots a stopping
        // point in order to report how far the train overshoot a stopping point. In this case the stopping
        // point should be ignored until the next stopping point on the track ahead of the train is reported.
        // This is required so that the ATO does not receive a new stopping point distance when overshooting a
        // stopping point
        if (((X().stopping_distance < 1.0) && (U().ato_driving_state != Project::TypeValue::ATOState::AM_ATO_ENABLED)) ||
            X().skipping_station)
        {
            X().ignore_next_stopping_point = true;
        }

        // We stop ignoring the stopping point distance only once the distance to the next stopping point
        // starts to be reported to the onboard system
        if ((X().ignore_next_stopping_point && X().stopping_distance > 5.0) && !X().skipping_station)
        {
            X().ignore_next_stopping_point = false;
        }
    }
    else
        X().ignore_next_stopping_point = false;

    return X().ignore_next_stopping_point;
}

/// Performs the actions required to process the track event list data
//
/// Distance defined as the absolute path distance rather than the offset from reference position
///
void TrackSideDataModule::ProcessTrackEventList()
{
    // Return immediately since nothing to do if data has not been updated
    if ((X().track_event_reference_position == U().track_event_data.reference_train_position()) &&
        !X().transition_track_events.empty() && (X().previous_train_position != U().current_train_position))
        return;

    // Clear the track event lists
    X().driver_track_events.clear();
    X().transition_track_events.clear();

    // Now that existing data has been cleared there is nothing more to do if trackside data is invalid
    if (!U().track_event_data.has_reference_train_position() && !X().transition_track_events.empty())
        return;

    /// TBD - return immediately if we loose radio communications.

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << "\nTrack Events: " << U().track_event_data.reference_train_position() << "\n ";

    // Process the track event list if it is present and record each of the track events
    for (auto& track_event : U().track_event_data.track_event_list())
    {
        // Create next trackside data event record where location identifies the absolute path position of a given event
        double event_location = U().track_event_data.reference_train_position() + track_event.distance();
        std::pair<double, CBTC::Protos::TrackEventList::TrackEvent> next_track_event(event_location, track_event);

        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::ERR) << "(" << event_location << ", " << track_event.event() << ")   ";

        if ((track_event.event() == CBTC::Protos::TrackEventType::ENTER_AUTOMATIC) ||
            (track_event.event() == CBTC::Protos::TrackEventType::EXIT_AUTOMATIC))
            X().transition_track_events.push_back(next_track_event);
        else
            X().driver_track_events.push_back(next_track_event);
    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();

    X().track_event_reference_position = U().track_event_data.reference_train_position();
}

/// Manages the track event list data and reports it as required
///
void TrackSideDataModule::ManageTrackEvents()
{
    Y().dmi_driver_event_skip_station = Project::TypeValue::DriverEventStatus::INACTIVE;
    Y().dmi_driver_event_change_ends  = Project::TypeValue::DriverEventStatus::INACTIVE;
    Y().dmi_driver_event_work_zone    = Project::TypeValue::DriverEventStatus::INACTIVE;
    Y().transition_into_automatic     = false;
    // Y().transition_into_semi_automatic = false;

    // Determine if train is either entering or exiting the automatic region
    if (!X().transition_track_events.empty())
    {
        auto  next_track_event_location = X().transition_track_events.front().first;
        auto& next_track_event          = X().transition_track_events.front().second;

        // Train within a transition area will be flagged as either entering or exiting the automatic region
        // Note : The next_track_event_location will equal the current train position when the train is
        //        located inside the transition area
        if ((next_track_event.event() == CBTC::Protos::TrackEventType::ENTER_AUTOMATIC) &&
            (next_track_event_location <= U().current_train_position + DELTA))
        {
            Y().transition_into_automatic = true;
        }
        /* else if ((next_track_event.event() == CBTC::Protos::TrackEventType::EXIT_AUTOMATIC) &&
                  (next_track_event_location <= U().current_train_position + DELTA))
         {
             Y().transition_into_semi_automatic = true;
         }*/
    }
    else if (U().atp_zone_region == Project::TypeValue::ATPZoneStatus::OTHERWISE)
    {
        Y().transition_into_automatic = true;
    }

    X().skipping_station = false;

    // Determine what driver events, if any, should be reported by the DMI
    for (auto& driver_track_event : X().driver_track_events)
    {
        auto  next_track_event_location = driver_track_event.first;
        auto& next_track_event          = driver_track_event.second;
        auto  dist_to_next_track_event  = (next_track_event_location - U().current_train_position);

        switch (next_track_event.event())
        {
        // Report skip station when train is within the platform region of the station to be skipped and
        // Driving mode is AM or CM
        case CBTC::Protos::TrackEventType::SKIP:
            // Handle the case where the next stopping point is to be skipped
            if (dist_to_next_track_event < SKIP_STATION_LOOKAHEAD_DISTANCE)
            {
                // If in AM mode and skip speed not already added, add a skip station speed limit for the station being
                // skipped at the appropriate position within the speed profile
                if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO ||
                     U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) &&
                    (X().skip_station_speed_profile_location < 0))
                {
                    for (auto speed_profile = X().speed_data_profile.begin(); speed_profile != X().speed_data_profile.end();
                         speed_profile++)
                    {
                        auto skip_speed_limit_position = (next_track_event_location - K().auto_skip_distance);
                        if (speed_profile->first > skip_speed_limit_position)
                        {
                            auto skip_speed_limit = std::pair<double, double>(skip_speed_limit_position, X().auto_skip_speed_limit_kph);
                            X().speed_data_profile.emplace(speed_profile, skip_speed_limit);
                            X().skip_station_speed_profile_location = skip_speed_limit_position;
                            break;
                        }
                    }
                }

                // Flags when the next stopping point is being skipped
                X().skipping_station = true;

                if (DEBUG)
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE)
                      << __FUNCTIONW__ << "\n SKIP dist_to_next_track_event:" << dist_to_next_track_event
                      << "\n X().stopping_distance:" << X().stopping_distance << "\n K().overshoot_distance:" << K().overshoot_distance
                      << "\n K().auto_skip_distance:" << K().auto_skip_distance << Trace::EndLog();
                }
            }

            if (X().skipping_station && (U().train_front_near_platform || (dist_to_next_track_event < K().auto_skip_distance)) &&
                ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
                 (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
                 (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP)))
            {
                Y().dmi_driver_event_skip_station = Project::TypeValue::DriverEventStatus::ACTIVE;
            }
            break;

        // Report when train is approaching the change over stopping point when in ATP mode or in ATO mode as
        // precondition for ATB mode
        case CBTC::Protos::TrackEventType::CHANGE_OF_ENDS:
            if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP ||
                U().mode_selector_position == Project::TypeValue::ModeSelector::ATO)
                next_track_event_location -= REPORT_TRACK_EVENT_OFFSET;
            if (next_track_event_location <= U().current_train_position)
            {
                if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP ||
                    U().mode_selector_position == Project::TypeValue::ModeSelector::ATO ||
                    U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)
                    Y().dmi_driver_event_change_ends = Project::TypeValue::DriverEventStatus::ACTIVE;
            }
            break;

        // In CM and AM modes, report when train is approaching and inside a work zone area
        // Note : The next_track_event_location will equal the current train position when
        //        the train is inside of the work zone area
        case CBTC::Protos::TrackEventType::WORK_ZONE:
            if (((next_track_event_location - K().work_zone_alarm_distance) <= U().current_train_position) &&
                  (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO))
                Y().dmi_driver_event_work_zone = Project::TypeValue::DriverEventStatus::ACTIVE;
            break;

        default: break;
        }
    }

    // Erase the skip speed limit if the stopping point is no longer being skipped
    // NOTE: In debugging I haven't seen this code ever hit.
    // I believe that since ProcessSpeedProfileData() clears the speed_profile_data each frame,
    // then if skipping_station=false, skip_station_speed_profile_location will always be INVALID_DISTANCE,
    // so this code will never be hit.
    // The skip station doesn't need to be removed from the profile because the profile is cleared each frame,
    // and the skip is inserted into the profile each frame when appropriate.
    // This code must be a hangover from somewhere, but I'm reticent to remove in case something I don't know about is
    // using it.
    if (!X().skipping_station && (X().skip_station_speed_profile_location > 0))
    {
        for (auto speed_profile = X().speed_data_profile.begin(); speed_profile != X().speed_data_profile.end(); speed_profile++)
        {
            if (IsEqual(speed_profile->first, X().skip_station_speed_profile_location))
            {
                X().speed_data_profile.erase(speed_profile);
                break;
            }
        }

        X().skip_station_speed_profile_location = INVALID_DISTANCE;
    }
}

///  Removes any points that the train has moved past in the speed profile as the front of the train changes
///  location.
///
/// Need to Updates the distances in the speed profile since the first speed profile distance is given
/// in reference to the trains current position.
///
void TrackSideDataModule::UpdateTracksideData()
{
    // We need to delete any speed profile points that the train has moved past since the speed and distance monitoring
    // module requires the cuurent speed limit to be recorded in speed_profile_speed_limit and the first speed limit in
    // the speed profile to appear on the track ahead of the train
    if (X().speed_data_profile.size() > 0)
    {
        auto distance_to_speed_change = X().speed_data_profile[0].first - U().current_train_position;

        // If train has moved past the next speed change location, remove it from our list and update
        // the current train speed limit
        while ((X().speed_data_profile.size() > 0) && ((distance_to_speed_change + DELTA) < 0))
        {
            Y().speed_profile_speed_limit = X().speed_data_profile.begin()->second;

            X().speed_data_profile.erase(X().speed_data_profile.begin());
            if (X().speed_data_profile.size() > 0)
                distance_to_speed_change = X().speed_data_profile[0].first - U().current_train_position;
        }
    }

    if (X().path_gradient_profile.size() > 0)
    {
        // The first entry in the profile identifies the gradient that appears at the train's current position.
        // Need to update the location recorded in the first gradient profile point.
        X().path_gradient_profile[0].first = U().current_train_position;

        auto distance_to_gradient_change = X().path_gradient_profile[0].first - U().current_train_position;

        // The first entry in the profile identifies the gradient that appears at the train's current position.
        // If a second gradient profile point appears behind the train then the first of these needs to be deleted
        // and the location where the second one starts needs to be set to the train's current position
        while ((X().path_gradient_profile.size() > 1) &&
               ((X().path_gradient_profile[1].first - U().current_train_position + DELTA) < 0))
        {
            X().path_gradient_profile.erase(X().path_gradient_profile.begin());
            X().path_gradient_profile[0].first = U().current_train_position;
        }
    }

    if (X().driver_track_events.size() > 0)
    {
        auto distance_to_driver_event = X().driver_track_events[0].first - U().current_train_position;

        // If train has moved past the next driver track location, remove it from our list
        while ((X().driver_track_events.size() > 0) && ((distance_to_driver_event + DELTA) < 0))
        {
            X().driver_track_events.erase(X().driver_track_events.begin());
            if (X().driver_track_events.size() > 0)
                distance_to_driver_event = X().driver_track_events[0].first - U().current_train_position;
        }
    }

    if (X().transition_track_events.size() > 0)
    {
        auto distance_to_transition_event = X().transition_track_events[0].first - U().current_train_position;

        // If train has moved past the next gradient change location, remove it from our list and update the
        // distance to the next gradient change location
        while ((X().transition_track_events.size() > 0) && ((distance_to_transition_event + DELTA) < 0))
        {
            X().transition_track_events.erase(X().transition_track_events.begin());
            if (X().transition_track_events.size() > 0)
                distance_to_transition_event = X().transition_track_events[0].first - U().current_train_position;
        }
    }
}
