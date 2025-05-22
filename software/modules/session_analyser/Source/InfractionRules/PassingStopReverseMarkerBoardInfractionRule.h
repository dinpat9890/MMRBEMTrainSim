#ifndef PASSING_STOP_REVERSE_MARKER_BOARD_INFRACTION_RULE_H
#define PASSING_STOP_REVERSE_MARKER_BOARD_INFRACTION_RULE_H
#include "SessionAnalyserUnits/InfractionRule.h"


/// Implements the "Emergency stop infraction"
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 12, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class PassingStopReverseMarkerBoardInfractionRule : public InfractionRule
{
public:
	/// @throws CommonException if the scoring parameters are invalid or missing.
	PassingStopReverseMarkerBoardInfractionRule(
		InfractionUnit&                    punit,
		Scoring::ScoringParameterProvider& scoring_parameters);

private:
	// Scoring Parameters.
	const double m_penalty;

	// Inputs.
	double m_vehicle_speed;
	int m_feature_stopping_reverse_marker_board_id;

	 // Triggers
	void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj) override;
};

#endif //PASSING_STOP_REVERSE_MARKER_BOARD_INFRACTION_RULE_H

