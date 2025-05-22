/// @file      ScoringCategory.h
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
        class ScoringCategoryWeight
        {
        public:
            ScoringCategoryWeight(Common::DataAccess &data_access);

            std::vector<Data::ScoringCategoryWeight> GetAllScoringCategoryWeights() const;
            std::vector<Data::ScoringCategoryWeight> GetScoringCategoryWeights(int scheme_id) const;
            Data::ScoringCategoryWeight GetScoringCategoryWeight(int category_id, int scheme_id) const;

        private:
            class ScoringCategoryWeightImpl &m_impl;
        };
    }
}
