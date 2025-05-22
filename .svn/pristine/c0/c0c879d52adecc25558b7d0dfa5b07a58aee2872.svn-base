/// @file      ScoringParameter.h
/// @author    Ben van Gompel
/// @copyright © SYDAC Pty Ltd, 2018

#pragma once

#include "ScoringDataAccessTypes.h"

#include "common/DataAccess.h"

#include <vector>
#include <string>

namespace Scoring
{
    namespace Database
    {
        class ScoringParameter
        {
        public:
            ScoringParameter(Common::DataAccess &data_access);

            std::vector<Data::ScoringParameter> GetAllScoringParameters() const;
            std::vector<Data::ScoringParameter> GetScoringParameters(int rule_id) const;
            Data::ScoringParameter GetScoringParameter(int parameter_id) const;

        private:
            class ScoringParameterImpl &m_impl;
        };
    }
}
