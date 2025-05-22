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
        class ScoringRule
        {
        public:
            ScoringRule(Common::DataAccess &data_access);

            std::vector<Data::ScoringRule> GetAllScoringRules() const;
            std::vector<Data::ScoringRule> GetScoringRules(int category_id) const;
            Data::ScoringRule GetScoringRule(int rule_id) const;

        private:
            class ScoringRuleImpl &m_impl;
        };
    }
}
