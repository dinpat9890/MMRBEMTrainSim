//******************************************************************************
//
//  File:           FlightSimGaugeUnit.cpp
//
//  Description:    Serial Device - Flight Sim Gauge
//
//  Reference:      Lithuania Freight Simulator
//
//  Author:         Adrian James
//
//  Comments: This interface has been based on the following information.
//
//--------------------------------------------------------------
// G-Step VOR-1  Moduletype 106
//
// Version 1, Date:17 juni 2008
//
//--------------------------------------------------------------
// Commands from control PC
// Message layout:
//
// Byte 1: Flag byte:&h00
// Byte 2: Address: 1-255; (Adress 0 excluded)
// Byte 3: Command: CCCC.1SHL (CCCC=Command 1-15, S= Signbit, H & L are databits)
//                    The integer is unsigned 16 bits.
// Byte 4: Data Low; &h00-&hFF;  bit0 always 1 : XXXX.XXX1 -> XXXX.XXXL
// Byte 5: Data Hight:&h00-&hFF: bit1 always 1 : XXXX.XX1X -> XXXX.XXHX
// Byte 6: LPC Check byte or &hFF

// Commands:
//  0= noop
//  1= Initialize
//  2= Set Instrument Address; Value &h01-&hff (address 0 forbidden),second byte:&HAA
//  3= Set Instrument speed for Needle1
//  4= Calibrate Localiser Needle to center (delta from 472)
//  5= New needle1 position; Value 0-&h7fff
//  6= New needle2 position; Value 0-&h7fff (not applicable)
//  7= Send info about instrument; Reply &h00, Address, Type, Model, Version,
//  8= Switch lights: Low byte= DL00.0000; D=display on/off, L=light on/off
//  9= Calibrate Glide Slope Needle to center (delta from 472)
// 10= set indicator disk to a defined position. Low Byte=position number
// 11= Set compass disk to 0 (north)
// 12= rotate indicator disk indicator (for calibration).
// 13= Set indicator disk position. Integer: IPPP; I is position 0-7, PPP=diskposition (0-4000)
// 14= Set speed indicator disk
//
//  (C) Copyright:  SYDAC Pty Ltd, 2011
//
//******************************************************************************
#include "FlightSimGaugeUnit.h"

#include "utility/Utilities.h"
#include "project_comms_structure/ProjectObjectConstants.h"

#include "common/StandardLogging.h"

using namespace Sim;
using namespace std;

namespace
{
    const double UPDATE_FREQUENCY  = 20.0;
    const double REQUEST_FREQUENCY = 10.0;
    const double CYCLE_FREQUENCY   = 2.0;

};

//  Function:       FlightSimGaugeUnit::FlightSimGaugeUnit
//
//  Description:    Constructor. Creates hardware
//
//  Parameters:
//      Framework::Gateway &gateway - Gateway
//      const Sydac::Properties &properties - properties for extracting servos

FlightSimGaugeUnit::FlightSimGaugeUnit(Comms::Gateway &gateway, WorldAPI::TrainPathWatcher &tpw, int vehicle_index, const Common::Properties &properties, unsigned long simulation_start_time)
    : SessionUnit(gateway), m_train_watcher(tpw), m_phardware(0), m_pthread(0), m_vehicle_index(vehicle_index)
{
    try
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << "FlightSimGaugeUnit : Waiting for scenario train Vehicle with Vehicle index = " << m_vehicle_index << Trace::EndLog();

        // Naughty, Naughty Adrian - Should have a SessionAnalyserProperties class to handle all this!!!
        string port = properties.GetProperty<string>("Flight Sim Gauges", "Port", "COM Port Undefined!");
        int baud_rate = properties.GetProperty<int>("Flight Sim Gauges", "Baud Rate", CBR_38400);
        int data_bits = properties.GetProperty<int>("Flight Sim Gauges", "Data Bits", 8);
        int parity = properties.GetProperty<int>("Flight Sim Gauges", "Parity", NOPARITY);
        int stop_bits = properties.GetProperty<int>("Flight Sim Gauges", "Stop Bits", ONESTOPBIT);

        m_phardware = new FlightSimGaugeHardware(port.c_str(), baud_rate, data_bits, parity, stop_bits);
        Trace::g_plog->STAMP(Trace::INFO) << "Fight Sim Gauge controller on port " << port << Trace::EndLog();
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Could not create hardware");
        throw;
    }

    // For all groups labelled "Gauge *", extract properties
    vector<string> sections = properties.ListSections();
    m_flightSimGauges.reserve(sections.size());
    for(vector<string>::const_iterator i = sections.begin(); i != sections.end(); ++i)
    {
        if(*i == "Gauge" || i->size() >= 6 && i->substr(0, 6) == "Gauge ")
        {
            if(properties.GetProperty<bool>(*i, "Active", true))
            {
                try
                {
                    FlightSimGauge s;
                    s.property_name = properties.GetProperty<string>(*i, "Property");
                    s.gauge_address  = properties.GetProperty<int>(*i, "Gauge Address");
                    s.first_needle = properties.GetProperty<bool>(*i, "First Needle");
                    s.duel_scale = properties.GetProperty<bool>(*i, "Duel Scale",0);
                    s.backlight_property_name = properties.GetProperty<string>(*i, "Backlight Property","");
                    s.min_position  = properties.GetProperty<int>(*i, "Minimum Position");
                    s.centre_position = properties.GetProperty<int>(*i, "Centre Position",0);
                    s.max_position  = properties.GetProperty<int>(*i, "Maximum Position");
                    s.min_value = properties.GetProperty<double>(*i, "Minimum Value");
                    s.centre_value = properties.GetProperty<double>(*i, "Centre Value",0);
                    s.max_value = properties.GetProperty<double>(*i, "Maximum Value");
                    s.default_value  = properties.GetProperty<double>(*i, "Default Value");
                    s.value_property.value = s.default_value;
                    // Bug 42586 - Default the value of the backlight to on so that they get turned off at startup.
                    s.backlight_property.value = 1;
                    // Similar to above the red light defaults to on, so to trigger a comms update set it's initial value to 1
                    s.red_light_property.value = 1;

                    s.red_light_property_name = properties.GetProperty<string>(*i, "Red Light Property","");

                    m_flightSimGauges.push_back(s);

                    Trace::g_plog->STAMP(Trace::INFO) << *i << " is active. (" << s.gauge_address << " - " << s.property_name  << ")" << Trace::EndLog();
                }
                catch (CommonException &e)
                {
                    e.AddStackTrace(FLSTAMP, ("Getting properties of " + *i).c_str());
                    Trace::g_plog->LogException(e);
                }
            }
        }

    }

    // Use default values until a train is found
    UpdateFlightSimGaugePositions();

    // Use default values until a train is found
    UpdateFlightSimGaugeBackLights();

    // Create the Timer Thread
    m_pthread = new OS::Thread(MakeCallback(&FlightSimGaugeUnit::TimerThread, this));

    // Register for interest in the train
    {
        const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());

        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(m_train_watcher);
        m_train_watcher.AddTrainCreationCallback(MakeCallback(&FlightSimGaugeUnit::TrainCreation, this));
    }

}

//  Function:       FlightSimGaugeUnit::UpdateFlightSimGaugePositions
//
//  Description:    Updates the positions of flight sim gauges by calling the hardware,
//                  if it exists.

void FlightSimGaugeUnit::UpdateFlightSimGaugePositions()
{
    if(m_phardware)
    {

        for(std::vector<FlightSimGauge>::iterator i = m_flightSimGauges.begin(); i != m_flightSimGauges.end(); ++i)
        {
            if(m_vehicle_output_object.IsValid())
            {
                if (i->value_property.id != Sim::INVALID_NUMBER)
                {

                    m_vehicle_output_object.Numbers().Store().Get(i->value_property);

                    double position;

                    if (i->duel_scale)
                    {
                        if (i->value_property.value < i->centre_value)
                            position = ScaleAndClip(i->value_property.value, i->min_value, i->centre_value, i->min_position, i->centre_position);
                        else
                            position = ScaleAndClip(i->value_property.value, i->centre_value, i->max_value, i->centre_position, i->max_position);
                    }
                    else
                        position = ScaleAndClip(i->value_property.value, i->min_value, i->max_value, i->min_position, i->max_position);

                    //Trace::g_plog->STAMP(Trace::INFO) << "Updating Flight Sim Gauge Address '" << i->gauge_address << "', needle : '" << i->first_needle << "' value :" << i->property.value << "' gauge value: " << position <<  Trace::EndLog();
                    m_phardware->SetPosition(i->gauge_address, i->first_needle, position);
                }
            }
        }
    }
}

//  Function:       FlightSimGaugeUnit::UpdateFlightSimGaugeBackLights
//
//  Description:    Updates the back light states of flight sim gauges by calling the hardware,
//                  if it exists.

void FlightSimGaugeUnit::UpdateFlightSimGaugeBackLights()
{
    if(m_phardware)
    {
        for(std::vector<FlightSimGauge>::iterator i = m_flightSimGauges.begin(); i != m_flightSimGauges.end(); ++i)
        {

            if(m_vehicle_output_object.IsValid() && i->backlight_property.id != Sim::INVALID_NUMBER)
            {
                double old_backlight_value = i->backlight_property.value;
                m_vehicle_output_object.Numbers().Store().Get(i->backlight_property);

                if (i->backlight_property.value != old_backlight_value)
                {
                    int intensity = static_cast<int>(i->backlight_property.value);

                    if (i->backlight_property.value > 0)
                        m_phardware->SetLights(i->gauge_address, true, true, intensity);
                    else
                        m_phardware->SetLights(i->gauge_address, true, false, intensity);
                }
            }
            else if (i->backlight_property.id != Sim::INVALID_NUMBER)
            {
                int intensity = static_cast<int>(i->backlight_property.value);

                if (i->backlight_property.value > 0)
                    m_phardware->SetLights(i->gauge_address, true, true, intensity);
                else
                    m_phardware->SetLights(i->gauge_address, true, false, intensity);
            }

        }
    }
}

//  Function:       FlightSimGaugeUnit::UpdateFlightSimRedLight
//
//  Description:    Updates the red light value

void FlightSimGaugeUnit::UpdateFlightSimRedLight()
{
    if(m_phardware)
    {
        for(std::vector<FlightSimGauge>::iterator i = m_flightSimGauges.begin(); i != m_flightSimGauges.end(); ++i)
        {

            if(m_vehicle_output_object.IsValid() && i->red_light_property.id != Sim::INVALID_NUMBER)
            {
                double old_red_light_value = i->red_light_property.value;
                m_vehicle_output_object.Numbers().Store().Get(i->red_light_property);

                if (i->red_light_property.value != old_red_light_value)
                {
                    if (i->red_light_property.value == 1.0)
                        m_phardware->SetRedLight(i->gauge_address, true);
                    else
                        m_phardware->SetRedLight(i->gauge_address, false);
                }
            }
            else if (i->red_light_property.id != Sim::INVALID_NUMBER)
            {
                if (i->red_light_property.value == 1.0)
                    m_phardware->SetRedLight(i->gauge_address, true);
                else
                    m_phardware->SetRedLight(i->gauge_address, false);
            }

        }
    }
}

//  Function:       FlightSimGaugeUnit::~FlightSimGaugeUnit
//
//  Description:    Leaves gauges as they are. Destroys hardware.

FlightSimGaugeUnit::~FlightSimGaugeUnit()
{
    m_kill_thread.Set();
    m_pthread->GetHandle().Wait();
    delete m_pthread;

    // Ensure last values are set
    // Must do this after the thread is finished
    {
        const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());
        UpdateFlightSimGaugePositions();

    }
    ::Sleep(100);
    delete m_phardware;
}

//  Function:       FlightSimGaugeUnit::TrainCreation
//
//  Description:    Part of the chain of finding the Vehicle Outputs object.

void FlightSimGaugeUnit::TrainCreation(Comms::Object object)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainCreation : Scenario Train ID = " << object.GetID() << Trace::EndLog();

    AddCreationCallback(object, MakeCallback(&FlightSimGaugeUnit::TrainChildCreated, this));
}

//  Function:       ServoUnit::TrainChildCreated
//
//  Description:    Requests and retrieves on all needed properties and performs an initial update.

void FlightSimGaugeUnit::TrainChildCreated(Comms::Object object)
{

    if (Core::GetClassID(object) == Project::ClassID::VEHICLE)
    {
        // If this matches the vehicle index for the Hub, register for child creations
        int index = static_cast<int>(object.Numbers().Get(Project::ValueName::Vehicle::INDEX));

        // New PPP Comms - The DCO is now the Vehicle Outputs class and is a child
        // of Vehicle. Thus we need the vehicle index associated with the Hub to get it.
        if (index == m_vehicle_index)
        {
            Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainChildCreated : Vehicle Index = " << index << Trace::EndLog();

            AddCreationCallback(object, MakeCallback(&FlightSimGaugeUnit::TrainChildCreated, this));
        }
    }
    else if (Core::GetClassID(object) == Project::ClassID::VEHICLE_OUTPUTS)
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainChildCreated : VEHICLE_OUTPUTS" << Trace::EndLog();

        // Need a Destruction Callback as a copy of this object is kept for access to the servo property
        AddDestructionCallback(object, MakeCallback(&FlightSimGaugeUnit::VehicleOutputDestruction, this));

        std::vector<Sim::NumberInfo> request_info;
        std::vector<Sim::Number>     retrieves;

        // Each Servo is driven by a Vehicle Output Property
        for(std::vector<FlightSimGauge>::iterator i = m_flightSimGauges.begin(); i != m_flightSimGauges.end(); ++i)
        {
            // Lookup the Property by name
            if((i->value_property.id = object.Numbers().Info().GetID(i->property_name)) == Sim::INVALID_NUMBER)
            {
                i->value_property.value = i->default_value;
                Trace::g_plog->STAMP(Trace::WARN) << "TrainChildCreated : Flight Sim Gauge Property not found: '" << i->property_name << "'" << Trace::EndLog();
            }
            else
            {
                Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainChildCreated : Found Gauge Property '" <<i->property_name << "' with id " << i->value_property.id  << Trace::EndLog();

                request_info.push_back(object.Numbers().Info().GetInfo(i->value_property.id));
                retrieves.push_back(i->value_property);
            }

            // Lookup the Backlight Property by name
            /*if((i->backlight_property.id = object.Numbers().Info().GetID(i->backlight_property_name)) == Sim::INVALID_NUMBER)
            {
                i->backlight_property.value = i->default_value;
                Trace::g_plog->STAMP(Trace::WARN) << "TrainChildCreated : Flight Sim Backlight Property not found for gauge: '" << i->property_name << "'" << Trace::EndLog();
            }
            else
            {
                Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainChildCreated : Found Backlight Property '" <<i->backlight_property_name << "' with id " << i->backlight_property.id  << Trace::EndLog();

                request_info.push_back(object.Numbers().Info().GetInfo(i->backlight_property.id));
                retrieves.push_back(i->backlight_property);
            }*/

            // Lookup the Backlight Property by name
            /*if((i->red_light_property.id = object.Numbers().Info().GetID(i->red_light_property_name)) == Sim::INVALID_NUMBER)
            {
                i->red_light_property.value = i->default_value;
                Trace::g_plog->STAMP(Trace::WARN) << "TrainChildCreated : Flight Sim Red Light Property not found for gauge: '" << i->property_name << "'" << Trace::EndLog();
            }
            else
            {
                Trace::g_plog->STAMP(Trace::VERBOSE) << "TrainChildCreated : Found Red Light Property '" <<i->red_light_property_name << "' with id " << i->red_light_property.id  << Trace::EndLog();

                request_info.push_back(object.Numbers().Info().GetInfo(i->red_light_property.id));
                retrieves.push_back(i->red_light_property);
            }*/
        }

        object.Numbers().Store().Request(request_info.begin(), request_info.end(), REQUEST_FREQUENCY);
        object.Numbers().Store().Retrieve(retrieves.begin(), retrieves.end());

        m_vehicle_output_object = object;
    }
}

//  Function:       FlightSimGaugeUnit::VehicleOutputDestruction
//
//  Description:    Goes back to the default values

void FlightSimGaugeUnit::VehicleOutputDestruction(Comms::Object object)
{
    m_vehicle_output_object.Invalidate();

    // Use defaults now
    for(std::vector<FlightSimGauge>::iterator i = m_flightSimGauges.begin(); i != m_flightSimGauges.end(); ++i)
    {
        i->value_property.value = i->default_value;
        i->backlight_property.value = i->default_value;
    }

}

//  Function:       ServoUnit::TimerThread
//
//  Description:    The timer thread. Allows a callback on a timer.

unsigned long FlightSimGaugeUnit::TimerThread()
{
    double timer_period = 1 / UPDATE_FREQUENCY;

    OS::Timer  timer_end;
    OS::OSTime time_end;
    OS::OSTime time_period;
    time_end.seconds = 0;
    time_end.nano_seconds = 0;
    time_period.seconds = static_cast<int>(timer_period);
    time_period.nano_seconds = static_cast<int>((timer_period - static_cast<double>(time_end.seconds)) * 1000000000.0);

    timer_end.Set(time_end, true, time_period);

    std::vector<OS::Handle*> handles;
    handles.push_back(&m_kill_thread);
    handles.push_back(&timer_end);

    while(OS::Handle::Wait(handles) > 0)
    {
        const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());
        TimerCallback();
    }

    return 0;
}

//  Function:       FlightSimGaugeUnit::ScaleAndClip
//
//  Description:    Updates the display.

double FlightSimGaugeUnit::ScaleAndClip(double input, double min_input, double max_input, double min_output, double max_output)
{
    if(min_output == max_output)
        return min_output;

    if (min_output > max_output)
    {
        swap(min_output, max_output);
        swap(min_input, max_input);
    }

    return max(min_output, min(max_output, min_output + (input - min_input) * (max_output - min_output) / (max_input - min_input)));
}

//  Function:       ServoUnit::TimerCallback
//
//  Description:    Updates the display.

void FlightSimGaugeUnit::TimerCallback()
{
    UpdateFlightSimGaugePositions();
    UpdateFlightSimGaugeBackLights();
    UpdateFlightSimRedLight();

}
