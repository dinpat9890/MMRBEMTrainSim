///
/// @file       SessionAnalyserProperties.h
///
///             Declares the SessionAnalyserProperties class which provides consistent access to
///             properties.
///
/// @ingroup    Core Train Sim
///
/// @author     Dijon Page
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2009
///

#ifndef SESSION_ANALYSER_PROPERTIES_H
#define SESSION_ANALYSER_PROPERTIES_H

#include "core_properties/CommonProperties.h"

#include <vector>
#include <string>

namespace Project
{
    /// Provides consistent access to Session Analyser property file data. Intended to be used as
    /// part of the application properties type list.
    
    class SessionAnalyserProperties
    {
    public:
        explicit SessionAnalyserProperties(const Common::Properties &properties)
            : m_properties(properties)
        { }

        std::string              GetSaveCommand() const;
        std::vector<std::string> GetActiveInfractionRules(const std::string &car_class, const std::string &hub_mode) const;

        double      GetSunElevationDay() const;
        double      GetSunElevationNight() const;
        double      GetInfractionIgnoreTime() const;
        double      GetInfractionMonitoringDelayTime() const;
        std::string GetWhistleBoardFeatureName() const;
        std::string GetTunnelRegionFeatureName() const;
        std::string GetTownRegionFeatureName() const;

    private:
        const Common::Properties &m_properties;
    };
}

#endif // SESSION_ANALYSER_PROPERTIES_H
