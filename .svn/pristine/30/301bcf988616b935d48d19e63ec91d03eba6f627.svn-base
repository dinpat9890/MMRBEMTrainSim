/// @file       InputCommsInterface declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#ifndef  INPUT_COMMS_INTERFACE_H
#define  INPUT_COMMS_INTERFACE_H

#include <functional>
#include <mutex>

#include <core_types/SessionData.h>
#include <sim_comms/Unit.h>
#include <common/Properties.h>
#include <common/DataAccess.h>
#include <world_api/WorldAccess.h>

#include "ConstantDefined.h"
#include "OutputCommsInterface.h"
#include "EventHandler.h"

namespace PIS::Announcement { class MessageController; }
namespace PIS::Intercom     { class EventHandler; }

namespace PIS
{
    namespace Intercom
    {
        /// IntercomCommsInterface creates a Comms interface to 
        /// listen on Input comms changes and update Output comms properties 
        /// for the Public Address operations triggered by the driver

        class InputCommsInterface
        {
        public:

            InputCommsInterface(Comms::Gateway&                                     gateway,
                                const Common::Properties&                           module_props,
                                const Common::Properties&                           unit_props,
                                const int                                           scenario_train_id,
                                std::shared_ptr<Announcement::MessageController>    m_message_controller);

        private:

             // Object creation callbacks
            void CommsObjectCreated(Comms::Object                       comms_object);
            void TrainObjectCreated(Comms::Object                       train_object);
            void OHPInputsObjectCreated(Comms::Object                   ohp_inputs_object);
            void OHPOutputsObjectCreated(Comms::Object                  ohp_outputs_object);
            void EmergencyBrakeLeverInputsObjectCreated(Comms::Object   emergency_brake_lever_inputs_object);
            void IntercomInputsObjectCreated(Comms::Object              intercom_inputs_object);
            void IntercomOutputsObjectCreated(Comms::Object             intercom_outputs_object);
            void SCCFaultEventsIntercomInputsObjectCreated(Comms::Object scc_fault_events_intercom_inputs_object);

            // Object destruction callback
            /*void OHPOutputObjectDestroyed(Comms::Object               ohp_outputs_object);
            void EmergencyBreakLeaverInputObjectDestroyed(Comms::Object emergency_break_leaver_object);*/

            // Intercom Inputs button state changed callback
            void InPAButtonStateChanged(Sim::Number              event_state);
            void OutPAButtonStateChanged(Sim::Number             event_state);
            void IntercomButtonStateChanged(Sim::Number          event_state);
            void CancelButtonStateChanged(Sim::Number            event_state);
            void SCCIntercomButtonStateChanged(Sim::Number       event_state);
            void SCCIntercomCancelButtonStateChanged(Sim::Number event_state);
            void OHPButtonStateChanged(Sim::Number               event_state, int vehicle_id, int ohp_id);
            void OHP_ID_StateChanged(Sim::Number                 event_state);
            void EmergencyBreakLeaverStateChanged(Sim::Number    event_state, double vehicle_id, double ohp_id, double emergency_break_leaver_id);
            void FaultEDRActivatedStateChanged(Sim::Number       event_state, int vehicle_id, int ohp_id);

            void OnButtonPressed(const PIS::Intercom::Message&  call_data);
            void OnButtonReleased(const PIS::Intercom::Message& call_data);
            void RadioAudioEnable(const Sim::Number &num_obj);

            void IsolateCB(const Sim::Number &num_obj);
            void DeIsolateCB(const Sim::Number &num_obj);

            void SetIntercomState(IntercomCallState intercom_state);
            void SetOHP_Id(int ohp_id);
            void SetOHP_Status(Status ohp_status);
            void SetInputValuesOHPPEId(int ohp_id);
            void SetIntercomOutputsIntercom(IntercomCallState intercom_state);
            void SetIntercomOutputsActiveCallType(ActiveCallType active_call_type);
            
            // Synchronization
            std::recursive_mutex                                    m_mutex;

            // scenario train id
            const int                                               m_scenario_train_id;

            // Comms
            Comms::Gateway&                                         m_gateway;

            // MessageController
            std::shared_ptr<PIS::Announcement::MessageController>   m_controller;

            PIS::Interface::EventHandler                            m_event_handler;

            bool                                                    m_ohp_output_object_number_ids_retrieved;
            Comms::Object                                           m_pis_inputs_comms;
            Comms::Object                                           m_ohp_comms;
            Sim::Number::ID                                         m_intercom_status_property_id;
            Sim::Number::ID                                         m_ohp_id_property_id;
            Sim::Number::ID                                         m_ohp_status_property_id;
            Sim::Number::ID                                         m_input_ohp_id_property_id;
            Sim::Number::ID                                         m_output_intercom_property_id;
            Sim::Number::ID                                         m_output_active_call_type_property_id;
            int                                                     m_radio_intercom_state = 0 ;
            int                                                     m_multiple_end_call_count = 0;

            Comms::Object                                           m_intercom_outputs_object;
            Comms::Object                                           m_ohp_inputs_object;
            Comms::Object                                           m_ohp_outputs_object;

            std::vector <double>                                    m_allIsolatedCalls;
            int                                                     m_currentIsolatedCall{ 0 };
            double                                                  m_currentDeIsolatedCall{ 0 };
            std::vector<int>                                        m_iso_call_list
            {
                0,0,0,0,
                0,0,0,0,
                0,0,0,0,
                0,0,0,0,
                0,0,0,0,
                0,0,0,0,
                0,0,0,0,
                0,0,0,0
            }; // index = pecu no and value = iso or de iso
        };

    }
}

#endif // ! INPUT_COMMS_INTERFACE_H
