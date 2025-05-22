///
/// @file       SessionAnalyserModule.h
///
///             Declares the SessionAnalyserModule class, which is the
///             class that creates the Units when a session begins.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#ifndef SESSION_ANALYSER_APPLICATION_H
#define SESSION_ANALYSER_APPLICATION_H

#include "SessionAnalyserProperties.h"

#include "session_data_access/SessionAccess.h"
#include "DataAccess/SessionTransactionalDataWriter.h"
#include "SessionAnalyserUnits/SATrainPathWatcher.h"

#include <memory>

#include <core_types/SessionData.h>
#include <utility/SelectiveModule.h>
#include <world_api/PathPointsWatcher.h>
#include <world_api/PointsWatcher.h>
#include <world_api/WorldAccess.h>

/// This is the application class - the main class of the program. It creates the necessary world
/// model units in the Define function when a session is being created.
///
/// @note
///     It is being set up to be a hub application for the moment,
///     although this may need to change in the future.

class SessionAnalyserModule : public Core::SelectiveModules<Core::BaseScenarioData, Core::BaseSessionData, Core::FixedBehaviour<false, true>>::Hub
{
public:
    SessionAnalyserModule(Common::Properties &properties, Common::DataAccess &data_access);

    Comms::UnitCreators InitialiseSession() override;
    void                ResetSession() override;

    void Save(OS::UniqueIdentifier tag) override;

private:
    Project::SessionAnalyserProperties m_properties;
    Common::DataAccess &m_data_access;
    std::unique_ptr<Session::Database::SessionAccess> m_transactional_data_access;

    // Shared resources, session based
    std::unique_ptr<DataAccess::SessionTransactionalDataWriter> m_transactional_data_writer;
    std::unique_ptr<WorldAPI::WorldAccess>       m_world_access;
    std::unique_ptr<WorldAPI::PointsWatcher>     m_points_watcher;
    std::unique_ptr<WorldAPI::PathPointsWatcher> m_path_points_watcher;
    std::unique_ptr<SATrainPathWatcher>          m_path_watcher;

    // Only save once per session
    bool m_have_saved;

    int m_hub_id;
    int m_simulator_id;

    std::string m_save_command;

    // Premiership points are handled by the application, this is a post process step
    Session::Data::PremiershipDetail m_premiership_detail;
};

#endif // SESSION_ANALYSER_APPLICATION_H
