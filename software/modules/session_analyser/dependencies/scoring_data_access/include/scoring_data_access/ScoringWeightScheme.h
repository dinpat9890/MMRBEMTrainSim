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
        class ScoringWeightScheme
        {
        public:
            ScoringWeightScheme(Common::DataAccess &data_access);

            std::vector<Data::ScoringWeightScheme> GetAllScoringWeightSchemes() const;
            Data::ScoringWeightScheme GetScoringWeightScheme(int scheme_id) const;

        private:
            class ScoringWeightSchemeImpl &m_impl;
        };
    }
}
