// @file       IntercomOutput declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "OutputCommsInterface.h"
#include <project_comms_structure/ProjectObjectConstants.h>
#include "Source/Protobuf/PAPISProtos.pb.h"

namespace
{
    const auto FLASH_INTERVAL = 0.5;
}

namespace PIS
{

    namespace Intercom
    {

        OutputCommsInterface::OutputCommsInterface(Comms::Gateway& gateway) : m_gateway(gateway)
        {
            m_flashing_timer_id = gateway.ScheduleTimerCallback([this](double time) { return FlashingTimerCallback(time); },
                                                             gateway.GetTiming().GetCurrentModuleTime() + FLASH_INTERVAL);
        }

        OutputCommsInterface::~OutputCommsInterface() { m_gateway.CancelTimerCallback(m_flashing_timer_id); }

        void OutputCommsInterface::SetPAState(const IO state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (m_intercom_outputs_object.IsValid())
            {
                const auto pa_id = m_property_ids.find(Project::ValueName::IntercomOutputs::PUBLIC_ADDRESS);

                if (pa_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(state), pa_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
        }

        void OutputCommsInterface::SetPALightState(const PAOutput pa_light, const IO state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (!m_intercom_outputs_object.IsValid())
            {
                return;
            }

            if (pa_light == PAOutput::PA_IN_LIGHT)
            {
                const auto in_pa_light_id = m_property_ids.find(Project::ValueName::IntercomOutputs::IN_PA_LIGHT);

                if (in_pa_light_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(state), in_pa_light_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
            else if (pa_light == PAOutput::PA_OUT_LIGHT)
            {
                const auto out_pa_light_id = m_property_ids.find(Project::ValueName::IntercomOutputs::OUT_PA_LIGHT);

                if (out_pa_light_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(state), out_pa_light_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
        }

        void OutputCommsInterface::SetIntercomLightState(const IO state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (state != IO::FLASHING)
            {
                if (m_intercom_outputs_object.IsValid())
                {
                    const auto intercom_light_id = m_property_ids.find(Project::ValueName::IntercomOutputs::INTERCOM_LIGHT);

                    if (intercom_light_id != m_property_ids.end())
                    {
                        const auto status = Sim::Number(static_cast<double>(state), intercom_light_id->second);
                        m_intercom_outputs_object.Numbers().Store().Set(status);
                    }
                }

                m_intercom_light_flashing = false;
            }
            else
            {
                m_intercom_light_flashing = true;
            }
        }

        void OutputCommsInterface::SetIntercomState(const IntercomCallState state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (m_intercom_outputs_object.IsValid())
            {
                const auto intercom_id = m_property_ids.find(Project::ValueName::IntercomOutputs::INTERCOM);

                if (intercom_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(state), intercom_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
        }

        void OutputCommsInterface::SetOHPChimeState(const State state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (m_intercom_outputs_object.IsValid())
            {
                const auto ohp_chime_id = m_property_ids.find(Project::ValueName::IntercomOutputs::OHP_CHIME);

                if (ohp_chime_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(state), ohp_chime_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
        }

        void OutputCommsInterface::SetActiveCallType(const ActiveCallType active_call_type)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (m_intercom_outputs_object.IsValid())
            {
                const auto active_call_type_id = m_property_ids.find(Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);

                if (active_call_type_id != m_property_ids.end())
                {
                    const auto status = Sim::Number(static_cast<double>(active_call_type), active_call_type_id->second);
                    m_intercom_outputs_object.Numbers().Store().Set(status);
                }
            }
        }

        void OutputCommsInterface::SetOHPStatus(Comms::Object ohp_object, const Status status)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (ohp_object.IsValid())
            {
                const auto status_id = m_property_ids.find(Project::ValueName::OHPOutputs::STATUS);

                if (status_id != m_property_ids.end())
                {
                    const auto l_status = Sim::Number(static_cast<double>(status), status_id->second);
                    ohp_object.Numbers().Store().Set(l_status);
                }
            }
        }

        //void OutputCommsInterface::SetOHPPEName(Comms::Object ohp_object, const std::string & pe_name)
        //{
        //    const std::lock_guard<std::recursive_mutex> lock(m_mutex);

        //    if (ohp_object.IsValid())
        //    {
        //        const auto pe_name_id_itr = m_property_ids.find(Project::ValueName::OHPOutputs::PE_NAME);

        //        if (pe_name_id_itr != m_property_ids.end())
        //        {
        //            auto pe_name_id = pe_name_id_itr->second;
        //            Sim::Raw raw = ohp_object.Raws().Get(Project::ValueName::OHPOutputs::PE_NAME);

        //            raw.value.clear();
        //            raw.value.insert(raw.value.begin(), pe_name.begin(), pe_name.end());
        //            ohp_object.Raws().Store().Set(raw);
        //        }
        //    }
        //}
    
        void OutputCommsInterface::SetPEId(Comms::Object ohp_object, int pe_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (ohp_object.IsValid())
            {
                const auto pe_comms_id = m_property_ids.find(Project::ValueName::OHPOutputs::PE_ID);
                if (pe_comms_id != m_property_ids.end())
                {
                    const auto l_pe_id = Sim::Number(static_cast<double>(pe_id), pe_comms_id->second);
                    ohp_object.Numbers().Store().Set(l_pe_id);
                }
            }
        }

        void OutputCommsInterface::SetOHPId(Comms::Object ohp_object, int ohp_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (ohp_object.IsValid())
            {
                const auto pe_comms_id = m_property_ids.find(Project::ValueName::OHPOutputs::OHP_ID);
                if (pe_comms_id != m_property_ids.end())
                {
                    const auto l_pe_id = Sim::Number(static_cast<double>(ohp_id), pe_comms_id->second);
                    ohp_object.Numbers().Store().Set(l_pe_id);
                }
            }
        }

        void OutputCommsInterface::SetVehId(Comms::Object ohp_object, int vehicle_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (ohp_object.IsValid())
            {
                const auto pe_comms_id = m_property_ids.find(Project::ValueName::OHPOutputs::VEHICLE_ID);
                if (pe_comms_id != m_property_ids.end())
                {
                    const auto l_pe_id = Sim::Number(static_cast<double>(vehicle_id), pe_comms_id->second);
                    ohp_object.Numbers().Store().Set(l_pe_id);
                }
            }
        }

        void OutputCommsInterface::SetRawIsoCalls(Comms::Object ohp_object, std::vector<int> allIsoCalls)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);
            if (ohp_object.IsValid())
            {
                const auto pe_comms_id = m_property_ids.find(Project::ValueName::OHPOutputs::ISOLATION_DEISOLATION_LIST);
                if (pe_comms_id != m_property_ids.end())
                {
                    com::sydac::mmrbem::common::protos::VehiclePecuList veh_pecu_list_proto;
                    com::sydac::mmrbem::common::protos::VehiclePecuList_VehiclePecu pecuNumber;

                    //pecuNumber.set_pecu1(1);
                    //pecuNumber.set_pecu2(0);
                    //pecuNumber.set_pecu3(0);
                    //pecuNumber.set_pecu4(0);
                    //veh_pecu_list_proto.add_peculist()->CopyFrom(pecuNumber);

                    //pecuNumber.set_pecu1(1);
                    //pecuNumber.set_pecu2(0);
                    //pecuNumber.set_pecu3(0);
                    //pecuNumber.set_pecu4(0);
                    //veh_pecu_list_proto.add_peculist()->CopyFrom(pecuNumber);
                    int veh_ind = 1;
                    for (int x = 0; x < static_cast<int>(allIsoCalls.size()); x++)
                    {
                        pecuNumber.set_vehind(veh_ind++);
                        pecuNumber.set_pecu1(allIsoCalls[x++]);
                        pecuNumber.set_pecu2(allIsoCalls[x++]);
                        pecuNumber.set_pecu3(allIsoCalls[x++]);
                        pecuNumber.set_pecu4(allIsoCalls[x]);
                        veh_pecu_list_proto.add_peculist()->CopyFrom(pecuNumber);
                    }

                    std::string list_string;
                    veh_pecu_list_proto.AppendToString(&list_string);

                    Sim::Raw raw = ohp_object.Raws().Get(Project::ValueName::OHPOutputs::ISOLATION_DEISOLATION_LIST);
                    raw.value.clear();
                    raw.value.insert(raw.value.begin(), list_string.begin(), list_string.end());

                    //PRINT PROTO 
                    auto proto_str = veh_pecu_list_proto.DebugString();
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PECU PROTO STRING: \n" << proto_str << Trace::EndLog();

                    ohp_object.Raws().Store().Set(raw);
                }
            }
        }

        void OutputCommsInterface::SetOHPIndicatorState(Comms::Object ohp_object, const OHPOutputs ohp_indicator, const IO state)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (!ohp_object.IsValid())
            {
                return;
            }

            switch (ohp_indicator)
            {
            case OHPOutputs::WAIT_INDICATOR:
            {
                const auto wait_indicator_id = m_property_ids.find(Project::ValueName::OHPOutputs::WAIT_INDICATOR);

                if (wait_indicator_id != m_property_ids.end())
                {
                    const auto wait_indicator = Sim::Number(static_cast<double>(state), wait_indicator_id->second);
                    ohp_object.Numbers().Store().Set(wait_indicator);
                }
            }
            break;
            case OHPOutputs::LISTEN_INDICATOR:
            {
                const auto listen_indicator_id = m_property_ids.find(Project::ValueName::OHPOutputs::LISTEN_INDICATOR);

                if (listen_indicator_id != m_property_ids.end())
                {
                    const auto listen_indicator = Sim::Number(static_cast<double>(state), listen_indicator_id->second);
                    ohp_object.Numbers().Store().Set(listen_indicator);
                }
            }
            break;
            case OHPOutputs::SPEAK_INDICATOR:
            {
                const auto speak_indicator_id = m_property_ids.find(Project::ValueName::OHPOutputs::SPEAK_INDICATOR);

                if (speak_indicator_id != m_property_ids.end())
                {
                    const auto speak_indicator = Sim::Number(static_cast<double>(state), speak_indicator_id->second);
                    ohp_object.Numbers().Store().Set(speak_indicator);
                }
            }
            break;
            }
        }

        void OutputCommsInterface::SetIntercomOutputPropertyID(std::string type, const Sim::Number::ID property_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            using namespace Project::ValueName::IntercomOutputs;

            if (type.compare(PUBLIC_ADDRESS) == 0)
            {
                m_property_ids[PUBLIC_ADDRESS] = property_id;
            }
            else if (type.compare(INTERCOM) == 0)
            {
                m_property_ids[INTERCOM] = property_id;
            }
            else if (type.compare(IN_PA_LIGHT) == 0)
            {
                m_property_ids[IN_PA_LIGHT] = property_id;
            }
            else if (type.compare(OUT_PA_LIGHT) == 0)
            {
                m_property_ids[OUT_PA_LIGHT] = property_id;
            }
            else if (type.compare(INTERCOM_LIGHT) == 0)
            {
                m_property_ids[INTERCOM_LIGHT] = property_id;
            }
            else if (type.compare(OHP_CHIME) == 0)
            {
                m_property_ids[OHP_CHIME] = property_id;
            }
            else if (type.compare(ACTIVE_CALL_TYPE) == 0)
            {
                m_property_ids[ACTIVE_CALL_TYPE] = property_id;
            }
        }

        void OutputCommsInterface::SetOHPOutputPropertyID(std::string type, const Sim::Number::ID property_id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            using namespace Project::ValueName::OHPOutputs;

            if (type.compare(STATUS) == 0)
            {
                m_property_ids[STATUS] = property_id;
            }
            else if (type.compare(WAIT_INDICATOR) == 0)
            {
                m_property_ids[WAIT_INDICATOR] = property_id;
            }
            else if (type.compare(SPEAK_INDICATOR) == 0)
            {
                m_property_ids[SPEAK_INDICATOR] = property_id;
            }
            else if (type.compare(LISTEN_INDICATOR) == 0)
            {
                m_property_ids[LISTEN_INDICATOR] = property_id;
            }
            else if (type.compare(PE_ID) == 0)
            {
                m_property_ids[PE_ID] = property_id;
            }
            else if (type.compare(OHP_ID) == 0)
            {
                m_property_ids[OHP_ID] = property_id;
            }
            else if (type.compare(VEHICLE_ID) == 0)
            {
                m_property_ids[VEHICLE_ID] = property_id;
            }
            else if (type.compare(ISOLATION_DEISOLATION_LIST) == 0)
            {
                m_property_ids[ISOLATION_DEISOLATION_LIST] = property_id;
            }
        }

        void OutputCommsInterface::SetOHPObject(const Comms::Object ohp_eb_object, const OHPID id)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            m_ohp_Objects.insert_or_assign(id, ohp_eb_object);
        }
        void OutputCommsInterface::SetIntercomOHPObject(const Comms::Object ohp_output_object)
        {
            m_ohp_output_object = ohp_output_object;
        }

        Comms::Object OutputCommsInterface::GetIntercomOHPObject()
        {
            return m_ohp_output_object;
        }

        void OutputCommsInterface::SetEmergencyBreakeLeaverID(const int emergency_break_id, const OHPID ohp_uid)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            MessageID eb_ohp_id(ohp_uid.m_vehicle_id, ohp_uid.m_ohp_id, emergency_break_id);
            m_eb_ohp_map.insert(eb_ohp_id);
        }

        void OutputCommsInterface::SetIntercomObject(const Comms::Object intercom_output_object)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            m_intercom_outputs_object = intercom_output_object;
        }

        Comms::Object OutputCommsInterface::GetIntercomOutputObject() const { return m_intercom_outputs_object; }

        Comms::Object OutputCommsInterface::GetOHPOutputObject(const MessageID& uid)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            if (uid.m_break_leaver_id >= 0)
            {
                const auto ohp_id = m_eb_ohp_map.find(uid);
                if (ohp_id != m_eb_ohp_map.end())
                {
                    const auto l_ohp_id   = OHPID(ohp_id->m_vehicle_id, ohp_id->m_ohp_id);
                    const auto ohp_object = m_ohp_Objects.find(l_ohp_id);
                    if (ohp_object != m_ohp_Objects.end())
                    {
                        return ohp_object->second;
                    }
                }
            }
            else
            {
                const auto ohp_id     = OHPID(uid.m_vehicle_id, uid.m_ohp_id);
                const auto ohp_object = m_ohp_Objects.find(ohp_id);
                if (ohp_object != m_ohp_Objects.end())
                {
                    return ohp_object->second;
                }
            }

            return nullptr;
        }
        double OutputCommsInterface::FlashingTimerCallback(double time)
        {
            if (m_intercom_light_flashing)
            {
                if (m_intercom_outputs_object.IsValid())
                {
                    const auto intercom_light_id = m_property_ids.find(Project::ValueName::IntercomOutputs::INTERCOM_LIGHT);

                    if (intercom_light_id != m_property_ids.end())
                    {
                        const auto current_state = m_intercom_outputs_object.Numbers().Store().Get(intercom_light_id->second);
                        const auto flashing_state = current_state.value == 0 ? 1.0 : 0.0;
                        const auto status         = Sim::Number(flashing_state, intercom_light_id->second);
                        m_intercom_outputs_object.Numbers().Store().Set(status);
                    }
                }
            }

            return time + FLASH_INTERVAL;
        }
    }
}