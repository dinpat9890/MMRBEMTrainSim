///
/// @file       TextManagementModule.h
///
///             Module that handles the functionality related to the Text Management function of the CBTC OnBoard
///             System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

#include <list>

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Defines the standard structures required of a Module
        using TimestampedCBTCTextMessage  = std::pair<double, CBTC::Protos::CBTCTextMessages_CBTCTextMessage>;
        using TimestampedCBTCTextMessages = std::list<TimestampedCBTCTextMessage>;

        struct TextManagementModuleIO
        {
            struct Initialisation
            {
                unsigned long session_start_time = 0;
            };

            struct Inputs
            {
                //=========================================================================================
                // The following data is populated using inputs from the Train Model
                //=========================================================================================

                double cabin_activation      = Project::TypeValue::CabinActivation::INACTIVE;
                double safety_brake_state    = Project::TypeValue::SafetyBrakeState::INACTIVE;
                double selected_driving_mode = Project::TypeValue::DriverModeSelection::OFF;
                double current_train_speed;
                double train_docking_status = Project::TypeValue::TrainDockingStatus::UNKNOWN;

                //=========================================================================================
                // The following data is populated using inputs from the DMI
                //=========================================================================================

                /// Identifies the message that has been acknowledged
                double ack_text_message_id = UNDEFINED_TEXT_ID;

                //=========================================================================================
                // The following data is populated using inputs from the Onboard Controller
                //=========================================================================================

                /// Identifies where in the startup test process we currently are
                Project::CBTCOnBoard::TypeValue::StartupTestStage start_up_test_stage = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_NOT_ACTIVE;

                //=========================================================================================
                // The following data is populated using Outputs from the Mode Transition Module
                //=========================================================================================

                /// Identifies the current CBTC Driving Mode
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;

                //=========================================================================================
                // The following data is populated using Outputs from the Automatic Train Protection Module
                //=========================================================================================

                /// Used to control the emergency brake
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_condition =
                  Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;

                /// Flag specifying when the emergency brake is being applied
                bool emergency_brake_ordered = Project::TypeValue::EmergencyBrakeOrder::NO_EB_BRAKE;

                // Identifies when ATO is available for selection
                bool ato_is_available = false;
                //=========================================================================================
                // The following data is populated using Outputs from the Trackside Data Module
                //=========================================================================================

                /// Flags when the train is in the transition area associated with entering into the automatic region
                bool transition_into_automatic = false;
            };

            struct Outputs
            {
                //=========================================================================================
                // The following data is outputted to Automatic Train Protection Module
                //=========================================================================================

                /// Used to report the display of messages that require audio to be played
                bool new_high_priority_msg_reported = false;
                bool new_acknowledge_msg_reported   = false;

                CBTC::Protos::CBTCTextMessages cbtc_text_messages;
            };

            struct State
            {
                // List of high and low priority messages to be reported
                TimestampedCBTCTextMessages high_priority_message_list;
                TimestampedCBTCTextMessages low_priority_message_list;

                /// Used to determine when a High Priority / Ack message is first reported
                bool new_high_priority_msg_reported = false;
                bool new_acknowledge_msg_reported   = false;

                // Records the last reported ack message so that the same ack message is not generated
                // multiple time
                double last_reported_ack_message = UNDEFINED_TEXT_ID;

                // Identifies time at which scenario was started and used to set the text message timestamp
                unsigned long session_start_time = 0;

                /// ID to manage uniqueness among all messages of different categories.
                /// This is getting used to clear the message for which the acknowledgement
                /// is given by the driver, it will be an input from the DMI
                int unique_message_id = 0;

                // Record the previously reported emergency brake condition
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_condition =
                  Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;

                /// Record the previously reported flag specifying whether the emergency brake is being applied by the
                /// train protection system
                bool emergency_brake_ordered = false;

                /// Identies the previous state of the trains safety brake
                double safety_brake_state = Project::TypeValue::SafetyBrakeStatus::SAFETY_BRAKE_APPLIED;

                // Records the previous position of the driver mode selector
                double selected_driving_mode = Project::TypeValue::DriverModeSelection::OFF;

                /// Records the time at which the rolling stock EB was detected
                double rs_eb_report_time = INVALID_TIME;
            };
        };

        /// Module that handles the functionality related to the Text Message function of the CBTC OnBoard
        /// System.
        ///
        class TextManagementModule : public CBTCModule<TextManagementModule, TextManagementModuleIO>
        {
        public:
            TextManagementModule(const Initialisation& init);
            void Step(double elapsed_time);

        private:
            void ProcessTextConditions(double elapsed_time);
            void AddTextMessage(double elapsed_time, CBTC::Protos::TextId id, bool msg_ack_info, CBTC::Protos::TextMessagePriority priority);
            void ClearExpiredHighPriorityMessages(double elapsed_time);

            void UpdateMessageListOnAckReceived();

            bool IsMessageAlreadyInList(int id);
            bool IsMessageAlreadyInHighPriorityList(int id);
            void PopulateOutputMessageList();
            void ManageClearAllMessages();
            int  GenerateUniqueMessageId();
        };
    }
}
