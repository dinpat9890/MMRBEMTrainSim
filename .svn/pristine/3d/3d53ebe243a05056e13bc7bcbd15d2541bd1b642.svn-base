/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Door opened from wrong panel" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 17, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class DoorOpenedFromWrongPanelInfractionRule : public InfractionRule
{
public:
	/// @throws CommonException if the scoring parameters are invalid or missing.
	DoorOpenedFromWrongPanelInfractionRule(
		InfractionUnit&                    punit,
		Scoring::ScoringParameterProvider& scoring_parameters);

private:
	// Scoring Parameters.
	const double m_penalty;

	// comms Inputs.
	double m_number_driver_mode_selection;
	double m_number_left_door_open_pb_OpPanel1;
	double m_number_right_door_open_pb_OpPanel1;
	
	void CheckInfraction();
};