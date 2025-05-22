#pragma once
#include "ScoringParameterProvider.h"
#include "common/DataAccess.h"
#include "scoring_data_access/ScoringDataAccessTypes.h"
#include <map>
#include <string>

namespace Scoring
{
    class DBScoringParameterProvider : public ScoringParameterProvider
    {
    public:
        explicit DBScoringParameterProvider(Common::DataAccess& data_access);

        double GetParameterValue(std::string_view parameter_name) const override;
    private:
        const std::map<std::string, Scoring::Data::ScoringParameter, std::less<>> m_name_to_parameter;
    };
}