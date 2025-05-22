// @file       IntercomOutput declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#ifndef INTERCOM_OUTPUT_H
#define INTERCOM_OUTPUT_H

#include <map>
#include <set>

#include "ConstantDefined.h"

using namespace PIS::Intercom;

namespace PIS
{
    namespace Intercom
    {
        class OutputCommsInterface
        {
        public:
            OutputCommsInterface(Comms::Gateway&  gateway);
            ~OutputCommsInterface();

            void SetPAState(const IO state);
            void SetPALightState(const PAOutput pa_light, const PIS::Intercom::IO state);
            void SetIntercomLightState(const IO state);
            void SetIntercomState(const IntercomCallState state);
            void SetOHPChimeState(const State state);
            void SetActiveCallType(const ActiveCallType active_call_type);
            void SetOHPStatus(Comms::Object ohp_object_info, const Status status);
            void SetPEId(Comms::Object ohp_object, int pe_id);
            void SetOHPId(Comms::Object ohp_object, int ohp_id);
            void SetVehId(Comms::Object ohp_object, int vehicle_id);
            void SetRawIsoCalls(Comms::Object ohp_object, std::vector<int> allIsoCalls);
            void SetOHPIndicatorState(Comms::Object ohp_object_info, const OHPOutputs ohp_indicator, const IO state);

            void SetIntercomOutputPropertyID(std::string type, const Sim::Number::ID property_id);
            void SetOHPOutputPropertyID(std::string type, const Sim::Number::ID property_id);
            void SetOHPObject(const Comms::Object ohp_object, const OHPID ohp_uid);
            void SetIntercomOHPObject(const Comms::Object ohp_object);
            Comms::Object GetIntercomOHPObject();
            void SetEmergencyBreakeLeaverID(const int emergency_break_id, const OHPID ohp_uid);
            void SetIntercomObject(const Comms::Object);

            Comms::Object GetIntercomOutputObject() const;
            Comms::Object GetOHPOutputObject(const MessageID& uid);

        private:

            double FlashingTimerCallback(double time);

        private:

            std::recursive_mutex                    m_mutex;

            Comms::Object                           m_intercom_outputs_object;

            // Comms Gateway
            Comms::Gateway&                         m_gateway;

            // Map of ohp_id to ohp_output_object
            std::map<OHPID, Comms::Object>          m_ohp_Objects;
            
            // Map of emergency break to ohp_id
            std::set<MessageID>                     m_eb_ohp_map;

            // Map of properties name and ID
            std::map<std::string, Sim::Number::ID>  m_property_ids;

            // Blinking outputs
            Comms::SessionOperations::TimerID m_flashing_timer_id;
            bool                              m_intercom_light_flashing = false;
            Comms::Object                     m_ohp_output_object;
        };
    }
}

#endif INTERCOM_OUTPUT_H // !INTERCOM_OUTPUT_H
