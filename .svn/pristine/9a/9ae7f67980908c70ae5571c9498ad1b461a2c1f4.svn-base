/// @file      ScenarioTrainTypeService.h
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "IScenarioTrainTypeService.h"
#include <map>

namespace DataAccess { class SimulatorData; }

class ScenarioTrainTypeService : public IScenarioTrainTypeService
{
public:
    ScenarioTrainTypeService(int                        scenario_id,
                             DataAccess::SimulatorData &simulator_data);

    /// @internal As defined in IScenarioTrainTypeService.
    int GetTrainType(int scenario_train_id) override;

private:
    std::map<int, int> m_scenario_train_id_to_train_type_id;
};
