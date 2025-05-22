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

class AlarmViewController : public CCTVViewController
{
public:
    AlarmViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~AlarmViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;
    void processExternalAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type);
    void processSaloonAlarm(CCTVState::AlarmVehicleType eventType, int veh_index, int pecu_alarm_id);
    void processInternalCabAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type);
    
    void processFireAlarm(CCTVState::AlarmVehicleType eventType);    
    void processPantoAlarm(CCTVState::AlarmVehicleType eventType);
    void processDoorObstcleAlarm(CCTVState::AlarmVehicleType eventType);
    void processEmergencyDoorAlarm(CCTVState::AlarmVehicleType eventType);
    void processTrackAlarm(CCTVState::AlarmVehicleType eventType);
    void processODDAlarm(CCTVState::AlarmVehicleType eventType);
    void processOHEAlarm(CCTVState::AlarmVehicleType eventType); //Front camera
    void processCABAlarm(CCTVState::AlarmVehicleType eventType); //driver console

private:
    bool m_executed = false;
};
