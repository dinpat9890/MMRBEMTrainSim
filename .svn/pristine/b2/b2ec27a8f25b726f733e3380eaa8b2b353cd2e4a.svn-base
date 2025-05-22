///
/// @file       ProjectConfig.cpp
///
///             Defines the functions that need to be modified by a project to configure
///             SessionAnalyser's functionality.
///
/// @ingroup    Core Train Sim
///
/// @author     Dijon Page
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2009
///

#include "ProjectConfig.h"

#include "SessionAnalyserProperties.h"

#include "LocomotiveTrainProperties.h"

#include <common/StandardLogging.h>
#include "SessionAnalyserUnits/InfractionUnit.h"

#include "InfractionRules/RollbackInfractionRule.h"
#include "InfractionRules/PantographOperatedInMotionInfractionRule.h"
#include "InfractionRules/EmergencyStopInfractionRule.h"
#include "InfractionRules/DeadmanEmergencyBelowRule.h"
#include "InfractionRules/DeadmanEmergencyAboveRule.h"
#include "InfractionRules/DoorOpenedCmdRemovedTooQuicklyInfractionRule.h"
#include "InfractionRules/DoorOpenedFromWrongPanelInfractionRule.h"
#include "InfractionRules/DoorNotOpenedForBoardingPassInfractionRule.h"
#include "InfractionRules/DoorOpenedCmdHeldTooLongInfractionRule.h"
#include "InfractionRules/DoorOpenedFromWrongSideInfractionRule.h"
#include "InfractionRules/AlertPeopleInfractionRule.h"
#include "InfractionRules/PassingStopReverseMarkerBoardInfractionRule.h"
#include "InfractionRules/JerkyDrivingInfractionRule.h"
#include "InfractionRules//TrainStoppedAfterStoppingPointInfractionRule.h"
#include "InfractionRules/TrainStoppedBeforeStoppingPointInfractionRule.h"
#include "InfractionRules/CBTCEBInfractionRule.h"
#include "InfractionRules/ElectricConsumptionInfractionRule.h"
#include "InfractionRules/ObstructionCollisionInfractionRule.h"
#include "InfractionRules/ElectricEfficiencyInfractionRule.h"
#include "InfractionRules/RunningTimeNotAchievedInfractionRule.h"
#include "InfractionRules/TimetableNotFollowedInfractionRule.h"

namespace
{
    const std::string ALERT_PEOPLE_INFRACTIONRULE = "AlertPeopleInfractionRule";
    const std::string CBTCEB_FORBIDDEN_DEPARTURE_INFRACTIONRULE = "CbtcEbForbiddenDepartureInfractionRule";
    const std::string CBTCEB_FORBIDDEN_DRIVINGMODE_INFRACTIONRULE = "CbtcEbForbiddenDrivingModeInfractionRule";    
    const std::string CBTCEB_OVERSPEED_INFRACTIONRULE = "CbtcEbOverSpeedInfractionRule";
    const std::string CBTCEB_REDSIGNALOVERRUN_INFRACTIONRULE = "CbtcEbRedSignalOverrunInfractionRule";    
    const std::string DEADMAN_EMERGENCY_ABOVE_RULE = "DeadmanEmergencyAboveRule";
    const std::string DEADMAN_EMERGENCY_BELOW_RULE = "DeadmanEmergencyBelowRule";
    const std::string DOOR_NOT_OPENED_FOR_BOARDING_PASSINFRACTION = "DoorNotOpenedForBoardingPassInfraction";
    const std::string DOOR_OPENEDCMD_HELD_TOO_LONG_INFRACTIONRULE = "DoorOpenedCmdHeldTooLongInfractionRule";
    const std::string DOOR_OPENEDCMD_REMOVED_TOO_QUICKLY_INFRACTIONRULE = "DoorOpenedCmdRemovedTooQuicklyInfractionRule";
    const std::string DOOR_OPENED_FROM_WRONG_PANEL_INFRACTIONRULE = "DoorOpenedFromWrongPanelInfractionRule";
    const std::string DOOR_OPENED_FROM_WRONG_SIDE_INFRACTIONRULE = "DoorOpenedFromWrongSideInfractionRule";
    const std::string ELECTRIC_CONSUMPTION_INFRACTIONRULE = "ElectricConsumptionInfractionRule";
    const std::string EMERGENCY_STOP_INFRACTIONRULE = "EmergencyStopInfractionRule";
    const std::string INCORRECT_STOPPING_LOCATION_AT_STATION_INFRACTIONRULE = "IncorrectStoppingLocationAtStationInfractionRule";
    const std::string JERKY_DRIVING_INFRACTION_RULE = "JerkyDrivingInfractionRule";
    const std::string PANTOGRAPH_OPERATED_IN_MOTION_INFRACTIONRULE = "PantographOperatedInMotionInfractionRule";
    const std::string PASSING_STOP_REVERSE_MARKER_BOARD_INFRACTIONRULE = "PassingStopReverseMarkerBoardInfractionRule";
    const std::string ROLLBACK_INFRACTIONRULE = "RollbackInfractionRule";
    const std::string TRAIN_STOPPED_AFTER_STOPPINGPOINT_INFRACTIONRULE = "TrainStoppedAfterStoppingPointInfractionRule";
    const std::string TRAIN_STOPPED_BEFORE_STOPPINGPOINT_INFRACTIONRULE = "TrainStoppedBeforeStoppingPointInfractionRule";
    const std::string OBSTRUCTION_COLLISION_INFRACTIONRULE = "ObstructionCollisionInfractionRule";
    const std::string ELECTRIC_EFFICIENCY_INFRACTIONRULE = "ElectricEfficiencyInfractionRule";
    const std::string RUNNING_TIME_NOT_ACHIEVED_INFRACTIONRULE = "RunningTimeNotAchievedInfractionRule";
    const std::string TIMETABLE_NOT_FOLLOWED_INFRACTIONRULE = "TimetableNotFollowedInfractionRule";           
}
/// Creates the correct train properties class based on the given car class. This will be changed
/// per project.
///
/// @param punit      The infraction unit that the properties will use.
/// @param prule      The infraction rule that the properties will use.
/// @param car_class  The name of the car class we need to make interpretted properties class for.
///
/// @return The train properties we decided to create.

std::unique_ptr<InterpretedTrainProperties> Project::CreateInterpretedTrainProperties(InfractionUnit *punit, InfractionRule *prule, std::string_view car_class)
{
    // Default. There must be a default! Warn in this case, because this likely isn't desired.
    Trace::GetLogger().STAMP(Trace::WARN) << "Using default train properties because no specific interpreter class was identified for car class '" << car_class << "'" << Trace::EndLog();
    return std::make_unique<LocomotiveTrainProperties>(punit, prule);
}

/// Creates the infraction rules that should run for the given car class and hub mode. We use
/// SessionAnalyserProperties to give us the desired list of infraction rules, then create them if
/// we know which classes apply to them.
///
/// @param punit      The infraction unit that the properties will use.
/// @param props      The infraction rule that the properties will use.
/// @param car_class  The name of the car class we need to make infractions for.
/// @param hub_mode   The name of the hub mode we need to make infractions for.
///
/// @return The infraction rules we decided to create. Ownership of the dynamically allocated
///         infraction rules belongs to the caller of this function.

std::vector<std::unique_ptr<InfractionRule>> Project::CreateInfractionRules(InfractionUnit *punit, const SessionAnalyserProperties &props, std::string_view car_class, std::string_view hub_mode)
{
    std::vector<std::unique_ptr<InfractionRule>> infraction_rules;

    try
    {
        const auto active_rules{props.GetActiveInfractionRules(std::string{car_class}, std::string{hub_mode})};
        infraction_rules.reserve(active_rules.size());
        for (auto &rule : active_rules)
        {
            if (rule == CBTCEB_FORBIDDEN_DEPARTURE_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<CBTCEBInfractionRule>(*punit, punit->GetParameterProvider(), "CB_FBDP", "FBDP_PNLTY", CBTCEBInfractionRule::BrakeReason::EB_TRAIN_HOLD));
            else if (rule == CBTCEB_FORBIDDEN_DRIVINGMODE_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<CBTCEBInfractionRule>(*punit, punit->GetParameterProvider(), "CB_FBDR", "FRDR_PNLTY", CBTCEBInfractionRule::BrakeReason::EB_MODE_CHANGE_ON_RUN));
            else if (rule == CBTCEB_OVERSPEED_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<CBTCEBInfractionRule>(*punit, punit->GetParameterProvider(), "CB_OSPD", "OSPD_PNLTY",  CBTCEBInfractionRule::BrakeReason::EB_OVERSPEED_INTERVENTION));
            else if (rule == CBTCEB_REDSIGNALOVERRUN_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<CBTCEBInfractionRule>(*punit, punit->GetParameterProvider(), "CB_RED", "RED_PNLTY", CBTCEBInfractionRule::BrakeReason::EB_SIGNAL_OVERRUN));
            else if (rule == DEADMAN_EMERGENCY_ABOVE_RULE)
                infraction_rules.emplace_back(std::make_unique<DeadmanEmergencyAboveRule>(*punit, punit->GetParameterProvider()));
            else if (rule == DEADMAN_EMERGENCY_BELOW_RULE)
                infraction_rules.emplace_back(std::make_unique<DeadmanEmergencyBelowRule>(*punit, punit->GetParameterProvider()));
            else if (rule == DOOR_NOT_OPENED_FOR_BOARDING_PASSINFRACTION)
                infraction_rules.emplace_back(std::make_unique<DoorNotOpenedForBoardingPassInfraction>(*punit, punit->GetParameterProvider()));
            else if (rule == DOOR_OPENEDCMD_HELD_TOO_LONG_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<DoorOpenedCmdHeldTooLongInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == DOOR_OPENEDCMD_REMOVED_TOO_QUICKLY_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<DoorOpenedCmdRemovedTooQuicklyInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == DOOR_OPENED_FROM_WRONG_PANEL_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<DoorOpenedFromWrongPanelInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == DOOR_OPENED_FROM_WRONG_SIDE_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<DoorOpenedFromWrongSideInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == ELECTRIC_CONSUMPTION_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<ElectricConsumptionInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == EMERGENCY_STOP_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<EmergencyStopInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == JERKY_DRIVING_INFRACTION_RULE)
                infraction_rules.emplace_back(std::make_unique<JerkyDrivingInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == PANTOGRAPH_OPERATED_IN_MOTION_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<PantographOperatedInMotionInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == PASSING_STOP_REVERSE_MARKER_BOARD_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<PassingStopReverseMarkerBoardInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == ROLLBACK_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<RollBackInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == TRAIN_STOPPED_AFTER_STOPPINGPOINT_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<TrainStoppedAfterStoppingPointInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == TRAIN_STOPPED_BEFORE_STOPPINGPOINT_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<TrainStoppedBeforeStoppingPointInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == OBSTRUCTION_COLLISION_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<ObstructionCollisionInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == ALERT_PEOPLE_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<AlertPeopleInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == ELECTRIC_EFFICIENCY_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<ElectricEfficiencyInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == RUNNING_TIME_NOT_ACHIEVED_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<RunningTimeNotAchievedInfractionRule>(*punit, punit->GetParameterProvider()));
            else if (rule == TIMETABLE_NOT_FOLLOWED_INFRACTIONRULE)
                infraction_rules.emplace_back(std::make_unique<TimetableNotFollowedInfractionRule>(*punit, punit->GetParameterProvider()));
        }
       
    }
    catch(CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Creating infraction rules");
        Trace::g_plog->LogException(e);
        throw;
    }

    return infraction_rules;
}
