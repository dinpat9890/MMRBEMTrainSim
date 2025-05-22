///
/// @file       CBTCOnBoardUnit.cpp
///
///             Main unit of the CBTC Onboard system which controls the systems runcycle.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#include "CBTCOnBoardUnit.h"

namespace
{
    const double UPDATE_FREQUENCY = 20.0;
}

using namespace Project::CBTCOnBoard;

/// Constructor
///
/// @param gateway          The comms gateway
/// @param properties       Unit configuration data
/// @param train_id         Identifies the train in which the unit appears
///
CBTCOnBoardUnit::CBTCOnBoardUnit(Comms::Gateway& gateway, CBTCOnBoardProperties& properties, int train_id, unsigned long date_time)
  : Comms::SteppingUnit(gateway), m_train_id(train_id)
{
    // Read data from configuration files and populate the initialisation data
    OnBoardController::Initialisation onboard_controller_init;
    onboard_controller_init.train_position_uncertainty               = properties.GetTrainPositionUncertainty();
    onboard_controller_init.dbec                                     = properties.GetDbec();
    onboard_controller_init.ebd_rate                                 = properties.GetEBD();
    onboard_controller_init.sbd_rate                                 = properties.GetSBD();
    onboard_controller_init.ato_brake_demand_rate                    = properties.Get_ATO_Brake_Demand();
    onboard_controller_init.t_indication                             = properties.GetTIndication();
    onboard_controller_init.t_service_brake                          = properties.GetTServiceBrake();
    onboard_controller_init.auto_region_speed_limit                  = properties.GetAutoSpeedLimit();
    onboard_controller_init.rmf_speed_limit                          = properties.GetRMFSpeedLimit();
    onboard_controller_init.rmr_speed_limit                          = properties.GetRMRSpeedLimit();
    onboard_controller_init.ros_speed_limit                          = properties.GetROSSpeedLimit();
    onboard_controller_init.auto_skip_speed_limit                    = properties.GetAutoSkipSpeedLimit();
    onboard_controller_init.auto_skip_distance                       = properties.GetAutoSkipDistance();
    onboard_controller_init.memorised_localisation_speed_limit       = properties.GetMemorisedLocalisationSpeedLimit();
    onboard_controller_init.memorised_localisation_validity_distance = properties.GetMemorisedLocalisationValidityDistance();
    onboard_controller_init.max_rollback_distance                    = properties.GetRollbackDistance();
    onboard_controller_init.max_reversing_zone                       = properties.GetMaxReverseZone();
    onboard_controller_init.long_docking_distance                    = properties.GetLongDockingDistance();
    onboard_controller_init.overshoot_distance                       = properties.GetOvershootDistance();
    onboard_controller_init.undershoot_distance                      = properties.GetUndershootDistance();
    onboard_controller_init.work_zone_alarm_distance                 = properties.GetWorkZoneAlarmDistance();
    onboard_controller_init.train_length                             = properties.GetTrainLength();
    onboard_controller_init.fsb_enabled                              = properties.GetFSBEnabled();
    onboard_controller_init.fsb_speed_limit                          = properties.GetFSBSpeedLimit();

    onboard_controller_init.dv_ebi_min     = properties.GetMinEBIDv();
    onboard_controller_init.dv_ebi_max     = properties.GetMaxEBIDv();
    onboard_controller_init.v_ebi_min      = properties.GetMinEBIVelocity();
    onboard_controller_init.v_ebi_max      = properties.GetMaxEBIVelocity();
    onboard_controller_init.dv_sbi_min     = properties.GetMinSBIDv();
    onboard_controller_init.dv_sbi_max     = properties.GetMaxSBIDv();
    onboard_controller_init.v_sbi_min      = properties.GetMinSBIVelocity();
    onboard_controller_init.v_sbi_max      = properties.GetMaxSBIVelocity();
    onboard_controller_init.dv_warning_min = properties.GetMinWarningDv();
    onboard_controller_init.dv_warning_max = properties.GetMaxWarningDv();
    onboard_controller_init.v_warning_min  = properties.GetMinWarningVelocity();
    onboard_controller_init.v_warning_max  = properties.GetMaxWarningVelocity();
    onboard_controller_init.t_warning      = properties.GetWarningTime();
    onboard_controller_init.t_driver       = properties.GetDriverTime();
    onboard_controller_init.t_preindiction = properties.GetPreindicationTime();

    onboard_controller_init.session_start_time = date_time;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "CBTCOnBoardUnit - Started " << Trace::EndLog();

    // Start the On Board System controller
    m_external_intefaces = std::unique_ptr<CommsInterface>(
      new CommsInterface(gateway, properties, train_id, properties.GetCBTCActiveVehicleIndex()));
    m_on_board_controller = std::unique_ptr<OnBoardController>(
      new OnBoardController(onboard_controller_init, *m_external_intefaces, *m_external_intefaces, *m_external_intefaces));

    // Register the Comms interface
    // - Note that this is done in this way since we will need to move this into the initialise session function
    //   when snapshotting is implemented
    m_external_intefaces->RegisterWithComms();
}

/// @return A name for this Unit
///
std::string CBTCOnBoardUnit::GetName() const
{
    return "CBTC OnBoard Unit";
}

/// This is where we call the run cyle of the OnBoard system controller. This controller then looks after
/// getting the input data from COMMS, running the run cycle of each CBTC functional module, passing
/// data between these modules and reporting the outputs that are generated by the CBTC OnBoard System.
///
/// @param new_time The time that this cycle corresponds to.
///
void CBTCOnBoardUnit::Step(double new_time)
{
    // We need a lock to access the root object
    OS::Lock<Comms::Gateway> lock(GetGateway());

    // Ensure that the unit has completed initialisation before running the next run cycle
    if (!m_external_intefaces->IsCommsInitialisationComplete())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "CBTCOnBoardUnit - Unit is Missing all required objects" << Trace::EndLog();
        return;
    }

    // Run the next execution cycle
    m_on_board_controller->RunCycle(new_time);

    m_external_intefaces->SendUpdates(new_time);
}

/// Gets the next period to wait before calling RunCycle().
///
/// @return The period for the model cycles.
///
double CBTCOnBoardUnit::GetPeriod() const
{
    return 1.0 / UPDATE_FREQUENCY;
}
