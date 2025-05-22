///
/// @file       DoorNotOpenedForBoardingPassInfractionRule.h
///
///            Door Not Open Boarding Pass Infraction Rule
///
/// @ingroup    Mumbai Metro L2 & L7 simulator.
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2022
///
/// Implements the "Door not opened infraction"
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 13, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
#ifndef DOOR_NOT_OPENED_BOARDING_PASS_INFRACTION_RULE_H
#define DOOR_NOT_OPENED_BOARDING_PASS_INFRACTION_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class DoorNotOpenedForBoardingPassInfraction : public InfractionRule
{
public:
	explicit DoorNotOpenedForBoardingPassInfraction(InfractionUnit& unit, Scoring::ScoringParameterProvider& scoring_parameters);

private:
	// Triggers
	void LeftDoorEnableStatusChanged(Sim::Number number);
	void RightDoorEnableStatusChanged(Sim::Number number);
	void LeftSideDoorOpenRequestChanged(Sim::Number number);
	void RightSideDoorOpenRequestChanged(Sim::Number number);

	//TODO: RSHI: this may be deleted at later...
	void RequiredAvailable() override;
	void TimePositionChanged(TimePosition time_position) override;

	// Configuration
	double m_penalty;
	double m_wait_duration;
	double m_time_when_left_doors_are_enabled;
	double m_time_when_right_doors_are_enabled;
	double m_time_when_left_side_door_open_requested;
	double m_time_when_right_side_door_open_requested;
	bool   m_button_pushed_for_open_left_doors;
	bool   m_button_pushed_for_open_right_doors;
	bool   m_left_door_enabled;
	bool   m_right_door_enabled;
	bool   m_left_door_open_request;
	bool   m_right_door_open_request;


	// Comms
	double m_number_left_side_door_enable;
	double m_number_right_side_door_enable;
	double m_number_door_mode;
	double m_number_driver_mode_selection;
	double m_number_is_left_side_door_open_request;
	double m_number_is_right_side_door_open_request;
};

#endif // DOOR_NOT_OPENED_BOARDING_PASS_INFRACTION_RULE_H

