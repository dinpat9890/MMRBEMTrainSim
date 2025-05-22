/// @file      IntercomCommsInterface definition
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include <sim_common/Listener.h>
#include <project_comms_structure/ProjectObjectConstants.h>
#include <project_comms_structure/ProjectObjectDefinition.h>
#include <Utility/Utilities.h>

#include "InputCommsInterface.h"
//#include "PISAudioControllerProxy/AudioControllerProxy.h"
#include "Intercom.h"
#include "SCC.h"
#include "SCCCancel.h"
#include "OHP.h"
#include "EmergencyBreak.h"
#include "InPA.h"
#include "OutPA.h"
#include "Cancel.h"
#include "..\..\units\UnitsCommonCode\include\CommsPropertyAccessors.h"
#include <algorithm>

namespace
{
    const auto REQUEST_FREQUENCY = 0.0;

    using  NumberListener   = Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>;
    using  RawListener      = Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Raw>>;

    using  NumberCallback   = std::function<void(Sim::Number number)>;
    using  NumberToCbMap    = std::map<std::string, NumberCallback>;

    /// @brief Adds listener and callback to faults.
    ///
    /// @param property_map     faults which we are interested in state change.
    /// @param object           Comms object which you are intersted in the state change.
    void AddNumberListeners(const NumberToCbMap & property_map, Comms::Object &object)
    {
        NumberListener num_listener;
        for (auto &auto_property : property_map)
        {
            auto  property_name     = auto_property.first;
            auto number_cb          = auto_property.second;

            Sim::Number property_number     = object.Numbers().Get(property_name);
            if (property_number == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << property_name << " is not a valid number in Comms Object, hence ignoring." << Trace::EndLog();
            }
            else
            {
                num_listener.AddCallback(property_number, number_cb);

                Sim::NumberInfo number_info = object.Numbers().Info().GetInfo(property_number.id);
                object.Numbers().Store().Request(number_info, REQUEST_FREQUENCY);
            }
        }

        object.Numbers().Store().AddListener(num_listener);
    }

}


namespace PIS
{
    namespace Intercom
    {
        InputCommsInterface::InputCommsInterface(Comms::Gateway&                                              gateway,
                                                 const Common::Properties&                                    module_props,
                                                 const Common::Properties&                                    unit_props,
                                                 const int                                                    scenario_train_id,
                                                 std::shared_ptr<PIS::Announcement::MessageController>        m_message_controller)
            : m_gateway(gateway), m_scenario_train_id(scenario_train_id), m_controller(m_message_controller), m_ohp_output_object_number_ids_retrieved(false)
        {
            // We need a lock to access the root object
            OS::Lock<Comms::Gateway> lock(gateway);

            AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectCreated(object); });

            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_CAB, std::make_shared<PIS::Interface::CAB>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_SCC, std::make_shared<PIS::Interface::SCC>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_SCC_CANCEL, std::make_shared<PIS::Interface::SCCCancel>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_CANCEL, std::make_shared<PIS::Interface::Cancel>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_OHP, std::make_shared<PIS::Interface::OHP>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::IC_EBM, std::make_shared<PIS::Interface::EmergencyBreak>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::PA_IN, std::make_shared<PIS::Interface::InPA>());
            m_event_handler.RegisterEvent(PIS::Intercom::MessageType::PA_OUT, std::make_shared<PIS::Interface::OutPA>());
        }

        void InputCommsInterface::RadioAudioEnable(const Sim::Number &num_obj)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            m_radio_intercom_state = static_cast<int>(num_obj.value);
        }

        /// @brief This function is called whenever interested object created.
        ///         This will also registers callback for interested comms child objects.
        ///
        /// @param object               Comms Object
        void InputCommsInterface::CommsObjectCreated(Comms::Object object)
        {
            const auto class_id = Core::GetClassID(object);

            if (class_id == Core::ClassID::WORLD)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            }
            else if (class_id == Train::ClassID::TRAIN)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
                TrainObjectCreated(object);
            }
            else if (class_id == Project::ClassID::VEHICLE)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            }
            else if (class_id == Project::ClassID::PIS_BE)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            }
            else if (class_id == Project::ClassID::PIS_BE_INPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            }
            else if (class_id == Project::ClassID::PIS_BE_INPUTS_VALUES)
            {
                m_pis_inputs_comms = object;
                if (m_pis_inputs_comms.IsValid())
                {
                    m_intercom_status_property_id = m_pis_inputs_comms.Numbers().Info().GetID(Project::ValueName::PISBEInputs::INTERCOM_STATUS);
                }
                
            }
            else if (class_id == Project::ClassID::RADIO_INTERCOM)
            {

                auto scenario_train_id = object.GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
                if (scenario_train_id == m_scenario_train_id)
                {
                    Comms::AddCreationCallback(object, MakeCallback(&InputCommsInterface::CommsObjectCreated, this));
                }
            }
            else if (class_id == Project::ClassID::RADIO_INTERCOM_OUTPUTS)
            {
                // Register listener for Radio Intercom state change

                NumberListener num_listener;
                Sim::Number number = object.Numbers().Get(Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE);
                if (number.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE
                        << " is not a valid number in RadioIntercomOutputs, hence ignoring." << Trace::EndLog();
                }
                else
                {
                    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
                    num_listener.AddCallback(number, MakeCallback(&InputCommsInterface::RadioAudioEnable, this));
                }
                object.Numbers().Store().AddListener(num_listener);
            }

            else if (class_id == Project::ClassID::INTERCOM)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                auto intercom_obj = object;
                intercom_obj.CreateChild(Project::GetObjectDefinition(Project::ClassID::INTERCOM_INPUTS));
                intercom_obj.CreateChild(Project::GetObjectDefinition(Project::ClassID::INTERCOM_OUTPUTS));
            }
            else if (class_id == Project::ClassID::INTERCOM_INPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                auto intercom_inputs_obj = object;
                IntercomInputsObjectCreated(intercom_inputs_obj);

                // Below code added just for testing uncommment code block for testing purpose
                //for (auto t = 0; t < 5; ++t)
                //{
                //    for (auto x = 0; x < 4; ++x)
                //    {
                //        auto ohp_inputs_object_definition = Project::GetObjectDefinition(Project::ClassID::OHP_INPUTS);
                //        ohp_inputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::VEHICLE_ID, t);
                //        ohp_inputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::OHP_ID, x);
                //        intercom_inputs_obj.CreateChild(ohp_inputs_object_definition);

                        auto ohp_inputs_object_definition = Project::GetObjectDefinition(Project::ClassID::OHP_INPUTS);
                        ohp_inputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::VEHICLE_ID, 0);
                        ohp_inputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::OHP_ID, 0);
                        intercom_inputs_obj.CreateChild(ohp_inputs_object_definition);
                //    }
                //}

                // Below code added just for testing uncommment code block for testing purpose
                /*for (auto t = 0; t < 5; ++t)
                {
                    for (auto x = 0; x < 4; ++x)
                    {
                        auto ebm_inputs_object_definition = Project::GetObjectDefinition(Project::ClassID::EMERGENCY_BRAKE_LEVER_INPUTS);
                        ebm_inputs_object_definition.SetNumberInitial(Project::ValueName::EmergencyBrakeLeverInputs::VEHICLE_ID, t);
                        ebm_inputs_object_definition.SetNumberInitial(Project::ValueName::EmergencyBrakeLeverInputs::OHP_ID, x);
                        ebm_inputs_object_definition.SetNumberInitial(Project::ValueName::EmergencyBrakeLeverInputs::LEAVER_ID, x);
                        intercom_inputs_obj.CreateChild(ebm_inputs_object_definition);
                    }
                }*/
            }
            else if (class_id == Project::ClassID::INTERCOM_OUTPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                m_intercom_outputs_object = object;
                if (m_intercom_outputs_object.IsValid())
                {
                    m_output_intercom_property_id = m_intercom_outputs_object.Numbers().Info().GetID(Project::ValueName::IntercomOutputs::INTERCOM);
                    m_output_active_call_type_property_id = m_intercom_outputs_object.Numbers().Info().GetID(Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
                }

                IntercomOutputsObjectCreated(m_intercom_outputs_object);
            }
            else if (class_id == Project::ClassID::OHP_INPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                m_ohp_inputs_object = object;
                if (m_ohp_inputs_object.IsValid())
                {
                    m_input_ohp_id_property_id = m_ohp_inputs_object.Numbers().Info().GetID(Project::ValueName::OHPInputs::OHP_ID);
                }

                // Register listener for OHP_INPUTS pecu isolate and deisolate state change
                NumberListener num_listener;
                //1
                Sim::Number number = object.Numbers().Get(Project::ValueName::OHPInputs::PECU_ISOLATE_REQ); // iso
                if (number.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::OHPInputs::PECU_ISOLATE_REQ
                        << " is not a valid number in OHPInputs, hence ignoring." << Trace::EndLog();
                }
                else
                {
                    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
                    num_listener.AddCallback(number, MakeCallback(&InputCommsInterface::IsolateCB, this));
                }

                //2
                number = object.Numbers().Get(Project::ValueName::OHPInputs::PECU_DE_ISOLATE_REQ); // de iso
                if (number.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::OHPInputs::PECU_DE_ISOLATE_REQ
                        << " is not a valid number in OHPInputs, hence ignoring." << Trace::EndLog();
                }
                else
                {
                    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
                    num_listener.AddCallback(number, MakeCallback(&InputCommsInterface::DeIsolateCB, this));
                }
                object.Numbers().Store().AddListener(num_listener);

                OHPInputsObjectCreated(m_ohp_inputs_object);
            }
            else if (class_id == Project::ClassID::OHP_OUTPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                m_ohp_outputs_object = object;
                if (m_ohp_outputs_object.IsValid())
                {
                    m_ohp_id_property_id = m_ohp_outputs_object.Numbers().Info().GetID(Project::ValueName::OHPOutputs::OHP_ID);
                    m_ohp_status_property_id = m_ohp_outputs_object.Numbers().Info().GetID(Project::ValueName::OHPOutputs::STATUS);
                }

                OHPOutputsObjectCreated(m_ohp_outputs_object);
            }
            else if (class_id == Project::ClassID::EMERGENCY_BRAKE_LEVER_INPUTS)
            {
                AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });

                auto emergency_brake_lever_input_obj = object;
                EmergencyBrakeLeverInputsObjectCreated(emergency_brake_lever_input_obj);
            }
            else if (class_id == Project::ClassID::SCC_FAULT_EVENTS_INTERCOM_INPUTS)
            {
                SCCFaultEventsIntercomInputsObjectCreated(object);
            }
        }

        void InputCommsInterface::TrainObjectCreated(Comms::Object object)
        {
            auto& train_object = object;
            if (static_cast<int>(train_object.Numbers().Get(Project::ValueName::Train::SCENARIO_TRAIN_ID).value) == m_scenario_train_id)
            {
                auto intercom_obj_def = Project::GetObjectDefinition(Project::ClassID::INTERCOM);
                train_object.CreateChild(intercom_obj_def);

                //create PIS_INPUT object here if required please uncomment the code...
                /*auto m_pis_input_object = Project::GetObjectDefinition(Project::ClassID::PIS_INPUTS);
                m_pis_input_object.SetNumberInitial(Project::ValueName::PISInputs::FAULT, 0);
                object.CreateChild(m_pis_input_object);*/

            }
        }

        void InputCommsInterface::OHPInputsObjectCreated(Comms::Object ohp_inputs_object)
        {
            assert(Core::GetClassID(ohp_inputs_object) == Project::ClassID::OHP_INPUTS);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            auto intercom_output = m_controller->GetIntercomOutput();
            auto output_object = intercom_output->GetIntercomOutputObject();

            if (output_object.IsValid())
            {
                m_ohp_inputs_object = ohp_inputs_object;
                // Get vehicle id and ohp id value when OHP Input object is created.
                using namespace Project::ValueName::OHPInputs;
                const auto vehicle_id_info  = ohp_inputs_object.Numbers().Info().GetID(VEHICLE_ID);
                const auto vehicle_id       = ohp_inputs_object.Numbers().Store().Get(vehicle_id_info).value;
                const auto ohp_id_info      = ohp_inputs_object.Numbers().Info().GetID(OHP_ID);
                const auto ohp_id           = ohp_inputs_object.Numbers().Store().Get(ohp_id_info).value;

                Trace::GetLogger().STAMP(Trace::VERBOSE) << " IntercomCommsInterface::OHPInputsObjectCreated, vehicle_id = " << vehicle_id << " ohp_id" << ohp_id << Trace::EndLog();

                // Register listener for OHP Button state change
                std::map<std::string, NumberCallback> numbers;

                const auto ohp_button_cb = [this, vehicle_id, ohp_id](Sim::Number ohp_button_status) { this->OHPButtonStateChanged(ohp_button_status, static_cast<int>(vehicle_id), static_cast<int>(ohp_id)); };
                const auto ohp_id_cb     = [this](Sim::Number ohp_id_status) { this->OHP_ID_StateChanged(ohp_id_status); };

                const auto pecu_iso_cb = [this](Sim::Number pecu_iso_status) { this->OHP_ID_StateChanged(pecu_iso_status); };
                const auto pecu_de_iso_cb = [this](Sim::Number pecu_de_iso_status) { this->OHP_ID_StateChanged(pecu_de_iso_status); };

                numbers[OHP_BUTTON] = ohp_button_cb;
                numbers[OHP_ID] = ohp_id_cb;
                numbers[PECU_ISOLATE_REQ] = pecu_iso_cb;
                numbers[PECU_DE_ISOLATE_REQ] = pecu_de_iso_cb;
                
                AddNumberListeners(numbers, ohp_inputs_object);

                auto ohp_outputs_object_definition = Project::GetObjectDefinition(Project::ClassID::OHP_OUTPUTS);
                ohp_outputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::VEHICLE_ID, vehicle_id);
                ohp_outputs_object_definition.SetNumberInitial(Project::ValueName::OHPOutputs::OHP_ID, ohp_id);

                output_object.CreateChild(ohp_outputs_object_definition);

                const double REQUEST_FREQ = 20.0; // In Hz

                Sim::Number number = ohp_inputs_object.Numbers().Get(VEHICLE_ID);
                if (number.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << VEHICLE_ID
                        << " is not a valid number in OHPInputsObjectCreated (VEHICLE_ID), hence ignoring." << Trace::EndLog();
                }
                else
                {
                    ohp_inputs_object.Numbers().Store().Request(ohp_inputs_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
                }
                number = ohp_inputs_object.Numbers().Get(OHP_ID);
                if (number.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << OHP_ID
                        << " is not a valid number in OHPInputsObjectCreated (OHP_ID), hence ignoring." << Trace::EndLog();
                }
                else
                {
                    ohp_inputs_object.Numbers().Store().Request(ohp_inputs_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
                }

            }
        }

        void InputCommsInterface::SetIntercomState(IntercomCallState intercom_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_pis_inputs_comms.IsValid())
            {
                const auto status = Sim::Number(static_cast<double>(intercom_state), m_intercom_status_property_id);
                m_pis_inputs_comms.Numbers().Store().Set(status);
            }
        }

        void InputCommsInterface::SetIntercomOutputsIntercom(IntercomCallState intercom_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_intercom_outputs_object.IsValid())
            {
                const auto status = Sim::Number(static_cast<double>(intercom_state), m_output_intercom_property_id);
                m_intercom_outputs_object.Numbers().Store().Set(status);
            }
        }

        void InputCommsInterface::SetIntercomOutputsActiveCallType(ActiveCallType active_call_type)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_intercom_outputs_object.IsValid())
            {
                const auto status = Sim::Number(static_cast<double>(active_call_type), m_output_active_call_type_property_id);
                m_intercom_outputs_object.Numbers().Store().Set(status);
            }
        }

        void InputCommsInterface::SetOHP_Id(int ohp_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_ohp_outputs_object.IsValid())
            {
                const auto l_ohp_id = Sim::Number(static_cast<double>(ohp_id), m_ohp_id_property_id);
                m_ohp_outputs_object.Numbers().Store().Set(l_ohp_id);
            }
        }

        void InputCommsInterface::SetOHP_Status(Status ohp_status)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_ohp_outputs_object.IsValid())
            {
                const auto l_ohp_status = Sim::Number(static_cast<double>(ohp_status), m_ohp_status_property_id);
                m_ohp_outputs_object.Numbers().Store().Set(l_ohp_status);
            }
        }

        void InputCommsInterface::SetInputValuesOHPPEId(int ohp_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (m_ohp_inputs_object.IsValid())
            {
                const auto l_ohp_id = Sim::Number(static_cast<double>(ohp_id), m_input_ohp_id_property_id);
                m_ohp_inputs_object.Numbers().Store().Set(l_ohp_id);
            }
        }

        void InputCommsInterface::OHPOutputsObjectCreated(Comms::Object ohp_outputs_object)
        {
            assert(Core::GetClassID(ohp_outputs_object) == Project::ClassID::OHP_OUTPUTS);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            auto intercom_output = m_controller->GetIntercomOutput();

            using namespace Project::ValueName::OHPOutputs;
            if (!m_ohp_output_object_number_ids_retrieved)
            {
                const auto status_id              = ohp_outputs_object.Numbers().Info().GetID(STATUS);
                intercom_output->SetOHPOutputPropertyID(STATUS, status_id);
                const auto wait_indicator_id      = ohp_outputs_object.Numbers().Info().GetID(WAIT_INDICATOR);
                intercom_output->SetOHPOutputPropertyID(WAIT_INDICATOR, wait_indicator_id);
                const auto speak_indicator_id     = ohp_outputs_object.Numbers().Info().GetID(SPEAK_INDICATOR);
                intercom_output->SetOHPOutputPropertyID(SPEAK_INDICATOR, speak_indicator_id);
                const auto listen_indicator_id    = ohp_outputs_object.Numbers().Info().GetID(LISTEN_INDICATOR);
                intercom_output->SetOHPOutputPropertyID(LISTEN_INDICATOR, listen_indicator_id);
                
                //PE ID
                const auto pe_id = ohp_outputs_object.Numbers().Info().GetID(PE_ID);
                intercom_output->SetOHPOutputPropertyID(PE_ID, pe_id);

                //OHP ID
                const auto ohp_id = ohp_outputs_object.Numbers().Info().GetID(OHP_ID);
                intercom_output->SetOHPOutputPropertyID(OHP_ID, ohp_id);

                //VEHICLE ID
                const auto vehicle_id = ohp_outputs_object.Numbers().Info().GetID(VEHICLE_ID);
                intercom_output->SetOHPOutputPropertyID(VEHICLE_ID, vehicle_id);

                //Isolation list ID
                const auto iso_list_id = ohp_outputs_object.Numbers().Info().GetID(ISOLATION_DEISOLATION_LIST);
                intercom_output->SetOHPOutputPropertyID(ISOLATION_DEISOLATION_LIST, iso_list_id);

                m_ohp_output_object_number_ids_retrieved = true;
            }

            const auto vehicle_id   = ohp_outputs_object.Numbers().Get(VEHICLE_ID).value;
            const auto ohp_id       = ohp_outputs_object.Numbers().Get(OHP_ID).value;

            const auto vehicle_ohp_ids = OHPID(static_cast<int>(vehicle_id), static_cast<int>(ohp_id));
            Trace::GetLogger().STAMP(Trace::VERBOSE) << " IntercomCommsInterface::OHPOutputsObjectCreated, inserting object " << ohp_outputs_object.GetID() << Trace::EndLog();
            Trace::GetLogger().STAMP(Trace::VERBOSE) << " IntercomCommsInterface::OHPOutputsObjectCreated, vehicle_id = " << vehicle_id << " ohp_id " << ohp_id << Trace::EndLog();

            intercom_output->SetOHPObject(ohp_outputs_object, vehicle_ohp_ids);
            intercom_output->SetIntercomOHPObject(ohp_outputs_object);
        }

        void InputCommsInterface::EmergencyBrakeLeverInputsObjectCreated(Comms::Object emergency_brake_lever_inputs_object)
        {
            assert(Core::GetClassID(emergency_brake_lever_inputs_object) == Project::ClassID::EMERGENCY_BRAKE_LEVER_INPUTS);

            // Get vehicle id and ohp id value when OHP Input object is created.
            using namespace Project::ValueName::EmergencyBrakeLeverInputs;
            const auto vehicle_id_info  = emergency_brake_lever_inputs_object.Numbers().Info().GetID(VEHICLE_ID);
            const auto vehicle_id       = emergency_brake_lever_inputs_object.Numbers().Store().Get(vehicle_id_info).value;
            const auto ohp_id_info      = emergency_brake_lever_inputs_object.Numbers().Info().GetID(OHP_ID);
            const auto ohp_id           = emergency_brake_lever_inputs_object.Numbers().Store().Get(ohp_id_info).value;
            const auto leaver_id_info   = emergency_brake_lever_inputs_object.Numbers().Info().GetID(LEAVER_ID);
            const auto leaver_id        = emergency_brake_lever_inputs_object.Numbers().Store().Get(ohp_id_info).value;

            /*Trace::GetLogger().STAMP(Trace::INFO) << " IntercomCommsInterface::EmergencyBrakeLeverInputsObjectCreated, vehicle_id = " <<
                vehicle_id << " ohp_id" << ohp_id << " leaver_id = " << leaver_id << Trace::EndLog();*/

            // Attach a listener and a callback to Emergency Brake Lever Input Button
            auto emergency_brake_lever_status_cb = [this, vehicle_id, ohp_id, leaver_id](Sim::Number emergency_brake_lever_status) {
                this->EmergencyBreakLeaverStateChanged(emergency_brake_lever_status, vehicle_id, ohp_id, leaver_id);
            };

            const auto numbers = std::map<std::string, NumberCallback>{ { Project::ValueName::EmergencyBrakeLeverInputs::STATUS, emergency_brake_lever_status_cb } };
            AddNumberListeners(numbers, emergency_brake_lever_inputs_object);

            {
                const std::lock_guard<std::recursive_mutex> lock(m_mutex);
                auto intercom_output = m_controller->GetIntercomOutput();

                const auto emergency_id = static_cast<int>(leaver_id);
                const auto ohp_id_ref = OHPID(static_cast<int>(vehicle_id), static_cast<int>(ohp_id));

                intercom_output->SetEmergencyBreakeLeaverID(emergency_id, ohp_id_ref);
            }

        }

        void InputCommsInterface::SCCFaultEventsIntercomInputsObjectCreated(Comms::Object scc_fault_events_intercom_inputs_object)
        {
            assert(Core::GetClassID(scc_fault_events_intercom_inputs_object) == Project::ClassID::SCC_FAULT_EVENTS_INTERCOM_INPUTS);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto edr_activated_id = scc_fault_events_intercom_inputs_object.Numbers().Info().GetID(Project::ValueName::SCCFaultEventsIntercomInputs::EDR_ACTIVATED);
            const auto vehicle_id_id = scc_fault_events_intercom_inputs_object.Numbers().Info().GetID(Project::ValueName::SCCFaultEventsIntercomInputs::VEHICLE_ID);
            const auto ohp_id_id = scc_fault_events_intercom_inputs_object.Numbers().Info().GetID(Project::ValueName::SCCFaultEventsIntercomInputs::OHP_ID);

            if (edr_activated_id != Sim::INVALID_NUMBER
                && vehicle_id_id != Sim::INVALID_NUMBER
                && ohp_id_id != Sim::INVALID_NUMBER)
            {
                const auto vehicle_id = scc_fault_events_intercom_inputs_object.Numbers().Store().Get(vehicle_id_id).value;
                const auto ohp_id = scc_fault_events_intercom_inputs_object.Numbers().Store().Get(ohp_id_id).value;

                Trace::GetLogger().STAMP(Trace::VERBOSE) << " IntercomCommsInterface::SCCFaultEventsIntercomInputsObjectCreated, vehicle_id = " << vehicle_id << " ohp_id" << ohp_id << Trace::EndLog();

                // Register listener for SCCFaultEventsIntercomInputs EDR_ACTIVATED state change
                NumberListener num_listener;
                const auto edr_activated_change_cb = [this, vehicle_id, ohp_id](Sim::Number edr_activated_status)
                                                        { this->FaultEDRActivatedStateChanged(edr_activated_status, static_cast<int>(vehicle_id), static_cast<int>(ohp_id)); };
                const auto numbers = std::map<std::string, NumberCallback>{ {Project::ValueName::SCCFaultEventsIntercomInputs::EDR_ACTIVATED, edr_activated_change_cb} };
                AddNumberListeners(numbers, scc_fault_events_intercom_inputs_object);
            }
        }

        void InputCommsInterface::IntercomInputsObjectCreated(Comms::Object intercom_inputs_object)
        {
            assert(Core::GetClassID(intercom_inputs_object) == Project::ClassID::INTERCOM_INPUTS);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            // Attach a listener and a callback to Intercom Input Button

            std::map<std::string, NumberCallback> numbers;
            const auto in_pa_button_cb               = [this](Sim::Number cab_in_pa_button_status) { this->InPAButtonStateChanged(cab_in_pa_button_status); };
            const auto out_pa_button_cb              = [this](Sim::Number cab_out_pa_button_status) { this->OutPAButtonStateChanged(cab_out_pa_button_status); };
            const auto intercom_button_cb            = [this](Sim::Number cab_intercom_button_status) { this->IntercomButtonStateChanged(cab_intercom_button_status); };
            const auto cancel_button_cb              = [this](Sim::Number cab_cancel_button_status) { this->CancelButtonStateChanged(cab_cancel_button_status); };
            const auto scc_intercom_button_cb        = [this](Sim::Number cab_scc_button_status) { this->SCCIntercomButtonStateChanged(cab_scc_button_status); };
            const auto scc_intercom_cancel_button_cb = [this](Sim::Number cab_scc_cancel_button_status) { this->SCCIntercomCancelButtonStateChanged(cab_scc_cancel_button_status); };//

            using namespace Project::ValueName::IntercomInputs;
            numbers[CAB_IN_PA_BUTTON]           = in_pa_button_cb;
            numbers[CAB_OUT_PA_BUTTON]          = out_pa_button_cb;
            numbers[CAB_INTERCOM_BUTTON]        = intercom_button_cb;
            numbers[CAB_CANCEL_BUTTON]          = cancel_button_cb;
            numbers[SCC_INTERCOM_BUTTON]        = scc_intercom_button_cb;
            numbers[SCC_INTERCOM_CANCEL_BUTTON] = scc_intercom_cancel_button_cb;

            AddNumberListeners(numbers, intercom_inputs_object);
        }

        void InputCommsInterface::IntercomOutputsObjectCreated(Comms::Object intercom_outputs_object)
        {
            assert(Core::GetClassID(intercom_outputs_object) == Project::ClassID::INTERCOM_OUTPUTS);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            auto intercom_output = m_controller->GetIntercomOutput();

            using namespace Project::ValueName::IntercomOutputs;

            const auto pa_id                 = intercom_outputs_object.Numbers().Info().GetID(PUBLIC_ADDRESS);
            intercom_output->SetIntercomOutputPropertyID(PUBLIC_ADDRESS, pa_id);
            const auto intercom_id           = intercom_outputs_object.Numbers().Info().GetID(INTERCOM);
            intercom_output->SetIntercomOutputPropertyID(INTERCOM, intercom_id);
            const auto in_pa_light_id        = intercom_outputs_object.Numbers().Info().GetID(IN_PA_LIGHT);
            intercom_output->SetIntercomOutputPropertyID(IN_PA_LIGHT, in_pa_light_id);
            const auto out_pa_light_id       = intercom_outputs_object.Numbers().Info().GetID(OUT_PA_LIGHT);
            intercom_output->SetIntercomOutputPropertyID(OUT_PA_LIGHT, out_pa_light_id);
            const auto intercom_light_id     = intercom_outputs_object.Numbers().Info().GetID(INTERCOM_LIGHT);
            intercom_output->SetIntercomOutputPropertyID(INTERCOM_LIGHT, intercom_light_id);
            const auto ohp_chime_id          = intercom_outputs_object.Numbers().Info().GetID(OHP_CHIME);
            intercom_output->SetIntercomOutputPropertyID(OHP_CHIME, ohp_chime_id);
            const auto active_call_type_id = intercom_outputs_object.Numbers().Info().GetID(ACTIVE_CALL_TYPE);
            intercom_output->SetIntercomOutputPropertyID(ACTIVE_CALL_TYPE, active_call_type_id);

            intercom_output->SetIntercomObject(intercom_outputs_object);
        }

        void InputCommsInterface::InPAButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto in_pa_button_state = static_cast<int>(event_state.value);
            if (m_radio_intercom_state > Project::TypeValue::IntercomConstant::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Radio Intercom already Connected " << Trace::EndLog();
                return;
            }

            if (in_pa_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined IN PA button state " << in_pa_button_state << Trace::EndLog();
                return;
            }

            switch (in_pa_button_state)
            {
            case Project::TypeValue::PAButtonState::PRESSED:
                {
                    SetIntercomState(IntercomCallState::CALL_REQUEST);
                    const Message request_data(MessageType::PA_IN, ButtonState::PRESSED);
                    OnButtonPressed(request_data);
                }
                break;
            case Project::TypeValue::PAButtonState::RELEASED:
                {
                    const Message request_data(MessageType::PA_IN, ButtonState::RELEASED);
                    OnButtonReleased(request_data);
                    SetIntercomState(IntercomCallState::INACTIVE);
                }
                break;
            };
        }

        void InputCommsInterface::OutPAButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            const auto received_out_pa_button_state = static_cast<int>(event_state.value);

            if (m_radio_intercom_state > Project::TypeValue::IntercomConstant::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Radio Intercom already Connected. " << Trace::EndLog();
                return;
            }

            if(received_out_pa_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined OUT PA button state " << received_out_pa_button_state << Trace::EndLog();
                return;
            }

            switch (received_out_pa_button_state)
            {
            case Project::TypeValue::PAButtonState::PRESSED:
                {
                SetIntercomState(IntercomCallState::CALL_REQUEST);
                    const Message request_data(MessageType::PA_OUT, ButtonState::PRESSED);
                    OnButtonPressed(request_data);
                }
                break;
            case Project::TypeValue::PAButtonState::RELEASED:
                {
                    const Message request_data(MessageType::PA_IN, ButtonState::RELEASED);
                    OnButtonPressed(request_data);
                    SetIntercomState(IntercomCallState::INACTIVE);
                }
                break;
            }
        }

        void InputCommsInterface::IntercomButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (m_radio_intercom_state > Project::TypeValue::IntercomConstant::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Radio Intercom already Connected.. " << Trace::EndLog();
                return;
            }

            const auto received_intercom_button_state = static_cast<int>(event_state.value);
            const auto ohp_id_inp = CTSProjectUtility::GetObjectPropertyNumber<int>(m_ohp_inputs_object, Project::ValueName::OHPInputs::OHP_ID);
            if (received_intercom_button_state == Project::TypeValue::ButtonState::PRESSED)
            {
                if (ohp_id_inp == 5)
                {
                    SetIntercomOutputsIntercom(IntercomCallState::ACTIVE);
                    SetOHP_Status(Status::TALKING);
                    //SetIntercomState(IntercomCallState::INACTIVE);
                }
                else
                {
                    SetIntercomState(IntercomCallState::CALL_REQUEST);
                    const Message request_data(MessageType::IC_CAB, ButtonState::PRESSED);
                    OnButtonPressed(request_data);
                }
            }
            else if(received_intercom_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined INTERCOM button state " << received_intercom_button_state << Trace::EndLog();
            }
        }

        void InputCommsInterface::CancelButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto received_cancel_button_state = static_cast<int>(event_state.value);

            const auto ohp_id_inp = CTSProjectUtility::GetObjectPropertyNumber<int>(m_ohp_inputs_object, Project::ValueName::OHPInputs::OHP_ID);
            if (received_cancel_button_state == Project::TypeValue::ButtonState::PRESSED && m_multiple_end_call_count != 4 && ohp_id_inp == 5)
            {
                m_multiple_end_call_count++;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Multiple Call Scenario, Call number " << m_multiple_end_call_count << " ended " << Trace::EndLog();
            }
            if (received_cancel_button_state == Project::TypeValue::ButtonState::PRESSED && m_multiple_end_call_count == 4 && ohp_id_inp == 5)
            {
                SetIntercomOutputsIntercom(IntercomCallState::INACTIVE);
                SetIntercomState(IntercomCallState::INACTIVE);
                SetInputValuesOHPPEId(0);
                SetOHP_Status(Status::NORMAL);
                SetIntercomOutputsActiveCallType(ActiveCallType::INACTIVE);

                m_multiple_end_call_count = 0;

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "OHP ID reset to 0" << Trace::EndLog();
            }
            else if (ohp_id_inp == 5 && received_cancel_button_state == Project::TypeValue::ButtonState::PRESSED)
            {
                // added this to manage the status of individual ohp call, while connection and disconnection,    For MULTIPLE CALL SCENARIO
                SetIntercomState(IntercomCallState::CALL_REQUEST);
                SetIntercomOutputsIntercom(IntercomCallState::CALL_REQUEST);
                SetOHP_Status(Status::CALLING);
            }

            if (received_cancel_button_state == Project::TypeValue::ButtonState::PRESSED && ohp_id_inp != 5)
            {
                const Message request_data(MessageType::IC_CANCEL, ButtonState::PRESSED);
                OnButtonPressed(request_data);  
                SetIntercomState(IntercomCallState::INACTIVE);
            }
            else if(received_cancel_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined CANCEL button state " << received_cancel_button_state << Trace::EndLog();
            }
        }

        void InputCommsInterface::SCCIntercomButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto received_scc_button_state = static_cast<int>(event_state.value);
            if (m_radio_intercom_state > Project::TypeValue::IntercomConstant::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Radio Intercom - already Connected " << Trace::EndLog();
                return;
            }
            const auto ohp_id_inp = CTSProjectUtility::GetObjectPropertyNumber<int>(m_ohp_inputs_object, Project::ValueName::OHPInputs::OHP_ID);
            if (received_scc_button_state == Project::TypeValue::ButtonState::PRESSED)
            {
                if (ohp_id_inp == 5)
                {
                    SetIntercomOutputsIntercom(IntercomCallState::ACTIVE);
                    SetOHP_Status(Status::TALKING);
                    //SetIntercomState(IntercomCallState::INACTIVE);
                }
                else
                {
                    SetIntercomState(IntercomCallState::CALL_REQUEST);
                    const Message request_data(MessageType::IC_SCC, ButtonState::PRESSED);
                    OnButtonPressed(request_data);
                }
            }
            else if(received_scc_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined SCC button state " << received_scc_button_state << Trace::EndLog();
                return;
            }
        }

        void InputCommsInterface::SCCIntercomCancelButtonStateChanged(Sim::Number event_state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto received_scc_button_state = static_cast<int>(event_state.value);

            const auto ohp_id_inp = CTSProjectUtility::GetObjectPropertyNumber<int>(m_ohp_inputs_object, Project::ValueName::OHPInputs::OHP_ID);

            if (ohp_id_inp == 5 && received_scc_button_state == Project::TypeValue::ButtonState::PRESSED)
            {
                SetIntercomOutputsIntercom(IntercomCallState::INACTIVE);
                SetIntercomState(IntercomCallState::INACTIVE);
                SetInputValuesOHPPEId(0);
                SetOHP_Status(Status::NORMAL);
                SetIntercomOutputsActiveCallType(ActiveCallType::INACTIVE);

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "OHP ID reset to 0" << Trace::EndLog();
            }

            if (received_scc_button_state == Project::TypeValue::ButtonState::PRESSED && ohp_id_inp != 5)
            {
                const Message request_data(MessageType::IC_SCC_CANCEL, ButtonState::PRESSED);
                OnButtonPressed(request_data);
                SetIntercomState(IntercomCallState::INACTIVE);
            }
            else if (received_scc_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR)
                    << " Encounter undefined SCC cancel button state " << received_scc_button_state << Trace::EndLog();
            }
        }

        void InputCommsInterface::OHPButtonStateChanged(Sim::Number event_state, int vehicle_id, int ohp_id)
        {
            std::lock_guard<std::recursive_mutex>  lock(m_mutex);

            const auto ohp_button_state = static_cast<int>(event_state.value);
            if (m_radio_intercom_state > Project::TypeValue::IntercomConstant::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Radio Intercom - already Connected. " << Trace::EndLog();
                return;
            }

            //auto currentIsolatedCall = 20;

            if (ohp_button_state >= Project::TypeValue::ButtonState::PRESSED)
            {
                // Get vehicle id and ohp id value when OHP Input object is created.
                using namespace Project::ValueName::OHPInputs;
                const auto vehicle_id_info = m_ohp_inputs_object.Numbers().Info().GetID(VEHICLE_ID);
                const auto vehicle_id_upated = static_cast<int>(m_ohp_inputs_object.Numbers().Store().Get(vehicle_id_info).value);
                const auto ohp_id_info = m_ohp_inputs_object.Numbers().Info().GetID(OHP_ID);
                const auto ohp_id_updated = static_cast<int>(m_ohp_inputs_object.Numbers().Store().Get(ohp_id_info).value);

                //m_allIsolatedCalls = { 1.0, 3.0 };
                //m_currentIsolatedCall = event_state.value;
                if (std::find(m_allIsolatedCalls.begin(), m_allIsolatedCalls.end(), m_currentIsolatedCall) == m_allIsolatedCalls.end())
                {
                    SetIntercomState(IntercomCallState::CALL_REQUEST);
                    const OHPID ohp_data(vehicle_id_upated, ohp_id_updated);
                    Message request_data(MessageType::IC_OHP, ButtonState::PRESSED);
                    request_data.SetData(ohp_data);
                    OnButtonPressed(request_data);
                }
            }
            else if(ohp_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined OHP button state " << ohp_button_state << Trace::EndLog();
            }
            //else
            //{
            //    SetIntercomState(IntercomCallState::INACTIVE);
            //}
        }

        void InputCommsInterface::OHP_ID_StateChanged(Sim::Number event_state)
        {
            std::lock_guard<std::recursive_mutex>  lock(m_mutex);

            const auto ohp_id_state = static_cast<int>(event_state.value);
            if (ohp_id_state == 5 || ohp_id_state == 0)
            {
                SetOHP_Id(ohp_id_state);

                if (ohp_id_state == 5)
                {
                    Trace::GetLogger().STAMP(Trace::INFO) << "Multiple OHP Scenario Started " << Trace::EndLog();
                    SetIntercomState(IntercomCallState::CALL_REQUEST);
                    SetIntercomOutputsIntercom(IntercomCallState::CALL_REQUEST);
                    SetOHP_Status(Status::CALLING);
                    SetIntercomOutputsActiveCallType(ActiveCallType::OHP);
                }
            }
        }

        void InputCommsInterface::EmergencyBreakLeaverStateChanged(Sim::Number event_state, double vehicle_id, double ohp_id, double emergency_break_leaver_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto leaver_button_state = static_cast<int>(event_state.value);

            if (leaver_button_state == Project::TypeValue::ButtonState::PRESSED)
            {
                const OHPID ohp_data(static_cast<int>(vehicle_id), static_cast<int>(ohp_id));
                Message request_data(MessageType::IC_EBM, ButtonState::PRESSED);
                request_data.SetData(ohp_data, static_cast<int>(emergency_break_leaver_id));
                OnButtonPressed(request_data);
            }
            else if(leaver_button_state < 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << " Encounter undefined Break Leaver button state " << leaver_button_state << Trace::EndLog();
            }
        }

        void InputCommsInterface::FaultEDRActivatedStateChanged(Sim::Number event_state, int vehicle_id, int ohp_id)
        {
            std::lock_guard<std::recursive_mutex>  lock(m_mutex);

            const auto edr_activated_state = (event_state.value > 0.5) ? PIS::Intercom::State::ACTIVE : PIS::Intercom::State::INACTIVE;

            if (edr_activated_state == PIS::Intercom::State::ACTIVE)
            {
                const OHPID ohp_data(vehicle_id, ohp_id);
                Message request_data(MessageType::IC_OHP, ButtonState::PRESSED);
                request_data.SetData(ohp_data);
                OnButtonPressed(request_data);
            }
        }

        void InputCommsInterface::OnButtonPressed(const PIS::Intercom::Message& request_data)
        {
            m_event_handler.HandleEvent(request_data, m_controller);
        }

        void InputCommsInterface::OnButtonReleased(const PIS::Intercom::Message& request_data)
        {
            m_event_handler.HandleEvent(request_data, m_controller);
        }

        void InputCommsInterface::IsolateCB(const Sim::Number &num_obj)
        {
            m_currentIsolatedCall = static_cast <int>(num_obj.value);

            if (32 < m_currentIsolatedCall || m_currentIsolatedCall <= 0)
                return;

            auto ohp_id = m_currentIsolatedCall % 4;
            if (ohp_id == 0)
                ohp_id = 4;
            auto veh_id = (m_currentIsolatedCall / 4) + 1;
            if (ohp_id == 4)
                veh_id = veh_id - 1;
            auto intercom_output = m_controller->GetIntercomOutput();
            Trace::GetLogger().STAMP(Trace::INFO) << ohp_id <<" <Pecu Number,  ISO vehicle Number> " << veh_id << Trace::EndLog();

            intercom_output->SetOHPId(m_ohp_outputs_object, ohp_id);
            intercom_output->SetVehId(m_ohp_outputs_object, veh_id);

            //Project::ValueName::OHPOutputs::ISOLATION_DEISOLATION_LIST;

            //m_iso_call_list = 
            //{
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0,
            //    0,0,0,0
            //};

             //std::vector<std::array<int>> m_iso_call_list = { 
             //   {0,0,0,0},
             //   {0,0,0,0},
             //   {0,0,0,0},
             //   {0,0,0,0},
             //   {0,0,0,0}
             //             };

            m_iso_call_list[m_currentIsolatedCall - 1] = 1;

            intercom_output->SetRawIsoCalls(m_ohp_outputs_object, m_iso_call_list);
            //SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);

            SetIntercomState(IntercomCallState::ISOLATED);
            SetIntercomOutputsIntercom(IntercomCallState::ISOLATED);
            SetOHP_Status(Status::ISOLATED);

            m_allIsolatedCalls.push_back(num_obj.value);
        }

        void InputCommsInterface::DeIsolateCB(const Sim::Number &num_obj)
        {
            m_currentIsolatedCall = static_cast <int>(num_obj.value);

            if (32 <= m_currentIsolatedCall || m_currentIsolatedCall <= 0)
                return;

            auto ohp_id = m_currentIsolatedCall % 4;
            if (ohp_id == 0)
                ohp_id = 4;
            auto veh_id = (m_currentIsolatedCall / 4) + 1;
            if (ohp_id == 4)
                veh_id = veh_id - 1;
            auto intercom_output = m_controller->GetIntercomOutput();
            Trace::GetLogger().STAMP(Trace::INFO) << ohp_id << " <Pecu Number,  DE-ISO vehicle Number> " << veh_id << Trace::EndLog();

            intercom_output->SetOHPId(m_ohp_outputs_object, ohp_id);
            intercom_output->SetVehId(m_ohp_outputs_object, veh_id);

            m_iso_call_list[m_currentIsolatedCall - 1] = 0;
            intercom_output->SetRawIsoCalls(m_ohp_outputs_object, m_iso_call_list);

            SetIntercomState(IntercomCallState::DEISOLATED);
            SetIntercomOutputsIntercom(IntercomCallState::DEISOLATED);
            SetOHP_Status(Status::DEISOLATED);

            //m_allIsolatedCalls.erase(std::remove_if(m_allIsolatedCalls.begin(), m_allIsolatedCalls.end(),[m_currentDeIsolatedCall](double isoCall) { return isoCall == m_currentDeIsolatedCall; }),
                //m_allIsolatedCalls.end());

            auto size = m_allIsolatedCalls.size();
            // below is DeIsolation call logic, Here we are checking if m_currentDeIsolatedCall is already present in m_allIsolatedCalls
            for (auto it = m_allIsolatedCalls.begin(); it != m_allIsolatedCalls.end();)
            {
                if (*it == m_currentDeIsolatedCall)
                    it = m_allIsolatedCalls.erase(it);
                else
                    it++;
            }

            if (size == m_allIsolatedCalls.size())
                Trace::GetLogger().STAMP(Trace::ERR) << " Cant deIsolate Pecu " << m_currentDeIsolatedCall << Trace::EndLog();
        }
    }
}
