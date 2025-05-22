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
        class ScoringCategory
        {
        public:
            ScoringCategory(Common::DataAccess &data_access);

            std::vector<Data::ScoringCategory> GetAllScoringCategories() const;
            Data::ScoringCategory GetScoringCategory(int category_id) const;

        private:
            class ScoringCategoryImpl &m_impl;
        };
    }
}
