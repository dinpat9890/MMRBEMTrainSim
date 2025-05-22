///
/// @file       IncorrectStoppingLocationAtStationInfractionRule.cpp
///
///             This infraction is recorded whenever the train stops an insufficient distance before the Platform Stop feature at stations
///
/// @ingroup    Integrated Scenarios,
///             SYDDEVEM-DR-014 Driver Evaluation System High Level Design.doc (section 5.3.23)
///
///@Author:        Vikrant Chaudhary
///
///(C) Copyright:  SYDAC Pty Ltd, 2017
///
//#include "IncorrectStoppingLocationAtStationInfractionRule.h"
//#include "common/StandardLogging.h"
//#include "project_comms_structure/ProjectObjectConstants.h"
//
//
//
//namespace
//{
//	const double  MIN_MOVING_SPEED = 0.1;
//	const double PLATFORM_STOP_FEATURE_IN_ENABLED_STATE = 2.0;
//	constexpr auto rule_name{ "STOP_POS" };
//}
//
//IncorrectStoppingLocationAtStationInfractionRule::IncorrectStoppingLocationAtStationInfractionRule(InfractionUnit&        unit,
//	Scoring::ScoringParameterProvider& scoring_parameters)
//	: InfractionRule(unit, rule_name, scoring_parameters)
//{
//	m_last_train_stop_state = false;
//	//m_rule_id = GetRuleID("STOP_POS");
//	m_stop_pos_dist = GetParameter("MAXIMUM_DIST");
//	m_stop_pos_penalty = GetParameter("STOP_P");
//
//	//try
//	{
//		std::vector<int> platform_stop_feature_type_id;
//
//		Core::Database::Feature feature(GetDataAccess());
//		const auto feature_type = feature.GetFeatureType(Project::FeatureTypes::FETY_PLATFORM_STOP_MARKER_6C);
//		platform_stop_feature_type_id.push_back(feature_type.feature_type_id);
//
//		RequiresPath();
//		//Requires(SimPropertyWatcher::Group::TRAIN, Project::ValueName::Train::LLO_LEAD_LOCO_SPEED, &m_number_speed, MakeCallback(&IncorrectStoppingLocationAtStationInfractionRule::SpeedChanged, this));
//		Requires(
//			SimPropertyWatcher::Group::TRAIN,
//			Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
//			&m_number_speed,
//			[this](const auto& value)
//		{
//			m_number_speed = value;
//			SpeedChanged(m_number_speed);
//		});
//		WatchFeatureTypes(platform_stop_feature_type_id);
//	}
//	/*catch (SydacException &e)
//	{
//		e.AddStackTrace(FLSTAMP, "Error in loading 'Platform Stop' feature, so IncorrectStoppingLocationAtStationInfractionRule will not work.");
//		Trace::g_plog->LogException(e);
//	}*/
//}
//
//void IncorrectStoppingLocationAtStationInfractionRule::SpeedChanged(Sim::Number number)
//{
//	const auto train_has_stopped = abs(number.value) < MIN_MOVING_SPEED;
//	auto change_in_train_stop_state = Change(m_last_train_stop_state, train_has_stopped);
//
//	if (change_in_train_stop_state && train_has_stopped)
//	{
//		if (GetPathWatcher().HasLock() && GetPathWatcher().HasPath())
//		{
//			auto platform_stop_feature_objects = GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(), GetFeatureObjects(), true, false, 0.0, m_stop_pos_dist);
//			const auto platform_stop_feature_found = !platform_stop_feature_objects.empty();
//			if (platform_stop_feature_found)
//			{
//				auto platform_stop_object = platform_stop_feature_objects.front().second;
//				if (platform_stop_object.IsValid())
//				{
//					auto feature_object_id = platform_stop_object.GetID();
//					//To raise this infraction once for one platform stop feature.
//					auto feature_iterator_found = std::find_if(m_platform_stop_feature_ids.begin(), m_platform_stop_feature_ids.end(),
//						[&feature_object_id](Sim::ObjectID store_feature_id) {return feature_object_id == store_feature_id; }
//					);
//					if (feature_iterator_found != m_platform_stop_feature_ids.end())
//						return;
//
//					m_platform_stop_feature_ids.emplace_back(feature_object_id);
//					const auto feature_state_id = platform_stop_object.Numbers().Info().GetID(Project::ValueName::Feature::STATE);
//					if (feature_state_id != Sim::INVALID_NUMBER)
//					{
//						const auto feature_state = platform_stop_object.Numbers().Store().Get(feature_state_id).value;
//
//						if (feature_state == PLATFORM_STOP_FEATURE_IN_ENABLED_STATE)
//							//RecordInfraction(m_rule_id, GetCurrentTimePosition(), m_stop_pos_penalty);
//							RecordInfraction(m_rule_id);
//					}
//				}
//			}
//		}
//		else
//			Trace::GetLogger().STAMP(Trace::ERR) << "IncorrectStoppingLocationAtStationInfractionRule::SpeedChanged path watcher lock not acquired or found no path" << Trace::EndLog();
//	}
//}
//
//void IncorrectStoppingLocationAtStationInfractionRule::FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject passed_object)
//{
//	auto flatform_stop_feature_object = passed_object.object;
//	if (flatform_stop_feature_object.IsValid())
//	{
//		auto passed_feature_object_id = flatform_stop_feature_object.GetID();
//		auto feature_itr_remove = std::remove_if(m_platform_stop_feature_ids.begin(), m_platform_stop_feature_ids.end(),
//			[&passed_feature_object_id](Sim::ObjectID store_feature_id) {return passed_feature_object_id == store_feature_id; }
//		);
//
//		if (feature_itr_remove != m_platform_stop_feature_ids.end())
//			m_platform_stop_feature_ids.erase(feature_itr_remove);
//	}
//}
