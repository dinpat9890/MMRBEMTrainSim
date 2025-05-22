#pragma once

namespace Common { class Properties; }

class SpeedLimitTrackerProperties
{
public:
    explicit SpeedLimitTrackerProperties(const Common::Properties &properties);

    bool EnableMainlineLimits() const;
    bool EnableSignalLimits() const;
    bool EnableCrossoverLimits() const;
    bool EnableTemporaryLimits() const;

private:
    const Common::Properties &m_properties;
};
