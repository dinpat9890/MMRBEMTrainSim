///
/// @file       SessionFeatureUnit.h
///
///             Declares the SessionFeatureUnit unit, who records all
///             features passed by a train in a session.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#ifndef SESSION_FEATURE_UNIT_H
#define SESSION_FEATURE_UNIT_H

#include "SessionAnalyserUnits/SATrainPathWatcher.h"

#include "DataAccess/SessionTransactionalDataWriter.h"

#include <sim_comms/Unit.h>
#include <sim_comms/ScenarioSessionData.h>
#include <common/DataAccess.h>
#include <world_api/WorldAccess.h>
#include <world_api/PathFeatureWatcher.h>

namespace Core
{
    struct BaseScenarioData;
    struct BaseSessionData;
}

/// The SessionFeatureUnit records all features passed by a train in a session.

class SessionFeatureUnit : public Comms::SessionUnit
{
public:
    // Constructor
    SessionFeatureUnit(Comms::Gateway &gateway, WorldAPI::WorldAccess &world_access, SATrainPathWatcher &path_watcher,
        Common::DataAccess &data_access, DataAccess::SessionTransactionalDataWriter &transaction_data_access,
        const Core::BaseScenarioData &scenario_data, const Core::BaseSessionData &session_data, int hub_id);
    ~SessionFeatureUnit();

    std::string GetName() const override;

private:
    // Callbacks
    void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject pobj);

private:
    std::mutex m_mutex;

    // Configuration
    WorldAPI::WorldAccess &m_world_access;
    Common::DataAccess &m_data_access;
    DataAccess::SessionTransactionalDataWriter &m_transaction_data_access;
    SATrainPathWatcher &m_path_watcher;

    WorldAPI::FeatureWatcher *m_pfeature_watcher;
    WorldAPI::PathFeatureWatcher *m_ppath_feature_watcher;

    // Base data for each record
    Session::Data::SessionFeature m_feature;
};

#endif // SESSION_FEATURE_UNIT_H
