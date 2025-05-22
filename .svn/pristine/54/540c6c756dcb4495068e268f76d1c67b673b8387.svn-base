///
/// @file       CCTVTrainInterface.cpp
///
///             Interface to Sydac Train Properties.
///             It is interface classs for Train Interface & .
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///
///
#ifndef SALOON_TRAIN_INTERFACE_H
#define SALOON_TRAIN_INTERFACE_H

#include "ITrainInterface.h"
#include "Utility/CallbackCollection.h"
#include "sim_comms/Gateway.h"
#include "core_types/SessionData.h"
#include "train_data_access/TrainDataAccess.h"

#include "CCTVState.h"

#include<vector>
#include <map>
#include <utility>

class CCTVTrainInterface : public ITrainInterface
{
public:

    CCTVTrainInterface(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, const Core::BaseScenarioData &scenario_data, const Common::Properties &properties);
    ~CCTVTrainInterface();

    void Start();

    virtual std::vector<Train::Data::TrainElement> GetTrainElements(int scenario_train_id);
    virtual int GetScenarioTrainId();
    virtual std::vector<Train::Data::TrainCamera> GetTrainCamera(int scenario_train_id);
    virtual std::vector<Train::Data::ScenarioTrain> GetScenarioTrains();

    size_t GetScenarioId();
    double GetCurrentModuleTime();
    size_t GetVehicleCountID();

    void ObjectCreated(Comms::Object object);

private:
    int m_scenario_train_id;
    size_t m_train_vehcl_count_id;
    size_t m_scenario_id;
    std::vector<Train::Data::ScenarioTrain> m_scenario_trains;

    Common::Data::CachingByID<std::vector<Train::Data::TrainElement>, Train::Database::Train, &Train::Database::Train::GetTrainElements> m_train_elements_cache;
    Common::Data::CachingByID<std::vector<Train::Data::TrainCamera>, Train::Database::Train, &Train::Database::Train::GetTrainCameras> m_train_cameras_cache;

    std::recursive_mutex m_mutex;
    Comms::Gateway &m_gateway;

    //CCTVState::PEACommsInfoToVehicleCameraMapping m_pea_id_to_vehicle_camera;

public:
    //CCTVState::PEACommsInfoToVehicleCameraMapping GetPEADIDToVehicleCamera() override;
};

#endif