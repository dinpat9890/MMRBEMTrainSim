/// @file ScenarioTrainLengthService.cpp
/// Implementation of the ITrainLengthService interface that uses DataAccess
/// to determine the train length.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#include "ScenarioTrainLengthService.h"
#include "train_data_access/Train.h"
#include "world_api/WorldAccess.h"
#include <numeric>

ScenarioTrainLengthService::ScenarioTrainLengthService(const int               scenario_id,
                                                       Train::Database::Train &train_data)
{
    // If everything is working normally, I don't *think* that
    // GetScenarioTrains() will throw (on an invalid scenario ID). Sadly, our
    // documentation is a steaming turd pile, so I have no idea what
    // implementations are contractually obliged to do with invalid parameters.
    for(const auto &scenario_train : train_data.GetScenarioTrains(scenario_id))
    {
        // Same comment as above, but applied to GetTrainElements().
        const auto train_elements = train_data.GetTrainElements(scenario_train.train_id);
        const auto train_length   = std::accumulate(train_elements.cbegin(),
                                                    train_elements.cend(),
                                                    0.0,
                                                    [](const double length, const Train::Data::TrainElement &train_element)
                                                    {
                                                        return length + train_element.length;
                                                    });

        m_scenario_train_id_to_train_length[scenario_train.scenario_train_id] = train_length;
    }
}

double ScenarioTrainLengthService::GetTrainLength(const int scenario_train_id)
{
    try
    {
        return m_scenario_train_id_to_train_length.at(scenario_train_id);
    }
    catch (std::out_of_range) { } // This just means we don't know the length of this train.

    return 0.0;
}
