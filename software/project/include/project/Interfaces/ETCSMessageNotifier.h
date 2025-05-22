///
/// @file       ETCSMessageNotifier.h
///
///             Declares the interface class that should be used to create resources that allows one unit to
///             notify another unit that it should send a given message.
///
/// @ingroup    CoreTrainSim
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
///

#pragma once

// The following include file identifies the ETCS message types for which a message populator resources may need to be created
#include "ETCSExternalInterface.pb.h"

#include <functional>

namespace Core
{
    namespace ETCS
    {
        /// Defines the interface for the resources that populate ETCS message data.
		/// The MessageType identifies the ETCS message type that a given instance of the message populator is responsible for populating

		class ETCSMessageNotifier
        {
        public:
            // Identifies the messages that can be sent by the notifier
			enum ETCSMessageId
			{
				BALISE_TELEGRAM    = 0,
				SR_AUTHORISATION   = 2,
				MOVEMENT_AUTHORITY = 3,
                GENERAL            = 24
			};

			/// Destructor so that the implementation classes' destructors are called
            virtual ~ETCSMessageNotifier() {}

			/// Registers a message callback. Registered callbacks will get called when there is a new message to send to the ETCS OnBoard System.
			///
			/// @param callback The callback to be registered for message notification
			///
			virtual int RegisterMessageCallback(const std::function<void(const Core::ETCSOnBoard::Protos::ETCSMessage &)> &callback) = 0;

            virtual void UnRegisterMessageCallback(int cb_index) = 0;

            /// Trigger the sending of a message to all registered parties
            ///
            /// This message will be populated using the message and packet populators
			///
			/// @param message_id          Identifies the message to be sent
            /// @param optional_packet_ids Identifies the optional packets that are to be included in the message
            ///
			virtual void SendMessage(ETCSMessageId message_id, std::vector<Core::ETCSOnBoard::Protos::SupportedPacketIds> optional_packet_ids) = 0;

            /// Trigger the sending of a message to all registered parties
			///
			/// @param etcs_message  The prepopulated ETCS message that needs to be sent
            ///
			virtual void SendMessage(const Core::ETCSOnBoard::Protos::ETCSMessage &etcs_message) = 0;
        };
    }
}
