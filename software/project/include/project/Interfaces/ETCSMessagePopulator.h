///
/// @file       ETCSMessagePopulator.h
///
///             Declares the interface class that should be used to create resources that populate message data
///             sent to the ETCS OnBoard Unit.
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

namespace Core
{
    namespace ETCS
    {
        /// Defines the interface for the resources that populate ETCS message data.
        /// The MessageType identifies the ETCS message type that a given instance of the message populator is responsible for populating

        template <class MessageType> class MessagePopulator
        {
        public:
            /// Destructor so that the implementation classes' destructors are called
            virtual ~MessagePopulator() {}

            /// Populates the message data located in the referenced ETCS message.
            ///
            /// @param message Reference to the message into which message data is to be written
            /// @param optional_packet_ids Identifies the optional packets that need to be added into the message
            ///
            virtual void PopulateMessage(MessageType &message, std::vector<Core::ETCSOnBoard::Protos::SupportedPacketIds> optional_packet_ids) = 0;
        };
    }
}
