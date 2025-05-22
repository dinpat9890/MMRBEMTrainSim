/// @file ScenarioTrainLengthService.h
/// Implementation of the IScenarioTrainLengthService interface that uses
/// DataAccess to determine the train length.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "IScenarioTrainLengthService.h"
#include <map>

namespace Train::Database { class Train; }

/// @brief The implementation of ITrainLengthService you would probably expect,
///        which simply uses DataAccess to do all the work.
class ScenarioTrainLengthService : public IScenarioTrainLengthService
{
public:
    /// Creates a ScenarioTrainLengthService for a given Scenario ID.
    ///
    /// @param scenario_id
    ///        ID of the scenario of interest. Invalid values are fine, but
    ///        will mean that this service has no idea about the length of
    ///        any train.
    /// @param train_data
    ///        The train DataAccess interface to query.
    ScenarioTrainLengthService(int                     scenario_id,
                               Train::Database::Train &train_data);

    /// @internal As defined in IScenarioTrainLengthService.
    double GetTrainLength(int scenario_train_id) override;

private:
    std::map<int, double> m_scenario_train_id_to_train_length;
};
