///
/// @file       AlarmViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when some event is triggered. Only supports Single view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "CCTVViewController.h"

class AlarmFourViewController : public CCTVViewController
{
public:
    AlarmFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~AlarmFourViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;
    void processExternalAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processInternalCabAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processSaloonAlarm(CCTVState::AlarmVehicleType eventType, int door_index, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    
    void processFireAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processPantoAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processDoorObstcleAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processEmergencyDoorAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processTrackAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processODDAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids);
    void processOHEAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids); //Front camera
    void processCABAlarm(CCTVState::AlarmVehicleType eventType, CameraViewButtons & buttons, std::vector<size_t> & perspective_ids); //driver console
    void SetEmptyButton(std::vector<size_t> & perspective_ids, CameraViewButtons & buttons);

private:
    bool m_executed = false;
};
