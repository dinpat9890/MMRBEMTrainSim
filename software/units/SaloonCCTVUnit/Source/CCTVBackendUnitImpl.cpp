///
/// @file       CCTVBackendUnitImpl.cpp
///
///             Implementation of unit implementation.
///             This class is interface to Production Unit
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Ltd, 2022
///

#include "project_comms_structure/ProjectObjectConstants.h"

#include "CCTVBackendUnitImpl.h"
#include "StaticFourViewController.h"
#include "AutoRotateFourViewController.h"
#include "AutoRotateSingleViewController.h"
#include "PowerUpViewController.h"
#include "StaticSingleViewController.h"
#include "SelectedCameraViewController.h"
#include "VehicleModuleViewcontroller.h"
#include "ExternalCamTypeViewcontroller.h"
#include "AlarmViewController.h"
#include "ShutdownViewController.h"

#include "train_data_access/TrainDataAccessTypes.h"
#include "CCTVTrainInterface.h"
#include "CCTVVisionManager.h"
#include "CCTVProperties.h"
#include "CCTVCommsInterface.h"
#include "AlarmFourViewController.h"
#include "../../../config/project_features/include/project_features/ProjectFeatureConstants.h"

namespace
{
    const double AUTO_ROTATTION_STATE_ON = 1.0;
    const double AUTO_ROTATTION_STATE_OFF = 0.0;
    const std::string CSDE_CODE_PROPERTY = "CSDE Code";
    const std::string SIX_CAB_STOP_POINT = "6";
    const std::string EIGHT_CAB_STOP_POINT = "8";
}

CCTVBackendUnitImpl::CCTVBackendUnitImpl(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, WorldAPI::WorldAccess &world_access,
    WorldAPI::TrainPathWatcher &path_watcher, const Core::BaseScenarioData &scenario_data, const Common::Properties &properties)
        : Comms::SteppingUnit(gateway), m_gateway(gateway), m_world_access(world_access), m_path_watcher(path_watcher)
{
    try
    {
        //Get and store Hub Data
        auto hub_id = Core::Properties::GetHubID(properties, data_access);
        m_hub_data = Core::GetHubData(scenario_data, hub_id);

        m_pITrainInterface = std::make_unique<CCTVTrainInterface>(gateway, data_access, scenario_data, properties);
        m_pVisionInterface = std::make_shared<CCTVVisionManager>(gateway, data_access, SaloonCCTV::ENGINE_NAME, m_hub_data);
        m_pICCTVProperties = std::make_shared<CCTVProperties>(properties);
        m_pCommsInterface1 = std::make_unique<CCTVCommsInterface>(gateway, m_hub_data, REQUEST_FREQ);

        m_pcomms_interface = std::make_unique<CommsInterface>(*m_pCommsInterface1);
        m_pcanvas_view_manager = std::make_shared<CanvasViewManager>(*m_pVisionInterface, *m_pICCTVProperties, SaloonCCTV::ENGINE_NAME);
        m_psaloon_cctv_state = std::make_shared<CCTVState>(*m_pVisionInterface, *m_pICCTVProperties, *m_pITrainInterface);

        m_psaloon_cctv_state->m_execution_frequency = REQUEST_FREQ;

        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, MakeCallback(&CCTVBackendUnitImpl::AutoRotationOnChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::VIEW_SELECTION_REQUEST, MakeCallback(&CCTVBackendUnitImpl::SelectionViewRequestChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, MakeCallback(&CCTVBackendUnitImpl::IntExtCamSelRequestChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, MakeCallback(&CCTVBackendUnitImpl::SelectedCameraIDChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::CURRENT_SELECTED_VEHICLE, MakeCallback(&CCTVBackendUnitImpl::VehicleSelectionChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::PREVIOUS_ARROW_PRESSED_REQUEST, MakeCallback(&CCTVBackendUnitImpl::PrevVehicleSelectionChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::NEXT_ARROW_PRESSED_REQUEST, MakeCallback(&CCTVBackendUnitImpl::NextVehicleSelectionChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, MakeCallback(&CCTVBackendUnitImpl::ExtCameraTypeSelectionChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, MakeCallback(&CCTVBackendUnitImpl::ExtCameraVehicleChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::ALARM_MODE, MakeCallback(&CCTVBackendUnitImpl::AlarmModeChanged, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER, MakeCallback(&CCTVBackendUnitImpl::BatteryStateOnOff, this));

        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Train::DERAILMENT, MakeCallback(&CCTVBackendUnitImpl::DerailmentChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::PAPISVehicleOutputs::FRONT_OBSTACLE_DETECTED, MakeCallback(&CCTVBackendUnitImpl::ObstacleDetectedChangedCallback, this));

        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::OHPOutputs::PE_ID, MakeCallback(&CCTVBackendUnitImpl::PEidChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN, MakeCallback(&CCTVBackendUnitImpl::DetrainmentEmgDoorChangedCallback, this));

        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_ODD_FAILURE, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Train::FLT_DAMAGED_OHE, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::Train::FLT_TRACK_CIRCUIT_OCCUPIED, MakeCallback(&CCTVBackendUnitImpl::FaultStateChangedCallback, this));

        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::CCTV_SETTING_QUIT_BUTTON_REQUEST, MakeCallback(&CCTVBackendUnitImpl::SettingQuitChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::CCTV_SETTING_PANEL_REQUEST, MakeCallback(&CCTVBackendUnitImpl::SettingChangedCallback, this));
        m_pcomms_interface->AddNumberCommsCallback(Project::ValueName::VDUInputsValues::CCTV_NORMAl_EVENT_SWITCH_REQUEST, MakeCallback(&CCTVBackendUnitImpl::NormalEventChangedCallback, this));

        std::function<void()> cb = std::bind(&CCTVBackendUnitImpl::DestroyVDUObjCallback, this);;
        m_pcomms_interface->AddDestroyVDUCallback(cb);

        Core::Database::Feature feature = Core::Database::Feature(data_access);

        int stopping_feature_point = feature.GetFeatureType(Project::FeatureTypes::FETY_STOPPING_POINT).feature_type_id;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "FETY_STOPPING_POINT: Feature_type_id " << stopping_feature_point << Trace::EndLog();
        m_pcomms_interface->SetStationFeatureType(stopping_feature_point);

        m_pITrainInterface->Start();
        m_pVisionInterface->Start();
        m_pCommsInterface1->Start();
        Start();
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ".\n hub data not operatinal " << Trace::EndLog();
    }
}

void CCTVBackendUnitImpl::DestroyVDUObjCallback()
{
    Trace::GetLogger().STAMP(Trace::INFO) << "VDU Object Destroyed, reseting Comms values" << Trace::EndLog();
    m_pcomms_interface->ClearCommsValues();
    m_psaloon_cctv_state->ResetState();
}
CCTVBackendUnitImpl::~CCTVBackendUnitImpl()
{
}

void CCTVBackendUnitImpl::Step(double new_time)
{

    if(m_power_on)
    {
        std::shared_ptr<CCTVViewController> curr_view_controller;
        if (m_last_selected_view_controller == ViewController::POWERUP_VIEW &&
            m_psaloon_cctv_state->m_initialization_completed)
        {
            m_psaloon_cctv_state->m_initialization_completed = false;
            m_psaloon_cctv_state->m_auto_rotation_active = true;
            m_last_selected_view_controller = ViewController::AUTO_ROTATE_FOUR_VIEW;
            m_working_cctv_view_controller->MarkExecutionCompleted();
            m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            m_psaloon_cctv_state->m_cctv_started = true;
        }
        if (m_psaloon_cctv_state->m_cctv_started && m_psaloon_cctv_state->m_alarm_mode == true)
        {
            if (m_psaloon_cctv_state->m_alarm_events.size() > 1)
            {
                m_last_selected_view_controller = ViewController::ALARM_FOUR_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            }
            else
            {
                //Trace::GetLogger().STAMP(Trace::VERBOSE) << "PQ size: equal to 1" << Trace::EndLog();
                m_last_selected_view_controller = ViewController::ALARM_SINGLE_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            }
        }
        std::unique_lock<std::recursive_mutex> local_lock1(m_mutex);
        curr_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        local_lock1.unlock();

        if (curr_view_controller.use_count() > 0)
        {
            curr_view_controller->Execute();
        }

        std::unique_lock<std::recursive_mutex> local_lock(m_mutex);
        if ((m_last_selected_view_controller == ViewController::VEHICLE_MODULE_VIEW || m_last_selected_view_controller == ViewController::SELECTED_CAMERA_VIEW
            || m_last_selected_view_controller == ViewController::EXT_CAMERA_TYPE_VIEW) && m_psaloon_cctv_state->m_auto_rotation_active == true)
        {
            if (m_working_cctv_view_controller->IsWaitTimeOver())
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "SetCurrentGroup" << Trace::EndLog();
                m_psaloon_cctv_state->m_internal_cam_group_seq.SetCurrentGroup(m_psaloon_cctv_state->m_curr_vehicle_index);
                m_psaloon_cctv_state->m_curr_vehicle_index = m_selected_vehicle_module - 1;
                m_last_selected_view_controller = ViewController::AUTO_ROTATE_FOUR_VIEW;
                m_working_cctv_view_controller->MarkExecutionCompleted();
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            }
        }
        if (m_last_selected_view_controller == ViewController::AUTO_ROTATE_FOUR_VIEW && m_psaloon_cctv_state->m_auto_rotation_active == true)
        {
            if (!m_psaloon_cctv_state->m_external_camera_selected)
                m_selected_vehicle_module = (int)m_psaloon_cctv_state->m_curr_vehicle_index + 1;
            else
                m_selected_ext_cam_type = m_psaloon_cctv_state->m_curr_ext_cameraType_index;
        }
        if (m_last_selected_view_controller == ViewController::SHUTDOWN_VIEW)
        {
            m_power_on = false;
            DestroyViewControllers();
            m_pcomms_interface->ResetCommsValues();
            m_psaloon_cctv_state->ResetState();
        }
        local_lock.unlock();
        AlarmEventTypeChanged();
        CheckExternalCCTVPlatform();
    }
}
CCTVState::CCTVViewModes CCTVBackendUnitImpl::GetCurrentViewMode()
{
    CCTVState::CCTVViewModes viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
    switch (m_last_selected_view_controller)
    {
    case ViewController::STATIC_FOUR_VIEW:
        viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
        break;

    case ViewController::STATIC_SINGLE_VIEW:
        viewode = CCTVState::CCTVViewModes::SINGLE_VIEW_MODE;
        break;

    case ViewController::AUTO_ROTATE_SINGLE_VIEW:
        viewode = CCTVState::CCTVViewModes::SINGLE_VIEW_MODE;
        break;

    case ViewController::AUTO_ROTATE_FOUR_VIEW:
        viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
        break;

    case ViewController::SELECTED_CAMERA_VIEW:
        viewode = CCTVState::CCTVViewModes::SINGLE_VIEW_MODE;
        break;

    case ViewController::VEHICLE_MODULE_VIEW:
        viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
        break;

    case ViewController::EXT_CAMERA_TYPE_VIEW:
        viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
        break;

    default:
        viewode = CCTVState::CCTVViewModes::FOUR_VIEW_MODE;
    }
    return viewode;
}
int FindButtonIndex(std::vector<std::string> v, std::string button_name)
{
    size_t indx = 0;
    for(size_t i = 0; i < v.size(); i++) {
        if (button_name == v[i]) {
            indx = i;
            break;
        }
    }
    return indx;
}

void CCTVBackendUnitImpl::SetCamDetails(bool externalCam, bool prev)
{
    auto & button_sequence = externalCam ? m_psaloon_cctv_state->m_external_camera_sequence : m_psaloon_cctv_state->m_internal_camera_sequence;
    auto & vehicle_button_map = externalCam ? m_psaloon_cctv_state->m_all_vehicle_external_buttons : m_psaloon_cctv_state->m_all_vehicle_internal_buttons;

    int total_button_count = button_sequence.size();
    int button_idx = FindButtonIndex(button_sequence, m_psaloon_cctv_state->m_current_button_name);

    if (prev)
    {
        if (button_idx == 0)
            m_last_iteration_button = total_button_count - 1;
        else
            m_last_iteration_button = button_idx - 1;
    }
    else
    {
        ++button_idx;
        if (button_idx == total_button_count)
            m_last_iteration_button = 0;
        else
            m_last_iteration_button = button_idx;
    }

    auto & full_button_name = button_sequence[m_last_iteration_button];
    std::string button_name = full_button_name.substr(0, (full_button_name).find("_"));
    std::string veh_index_str = full_button_name.substr(full_button_name.find_first_of("_") + 1);
    size_t veh_index = stoi(veh_index_str) - 1;
    
    if (vehicle_button_map.find(veh_index) != vehicle_button_map.end())
    {
        auto & button_list = vehicle_button_map[veh_index];
        auto iter = std::find_if(button_list.begin(), button_list.end(), [&](CCTVState::CameraButtonDescriptor item)
        {
            return (full_button_name == item.camera_name);
        });

        if (iter != button_list.end())
        {
            m_psaloon_cctv_state->m_selected_button_id = iter->camera_type;
            m_selected_vehicle_module = iter->vehicle_index + 1;
            m_psaloon_cctv_state->m_curr_vehicle_index = iter->vehicle_index;

            if (!externalCam)
            {
                m_psaloon_cctv_state->m_curr_vehicle_index = iter->vehicle_index;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << (prev ? "Prev" : "Next") << " Camera Single View (internal) found, vehicle Module: " << m_selected_vehicle_module
                    << " camera type (id): " << m_psaloon_cctv_state->m_selected_button_id
                    << " button name: " << button_name << Trace::EndLog();
            }
            else
            {
                m_psaloon_cctv_state->m_current_ext_cam_vehicle_idx = iter->vehicle_index;
                m_selected_ext_cam_type = iter->ext_cam_type;
                m_psaloon_cctv_state->m_curr_ext_cameraType_index = iter->ext_cam_type;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << (prev ? "Prev" : "Next") << " Camera Single View (external) found, vehicle Module: " << m_selected_vehicle_module
                    << " camera type: " << iter->camera_type
                    << " External camera type: " << iter->ext_cam_type
                    << " button name: " << button_name << Trace::EndLog();
                m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, m_selected_ext_cam_type);
            }

        }
        else
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Prev Camera Single View " << (externalCam ? "external" : "internal") << " not found, vehicle Module: " << iter->vehicle_index + 1
            << " camera type: " << iter->camera_type
            << " External camera type: " << iter->ext_cam_type
            << " button name: " << button_name << Trace::EndLog();
    }
}
void CCTVBackendUnitImpl::PrevVehicleSelectionChanged(Sim::Number number)
{
    if (!m_power_on)
        return;
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (m_psaloon_cctv_state->m_auto_rotation_active) {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Previous Button disabled in auto rotation mode" << Trace::EndLog();
        return;
    }

    CCTVState::CCTVViewModes curr_view_mode = GetCurrentViewMode();
    if (number.value > 0.5)
    {
        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        if (curr_view_mode == CCTVState::CCTVViewModes::FOUR_VIEW_MODE)
        {
            if (!m_psaloon_cctv_state->m_external_camera_selected)
            {
                m_previous_vehicle_module = m_selected_vehicle_module;

                if (m_selected_vehicle_module == 1)
                    m_selected_vehicle_module = m_psaloon_cctv_state->m_car_count;
                else if(number.value == 1.0)
                    --m_selected_vehicle_module;

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Internal 4 View Previous Vehicle No: " << m_selected_vehicle_module << " Set Successfully" << Trace::EndLog();
                
                m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
                m_psaloon_cctv_state->m_curr_vehicle_index = m_selected_vehicle_module - 1;


                if (number.value == 2.0)
                    m_psaloon_cctv_state->m_detrainment_cam_enable = true;
                else if (number.value == 1.0)
                    m_psaloon_cctv_state->m_detrainment_cam_enable = false;


                m_last_selected_view_controller = ViewController::VEHICLE_MODULE_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            }
            else
            {
                m_previous_ext_cam_type = m_selected_ext_cam_type;
                if (m_selected_ext_cam_type == CCTVState::ExteriorCameraType::ECAM_L) {
                    m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_R;
                }
                else {
                    int ext_cam_type = static_cast<int>(m_selected_ext_cam_type);
                    --ext_cam_type;
                    m_selected_ext_cam_type = static_cast<CCTVState::ExteriorCameraType>(ext_cam_type);
                }
                m_psaloon_cctv_state->m_curr_ext_cameraType_index = m_selected_ext_cam_type;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "External 4 View Previous Ext CamType Index: " << m_selected_ext_cam_type << " Set Successfully" << Trace::EndLog();
                m_selected_vehicle_module = 1;
                m_psaloon_cctv_state->m_curr_vehicle_index = 0;

                m_last_selected_view_controller = ViewController::EXT_CAMERA_TYPE_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
                m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, m_selected_ext_cam_type);
            }
        }
        else if (curr_view_mode == CCTVState::CCTVViewModes::SINGLE_VIEW_MODE)
        {            
            SetCamDetails(m_psaloon_cctv_state->m_external_camera_selected, true);
            m_last_selected_view_controller = ViewController::SELECTED_CAMERA_VIEW;
            m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        }
        //m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), 
        //                                             Project::ValueName::VDUInputs::PREVIOUS_ARROW_PRESSED_REQUEST, 0.0);
    }
}

void CCTVBackendUnitImpl::NextVehicleSelectionChanged(Sim::Number number)
{
    if (!m_power_on)
        return;
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (m_psaloon_cctv_state->m_auto_rotation_active)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Next Button disabled in auto rotation mode" << Trace::EndLog();
        return;
    }

    CCTVState::CCTVViewModes curr_view_mode = GetCurrentViewMode();
    if (number.value > 0.5)
    {
        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        if (curr_view_mode == CCTVState::CCTVViewModes::FOUR_VIEW_MODE)
        {
            if (!m_psaloon_cctv_state->m_external_camera_selected)
            {
                m_previous_vehicle_module = m_selected_vehicle_module;

                if (number.value == 1.0)
                    ++m_selected_vehicle_module;

                if (m_selected_vehicle_module > (int)m_psaloon_cctv_state->m_car_count)
                    m_selected_vehicle_module = (m_selected_vehicle_module) % (m_psaloon_cctv_state->m_car_count);

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Internal 4 View Next Vehicle No: " << m_selected_vehicle_module << " Set Successfully" << Trace::EndLog();

                m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;

                if (number.value == 2.0)
                {
                    m_psaloon_cctv_state->m_detrainment_cam_enable = true;
                    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::CCTV_DETRAINMENT_CAMERA_ID, 1.0);
                }
                else if (number.value == 1.0)
                {
                    m_psaloon_cctv_state->m_detrainment_cam_enable = false;
                    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::CCTV_DETRAINMENT_CAMERA_ID, 0.0);
                }

                m_psaloon_cctv_state->m_curr_vehicle_index = m_selected_vehicle_module - 1;

                m_last_selected_view_controller = ViewController::VEHICLE_MODULE_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
            }
            else
            {
                m_previous_ext_cam_type = m_selected_ext_cam_type;
                if (m_selected_ext_cam_type == CCTVState::ExteriorCameraType::ECAM_R) {
                    m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
                }
                else {
                    int ext_cam_type = static_cast<int>(m_selected_ext_cam_type);
                    ++ext_cam_type;
                    m_selected_ext_cam_type = static_cast<CCTVState::ExteriorCameraType>(ext_cam_type);
                }
                m_psaloon_cctv_state->m_curr_ext_cameraType_index = m_selected_ext_cam_type;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "External 4 View Next Ext CamType Index: " << m_selected_ext_cam_type << " Set Successfully" << Trace::EndLog();
                m_selected_vehicle_module = 1;
                m_psaloon_cctv_state->m_curr_vehicle_index = 0;

                m_last_selected_view_controller = ViewController::EXT_CAMERA_TYPE_VIEW;
                m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
                m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, m_selected_ext_cam_type);
            }
        }
        else if (curr_view_mode == CCTVState::CCTVViewModes::SINGLE_VIEW_MODE)
        {
            SetCamDetails(m_psaloon_cctv_state->m_external_camera_selected, false);
            m_last_selected_view_controller = ViewController::SELECTED_CAMERA_VIEW;
            m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        }
        //m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(),
        //    Project::ValueName::VDUInputs::NEXT_ARROW_PRESSED_REQUEST, 0.0);
    }
}

void CCTVBackendUnitImpl::PlatformDetection(CCTVState::ExteriorCameraType Left_right_ext_camera, bool platform_detected)
{
    if (platform_detected)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " PlatformDetection internal/external camera : " << Left_right_ext_camera << Trace::EndLog();
        m_psaloon_cctv_state->m_external_camera_selected = true;
        m_psaloon_cctv_state->m_external_cam_group_seq.ResetGroupIndex();
        m_psaloon_cctv_state->m_ext_cam_group_seq.ResetGroupIndex();

        m_psaloon_cctv_state->m_auto_rotation_active = AUTO_ROTATTION_STATE_OFF;
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, m_psaloon_cctv_state->m_auto_rotation_active);

        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW, CCTVState::EXTERNAL_CAMERA_SELECTION);
        m_psaloon_cctv_state->m_curr_ext_cameraType_index = Left_right_ext_camera;
        m_psaloon_cctv_state->m_curr_vehicle_index = 0;

        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_last_selected_view_controller = ViewController::EXT_CAMERA_TYPE_VIEW;
        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Train leaving Platform " << Trace::EndLog();
        m_psaloon_cctv_state->m_external_camera_selected = false;
        m_previous_vehicle_module = m_selected_vehicle_module;
        m_selected_vehicle_module = 1;
        m_psaloon_cctv_state->m_curr_vehicle_index = m_selected_vehicle_module - 1;
        m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
        m_psaloon_cctv_state->m_curr_ext_cameraType_index = m_selected_ext_cam_type;

        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_last_selected_view_controller = ViewController::VEHICLE_MODULE_VIEW;
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW, CCTVState::INTERNAL_CAMERA_SELECTION);

        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
    }
}

void CCTVBackendUnitImpl::ExtCameraVehicleChanged(Sim::Number number)
{
    if (!m_power_on)
        return;
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (!m_psaloon_cctv_state->m_external_camera_selected)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Exterior Camera Type selection " << number.value << " not supported for Internal camera mode" << Trace::EndLog();
        return;
    }

    if (number.value > 0.5)
    {
        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_selected_ext_cam_vehicle_idx = static_cast<int>(number.value);
        m_psaloon_cctv_state->m_current_ext_cam_vehicle_idx = m_selected_ext_cam_vehicle_idx - 1;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Vehicle idx in external cam  mode " << m_selected_ext_cam_vehicle_idx << " Set Successfully" << Trace::EndLog();
    }
    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, number);
}
void CCTVBackendUnitImpl::ExtCameraTypeSelectionChanged(Sim::Number number)
{
    if (!m_power_on)
        return;
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (!m_psaloon_cctv_state->m_external_camera_selected)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Exterior Camera Type selection " << number.value << " not supported for Internal camera mode" << Trace::EndLog();
        return;
    }

    if (number.value > 0.5)
    {
        //if (m_working_cctv_view_controller.use_count() > 0)
        //    m_working_cctv_view_controller->MarkExecutionCompleted();
        m_previous_ext_cam_type = m_selected_ext_cam_type;
        int ext_cam_type = static_cast<int>(number.value);

        m_selected_ext_cam_type = static_cast<CCTVState::ExteriorCameraType>(ext_cam_type);
        m_psaloon_cctv_state->m_curr_ext_cameraType_index = m_selected_ext_cam_type;
        m_selected_vehicle_module = 1;
        m_psaloon_cctv_state->m_curr_vehicle_index = 0;

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "ExtCameraTypeSelectionChanged: " << m_selected_ext_cam_type << " Set Successfully" << Trace::EndLog();

        m_working_cctv_view_controller->MarkExecutionCompleted();
        m_last_selected_view_controller = ViewController::EXT_CAMERA_TYPE_VIEW;

        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];

        //m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(),
        //    Project::ValueName::VDUInputs::EXT_CAMERA_TYPE_REQUEST, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, number.value);
    }
   
}
void CCTVBackendUnitImpl::VehicleSelectionChanged(Sim::Number number)
{
    if (!m_power_on)
        return;
    /*
        Switch to the selected vehicle and display its content on the Vision
        on every time when the diferent vehicle module is selected we have to update the view.
    */
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "VehicleSelectionChanged " << number.value << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (m_psaloon_cctv_state->m_external_camera_selected)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Vehicle selection " << number.value << " not supported for exterior camera mode" << Trace::EndLog();
        return;
    }

    if (number.value > 0.5)
    {
        // reseting the detrainment cab camera
        m_psaloon_cctv_state->m_detrainment_cam_enable = false;

        if (!m_psaloon_cctv_state->m_external_camera_selected)
        {
            //if (m_working_cctv_view_controller.use_count() > 0)
            //    m_working_cctv_view_controller->MarkExecutionCompleted();

            m_previous_vehicle_module = m_selected_vehicle_module;
            m_selected_vehicle_module = static_cast<int>(number.value);
            m_psaloon_cctv_state->m_curr_vehicle_index = m_selected_vehicle_module - 1;
            m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
            m_psaloon_cctv_state->m_curr_ext_cameraType_index = m_selected_ext_cam_type;

            Trace::GetLogger().STAMP(Trace::VERBOSE) << m_selected_vehicle_module << " Set Successfully" << Trace::EndLog();
            m_psaloon_cctv_state->m_auto_rotation_active = AUTO_ROTATTION_STATE_OFF;
            m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, m_psaloon_cctv_state->m_auto_rotation_active);

            if (m_working_cctv_view_controller.use_count() > 0)
                m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::VEHICLE_MODULE_VIEW;

            m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        }
    }
    //m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, number);
}
void CCTVBackendUnitImpl::AutoRotationOnChanged(Sim::Number number)
{
    if (!m_power_on)
        return;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << " AutoRotationOnChanged has changed to : " << number.value << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (number.value > 0.0) // value is 1
    {
        m_psaloon_cctv_state->m_auto_rotation_active = true;

        if (m_last_selected_view_controller == ViewController::STATIC_SINGLE_VIEW ||
            m_last_selected_view_controller == ViewController::SELECTED_CAMERA_VIEW)
        {
            m_psaloon_cctv_state->m_selected_button_id = m_psaloon_cctv_state->m_external_camera_selected ?
                static_cast<double>(CCTVState::CarCameraType::DM_EXTERIOR_CAMERA_1) :
                static_cast<double>(CCTVState::CarCameraType::DM_SALOON_CAMERA_1);

            if (m_working_cctv_view_controller.use_count() > 0)
                m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::AUTO_ROTATE_SINGLE_VIEW;
        }
        else if (m_last_selected_view_controller == ViewController::STATIC_FOUR_VIEW || 
            m_last_selected_view_controller == ViewController::ALARM_SINGLE_VIEW ||
            m_last_selected_view_controller == ViewController::ALARM_FOUR_VIEW)
        {
            auto& current_group = m_psaloon_cctv_state->m_external_camera_selected ?
                m_psaloon_cctv_state->m_external_cam_group_seq :
                m_psaloon_cctv_state->m_internal_cam_group_seq;
            current_group.ResetGroupIndex();

            if (m_psaloon_cctv_state->m_external_camera_selected)
                m_psaloon_cctv_state->m_ext_cam_group_seq.ResetGroupIndex();

            if (m_working_cctv_view_controller.use_count() > 0)
                m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::AUTO_ROTATE_FOUR_VIEW;
        }
    }
    else if (-0.5 < number.value && number.value < 0.5) // value is 0
    {
         m_psaloon_cctv_state->m_auto_rotation_active = false;
        if (m_last_selected_view_controller == ViewController::AUTO_ROTATE_SINGLE_VIEW)
        {
            m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::STATIC_SINGLE_VIEW;
        }
        else if (m_last_selected_view_controller == ViewController::AUTO_ROTATE_FOUR_VIEW)
        {
            m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::STATIC_FOUR_VIEW;
        }
    }

    m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
}

void CCTVBackendUnitImpl::SelectionViewRequestChanged(Sim::Number number)
{
    if (!m_power_on)
        return;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << " SelectedViewIDChanged has changed to : " << number.value << Trace::EndLog();

    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (m_working_cctv_view_controller.use_count() > 0)
        m_working_cctv_view_controller->MarkExecutionCompleted();

    auto& current_group = m_psaloon_cctv_state->m_external_camera_selected ?
                        m_psaloon_cctv_state->m_external_cam_group_seq :
                        m_psaloon_cctv_state->m_internal_cam_group_seq;
    
    if (m_psaloon_cctv_state->m_external_camera_selected)
        m_psaloon_cctv_state->m_ext_cam_group_seq.ResetGroupIndex();

    if (0.5 < number.value && number.value < 1.5) // SINGLE_VIEW_MODE = 1
    {
        if (m_psaloon_cctv_state->m_auto_rotation_active)
        {
            m_last_selected_view_controller = ViewController::AUTO_ROTATE_SINGLE_VIEW;
        }
        else
        {
            auto& last_selected_single_view_camera_name = m_psaloon_cctv_state->m_external_camera_selected ?
                                                        m_psaloon_cctv_state->m_last_active_single_view_external_camera_name :
                                                        m_psaloon_cctv_state->m_last_active_single_view_internal_camera_name;
            //m_psaloon_cctv_state->SetDefaultLastActiveSingleViewCameraName();
            last_selected_single_view_camera_name = m_psaloon_cctv_state->GetCameraName(current_group.GetCurrentGroup().front());
            m_last_selected_view_controller = ViewController::STATIC_SINGLE_VIEW;
        }
    }
    else // FOUR_VIEW_MODE = 4
    {
        current_group.ResetGroupIndex();

        if (m_psaloon_cctv_state->m_auto_rotation_active)
        {
            m_last_selected_view_controller = ViewController::AUTO_ROTATE_FOUR_VIEW;
        }
        else
        {
            m_last_selected_view_controller = ViewController::STATIC_FOUR_VIEW;
        }
    }
    m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];

    // Just resend what ever is received, as this is required by frontend.
   // m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, number);
}

void CCTVBackendUnitImpl::IntExtCamSelRequestChanged(Sim::Number number)
{
    if (!m_power_on)
        return;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << " IntExtCamSelRequestChanged has changed to : " << number.value << Trace::EndLog();

    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    m_psaloon_cctv_state->m_curr_ext_cameraType_index = CCTVState::ExteriorCameraType::ECAM_L;
    m_psaloon_cctv_state->m_curr_vehicle_index = 0;

    // -1: Reset, 0: External, 1: Internal
    if(-0.5 < number.value && number.value < 0.5) // Consider only 0.0
    {
        m_psaloon_cctv_state->m_external_camera_selected = true;
        m_psaloon_cctv_state->m_external_cam_group_seq.ResetGroupIndex();
        m_psaloon_cctv_state->m_ext_cam_group_seq.ResetGroupIndex();

        // Just resend what ever is received, as this is required by frontend.
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW, number);

        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_last_selected_view_controller = ViewController::EXT_CAMERA_TYPE_VIEW;
        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
    }
    else if (number.value > 0.5) // value is 1
    {
        m_psaloon_cctv_state->m_external_camera_selected = false;
        m_psaloon_cctv_state->m_internal_cam_group_seq.ResetGroupIndex();

        // Just resend what ever is received, as this is required by frontend.
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW, number);

        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_last_selected_view_controller = ViewController::VEHICLE_MODULE_VIEW;
        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
    }

    // Should be marked completed here only at the end;
    //m_working_cctv_view_controller->MarkExecutionCompleted();
}

void CCTVBackendUnitImpl::SelectedCameraIDChanged(Sim::Number number)
{
    if (!m_power_on)
        return;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << " SelectedCameraIDChanged has changed : " << number.value << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (number.value > 0.5) // value is 1
    {
        if (m_working_cctv_view_controller.use_count() > 0)
            m_working_cctv_view_controller->MarkExecutionCompleted();
        m_psaloon_cctv_state->m_selected_button_id = number.value;
        m_last_selected_view_controller = ViewController::SELECTED_CAMERA_VIEW;
        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        //m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(),
        //    Project::ValueName::VDUInputs::SELECTED_CAMERA_ID, 0.0);
        // Just resend what ever is received, as this is required by frontend.
        //m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, number);
    }
}

void CCTVBackendUnitImpl::BatteryStateOnOff(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << " Control Key (Power On) has changed to : " << number.value << Trace::EndLog();
    if (number.value > 0.0) // Battery on is momentry switch
    {
        std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
        PowerStateChanged(true);
    }
    else
    {
        if (!m_power_on)
            return;

        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Control Key (Power Off) has changed to  : " << number.value << Trace::EndLog();
        if (number.value > 0.0) // Battery off is momentry switch
        {
            std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
            PowerStateChanged(false);
        }
    }
}

void CCTVBackendUnitImpl::PowerStateChanged(bool power_on)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << " PowerStateChanged has changed to : " << power_on << Trace::EndLog();

    if(power_on)
    {
        CreateViewControllers();
        m_psaloon_cctv_state->m_just_powered_up = true;
        m_psaloon_cctv_state->m_initialization_started = false;
        m_psaloon_cctv_state->m_initialization_completed = false;
        m_power_on = true;

        m_last_selected_view_controller = ViewController::POWERUP_VIEW;
        m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];

        std::vector<ViewController> view_controller_types;
        for (auto it = m_all_cctv_view_controllers.begin(); it != m_all_cctv_view_controllers.end(); it++)
            if (it->second.use_count() == 0)
                view_controller_types.push_back(it->first);

        for (auto item : view_controller_types)
        {
            int type = static_cast<int> (item);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Creating controller: " << type << Trace::EndLog();
            switch (type)
            {
            case 0:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(item,
                    std::make_shared<StaticFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 1:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::AUTO_ROTATE_FOUR_VIEW,
                    std::make_shared<AutoRotateFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 2:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::AUTO_ROTATE_SINGLE_VIEW,
                    std::make_shared<AutoRotateSingleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 3:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::PEA_VIEW,
                    std::make_shared<StaticFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 4:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::POWERUP_VIEW,
                    std::make_shared<PowerUpViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 5:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::STATIC_SINGLE_VIEW,
                    std::make_shared<StaticSingleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 6:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::SELECTED_CAMERA_VIEW,
                    std::make_shared<SelectedCameraViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 7:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::SHUTDOWN_VIEW,
                    std::make_shared<ShutdownViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 8:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::VEHICLE_MODULE_VIEW,
                    std::make_shared<VehicleModuleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 9:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::EXT_CAMERA_TYPE_VIEW,
                    std::make_shared<ExternalCamTypeViewcontroller>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 10:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::ALARM_SINGLE_VIEW,
                    std::make_shared<AlarmViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            case 11:
                m_all_cctv_view_controllers.erase(item);
                m_all_cctv_view_controllers.insert(std::make_pair(ViewController::ALARM_FOUR_VIEW,
                    std::make_shared<AlarmFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));
                break;
            }
        }
    }
    else if(m_working_cctv_view_controller.get() != nullptr)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " PowerStateChanged has changed to shutdown " << power_on << Trace::EndLog();
        if (m_working_cctv_view_controller.use_count() > 0)
        {
            m_working_cctv_view_controller->MarkExecutionCompleted();
            m_last_selected_view_controller = ViewController::SHUTDOWN_VIEW;
            m_working_cctv_view_controller = m_all_cctv_view_controllers[m_last_selected_view_controller];
        }
    }
}


void CCTVBackendUnitImpl::CreateViewControllers()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << " Creating View Controllers" << Trace::EndLog();
    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::STATIC_FOUR_VIEW,
        std::make_shared<StaticFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::AUTO_ROTATE_FOUR_VIEW,
        std::make_shared<AutoRotateFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::AUTO_ROTATE_SINGLE_VIEW,
        std::make_shared<AutoRotateSingleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::POWERUP_VIEW,
        std::make_shared<PowerUpViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::STATIC_SINGLE_VIEW,
        std::make_shared<StaticSingleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::SELECTED_CAMERA_VIEW,
        std::make_shared<SelectedCameraViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::SHUTDOWN_VIEW,
        std::make_shared<ShutdownViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::VEHICLE_MODULE_VIEW,
        std::make_shared<VehicleModuleViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::EXT_CAMERA_TYPE_VIEW,
        std::make_shared<ExternalCamTypeViewcontroller>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::ALARM_SINGLE_VIEW,
        std::make_shared<AlarmViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_all_cctv_view_controllers.insert(std::make_pair(ViewController::ALARM_FOUR_VIEW,
        std::make_shared<AlarmFourViewController>(*m_pcomms_interface, *m_pcanvas_view_manager, *m_psaloon_cctv_state)));

    m_working_cctv_view_controller = m_all_cctv_view_controllers[ViewController::SHUTDOWN_VIEW];
}

bool CCTVBackendUnitImpl::CheckValidVehicle(CCTVState::CarCameraType camera_type, int vehicle_index, CCTVState::CameraSelection internal_external_cam_type)
{
    if (internal_external_cam_type == CCTVState::EXTERNAL_CAMERA_SELECTION)
    {
        const auto & all_camera_buttons = m_psaloon_cctv_state->m_all_vehicle_external_buttons;
        auto associated_vehicle_index = vehicle_index - 1;

        const auto button_list_itr = all_camera_buttons.find(associated_vehicle_index);
        if (button_list_itr != all_camera_buttons.end())
        {
            auto & button_list = button_list_itr->second;
            for (auto & item : button_list)
            {
                if (item.camera_type == camera_type)
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Valid Vehicle for Alarm Event: "<< vehicle_index << Trace::EndLog();
                    return true;
                }
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}
bool CCTVBackendUnitImpl::ProcessAlarm(CCTVState::AlarmType eventype, int vehicle_index, int pecu_alarm_id)
{
    auto itr = m_psaloon_cctv_state->m_current_alarm_list.find(eventype);

    if (itr == m_psaloon_cctv_state->m_current_alarm_list.end())
    {
        bool ret = false;
        switch (static_cast<int>(eventype))
        {
        case CCTVState::ALARM_FIRE_1:
            ret = CheckValidVehicle(CCTVState::T_SALOON_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_OBSTCL_SALOON_DR_2:
            ret = CheckValidVehicle(CCTVState::T_SALOON_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_PECU_3:
            ret = CheckValidVehicle(CCTVState::T_SALOON_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_DR_UNLK_4:
            ret = CheckValidVehicle(CCTVState::T_SALOON_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_EMRG_DR_OPN_5:
            ret = CheckValidVehicle(CCTVState::DM_CAB_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAB_CAMERA_SELECTION);
            break;
        //case CCTVState::ALARM_DRVR_DSK_6:
            //ret = CheckValidVehicle(CCTVState::DM_FRONT_CAMERA_1, vehicle_index, CCTVState::EXTERNAL_CAMERA_SELECTION);
            //break;
        case CCTVState::ALARM_OBSTRUCTION_DEFLCT_7:
            ret = CheckValidVehicle(CCTVState::DM_ODD_CAMERA_1, vehicle_index, CCTVState::EXTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_TRACK_EVENT_8:
            ret = CheckValidVehicle(CCTVState::DM_TRACK_CAMERA_1, vehicle_index, CCTVState::EXTERNAL_CAMERA_SELECTION);
            break;
        //case CCTVState::ALARM_EMRG_CCTV_9:
        //    ret = CheckValidVehicle(CCTVState::T_SALOON_CAMERA_1, vehicle_index, CCTVState::INTERNAL_CAMERA_SELECTION);
        //    break;
        case CCTVState::ALARM_OHE_10:
            ret = CheckValidVehicle(CCTVState::DM_FRONT_CAMERA_1, vehicle_index, CCTVState::EXTERNAL_CAMERA_SELECTION);
            break;
        case CCTVState::ALARM_PANTO_11:
            ret = CheckValidVehicle(CCTVState::T_PANTO_CAMERA_1, vehicle_index, CCTVState::EXTERNAL_CAMERA_SELECTION);
            break;
        }
        if (ret)
        {
            m_psaloon_cctv_state->m_alarm_events.push({ eventype, vehicle_index, pecu_alarm_id });
            m_psaloon_cctv_state->m_current_alarm_list.insert(static_cast<int>(eventype));
            m_psaloon_cctv_state->m_current_alarm_event = eventype;

            m_all_cctv_view_controllers[ViewController::ALARM_FOUR_VIEW]->MarkExecutionCompleted();
            m_all_cctv_view_controllers[ViewController::ALARM_SINGLE_VIEW]->MarkExecutionCompleted();

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "ProcessAlarm : eventype: " << eventype << " veh idx: " << vehicle_index <<
                " PQ Size: " << m_psaloon_cctv_state->m_alarm_events.size() << Trace::EndLog();
            return true;
        }
    }
    return false;
}
void CCTVBackendUnitImpl::CheckExternalCCTVPlatform()
{
    std::vector<Comms::Object> station_feature_list = m_pcomms_interface->GetStationFeatureList();

    if (!m_platform_cctv)
    {
        std::vector<std::pair<double, Comms::Object>> platform_stopping_start_unit;
        platform_stopping_start_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), station_feature_list, true, false
            , 0.0, m_pICCTVProperties->GetStpPointStartDistance());

        if (platform_stopping_start_unit.size() > 0)
        {
            auto stop_point_feature_name = platform_stopping_start_unit.begin()->second.GetName();
            auto str = stop_point_feature_name;
            for (int i = 0; i < 2; i++)
            {
                auto pos = str.find("_");
                str = str.substr(pos+1);
            }
            std::string str2 = str.substr(0, 1);
            if (str2 == SIX_CAB_STOP_POINT)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Station Feature start found " << platform_stopping_start_unit.begin()->second.GetName()
                    << " " << m_pICCTVProperties->GetStpPointStartDistance() << Trace::EndLog();
                m_platform_cctv = true;

                auto door_side = static_cast<int>(platform_stopping_start_unit.begin()->second.Numbers().Get(CSDE_CODE_PROPERTY).value);
                if (door_side == CCTVState::PlatformSide::LEFT_SIDE)
                    PlatformDetection(CCTVState::ExteriorCameraType::ECAM_L, m_platform_cctv);
                else if (door_side == CCTVState::PlatformSide::RIGHT_SIDE)
                    PlatformDetection(CCTVState::ExteriorCameraType::ECAM_R, m_platform_cctv);
            }
        }
    }
    else
    {
        std::vector<std::pair<double, Comms::Object>> platform_stopping_end_unit;
        auto distance = m_pICCTVProperties->GetStpPointEndDistance();
        platform_stopping_end_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), station_feature_list, true, false, -distance, 0);
        if (platform_stopping_end_unit.size() > 0)
        {
            auto stop_point_feature_name = platform_stopping_end_unit.begin()->second.GetName();
            auto str = stop_point_feature_name;
            for (int i = 0; i < 2; i++)
            {
                auto pos = str.find("_");
                str = str.substr(pos + 1);
            }
            std::string str2 = str.substr(0, 1);
            if (str2 == EIGHT_CAB_STOP_POINT)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Station Feature end found, Train leaving platform "
                    << platform_stopping_end_unit.begin()->second.GetName() << " " << distance << Trace::EndLog();
                m_platform_cctv = false;
                PlatformDetection(CCTVState::ExteriorCameraType::ECAM_L, m_platform_cctv);
            }
        }
    }
}
bool CCTVBackendUnitImpl::AlarmEventTypeChanged()
{
    auto & papis_comms_map = m_pcomms_interface->GetPAPISCommsMap();
    int vehicle_idx = 1;
    bool alrarm_status = false;
    bool alrarm_off = true;
    
    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
    for (const auto& vehicle_comms : papis_comms_map)
    {
        const int pecu_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second, Project::ValueName::PAPISVehicleOutputs::PECU_ALARM_ACTIVE);
        const int pe_id = m_pcomms_interface->GetObjectPropertyNumber<int>(m_pcomms_interface->GetOHPoutpusComms(), Project::ValueName::OHPOutputs::PE_ID);
        if (pecu_alarm > 0.5 || pe_id > 0.5)
        {
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_PECU_3, vehicle_idx, pe_id))
                alrarm_status = true;
        }

        const int emergency_door_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second, Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN);
        if (emergency_door_alarm > 0.5)
        {
            alrarm_off = false;
            if(ProcessAlarm(CCTVState::ALARM_EMRG_DR_OPN_5, vehicle_idx, 0))
                alrarm_status = true;
        }

        ++vehicle_idx;
    }

    auto & vehicles_comms_map = m_pcomms_interface->GetVehiclesCommsMap();
    vehicle_idx = 1;
    for (const auto& vehicle_comms : vehicles_comms_map)
    {
        const int door_close_obstacle_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second, 
                                                                           Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION);
        const int door_open_obstacle_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_DOOR_OPEN_OBSTRUCTION);

        if (door_close_obstacle_alarm > 0.5 || door_open_obstacle_alarm > 0.5)
        {
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_OBSTCL_SALOON_DR_2, vehicle_idx, 0))
                alrarm_status = true;
        }




        // fault 4 
        const int door_unexpected_unlocking_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING);
        
        if (door_unexpected_unlocking_alarm > 0.5)
        {
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_DR_UNLK_4, vehicle_idx, 0)) {
                alrarm_status = true;
            }
        }

        const int hvac_1_fire_mode_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE);//FTS_HVAC_1_FIRE_MODE could be this fts instead of flt 
        if (hvac_1_fire_mode_alarm > 0.5)
        {
            //fault 1
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_FIRE_1, vehicle_idx, 0)) {
                alrarm_status = true;
            }
        }

        const int odd_failure_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_ODD_FAILURE);
        if (odd_failure_alarm > 0.5)
        {
            //fault 7
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_OBSTRUCTION_DEFLCT_7, vehicle_idx, 0)) {
                alrarm_status = true;
            }
        }

        



        

        const int panto_rise_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE);
        const int panto_down_add_interv_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION);
        const int panto_down_ord_interv_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(vehicle_comms.second,
            Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION);
        
        if (panto_rise_alarm > 0.5 || panto_down_add_interv_alarm > 0.5 || panto_down_ord_interv_alarm > 0.5)
        {
            alrarm_off = false;
            if (ProcessAlarm(CCTVState::ALARM_PANTO_11, vehicle_idx, 0))
                alrarm_status = true;
        }
        ++vehicle_idx;
    }






    auto & trains_comms_map = m_pcomms_interface->GetTrainsCommsMap();
    const int damaged_ohe_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(trains_comms_map, Project::ValueName::Train::FLT_DAMAGED_OHE);
    if (damaged_ohe_alarm > 0.5)
    {
        //fault 10
        alrarm_off = false;
        if (ProcessAlarm(CCTVState::ALARM_OHE_10, 1, 0)) {
            alrarm_status = true;
        }
    }

    const int track_circuit_occupied_alarm = m_pcomms_interface->GetObjectPropertyNumber<int>(trains_comms_map, Project::ValueName::Train::FLT_TRACK_CIRCUIT_OCCUPIED);
    if (track_circuit_occupied_alarm > 0.5)
    {
        //fault 8
        alrarm_off = false;
        if (ProcessAlarm(CCTVState::ALARM_TRACK_EVENT_8, 1, 0)) {
            alrarm_status = true;
        }
    }






    if (alrarm_status == true && m_psaloon_cctv_state->m_alarm_mode == false)
    {
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::ALARM_MODE, 1.0);

    }
    if (alrarm_off == true && !m_psaloon_cctv_state->m_current_alarm_list.empty())
    {
        m_psaloon_cctv_state->m_current_alarm_list.clear();
        while (!m_psaloon_cctv_state->m_alarm_events.empty())
            m_psaloon_cctv_state->m_alarm_events.pop();
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "All Events are now ok, clearing all alarms events from priority list" <<
            " PQ Size: " << m_psaloon_cctv_state->m_alarm_events.size() << Trace::EndLog();
        // if set (list of events) is empty, we should clean the pq as well and it should be done when all events are cleard.
    }
        
    return alrarm_status;
}

void CCTVBackendUnitImpl::AlarmModeChanged(Sim::Number number)
{
    if (!m_psaloon_cctv_state->m_cctv_started)
        return;
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (number.value > 0.5)
    {
        m_psaloon_cctv_state->m_alarm_mode = true;
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::NORMAL_OR_EVENT_VIEW, 1.0);
    }
    else
    {
        m_psaloon_cctv_state->m_alarm_mode = false;
        while(!m_psaloon_cctv_state->m_alarm_events.empty())
            m_psaloon_cctv_state->m_alarm_events.pop();
        
        //m_psaloon_cctv_state->m_current_alarm_list.clear();  //if the mode is set to normal and still we have this list filed with events, cctv will not enqueu such 
        // events again and will not trigger event mode. Whenever actual propert for an alarm is set to 0, corresponding alarm is removed from this set

        m_all_cctv_view_controllers[ViewController::ALARM_FOUR_VIEW]->MarkExecutionCompleted();
        m_all_cctv_view_controllers[ViewController::ALARM_SINGLE_VIEW]->MarkExecutionCompleted();

        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, 1.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::NORMAL_OR_EVENT_VIEW, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::PECU_ALARM_3, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::OHE_ALARM_10, 0.0);
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::PANTO_ALARM_11, 0.0);
    }
    
    if (m_working_cctv_view_controller.use_count() > 0)
        m_working_cctv_view_controller->MarkExecutionCompleted();
}

void CCTVBackendUnitImpl::DestroyViewControllers()
{
    m_working_cctv_view_controller.reset();
    m_all_cctv_view_controllers.clear();
}

void CCTVBackendUnitImpl::DerailmentChangedCallback(Sim::Number number)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (number.value > 0.5)
    {
        // Pulse to switch to External CAM, Stop the auto rotation and Select FCAM, Here pulse sequence is important
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, 2.0);

        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, -1.0);
    }
    else
    {
        // Pulse to Reset the configuration
        // Reset ext_CAM, Switch to Internal cam and Start the auto rotation, Here pulse sequence is important
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, 1.0);

        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, -1.0);
    }
}

void CCTVBackendUnitImpl::ObstacleDetectedChangedCallback(Sim::Number number)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    if (number.value > 0.5) // value is 1
    {
        // Logic to calculate which ODD cam to show
        int veh_idx = 0;
        Comms::Object papis_vehicle_outputs_obj = m_gateway.GetObject(number.object_id);
        Comms::Object vehicle_object = papis_vehicle_outputs_obj.GetParent();
        if (vehicle_object.IsValid())
        {
            veh_idx = static_cast<int>(vehicle_object.Numbers().Get(Project::ValueName::Vehicle::INDEX).value);
        }
        else
            Trace::GetLogger().STAMP(Trace::ERR) << __FUNCTION__ " vehicle_object not found " << Trace::EndLog();

        int veh_size = m_psaloon_cctv_state->m_car_count;
        double odd_cam_veh_indx = 1.0;
        if (veh_idx >= veh_size / 2)
            odd_cam_veh_indx = static_cast<double>(veh_size);

        // Pulse to switch to External CAM, Stop the auto rotation and Select OCAM, then select the singleView OCAM, Here pulse sequence is important
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, 4.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, odd_cam_veh_indx);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, 6.0);

        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, -1.0);
    }
    else
    {
        // Pulse to Reset the configuration
        // Reset ext_CAM, Switch to Internal cam and Start the auto rotation, Here pulse sequence is important
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, 1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, 1.0);

        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, -1.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, -1.0);
    }
}

void CCTVBackendUnitImpl::PEidChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PEidChangedCallback() " << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (number.value < 0.5)
    {
        // Switching AlarmMode to NORMAL mode from EVENT mode
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmMode set to 0 (NORMAL)" << Trace::EndLog();
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::ALARM_MODE, 0.0);
    }
}

void CCTVBackendUnitImpl::FaultStateChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "FaultStateChangedCallback() " << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (number.value < 0.5)
    {
        // Switching AlarmMode to NORMAL mode from EVENT mode
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmMode set to 0 (NORMAL)" << Trace::EndLog();
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::ALARM_MODE, 0.0);
    }
}

void CCTVBackendUnitImpl::DetrainmentEmgDoorChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "DetrainmentEmgDoorChangedCallback() " << number << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    if (number.value > 0.5)
    {
        // Set Detrainment Camera State to 1, door is open and camera is active
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::DETRAINMENT_CAMERA_STATE, 1.0);
    }
    else {
        m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::DETRAINMENT_CAMERA_STATE, 0.0);
        m_pcomms_interface->SetObjectPropertyNumber(m_pcomms_interface->GetInputCommsObject(), Project::ValueName::VDUInputsValues::ALARM_MODE, 0.0);
    }
}

void CCTVBackendUnitImpl::SettingQuitChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "SettingQuitChangedCallback() " << number << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::CCTV_SETTING_QUIT_BUTTON_STATE, number.value);
}

void CCTVBackendUnitImpl::SettingChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "SettingChangedCallback() " << number << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::CCTV_SETTING_PANEL_STATE, number.value);
}

void CCTVBackendUnitImpl::NormalEventChangedCallback(Sim::Number number)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "NormalEventChangedCallback() " << number << Trace::EndLog();
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);
    m_pcomms_interface->SetOutputNumber(Project::ValueName::VDUOutputs::CCTV_NORMAl_EVENT_SWITCH_STATE, number.value);
}

double CCTVBackendUnitImpl::GetPeriod() const
{
    return (1.0 / REQUEST_FREQ);
}