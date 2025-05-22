///
/// @file       PantographInfractionRule.cpp
///
///             Door Not Open Boarding Pass Infraction Rule
///
/// @ingroup    Mumbai Metro L2 & L7 simulator.
///
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2022
///

#include "DoorNotOpenedForBoardingPassInfractionRule.h"
#include "common/CommonExceptions.h"
#include "CreateCallback.h"
#include "fmt/format.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>
#include <cmath>

namespace
{
	const auto MOVING_SPEED = 0.1;
	const auto DOOR_OPEN_PRESSED_FOR_200MS = 0.2;
	const std::string RULE_NAME = "DNOBPASS";
	const std::string PARAMETER_DURATION = "WAIT_TIME1";
	const std::string PARAMETER_PENALTY = "DNOBPAS_P1";
}

DoorNotOpenedForBoardingPassInfraction::DoorNotOpenedForBoardingPassInfraction(
	InfractionUnit&						unit, 
	Scoring::ScoringParameterProvider& scoring_parameters)
	: InfractionRule(unit, RULE_NAME, scoring_parameters)
	, m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_PENALTY))
	, m_wait_duration(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_DURATION))
	, m_left_door_enabled(false)
	, m_right_door_enabled(false)
	, m_time_when_left_doors_are_enabled(0)
	, m_time_when_right_doors_are_enabled(0)
	, m_right_door_open_request(false)
	, m_left_door_open_request(false)
	, m_button_pushed_for_open_left_doors(false)
	, m_button_pushed_for_open_right_doors(false)

{
	///Door enable status
	Requires(
		SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
		Project::ValueName::CBTCVehicleInputs::LEFT_SIDE_DOOR_ENABLE,
		&m_number_left_side_door_enable,
		[this](const auto& value)
	{
		m_number_left_side_door_enable = value;
		LeftDoorEnableStatusChanged(m_number_left_side_door_enable);
	});
	
	Requires(
		SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
		Project::ValueName::CBTCVehicleInputs::RIGHT_SIDE_DOOR_ENABLE,
		&m_number_right_side_door_enable,
		[this](const auto& value)
	{
		m_number_right_side_door_enable = value;
		RightDoorEnableStatusChanged(m_number_right_side_door_enable);
	});

	// Door opened status
	Requires(
		SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
		Project::ValueName::CBTCVehicleOutputs::LEFT_SIDE_DOOR_OPEN_REQUEST,
		&m_number_is_left_side_door_open_request,
		[this](const auto& value)
	{
		m_number_is_left_side_door_open_request = value;
		LeftSideDoorOpenRequestChanged(m_number_is_left_side_door_open_request);
	});

	Requires(
		SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, 
		Project::ValueName::CBTCVehicleOutputs::RIGHT_SIDE_DOOR_OPEN_REQUEST,
		&m_number_is_right_side_door_open_request, 
		[this](const auto& value)
	{
		m_number_is_right_side_door_open_request = value;
		RightSideDoorOpenRequestChanged(m_number_is_right_side_door_open_request);
	});

	///Door Mode either manual or auto...
	Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DOOR_MODE, &m_number_door_mode);

	///Driver mode selection
	Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);
}

void DoorNotOpenedForBoardingPassInfraction::LeftDoorEnableStatusChanged(Sim::Number number)
{
	//get current time for left sides doors enabled called
	if (number.value > 0.5)
	{
		m_left_door_enabled = true;
		m_time_when_left_doors_are_enabled = GetCurrentTimePosition().time;

		//TODO: RSHI: Delete after all testing done
		Trace::GetLogger().STAMP(Trace::VERBOSE) << "Left Side Door Enabled called at .... : " << m_time_when_left_doors_are_enabled << Trace::EndLog();
		m_button_pushed_for_open_left_doors = false;
	}
}

void DoorNotOpenedForBoardingPassInfraction::RightDoorEnableStatusChanged(Sim::Number number)
{

	//get current time for right sides doors enabled called
	if (number.value > 0.5)
	{
		m_right_door_enabled = true;
		m_time_when_right_doors_are_enabled = GetCurrentTimePosition().time;

		//TODO: RSHI: Delete after all testing done
		Trace::GetLogger().STAMP(Trace::VERBOSE) << "Right Side Doors Enabled called at .... : " << m_time_when_right_doors_are_enabled << Trace::EndLog();
		m_button_pushed_for_open_right_doors = false;
	}
}

void DoorNotOpenedForBoardingPassInfraction::LeftSideDoorOpenRequestChanged(Sim::Number number)
{
	if (number.value > 0.5)
	{
		m_left_door_open_request = true;
		m_time_when_left_side_door_open_requested = GetCurrentTimePosition().time;

		//TODO: RSHI: Delete after all testing done
		Trace::GetLogger().STAMP(Trace::VERBOSE) << "Left Side Doors Open Request called at .... : " << m_time_when_left_side_door_open_requested << Trace::EndLog();
	}
	else
	{
		if (m_left_door_open_request && ((GetCurrentTimePosition().time - m_time_when_left_side_door_open_requested) >= DOOR_OPEN_PRESSED_FOR_200MS))
		{
			m_button_pushed_for_open_left_doors = true;
		}
		else
		{
			// can not add here this because value can be released before 5 seconds from the time of enable
			m_button_pushed_for_open_left_doors = false;
		}

		m_left_door_open_request = false;

	}
}

void DoorNotOpenedForBoardingPassInfraction::RightSideDoorOpenRequestChanged(Sim::Number number)
{
	if (number.value > 0.5)
	{
		m_right_door_open_request = true;
		m_time_when_right_side_door_open_requested = GetCurrentTimePosition().time;

		//TODO: RSHI: Delete after all testing done
		Trace::GetLogger().STAMP(Trace::VERBOSE) << "Right Side Doors Open Request called at .... : " << m_time_when_right_side_door_open_requested << Trace::EndLog();
	}
	else
	{
		if (m_right_door_open_request && ((GetCurrentTimePosition().time - m_time_when_right_side_door_open_requested) >= DOOR_OPEN_PRESSED_FOR_200MS))
		{
			m_button_pushed_for_open_right_doors = true;
		}
		else
		{
			// can not add here this because value can be released before 5 seconds from the time of enable
			m_button_pushed_for_open_right_doors = false;
		}
		m_right_door_open_request = false;
	}
}


void DoorNotOpenedForBoardingPassInfraction::RequiredAvailable()
{
	//TODO: RSHI: Delete this function, as it is added just for testing calls.
	Trace::GetLogger().STAMP(Trace::VERBOSE) << "Doors Not Opened Infraction RequiredAvailable... m_door_mode.id : " << m_number_door_mode << Trace::EndLog();
}

void DoorNotOpenedForBoardingPassInfraction::TimePositionChanged(TimePosition time_position)
{
	/***
		Algorithm:
		Door is enabled and if doors are not opened within a time of 5 sec and driving mode is "CM mode" and Door Control Mode is "Manual"
		then Record Infraction
	***/
	auto flag_for_right_door_opened_state = (m_button_pushed_for_open_right_doors || (m_right_door_open_request && (time_position.time - m_time_when_right_side_door_open_requested >= DOOR_OPEN_PRESSED_FOR_200MS))); // change to 0.2
	auto flag_for_left_door_opened_state = (m_button_pushed_for_open_left_doors || (m_left_door_open_request && (time_position.time - m_time_when_left_side_door_open_requested >= DOOR_OPEN_PRESSED_FOR_200MS))); // change to 0.2

	if ((((m_right_door_enabled && (!flag_for_right_door_opened_state) && ((time_position.time - m_time_when_right_doors_are_enabled) >= m_wait_duration)))     //check if "door is enabled" but "door is not opened" and "time" is not more than 5 sec...
		|| (m_left_door_enabled && (!flag_for_left_door_opened_state) && ((time_position.time - m_time_when_left_doors_are_enabled) >= m_wait_duration))) &&   //check if "door is enabled" but "door is not opened" and "time" is not more than 5 sec...
		(m_number_door_mode < 0.5 || (m_number_driver_mode_selection >= 1.5 && m_number_driver_mode_selection < 2.5))    //check either door mode is manual (value is 0 ) or driver mode selected is CBTC (value is 2)...
		)
	{
		Trace::GetLogger().STAMP(Trace::VERBOSE) << "Doors not opened Infraction has been recorded " << Trace::EndLog();
		RecordInfraction(m_penalty);

		// check for Right sides of doors are enabled but not yet opened... to avoid multiple calls for record...
		m_right_door_enabled = false;

		// check for Left sides of doors are enabled but not yet opened... to avoid multiple calls for record...
		m_left_door_enabled = false;
	}
}
