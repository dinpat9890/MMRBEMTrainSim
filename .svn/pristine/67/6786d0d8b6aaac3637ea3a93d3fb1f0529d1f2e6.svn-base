//******************************************************************************
//
//  File:           FlightSimUnitV2.h
//
//  Description:    Serial Device Unit Wrapper around Serial Device Units that share a (non-gauge) FlightSim device 
//                  driver. i.e. All Child units communicate with there devices over the same COM port.
//
//  Reference:      Metronet Trains Melbourne
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2013
//
//******************************************************************************
#ifndef FLIGHTSIM_UNITV2_H
#define FLIGHTSIM_UNITV2_H

#include "common/Properties.h"
#include "Hardware/FlightSimHardwareV2.h"
#include "sim_comms/Unit.h"
#include "sim_comms/ProcessingInterfaces.h"
#include "world_api/WorldAccess.h"
#include "world_api/TrainPathWatcher.h"

//  Class:          FlightSimUnit
//
//  Description:    Serial Device - Flight Sim Devices

class FlightSimUnitV2 : public Comms::Unit, public Comms::SessionProcessing
{
public:
    // Constructor
    FlightSimUnitV2(const std::string &section_base, Comms::Gateway &gateway, WorldAPI::TrainPathWatcher &tpw, int logical_hub_id, int scenario_train_id, int vehicle_index, const Common::Properties &properties, unsigned long simulation_start_time );
    ~FlightSimUnitV2();

    std::string GetName() const { return "FlightSimV2 Unit"; }

	//Comms::UnitCreators DefineSession(Comms::Gateway &gateway);
	Comms::UnitCreators InitialiseSession() override;

private:
    WorldAPI::TrainPathWatcher      &m_train_watcher;
    const Common::Properties         &m_properties;
	Comms::Gateway                  &m_gateway;
	std::string                     m_section_base;
	unsigned long                   m_simulation_start_time;
	int                             m_logical_hub_id;
    int                             m_scenario_train_id;
	int                             m_vehicle_index;
    std::unique_ptr<FlightSimHardwareV2> m_phardware;          
    
};

#endif //FLIGHTSIM_UNITV2_H
