///
/// @file       SessionFeatureUnit.cpp
///
///             Defines the SessionFeatureUnit unit, who records all
///             features passed by a train in a session.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#include "SessionFeatureUnit.h"

#include <core_comms_structure/CoreObjectConstants.h>
#include <core_data_access/Scenario.h>
#include <core_types/SessionData.h>
#include <common/StandardLogging.h>

namespace
{
    const double REQUEST_FREQUENCY = 20.0;
}

/// Returns a string describing this unit.

std::string SessionFeatureUnit::GetName() const
{
    return "Session Feature Unit";
}

/// Constructor. Starts a path feature watcher.

SessionFeatureUnit::SessionFeatureUnit(Comms::Gateway &gateway, WorldAPI::WorldAccess &world_access,
                                       SATrainPathWatcher &path_watcher, Common::DataAccess &data_access,
                                       DataAccess::SessionTransactionalDataWriter &transaction_data_access,
                                       const Core::BaseScenarioData &scenario_data,
                                       const Core::BaseSessionData &session_data, int hub_id)
  : Comms::SessionUnit(gateway)
  , m_world_access(world_access)
  , m_data_access(data_access)
  , m_transaction_data_access(transaction_data_access)
  , m_path_watcher(path_watcher)
  , m_pfeature_watcher(0)
  , m_ppath_feature_watcher(0)
{
    // Base data for each record
    m_feature.sim_session_id = session_data.session_id;

    Core::Database::Scenario scenario_db(m_data_access);
    auto scenario = scenario_db.GetScenario(scenario_data.scenario_id);

    m_feature.network_id     = scenario.tracknetwork_id;
    m_feature.hub_id         = hub_id;

    OS::Lock<Comms::Gateway> lock(GetGateway());

    // Attempt to create a feature watcher on everything
    // And a path watcher so we are told whenever we pass a feature
    try
    {
        m_pfeature_watcher      = new WorldAPI::FeatureWatcher();
        m_ppath_feature_watcher = new WorldAPI::PathFeatureWatcher(m_world_access, m_path_watcher, *m_pfeature_watcher);

        m_ppath_feature_watcher->AddFeaturePassedCallback(MakeCallback(&SessionFeatureUnit::FeaturePassed, this));

        // Start the feature watcher
        m_pfeature_watcher->SetRequestFrequency(REQUEST_FREQUENCY);
        m_pfeature_watcher->Attach(GetGateway().GetRootObject());
    }
    catch (...)
    {
        // Clean up and throw
        delete m_ppath_feature_watcher;
        delete m_pfeature_watcher;

        throw;
    }
}

/// Stops the path feature watcher

SessionFeatureUnit::~SessionFeatureUnit()
{
    OS::Lock<Comms::Gateway> lock(GetGateway());

    delete m_ppath_feature_watcher;
    delete m_pfeature_watcher;
}

/// Called when a feature is passed by the train. Records this.
///
/// @param pobj  object passed

void SessionFeatureUnit::FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj)
{
    std::lock_guard<std::mutex> lock(m_mutex);  // Looks like unnecessary but intends to protect m_transaction_data_access

    m_feature.feature_id      = static_cast<int>(pobj.object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID));
    m_feature.feature_type_id = static_cast<int>(pobj.object.Numbers().Get(Core::ValueName::Feature::TYPE));
    m_feature.passed_time     = m_path_watcher.GetTime();
    m_feature.position        = m_path_watcher.GetPosition();

    // Not all feature types will have a 'State' number, so we specify this to DataAccess.
    const Sim::Number::ID STATE_NUM_ID = pobj.object.Numbers().Info().GetID(Core::ValueName::Feature::STATE);
    if (m_feature.has_state = (STATE_NUM_ID != Sim::INVALID_NUMBER))
    {
        m_feature.feature_state_id = static_cast<int>(pobj.object.Numbers().Store().Get(STATE_NUM_ID)); 
    }

    m_transaction_data_access.InsertSessionFeature(m_feature);
}
