///
/// @file       CCTVBackendUnitImpl.h
///
///             Implementation of unit implementation.
///             
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "CanvasViewManager.h"
#include "CCTVViewController.h"
#include "CommsInterface.h"
#include "CCTVState.h"

#include "ITrainInterface.h"
#include "IVisionInterface.h"
#include "ICCTVProperties.h"
#include "ICommsInterface.h"

#include "sim_comms/Unit.h"
#include "Common/DataAccess.h"
#include "world_api/WorldAccess.h"
#include "world_api/TrainPathWatcher.h"
#include "CCTVBackendUnitImpl.h"

#ifndef SALOON_CCTV_BACKENDUNIT_IMPL_H
#define SALOON_CCTV_BACKENDUNIT_IMPL_H

namespace
{
    const double REQUEST_FREQ = 20.0; // In Hz
}

class CCTVBackendUnitImpl : public Comms::SteppingUnit
{
public:

    CCTVBackendUnitImpl(Comms::Gateway &gateway, Common::Data::DataAccess &data_access, WorldAPI::WorldAccess &world_access,
        WorldAPI::TrainPathWatcher &path_watcher, const Core::BaseScenarioData &scenario_data, const Common::Properties &properties);
    ~CCTVBackendUnitImpl();

    void Step(double new_time) ;

    void PowerStateChanged(bool power_on);
    void BatteryStateOnOff(Sim::Number number);
    void AutoRotationOnChanged(Sim::Number number);
    void SelectionViewRequestChanged(Sim::Number number);
    void IntExtCamSelRequestChanged(Sim::Number number);
    void SelectedCameraIDChanged(Sim::Number number);
    double GetPeriod() const ; 
    // for which vehicle is selected to show on the view...
    void VehicleSelectionChanged(Sim::Number number);
    void PrevVehicleSelectionChanged(Sim::Number number);
    void NextVehicleSelectionChanged(Sim::Number number);
    void ExtCameraTypeSelectionChanged(Sim::Number number);
    void ExtCameraVehicleChanged(Sim::Number number);
    void AlarmModeChanged(Sim::Number number);
    bool AlarmEventTypeChanged();
    bool ProcessAlarm(CCTVState::AlarmType eventype, int vehicle_index, int pecu_alarm_id);
    void PlatformDetection(CCTVState::ExteriorCameraType Left_right_ext_camera, bool platform_detected);
    void CheckExternalCCTVPlatform();

    void DerailmentChangedCallback(Sim::Number number);
    void PEidChangedCallback(Sim::Number number);
    void DetrainmentEmgDoorChangedCallback(Sim::Number number);
    void FaultStateChangedCallback(Sim::Number number);

    void SettingQuitChangedCallback(Sim::Number number);
    void SettingChangedCallback(Sim::Number number);
    void NormalEventChangedCallback(Sim::Number number);

    void ObstacleDetectedChangedCallback(Sim::Number number);
    
    CCTVState::CCTVViewModes GetCurrentViewMode();
    void SetCamDetails(bool externalCam, bool prev);
    bool CheckValidVehicle(CCTVState::CarCameraType camera_type, int vehicle_index, CCTVState::CameraSelection internal_external_cam_type);

    void DestroyVDUObjCallback();

    std::unique_ptr<CommsInterface>       m_pcomms_interface;
    std::shared_ptr<CanvasViewManager>    m_pcanvas_view_manager;
    std::shared_ptr<CCTVState>            m_psaloon_cctv_state;
    std::unique_ptr<ITrainInterface>      m_pITrainInterface;

private:

    Comms::Gateway  &m_gateway;
    Core::BaseScenarioData::HubData m_hub_data;
    WorldAPI::WorldAccess &m_world_access;
    WorldAPI::TrainPathWatcher &m_path_watcher;
    std::shared_ptr<IVisionInterface> m_pVisionInterface;
    std::shared_ptr<ICCTVProperties> m_pICCTVProperties;
    std::unique_ptr<ICommsInterface> m_pCommsInterface1;

    void CreateViewControllers();
    void DestroyViewControllers();

    enum class ViewController
    {
        STATIC_FOUR_VIEW,
        AUTO_ROTATE_FOUR_VIEW,
        AUTO_ROTATE_SINGLE_VIEW,
        PEA_VIEW,
        POWERUP_VIEW,
        STATIC_SINGLE_VIEW,
        SELECTED_CAMERA_VIEW,
        SHUTDOWN_VIEW,
        VEHICLE_MODULE_VIEW,
        EXT_CAMERA_TYPE_VIEW,
        ALARM_SINGLE_VIEW,
        ALARM_FOUR_VIEW
    };

    bool                    m_power_on = false;
    ViewController          m_last_selected_view_controller;
    std::recursive_mutex    m_mutex;
    int                     m_selected_vehicle_module=0;
    int                        m_previous_vehicle_module=-1;
    CCTVState::ExteriorCameraType        m_selected_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
    CCTVState::ExteriorCameraType        m_previous_ext_cam_type = CCTVState::ExteriorCameraType::ECAM_L;
    int                        m_selected_ext_cam_vehicle_idx = 0;
    int                        m_last_iteration_button = 0; // for prev and next functionlity
    bool                    m_platform_cctv = false;

    std::shared_ptr<CCTVViewController> m_working_cctv_view_controller;
    std::map<ViewController, std::shared_ptr<CCTVViewController>> m_all_cctv_view_controllers;
};

#endif