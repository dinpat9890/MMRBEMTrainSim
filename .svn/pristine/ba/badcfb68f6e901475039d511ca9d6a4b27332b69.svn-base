#ifndef PROJECT_PROPERTIES_H
#define PROJECT_PROPERTIES_H

#include "Config/CommonProperties.h"

#include <string>
#include <vector>

namespace Core { struct AdjacencyConfig; }

namespace Project
{
    class DynamicFeatureProperties
    {
    public:
        DynamicFeatureProperties(const Sydac::Properties &properties)
            : m_properties(properties)
        { }

        double GetAcceleration() const;
        double GetDeceleration() const;
        double GetMaxSpeed() const;

    private:
        const Sydac::Properties &m_properties;
    };

    //  Class:          TrainInteractionProperties
    //
    //  Description:    Class containing the logic for extracting information about how a train
    //                  interacts with the world from the properties file.

    class TrainInteractionProperties
    {
    public:
        TrainInteractionProperties(const Sydac::Properties &properties)
            : m_properties(properties)
        { }

        Core::AdjacencyConfig GetAdjacencyConfig() const;

    private:
        const Sydac::Properties &m_properties;
    };

    //  Class:          TrainSelectionProperties
    //
    //  Description:    Class containing the logic for extracting information about how to choose
    //                  which trains to model from the properties file.

    class TrainSelectionProperties
    {
    public:
        TrainSelectionProperties(const Sydac::Properties &properties)
            : m_properties(properties)
        { }

        bool UseDB() const;

    private:
        const Sydac::Properties &m_properties;
    };

    //  Class:          PlatformPassengerProperties
    //
    //  Description:    Class containing the platform passenger properties contained within
    //                  the properties file.

    class PlatformPassengerProperties
    {
    public:
        PlatformPassengerProperties(const Sydac::Properties &properties)
            : m_properties(properties)
        { }

        double GetInRangeThreshold() const;
        double GetStationarySpeedThreshold() const;
        double GetParkingThreshold() const;
        double GetDefaultPlatformLength() const;

    private:
        const Sydac::Properties &m_properties;
    };
}

#endif // PROJECT_PROPERTIES_H
