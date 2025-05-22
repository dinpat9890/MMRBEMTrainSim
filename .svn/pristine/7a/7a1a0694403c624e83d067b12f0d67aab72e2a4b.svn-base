#include "TrainStoppedBeforeStoppingPointInfractionRule.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>
#include "core_data_access/Feature.h"
#include <vector>

namespace
{
	constexpr auto rule_name{ "STPOSBEF" };

	namespace Parameters
	{
		constexpr auto penalty{ "STPOSBEF_P" };
		constexpr auto max_distance{ "MAX_DIST1" };
		constexpr auto min_distance{ "MIN_DIST1" };
	}
	const double MIN_MOVING_SPEED = 0.1;
	const double DISTANCE_BETWEEN_6C_AND_8C_STOPPING_POINT = 22.92;
}

TrainStoppedBeforeStoppingPointInfractionRule::TrainStoppedBeforeStoppingPointInfractionRule(
	InfractionUnit&                    unit,
	Scoring::ScoringParameterProvider& scoring_parameters)
	: InfractionRule(unit, rule_name, scoring_parameters),
	m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
	m_max_distance(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::max_distance)),
	m_min_distance(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::min_distance)),
	m_vehicle_speed(0.0),
    m_last_train_stop_state(false)
{
   //Train speed
	Requires(
		SimPropertyWatcher::Group::TRAIN,
		Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
		&m_vehicle_speed,
		[this](const auto& value)
	{
		m_vehicle_speed = value;
		SpeedChanged(m_vehicle_speed);
	});

	//Watch feature stopping point
	Core::Database::Feature feature(GetDataAccess());
	m_feature_stopping_point_id = feature.GetFeatureType(Project::FeatureTypes::FETY_STOPPING_POINT).feature_type_id;
	std::vector<int> feature_type_ids = { m_feature_stopping_point_id };
	RequiresPath();
	WatchFeatureTypes(feature_type_ids);

	assert(m_penalty >= 0);
}

void TrainStoppedBeforeStoppingPointInfractionRule::SpeedChanged(Sim::Number number)
{
	const auto train_has_stopped = abs(number.value) < MIN_MOVING_SPEED;
	auto change_in_train_stop_state = Change(m_last_train_stop_state, train_has_stopped);
	//If train is stopped
	if (change_in_train_stop_state && train_has_stopped)
	{
		if (/*GetPathWatcher().HasLock() &&*/ GetPathWatcher().HasPath())
		{
			//If stopping point is between m_min_distance to m_max_distance after lead car
			if (IsTrainNearToFeature(0.0, m_max_distance) && !IsTrainNearToFeature(0.0, m_min_distance))
			{                
				//There are 2 stopping points. First is for 6C train & second is for 8C train.
				//Distance between these two stopping points is 22.92
				//There may be possibility that 6C car can stop before 8C stopping point or 8C car can stop before 6C stopping point.
				auto vect_comms_obj_stoppingpoint = GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(),
					GetFeatureObjects(), true, false, 0.0, m_max_distance + DISTANCE_BETWEEN_6C_AND_8C_STOPPING_POINT);
				//Get vehicle count
				const auto vehicle_count = GetVehicleCount();
                const auto is_6C_train{ 6 == vehicle_count };
                const auto is_8C_train{ 8 == vehicle_count };
				//If 6C train is stopped && there are 2 stopping points ahead
				if (is_6C_train && 2 == vect_comms_obj_stoppingpoint.size())
				{
					Trace::GetLogger().STAMP(Trace::VERBOSE) << "Train stopped before stopping point infraction. " << Trace::EndLog();
					RecordInfraction(m_penalty);
				}
				//If 8C train is stopped && there is 1 stopping points ahead
				else if (is_8C_train && 1 == vect_comms_obj_stoppingpoint.size())
				{
					Trace::GetLogger().STAMP(Trace::VERBOSE) << "Train stopped before stopping point infraction. " << Trace::EndLog();
					RecordInfraction(m_penalty);
				}
                //If train is other than 6C or 8C && is stopped && there are 2 stopping points ahead ==> Expected to stop at 6C stopping point
                else if ((!is_6C_train && !is_8C_train) && 2 == vect_comms_obj_stoppingpoint.size())
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Train stopped before stopping point infraction. " << Trace::EndLog();
                    RecordInfraction(m_penalty);
                }
			}            
		}
	}
}


