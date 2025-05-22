//******************************************************************************
//
//  File:           FlightSimUnitV2.cpp
//
//  Description:    Serial Device - Flight Sim Hardware (Not Gauges)
//
//  Reference:      Metronet Trains Melbourne
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2013
//
//******************************************************************************
#include "FlightSimUnitV2.h"

#include "common/StandardLogging.h"

using namespace Sim;
using namespace std;

namespace
{
};

//  Function:       FlightSimUnitV2::FlightSimUnitV2
//
//  Description:    Constructor. 
//
//  Parameters:
//      std::string &section_base           - The Base name of the Properties file sections for devices that share the same COM port.
//      Framework::Gateway &gateway         - The Comms Gateway for passing to Child Units.
//      WorldAPI::TrainPathWatcher &tpw     - A Common TrainPathWatcher for Child units.
//      int vehicle_index                   - 
//      const Sydac::Properties &properties - Serial Devices Properties file with Configuration details
//      unsigned long simulation_start_time - The Simulation Start Time

FlightSimUnitV2::FlightSimUnitV2(const std::string &section_base, Comms::Gateway &gateway, WorldAPI::TrainPathWatcher &tpw, int logical_hub_id, int scenario_train_id, int vehicle_index, const Common::Properties &properties, unsigned long simulation_start_time)
    :  m_train_watcher(tpw), m_properties(properties), m_gateway(gateway), m_section_base(section_base), m_logical_hub_id(logical_hub_id), m_scenario_train_id(scenario_train_id), m_vehicle_index(vehicle_index), m_simulation_start_time(simulation_start_time)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "FlightSimUnitV2::FlightSimUnitV2 Constructor " << Trace::EndLog();
}

//Comms::UnitCreators FlightSimUnitV2::DefineSession(Comms::Gateway &gateway)
	Comms::UnitCreators FlightSimUnitV2::InitialiseSession()
{
	// Store our units in a vector.
    Comms::UnitCreators ret;


	try
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << m_section_base << " Unit Starting " << Trace::EndLog();

        // Get the COM port details from the Properties file.
        string port         = m_properties.GetProperty<string>(m_section_base, "Port", "COM Port Undefined!");
        int    baud_rate    = m_properties.GetProperty<int>(m_section_base, "Baud Rate", CBR_38400);
        int    data_bits    = m_properties.GetProperty<int>(m_section_base, "Data Bits", 8);
        int    parity       = m_properties.GetProperty<int>(m_section_base, "Parity", NOPARITY);
        int    stop_bits    = m_properties.GetProperty<int>(m_section_base, "Stop Bits", ONESTOPBIT);
        int    poll_period  = m_properties.GetProperty<int>(m_section_base, "Poll Period", 100);
        int    poll_retries = m_properties.GetProperty<int>(m_section_base, "Poll Retries", 3);
        double cmd_delay    = m_properties.GetProperty<double>(m_section_base, "Command Delay", 0);

        // Create the FlightSimHardware device that will manage all FlightSim devices registered to this Port.
        m_phardware.reset(new FlightSimHardwareV2(port.c_str(), baud_rate, data_bits, parity, stop_bits, poll_period, poll_retries, cmd_delay));

        Trace::g_plog->STAMP(Trace::INFO) << "FlightSimHardwareV2 controller initialised on port " << port << Trace::EndLog();
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Could not create FlightSimUnitV2 hardware");
        throw;
    }

	// Search the Properties file for Serial Devices Units that are defined for the COM port.
    // They are defined in sections that starts with the Section base and ends with ".DeviceTypeName"
    vector<string> sections = m_properties.ListSections();
    for(vector<string>::const_iterator i = sections.begin(); i != sections.end(); ++i)
    {
        if (i->compare(m_section_base + ".ATPSpeedo") == 0)
        {
            try
            {
                // Only create the Unit if the Active Flag is set.
                /*if (m_properties.GetProperty<bool>(m_section_base + ".ATPSpeedo", "Active", true))
				{
					std::shared_ptr<ATPSpeedoUnit> atpspeedo_ptr(new ATPSpeedoUnit(m_section_base + ".ATPSpeedo", m_gateway, m_logical_hub_id, m_scenario_train_id, m_vehicle_index, m_properties, *m_phardware.get(), m_simulation_start_time));
				    ret.push_back([atpspeedo_ptr]() { return atpspeedo_ptr; });
				}*/
            }                                           
            catch(CommonException &e)
            {
                // Log this exception. We can still create the units for the
                // other automatic trains.
                e.AddStackTrace(FLSTAMP, "Creating FlightSim ATP Speedo Hardware unit");
                Trace::g_plog->LogException(e);
            }

        }

		if (i->compare(m_section_base + ".ATPSpeedoTest") == 0)
        {
            try
            {
                // Only create the Unit if the Active Flag is set.
                /*if (m_properties.GetProperty<bool>(m_section_base + ".ATPSpeedoTest", "Active", true))
				{
					std::shared_ptr<ATPSpeedoTestUnit> atpspeedotest_ptr(new ATPSpeedoTestUnit(m_section_base + ".ATPSpeedoTest", m_gateway, m_train_watcher, m_vehicle_index, m_properties, *m_phardware.get(), m_simulation_start_time));
					ret.push_back([atpspeedotest_ptr]() { return atpspeedotest_ptr; });
				}*/
            }                                           
            catch(CommonException &e)
            {
                // Log this exception. 
                e.AddStackTrace(FLSTAMP, "Creating FlightSim ATP Speedo Test Hardware unit");
                Trace::g_plog->LogException(e);
            }

        }

    }

    // NB!!! It is a requirement of the Master Slave Architecture adopted here that the Generic FlightSimHardware
    //       polling thread is only started AFTER all the Child units have been created. It is the Child Units duty
    //       to Register a callback with the FlightSim Hardware during construction, and to de-register the callback
    //       on destruction (Or failure during construction). Child Units may not change Registrations once the Hardware 
    //       is started.

    // Start the Hardware thread once all Child units are created.
    m_phardware->Startup();


	return ret;
}

FlightSimUnitV2::~FlightSimUnitV2()
{
    // Stop the hardware polling thread before Killing the Child Units.
	if (m_phardware.get() != nullptr)
       m_phardware->Shutdown();

	Trace::g_plog->STAMP(Trace::VERBOSE) << "FlightSimUnitV2::FlightSimUnitV2 Destructor " << Trace::EndLog();

}


