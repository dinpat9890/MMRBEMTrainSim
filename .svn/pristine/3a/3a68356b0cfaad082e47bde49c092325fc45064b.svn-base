#pragma once

// Include core types so that we can pull in the name space below
#include <core_data_access/CoreDataAccessTypes.h>

#include <string>

namespace Scoring
{
    namespace Data
    {
        // Make all core types available just using the Train::Data namespace
        using namespace Core::Data;

        struct ScoringParameter
        {
            int             parameter_id;
            int             category_id;
            int             rule_id;
            std::string     name;
            double          si_value;
            std::string     display_units;
            double          lower_bound;
            double          upper_bound;
            std::string     display_units_label;
        };

        struct ScoringRule
        {
            int             rule_id;
            int             category_id;
            std::string     name;
            std::string     description_short;
            std::string     description_long;
        };

        struct ScoringRuleWeight
        {
            int             rule_id;
            int             category_id;
            int             scheme_id;
            double          weight;
        };

        struct ScoringCategory
        {
            int             category_id;
            std::string     name;
            std::string     description;
        };

        struct ScoringCategoryWeight
        {
            int             category_id;
            int             scheme_id;
            double          weight;
        };

        struct ScoringWeightScheme
        {
            int             scheme_id;
            std::string     name;
            std::string     description;
        };
    }
}
