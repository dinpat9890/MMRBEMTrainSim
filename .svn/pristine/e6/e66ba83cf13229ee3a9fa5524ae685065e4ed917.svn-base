#include "ProjectProperties.h"

#include "CoreUnits/TrainModelStructures.h"

namespace Project
{
    namespace
    {
        // Constants for the automatic trains properties
        const std::string DYNAMIC_FEATURE_SECTION       = "Dynamics";
        const std::string ACCELERATION                  = "Acceleration";
        const std::string DECELERATION                  = "Deceleration";
        const std::string MAX_SPEED                     = "Max Speed";

        const std::string ADJACENCY_SECTION_BASE        = "Adjacency - ";
        const std::string ADJACENCY_TYPE                = "Type";
        const std::string TYPE_BASE                     = "Feature.";
        const std::string STATE_BASE                    = "State.";
        const std::string FORWARD_BASE                  = "Forward.";
        const std::string VALUE_BASE                    = "Value.";

        const std::string TRAIN_SELECTION_SECTION       = "Train Selection";
        const std::string USE_DB                        = "Use DB";

        const std::string PLATFORM_PASSENGER_SECTION    = "Platform Passenger";
        const std::string IN_RANGE_THRESHOLD            = "In Range Threshold";
        const std::string STATIONARY_SPEED_THRESHOLD    = "Stationary Speed Threshold";
        const std::string PARKING_THRESHOLD             = "Parking Threshold";
        const std::string DEFAULT_PLATFORM_LENGTH       = "Default Platform Length";

        ///  Function:       GetAdjacencyTypeConfig
        //
        //  Description:    Extracts feature type names, states, directions and values associated
        //                  with the section defined. There may be multiple feature types specified,
        //                  so these are all paired by a common postfix (per feature type). This
        //                  looks at all keys defined, determines which features have been
        //                  satisfactorily defined and then adds their data to the return structure.
        //
        //  Parameters:
        //      const Sydac::Properties &properties - The properties file to extract the
        //                          configuration from.
        //      const std::string &section - The section within the properties file to use.
        //
        //  Return value:
        //      Core::AdjacencyConfig::AdjacencyTypeConfig - The resultant configuration.

        Core::AdjacencyConfig::AdjacencyTypeConfig GetAdjacencyTypeConfig(const Sydac::Properties &properties, const std::string &section)
        {
            Core::AdjacencyConfig::AdjacencyTypeConfig ret;

            // Firstly, this must support the Type key that will specify the string that should be
            // used to identify this adjacency type everywhere, including in the DLL.
            // If this doesn't exist then we need to throw anyway.
            ret.first = properties.GetProperty<std::string>(section, ADJACENCY_TYPE);

            // Read in all of the keys, and work out which ones begin with a key name that we are
            // interested in. Ensure that we have all necessities defined for each feature type,
            // so we will use a map to track these.
            std::map<std::string, std::tr1::tuple<bool, bool, bool, bool> > defined;

            const std::vector<std::string> ALL_KEYS = properties.ListKeys(section);
            for(size_t i = 0; i < ALL_KEYS.size(); ++i)
            {
                // Is this a feature type name?
                if(ALL_KEYS[i].find(TYPE_BASE) == 0)
                    std::tr1::get<Core::AdjacencyConfig::FEATURE>(defined[ALL_KEYS[i].substr(TYPE_BASE.size())]) = true;
                // Or the state name?
                else if(ALL_KEYS[i].find(STATE_BASE) == 0)
                    std::tr1::get<Core::AdjacencyConfig::STATE>(defined[ALL_KEYS[i].substr(STATE_BASE.size())]) = true;
                // Or the forward/reverse indication?
                else if(ALL_KEYS[i].find(FORWARD_BASE) == 0)
                    std::tr1::get<Core::AdjacencyConfig::FORWARD>(defined[ALL_KEYS[i].substr(FORWARD_BASE.size())]) = true;
                // Or the value to use?
                else if(ALL_KEYS[i].find(VALUE_BASE) == 0)
                    std::tr1::get<Core::AdjacencyConfig::VALUE>(defined[ALL_KEYS[i].substr(VALUE_BASE.size())]) = true;
            }

            // Run through the map now and work out which feature types have been completely
            // defined. To be completely defined we need to have a type name and state specified.
            // It is optional to specify the value and the forward direction indicator.
            for(std::map<std::string, std::tr1::tuple<bool, bool, bool, bool> >::iterator iter = defined.begin(); iter != defined.end(); )
            {
                if(!std::tr1::get<0>(iter->second) || !std::tr1::get<1>(iter->second))
                {
                    // Firstly, log this so they know that something is wrong with the ini file
                    Trace::g_plog->STAMP(Trace::WARN) << "Feature type '" << iter->first << "' in section '" << section << "' was inadequately specified." << Trace::EndLog();

                    // Next, remove this from the map so that we don't try and populate it in the
                    // config
                    defined.erase(iter++);
                }
                else
                    ++iter;
            }

            // Run through the map again, which should only have completely defined types in it
            // now, and start populating the config.
            for(std::map<std::string, std::tr1::tuple<bool, bool, bool, bool> >::const_iterator iter = defined.begin(); iter != defined.end(); ++iter)
            {
                Core::AdjacencyConfig::FeatureTypeStateConfig this_feature_type;

                // Read in the type and state - these are mandatory
                std::tr1::get<Core::AdjacencyConfig::FEATURE>(this_feature_type) = properties.GetProperty<std::string>(section, (TYPE_BASE + iter->first));
                std::tr1::get<Core::AdjacencyConfig::STATE>(this_feature_type)   = properties.GetProperty<std::string>(section, (STATE_BASE + iter->first));

                // Direction is optional, and defaults to first if not specified
                std::tr1::get<Core::AdjacencyConfig::FORWARD>(this_feature_type) = std::tr1::get<Core::AdjacencyConfig::FORWARD>(iter->second) ? (properties.GetProperty<int>(section, (FORWARD_BASE + iter->first)) != 0) : true;

                // Value is optional, and defaults to 1.0 if not specified
                std::tr1::get<Core::AdjacencyConfig::VALUE>(this_feature_type)   = std::tr1::get<Core::AdjacencyConfig::VALUE>(iter->second)   ? properties.GetProperty<double>(section, (VALUE_BASE + iter->first)) : 1.0;

                // Add this feature type to the adjacency type config that we are returning
                ret.second.push_back(this_feature_type);
            }

            return ret;
        }
    }

    // Dynamic Features Properties
    // ===========================

    double DynamicFeatureProperties::GetAcceleration() const
    {
        return m_properties.GetProperty<double>(DYNAMIC_FEATURE_SECTION, ACCELERATION, 10.0);
    }

    double DynamicFeatureProperties::GetDeceleration() const
    {
        return m_properties.GetProperty<double>(DYNAMIC_FEATURE_SECTION, DECELERATION, 5.0);
    }

    double DynamicFeatureProperties::GetMaxSpeed() const
    {
        return m_properties.GetProperty<double>(DYNAMIC_FEATURE_SECTION, MAX_SPEED, 30.0);
    }

    // Train Interaction Properties
    // ============================

    //  Function:       TrainInteractionProperties::GetAdjacencyConfig
    //
    //  Description:    Extracts the data to be used by the track-based feature adjacency detection
    //                  functionality.
    //
    //  Return value:
    //      Core::AdjacencyConfig - The AdjacencyConfig holding the configuration of the feature
    //                          types, states and associated values for each 'kind' of adjacency.

    Core::AdjacencyConfig TrainInteractionProperties::GetAdjacencyConfig() const
    {
        Core::AdjacencyConfig ret;

        // Look for all sections in the properties file that start "Adjacency" and which thus
        // indicate that they hold the configuration for an adjacency type.
        std::vector<std::string> ALL_SECTIONS = m_properties.ListSections();
        for(size_t i = 0; i < ALL_SECTIONS.size(); ++i)
        {
            // If this denotes an adjacency section, read in the configuration
            if(ALL_SECTIONS[i].find(ADJACENCY_SECTION_BASE) == 0)
                ret.adjacency_types.push_back(GetAdjacencyTypeConfig(m_properties, ALL_SECTIONS[i]));
        }

        return ret;
    }

    // Train Selection Properties
    // ==========================

    //  Function:       TrainSelectionProperties::UseDB
    //
    //  Description:    Returns whether the 'Use DB' flag has been set in the properties file.
    
    bool TrainSelectionProperties::UseDB() const
    {
        return m_properties.GetProperty<int>(TRAIN_SELECTION_SECTION, USE_DB, 1) != 0;
    }

    // Platform Passenger Properties
    // =============================

    //  Function:       PlatformPassengerProperties::GetInRangeThreshold
    //
    //  Description:    Returns the value in the properties file, defining when
    //                  a train is within range of a Platform, so that we should have idle passengers.

    double PlatformPassengerProperties::GetInRangeThreshold() const
    {
        return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, IN_RANGE_THRESHOLD, 1000.0);
    }

    //  Function:       PlatformPassengerProperties::GetStationarySpeedThreshold
    //
    //  Description:    Returns the value in the properties file, defining the speed at which the train is considered
    //                  stopped.

    double PlatformPassengerProperties::GetStationarySpeedThreshold() const
    {
        return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, STATIONARY_SPEED_THRESHOLD, 0.1);
    }

    //  Function:       PlatformPassengerProperties::GetParkingThreshold
    //
    //  Description:    Returns the value in the properties file, which allows us to determine
    //                  whether a train is parked at a platform.

    double PlatformPassengerProperties::GetParkingThreshold() const
    {
        return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, PARKING_THRESHOLD, 100.0);
    }

    //  Function:       PlatformPassengerProperties::GetDefaultPlatformLength
    //
    //  Description:    Returns the value in the properties file, defining the 
    //                  default platform length when one is not available on a platform feature.

    double PlatformPassengerProperties::GetDefaultPlatformLength() const
    {
        return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, DEFAULT_PLATFORM_LENGTH, 200.0);
    }
}
