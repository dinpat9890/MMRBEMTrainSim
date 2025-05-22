///
/// @file       ITrainInterface.h
///
///             Store Train Properties.
///             It is abstract class for Production Train Interface & Test Train Interface
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
#pragma once

#include "CCTVState.h"
#include "train_data_access/TrainDataAccess.h"

#include<vector>
#include <map>
#include <utility>
class ITrainInterface
{
public:
    virtual void Start() = 0;
    virtual std::vector<Train::Data::TrainElement> GetTrainElements(int scenario_train_id) = 0;
    virtual int GetScenarioTrainId() = 0;
    virtual std::vector<Train::Data::TrainCamera> GetTrainCamera(int scenario_train_id) = 0;
    virtual std::vector<Train::Data::ScenarioTrain> GetScenarioTrains() = 0;
    virtual size_t GetScenarioId() = 0;
    virtual double GetCurrentModuleTime() = 0;
    virtual size_t GetVehicleCountID() = 0;
    // virtual CCTVState::PEACommsInfoToVehicleCameraMapping GetPEADIDToVehicleCamera() = 0;
};