//******************************************************************************
//
//  File:           SerialDeviceApplication.cpp
//
//  Description:    Declares the SerialDeviceApplication class, which is the
//                  class that creates the Units when a session begins.
//
//  Reference:      Integrated Scenarios, AC05-004
//
//  Author:         James Errington
//
//  (C) Copyright:  SYDAC Pty Ltd, 2005
//
//******************************************************************************

#include "SerialDeviceApplication.h"
#include "world_api/WorldAccess.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_comms_structure/ProjectObjectConstants.h"

#include "core_types/SessionData.h"

#include "sim_comms/ProcessingInterfaces.h"
#include "sim_comms/System.h"
#include "core_properties/CommonProperties.h"

#include "FlightSimGaugeUnit.h"
#include "FlightSimUnitV2.h"
#include "core_data_access/Simulator.h"
#include "train_data_access/TrainDataAccessTypes.h"
#include "train_data_access/TrainDataAccess.h"


using namespace std;

namespace
{
    const double REQUEST_FREQ = 20.0;

	
}

//  Function:       SerialDeviceApplication::SerialDeviceApplication
//
//  Description:    Constructor. Initializes application, connects to database
//
//  Parameters:
//      Sydac::Properties &properties - Properties to use.
//      DataAccess:sim_data           - The database to get information from.
SerialDeviceApplication::SerialDeviceApplication(Common::Properties &properties, Common::DataAccess &data_access)
    : Core::CommsConnectionInfo(properties), Comms::SimpleNetworkModule(GetBehaviour(), GetSystemInfo(),GetLivelinessInfo(), GetSystemManagerInfo()),
       m_properties(properties),
       m_data_access(data_access),
       m_hub_id(Core::Properties::GetHubID(properties, data_access)),
	   m_scenario_train_id(-1),
	   m_car_index(-1)
{
	// Register the versions of the scenario and session data structures
    Common::LocalVersions::Instance().Register<Core::BaseScenarioData>(Core::BaseScenarioData::GetVersion());
    Common::LocalVersions::Instance().Register<Core::BaseSessionData>(Core::BaseSessionData::GetVersion());

    Core::Database::RegisterCoreNetworkAspects(data_access);
    Train::Database::RegisterTrainAspects(data_access);

    GetResources().Add(data_access);
}

/// Should we enter the scenario?
///
/// @param system The system the scenario is in, providing access to the scenario data
///
/// @return True if our hub is involved and we should accept

bool SerialDeviceApplication::AcceptScenario(Comms::System system)
{
    return Core::InvolvesHub(system.GetScenarioData<Core::BaseScenarioData>().data, m_hub_id);
}

/// Creates a new World Access for the session and then provides the creators necessary
///
/// @param gateway The gateway for the session
///
/// @return Creators for units that we want to have a session lifetime.

Comms::UnitCreators SerialDeviceApplication::DefineSession(Comms::Gateway &gateway)
{
	// Store our units in a vector.
    Comms::UnitCreators ret;

	Trace::g_plog->STAMP(Trace::VERBOSE) << "SerialDeviceApplication::DefineSession Starting " << Trace::EndLog();
	
	const auto scenario_data = gateway.GetScenarioData<Core::BaseScenarioData>().data;
	const auto session_data  = gateway.GetSessionData<Core::BaseSessionData>().data;

    // Determine scenario train
    Core::Database::Simulator simulator_data(m_data_access);
    int simulator_id = simulator_data.GetSimulatorID(m_properties.GetProperty<string>("Simulator", "Name"));

    // NB! Only use this function if InvolvesHub returns true (In Accept in this case)!!!
	// GetScenarioData returns Temporary Data so make a copy!
	auto sd = gateway.GetScenarioData<Core::BaseScenarioData>().data;
    const auto &hub_data = Core::GetHubData(sd, m_hub_id);

    m_car_index                              = hub_data.vehicle_index;
	m_logical_hub_id						 = hub_data.logical_hub_id;
    m_scenario_train_id                      = hub_data.scenario_train_id;

    Train::Database::Train database_train(m_data_access);
    if(database_train.HasScenarioTrain(scenario_data.scenario_id, m_scenario_train_id))
    {
        auto scenario_train = database_train.GetScenarioTrain(scenario_data.scenario_id, m_scenario_train_id);

		try
		{
			{
				m_world_access.reset(new WorldAPI::WorldAccess(m_data_access, scenario_data.scenario_id));

				m_points_watcher.reset(new WorldAPI::PointsWatcher());
				m_points_watcher->SetAcceptableTypes(m_data_access);

				const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());

				m_points_watcher->Attach(GetGateway().GetRootObject());
				m_train_watcher.reset(new WorldAPI::ScenarioTrainPathWatcher(*m_world_access.get(), *m_points_watcher.get(), REQUEST_FREQ, GetGateway().GetRootObject(), scenario_train.scenario_train_id));
			}

			if(m_properties.GetProperty<bool>("Flight Sim Gauges", "Active", false))
				ret.push_back([this, session_data] { return std::shared_ptr<Comms::Unit>(new FlightSimGaugeUnit(GetGateway(), *m_train_watcher.get(), m_car_index, m_properties, session_data.date_time)); });            

			// Do this for each FlightSimHardware unit that shares a common COM port
			const std::string  SECTION_BASE_1 = "FlightSimHardware.1";
			if(m_properties.GetProperty<bool>(SECTION_BASE_1, "Active", false))
			{
				Trace::g_plog->STAMP(Trace::VERBOSE) << "SerialDeviceApplication::DefineSession Create FlightSimUnitV2 " << Trace::EndLog();
				//ret.push_back([this, session_data, SECTION_BASE_1] { return std::shared_ptr<Comms::Unit>(new FlightSimUnitV2(SECTION_BASE_1, GetGateway(), *m_train_watcher.get(), m_car_index, m_properties, session_data.date_time)); });
				// OR Alternative to Construct NOW
				std::shared_ptr<FlightSimUnitV2> fsh1_ptr(new FlightSimUnitV2(SECTION_BASE_1, GetGateway(), *m_train_watcher.get(), m_logical_hub_id, m_scenario_train_id, m_car_index, m_properties, session_data.date_time));
				ret.push_back([fsh1_ptr]() { return fsh1_ptr; });
			}
		}
		catch(CommonException &e)
		{
			e.AddStackTrace(FLSTAMP, "Creating units for scenario");
			Trace::g_plog->LogException(e);

			// Report this error - the simulation should not run
			GetGateway().DegradeHealth(Comms::Health::SESSION_ERROR, "A Unit failed to construct in the Serial Device Module");
		}
	}

	return ret;
}

/// Releases the world access at the end of the session as it is no longer needed

void SerialDeviceApplication::ResetSession()
{
    {
        const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());
        m_train_watcher.reset();
        m_points_watcher.reset();
    }

    m_world_access.reset();
}
