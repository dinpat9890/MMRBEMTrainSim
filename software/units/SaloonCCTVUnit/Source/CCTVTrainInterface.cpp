///
/// @file       CCTVTrainInterface.cpp
///
///             Interface to Sydac Train Properties.
///             It fetch train propeties from Sydac using watcher.
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///
///

#include "CCTVTrainInterface.h"
#include "Utility/Utilities.h"
#include "core_properties/CommonProperties.h"
#include "project_comms_structure/ProjectObjectConstants.h"


CCTVTrainInterface::CCTVTrainInterface(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, const Core::BaseScenarioData &scenario_data, const Common::Properties &properties)
:m_train_elements_cache(data_access), m_train_cameras_cache(data_access), m_gateway(gateway)
{
        auto hub_id = Core::Properties::GetHubID(properties, data_access);
        auto hub_data = Core::GetHubData(scenario_data, hub_id);
        m_scenario_train_id = hub_data.scenario_train_id;
        

        m_scenario_id = m_gateway.GetScenarioData<Core::BaseScenarioData>().data.scenario_id;
        m_scenario_trains = Train::Database::Train(data_access).GetScenarioTrains(int(m_scenario_id));
}

void CCTVTrainInterface::Start()
{
    OS::Lock<Comms::Gateway> comms_lock(m_gateway);
    Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&CCTVTrainInterface::ObjectCreated, this));
}

std::vector<Train::Data::TrainElement> CCTVTrainInterface::GetTrainElements(int scenario_train_id)
{
    std::vector<Train::Data::TrainElement> te = m_train_elements_cache(scenario_train_id);
    return te;
}
int CCTVTrainInterface::GetScenarioTrainId()
{
    return m_scenario_train_id;
}
std::vector<Train::Data::TrainCamera> CCTVTrainInterface::GetTrainCamera(int scenario_train_id)
{
    std::vector<Train::Data::TrainCamera> cameras = m_train_cameras_cache(scenario_train_id);
    return cameras;
}
size_t CCTVTrainInterface::GetScenarioId()
{
    return m_scenario_id;
}
 std::vector<Train::Data::ScenarioTrain> CCTVTrainInterface::GetScenarioTrains()
{
     return m_scenario_trains;
}

 size_t CCTVTrainInterface::GetVehicleCountID()
 {
     return m_train_vehcl_count_id;
 }

void CCTVTrainInterface::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    switch(class_id)
    {
    case Project::ClassID::WORLD:
        Comms::AddCreationCallback(object, MakeCallback(&CCTVTrainInterface::ObjectCreated, this));
        break;

    case Project::ClassID::TRAIN:
        {
            auto scenario_train_id = static_cast<int>(object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value);
            auto train_vehcl_count_id = static_cast<int>(object.Numbers().Get(Train::ValueName::Train::TRAIN_ID).value);
            m_train_vehcl_count_id = train_vehcl_count_id;
            if(scenario_train_id == m_scenario_train_id)
            {
                Comms::AddCreationCallback(object, MakeCallback(&CCTVTrainInterface::ObjectCreated, this));
            }
        }
        break;

    case Project::ClassID::VEHICLE:
        {
            Comms::AddCreationCallback(object, MakeCallback(&CCTVTrainInterface::ObjectCreated, this));
        }
        break;

     // Add this to the comms file for input and output object creations.
     /*case Project::ClassID::SALOON_CCTV_VEHICLE_INPUTS:
        {
            auto num_id_1 = object.Numbers().Get(Project::ValueName::VDUInputsValues::PEA_NO_1_END_ACTIVE).id;
            auto num_object_id_1 = object.GetID();

            auto num_id_2 = object.Numbers().Get(Project::ValueName::VDUInputsValues::PEA_NO_2_END_ACTIVE).id;
            auto num_object_id_2 = object.GetID();

            double vehicle_index = object.GetParent().Numbers().Store().Get(object.GetParent().Numbers().Info().GetID(Project::ValueName::Vehicle::INDEX)).value;
            m_pea_id_to_vehicle_camera.insert({ { num_id_1, num_object_id_1 }, { static_cast<size_t>(vehicle_index), "Saloon camera 2" } });
            m_pea_id_to_vehicle_camera.insert({ { num_id_2, num_object_id_2 }, { static_cast<size_t>(vehicle_index), "Saloon camera 1" } });
        }
        break;*/

    default:
        break;
    }
}

double CCTVTrainInterface::GetCurrentModuleTime()
{
    return m_gateway.GetTiming().GetCurrentModuleTime();
}

CCTVTrainInterface::~CCTVTrainInterface(void)
{
}

//CCTVState::PEACommsInfoToVehicleCameraMapping CCTVTrainInterface::GetPEADIDToVehicleCamera()
//{
//    return m_pea_id_to_vehicle_camera;
//}
