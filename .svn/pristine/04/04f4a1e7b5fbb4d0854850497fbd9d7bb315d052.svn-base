#include "DBScoringParameterProvider.h"
#include "common/CommonExceptions.h"
#include "scoring_data_access/ScoringParameter.h"
#include <iterator>

Scoring::DBScoringParameterProvider::DBScoringParameterProvider(Common::DataAccess& data_access)
  : m_name_to_parameter(
    [&data_access]()
    {
        std::map<std::string, Scoring::Data::ScoringParameter, std::less<>> map;
        for(const auto& parameter : Scoring::Database::ScoringParameter{data_access}.GetAllScoringParameters())
            map.emplace(parameter.name, parameter);

        return map;
    }())
{
}

double Scoring::DBScoringParameterProvider::GetParameterValue(std::string_view parameter_name) const
{
    if (const auto map_iterator{m_name_to_parameter.find(parameter_name)};
        map_iterator != std::cend(m_name_to_parameter))
    {
        return map_iterator->second.si_value;
    }

    throw CommonException(FLSTAMP, ("Parameter '" + std::string{parameter_name} + "' unknown").c_str());
}