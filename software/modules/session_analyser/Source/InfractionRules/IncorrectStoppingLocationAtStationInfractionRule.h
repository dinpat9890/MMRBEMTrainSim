///
/// @file       IncorrectStoppingLocationAtStationInfractionRule.h
///
///             Train stops an insufficient distance before the Platform Stop feature at stations Infraction Rule
///
/// @ingroup    Integrated Scenarios,
///             SYDDEVEM-DR-014 Driver Evaluation System High Level Design.doc (section 5.3.23)
///
///  @Author:        Vikrant Chaudhary
///
///  (C) Copyright:  SYDAC Pty Ltd, 2017
///

#pragma once

//#include "SessionAnalyserUnits/InfractionRule.h"
//
//class IncorrectStoppingLocationAtStationInfractionRule : public InfractionRule
//{
//public:
//	IncorrectStoppingLocationAtStationInfractionRule(InfractionUnit&                    punit,
//		Scoring::ScoringParameterProvider& scoring_parameters);
//
//private:
//	// Configuration
//	int    m_rule_id;
//	double m_stop_pos_dist;
//	double m_stop_pos_penalty;
//
//	// Triggers
//	void SpeedChanged(Sim::Number number);
//	void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj);
//
//	bool m_last_train_stop_state;
//	double m_number_speed;
//	std::vector<Sim::ObjectID> m_platform_stop_feature_ids;
//};
