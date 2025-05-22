/// @file       ConstantDefined declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#pragma once

#include <project_comms_structure/ProjectObjectConstants.h>


#include <sim_common/DataTypes.h>
#include <sim_comms/Unit.h>

namespace PIS
{
    const int SCC_TO_CAB = 3;
    namespace Intercom
    {
        // Comms Object: IntercomOuputs Public Address lights
        enum class PAOutput
        {
            PA_IN_LIGHT,
            PA_OUT_LIGHT
        };

        // Comms Object: OHPOutputs Status
        enum class OHPOutputs
        {
            STATUS,
            WAIT_INDICATOR,
            SPEAK_INDICATOR,
            LISTEN_INDICATOR
        };

        enum class IntercomCallState
        {
            INACTIVE     = Project::TypeValue::IntercomConstant::INACTIVE,
            CALL_REQUEST = Project::TypeValue::IntercomConstant::CALL_REQUEST,
            ACTIVE       = Project::TypeValue::IntercomConstant::ACTIVE,
            ISOLATED     = Project::TypeValue::IntercomConstant::ISOLATED,
            DEISOLATED   = Project::TypeValue::IntercomConstant::DEISOLATED,
        };

        enum class ActiveCallType
        {
            INACTIVE   = Project::TypeValue::ActiveCallTypeConstant::INACTIVE,
            CAB_TO_CAB = Project::TypeValue::ActiveCallTypeConstant::CAB_TO_CAB,
            OHP        = Project::TypeValue::ActiveCallTypeConstant::OHP,
            CAB_TO_CAB_INSTRUCTOR = SCC_TO_CAB,
        };

        // Comms Object : Button Values ACTIVE/INACTIVE
        enum class State
        {
            INACTIVE = 0,
            ACTIVE
        };

        // Comms Object : Button Values ON/OFF
        enum class IO
        {
            OFF = 0,
            ON,
            FLASHING
        };

        // Comms Object : OHPOutputs Status values
        enum class Status
        {
            NORMAL,
            FAULT,
            CALLING,
            TALKING,
            ISOLATED,
            DEISOLATED
        };

        // Comms Object : Button States
        enum ButtonState
        {
            PRESSED,
            RELEASED
        };

        // Button Types
        enum class MessageType
        {
            IC_CAB,
            IC_CANCEL,
            IC_SCC,
            IC_SCC_CANCEL,
            IC_OHP,
            IC_EBM,
            PA_IN,
            PA_OUT,
            NONE
        };

        // Message States
        enum class MessageState
        {
            AWAITING,
            CONNECTED
        };

        // Unique id of OHP Device
        struct OHPID
        {
            int m_vehicle_id;
            int m_ohp_id;

            OHPID()
                :m_vehicle_id(0), m_ohp_id(0)
            {
            }
            
            OHPID(int vehicle_id, int ohp_id)
                : m_vehicle_id(vehicle_id), m_ohp_id(ohp_id)
            {}

            bool operator== (const OHPID& rhs) const
            {
                return std::tie(m_vehicle_id, m_ohp_id) == std::tie(rhs.m_vehicle_id, rhs.m_ohp_id);
            }

            bool operator<(const OHPID& rhs) const
            {
                return std::tie(m_vehicle_id, m_ohp_id) < std::tie(rhs.m_vehicle_id, rhs.m_ohp_id);
            }

            bool operator!=(const OHPID& rhs) const
            {
                return !(rhs != *this);
            }
        };

        // Unique id of each messages 
        struct MessageID
        {
            int m_vehicle_id;
            int m_ohp_id;
            int m_break_leaver_id;

            MessageID()
                :m_vehicle_id(-1), m_ohp_id(-1), m_break_leaver_id(-1)
            {            
            }

            MessageID(int vehicle_id, int ohp_id)
                : m_vehicle_id(vehicle_id), m_ohp_id(ohp_id), m_break_leaver_id(-1)
            {}

            MessageID(int vehicle_id, int ohp_id, int break_leaver_id)
                : m_vehicle_id(vehicle_id), m_ohp_id(ohp_id), m_break_leaver_id(break_leaver_id)
            {}

            bool operator== (const MessageID& rhs) const
            {
                return std::tie(m_vehicle_id, m_ohp_id, m_break_leaver_id) == std::tie(rhs.m_vehicle_id, rhs.m_ohp_id, rhs.m_break_leaver_id);
            }

            bool operator<(const MessageID& rhs) const
            {
                return std::tie(m_vehicle_id, m_ohp_id, m_break_leaver_id) < std::tie(rhs.m_vehicle_id, rhs.m_ohp_id, rhs.m_break_leaver_id);
            }

            bool operator!=(const MessageID& rhs) const
            {
                return !(rhs == *this);
            }
        };


        class Message
        {
        public:
            Message(const PIS::Intercom::MessageType        type,
                    const PIS::Intercom::ButtonState        button_state,
                    const PIS::Intercom::MessageState       state = PIS::Intercom::MessageState::AWAITING)
                : m_type(type), m_button_state(button_state), m_state(state)
            {
            }

            void SetType(const MessageType message_type)
            {
                m_type = message_type;
            }

            void SetData(const OHPID& ohp_id, const int eb_id=-1)
            {
                if (eb_id < 0)
                {
                    m_data.reset(new OHPData(ohp_id));
                }
                else
                {
                    MessageID message_id(ohp_id.m_vehicle_id, ohp_id.m_ohp_id, eb_id);
                    m_data.reset(new EmergencyData(message_id));
                }
            }

            PIS::Intercom::MessageState GetMessageState() const
            {
                return m_state;
            }

            PIS::Intercom::MessageType  GetMessageType() const
            {
                return m_type;
            }

            PIS::Intercom::ButtonState  GetButtonState() const
            {
                return m_button_state;
            }

            bool IsMessageDataPresent() const
            {
                return m_data != nullptr;
            }

            PIS::Intercom::MessageID  GetMessageID() const
            {
                if (m_data)
                {
                    return m_data->GetMessageID();
                }

                return MessageID();
            }

        private:

            class Data
            {
            public:
                ~Data() {};
                virtual MessageID GetMessageID() const = 0;
            };

            class OHPData : public Data
            {
            public:
                explicit OHPData(const OHPID ohp_id) : m_ohp_id(ohp_id)
                { }

                MessageID GetMessageID() const override
                {
                    return { m_ohp_id.m_vehicle_id,m_ohp_id.m_ohp_id ,-1 };
                }

            private:
                OHPID m_ohp_id;
            };

            class EmergencyData : public Data
            {
            public:
                explicit EmergencyData(const OHPID ohp_id) : m_ohp_id(ohp_id), m_eb_id(0)
                { }

                EmergencyData(const OHPID ohp_id, const int eb_id) : m_ohp_id(ohp_id), m_eb_id(eb_id)
                { }

                EmergencyData(const MessageID message_id)
                { 
                    m_ohp_id = OHPID(message_id.m_vehicle_id, message_id.m_ohp_id);
                    m_eb_id = message_id.m_break_leaver_id;
                }

                MessageID GetMessageID() const override
                {
                    return { m_ohp_id.m_vehicle_id,m_ohp_id.m_ohp_id ,m_eb_id };
                }

            private:
                OHPID m_ohp_id;
                int   m_eb_id;
            };

            PIS::Intercom::MessageState     m_state;
            PIS::Intercom::MessageType      m_type;
            PIS::Intercom::ButtonState      m_button_state;
            std::unique_ptr<Data>           m_data;
        };
    }
}
