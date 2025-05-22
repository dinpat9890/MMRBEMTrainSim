/// @file FeatureProperties.h
/// Constants for feature type properties.
///
/// @ingroup   0060KS9A
/// @author    Simon Wade (simon.wade@sydac.com.au), Adam Zielinski
/// @copyright © SYDAC Pty Ltd, 2017
/// @internal
/// This is hand-rolled, and not automatically generated, like it should be :(
#pragma once
#include <string>

namespace Project
{
    namespace FeatureProperties
    {
        namespace PLATFORM
        {
            const std::string STATION_CODE  = "Station Code";
            const std::string PLATFORM_NAME = "Platform Name";
            const std::string LENGTH        = "Length";
        }

        namespace STOPPING_POINT
        {
            const std::string PLATFORM_FEATURE_ID   = "Platform Feature ID";
            const std::string STATION_CODE          = "Station Code";
            const std::string CSDE_CODE             = "CSDE Code";
            const std::string DOORS_INVERTED        = "Doors Inverted";

            namespace CSDE_CODE_ENUM
            {
                const double      LHS   = 1;
                const double      RHS   = 2;
            }

            namespace DOORS_INVERTED_ENUM
            {
                const double      NO     = 0;
                const double      YES    = 1;
            }
        }

        namespace PLATFORM_SCREEN_DOORS
        {
            const std::string PLATFORM_FEATURE_ID   = "Platform Feature ID";
            const std::string DOOR_POSITION         = "Door Position";
            const std::string SDO_CODE              = "SDO Code";
            const std::string NUMBER_DOORS          = "Number Doors";
            const std::string PASSENGER_TRAPPED     = "Passenger Trapped";

            enum PassengerTrappedValue
            {
                NOT_TRAPPED,
                TRAPPED,
                WALKING_AWAY_FROM_PSD
            };
        }

        namespace MARKER_BOARD
        {
            const std::string POP                    = "POP";
            const std::string OSP                    = "OSP";
            const std::string DISABLE_MA_OFFSET      = "Disable MA Offset";
        }

        namespace ATO_INHIBIT
        {
            const std::string ATO_INHIBIT_OFFSET     = "ATO Inhibit Offset";
            const std::string AM_END_OSP             = "AM End OSP";
            const std::string AM_END_POP             = "AM End POP";
        }

        namespace CONTROL_BALISE
        {
            const std::string ENTER_CBTC_PM_OFFSET   = "Enter CBTC PM Offset";
            const std::string CBTC_TRANSITION_OFFSET = "CBTC Transition Offset";
            const std::string EXIT_TRANSITION_MODE   = "Exit Transition Mode";
        }

        namespace POSITION_BALISE
        {
            const std::string VIRTUAL                = "Virtual";
        }

        namespace TRANSITION_BALISE
        {
            const std::string TRANSITION_OFFSET  = "Transition Offset";
            const std::string ACKNOWLEDGE_OFFSET = "Acknowledge Offset";
            const std::string AVAILABLE_LEVEL    = "Available Level";
        }
    }
}
