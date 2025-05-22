/// @file      ScenarioTrainTypeService.cpp
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#include "ScenarioTrainTypeService.h"
#include "DataAccess/DataAccess.h"

ScenarioTrainTypeService::ScenarioTrainTypeService(const int                  scenario_id,
                                                   DataAccess::SimulatorData &simulator_data)
{
    for(const auto &scenario_train : simulator_data.GetScenarioTrains(scenario_id))
    {
        const auto train = simulator_data.GetTrain(scenario_train.train_id);
        m_scenario_train_id_to_train_type_id.insert(std::make_pair(scenario_train.scenario_train_id, train.type));
    }
}

int ScenarioTrainTypeService::GetTrainType(const int scenario_train_id)
{
    try
    {
        return m_scenario_train_id_to_train_type_id.at(scenario_train_id);
    }
    catch(std::out_of_range &e) { } // This just means we don't know about this train.

    return -1;
}
