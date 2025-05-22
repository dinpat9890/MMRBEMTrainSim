///
/// @file       ETCSPacketPopulator.h
///
///             Declares the interface class that should be used to create resources that populate packet data
///             sent to the ETCS OnBoard Unit.
///
/// @ingroup    CoreTrainSim
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
///

#pragma once

// The following include file identifies the ETCS data packet types for which a packet populator resources may need to be created
#include "ETCSExternalInterface.pb.h"

namespace Core
{
    namespace ETCS
    {

        /// Defines the interface for the resources that populate ETCS packet data.
		/// The PacketType identifies the ETCS packet type that a given instance of the packet populator is responsible for populating

		template <class PacketType> class PacketPopulator
        {
        public:
			/// Destructor so that the implementation classes' destructors are called
            virtual ~PacketPopulator() {}

            /// Populates the packet data located in the referenced ETCS packet.
            ///
			/// @param packet Reference to the packet into which packet data is to be written
			///
			/// @returns true if the packet was successfully populated, false otherwise
			///
            virtual bool PopulatePacket(PacketType &packet) = 0;
        };
    }
}
