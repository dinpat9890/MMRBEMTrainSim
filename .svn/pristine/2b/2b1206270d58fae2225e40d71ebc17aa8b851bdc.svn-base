/// @file      ScoringRule.h
/// @author    Ben van Gompel
/// @copyright © SYDAC Pty Ltd, 2018

#pragma once

#include "ScoringDataAccessTypes.h"

#include "common/DataAccess.h"

#include <vector>

namespace Scoring
{
    namespace Database
    {
        class ScoringRuleWeight
        {
        public:
            ScoringRuleWeight(Common::DataAccess &data_access);

            std::vector<Data::ScoringRuleWeight> GetAllScoringRuleWeights() const;
            std::vector<Data::ScoringRuleWeight> GetScoringRuleWeights(int scheme_id) const;
            Data::ScoringRuleWeight GetScoringRuleWeight(int rule_id, int scheme_id) const;

        private:
            class ScoringRuleWeightImpl &m_impl;
        };
    }
}
