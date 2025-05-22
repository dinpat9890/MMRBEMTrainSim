/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "DoorOpenedFromWrongPanelInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
	constexpr auto rule_name{ "DOPWRGPN" };

	namespace Parameters
	{
		constexpr auto penalty{ "DOPWRGPN_P" };
	}
}

DoorOpenedFromWrongPanelInfractionRule::DoorOpenedFromWrongPanelInfractionRule(
	InfractionUnit&                    unit,
	Scoring::ScoringParameterProvider& scoring_parameters)
	: InfractionRule(unit, rule_name, scoring_parameters),
	m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
	m_number_driver_mode_selection(0.0),
	m_number_left_door_open_pb_OpPanel1(0.0),
	m_number_right_door_open_pb_OpPanel1(0.0)
{
	///Driver mode selection
	Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);

	//Left door Pb from operating panel 1
	Requires(
		SimPropertyWatcher::Group::VEHICLE_INPUTS,
		Project::ValueName::VehicleInputs::LEFT_DOOR_OPEN_PB_OPERATING_PANEL_1,
		&m_number_left_door_open_pb_OpPanel1,
		[this](const auto& value)
	{
		m_number_left_door_open_pb_OpPanel1 = value;
		CheckInfraction();
	});

	//Right door Pb from operating panel 1
	Requires(
		SimPropertyWatcher::Group::VEHICLE_INPUTS,
		Project::ValueName::VehicleInputs::RIGHT_DOOR_OPEN_PB_OPERATING_PANEL_1,
		&m_number_right_door_open_pb_OpPanel1,
		[this](const auto& value)
	{
		m_number_right_door_open_pb_OpPanel1 = value;
		CheckInfraction();
	});

	assert(m_penalty >= 0);
}

void DoorOpenedFromWrongPanelInfractionRule::CheckInfraction()
{
	const auto is_door_pb_pressed_from_OpPanel1{
		m_number_left_door_open_pb_OpPanel1 > 0.5 || m_number_right_door_open_pb_OpPanel1 > 0.5 };

	const auto is_driving_mode_stand_by{ 0.0 == m_number_driver_mode_selection };

	//If driving mode is standby & door pb from operating panel1 is pressed.
	if (is_driving_mode_stand_by && is_door_pb_pressed_from_OpPanel1)
		RecordInfraction(m_penalty);
}