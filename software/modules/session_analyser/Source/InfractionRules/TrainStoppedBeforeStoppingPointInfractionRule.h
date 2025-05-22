#ifndef TRAIN_STOPPED_BEFORE_STOPPINGPOINT_INFRACTION_RULE_H
#define TRAIN_STOPPED_BEFORE_STOPPINGPOINT_INFRACTION_RULE_H
#include "SessionAnalyserUnits/InfractionRule.h"


/// Implements the "Train Stopped Before Stopping Point Infraction"
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 18, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class TrainStoppedBeforeStoppingPointInfractionRule : public InfractionRule
{
public:
	/// @throws CommonException if the scoring parameters are invalid or missing.
	TrainStoppedBeforeStoppingPointInfractionRule(
		InfractionUnit&                    punit,
		Scoring::ScoringParameterProvider& scoring_parameters);

private:
	// Scoring Parameters.
	const double m_penalty;
	const double m_min_distance;
	const double m_max_distance;

	// Inputs.
	double m_vehicle_speed;
	int m_feature_stopping_point_id;

	bool m_last_train_stop_state;

	// Triggers
	void SpeedChanged(Sim::Number number);
};

#endif //TRAIN_STOPPED_BEFORE_STOPPINGPOINT_INFRACTION_RULE_H



