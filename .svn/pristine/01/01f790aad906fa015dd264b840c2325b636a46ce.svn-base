//******************************************************************************
//
//  File:           FlightSimGaugeUnit.h
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

// Original Commands - For Most other Gauges
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

// Speedometer Specific Commands:
//   '  0= noop/forbidden
//   '  1= Initialize
//   '  2= Set Instrument Address; Value 0-&hff (odd addr. only),second byte:&HAA
//   '  3= Not used
//   '  4= Not used
//   '  5= Set Speed (0-180) 0x0000 to 0x00B4
//   '  6= Not used
//   '  7= Send info about instrument; Reply &h00, Address, Type, Model, Version, various statuses/values
//   '  8= Switch lights: Low byte= DLI0.xxxx; D=display on/off, 
//                                             L=backlight on/off
//   '                                         I0.xxxx:If I=1 then set Dimmer value xxxx.(0-15)
//   '  9= Not used
//   ' 10= Set Leading Zero mode:  0=Show leading zero's, 1=delete leading zero's
//   ' 11= Not used
//   ' 12= Not used
//   ' 13= Set Display brightness Digits;    Low byte 000X.IIII: X=0:Set day, 1=Set:night. IIII = Intensity  (0-15)
//   ' 14= Set Display brightness Speed bar; Low byte 000X.IIII: X=0:Set day, 1=Set:night. IIII = Intensity  (0-15)
//   ' 15= Not used
//
//
//  (C) Copyright:  SYDAC Pty Ltd, 2011
//
//******************************************************************************
#ifndef FLIGHTSIM_GAUGE_UNIT_H
#define FLIGHTSIM_GAUGE_UNIT_H

#include "sim_comms/Unit.h"
#include "world_api/TrainPathWatcher.h"

#include "common/Properties.h"
#include "Hardware/FlightSimGaugeHardware.h"

//  Class:          FlightSimGaugeUnit
//
//  Description:    Serial Device - Flight Sim Gauge

class FlightSimGaugeUnit : public Comms::SessionUnit
{
public:
    // Constructor. No listeners used, so no need for a destructor.
    FlightSimGaugeUnit(Comms::Gateway &gateway, WorldAPI::TrainPathWatcher &tpw, int vehicle_index, const Common::Properties &properties, unsigned long simulation_start_time);
    ~FlightSimGaugeUnit();

    std::string GetName() const override{ return "FlightSim Gauge Unit"; }

private:
    WorldAPI::TrainPathWatcher &m_train_watcher;
    Comms::Object m_vehicle_output_object;

    void TrainCreation(Comms::Object object);
    void TrainChildCreated(Comms::Object object);
    void VehicleOutputDestruction(Comms::Object object);

    // Timer
    OS::Event   m_kill_thread;
    OS::Thread *m_pthread;

    unsigned long TimerThread();

    void TimerCallback();

    struct FlightSimGauge
    {
        // Configuration
        std::string property_name;
        std::string power_property_name;
        int gauge_address;
        bool first_needle;
        std::string backlight_property_name;
        bool duel_scale;
        int min_position;
        int centre_position;
        int max_position;
        double min_value;
        double centre_value;
        double max_value;
        double default_value;
		std::string red_light_property_name;

        Sim::Number value_property;
        Sim::Number backlight_property;
		Sim::Number red_light_property;
    };

    std::vector<FlightSimGauge>   m_flightSimGauges;

    FlightSimGaugeHardware* m_phardware;

    void UpdateFlightSimGaugePositions();
    void UpdateFlightSimGaugeBackLights();
	void UpdateFlightSimRedLight();

    double ScaleAndClip(double input, double min_input, double max_input, double min_output, double max_output);

    int           m_vehicle_index;
};

#endif //FLIGHTSIM_GAUGE_UNIT_H
