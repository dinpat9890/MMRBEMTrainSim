#include "PassingStopReverseMarkerBoardInfractionRule.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>
#include "core_data_access/Feature.h"
#include <vector>


namespace
{
	constexpr auto rule_name{ "PSRMBI" };

	namespace Parameters
	{
		constexpr auto penalty{ "PSRPNLTY" };
	}
	const double MIN_MOVING_SPEED = 0.1;
}

PassingStopReverseMarkerBoardInfractionRule::PassingStopReverseMarkerBoardInfractionRule(
	InfractionUnit&                    unit,
	Scoring::ScoringParameterProvider& scoring_parameters)
	: InfractionRule(unit, rule_name, scoring_parameters),
	m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
	m_vehicle_speed(0.0)
{
	Requires(
		SimPropertyWatcher::Group::TRAIN,
		Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
		&m_vehicle_speed);

	//Watch feature reverse marker board.
	Core::Database::Feature feature(GetDataAccess());	
	m_feature_stopping_reverse_marker_board_id = feature.GetFeatureType(Project::FeatureTypes::FETY_STOPPING_REVERSE_MARKER_BOARD).feature_type_id;
	std::vector<int> feature_type_ids = { m_feature_stopping_reverse_marker_board_id };
	RequiresPath();
	WatchFeatureTypes(feature_type_ids);

	assert(m_penalty >= 0);
}

void PassingStopReverseMarkerBoardInfractionRule::FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj)
{
	const auto train_is_moving{ std::abs(m_vehicle_speed) > MIN_MOVING_SPEED };
	int feature_id = static_cast<int>(pobj.object.Numbers().Get(Project::ValueName::Feature::TYPE).value);
	//If train is moving & crossed stopping reverse marker board, record infraction
	if ( feature_id == m_feature_stopping_reverse_marker_board_id && train_is_moving)
	{
		RecordInfraction(m_penalty);
	}
}
