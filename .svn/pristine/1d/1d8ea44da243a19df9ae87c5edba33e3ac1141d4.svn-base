#pragma once
#include <string_view>

namespace Scoring
{
    class ScoringParameterProvider
    {
    public:
        virtual ~ScoringParameterProvider() noexcept
        {
        }

        /// @return The value of the parameter, in SI units.
        /// @throw CommonException if the parameter is unknown.
        virtual double GetParameterValue(std::string_view parameter_name) const = 0;
    };
}