//******************************************************************************
//
//  File:           SerialDeviceApplication.h
//
//  Description:    Declares the SerialDeviceApplication class, which is the
//                  class that creates the Units when a session begins.
//
//  Reference:      PPP - AC07-015
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2009
//
//******************************************************************************
#ifndef SERIAL_DEVICES_APPLICATION_H
#define SERIAL_DEVICES_APPLICATION_H

#include "Utility/CommsConnectionInfo.h"

#include "world_api/WorldAccess.h"
#include "world_api/PointsWatcher.h"
#include "world_api/TrainPathWatcher.h"

// #include "CoreUnits/CoreUnitProperties.h"

// Forward declaration
namespace DataAccess { class SimulatorData; }

//  Class:          SerialDeviceApplication
//
//  Description:    This is the application class - the main class of the
//                  program. It creates the necessary world model units
//                  in the Define function when a session is being created.

class SerialDeviceApplication : private Core::CommsConnectionInfo, public Comms::SimpleNetworkModule
{
public:
    // The necessary typedef that ConsoleMain requires
    typedef Common::Properties Properties;
    //typedef TYPELIST_2(Core::CommonPropertiesManager, Core::CoreUnitProperties) ProjectProperties;
    //typedef Core::PropertiesManager<ProjectProperties>                          Properties;

public:
    // Constructor and destructor. We are unique - no copying or assignment.
    SerialDeviceApplication(Common::Properties &properties, Common::DataAccess &data_access);

    bool                AcceptScenario(Comms::System system) override;
    Comms::UnitCreators DefineSession(Comms::Gateway &gateway) override;
    void                ResetSession() override;

    int GetHubID() const{ return m_hub_id; }

private:
    const Properties                                 &m_properties;

    int                                               m_hub_id;
	int                                               m_scenario_train_id;
    int                                               m_car_index;
	int												  m_logical_hub_id;

    Common::DataAccess                                 &m_data_access;

    std::unique_ptr<WorldAPI::WorldAccess>              m_world_access;
    std::unique_ptr<WorldAPI::PointsWatcher>            m_points_watcher;
    std::unique_ptr<WorldAPI::ScenarioTrainPathWatcher> m_train_watcher;

};

#endif // SERIAL_DEVICES_APPLICATION_H
