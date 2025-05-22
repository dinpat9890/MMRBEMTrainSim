#include "SpeedLimitTrackerProperties.h"

#include <Common/Properties.h>
#include <string>

namespace
{
    namespace SpeedLimits
    {
        const std::string SECTION_NAME = "Speed Limits";

        namespace Keys
        {
            const std::string ENABLE_LINE_LIMITS      = "Enable Line Limits";
            const std::string ENABLE_SIGNAL_LIMITS    = "Enable Signal Limits";
            const std::string ENABLE_CROSSOVER_LIMITS = "Enable Crossover Limits";
            const std::string ENABLE_TEMPORARY_LIMITS = "Enable Temporary Limits";
        }

        namespace Defaults
        {
            const bool ENABLE_LINE_LIMITS      = true;
            const bool ENABLE_SIGNAL_LIMITS    = true;
            const bool ENABLE_CROSSOVER_LIMITS = true;
            const bool ENABLE_TEMPORARY_LIMITS = true;
        }
    }
}

SpeedLimitTrackerProperties::SpeedLimitTrackerProperties(const Common::Properties &properties)
  : m_properties(properties)
{
}

bool SpeedLimitTrackerProperties::EnableMainlineLimits() const
{
    return m_properties.GetProperty(SpeedLimits::SECTION_NAME,
                                    SpeedLimits::Keys::ENABLE_LINE_LIMITS,
                                    SpeedLimits::Defaults::ENABLE_LINE_LIMITS);
}

bool SpeedLimitTrackerProperties::EnableSignalLimits() const
{
    return m_properties.GetProperty(SpeedLimits::SECTION_NAME,
                                    SpeedLimits::Keys::ENABLE_SIGNAL_LIMITS,
                                    SpeedLimits::Defaults::ENABLE_SIGNAL_LIMITS);
}

bool SpeedLimitTrackerProperties::EnableCrossoverLimits() const
{
    return m_properties.GetProperty(SpeedLimits::SECTION_NAME,
                                    SpeedLimits::Keys::ENABLE_CROSSOVER_LIMITS,
                                    SpeedLimits::Defaults::ENABLE_CROSSOVER_LIMITS);
}

bool SpeedLimitTrackerProperties::EnableTemporaryLimits() const
{
    return m_properties.GetProperty(SpeedLimits::SECTION_NAME,
                                    SpeedLimits::Keys::ENABLE_TEMPORARY_LIMITS,
                                    SpeedLimits::Defaults::ENABLE_TEMPORARY_LIMITS);
}