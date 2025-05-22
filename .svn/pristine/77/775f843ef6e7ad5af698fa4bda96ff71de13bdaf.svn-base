///
/// @file       AlarmViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when some event is triggered. Only supports Single view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "AlarmViewController.h"

namespace
{
    const size_t ACTIVE_BUTTON_COUNT_MAX = 4;
    const size_t CANVAS_SINGLE_VIEW_ID = 0;
    const double AUTO_ROTATTION_OFF = 0.0;
}

AlarmViewController::AlarmViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

AlarmViewController::~AlarmViewController()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController Destructor" << Trace::EndLog();
}

void AlarmViewController::MarkExecutionCompleted()
{
    m_executed = false;
}

void AlarmViewController::Execute()
{
    if (!m_executed)
    {
        m_executed = true;
        if (m_saloon_cctv_state.m_alarm_mode == true)
        {
            //while till pw is empty
            CCTVState::AlarmVehicleType event_type = m_saloon_cctv_state.m_alarm_events.top();
            auto veh_ind = m_saloon_cctv_state.m_alarm_events.top().vehicle_idx;
            auto pecu_alarm_id = m_saloon_cctv_state.m_alarm_events.top().pecu_alarm_id;
            //m_saloon_cctv_state.m_alarm_events.pop();
            switch (static_cast<int>(event_type.eventType))
            {
            case CCTVState::ALARM_FIRE_1:
                processFireAlarm(event_type); //
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_FIRE_1);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::FIRE_ALARM_1, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Fire Alarm Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_OBSTCL_SALOON_DR_2:
                processDoorObstcleAlarm(event_type);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OBSTCL_SALOON_DR_2);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Obstacle detected by saloon door type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_PECU_3:
                processSaloonAlarm(event_type, veh_ind, pecu_alarm_id);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_PECU_3);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::PECU_ALARM_3, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - PECU alarm type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_DR_UNLK_4:
                processSaloonAlarm(event_type, 0, 0); //
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_DR_UNLK_4);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Door unlocked type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_EMRG_DR_OPN_5:
                processEmergencyDoorAlarm(event_type); //DMC CCTV Cab Camera
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_EMRG_DR_OPN_5);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Opening of emergency door type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_DRVR_DSK_6:
                processCABAlarm(event_type); //not in scope (DMC Detrainment Camera)
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_DRVR_DSK_6);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Opening of driver console desk type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_OBSTRUCTION_DEFLCT_7:
                processODDAlarm(event_type); // (DMC ODD Camera)
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OBSTRUCTION_DEFLCT_7);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Obstruction deflection device type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_TRACK_EVENT_8:
                processTrackAlarm(event_type); // (DMC Driver's Track Camera)
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_TRACK_EVENT_8);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Track related events type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_EMRG_CCTV_9:
                processSaloonAlarm(event_type, 0, 0); // not in scope
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_EMRG_CCTV_9);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - CCTV emergency button Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_OHE_10:
                processOHEAlarm(event_type); // (Driver's Forward View)
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_OHE_10);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::OHE_ALARM_10, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - OHE event type Event Triggered " << Trace::EndLog();
                break;
            case CCTVState::ALARM_PANTO_11:
                processPantoAlarm(event_type); // PANTO Camera
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, CCTVState::ALARM_PANTO_11);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::PANTO_ALARM_11, 1.0);
                Trace::GetLogger().STAMP(Trace::INFO) << "Alarm - Pantograph event type Event Triggered " << Trace::EndLog();
                break;
            }

        }
    }
}

void AlarmViewController::processFireAlarm(CCTVState::AlarmVehicleType eventType)
{
    processSaloonAlarm(eventType, 0, 0);
}
void AlarmViewController::processSaloonAlarm(CCTVState::AlarmVehicleType eventType, int veh_index, int pecu_door_id)
{
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_internal_buttons;

    CameraViewButtons buttons;
    buttons.Clear();

    // Set auto rotation off
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);

    int pecu_vehicle_index = eventType.vehicle_idx - 1;
    int pecu_cam_door_ind = 0;

    //auto associated_vehicle_index = eventType.vehicle_idx - 1;
    if (pecu_door_id >= 1) {
        pecu_vehicle_index = (pecu_door_id - 1) / 4;
        pecu_cam_door_ind = (pecu_door_id - 1) % 4;
    }

    auto button_list_itr = all_camera_buttons.find(pecu_vehicle_index);
    
    if (button_list_itr != all_camera_buttons.end())
    {
        auto & button_list = button_list_itr->second;

        if (pecu_cam_door_ind >= button_list.size())
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "pecu_cam_door_ind is invalid" << Trace::EndLog();
            return;
        }

        auto & cam_button = button_list[pecu_cam_door_ind];

        CameraViewButtons_Button button;
        button.Clear();

        cam_button.button_state = CameraViewButtons_State_ACTIVE;
        CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

        auto cam_type = cam_button.camera_type;

        auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[pecu_vehicle_index].GetPerspectiveOfCamera(cam_type);

        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);
        bool activeFlg = true;

        button.set_id(int(pecu_vehicle_index));
        button.set_name(cam_button.camera_name);
        button.set_state(cam_button.button_state);
        button.set_associatedview(asso_view);
        button.set_alarmtype(static_cast<int>(eventType.eventType));
        if (activeFlg)
            buttons.add_button()->CopyFrom(button);

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController:: Saloon Int Cam Vehicle Index : " << pecu_vehicle_index + 1 << Trace::EndLog();

        std::string buttons_state;
        buttons.AppendToString(&buttons_state);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController::Saloon Internal Buttons State : " << buttons.DebugString() << Trace::EndLog();

        m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
    }
}


void AlarmViewController::processExternalAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type)
{
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_external_buttons;

    CameraViewButtons buttons;
    buttons.Clear();

    // Set auto rotation off
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);

    auto associated_vehicle_index = eventType.vehicle_idx - 1;

    auto button_list_itr = all_camera_buttons.find(associated_vehicle_index);
    if (button_list_itr != all_camera_buttons.end())
    {
        auto & button_list = button_list_itr->second;
        for (auto & item : button_list)
        {
            if (item.camera_type == camera_type)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Button found" << Trace::EndLog();
                auto & panto_button = item;
                CameraViewButtons_Button button;
                button.Clear();

                panto_button.button_state = CameraViewButtons_State_ACTIVE;
                CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

                auto associated_camera = panto_button.camera_type;
                auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[associated_vehicle_index].GetPerspectiveOfCamera(associated_camera);

                m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);
                bool activeFlg = true;

                button.set_id(int(associated_vehicle_index));
                button.set_name(panto_button.camera_name);
                button.set_state(panto_button.button_state);
                button.set_associatedview(asso_view);
                button.set_alarmtype(static_cast<int>(eventType.eventType));
                if (activeFlg)
                    buttons.add_button()->CopyFrom(button);

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController::External Alarm, Vehicle Index : " << associated_vehicle_index + 1 << Trace::EndLog();

                std::string buttons_state;
                buttons.AppendToString(&buttons_state);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController::External Alarm, Buttons State : " << buttons.DebugString() << Trace::EndLog();

                m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

                break;
            }
        }
    }
}

void AlarmViewController::processInternalCabAlarm(CCTVState::AlarmVehicleType eventType, CCTVState::CarCameraType camera_type)
{
    auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_cab_buttons;

    CameraViewButtons buttons;
    buttons.Clear();

    // Set auto rotation off
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);

    auto associated_vehicle_index = eventType.vehicle_idx - 1;

    auto button_list_itr = all_camera_buttons.find(associated_vehicle_index);
    if (button_list_itr != all_camera_buttons.end())
    {
        //auto & button_list = button_list_itr;
        //for (auto & item : button_list)
        {
            if (button_list_itr->second.camera_type == camera_type)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Button found" << Trace::EndLog();
                auto & panto_button = button_list_itr;
                CameraViewButtons_Button button;
                button.Clear();

                panto_button->second.button_state = CameraViewButtons_State_ACTIVE;
                CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

                auto associated_camera = panto_button->second.camera_type;
                auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[associated_vehicle_index].GetPerspectiveOfCamera(associated_camera);

                m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);
                bool activeFlg = true;

                button.set_id(int(associated_vehicle_index));
                button.set_name(panto_button->second.camera_name);
                button.set_state(panto_button->second.button_state);
                button.set_associatedview(asso_view);
                button.set_alarmtype(static_cast<int>(eventType.eventType));
                if (activeFlg)
                    buttons.add_button()->CopyFrom(button);

                Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController::Internal Cab Alarm, Vehicle Index : " << associated_vehicle_index + 1 << Trace::EndLog();

                std::string buttons_state;
                buttons.AppendToString(&buttons_state);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "AlarmViewController::Internal Cab Alarm, Buttons State : " << buttons.DebugString() << Trace::EndLog();

                m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

                //break;
            }
        }
    }
}

void AlarmViewController::processPantoAlarm(CCTVState::AlarmVehicleType eventType)
{
    processExternalAlarm(eventType, CCTVState::T_PANTO_CAMERA_1);
}
void AlarmViewController::processDoorObstcleAlarm(CCTVState::AlarmVehicleType event_type)
{
    processSaloonAlarm(event_type, 0, 0);
}
void AlarmViewController::processEmergencyDoorAlarm(CCTVState::AlarmVehicleType eventType)
{
    processInternalCabAlarm(eventType, CCTVState::DM_CAB_CAMERA_1); //DMC Cab or Detrainment Camera
}
void AlarmViewController::processTrackAlarm(CCTVState::AlarmVehicleType eventType)
{
    processExternalAlarm(eventType, CCTVState::DM_TRACK_CAMERA_1); //DMC Track Camera
}
void AlarmViewController::processODDAlarm(CCTVState::AlarmVehicleType eventType)
{
    processExternalAlarm(eventType, CCTVState::DM_ODD_CAMERA_1); //DMC ODD Camera
}
void AlarmViewController::processOHEAlarm(CCTVState::AlarmVehicleType eventType) //Front camera
{
    processExternalAlarm(eventType, CCTVState::DM_FRONT_CAMERA_1); //Driver's Forward View
}
void AlarmViewController::processCABAlarm(CCTVState::AlarmVehicleType eventType) //driver console
{
    processExternalAlarm(eventType, CCTVState::DM_FRONT_CAMERA_1); //DMC Detrainment Camera
}
