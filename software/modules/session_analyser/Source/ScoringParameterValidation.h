#pragma once
#include "common/CommonExceptions.h"
#include "fmt/format.h"
#include "ScoringParameterProvider.h"
#include <string_view>

namespace Scoring
{
    template <typename Validator>
    auto GetParameter(
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name,
        Validator                                validator,
        std::string_view                         validator_description)
    {
        const auto value{parameter_provider.GetParameterValue(parameter_name)};

        if (!validator(value))
        {
            throw CommonException{fmt::format(
                    "Invalid scoring parameter {}={} ({})",
                    parameter_name,
                    value,
                    validator_description).c_str()};
        }

        return value;
    }

    static auto GetPositiveParameter(
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name)
    {
        return GetParameter(
            parameter_provider,
            parameter_name,
            [](const auto& value) { return value > 0; },
            "Value must be > 0");
    }

    static auto GetNonNegativeParameter(
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name)
    {
        return GetParameter(
            parameter_provider,
            parameter_name,
            [](const auto& value) { return value >= 0; },
            "Value must be >= 0");
    }

    static auto GetNegativeParameter(
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name)
    {
        return GetParameter(
            parameter_provider,
            parameter_name,
            [](const auto& value) { return value < 0; },
            "Value must be < 0");
    }

    static auto GetParameterGreaterThan(
        double                                   minimum_value,
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name)
    {
        return GetParameter(
            parameter_provider,
            parameter_name,
            [minimum_value](const auto& value) { return value > minimum_value; },
            fmt::format("Value must be > {}", minimum_value));
    }

    static auto GetParameterGreaterThanOrEqualTo(
        double                                   minimum_value,
        const Scoring::ScoringParameterProvider& parameter_provider,
        std::string_view                         parameter_name)
    {
        return GetParameter(
            parameter_provider,
            parameter_name,
            [minimum_value](const auto& value) { return value >= minimum_value; },
            fmt::format("Value must be >= {}", minimum_value));
    }
}