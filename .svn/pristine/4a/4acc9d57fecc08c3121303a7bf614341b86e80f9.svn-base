///
/// @file       ModeTransitionModule.cpp
///
///             Implements the ModeTransition Module class.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "ModeTransitionModule.h"

#include "IMode.h"

#include "common/StandardLogging.h"

// Mode Transition Machine
#include "ModeTransitionMachine.h"

using namespace Project::CBTCOnBoard;

namespace
{
    const double STANDSTILL = 0.1; // mps
    const bool   DEBUG      = false;
}

/// Constructor, which just initializes the members appropriately
ModeTransitionModule::ModeTransitionModule(const Initialisation& init)
  : CBTCModule<ModeTransitionModule, ModeTransitionIO>(init)
{
    // Set the default start mode to NO POWER mode
    SetCurrentMode(Project::TypeValue::CBTCMode::NO_MODE);

    // Initialise state data, if required
}

/// Finalizes an instance of the <see cref="ModeTransitionModule"/> class.
ModeTransitionModule::~ModeTransitionModule()
{
    m_imode.release();
}

/// The module function which, given the current outputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step The amount of time to since the module was last run
void ModeTransitionModule::Step(double time_step)
{
    DetermineAvailableDrivingModes();

    // Execute the mode transition machine
    m_imode->Execute();

    // Report the current Onboard system mode
    Y().cbtc_current_mode = X().cbtc_current_mode;

    // Update the current driving mode based upon selected driving mode
    if (X().cbtc_current_mode != Project::TypeValue::CBTCMode::ATC_BYPASS)
    {
        Y().atc_bypass_state = Project::TypeValue::ATCBypassState::NO_BYPASS;

        // Set the (output) "current_driving_mode" based upon what the
        // (input) "selected_driving_mode" (OFF/RMF/RMR/ATP/ATO) and "cbtc_current_mode" (OFF/RMF/RMR/ATP/ATO) are.
        // This controls the active DMI screen & selections

        if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATP)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::ATP;

        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATO || U().mode_selector_position == Project::TypeValue::ModeSelector::ATO)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::ATO;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::UTO)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::UTO;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATB)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::ATB;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMF)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::RMF;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMR)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::RMR;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ROS)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::ROS;
        else // Project::TypeValue::DriverModeSelection::OFF
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::NO_MODE;
    }

    // When mode is ATC bypass need to report the bypass is active and the currently selected
    // driver switch position. Note that the only valid drive mode with ATC bypass active are
    // RMF and RMR
    else
    {
        Y().atc_bypass_state = Project::TypeValue::ATCBypassState::BYPASS_ENABLED;

        if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMF)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::RMF;
        else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMR)
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::RMR;
        else
            Y().current_driving_mode = Project::TypeValue::CurrentDrivingMode::NO_MODE;
    }
}

/// The module function which, sets the current mode and
/// update the pointer to the mode class
///
/// @param mode mode at which onboard needs to be set
void ModeTransitionModule::SetCurrentMode(int mode)
{
    {
        X().cbtc_current_mode = mode;

        switch (X().cbtc_current_mode)
        {
        case Project::TypeValue::CBTCMode::ATP: m_imode.reset(new ATP(*this)); break;
        case Project::TypeValue::CBTCMode::ATO: m_imode.reset(new ATO(*this)); break;
        case Project::TypeValue::CBTCMode::RMF: m_imode.reset(new RMF(*this)); break;
        case Project::TypeValue::CBTCMode::RMR: m_imode.reset(new RMR(*this)); break;
        case Project::TypeValue::CBTCMode::ROS: m_imode.reset(new ROS(*this)); break;
        case Project::TypeValue::CBTCMode::ATB: m_imode.reset(new ATB(*this)); break;
        case Project::TypeValue::CBTCMode::UTO: m_imode.reset(new UTO(*this)); break;
        case Project::TypeValue::CBTCMode::ATC_BYPASS: m_imode.reset(new ATPBypass(*this)); break;

        case Project::TypeValue::CBTCMode::NO_MODE:
            // Fallthru
        default: m_imode.reset(new NoMode(*this));
        }
    }
}

/// Gets the state of the CBTC current mode.
double ModeTransitionModule::GetSelectedDrivingMode()
{
    return U().selected_driving_mode;
}

/// Gets the state of the current driving mode.
double ModeTransitionModule::GetCBTCCurrentDrivingModeState()
{
    return X().cbtc_current_mode;
}

bool ModeTransitionModule::IsTrainStandstill()
{
    return (std::abs(U().current_train_speed) < STANDSTILL);
}

/// Determines whether cab is active
///
/// @return true if cab is active; otherwise, false.
bool ModeTransitionModule::IsCabActive()
{
    return (U().cab_activate == Project::TypeValue::CabinActivation::ACTIVE);
}

/// Determines whether CBTC is powered on
///
/// @return true if CBTC powered on; otherwise, false.
bool ModeTransitionModule::IsCBTCPoweredOn()
{
    return (U().power_supply == Project::TypeValue::PowerSupply::POWER_ON);
}

/// Determines whether ATP bypass enabled
///
/// @return true if ATP bypass enabled; otherwise, false.
bool ModeTransitionModule::IsATPBypassOn()
{
    return (U().atc_bypass_switch == Project::TypeValue::ATCBypassState::BYPASS_ENABLED);
}

/// Determines whether CBTC System startup has completed
///
/// @return true if CBTC System startup completed; otherwise, false.
bool ModeTransitionModule::IsCBTCSystemStartupComplete()
{
    return U().system_startup_complete;
}

/// Determines whether TBC is in Coast
///
/// @return true if TBC in Coast; otherwise, false.
bool ModeTransitionModule::IsTBCFullSB()
{
    return (U().tbc_position == Project::TypeValue::TBCPosition::FULL_SB);
}

/// Determines whether ato driving has been enabled
///
/// @return true if ato driving has been enabled; otherwise, false.
bool ModeTransitionModule::IsATODrivingEnabled()
{
    return (U().ato_driving_state == Project::TypeValue::ATOState::AM_ATO_ENABLED);
}

/// Determines whether EOA is available
///
/// @return true if EOA Available; otherwise, false.
bool ModeTransitionModule::IsEoaAvailable()
{
    // Assuming EOA is always available except if radio connection is lost
    return (U().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED);
}

/// Determines whether ros driving has been enabled
///
/// @return true if ros driving has been enabled; otherwise, false.
bool ModeTransitionModule::IsROSIndicatorEnabled()
{
    return (U().ros_indicator == Project::TypeValue::IndicatorState::ON);
}

/// Determines whether ros driving has been enabled
///
/// @return true if ros driving has been enabled; otherwise, false.
bool ModeTransitionModule::IsATBEnabled()
{
    return (U().driver_change_ends == Project::TypeValue::DriverEventStatus::ACTIVE);
}

/// Determines whether uto driving has been enabled
///
/// @return true if wake up enabled; otherwise, false.
bool ModeTransitionModule::IsUTOEnabled()
{
    return (U().uto_mode_active == Project::TypeValue::UTOState::AM_UTO_ENABLED);
}

/// Determines whether currently selected mode is available
///
/// @return true if EOA Available; otherwise, false.
bool ModeTransitionModule::IsSelectedModeAvailable()
{

    // Only return true if the current driving mode is available
    auto selected_mode_iter = std::find_if(
      Y().available_driving_modes.availabledrivingmode().begin(),
      Y().available_driving_modes.availabledrivingmode().end(),
      [&](const google::protobuf::int32& available_mode)
      {
          if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATO)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_ATO_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATP)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_ATP_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATB)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_ATB_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::UTO)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_UTO_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMF)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_RMF_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::RMR)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_RMR_MODE);
          else if (U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ROS)
              return (available_mode == CBTC::Protos::AvailableModesList_DrivingMode_ROS_MODE);
          else
              return false;
      });

    return (selected_mode_iter != Y().available_driving_modes.availabledrivingmode().end());
}

/// Determines which Driving Modes are available
///
void ModeTransitionModule::DetermineAvailableDrivingModes()
{
    Y().available_driving_modes.Clear();

    static int count = 0;

    if ((U().atc_bypass_switch == Project::TypeValue::ATCBypassState::BYPASS_ENABLED) || (!U().power_up_test_completed))
        return;

    // Conditions under which ATP mode is available
    // - Train localised or has memorised localisation
    // - Radio Comms Established(Valid EOA)
    // - No PSD Unlocked while train near station
    // - No Onboard System failure
    if (((U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) ||
         (U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED)) &&
        (U().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED) &&
        // Missing Condition -  No PSD Unlocked while train near station
        (U().atc_status != Project::TypeValue::ATCStatus::WARNING))
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_ATP_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "ATP, ";
    }
    // condition underwhich ROS mode available
    // Delocalised
    // In ROS mode
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::NOT_LOCALISED ||
         U().localisation_state == Project::TypeValue::LocalisationStatus::UNAVAILABLE) &&
        U().mode_selector_position == Project::TypeValue::ModeSelector::ATP &&
        U().ros_indicator == Project::TypeValue::IndicatorState::ON)
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_ROS_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "ROS, ";
    }
    // Conditions under which ATO mode is available
    // - In Automated region
    // - Train localised
    // - Radio Comms Established
    // - No PSD Unlocked while train near station
    // - No Onboard System failure
    if ( //(U().in_automatic_region) &&
      (U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
       U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
      (U().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED) &&
      //  Missing Condition -  No PSD Unlocked while train near station
      (U().atc_status != Project::TypeValue::ATCStatus::WARNING))
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_ATO_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "ATO, ";
    }

    // Conditions under which ATB mode is available
    // - In Automated region
    // - Train localised
    // - Radio Comms Established
    // - Cumulative rollback is less than predefined safety distance
    // - No PSD Unlocked while train near station
    // - No Onboard System failure
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
         U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
         U().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED &&
         U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATO &&
         U().atc_status != Project::TypeValue::ATCStatus::WARNING &&
         U().driver_change_ends == Project::TypeValue::ActiveInactive::ACTIVE)
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_ATB_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "ATO, ";
    }

    // Conditions under which UTO mode is available
    // - In Automated region
    // - Train localised
    // - Radio Comms Established
    // - Cumulative rollback is less than predefined safety distance
    // - No PSD Unlocked while train near station
    // - No Onboard System failure
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
        U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
       (U().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED) &&
       (U().atc_status != Project::TypeValue::ATCStatus::WARNING))
    {
        Y().available_driving_modes.add_availabledrivingmode(
          CBTC::Protos::AvailableModesList_DrivingMode_UTO_MODE /*CBTC::Protos::AvailableModesList_DrivingMode_UTO_MODE*/);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "UTO, ";
    }
    // Conditions under which RMF mode is available
    // - No Onboard System failure
    if (U().atc_status != Project::TypeValue::ATCStatus::WARNING)
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_RMF_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "RMF, ";
    }

    // Conditions under which RMR mode is available
    // - Cumulative rollback is less than predefined safety distance
    // - No Onboard System failure
    if (U().atc_status != Project::TypeValue::ATCStatus::WARNING)
    {
        Y().available_driving_modes.add_availabledrivingmode(CBTC::Protos::AvailableModesList_DrivingMode_RMR_MODE);

        if (DEBUG && count % 40 == 0)
            Trace::GetLogger().STAMP(Trace::ERR) << "RMR";
    }

    if (DEBUG && count % 40 == 0)
        Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
}
