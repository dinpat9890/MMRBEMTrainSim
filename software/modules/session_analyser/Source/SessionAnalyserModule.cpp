///
/// @file       SessionAnalyserModule.cpp
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

#include "SessionAnalyserModule.h"

// Include units here
#include "SessionAnalyserUnits/SessionFeatureUnit.h"
#include "SessionAnalyserUnits/TransactionLogUnit.h"
#include "SessionAnalyserUnits/InfractionUnit.h"
#include "SessionAnalyserUnits/SATrainPathWatcherUnit.h"

#include <session_data_access/SessionDataAccess.h>
#include <scoring_data_access/ScoringDataAccess.h>

#include <core_data_access/CoreDataAccess.h>
#include <train_data_access/TrainDataAccess.h>
#include <world_api/WorldAccess.h>

namespace
{
    const double REQUEST_FREQUENCY     = 20.0;
    const int    DEFAULT_VEHICLE_INDEX = 0;

    const std::string LOCATION_TYPE_NAME_TRAIN   = "Train";
    const std::string LOCATION_TYPE_NAME_VEHICLE = "Vehicle";
    const std::string LOCATION_TYPE_NAME_GLOBAL  = "Global";
}

/// Constructor. Initializes application, connects to database
///
/// @param properties  Properties to use.
/// @param sim_data    Database to use.

// cppcheck-suppress uninitMemberVar
SessionAnalyserModule::SessionAnalyserModule(Common::Properties &properties, Common::DataAccess &data_access)
    : Core::SelectiveModules<Core::BaseScenarioData, Core::BaseSessionData, Core::FixedBehaviour<false, true>>::Hub(properties, data_access)
    , m_properties(properties)
    , m_data_access(data_access)
    , m_have_saved(false)
    , m_hub_id(GetHubID())
    , m_simulator_id(GetSimulatorID())
    , m_save_command(m_properties.GetSaveCommand())
{
    Core::Database::RegisterCoreNetworkAspects(m_data_access);
    Train::Database::RegisterTrainAspects(m_data_access);
    Session::Database::RegisterSessionAspects(m_data_access);
    Scoring::Database::RegisterScoringAspects(m_data_access);

    m_transactional_data_access = std::unique_ptr<Session::Database::SessionAccess>(new Session::Database::SessionAccess(m_data_access));
}

/// Does not operate in replay. Creates many shared resources if this simulator has a scenario
/// train. Creates all child units by returning creators to do so
///
/// @return The creators for the Units that we want created

Comms::UnitCreators SessionAnalyserModule::InitialiseSession()
{
    Comms::UnitCreators ret;

    const auto scenario_data = GetGateway().GetScenarioData<Core::BaseScenarioData>().data;
    const auto session_data = GetGateway().GetSessionData<Core::BaseSessionData>().data;

    // TODO: should we just not accept in this case? Why are we in the session if we
    // aren't going to be doing anything?
    // We also don't want to do anything if we are going to be in preview mode either!
    if (GetGateway().IsReplay() || session_data.preview)
    {
        // Stop saving
        m_have_saved = true;
        return ret;
    }

    m_premiership_detail.hub_id = -1;
    m_have_saved = false;

    m_transactional_data_writer.reset(new DataAccess::SessionTransactionalDataWriter(*m_transactional_data_access));
    m_world_access.reset(new WorldAPI::WorldAccess(m_data_access, scenario_data.scenario_id));

    m_premiership_detail.session_id = session_data.session_id;
    m_premiership_detail.hub_id = m_hub_id;

    auto hub
        = std::find_if(scenario_data.hub_data.begin(), scenario_data.hub_data.end(),
                      [&](const Core::BaseScenarioData::HubData &hub_data){ return hub_data.hub_id == m_hub_id; });
    if (hub != scenario_data.hub_data.end())
    {
        Train::Database::Train train(m_data_access);
        auto scenario_train = train.GetScenarioTrain(scenario_data.scenario_id, hub->scenario_train_id);

        if (train.HasScenarioTrain(scenario_data.scenario_id, hub->scenario_train_id))
        {
            Trace::g_plog->STAMP(Trace::INFO) << "Found train for scenario with ID = " << hub->scenario_train_id << Trace::EndLog();

            m_points_watcher.reset(new WorldAPI::PointsWatcher());
            m_points_watcher->SetAcceptableTypes(m_data_access);
            m_points_watcher->SetRequestFrequency(REQUEST_FREQUENCY);

            {
                const OS::Lock<Comms::Gateway> LOCK(GetGateway());
                m_points_watcher->Attach(GetGateway().GetRootObject());
                m_path_watcher.reset(new SATrainPathWatcher(GetGateway(), *m_world_access, *m_points_watcher, REQUEST_FREQUENCY, hub->scenario_train_id));
                m_path_points_watcher.reset(new WorldAPI::PathPointsWatcher(*m_world_access, *m_path_watcher, *m_points_watcher));
            }

            Core::Database::Config db_config(m_data_access);
            int vehicle_index = (db_config.GetLocationType(hub->location_type).name == LOCATION_TYPE_NAME_TRAIN) ? hub->vehicle_index : DEFAULT_VEHICLE_INDEX;

            // Depending on whether this is a 'train' or 'vehicle' location, we either ignore
            // the vehicle position number (and use 0 instead) or not.
            auto scenario_train = train.GetScenarioTrain(scenario_data.scenario_id, hub->scenario_train_id);
            auto elements = train.GetTrainElements(scenario_train.train_id);;
            auto our_element
                = std::find_if(elements.begin(), elements.end(),
                               [&vehicle_index](Train::Data::TrainElement &element){ return element.position == vehicle_index; });
            if (our_element != elements.end())
            {
                // Because we have some timing constraints on how we will access the database, which
                // proscribes an order of Unit creation, we don't want to return all Units as
                // creators for parallel creation. (At least, that is how the comments read, and it
                // appears that it would require some massaging to handle parallel creation.)

                // So, we will create them all now, then move them by value into the creator which
                // will then take ownership of them.
                std::shared_ptr<SATrainPathWatcherUnit> tpw_ptr(new SATrainPathWatcherUnit(GetGateway(), *m_path_watcher));
                std::shared_ptr<TransactionLogUnit> tlu_ptr(new TransactionLogUnit(GetGateway(), m_data_access,
                    *m_transactional_data_access, *m_transactional_data_writer, *m_path_watcher, scenario_data,
                    session_data, m_hub_id));
                std::shared_ptr<SessionFeatureUnit> sfu_ptr(new SessionFeatureUnit(GetGateway(), *m_world_access,
                    *m_path_watcher, m_data_access, *m_transactional_data_writer, scenario_data,
                    session_data, m_hub_id));

                Core::Database::Hub hub_db(m_data_access);
                std::shared_ptr<InfractionUnit> inu_ptr(new InfractionUnit(GetGateway(), m_data_access, *m_world_access,
                    *m_path_watcher, *m_path_points_watcher, *m_points_watcher, *m_transactional_data_writer, m_hub_id,
                    vehicle_index, our_element->class_code, hub_db.GetHubModeName(hub->mode), session_data.session_id,
                    scenario_data.scenario_id, hub->scenario_train_id, m_properties));

                // Now that all configuration data has been read, session header is inserted, writing can begin
                m_transactional_data_writer->EnableWriting();

                // Now we can create our 'creators'
                ret.push_back([tpw_ptr]() { return tpw_ptr; });
                ret.push_back([tlu_ptr]() { return tlu_ptr; });
                ret.push_back([sfu_ptr]() { return sfu_ptr; });
                ret.push_back([inu_ptr]() { return inu_ptr; });
            }
        }
        else
        {
            Trace::g_plog->STAMP(Trace::INFO) << "No train this scenario" << Trace::EndLog(); 
        }
    }

    return ret;
}

void SessionAnalyserModule::Save(OS::UniqueIdentifier tag)
{
    if (!m_have_saved)
    {
        m_transactional_data_writer->Finalize();
        m_transactional_data_access->Commit();

        // Premiership
        if (m_premiership_detail.hub_id != -1)
        {
            try
            {
                m_transactional_data_access->InsertPremiershipDetails(m_premiership_detail.session_id, m_premiership_detail.hub_id,
                    m_transactional_data_access->GetAllPremiershipDetails(m_premiership_detail.session_id, m_premiership_detail.hub_id));
            }
            catch(CommonException &e)
            {
                e.AddStackTrace(FLSTAMP, "Inserting PREMIERSHIP details from the transaction database to the configuration database");
                Trace::g_plog->LogException(e);
            }

            // Launch saver.
            std::stringstream saver_exec;
            saver_exec << m_save_command << " " << m_premiership_detail.session_id << " " << m_premiership_detail.hub_id;

            Trace::g_plog->STAMP(Trace::INFO) << "Launching: '" << saver_exec.str() << "'." << Trace::EndLog();

            int ret_val = system(saver_exec.str().c_str());
            if (ret_val < 0)
            {
                Trace::g_plog->STAMP(Trace::ERR) << "Command failed.  errno=" << errno << ", message='" << _sys_errlist[errno] << "'." << Trace::EndLog(); 
            }
            else
            {
                Trace::g_plog->STAMP(Trace::INFO) << "Command executed, return value = " << ret_val << Trace::EndLog(); 
            }
        }

        Trace::g_plog->STAMP(Trace::INFO) << "Saved" << Trace::EndLog();

        // Now remove all the session data again
        try
        {
            m_transactional_data_access->DeleteSessionData(m_premiership_detail.session_id);
        }
        catch (CommonException& e)
        {
            e.AddStackTrace(FLSTAMP, "Deleting SESSIONDATA details for session " + m_premiership_detail.session_id);
            Trace::g_plog->LogException(e);
        }

        Trace::g_plog->STAMP(Trace::INFO) << "Session Data Cleaned" << Trace::EndLog();
    }
    else
    {
        Trace::g_plog->STAMP(Trace::INFO) << "Save requested, but already saved." << Trace::EndLog(); 
    }
}

/// Releases the world access now it is no longer needed

void SessionAnalyserModule::ResetSession()
{
    if (m_transactional_data_writer.get())
    {
        m_transactional_data_writer.reset();
        m_transactional_data_access->Rollback();
    }

    const OS::Lock<Comms::Gateway> LOCK(GetGateway());

    m_path_points_watcher.reset();
    m_path_watcher.reset();
    m_points_watcher.reset();
    m_world_access.reset();
}
